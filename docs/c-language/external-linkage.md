---
title: Ligação externa
ms.date: 11/04/2016
helpviewer_keywords:
- linkage [C++], external
- external linkage, about external linkage
- external linkage
ms.assetid: a6f8ea69-b405-4cdd-bf12-ad5462b73183
ms.openlocfilehash: 05fd4bd07aca995a938c7744dfd506d2a71b8774
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217084"
---
# <a name="external-linkage"></a>Ligação externa

Se a primeira declaração no nível de escopo de arquivo para um identificador não usar o **`static`** especificador de classe de armazenamento, o objeto terá vínculo externo.

Se a declaração de um identificador para uma função não tiver um *especificador de classe de armazenamento*, seu vínculo será determinado exatamente como se ele fosse declarado com o *especificador de classe de armazenamento* **`extern`** . Se a declaração de um identificador para um objeto tiver escopo de arquivo e nenhum *storage-class-specifier*, a ligação será externa.

O nome de um identificador de vinculação externa designa a mesma função ou o mesmo objeto de dados como qualquer outra declaração para o mesmo nome com vinculação externa. As duas declarações podem estar na mesma unidade de tradução ou em unidades de tradução diferentes. Se o objeto ou a função também tiverem tempo de vida global, o objeto ou a função são compartilhados em todo o programa.

## <a name="see-also"></a>Confira também

[Usando extern para especificar a ligação](../cpp/using-extern-to-specify-linkage.md)
