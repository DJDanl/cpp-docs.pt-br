---
title: Erro das Ferramentas de Vinculador LNK1277
ms.date: 11/04/2016
f1_keywords:
- LNK1277
helpviewer_keywords:
- LNK1277
ms.assetid: afca3de0-50cc-4140-af7a-13493a170835
ms.openlocfilehash: 137aa15dd9dad4b08d52af55da60a9cdf8b58055
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50662066"
---
# <a name="linker-tools-error-lnk1277"></a>Erro das Ferramentas de Vinculador LNK1277

registro de objeto não encontrado no pgd (filename)

Ao usar [/LTCG:PGOPTIMZE](../../build/reference/ltcg-link-time-code-generation.md), o caminho de um dos arquivos de entrada. lib, def ou. obj era diferente do caminho no qual eles foram encontrados durante a /LTCG:PGINSTRUMENT. Isso pode ser explicado por uma alteração na variável de ambiente LIB após /LTCG:PGINSTRUMENT. O caminho completo para os arquivos de entrada é armazenado no arquivo. PGD.

/LTCG:PGOPTIMIZE requer que as entradas sejam idênticos à fase de /LTCG:PGINSTRUMENT.

Para resolver este aviso, siga um destes procedimentos:

- Executar /LTCG:PGINSTRUMENT, refazer todas as execuções de teste e execute /LTCG:PGOPTIMIZE.

- Altere a variável de ambiente LIB ao que era quando você executou /LTCG:PGINSTRUMENT.

Não é recomendável que você trabalhe em torno das LNK1277 usando /LTCG:PGUPDATE.