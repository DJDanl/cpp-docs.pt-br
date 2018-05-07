---
title: CCharacterSets, CCharacterSetInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- m_szCollateName
- m_szCatalog
- DEFAULT_COLLATE_NAME
- m_szCollateSchema
- FORM_OF_USE
- DEFAULT_COLLATE_SCHEMA
- m_szCollateCatalog
- CCharacterSets
- CHARACTER_SET_NAME
- DEFAULT_COLLATE_CATALOG
- CHARACTER_SET_SCHEMA
- m_szFormOfUse
- NUMBER_OF_CHARACTERS
- m_szSchema
- CHARACTER_SET_CATALOG
- CCharacterSetInfo
- m_nNumCharacters
- m_szName
dev_langs:
- C++
helpviewer_keywords:
- DEFAULT_COLLATE_SCHEMA
- m_nNumCharacters
- m_szSchema
- NUMBER_OF_CHARACTERS
- m_szCollateCatalog
- CCharacterSetInfo parameter class
- m_szCatalog
- CCharacterSets typedef class
- m_szCollateName
- m_szName
- m_szCollateSchema
- FORM_OF_USE OLE DB column
- CHARACTER_SET_NAME
- DEFAULT_COLLATE_CATALOG
- DEFAULT_COLLATE_NAME
- m_szFormOfUse
- CHARACTER_SET_SCHEMA
- CHARACTER_SET_CATALOG
ms.assetid: 029d068c-8bb2-4fc0-8709-78ce7f74446e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: e46c61df81a9a527fa637c96c37324319bbe5cf5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="ccharactersets-ccharactersetinfo"></a>CCharacterSets, CCharacterSetInfo
Chamar a classe typedef **CCharacterSets** para implementar sua classe de parâmetro **CCharacterSetInfo**.  
  
## <a name="remarks"></a>Comentários  
 Consulte [Classes de conjunto de linhas de esquema e Typedef](../../data/oledb/schema-rowset-classes-and-typedef-classes.md) para obter mais informações sobre como usar classes do typedef.  
  
 Essa classe identifica os conjuntos de caracteres definidos no catálogo e acessíveis para um determinado usuário.  
  
 A tabela a seguir lista os membros de dados de classe e o OLE DB colunas correspondentes. Consulte [CHARACTER_SETS linhas](https://msdn.microsoft.com/en-us/library/ms722638.aspx) no *referência do programador de DB OLE* para obter mais informações sobre o esquema e as colunas.  
  
|Membros de dados|Colunas de banco de dados OLE|  
|------------------|--------------------|  
|m_szCatalog|CHARACTER_SET_CATALOG|  
|m_szSchema|CHARACTER_SET_SCHEMA|  
|m_szName|CHARACTER_SET_NAME|  
|m_szFormOfUse|FORM_OF_USE|  
|m_nNumCharacters|NUMBER_OF_CHARACTERS|  
|m_szCollateCatalog|DEFAULT_COLLATE_CATALOG|  
|m_szCollateSchema|DEFAULT_COLLATE_SCHEMA|  
|m_szCollateName|DEFAULT_COLLATE_NAME|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbsch.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CRestrictions](../../data/oledb/crestrictions-class.md)