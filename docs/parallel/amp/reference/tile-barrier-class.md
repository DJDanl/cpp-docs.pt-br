---
title: Classe tile_barrier
ms.date: 03/27/2019
f1_keywords:
- tile_barrier
- AMP/tile_barrier
- AMP/Concurrency::tile_barrier::tile_barrier::tile_barrier
- AMP/Concurrency::tile_barrier::tile_barrier::wait
- AMP/Concurrency::tile_barrier::tile_barrier::wait_with_all_memory_fence
- AMP/Concurrency::tile_barrier::tile_barrier::wait_with_global_memory_fence
- AMP/Concurrency::tile_barrier::tile_barrier::wait_with_tile_static_memory_fence
helpviewer_keywords:
- tile_barrier class
ms.assetid: b4ccdccb-0032-4e11-b7bd-dc9d43445dee
ms.openlocfilehash: 757309a10da3e6d1c9c053430cce2cf603380b1f
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77127758"
---
# <a name="tile_barrier-class"></a>Classe tile_barrier

Sincroniza a execução de threads que estão em execução no grupo de threads (o bloco) usando os métodos `wait`. Somente o tempo de execução pode criar uma instância dessa classe.

## <a name="syntax"></a>Sintaxe

```cpp
class tile_barrier;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Construtor de tile_barrier](#ctor)|Inicializa uma nova instância da classe `tile_barrier`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[esperado](#wait)|Instrui todos os threads no grupo de threads (bloco) para interromper a execução até que todos os threads no bloco terminem de esperar.|
|[wait_with_all_memory_fence](#wait_with_all_memory_fence)|Bloqueia a execução de todos os threads em um bloco até que todos os acessos à memória tenham sido concluídos e que todos os threads no bloco tenham atingido essa chamada.|
|[wait_with_global_memory_fence](#wait_with_global_memory_fence)|Bloqueia a execução de todos os threads em um bloco até que todos os acessos de memória global tenham sido concluídos e que todos os threads no bloco tenham atingido essa chamada.|
|[wait_with_tile_static_memory_fence](#wait_with_tile_static_memory_fence)|Bloqueia a execução de todos os threads em um bloco até que todos os `tile_static` acessos à memória tenham sido concluídos e que todos os threads no bloco tenham atingido essa chamada.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`tile_barrier`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** amp. h

**Namespace:** Simultaneidade

## <a name="ctor"></a>Construtor de tile_barrier

Inicializa uma nova instância da classe copiando uma existente.

### <a name="syntax"></a>Sintaxe

```cpp
tile_barrier(
    const tile_barrier& _Other ) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O objeto `tile_barrier` a ser copiado.

## <a name="wait"></a>wait

Instrui todos os threads no grupo de threads (bloco) para interromper a execução até que todos os threads no bloco terminem de esperar.

### <a name="syntax"></a>Sintaxe

```cpp
void wait() const restrict(amp);
```

## <a name="wait_with_all_memory_fence"></a>wait_with_all_memory_fence

Bloqueia a execução de todos os threads em um bloco até que todos os threads em um bloco tenham atingido essa chamada. Isso garante que todos os acessos à memória sejam visíveis para outros threads no bloco thread e tenham sido executados na ordem do programa.

### <a name="syntax"></a>Sintaxe

```cpp
void wait_with_all_memory_fence() const restrict(amp);
```

## <a name="a-namewait_with_global_memory_fence-wait_with_global_memory_fence"></a><a name="wait_with_global_memory_fence"> wait_with_global_memory_fence

Bloqueia a execução de todos os threads em um bloco até que todos os threads em um bloco tenham atingido essa chamada. Isso garante que todos os acessos de memória global fiquem visíveis para outros threads no bloco de thread e tenham sido executados na ordem do programa.

### <a name="syntax"></a>Sintaxe

```cpp
void wait_with_global_memory_fence() const  restrict(amp);
```

## <a name="a-namewait_with_tile_static_memory_fence-wait_with_tile_static_memory_fence"></a><a name="wait_with_tile_static_memory_fence"> wait_with_tile_static_memory_fence

Bloqueia a execução de todos os threads em um bloco até que todos os threads em um bloco tenham atingido essa chamada. Isso garante que `tile_static` acessos de memória sejam visíveis para outros threads no bloco de thread e tenham sido executados na ordem do programa.

### <a name="syntax"></a>Sintaxe

```cpp
void wait_with_tile_static_memory_fence() const restrict(amp);
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
