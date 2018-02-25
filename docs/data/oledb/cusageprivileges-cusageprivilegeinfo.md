---
title: CUsagePrivileges, CUsagePrivilegeInfo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- m_szObjectCatalog
- CUsagePrivilegeInfo
- m_bIsGrantable
- OBJECT_NAME
- m_szPrivilegeType
- OBJECT_SCHEMA
- IS_GRANTABLE
- CUsagePrivileges
- m_szGrantor
- GRANTOR
- GRANTEE
- m_szObjectSchema
- OBJECT_CATALOG
- m_szObjectType
- m_szObjectName
- m_szGrantee
- OBJECT_TYPE
dev_langs:
- C++
helpviewer_keywords:
- OBJECT_NAME
- GRANTOR
- OBJECT_CATALOG
- CUsagePrivileges typedef class
- m_szPrivilegeType
- OBJECT_SCHEMA
- m_szObjectSchema
- m_szObjectType
- IS_GRANTABLE
- OBJECT_TYPE
- CUsagePrivilegeInfo parameter class
- m_szGrantee
- m_szObjectCatalog
- m_szGrantor
- GRANTEE
- m_bIsGrantable
- m_szObjectName
ms.assetid: 09460e7f-3947-4837-ad1e-407b94acedb8
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: b5db871447d6de6554d7f7e6a555c195edc97498
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="cusageprivileges-cusageprivilegeinfo"></a>CUsagePrivileges, CUsagePrivilegeInfo
Chamar a classe typedef **CUsagePrivileges** para implementar sua classe de parâmetro **CUsagePrivilegeInfo**.  
  
## <a name="remarks"></a>Comentários  
 Consulte [Classes de conjunto de linhas de esquema e Typedef](../../data/oledb/schema-rowset-classes-and-typedef-classes.md) para obter mais informações sobre como usar classes do typedef.  
  
 Essa classe identifica os privilégios de uso nos objetos definidos no catálogo que estão disponíveis para ou concedido por um determinado usuário.  
  
 A tabela a seguir lista os membros de dados de classe e o OLE DB colunas correspondentes. Consulte [USAGE_PRIVILEGES linhas](https://msdn.microsoft.com/en-us/library/ms722743.aspx) no *referência do programador de DB OLE* para obter mais informações sobre o esquema e as colunas.  
  
|Membros de dados|Colunas de banco de dados OLE|  
|------------------|--------------------|  
|m_szGrantor|GRANTOR|  
|m_szGrantee|GRANTEE|  
|m_szObjectCatalog|OBJECT_CATALOG|  
|m_szObjectSchema|OBJECT_SCHEMA|  
|m_szObjectName|OBJECT_NAME|  
|m_szObjectType|OBJECT_TYPE|  
|m_szPrivilegeType|PRIVILEGE_TYPE|  
|m_bIsGrantable|IS_GRANTABLE|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbsch.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CRestrictions](../../data/oledb/crestrictions-class.md)