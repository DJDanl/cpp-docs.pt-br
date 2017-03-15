---
title: "CProviderTypes, CProviderInfo | Microsoft Docs"
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
  - "m_bIsLong"
  - "m_szLocalTypeName"
  - "m_guidType"
  - "m_bCaseSensitive"
  - "m_szVersion"
  - "m_szCreateParams"
  - "IS_NULLABLE"
  - "m_bAutoUniqueValue"
  - "LITERAL_SUFFIX"
  - "COLUMN_SIZE"
  - "CProviderTypes"
  - "LOCAL_TYPE_NAME"
  - "MINIMUM_SCALE"
  - "m_nMinScale"
  - "m_nColumnSize"
  - "m_szLiteralSuffix"
  - "m_bFixedPrecScale"
  - "m_szLiteralPrefix"
  - "m_nMaxScale"
  - "m_szTypeLib"
  - "m_nDataType"
  - "m_bUnsignedAttribute"
  - "m_nSearchable"
  - "m_bBestMatch"
  - "m_szTypeName"
  - "DATA_TYPE"
  - "MAXIMUM_SCALE"
  - "CProviderInfo"
  - "FIXED_PREC_SCALE"
  - "m_bIsNullable"
  - "IS_LONG"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "COLUMN_SIZE"
  - "Classe de parâmetro CProviderInfo"
  - "Classe CProviderTypes (typedef)"
  - "DATA_TYPE"
  - "FIXED_PREC_SCALE"
  - "IS_LONG"
  - "IS_NULLABLE"
  - "LITERAL_SUFFIX"
  - "LOCAL_TYPE_NAME"
  - "m_bAutoUniqueValue"
  - "m_bBestMatch"
  - "m_bCaseSensitive"
  - "m_bFixedPrecScale"
  - "m_bIsLong"
  - "m_bIsNullable"
  - "m_bUnsignedAttribute"
  - "m_guidType"
  - "m_nColumnSize"
  - "m_nDataType"
  - "m_nMaxScale"
  - "m_nMinScale"
  - "m_nSearchable"
  - "m_szCreateParams"
  - "m_szLiteralPrefix"
  - "m_szLiteralSuffix"
  - "m_szLocalTypeName"
  - "m_szTypeLib"
  - "m_szTypeName"
  - "m_szVersion"
  - "MAXIMUM_SCALE"
  - "MINIMUM_SCALE"
ms.assetid: 6f1620ff-c2f0-4f5b-931c-27b0cd2a580d
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CProviderTypes, CProviderInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Chame a classe **CProviderTypes** do typedef para implementar a sua classe **CProviderInfo**do parâmetro.  
  
## Comentários  
 Consulte [Classes do conjunto de linhas de esquema e classes de Typedef](../Topic/Schema%20Rowset%20Classes%20and%20Typedef%20Classes.md) para obter mais informações sobre como usar classes do typedef.  
  
 Essa classe identifica os tipos de dados \(base\) suportados pelo provedor de dados.  
  
 A tabela a seguir lista os membros de dados da classe e suas colunas correspondentes OLE DB.  Consulte [Conjunto de linhas de PROVIDER\_TYPES](https://msdn.microsoft.com/en-us/library/ms709785.aspx)*na referência do programador de OLE DB* para obter mais informações sobre o esquema e de colunas.  
  
|Membros de dados|Colunas de OLE DB|  
|----------------------|-----------------------|  
|m\_szTypeName|TYPE\_NAME|  
|m\_nDataType|DATA\_TYPE|  
|m\_nColumnSize|COLUMN\_SIZE|  
|m\_szLiteralPrefix|LITERAL\_PREFIX|  
|m\_szLiteralSuffix|LITERAL\_SUFFIX|  
|m\_szCreateParams|CREATE\_PARAMS|  
|m\_bIsNullable|IS\_NULLABLE|  
|m\_bCaseSensitive|CASE\_SENSITIVE|  
|m\_nSearchable|SEARCHABLE|  
|m\_bUnsignedAttribute|UNSIGNED\_ATTRIBUTE|  
|m\_bFixedPrecScale|FIXED\_PREC\_SCALE|  
|m\_bAutoUniqueValue|AUTO\_UNIQUE\_VALUE|  
|m\_szLocalTypeName|LOCAL\_TYPE\_NAME|  
|m\_nMinScale|MINIMUM\_SCALE|  
|m\_nMaxScale|MAXIMUM\_SCALE|  
|m\_guidType|GUID|  
|m\_szTypeLib|TYPELIB|  
|m\_szVersion|VERSION|  
|m\_bIsLong|IS\_LONG|  
|m\_bBestMatch|BEST\_MATCH|  
  
## Requisitos  
 **Header:** atldbsch.h  
  
## Consulte também  
 [Classe CRestrictions](../Topic/CRestrictions%20Class.md)