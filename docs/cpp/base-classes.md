---
title: Classes base
ms.date: 11/19/2018
helpviewer_keywords:
- inheritance, multiple
- base classes [C++], virtual
- derived classes [C++], multiple bases
- multiple inheritance, base classes
- virtual base classes [C++]
- base classes [C++]
ms.assetid: 6e6d54d0-6f21-4a16-9103-22935d98f596
ms.openlocfilehash: 59c474f54ea439acf83cf6923eba6e167901dd37
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62392396"
---
# <a name="base-classes"></a>Classes base

O processo de herança cria uma nova classe derivada que é composta dos membros da classe base (ou das classes base), mais os novos membros adicionados pela classe derivada. Em uma herança múltipla, é possível construir um gráfico de herança em que a mesma classe base faz parte de mais de uma das classes derivadas. A figura a seguir mostra um gráfico desse tipo.

![Várias instâncias de uma classe base](../cpp/media/vc38xn1.gif "várias instâncias de uma classe base") <br/>
Várias instâncias de uma única classe base

Na figura, são mostradas representações pictóricas dos componentes de `CollectibleString` e `CollectibleSortable`. No entanto, a classe base, `Collectible`, está em `CollectibleSortableString` pelo caminho de `CollectibleString` e pelo caminho de `CollectibleSortable`. Para eliminar essa redundância, essas classes podem ser declaradas como classes base virtuais quando são herdadas.