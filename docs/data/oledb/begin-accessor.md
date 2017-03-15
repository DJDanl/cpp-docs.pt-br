---
title: "BEGIN_ACCESSOR | Microsoft Docs"
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
  - "BEGIN_ACCESSOR"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro BEGIN_ACCESSOR"
  - "Macro BEGIN_ACCESSOR, sintaxe"
ms.assetid: 59d0ff3e-7cfd-4ce8-9a1c-d664c0892a52
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# BEGIN_ACCESSOR
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Marca o início de uma entrada do acessador.  
  
## Sintaxe  
  
```  
  
BEGIN_ACCESSOR(  
num  
,   
bAuto  
 )  
  
```  
  
#### Parâmetros  
 *numérico*  
 \[in\] o número de zero deslocamento do acessador neste mapa do acessador.  
  
 *bAuto*  
 \[in\] especifica se esse acessador é um acessador automático ou um acessador manual.  Se **true**, o acessador é automático; se **false**, o acessador é manual.  Um dados automática do acessador são buscados para você em operações de movimentação.  
  
## Comentários  
 No caso de vários acessadores em um conjunto de linhas, você precisa especificar `BEGIN_ACCESSOR_MAP` e usar a macro de `BEGIN_ACCESSOR` para cada acessador individual.  A macro de `BEGIN_ACCESSOR` é concluído com a macro de `END_ACCESSOR` .  A macro de `BEGIN_ACCESSOR_MAP` é concluído com a macro de `END_ACCESSOR_MAP` .  
  
## Exemplo  
 Consulte [BEGIN\_ACCESSOR\_MAP](../../data/oledb/begin-accessor-map.md).  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Macros e funções globais para modelos de consumidor de banco de dados OLE](../Topic/Macros%20and%20Global%20Functions%20for%20OLE%20DB%20Consumer%20Templates.md)   
 [BEGIN\_ACCESSOR\_MAP](../../data/oledb/begin-accessor-map.md)   
 [END\_ACCESSOR](../Topic/END_ACCESSOR.md)   
 [END\_ACCESSOR\_MAP](../../data/oledb/end-accessor-map.md)