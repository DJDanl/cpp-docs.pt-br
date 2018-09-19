---
title: CXX0065 de erro do avaliador de expressão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- CXX0065
dev_langs:
- C++
helpviewer_keywords:
- CAN0065
- CXX0065
ms.assetid: aac68f87-0b90-4c19-afa6-1c587625a5fd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c100b1edbd36f4384e8deb1abf5b36465e8da479
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46024158"
---
# <a name="expression-evaluator-error-cxx0065"></a>Erro CXX0065 (avaliador de expressão)

precisa de variável de quadro de pilha

Uma expressão continha uma variável que existe dentro do escopo atual, mas ainda não tiver sido criada.

Esse erro pode ocorrer quando você tiver entrado em prólogo de uma função, mas ainda não configurar o registro de ativação para a função, ou se você tiver entrado no código de saída para a função.

Percorrer o código de prólogo até que o quadro de pilha foi configurado antes de avaliar a expressão.

Esse erro é idêntico ao CAN0065.