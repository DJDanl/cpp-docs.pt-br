---
title: Ferramentas de vinculador LNK4022 aviso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4022
dev_langs:
- C++
helpviewer_keywords:
- LNK4022
ms.assetid: 890f487e-db98-45dd-a226-c7ccead82b1e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 644e7a9ba26dab15e2bfa2a269f62c04f0510180
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46040993"
---
# <a name="linker-tools-warning-lnk4022"></a>Aviso LNK4022 (Ferramentas de Vinculador)

não é possível localizar uma correspondência exclusiva para o símbolo 'symbol'

Corresponde a LIB encontradas várias ou LINK para o símbolo não decorado fornecido e ele não foi possível resolver a ambiguidade. Nenhum arquivo de saída (.exe,. dll,. EXP ou. lib) é produzido. Esse aviso é seguido por um aviso [LNK4002](../../error-messages/tool-errors/linker-tools-warning-lnk4002.md) para cada duplicar o símbolo e, finalmente, é seguido por um erro fatal [das LNK1152](../../error-messages/tool-errors/linker-tools-error-lnk1152.md).

Para evitar esse aviso, especifique o símbolo em sua forma decorada. Execute [DUMPBIN](../../build/reference/dumpbin-options.md) no objeto para ver os nomes decorados.