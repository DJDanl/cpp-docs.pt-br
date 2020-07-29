---
title: allocator
ms.date: 03/21/2019
f1_keywords:
- allocator_cpp
helpviewer_keywords:
- __declspec keyword [C++], allocator
- allocator __declspec keyword
ms.openlocfilehash: a26cf4d2b79d64ddc9f0b60982d778e33d0f200a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87216642"
---
# `allocator`

**Específico da Microsoft**

O **`allocator`** especificador de declaração pode ser aplicado a funções de alocação de memória personalizadas para tornar as alocações visíveis por meio do ETW (rastreamento de eventos para Windows).

## <a name="syntax"></a>Sintaxe

> **`__declspec(allocator)`**

## <a name="remarks"></a>Comentários

O criador de perfil de memória nativa no Visual Studio funciona coletando dados de evento ETW de alocação emitidos pelo durante o tempo de execução. Os alocadores no CRT e no SDK do Windows foram anotados no nível de origem para que seus dados de alocação possam ser capturados. Se você estiver escrevendo seus próprios alocadores, todas as funções que retornam um ponteiro para a memória de heap alocada recentemente podem ser decoradas com `__declspec(allocator)` , como visto neste exemplo para mymalloc:

```cpp
__declspec(allocator) void* myMalloc(size_t size)
```

Para obter mais informações, consulte [medir o uso de memória no Visual Studio](/visualstudio/profiling/memory-usage) e eventos de [heap de ETW nativo personalizado](/visualstudio/profiling/custom-native-etw-heap-events).

**FINAL específico da Microsoft**
