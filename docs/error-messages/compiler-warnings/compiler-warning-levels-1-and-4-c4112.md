---
title: Compilador (níveis 1 e 4) de aviso C4112 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4112
dev_langs:
- C++
helpviewer_keywords:
- C4112
ms.assetid: aff64897-bb79-4a67-9b6f-902c6d44f3dc
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 43718511af0d85f0c9026fe70b4749c4e3d4b1e4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33299273"
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