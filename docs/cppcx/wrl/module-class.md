---
title: Classe de módulo
ms.date: 10/18/2018
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module
- module/Microsoft::WRL::Module::Create
- module/Microsoft::WRL::Module::DecrementObjectCount
- module/Microsoft::WRL::Module::GetActivationFactory
- module/Microsoft::WRL::Module::GetClassObject
- module/Microsoft::WRL::Module::GetModule
- module/Microsoft::WRL::Module::GetObjectCount
- module/Microsoft::WRL::Module::IncrementObjectCount
- module/Microsoft::WRL::Module::Module
- module/Microsoft::WRL::Module::objectCount_Data
- module/Microsoft::WRL::Module::RegisterCOMObject
- module/Microsoft::WRL::Module::RegisterObjects
- module/Microsoft::WRL::Module::RegisterWinRTObject
- module/Microsoft::WRL::Module::releaseNotifier_
- module/Microsoft::WRL::Module::Terminate
- module/Microsoft::WRL::Module::~Module
- module/Microsoft::WRL::Module::UnregisterCOMObject
- module/Microsoft::WRL::Module::UnregisterObjects
- module/Microsoft::WRL::Module::UnregisterWinRTObject
helpviewer_keywords:
- Microsoft::WRL::Module class
- Microsoft::WRL::Module::Create method
- Microsoft::WRL::Module::DecrementObjectCount method
- Microsoft::WRL::Module::GetActivationFactory method
- Microsoft::WRL::Module::GetClassObject method
- Microsoft::WRL::Module::GetModule method
- Microsoft::WRL::Module::GetObjectCount method
- Microsoft::WRL::Module::IncrementObjectCount method
- Microsoft::WRL::Module::Module, constructor
- Microsoft::WRL::Module::objectCount_ data member
- Microsoft::WRL::Module::RegisterCOMObject method
- Microsoft::WRL::Module::RegisterObjects method
- Microsoft::WRL::Module::RegisterWinRTObject method
- Microsoft::WRL::Module::releaseNotifier_ data member
- Microsoft::WRL::Module::Terminate method
- Microsoft::WRL::Module::~Module, destructor
- Microsoft::WRL::Module::UnregisterCOMObject method
- Microsoft::WRL::Module::UnregisterObjects method
- Microsoft::WRL::Module::UnregisterWinRTObject method
ms.assetid: dd67e3b8-c2e1-4f53-8c0f-565a140ba649
ms.openlocfilehash: f7930247c979c111a7f4798e35ebe7aa95209f37
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225742"
---
# <a name="module-class"></a>Classe de módulo

Representa uma coleção de objetos relacionados.

## <a name="syntax"></a>Sintaxe

```cpp
template<ModuleType moduleType>
class Module;

template<>
class Module<InProc> : public Details::ModuleBase;

template<>
class Module<OutOfProc> : public Module<InProc>;
```

### <a name="parameters"></a>parâmetros

*moduleType*<br/>
Uma combinação de um ou mais valores de enumeração do tipo de [módulo](moduletype-enumeration.md) .

## <a name="members"></a>Membros

### <a name="protected-classes"></a>Classes protegidas

Nome                                                                                | Descrição
----------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------
[Módulo:: GenericReleaseNotifier](module-genericreleasenotifier-class.md) | Invoca um manipulador de eventos quando o último objeto no módulo atual é liberado. O manipulador de eventos é especificado por em um lambda, functor ou ponteiro para função.
[Módulo:: MethodReleaseNotifier](module-methodreleasenotifier-class.md)   | Invoca um manipulador de eventos quando o último objeto no módulo atual é liberado. O manipulador de eventos é especificado por um objeto e seu membro de ponteiro para um método.
[Módulo:: ReleaseNotifier](module-releasenotifier-class.md)               | Invoca um manipulador de eventos quando o último objeto em um módulo é liberado.

### <a name="public-constructors"></a>Construtores públicos

Nome                             | Descrição
-------------------------------- | -----------------------------------------------------------
[Módulo:: ~ module](#tilde-module) | Desinicializa a instância atual da `Module` classe.

### <a name="protected-constructors"></a>Construtores Protegidos

Nome                      | Descrição
------------------------- | ---------------------------------------------------
[Módulo:: módulo](#module) | Inicializa uma nova instância da classe `Module`.

### <a name="public-methods"></a>Métodos públicos

Nome                                                    | Descrição
------------------------------------------------------- | --------------------------------------------------------------------------------------------------
[Módulo:: criar](#create)                               | Cria uma instância de um módulo.
[Módulo::D ecrementObjectCount](#decrementobjectcount)   | Decrementa o número de objetos rastreados pelo módulo.
[Módulo:: GetActivationFactory](#getactivationfactory)   | Obtém um alocador de ativação para o módulo.
[Módulo:: GetClassObject](#getclassobject)               | Recupera um cache de fábricas de classe.
[Módulo:: GetModule](#getmodule)                         | Cria uma instância de um módulo.
[Módulo:: GetObjectCount](#getobjectcount)               | Recupera o número de objetos gerenciados por este módulo.
[Módulo:: IncrementObjectCount](#incrementobjectcount)   | Incrementa o número de objetos rastreados pelo módulo.
[Módulo:: RegisterCOMObject](#registercomobject)         | Registra um ou mais objetos COM para que outros aplicativos possam se conectar a eles.
[Módulo:: RegisterObjects](#registerobjects)             | Registra objetos COM ou Windows Runtime para que outros aplicativos possam se conectar a eles.
[Módulo:: RegisterWinRTObject](#registerwinrtobject)     | Registra um ou mais objetos Windows Runtime para que outros aplicativos possam se conectar a eles.
[Módulo:: encerrar](#terminate)                         | Faz com que todas as fábricas instanciadas pelo módulo sejam desligadas.
[Módulo:: UnregisterCOMObject](#unregistercomobject)     | Cancela o registro de um ou mais objetos COM, o que impede que outros aplicativos se conectem a eles.
[Módulo:: UnregisterObjects](#unregisterobjects)         | Cancela o registro dos objetos no módulo especificado para que outros aplicativos não possam se conectar a eles.
[Módulo:: UnregisterWinRTObject](#unregisterwinrtobject) | Cancela o registro de um ou mais objetos Windows Runtime para que outros aplicativos não possam se conectar a eles.

### <a name="protected-methods"></a>Métodos Protegidos

Nome                      | Descrição
------------------------- | --------------------------------
[Módulo:: criar](#create) | Cria uma instância de um módulo.

### <a name="protected-data-members"></a>Membros de Dados Protegidos

Nome                                         | Descrição
-------------------------------------------- | --------------------------------------------------------------------------------------------------------
[Módulo:: objectCount_](#objectcount)         | Controla quantas classes foram criadas com a função [Make](make-function.md) .
[Módulo:: releaseNotifier_](#releasenotifier) | Mantém um ponteiro para um `ReleaseNotifier` objeto.

### <a name="macros"></a>Macros

Nome                                                                   | Descrição
---------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
[ActivatableClass](activatableclass-macros.md)              | Popula um cache interno que contém uma fábrica que pode criar uma instância da classe especificada. Essa macro especifica os parâmetros padrão de fábrica e ID de grupo.
[ActivatableClassWithFactory](activatableclass-macros.md)   | Popula um cache interno que contém uma fábrica que pode criar uma instância da classe especificada. Essa macro permite que você especifique um determinado parâmetro de fábrica.
[ActivatableClassWithFactoryEx](activatableclass-macros.md) | Popula um cache interno que contém uma fábrica que pode criar uma instância da classe especificada. Essa macro permite que você especifique parâmetros de ID de grupo e de fábrica específicos.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ModuleBase`

`Module`

`Module`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Module. h

**Namespace:** Microsoft:: WRL

## <a name="modulemodule"></a><a name="tilde-module"></a>Módulo:: ~ module

Desinicializa a instância atual da `Module` classe.

```cpp
virtual ~Module();
```

## <a name="modulecreate"></a><a name="create"></a>Módulo:: criar

Cria uma instância de um módulo.

```cpp
WRL_NOTHROW static Module& Create();
template<typename T>
WRL_NOTHROW static Module& Create(
   T callback
);
template<typename T>
WRL_NOTHROW static Module& Create(
   _In_ T* object,
   _In_ void (T::* method)()
);
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Tipo de módulo.

*retorno de chamada*<br/>
Chamado quando o último objeto de instância do módulo é liberado.

*object*<br/>
Os parâmetros *Object* e *Method* são usados em combinação. Aponta para o último objeto de instância quando o último objeto de instância no módulo é liberado.

*forma*<br/>
Os parâmetros *Object* e *Method* são usados em combinação. Aponta para o método do último objeto de instância quando o último objeto de instância no módulo é liberado.

### <a name="return-value"></a>Valor retornado

Referência ao módulo.

## <a name="moduledecrementobjectcount"></a><a name="decrementobjectcount"></a>Módulo::D ecrementObjectCount

Decrementa o número de objetos rastreados pelo módulo.

```cpp
virtual long DecrementObjectCount();
```

### <a name="return-value"></a>Valor retornado

A contagem antes da operação de diminuição.

## <a name="modulegetactivationfactory"></a><a name="getactivationfactory"></a>Módulo:: GetActivationFactory

Obtém um alocador de ativação para o módulo.

```cpp
WRL_NOTHROW HRESULT GetActivationFactory(
   _In_ HSTRING pActivatibleClassId,
   _Deref_out_ IActivationFactory **ppIFactory,
   wchar_t* serverName = nullptr
);
```

### <a name="parameters"></a>parâmetros

*pActivatibleClassId*<br/>
IID de uma classe de tempo de execução.

*ppIFactory*<br/>
O IActivationFactory para a classe de tempo de execução especificada.

*serverName*<br/>
O nome de um subconjunto de fábricas de classe no módulo atual. Especifique o nome do servidor usado na macro [ActivatableClassWithFactoryEx](activatableclass-macros.md) ou especifique **`nullptr`** para obter o nome do servidor padrão.

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, o HRESULT retornado por GetActivationFactory.

## <a name="modulegetclassobject"></a><a name="getclassobject"></a>Módulo:: GetClassObject

Recupera um cache de fábricas de classe.

```cpp
HRESULT GetClassObject(
   REFCLSID clsid,
   REFIID riid,
   _Deref_out_ void **ppv,
   wchar_t* serverName = nullptr
);
```

### <a name="parameters"></a>parâmetros

*clsid*<br/>
ID da classe.

*riid*<br/>
ID de interface solicitada.

*ppv*<br/>
Ponteiro para o objeto retornado.

*serverName*<br/>
O nome do servidor que é especificado na `ActivatableClassWithFactory` macro, `ActivatableClassWithFactoryEx` ou `ActivatableClass` ; ou **`nullptr`** para obter o nome do servidor padrão.

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

Use este método somente para COM, não para o Windows Runtime. Esse método expõe apenas `IClassFactory` métodos.

## <a name="modulegetmodule"></a><a name="getmodule"></a>Módulo:: GetModule

Cria uma instância de um módulo.

```cpp
static Module& GetModule();
WRL_NOTHROW static Module& GetModule();
```

### <a name="return-value"></a>Valor retornado

Uma referência a um módulo.

## <a name="modulegetobjectcount"></a><a name="getobjectcount"></a>Módulo:: GetObjectCount

Recupera o número de objetos gerenciados por este módulo.

```cpp
virtual long GetObjectCount() const;
```

### <a name="return-value"></a>Valor retornado

O número atual de objetos gerenciados por este módulo.

## <a name="moduleincrementobjectcount"></a><a name="incrementobjectcount"></a>Módulo:: IncrementObjectCount

Incrementa o número de objetos rastreados pelo módulo.

```cpp
virtual long IncrementObjectCount();
```

### <a name="return-value"></a>Valor retornado

A contagem antes da operação de incremento.

## <a name="modulemodule"></a><a name="module"></a>Módulo:: módulo

Inicializa uma nova instância da classe `Module`.

```cpp
Module();
```

### <a name="remarks"></a>Comentários

Este construtor é protegido e não pode ser chamado com a **`new`** palavra-chave. Em vez disso, chame um [módulo:: GetModule](#getmodule) ou [módulo:: Create](#create).

## <a name="moduleobjectcount_"></a><a name="objectcount"></a>Módulo:: objectCount_

Controla quantas classes foram criadas com a função [Make](make-function.md) .

```cpp
volatile long objectCount_;
```

## <a name="moduleregistercomobject"></a><a name="registercomobject"></a>Módulo:: RegisterCOMObject

Registra um ou mais objetos COM para que outros aplicativos possam se conectar a eles.

```cpp
WRL_NOTHROW virtual HRESULT RegisterCOMObject(
   const wchar_t* serverName,
   IID* clsids,
   IClassFactory** factories,
   DWORD* cookies,
   unsigned int count);
```

### <a name="parameters"></a>parâmetros

*serverName*<br/>
Nome totalmente qualificado de um servidor.

*CLSIDs*<br/>
Uma matriz de CLSIDs para registrar.

*factories*<br/>
Uma matriz de interfaces IUnknown dos objetos de classe cuja disponibilidade está sendo publicada.

*arar*<br/>
Quando a operação é concluída, uma matriz de ponteiros para valores que identificam os objetos de classe que foram registrados. Esses valores são usados posteriormente para revogar o registro.

*contagem*<br/>
O número de CLSIDs a serem registrados.

### <a name="return-value"></a>Valor retornado

S_OK se sucedidas; caso contrário, um HRESULT como CO_E_OBJISREG que indica o motivo pelo qual a operação falhou.

### <a name="remarks"></a>Comentários

Os objetos COM são registrados com o enumerador CLSCTX_LOCAL_SERVER da enumeração CLSCTX.

O tipo de conexão com os objetos registrados é especificado por uma combinação do parâmetro de modelo *comsinalizador* atual e o enumerador REGCLS_SUSPENDED da enumeração REGCLS.

## <a name="moduleregisterobjects"></a><a name="registerobjects"></a>Módulo:: RegisterObjects

Registra objetos COM ou Windows Runtime para que outros aplicativos possam se conectar a eles.

```cpp
HRESULT RegisterObjects(
   ModuleBase* module,
   const wchar_t* serverName);
```

### <a name="parameters"></a>parâmetros

*modulo*<br/>
Uma matriz de objetos COM ou Windows Runtime.

*serverName*<br/>
Nome do servidor que criou os objetos.

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, um HRESULT que indica o motivo da falha na operação.

## <a name="moduleregisterwinrtobject"></a><a name="registerwinrtobject"></a>Módulo:: RegisterWinRTObject

Registra um ou mais objetos Windows Runtime para que outros aplicativos possam se conectar a eles.

```cpp
HRESULT RegisterWinRTObject(const wchar_t* serverName,
   wchar_t** activatableClassIds,
   WINRT_REGISTRATION_COOKIE* cookie,
   unsigned int count)
```

### <a name="parameters"></a>parâmetros

*serverName*<br/>
Um nome que especifica um subconjunto de objetos afetados por esta operação.

*activatableClassIds*<br/>
Uma matriz de CLSIDs ativáveis para registrar.

*cookie*<br/>
Um valor que identifica os objetos de classe que foram registrados. Esse valor é usado posteriormente para revogar o registro.

*contagem*<br/>
O número de objetos a serem registrados.

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, um erro HRESULT, como CO_E_OBJISREG, que indica o motivo da falha na operação.

## <a name="modulereleasenotifier_"></a><a name="releasenotifier"></a>Módulo:: releaseNotifier_

Mantém um ponteiro para um `ReleaseNotifier` objeto.

```cpp
ReleaseNotifier *releaseNotifier_;
```

## <a name="moduleterminate"></a><a name="terminate"></a>Módulo:: encerrar

Faz com que todas as fábricas instanciadas pelo módulo sejam desligadas.

```cpp
void Terminate();
```

### <a name="remarks"></a>Comentários

Libera as fábricas no cache.

## <a name="moduleunregistercomobject"></a><a name="unregistercomobject"></a>Módulo:: UnregisterCOMObject

Cancela o registro de um ou mais objetos COM, o que impede que outros aplicativos se conectem a eles.

```cpp
virtual HRESULT UnregisterCOMObject(
   const wchar_t* serverName,
   DWORD* cookies,
   unsigned int count
```

### <a name="parameters"></a>parâmetros

*serverName*<br/>
Não utilizado

*arar*<br/>
Uma matriz de ponteiros para valores que identificam os objetos de classe cujo registro deve ser cancelado. A matriz foi criada pelo método [RegisterCOMObject](#registercomobject) .

*contagem*<br/>
O número de classes para cancelar o registro.

### <a name="return-value"></a>Valor retornado

S_OK se esta operação for bem-sucedida; caso contrário, um erro HRESULT indica o motivo da falha da operação.

## <a name="moduleunregisterobjects"></a><a name="unregisterobjects"></a>Módulo:: UnregisterObjects

Cancela o registro dos objetos no módulo especificado para que outros aplicativos não possam se conectar a eles.

```cpp
HRESULT UnregisterObjects(
   ModuleBase* module,
   const wchar_t* serverName);
```

### <a name="parameters"></a>parâmetros

*modulo*<br/>
Ponteiro para um módulo.

*serverName*<br/>
Um nome qualificado que especifica um subconjunto de objetos afetados por essa operação.

### <a name="return-value"></a>Valor retornado

S_OK se esta operação for bem-sucedida; caso contrário, um erro HRESULT indica o motivo pelo qual essa operação falhou.

## <a name="moduleunregisterwinrtobject"></a><a name="unregisterwinrtobject"></a>Módulo:: UnregisterWinRTObject

Cancela o registro de um ou mais objetos Windows Runtime para que outros aplicativos não possam se conectar a eles.

```cpp
virtual HRESULT UnregisterWinRTObject(
   unsigned int,
   _Inout_ WINRT_REGISTRATION_COOKIE* cookie
);
```

### <a name="parameters"></a>parâmetros

*cookie*<br/>
Um ponteiro para um valor que identifica o objeto de classe cujo registro deve ser revogado.
