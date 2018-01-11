---
title: Classe CAccessorBase | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: CAccessorBase
dev_langs: C++
helpviewer_keywords: CAccessorBase class
ms.assetid: 389b65be-11ca-4ae0-9290-60c621c4982b
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 9b7c12430c4e7a6872afd46e72e93a29a3189333
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="caccessorbase-class"></a>Classe CAccessorBase
Todos os acessadores nos modelos OLE DB derivam dessa classe. `CAccessorBase`permite que um conjunto de linhas gerenciar vários acessadores. Ele também fornece uma associação de parâmetros e colunas de saída.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
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