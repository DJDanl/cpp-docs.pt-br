---
title: "DEFINE_COMMAND_EX | Microsoft Docs"
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
  - "DEFINE_COMMAND_EX"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro DEFINE_COMMAND_EX"
ms.assetid: d3e2ef20-1455-46d2-8499-8ab84bbb90a4
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# DEFINE_COMMAND_EX
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica o comando que será usado para criar o conjunto de linhas ao usar a classe de [CCommand](../../data/oledb/ccommand-class.md) .  O oferece suporte ao Unicode e aplicativos ANSI.  
  
## Sintaxe  
  
```  
  
DEFINE_COMMAND_EX(  
x  
,   
wszCommand  
 )  
  
```  
  
#### Parâmetros  
 *x*  
 \[in\] o nome da classe do registro de usuário comando \(\).  
  
 `wszCommand`  
 \[in\] a cadeia de caracteres de comando que será usada para criar o conjunto de linhas ao usar [CCommand](../../data/oledb/ccommand-class.md).  
  
## Comentários  
 A cadeia de caracteres de comando que você especifica será usada como a opção se você não especificar o texto do comando no método de [CCommand::Open](../../data/oledb/ccommand-open.md) .  
  
 Esta macro aceita cadeias de caracteres Unicode, independentemente do tipo de aplicativo.  Esta macro é preferível [DEFINE\_COMMAND](../../data/oledb/define-command.md) porque oferece suporte ao Unicode bem como aplicativos ANSI.  
  
## Exemplo  
 Consulte [BOOKMARK\_ENTRY](../../data/oledb/bookmark-entry.md).  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Macros e funções globais para modelos de consumidor de banco de dados OLE](../Topic/Macros%20and%20Global%20Functions%20for%20OLE%20DB%20Consumer%20Templates.md)