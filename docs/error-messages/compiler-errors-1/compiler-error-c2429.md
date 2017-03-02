---
title: C2429 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
translationtype: Machine Translation
ms.sourcegitcommit: eb0c1bf407d1478451c246cf615d031ef6c45bf9
ms.openlocfilehash: 7d2c27ccdba28720596984c46c9d24f9d29c7b15
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2429"></a>C2429 de erro do compilador
'*recurso de linguagem*'requer o sinalizador do compilador'*opção de compilador*'  
  
O recurso de idioma requer uma opção de compilador específicas de suporte.  
  
O erro C2429: o recurso de idioma 'aninhado-namespace-definition' requer o sinalizador do compilador ' / std:c + + mais recente ' será gerado se você tentar definir uma *composta namespace*, um namespace que contém um ou mais nomes de namespace de escopo aninhado, a partir do Visual Studio 2015 atualização 3. Composto de namespace não são permitidas definições em C++ antes do C++&17;. O compilador suporta as definições do namespace composta quando o [/std:c + + mais recente](../../build/reference/std-specify-language-standard-version.md) for especificada a opção de compilador:  
```cpp  
// C2429a.cpp  
namespace a::b { int i; } // C2429 starting in Visual C++ 2015 Update 3.  
                          // Use /std:c++latest to fix, or do this:  
// namespace a { namespace b { int i; }}  
  
int main() {  
   a::b::i = 2;  
}  
```  
