---
title: PROVIDER_COLUMN_ENTRY_TYPE_LENGTH | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: PROVIDER_COLUMN_ENTRY_TYPE_LENGTH
dev_langs: C++
helpviewer_keywords: PROVIDER_COLUMN_ENTRY_TYPE_LENGTH macro
ms.assetid: a60b1a8b-0903-4ff4-91ec-ed62126449fb
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 8b7f072c2a83bb476c4e088d36643e21bd075473
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="providercolumnentrytypelength"></a>PROVIDER_COLUMN_ENTRY_TYPE_LENGTH
Representa uma coluna específica suportada pelo provedor.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
PROVIDER_COLUMN_ENTRY_TYPE_LENGTH(  
name  
, ordinal, dbtype, size, member )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *name*  
  
 [in] O nome da coluna.  
  
 `ordinal`  
 [in] O número da coluna. A menos que a coluna é uma coluna de indicador, o número da coluna não deve ser 0.  
  
 `dbtype`  
 [in] O tipo de dados em [DBTYPE](https://msdn.microsoft.com/en-us/library/ms711251.aspx).  
  
 `size`  
 [in] O tamanho da coluna em bytes.  
  
 `member`  
 [in] A variável de membro na classe de dados que armazena os dados.  
  
## <a name="remarks"></a>Comentários  
 Semelhante ao [PROVIDER_COLUMN_ENTRY_LENGTH](../../data/oledb/provider-column-entry-length.md) , mas também permite que você especifique o tipo de dados da coluna, bem como o tamanho.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros para modelos de provedor do OLE DB](../../data/oledb/macros-for-ole-db-provider-templates.md)   
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura do modelo de provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)   
 [Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)