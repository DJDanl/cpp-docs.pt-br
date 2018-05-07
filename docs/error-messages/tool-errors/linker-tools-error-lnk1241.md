---
title: Ferramentas de vinculador LNK1241 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1241
dev_langs:
- C++
helpviewer_keywords:
- LNK1241
ms.assetid: 7b8b52eb-0231-4521-b52a-2bce8d3e8956
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b02b1d9d06706c70478d958dd3c2af8dbc9c2c03
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="linker-tools-error-lnk1241"></a>Erro das Ferramentas de Vinculador LNK1241
arquivo de recurso 'arquivo de recurso' já especificado  
  
 Esse erro é gerado se você executar **cvtres** manualmente a partir da linha de comando e se você passar o obj resultante de arquivo para o vinculador além para outros arquivos. res.  
  
 Para especificar vários arquivos. res, passá-los todos para o vinculador como arquivos. res, não de dentro. obj arquivos criados por **cvtres**.