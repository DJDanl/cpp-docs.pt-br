---
title: Classe CAccessorBase | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CAccessorBase
dev_langs:
- C++
helpviewer_keywords:
- CAccessorBase class
ms.assetid: 389b65be-11ca-4ae0-9290-60c621c4982b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: f598f49d279085b23e0bd3b94c48620363b5a816
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33090790"
---
# <a name="caccessorbase-class"></a>Classe CAccessorBase
Todos os acessadores nos modelos OLE DB derivam dessa classe. `CAccessorBase` permite que um conjunto de linhas gerenciar vários acessadores. Ele também fornece uma associação de parâmetros e colunas de saída.  
  
## <a name="syntax"></a>Sintaxe

```cpp
// Replace with syntax  
```  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[Fechar](../../data/oledb/caccessorbase-close.md)|Fecha os acessadores.|  
|[GetHAccessor](../../data/oledb/caccessorbase-gethaccessor.md)|Recupera o identificador do acessador.|  
|[GetNumAccessors](../../data/oledb/caccessorbase-getnumaccessors.md)|Recupera o número de acessadores criado pela classe.|  
|[IsAutoAccessor](../../data/oledb/caccessorbase-isautoaccessor.md)|Testa se o acessador especificado é um autoaccessor.|  
|[ReleaseAccessors](../../data/oledb/caccessorbase-releaseaccessors.md)|Libera os acessadores.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)