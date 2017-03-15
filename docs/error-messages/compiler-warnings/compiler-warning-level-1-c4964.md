---
title: "Compilador aviso (nível 1) C4964 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4964
dev_langs:
- C++
helpviewer_keywords:
- C4964
ms.assetid: b89c9274-8a92-4b7c-aa30-3fbb1b68ac73
caps.latest.revision: 8
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 49e808850ba2d65266ec68364acc0a7956d00915
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4964"></a>Compilador C4964 de aviso (nível 1)
Nenhuma opção de otimização foi especificada; informações de perfil não serão coletadas  
  
 [/GL](../../build/reference/gl-whole-program-optimization.md) e [/LTCG](../../build/reference/ltcg-link-time-code-generation.md) foram especificadas, mas sem otimizações foram solicitados, portanto nenhum arquivo .pgc será gerado e, portanto, será possíveis sem otimizações guiadas por perfil.  
  
 Se você quiser .pgc arquivos sejam gerados quando você executar o aplicativo, especifique uma da [/O](../../build/reference/o-options-optimize-code.md) opções do compilador.  
  
 O exemplo a seguir gera C4964:  
  
```  
// C4964.cpp  
// compile with: /W1 /GL /link /ltcg:pgi  
// C4964 expected  
// Add /O2, for example, to the command line to resolve this warning.  
int main() {  
   int i;  
}  
```
