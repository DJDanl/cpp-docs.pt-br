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
ms.openlocfilehash: c00f1e41e70e723be185959eeff176390def7647
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374719"
---
# <a name="tile_barrier-class"></a>Classe tile_barrier

Sincroniza a execução de roscas que estão sendo executados `wait` no grupo de rosca (o bloco) usando métodos. Só o tempo de execução pode instanciar esta classe.

## <a name="syntax"></a>Sintaxe

```cpp
class tile_barrier;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[construtor tile_barrier](#ctor)|Inicia uma nova instância da classe `tile_barrier`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Esperar](#wait)|Instrui todos os segmentos do grupo de rosca (ladrilho) a parar de executar até que todos os fios da telha tenham terminado de esperar.|
|[wait_with_all_memory_fence](#wait_with_all_memory_fence)|Bloqueia a execução de todos os segmentos em um ladrilho até que todos os acessos de memória tenham sido concluídos e todos os fios no azulejo tenham atingido esta chamada.|
|[wait_with_global_memory_fence](#wait_with_global_memory_fence)|Bloqueia a execução de todos os segmentos em um ladrilho até que todos os acessos de memória global tenham sido concluídos e todos os segmentos no azulejo tenham chegado a esta chamada.|
|[wait_with_tile_static_memory_fence](#wait_with_tile_static_memory_fence)|Bloqueia a execução de todos `tile_static` os segmentos em um ladrilho até que todos os acessos de memória tenham sido concluídos e todos os fios no azulejo tenham atingido esta chamada.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`tile_barrier`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp.h

**Namespace:** Simultaneidade

## <a name="tile_barrier-constructor"></a><a name="ctor"></a>construtor tile_barrier

Inicializa uma nova instância da classe copiando uma já existente.

### <a name="syntax"></a>Sintaxe

```cpp
tile_barrier(
    const tile_barrier& _Other ) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O objeto `tile_barrier` a ser copiado.

## <a name="wait"></a>wait

Instrui todos os segmentos do grupo de rosca (ladrilho) a interromper a execução até que todos os fios do azulejo tenham terminado de esperar.

### <a name="syntax"></a>Sintaxe

```cpp
void wait() const restrict(amp);
```

## <a name="wait_with_all_memory_fence"></a><a name="wait_with_all_memory_fence"></a>wait_with_all_memory_fence

Bloqueia a execução de todos os fios em um ladrilho até que todos os fios em um ladrilho tenham atingido esta chamada. Isso garante que todos os acessos de memória sejam visíveis para outros segmentos no bloco de segmentos e tenham sido executados em ordem de programa.

### <a name="syntax"></a>Sintaxe

```cpp
void wait_with_all_memory_fence() const restrict(amp);
```

## <a name="a-namewait_with_global_memory_fence-wait_with_global_memory_fence"></a><a name="wait_with_global_memory_fence">wait_with_global_memory_fence

Bloqueia a execução de todos os fios em um ladrilho até que todos os fios em um ladrilho tenham atingido esta chamada. Isso garante que todos os acessos de memória globais sejam visíveis para outros segmentos no bloco de segmentos e tenham sido executados em ordem de programa.

### <a name="syntax"></a>Sintaxe

```cpp
void wait_with_global_memory_fence() const  restrict(amp);
```

## <a name="a-namewait_with_tile_static_memory_fence-wait_with_tile_static_memory_fence"></a><a name="wait_with_tile_static_memory_fence">wait_with_tile_static_memory_fence

Bloqueia a execução de todos os fios em um ladrilho até que todos os fios em um ladrilho tenham atingido esta chamada. Isso garante `tile_static` que os acessos de memória sejam visíveis para outros segmentos no bloco de segmentos e tenham sido executados em ordem de programa.

### <a name="syntax"></a>Sintaxe

```cpp
void wait_with_tile_static_memory_fence() const restrict(amp);
```

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
