---
title: Classe Platform::Box
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::Box
ms.assetid: b3d7ea37-e98a-4fbc-80b0-ad35e50250c6
ms.openlocfilehash: 6afc12dbc3f6980bb7fd42d7f0a8fdc9e6d0e284
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87232164"
---
# <a name="platformbox-class"></a>Classe Platform::Box

Habilita um tipo de valor como `Windows::Foundation::DateTime` ou um tipo escalar, como **`int`** para ser armazenado em um `Platform::Object` tipo. Geralmente, não é necessário usar `Box` explicitamente, já que a conversão boxing é inerente ao converter um tipo de valor para `Object^`.

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
|[Caixa de operador &lt; const T&gt;^](#box-const-t) | Habilita conversões Boxing de uma **`const`** classe de valor `T` ou **`enum`** classe `T` para `Box<T>` . |
|[Caixa operador &lt; const volatile T&gt;^](#box-const-volatile-t) | Habilita conversões Boxing de uma **`const volatile`** classe value `T` ou **`enum`** tipo `T` para `Box<T>` . |
|[Caixa operador &lt; T&gt;^](#box-t) | Permite conversões boxing de uma classe de valor `T` em `Box<T>`. |
|[Caixa operador &lt; volátil T&gt;^](#box-volatile-t) | Habilita conversões Boxing de uma **`volatile`** classe value `T` ou **`enum`** tipo `T` para `Box<T>` . |
|[Caixa:: operador T](#t) | Habilita conversões Boxing de uma classe de valor `T` ou **`enum`** classe `T` para `Box<T>` . |
|[Propriedade Value](#value) | Retorna o valor que é encapsulado em um objeto `Box`. |

## <a name="boxbox-constructor"></a><a name="ctor"></a>Construtor Box:: Box

Cria um `Box` que pode encapsular um valor do tipo especificado.

### <a name="syntax"></a>Sintaxe

```cpp
Box(T valueArg);
```

### <a name="parameters"></a>parâmetros

*valueArg*<br/>
O tipo de valor a ser emoldurado, por exemplo,,,, **`int`** **`bool`** `float64` `DateTime` .

## <a name="boxoperator-boxltconst-tgt-operator"></a><a name="box-const-t"></a>Operador Box:: Operator caixa &lt; const T &gt; ^

Habilita conversões Boxing de uma **`const`** classe de valor `T` ou **`enum`** classe `T` para `Box<T>` .

### <a name="syntax"></a>Sintaxe

```cpp
operator Box<const T>^(const T valueType);
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Qualquer classe de valor, estrutura de valor ou tipo enum. Inclui os tipos internos no [namespace padrão](../cppcx/default-namespace.md).

### <a name="return-value"></a>Valor retornado

Uma `Platform::Box<T>^` instância que representa o valor original in a box em uma classe ref.

## <a name="boxoperator-boxltconst-volatile-tgt-operator"></a><a name="box-const-volatile-t"></a>Operador Box:: caixa operador &lt; const volatile T &gt; ^

Habilita conversões Boxing de uma **`const volatile`** classe value `T` ou **`enum`** tipo `T` para `Box<T>` .

### <a name="syntax"></a>Sintaxe

```cpp
operator Box<const volatile T>^(const volatile T valueType);
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Qualquer tipo enum, classe de valor ou estrutura de valor. Inclui os tipos internos no [namespace padrão](../cppcx/default-namespace.md).

### <a name="return-value"></a>Valor retornado

Uma `Platform::Box<T>^` instância que representa o valor original in a box em uma classe ref.

## <a name="boxoperator-boxlttgt-operator"></a><a name="box-t"></a>Operador Box:: caixa operador &lt; T &gt; ^

Permite conversões boxing de uma classe de valor `T` em `Box<T>`.

### <a name="syntax"></a>Sintaxe

```cpp
operator Box<const T>^(const T valueType);
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Qualquer tipo enum, classe de valor ou estrutura de valor. Inclui os tipos internos no [namespace padrão](../cppcx/default-namespace.md).

### <a name="return-value"></a>Valor retornado

Uma `Platform::Box<T>^` instância que representa o valor original in a box em uma classe ref.

## <a name="boxoperator-boxltvolatile-tgt-operator"></a><a name="box-volatile-t"></a>Operador Box:: Operator caixa &lt; volátil T &gt; ^

Habilita conversões Boxing de uma **`volatile`** classe value `T` ou **`enum`** tipo `T` para `Box<T>` .

### <a name="syntax"></a>Sintaxe

```cpp
operator Box<volatile T>^(volatile T valueType);
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Qualquer tipo enum, classe de valor ou estrutura de valor. Inclui os tipos internos no [namespace padrão](../cppcx/default-namespace.md).

### <a name="return-value"></a>Valor retornado

Uma `Platform::Box<T>^` instância que representa o valor original in a box em uma classe ref.

## <a name="boxoperator-t-operator"></a><a name="t"></a>Operador Box:: operador T

Habilita conversões Boxing de uma classe de valor `T` ou **`enum`** classe `T` para `Box<T>` .

### <a name="syntax"></a>Sintaxe

```cpp
operator Box<T>^(T valueType);
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Qualquer tipo enum, classe de valor ou estrutura de valor. Inclui os tipos internos no [namespace padrão](../cppcx/default-namespace.md).

### <a name="return-value"></a>Valor retornado

Uma `Platform::Box<T>^` instância que representa o valor original in a box em uma classe ref.

## <a name="boxvalue-property"></a><a name="value"></a>Propriedade Box:: valor

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
