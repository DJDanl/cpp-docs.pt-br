---
title: SafeIntException::SafeIntException | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- SafeIntException
- SafeIntException.SafeIntException
- SafeIntException::SafeIntException
dev_langs:
- C++
helpviewer_keywords:
- SafeIntException, constructor
ms.assetid: 8e5a0c24-a56b-4c80-9ee8-876604b1e7dc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 24138db5ab772990f050fc8fcb6e5dad640a662d
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46396773"
---
# <a name="safeintexceptionsafeintexception"></a>SafeIntException::SafeIntException

Cria uma **SafeIntException** objeto.

## <a name="syntax"></a>Sintaxe

```cpp
SafeIntException();

SafeIntException(
   SafeIntError code
);
```

### <a name="parameters"></a>Parâmetros

*Código*<br/>
[in] Um valor de dados enumerado que descreve o erro que ocorreu.

## <a name="remarks"></a>Comentários

Os valores possíveis para *código* são definidos no arquivo safeint. Para sua conveniência, os possíveis valores também são listados aqui.

- `SafeIntNoError`

- `SafeIntArithmeticOverflow`

- `SafeIntDivideByZero`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** safeint

**Namespace:** MSL:: Utilities

## <a name="see-also"></a>Consulte também

[Biblioteca SafeInt](../windows/safeint-library.md)<br/>
[Classe SafeIntException](../windows/safeintexception-class.md)<br/>
[Classe SafeInt](../windows/safeint-class.md)