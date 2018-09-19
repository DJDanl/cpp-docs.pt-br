---
title: CXX0024 de erro do avaliador de expressão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- CXX0024
dev_langs:
- C++
helpviewer_keywords:
- CXX0024
- CAN0024
ms.assetid: eca6adbd-8ff2-4f51-a1cc-a2e9d5d0a47d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2816be7bb1d33757d9722d605d461ac6fb34fadd
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46118187"
---
# <a name="expression-evaluator-error-cxx0024"></a>Erro CXX0024 (avaliador de expressão)

operação precisa l-value

Uma expressão que não é avaliada como um l-value foi especificada para uma operação que exige um l-value.

Um l-value (portanto, é chamado porque ele aparece no lado esquerdo de uma instrução de atribuição) é uma expressão que se refere a um local de memória.

Por exemplo, `buffer[count]` é um l-value válido que aponta para um local específico da memória. A comparação lógica `zed != 0` não é um l-value válido porque ele será avaliado como TRUE ou FALSE, não como um endereço de memória.

Esse erro é idêntico ao CAN0024.