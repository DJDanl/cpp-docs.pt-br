---
title: Destinos
ms.date: 11/04/2016
helpviewer_keywords:
- targets, specifying in NMAKE
ms.assetid: 826ee849-4278-4c6e-97c3-79a2b5fe6463
ms.openlocfilehash: 4bb80b01993ee3f3715f551c73337cf24cd43f2c
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824265"
---
# <a name="targets"></a>Destinos

Em uma linha de dependência, especifique um ou mais destinos, usando qualquer nome de arquivo válido, o nome do diretório, ou [pseudotarget](pseudotargets.md). Separe vários destinos com um ou mais espaços ou tabulações. Destinos não diferenciam maiusculas de minúsculas. Caminhos são permitidos com nomes de arquivo. Um destino não pode exceder 256 caracteres. Se o destino anterior a ele é um único caractere, use um espaço de separação; Caso contrário, NMAKE interpreta a combinação de dois-pontos de letra como um especificador de unidade.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

[Pseudodestinos](pseudotargets.md)

[Vários destinos](multiple-targets.md)

[Dependências cumulativas](cumulative-dependencies.md)

[Destinos em vários blocos de descrição](targets-in-multiple-description-blocks.md)

[Efeitos colaterais da dependência](dependency-side-effects.md)

## <a name="see-also"></a>Consulte também

[Blocos de descrição](description-blocks.md)