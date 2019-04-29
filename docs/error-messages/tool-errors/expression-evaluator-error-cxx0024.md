---
title: Erro CXX0024 (avaliador de expressão)
ms.date: 11/04/2016
f1_keywords:
- CXX0024
helpviewer_keywords:
- CXX0024
- CAN0024
ms.assetid: eca6adbd-8ff2-4f51-a1cc-a2e9d5d0a47d
ms.openlocfilehash: 93f8389ed3959d5747e46c1234fd8d2eae0f1ae5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62359826"
---
# <a name="expression-evaluator-error-cxx0024"></a>Erro CXX0024 (avaliador de expressão)

operação precisa l-value

Uma expressão que não é avaliada como um l-value foi especificada para uma operação que exige um l-value.

Um l-value (portanto, é chamado porque ele aparece no lado esquerdo de uma instrução de atribuição) é uma expressão que se refere a um local de memória.

Por exemplo, `buffer[count]` é um l-value válido que aponta para um local específico da memória. A comparação lógica `zed != 0` não é um l-value válido porque ele será avaliado como TRUE ou FALSE, não como um endereço de memória.

Esse erro é idêntico ao CAN0024.