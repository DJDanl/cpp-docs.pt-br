---
title: "Convenções de chamada | Microsoft Docs"
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
helpviewer_keywords:
- calling conventions
ms.assetid: 11b1e45c-8fd1-420b-bca0-a19e294c1d85
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: bbdee0427dcefc019214e7f9af16831f162cef83
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="calling-conventions"></a>Convenções de chamada
O compilador Visual C/C++ fornece várias convenções diferentes para chamar funções internas e externos. Entender essas abordagens diferentes pode ajudar a depurar seu programa e a vincular seu código a rotinas de linguagem de assembly.  
  
 Os tópicos neste assunto explicam as diferenças entre as convenções de chamada, como os argumentos são passados, e como os valores são retornados por funções. Também são abordadas chamadas de função naked, um recurso avançado que permite escrever seu próprio código de prólogo e epílogo.  
  
 Para obter informações sobre convenções de chamada para x64 processadores, consulte [convenção de chamada](../build/calling-convention.md).  
  
## <a name="topics-in-this-section"></a>Tópicos desta seção  
  
-   [Transmissão de argumentos e convenções de nomenclatura](../cpp/argument-passing-and-naming-conventions.md) (`__cdecl`, `__stdcall`, `__fastcall`e outros)  
  
-   [Exemplo de chamada: protótipo de função e chamada](../cpp/calling-example-function-prototype-and-call.md)  
  
-   [Usando chamadas de função naked para escrever código de prólogo/epílogo personalizado](../cpp/naked-function-calls.md)  
  
-   [Coprocessador de ponto flutuante e convenções de chamada](../cpp/floating-point-coprocessor-and-calling-conventions.md)  
  
-   [Convenções de chamada obsoletas](../cpp/obsolete-calling-conventions.md)  
  
## <a name="see-also"></a>Consulte também  
 [Modificadores específicos da Microsoft](../cpp/microsoft-specific-modifiers.md)
