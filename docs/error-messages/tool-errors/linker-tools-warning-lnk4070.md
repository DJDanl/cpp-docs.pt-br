---
title: "Aviso LNK4070 (Ferramentas de Vinculador) | Microsoft Docs"
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
  - "LNK4070"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK4070"
ms.assetid: f95f179a-fff9-427e-bd51-466b3934517f
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso LNK4070 (Ferramentas de Vinculador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

a política de\/OUT:filename em .EXP difere do nome de arquivo “nome do arquivo de saída;” ignorando a política  
  
 `filename` especificado na instrução de [NAME](../Topic/NAME%20\(C-C++\).md) ou de [BIBLIOTECA](../../build/reference/library.md) quando o arquivo de .exp foi criado difere de saída `filename` que foram assumidas por padrão ou especificado com a opção de [\/OUT](../../build/reference/out-output-file-name.md) .  
  
 Você verá esse aviso se você alterar o nome de um arquivo de saída no ambiente de desenvolvimento e onde o arquivo .def do projeto não esteve atualizado.  Atualizar manualmente o arquivo .def para resolver esse aviso.  
  
 Um programa cliente que usa a DLL resultante poderá encontrar problemas.