---
title: "Comandos em um makefile | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "comandos, makefiles"
ms.assetid: 8085517e-42f4-493b-b8f8-44311fc08c64
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Comandos em um makefile
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma regra do bloco ou de inferência de descrição especifica que um bloco de comandos executada se a dependência é esgotado.  NMAKE exibe cada comando antes de executá\-lo, a menos que **.SILENT**, \/S, **\!CMDSWITCHES**, ou @ é usado.  NMAKE procurará uma regra de inferência compatível se um bloco de descrição não é seguido por um bloco de comandos.  
  
 Um bloco de comandos contém um ou mais comandos, cada um em sua própria linha.  Nenhuma linha em branco pode aparecer entre a dependência ou ordenar e o bloco de comandos.  No entanto, uma linha que contém apenas espaços ou guias pode aparecer; essa linha é interpretada como um comando nulo, e não ocorre nenhum erro.  As linhas em branco são permitidas entre linhas de comando.  
  
 Uma linha de comando inicia com um ou mais espaços ou guias.  Uma barra invertida \(\\\) seguida por um caractere de nova linha é interpretada como um espaço no comando; use uma barra invertida no final de uma linha para retomar um comando na próxima linha.  NMAKE interpreta a barra invertida literalmente se qualquer outro caractere, incluindo um espaço ou uma guia, segue a barra invertida.  
  
 Um comando precedido por um ponto\-e\-vírgula \(;\) pode aparecer em uma regra de linha ou de inferência de dependências, mesmo se um bloco de comandos seguintes:  
  
```  
project.obj : project.c project.h ; cl /c project.c  
```  
  
## Que você deseja saber mais?  
 [Modificadores de comando](../Topic/Command%20Modifiers.md)  
  
 [Sintaxe de Nome de arquivo partes](../build/filename-parts-syntax.md)  
  
 [Arquivos embutidos em um makefile](../build/inline-files-in-a-makefile.md)  
  
## Consulte também  
 [Referência de NMAKE](../build/nmake-reference.md)