---
title: _mm_stream_sd | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- _mm_stream_sd
dev_langs:
- C++
helpviewer_keywords:
- _mm_stream_sd intrinsic
- movntsd instruction
ms.assetid: 2b4bea5e-e64e-45fa-9afc-88a2e4b82cfc
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e5d9d5a4d984e09ef8e77a4b7128d266d05f6b64
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="mmstreamsd"></a>_mm_stream_sd
**Seção específica da Microsoft**  
  
 Grava dados de 64 bits em um local de memória sem polua caches.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void _mm_stream_sd(  
   double * Dest,  
   __m128d Source  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [out] `Dest`  
 Um ponteiro para o local onde os dados de origem serão gravados.  
  
 [in] `Source`  
 Um valor de 128 bits que contém o `double` valor a ser gravado no seu inferior de 64 bits.  
  
## <a name="return-value"></a>Valor de retorno  
 Nenhum.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`_mm_stream_sd`|SSE4a|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
## <a name="remarks"></a>Comentários  
 Nesse intrínsecas gera o `movntsd` instrução. Para determinar o suporte de hardware para essa instrução, chame o `__cpuid` intrínseco com `InfoType=0x80000001` e verifique o bit 6 de `CPUInfo[2] (ECX)`. Esse bit for 1, se o hardware der suporte a essa instrução e 0 caso contrário.  
  
 Se você executar o código que usa o `_mm_stream_sd` intrínseco no hardware que não oferece suporte a `movntsd` instrução, os resultados são imprevisíveis.  
  
## <a name="example"></a>Exemplo  
  
```  
// Compile this sample with: /EHsc  
#include <iostream>  
#include <intrin.h>  
using namespace std;  
  
int main()  
{  
    __m128d vals;  
    double d[2];  
  
    d[0] = -1.;  
    d[1] = -2.;  
    vals.m128d_f64[0] = 0.;  
    vals.m128d_f64[1] = 1.;  
    _mm_stream_sd(&d[1], vals);  
    cout << "d[0] = " << d[0] << ", d[1] = " << d[1] << endl;  
}  
  
```  
  
```Output  
d[0] = -1, d[1] = 1  
```  
  
**Fim da seção específica da Microsoft**  
 Copyright 2007 Advanced Micro dispositivos, Inc. Todos os direitos reservados. Reproduzido com a permissão do Advanced Micro Devices, Inc.  
  
## <a name="see-also"></a>Consulte também  
 [_mm_stream_ss](../intrinsics/mm-stream-ss.md)   
 [_mm_store_sd](https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_mm_store_sd)   
 [_mm_sfence](https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_mm_sfence)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)