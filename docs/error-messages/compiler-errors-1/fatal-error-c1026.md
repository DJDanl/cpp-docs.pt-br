---
title: Erro fatal C1026 | Documentos do Microsoft
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
caps.latest.revision: 7
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 7755bb1cb5051b77d7d4cb46aeac2303afd857ac
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1026"></a>Erro fatal C1026
estouro na pilha do analisador, programa muito complexo  
  
 O espaço necessário para analisar o programa causou um estouro de pilha do compilador.  
  
 Reduza a complexidade das expressões por:  
  
-   Diminuindo o aninhamento no `for` e `switch` instruções. Colocar instruções mais profundamente aninhadas em funções separadas.  
  
-   Dividir expressões longas que envolvem operadores de vírgula ou chamadas de função.
