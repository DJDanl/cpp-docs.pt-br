---
title: Classe scheduler_resource_allocation_error | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- scheduler_resource_allocation_error
- CONCRT/concurrency::scheduler_resource_allocation_error
- CONCRT/concurrency::scheduler_resource_allocation_error::scheduler_resource_allocation_error
- CONCRT/concurrency::scheduler_resource_allocation_error::get_error_code
dev_langs:
- C++
helpviewer_keywords:
- scheduler_resource_allocation_error class
ms.assetid: 8b40449a-7abb-4d0a-bb85-c0e9a495ae97
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f8639e70e74f122da8ffa2d58501ad04884aa306
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46437138"
---
# <a name="schedulerresourceallocationerror-class"></a>Classe scheduler_resource_allocation_error

Esta classe descreve uma exceção gerada devido a uma falha ao adquirir um recurso crítico no tempo de execução de simultaneidade.

## <a name="syntax"></a>Sintaxe

```
class scheduler_resource_allocation_error : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[scheduler_resource_allocation_error](#ctor)|Sobrecarregado. Constrói um objeto `scheduler_resource_allocation_error`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[get_error_code](#get_error_code)|Retorna o código de erro que causou a exceção.|

## <a name="remarks"></a>Comentários

Essa exceção normalmente é lançada quando a falha de uma chamada para o sistema operacional de dentro do tempo de execução de simultaneidade. O código de erro que normalmente seria retornado de uma chamada para o método do Win32 `GetLastError` é convertido em um valor do tipo `HRESULT` e pode ser recuperado usando o `get_error_code` método.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`scheduler_resource_allocation_error`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade

##  <a name="get_error_code"></a> get_error_code

Retorna o código de erro que causou a exceção.

```
HRESULT get_error_code() const throw();
```

### <a name="return-value"></a>Valor de retorno

O `HRESULT` valor do erro que causou a exceção.

##  <a name="ctor"></a> scheduler_resource_allocation_error

Constrói um objeto `scheduler_resource_allocation_error`.

```
scheduler_resource_allocation_error(
    _In_z_ const char* _Message,
    HRESULT _Hresult) throw();

explicit _CRTIMP scheduler_resource_allocation_error(
    HRESULT _Hresult) throw();
```

### <a name="parameters"></a>Parâmetros

*Mensagem*<br/>
Uma mensagem descritiva do erro.

*_Hresult*<br/>
O `HRESULT` valor do erro que causou a exceção.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
