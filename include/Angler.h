#ifndef ANGLER_H
#define ANGLER_H

//fwd declaration
class App;

//represents the user (angler)
class Angler {
public:
  //angler interacts with app)
  void interactWithApp(App& application);
};

#endif