---
title: Erro fatal C1026 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1026
dev_langs:
- C++
helpviewer_keywords:
- C1026
ms.assetid: 89bb9d40-673a-44aa-a9f4-b42c07b49d44
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 24c034d45b7f8b222471094f4580902ae1b8dc66
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="fatal-error-c1026"></a>Erro fatal C1026
estouro de pilha do analisador, programa muito complexo  
  
 O espaço necessário para analisar o programa causou um estouro de pilha do compilador.  
  
 Reduza a complexidade das expressões por:  
  
-   Diminuindo o aninhamento em `for` e `switch` instruções. Colocar instruções mais profundamente aninhadas em funções separadas.  
  
-   Dividindo expressões longas que envolvem operadores de vírgula ou chamadas de função.