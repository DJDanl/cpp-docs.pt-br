---
title: Erro CXX0030 (avaliador de expressão)
ms.date: 11/04/2016
f1_keywords:
- CXX0030
helpviewer_keywords:
- CAN0030
- CXX0030
ms.assetid: ada8b48c-09c8-49bf-ae23-313ed663c4fe
ms.openlocfilehash: 477ec31d18924e91baf2d8b7b732bc7a50eee53b
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80195611"
---
# <a name="expression-evaluator-error-cxx0030"></a>Erro CXX0030 (avaliador de expressão)

expressão não evaluatableda

O avaliador de expressão do depurador não pôde obter um valor para a expressão como gravada. Uma causa provável é que a expressão se refere à memória que está fora do espaço de endereço do programa (desreferenciar um ponteiro nulo é um exemplo). O Windows não permite o acesso à memória que está fora do espaço de endereço do programa.

Talvez você queira reescrever a expressão usando parênteses para controlar a ordem de avaliação.

Esse erro é idêntico a CAN0030.
