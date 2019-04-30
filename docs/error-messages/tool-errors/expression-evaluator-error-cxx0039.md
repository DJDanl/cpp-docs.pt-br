---
title: Erro CXX0039 (avaliador de expressão)
ms.date: 11/04/2016
f1_keywords:
- CXX0039
helpviewer_keywords:
- CXX0039
- CAN0039
ms.assetid: 8bf698d2-e015-4595-944f-72b81aa43d22
ms.openlocfilehash: 053e57a21f0cb75cbd96732edb6812b3557bcd50
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62396971"
---
# <a name="expression-evaluator-error-cxx0039"></a>Erro CXX0039 (avaliador de expressão)

o símbolo é ambíguo

O avaliador de expressão C não pode determinar qual instância de um símbolo a ser usado em uma expressão. O símbolo ocorre mais de uma vez na árvore de herança.

Você deve usar o operador de resolução de escopo (`::`) para especificar explicitamente a instância a ser usada na expressão.

Esse erro é idêntico ao CAN0039.