---
title: Ferramentas de vinculador LNK1158 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1158
dev_langs:
- C++
helpviewer_keywords:
- LNK1158
ms.assetid: 45febf16-d9e1-42db-af91-532e2717fd6a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 71cee2a31d1a7b05104031fbf41e8e3addb82d7d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="linker-tools-error-lnk1158"></a>Erro das Ferramentas de Vinculador LNK1158
não é possível executar 'filename'  
  
 O arquivo executável fornecido chamado pelo [LINK](../../build/reference/linker-command-line-syntax.md) está fora do diretório que contém o LINK nem em um diretório especificado na variável de ambiente PATH.  
  
 Por exemplo, você receberá esse erro se você tentar usar o parâmetro PGOPTIMIZE para o [/LTCG](../../build/reference/ltcg-link-time-code-generation.md) opção de vinculador em um computador com um sistema operacional de 32 bits.