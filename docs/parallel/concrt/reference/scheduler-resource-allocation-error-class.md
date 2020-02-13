---
title: Classe scheduler_resource_allocation_error
ms.date: 11/04/2016
f1_keywords:
- scheduler_resource_allocation_error
- CONCRT/concurrency::scheduler_resource_allocation_error
- CONCRT/concurrency::scheduler_resource_allocation_error::scheduler_resource_allocation_error
- CONCRT/concurrency::scheduler_resource_allocation_error::get_error_code
helpviewer_keywords:
- scheduler_resource_allocation_error class
ms.assetid: 8b40449a-7abb-4d0a-bb85-c0e9a495ae97
ms.openlocfilehash: 2955320b443fb61f26d9f07ca336a45c620e2aa9
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77143333"
---
# <a name="scheduler_resource_allocation_error-class"></a>Classe scheduler_resource_allocation_error

Essa classe descreve uma exceção gerada devido a uma falha na aquisição de um recurso crítico no Tempo de Execução de Simultaneidade.

## <a name="syntax"></a>Sintaxe

```cpp
class scheduler_resource_allocation_error : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[scheduler_resource_allocation_error](#ctor)|Sobrecarregado. Constrói um objeto `scheduler_resource_allocation_error`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[get_error_code](#get_error_code)|Retorna o código de erro que causou a exceção.|

## <a name="remarks"></a>Comentários

Essa exceção normalmente é gerada quando uma chamada para o sistema operacional de dentro do Tempo de Execução de Simultaneidade falha. O código de erro que normalmente seria retornado de uma chamada para o método Win32 `GetLastError` é convertido em um valor do tipo `HRESULT` e pode ser recuperado usando o método `get_error_code`.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`scheduler_resource_allocation_error`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ConcRT. h

**Namespace:** simultaneidade

## <a name="get_error_code"></a>get_error_code

Retorna o código de erro que causou a exceção.

```cpp
HRESULT get_error_code() const throw();
```

### <a name="return-value"></a>Valor retornado

O valor `HRESULT` do erro que causou a exceção.

## <a name="ctor"></a>scheduler_resource_allocation_error

Constrói um objeto `scheduler_resource_allocation_error`.

```cpp
scheduler_resource_allocation_error(
    _In_z_ const char* _Message,
    HRESULT _Hresult) throw();

explicit _CRTIMP scheduler_resource_allocation_error(
    HRESULT _Hresult) throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

*_Hresult*<br/>
O valor `HRESULT` do erro que causou a exceção.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
