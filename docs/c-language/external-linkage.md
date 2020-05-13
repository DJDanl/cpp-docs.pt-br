---
title: Ligação externa
ms.date: 11/04/2016
helpviewer_keywords:
- linkage [C++], external
- external linkage, about external linkage
- external linkage
ms.assetid: a6f8ea69-b405-4cdd-bf12-ad5462b73183
ms.openlocfilehash: 35b0fda1f501755640123f5181454a5c36b7e986
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62233729"
---
# <a name="external-linkage"></a>Ligação externa

Se a primeira instrução no nível do escopo de arquivo em um identificador não usar o especificador de classe de armazenamento **static**, o objeto tem vínculos externos.

Se a declaração de um identificador para uma função não tiver um *storage-class-specifier*, a ligação será determinada exatamente como se tivesse sido declarada com o *storage-class-specifier* `extern`. Se a declaração de um identificador para um objeto tiver escopo de arquivo e nenhum *storage-class-specifier*, a ligação será externa.

O nome de um identificador de vinculação externa designa a mesma função ou o mesmo objeto de dados como qualquer outra declaração para o mesmo nome com vinculação externa. As duas declarações podem estar na mesma unidade de tradução ou em unidades de tradução diferentes. Se o objeto ou a função também tiverem tempo de vida global, o objeto ou a função são compartilhados em todo o programa.

## <a name="see-also"></a>Confira também

[Usando extern para especificar a ligação](../cpp/using-extern-to-specify-linkage.md)
