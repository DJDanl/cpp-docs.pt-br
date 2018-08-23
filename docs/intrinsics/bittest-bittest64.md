---
title: _bittest, _bittest64 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- _bittest64
- _bittest_cpp
- _bittest64_cpp
- _bittest
dev_langs:
- C++
helpviewer_keywords:
- _bittest intrinsic
- _bittest64 intrinsic
- bt instruction
ms.assetid: 15e62afb-abea-4ee7-a6b1-13efa2034937
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 623077695731b88285769c5b887b1f64f5263855
ms.sourcegitcommit: a41c4d096afca1e9b619bbbce045b77135d32ae2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/14/2018
ms.locfileid: "42544378"
---
# <a name="bittest-bittest64"></a>_bittest, _bittest64
**Seção específica da Microsoft**  
  
Gera a instrução `bt`, que examina o bit na posição `b` do endereço `a`e retorna o valor desse bit.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
unsigned char _bittest(  
   long const *a,  
   long b  
);  
unsigned char _bittest64(  
   __int64 const *a,  
   __int64 b  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
[in] `a`  
Um ponteiro para a memória a examinar.  
  
[in] `b`  
A posição de bit a testar.  
  
### <a name="return-value"></a>Valor de retorno  
O bit na posição especificada.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|Cabeçalho|  
|---------------|------------------|------------|  
|`_bittest`|x86, ARM, x64|\<intrin.h>|  
|`_bittest64`|ARM, x64|\<intrin.h>|  
  
## <a name="remarks"></a>Comentários  
Essa rotina só está disponível como função intrínseca.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// bittest.cpp  
// processor: x86, ARM, x64  
  
#include <stdio.h>  
#include <intrin.h>  
  
long num = 78002;  
  
int main()  
{  
    unsigned char bits[32];  
    long nBit;  
  
    printf_s("Number: %d\n", num);  
  
    for (nBit = 0; nBit < 31; nBit++)  
    {  
        bits[nBit] = _bittest(&num, nBit);  
    }  
  
    printf_s("Binary representation:\n");  
    while (nBit--)  
    {  
        if (bits[nBit])  
            printf_s("1");  
        else  
            printf_s("0");  
    }  
}  
```  
  
```Output  
Number: 78002  
Binary representation:  
0000000000000010011000010110010  
```  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)