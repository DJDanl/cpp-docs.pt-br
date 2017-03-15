---
title: "lock::~lock | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "~lock"
  - "msclr.lock.~lock"
  - "lock.~lock"
  - "msclr::lock::~lock"
  - "lock::~lock"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Destruidor ~lock"
ms.assetid: 55fa9f6c-d7a6-48ef-9236-ee03342c1d20
caps.latest.revision: 10
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# lock::~lock
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Destructs um objeto de `lock` .  
  
## Sintaxe  
  
```  
~lock();  
```  
  
## Comentários  
 O destruidor chama [lock::release](../Topic/lock::release.md).  
  
## Exemplo  
 Este exemplo usa uma única instância de uma classe em vários threads.  A classe usar um bloqueio em para assegurar que acessa a seus dados internos são consistentes para cada thread.  O thread principal do aplicativo usa um bloqueio na mesma instância da classe para verificar periodicamente se algum thread de trabalho ainda existe, e para sair de espera até que todos os threads de trabalho foi concluído suas tarefas.  
  
```  
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
  
  **O thread 3, o contador \= 0**  
**O thread 3, o contador \= 10**  
**O thread 5, o contador \= 0**  
**O thread 5, o contador \= 10**  
**O thread 7, o contador \= 0**  
**O thread 7, o contador \= 10**  
**O thread 4, o contador \= 0**  
**O thread 4, o contador \= 10**  
**O thread 6, o contador \= 0**  
**O thread 6, o contador \= 10**  
**Todos os threads concluídos.**   
## Requisitos  
 msclr \<de**Arquivo de cabeçalho** \\ lock.h\>  
  
 msclr de**Namespace**  
  
## Consulte também  
 [Membros de bloqueio](../dotnet/lock-members.md)   
 [lock::lock](../dotnet/lock-lock.md)