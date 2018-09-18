---
title: CXX0015 de erro do avaliador de expressão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- CXX0015
dev_langs:
- C++
helpviewer_keywords:
- CXX0015
- CAN0015
ms.assetid: 35efaf77-d578-48d8-bfc5-fdeb2a46a8b5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1aa37a2cc7208063ce4cfa786de196842ab42b45
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46050810"
---
# <a name="expression-evaluator-error-cxx0015"></a>Erro CXX0015 (avaliador de expressão)

expressão muito complexa (estouro de pilha)

A expressão inserida era muito complexo ou aninhados muito profundamente para a quantidade de armazenamento disponível para o avaliador de expressão de C.

Estouro normalmente ocorre devido a muitos cálculos pendentes.

Reorganize a expressão para que cada componente da expressão pode ser avaliada como ele é encontrado, em vez de ter que esperar para outras partes da expressão deve ser calculado.

Divida a expressão em vários comandos.

Esse erro é idêntico ao CAN0015.