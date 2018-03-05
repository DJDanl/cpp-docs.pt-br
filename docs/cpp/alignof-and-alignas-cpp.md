---
title: alignof e alignas (C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: 1d18aa8a-9621-4fb5-86e5-4cc86d5187f4
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8a506a3c44c3304e786c41a2eb049939d317778e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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