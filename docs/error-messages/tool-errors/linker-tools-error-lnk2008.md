---
title: Erro das Ferramentas de Vinculador LNK2008
ms.date: 11/04/2016
f1_keywords:
- LNK2008
helpviewer_keywords:
- LNK2008
ms.assetid: bbcd83c5-c8ae-439e-a033-63643a5bb373
ms.openlocfilehash: 97bb2be18da5d166d1d5fba42e4ec8ce1f0439fe
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50544216"
---
# <a name="linker-tools-error-lnk2008"></a>Erro das Ferramentas de Vinculador LNK2008

O alvo da correção não está alinhado 'symbol_name'

LINK encontrado um alvo da correção em seu arquivo de objeto não foi devidamente alinhado.

Esse erro pode ser causado pelo alinhamento secton personalizado (#pragma, por exemplo, [pack](../../preprocessor/pack.md)), [alinhar](../../cpp/align-cpp.md) modificador, ou usando o código de linguagem assembly que modifica secton alinhamento.

Se seu código não usa nenhuma das opções acima, isso pode ser causado pelo compilador.