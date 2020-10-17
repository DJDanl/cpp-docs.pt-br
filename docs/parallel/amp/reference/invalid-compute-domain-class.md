---
title: Classe invalid_compute_domain
ms.date: 11/04/2016
f1_keywords:
- invalid_compute_domain
- AMPRT/invalid_compute_domain
- AMPRT/Concurrency::invalid_compute_domain::invalid_compute_domain
helpviewer_keywords:
- invalid_compute_domain class
ms.assetid: ac7a7166-8bdb-4db1-8caf-ea129ab5117e
ms.openlocfilehash: 09418991e805e494c1d79ef31980bbec66a2e172
ms.sourcegitcommit: ced5ff1431ffbd25b20d106901955532723bd188
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/16/2020
ms.locfileid: "92135561"
---
# <a name="invalid_compute_domain-class"></a>Classe invalid_compute_domain

A exceção que é lançada quando o tempo de execução não pode iniciar um kernel usando o domínio de computação especificado no site de chamada [parallel_for_each](concurrency-namespace-functions-amp.md#parallel_for_each) .

## <a name="syntax"></a>Sintaxe

```cpp
class invalid_compute_domain : public runtime_exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor de invalid_compute_domain](#ctor)|Inicializa uma nova instância da classe `invalid_compute_domain`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`runtime_exception`

`invalid_compute_domain`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amprt. h

**Namespace:** Simultaneidade

## <a name="invalid_compute_domain"></a><a name="ctor"></a> invalid_compute_domain

Inicializa uma nova instância da classe.

### <a name="syntax"></a>Sintaxe

```cpp
explicit invalid_compute_domain(
    const char * _Message ) throw();

invalid_compute_domain() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma descrição do erro.

### <a name="return-value"></a>Valor Retornado

Uma instância da `invalid_compute_domain` classe

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
