---
title: 'Construtor eventtargetarray:: Eventtargetarray | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::Details::EventTargetArray::EventTargetArray
dev_langs:
- C++
helpviewer_keywords:
- EventTargetArray, constructor
ms.assetid: 6c6d3737-3cd3-4515-a8f6-d27901bb8ed2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 59753f592f099f80396f408fa531756ba91b308e
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39652533"
---
# <a name="eventtargetarrayeventtargetarray-constructor"></a>Construtor EventTargetArray::EventTargetArray
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
EventTargetArray(  
   _Out_ HRESULT* hr,  
   size_t items  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *hr*  
 Depois de operações esse construtor, parâmetro *hr* indica se a alocação da matriz foi bem-sucedida ou falhou. A tabela a seguir lista os possíveis valores para *hr*.  
  
 S_OK  
 A operação foi bem-sucedida.  
  
 E_OUTOFMEMORY  
 Não foi possível alocar memória para a matriz.  
  
 S_FALSE  
 Parâmetro *itens* é menor ou igual a zero.  
  
 *Itens*  
 O número de elementos da matriz para alocar.  
  
## <a name="remarks"></a>Comentários  
 Inicializa uma nova instância dos **EventTargetArray** classe.  
  
 **EventTargetArray** é usado para manter uma matriz de manipuladores de eventos em um `EventSource` objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Event. h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Classe EventTargetArray](../windows/eventtargetarray-class.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)