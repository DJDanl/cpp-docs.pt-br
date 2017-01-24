---
title: "/LINENUMBERS | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/linenumbers"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção /LINENUMBERS (dumpbin)"
  - "números de linha"
  - "opção dumpbin LINENUMBERS"
  - "opção dumpbin -LINENUMBERS"
ms.assetid: 1681d582-2c2f-484e-9920-109959549055
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /LINENUMBERS
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/LINENUMBERS  
```  
  
## Comentários  
 Esta opção exibe números de linha de COFF.  Números de linha existe em um arquivo de objeto se foi criada com base de dados do programa \(\/Zi\), o C7 correspondente \(\/Z7\), ou a linha apenas números \(\/Zd\).  Um arquivo executável ou uma DLL contêm números de linha de COFF se estiver vinculada com gerenciar informações de depuração \(\/DEBUG\).  
  
 Somente a opção de DUMPBIN de [\/HEADERS](../../build/reference/headers.md) está disponível para uso em arquivos gerados com a opção do compilador de [\/GL](../../build/reference/gl-whole-program-optimization.md) .  
  
## Consulte também  
 [Opções de DUMPBIN](../../build/reference/dumpbin-options.md)