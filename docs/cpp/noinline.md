---
title: noinline | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- noinline_cpp
dev_langs:
- C++
helpviewer_keywords:
- noinline __declspec keyword
- __declspec keyword [C++], noinline
ms.assetid: f259d55b-dec7-4bde-8cf9-14521e4fdc42
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6d959235cbcad3e33140c2711633a55c1bba2096
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="noinline"></a>noinline
## <a name="microsoft-specific"></a>Específico da Microsoft  
 **__declspec(noinline)** informa ao compilador embutido nunca uma função de membro particular (em uma classe de função).  
  
 Pode ser válido não embutir uma função quando ela é pequena e não é crítica para o desempenho do seu código. Ou seja, se a função for pequena e se for improvável que ela seja chamada com frequência, como uma função que trata de uma condição de erro.  
  
 Lembre-se de que, se uma função for marcada como `noinline`, a função de chamada será menor e portanto, será uma candidata para embutimento pelo compilador.  
  
```  
class X {  
   __declspec(noinline) int mbrfunc() {  
      return 0;   
   }   // will not inline  
};  
```  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [declspec](../cpp/declspec.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [inline, __inline, \__forceinline](inline-functions-cpp.md)

