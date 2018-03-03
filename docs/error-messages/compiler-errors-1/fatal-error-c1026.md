---
title: Erro fatal C1026 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1026
dev_langs:
- C++
helpviewer_keywords:
- C1026
ms.assetid: 89bb9d40-673a-44aa-a9f4-b42c07b49d44
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 206e9843fd8566f4f595a46918548af14f119439
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="fatal-error-c1026"></a>Erro fatal C1026
estouro de pilha do analisador, programa muito complexo  
  
 O espaço necessário para analisar o programa causou um estouro de pilha do compilador.  
  
 Reduza a complexidade das expressões por:  
  
-   Diminuindo o aninhamento em `for` e `switch` instruções. Colocar instruções mais profundamente aninhadas em funções separadas.  
  
-   Dividindo expressões longas que envolvem operadores de vírgula ou chamadas de função.