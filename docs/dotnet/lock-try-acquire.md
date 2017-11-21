---
title: Lock::try_acquire | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- try_acquire
- lock.try_acquire
- msclr.lock.try_acquire
- lock::try_acquire
- msclr::lock::try_acquire
dev_langs: C++
helpviewer_keywords: lock::try_acquire
ms.assetid: ef0649a9-e611-4495-84bd-2784533221d9
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: c63d6a9161eab707b0eab2b831d02210c57a25d8
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="locktryacquire"></a>lock::try_acquire
Adquire um bloqueio em um objeto, aguardando um período de tempo especificado e retornar um `bool` para informar o sucesso da aquisição em vez de gerar uma exceção.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
bool try_acquire(  
   int _timeout_ms  
);  
bool try_acquire(  
   System::TimeSpan _timeout  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_timeout`  
 Valor de tempo limite em milissegundos, ou como um <xref:System.TimeSpan>.  
  
## <a name="return-value"></a>Valor de retorno  
 `true`Se o bloqueio foi adquirido, `false` caso contrário.  
  
## <a name="remarks"></a>Comentários  
 Se já tiver sido adquirido um bloqueio, essa função não faz nada.  
  
## <a name="example"></a>Exemplo  
 Este exemplo usa uma única instância de uma classe em vários threads.  A classe usa um bloqueio em si mesmo para garantir que acessa a seus dados internos é consistente para cada thread.  O thread principal do aplicativo usa um bloqueio na mesma instância da classe Verifique periodicamente para ver se qualquer threads de trabalho ainda existem e esperas para sair até que todos os threads de trabalho concluir suas tarefas.  
  
```  
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
  
## <a name="requirements"></a>Requisitos  
 **Arquivo de cabeçalho** \<msclr\lock.h >  
  
 **Namespace** msclr  
  
## <a name="see-also"></a>Consulte também  
 [Membros de bloqueio](../dotnet/lock-members.md)   
 [lock::acquire](../dotnet/lock-acquire.md)