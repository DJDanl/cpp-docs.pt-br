---
title: "lock::lock | Microsoft Docs"
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
  - "lock::lock"
  - "lock.lock"
  - "msclr.lock.lock"
  - "msclr::lock::lock"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "construtor de bloqueio"
ms.assetid: c9ad6c71-36ec-49c5-8ebd-f5c3a0cc94f0
caps.latest.revision: 15
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# lock::lock
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria um objeto de `lock` opcionalmente, esperando para adquirir o bloqueio para sempre, para uma quantidade especificada de tempo, ou não.  
  
## Sintaxe  
  
```  
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
  
#### Parâmetros  
 `_object`  
 O objeto a ser bloqueada.  
  
 `_timeout`  
 Valor de tempo limite em milissegundos ou como <xref:System.TimeSpan>.  
  
## Exceções  
 Gerencie <xref:System.ApplicationException> se a aquisição do bloqueio não ocorre antes do tempo limite.  
  
## Comentários  
 Os primeiros três formulários do construtor tentam adquirir um bloqueio em `_object` dentro do tempo limite especificado \(ou de <xref:System.Threading.Timeout.Infinite> se nenhum for especificado\).  
  
 O quarto formulário de construtor não adquire um bloqueio em `_object`.  `lock_later` é um membro de [lock\_when Enum](../dotnet/lock-when-enum.md).  Use [lock::acquire](../dotnet/lock-acquire.md) ou [lock::try\_acquire](../Topic/lock::try_acquire.md) para adquirir caso em que o bloqueio.  
  
 O bloqueio será liberado automaticamente quando o destruidor é chamado.  
  
 `_object` não pode ser <xref:System.Threading.ReaderWriterLock>.  Se for, um erro do compilador ocorrerá.  
  
## Exemplo  
 Este exemplo usa uma única instância de uma classe em vários threads.  A classe usar um bloqueio em para assegurar que acessa a seus dados internos são consistentes para cada thread.  O thread principal do aplicativo usa um bloqueio na mesma instância da classe para verificar periodicamente se algum thread de trabalho ainda existe, e para sair de espera até que todos os threads de trabalho foi concluído suas tarefas.  
  
```  
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
 [lock::~lock](../dotnet/lock-tilde-lock.md)   
 [lock::acquire](../dotnet/lock-acquire.md)   
 [lock::try\_acquire](../Topic/lock::try_acquire.md)