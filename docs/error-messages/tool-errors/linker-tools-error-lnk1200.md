---
title: Erro das Ferramentas de Vinculador LNK1200
ms.date: 11/04/2016
f1_keywords:
- LNK1200
helpviewer_keywords:
- LNK1200
ms.assetid: 55771145-915e-4006-ac6c-ac702041eb2f
ms.openlocfilehash: c99b25a83836f1ee0bc6ba622e42ea382c377172
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62213544"
---
# <a name="linker-tools-error-lnk1200"></a>Erro das Ferramentas de Vinculador LNK1200

Erro ao ler o banco de dados do programa 'filename'

Não foi possível ler o banco de dados do programa (PDB).

Esse erro pode ser causado por corrupção de arquivo.

Se `filename` é o PDB para um arquivo de objeto, recompile o arquivo de objeto usando [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md).

Se `filename` é o PDB para o arquivo de saída principal, e esse erro ocorreu durante uma vinculação incremental, exclua o PDB e vincular novamente.