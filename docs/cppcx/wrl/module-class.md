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
ms.openlocfilehash: afd2edacefdf5d62b50a03c0a8c37f13ee5d9c9f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371312"
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
Uma combinação de um ou mais valores de enumeração [ModuleType.](moduletype-enumeration.md)

## <a name="members"></a>Membros

### <a name="protected-classes"></a>Classes protegidas

Nome                                                                                | Descrição
----------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------
[Módulo::GenericReleaseNotifier](module-genericreleasenotifier-class.md) | Invoca um manipulador de eventos quando o último objeto no módulo atual é liberado. O manipulador de eventos é especificado por um lambda, functor ou pointer-to-function.
[Módulo::MethodReleaseNotifier](module-methodreleasenotifier-class.md)   | Invoca um manipulador de eventos quando o último objeto no módulo atual é liberado. O manipulador de eventos é especificado por um objeto e seu membro de ponteiro para um método.
[Módulo::ReleaseNotifier](module-releasenotifier-class.md)               | Invoca um manipulador de eventos quando o último objeto em um módulo é liberado.

### <a name="public-constructors"></a>Construtores públicos

Nome                             | Descrição
-------------------------------- | -----------------------------------------------------------
[Módulo::~Módulo](#tilde-module) | Desinicializa a instância `Module` atual da classe.

### <a name="protected-constructors"></a>Construtores Protegidos

Nome                      | Descrição
------------------------- | ---------------------------------------------------
[Módulo::Módulo](#module) | Inicia uma nova instância da classe `Module`.

### <a name="public-methods"></a>Métodos públicos

Nome                                                    | Descrição
------------------------------------------------------- | --------------------------------------------------------------------------------------------------
[Módulo::Criar](#create)                               | Cria uma instância de um módulo.
[Módulo::DecrementObjectCount](#decrementobjectcount)   | Diminui o número de objetos rastreados pelo módulo.
[Módulo::GetActivationFactory](#getactivationfactory)   | Tem uma fábrica de ativação para o módulo.
[Módulo::GetClassObject](#getclassobject)               | Recupera um esconderijo de fábricas de classe.
[Módulo::GetModule](#getmodule)                         | Cria uma instância de um módulo.
[Módulo::GetObjectCount](#getobjectcount)               | Recupera o número de objetos gerenciados por este módulo.
[Módulo::IncrementObjectCount](#incrementobjectcount)   | Aumenta o número de objetos rastreados pelo módulo.
[Módulo::RegisterCOMObject](#registercomobject)         | Registra um ou mais objetos COM para que outros aplicativos possam se conectar a eles.
[Módulo::Registrarobjetos](#registerobjects)             | Registra objetos COM ou Windows Runtime para que outros aplicativos possam se conectar a eles.
[Módulo::RegisterWinRTObject](#registerwinrtobject)     | Registra um ou mais objetos do Windows Runtime para que outros aplicativos possam se conectar a eles.
[Módulo::Terminar](#terminate)                         | Faz com que todas as fábricas instanciadas pelo módulo fechem.
[Módulo::DesregistrarCOMObject](#unregistercomobject)     | Desregistra um ou mais objetos COM, o que impede que outros aplicativos se conectem a eles.
[Módulo::Não registrarobjetos](#unregisterobjects)         | Desregistra os objetos no módulo especificado para que outros aplicativos não possam se conectar a eles.
[Módulo::DesregistrarMarcaRRTObject](#unregisterwinrtobject) | Desregistra um ou mais objetos do Windows Runtime para que outros aplicativos não possam se conectar a eles.

### <a name="protected-methods"></a>Métodos Protegidos

Nome                      | Descrição
------------------------- | --------------------------------
[Módulo::Criar](#create) | Cria uma instância de um módulo.

### <a name="protected-data-members"></a>Membros de Dados Protegidos

Nome                                         | Descrição
-------------------------------------------- | --------------------------------------------------------------------------------------------------------
[Módulo::objectCount_](#objectcount)         | Mantém o controle de quantas classes foram criadas com a função [Fazer.](make-function.md)
[Módulo::releaseNotifier_](#releasenotifier) | Segura um ponteiro `ReleaseNotifier` para um objeto.

### <a name="macros"></a>Macros

Nome                                                                   | Descrição
---------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
[ActivatableClass](activatableclass-macros.md)              | Preenche um cache interno que contém uma fábrica que pode criar uma instância da classe especificada. Esta macro especifica parâmetros padrão de fábrica e iD de grupo.
[ActivatableClassWithFactory](activatableclass-macros.md)   | Preenche um cache interno que contém uma fábrica que pode criar uma instância da classe especificada. Esta macro permite especificar um parâmetro de fábrica específico.
[ActivatableClassWithFactoryEx](activatableclass-macros.md) | Preenche um cache interno que contém uma fábrica que pode criar uma instância da classe especificada. Essa macro permite especificar parâmetros específicos de id de fábrica e grupo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ModuleBase`

`Module`

`Module`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Espaço de nome:** Microsoft::WRL

## <a name="modulemodule"></a><a name="tilde-module"></a>Módulo::~Módulo

Desinicializa a instância `Module` atual da classe.

```cpp
virtual ~Module();
```

## <a name="modulecreate"></a><a name="create"></a>Módulo::Criar

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
Chamado quando o objeto de última instância do módulo é liberado.

*Objeto*<br/>
Os parâmetros *de objeto* e *método* são usados em combinação. Aponta para o objeto de última instância quando o objeto de última instância no módulo é liberado.

*Método*<br/>
Os parâmetros *de objeto* e *método* são usados em combinação. Aponta para o método do objeto de última instância quando o objeto de última instância no módulo é liberado.

### <a name="return-value"></a>Valor retornado

Referência ao módulo.

## <a name="moduledecrementobjectcount"></a><a name="decrementobjectcount"></a>Módulo::DecrementObjectCount

Diminui o número de objetos rastreados pelo módulo.

```cpp
virtual long DecrementObjectCount();
```

### <a name="return-value"></a>Valor retornado

A contagem antes da operação de decrésia.

## <a name="modulegetactivationfactory"></a><a name="getactivationfactory"></a>Módulo::GetActivationFactory

Tem uma fábrica de ativação para o módulo.

```cpp
WRL_NOTHROW HRESULT GetActivationFactory(
   _In_ HSTRING pActivatibleClassId,
   _Deref_out_ IActivationFactory **ppIFactory,
   wchar_t* serverName = nullptr
);
```

### <a name="parameters"></a>Parâmetros

*pActivatibleClassId*<br/>
IID de uma aula de tempo de execução.

*ppIFactory*<br/>
A IActivationFactory para a classe de tempo de execução especificada.

*Servername*<br/>
O nome de um subconjunto de fábricas de classe no módulo atual. Especifique o nome do servidor usado na macro `nullptr` [ActivatableClassWithFactoryEx](activatableclass-macros.md) ou especifique para obter o nome padrão do servidor.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, o HRESULT retornou por GetActivationFactory.

## <a name="modulegetclassobject"></a><a name="getclassobject"></a>Módulo::GetClassObject

Retreives um cache de fábricas de classe.

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

*Ppv*<br/>
Ponteiro para objeto devolvido.

*Servername*<br/>
O nome do servidor especificado `ActivatableClassWithFactory` `ActivatableClassWithFactoryEx`no `ActivatableClass` , ou macro; ou `nullptr` para obter o nome padrão do servidor.

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

Use este método apenas para COM, não para o Tempo de Execução do Windows. Este método expõe `IClassFactory` apenas métodos.

## <a name="modulegetmodule"></a><a name="getmodule"></a>Módulo::GetModule

Cria uma instância de um módulo.

```cpp
static Module& GetModule();
WRL_NOTHROW static Module& GetModule();
```

### <a name="return-value"></a>Valor retornado

Uma referência a um módulo.

## <a name="modulegetobjectcount"></a><a name="getobjectcount"></a>Módulo::GetObjectCount

Recupera o número de objetos gerenciados por este módulo.

```cpp
virtual long GetObjectCount() const;
```

### <a name="return-value"></a>Valor retornado

O número atual de objetos gerenciados por este módulo.

## <a name="moduleincrementobjectcount"></a><a name="incrementobjectcount"></a>Módulo::IncrementObjectCount

Aumenta o número de objetos rastreados pelo módulo.

```cpp
virtual long IncrementObjectCount();
```

### <a name="return-value"></a>Valor retornado

A contagem antes da operação de incremento.

## <a name="modulemodule"></a><a name="module"></a>Módulo::Módulo

Inicia uma nova instância da classe `Module`.

```cpp
Module();
```

### <a name="remarks"></a>Comentários

Este construtor está protegido e não `new` pode ser chamado com a palavra-chave. Em vez disso, ligue para [módulo::GetModule](#getmodule) ou [Module::Create](#create).

## <a name="moduleobjectcount_"></a><a name="objectcount"></a>Módulo::objectCount_

Mantém o controle de quantas classes foram criadas com a função [Fazer.](make-function.md)

```cpp
volatile long objectCount_;
```

## <a name="moduleregistercomobject"></a><a name="registercomobject"></a>Módulo::RegisterCOMObject

Registra um ou mais objetos COM para que outros aplicativos possam se conectar a eles.

```cpp
WRL_NOTHROW virtual HRESULT RegisterCOMObject(
   const wchar_t* serverName,
   IID* clsids,
   IClassFactory** factories,
   DWORD* cookies,
   unsigned int count);
```

### <a name="parameters"></a>Parâmetros

*Servername*<br/>
Nome totalmente qualificado de um servidor.

*Clsids*<br/>
Uma matriz de CLSIDs para registrar.

*Fábricas*<br/>
Uma matriz de interfaces IUnknown dos objetos de classe cuja disponibilidade está sendo publicada.

*Cookies*<br/>
Quando a operação é concluída, uma matriz de ponteiros para valores que identificam os objetos de classe que foram registrados. Esses valores são posteriormente usados para revogar o registro.

*contagem*<br/>
O número de CLSIDs para registrar.

### <a name="return-value"></a>Valor retornado

S_OK se sucessofu; caso contrário, um HRESULT como CO_E_OBJISREG que indica a razão pela qual a operação falhou.

### <a name="remarks"></a>Comentários

Os objetos COM estão registrados no enumerador CLSCTX_LOCAL_SERVER da enumeração CLSCTX.

O tipo de conexão com os objetos registrados é especificado por uma combinação do parâmetro atual do modelo *de bandeira* e do enumerador REGCLS_SUSPENDED da enumeração REGCLS.

## <a name="moduleregisterobjects"></a><a name="registerobjects"></a>Módulo::Registrarobjetos

Registra objetos COM ou Windows Runtime para que outros aplicativos possam se conectar a eles.

```cpp
HRESULT RegisterObjects(
   ModuleBase* module,
   const wchar_t* serverName);
```

### <a name="parameters"></a>Parâmetros

*Módulo*<br/>
Uma matriz de objetos COM ou Windows Runtime.

*Servername*<br/>
Nome do servidor que criou os objetos.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que indica a razão pela qual a operação falhou.

## <a name="moduleregisterwinrtobject"></a><a name="registerwinrtobject"></a>Módulo::RegisterWinRTObject

Registra um ou mais objetos do Windows Runtime para que outros aplicativos possam se conectar a eles.

```cpp
HRESULT RegisterWinRTObject(const wchar_t* serverName,
   wchar_t** activatableClassIds,
   WINRT_REGISTRATION_COOKIE* cookie,
   unsigned int count)
```

### <a name="parameters"></a>Parâmetros

*Servername*<br/>
Um nome que especifica um subconjunto de objetos afetados por esta operação.

*activatableClassIds*<br/>
Uma matriz de CLSIDs activáveis para registrar.

*Cookie*<br/>
Um valor que identifica os objetos de classe que foram registrados. Esse valor é usado posteriormente para revogar o registro.

*contagem*<br/>
O número de objetos para registrar.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um erro HRESULT como CO_E_OBJISREG que indica a razão pela qual a operação falhou.

## <a name="modulereleasenotifier_"></a><a name="releasenotifier"></a>Módulo::releaseNotifier_

Segura um ponteiro `ReleaseNotifier` para um objeto.

```cpp
ReleaseNotifier *releaseNotifier_;
```

## <a name="moduleterminate"></a><a name="terminate"></a>Módulo::Terminar

Faz com que todas as fábricas instanciadas pelo módulo fechem.

```cpp
void Terminate();
```

### <a name="remarks"></a>Comentários

Libera as fábricas no cache.

## <a name="moduleunregistercomobject"></a><a name="unregistercomobject"></a>Módulo::DesregistrarCOMObject

Desregistra um ou mais objetos COM, o que impede que outros aplicativos se conectem a eles.

```cpp
virtual HRESULT UnregisterCOMObject(
   const wchar_t* serverName,
   DWORD* cookies,
   unsigned int count
```

### <a name="parameters"></a>Parâmetros

*Servername*<br/>
(Não utilizado)

*Cookies*<br/>
Uma matriz de ponteiros para valores que identificam os objetos de classe não registrados. A matriz foi criada pelo método [RegisterCOMObject.](#registercomobject)

*contagem*<br/>
O número de aulas para cancelar o registro.

### <a name="return-value"></a>Valor retornado

S_OK se esta operação for bem sucedida; caso contrário, um erro HRESULT que indica a razão pela qual a operação falhou.

## <a name="moduleunregisterobjects"></a><a name="unregisterobjects"></a>Módulo::Não registrarobjetos

Desregistra os objetos no módulo especificado para que outros aplicativos não possam se conectar a eles.

```cpp
HRESULT UnregisterObjects(
   ModuleBase* module,
   const wchar_t* serverName);
```

### <a name="parameters"></a>Parâmetros

*Módulo*<br/>
Ponteiro para um módulo.

*Servername*<br/>
Um nome de qualificação que especifica um subconjunto de objetos afetados por esta operação.

### <a name="return-value"></a>Valor retornado

S_OK se esta operação for bem sucedida; caso contrário, um erro HRESULT que indica a razão pela qual esta operação falhou.

## <a name="moduleunregisterwinrtobject"></a><a name="unregisterwinrtobject"></a>Módulo::DesregistrarMarcaRRTObject

Desregistra um ou mais objetos do Windows Runtime para que outros aplicativos não possam se conectar a eles.

```cpp
virtual HRESULT UnregisterWinRTObject(
   unsigned int,
   _Inout_ WINRT_REGISTRATION_COOKIE* cookie
);
```

### <a name="parameters"></a>Parâmetros

*Cookie*<br/>
Um ponteiro para um valor que identifica o objeto de classe cujo registro deve ser revogado.
