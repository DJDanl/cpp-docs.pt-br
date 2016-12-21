---
title: "Erro do Compilador C3173 | Microsoft Docs"
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
  - "C3173"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3173"
ms.assetid: edf79e10-e8cf-4f76-8d33-ab9d05e974e9
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3173
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

incompatibilidade de versão na mesclagem de idl  
  
 Esse erro ocorre quando um arquivo de objeto contém o idl inserido que esteve gerado com uma versão anterior do compilador.  O compilador codifica um número de versão para garantir que o mesmo compilador usado para gerar conteúdo de idl que é inserido nos arquivos de .obj também é o mesmo compilador usado para mesclar o idl inserido.  
  
 Atualizar sua instalação do Visual C\+\+ de modo que todas as ferramentas seja da versão lançada pela última vez.