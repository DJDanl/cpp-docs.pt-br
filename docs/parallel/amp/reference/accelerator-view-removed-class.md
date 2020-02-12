---
title: Classe accelerator_view_removed
ms.date: 03/27/2019
f1_keywords:
- accelerator_view_removed
- AMPRT/accelerator_view_removed
- AMPRT/Concurrency::accelerator_view_removed::accelerator_view_removed
- AMPRT/Concurrency::accelerator_view_removed::get_view_removed_reason
helpviewer_keywords:
- AMPRT/Concurrency::accelerator_view_removed::accelerator_view_removed Class
ms.assetid: 262446de-311c-454e-a5ed-e2aaced0d88a
ms.openlocfilehash: 9a3f6f349fc3103893639fe209dcf23a07ffec56
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77127105"
---
# <a name="accelerator_view_removed-class"></a>Classe accelerator_view_removed

A exceção gerada quando uma chamada DirectX subjacente falha devido ao mecanismo de detecção e recuperação de tempo limite do Windows.

## <a name="syntax"></a>Sintaxe

```cpp
class accelerator_view_removed : public runtime_exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Construtor de accelerator_view_removed](#ctor)|Inicializa uma nova instância da classe `accelerator_view_removed`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[get_view_removed_reason](#get_view_removed_reason)|Retorna um código de erro HRESULT que indica a causa da remoção do objeto `accelerator_view`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`runtime_exception`

`out_of_memory`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** amprt. h

**Namespace:** Simultaneidade

## <a name="ctor"></a>accelerator_view_removed

Inicializa uma nova instância da classe [accelerator_view_removed](accelerator-view-removed-class.md) .

### <a name="syntax"></a>Sintaxe

```cpp
explicit accelerator_view_removed(
    const char * message,
    HRESULT view_removed_reason ) throw();

explicit accelerator_view_removed(
    HRESULT view_removed_reason ) throw();
```

### <a name="parameters"></a>Parâmetros

*message*<br/>
Uma descrição do erro.

*view_removed_reason*<br/>
Um código de erro HRESULT que indica a causa da remoção do objeto `accelerator_view`.

### <a name="return-value"></a>Valor retornado

Uma nova instância da classe `accelerator_view_removed`.

## <a name="get_view_removed_reason"></a>get_view_removed_reason

Retorna um código de erro HRESULT que indica a causa da remoção do objeto `accelerator_view`.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT get_view_removed_reason() const throw();
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
