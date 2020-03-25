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
ms.openlocfilehash: 50bddef3ea1ee1462d8cf115c0980270c8deab25
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80181467"
---
# <a name="base-classes"></a>Classes base

O processo de herança cria uma nova classe derivada que é composta dos membros da classe base (ou das classes base), mais os novos membros adicionados pela classe derivada. Em uma herança múltipla, é possível construir um gráfico de herança em que a mesma classe base faz parte de mais de uma das classes derivadas. A figura a seguir mostra um gráfico desse tipo.

![Várias instâncias de uma classe base](../cpp/media/vc38xn1.gif "Várias instâncias de uma classe base") <br/>
Várias instâncias de uma única classe base

Na figura, são mostradas representações pictóricas dos componentes de `CollectibleString` e `CollectibleSortable`. No entanto, a classe base, `Collectible`, está em `CollectibleSortableString` pelo caminho de `CollectibleString` e pelo caminho de `CollectibleSortable`. Para eliminar essa redundância, essas classes podem ser declaradas como classes base virtuais quando são herdadas.
