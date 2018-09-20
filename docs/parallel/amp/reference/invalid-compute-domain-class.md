---
title: Classe invalid_compute_domain | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-amp
ms.topic: reference
f1_keywords:
- invalid_compute_domain
- AMPRT/invalid_compute_domain
- AMPRT/Concurrency::invalid_compute_domain::invalid_compute_domain
dev_langs:
- C++
helpviewer_keywords:
- invalid_compute_domain class
ms.assetid: ac7a7166-8bdb-4db1-8caf-ea129ab5117e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 17d0556a349d66f4c70d730108d9cd843b736dfd
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46387023"
---
# <a name="invalidcomputedomain-class"></a>Classe invalid_compute_domain

A exceção que é lançada quando o tempo de execução não pode iniciar um kernel usando o domínio de cálculo especificado na [parallel_for_each](concurrency-namespace-functions-amp.md#parallel_for_each) site de chamada.

## <a name="syntax"></a>Sintaxe

```
class invalid_compute_domain : public runtime_exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

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

## <a name="ctor"></a> invalid_compute_domain

Inicializa uma nova instância da classe.

## <a name="syntax"></a>Sintaxe

```
explicit invalid_compute_domain(
    const char * _Message ) throw();

invalid_compute_domain() throw();
```

### <a name="parameters"></a>Parâmetros

*Mensagem*<br/>
Uma descrição do erro.

### <a name="return-value"></a>Valor de retorno

Uma instância da `invalid_compute_domain` classe

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
