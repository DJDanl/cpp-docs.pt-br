---
title: Aviso LNK4001 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4001
helpviewer_keywords:
- LNK4001
ms.assetid: 0a8b1c3a-64ce-4311-b7c0-065995059246
ms.openlocfilehash: 75ca9ec92bbba1c15efc11a731b3894ea03e33dd
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50651419"
---
# <a name="linker-tools-warning-lnk4001"></a>Aviso LNK4001 (Ferramentas de Vinculador)

Nenhum arquivo de objeto especificado; bibliotecas usadas

O vinculador foi passado um ou mais arquivos. lib, mas nenhum arquivo. obj.

Como o vinculador não é capaz de acessar informações em um arquivo. lib que ele é capaz de acessar em um arquivo. obj, este aviso indica que você terá que especificar explicitamente as outras opções de vinculador. Por exemplo, você talvez tenha que especificar o [/máquina](../../build/reference/machine-specify-target-platform.md), [/out](../../build/reference/out-output-file-name.md), ou [/ENTRY](../../build/reference/entry-entry-point-symbol.md) opções.