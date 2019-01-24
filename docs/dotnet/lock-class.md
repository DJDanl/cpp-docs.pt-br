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
ms.openlocfilehash: 43418da36aa2d87608a9d672e4345d24011be0b3
ms.sourcegitcommit: 9813e146a4eb30929d8352872859e8fcb7ff6d2f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/23/2019
ms.locfileid: "54805949"
---
# <a name="lock-class"></a>Classe lock

Essa classe automatiza a usar um bloqueio para sincronizar o acesso a um objeto de vários threads.  Quando construído adquire o bloqueio e quando destruído versões o bloqueio.

## <a name="syntax"></a>Sintaxe

```cpp
ref class lock;
```

## <a name="remarks"></a>Comentários

`lock` está disponível somente para objetos CLR e só pode ser usado no código do CLR.

Internamente, os usos da classe de bloqueio <xref:System.Threading.Monitor> para sincronizar o acesso. Para obter mais informações, consulte o artigo referenciado.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|---------|-----------|
|[lock::lock](#lock)|Constrói um `lock` objeto, opcionalmente, aguardando para adquirir o bloqueio para sempre, para uma quantidade especificada de tempo, ou não de forma alguma.|
|[lock::~lock](#tilde-lock)|Destructs um `lock` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|---------|-----------|
|[lock::acquire](#acquire)|Adquire um bloqueio em um objeto, opcionalmente, aguardando para adquirir o bloqueio para sempre, para uma quantidade especificada de tempo, ou não de forma alguma.|
|[lock::is_locked](#is-locked)|Indica se um bloqueio está sendo mantido.|
|[lock::release](#release)|Libera um bloqueio.|
|[lock::try_acquire](#try-acquire)|Adquire um bloqueio em um objeto, aguardando um período de tempo especificado e retornando um `bool` para relatar o sucesso da aquisição em vez de gerar uma exceção.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|---------|-----------|
|[lock::operator&nbsp;bool](#operator-bool)|Operador para usar `lock` em uma expressão condicional.|
|[lock::operator==](#operator-equality)|Operador de igualdade.|
|[lock::operator!=](#operator-inequality)|Operador de desigualdade.|

## <a name="requirements"></a>Requisitos

**Arquivo de cabeçalho** \<msclr\lock.h >

**Namespace** msclr



## <a name="lock"></a>lock::lock

Constrói um `lock` objeto, opcionalmente, aguardando para adquirir o bloqueio para sempre, para uma quantidade especificada de tempo, ou não de forma alguma.

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
Valor de tempo limite em milissegundos, ou como um <xref:System.TimeSpan>.

### <a name="exceptions"></a>Exceções

Gera <xref:System.ApplicationException> se a aquisição do bloqueio não ocorrer antes do tempo limite.

### <a name="remarks"></a>Comentários

Os primeiros três formulários do construtor tentam adquirir um bloqueio em `_object` dentro do período de tempo limite especificado (ou <xref:System.Threading.Timeout.Infinite> se nenhum for especificado).

O quarto formulário do construtor não adquirir um bloqueio em `_object`. `lock_later` é um membro do [enum lock_when](../dotnet/lock-when-enum.md). Use [lock::acquire](../dotnet/lock-acquire.md) ou [lock::try_acquire](../dotnet/lock-try-acquire.md) para adquirir o bloqueio neste caso.

O bloqueio será liberado automaticamente quando o destruidor é chamado.

`_object` não pode ser <xref:System.Threading.ReaderWriterLock>.  Se for, ocorrerá um erro de compilador.

### <a name="example"></a>Exemplo

Este exemplo usa uma única instância de uma classe entre vários threads. A classe usa um bloqueio em si mesmo para certificar-se de que os acessos a seus dados internos são consistentes para cada thread. O thread do aplicativo principal usa um bloqueio na mesma instância da classe para verificar periodicamente para ver se ainda existirem qualquer threads de trabalho. O aplicativo principal, em seguida, aguarda para sair até que todos os threads de trabalho concluir suas tarefas.

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

## <a name="tilde-lock"></a>bloqueio:: ~ lock

Destructs um `lock` objeto.

```cpp
~lock();
```

### <a name="remarks"></a>Comentários

As chamadas de destruidor [lock::release](../dotnet/lock-release.md).

### <a name="example"></a>Exemplo

Este exemplo usa uma única instância de uma classe entre vários threads.  A classe usa um bloqueio em si mesmo para certificar-se de que os acessos a seus dados internos são consistentes para cada thread.  O thread do aplicativo principal usa um bloqueio na mesma instância da classe para verificar periodicamente para ver se ainda existirem qualquer threads de trabalho. O aplicativo principal, em seguida, aguarda para sair até que todos os threads de trabalho concluir suas tarefas.

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

## <a name="acquire"></a>lock::acquire

Adquire um bloqueio em um objeto, opcionalmente, aguardando para adquirir o bloqueio para sempre, para uma quantidade especificada de tempo, ou não de forma alguma.

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
Valor de tempo limite em milissegundos, ou como um <xref:System.TimeSpan>.

### <a name="exceptions"></a>Exceções

Gera <xref:System.ApplicationException> se a aquisição do bloqueio não ocorrer antes do tempo limite.

### <a name="remarks"></a>Comentários

Se não for fornecido um valor de tempo limite, o tempo limite padrão é <xref:System.Threading.Timeout.Infinite>.

Se já tiver sido adquirido um bloqueio, essa função não faz nada.

### <a name="example"></a>Exemplo

Este exemplo usa uma única instância de uma classe entre vários threads.  A classe usa um bloqueio em si mesmo para certificar-se de que os acessos a seus dados internos são consistentes para cada thread. O thread do aplicativo principal usa um bloqueio na mesma instância da classe para verificar periodicamente para ver se ainda existirem qualquer threads de trabalho. O aplicativo principal, em seguida, aguarda para sair até que todos os threads de trabalho concluir suas tarefas.

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

## <a name="is-locked"></a>lock::is_locked

Indica se um bloqueio está sendo mantido.

```cpp
bool is_locked();
```

### <a name="return-value"></a>Valor de retorno

`true` Se um bloqueio for mantido, `false` caso contrário.

### <a name="example"></a>Exemplo

Este exemplo usa uma única instância de uma classe entre vários threads.  A classe usa um bloqueio em si mesmo para certificar-se de que os acessos a seus dados internos são consistentes para cada thread.  O thread do aplicativo principal usa um bloqueio na mesma instância da classe para verificar periodicamente para ver se os threads de trabalho ainda existem e esperas para sair até que todos os threads de trabalho concluir suas tarefas.

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

## <a name="operator-bool"></a>Lock:: Operator bool

Operador para usar `lock` em uma expressão condicional.

```cpp
operator bool();
```

### <a name="return-value"></a>Valor de retorno

`true` Se um bloqueio for mantido, `false` caso contrário.

### <a name="remarks"></a>Comentários

Este operador converte realmente para `_detail_class::_safe_bool` que é mais segura do que `bool` porque ele não pode ser convertido em um tipo integral.

### <a name="example"></a>Exemplo

Este exemplo usa uma única instância de uma classe entre vários threads.  A classe usa um bloqueio em si mesmo para certificar-se de que os acessos a seus dados internos são consistentes para cada thread. O thread do aplicativo principal usa um bloqueio na mesma instância da classe para verificar periodicamente para ver se ainda existirem qualquer threads de trabalho. O aplicativo principal aguarda para sair até que todos os threads de trabalho concluir suas tarefas.

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

## <a name="release"></a>lock::release

Libera um bloqueio.

```cpp
void release();
```

### <a name="remarks"></a>Comentários

Se nenhum bloqueio está sendo mantido, `release` não faz nada.

Você não precisa chamar essa função explicitamente. Quando um `lock` objeto sai do escopo, suas chamadas de destruidor `release`.

### <a name="example"></a>Exemplo

Este exemplo usa uma única instância de uma classe entre vários threads. A classe usa um bloqueio em si mesmo para certificar-se de que os acessos a seus dados internos são consistentes para cada thread. O thread do aplicativo principal usa um bloqueio na mesma instância da classe para verificar periodicamente para ver se ainda existirem qualquer threads de trabalho. O aplicativo principal, em seguida, aguarda para sair até que todos os threads de trabalho concluir suas tarefas.

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

## <a name="try-acquire"></a>lock::try_acquire

Adquire um bloqueio em um objeto, aguardando um período de tempo especificado e retornando um `bool` para relatar o sucesso da aquisição em vez de gerar uma exceção.

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
Valor de tempo limite em milissegundos, ou como um <xref:System.TimeSpan>.

### <a name="return-value"></a>Valor de retorno

`true` Se o bloqueio foi adquirido, `false` caso contrário.

### <a name="remarks"></a>Comentários

Se já tiver sido adquirido um bloqueio, essa função não faz nada.

### <a name="example"></a>Exemplo

Este exemplo usa uma única instância de uma classe entre vários threads. A classe usa um bloqueio em si mesmo para certificar-se de que os acessos a seus dados internos são consistentes para cada thread. O thread do aplicativo principal usa um bloqueio na mesma instância da classe para verificar periodicamente para ver se ainda existirem qualquer threads de trabalho. O aplicativo principal, em seguida, aguarda para sair até que todos os threads de trabalho concluir suas tarefas.

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

## <a name="operator-equality"></a>lock::operator==

Operador de igualdade.

```cpp
template<class T> bool operator==(
   T t
);
```

### <a name="parameters"></a>Parâmetros

*t*<br/>
A igualdade de um objeto a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retorna `true` se `t` é o mesmo que objeto do bloqueio, `false` caso contrário.

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

## <a name="operator-inequality"></a>lock::operator!=

Operador de desigualdade.

```cpp
template<class T> bool operator!=(
   T t
);
```

### <a name="parameters"></a>Parâmetros

*t*<br/>
O objeto a ser comparado quanto à desigualdade.

### <a name="return-value"></a>Valor de retorno

Retorna `true` se `t` é diferente do objeto do bloqueio, `false` caso contrário.

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