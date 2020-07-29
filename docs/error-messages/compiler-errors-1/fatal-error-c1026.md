---
title: Erro fatal C1026
ms.date: 11/04/2016
f1_keywords:
- C1026
helpviewer_keywords:
- C1026
ms.assetid: 89bb9d40-673a-44aa-a9f4-b42c07b49d44
ms.openlocfilehash: 9ea97bef16bebb8fc0e765ed708e54baee9a64de
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220334"
---
# <a name="fatal-error-c1026"></a>Erro fatal C1026

estouro de pilha do analisador, programa muito complexo

O espaço necessário para analisar o programa causou um estouro de pilha do compilador.

Diminuir a complexidade das expressões por:

- Diminuindo o aninhamento **`for`** nas **`switch`** instruções e. Coloque instruções aninhadas mais profundamente em funções separadas.

- Dividir expressões longas que envolvem operadores de vírgula ou chamadas de função.
