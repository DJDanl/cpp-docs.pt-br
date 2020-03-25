---
title: Aviso LNK4219 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4219
helpviewer_keywords:
- LNK4219
ms.assetid: 363fedf4-b10c-4985-811a-55a9fba688d6
ms.openlocfilehash: 4488539a4f7282180048f1e3530e62e35c3b339e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80183092"
---
# <a name="linker-tools-warning-lnk4219"></a>Aviso LNK4219 (Ferramentas de Vinculador)

estouro de conserto de nome de correção. O ' nome do símbolo de destino ' de destino está fora do intervalo, inserindo conversão

O vinculador inseriu uma conversão em uma situação em que o endereço ou o deslocamento não conseguiu se ajustar à instrução especificada porque o símbolo de destino está muito longe do local da instrução.

Talvez você queira reordenar a imagem (usando a opção [/Order](../../build/reference/order-put-functions-in-order.md) , por exemplo) para evitar o nível extra de indireção.
