#ifndef ANGLER_H
#define ANGLER_H

// Forward declaration
class App;

class Angler {
public:
  // Method might be used conceptually or to trigger the app
  void interactWithApp(App &application); // Takes App by reference perhaps
};

#endif // ANGLER_H