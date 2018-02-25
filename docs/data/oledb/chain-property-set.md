---
title: CHAIN_PROPERTY_SET | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CHAIN_PROPERTY_SET
dev_langs:
- C++
helpviewer_keywords:
- CHAIN_PROPERTY_SET macro
ms.assetid: 2bcf6d7d-f4e5-480d-9140-1e32a0994c94
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 634ab21ef9ffa18e5c18efa9078eb0606f9ff387
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="chainpropertyset"></a>CHAIN_PROPERTY_SET
Esta macro encadeia grupos de propriedade em conjunto.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
CHAIN_PROPERTY_SET(ChainClass)  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *ChainClass*  
 [in] O nome da classe para as propriedades de cadeia de. Esta é uma classe gerada pelo Assistente de projeto de ATL que já contém um mapa (como uma sessão, comando ou dados de origem classe de objeto).  
  
## <a name="remarks"></a>Comentários  
 Você pode encadear um conjunto de propriedades de outra classe para sua própria classe e acessar as propriedades diretamente de sua classe.  
  
> [!CAUTION]
>  Use esta macro com moderação. O uso inadequado pode causar um consumidor falha os testes de conformidade do OLE DB.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros para modelos de provedor do OLE DB](../../data/oledb/macros-for-ole-db-provider-templates.md)