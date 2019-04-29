---
title: Aviso LNK4022 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4022
helpviewer_keywords:
- LNK4022
ms.assetid: 890f487e-db98-45dd-a226-c7ccead82b1e
ms.openlocfilehash: 1c9ccfe6ca201ae4deed69c7d01429c67cce4bda
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62298458"
---
# <a name="linker-tools-warning-lnk4022"></a>Aviso LNK4022 (Ferramentas de Vinculador)

não é possível localizar uma correspondência exclusiva para o símbolo 'symbol'

Corresponde a LIB encontradas várias ou LINK para o símbolo não decorado fornecido e ele não foi possível resolver a ambiguidade. Nenhum arquivo de saída (.exe,. dll,. EXP ou. lib) é produzido. Esse aviso é seguido por um aviso [LNK4002](../../error-messages/tool-errors/linker-tools-warning-lnk4002.md) para cada duplicar o símbolo e, finalmente, é seguido por um erro fatal [das LNK1152](../../error-messages/tool-errors/linker-tools-error-lnk1152.md).

Para evitar esse aviso, especifique o símbolo em sua forma decorada. Execute [DUMPBIN](../../build/reference/dumpbin-options.md) no objeto para ver os nomes decorados.