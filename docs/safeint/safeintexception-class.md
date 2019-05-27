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
ms.openlocfilehash: 2998bbb83fd568d7ff627d6598c32fb5b17c1e40
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "65515561"
---
# <a name="safeintexception-class"></a>Classe SafeIntException

A classe `SafeInt` usa `SafeIntException` para identificar por que uma operação matemática não pode ser concluída.

> [!NOTE]
> A última versão dessa biblioteca está localizada em [https://github.com/dcleblanc/SafeInt](https://github.com/dcleblanc/SafeInt).

## <a name="syntax"></a>Sintaxe

```cpp
class SafeIntException;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                                    | Descrição
------------------------------------------------------- | ------------------------------------
[SafeIntException::SafeIntException](#safeintexception) | Cria um objeto `SafeIntException`.

## <a name="remarks"></a>Comentários

A [classe SafeInt](../safeint/safeint-class.md) é a única que usa a classe `SafeIntException`.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`SafeIntException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** safeint.h

**Namespace:** msl::utilities

## <a name="safeintexception"></a>SafeIntException::SafeIntException

Cria um objeto `SafeIntException`.

```cpp
SafeIntException();

SafeIntException(
   SafeIntError code
);
```

### <a name="parameters"></a>Parâmetros

*código*<br/>
[in] Um valor de dados enumerados que descreve o erro ocorrido.

### <a name="remarks"></a>Comentários

Os valores possíveis para *code* estão definidos no arquivo Safeint.h. Para praticidade, os valores possíveis também aparecem nesta lista.

- `SafeIntNoError`
- `SafeIntArithmeticOverflow`
- `SafeIntDivideByZero`
