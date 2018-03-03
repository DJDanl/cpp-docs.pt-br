---
title: 'Construtor eventtargetarray:: Eventtargetarray | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::Details::EventTargetArray::EventTargetArray
dev_langs:
- C++
helpviewer_keywords:
- EventTargetArray, constructor
ms.assetid: 6c6d3737-3cd3-4515-a8f6-d27901bb8ed2
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3e8c8ada61a18437ed159452355e8286bc9d190f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="eventtargetarrayeventtargetarray-constructor"></a>Construtor EventTargetArray::EventTargetArray
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
EventTargetArray(  
   _Out_ HRESULT* hr,  
   size_t items  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `hr`  
 Após operações de construtor, parâmetro `hr` indica se a alocação de matriz teve êxito ou falha. A tabela a seguir lista os possíveis valores para `hr`.  
  
 S_OK  
 A operação foi bem-sucedida.  
  
 E_OUTOFMEMORY  
 Não foi possível alocar memória para a matriz.  
  
 S_FALSE  
 Parâmetro `items` é menor ou igual a zero.  
  
 `items`  
 O número de elementos da matriz para alocar.  
  
## <a name="remarks"></a>Comentários  
 Inicializa uma nova instância da classe EventTargetArray.  
  
 EventTargetArray é usada para manter uma matriz de manipuladores de eventos em um objeto de EventSource.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Classe EventTargetArray](../windows/eventtargetarray-class.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)