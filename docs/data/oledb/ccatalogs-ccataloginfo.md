---
title: CCatalogs, CCatalogInfo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CCatalogs
- m_szName
- CCatalogInfo
dev_langs: C++
helpviewer_keywords:
- DESCRIPTION class data member
- CCatalogInfo parameter class
- CCatalogs typedef class
- m_szName
- m_szDescription
ms.assetid: 8362cbbd-2f00-4272-8518-fc235c4de193
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 30ab92811c214e71534831f40e0a2fb144ed9017
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ccatalogs-ccataloginfo"></a>CCatalogs, CCatalogInfo
Chamar a classe typedef **CCatalogs** para implementar sua classe de parâmetro **CCatalogInfo**.  
  
## <a name="remarks"></a>Comentários  
 Consulte [Classes de conjunto de linhas de esquema e Typedef](../../data/oledb/schema-rowset-classes-and-typedef-classes.md) para obter mais informações sobre como usar classes do typedef.  
  
 Essa classe identifica os atributos físicos associados a catálogos acessíveis a partir do DBMS.  
  
 A tabela a seguir lista os membros de dados de classe e o OLE DB colunas correspondentes. Consulte [CATÁLOGOS linhas](https://msdn.microsoft.com/en-us/library/ms721241.aspx) no *referência do programador de DB OLE* para obter mais informações sobre o esquema e as colunas.  
  
|Membros de dados|Colunas de banco de dados OLE|  
|------------------|--------------------|  
|m_szName|CATALOG_NAME|  
|m_szDescription|DESCRIÇÃO|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbsch.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CRestrictions](../../data/oledb/crestrictions-class.md)