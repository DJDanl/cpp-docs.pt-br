---
title: Erro CXX0065 (avaliador de expressão)
ms.date: 11/04/2016
f1_keywords:
- CXX0065
helpviewer_keywords:
- CAN0065
- CXX0065
ms.assetid: aac68f87-0b90-4c19-afa6-1c587625a5fd
ms.openlocfilehash: b4120deec3c8e7ce14e381f782904cf83a588e43
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80184418"
---
# <a name="expression-evaluator-error-cxx0065"></a>Erro CXX0065 (avaliador de expressão)

a variável precisa de um quadro de pilha

Uma expressão continha uma variável que existe dentro do escopo atual, mas ainda não foi criada.

Esse erro pode ocorrer quando você tiver passado para o prólogo de uma função, mas ainda não tiver configurado o registro de ativação para a função, ou se você tiver percorrido o código de saída para a função.

Percorra o código de prólogo até que o registro de ativação tenha sido configurado antes de avaliar a expressão.

Esse erro é idêntico a CAN0065.
