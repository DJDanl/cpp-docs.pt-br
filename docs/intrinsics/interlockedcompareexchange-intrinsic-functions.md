---
title: "_InterlockedCompareExchange fun&#231;&#245;es intr&#237;nsecas | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "_InterlockedCompareExchange_HLERelease"
  - "_InterlockedCompareExchange8_nf"
  - "_InterlockedCompareExchange16_acq_cpp"
  - "_InterlockedCompareExchange_acq_cpp"
  - "_InterlockedCompareExchange16_rel_cpp"
  - "_InterlockedCompareExchange64_rel_cpp"
  - "_InterlockedCompareExchange_cpp"
  - "_InterlockedCompareExchange16_cpp"
  - "_InterlockedCompareExchange64_acq_cpp"
  - "_InterlockedCompareExchange_acq"
  - "_InterlockedCompareExchange64_rel"
  - "_InterlockedCompareExchange64_nf"
  - "_InterlockedCompareExchange_rel_cpp"
  - "_InterlockedCompareExchange16_nf"
  - "_InterlockedCompareExchange8"
  - "_InterlockedCompareExchange64_np"
  - "_InterlockedCompareExchange16_rel"
  - "_InterlockedCompareExchange64_acq"
  - "_InterlockedCompareExchange8_rel"
  - "_InterlockedCompareExchange_HLEAcquire"
  - "_InterlockedCompareExchange64_HLERelease"
  - "_InterlockedCompareExchange64_cpp"
  - "_InterlockedCompareExchange_np"
  - "_InterlockedCompareExchange8_acq"
  - "_InterlockedCompareExchange16_acq"
  - "_InterlockedCompareExchange_rel"
  - "_InterlockedCompareExchange64_HLEAcquire"
  - "_InterlockedCompareExchange64"
  - "_InterlockedCompareExchange16"
  - "_InterlockedCompareExchange"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "_InterlockedCompareExchange intrínseca"
  - "_InterlockedCompareExchange_acq intrínseca"
  - "_InterlockedCompareExchange_rel intrínseca"
  - "_InterlockedCompareExchange16 intrínseca"
  - "_InterlockedCompareExchange64 intrínseca"
  - "_InterlockedCompareExchange64_acq intrínseca"
  - "_InterlockedCompareExchange64_rel intrínseca"
  - "InterlockedCompareExchange intrínseca"
  - "InterlockedCompareExchange_acq intrínseca"
  - "InterlockedCompareExchange_rel intrínseca"
  - "InterlockedCompareExchange16 intrínseca"
  - "InterlockedCompareExchange64 intrínseca"
  - "InterlockedCompareExchange64_acq intrínseca"
  - "InterlockedCompareExchange64_rel intrínseca"
ms.assetid: c3ad79c0-a523-4930-a3a4-69a65d7d5c81
caps.latest.revision: 26
caps.handback.revision: 24
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _InterlockedCompareExchange fun&#231;&#245;es intr&#237;nsecas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Executa uma comparação e troca sincronizada.  
  
## Sintaxe  
  
```  
long _InterlockedCompareExchange(  
   long volatile * Destination,  
   long Exchange,  
   long Comparand  
);  
long _InterlockedCompareExchange_acq(  
   long volatile * Destination,  
   long Exchange,  
   long Comparand  
);  
long _InterlockedCompareExchange_HLEAcquire(  
   long volatile * Destination,  
   long Exchange,  
   long Comparand  
);  
long _InterlockedCompareExchange_HLERelease(  
   long volatile * Destination,  
   long Exchange,  
   long Comparand  
);  
long _InterlockedCompareExchange_np(  
   long volatile * Destination,  
   long Exchange,  
   long Comparand  
);  
long _InterlockedCompareExchange_rel(  
   long volatile * Destination,  
   long Exchange,  
   long Comparand  
);  
char _InterlockedCompareExchange8(  
   char volatile * Destination,  
   char Exchange,  
   char Comparand  
);  
char _InterlockedCompareExchange8_acq(  
   char volatile * Destination,  
   char Exchange,  
   char Comparand  
);  
char _InterlockedCompareExchange8_nf(  
   char volatile * Destination,  
   char Exchange,  
   char Comparand  
);  
char _InterlockedCompareExchange8_rel(  
   char volatile * Destination,  
   char Exchange,  
   char Comparand  
);  
short _InterlockedCompareExchange16(  
   short volatile * Destination,  
   short Exchange,  
   short Comparand  
);  
short _InterlockedCompareExchange16_acq(  
   short volatile * Destination,  
   short Exchange,  
   short Comparand  
);  
short _InterlockedCompareExchange16_nf(  
   short volatile * Destination,  
   short Exchange,  
   short Comparand  
);  
short _InterlockedCompareExchange16_np(  
   short volatile * Destination,  
   short Exchange,  
   short Comparand  
);  
short _InterlockedCompareExchange16_rel(  
   short volatile * Destination,  
   short Exchange,  
   short Comparand  
);  
__int64 _InterlockedCompareExchange64(  
   __int64 volatile * Destination,  
   __int64 Exchange,  
   __int64 Comparand  
);  
__int64 _InterlockedCompareExchange64_acq(  
   __int64 volatile * Destination,  
   __int64 Exchange,  
   __int64 Comparand  
);  
__int64 _InterlockedCompareExchange64_HLEAcquire (  
   __int64 volatile * Destination,  
   __int64 Exchange,  
   __int64 Comparand  
);  
__int64 _InterlockedCompareExchange64_HLERelease(  
   __int64 volatile * Destination,  
   __int64 Exchange,  
   __int64 Comparand  
);  
__int64 _InterlockedCompareExchange64_nf(  
   __int64 volatile * Destination,  
   __int64 Exchange,  
   __int64 Comparand  
);  
__int64 _InterlockedCompareExchange64_np(  
   __int64 volatile * Destination,  
   __int64 Exchange,  
   __int64 Comparand  
);  
__int64 _InterlockedCompareExchange64_rel(  
   __int64 volatile * Destination,  
   __int64 Exchange,  
   __int64 Comparand  
);  
```  
  
#### Parâmetros  
 \[in, out\] `Destination`  
 Ponteiro para o valor de destino.  O sinal é ignorado.  
  
 \[in\] `Exchange`  
 Valor de troca.  O sinal é ignorado.  
  
 \[in\] `Comparand`  
 Valor a ser comparado ao destino.  O sinal é ignorado.  
  
## Valor de retorno  
 O valor retornado é o valor inicial do ponteiro `Destination`.  
  
## Requisitos  
  
|Intrínseco|Arquitetura|Cabeçalho|  
|----------------|-----------------|---------------|  
|`_InterlockedCompareExchange`, `_InterlockedCompareExchange8`, `_InterlockedCompareExchange16`, `_InterlockedCompareExchange64`|x86, ARM, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|\<intrin.h\>|  
|`_InterlockedCompareExchange_acq`, `_InterlockedCompareExchange_rel`, `_InterlockedCompareExchange8_acq`, `_InterlockedCompareExchange8_nf`, `_InterlockedCompareExchange8_rel`,`_InterlockedCompareExchange16_acq`, `_InterlockedCompareExchange16_nf`, `_InterlockedCompareExchange16_rel`, `_InterlockedCompareExchange64_acq`, `_InterlockedCompareExchange64_nf`, `_InterlockedCompareExchange64_rel`,|ARM|\<intrin.h\>|  
|`_InterlockedCompareExchange_np`, `_InterlockedCompareExchange16_np`, `_InterlockedCompareExchange64_np`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|\<intrin.h\>|  
|`_InterlockedCompareExchange_HLEAcquire`, `_InterlockedCompareExchange_HLERelease`, `_InterlockedCompareExchange64_HLEAcquire`, `_InterlockedCompareExchange64_HLERelease`|x86, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|\<immintrin.h\>|  
  
## Comentários  
 `_InterlockedCompareExchange` realiza uma comparação atômica do valor `Destination` com o valor `Comparand`.  Se o valor `Destination` for igual ao valor `Comparand`, o valor `Exchange` será armazenado no endereço especificado pelo `Destination`.  Caso contrário, nenhuma operação será executada.  
  
 `_InterlockedCompareExchange` fornece suporte intrínsecos do compilador para o Win32 [!INCLUDE[winsdkshort](../atl/reference/includes/winsdkshort_md.md)] [InterlockedCompareExchange](http://msdn.microsoft.com/library/ms683560.aspx) função.  
  
 Há diversas variações em `_InterlockedCompareExchange` que têm base no tipo de dados que envolvem e se a semântica acquire ou release é usada.  
  
 Enquanto a função `_InterlockedCompareExchange` opera em valores de inteiro longo, `_InterlockedCompareExchange8` opera em valores inteiros de 8 bits `_InterlockedCompareExchange16` opera em valores inteiros curtos e `_InterlockedCompareExchange64` opera em valores inteiros de 64 bits.  
  
 Em plataformas ARM, use intrínsecos com os sufixos `_acq` e `_rel` para semântica de aquisição e liberação, como no início e no final de uma seção crítica.  Os intrínsecos de ARM com um sufixo `_nf` \("no fence"\) não funcionam como uma barreira de memória.  
  
 Intrínsecos com um sufixo `_np` \("no prefetch"\) impedem que uma possível operação de pré\-busca seja inserida pelo compilador.  
  
 Em plataformas Intel que suportam instruções HLE \(Elisão de Bloqueio de Hardware\), intrínsecos com os sufixos `_HLEAcquire` e `_HLERelease` incluem uma dica para o processador que pode acelerar o desempenho, eliminando uma etapa de gravação de bloqueio no hardware.  Se esses intrínsecos forem chamados em plataformas que não dão suporte a HLE, a dica será ignorada.  
  
 Essas rotinas somente estão disponíveis como intrínsecos.  
  
## Exemplo  
 No exemplo a seguir, `_InterlockedCompareExchange` é usado para sincronização de thread simples de nível inferior.  A abordagem tem suas limitações como base para a programação multithreaded; ela é apresentada para ilustrar o uso típico de intrínsecos sincronizados.  Para obter melhores resultados, use a API do Windows.  Para obter mais informações sobre a programação multithreaded, consulte [Escrevendo um programa Win32 multithreaded](../Topic/Writing%20a%20Multithreaded%20Win32%20Program.md).  
  
```  
// intrinExample.cpp  
// compile with: /EHsc /O2  
// Simple example of using _Interlocked* intrinsics to  
// do manual synchronization  
//  
// Add [-DSKIP_LOCKING] to the command line to disable  
// the locking. This will cause the threads to execute out  
// of sequence.  
  
#define _CRT_RAND_S  
  
#include "windows.h"  
  
#include <iostream>  
#include <queue>  
#include <intrin.h>  
  
using namespace std;  
  
// --------------------------------------------------------------------  
  
// if defined, will not do any locking on shared data  
//#define SKIP_LOCKING  
  
// A common way of locking using _InterlockedCompareExchange.  
// Please refer to other sources for a discussion of the many issues  
// involved. For example, this particular locking scheme performs well   
// when lock contention is low, as the while loop overhead is small and  
// locks are acquired very quickly, but degrades as many callers want  
// the lock and most threads are doing a lot of interlocked spinning.  
// There are also no guarantees that a caller will ever acquire the  
// lock.  
namespace MyInterlockedIntrinsicLock  
{  
    typedef unsigned LOCK, *PLOCK;  
  
#pragma intrinsic(_InterlockedCompareExchange, _InterlockedExchange)  
  
    enum {LOCK_IS_FREE = 0, LOCK_IS_TAKEN = 1};  
  
    void Lock(PLOCK pl)   
    {  
#if !defined(SKIP_LOCKING)  
        // If *pl == LOCK_IS_FREE, it is set to LOCK_IS_TAKEN  
        // atomically, so only 1 caller gets the lock.  
        // If *pl == LOCK_IS_TAKEN,  
        // the result is LOCK_IS_TAKEN, and the while loop keeps spinning.  
        while (_InterlockedCompareExchange((long *)pl,  
                                           LOCK_IS_TAKEN, // exchange  
                                           LOCK_IS_FREE)  // comparand  
               == LOCK_IS_TAKEN)  
        {  
            // spin!  
        }  
        // This will also work.  
        //while (_InterlockedExchange(pl, LOCK_IS_TAKEN) ==   
        //                             LOCK_IS_TAKEN)  
        //{  
        //    // spin!  
        //}  
  
        // At this point, the lock is acquired.  
#endif  
    }  
  
    void Unlock(PLOCK pl) {  
#if !defined(SKIP_LOCKING)  
        _InterlockedExchange((long *)pl, LOCK_IS_FREE);  
#endif  
    }  
}  
  
// ------------------------------------------------------------------  
  
// Data shared by threads  
  
queue<int> SharedQueue;  
MyInterlockedIntrinsicLock::LOCK SharedLock;  
int TicketNumber;  
  
// ------------------------------------------------------------------  
  
DWORD WINAPI  
ProducerThread(  
    LPVOID unused  
    )  
{  
    unsigned int randValue;  
    while (1) {  
        // Acquire shared data. Enter critical section.  
        MyInterlockedIntrinsicLock::Lock(&SharedLock);  
  
        //cout << ">" << TicketNumber << endl;  
        SharedQueue.push(TicketNumber++);  
  
        // Release shared data. Leave critical section.  
        MyInterlockedIntrinsicLock::Unlock(&SharedLock);  
  
        rand_s(&randValue);  
        Sleep(randValue % 20);  
    }  
  
    return 0;  
}  
  
DWORD WINAPI  
ConsumerThread(  
    LPVOID unused  
    )  
{  
    while (1) {  
        // Acquire shared data. Enter critical section  
        MyInterlockedIntrinsicLock::Lock(&SharedLock);  
  
        if (!SharedQueue.empty()) {  
            int x = SharedQueue.front();  
            cout << "<" << x << endl;  
            SharedQueue.pop();  
        }  
  
        // Release shared data. Leave critical section  
        MyInterlockedIntrinsicLock::Unlock(&SharedLock);  
  
        unsigned int randValue;  
        rand_s(&randValue);  
        Sleep(randValue % 20);  
    }  
    return 0;  
}  
  
int main(  
    void  
    )  
{  
    const int timeoutTime = 500;  
    int unused1, unused2;  
    HANDLE threads[4];  
  
    // The program creates 4 threads:  
    // two producer threads adding to the queue  
    // and two consumers taking data out and printing it.  
    threads[0] = CreateThread(NULL,  
                              0,  
                              ProducerThread,  
                              &unused1,  
                              0,  
                              (LPDWORD)&unused2);  
  
    threads[1] = CreateThread(NULL,  
                              0,  
                              ConsumerThread,  
                              &unused1,  
                              0,  
                              (LPDWORD)&unused2);  
  
    threads[2] = CreateThread(NULL,  
                              0,  
                              ProducerThread,  
                              &unused1,  
                              0,  
                              (LPDWORD)&unused2);  
  
    threads[3] = CreateThread(NULL,  
                              0,  
                              ConsumerThread,  
                              &unused1,  
                              0,  
                              (LPDWORD)&unused2);  
  
    WaitForMultipleObjects(4, threads, TRUE, timeoutTime);  
  
    return 0;  
}  
```  
  
  **\<0**  
**\<1**  
**\<2**  
**\<3**  
**\<4**  
**\<5**  
**\<6**  
**\<7**  
**\<8**  
**\<9**  
**\<10**  
**\<11**  
**\<12**  
**\<13**  
**\<14**  
**\<15**  
**\<16**  
**\<17**  
**\<18**  
**\<19**  
**\<20**  
**\<21**  
**\<22**  
**\<23**  
**\<24**  
**\<25**  
**\<26**  
**\<27**  
**\<28**  
**\<29**   
## FIM de Específico da Microsoft  
  
## Consulte também  
 [\_InterlockedCompareExchange128](../intrinsics/interlockedcompareexchange128.md)   
 [Funções intrínsecas \_InterlockedCompareExchangePointer](../intrinsics/interlockedcompareexchangepointer-intrinsic-functions.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Conflitos com o compilador x86](../Topic/Conflicts%20with%20the%20x86%20Compiler.md)