---
title: Classe Platform::Exception
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::Exception::Exception
- VCCORLIB/Platform::Exception::CreateException
- VCCORLIB/Platform::Exception::HResult
- VCCORLIB/Platform::Exception::Message
helpviewer_keywords:
- Platform::Exception Class
ms.assetid: ca1d5a67-3a5a-48fe-8099-f9c38a2d2dce
ms.openlocfilehash: 4604769d9d1bc5fa848d15459327dc87d82f7016
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81363776"
---
# <a name="platformexception-class"></a>Classe Platform::Exception

Representa erros que ocorrem durante a execução do aplicativo. Classes de exceção personalizadas não podem ser derivadas de `Platform::Exception`. Se você precisar de uma exceção personalizada, poderá usar `Platform::COMException` e especificar um HRESULT específico de aplicativo.

## <a name="syntax"></a>Sintaxe

```cpp
public ref class Exception : Object,    IException,    IPrintable,    IEquatable
```

### <a name="members"></a>Membros

A classe `Exception` herda da classe `Object` e das interfaces `IException`, `IPrintable`e `IEquatable` .

A classe `Exception` também tem os tipos de membros a seguir.

### <a name="constructors"></a>Construtores

|Membro|Descrição|
|------------|-----------------|
|[Exceção::Exceção](#ctor)|Inicia uma nova instância da classe `Exception`.|

### <a name="methods"></a>Métodos

A classe `Exception` herda os métodos `Equals()`, `Finalize()`,`GetHashCode()`,`GetType()`,`MemberwiseClose()`e `ToString()` da [Platform::Object Class](../cppcx/platform-object-class.md). A classe `Exception` tem o método a seguir.

|Membro|Descrição|
|------------|-----------------|
|[Exceção::CreateException](#createexception)|Cria uma exceção que representa o valor HRESULT especificado.|

### <a name="properties"></a>Propriedades

A classe Exception também tem as propriedades a seguir.

|Membro|Descrição|
|------------|-----------------|
|[Exceção::HResult](#hresult)|O HRESULT que corresponde à exceção.|
|[Exceção::Mensagem](#message)|Uma mensagem que descreve a exceção. Esse valor é somente leitura e não pode ser modificado após a construção de `Exception` .|

### <a name="requirements"></a>Requisitos

**Cliente com suporte mínimo:** Windows 8

**Servidor com suporte mínimo:** Windows Server 2012

**Namespace:** Platform

**Metadados:** platform.winmd

## <a name="exceptioncreateexception-method"></a><a name="createexception"></a>Exceção::Método de criação de exceção

Cria uma Platform::Exception^ a partir de um valor HRESULT especificado.

### <a name="syntax"></a>Sintaxe

```cpp
Exception^ CreateException(int32 hr);
Exception^ CreateException(int32 hr, Platform::String^ message);
```

### <a name="parameters"></a>Parâmetros

*Hr*<br/>
Um valor HRESULT que você normalmente obtém de uma chamada para um método COM. Se o valor for 0, que é igual a S_OK, este método lança [Plataforma::InvalidArgumentException](../cppcx/platform-invalidargumentexception-class.md) porque os métodos COM que forem bem sucedidos não devem abrir exceções.

*Mensagem*<br/>
Uma cadeia de caracteres que descreve o erro.

### <a name="return-value"></a>Valor retornado

Uma exceção que representa o HRESULT de erro.

### <a name="remarks"></a>Comentários

Use esse método para criar uma exceção fora de um HRESULT que é retornado, por exemplo, a partir de uma chamada para um método de interface COM. Você pode usar a sobrecarga que utiliza um parâmetro String^ para fornecer uma mensagem personalizada.

É fortemente recomendável usar CreateException para criar uma exceção fortemente digitada em vez de criar uma [Plataforma::COMException](../cppcx/platform-comexception-class.md) que contém apenas o HRESULT.

## <a name="exceptionexception-constructor"></a><a name="ctor"></a>Exceção::Construtor de exceção

Inicializa uma nova instância da classe Exception.

### <a name="syntax"></a>Sintaxe

```cpp
Exception(int32 hresult);
Exception(int32 hresult, ::Platform::String^ message);
```

### <a name="parameters"></a>Parâmetros

*Hresult*<br/>
O erro HRESULT que é representado pela exceção.

*Mensagem*<br/>
Uma mensagem especificada pelo usuário, como texto prescritivo, que é associada à exceção. Em geral, você deve preferir a segunda sobrecarga para fornecer uma mensagem descritiva que seja a mais específica possível sobre como e por que ocorreu o erro.

## <a name="exceptionhresult-property"></a><a name="hresult"></a>Exceção::HResult Property

O HRESULT que corresponde à exceção.

### <a name="syntax"></a>Sintaxe

```cpp
public:
    property int HResult { int get(); }
```

## <a name="property-value"></a>Valor da propriedade

Um valor HRESULT.

### <a name="remarks"></a>Comentários

A maioria das exceções começa como erros COM, que são retornados como valores HRESULT. C++/CX converte esses valores em objetos Platform::Exception^ e essa propriedade armazena o valor do código de erro original.

## <a name="exceptionmessage-property"></a><a name="message"></a>Exceção::Propriedade de mensagem

Mensagem que descreve o erro.

### <a name="syntax"></a>Sintaxe

```cpp
public:property String^ Message;
```

## <a name="property-value"></a>Valor da propriedade

Nas exceções originadas no Windows Runtime, essa é uma descrição do erro fornecida pelo sistema.

### <a name="remarks"></a>Comentários

No Windows 8, essa propriedade é somente leitura porque exceções nessa versão do Windows Runtime são transportadas através do ABI apenas como HRESULTS. No Windows 8.1, as informações de exceção mais detalhadas são transportadas pela ABI, e você pode fornecer uma mensagem personalizada que outros componentes podem acessar programaticamente. Para obter mais informações, consulte [Exceções (C++/CX)](../cppcx/exceptions-c-cx.md).

## <a name="see-also"></a>Confira também

[Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)
