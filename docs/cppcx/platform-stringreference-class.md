---
title: Classe Platform::StringReference
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::StringReference::StringReference
- VCCORLIB/Platform::StringReference::Data
- VCCORLIB/Platform::StringReference::Length
- VCCORLIB/Platform::StringReference::GetHSTRING
- VCCORLIB/Platform::StringReference::GetString
ms.assetid: 2d09c7ec-0f16-458e-83ed-7225a1b9221e
ms.openlocfilehash: 4748eecdf67ae5a60ddf97783a934a05e80b406c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374656"
---
# <a name="platformstringreference-class"></a>Classe Platform::StringReference

Um tipo de otimização que você pode usar para transmitir dados de cadeia de caracteres dos parâmetros de entrada `Platform::String^` a outros métodos com um mínimo de operações de cópia.

## <a name="syntax"></a>Sintaxe

```cpp
class StringReference
```

### <a name="remarks"></a>Comentários

### <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[StringReference::StringReference](#ctor)|Dois construtores para criar instâncias de `StringReference`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[StringReference::Data](#data)|Retorna os dados da cadeia de caracteres como uma matriz de valores char16.|
|[StringReference::Comprimento](#length)|Retorna o número de caracteres na cadeia de caracteres.|
|[StringReference::GetHSTRING](#gethstring)|Retorna os dados da cadeia de caracteres como um HSTRING.|
|[StringReference::GetString](#getstring)|Retorna os dados da cadeia de caracteres como uma `Platform::String^`.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[StringReference::operador=](#operator-assign)|Atribui uma `StringReference` a uma nova instância de `StringReference` .|
|[StringReference::operador()](#operator-call)|Converte uma `StringReference` em uma `Platform::String^`.|

### <a name="requirements"></a>Requisitos

**Cliente com suporte mínimo:** Windows 8

**Servidor com suporte mínimo:** Windows Server 2012

**Namespace:** Platform

**Cabeçalho:** vccorlib.h

## <a name="stringreferencedata-method"></a><a name="data"></a>StringReference::Data Method

Retorna o conteúdo desse `StringReference` como uma matriz de valores char16.

### <a name="syntax"></a>Sintaxe

```cpp
const ::default::char16 * Data() const;
```

### <a name="return-value"></a>Valor retornado

Uma matriz de caracteres de texto UNICODE char16.

## <a name="stringreferencegethstring-method"></a><a name="gethstring"></a>StringReference::GetHSTRING Method

Retorna o conteúdo da cadeia de caracteres como `__abi_HSTRING`.

### <a name="syntax"></a>Sintaxe

```cpp
__abi_HSTRING GetHSTRING() const;
```

### <a name="return-value"></a>Valor retornado

Uma `__abi_HSTRING` que contém os dados da cadeia de caracteres.

### <a name="remarks"></a>Comentários

## <a name="stringreferencegetstring-method"></a><a name="getstring"></a>StringReference::GetString Method

Retorna o conteúdo da cadeia de caracteres como uma `Platform::String^`.

### <a name="syntax"></a>Sintaxe

```cpp
__declspec(no_release_return) __declspec(no_refcount)
    ::Platform::String^ GetString() const;
```

### <a name="return-value"></a>Valor retornado

Uma `Platform::String^` que contém os dados da cadeia de caracteres.

## <a name="stringreferencelength-method"></a><a name="length"></a>StringReference::Método de comprimento

Retorna o número de caracteres na cadeia de caracteres.

### <a name="syntax"></a>Sintaxe

```cpp
unsigned int Length() const;
```

### <a name="return-value"></a>Valor retornado

Um inteiro sem sinal que especifica o número de caracteres na cadeia de caracteres.

### <a name="remarks"></a>Comentários

## <a name="stringreferenceoperator-operator"></a><a name="operator-assign"></a>StringReference::operador = Operador

Atribui o objeto especificado ao objeto `StringReference` atual.

### <a name="syntax"></a>Sintaxe

```cpp
StringReference& operator=(const StringReference& __fstrArg);
StringReference& operator=(const ::default::char16* __strArg);
```

### <a name="parameters"></a>Parâmetros

*__fstrArg*<br/>
O endereço de um objeto `StringReference` que é usado para inicializar o objeto `StringReference` atual.

*__strArg*<br/>
Ponteiro para uma matriz de valores char16 usado para inicializar o objeto `StringReference` atual.

### <a name="return-value"></a>Valor retornado

Referência a um objeto do tipo `StringReference`.

### <a name="remarks"></a>Comentários

Como `StringReference` é uma classe C++ padrão e não uma classe ref, ele não aparece no **Object Browser**.

## <a name="stringreferenceoperator--operator"></a><a name="operator-call"></a>StringReference::operador() Operador

Converte um objeto `StringReference` em um objeto `Platform::String^`.

### <a name="syntax"></a>Sintaxe

```cpp
__declspec(no_release_return) __declspec(no_refcount)
         operator ::Platform::String^() const;
```

### <a name="return-value"></a>Valor retornado

Um identificador de um objeto do tipo `Platform::String`.

## <a name="stringreferencestringreference-constructor"></a><a name="ctor"></a>StringReference::StringReference Constructor

Inicia uma nova instância da classe `StringReference`.

### <a name="syntax"></a>Sintaxe

```cpp
StringReference();
StringReference(const StringReference& __fstrArg);
StringReference(const ::default::char16* __strArg);
StringReference(const ::default::char16* __strArg, size_t __lenArg);
```

### <a name="parameters"></a>Parâmetros

*__fstrArg*<br/>
A `StringReference` cujos dados são usados para inicializar a nova instância.

*__strArg*<br/>
Ponteiro para uma matriz de valores char16 usado para inicializar a nova instância.

*__lenArg*<br/>
O número de elementos em `__strArg`.

### <a name="remarks"></a>Comentários

A primeira versão desse construtor é o construtor padrão. A segunda versão inicializa uma nova classe da instância de `StringReference` do objeto especificado pelo parâmetro `__fstrArg`. As terceira e quarta sobrecargas inicializam uma nova instância de `StringReference` de uma matriz de valores char16. char16 representa um caractere de texto UNICODE de 16 bits.

## <a name="see-also"></a>Confira também

[Classe Platform::StringReference](../cppcx/platform-stringreference-class.md)
