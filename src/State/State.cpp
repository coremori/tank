/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

namespace State {

  /// class State - mobiles-> liste des truc mobile (tank, misile)
grid -> surface
  class State : public State::Observable {
    // Associations
    // Attributes
  protected:
    ElementList mobiles;
    ElementGrid grid;
    // Operations
  public:
    State ();
    ~State ();
    State* const clone ();
    bool const equals (const State& other);
    const ElementGrid& const getGrid ();
    ElementGrid& getGrid ();
    const ElementList& const getMobiles ();
    ElementList& getMobiles ();
    const MobileElement* const getMobile ( int idx);
    MobileElement* getMobile ( int idx);
    void setGrid (const ElementGrid& grid);
    void setMobiles (const ElementList list);
    void loadLevel (const char* file_name);
    void setElementFactory (ElementFactory* factory);
    void const notifyObservers (StateEventId id);
    void const notifyObservers (const StateEvent& e);
  };

};

