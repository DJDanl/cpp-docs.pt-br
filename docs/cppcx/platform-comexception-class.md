---
title: Classe Platform::COMException
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::COMException
- VCCORLIB/Platform::COMException::HResult
- VCCORLIB/Platform::COMException::Message
helpviewer_keywords:
- Platform::COMException Class
ms.assetid: 44fda4e5-574f-4d12-ab5f-4ff3f277448d
ms.openlocfilehash: 1d0d36ec16303d6bdaa5f2344cd5d48fba03c8bf
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79444299"
---
# <a name="platformcomexception-class"></a>Classe Platform::COMException

Representa um ou mais erros COM que ocorrem durante a execução do aplicativo. COMException é a classe base para um conjunto de exceções padrão predefinidas.

## <a name="syntax"></a>Sintaxe

```cpp
public ref class COMException : Exception,    IException,    IPrintable,    IEquatable
```

### <a name="members"></a>Membros

A classe COMException herda da classe Object e das interfaces IException, IPrintable e IEquatable.

COMException também tem os tipos de membros a seguir.

**Construtores**

|{1&gt;Membro&lt;1}|Descrição|
|------------|-----------------|
|[COMException](#ctor)|Inicializa uma nova instância da classe COMException.|

**Métodos**

A classe COMException herda os métodos Equals(), Finalize(), GetHashCode(), GetType(), MemberwiseClose() e ToString() da [Platform::Object Class](../cppcx/platform-object-class.md).

**Propriedades**

A classe COMException agora tem as propriedades a seguir.

|{1&gt;Membro&lt;1}|Descrição|
|------------|-----------------|
|[Exceção:: HResult](#hresult)|O HRESULT que corresponde à exceção.|
|[Exceção:: mensagem](#message)|Mensagem que descreve a exceção.|

## <a name="derived-exceptions"></a>Exceções derivadas

As exceções predefinidas a seguir são derivadas de COMException. Elas diferem de COMException apenas pelo nome, o nome de seu construtor e seu valor HRESULT subjacente.

|{1&gt;Nome&lt;1}|{1&gt;HRESULT subjacente&lt;1}|Descrição|
|----------|------------------------|-----------------|
|{1&gt;COMException&lt;1}|*hresult definido pelo usuário*|{1&gt;Gerada quando um HRESULT não reconhecido é retornado de um chamada de método COM.&lt;1}|
|{1&gt;AccessDeniedException&lt;1}|{1&gt;E_ACCESSDENIED&lt;1}|{1&gt;Gerada quando o acesso a um recurso é negado.&lt;1}|
|{1&gt;ChangedStateException&lt;1}|{1&gt;E_CHANGED_STATE&lt;1}|Gerada quando os métodos de um iterador de coleção ou uma exibição de coleção são chamados após a alteração da coleção pai, invalidando os resultados do método.|
|{1&gt;ClassNotRegisteredException&lt;1}|{1&gt;REGDB_E_CLASSNOTREG&lt;1}|{1&gt;Gerada quando uma classe COM não foi registrada.&lt;1}|
|{1&gt;DisconnectedException&lt;1}|{1&gt;RPC_E_DISCONNECTED&lt;1}|{1&gt;Gerada quando um objeto é desconectado de seus clientes.&lt;1}|
|{1&gt;FailureException&lt;1}|{1&gt;E_FAIL&lt;1}|{1&gt;Gerada quando uma operação falha.&lt;1}|
|{1&gt;InvalidArgumentException&lt;1}|{1&gt;E_INVALIDARG&lt;1}|Lançada quando um dos argumentos fornecidos a um método não é válido.|
|{1&gt;InvalidCastException&lt;1}|{1&gt;E_NOINTERFACE&lt;1}|{1&gt;Gerada quando um tipo não pode ser convertido em outro tipo.&lt;1}|
|{1&gt;NotImplementedException&lt;1}|{1&gt;E_NOTIMPL&lt;1}|{1&gt;Gerada se um método de interface não foi implementado em uma classe.&lt;1}|
|{1&gt;NullReferenceException&lt;1}|{1&gt;E_POINTER&lt;1}|Gerada quando ocorre uma tentativa de cancelar a referência de um objeto de referência nula.|
|{1&gt;OperationCanceledException&lt;1}|{1&gt;E_ABORT&lt;1}|{1&gt;Gerada quando uma operação é anulada.&lt;1}|
|{1&gt;OutOfBoundsException&lt;1}|{1&gt;E_BOUNDS&lt;1}|{1&gt;Gerada quando uma operação tenta acessar dados fora do intervalo válido.&lt;1}|
|{1&gt;OutOfMemoryException&lt;1}|{1&gt;E_OUTOFMEMORY&lt;1}|{1&gt;Gerada quando a memória para concluir a operação é insuficiente.&lt;1}|

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Mínimo de cliente com suporte:** Windows 8

**Mínimo de servidor com suporte:** Windows Server 2012

**Namespace:** Platform

**Metadados:** platform.winmd

## <a name="ctor"></a>Construtor COMException:: COMException

Inicializa uma nova instância da classe COMException.

### <a name="syntax"></a>Sintaxe

```cpp
COMException( int hresult )
```

### <a name="parameters"></a>Parâmetros

*resultado*<br/>
O erro HRESULT que é representado pela exceção.

## <a name="hresult"></a>Propriedade COMException:: HResult

O HRESULT que corresponde à exceção.

### <a name="syntax"></a>Sintaxe

```cpp
public:
    property int HResult { int get();}
```

## <a name="property-value"></a>Valor da propriedade

Um valor HRESULT que especifica o erro.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre como interpretar o valor HRESULT, consulte [estrutura de códigos de erro com](/windows/win32/com/structure-of-com-error-codes).

## <a name="message"></a>Propriedade COMException:: Message

Mensagem que descreve a exceção.

### <a name="syntax"></a>Sintaxe

```cpp
public:property String^ Message {    String^ get();}
```

### <a name="property-value"></a>Valor da propriedade

Uma descrição da exceção.

## <a name="see-also"></a>Consulte também

[Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)
