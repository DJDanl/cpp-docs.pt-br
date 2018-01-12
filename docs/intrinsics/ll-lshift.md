---
title: __ll_lshift | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- __ll_lshift_cpp
- __ll_lshift
dev_langs: C++
helpviewer_keywords:
- ll_lshift intrinsic
- __ll_lshift intrinsic
ms.assetid: fe98f733-426d-44b3-8f24-5d0d6d44bd94
caps.latest.revision: "16"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 958ade238317d1577bd93d373b9e8ce4aa1f4234
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="lllshift"></a>__ll_lshift
**Seção específica da Microsoft**  
  
 Desloca o valor fornecido de 64 bits para a esquerda pelo número especificado de bits.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
unsigned __int64 __ll_lshift(  
   unsigned __int64 Mask,  
   int nBit  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `Mask`  
 O valor inteiro de 64-bit shift esquerda.  
  
 [in] `nBit`  
 O número de bits a deslocar.  
  
## <a name="return-value"></a>Valor de retorno  
 A máscara adiantadas esquerda por `nBit` bits.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__ll_lshift`|x86, [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
## <a name="remarks"></a>Comentários  
 Se você compilar seu programa usando a arquitetura de 64 bits e `nBit` é maior do que 63, é o número de bits para deslocar `nBit` módulo 64. Se você compilar seu programa usando a arquitetura de 32 bits e `nBit` é maior do que 31, é o número de bits para deslocar `nBit` módulo 32.  
  
 O `ll` o nome indica que esta é uma operação em `long long` (`__int64`).  
  
## <a name="example"></a>Exemplo  
  
```  
// ll_lshift.cpp  
// compile with: /EHsc  
// processor: x86, x64  
#include <iostream>  
#include <intrin.h>  
using namespace std;  
  
#pragma intrinsic(__ll_lshift)  
  
int main()  
{  
   unsigned __int64 Mask = 0x100;  
   int nBit = 8;  
   Mask = __ll_lshift(Mask, nBit);  
   cout << hex << Mask << endl;  
}  
```  
  
## <a name="output"></a>Saída  
  
```  
10000  
```  
  
 **Observação** não há nenhuma versão não assinada da operação de deslocamento para a esquerda. Isso ocorre porque `__ll_lshift` já usa um parâmetro de entrada não assinado. Ao contrário de deslocamento à direita, não há nenhuma dependência de entrada para o deslocamento à esquerda, porque o bit menos significativo no resultado é sempre definido como zero, independentemente do sinal do valor alterado.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [__ll_rshift](../intrinsics/ll-rshift.md)   
 [__ull_rshift](../intrinsics/ull-rshift.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)