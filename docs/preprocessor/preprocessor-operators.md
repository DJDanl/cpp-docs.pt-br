---
title: "Operadores de pré-processador | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- preprocessor operators
- operators [C++], preprocessor
ms.assetid: 884126d1-0ce2-48b6-9e06-8a2d7c4a9656
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 551b2c3ba8a5055fc6b6dfd1b94c461c37e72209
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
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