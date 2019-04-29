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
ms.openlocfilehash: f0e742a0cc1a0809fc08b3862cadb7e3deb36fa8
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62351502"
---
# <a name="tilebarrier-class"></a>Classe tile_barrier

Sincroniza a execução de threads que estão em execução no grupo de thread (o tile) usando `wait` métodos. O tempo de execução pode criar uma instância dessa classe.

### <a name="syntax"></a>Sintaxe

```
class tile_barrier;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor de tile_barrier](#ctor)|Inicializa uma nova instância da classe `tile_barrier`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[wait](#wait)|Instrui a todos os threads no grupo de segmentos (tile) para interromper a execução até que todos os threads no tile terminem de esperar.|
|[wait_with_all_memory_fence](#wait_with_all_memory_fence)|Impede a execução de todos os threads em um bloco até que todos os acessos de memória sejam concluídos e todos os segmentos no bloco atinjam esta chamada.|
|[wait_with_global_memory_fence](#wait_with_global_memory_fence)|Impede a execução de todos os threads em um bloco até que todos os acessos de memória global estejam concluídos e todos os segmentos no bloco atinjam esta chamada.|
|[wait_with_tile_static_memory_fence](#wait_with_tile_static_memory_fence)|Impede a execução de todos os threads em um bloco até que todos os `tile_static` acessos de memória sejam concluídos e todos os segmentos no bloco atinjam esta chamada.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`tile_barrier`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp. h

**Namespace:** Concorrência

## <a name="ctor"></a>  Construtor de tile_barrier

Inicializa uma nova instância da classe copiando uma existente.

### <a name="syntax"></a>Sintaxe

```
tile_barrier(
    const tile_barrier& _Other ) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O `tile_barrier` objeto a ser copiado.

## <a name="wait"></a>Aguarde

Instrui a todos os threads no grupo de segmentos (tile) para interromper a execução até que todos os threads no tile terminem de esperar.

### <a name="syntax"></a>Sintaxe

```
void wait() const restrict(amp);
```

## <a name="waitwithallmemoryfence"></a>wait_with_all_memory_fence

Impede a execução de todos os threads em um bloco até que todos os threads em um bloco atinjam esta chamada. Isso garante que todos os acessos de memória sejam visíveis para outros threads no quadro de threads e que sejam executados na ordem do programa.

### <a name="syntax"></a>Sintaxe

```
void wait_with_all_memory_fence() const restrict(amp);
```

## <a name="waitwithglobalmemoryfence"></a>wait_with_global_memory_fence

Impede a execução de todos os threads em um bloco até que todos os threads em um bloco atinjam esta chamada. Isso garante que todos os acessos de memória global sejam visíveis para outros threads no quadro de threads e que sejam executados na ordem do programa.

### <a name="syntax"></a>Sintaxe

```
void wait_with_global_memory_fence() const  restrict(amp);
```

## <a name="waitwithtilestaticmemoryfence"></a>wait_with_tile_static_memory_fence

Impede a execução de todos os threads em um bloco até que todos os threads em um bloco atinjam esta chamada. Isso garante que `tile_static` memória acessos são visíveis para outros threads no quadro de threads e que sejam executados na ordem do programa.

### <a name="syntax"></a>Sintaxe

```
void wait_with_tile_static_memory_fence() const restrict(amp);
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
