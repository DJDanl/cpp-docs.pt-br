---
title: CPrimaryKeys, CPrimaryKeyInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- m_nOrdinal
- m_szTableSchema
- m_nColumnPropID
- CPrimaryKeys
- COLUMN_GUID
- CPrimaryKeyInfo
- m_szColumnName
- m_szTableCatalog
- COLUMN_PROPID
- m_guidColumn
- ORDINAL
- m_szTableName
dev_langs:
- C++
helpviewer_keywords:
- COLUMN_PROPID
- m_szTableSchema
- TABLE_CATALOG
- ORDINAL data member
- CPrimaryKeys typedef class
- TABLE_NAME
- m_nColumnPropID
- TABLE_SCHEMA
- m_szColumnName
- COLUMN_NAME
- m_szTableCatalog
- m_szTableName
- m_nOrdinal
- CPrimaryKeyInfo parameter class
- COLUMN_GUID
- m_guidColumn
ms.assetid: c27b97a4-a156-4f66-89e3-95f85d7d6281
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: f10596e66bdca8bef639f680ae838ce9016ad60d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cprimarykeys-cprimarykeyinfo"></a>CPrimaryKeys, CPrimaryKeyInfo
Chamar a classe typedef **CPrimaryKeys** para implementar sua classe de parâmetro **CPrimaryKeyInfo**.  
  
## <a name="remarks"></a>Comentários  
 Consulte [Classes de conjunto de linhas de esquema e Typedef](../../data/oledb/schema-rowset-classes-and-typedef-classes.md) para obter mais informações sobre como usar classes do typedef.  
  
 Essa classe identifica as colunas de chave primária definidas no catálogo por um determinado usuário.  
  
 A tabela a seguir lista os membros de dados de classe e o OLE DB colunas correspondentes. Consulte [linhas PRIMARY_KEYS](https://msdn.microsoft.com/en-us/library/ms714362.aspx) no *referência do programador de DB OLE* para obter mais informações sobre o esquema e as colunas.  
  
|Membros de dados|Colunas de banco de dados OLE|  
|------------------|--------------------|  
|m_szTableCatalog|TABLE_CATALOG|  
|m_szTableSchema|TABLE_SCHEMA|  
|m_szTableName|TABLE_NAME|  
|m_szColumnName|COLUMN_NAME|  
|m_guidColumn|COLUMN_GUID|  
|m_nColumnPropID|COLUMN_PROPID|  
|m_nOrdinal|ORDINAL|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbsch.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CRestrictions](../../data/oledb/crestrictions-class.md)