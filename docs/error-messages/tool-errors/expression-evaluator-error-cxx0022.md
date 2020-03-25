---
title: Erro CXX0022 (avaliador de expressão)
ms.date: 11/04/2016
f1_keywords:
- CXX0022
helpviewer_keywords:
- CXX0022
- CAN0022
ms.assetid: f6b299ac-a4ee-492c-bd9f-6fff005bc537
ms.openlocfilehash: 5858ce936acfb8b949351c9263f3a9379c73648e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80195819"
---
# <a name="expression-evaluator-error-cxx0022"></a>Erro CXX0022 (avaliador de expressão)

chamada de função antes de _main

O avaliador de expressão C não pode avaliar uma função antes que o depurador tenha inserido a função **_main**. O programa não foi inicializado corretamente até que **_main** tenha sido chamado.

Esse erro é idêntico a CAN0022.
