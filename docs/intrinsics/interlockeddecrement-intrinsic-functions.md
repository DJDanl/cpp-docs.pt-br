---
title: _InterlockedDecrement funções intrínsecas
ms.date: 09/02/2019
f1_keywords:
- _InterlockedDecrement16_rel_cpp
- _InterlockedDecrement16_acq_cpp
- _InterlockedDecrement16_rel
- _InterlockedDecrement64_acq
- _InterlockedDecrement_nf
- _InterlockedDecrement16_nf
- _InterlockedDecrement64_rel_cpp
- _InterlockedDecrement_rel_cpp
- _InterlockedDecrement16_acq
- _InterlockedDecrement64_acq_cpp
- _InterlockedDecrement_rel
- _InterlockedDecrement64_nf
- _InterlockedDecrement16_cpp
- _InterlockedDecrement64
- _InterlockedDecrement_cpp
- _InterlockedDecrement64_rel
- _InterlockedDecrement16
- _InterlockedDecrement
- _InterlockedDecrement64_cpp
- _InterlockedDecrement_acq
- _InterlockedDecrement_acq_cpp
helpviewer_keywords:
- InterlockedDecrement64_rel intrinsic
- InterlockedDecrement64 intrinsic
- _InterlockedDecrement16 intrinsic
- _InterlockedDecrement16_acq intrinsic
- _InterlockedDecrement intrinsic
- _InterlockedDecrement_nf intrinsic
- _InterlockedDecrement_acq intrinsic
- _InterlockedDecrement64_rel intrinsic
- _InterlockedDecrement16_rel intrinsic
- InterlockedDecrement intrinsic
- InterlockedDecrement16 intrinsic
- _InterlockedDecrement16_nf intrinsic
- InterlockedDecrement64_acq intrinsic
- _InterlockedDecrement_rel intrinsic
- InterlockedDecrement_acq intrinsic
- _InterlockedDecrement64_acq intrinsic
- _InterlockedDecrement64 intrinsic
- _InterlockedDecrement64_nf intrinsic
- InterlockedDecrement_rel intrinsic
ms.assetid: 5268fce3-86b5-4b2b-b96c-2e531a3fb9b5
ms.openlocfilehash: f6b256ff1551eea4d0b362e78c9780fce29a8513
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857912"
---
# <a name="_interlockeddecrement-intrinsic-functions"></a>_InterlockedDecrement funções intrínsecas

**Seção específica da Microsoft**

Fornece suporte intrínseco do compilador para a função [InterlockedDecrement](/windows/win32/api/winnt/nf-winnt-interlockeddecrement) do Win32 SDK do Windows.

## <a name="syntax"></a>Sintaxe

```C
long _InterlockedDecrement(
   long * lpAddend
);
long _InterlockedDecrement_acq(
   long * lpAddend
);
long _InterlockedDecrement_rel(
   long * lpAddend
);
long _InterlockedDecrement_nf(
   long * lpAddend
);
short _InterlockedDecrement16(
   short * lpAddend
);
short _InterlockedDecrement16_acq(
   short * lpAddend
);
short _InterlockedDecrement16_rel(
   short * lpAddend
);
short _InterlockedDecrement16_nf(
   short * lpAddend
);
__int64 _InterlockedDecrement64(
   __int64 * lpAddend
);
__int64 _InterlockedDecrement64_acq(
   __int64 * lpAddend
);
__int64 _InterlockedDecrement64_rel(
   __int64 * lpAddend
);
__int64 _InterlockedDecrement64_nf(
   __int64 * lpAddend
);
```

### <a name="parameters"></a>Parâmetros

\ *lpAddend*
[entrada, saída] Ponteiro para a variável a ser decrementada.

## <a name="return-value"></a>Valor retornado

O valor retornado é o valor diminuído resultante.

## <a name="requirements"></a>Requisitos do

|Intrinsic|Arquitetura|
|---------------|------------------|
|`_InterlockedDecrement`, `_InterlockedDecrement16`|x86, ARM, x64, ARM64|
|`_InterlockedDecrement64`|ARM, x64, ARM64|
|`_InterlockedDecrement_acq`, `_InterlockedDecrement_rel`, `_InterlockedDecrement_nf`, `_InterlockedDecrement16_acq`, `_InterlockedDecrement16_rel`, `_InterlockedDecrement16_nf`, `_InterlockedDecrement64_acq`, `_InterlockedDecrement64_rel`, `_InterlockedDecrement64_nf`,|ARM, ARM64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

Há diversas variações em `_InterlockedDecrement` que têm base no tipo de dados que envolvem e se a semântica acquire ou release é usada.

Enquanto a função `_InterlockedDecrement` opera nos valores inteiros de 32 bits, `_InterlockedDecrement16` opera em valores inteiros de 16 bits `_InterlockedDecrement64` opera em valores inteiros de 64 bits.

Em plataformas ARM, use intrínsecos com os sufixos `_acq` e `_rel` para semântica de aquisição e liberação, como no início e no final de uma seção crítica. Os intrínsecos com um sufixo de `_nf` ("sem limite") não agem como uma barreira de memória.

A variável apontada para o parâmetro `lpAddend` deve estar alinhada em um limite de 32 bits; caso contrário, essa função falhará em sistemas de multiprocessor x86 e em qualquer sistema não x86. Para obter mais informações, consulte [alinhar](../cpp/align-cpp.md).

Essas rotinas somente estão disponíveis como intrínsecos.

## <a name="example"></a>Exemplo

```cpp
// compiler_intrinsics_interlocked.cpp
// compile with: /Oi
#define _CRT_RAND_S

#include <cstdlib>
#include <cstdio>
#include <process.h>
#include <windows.h>

// To declare an interlocked function for use as an intrinsic,
// include intrin.h and put the function in a #pragma intrinsic
// statement.
#include <intrin.h>

#pragma intrinsic (_InterlockedIncrement)

// Data to protect with the interlocked functions.
volatile LONG data = 1;

void __cdecl SimpleThread(void* pParam);

const int THREAD_COUNT = 6;

int main() {
   DWORD num;
   HANDLE threads[THREAD_COUNT];
   int args[THREAD_COUNT];
   int i;

   for (i = 0; i < THREAD_COUNT; i++) {
      args[i] = i + 1;
      threads[i] = reinterpret_cast<HANDLE>(_beginthread(SimpleThread, 0,
                           args + i));
      if (threads[i] == reinterpret_cast<HANDLE>(-1))
         // error creating threads
         break;
   }

   WaitForMultipleObjects(i, threads, true, INFINITE);
}

// Code for our simple thread
void __cdecl SimpleThread(void* pParam) {
   int threadNum = *((int*)pParam);
   int counter;
   unsigned int randomValue;
   unsigned int time;
   errno_t err = rand_s(&randomValue);

   if (err == 0) {
      time = (unsigned int) ((double) randomValue / (double) UINT_MAX * 500);
      while (data < 100) {
         if (data < 100) {
            _InterlockedIncrement(&data);
            printf_s("Thread %d: %d\n", threadNum, data);
         }

         Sleep(time);   // wait up to half of a second
      }
   }

   printf_s("Thread %d complete: %d\n", threadNum, data);
}
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

\ [intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
\ [palavras-chave](../cpp/keywords-cpp.md)
[conflitos com o compilador x86](../build/x64-software-conventions.md#conflicts-with-the-x86-compiler)
