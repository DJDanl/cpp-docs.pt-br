---
title: Ferramentas de vinculador LNK1241 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1241
dev_langs:
- C++
helpviewer_keywords:
- LNK1241
ms.assetid: 7b8b52eb-0231-4521-b52a-2bce8d3e8956
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: bb256607f6babbba90fbd17ae89bfbdfcfb48138
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk1241"></a>Erro das Ferramentas de Vinculador LNK1241
arquivo de recurso 'arquivo de recurso' já especificado  
  
 Esse erro é gerado se você executar **cvtres** manualmente a partir da linha de comando e se você passar o obj resultante de arquivo para o vinculador além para outros arquivos. res.  
  
 Para especificar vários arquivos. res, passá-los todos para o vinculador como arquivos. res, não de dentro. obj arquivos criados por **cvtres**.