---
title: Destinos
ms.date: 11/04/2016
helpviewer_keywords:
- targets, specifying in NMAKE
ms.assetid: 826ee849-4278-4c6e-97c3-79a2b5fe6463
ms.openlocfilehash: f2163b6fdbd03c5cc1f5af307b5646f31d8a0c34
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50664211"
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