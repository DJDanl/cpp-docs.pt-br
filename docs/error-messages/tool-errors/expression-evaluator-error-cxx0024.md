---
title: Erro CXX0024 (avaliador de expressão)
ms.date: 11/04/2016
f1_keywords:
- CXX0024
helpviewer_keywords:
- CXX0024
- CAN0024
ms.assetid: eca6adbd-8ff2-4f51-a1cc-a2e9d5d0a47d
ms.openlocfilehash: 525210090b0a4c2966f2e1432f85fd4bb6a8156d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80195754"
---
# <a name="expression-evaluator-error-cxx0024"></a>Erro CXX0024 (avaliador de expressão)

a operação precisa de l-Value

Uma expressão que não é avaliada como um valor l foi especificada para uma operação que requer um valor l.

Um l-Value (portanto chamado porque aparece no lado esquerdo de uma instrução de atribuição) é uma expressão que se refere a um local de memória.

Por exemplo, `buffer[count]` é um valor l válido porque aponta para um local de memória específico. O `zed != 0` de comparação lógica não é um valor l válido porque ele é avaliado como verdadeiro ou falso, e não com um endereço de memória.

Esse erro é idêntico a CAN0024.
