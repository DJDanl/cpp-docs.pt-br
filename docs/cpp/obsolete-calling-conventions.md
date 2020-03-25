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
ms.openlocfilehash: 156482a395c7dfc8711e273141a09a37ea3e135d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80188552"
---
# <a name="obsolete-calling-conventions"></a>Convenções de chamada obsoletas

**Seção específica da Microsoft**

Não há mais suporte para as convenções de chamada **__pascal**, **__fortran**e **__syscall** . Você pode emular a funcionalidade delas usando uma das convenções de chamada com suporte e as opções do vinculador apropriadas.

\<o Windows. h > Agora dá suporte à macro Winapi tenha, que se traduz na Convenção de chamada apropriada para o destino. Use Winapi tenha em que você usou anteriormente o PASCAL ou o **__far \__pascal**.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Convenções de passagem e nomenclatura de argumentos](../cpp/argument-passing-and-naming-conventions.md)
