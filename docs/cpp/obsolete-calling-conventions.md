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
ms.openlocfilehash: 86c75c779158d9f191dd015410cf16c9ce25690d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62245007"
---
# <a name="obsolete-calling-conventions"></a>Convenções de chamada obsoletas

## <a name="microsoft-specific"></a>Específico da Microsoft

O **Pascal**, **Fortran**, e **syscall** convenções de chamada não têm mais suporte. Você pode emular a funcionalidade delas usando uma das convenções de chamada com suporte e as opções do vinculador apropriadas.

\<Windows. h > agora é compatível com a macro WINAPI, que se traduz a convenção de chamada apropriada para o destino. Usar WINAPI onde você usava PASCAL ou **__far \__pascal**.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Convenções de passagem e nomenclatura de argumentos](../cpp/argument-passing-and-naming-conventions.md)