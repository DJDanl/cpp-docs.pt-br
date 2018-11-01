---
title: Erro das Ferramentas de Vinculador LNK1158
ms.date: 11/04/2016
f1_keywords:
- LNK1158
helpviewer_keywords:
- LNK1158
ms.assetid: 45febf16-d9e1-42db-af91-532e2717fd6a
ms.openlocfilehash: f2e3e1d9948960beed631861c5981f2d09daf632
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50455933"
---
# <a name="linker-tools-error-lnk1158"></a>Erro das Ferramentas de Vinculador LNK1158

não é possível executar 'filename'

O determinado arquivo executável chamado pelo [LINK](../../build/reference/linker-command-line-syntax.md) está fora do diretório que contém o LINK nem em um diretório especificado na variável de ambiente PATH.

Por exemplo, você receberá esse erro se você tentar usar o parâmetro PGOPTIMIZE para o [/LTCG](../../build/reference/ltcg-link-time-code-generation.md) opção de vinculador em um computador com um sistema operacional de 32 bits.