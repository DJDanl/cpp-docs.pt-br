---
title: "Compilador (nível 1) de aviso C4964 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4964
dev_langs:
- C++
helpviewer_keywords:
- C4964
ms.assetid: b89c9274-8a92-4b7c-aa30-3fbb1b68ac73
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b1c7483b82c363898bc16ed5fc7d48f9cf0b35c7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4964"></a>Compilador C4964 de aviso (nível 1)
Nenhuma opção de otimização foi especificada; informações de perfil não serão coletadas  
  
 [/GL](../../build/reference/gl-whole-program-optimization.md) e [/LTCG](../../build/reference/ltcg-link-time-code-generation.md) foram especificadas, mas nenhum otimizações foram solicitados, para que nenhum arquivo. PGC será gerado e, portanto, não será possível nenhuma Otimização Guiada por perfil.  
  
 Se desejar que os arquivos. PGC para ser gerado quando você executar o aplicativo, especifique uma da [/O](../../build/reference/o-options-optimize-code.md) opções do compilador.  
  
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