---
title: __ll_rshift | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- __ll_rshift_cpp
- __ll_rshift
dev_langs:
- C++
helpviewer_keywords:
- __ll_rshift intrinsic
- ll_rshift intrinsic
ms.assetid: ef13b732-d122-44a0-add9-f5544a2c4ab2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4e086339c41f789323cb4aab386a96dae27a0eeb
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="llrshift"></a>__ll_rshift
**Seção específica da Microsoft**  
  
 Desloca um valor de 64 bits especificado pelo primeiro parâmetro para a direita em um número de bits especificado pelo segundo parâmetro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__int64 __ll_rshift(  
   __int64 Mask,  
   int nBit  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `Mask`  
 O valor de inteiro de 64 bits para deslocar para a direita.  
  
 [in] `nBit`  
 O número de bits para deslocar, módulo 64 em x64 e de módulo 32 em x86.  
  
## <a name="return-value"></a>Valor de retorno  
 A máscara é alterado em `nBit` bits.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__ll_rshift`|x86, [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
## <a name="remarks"></a>Comentários  
 Se o segundo parâmetro for maior que 64 em x64 (x86 de 32), esse número é obtido módulo 64 (x86 de 32) para determinar o número de bits para deslocar. O `ll` prefixo indica que esta é uma operação em `long long`, outro nome para `__int64`, o tipo integral assinado de 64 bits.  
  
## <a name="example"></a>Exemplo  
  
```  
// ll_rshift.cpp  
// compile with: /EHsc  
// processor: x86, x64  
#include <iostream>  
#include <intrin.h>  
using namespace std;  
  
#pragma intrinsic(__ll_rshift)  
  
int main()  
{  
   __int64 Mask = - 0x100;  
   int nBit = 4;  
   cout << hex << Mask << endl;  
   cout << " - " << (- Mask) << endl;  
   Mask = __ll_rshift(Mask, nBit);  
   cout << hex << Mask << endl;  
   cout << " - " << (- Mask) << endl;  
}  
```  
  
## <a name="output"></a>Saída  
  
```  
ffffffffffffff00  
 - 100  
fffffffffffffff0  
 - 10  
```  
  
 **Observação** se `_ull_rshift` tiver sido usado, o MSB do valor deslocada à direita seria zero, para que o resultado desejado não poderia ter sido obtido no caso de um valor negativo.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [__ll_lshift](../intrinsics/ll-lshift.md)   
 [__ull_rshift](../intrinsics/ull-rshift.md)