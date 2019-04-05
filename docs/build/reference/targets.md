---
title: Destinos
ms.date: 11/04/2016
helpviewer_keywords:
- targets, specifying in NMAKE
ms.assetid: 826ee849-4278-4c6e-97c3-79a2b5fe6463
ms.openlocfilehash: 52b2f3293b97955b605e2821102247f506c2950b
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59040842"
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