qtdemo
======
说明：通过QT的UI designer设计界面，所有界面相关的都是用QT实现；所有非界面相关的用C++实现，所有与底层相关的，
增加了porting层，在porting层里面进行对不同操作系统接口的封装。

这里面我写了thread类，该类是针对线程进行的类封装，会调用porting层里的thread接口，如果要将该类移植到Linux上，
只需要将porting层里的thread接口替换成Linux实现即可。
tcpClient类是这里与操作系统无关、与UI实现无关的逻辑类，这里应该完成咱们要做的真正工作。
