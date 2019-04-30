---
title: Aviso LNK4219 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4219
helpviewer_keywords:
- LNK4219
ms.assetid: 363fedf4-b10c-4985-811a-55a9fba688d6
ms.openlocfilehash: 7407537b55525bf622fc11cdbdb8e00244e51c18
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62410246"
---
# <a name="linker-tools-warning-lnk4219"></a>Aviso LNK4219 (Ferramentas de Vinculador)

estouro de conserto de nome de correção. Destino de 'nome do símbolo de destino' está fora do intervalo, inserindo conversão

O vinculador inserido uma conversão em uma situação em que o endereço ou o deslocamento não pôde ajustar na instrução de determinado porque o símbolo de destino está muito longe do local da instrução.

Talvez você queira reordenar a imagem (usando o [/ORDER](../../build/reference/order-put-functions-in-order.md) opção, por exemplo) para evitar o nível extra de indireção.