---
title: Convenções de chamada obsoletas
ms.date: 11/04/2016
f1_keywords:
- __fortran
- __pascal
- __syscall
helpviewer_keywords:
- WINAPI [C++]
- __syscall keyword [C++]
- __pascal keyword [C++]
- __fortran keyword [C++]
- calling conventions, obsolete
ms.assetid: a91fc665-034a-48ce-b6bd-d27125f308a7
ms.openlocfilehash: 7f059afe02cbbad77920fd8c4a0e6cb7c958e992
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857353"
---
# <a name="obsolete-calling-conventions"></a>Convenções de chamada obsoletas

**Seção específica da Microsoft**

Não há mais suporte para as convenções de chamada **__pascal**, **__fortran**e **__syscall** . Você pode emular a funcionalidade delas usando uma das convenções de chamada com suporte e as opções do vinculador apropriadas.

\<o Windows. h > Agora dá suporte à macro Winapi tenha, que se traduz na Convenção de chamada apropriada para o destino. Use Winapi tenha em que você usou anteriormente o PASCAL ou o **__far \__pascal**.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Convenções de passagem e nomenclatura de argumentos](../cpp/argument-passing-and-naming-conventions.md)