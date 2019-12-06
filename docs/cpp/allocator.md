---
title: allocator
ms.date: 03/21/2019
f1_keywords:
- allocator_cpp
helpviewer_keywords:
- __declspec keyword [C++], allocator
- allocator __declspec keyword
ms.openlocfilehash: 2e2615829f6491bf660859fbc86ebcd07a56c5fe
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857678"
---
# <a name="allocator"></a>allocator

**Seção específica da Microsoft**

O especificador de declaração de **alocador** pode ser aplicado a funções de alocação de memória personalizadas para tornar as alocações visíveis por meio do ETW (rastreamento de eventos para Windows).

## <a name="syntax"></a>Sintaxe

```
   __declspec(allocator) 
```

## <a name="remarks"></a>Comentários

O criador de perfil de memória nativa no Visual Studio funciona coletando dados de evento ETW de alocação emitidos pelo durante o tempo de execução. Os alocadores no CRT e no SDK do Windows foram anotados no nível de origem para que seus dados de alocação possam ser capturados. Se você estiver escrevendo seus próprios alocadores, todas as funções que retornam um ponteiro para a memória de heap alocada recentemente podem ser decoradas com `__declspec(allocator)`, como visto neste exemplo para mymalloc:

```cpp
__declspec(allocator) void* myMalloc(size_t size)
```

Para obter mais informações, consulte [medir o uso de memória no Visual Studio](/visualstudio/profiling/memory-usage) e eventos de [heap de ETW nativo personalizado](/visualstudio/profiling/custom-native-etw-heap-events).

**Fim da seção específica da Microsoft**
