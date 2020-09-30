---
title: Ligação externa
ms.date: 11/04/2016
helpviewer_keywords:
- linkage [C++], external
- external linkage, about external linkage
- external linkage
ms.assetid: a6f8ea69-b405-4cdd-bf12-ad5462b73183
ms.openlocfilehash: d8a7655b7504aa8458bda8db24ff3f919b5b09c1
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91509913"
---
# <a name="external-linkage"></a>Ligação externa

Se a primeira declaração no nível de escopo de arquivo para um identificador não usar o **`static`** especificador de classe de armazenamento, o objeto terá vínculo externo.

Se a declaração de um identificador para uma função não tiver um *especificador de classe de armazenamento*, seu vínculo será determinado exatamente como se ele fosse declarado com o *especificador de classe de armazenamento* **`extern`** . Se a declaração de um identificador para um objeto tiver escopo de arquivo e nenhum *storage-class-specifier*, a ligação será externa.

O nome de um identificador de vinculação externa designa a mesma função ou o mesmo objeto de dados como qualquer outra declaração para o mesmo nome com vinculação externa. As duas declarações podem estar na mesma unidade de tradução ou em unidades de tradução diferentes. Se o objeto ou a função também tiverem tempo de vida global, o objeto ou a função são compartilhados em todo o programa.

## <a name="see-also"></a>Consulte também

[Usando extern para especificar a ligação](../cpp/extern-cpp.md)
