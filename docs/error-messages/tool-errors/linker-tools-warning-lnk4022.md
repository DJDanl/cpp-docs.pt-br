---
title: Aviso LNK4022 das ferramentas de vinculador | Microsoft Docs
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
ms.openlocfilehash: cffb9c4c67bc3003b8dcdda0ad3a2e8d55abe932
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="linker-tools-warning-lnk4022"></a>Aviso LNK4022 (Ferramentas de Vinculador)
não é possível localizar uma correspondência exclusiva para o símbolo 'symbol'  
  
 LINK ou LIB encontrados vários corresponde para o símbolo não decorado determinado e ele não foi possível resolver a ambiguidade. Nenhum arquivo de saída (.exe,. dll,. EXP ou. lib) é produzido. Esse aviso é seguido por um aviso [LNK4002](../../error-messages/tool-errors/linker-tools-warning-lnk4002.md) para cada duplicar o símbolo e é seguido por último erro fatal [LNK1152](../../error-messages/tool-errors/linker-tools-error-lnk1152.md).  
  
 Para evitar este aviso, especifique o símbolo em sua forma realçada. Executar [DUMPBIN](../../build/reference/dumpbin-options.md) no objeto para ver os nomes decorados.