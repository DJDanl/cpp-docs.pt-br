---
title: __uncaught_exception
ms.date: 11/04/2016
api_name:
- __uncaught_exception
api_location:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- __uncaught_exception
helpviewer_keywords:
- __uncaught_exception
ms.assetid: 4d9b75c6-c9c7-4876-b761-ea9ab1925e96
ms.openlocfilehash: 1eb06abbda7978acf578555f966f0857dff02053
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211626"
---
# <a name="__uncaught_exception"></a>__uncaught_exception

Indica se uma ou mais exceções foram geradas, mas ainda não foram tratadas pelo bloco correspondente **`catch`** de uma instrução [try-catch](../../cpp/try-throw-and-catch-statements-cpp.md) .

## <a name="syntax"></a>Sintaxe

```cpp
bool __uncaught_exception(
   );
```

## <a name="return-value"></a>Valor retornado

**`true`** desde o momento em que uma exceção é lançada em um **`try`** bloco até que o **`catch`** bloco correspondente seja inicializado; caso contrário, **`false`** .

## <a name="remarks"></a>Comentários

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|__uncaught_exception|eh.h|

## <a name="see-also"></a>Confira também

[Instruções try, throw e catch (C++)](../../cpp/try-throw-and-catch-statements-cpp.md)<br/>
