---
title: Classe AsyncBase | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::AsyncBase
dev_langs:
- C++
helpviewer_keywords:
- AsyncBase class
ms.assetid: 64259b9b-f427-4ffd-a611-e7a2f82362b2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5c9dbd5d7296edaed9e850e6453f1b1b593ddba9
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="asyncbase-class"></a>Classe AsyncBase
Implementa a máquina de estado assíncrona do tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
template <  
   typename TComplete,  
   typename TProgress = Details::Nil,  
   AsyncResultType resultType = SingleResult  
>  
class AsyncBase : public AsyncBase<TComplete, Details::Nil, resultType>;  
  
template <  
   typename TComplete,  
   AsyncResultType resultType  
>  
class AsyncBase<TComplete, Details::Nil, resultType> : public Microsoft::WRL::Implements<IAsyncInfo>;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `TComplete`  
 Um manipulador de eventos que é chamado quando uma operação assíncrona é concluída.  
  
 `TProgress`  
 Um manipulador de eventos que é chamado quando uma operação assíncrona em execução relata o progresso atual da operação.  
  
 `resultType`  
 Uma da [AsyncResultType](../windows/asyncresulttype-enumeration.md) valores de enumeração. Por padrão, SingleResult.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor AsyncBase::AsyncBase](../windows/asyncbase-asyncbase-constructor.md)|Inicializa uma instância da classe AsyncBase.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método AsyncBase::Cancel](../windows/asyncbase-cancel-method.md)|Cancela uma operação assíncrona.|  
|[Método AsyncBase::Close](../windows/asyncbase-close-method.md)|Fecha a operação assíncrona.|  
|[Método AsyncBase::FireCompletion](../windows/asyncbase-firecompletion-method.md)|Invoca o manipulador de eventos de conclusão ou redefine o delegado de progresso interno.|  
|[Método AsyncBase::FireProgress](../windows/asyncbase-fireprogress-method.md)|Invoca o manipulador de eventos de andamento atual.|  
|[Método AsyncBase::get_ErrorCode](../windows/asyncbase-get-errorcode-method.md)|Recupera o código de erro para a operação assíncrona atual.|  
|[Método AsyncBase::get_Id](../windows/asyncbase-get-id-method.md)|Recupera o identificador da operação assíncrona.|  
|[Método AsyncBase::get_Status](../windows/asyncbase-get-status-method.md)|Recupera um valor que indica o status da operação assíncrona.|  
|[Método AsyncBase::GetOnComplete](../windows/asyncbase-getoncomplete-method.md)|Copia o endereço do manipulador de eventos de conclusão atual para a variável especificada.|  
|[Método AsyncBase::GetOnProgress](../windows/asyncbase-getonprogress-method.md)|Copia o endereço do manipulador de eventos de andamento atual para a variável especificada.|  
|[Método AsyncBase::put_Id](../windows/asyncbase-put-id-method.md)|Define o identificador da operação assíncrona.|  
|[Método AsyncBase::PutOnComplete](../windows/asyncbase-putoncomplete-method.md)|Define o endereço do manipulador de eventos de conclusão para o valor especificado.|  
|[Método AsyncBase::PutOnProgress](../windows/asyncbase-putonprogress-method.md)|Define o endereço do manipulador de eventos de andamento para o valor especificado.|  
|[Método AsyncBase::Start](../windows/asyncbase-start-method.md)|Inicia a operação assíncrona.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método AsyncBase::CheckValidStateForDelegateCall](../windows/asyncbase-checkvalidstatefordelegatecall-method.md)|Testa se o delegado propriedades podem ser modificadas no estado atual assíncrono.|  
|[Método AsyncBase::CheckValidStateForResultsCall](../windows/asyncbase-checkvalidstateforresultscall-method.md)|Verifica se os resultados de uma operação assíncrona podem ser coletados no estado atual assíncrono.|  
|[Método AsyncBase::ContinueAsyncOperation](../windows/asyncbase-continueasyncoperation-method.md)|Determina se a operação assíncrona deve continuar o processamento ou deve parar.|  
|[Método AsyncBase::CurrentStatus](../windows/asyncbase-currentstatus-method.md)|Recupera o status da operação assíncrona atual.|  
|[Método AsyncBase::ErrorCode](../windows/asyncbase-errorcode-method.md)|Recupera o código de erro para a operação assíncrona atual.|  
|[Método AsyncBase::OnCancel](../windows/asyncbase-oncancel-method.md)|Quando substituído em uma classe derivada, cancela uma operação assíncrona.|  
|[Método AsyncBase::OnClose](../windows/asyncbase-onclose-method.md)|Quando substituído em uma classe derivada, fecha uma operação assíncrona.|  
|[Método AsyncBase::OnStart](../windows/asyncbase-onstart-method.md)|Quando substituído em uma classe derivada, inicia uma operação assíncrona.|  
|[Método AsyncBase::TryTransitionToCompleted](../windows/asyncbase-trytransitiontocompleted-method.md)|Indica se a operação assíncrona atual foi concluída.|  
|[Método AsyncBase::TryTransitionToError](../windows/asyncbase-trytransitiontoerror-method.md)|Indica se o código de erro especificado pode modificar o estado de erro interno.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `AsyncBase`  
  
 `AsyncBase`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)