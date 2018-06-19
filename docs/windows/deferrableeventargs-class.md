---
title: Classe DeferrableEventArgs | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
ms.assetid: ece89267-7b72-40e1-8185-550c865b070a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 15be5c26e5d4e976eaba7b6b24e1bf4f62c53aca
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33872084"
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
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)