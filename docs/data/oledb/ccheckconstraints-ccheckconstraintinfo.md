---
title: CCheckConstraints, CCheckConstraintInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CCheckConstraintInfo
- CHECK_CONSTRAINTS
- m_szCatalog
- CCheckConstraints
- CONSTRAINT_NAME
- m_szSchema
- CHECK_CLAUSE
- m_szCheckClause
- m_szName
- CONSTRAINT_CATALOG
- CONSTRAINT_SCHEMA
dev_langs:
- C++
helpviewer_keywords:
- DESCRIPTION class data member
- m_szSchema
- CONSTRAINT_CATALOG
- m_szCatalog
- CONSTRAINT_NAME
- CONSTRAINT_SCHEMA
- CCheckConstraints typedef class
- CHECK_CLAUSE
- m_szName
- m_szDescription
- CCheckConstraintInfo parameter class
- m_szCheckClause
- CHECK_CONSTRAINTS
ms.assetid: e53e79a5-01e5-42b7-aa8c-164aec94b011
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: a2f167212458266b44f93315cd3185010461c78d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33093864"
---
# <a name="ccheckconstraints-ccheckconstraintinfo"></a>CCheckConstraints, CCheckConstraintInfo
Chamar a classe typedef **CCheckConstraints** para implementar sua classe de parâmetro **CCheckConstraintInfo**.  
  
## <a name="remarks"></a>Comentários  
 Consulte [Classes de conjunto de linhas de esquema e Typedef](../../data/oledb/schema-rowset-classes-and-typedef-classes.md) para obter mais informações sobre como usar classes do typedef.  
  
 Essa classe identifica as restrições de verificação, definidas no catálogo, que são de propriedade de um determinado usuário. Uma restrição check Especifica os valores de dados ou formatos são aceitáveis em uma ou mais colunas em uma tabela.  
  
 A tabela a seguir lista os membros de dados de classe e o OLE DB colunas correspondentes. Consulte [CHECK_CONSTRAINTS linhas](https://msdn.microsoft.com/en-us/library/ms712845.aspx) no *referência do programador de DB OLE* para obter mais informações sobre o esquema e as colunas.  
  
|Membros de dados|Colunas de banco de dados OLE|  
|------------------|--------------------|  
|m_szCatalog|CONSTRAINT_CATALOG|  
|m_szSchema|CONSTRAINT_SCHEMA|  
|m_szName|CONSTRAINT_NAME|  
|m_szCheckClause|CHECK_CLAUSE|  
|m_szDescription|DESCRIÇÃO|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbsch.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CRestrictions](../../data/oledb/crestrictions-class.md)