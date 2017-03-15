---
title: "CProcedureParameters CProcedureParamInfo | Microsoft Docs"
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
  - "m_szDefault"
  - "CProcedureParameters"
  - "m_bHasDefault"
  - "CProcedureParamInfo"
  - "IS_NULLABLE"
  - "m_szCatalog"
  - "ORDINAL_POSITION"
  - "m_nOrdinalPosition"
  - "NUMERIC_PRECISION"
  - "m_nDataType"
  - "m_szSchema"
  - "CHARACTER_OCTET_LENGTH"
  - "NUMERIC_SCALE"
  - "m_szParameterName"
  - "m_nMaxLength"
  - "CHARACTER_MAXIMUM_LENGTH"
  - "m_nPrecision"
  - "m_szName"
  - "DATA_TYPE"
  - "m_nOctetLength"
  - "m_nType"
  - "m_bIsNullable"
  - "m_nScale"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "CHARACTER_MAXIMUM_LENGTH"
  - "CHARACTER_OCTET_LENGTH"
  - "Classe CProcedureParameters (typedef)"
  - "Classe de parâmetro CProcedureParamInfo"
  - "DATA_TYPE"
  - "Membro de dados de classe DESCRIPTION"
  - "IS_NULLABLE"
  - "m_bHasDefault"
  - "m_bIsNullable"
  - "m_nDataType"
  - "m_nMaxLength"
  - "m_nOctetLength"
  - "m_nOrdinalPosition"
  - "m_nPrecision"
  - "m_nScale"
  - "m_nType"
  - "m_szCatalog"
  - "m_szDefault"
  - "m_szDescription"
  - "m_szName"
  - "m_szParameterName"
  - "m_szSchema"
  - "NUMERIC_PRECISION"
  - "NUMERIC_SCALE"
  - "ORDINAL_POSITION"
ms.assetid: 61f8d55a-684a-47a3-b102-068cc3f52d84
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CProcedureParameters CProcedureParamInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Chame a classe **CProcedureParameters** do typedef para implementar a sua classe **CProcedureParamInfo**do parâmetro.  
  
## Comentários  
 Consulte [Classes do conjunto de linhas de esquema e classes de Typedef](../Topic/Schema%20Rowset%20Classes%20and%20Typedef%20Classes.md) para obter mais informações sobre como usar classes do typedef.  
  
 Esta classe retorna informações sobre os parâmetros e códigos de retorno de procedimentos.  
  
 A tabela a seguir lista os membros de dados da classe e suas colunas correspondentes OLE DB.  Consulte [Conjunto de linhas de PROCEDURE\_PARAMETERS](https://msdn.microsoft.com/en-us/library/ms713623.aspx)*na referência do programador de OLE DB* para obter mais informações sobre o esquema e de colunas.  
  
|Membros de dados|Colunas de OLE DB|  
|----------------------|-----------------------|  
|m\_szCatalog|PROCEDURE\_CATALOG|  
|m\_szSchema|PROCEDURE\_SCHEMA|  
|m\_szName|PROCEDURE\_NAME|  
|m\_szParameterName|PARAMETER\_NAME|  
|m\_nOrdinalPosition|ORDINAL\_POSITION|  
|m\_nType|PARAMETER\_TYPE|  
|m\_bHasDefault|PARAMETER\_HASDEFAULT|  
|m\_szDefault|PARAMETER\_DEFAULT|  
|m\_bIsNullable|IS\_NULLABLE|  
|m\_nDataType|DATA\_TYPE|  
|m\_nMaxLength|CHARACTER\_MAXIMUM\_LENGTH|  
|m\_nOctetLength|CHARACTER\_OCTET\_LENGTH|  
|m\_nPrecision|NUMERIC\_PRECISION|  
|m\_nScale|NUMERIC\_SCALE|  
|m\_szDescription|DESCRIÇÃO|  
  
## Requisitos  
 **Header:** atldbsch.h  
  
## Consulte também  
 [Classe CRestrictions](../Topic/CRestrictions%20Class.md)