---
title: Erro das Ferramentas de Vinculador LNK1277
ms.date: 11/04/2016
f1_keywords:
- LNK1277
helpviewer_keywords:
- LNK1277
ms.assetid: afca3de0-50cc-4140-af7a-13493a170835
ms.openlocfilehash: 7c00fb32e4b36eff119195efbb34d536d80df6a9
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80183651"
---
# <a name="linker-tools-error-lnk1277"></a>Erro das Ferramentas de Vinculador LNK1277

registro de objeto não encontrado em PGD (filename)

Ao usar [/LTCG: PGOPTIMZE](../../build/reference/ltcg-link-time-code-generation.md), o caminho de um dos arquivos Input. lib, def ou. obj era diferente do caminho no qual eles foram encontrados durante/LTCG: PGINSTRUMENT. Isso pode ser explicado por uma alteração na variável de ambiente LIB após/LTCG: PGINSTRUMENT. O caminho completo para os arquivos de entrada é armazenado no arquivo. pgd.

/LTCG: PGOPTIMIZE requer que as entradas sejam idênticas à fase/LTCG: PGINSTRUMENT.

Para resolver esse aviso, siga um destes procedimentos:

- Execute/LTCG: PGINSTRUMENT, refaça todas as execuções de teste e Execute/LTCG: PGOPTIMIZE.

- Altere a variável de ambiente LIB para o que era quando você executou/LTCG: PGINSTRUMENT.

Não é recomendável que você contorne para contornar LNK1277 usando/LTCG: PGUPDATE.
