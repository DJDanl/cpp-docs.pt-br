---
title: Erro das Ferramentas de Vinculador LNK1200
ms.date: 11/04/2016
f1_keywords:
- LNK1200
helpviewer_keywords:
- LNK1200
ms.assetid: 55771145-915e-4006-ac6c-ac702041eb2f
ms.openlocfilehash: 9dcc37bd74a25e29726529346b1578bb8b18ac3e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80195130"
---
# <a name="linker-tools-error-lnk1200"></a>Erro das Ferramentas de Vinculador LNK1200

erro ao ler o banco de dados do programa ' FileName '

Não foi possível ler o banco de dados do programa (PDB).

Esse erro pode ser causado por corrupção de arquivo.

Se `filename` for o PDB de um arquivo de objeto, recompile o arquivo de objeto usando [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md).

Se `filename` for o PDB do arquivo de saída principal e esse erro ocorreu durante um link incremental, exclua o PDB e Revincule.
