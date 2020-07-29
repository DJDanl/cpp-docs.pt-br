---
title: high_resolution_clock struct | Microsoft Docs
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
ms.openlocfilehash: 850d5e3a5434aa44e23a7f74aeb9c306ab6c0a8e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87203202"
---
# <a name="steady_clock-struct"></a>Struct steady_clock

Representa um relógio de *high_resolution* .

## <a name="syntax"></a>Sintaxe

```cpp
class high_resolution_clock
```

## <a name="members"></a>Membros

### <a name="typedefs"></a>Typedefs

|Nome|Descrição|
|----------|-----------------|
|`duration`|Um sinônimo para `nanoseconds` , definido em \<chrono> .|
|`period`|Um sinônimo para `nano` , definido em \<ratio> .|
|`rep`|Um sinônimo para **`long long`** , o tipo que é usado para representar o número de tiques de relógio na instanciação contida de `duration` .|
|`time_point`|Um sinônimo de `chrono::time_point<high_resolution_clock>`.|

## <a name="functions"></a>Funções

|||
|-|-|
|`now`|Retorna a hora atual como um `time_point` valor.|

## <a name="constants"></a>Constantes

|Nome|Descrição|
|----------|-----------------|
|`is_steady`|Contém **`true`** . Um `high_resolution_clock` é *steady*.|
