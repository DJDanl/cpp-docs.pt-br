---
title: Ferramentas de vinculador LNK2011 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK2011
dev_langs: C++
helpviewer_keywords: LNK2011
ms.assetid: 04991ef5-49d5-46c7-8eee-a9d1d3fc541e
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9811bdb905df61bb77ea4af6bc4ced7c4ba42106
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk2011"></a>Erro das Ferramentas de Vinculador LNK2011
objeto precompilado não vinculado; imagem não pode ser executada  
  
 Se você usar cabeçalhos pré-compilados, LINK requer que todos os arquivos de objeto criados com cabeçalhos pré-compilados devem ser vinculados no. Se você tiver um arquivo de origem que você usa para gerar um cabeçalho pré-compilado para uso com outros arquivos de origem, você deve incluir o arquivo de objeto criado juntamente com o cabeçalho pré-compilado.  
  
 Por exemplo, se você compilar um arquivo chamado STUB.cpp para criar um cabeçalho pré-compilado para uso com outros arquivos de origem, você deve vincular com STUB.obj ou você receberá esse erro. Nas seguintes linhas de comando, linha é usada para criar um cabeçalho pré-compilado, COMMON.pch, que é usado com PROG1.cpp e PROG2.cpp nas linhas dois e três. O arquivo STUB.cpp contém apenas `#include` linhas (o mesmo `#include` linhas como PROG1.cpp e PROG2.cpp) e é usado somente para gerar cabeçalhos pré-compilados. Na última linha, STUB.obj deve ser vinculadas para evitar LNK2011.  
  
```  
cl /c /Yccommon.h stub.cpp  
cl /c /Yucommon.h prog1.cpp  
cl /c /Yucommon.h prog2.cpp  
link /out:prog.exe stub.obj prog1.obj prog2.obj  
```