---
title: CXX0039 de erro do avaliador de expressão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- CXX0039
dev_langs:
- C++
helpviewer_keywords:
- CXX0039
- CAN0039
ms.assetid: 8bf698d2-e015-4595-944f-72b81aa43d22
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b5397426618c5dfcbaa6307105781ff2e6f2eb97
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46048325"
---
# <a name="expression-evaluator-error-cxx0039"></a>Erro CXX0039 (avaliador de expressão)

o símbolo é ambíguo

O avaliador de expressão C não pode determinar qual instância de um símbolo a ser usado em uma expressão. O símbolo ocorre mais de uma vez na árvore de herança.

Você deve usar o operador de resolução de escopo (`::`) para especificar explicitamente a instância a ser usada na expressão.

Esse erro é idêntico ao CAN0039.