---
title: "Classe AsyncBase | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "async/Microsoft::WRL::AsyncBase"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe AsyncBase"
ms.assetid: 64259b9b-f427-4ffd-a611-e7a2f82362b2
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe AsyncBase
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Implementa a máquina de status assíncrono de Tempo de Execução do Windows.  
  
## Sintaxe  
  
```  
  
template <  
   typename TComplete,  
   typename TProgress = Details::Nil,  
   AsyncResultType resultType = SingleResult  
>  
class AsyncBase : public AsyncBase< TComplete, Details::Nil, resultType >;  
  
template <  
   typename TComplete,  
   AsyncResultType resultType  
>  
class AsyncBase< TComplete, Details::Nil, resultType > : public Microsoft::WRL::Implements< IAsyncInfo >;  
```  
  
#### Parâmetros  
 `TComplete`  
 Um manipulador de eventos que é chamado quando uma operação assíncrona seja concluída.  
  
 `TProgress`  
 Um manipulador de eventos que é chamado quando uma operação assíncrona em execução informar o progresso atual da operação.  
  
 `resultType`  
 Um dos valores de enumeração de [AsyncResultType](../windows/asyncresulttype-enumeration.md) .  Por padrão, SingleResult.  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor AsyncBase::AsyncBase](../windows/asyncbase-asyncbase-constructor.md)|Inicializa uma instância da classe de AsyncBase.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método AsyncBase::Cancel](../Topic/AsyncBase::Cancel%20Method.md)|Cancela uma operação assíncrona.|  
|[Método AsyncBase::Close](../windows/asyncbase-close-method.md)|Fecha a operação assíncrona.|  
|[Método AsyncBase::FireCompletion](../windows/asyncbase-firecompletion-method.md)|Invoca o manipulador de eventos de conclusão, ou redefine o delegado interno de progresso.|  
|[Método AsyncBase::FireProgress](../windows/asyncbase-fireprogress-method.md)|Invoca o manipulador de eventos atual do progresso.|  
|[Método AsyncBase::get\_ErrorCode](../windows/asyncbase-get-errorcode-method.md)|Recupera o código de erro para a operação assíncrona atual.|  
|[Método AsyncBase::get\_Id](../windows/asyncbase-get-id-method.md)|Recupera o identificador de operação assíncrona.|  
|[Método AsyncBase::get\_Status](../Topic/AsyncBase::get_Status%20Method.md)|Recupera um valor que indica o status da operação assíncrona.|  
|[Método AsyncBase::GetOnComplete](../windows/asyncbase-getoncomplete-method.md)|Copia o endereço do manipulador de eventos atual de conclusão a variável especificada.|  
|[Método AsyncBase::GetOnProgress](../windows/asyncbase-getonprogress-method.md)|Copia o endereço do manipulador de eventos atual do progresso a variável especificada.|  
|[Método AsyncBase::put\_Id](../windows/asyncbase-put-id-method.md)|Define o identificador de operação assíncrona.|  
|[Método AsyncBase::PutOnComplete](../windows/asyncbase-putoncomplete-method.md)|Define o endereço do manipulador de eventos de conclusão com o valor especificado.|  
|[Método AsyncBase::PutOnProgress](../windows/asyncbase-putonprogress-method.md)|Define o endereço do manipulador de eventos de andamento para o valor especificado.|  
|[Método AsyncBase::Start](../windows/asyncbase-start-method.md)|Começa uma operação assíncrona.|  
  
### Métodos Protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método AsyncBase::CheckValidStateForDelegateCall](../windows/asyncbase-checkvalidstatefordelegatecall-method.md)|Testa se as propriedades de delegação podem ser alteradas no estado assíncrona atual.|  
|[Método AsyncBase::CheckValidStateForResultsCall](../windows/asyncbase-checkvalidstateforresultscall-method.md)|Testa se os resultados de uma operação assíncrona podem ser coletados no estado assíncrona atual.|  
|[Método AsyncBase::ContinueAsyncOperation](../Topic/AsyncBase::ContinueAsyncOperation%20Method.md)|Determina se a operação assíncrona deve continuar a processar ou deve parar.|  
|[Método AsyncBase::CurrentStatus](../Topic/AsyncBase::CurrentStatus%20Method.md)|Recupera o status da operação assíncrona atual.|  
|[Método AsyncBase::ErrorCode](../windows/asyncbase-errorcode-method.md)|Recupera o código de erro para a operação assíncrona atual.|  
|[Método AsyncBase::OnCancel](../windows/asyncbase-oncancel-method.md)|Quando substituído em uma classe derivada, cancela uma operação assíncrona.|  
|[Método AsyncBase::OnClose](../windows/asyncbase-onclose-method.md)|Quando substituído em uma classe derivada, fecha uma operação assíncrona.|  
|[Método AsyncBase::OnStart](../windows/asyncbase-onstart-method.md)|Quando substituído em uma classe derivada, começa uma operação assíncrona.|  
|[Método AsyncBase::TryTransitionToCompleted](../windows/asyncbase-trytransitiontocompleted-method.md)|Indica se a operação assíncrona atual foi concluída.|  
|[Método AsyncBase::TryTransitionToError](../windows/asyncbase-trytransitiontoerror-method.md)|Indica se o código de erro especificado é possível alterar o estado de erro interno.|  
  
## Hierarquia de Herança  
 `AsyncBase`  
  
 `AsyncBase`  
  
## Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)