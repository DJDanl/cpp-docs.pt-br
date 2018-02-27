---
title: Classe cancellation_token | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- cancellation_token
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token::cancellation_token
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token::deregister_callback
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token::is_cancelable
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token::is_canceled
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token::none
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token::register_callback
dev_langs:
- C++
helpviewer_keywords:
- cancellation_token class
ms.assetid: 2787df2b-e9d3-440e-bfd0-841a46a9835f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1e95bfb264b1c6fbc4230cf38fc26b7b6a2c12a1
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="cancellationtoken-class"></a>Classe cancellation_token
O `cancellation_token` classe representa a capacidade de determinar se alguma operação foi solicitada para cancelar. Um token fornecido pode ser associado com um `task_group`, `structured_task_group`, ou `task` para fornecer cancelamento implícita. Ele também pode ser controlado de cancelamento ou tem um retorno de chamada registrado para se e quando associado `cancellation_token_source` é cancelada.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class cancellation_token;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[cancellation_token](#ctor)||  
|[~cancellation_token Destructor](#dtor)||  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[deregister_callback](#deregister_callback)|Remove um retorno de chamada registrado anteriormente por meio de `register` método com base no `cancellation_token_registration` objeto retornado no momento do registro.|  
|[is_cancelable](#is_cancelable)|Retorna uma indicação de se esse token pode ser cancelado ou não.|  
|[is_canceled](#is_canceled)|Retorna `true` se o token foi cancelado.|  
|[none](#none)|Retorna um token de cancelamento que nunca pode estar sujeitos a cancelamento.|  
|[register_callback](#register_callback)|Registra uma função de retorno de chamada com o token. Se o token é cancelado, e quando o retorno de chamada será feito. Observe que, se o token já é cancelado no ponto em que este método é chamado, o retorno de chamada será feito imediatamente e de forma síncrona.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operator!=](#operator_neq)||  
|[operator=](#operator_eq)||  
|[operator==](#operator_eq_eq)||  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `cancellation_token`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** pplcancellation_token.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="dtor"></a> ~cancellation_token 

```
~cancellation_token();
```  
  
##  <a name="ctor"></a> cancellation_token 

```
cancellation_token(const cancellation_token& _Src);

cancellation_token(cancellation_token&& _Src);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Src`  
  
##  <a name="deregister_callback"></a> deregister_callback 

 Remove um retorno de chamada registrado anteriormente por meio de `register` método com base no `cancellation_token_registration` objeto retornado no momento do registro.  
  
```
void deregister_callback(const cancellation_token_registration& _Registration) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Registration`  
 O `cancellation_token_registration` objeto correspondente para o retorno de chamada para ter o registro cancelado. Esse token deve ter sido retornado de uma chamada para o `register` método.  
  
##  <a name="is_cancelable"></a> is_cancelable 

 Retorna uma indicação de se esse token pode ser cancelado ou não.  
  
```
bool is_cancelable() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma indicação de se esse token pode ser cancelado ou não.  
  
##  <a name="is_canceled"></a> is_canceled 

 Retorna `true` se o token foi cancelado.  
  
```
bool is_canceled() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor `true` se o token tiver sido cancelada; caso contrário, o valor `false`.  
  
##  <a name="none"></a> Nenhum 

 Retorna um token de cancelamento que nunca pode estar sujeitos a cancelamento.  
  
```
static cancellation_token none();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um token de cancelamento que não pode ser cancelado.  
  
##  <a name="operator_neq"></a> operador! = 

```
bool operator!= (const cancellation_token& _Src) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Src`  
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="operator_eq"></a> operador = 

```
cancellation_token& operator= (const cancellation_token& _Src);

cancellation_token& operator= (cancellation_token&& _Src);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Src`  
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="operator_eq_eq"></a> operador = = 

```
bool operator== (const cancellation_token& _Src) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Src`  
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="register_callback"></a> register_callback 

 Registra uma função de retorno de chamada com o token. Se o token é cancelado, e quando o retorno de chamada será feito. Observe que, se o token já é cancelado no ponto em que este método é chamado, o retorno de chamada será feito imediatamente e de forma síncrona.  
  
```
template<typename _Function>
::Concurrency::cancellation_token_registration register_callback(const _Function& _Func) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Function`  
 O tipo do objeto de função que será chamado quando este `cancellation_token` é cancelada.  
  
 `_Func`  
 O objeto de função que será chamado quando este `cancellation_token` é cancelada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `cancellation_token_registration` objeto que pode ser utilizado com o `deregister` método para cancelar o registro de um retorno de chamada registrado anteriormente e impedi-lo de que está sendo feita. O método lançará um [invalid_operation](invalid-operation-class.md) exceção se for chamado um `cancellation_token` objeto que foi criado usando o [cancellation_token:: none](#none) método.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)
