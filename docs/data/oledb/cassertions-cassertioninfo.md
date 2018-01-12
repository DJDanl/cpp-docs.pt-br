---
title: CAssertions, CAssertionInfo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CAssertions
- m_szCatalog
- m_bInitiallyDeferred
- CONSTRAINT_NAME
- m_szSchema
- INITIALLY_DEFERRED
- m_bIsDeferrable
- m_szName
- CAssertionInfo
- CONSTRAINT_CATALOG
- CONSTRAINT_SCHEMA
- IS_DEFERRABLE
dev_langs: C++
helpviewer_keywords:
- CAssertionInfo parameter class
- DESCRIPTION class data member
- CAssertions typedef class
- IS_DEFERRABLE
- m_szSchema
- m_bInitiallyDeferred
- CONSTRAINT_CATALOG
- m_szCatalog
- CONSTRAINT_NAME
- CONSTRAINT_SCHEMA
- m_szName
- m_szDescription
- INITIALLY_DEFERRED
- m_bIsDeferrable
ms.assetid: 2a79c2da-5c9b-4fa6-98e8-90b7f5d6f021
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 10738f2236e5ecc4f04edfe21a25d6d5da80a841
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cassertions-cassertioninfo"></a>CAssertions, CAssertionInfo
Chamar a classe typedef **CAssertions** para implementar sua classe de parâmetro **CAssertionInfo**.  
  
## <a name="remarks"></a>Comentários  
 Consulte [Classes de conjunto de linhas de esquema e Typedef](../../data/oledb/schema-rowset-classes-and-typedef-classes.md) para obter mais informações sobre como usar classes do typedef.  
  
 Essa classe identifica as asserções definidas no catálogo que são de propriedade de um determinado usuário.  
  
 A tabela a seguir lista os membros de dados de classe para **CAssertionInfo** e o OLE DB colunas correspondentes. Consulte [ASSERÇÕES linhas](https://msdn.microsoft.com/en-us/library/ms719776.aspx) no *referência do programador de DB OLE* para obter mais informações sobre o esquema e as colunas.  
  
|Membros de dados|Colunas de banco de dados OLE|  
|------------------|--------------------|  
|m_szCatalog|CONSTRAINT_CATALOG|  
|m_szSchema|CONSTRAINT_SCHEMA|  
|m_szName|CONSTRAINT_NAME|  
|m_bIsDeferrable|IS_DEFERRABLE|  
|m_bInitiallyDeferred|INITIALLY_DEFERRED|  
|m_szDescription|DESCRIÇÃO|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbsch.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CRestrictions](../../data/oledb/crestrictions-class.md)