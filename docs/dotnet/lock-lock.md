---
title: Lock::Lock | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- lock::lock
- lock.lock
- msclr.lock.lock
- msclr::lock::lock
dev_langs:
- C++
helpviewer_keywords:
- lock constructor
ms.assetid: c9ad6c71-36ec-49c5-8ebd-f5c3a0cc94f0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 128a86b59ebf43ab87b0f4f4bcb7e9c684e4ad07
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46051809"
---
# <a name="locklock"></a>lock::lock
Constrói um `lock` objeto, opcionalmente, aguardando para adquirir o bloqueio para sempre, para uma quantidade especificada de tempo, ou não de forma alguma.  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
*Object*<br/>
O objeto a ser bloqueado.  
  
*tempo limite*<br/>
Valor de tempo limite em milissegundos, ou como um <xref:System.TimeSpan>.  
  
## <a name="exceptions"></a>Exceções  
 Gera <xref:System.ApplicationException> se a aquisição do bloqueio não ocorrerá antes do tempo limite.  
  
## <a name="remarks"></a>Comentários  
 Os primeiros três formulários do construtor tentam adquirir um bloqueio em `_object` dentro do período de tempo limite especificado (ou <xref:System.Threading.Timeout.Infinite> se nenhum for especificado).  
  
 O quarto formulário do construtor não adquirir um bloqueio em `_object`. `lock_later` é um membro do [Enum lock_when](../dotnet/lock-when-enum.md). Use [lock::acquire](../dotnet/lock-acquire.md) ou [lock::try_acquire](../dotnet/lock-try-acquire.md) para adquirir o bloqueio neste caso.  
  
 O bloqueio será liberado automaticamente quando o destruidor é chamado.  
  
 `_object` não pode ser <xref:System.Threading.ReaderWriterLock>.  Se for, ocorrerá um erro de compilador.  
  
## <a name="example"></a>Exemplo  
 Este exemplo usa uma única instância de uma classe entre vários threads.  A classe usa um bloqueio em si mesmo para garantir que os acessos a seus dados internos são consistentes para cada thread.  O thread do aplicativo principal usa um bloqueio na mesma instância da classe para verificar periodicamente para ver se os threads de trabalho ainda existem e esperas para sair até que todos os threads de trabalho concluir suas tarefas.  
  
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
 [Membros Lock](../dotnet/lock-members.md)   
 [bloqueio:: ~ lock](../dotnet/lock-tilde-lock.md)   
 [Lock::acquire](../dotnet/lock-acquire.md)   
 [lock::try_acquire](../dotnet/lock-try-acquire.md)