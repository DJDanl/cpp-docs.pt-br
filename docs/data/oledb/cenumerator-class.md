---
title: Classe CEnumerator | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: CEnumerator
dev_langs: C++
helpviewer_keywords: CEnumerator class
ms.assetid: 25805f1b-26e3-402f-af83-1b5fe5ddebf7
caps.latest.revision: "14"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: a64ac02e7b16bfab70966ffaf2a1897ae955f8c7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cenumerator-class"></a>Classe CEnumerator
Usa um objeto de enumerador de OLE DB, que expõe o [ISourcesRowset da](https://msdn.microsoft.com/en-us/library/ms715969.aspx) interface para retornar um conjunto de linhas que descreve todas as fontes de dados e enumeradores.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CEnumerator :   
   public CAccessorRowset< CAccessor <CEnumeratorAccessor >>  
```  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[Find](../../data/oledb/cenumerator-find.md)|Pesquisas por meio de provedores disponíveis (fontes de dados) procurando um com o nome especificado.|  
|[GetMoniker](../../data/oledb/cenumerator-getmoniker.md)|Recupera o `IMoniker` interface para o registro atual.|  
|[Abrir](../../data/oledb/cenumerator-open.md)|Abre o enumerador.|  
  
## <a name="remarks"></a>Comentários  
 Você pode recuperar o **ISourcesRowset da** dados indiretamente a partir dessa classe.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:**atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [DBViewer](../../visual-cpp-samples.md)   
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)