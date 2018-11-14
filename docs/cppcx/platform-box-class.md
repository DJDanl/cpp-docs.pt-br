---
title: Classe Platform::Box
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::Box
ms.assetid: b3d7ea37-e98a-4fbc-80b0-ad35e50250c6
ms.openlocfilehash: 29cbe852dcd606ea5cf2953c709fc8e47b89e1f1
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51327025"
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
|[operador caixa&lt;const T&gt;^](#box-const-t) | Permite conversões boxing de uma classe de valor `const` `T` ou classe `enum` `T` em `Box<T>`. |
|[operador caixa&lt;const T volátil&gt;^](#box-const-volatile-t) | Permite conversões boxing de uma classe de valor `const volatile` `T` ou do tipo `enum` `T` em `Box<T>`. |
|[operador caixa&lt;T&gt;^](#box-t) | Permite conversões boxing de uma classe de valor `T` em `Box<T>`. |
|[operador caixa&lt;T volátil&gt;^](#box-volatile-t) | Permite conversões boxing de uma classe de valor `volatile` `T` ou do tipo `enum` `T` em `Box<T>`. |
|[Box:: Operator T](#t) | Permite conversões boxing de uma classe de valor `T` ou classe `enum` `T` em `Box<T>`. |
|[Propriedade Value](#value) | Retorna o valor que é encapsulado em um objeto `Box`. |

## <a name="ctor"></a> Construtor box:: box

Cria um `Box` que pode encapsular um valor do tipo especificado.

### <a name="syntax"></a>Sintaxe

```cpp
Box(T valueArg);
```

### <a name="parameters"></a>Parâmetros

*valueArg*<br/>
O tipo de valor a ser demarcado – por exemplo, `int`, `bool`, `float64` e `DateTime`.

## <a name="box-const-t"></a> Caixa de box:: Operator&lt;const T&gt;^ operador

Permite conversões boxing de uma classe de valor `const` `T` ou classe `enum` `T` em `Box<T>`.

### <a name="syntax"></a>Sintaxe

```cpp
operator Box<const T>^(const T valueType);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Qualquer classe de valor, estrutura de valor ou tipo enum. Inclui os tipos internos na [namespace padrão](../cppcx/default-namespace.md).

### <a name="return-value"></a>Valor de retorno

Um `Platform::Box<T>^` instância que representa o valor original demarcado em uma classe ref.

## <a name="box-const-volatile-t"></a> Caixa de box:: Operator&lt;const T volátil&gt;^ operador

Permite conversões boxing de uma classe de valor `const volatile` `T` ou do tipo `enum` `T` em `Box<T>`.

### <a name="syntax"></a>Sintaxe

```cpp
operator Box<const volatile T>^(const volatile T valueType);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Qualquer tipo enum, classe de valor ou estrutura de valor. Inclui os tipos internos na [namespace padrão](../cppcx/default-namespace.md).

### <a name="return-value"></a>Valor de retorno

Um `Platform::Box<T>^` instância que representa o valor original demarcado em uma classe ref.

## <a name="box-t"></a> Caixa de box:: Operator&lt;T&gt;^ operador

Permite conversões boxing de uma classe de valor `T` em `Box<T>`.

### <a name="syntax"></a>Sintaxe

```cpp
operator Box<const T>^(const T valueType);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Qualquer tipo enum, classe de valor ou estrutura de valor. Inclui os tipos internos na [namespace padrão](../cppcx/default-namespace.md).

### <a name="return-value"></a>Valor de retorno

Um `Platform::Box<T>^` instância que representa o valor original demarcado em uma classe ref.

## <a name="box-volatile-t"></a> Caixa de box:: Operator&lt;volátil T&gt;^ operador

Permite conversões boxing de uma classe de valor `volatile` `T` ou do tipo `enum` `T` em `Box<T>`.

### <a name="syntax"></a>Sintaxe

```cpp
operator Box<volatile T>^(volatile T valueType);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Qualquer tipo enum, classe de valor ou estrutura de valor. Inclui os tipos internos na [namespace padrão](../cppcx/default-namespace.md).

### <a name="return-value"></a>Valor de retorno

Um `Platform::Box<T>^` instância que representa o valor original demarcado em uma classe ref.

## <a name="t"></a>  Operador box:: Operator T

Permite conversões boxing de uma classe de valor `T` ou classe `enum` `T` em `Box<T>`.

### <a name="syntax"></a>Sintaxe

```cpp
operator Box<T>^(T valueType);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Qualquer tipo enum, classe de valor ou estrutura de valor. Inclui os tipos internos na [namespace padrão](../cppcx/default-namespace.md).

### <a name="return-value"></a>Valor de retorno

Um `Platform::Box<T>^` instância que representa o valor original demarcado em uma classe ref.

## <a name="value"></a> Propriedade box:: Value

Retorna o valor que é encapsulado em um objeto `Box`.

### <a name="syntax"></a>Sintaxe

```cpp
virtual property T Value{
   T get();
}
```

### <a name="return-value"></a>Valor de retorno

Retorna o valor demarcado com o mesmo tipo que ele tinha originalmente antes de ser demarcado.

## <a name="see-also"></a>Consulte também

[Namespace Platform](../cppcx/platform-namespace-c-cx.md)<br/>
[Conversão boxing](../cppcx/boxing-c-cx.md)