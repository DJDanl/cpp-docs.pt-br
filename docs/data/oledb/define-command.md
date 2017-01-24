---
title: "DEFINE_COMMAND | Microsoft Docs"
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
  - "DEFINE_COMMAND"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro DEFINE_COMMAND"
ms.assetid: 9d724968-e242-413c-9a13-e7175fccf9b1
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# DEFINE_COMMAND
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica o comando que será usado para criar o conjunto de linhas ao usar a classe de [CCommand](../../data/oledb/ccommand-class.md) .  Aceita apenas os tipos de cadeia de caracteres que correspondem ao tipo de aplicativo especificado \(ANSI ou Unicode\).  
  
> [!NOTE]
>  É recomendável usar [DEFINE\_COMMAND\_EX](../../data/oledb/define-command-ex.md) em vez de `DEFINE_COMMAND`.  
  
## Sintaxe  
  
```  
  
DEFINE_COMMAND(  
x  
,   
szCommand  
 )  
  
```  
  
#### Parâmetros  
 *x*  
 \[in\] o nome da classe do registro de usuário comando \(\).  
  
 `szCommand`  
 \[in\] a cadeia de caracteres de comando que será usada para criar o conjunto de linhas ao usar [CCommand](../../data/oledb/ccommand-class.md).  
  
## Comentários  
 A cadeia de caracteres de comando que você especifica será usada como a opção se você não especificar o texto do comando no método de [CCommand::Open](../../data/oledb/ccommand-open.md) .  
  
 Esta macro aceita cadeias de caracteres ANSI se você criar seu aplicativo como ANSI, ou cadeias de caracteres Unicode se você criar seu aplicativo como Unicode.  É recomendável usar [DEFINE\_COMMAND\_EX](../../data/oledb/define-command-ex.md) em vez de `DEFINE_COMMAND`, porque o antigo aceita cadeias de caracteres Unicode, independentemente do tipo de aplicativo ANSI ou Unicode.  
  
## Exemplo  
 Consulte [BOOKMARK\_ENTRY](../../data/oledb/bookmark-entry.md).  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Macros e funções globais para modelos de consumidor de banco de dados OLE](../Topic/Macros%20and%20Global%20Functions%20for%20OLE%20DB%20Consumer%20Templates.md)