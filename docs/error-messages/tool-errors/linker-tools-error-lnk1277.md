---
title: "Erro das Ferramentas de Vinculador LNK1277 | Microsoft Docs"
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
  - "LNK1277"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK1277"
ms.assetid: afca3de0-50cc-4140-af7a-13493a170835
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK1277
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

registro de objeto não for localizado no pgd \(nome de arquivo\)  
  
 Ao usar [\/LTCG: PGOPTIMZE](../../build/reference/ltcg-link-time-code-generation.md), o caminho de uma de entrada .lib, abc def, ou os arquivos de .obj fossem diferentes do caminho no qual a foi localizada em: \/LTCGPGINSTRUMENT.  Isso pode ser explicado por uma alteração na variável de ambiente de LIB depois de \/LTCG:PGINSTRUMENT.  O caminho completo para os arquivos de entrada é armazenado no arquivo de .pgd.  
  
 \/LTCG:PGOPTIMIZE requer que as entradas sejam idênticas para o estágio de \/LTCG:PGINSTRUMENT .  
  
 Para resolver esse aviso, siga um destes procedimentos:  
  
-   Executar \/LTCG:PGINSTRUMENT, refazer todas as execuções de teste, e \/LTCG:PGOPTIMIZEexecutado.  
  
-   Alterar a variável de ambiente de LIB o que era quando você executar \/LTCG:PGINSTRUMENT.  
  
 Não é recomendável que você trabalha em torno de LNK1277 usando \/LTCG:PGUPDATE.