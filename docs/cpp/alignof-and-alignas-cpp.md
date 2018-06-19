---
title: alignof e alignas (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: 1d18aa8a-9621-4fb5-86e5-4cc86d5187f4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1e2988d1260cac91e2614765aba8ae1b9be9b922
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32407974"
---
# <a name="alignof-and-alignas-c"></a>alignof e alignas (C++)
O `alignas` especificador de tipo é um modo padrão do C++ portáteis, para especificar um alinhamento personalizado de variáveis e tipos definidos pelo usuário. O `alignof` operador da mesma forma é uma forma padrão portátil para obter o alinhamento de um tipo especificado ou variável.  
  
## <a name="example"></a>Exemplo  
 Você pode usar `alignas` em uma classe com traçado ou union, ou em membros individuais. Quando vários `alignas` especificadores forem encontrados, o compilador escolherá aquele mais rígido, (aquele com o maior valor).  
  
```cpp  
// alignas_alignof.cpp
// compile with: cl /EHsc alignas_alignof.cpp
#include <iostream>

struct alignas(16) Bar  
{      
    int i;       // 4 bytes  
    int n;      // 4 bytes  
    alignas(4) char arr[3];  
    short s;          // 2 bytes  
};  

int main()
{  
    std::cout << alignof(Bar) << std::endl; // output: 16  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Alinhamento](../cpp/alignment-cpp-declarations.md)