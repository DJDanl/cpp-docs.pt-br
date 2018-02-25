---
title: Classe CManualAccessor | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CManualAccessor
- ATL.CManualAccessor
- CManualAccessor
dev_langs:
- C++
helpviewer_keywords:
- CManualAccessor class
ms.assetid: a0088074-7135-465c-b228-69097a50b8cc
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: ecb9f31c862f62ddc2422f201aa824a959e961a0
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="cmanualaccessor-class"></a>Classe CManualAccessor
Representa um tipo de acessador projetado para uso avançado.  
  
## <a name="syntax"></a>Sintaxe

```cpp
class CManualAccessor : public CAccessorBase  
```  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[AddBindEntry](../../data/oledb/cmanualaccessor-addbindentry.md)|Adiciona uma entrada de associação às colunas de saída.|  
|[AddParameterEntry](../../data/oledb/cmanualaccessor-addparameterentry.md)|Adiciona uma entrada de parâmetro para o acessador de parâmetro.|  
|[CreateAccessor](../../data/oledb/cmanualaccessor-createaccessor.md)|Aloca memória para a coluna de estruturas de associação e inicializa os membros de dados de coluna.|  
|[CreateParameterAccessor](../../data/oledb/cmanualaccessor-createparameteraccessor.md)|Aloca memória para o parâmetro de estruturas de associação e inicializa os membros de dados do parâmetro.|  
  
## <a name="remarks"></a>Comentários  
 Usando `CManualAccessor`, você pode especificar o parâmetro e associação de coluna de saída por chamadas de função do tempo de execução.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [DBViewer](../../visual-cpp-samples.md)   
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)   
 [Classe CAccessor](../../data/oledb/caccessor-class.md)   
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)   
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)