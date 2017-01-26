#ifndef PILE_H
#define PILE_H
#include <QLabel>
#include <QMouseEvent>
#include "rule.h"
#include "game.h"
class Card;

const int DRAGLAST = 6;
const int DROPLAST = 6;
enum pileType{FOUNDATION, STOCK, WASTE, TABLEAU,FREE_CELL};

class Pile :public QLabel // abstract base class for pile types
{
private:
    QPoint delta; //offset to next card in the pile
    Card *top;
    Card *bottom;

public:
    Pile(int x, int y, int dx, int dy, QWidget *parent);
    ~Pile();

    Card *Top(){return top;}
    Card *Bottom(){return bottom;}
    void AcceptCards(Card *c, bool expose = true, bool record = true);
    void ReleaseCards(Card *c, bool expose = true);
    QPoint Delta(){ return delta;}
    bool Empty(){return !bottom;}
    bool CanBeDragged(Card *c); //checks relavent rules for this pile
    bool CanBeDropped(Card *c); //checks relavent rules for this pile
    void FindClosestDrop(Card *c);
    void Deal(QMouseEvent *ev);
    void AddDropRules(int n...);
    void AddDragRules(int n...);

    virtual Rule * DragRule(int i)=0;
    virtual void DragRule(int i, Rule *r)=0;
    virtual Rule *DropRule(int i)=0;
    virtual void DropRule(int i, Rule *r)=0;
    virtual pileType Type()=0;

    //void mouseReleaseEvent(QMouseEvent *);
    virtual void onClickEvent(Card *){} //override as needed
    virtual void mouseDoubleClickEvent(Card *){} //override as needed
};
/*
// Inheriting classes that differ in rules
class PileStock: public Pile
{
private:
    static Rule *dragRules[DRAGLAST];
    static Rule *dropRules[DROPLAST];
public:
    Rule * DragRule(int i);
    void DragRule(int i, Rule *r);
    Rule *DropRule(int i);
    void DropRule(int i, Rule *r);
    pileType Type();
    void onClickEvent(Card *);
    void mouseDoubleClickEvent(Card *);
};


class PileFoundation: public Pile
{
private:
    static Rule *dragRules[DRAGLAST];
    static Rule *dropRules[DROPLAST];
public:
    Rule * DragRule(int i);
    void DragRule(int i, Rule *r);
    Rule *DropRule(int i);
    void DropRule(int i, Rule *r);
    pileType Type();
    void onClickEvent(Card *);
    void mouseDoubleClickEvent(Card *);
};
*/
#if(0)
class PileTableau:public Pile
{
    //TODO
};
class PileFreeCell:public Pile
{
    //TODO
};
class PileWaste:public Pile
{
    //TODO
};
#endif


#endif // PILE_H