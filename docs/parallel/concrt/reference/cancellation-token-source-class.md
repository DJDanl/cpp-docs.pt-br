---
title: Classe cancellation_token_source | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- cancellation_token_source
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token_source
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token_source::cancellation_token_source
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token_source::cancel
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token_source::create_linked_source
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token_source::get_token
dev_langs:
- C++
helpviewer_keywords:
- cancellation_token_source class
ms.assetid: 3548b1a0-12b0-4334-95db-4bf57141c066
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: f41a4a21af5bc37ab612221152b8311a5a91d914
ms.contentlocale: pt-br
ms.lasthandoff: 03/17/2017

---
# <a name="cancellationtokensource-class"></a>Classe cancellation_token_source
O `cancellation_token_source` classe representa a capacidade de cancelar uma operação cancelável.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class cancellation_token_source;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[cancellation_token_source](#ctor)|Sobrecarregado. Constrói um novo `cancellation_token_source`. A origem pode ser usada para sinalizar o cancelamento de alguma operação cancelável.|  
|[~ cancellation_token_source destruidor](#dtor)||  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Cancelar](#cancel)|Cancela o token. Qualquer `task_group`, `structured_task_group`, ou `task` que utiliza o token será cancelado após esta chamada e lançar uma exceção no próximo ponto de interrupção.|  
|[create_linked_source](#create_linked_source)|Sobrecarregado. Cria um `cancellation_token_source` que é cancelado quando o token fornecido é cancelado.|  
|[get_token](#get_token)|Retorna um token de cancelamento associado com essa origem. O token retornado pode ser controlado de cancelamento ou fornecer um retorno de chamada quando ocorre de cancelamento.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operator!=](#operator_neq)||  
|[operator=](#operator_eq)||  
|[operator==](#operator_eq_eq)||  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `cancellation_token_source`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** pplcancellation_token.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="dtor"></a>~ cancellation_token_source 

```
~cancellation_token_source();
```  
  
##  <a name="cancel"></a>Cancelar 

 Cancela o token. Qualquer `task_group`, `structured_task_group`, ou `task` que utiliza o token será cancelado após esta chamada e lançar uma exceção no próximo ponto de interrupção.  
  
```
void cancel() const;
```  
  
##  <a name="ctor"></a>cancellation_token_source 

 Constrói um novo `cancellation_token_source`. A origem pode ser usada para sinalizar o cancelamento de alguma operação cancelável.  
  
```
cancellation_token_source();

cancellation_token_source(const cancellation_token_source& _Src);

cancellation_token_source(cancellation_token_source&& _Src);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Src`  
  
##  <a name="create_linked_source"></a>create_linked_source 

 Cria um `cancellation_token_source` que é cancelado quando o token fornecido é cancelado.  
  
```
static cancellation_token_source create_linked_source(
    cancellation_token& _Src);

template<typename _Iter>
static cancellation_token_source create_linked_source(_Iter _Begin, _Iter _End);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Iter`  
 `_Src`  
 Um token cujo cancelamento causará o cancelamento da fonte de token retornado. Observe que a fonte de token retornada também pode ser cancelada independentemente de origem contida nesse parâmetro.  
  
 `_Begin`  
 O iterador de biblioteca padrão C++ correspondente ao início do intervalo de tokens para escutar o cancelamento da.  
  
 `_End`  
 O iterador de biblioteca padrão C++ correspondente para o final do intervalo de tokens para escutar o cancelamento da.  
  
### <a name="return-value"></a>Valor de retorno  
 A `cancellation_token_source` que é cancelado quando o token fornecido pelo `_Src` parâmetro será cancelado.  
  
##  <a name="get_token"></a>get_token 

 Retorna um token de cancelamento associado com essa origem. O token retornado pode ser controlado de cancelamento ou fornecer um retorno de chamada quando ocorre de cancelamento.  
  
```
cancellation_token get_token() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um token de cancelamento associado com essa origem.  
  
##  <a name="operator_neq"></a>operador! = 

```
bool operator!= (const cancellation_token_source& _Src) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Src`  
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="operator_eq"></a>operador = 

```
cancellation_token_source& operator= (const cancellation_token_source& _Src);

cancellation_token_source& operator= (cancellation_token_source&& _Src);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Src`  
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="operator_eq_eq"></a>operador = = 

```
bool operator== (const cancellation_token_source& _Src) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Src`  
  
### <a name="return-value"></a>Valor de retorno  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)

