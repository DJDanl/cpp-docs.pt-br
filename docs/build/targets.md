---
title: Destinos
ms.date: 11/04/2016
helpviewer_keywords:
- targets, specifying in NMAKE
ms.assetid: 826ee849-4278-4c6e-97c3-79a2b5fe6463
ms.openlocfilehash: 9d9341178150e19aac51379c2b31ca4ca25bc7f8
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57415429"
---
# <a name="targets"></a>Destinos

Em uma linha de dependência, especifique um ou mais destinos, usando qualquer nome de arquivo válido, o nome do diretório, ou [pseudotarget](../build/pseudotargets.md). Separe vários destinos com um ou mais espaços ou tabulações. Destinos não diferenciam maiusculas de minúsculas. Caminhos são permitidos com nomes de arquivo. Um destino não pode exceder 256 caracteres. Se o destino anterior a ele é um único caractere, use um espaço de separação; Caso contrário, NMAKE interpreta a combinação de dois-pontos de letra como um especificador de unidade.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

[Pseudodestinos](../build/pseudotargets.md)

[Vários destinos](../build/multiple-targets.md)

[Dependências cumulativas](../build/cumulative-dependencies.md)

[Destinos em vários blocos de descrição](../build/targets-in-multiple-description-blocks.md)

[Efeitos colaterais da dependência](../build/dependency-side-effects.md)

## <a name="see-also"></a>Consulte também

[Blocos de descrição](../build/description-blocks.md)
