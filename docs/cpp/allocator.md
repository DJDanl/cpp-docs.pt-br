---
title: allocator
ms.date: 03/21/2019
f1_keywords:
- allocator_cpp
helpviewer_keywords:
- __declspec keyword [C++], allocator
- allocator __declspec keyword
ms.openlocfilehash: f9c8de7c8686b89a2ab9570a2558e3f649e545b5
ms.sourcegitcommit: 0064d37467f958dd6a5111f20d7660eaccd53ee9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/25/2019
ms.locfileid: "58419077"
---
# <a name="allocator"></a>allocator

**Seção específica da Microsoft**

O **alocador** especificador de declaração pode ser aplicado a funções de alocação de memória personalizado para tornar as alocações visível por meio do Event Tracing for Windows (ETW).

## <a name="syntax"></a>Sintaxe

```
   __declspec(allocator) 
```

## <a name="remarks"></a>Comentários

O criador de perfil de memória nativa no Visual Studio funciona com a coleta de alocação de dados de eventos ETW emitidos pelo durante o tempo de execução. Os alocadores no CRT e no SDK do Windows foram anotados no nível de origem para que seus dados de alocação possam ser capturados. Se você estiver escrevendo seus próprios alocadores, todas as funções que retornam um ponteiro para memória heap recém-alocada poderão ser decoradas com `__declspec(allocator)`, como mostrado neste exemplo de myMalloc:

```cpp
__declspec(allocator) void* myMalloc(size_t size)
```

Para obter mais informações, consulte [medir o uso de memória no Visual Studio](/visualstudio/profiling/memory-usage) e [eventos de heap ETW nativos personalizado](/visualstudio/profiling/custom-native-etw-heap-events).