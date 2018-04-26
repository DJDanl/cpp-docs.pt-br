---
title: __uncaught_exception | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- __uncaught_exception
apilocation:
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
apitype: DLLExport
f1_keywords:
- __uncaught_exception
dev_langs:
- C++
helpviewer_keywords:
- __uncaught_exception
ms.assetid: 4d9b75c6-c9c7-4876-b761-ea9ab1925e96
caps.latest.revision: 2
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f39e83aee5ee8c8652c32f72b6923c6c0c38a4ba
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="uncaughtexception"></a>__uncaught_exception

Indica se uma ou mais exceções foram lançadas, mas ainda não foram manipuladas por correspondente **catch** block de um [de try-catch](../../cpp/try-throw-and-catch-statements-cpp.md) instrução.

## <a name="syntax"></a>Sintaxe

```cpp
bool __uncaught_exception(
   );
```

## <a name="return-value"></a>Valor de retorno

**True** do momento em que uma exceção será lançada uma **tente** bloco até que a correspondência **catch** bloco for inicializada; caso contrário, **false**.

## <a name="remarks"></a>Comentários

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|__uncaught_exception|eh.h|

## <a name="see-also"></a>Consulte também

[Instruções try, throw e catch (C++)](../../cpp/try-throw-and-catch-statements-cpp.md)<br/>
