---
title: noinline | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- noinline_cpp
dev_langs:
- C++
helpviewer_keywords:
- noinline __declspec keyword
- __declspec keyword [C++], noinline
ms.assetid: f259d55b-dec7-4bde-8cf9-14521e4fdc42
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: de433a1eccab3b58858aaf5fd3aa9ddb04d0cc1c
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39406071"
---
# <a name="noinline"></a>noinline
## <a name="microsoft-specific"></a>Específico da Microsoft  
 **{1&gt;__declspec(noinline)&lt;1** informa ao compilador para nunca embutir uma função de membro particular (em uma classe de função).  
  
 Pode ser válido não embutir uma função quando ela é pequena e não é crítica para o desempenho do seu código. Ou seja, se a função for pequena e se for improvável que ela seja chamada com frequência, como uma função que trata de uma condição de erro.  
  
 Tenha em mente que, se uma função for marcada **noinline**, a função de chamada será menor e, portanto, em si uma candidata para Embutimento pelo compilador.  
  
```cpp 
class X {  
   __declspec(noinline) int mbrfunc() {  
      return 0;   
   }   // will not inline  
};  
```  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [__declspec](../cpp/declspec.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [inline, __inline, \__forceinline](inline-functions-cpp.md)

