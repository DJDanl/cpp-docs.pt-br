---
title: struct high_resolution_clock | Microsoft Docs
ms.custom: ''
ms.date: 05/22/2018
ms.technology: cpp-standard-libraries
ms.topic: reference
f1_keywords:
- chrono/std::chrono::high_resolution_clock
dev_langs:
- C++
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0b00b20e7cea4fa24b37ad33d5536eb9844e6953
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68269118"
---
# <a name="steadyclock-struct"></a>Struct steady_clock

Representa uma *high_resolution* relógio.

## <a name="syntax"></a>Sintaxe

```cpp
class high_resolution_clock
```

## <a name="members"></a>Membros

### <a name="typedefs"></a>Typedefs

|Nome|Descrição|
|----------|-----------------|
|`duration`|Um sinônimo de `nanoseconds`, definida em \<chrono >.|
|`period`|Um sinônimo de `nano`, definida em \<taxa >.|
|`rep`|Um sinônimo de **longo** **longo**, o tipo que é usado para representar o número de tiques do relógio na instanciação independente de `duration`.|
|`time_point`|Um sinônimo de `chrono::time_point<high_resolution_clock>`.|

## <a name="functions"></a>Funções

|||
|-|-|
|`now`|Retorna a hora atual como um `time_point` valor.|

## <a name="constants"></a>Constantes

|Nome|Descrição|
|----------|-----------------|
|`is_steady`|Mantém **verdadeira**. Um `high_resolution_clock` é *steady*.|
