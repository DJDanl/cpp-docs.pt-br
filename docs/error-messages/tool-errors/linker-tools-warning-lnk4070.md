---
title: Aviso LNK4070 das ferramentas de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK4070
dev_langs: C++
helpviewer_keywords: LNK4070
ms.assetid: f95f179a-fff9-427e-bd51-466b3934517f
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1c3c683593b9019851b1a330a613adcf7a18c4a1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-warning-lnk4070"></a>Aviso LNK4070 (Ferramentas de Vinculador)
/Out: nome_do_arquivo diretiva em. EXP difere do nome do arquivo de saída 'filename'; Ignorando diretiva  
  
 O `filename` especificado no [nome](../../build/reference/name-c-cpp.md) ou [biblioteca](../../build/reference/library.md) instrução quando foi criado o arquivo. EXP difere da saída `filename` que foi considerado por padrão ou especificado com o [/Out](../../build/reference/out-output-file-name.md) opção.  
  
 Você verá este aviso se você alterar o nome de um arquivo de saída no ambiente de desenvolvimento e onde o arquivo do projeto. def não foi atualizado. Atualize manualmente o arquivo. def para resolver este aviso.  
  
 Um programa cliente que usa a DLL resultante poderá ter problemas.