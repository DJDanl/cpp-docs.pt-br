---
title: BEGIN_ACCESSOR | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: BEGIN_ACCESSOR
dev_langs: C++
helpviewer_keywords:
- BEGIN_ACCESSOR macro, syntax
- BEGIN_ACCESSOR macro
ms.assetid: 59d0ff3e-7cfd-4ce8-9a1c-d664c0892a52
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: f9461c508fe13a2930a39a2632d5a5a80f01c385
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="beginaccessor"></a>BEGIN_ACCESSOR
Marca o início de uma entrada de acessador.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
BEGIN_ACCESSOR(  
num  
,   
bAuto  
 )  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *num*  
 [in] O número de deslocamento de zero para o acessador neste mapa de acessador.  
  
 *Houver*  
 [in] Especifica se esse acessador é um acessador de automático ou um acessador manual. Se **true**, o acessador é automática; se **false**, o acessador é manual. Um acessador automática significa que dados são buscados para você em operações de movimentação.  
  
## <a name="remarks"></a>Comentários  
 No caso de vários acessadores em um conjunto de linhas, você precisa especificar `BEGIN_ACCESSOR_MAP` e usar o `BEGIN_ACCESSOR` macro cada acessador individuais. O `BEGIN_ACCESSOR` macro é concluída com o `END_ACCESSOR` macro. O `BEGIN_ACCESSOR_MAP` macro é concluída com o `END_ACCESSOR_MAP` macro.  
  
## <a name="example"></a>Exemplo  
 Consulte [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros e funções globais para modelos de consumidor OLE DB](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md)   
 [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md)   
 [END_ACCESSOR](../../data/oledb/end-accessor.md)   
 [END_ACCESSOR_MAP](../../data/oledb/end-accessor-map.md)