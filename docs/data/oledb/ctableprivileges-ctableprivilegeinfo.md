---
title: CTablePrivileges, CTablePrivilegeInfo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- m_szCatalog
- m_bIsGrantable
- IS_GRANTABLE
- m_szType
- m_szSchema
- m_szGrantor
- GRANTOR
- GRANTEE
- CTablePrivileges
- CTablePrivilegeInfo
- m_szName
- m_szGrantee
dev_langs:
- C++
helpviewer_keywords:
- GRANTOR
- CTablePrivilegeInfo parameter class
- m_szSchema
- TABLE_CATALOG
- m_szType
- m_szCatalog
- TABLE_NAME
- IS_GRANTABLE
- TABLE_SCHEMA
- m_szName
- m_szGrantee
- CTablePrivileges typedef class
- m_szGrantor
- GRANTEE
- m_bIsGrantable
ms.assetid: ffcd6f73-022e-452a-8342-f2b9362d256b
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 89ff02138ae85bebbc9b6f7a1a32ef449c8ad0a8
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="ctableprivileges-ctableprivilegeinfo"></a>CTablePrivileges, CTablePrivilegeInfo
Chamar a classe typedef **CTablePrivileges** para implementar sua classe de parâmetro **CTablePrivilegeInfo**.  
  
## <a name="remarks"></a>Comentários  
 Consulte [Classes de conjunto de linhas de esquema e Typedef](../../data/oledb/schema-rowset-classes-and-typedef-classes.md) para obter mais informações sobre como usar classes do typedef.  
  
 Essa classe identifica as tabelas definidas no catálogo que são acessíveis para um determinado usuário.  
  
 A tabela a seguir lista os membros de dados de classe e o OLE DB colunas correspondentes. Consulte [TABLE_PRIVILEGES linhas](https://msdn.microsoft.com/en-us/library/ms725428.aspx) no *referência do programador de DB OLE* para obter mais informações sobre o esquema e as colunas.  
  
|Membros de dados|Colunas de banco de dados OLE|  
|------------------|--------------------|  
|m_szGrantor|GRANTOR|  
|m_szGrantee|GRANTEE|  
|m_szCatalog|TABLE_CATALOG|  
|m_szSchema|TABLE_SCHEMA|  
|m_szName|TABLE_NAME|  
|m_szType|PRIVILEGE_TYPE|  
|m_bIsGrantable|IS_GRANTABLE|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbsch.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CRestrictions](../../data/oledb/crestrictions-class.md)