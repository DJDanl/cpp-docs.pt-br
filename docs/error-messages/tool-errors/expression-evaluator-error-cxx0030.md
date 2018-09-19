---
title: CXX0030 de erro do avaliador de expressão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- CXX0030
dev_langs:
- C++
helpviewer_keywords:
- CAN0030
- CXX0030
ms.assetid: ada8b48c-09c8-49bf-ae23-313ed663c4fe
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: cb2921013d116b7d8f02e1e29380ca3cd14086b9
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46102797"
---
# <a name="expression-evaluator-error-cxx0030"></a>Erro CXX0030 (avaliador de expressão)

expressão não evaluatable

O avaliador de expressão do depurador não foi possível obter um valor para a expressão como escrito. Uma causa provável é que a expressão se refere a memória que está fora do espaço de endereço do programa (desreferenciar um ponteiro nulo é um exemplo). Windows não permitem acesso à memória que está fora do espaço de endereço do programa.

Você talvez queira reescrever seu usando parênteses para controlar a ordem de avaliação de expressão.

Esse erro é idêntico ao CAN0030.