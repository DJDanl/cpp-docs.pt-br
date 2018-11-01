---
title: Erro fatal C1026
ms.date: 11/04/2016
f1_keywords:
- C1026
helpviewer_keywords:
- C1026
ms.assetid: 89bb9d40-673a-44aa-a9f4-b42c07b49d44
ms.openlocfilehash: b1a659967a9a62cb79e1084f7d1fa1729bae14da
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50666166"
---
# <a name="fatal-error-c1026"></a>Erro fatal C1026

estouro de pilha do analisador, programa muito complexo

O espaço necessário para analisar o programa causou um estouro de pilha do compilador.

Reduza a complexidade de expressões por:

- Diminuindo o aninhamento `for` e `switch` instruções. Colocar instruções mais profundamente aninhadas em funções separadas.

- Dividir expressões longas que envolvem operadores de vírgulas ou chamadas de função.