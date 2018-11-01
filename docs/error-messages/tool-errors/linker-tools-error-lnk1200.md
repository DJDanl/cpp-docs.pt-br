---
title: Erro das Ferramentas de Vinculador LNK1200
ms.date: 11/04/2016
f1_keywords:
- LNK1200
helpviewer_keywords:
- LNK1200
ms.assetid: 55771145-915e-4006-ac6c-ac702041eb2f
ms.openlocfilehash: c99b25a83836f1ee0bc6ba622e42ea382c377172
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50466827"
---
# <a name="linker-tools-error-lnk1200"></a>Erro das Ferramentas de Vinculador LNK1200

Erro ao ler o banco de dados do programa 'filename'

Não foi possível ler o banco de dados do programa (PDB).

Esse erro pode ser causado por corrupção de arquivo.

Se `filename` é o PDB para um arquivo de objeto, recompile o arquivo de objeto usando [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md).

Se `filename` é o PDB para o arquivo de saída principal, e esse erro ocorreu durante uma vinculação incremental, exclua o PDB e vincular novamente.