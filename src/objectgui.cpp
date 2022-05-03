#include "objectgui.h"
#include "diagraminterface.h"
#include "controllers/editobjectdialog.h"
#include "dialogs/askdialog.h"

#include <QGraphicsSceneMouseEvent>
ObjectGUI::ObjectGUI(UMLClass umlClass) : umlClass("")
{
    // make the object movable
    setFlag(QGraphicsItem::ItemIsMovable);

    // set whether it is selected or not
    this->isSelected = false;

    // set the uml class
    // there is a default initialize at the beggining of this function, but the class cant be without a name
    this->umlClass = umlClass;

    // set gui coordinates of the object
    this->boundingHeight = 100;
    this->boundingWidth = 100;
    this->boundingX = 50;
    this->boundingY = 50;
}

QRectF ObjectGUI::boundingRect() const
{
    return QRectF(this->boundingX, this->boundingY, this->boundingWidth, this->boundingHeight);
}

void ObjectGUI::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush(Qt::blue);
    QPen pen(Qt::black);

    // test
    QList<QString> list;
    list.append("first param");
    list.append("long paramaaaaaaaaaaaaaaaaaaaaaaa");
    list.append("third param");

    // handle whether it is selected or not
    if (this->isSelected)
    {
        brush.setColor(Qt::red);
    }
    else
    {
        brush.setColor(Qt::blue);
    }
    painter->fillRect(rec, brush);

    painter->fillRect(10 + this->boundingX,this->boundingY + 10, this->boundingWidth - 10 - this->boundingX, this->boundingHeight-10 - this->boundingY, Qt::yellow);

    // draw name of the class/interface
    painter->drawText(this->boundingX + int(this->boundingWidth / 2) - 30, this->boundingY + 20, "First class");
    // first line - space between object name and
    painter->drawLine(this->boundingX + 0, this->boundingY + 40, this->boundingX + this->boundingWidth, this->boundingY + 40);

    // add attributes
    int currentHeight = 55;

    for (QString attr : list)
    {
        // resize the box if the attributes are widther
        if (int(attr.size() * 5) > boundingWidth)
        {
            this->boundingWidth = int(attr.size() * 9) + 10;
            rec = boundingRect();
        }

        // draw the text of attr at sufficient possition
        painter->drawText(this->boundingX + 10, this->boundingY + currentHeight, attr);
        currentHeight += 15; // increase the Y axis, where the next element will be stored

        // check, whether the position for the next element doesnt go out of the bound
        if (currentHeight >= this->boundingHeight)
        {
            this->boundingHeight = currentHeight + 30;
            rec = boundingRect();
        }
    }

    // second line - space between attributes and operations
    painter->drawLine(this->boundingX + 0, this->boundingY + currentHeight, this->boundingX + this->boundingWidth, this->boundingY + currentHeight);

    // finally draw the main - bounding - rectangle
    painter->drawRect(rec);
}

void ObjectGUI::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->isSelected = !isSelected;

    std::cout << event->scenePos().x() << "  ahoj" << std::endl;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void ObjectGUI::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    int maxX = this->boundingWidth;
    int maxY = this->boundingHeight;
    bool isInX = (((event->pos().x()-this->boundingX) >= 10) && ((maxX - 10) >= (event->pos().x()-this->boundingX)));
    bool isInY = (((event->pos().y()-this->boundingY) >= 10) && ((maxY - 10) >= (event->pos().y() - this->boundingY)));
    std::cout << "X pos" << event->pos().x()-this->boundingX << "  " << maxX  << isInX <<std::endl;
    std::cout << "Y pos" << event->pos().y() -this->boundingY << "   " << maxY<< isInY << std::endl;

    if (!(isInX && isInY))
    {
        AskDialog *dialog = new AskDialog();
        // dialog.setWordCount(document().wordCount());
        bool wants = dialog->exec();
        return;
    }
    else
    {
        // create new dialog, wait for response
        EditObjectDialog *dlg = new EditObjectDialog();
        dlg->show();
    }

    QGraphicsItem::mouseDoubleClickEvent(event);
}

ObjectGUI::~ObjectGUI()
{
}
