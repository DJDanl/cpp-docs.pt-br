---
title: Classe CEnumerator | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CEnumerator
dev_langs:
- C++
helpviewer_keywords:
- CEnumerator class
ms.assetid: 25805f1b-26e3-402f-af83-1b5fe5ddebf7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 2b7e390212da53f85cb50dd5bb151ea6740784b0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33096100"
---
# <a name="cenumerator-class"></a>Classe CEnumerator
Usa um objeto de enumerador de OLE DB, que expõe o [ISourcesRowset da](https://msdn.microsoft.com/en-us/library/ms715969.aspx) interface para retornar um conjunto de linhas que descreve todas as fontes de dados e enumeradores.  
  
## <a name="syntax"></a>Sintaxe

```cpp
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
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [DBViewer](../../visual-cpp-samples.md)   
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)