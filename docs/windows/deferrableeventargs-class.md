---
title: Classe DeferrableEventArgs | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
ms.assetid: ece89267-7b72-40e1-8185-550c865b070a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9ce2c554ac6d959df868b80c1959a286fb0ef307
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="deferrableeventargs-class"></a>Classe DeferrableEventArgs
Uma classe de modelo usada para os tipos de argumento do evento para adiamentos.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template <  
typename TEventArgsInterface,  
typename TEventArgsClass  
>  
class DeferrableEventArgs : public TEventArgsInterface  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `TEventArgsInterface`  
 O tipo de interface que declara os argumentos para um evento adiado.  
  
 `TEventArgsClass`  
 A classe que implementa `TEventArgsInterface`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método DeferrableEventArgs::GetDeferral](../windows/deferrableeventargs-getdeferral-method.md)|Obtém uma referência para o [adiamento](http://go.microsoft.com/fwlink/p/?linkid=526520) objeto que representa um evento adiado.|  
|[Método DeferrableEventArgs::InvokeAllFinished](../windows/deferrableeventargs-invokeallfinished-method.md)|Chamado para indicar que todo o processamento para manipular um evento adiado foi concluída.|  
  
## <a name="remarks"></a>Comentários  
 As instâncias dessa classe são passadas para manipuladores de eventos para eventos adiados. Os parâmetros de modelo representam uma interface que define os detalhes dos argumentos do evento para um tipo específico de evento adiado e uma classe que implementa essa interface.  
  
 A classe é exibido como o primeiro argumento para um manipulador de eventos para um evento adiado. Você pode chamar o [GetDeferral](../windows/deferrableeventargs-getdeferral-method.md) método para obter o [adiamento](http://go.microsoft.com/fwlink/p/?linkid=526520) objeto do qual você pode obter todas as informações sobre o evento adiado. Depois de concluir a manipulação de eventos, você deve chamar Complete no objeto de adiamento. Em seguida, você deve chamar [InvokeAllFinished](../windows/deferrableeventargs-invokeallfinished-method.md) no final do método do manipulador de eventos, que garante que a conclusão de adiada todos os eventos é comunicada corretamente.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)