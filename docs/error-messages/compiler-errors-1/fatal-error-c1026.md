---
title: Erro fatal C1026
ms.date: 11/04/2016
f1_keywords:
- C1026
helpviewer_keywords:
- C1026
ms.assetid: 89bb9d40-673a-44aa-a9f4-b42c07b49d44
ms.openlocfilehash: a7c7a5da01c8b4a44c307a00f53530acb12a8009
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80204647"
---
# <a name="fatal-error-c1026"></a>Erro fatal C1026

estouro de pilha do analisador, programa muito complexo

O espaço necessário para analisar o programa causou um estouro de pilha do compilador.

Diminuir a complexidade das expressões por:

- Diminuindo o aninhamento nas instruções `for` e `switch`. Coloque instruções aninhadas mais profundamente em funções separadas.

- Dividir expressões longas que envolvem operadores de vírgula ou chamadas de função.
