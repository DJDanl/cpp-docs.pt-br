---
title: "Operadores de pré-processador | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- preprocessor operators
- operators [C++], preprocessor
ms.assetid: 884126d1-0ce2-48b6-9e06-8a2d7c4a9656
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f28d2eba75636d6000f909ffe4527ca2b037dd85
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="preprocessor-operators"></a>Operadores de pré-processador
Quatro operadores específicos de pré-processadores são usados no contexto da política de `#define` (consulte a lista a seguir para obter um resumo de cada um.) Os operadores stringizing, charizing e token-pasting são discutidos nas três seções seguintes. Para obter informações sobre o **definido** operador, consulte [a #if, #elif, #else e #endif](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md).  
  
|Operador|Ação|  
|--------------|------------|  
|[Operador stringizing (#)](../preprocessor/stringizing-operator-hash.md)|Faz com que o argumento correspondente real seja incluído entre aspas duplas|  
|[Operador de caracterização (#@)](../preprocessor/charizing-operator-hash-at.md)|Faz com que o argumento correspondente seja incluído entre aspas simples e tratado como um caractere (específico da Microsoft)|  
|[Operador de colagem de token (#)](../preprocessor/token-pasting-operator-hash-hash.md)|Permite que os tokens utilizados como argumentos reais sejam concatenados para formar outros tokens|  
|[operador definido](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md)|Simplifica a gravação de expressões compostas em determinadas políticas de macro|  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas de pré-processador](../preprocessor/preprocessor-directives.md)   
 [Macros predefinidas](../preprocessor/predefined-macros.md)   
 [Referência de pré-processador do C/C++](../preprocessor/c-cpp-preprocessor-reference.md)