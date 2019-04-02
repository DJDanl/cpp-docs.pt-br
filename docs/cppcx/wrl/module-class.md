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
ms.openlocfilehash: db3eb123382ac70f6198d094c5eb3fe44d3bbcd9
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58783892"
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

### <a name="parameters"></a>Parâmetros

*moduleType*<br/>
Uma combinação de um ou mais [ModuleType](moduletype-enumeration.md) valores de enumeração.

## <a name="members"></a>Membros

### <a name="protected-classes"></a>Classes protegidas

Nome                                                                                | Descrição
----------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------
[Module::GenericReleaseNotifier](module-genericreleasenotifier-class.md) | Invoca um manipulador de eventos quando o último objeto no módulo atual é liberado. O manipulador de eventos é especificado em um lambda, functor ou ponteiro para função.
[Module::MethodReleaseNotifier](module-methodreleasenotifier-class.md)   | Invoca um manipulador de eventos quando o último objeto no módulo atual é liberado. O manipulador de eventos é especificado por um objeto e seu membro de ponteiro ao método.
[Module::ReleaseNotifier](module-releasenotifier-class.md)               | Invoca um manipulador de eventos quando o último objeto em um módulo é liberado.

### <a name="public-constructors"></a>Construtores públicos

Nome                             | Descrição
-------------------------------- | -----------------------------------------------------------
[Módulo:: ~ Module](#tilde-module) | A instância atual do realiza o desligamento de `Module` classe.

### <a name="protected-constructors"></a>Construtores Protegidos

Nome                      | Descrição
------------------------- | ---------------------------------------------------
[Module:: Module](#module) | Inicializa uma nova instância da classe `Module`.

### <a name="public-methods"></a>Métodos públicos

Nome                                                    | Descrição
------------------------------------------------------- | --------------------------------------------------------------------------------------------------
[Module:: Create](#create)                               | Cria uma instância de um módulo.
[Module::DecrementObjectCount](#decrementobjectcount)   | Diminui o número de objetos rastreados pelo módulo.
[Module::GetActivationFactory](#getactivationfactory)   | Obtém um alocador de ativação para o módulo.
[Module::GetClassObject](#getclassobject)               | Recupera um cache de fábricas de classes.
[Module::GetModule](#getmodule)                         | Cria uma instância de um módulo.
[Module::GetObjectCount](#getobjectcount)               | Recupera o número de objetos gerenciados por esse módulo.
[Module::IncrementObjectCount](#incrementobjectcount)   | Incrementa o número de objetos controlados pelo módulo.
[Module::RegisterCOMObject](#registercomobject)         | Registra os objetos COM um ou mais para que outros aplicativos podem se conectar a eles.
[Module::RegisterObjects](#registerobjects)             | Registra os objetos COM ou tempo de execução do Windows para que outros aplicativos podem se conectar a eles.
[Module::RegisterWinRTObject](#registerwinrtobject)     | Registra um ou mais objetos de tempo de execução do Windows para que outros aplicativos podem se conectar a eles.
[Module:: Terminate](#terminate)                         | Faz com que todas as fábricas instanciadas pelo módulo para desligar.
[Module::UnregisterCOMObject](#unregistercomobject)     | Cancela o registro de um ou mais objetos COM, que impede que outros aplicativos se conectem a eles.
[Module::UnregisterObjects](#unregisterobjects)         | Cancela o registro os objetos no módulo especificado para que outros aplicativos não podem se conectar a eles.
[Module::UnregisterWinRTObject](#unregisterwinrtobject) | Cancela o registro de um ou mais objetos de tempo de execução do Windows para que outros aplicativos não podem se conectar a eles.

### <a name="protected-methods"></a>Métodos Protegidos

Nome                      | Descrição
------------------------- | --------------------------------
[Module:: Create](#create) | Cria uma instância de um módulo.

### <a name="protected-data-members"></a>Membros de dados protegidos

Nome                                         | Descrição
-------------------------------------------- | --------------------------------------------------------------------------------------------------------
[Module::objectCount_](#objectcount)         | Mantém o controle de quantas classes foram criadas com o [tornar](make-function.md) função.
[Module::releaseNotifier_](#releasenotifier) | Contém um ponteiro para um `ReleaseNotifier` objeto.

### <a name="macros"></a>Macros

Nome | Descrição-----| --- [ActivatableClass](activatableclass-macros.md) |  Popula um cache interno que contém uma fábrica que pode criar uma instância da classe especificada. Essa macro especifica os parâmetros de ID de fábrica e o grupo padrão.
[ActivatableClassWithFactory](activatableclass-macros.md) | Popula um cache interno que contém uma fábrica que pode criar uma instância da classe especificada. Essa macro permite que você especificar um parâmetro alocador determinado.
[ActivatableClassWithFactoryEx](activatableclass-macros.md) | Popula um cache interno que contém uma fábrica que pode criar uma instância da classe especificada. Essa macro permite que você especifique parâmetros de ID de grupo e fábrica específica.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ModuleBase`

`Module`

`Module`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="tilde-module"></a>Módulo:: ~ Module

A instância atual do realiza o desligamento de `Module` classe.

```cpp
virtual ~Module();
```

## <a name="create"></a>Module:: Create

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

### <a name="parameters"></a>Parâmetros

*T*<br/>
Tipo de módulo.

*callback*<br/>
Chamado quando o último objeto de instância do módulo é liberado.

*object*<br/>
O *objeto* e *método* parâmetros são usados em combinação. Aponta para o último objeto de instância quando o último objeto de instância no módulo é liberado.

*Método*<br/>
O *objeto* e *método* parâmetros são usados em combinação. Aponta para o método do último objeto de instância quando o último objeto de instância no módulo é liberado.

### <a name="return-value"></a>Valor de retorno

Referência para o módulo.

## <a name="decrementobjectcount"></a>Module::DecrementObjectCount

Diminui o número de objetos rastreados pelo módulo.

```cpp
virtual long DecrementObjectCount();
```

### <a name="return-value"></a>Valor de retorno

A contagem de antes da operação de decremento.

## <a name="getactivationfactory"></a>Module::GetActivationFactory

Obtém um alocador de ativação para o módulo.

```cpp
WRL_NOTHROW HRESULT GetActivationFactory(
   _In_ HSTRING pActivatibleClassId,
   _Deref_out_ IActivationFactory **ppIFactory,
   wchar_t* serverName = nullptr
);
```

### <a name="parameters"></a>Parâmetros

*pActivatibleClassId*<br/>
IID de uma classe de tempo de execução.

*ppIFactory*<br/>
O IActivationFactory para a classe de tempo de execução especificado.

*serverName*<br/>
O nome de um subconjunto de fábricas de classe no módulo atual. Especifique o nome do servidor usado na [ActivatableClassWithFactoryEx](activatableclass-macros.md) macro, ou especificar `nullptr` para obter o nome do servidor padrão.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, o HRESULT retornado pelo GetActivationFactory.

## <a name="getclassobject"></a>Module::GetClassObject

Recupera um cache de fábricas de classes.

```cpp
HRESULT GetClassObject(
   REFCLSID clsid,
   REFIID riid,
   _Deref_out_ void **ppv,
   wchar_t* serverName = nullptr
);
```

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
ID de classe.

*riid*<br/>
ID de interface que você solicitar.

*ppv*<br/>
Ponteiro para o objeto retornado.

*serverName*<br/>
O nome do servidor que é especificado em ambos os `ActivatableClassWithFactory`, `ActivatableClassWithFactoryEx`, ou `ActivatableClass` macro; ou `nullptr` para obter o nome do servidor padrão.

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

Use esse método somente para COM, não o tempo de execução do Windows. Esse método expõe apenas `IClassFactory` métodos.

## <a name="getmodule"></a>Module::GetModule

Cria uma instância de um módulo.

```cpp
static Module& GetModule();
WRL_NOTHROW static Module& GetModule();
```

### <a name="return-value"></a>Valor de retorno

Uma referência a um módulo.

## <a name="getobjectcount"></a>Module::GetObjectCount

Recupera o número de objetos gerenciados por esse módulo.

```cpp
virtual long GetObjectCount() const;
```

### <a name="return-value"></a>Valor de retorno

O número atual de objetos gerenciados por esse módulo.

## <a name="incrementobjectcount"></a>Module::IncrementObjectCount

Incrementa o número de objetos controlados pelo módulo.

```cpp
virtual long IncrementObjectCount();
```

### <a name="return-value"></a>Valor de retorno

A contagem de antes da operação de incremento.

## <a name="module"></a>Module:: Module

Inicializa uma nova instância da classe `Module`.

```cpp
Module();
```

### <a name="remarks"></a>Comentários

Este construtor é protegido e não pode ser chamado com o `new` palavra-chave. Em vez disso, chame o [Module:: getmodule](#getmodule) ou [Module:: Create](#create).

## <a name="objectcount"></a>Module::objectCount_

Mantém o controle de quantas classes foram criadas com o [tornar](make-function.md) função.

```cpp
volatile long objectCount_;
```

## <a name="registercomobject"></a>Module::RegisterCOMObject

Registra os objetos COM um ou mais para que outros aplicativos podem se conectar a eles.

```cpp
WRL_NOTHROW virtual HRESULT RegisterCOMObject(
   const wchar_t* serverName,
   IID* clsids,
   IClassFactory** factories,
   DWORD* cookies,
   unsigned int count);
```

### <a name="parameters"></a>Parâmetros

*serverName*<br/>
Nome totalmente qualificado de um servidor.

*clsids*<br/>
Uma matriz de CLSIDs para registrar.

*fábricas*<br/>
Uma matriz de interfaces IUnknown dos objetos de classe cuja disponibilidade está sendo publicada.

*Cookies*<br/>
Quando a operação for concluída, uma matriz de ponteiros para valores que identificam a classe de objetos que foram registrados. Esses valores são usados mais tarde revoga o registro.

*count*<br/>
O número de CLSIDs para registrar.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT como CO_E_OBJISREG que indica o motivo pelo qual a operação falhou.

### <a name="remarks"></a>Comentários

Os objetos COM são registrados com o enumerador CLSCTX_LOCAL_SERVER da enumeração CLSCTX.

O tipo de conexão para os objetos registrados é especificado por uma combinação do atual *comflag* parâmetro de modelo e o enumerador REGCLS_SUSPENDED da enumeração REGCLS.

## <a name="registerobjects"></a>Module::RegisterObjects

Registra os objetos COM ou tempo de execução do Windows para que outros aplicativos podem se conectar a eles.

```cpp
HRESULT RegisterObjects(
   ModuleBase* module,
   const wchar_t* serverName);
```

### <a name="parameters"></a>Parâmetros

*module*<br/>
Uma matriz de objetos COM ou tempo de execução do Windows.

*serverName*<br/>
Nome do servidor que criou os objetos.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o motivo pelo qual a operação falhou.

## <a name="registerwinrtobject"></a>Module::RegisterWinRTObject

Registra um ou mais objetos de tempo de execução do Windows para que outros aplicativos podem se conectar a eles.

```cpp
HRESULT RegisterWinRTObject(const wchar_t* serverName,
   wchar_t** activatableClassIds,
   WINRT_REGISTRATION_COOKIE* cookie,
   unsigned int count)
```

### <a name="parameters"></a>Parâmetros

*serverName*<br/>
Um nome que especifica um subconjunto de objetos afetados por essa operação.

*activatableClassIds*<br/>
Uma matriz de ativáveis CLSIDs para registrar.

*cookie*<br/>
Um valor que identifica os objetos de classe que foram registrados. Esse valor é usado posteriormente para revoga o registro.

*count*<br/>
O número de objetos para registrar.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um erro HRESULT, como CO_E_OBJISREG que indica o motivo pelo qual a operação falhou.

## <a name="releasenotifier"></a>Module::releaseNotifier_

Contém um ponteiro para um `ReleaseNotifier` objeto.

```cpp
ReleaseNotifier *releaseNotifier_;
```

## <a name="terminate"></a>Module:: Terminate

Faz com que todas as fábricas instanciadas pelo módulo para desligar.

```cpp
void Terminate();
```

### <a name="remarks"></a>Comentários

Libera as fábricas no cache.

## <a name="unregistercomobject"></a>Module::UnregisterCOMObject

Cancela o registro de um ou mais objetos COM, que impede que outros aplicativos se conectem a eles.

```cpp
virtual HRESULT UnregisterCOMObject(
   const wchar_t* serverName,
   DWORD* cookies,
   unsigned int count
```

### <a name="parameters"></a>Parâmetros

*serverName*<br/>
(Não usado)

*Cookies*<br/>
Uma matriz de ponteiros para valores que identificam os objetos de classe para cancelar o registro. A matriz foi criada por meio de [RegisterCOMObject](#registercomobject) método.

*count*<br/>
O número de classes para cancelar o registro.

### <a name="return-value"></a>Valor de retorno

S_OK se essa operação for bem-sucedida; Caso contrário, um erro HRESULT que indica o motivo pelo qual a operação falhou.

## <a name="unregisterobjects"></a>Module::UnregisterObjects

Cancela o registro os objetos no módulo especificado para que outros aplicativos não podem se conectar a eles.

```cpp
HRESULT UnregisterObjects(
   ModuleBase* module,
   const wchar_t* serverName);
```

### <a name="parameters"></a>Parâmetros

*module*<br/>
Ponteiro para um módulo.

*serverName*<br/>
Um nome qualificado que especifica um subconjunto de objetos afetados por essa operação.

### <a name="return-value"></a>Valor de retorno

S_OK se essa operação for bem-sucedida; Caso contrário, um erro HRESULT que indica o motivo pelo qual esta operação falhou.

## <a name="unregisterwinrtobject"></a>Module::UnregisterWinRTObject

Cancela o registro de um ou mais objetos de tempo de execução do Windows para que outros aplicativos não podem se conectar a eles.

```cpp
virtual HRESULT UnregisterWinRTObject(
   unsigned int,
   _Inout_ WINRT_REGISTRATION_COOKIE* cookie
);
```

### <a name="parameters"></a>Parâmetros

*cookie*<br/>
Um ponteiro para um valor que identifica o objeto de classe cujo registro deve ser revogado.
