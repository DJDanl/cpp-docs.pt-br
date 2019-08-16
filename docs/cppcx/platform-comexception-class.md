---
title: Classe Platform::COMException
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::COMException
- VCCORLIB/Platform::Exception::HResult
- VCCORLIB/Platform::Exception::Message
helpviewer_keywords:
- Platform::COMException Class
ms.assetid: 44fda4e5-574f-4d12-ab5f-4ff3f277448d
ms.openlocfilehash: eb6f3e0e4860687d0d47294e11b7741294abac20
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69500541"
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

|Membro|Descrição|
|------------|-----------------|
|[COMException](#ctor)|Inicializa uma nova instância da classe COMException.|

**Métodos**

A classe COMException herda os métodos Equals(), Finalize(), GetHashCode(), GetType(), MemberwiseClose() e ToString() da [Platform::Object Class](../cppcx/platform-object-class.md).

**Propriedades**

A classe COMException agora tem as propriedades a seguir.

|Membro|Descrição|
|------------|-----------------|
|[Exception::HResult](#hresult)|O HRESULT que corresponde à exceção.|
|[Exception::Message](#message)|Mensagem que descreve a exceção.|

## <a name="derived-exceptions"></a>Exceções derivadas

As exceções predefinidas a seguir são derivadas de COMException. Elas diferem de COMException apenas pelo nome, o nome de seu construtor e seu valor HRESULT subjacente.

|Nome|HRESULT subjacente|Descrição|
|----------|------------------------|-----------------|
|COMException|*hresult definido pelo usuário*|Gerada quando um HRESULT não reconhecido é retornado de um chamada de método COM.|
|AccessDeniedException|E_ACCESSDENIED|Gerada quando o acesso a um recurso é negado.|
|ChangedStateException|E_CHANGED_STATE|Gerada quando os métodos de um iterador de coleção ou uma exibição de coleção são chamados após a alteração da coleção pai, invalidando os resultados do método.|
|ClassNotRegisteredException|REGDB_E_CLASSNOTREG|Gerada quando uma classe COM não foi registrada.|
|DisconnectedException|RPC_E_DISCONNECTED|Gerada quando um objeto é desconectado de seus clientes.|
|FailureException|E_FAIL|Gerada quando uma operação falha.|
|InvalidArgumentException|E_INVALIDARG|Lançada quando um dos argumentos fornecidos a um método não é válido.|
|InvalidCastException|E_NOINTERFACE|Gerada quando um tipo não pode ser convertido em outro tipo.|
|NotImplementedException|E_NOTIMPL|Gerada se um método de interface não foi implementado em uma classe.|
|NullReferenceException|E_POINTER|Gerada quando ocorre uma tentativa de cancelar a referência de um objeto de referência nula.|
|OperationCanceledException|E_ABORT|Gerada quando uma operação é anulada.|
|OutOfBoundsException|E_BOUNDS|Gerada quando uma operação tenta acessar dados fora do intervalo válido.|
|OutOfMemoryException|E_OUTOFMEMORY|Gerada quando a memória para concluir a operação é insuficiente.|

### <a name="requirements"></a>Requisitos

**Mínimo de cliente com suporte:** Windows 8

**Mínimo de servidor com suporte:** Windows Server 2012

**Namespace:** Plataforma

**Metadados:** platform.winmd

## <a name="ctor"></a>Construtor COMException:: COMException

Inicializa uma nova instância da classe COMException.

### <a name="syntax"></a>Sintaxe

```cpp
COMException( int hresult )
```

### <a name="parameters"></a>Parâmetros

*hresult*<br/>
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
