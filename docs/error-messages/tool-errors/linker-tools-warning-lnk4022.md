---
title: Aviso LNK4022 das ferramentas de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK4022
dev_langs: C++
helpviewer_keywords: LNK4022
ms.assetid: 890f487e-db98-45dd-a226-c7ccead82b1e
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9e35974a72de349f94f2189f676b6dc955c48fab
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-warning-lnk4022"></a>Aviso LNK4022 (Ferramentas de Vinculador)
não é possível localizar uma correspondência exclusiva para o símbolo 'symbol'  
  
 LINK ou LIB encontrados vários corresponde para o símbolo não decorado determinado e ele não foi possível resolver a ambiguidade. Nenhum arquivo de saída (.exe,. dll,. EXP ou. lib) é produzido. Esse aviso é seguido por um aviso [LNK4002](../../error-messages/tool-errors/linker-tools-warning-lnk4002.md) para cada duplicar o símbolo e é seguido por último erro fatal [LNK1152](../../error-messages/tool-errors/linker-tools-error-lnk1152.md).  
  
 Para evitar este aviso, especifique o símbolo em sua forma realçada. Executar [DUMPBIN](../../build/reference/dumpbin-options.md) no objeto para ver os nomes decorados.