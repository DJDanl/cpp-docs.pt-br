---
title: 'Classe Platform:: Exception | Microsoft Docs'
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::Exception::Exception
- VCCORLIB/Platform::Exception::CreateException
- VCCORLIB/Platform::Exception::HResult
- VCCORLIB/Platform::Exception::Message
dev_langs:
- C++
helpviewer_keywords:
- Platform::Exception Class
ms.assetid: ca1d5a67-3a5a-48fe-8099-f9c38a2d2dce
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8e79788815a240a026da3121432ea688a2507fdf
ms.sourcegitcommit: 761c5f7c506915f5a62ef3847714f43e9b815352
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/07/2018
ms.locfileid: "44103808"
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
|[Exception:: Exception](#ctor)|Inicializa uma nova instância da classe `Exception`.|

### <a name="methods"></a>Métodos

A classe `Exception` herda os métodos `Equals()`, `Finalize()`,`GetHashCode()`,`GetType()`,`MemberwiseClose()`e `ToString()` da [Platform::Object Class](../cppcx/platform-object-class.md). A classe `Exception` tem o método a seguir.

|Membro|Descrição|
|------------|-----------------|
|[Exception::CreateException](#createexception)|Cria uma exceção que representa o valor HRESULT especificado.|

### <a name="properties"></a>Propriedades

A classe Exception também tem as propriedades a seguir.

|Membro|Descrição|
|------------|-----------------|
|[Exception::HResult](#hresult)|O HRESULT que corresponde à exceção.|
|[Exception::Message](#message)|Uma mensagem que descreve a exceção. Esse valor é somente leitura e não pode ser modificado após a construção de `Exception` .|

### <a name="requirements"></a>Requisitos

**Mínimo de cliente com suporte:** Windows 8

**Mínimo de servidor com suporte:** Windows Server 2012

**Namespace:** Platform

**Metadados:** platform.winmd

## <a name="createexception"></a> Método Exception:: createexception

Cria uma Platform::Exception^ a partir de um valor HRESULT especificado.

### <a name="syntax"></a>Sintaxe

```cpp
Exception^ CreateException(int32 hr);
Exception^ CreateException(int32 hr, Platform::String^ message);
```

### <a name="parameters"></a>Parâmetros

*hr*<br/>
Um valor HRESULT que você normalmente obtém de uma chamada para um método COM. Se o valor for 0, que é igual a S_OK, esse método gerará [Platform:: invalidargumentexception](../cppcx/platform-invalidargumentexception-class.md) porque os métodos COM bem-sucedidos não devem lançar exceções.

*message*<br/>
Uma cadeia de caracteres que descreve o erro.

### <a name="return-value"></a>Valor de retorno

Uma exceção que representa o HRESULT de erro.

### <a name="remarks"></a>Comentários

Use esse método para criar uma exceção fora de um HRESULT que é retornado, por exemplo, a partir de uma chamada para um método de interface COM. Você pode usar a sobrecarga que utiliza um parâmetro String^ para fornecer uma mensagem personalizada.

É altamente recomendável usar CreateException para criar uma exceção fortemente tipada em vez de criar uma [Platform:: COMException](../cppcx/platform-comexception-class.md) que simplesmente contenha o HRESULT.

## <a name="ctor"></a>  Construtor Exception:: Exception

Inicializa uma nova instância da classe Exception.

### <a name="syntax"></a>Sintaxe

```cpp
Exception(int32 hresult);
Exception(int32 hresult, ::Platform::String^ message);
```

### <a name="parameters"></a>Parâmetros

*HRESULT*<br/>
O erro HRESULT que é representado pela exceção.

*message*<br/>
Uma mensagem especificada pelo usuário, como texto prescritivo, que é associada à exceção. Em geral, você deve preferir a segunda sobrecarga para fornecer uma mensagem descritiva que seja a mais específica possível sobre como e por que ocorreu o erro.

## <a name="hresult"></a>  Propriedade Exception:: HRESULT

O HRESULT que corresponde à exceção.

### <a name="syntax"></a>Sintaxe

```cpp
public:
    property int HResult { int get(); }
```

## <a name="property-value"></a>Valor de propriedade

Um valor HRESULT.

### <a name="remarks"></a>Comentários

A maioria das exceções começa como erros COM, que são retornados como valores HRESULT. C++/CX converte esses valores em objetos Platform::Exception^ e essa propriedade armazena o valor do código de erro original.

## <a name="message"></a> Propriedade Exception:: Message

Mensagem que descreve o erro.

### <a name="syntax"></a>Sintaxe

```cpp
public:property String^ Message;
```

## <a name="property-value"></a>Valor de propriedade

Nas exceções originadas no Windows Runtime , essa é uma descrição do erro fornecida pelo sistema.

### <a name="remarks"></a>Comentários

No Windows 8, essa propriedade é somente leitura, porque as exceções nessa versão do Windows Runtime são transportadas pela ABI somente como HRESULTS. No Windows 8.1, as informações de exceção mais detalhadas são transportadas pela ABI, e você pode fornecer uma mensagem personalizada que outros componentes podem acessar programaticamente. Para obter mais informações, consulte [exceções (C + + c++ /CX)](../cppcx/exceptions-c-cx.md).

## <a name="see-also"></a>Consulte também

[Namespace Platform](../cppcx/platform-namespace-c-cx.md)