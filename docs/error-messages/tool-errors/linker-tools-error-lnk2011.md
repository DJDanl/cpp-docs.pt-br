---
title: "Erro das Ferramentas de Vinculador LNK2011 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "LNK2011"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK2011"
ms.assetid: 04991ef5-49d5-46c7-8eee-a9d1d3fc541e
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK2011
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

objeto pré\-compilado não vinculado em; a imagem não pode executar  
  
 Se você usar cabeçalhos pré\-compilados, o LINK requer que todos os arquivos de objeto criado com cabeçalhos pré\-compilados devem ser vinculados em.  Se você tiver um arquivo de origem que você usa para gerar um cabeçalho pré\-compilado para uso com outros arquivos de origem, você agora deve incluir o arquivo de objeto criado com o cabeçalho pré\-compilado.  
  
 Por exemplo, se você criar um arquivo chamado STUB.cpp para criar um cabeçalho pré\-compilado para uso com outros arquivos de origem, você deverá vincular a STUB.obj ou você obterá o erro.  Nas seguintes linhas de comando, a uma linha é usada para criar um cabeçalho COMMON.pch, pré\-compilado, que é usado com PROG1.cpp e PROG2.cpp em dois e três linhas.  O arquivo STUB.cpp contém somente as linhas de `#include` \(mesmo `#include` alinha como em PROG1.cpp e em PROG2.cpp\) e é usado para gerar somente cabeçalhos pré\-compilados.  Na última linha, STUB.obj deve ser vinculado no para evitar LNK2011.  
  
```  
cl /c /Yccommon.h stub.cpp  
cl /c /Yucommon.h prog1.cpp  
cl /c /Yucommon.h prog2.cpp  
link /out:prog.exe stub.obj prog1.obj prog2.obj  
```