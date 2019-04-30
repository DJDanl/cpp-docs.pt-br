---
title: Erro CXX0015 (avaliador de expressão)
ms.date: 11/04/2016
f1_keywords:
- CXX0015
helpviewer_keywords:
- CXX0015
- CAN0015
ms.assetid: 35efaf77-d578-48d8-bfc5-fdeb2a46a8b5
ms.openlocfilehash: f73aef18563426d28a81b92b3c37d1b7e345d0d3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62397140"
---
# <a name="expression-evaluator-error-cxx0015"></a>Erro CXX0015 (avaliador de expressão)

expressão muito complexa (estouro de pilha)

A expressão inserida era muito complexo ou aninhados muito profundamente para a quantidade de armazenamento disponível para o avaliador de expressão de C.

Estouro normalmente ocorre devido a muitos cálculos pendentes.

Reorganize a expressão para que cada componente da expressão pode ser avaliada como ele é encontrado, em vez de ter que esperar para outras partes da expressão deve ser calculado.

Divida a expressão em vários comandos.

Esse erro é idêntico ao CAN0015.