---
title: Aviso LNK4022 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4022
helpviewer_keywords:
- LNK4022
ms.assetid: 890f487e-db98-45dd-a226-c7ccead82b1e
ms.openlocfilehash: 9b9ce09a7133c0bdc18957f6ade213583e9540eb
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80194181"
---
# <a name="linker-tools-warning-lnk4022"></a>Aviso LNK4022 (Ferramentas de Vinculador)

Não é possível localizar uma correspondência exclusiva para o símbolo ' Symbol '

LINK ou LIB encontrou várias correspondências para o símbolo não decorado fornecido e não pôde resolver a ambiguidade. Nenhum arquivo de saída (. exe,. dll,. exp ou. lib) é produzido. Esse aviso é seguido por um aviso [LNK4002](../../error-messages/tool-errors/linker-tools-warning-lnk4002.md) para cada símbolo duplicado e é finalmente seguido pelo erro fatal [LNK1152](../../error-messages/tool-errors/linker-tools-error-lnk1152.md).

Para evitar esse aviso, especifique o símbolo em seu formulário decorado. Execute [DUMPBIN](../../build/reference/dumpbin-options.md) no objeto para ver nomes decorados.
