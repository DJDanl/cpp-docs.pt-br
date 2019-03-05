---
title: Classe accelerator_view_removed
ms.date: 11/04/2016
f1_keywords:
- accelerator_view_removed
- AMPRT/accelerator_view_removed
- AMPRT/Concurrency::accelerator_view_removed:accelerator_view_removed
- AMPRT/Concurrency::accelerator_view_removed:get_view_removed_reason
helpviewer_keywords:
- AMPRT/Concurrency::accelerator_view_removed:accelerator_view_removed Class
ms.assetid: 262446de-311c-454e-a5ed-e2aaced0d88a
ms.openlocfilehash: 9b803b205ea925ed8cc07e36342a1646d576d7d4
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57263748"
---
# <a name="acceleratorviewremoved-class"></a>Classe accelerator_view_removed

A exceção que é lançada quando uma chamada subjacente de DirectX falha devido ao mecanismo de detecção e recuperação de tempo limite do Windows.

## <a name="syntax"></a>Sintaxe

```
class accelerator_view_removed : public runtime_exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor de accelerator_view_removed](#ctor)|Inicializa uma nova instância da classe `accelerator_view_removed`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[get_view_removed_reason](#get_view_removed_reason)|Retorna um código de erro HRESULT que indica a causa do `accelerator_view` remoção do objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`runtime_exception`

`out_of_memory`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amprt. h

**Namespace:** Concorrência

## <a name="ctor"></a> accelerator_view_removed

Inicializa uma nova instância dos [accelerator_view_removed](accelerator-view-removed-class.md) classe.

### <a name="syntax"></a>Sintaxe

```
explicit accelerator_view_removed(
    const char * _Message,
    HRESULT _View_removed_reason ) throw();

explicit accelerator_view_removed(
    HRESULT _View_removed_reason ) throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma descrição do erro.

*_View_removed_reason*<br/>
Um código de erro HRESULT que indica a causa da remoção do `accelerator_view` objeto.

### <a name="return-value"></a>Valor de retorno

Uma nova instância da classe accelerator_view_removed.

## <a name="get_view_removed_reason_method"></a> get_view_removed_reason

Retorna um código de erro HRESULT que indica a causa do `accelerator_view` remoção do objeto.

### <a name="syntax"></a>Sintaxe

```
HRESULT get_view_removed_reason() const throw();
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
