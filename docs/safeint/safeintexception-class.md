---
title: Classe SafeIntException
ms.date: 10/22/2018
ms.topic: reference
f1_keywords:
- SafeIntException Class
- SafeIntException
- SafeIntException.SafeIntException
- SafeIntException::SafeIntException
helpviewer_keywords:
- SafeIntException class
- SafeIntException, constructor
ms.assetid: 88bef958-1f48-4d55-ad4f-d1f9581a293a
ms.openlocfilehash: 8149a5e1216e26fafc1e0cd4a489cdad0551607c
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84615418"
---
# <a name="safeintexception-class"></a>Classe SafeIntException

A classe `SafeInt` usa `SafeIntException` para identificar por que uma operação matemática não pode ser concluída.

> [!NOTE]
> A versão mais recente desta biblioteca está localizada em [https://github.com/dcleblanc/SafeInt](https://github.com/dcleblanc/SafeInt) .

## <a name="syntax"></a>Sintaxe

```cpp
class SafeIntException;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Name                                                    | Descrição
------------------------------------------------------- | ------------------------------------
[SafeIntException:: SafeIntException](#safeintexception) | Cria um objeto `SafeIntException`.

## <a name="remarks"></a>Comentários

A [classe SafeInt](safeint-class.md) é a única que usa a classe `SafeIntException`.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`SafeIntException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** safeint.h

**Namespace:** msl::utilities

## <a name="safeintexceptionsafeintexception"></a><a name="safeintexception"></a>SafeIntException:: SafeIntException

Cria um objeto `SafeIntException`.

```cpp
SafeIntException();

SafeIntException(
   SafeIntError code
);
```

### <a name="parameters"></a>Parâmetros

*code*<br/>
[in] Um valor de dados enumerados que descreve o erro ocorrido.

### <a name="remarks"></a>Comentários

Os valores possíveis para *code* estão definidos no arquivo Safeint.h. Para praticidade, os valores possíveis também aparecem nesta lista.

- `SafeIntNoError`
- `SafeIntArithmeticOverflow`
- `SafeIntDivideByZero`
