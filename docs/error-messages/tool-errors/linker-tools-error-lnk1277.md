---
title: Erro das LNK1277 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1277
dev_langs:
- C++
helpviewer_keywords:
- LNK1277
ms.assetid: afca3de0-50cc-4140-af7a-13493a170835
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 542c48bd23b3f84ab301404987c77d964f51823e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46082502"
---
# <a name="linker-tools-error-lnk1277"></a>Erro das Ferramentas de Vinculador LNK1277

registro de objeto não encontrado no pgd (filename)

Ao usar [/LTCG:PGOPTIMZE](../../build/reference/ltcg-link-time-code-generation.md), o caminho de um dos arquivos de entrada. lib, def ou. obj era diferente do caminho no qual eles foram encontrados durante a /LTCG:PGINSTRUMENT. Isso pode ser explicado por uma alteração na variável de ambiente LIB após /LTCG:PGINSTRUMENT. O caminho completo para os arquivos de entrada é armazenado no arquivo. PGD.

/LTCG:PGOPTIMIZE requer que as entradas sejam idênticos à fase de /LTCG:PGINSTRUMENT.

Para resolver este aviso, siga um destes procedimentos:

- Executar /LTCG:PGINSTRUMENT, refazer todas as execuções de teste e execute /LTCG:PGOPTIMIZE.

- Altere a variável de ambiente LIB ao que era quando você executou /LTCG:PGINSTRUMENT.

Não é recomendável que você trabalhe em torno das LNK1277 usando /LTCG:PGUPDATE.