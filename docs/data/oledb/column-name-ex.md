---
title: "COLUMN_NAME_EX | Microsoft Docs"
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
  - "COLUMN_NAME_EX"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro COLUMN_NAME_EX"
ms.assetid: 4f916a85-f6ae-464a-9cbe-0a56dbb274a6
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# COLUMN_NAME_EX
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas.  Semelhante a, exceto que a [COLUMN\_NAME](../Topic/COLUMN_NAME.md)esta macro também usa o tipo de dados, tamanho, precisão, escala, comprimento da coluna, e o status da coluna.  
  
## Sintaxe  
  
```  
  
COLUMN_NAME_EX(  
pszName  
,   
wType  
,   
nLength  
,   
nPrecision  
,   
nScale  
,   
data  
,   
length  
,   
status )  
```  
  
#### Parâmetros  
 `pszName`  
 \[in\] ponteiro da o nome da coluna.  O nome deve ser uma cadeia de caracteres Unicode.  Isso pode ser feito colocando um “L” em frente do nome, por exemplo: `L"MyColumn"`.  
  
 `wType`  
 \[in\] o tipo de dados.  
  
 `nLength`  
 \[in\] o tamanho dos dados em bytes.  
  
 `nPrecision`  
 \[in\] a precisão máxima para uso quando obtendo dados e `wType` é `DBTYPE_NUMERIC`.  Caso contrário, esse parâmetro será ignorado.  
  
 `nScale`  
 \[in\] a escala a ser usado quando obtendo dados e `wType` é `DBTYPE_NUMERIC` ou **DBTYPE\_DECIMAL**.  
  
 `data`  
 \[in\] o membro de dados correspondente no registro do usuário.  
  
 *length*  
 \[in\] a variável a ser associado ao comprimento da coluna.  
  
 *status*  
 \[in\] a variável a ser associado ao status da coluna.  
  
## Comentários  
 Consulte [COLUMN\_NAME](../Topic/COLUMN_NAME.md) para obter informações sobre onde as macros de **COLUMN\_NAME\_\*** são usados.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Macros e funções globais para modelos de consumidor de banco de dados OLE](../Topic/Macros%20and%20Global%20Functions%20for%20OLE%20DB%20Consumer%20Templates.md)   
 [BEGIN\_ACCESSOR](../../data/oledb/begin-accessor.md)   
 [BEGIN\_ACCESSOR\_MAP](../../data/oledb/begin-accessor-map.md)   
 [BEGIN\_COLUMN\_MAP](../Topic/BEGIN_COLUMN_MAP.md)   
 [COLUMN\_NAME](../Topic/COLUMN_NAME.md)   
 [COLUMN\_NAME\_LENGTH](../Topic/COLUMN_NAME_LENGTH.md)   
 [COLUMN\_NAME\_LENGTH\_STATUS](../Topic/COLUMN_NAME_LENGTH_STATUS.md)   
 [COLUMN\_NAME\_STATUS](../../data/oledb/column-name-status.md)   
 [COLUMN\_NAME\_PS](../../data/oledb/column-name-ps.md)   
 [COLUMN\_NAME\_PS\_LENGTH](../Topic/COLUMN_NAME_PS_LENGTH.md)   
 [COLUMN\_NAME\_PS\_STATUS](../../data/oledb/column-name-ps-status.md)   
 [COLUMN\_NAME\_PS\_LENGTH\_STATUS](../../data/oledb/column-name-ps-length-status.md)   
 [COLUMN\_NAME\_TYPE](../../data/oledb/column-name-type.md)   
 [COLUMN\_NAME\_TYPE\_PS](../../data/oledb/column-name-type-ps.md)   
 [COLUMN\_NAME\_TYPE\_SIZE](../../data/oledb/column-name-type-size.md)   
 [COLUMN\_NAME\_TYPE\_STATUS](../Topic/COLUMN_NAME_TYPE_STATUS.md)