#include "objectgui.h"
#include "diagraminterface.h"
#include "controllers/editobjectdialog.h"

#include <QGraphicsSceneMouseEvent>
#include <QInputDialog>

ObjectGUI::ObjectGUI(UMLClass umlClass, DiagramInterface *diagramInterface) : umlObject("")
{
    // make the object movable
    setFlag(QGraphicsItem::ItemIsMovable);

    // set whether it is selected or not
    this->isSelected = false;

    // set whether it is interface or class
    this->isInterface = umlClass.isInterface;

    // set the uml class
    // there is a default initialize at the beggining of this function, but the class cant be without a name
    this->umlObject = umlClass;

    // store diagram interface variable
    this->diagramInterface = diagramInterface;

    // initialize gui representation of this object
    this->initGui();

    // set gui coordinates of the object
    this->boundingHeight = 100;
    this->boundingWidth = 100;
    this->boundingX = this->umlObject.Xcoord;
    this->boundingY = this->umlObject.Ycoord;
}

void ObjectGUI::initGui()
{
    // set name
    this->objectName = this->umlObject.name;
    //reset maps
    this->attributesMapGUI.clear();
    this->operationMapGUI.clear();

    // add all attributes (only if class) to the map with their string representation
    if (!this->isInterface)
    {
        foreach (UMLAttribute umlAttribute, this->umlObject.umlAttributesList)
        {
            QString attrText = umlAttribute.modifier + umlAttribute.name + " : " + umlAttribute.type;
            // add to the map
            this->attributesMapGUI.insert(umlAttribute, attrText);
        }
    }

    // set all operations (both class and interface)
    foreach (UMLOperation umlOperation, this->umlObject.umlOperationsList)
    {
        // build the operation text
        QString operationText = umlOperation.modifier + umlOperation.name + "(";
        foreach (UMLAttribute operationParam, umlOperation.parameterssOfOperationList)
        {
            operationText += operationParam.name + ":" + operationParam.type;
        }
        operationText += ") : " + umlOperation.type;

        // add to the map
        this->operationMapGUI.insert(umlOperation, operationText);
    }

}

QRectF ObjectGUI::boundingRect() const
{
    return QRectF(this->boundingX, this->boundingY, this->boundingWidth, this->boundingHeight);
}

void ObjectGUI::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // variable for storing whether should be updated the gui if changed size during drawing
    bool hasChangedSize = false;

    // get and set current font
    QFont font("arial", 12); //-> for text length measure
    QFontMetrics fontMetrics(font);
    painter->setFont(font);

    // get bounding rect
    QRectF rec = boundingRect();
    QBrush brush(Qt::blue);
    QPen pen(Qt::black);

    // handle whether it is selected or not
    if (this->isSelected)
    {
        brush.setColor(Qt::red);
    }
    else
    {
        brush.setColor(Qt::blue);
    }

    // fill the most back background (containing whole object)
    painter->fillRect(rec, brush);

    std::cout << this->boundingX << std::endl;
    // fill the second background (making space for object contain)
    painter->fillRect(10 + this->boundingX, this->boundingY + 10, this->boundingWidth - 20, this->boundingHeight - 20, QColor(217, 211, 210));

    // height, from which object contain (starting its name,..) starting draw
    int currentHeight = 25;

    // draw name of the class/interface -> draw it on the middle
    // resize the box if the name is widther
    if (fontMetrics.width(this->objectName) > boundingWidth - 30)
    {
        this->boundingWidth = fontMetrics.width(this->objectName) + 30;
        rec = boundingRect();
        hasChangedSize = true; // design should be redrawn
    }
    painter->drawText(this->boundingX + int(this->boundingWidth / 2) - int(fontMetrics.width(this->objectName) / 2), this->boundingY + currentHeight, this->objectName);
    currentHeight += 20;

    //if interface -> draw "interface" label
    if (this->isInterface){
        if (fontMetrics.width("<<interface>>") > boundingWidth - 30)
        {
            this->boundingWidth = fontMetrics.width("<<interface>>") + 30;
            rec = boundingRect();
            hasChangedSize = true; // design should be redrawn
        }
        painter->drawText(this->boundingX + int(this->boundingWidth / 2) - int(fontMetrics.width("<<interface>>") / 2),
                          this->boundingY + currentHeight,
                          "<<interface>>");
        currentHeight += 20;
    }

    // first line - space between object name and
    painter->drawLine(this->boundingX + 10, this->boundingY + currentHeight, this->boundingX + this->boundingWidth - 10, this->boundingY + currentHeight);
    currentHeight += 20;

    // add attributes
    QMapIterator<UMLAttribute, QString> attrMap(this->attributesMapGUI);
    while (attrMap.hasNext())
    {
        // get next attribute
        attrMap.next();

        // resize the box if the attributes are widther
        if (fontMetrics.width(attrMap.value()) > boundingWidth - 25)
        {
            this->boundingWidth = fontMetrics.width(attrMap.value()) + 25;
            rec = boundingRect();
            hasChangedSize = true; // design should be redrawn
        }

        // draw the text of attr at sufficient possition
        painter->drawText(this->boundingX + 10, this->boundingY + currentHeight, attrMap.value());
        currentHeight += 15; // increase the Y axis, where the next element will be stored
    }

    // second line - space between attributes and operations
    painter->drawLine(this->boundingX + 10, this->boundingY + currentHeight, this->boundingX + this->boundingWidth - 10, this->boundingY + currentHeight);
    currentHeight += 20;

    // add operations
    QMapIterator<UMLOperation, QString> operationMap(this->operationMapGUI);
    while (operationMap.hasNext())
    {
        // get next attribute
        operationMap.next();

        // resize the box if the operations are widther
        if (fontMetrics.width(operationMap.value()) > boundingWidth - 25)
        {
            this->boundingWidth = fontMetrics.width(operationMap.value()) + 25;
            rec = boundingRect();
            hasChangedSize = true; // design should be redrawn
        }

        // draw the text of attr at sufficient possition
        // if this operation is override, change color
        if (this->overrideOperations.contains(operationMap.key()))
        {
            painter->setPen(QColor(191, 79, 71));
        }
        painter->drawText(this->boundingX + 10, this->boundingY + currentHeight, operationMap.value());
        currentHeight += 15; // increase the Y axis, where the next element will be stored

        // reset color
        painter->setPen(QColor(0, 0, 0));
    }

    // finally draw the main - bounding - rectangle
    painter->drawRect(rec);

    // check height
    if (currentHeight >= this->boundingHeight)
    {
        this->boundingHeight = currentHeight + 30;
        hasChangedSize = true; // design should be redrawn
    }

    // when some resizing has been done then update the design
    if (hasChangedSize)
        update();
}

void ObjectGUI::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->prevMouseX = event->pos().x();
    this->prevMouseY = event->pos().y();

    this->isSelected = !isSelected;

    update();
    QGraphicsItem::mousePressEvent(event);
}

void ObjectGUI::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    int maxX = this->boundingWidth;
    int maxY = this->boundingHeight;
    bool isInX = (((event->pos().x() - this->boundingX) >= 10) && ((maxX - 10) >= (event->pos().x() - this->boundingX)));
    bool isInY = (((event->pos().y() - this->boundingY) >= 10) && ((maxY - 10) >= (event->pos().y() - this->boundingY)));

    if (!(isInX && isInY))
    {
        // create dialog asking for desired type for new relation

        // add relation types to the list -> future combobox items
        QStringList items;
        items << QDialog::tr("ASSOCIATION") << QDialog::tr("GENERALIZATION") << QDialog::tr("COMPOSITION") << QDialog::tr("AGGREGATION");

        // create new dialog
        bool ok; // variable storing whether ok has been pressed
        QString item = QInputDialog::getItem(event->widget(),
                                             QDialog::tr("Choose relation type"),
                                             QDialog::tr("Relation type"),
                                             items, 0, false, &ok);

        // if ok pressed and item has been selected then start creating relation
        if (ok && !item.isEmpty())
            std::cout << qPrintable(item) << std::endl;
        else
            std::cout << "Relation type hasn't been selected - canceled" << std::endl;
    }
    else
    {
        //create new dialog, wait for response
        EditObjectDialog *dlg = new EditObjectDialog();
        dlg->init(this->diagramInterface, &this->umlObject);
        dlg->exec();

        //update this object
        if (dlg->getUpdatedUmlObject() == NULL){

            //delete the class in diagraminterface and remove also object from
            diagramInterface->removeUMLClass(this->umlObject);

            //remove from gui
            diagramInterface->removeObjectFromGuiList(this);

            return; //this is the end of this object
        } else {
            this->umlObject = *dlg->getUpdatedUmlObject();
            //update the class in class diagram
            this->diagramInterface->updateUMLClass(this->objectName, this->umlObject);
            //newly init everything
            this->initGui();

            update();
        }


    }

    QGraphicsItem::mouseDoubleClickEvent(event);
}

void ObjectGUI::mouseMoveEvent(QGraphicsSceneMouseEvent *event){

    this->boundingX += event->pos().x() -  this->prevMouseX;
    this->boundingY += event->pos().y() -  this->prevMouseY;

    this->prevMouseX = event->pos().x();
    this->prevMouseY = event->pos().y();

    this->umlObject.Xcoord = this->boundingX;
    this->umlObject.Ycoord = this->boundingY;

    QGraphicsItem::mouseMoveEvent(event);
}

ObjectGUI::~ObjectGUI()
{
}
