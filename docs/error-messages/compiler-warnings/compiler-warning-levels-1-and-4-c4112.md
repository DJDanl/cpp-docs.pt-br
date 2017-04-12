---
title: "Compilador (níveis 1 e 4) de aviso C4112 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4112
dev_langs:
- C++
helpviewer_keywords:
- C4112
ms.assetid: aff64897-bb79-4a67-9b6f-902c6d44f3dc
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: f7733698b8b819ffeb145425749ca0ffbc40848c
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-levels-1-and-4-c4112"></a>Compilador C4112 de aviso (níveis 1 e 4)
\#linha requer um número inteiro entre 1 e número  
  
 O [#line](../../preprocessor/hash-line-directive-c-cpp.md) diretiva especifica um parâmetro de número inteiro que está fora do intervalo permitido.  
  
 Se o parâmetro especificado é menor que 1, o contador de linha é redefinido para 1. Se o parâmetro especificado é maior que *número*, que é o limite definido pelo compilador, o contador de linha permanece inalterado. Este é um aviso de nível 1 em compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)) e um aviso de nível 4 com extensões da Microsoft ([/Ze](../../build/reference/za-ze-disable-language-extensions.md)).  
  
 O exemplo a seguir gera C4112:  
  
```  
// C4112.cpp  
// compile with: /W4  
#line 0   // C4112, value must be between 1 and number  
  
int main() {  
}  
```
