---
title: C2429 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2429
dev_langs:
- C++
helpviewer_keywords:
- C2429
ms.assetid: 57ff6df9-5cf1-49f3-8bd8-4e550dfd65a0
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 18fd64199ff043b660bb205199b982ee2843cdcd
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2429"></a>C2429 de erro do compilador
'*recurso de idioma*'requer o sinalizador do compilador'*opção de compilador*'  
  
O recurso de idioma requer uma opção de compilador específico para obter suporte.  
  
O erro C2429: o recurso de linguagem 'aninhado--definição de namespace' requer o sinalizador do compilador ' / std:c + + mais recente ' será gerado se você tentar definir um *composta namespace*, um namespace que contém um ou mais nomes de namespace aninhado de escopo , a partir do Visual Studio 2015 atualização 3. Composta namespace não são permitidas definições em C++ antes de C++ 17. O compilador suporta as definições do namespace composta quando o [/std:c + + mais recente](../../build/reference/std-specify-language-standard-version.md) opção de compilador é especificada:  
```cpp  
// C2429a.cpp  
namespace a::b { int i; } // C2429 starting in Visual C++ 2015 Update 3.  
                          // Use /std:c++latest to fix, or do this:  
// namespace a { namespace b { int i; }}  
  
int main() {  
   a::b::i = 2;  
}  
```  
