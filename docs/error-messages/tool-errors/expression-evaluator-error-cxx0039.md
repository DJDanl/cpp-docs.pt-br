---
title: Erro CXX0039 (avaliador de expressão)
ms.date: 11/04/2016
f1_keywords:
- CXX0039
helpviewer_keywords:
- CXX0039
- CAN0039
ms.assetid: 8bf698d2-e015-4595-944f-72b81aa43d22
ms.openlocfilehash: 5706d002eb3d566d05b059cb04b6b1626fdb3d33
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80185120"
---
# <a name="expression-evaluator-error-cxx0039"></a>Erro CXX0039 (avaliador de expressão)

o símbolo é ambíguo

O avaliador de expressão C não pode determinar qual instância de um símbolo usar em uma expressão. O símbolo ocorre mais de uma vez na árvore de herança.

Você deve usar o operador de resolução de escopo (`::`) para especificar explicitamente a instância a ser usada na expressão.

Esse erro é idêntico a CAN0039.
