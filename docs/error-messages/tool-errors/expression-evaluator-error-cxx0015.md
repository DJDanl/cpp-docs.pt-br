---
title: Erro CXX0015 (avaliador de expressão)
ms.date: 11/04/2016
f1_keywords:
- CXX0015
helpviewer_keywords:
- CXX0015
- CAN0015
ms.assetid: 35efaf77-d578-48d8-bfc5-fdeb2a46a8b5
ms.openlocfilehash: 19cf47d6b7b718eb19b987bcc16854af3266069b
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80196060"
---
# <a name="expression-evaluator-error-cxx0015"></a>Erro CXX0015 (avaliador de expressão)

expressão muito complexa (estouro de pilha)

A expressão inserida era muito complexa ou está aninhada muito profundamente para a quantidade de armazenamento disponível para o avaliador de expressão C.

O estouro geralmente ocorre devido a muitos cálculos pendentes.

Reorganize a expressão para que cada componente da expressão possa ser avaliado conforme for encontrado, em vez de ter que esperar que outras partes da expressão sejam calculadas.

Quebre a expressão em vários comandos.

Esse erro é idêntico a CAN0015.
