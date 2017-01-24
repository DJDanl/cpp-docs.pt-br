---
title: "Erro das Ferramentas de Vinculador LNK1200 | Microsoft Docs"
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
  - "LNK1200"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK1200"
ms.assetid: 55771145-915e-4006-ac6c-ac702041eb2f
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK1200
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

base de dados “nome de arquivo” do programa de leitura de erro  
  
 O base de dados \(PDB\) do programa não foi possível ler.  
  
 Esse erro pode ser causado por danos no arquivo.  
  
 Se `filename` é o PDB para um arquivo de objeto, recompile o arquivo do objeto usando [\/Zi](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md).  
  
 Se `filename` é o PDB para o arquivo de saída principal, e esse erro ocorrido durante um link incremental, exclua o PDB e relink.