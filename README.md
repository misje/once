# once

Sometimes you want to connect a slot or a functor to a Qt signal and only have it be called once. Adding the necessary logic to enable this can mess up the code unnecessarily, especially with lambdas, since a connection handle is needed to disconnect them.

This tiny framework provides connect functions argument-compatible with the QObject::connect series that will call the slot or functor only once. The logic is simple:
- Create a pointer that will store the connection handle returned from QObject::connect
- Capture this pointer in a wrapper function
- Connect the passed signal to call the wrapper function
- Disconnect the connection inside the wrapper function and then call the passed functor or slot

Although the fire-once-only logic is simple, additional logic and template code is needed since Once::connect needs to work like QObject::connect: accept all kinds of functors, lambda and slots and conveniently discard superfluous signal arguments. The implementation allows perfect forwarding of arguments and, although it can probably be simplified, should work just as QObject::connect does.

## Methods
The following methods are available. Note that the function signature is simplified for readability. Remember that a slot also can be a signal.

```cpp
/* Call functor when signal is emitted from sender and disconnect it
   immediately afterwards */
QMetaObject::Connection Once::connect(const QObject *sender, Signal signal,
      Functor functor)

/* Call functor when signal is emitted from sender in the given context, using
   the given connection type. Disconnect functor immediately afterwards. */
QMetaObject::Connection Once::connect(const QObject *sender, Signal signal,
      const QObject *context, Functor functor, Qt::ConnectionType type =
      Qt::AutoConnection)

/* Call functor when signal is emitted from sender and disconnect it after N
   calls, specified by callCount. */
QMetaObject::Connection Once::connect(const QObject *sender, Signal signal, int
      callCount, Functor functor)

/* Call functor when signal is emitted from sender in the given context, using
   the given connection type. Disconnect functor after N calls, specified by
   callCount. */
QMetaObject::Connection Once::connect(const QObject *sender, Signal signal, int
      callCount, const QObject *context, Functor functor, Qt::ConnectionType
      type = Qt::AutoConnection)

/* Call member function when signal is emitted from sender (in the context of
   receiver), using the given connection type. Disconnect the slot immediately
   afterwards. */
QMetaObject::Connection Once::connect(const QObject *sender, Signal signal,
      const QObject *receiver, Slot slot, Qt::ConnectionType type =
      Qt::AutoConnection)

/* Call member function when signal is emitted from sender (in the context of
   receiver), using the given connection type. Disconnect the slot after N
   calls, specified by callCount. */
QMetaObject::Connection Once::connect(const QObject *sender, Signal signal, int
      callCount, const QObject *receiver, Slot slot, Qt::ConnectionType type =
      Qt::AutoConnection)
```
