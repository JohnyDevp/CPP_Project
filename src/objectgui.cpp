/**
 * @author xholan11
 * graphical representation of uml object (inner representation)
 */
#include "objectgui.h"
#include "diagraminterface.h"
#include "controllers/editobjectdialog.h"
#include "errors.h"
#include "qgraphicsscene.h"
#include "qmessagebox.h"

#include <QGraphicsSceneMouseEvent>
#include <QInputDialog>

ObjectGUI::ObjectGUI(UMLClass umlClass, DiagramInterface *diagramInterface) : umlObject("")
{
    // make the object movable
    setFlag(QGraphicsItem::ItemIsMovable);

    // set Z value
    setZValue(10);

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
    // reset maps
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

    int prevWidth = this->boundingWidth;
    int prevHeight = this->boundingHeight;

    // get and set current font
    QFont font("arial", 12); //-> for text length measure
    QFontMetrics fontMetrics(font);
    painter->setFont(font);

    // get bounding rect
    QRectF rec = boundingRect();
    QBrush brush(Qt::blue);
    QPen pen(Qt::black);

    // fill the most back background (containing whole object)
    painter->fillRect(rec, brush);

    // std::cout << this->boundingX << std::endl;

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

    // if interface -> draw "interface" label
    if (this->isInterface)
    {
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
    {
        foreach (RelationGui *relation, this->relatedRelations)
        {
            if (relation->objectEnd->objectName == this->objectName)
            {
                QPointF diff(0, 0);
                // if the relation ends at the edge
                if (relation->umlRelation.endX > this->boundingX + prevWidth - 10)
                {
                    diff.setX(this->boundingWidth - prevWidth);
                }
                if (relation->umlRelation.endY > this->boundingY + prevHeight - 10)
                {
                    diff.setY(this->boundingHeight - prevHeight);
                }
                // update the relation
                relation->updatePosition(this->umlObject, diff);
            }
            else if (relation->objectStart->objectName == this->objectName)
            {
                QPointF diff(0, 0);
                // if the relation ends at the edge
                if (relation->umlRelation.startX > this->boundingX + prevWidth - 10)
                {
                    diff.setX(this->boundingWidth - prevWidth);
                }
                if (relation->umlRelation.startY > this->boundingY + prevHeight - 10)
                {
                    diff.setY(this->boundingHeight - prevHeight);
                }
                // update the relation
                relation->updatePosition(this->umlObject, diff);
            }
        }
    }
    update();
}

void ObjectGUI::addRelatedRelation(RelationGui *relation)
{
    this->relatedRelations.append(relation);
}

void ObjectGUI::removeRelatedRelation(RelationGui *relation)
{
    this->relatedRelations.removeOne(relation);
    // update - because of possible overriden operations
    checkForOverrideOperationsNotification();
}

void ObjectGUI::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->prevMouseLocalX = event->pos().x();
    this->prevMouseLocalY = event->pos().y();

    this->prevMouseSceneX = event->scenePos().x();
    this->prevMouseSceneY = event->scenePos().y();

    update();
    QGraphicsItem::mousePressEvent(event);
}

void ObjectGUI::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    int maxX = this->boundingWidth;
    int maxY = this->boundingHeight;
    bool isInX = (((event->pos().x() - this->boundingX) >= 10) && ((maxX - 10) >= (event->pos().x() - this->boundingX)));
    bool isInY = (((event->pos().y() - this->boundingY) >= 10) && ((maxY - 10) >= (event->pos().y() - this->boundingY)));

    // check whether the click was inside the object or on the edges of the object
    if (!(isInX && isInY))
    {
        if (diagramInterface->isRelationCreating)
        {
            // raise dialog asking whether continue creating relation
            QMessageBox msgBox;
            // this button is added only if the clicked object is different from object where the relation started
            QPushButton *continueButton = nullptr;
            msgBox.setText("Continue creating relation?");
            if (this->diagramInterface->tempUmlRelation.relationFrom != this->objectName)
            {
                continueButton = msgBox.addButton(QDialog::tr("Create relation here"), QMessageBox::ActionRole);
            }
            QPushButton *abortButton = msgBox.addButton(QDialog::tr("Abort creating relation"), QMessageBox::ActionRole);
            QPushButton *cancelButton = msgBox.addButton(QMessageBox::Cancel);
            msgBox.exec();

            if (msgBox.clickedButton() == (QAbstractButton *)continueButton)
            {

                this->diagramInterface->isRelationCreating = false;
                this->diagramInterface->tempUmlRelation.relationTo = this->objectName;

                QPointF point(event->scenePos().x(), event->scenePos().y());
                // std::cout << point.x() << " " << point.y() << std::endl;

                // normalizePointToEdge(&point);

                this->diagramInterface->tempUmlRelation.endX = point.x();
                this->diagramInterface->tempUmlRelation.endY = point.y();

                // add the relation to the diagram
                this->diagramInterface->createRelation();
            }
            else if (msgBox.clickedButton() == (QAbstractButton *)abortButton)
            {
                // abort creating -
                this->diagramInterface->isRelationCreating = false;
            }
            else if (msgBox.clickedButton() == (QAbstractButton *)cancelButton)
            {
                // do nothing
                return;
            }
        }
        else
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
            {
                UMLRelation::RelationType relType = UMLRelation::ASSOCIATION; // default
                if (item == "ASSOCIATION")
                    relType = UMLRelation::ASSOCIATION;
                else if (item == "GENERALIZATION")
                    relType = UMLRelation::GENERALIZATION;
                else if (item == "COMPOSITION")
                    relType = UMLRelation::COMPOSITION;
                else if (item == "AGGREGATION")
                    relType = UMLRelation::AGGREGATION;

                // create new uml relation, assign it to diagram interface and set creatingrelation variable to true
                UMLRelation umlRelation("", this->objectName, "", relType);
                umlRelation.startX = event->scenePos().x();
                umlRelation.startY = event->scenePos().y();

                this->diagramInterface->isRelationCreating = true;
                this->diagramInterface->tempUmlRelation = umlRelation;

                // std::cout << qPrintable(item) << std::endl;
            }
            else
            {
                std::cout << "Relation type hasn't been selected - canceled" << std::endl;
            }
        }
    }
    else
    {
        // create new dialog, wait for response
        EditObjectDialog *dlg = new EditObjectDialog();
        dlg->init(this->diagramInterface, &this->umlObject, this);
        dlg->exec();

        // update this object
        // if the object is null -> has been just removed
        if (dlg->getUpdatedUmlObject() == NULL)
        {
            // notify relations about deletion
            foreach (RelationGui *relation, this->relatedRelations)
            {
                relation->removeRelationNotification();
            }
            // delete the class in diagraminterface and remove also object from
            diagramInterface->removeUMLClass(this->umlObject);

            // remove from gui
            diagramInterface->removeObjectFromGuiList(this);

            return; // this is the end of this object
        }
        else
        {
            this->umlObject = *dlg->getUpdatedUmlObject();
            // update the class in class diagram
            this->diagramInterface->updateUMLClass(this->objectName, this->umlObject);
            // newly init everything
            this->initGui();
            // check for all overriden opeartions
            this->checkForOverrideOperationsNotification();
            // notify all other objects (related by the generalization) about possible overridness
            //*objects which starts the relation
            foreach (RelationGui *relation, this->relatedRelations)
            {
                if (relation->relType == UMLRelation::GENERALIZATION &&
                    relation->objectEnd->objectName == this->objectName)
                {
                    relation->objectStart->checkForOverrideOperationsNotification();
                }
            }

            update();
        }
        // TODO: Maybe delete dlg;
    }

    QGraphicsItem::mouseDoubleClickEvent(event);
}

void ObjectGUI::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    int diffX = event->scenePos().x() - this->prevMouseSceneX;
    int diffY = event->scenePos().y() - this->prevMouseSceneY;

    this->boundingX += event->pos().x() - this->prevMouseLocalX;
    this->boundingY += event->pos().y() - this->prevMouseLocalY;

    this->prevMouseSceneX = event->scenePos().x();
    this->prevMouseSceneY = event->scenePos().y();

    this->prevMouseLocalX = event->pos().x();
    this->prevMouseLocalY = event->pos().y();

    this->umlObject.Xcoord += diffX;
    this->umlObject.Ycoord += diffY;

    // std::cout << "Object gui X Y: " << this->umlObject.Xcoord << " " << this->umlObject.Ycoord << std::endl;

    // go through all related relations and notify them about moving
    QListIterator<RelationGui *> itr(this->relatedRelations);
    while (itr.hasNext())
    {
        itr.next()->updatePosition(this->umlObject, QPointF(
                                                        diffX,
                                                        diffY));
    }

    this->diagramInterface->scene->update();
    QGraphicsItem::mouseMoveEvent(event);
}

void ObjectGUI::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->diagramInterface->updateUMLClass(this->objectName, this->umlObject);
    QGraphicsItem::mouseReleaseEvent(event);
}

void ObjectGUI::checkForOverrideOperationsNotification()
{
    // check for all generalized opearations
    // firstly clear list with overridden opeartions
    this->overrideOperations.clear();
    // loop through the relation gui (related)
    foreach (RelationGui *relation, this->relatedRelations)
    {
        if (relation->relType == UMLRelation::GENERALIZATION && relation->objectStart->objectName == this->objectName)
        {
            // when generalization takes part and this object takes part as starter of the relation
            // iterate through all operations of the object, where the relation ends
            QMapIterator<UMLOperation, QString> itr(relation->objectEnd->operationMapGUI);
            while (itr.hasNext())
            {
                itr.next();
                // iterate through all operations of this object and look for the same operations
                QMapIterator<UMLOperation, QString> itrThis(this->operationMapGUI);
                while (itrThis.hasNext())
                {
                    itrThis.next();
                    // if found the same operation - OVERRIDE - add it to the list of overriden operations
                    if (itrThis.value() == itr.value())
                    {
                        this->overrideOperations.append(itrThis.key());
                    }
                }
            }
        }
    }

    // finally update
    update();
}

void ObjectGUI::normalizePointToEdge(QPointF *point)
{
    // intersects question
    // TODO
    bool end = false;
    int prevX = point->x();
    int prevY = point->y();

    bool leftEdgeX = false, rightEdgeX = false;
    bool upperEdgeY = false, bottomEdgeY = false;

    if (point->x() < this->umlObject.Xcoord + 10)
    {
        point->setX(this->umlObject.Xcoord);
        leftEdgeX = true;
    }
    else if (point->x() > this->umlObject.Xcoord + this->boundingWidth - 10)
    {
        point->setX(this->boundingX + this->boundingWidth);
        rightEdgeX = true;
    }

    if (end)
        return;

    if (point->y() < this->umlObject.Ycoord + 10)
    {
        point->setY(this->umlObject.Ycoord);
        upperEdgeY = true;
    }
    else if (point->y() > this->umlObject.Ycoord + this->boundingHeight - 10)
    {
        point->setY(this->umlObject.Ycoord + this->boundingHeight);
        bottomEdgeY = true;
    }

    if (leftEdgeX && upperEdgeY)
    {
        if (point->x() - this->umlObject.Xcoord > point->y() - this->umlObject.Ycoord)
            point->setX(prevX);
        else
            point->setY(prevY);
    }
    else if (leftEdgeX && bottomEdgeY)
    {
        if (point->x() - this->boundingX > point->y() - this->boundingY + this->boundingHeight)
            point->setX(prevX);
        else
            point->setY(prevY);
    }
    else if (rightEdgeX && upperEdgeY)
    {
        if (point->x() - this->umlObject.Xcoord + this->boundingWidth > point->y() - this->umlObject.Ycoord)
            point->setX(prevX);
        else
            point->setY(prevY);
    }
    else if (rightEdgeX && bottomEdgeY)
    {
        if (point->x() - this->umlObject.Xcoord + this->boundingWidth > point->y() - this->umlObject.Ycoord + this->boundingHeight)
            point->setX(prevX);
        else
            point->setY(prevY);
    }
}

ObjectGUI::~ObjectGUI()
{
}
