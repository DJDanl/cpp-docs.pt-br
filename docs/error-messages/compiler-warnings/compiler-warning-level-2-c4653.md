---
title: "Aviso do compilador (n&#237;vel 2) C4653 | Microsoft Docs"
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
  - "C4653"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4653"
ms.assetid: 90ec3317-3d39-4b4c-bcd1-97e7c799e1b6
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 2) C4653
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

opção “default” do compilador inconsistente com cabeçalho pré\-compilado; opção de linha de comando atual ignorada  
  
 Uma opção especificada com a opção pré\-compilada de cabeçalhos de uso \([\/Yu](../../build/reference/yu-use-precompiled-header-file.md)\) era inconsistente com as opções especificadas quando o cabeçalho pré\-compilado foi criado.  Essa compilação usou a opção especificada quando o cabeçalho pré\-compilado foi criado.  
  
 Esse aviso pode ocorrer quando um valor diferente para a opção das estruturas do bloco \([\/Zp](../Topic/-Zp%20\(Struct%20Member%20Alignment\).md)\) for especificado durante a compilação do cabeçalho pré\-compilado.