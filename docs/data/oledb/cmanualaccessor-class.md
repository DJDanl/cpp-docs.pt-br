---
title: Classe CManualAccessor | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL::CManualAccessor
- ATL.CManualAccessor
- CManualAccessor
dev_langs: C++
helpviewer_keywords: CManualAccessor class
ms.assetid: a0088074-7135-465c-b228-69097a50b8cc
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: f32046f36aefa2c19c8c364f7598a06b71d71bd4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmanualaccessor-class"></a>Classe CManualAccessor
Representa um tipo de acessador projetado para uso avançado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
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