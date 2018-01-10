---
title: __shiftleft128 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: __shiftleft128
dev_langs: C++
helpviewer_keywords: __shiftleft128 intrinsic
ms.assetid: 557b846a-8fb0-469d-91ac-1b1fad80dc2a
caps.latest.revision: "17"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e1cfb3ed19fce5c737e7b30139ccaf01739888fd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="shiftleft128"></a>__shiftleft128
**Seção específica da Microsoft**  
  
 Desloca uma quantidade de 128 bits, representada como duas quantidades de 64 bits `LowPart` e `HighPart`, para a esquerda por um número de bits especificado pelo `Shift` e retorna os 64 bits altos do resultado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
unsigned __int64 __shiftleft128(   
   unsigned __int64 LowPart,   
   unsigned __int64 HighPart,   
   unsigned char Shift   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `LowPart`  
 Os 64 bits baixos da quantidade de 128 bits a deslocar.  
  
 [in] `HighPart`  
 Os 64 bits altos da quantidade de 128 bits a deslocar.  
  
 [in] `Shift`  
 O número de bits a deslocar.  
  
## <a name="return-value"></a>Valor de retorno  
 64 bits altos do resultado.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__shiftleft128`|[!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
## <a name="remarks"></a>Comentários  
 O valor `Shift` é sempre módulo 64 para que, por exemplo, se você chamar, `__shiftleft128(1, 0, 64)`, a função deslocará os bits baixos `0` para a esquerda e retornará uma parte alta de `0` e não `1` como podia ser esperado.  
  
## <a name="example"></a>Exemplo  
  
```  
// shiftleft128.c  
// processor: IPF, x64  
#include <stdio.h>  
#include <intrin.h>  
  
#pragma intrinsic (__shiftleft128, __shiftright128)  
  
int main()  
{  
    unsigned __int64 i = 0x1I64;  
    unsigned __int64 j = 0x10I64;  
    unsigned __int64 ResultLowPart;  
    unsigned __int64 ResultHighPart;  
  
    ResultLowPart = i << 1;  
    ResultHighPart = __shiftleft128(i, j, 1);  
  
    // concatenate the low and high parts padded with 0's  
    // to display correct hexadecimal 128 bit values  
    printf_s("0x%02I64x%016I64x << 1 = 0x%02I64x%016I64x\n",  
             j, i, ResultHighPart, ResultLowPart);  
  
    ResultHighPart = j >> 1;  
    ResultLowPart = __shiftright128(i, j, 1);  
  
    printf_s("0x%02I64x%016I64x >> 1 = 0x%02I64x%016I64x\n",  
             j, i, ResultHighPart, ResultLowPart);    
}  
```  
  
```Output  
0x100000000000000001 << 1 = 0x200000000000000002  
0x100000000000000001 >> 1 = 0x080000000000000000  
```  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [__shiftright128](../intrinsics/shiftright128.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)