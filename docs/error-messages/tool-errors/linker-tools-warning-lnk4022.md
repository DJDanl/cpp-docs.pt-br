---
title: Aviso LNK4022 das ferramentas de vinculador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4022
dev_langs:
- C++
helpviewer_keywords:
- LNK4022
ms.assetid: 890f487e-db98-45dd-a226-c7ccead82b1e
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 25def05a4336ebe6f97caa05ce743a9a183a6e84
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4022"></a>Aviso LNK4022 (Ferramentas de Vinculador)
não é possível localizar uma correspondência exclusiva para o símbolo 'symbol'  
  
 LINK ou LIB encontradas várias correspondências para o determinado símbolo não decorado e ele não foi possível resolver a ambiguidade. Nenhum arquivo de saída (.exe,. dll,. EXP ou. lib) é produzido. Esse aviso é seguido por um aviso [LNK4002](../../error-messages/tool-errors/linker-tools-warning-lnk4002.md) para cada duplicar o símbolo e finalmente é seguido por um erro fatal [LNK1152](../../error-messages/tool-errors/linker-tools-error-lnk1152.md).  
  
 Para evitar esse aviso, especifique o símbolo em sua forma decorada. Executar [DUMPBIN](../../build/reference/dumpbin-options.md) no objeto para ver os nomes decorados.
