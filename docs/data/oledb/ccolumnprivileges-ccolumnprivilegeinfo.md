---
title: CColumnPrivileges, CColumnPrivilegeInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- m_szTableSchema
- CColumnPrivileges
- m_bIsGrantable
- m_nColumnPropID
- m_szPrivilegeType
- COLUMN_GUID
- IS_GRANTABLE
- m_szColumnName
- m_szTableCatalog
- m_szGrantor
- GRANTOR
- GRANTEE
- COLUMN_PROPID
- m_guidColumn
- COLUMN_PRIVILEGES
- m_szTableName
- CColumnPrivilegeInfo
- m_szGrantee
dev_langs:
- C++
helpviewer_keywords:
- COLUMN_PROPID
- GRANTOR
- m_szPrivilegeType
- m_szTableSchema
- TABLE_CATALOG
- TABLE_NAME
- COLUMN_PRIVILEGES
- IS_GRANTABLE
- m_nColumnPropID
- TABLE_SCHEMA
- m_szColumnName
- COLUMN_NAME
- m_szTableCatalog
- m_szGrantee
- m_szGrantor
- m_szTableName
- CColumnPrivileges typedef class
- COLUMN_GUID
- GRANTEE
- m_guidColumn
- CColumnPrivilegeInfo parameter class
- m_bIsGrantable
ms.assetid: 245df365-421f-43c6-9fcd-fb2197c871c6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 57ccdea5fbafea147da6c866dc0cc67c2f30b0ac
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="ccolumnprivileges-ccolumnprivilegeinfo"></a>CColumnPrivileges, CColumnPrivilegeInfo
Chamar a classe typedef **CColumnPrivileges** para implementar sua classe de parâmetro **CColumnPrivilegeInfo**.  
  
## <a name="remarks"></a>Comentários  
 Consulte [Classes de conjunto de linhas de esquema e Typedef](../../data/oledb/schema-rowset-classes-and-typedef-classes.md) para obter mais informações sobre como usar classes do typedef.  
  
 Essa classe identifica os privilégios em colunas de tabelas, definidas no catálogo, que estão disponíveis para ou concedido por um determinado usuário.  
  
 A tabela a seguir lista os membros de dados de classe e o OLE DB colunas correspondentes. Consulte [COLUMN_PRIVILEGES linhas](https://msdn.microsoft.com/en-us/library/ms715800.aspx) no *referência do programador de DB OLE* para obter mais informações sobre o esquema e as colunas.  
  
|Membros de dados|Colunas de banco de dados OLE|  
|------------------|--------------------|  
|m_szGrantor|GRANTOR|  
|m_szGrantee|GRANTEE|  
|m_szTableCatalog|TABLE_CATALOG|  
|m_szTableSchema|TABLE_SCHEMA|  
|m_szTableName|TABLE_NAME|  
|m_szColumnName|COLUMN_NAME|  
|m_guidColumn|COLUMN_GUID|  
|m_nColumnPropID|COLUMN_PROPID|  
|m_szPrivilegeType|PRIVILEGE_TYPE|  
|m_bIsGrantable|IS_GRANTABLE|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbsch.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CRestrictions](../../data/oledb/crestrictions-class.md)