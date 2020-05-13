---
title: Classe Platform::Box
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::Box
ms.assetid: b3d7ea37-e98a-4fbc-80b0-ad35e50250c6
ms.openlocfilehash: 7484bcda3f05a8a9e56a33222d0630d4597e1219
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81354753"
---
# <a name="platformbox-class"></a>Classe Platform::Box

Permite que um tipo de valor, como `Windows::Foundation::DateTime` , ou um tipo escalar, como `int` , seja armazenado em um tipo `Platform::Object` . Geralmente, não é necessário usar `Box` explicitamente, já que a conversão boxing é inerente ao converter um tipo de valor para `Object^`.

### <a name="syntax"></a>Sintaxe

```cpp
ref class Box abstract;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** vccorlib.h

**Namespace:** Platform

### <a name="members"></a>Membros

|Membro|Descrição|
|------------|-----------------|
|[Box](#ctor) | Cria um `Box` que pode encapsular um valor do tipo especificado. |
|[operador&lt;Caixa const T&gt;^](#box-const-t) | Permite conversões boxing de uma classe de valor `const``T` ou classe `enum``T` em `Box<T>`. |
|[operador&lt;Caixa const volátil T&gt;^](#box-const-volatile-t) | Permite conversões boxing de uma classe de valor `const volatile``T` ou do tipo `enum``T` em `Box<T>`. |
|[caixa&lt;de operador T&gt;^](#box-t) | Permite conversões boxing de uma classe de valor `T` em `Box<T>`. |
|[caixa&lt;operador volátil T&gt;^](#box-volatile-t) | Permite conversões boxing de uma classe de valor `volatile``T` ou do tipo `enum``T` em `Box<T>`. |
|[Caixa::operador T](#t) | Permite conversões boxing de uma classe de valor `T` ou classe `enum``T` em `Box<T>`. |
|[Propriedade de valor](#value) | Retorna o valor que é encapsulado em um objeto `Box`. |

## <a name="boxbox-constructor"></a><a name="ctor"></a>Caixa::Construtor de caixa

Cria um `Box` que pode encapsular um valor do tipo especificado.

### <a name="syntax"></a>Sintaxe

```cpp
Box(T valueArg);
```

### <a name="parameters"></a>Parâmetros

*valorArg*<br/>
O tipo de valor a ser demarcado – por exemplo, `int`, `bool`, `float64` e `DateTime`.

## <a name="boxoperator-boxltconst-tgt-operator"></a><a name="box-const-t"></a>Caixa::operador&lt;Caixa const T&gt;^ Operador

Permite conversões boxing de uma classe de valor `const``T` ou classe `enum``T` em `Box<T>`.

### <a name="syntax"></a>Sintaxe

```cpp
operator Box<const T>^(const T valueType);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Qualquer classe de valor, estrutura de valor ou tipo enum. Inclui os tipos incorporados no [namespace padrão](../cppcx/default-namespace.md).

### <a name="return-value"></a>Valor retornado

Um `Platform::Box<T>^` exemplo que representa o valor original encaixotado em uma classe de árbitro.

## <a name="boxoperator-boxltconst-volatile-tgt-operator"></a><a name="box-const-volatile-t"></a>Caixa::operador&lt;Caixa const&gt;volátil T ^ Operador

Permite conversões boxing de uma classe de valor `const volatile``T` ou do tipo `enum``T` em `Box<T>`.

### <a name="syntax"></a>Sintaxe

```cpp
operator Box<const volatile T>^(const volatile T valueType);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Qualquer tipo enum, classe de valor ou estrutura de valor. Inclui os tipos incorporados no [namespace padrão](../cppcx/default-namespace.md).

### <a name="return-value"></a>Valor retornado

Um `Platform::Box<T>^` exemplo que representa o valor original encaixotado em uma classe de árbitro.

## <a name="boxoperator-boxlttgt-operator"></a><a name="box-t"></a>Caixa::operador&lt;Caixa&gt;T ^ Operador

Permite conversões boxing de uma classe de valor `T` em `Box<T>`.

### <a name="syntax"></a>Sintaxe

```cpp
operator Box<const T>^(const T valueType);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Qualquer tipo enum, classe de valor ou estrutura de valor. Inclui os tipos incorporados no [namespace padrão](../cppcx/default-namespace.md).

### <a name="return-value"></a>Valor retornado

Um `Platform::Box<T>^` exemplo que representa o valor original encaixotado em uma classe de árbitro.

## <a name="boxoperator-boxltvolatile-tgt-operator"></a><a name="box-volatile-t"></a>Caixa::caixa&lt;de&gt;operador volátil T ^ Operador

Permite conversões boxing de uma classe de valor `volatile``T` ou do tipo `enum``T` em `Box<T>`.

### <a name="syntax"></a>Sintaxe

```cpp
operator Box<volatile T>^(volatile T valueType);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Qualquer tipo enum, classe de valor ou estrutura de valor. Inclui os tipos incorporados no [namespace padrão](../cppcx/default-namespace.md).

### <a name="return-value"></a>Valor retornado

Um `Platform::Box<T>^` exemplo que representa o valor original encaixotado em uma classe de árbitro.

## <a name="boxoperator-t-operator"></a><a name="t"></a>Caixa::operador T Operador

Permite conversões boxing de uma classe de valor `T` ou classe `enum``T` em `Box<T>`.

### <a name="syntax"></a>Sintaxe

```cpp
operator Box<T>^(T valueType);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Qualquer tipo enum, classe de valor ou estrutura de valor. Inclui os tipos incorporados no [namespace padrão](../cppcx/default-namespace.md).

### <a name="return-value"></a>Valor retornado

Um `Platform::Box<T>^` exemplo que representa o valor original encaixotado em uma classe de árbitro.

## <a name="boxvalue-property"></a><a name="value"></a>Caixa::Propriedade de valor

Retorna o valor que é encapsulado em um objeto `Box`.

### <a name="syntax"></a>Sintaxe

```cpp
virtual property T Value{
   T get();
}
```

### <a name="return-value"></a>Valor retornado

Retorna o valor demarcado com o mesmo tipo que ele tinha originalmente antes de ser demarcado.

## <a name="see-also"></a>Confira também

[Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)<br/>
[Conversão boxing](../cppcx/boxing-c-cx.md)
