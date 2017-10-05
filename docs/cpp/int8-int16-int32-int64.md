---
title: int8, Int16, Int32, Int64 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- __int8_cpp
- __int64
- __int8
- __int16
- __int16_cpp
- __int64_cpp
- __int32_cpp
- __int32
dev_langs:
- C++
helpviewer_keywords:
- __int16 keyword [C++]
- integer data type, integer types in C++
- __int32 keyword [C++]
- integer types [C++]
- __int8 keyword [C++]
- __int64 keyword [C++]
ms.assetid: 8e384602-2578-4980-8cc8-da63842356b2
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 82b06a776d40121b5f147388dadf053b5b072659
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="int8-int16-int32-int64"></a>__int8, __int16, __int32, __int64
## <a name="microsoft-specific"></a>Específico da Microsoft  
 O Microsoft C/C++ tem suporte para tipos de inteiros dimensionados. Você pode declarar 8, 16, 32 ou variáveis de inteiro de 64 bits usando o **__int** * n * digite especificador, onde * n * é 8, 16, 32 ou 64.  
  
 O exemplo a seguir declara uma variável para cada um desses tipos de inteiros dimensionados:  
  
```  
__int8 nSmall;      // Declares 8-bit integer  
__int16 nMedium;    // Declares 16-bit integer  
__int32 nLarge;     // Declares 32-bit integer  
__int64 nHuge;      // Declares 64-bit integer  
```  
  
 Os tipos `__int8`, `__int16` e `__int32` são sinônimos dos tipos ANSI que têm o mesmo tamanho e são úteis para escrever o código portátil que se comporta de forma idêntica em várias plataformas. O `__int8` tipo de dados é sinônimo de tipo `char`, `__int16` é sinônimo de tipo **curto**, e `__int32` é sinônimo de tipo `int`. O tipo `__int64` não tem equivalente ANSI.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra que um __int*xx* parâmetro será promovido para `int`:  
  
```  
// sized_int_types.cpp  
  
#include <stdio.h>  
  
void func(int i) {  
    printf_s("%s\n", __FUNCTION__);  
}  
  
int main()  
{  
    __int8 i8 = 100;  
    func(i8);   // no void func(__int8 i8) function  
                // __int8 will be promoted to int  
}  
```  
  
```Output  
func  
```  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Tipos fundamentais](../cpp/fundamental-types-cpp.md)   
 [Intervalos de tipos de dados](../cpp/data-type-ranges.md)
