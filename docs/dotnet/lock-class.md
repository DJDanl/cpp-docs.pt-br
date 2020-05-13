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
ms.openlocfilehash: ea09dd3d4a2eaf4cf7708d09509cfecfa4a6c6d5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373071"
---
# <a name="lock-class"></a>Classe lock

Esta classe automatiza a trava para sincronizar o acesso a um objeto a partir de vários segmentos.  Quando construído, adquire a fechadura e, quando destruída, libera a fechadura.

## <a name="syntax"></a>Sintaxe

```cpp
ref class lock;
```

## <a name="remarks"></a>Comentários

`lock`está disponível apenas para objetos CLR e só pode ser usado em código CLR.

Internamente, a classe <xref:System.Threading.Monitor> de bloqueio é usa para sincronizar o acesso. Para obter mais informações, consulte o artigo mencionado.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|---------|-----------|
|[lock::lock](#lock)|Constrói um `lock` objeto, opcionalmente esperando para adquirir o bloqueio para sempre, por um determinado período de tempo, ou não.|
|[bloqueio::~bloqueio](#tilde-lock)|Destrói um `lock` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|---------|-----------|
|[lock::acquire](#acquire)|Adquire um bloqueio em um objeto, opcionalmente esperando para adquirir o bloqueio para sempre, por um determinado período de tempo, ou não.|
|[lock::is_locked](#is-locked)|Indica se uma fechadura está sendo mantida.|
|[lock::release](#release)|Libera um cadeado.|
|[lock::try_acquire](#try-acquire)|Adquire um bloqueio em um objeto, esperando por um `bool` determinado período de tempo e retornando um para relatar o sucesso da aquisição em vez de lançar uma exceção.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|---------|-----------|
|[bloqueio::operador&nbsp;bool](#operator-bool)|Operador para `lock` uso em uma expressão condicional.|
|[lock::operator==](#operator-equality)|Operador de igualdade.|
|[bloqueio::operador!=](#operator-inequality)|Operador de desigualdade.|

## <a name="requirements"></a>Requisitos

Arquivo \< **de cabeçalho** msclr\lock.h>

**Namespace** msclr

## <a name="locklock"></a><a name="lock"></a>bloqueio::bloqueio

Constrói um `lock` objeto, opcionalmente esperando para adquirir o bloqueio para sempre, por um determinado período de tempo, ou não.

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
Valor de tempo em milissegundos ou como um <xref:System.TimeSpan>.

### <a name="exceptions"></a>Exceções

Lança <xref:System.ApplicationException> se a aquisição de bloqueio não ocorrer antes do intervalo.

### <a name="remarks"></a>Comentários

As três primeiras formas do construtor tentam `_object` adquirir um bloqueio dentro <xref:System.Threading.Timeout.Infinite> do período de tempo especificado (ou se nenhuma for especificada).

A quarta forma da construtora não adquire `_object`um bloqueio. `lock_later`é um membro do [lock_when enum](../dotnet/lock-when-enum.md). Use [lock::acquire](../dotnet/lock-acquire.md) ou [lock::try_acquire](../dotnet/lock-try-acquire.md) para adquirir o bloqueio neste caso.

O bloqueio será liberado automaticamente quando o destructor for chamado.

`_object`não pode <xref:System.Threading.ReaderWriterLock>ser .  Se for, um erro de compilador resultará.

### <a name="example"></a>Exemplo

Este exemplo usa uma única instância de uma classe em vários segmentos. A classe usa um bloqueio em si mesma para garantir que os acessos aos seus dados internos sejam consistentes para cada segmento. O segmento principal do aplicativo usa um bloqueio na mesma instância da classe para verificar periodicamente se ainda existem segmentos de trabalhador. O aplicativo principal então espera para sair até que todos os segmentos de trabalhadortenham concluído suas tarefas.

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

## <a name="locklock"></a><a name="tilde-lock"></a>bloqueio::~bloqueio

Destrói um `lock` objeto.

```cpp
~lock();
```

### <a name="remarks"></a>Comentários

O destruidor chama [bloqueio::liberação](../dotnet/lock-release.md).

### <a name="example"></a>Exemplo

Este exemplo usa uma única instância de uma classe em vários segmentos.  A classe usa um bloqueio em si mesma para garantir que os acessos aos seus dados internos sejam consistentes para cada segmento.  O segmento principal do aplicativo usa um bloqueio na mesma instância da classe para verificar periodicamente se ainda existem segmentos de trabalhador. O aplicativo principal então espera para sair até que todos os segmentos de trabalhadortenham concluído suas tarefas.

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

## <a name="lockacquire"></a><a name="acquire"></a>bloqueio::adquirir

Adquire um bloqueio em um objeto, opcionalmente esperando para adquirir o bloqueio para sempre, por um determinado período de tempo, ou não.

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
Valor de tempo em milissegundos ou como um <xref:System.TimeSpan>.

### <a name="exceptions"></a>Exceções

Lança <xref:System.ApplicationException> se a aquisição de bloqueio não ocorrer antes do intervalo.

### <a name="remarks"></a>Comentários

Se um valor de tempo não for fornecido, o tempo de intervalo padrão será <xref:System.Threading.Timeout.Infinite>.

Se um bloqueio já foi adquirido, esta função não faz nada.

### <a name="example"></a>Exemplo

Este exemplo usa uma única instância de uma classe em vários segmentos.  A classe usa um bloqueio em si mesma para garantir que os acessos aos seus dados internos sejam consistentes para cada segmento. O segmento principal do aplicativo usa um bloqueio na mesma instância da classe para verificar periodicamente se ainda existem segmentos de trabalhador. O aplicativo principal então espera para sair até que todos os segmentos de trabalhadortenham concluído suas tarefas.

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

## <a name="lockis_locked"></a><a name="is-locked"></a>bloqueio::is_locked

Indica se uma fechadura está sendo mantida.

```cpp
bool is_locked();
```

### <a name="return-value"></a>Valor retornado

`true`se uma fechadura `false` é mantida, caso contrário.

### <a name="example"></a>Exemplo

Este exemplo usa uma única instância de uma classe em vários segmentos.  A classe usa um bloqueio em si mesma para garantir que os acessos aos seus dados internos sejam consistentes para cada segmento.  O segmento principal do aplicativo usa um bloqueio na mesma instância da classe para verificar periodicamente se ainda existem segmentos de trabalhadores e aguarda para sair até que todos os segmentos do trabalhador tenham concluído suas tarefas.

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

## <a name="lockoperator-bool"></a><a name="operator-bool"></a>bloqueio::operador bool

Operador para `lock` uso em uma expressão condicional.

```cpp
operator bool();
```

### <a name="return-value"></a>Valor retornado

`true`se uma fechadura `false` é mantida, caso contrário.

### <a name="remarks"></a>Comentários

Este operador realmente `_detail_class::_safe_bool` converte `bool` para o que é mais seguro do que porque não pode ser convertido para um tipo integral.

### <a name="example"></a>Exemplo

Este exemplo usa uma única instância de uma classe em vários segmentos.  A classe usa um bloqueio em si mesma para garantir que os acessos aos seus dados internos sejam consistentes para cada segmento. O segmento principal do aplicativo usa um bloqueio na mesma instância da classe para verificar periodicamente se ainda existem segmentos de trabalhador. O aplicativo principal aguarda a saída até que todos os segmentos de trabalhadores tenham concluído suas tarefas.

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

## <a name="lockrelease"></a><a name="release"></a>bloqueio::liberação

Libera um cadeado.

```cpp
void release();
```

### <a name="remarks"></a>Comentários

Se nenhuma fechadura está `release` sendo mantida, não faz nada.

Você não tem que chamar essa função explicitamente. Quando `lock` um objeto sai do escopo, seu `release`destruidor chama .

### <a name="example"></a>Exemplo

Este exemplo usa uma única instância de uma classe em vários segmentos. A classe usa um bloqueio em si mesma para garantir que os acessos aos seus dados internos sejam consistentes para cada segmento. O segmento principal do aplicativo usa um bloqueio na mesma instância da classe para verificar periodicamente se ainda existem segmentos de trabalhador. O aplicativo principal então espera para sair até que todos os segmentos de trabalhadortenham concluído suas tarefas.

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

## <a name="locktry_acquire"></a><a name="try-acquire"></a>bloqueio::try_acquire

Adquire um bloqueio em um objeto, esperando por um `bool` determinado período de tempo e retornando um para relatar o sucesso da aquisição em vez de lançar uma exceção.

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
Valor de tempo em milissegundos ou como um <xref:System.TimeSpan>.

### <a name="return-value"></a>Valor retornado

`true`se o bloqueio `false` foi adquirido, caso contrário.

### <a name="remarks"></a>Comentários

Se um bloqueio já foi adquirido, esta função não faz nada.

### <a name="example"></a>Exemplo

Este exemplo usa uma única instância de uma classe em vários segmentos. A classe usa um bloqueio em si mesma para garantir que os acessos aos seus dados internos sejam consistentes para cada segmento. O segmento principal do aplicativo usa um bloqueio na mesma instância da classe para verificar periodicamente se ainda existem segmentos de trabalhador. O aplicativo principal então espera para sair até que todos os segmentos de trabalhadortenham concluído suas tarefas.

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

## <a name="lockoperator"></a><a name="operator-equality"></a>bloqueio::operador==

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

Retorna `true` `t` se for o mesmo que `false` o objeto da fechadura, caso contrário.

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

## <a name="lockoperator"></a><a name="operator-inequality"></a>bloqueio::operador!=

Operador de desigualdade.

```cpp
template<class T> bool operator!=(
   T t
);
```

### <a name="parameters"></a>Parâmetros

*t*<br/>
O objeto a ser comparado à desigualdade.

### <a name="return-value"></a>Valor retornado

Retorna `true` `t` se difere do objeto da `false` fechadura, caso contrário.

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
