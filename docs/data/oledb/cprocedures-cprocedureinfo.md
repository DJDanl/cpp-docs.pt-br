---
title: CProcedures, CProcedureInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CProcedures
- m_szCatalog
- CProcedureInfo
- m_szSchema
- m_szDefinition
- m_szName
- m_nType
dev_langs:
- C++
helpviewer_keywords:
- DESCRIPTION class data member
- m_szSchema
- m_nType
- m_szCatalog
- CProcedureInfo parameter class
- m_szName
- m_szDescription
- m_szDefinition
- CProcedures typedef class
ms.assetid: d0c7375e-ee0c-441d-aae6-6108150860a0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 643904ac0a1887f2812ec19420180560dcd568b2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cprocedures-cprocedureinfo"></a>CProcedures, CProcedureInfo
Chamar a classe typedef **CProcedures** para implementar sua classe de parâmetro **CProcedureInfo**.  
  
## <a name="remarks"></a>Comentários  
 Consulte [Classes de conjunto de linhas de esquema e Typedef](../../data/oledb/schema-rowset-classes-and-typedef-classes.md) para obter mais informações sobre como usar classes do typedef.  
  
 Essa classe identifica os procedimentos definidos no catálogo, que são de propriedade de um determinado usuário.  
  
 A tabela a seguir lista os membros de dados de classe e o OLE DB colunas correspondentes. Consulte [procedimentos linhas](https://msdn.microsoft.com/en-us/library/ms724021.aspx) no *referência do programador de DB OLE* para obter mais informações sobre o esquema e as colunas.  
  
|Membros de dados|Colunas de banco de dados OLE|  
|------------------|--------------------|  
|m_szCatalog|PROCEDURE_CATALOG|  
|m_szSchema|PROCEDURE_SCHEMA|  
|m_szName|PROCEDURE_NAME|  
|m_nType|PROCEDURE_TYPE|  
|m_szDefinition|PROCEDURE_DEFINITION|  
|m_szDescription|DESCRIÇÃO|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbsch.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CRestrictions](../../data/oledb/crestrictions-class.md)