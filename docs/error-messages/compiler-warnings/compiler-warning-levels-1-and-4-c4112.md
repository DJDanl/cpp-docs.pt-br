---
title: "Compilador (níveis 1 e 4) de aviso C4112 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4112
dev_langs:
- C++
helpviewer_keywords:
- C4112
ms.assetid: aff64897-bb79-4a67-9b6f-902c6d44f3dc
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6e82b2425aef840d8da7a0d0ad4dc4b81bd2a812
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-levels-1-and-4-c4112"></a>Compilador C4112 de aviso (níveis 1 e 4)
\#linha requer um inteiro entre 1 e o número  
  
 O [#line](../../preprocessor/hash-line-directive-c-cpp.md) diretiva especifica um parâmetro de número inteiro que está fora do intervalo permitido.  
  
 Se o parâmetro especificado é menor que 1, o contador de linha é redefinido para 1. Se o parâmetro especificado é maior do que *número*, que é o limite definido pelo compilador, o contador de linha é alterado. Este é um aviso de nível 1 em compatibilidade ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)) e um aviso de nível 4 com extensões da Microsoft ([/Ze](../../build/reference/za-ze-disable-language-extensions.md)).  
  
 O exemplo a seguir gera C4112:  
  
```  
// C4112.cpp  
// compile with: /W4  
#line 0   // C4112, value must be between 1 and number  
  
int main() {  
}  
```