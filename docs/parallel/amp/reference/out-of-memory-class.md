---
title: Classe out_of_memory
ms.date: 11/04/2016
f1_keywords:
- out_of_memory
- AMPRT/out_of_memory
- AMPRT/Concurrency::out_of_memory::out_of_memory
helpviewer_keywords:
- out_of_memory class
ms.assetid: 3aa7e682-8f13-4ae6-9188-31fb423956e4
ms.openlocfilehash: e716d4952bdb9634cc0d195285d3a65c5c06b0a1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81336811"
---
# <a name="out_of_memory-class"></a>Classe out_of_memory

A exceção que é lançada quando um método falha devido à falta de memória do sistema ou do dispositivo.

## <a name="syntax"></a>Sintaxe

```cpp
class out_of_memory : public runtime_exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor out_of_memory](#ctor)|Inicia uma nova instância da classe `out_of_memory`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`runtime_exception`

`out_of_memory`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amprt.h

**Namespace:** Simultaneidade

## <a name="out_of_memory"></a><a name="ctor"></a>out_of_memory

Inicializa uma nova instância da classe.

### <a name="syntax"></a>Sintaxe

```cpp
explicit out_of_memory(
    const char * _Message ) throw();

out_of_memory () throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma descrição do erro.

### <a name="return-value"></a>Valor retornado

Uma nova instância da classe `out_of_memory`.

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
