---
title: Classe lock
ms.date: 01/16/2019
ms.topic: reference
f1_keywords:
- msclr::lock::lock
- msclr::lock::is_locked
- msclr::lock.is_locked
- msclr::lock::acquire
- msclr::lock::try_acquire
- msclr::lock::release
- msclr::lock::operator==
- msclr::lock::operator!=
helpviewer_keywords:
- msclr::lock class
ms.assetid: 5123edd9-6aed-497d-9a0b-f4b6d6c0d666
ms.openlocfilehash: 7b2f187ec940af95523d0bbfb9265d7d9d6f69e8
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91508649"
---
# <a name="lock-class"></a>Classe lock

Essa classe automatiza a obtenção de um bloqueio para sincronizar o acesso a um objeto de vários threads.  Quando construída, ele adquire o bloqueio e, quando destruído, libera o bloqueio.

## <a name="syntax"></a>Sintaxe

```cpp
ref class lock;
```

## <a name="remarks"></a>Comentários

`lock` está disponível somente para objetos CLR e só pode ser usada em código CLR.

Internamente, a classe de bloqueio usa <xref:System.Threading.Monitor> para sincronizar o acesso. Para obter mais informações, consulte o artigo referenciado.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|---------|-----------|
|[lock::lock](#lock)|Constrói um `lock` objeto, opcionalmente esperando para adquirir o bloqueio para sempre, por um período de tempo especificado ou não.|
|[bloqueio:: ~ bloquear](#tilde-lock)|Destrui um `lock` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|---------|-----------|
|[lock::acquire](#acquire)|Adquire um bloqueio em um objeto, opcionalmente esperando para adquirir o bloqueio para sempre, por um período de tempo especificado ou não.|
|[lock::is_locked](#is-locked)|Indica se um bloqueio está sendo mantido.|
|[lock::release](#release)|Libera um bloqueio.|
|[lock::try_acquire](#try-acquire)|Adquire um bloqueio em um objeto, aguardando um período de tempo especificado e retornando um **`bool`** para relatar o sucesso da aquisição em vez de lançar uma exceção.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|---------|-----------|
|[booliano de Lock:: Operator &nbsp;](#operator-bool)|Operador para usar `lock` em uma expressão condicional.|
|[lock::operator==](#operator-equality)|Operador de igualdade.|
|[Lock:: Operator! =](#operator-inequality)|Operador de desigualdade.|

## <a name="requirements"></a>Requisitos

**Arquivo de cabeçalho** \<msclr\lock.h>

Msclr de **namespace**

## <a name="locklock"></a><a name="lock"></a> Bloquear:: bloquear

Constrói um `lock` objeto, opcionalmente esperando para adquirir o bloqueio para sempre, por um período de tempo especificado ou não.

```cpp
template<class T> lock(
   T ^ _object
);
template<class T> lock(
   T ^ _object,
   int _timeout
);
template<class T> lock(
   T ^ _object,
   System::TimeSpan _timeout
);
template<class T> lock(
   T ^ _object,
   lock_later
);
```

### <a name="parameters"></a>Parâmetros

*_object*<br/>
O objeto a ser bloqueado.

*_timeout*<br/>
Valor de tempo limite em milissegundos ou como um <xref:System.TimeSpan> .

### <a name="exceptions"></a>Exceções

Gera <xref:System.ApplicationException> se a aquisição de bloqueio não ocorre antes do tempo limite.

### <a name="remarks"></a>Comentários

As três primeiras formas do Construtor tentam adquirir um bloqueio no `_object` período de tempo limite especificado (ou <xref:System.Threading.Timeout.Infinite> se nenhum for especificado).

A quarta forma do construtor não adquire um bloqueio `_object` . `lock_later` é um membro da [enumeração lock_when](../dotnet/lock-when-enum.md). Use [Lock:: Acquire](#acquire) ou [lock:: try_acquire](#try-acquire) para adquirir o bloqueio nesse caso.

O bloqueio será liberado automaticamente quando o destruidor for chamado.

`_object` Não pode ser <xref:System.Threading.ReaderWriterLock> .  Se for, será resultado um erro do compilador.

### <a name="example"></a>Exemplo

Este exemplo usa uma única instância de uma classe em vários threads. A classe usa um bloqueio em si mesmo para garantir que os acessos aos seus dados internos sejam consistentes para cada thread. O thread do aplicativo principal usa um bloqueio na mesma instância da classe para verificar periodicamente se algum thread de trabalho ainda existe. O aplicativo principal aguardará a saída até que todos os threads de trabalho tenham concluído suas tarefas.

```cpp
// msl_lock_lock.cpp
// compile with: /clr
#include <msclr/lock.h>

using namespace System;
using namespace System::Threading;
using namespace msclr;

ref class CounterClass {
private:
   int Counter;

public:
   property int ThreadCount;

   // function called by multiple threads, use lock to keep Counter consistent
   // for each thread
   void UseCounter() {
      try {
         lock l(this); // wait infinitely

         Console::WriteLine("In thread {0}, Counter = {1}", Thread::CurrentThread->ManagedThreadId,
            Counter);

         for (int i = 0; i < 10; i++) {
            Counter++;
            Thread::Sleep(10);
         }

         Console::WriteLine("In thread {0}, Counter = {1}", Thread::CurrentThread->ManagedThreadId,
            Counter);

         Counter = 0;
         // lock is automatically released when it goes out of scope and its destructor is called
      }
      catch (...) {
         Console::WriteLine("Couldn't acquire lock!");
      }

      ThreadCount--;
   }
};

int main() {
   // create a few threads to contend for access to the shared data
   CounterClass^ cc = gcnew CounterClass;
   array<Thread^>^ tarr = gcnew array<Thread^>(5);
   ThreadStart^ startDelegate = gcnew ThreadStart(cc, &CounterClass::UseCounter);
   for (int i = 0; i < tarr->Length; i++) {
      tarr[i] = gcnew Thread(startDelegate);
      cc->ThreadCount++;
      tarr[i]->Start();
   }

   // keep our main thread alive until all worker threads have completed
   lock l(cc, lock_later); // don't lock now, just create the object
   while (true) {
      if (l.try_acquire(50)) { // try to acquire lock, don't throw an exception if can't
         if (0 == cc->ThreadCount) {
            Console::WriteLine("All threads completed.");
            break; // all threads are gone, exit while
         }
         else {
            Console::WriteLine("{0} threads exist, continue waiting...", cc->ThreadCount);
            l.release(); // some threads exist, let them do their work
         }
      }
   }
}
```

```Output
In thread 3, Counter = 0
In thread 3, Counter = 10
In thread 5, Counter = 0
In thread 5, Counter = 10
In thread 7, Counter = 0
In thread 7, Counter = 10
In thread 4, Counter = 0
In thread 4, Counter = 10
In thread 6, Counter = 0
In thread 6, Counter = 10
All threads completed.
```

## <a name="locklock"></a><a name="tilde-lock"></a> bloqueio:: ~ bloquear

Destrui um `lock` objeto.

```cpp
~lock();
```

### <a name="remarks"></a>Comentários

O destruidor chama [Lock:: Release](#release).

### <a name="example"></a>Exemplo

Este exemplo usa uma única instância de uma classe em vários threads.  A classe usa um bloqueio em si mesmo para garantir que os acessos aos seus dados internos sejam consistentes para cada thread.  O thread do aplicativo principal usa um bloqueio na mesma instância da classe para verificar periodicamente se algum thread de trabalho ainda existe. O aplicativo principal aguardará a saída até que todos os threads de trabalho tenham concluído suas tarefas.

```cpp
// msl_lock_dtor.cpp
// compile with: /clr
#include <msclr/lock.h>

using namespace System;
using namespace System::Threading;
using namespace msclr;

ref class CounterClass {
private:
   int Counter;

public:
   property int ThreadCount;

   // function called by multiple threads, use lock to keep Counter consistent
   // for each thread
   void UseCounter() {
      try {
         lock l(this); // wait infinitely

         Console::WriteLine("In thread {0}, Counter = {1}", Thread::CurrentThread->ManagedThreadId,
            Counter);

         for (int i = 0; i < 10; i++) {
            Counter++;
            Thread::Sleep(10);
         }

         Console::WriteLine("In thread {0}, Counter = {1}", Thread::CurrentThread->ManagedThreadId,
            Counter);

         Counter = 0;
         // lock is automatically released when it goes out of scope and its destructor is called
      }
      catch (...) {
         Console::WriteLine("Couldn't acquire lock!");
      }

      ThreadCount--;
   }
};

int main() {
   // create a few threads to contend for access to the shared data
   CounterClass^ cc = gcnew CounterClass;
   array<Thread^>^ tarr = gcnew array<Thread^>(5);
   ThreadStart^ startDelegate = gcnew ThreadStart(cc, &CounterClass::UseCounter);
   for (int i = 0; i < tarr->Length; i++) {
      tarr[i] = gcnew Thread(startDelegate);
      cc->ThreadCount++;
      tarr[i]->Start();
   }

   // keep our main thread alive until all worker threads have completed
   lock l(cc, lock_later); // don't lock now, just create the object
   while (true) {
      if (l.try_acquire(50)) { // try to acquire lock, don't throw an exception if can't
         if (0 == cc->ThreadCount) {
            Console::WriteLine("All threads completed.");
            break; // all threads are gone, exit while
         }
         else {
            Console::WriteLine("{0} threads exist, continue waiting...", cc->ThreadCount);
            l.release(); // some threads exist, let them do their work
         }
      }
   }
}
```

```Output
In thread 3, Counter = 0
In thread 3, Counter = 10
In thread 5, Counter = 0
In thread 5, Counter = 10
In thread 7, Counter = 0
In thread 7, Counter = 10
In thread 4, Counter = 0
In thread 4, Counter = 10
In thread 6, Counter = 0
In thread 6, Counter = 10
All threads completed.
```

## <a name="lockacquire"></a><a name="acquire"></a> Bloquear:: adquirir

Adquire um bloqueio em um objeto, opcionalmente esperando para adquirir o bloqueio para sempre, por um período de tempo especificado ou não.

```cpp
void acquire();
void acquire(
   int _timeout
);
void acquire(
   System::TimeSpan _timeout
);
```

### <a name="parameters"></a>Parâmetros

*_timeout*<br/>
Valor de tempo limite em milissegundos ou como um <xref:System.TimeSpan> .

### <a name="exceptions"></a>Exceções

Gera <xref:System.ApplicationException> se a aquisição de bloqueio não ocorre antes do tempo limite.

### <a name="remarks"></a>Comentários

Se um valor de tempo limite não for fornecido, o tempo limite padrão será <xref:System.Threading.Timeout.Infinite> .

Se um bloqueio já tiver sido adquirido, essa função não fará nada.

### <a name="example"></a>Exemplo

Este exemplo usa uma única instância de uma classe em vários threads.  A classe usa um bloqueio em si mesmo para garantir que os acessos aos seus dados internos sejam consistentes para cada thread. O thread do aplicativo principal usa um bloqueio na mesma instância da classe para verificar periodicamente se algum thread de trabalho ainda existe. O aplicativo principal aguardará a saída até que todos os threads de trabalho tenham concluído suas tarefas.

```cpp
// msl_lock_acquire.cpp
// compile with: /clr
#include <msclr/lock.h>

using namespace System;
using namespace System::Threading;
using namespace msclr;

ref class CounterClass {
private:
   int Counter;

public:
   property int ThreadCount;

   // function called by multiple threads, use lock to keep Counter consistent
   // for each thread
   void UseCounter() {
      try {
         lock l(this); // wait infinitely

         Console::WriteLine("In thread {0}, Counter = {1}", Thread::CurrentThread->ManagedThreadId,
            Counter);

         for (int i = 0; i < 10; i++) {
            Counter++;
            Thread::Sleep(10);
         }

         Console::WriteLine("In thread {0}, Counter = {1}", Thread::CurrentThread->ManagedThreadId,
            Counter);

         Counter = 0;
         // lock is automatically released when it goes out of scope and its destructor is called
      }
      catch (...) {
         Console::WriteLine("Couldn't acquire lock!");
      }

      ThreadCount--;
   }
};

int main() {
   // create a few threads to contend for access to the shared data
   CounterClass^ cc = gcnew CounterClass;
   array<Thread^>^ tarr = gcnew array<Thread^>(5);
   ThreadStart^ startDelegate = gcnew ThreadStart(cc, &CounterClass::UseCounter);
   for (int i = 0; i < tarr->Length; i++) {
      tarr[i] = gcnew Thread(startDelegate);
      cc->ThreadCount++;
      tarr[i]->Start();
   }

   // keep our main thread alive until all worker threads have completed
   lock l(cc, lock_later); // don't lock now, just create the object
   while (true) {
      if (l.try_acquire(50)) { // try to acquire lock, don't throw an exception if can't
         if (0 == cc->ThreadCount) {
            Console::WriteLine("All threads completed.");
            break; // all threads are gone, exit while
         }
         else {
            Console::WriteLine("{0} threads exist, continue waiting...", cc->ThreadCount);
            l.release(); // some threads exist, let them do their work
         }
      }
   }
}
```

```Output
In thread 3, Counter = 0
In thread 3, Counter = 10
In thread 5, Counter = 0
In thread 5, Counter = 10
In thread 7, Counter = 0
In thread 7, Counter = 10
In thread 4, Counter = 0
In thread 4, Counter = 10
In thread 6, Counter = 0
In thread 6, Counter = 10
All threads completed.
```

## <a name="lockis_locked"></a><a name="is-locked"></a> Bloquear:: is_locked

Indica se um bloqueio está sendo mantido.

```cpp
bool is_locked();
```

### <a name="return-value"></a>Valor retornado

**`true`** se um bloqueio for mantido, **`false`** caso contrário.

### <a name="example"></a>Exemplo

Este exemplo usa uma única instância de uma classe em vários threads.  A classe usa um bloqueio em si mesmo para garantir que os acessos aos seus dados internos sejam consistentes para cada thread.  O thread do aplicativo principal usa um bloqueio na mesma instância da classe para verificar periodicamente se algum thread de trabalho ainda existe e aguarda a saída até que todos os threads de trabalho tenham concluído suas tarefas.

```cpp
// msl_lock_is_locked.cpp
// compile with: /clr
#include <msclr/lock.h>

using namespace System;
using namespace System::Threading;
using namespace msclr;

ref class CounterClass {
private:
   int Counter;

public:
   property int ThreadCount;

   // function called by multiple threads, use lock to keep Counter consistent
   // for each thread
   void UseCounter() {
      try {
         lock l(this); // wait infinitely

         Console::WriteLine("In thread {0}, Counter = {1}", Thread::CurrentThread->ManagedThreadId,
            Counter);

         for (int i = 0; i < 10; i++) {
            Counter++;
            Thread::Sleep(10);
         }

         Console::WriteLine("In thread {0}, Counter = {1}", Thread::CurrentThread->ManagedThreadId,
            Counter);

         Counter = 0;
         // lock is automatically released when it goes out of scope and its destructor is called
      }
      catch (...) {
         Console::WriteLine("Couldn't acquire lock!");
      }

      ThreadCount--;
   }
};

int main() {
   // create a few threads to contend for access to the shared data
   CounterClass^ cc = gcnew CounterClass;
   array<Thread^>^ tarr = gcnew array<Thread^>(5);
   ThreadStart^ startDelegate = gcnew ThreadStart(cc, &CounterClass::UseCounter);
   for (int i = 0; i < tarr->Length; i++) {
      tarr[i] = gcnew Thread(startDelegate);
      cc->ThreadCount++;
      tarr[i]->Start();
   }

   // keep our main thread alive until all worker threads have completed
   lock l(cc, lock_later); // don't lock now, just create the object
   while (true) {
      l.try_acquire(50); // try to acquire lock, don't throw an exception if can't
      if (l.is_locked()) { // check if we got the lock
         if (0 == cc->ThreadCount) {
            Console::WriteLine("All threads completed.");
            break; // all threads are gone, exit while
         }
         else {
            Console::WriteLine("{0} threads exist, continue waiting...", cc->ThreadCount);
            l.release(); // some threads exist, let them do their work
         }
      }
   }
}
```

```Output
In thread 3, Counter = 0
In thread 3, Counter = 10
In thread 5, Counter = 0
In thread 5, Counter = 10
In thread 4, Counter = 0
In thread 4, Counter = 10
In thread 7, Counter = 0
In thread 7, Counter = 10
In thread 6, Counter = 0
In thread 6, Counter = 10
All threads completed.
```

## <a name="lockoperator-bool"></a><a name="operator-bool"></a> booliano de Lock:: Operator

Operador para usar `lock` em uma expressão condicional.

```cpp
operator bool();
```

### <a name="return-value"></a>Valor retornado

**`true`** se um bloqueio for mantido, **`false`** caso contrário.

### <a name="remarks"></a>Comentários

Esse operador realmente converte o `_detail_class::_safe_bool` que é mais seguro do que **`bool`** porque não pode ser convertido em um tipo integral.

### <a name="example"></a>Exemplo

Este exemplo usa uma única instância de uma classe em vários threads.  A classe usa um bloqueio em si mesmo para garantir que os acessos aos seus dados internos sejam consistentes para cada thread. O thread do aplicativo principal usa um bloqueio na mesma instância da classe para verificar periodicamente se algum thread de trabalho ainda existe. O aplicativo principal aguarda para sair até que todos os threads de trabalho tenham concluído suas tarefas.

```cpp
// msl_lock_op_bool.cpp
// compile with: /clr
#include <msclr/lock.h>

using namespace System;
using namespace System::Threading;
using namespace msclr;

ref class CounterClass {
private:
   int Counter;

public:
   property int ThreadCount;

   // function called by multiple threads, use lock to keep Counter consistent
   // for each thread
   void UseCounter() {
      try {
         lock l(this); // wait infinitely

         Console::WriteLine("In thread {0}, Counter = {1}", Thread::CurrentThread->ManagedThreadId,
            Counter);

         for (int i = 0; i < 10; i++) {
            Counter++;
            Thread::Sleep(10);
         }

         Console::WriteLine("In thread {0}, Counter = {1}", Thread::CurrentThread->ManagedThreadId,
            Counter);

         Counter = 0;
         // lock is automatically released when it goes out of scope and its destructor is called
      }
      catch (...) {
         Console::WriteLine("Couldn't acquire lock!");
      }

      ThreadCount--;
   }
};

int main() {
   // create a few threads to contend for access to the shared data
   CounterClass^ cc = gcnew CounterClass;
   array<Thread^>^ tarr = gcnew array<Thread^>(5);
   ThreadStart^ startDelegate = gcnew ThreadStart(cc, &CounterClass::UseCounter);
   for (int i = 0; i < tarr->Length; i++) {
      tarr[i] = gcnew Thread(startDelegate);
      cc->ThreadCount++;
      tarr[i]->Start();
   }

   // keep our main thread alive until all worker threads have completed
   lock l(cc, lock_later); // don't lock now, just create the object
   while (true) {
      l.try_acquire(50); // try to acquire lock, don't throw an exception if can't
      if (l) { // use bool operator to check for lock
         if (0 == cc->ThreadCount) {
            Console::WriteLine("All threads completed.");
            break; // all threads are gone, exit while
         }
         else {
            Console::WriteLine("{0} threads exist, continue waiting...", cc->ThreadCount);
            l.release(); // some threads exist, let them do their work
         }
      }
   }
}
```

```Output
In thread 3, Counter = 0
In thread 3, Counter = 10
In thread 5, Counter = 0
In thread 5, Counter = 10
In thread 7, Counter = 0
In thread 7, Counter = 10
In thread 4, Counter = 0
In thread 4, Counter = 10
In thread 6, Counter = 0
In thread 6, Counter = 10
All threads completed.
```

## <a name="lockrelease"></a><a name="release"></a> bloqueio:: versão

Libera um bloqueio.

```cpp
void release();
```

### <a name="remarks"></a>Comentários

Se nenhum bloqueio estiver sendo mantido, `release` não fará nada.

Você não precisa chamar essa função explicitamente. Quando um `lock` objeto sai do escopo, seu destruidor chama `release` .

### <a name="example"></a>Exemplo

Este exemplo usa uma única instância de uma classe em vários threads. A classe usa um bloqueio em si mesmo para garantir que os acessos aos seus dados internos sejam consistentes para cada thread. O thread do aplicativo principal usa um bloqueio na mesma instância da classe para verificar periodicamente se algum thread de trabalho ainda existe. O aplicativo principal aguardará a saída até que todos os threads de trabalho tenham concluído suas tarefas.

```cpp
// msl_lock_release.cpp
// compile with: /clr
#include <msclr/lock.h>

using namespace System;
using namespace System::Threading;
using namespace msclr;

ref class CounterClass {
private:
   int Counter;

public:
   property int ThreadCount;

   // function called by multiple threads, use lock to keep Counter consistent
   // for each thread
   void UseCounter() {
      try {
         lock l(this); // wait infinitely

         Console::WriteLine("In thread {0}, Counter = {1}", Thread::CurrentThread->ManagedThreadId,
            Counter);

         for (int i = 0; i < 10; i++) {
            Counter++;
            Thread::Sleep(10);
         }

         Console::WriteLine("In thread {0}, Counter = {1}", Thread::CurrentThread->ManagedThreadId,
            Counter);

         Counter = 0;
         // lock is automatically released when it goes out of scope and its destructor is called
      }
      catch (...) {
         Console::WriteLine("Couldn't acquire lock!");
      }

      ThreadCount--;
   }
};

int main() {
   // create a few threads to contend for access to the shared data
   CounterClass^ cc = gcnew CounterClass;
   array<Thread^>^ tarr = gcnew array<Thread^>(5);
   ThreadStart^ startDelegate = gcnew ThreadStart(cc, &CounterClass::UseCounter);
   for (int i = 0; i < tarr->Length; i++) {
      tarr[i] = gcnew Thread(startDelegate);
      cc->ThreadCount++;
      tarr[i]->Start();
   }

   // keep our main thread alive until all worker threads have completed
   lock l(cc, lock_later); // don't lock now, just create the object
   while (true) {
      if (l.try_acquire(50)) { // try to acquire lock, don't throw an exception if can't
         if (0 == cc->ThreadCount) {
            Console::WriteLine("All threads completed.");
            break; // all threads are gone, exit while
         }
         else {
            Console::WriteLine("{0} threads exist, continue waiting...", cc->ThreadCount);
            l.release(); // some threads exist, let them do their work
         }
      }
   }
}
```

```Output
In thread 3, Counter = 0
In thread 3, Counter = 10
In thread 5, Counter = 0
In thread 5, Counter = 10
In thread 7, Counter = 0
In thread 7, Counter = 10
In thread 4, Counter = 0
In thread 4, Counter = 10
In thread 6, Counter = 0
In thread 6, Counter = 10
All threads completed.
```

## <a name="locktry_acquire"></a><a name="try-acquire"></a> Bloquear:: try_acquire

Adquire um bloqueio em um objeto, aguardando um período de tempo especificado e retornando um **`bool`** para relatar o sucesso da aquisição em vez de lançar uma exceção.

```cpp
bool try_acquire(
   int _timeout_ms
);
bool try_acquire(
   System::TimeSpan _timeout
);
```

### <a name="parameters"></a>Parâmetros

*_timeout*<br/>
Valor de tempo limite em milissegundos ou como um <xref:System.TimeSpan> .

### <a name="return-value"></a>Valor retornado

**`true`** caso o bloqueio tenha sido adquirido, **`false`** caso contrário.

### <a name="remarks"></a>Comentários

Se um bloqueio já tiver sido adquirido, essa função não fará nada.

### <a name="example"></a>Exemplo

Este exemplo usa uma única instância de uma classe em vários threads. A classe usa um bloqueio em si mesmo para garantir que os acessos aos seus dados internos sejam consistentes para cada thread. O thread do aplicativo principal usa um bloqueio na mesma instância da classe para verificar periodicamente se algum thread de trabalho ainda existe. O aplicativo principal aguardará a saída até que todos os threads de trabalho tenham concluído suas tarefas.

```cpp
// msl_lock_try_acquire.cpp
// compile with: /clr
#include <msclr/lock.h>

using namespace System;
using namespace System::Threading;
using namespace msclr;

ref class CounterClass {
private:
   int Counter;

public:
   property int ThreadCount;

   // function called by multiple threads, use lock to keep Counter consistent
   // for each thread
   void UseCounter() {
      try {
         lock l(this); // wait infinitely

         Console::WriteLine("In thread {0}, Counter = {1}", Thread::CurrentThread->ManagedThreadId,
            Counter);

         for (int i = 0; i < 10; i++) {
            Counter++;
            Thread::Sleep(10);
         }

         Console::WriteLine("In thread {0}, Counter = {1}", Thread::CurrentThread->ManagedThreadId,
            Counter);

         Counter = 0;
         // lock is automatically released when it goes out of scope and its destructor is called
      }
      catch (...) {
         Console::WriteLine("Couldn't acquire lock!");
      }

      ThreadCount--;
   }
};

int main() {
   // create a few threads to contend for access to the shared data
   CounterClass^ cc = gcnew CounterClass;
   array<Thread^>^ tarr = gcnew array<Thread^>(5);
   ThreadStart^ startDelegate = gcnew ThreadStart(cc, &CounterClass::UseCounter);
   for (int i = 0; i < tarr->Length; i++) {
      tarr[i] = gcnew Thread(startDelegate);
      cc->ThreadCount++;
      tarr[i]->Start();
   }

   // keep our main thread alive until all worker threads have completed
   lock l(cc, lock_later); // don't lock now, just create the object
   while (true) {
      if (l.try_acquire(50)) { // try to acquire lock, don't throw an exception if can't
         if (0 == cc->ThreadCount) {
            Console::WriteLine("All threads completed.");
            break; // all threads are gone, exit while
         }
         else {
            Console::WriteLine("{0} threads exist, continue waiting...", cc->ThreadCount);
            l.release(); // some threads exist, let them do their work
         }
      }
   }
}
```

```Output
In thread 3, Counter = 0
In thread 3, Counter = 10
In thread 5, Counter = 0
In thread 5, Counter = 10
In thread 7, Counter = 0
In thread 7, Counter = 10
In thread 4, Counter = 0
In thread 4, Counter = 10
In thread 6, Counter = 0
In thread 6, Counter = 10
All threads completed.
```

## <a name="lockoperator"></a><a name="operator-equality"></a> Lock:: Operator = =

Operador de igualdade.

```cpp
template<class T> bool operator==(
   T t
);
```

### <a name="parameters"></a>Parâmetros

*t*<br/>
A igualdade de um objeto a ser comparado.

### <a name="return-value"></a>Valor retornado

Retorna **`true`** se `t` é o mesmo que o objeto do bloqueio, **`false`** caso contrário.

### <a name="example"></a>Exemplo

```cpp
// msl_lock_op_eq.cpp
// compile with: /clr
#include <msclr/lock.h>

using namespace System;
using namespace System::Threading;
using namespace msclr;

int main () {
   Object^ o1 = gcnew Object;
   lock l1(o1);
   if (l1 == o1) {
      Console::WriteLine("Equal!");
   }
}
```

```Output
Equal!
```

## <a name="lockoperator"></a><a name="operator-inequality"></a> Lock:: Operator! =

Operador de desigualdade.

```cpp
template<class T> bool operator!=(
   T t
);
```

### <a name="parameters"></a>Parâmetros

*t*<br/>
O objeto a ser comparado para desigualdade.

### <a name="return-value"></a>Valor retornado

Retorna **`true`** se for `t` diferente do objeto do bloqueio, **`false`** caso contrário.

### <a name="example"></a>Exemplo

```cpp
// msl_lock_op_ineq.cpp
// compile with: /clr
#include <msclr/lock.h>

using namespace System;
using namespace System::Threading;
using namespace msclr;

int main () {
   Object^ o1 = gcnew Object;
   Object^ o2 = gcnew Object;
   lock l1(o1);
   if (l1 != o2) {
      Console::WriteLine("Inequal!");
   }
}
```

```Output
Inequal!
```
