---
title: Erro das LNK1200 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1200
dev_langs:
- C++
helpviewer_keywords:
- LNK1200
ms.assetid: 55771145-915e-4006-ac6c-ac702041eb2f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 03ecd51142bf30230b6b177a36e007345e93bf2c
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46059310"
---
# <a name="linker-tools-error-lnk1200"></a>Erro das Ferramentas de Vinculador LNK1200

Erro ao ler o banco de dados do programa 'filename'

Não foi possível ler o banco de dados do programa (PDB).

Esse erro pode ser causado por corrupção de arquivo.

Se `filename` é o PDB para um arquivo de objeto, recompile o arquivo de objeto usando [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md).

Se `filename` é o PDB para o arquivo de saída principal, e esse erro ocorreu durante uma vinculação incremental, exclua o PDB e vincular novamente.