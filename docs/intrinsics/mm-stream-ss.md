---
title: _mm_stream_ss | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- _mm_stream_ss
dev_langs:
- C++
helpviewer_keywords:
- movntss instruction
- _mm_stream_ss intrinsic
ms.assetid: c53dffe9-0dfe-4063-85d3-e8987b870fce
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b5058ac6c415f155b6a7cab712002d4769983d1f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33339482"
---
# <a name="mmstreamss"></a>_mm_stream_ss  
  
**Seção específica da Microsoft**  
  
 Grava dados de 32 bits em um local de memória sem polua caches.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void _mm_stream_ss(  
   float * Dest,  
   __m128 Source  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
  
 [out] `Dest`  
 Um ponteiro para o local onde os dados de origem são gravados.  
  
 [in] `Source`  
 Um número de 128 bits que contém o `float` valor a ser gravado no seu inferior de 32 bits.  
  
## <a name="return-value"></a>Valor de retorno  
  
 nenhuma.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`_mm_stream_ss`|SSE4a|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
## <a name="remarks"></a>Comentários  
  
Nesse intrínsecas gera o `movntss` instrução. Para determinar o suporte de hardware para essa instrução, chame o `__cpuid` intrínseco com `InfoType=0x80000001` e verifique o bit 6 de `CPUInfo[2] (ECX)`. Esse bit for 1 quando há suporte para a instrução e 0, caso contrário.  
  
Se você executar o código que usa o `_mm_stream_ss` intrínseco no hardware que não oferece suporte a `movntss` instrução, os resultados são imprevisíveis.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// Compile this sample with: /EHsc  
#include <iostream>  
#include <intrin.h>  
using namespace std;  
  
int main()  
{  
    __m128 vals;  
    float f[4];  
  
    f[0] = -1.;  
    f[1] = -2.;  
    f[2] = -3.;  
    f[3] = -4.;  
    vals.m128_f32[0] = 0.;  
    vals.m128_f32[1] = 1.;  
    vals.m128_f32[2] = 2.;  
    vals.m128_f32[3] = 3.;  
    _mm_stream_ss(&f[3], vals);  
    cout << "f[0] = " << f[0] << ", f[1] = " << f[1] << endl;  
    cout << "f[1] = " << f[1] << ", f[3] = " << f[3] << endl;  
}  
```  
  
```Output  
f[0] = -1, f[1] = -2  
f[2] = -3, f[3] = 3  
```  
  
**Fim da seção específica da Microsoft**  

Copyright 2007 Advanced Micro dispositivos, Inc. Todos os direitos reservados. Reproduzido com a permissão do Advanced Micro Devices, Inc.  
  
## <a name="see-also"></a>Consulte também  
 [_mm_stream_sd](../intrinsics/mm-stream-sd.md)   
 [_mm_stream_ps](https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_mm_stream_ps)   
 [_mm_store_ss](https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_mm_store_ss)   
 [_mm_sfence](https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_mm_sfence)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)