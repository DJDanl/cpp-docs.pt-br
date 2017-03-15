---
title: "lock_when Enum | Microsoft Docs"
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
  - "msclr::lock_when"
  - "msclr.lock_when"
  - "lock_when"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "enum lock_when"
ms.assetid: 6b87bbe9-63cd-450d-a02e-bb91ffd0dcea
caps.latest.revision: 9
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# lock_when Enum
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica adiou o bloqueio.  
  
## Sintaxe  
  
```  
enum lock_when {  
   lock_later  
};  
```  
  
## Comentários  
 Quando é passada a [lock::lock](../dotnet/lock-lock.md), `lock_later` especifica que o bloqueio não ser tomada agora.  
  
## Exemplo  
 Este exemplo usa uma única instância de uma classe em vários threads.  A classe usar um bloqueio em para assegurar que acessa a seus dados internos são consistentes para cada thread.  O thread principal do aplicativo usa um bloqueio na mesma instância da classe para verificar periodicamente se algum thread de trabalho ainda existe, e para sair de espera até que todos os threads de trabalho foi concluído suas tarefas.  
  
```  
// msl_lock_lock_when.cpp  
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
 [bloqueio](../dotnet/lock.md)