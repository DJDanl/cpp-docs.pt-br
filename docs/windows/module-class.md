---
title: Classe de módulo | Microsoft Docs
ms.custom: ''
ms.date: 10/18/2018
ms.technology:
- cpp-windows
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 2357790e3084c91011f16eb9f1f718948462f898
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50059474"
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

*tipo de módulo*<br/>
Uma combinação de um ou mais [ModuleType](../windows/moduletype-enumeration.md) valores de enumeração.

## <a name="members"></a>Membros

### <a name="protected-classes"></a>Classes protegidas

Nome                                                                                | Descrição
----------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------
[Genericreleasenotifier](../windows/module-genericreleasenotifier-class.md) | Invoca um manipulador de eventos quando o último objeto no módulo atual é liberado. O manipulador de eventos é especificado em um lambda, functor ou ponteiro para função.
[Methodreleasenotifier](../windows/module-methodreleasenotifier-class.md)   | Invoca um manipulador de eventos quando o último objeto no módulo atual é liberado. O manipulador de eventos é especificado por um objeto e seu membro de ponteiro ao método.
[Releasenotifier](../windows/module-releasenotifier-class.md)               | Invoca um manipulador de eventos quando o último objeto em um módulo é liberado.

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
[Module:: decrementobjectcount](#decrementobjectcount)   | Diminui o número de objetos rastreados pelo módulo.
[Module:: getactivationfactory](#getactivationfactory)   | Obtém um alocador de ativação para o módulo.
[Module:: GetClassObject](#getclassobject)               | Recupera um cache de fábricas de classes.
[Module:: getmodule](#getmodule)                         | Cria uma instância de um módulo.
[Module:: getobjectcount](#getobjectcount)               | Recupera o número de objetos gerenciados por esse módulo.
[Module:: incrementobjectcount](#incrementobjectcount)   | Incrementa o número de objetos controlados pelo módulo.
[Module:: registercomobject](#registercomobject)         | Registra os objetos COM um ou mais para que outros aplicativos podem se conectar a eles.
[Module:: registerobjects](#registerobjects)             | Registra os objetos COM ou tempo de execução do Windows para que outros aplicativos podem se conectar a eles.
[Module:: registerwinrtobject](#registerwinrtobject)     | Registra um ou mais objetos de tempo de execução do Windows para que outros aplicativos podem se conectar a eles.
[Module:: Terminate](#terminate)                         | Faz com que todas as fábricas instanciadas pelo módulo para desligar.
[Module:: unregistercomobject](#unregistercomobject)     | Cancela o registro de um ou mais objetos COM, que impede que outros aplicativos se conectem a eles.
[Module:: unregisterobjects](#unregisterobjects)         | Cancela o registro os objetos no módulo especificado para que outros aplicativos não podem se conectar a eles.
[Module:: unregisterwinrtobject](#unregisterwinrtobject) | Cancela o registro de um ou mais objetos de tempo de execução do Windows para que outros aplicativos não podem se conectar a eles.

### <a name="protected-methods"></a>Métodos Protegidos

Nome                      | Descrição
------------------------- | --------------------------------
[Module:: Create](#create) | Cria uma instância de um módulo.

### <a name="protected-data-members"></a>Membros de dados protegidos

Nome                                         | Descrição
-------------------------------------------- | --------------------------------------------------------------------------------------------------------
[Module::objectCount_](#objectcount)         | Mantém o controle de quantas classes foram criadas com o [tornar](../windows/make-function.md) função.
[Module::releaseNotifier_](#releasenotifier) | Contém um ponteiro para um `ReleaseNotifier` objeto.

### <a name="macros"></a>Macros

Nome | Descrição-----| --- [ActivatableClass](../windows/activatableclass-macros.md) |  Popula um cache interno que contém uma fábrica que pode criar uma instância da classe especificada. Essa macro especifica os parâmetros de ID de fábrica e o grupo padrão.
[ActivatableClassWithFactory](../windows/activatableclass-macros.md) | Popula um cache interno que contém uma fábrica que pode criar uma instância da classe especificada. Essa macro permite que você especificar um parâmetro alocador determinado.
[ActivatableClassWithFactoryEx](../windows/activatableclass-macros.md) | Popula um cache interno que contém uma fábrica que pode criar uma instância da classe especificada. Essa macro permite que você especifique parâmetros de ID de grupo e fábrica específica.

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

*retorno de chamada*<br/>
Chamado quando o último objeto de instância do módulo é liberado.

*object*<br/>
O *objeto* e *método* parâmetros são usados em combinação. Aponta para o último objeto de instância quando o último objeto de instância no módulo é liberado.

*Método*<br/>
O *objeto* e *método* parâmetros são usados em combinação. Aponta para o método do último objeto de instância quando o último objeto de instância no módulo é liberado.

### <a name="return-value"></a>Valor de retorno

Referência para o módulo.

## <a name="decrementobjectcount"></a>Module:: decrementobjectcount

Diminui o número de objetos rastreados pelo módulo.

```cpp
virtual long DecrementObjectCount();
```

### <a name="return-value"></a>Valor de retorno

A contagem de antes da operação de decremento.

## <a name="getactivationfactory"></a>Module:: getactivationfactory

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

*ServerName*<br/>
O nome de um subconjunto de fábricas de classe no módulo atual. Especifique o nome do servidor usado na [ActivatableClassWithFactoryEx](../windows/activatableclass-macros.md) macro, ou especificar `nullptr` para obter o nome do servidor padrão.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, o HRESULT retornado pelo GetActivationFactory.

## <a name="getclassobject"></a>Module:: GetClassObject

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

*ServerName*<br/>
O nome do servidor que é especificado em ambos os `ActivatableClassWithFactory`, `ActivatableClassWithFactoryEx`, ou `ActivatableClass` macro; ou `nullptr` para obter o nome do servidor padrão.

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

Use esse método somente para COM, não o tempo de execução do Windows. Esse método expõe apenas `IClassFactory` métodos.

## <a name="getmodule"></a>Module:: getmodule

Cria uma instância de um módulo.

```cpp
static Module& GetModule();
WRL_NOTHROW static Module& GetModule();
```

### <a name="return-value"></a>Valor de retorno

Uma referência a um módulo.

## <a name="getobjectcount"></a>Module:: getobjectcount

Recupera o número de objetos gerenciados por esse módulo.

```cpp
virtual long GetObjectCount() const;
```

### <a name="return-value"></a>Valor de retorno

O número atual de objetos gerenciados por esse módulo.

## <a name="incrementobjectcount"></a>Module:: incrementobjectcount

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

Mantém o controle de quantas classes foram criadas com o [tornar](../windows/make-function.md) função.

```cpp
volatile long objectCount_;
```

## <a name="registercomobject"></a>Module:: registercomobject

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

*ServerName*<br/>
Nome totalmente qualificado de um servidor.

*CLSIDs*<br/>
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

## <a name="registerobjects"></a>Module:: registerobjects

Registra os objetos COM ou tempo de execução do Windows para que outros aplicativos podem se conectar a eles.

```cpp
HRESULT RegisterObjects(
   ModuleBase* module,
   const wchar_t* serverName);
```

### <a name="parameters"></a>Parâmetros

*module*<br/>
Uma matriz de objetos COM ou tempo de execução do Windows.

*ServerName*<br/>
Nome do servidor que criou os objetos.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o motivo pelo qual a operação falhou.

## <a name="registerwinrtobject"></a>Module:: registerwinrtobject

Registra um ou mais objetos de tempo de execução do Windows para que outros aplicativos podem se conectar a eles.

```cpp
HRESULT RegisterWinRTObject(const wchar_t* serverName,
   wchar_t** activatableClassIds,
   WINRT_REGISTRATION_COOKIE* cookie,
   unsigned int count)
```

### <a name="parameters"></a>Parâmetros

*ServerName*<br/>
Um nome que especifica um subconjunto de objetos afetados por essa operação.

*activatableClassIds*<br/>
Uma matriz de ativáveis CLSIDs para registrar.

*Cookie*<br/>
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

## <a name="unregistercomobject"></a>Module:: unregistercomobject

Cancela o registro de um ou mais objetos COM, que impede que outros aplicativos se conectem a eles.

```cpp
virtual HRESULT UnregisterCOMObject(
   const wchar_t* serverName,
   DWORD* cookies,
   unsigned int count
```

### <a name="parameters"></a>Parâmetros

*ServerName*<br/>
(Não usado)

*Cookies*<br/>
Uma matriz de ponteiros para valores que identificam os objetos de classe para cancelar o registro. A matriz foi criada por meio de [RegisterCOMObject](#registercomobject) método.

*count*<br/>
O número de classes para cancelar o registro.

### <a name="return-value"></a>Valor de retorno

S_OK se essa operação for bem-sucedida; Caso contrário, um erro HRESULT que indica o motivo pelo qual a operação falhou.

## <a name="unregisterobjects"></a>Module:: unregisterobjects

Cancela o registro os objetos no módulo especificado para que outros aplicativos não podem se conectar a eles.

```cpp
HRESULT UnregisterObjects(
   ModuleBase* module,
   const wchar_t* serverName);
```

### <a name="parameters"></a>Parâmetros

*module*<br/>
Ponteiro para um módulo.

*ServerName*<br/>
Um nome qualificado que especifica um subconjunto de objetos afetados por essa operação.

### <a name="return-value"></a>Valor de retorno

S_OK se essa operação for bem-sucedida; Caso contrário, um erro HRESULT que indica o motivo pelo qual esta operação falhou.

## <a name="unregisterwinrtobject"></a>Module:: unregisterwinrtobject

Cancela o registro de um ou mais objetos de tempo de execução do Windows para que outros aplicativos não podem se conectar a eles.

```cpp
virtual HRESULT UnregisterWinRTObject(
   unsigned int,
   _Inout_ WINRT_REGISTRATION_COOKIE* cookie
);
```

### <a name="parameters"></a>Parâmetros

*Cookie*<br/>
Um ponteiro para um valor que identifica o objeto de classe cujo registro deve ser revogado.
