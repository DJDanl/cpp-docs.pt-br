---
title: Erro CXX0065 (avaliador de expressão)
ms.date: 11/04/2016
f1_keywords:
- CXX0065
helpviewer_keywords:
- CAN0065
- CXX0065
ms.assetid: aac68f87-0b90-4c19-afa6-1c587625a5fd
ms.openlocfilehash: 7b62e42da2a74d910e2dc56ce2dfcb5cb38f2bfa
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62299308"
---
# <a name="expression-evaluator-error-cxx0065"></a>Erro CXX0065 (avaliador de expressão)

precisa de variável de quadro de pilha

Uma expressão continha uma variável que existe dentro do escopo atual, mas ainda não tiver sido criada.

Esse erro pode ocorrer quando você tiver entrado em prólogo de uma função, mas ainda não configurar o registro de ativação para a função, ou se você tiver entrado no código de saída para a função.

Percorrer o código de prólogo até que o quadro de pilha foi configurado antes de avaliar a expressão.

Esse erro é idêntico ao CAN0065.