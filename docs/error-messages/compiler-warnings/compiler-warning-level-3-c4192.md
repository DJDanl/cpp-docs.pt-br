---
title: "Aviso do compilador (n&#237;vel 3) C4192 | Microsoft Docs"
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
  - "C4192"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4192"
ms.assetid: ea5f91fa-8c96-4f3f-ac42-0c8a86d4e5df
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 3) C4192
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

excluindo automaticamente “name” ao importar a biblioteca “biblioteca” do tipo  
  
 Uma biblioteca de `#import` contém um item, *o nome*, que também é definido em cabeçalhos de sistema do Win32.  Devido às limitações de bibliotecas de tipo, os nomes como **IUnknown** ou o GUID são frequentemente definidas em uma biblioteca de tipos, duplicando a definição dos cabeçalhos do sistema.  `#import` detectará esses itens e recusá\-los\-á incorporar\-los nos arquivos de cabeçalho de .tlh e de .tli.  
  
 Para substituir esse comportamento, use [no\_auto\_exclude](../../preprocessor/no-auto-exclude.md) atributos e [include\(\)](../../preprocessor/include-parens.md)de `#import` .