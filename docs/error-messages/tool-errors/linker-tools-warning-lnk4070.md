---
title: Aviso LNK4070 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4070
dev_langs:
- C++
helpviewer_keywords:
- LNK4070
ms.assetid: f95f179a-fff9-427e-bd51-466b3934517f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9e4599e96552f1b98ef0b1af8d38995ebbe5a83e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="linker-tools-warning-lnk4070"></a>Aviso LNK4070 (Ferramentas de Vinculador)
/Out: nome_do_arquivo diretiva em. EXP difere do nome do arquivo de saída 'filename'; Ignorando diretiva  
  
 O `filename` especificado no [nome](../../build/reference/name-c-cpp.md) ou [biblioteca](../../build/reference/library.md) instrução quando foi criado o arquivo. EXP difere da saída `filename` que foi considerado por padrão ou especificado com o [/Out](../../build/reference/out-output-file-name.md) opção.  
  
 Você verá este aviso se você alterar o nome de um arquivo de saída no ambiente de desenvolvimento e onde o arquivo do projeto. def não foi atualizado. Atualize manualmente o arquivo. def para resolver este aviso.  
  
 Um programa cliente que usa a DLL resultante poderá ter problemas.