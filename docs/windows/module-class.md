---
title: Classe de módulo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module
dev_langs:
- C++
helpviewer_keywords:
- Module class
ms.assetid: dd67e3b8-c2e1-4f53-8c0f-565a140ba649
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a90a7c82706adead4379152b78d36e4dd4b91673
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46416221"
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

|Nome|Descrição|
|----------|-----------------|
|[Classe Module::GenericReleaseNotifier](../windows/module-genericreleasenotifier-class.md)|Invoca um manipulador de eventos quando o último objeto no módulo atual é liberado. O manipulador de eventos é especificado em um lambda, functor ou ponteiro para função.|
|[Classe Module::MethodReleaseNotifier](../windows/module-methodreleasenotifier-class.md)|Invoca um manipulador de eventos quando o último objeto no módulo atual é liberado. O manipulador de eventos é especificado por um objeto e seu membro de ponteiro ao método.|
|[Classe Module::ReleaseNotifier](../windows/module-releasenotifier-class.md)|Invoca um manipulador de eventos quando o último objeto em um módulo é liberado.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Destruidor Module::~Module](../windows/module-tilde-module-destructor.md)|Realiza o desligamento da instância atual do **módulo** classe.|

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[Construtor Module::Module](../windows/module-module-constructor.md)|Inicializa uma nova instância dos **módulo** classe.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Método Module::Create](../windows/module-create-method.md)|Cria uma instância de um módulo.|
|[Método Module::DecrementObjectCount](../windows/module-decrementobjectcount-method.md)|Diminui o número de objetos rastreados pelo módulo.|
|[Método Module::GetActivationFactory](../windows/module-getactivationfactory-method.md)|Obtém um alocador de ativação para o módulo.|
|[Método Module::GetClassObject](../windows/module-getclassobject-method.md)|Recupera um cache de fábricas de classes.|
|[Método Module::GetModule](../windows/module-getmodule-method.md)|Cria uma instância de um módulo.|
|[Método Module::GetObjectCount](../windows/module-getobjectcount-method.md)|Recupera o número de objetos gerenciados por esse módulo.|
|[Método Module::IncrementObjectCount](../windows/module-incrementobjectcount-method.md)|Incrementa o número de objetos controlados pelo módulo.|
|[Método Module::RegisterCOMObject](../windows/module-registercomobject-method.md)|Registra os objetos COM um ou mais para que outros aplicativos podem se conectar a eles.|
|[Método Module::RegisterObjects](../windows/module-registerobjects-method.md)|Registra os objetos COM ou tempo de execução do Windows para que outros aplicativos podem se conectar a eles.|
|[Método Module::RegisterWinRTObject](../windows/module-registerwinrtobject-method.md)|Registra um ou mais objetos de tempo de execução do Windows para que outros aplicativos podem se conectar a eles.|
|[Método Module::Terminate](../windows/module-terminate-method.md)|Faz com que todas as fábricas instanciadas pelo módulo para desligar.|
|[Método Module::UnregisterCOMObject](../windows/module-unregistercomobject-method.md)|Cancela o registro de um ou mais objetos COM, que impede que outros aplicativos se conectem a eles.|
|[Método Module::UnregisterObjects](../windows/module-unregisterobjects-method.md)|Cancela o registro os objetos no módulo especificado para que outros aplicativos não podem se conectar a eles.|
|[Método Module::UnregisterWinRTObject](../windows/module-unregisterwinrtobject-method.md)|Cancela o registro de um ou mais objetos de tempo de execução do Windows para que outros aplicativos não podem se conectar a eles.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[Método Module::Create](../windows/module-create-method.md)|Cria uma instância de um módulo.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[Membro de dados Module::objectCount_](../windows/module-objectcount-data-member.md)|Mantém o controle de quantas classes foram criadas com o [tornar](../windows/make-function.md) função.|
|[Membro de dados Module::releaseNotifier_](../windows/module-releasenotifier-data-member.md)|Contém um ponteiro para um `ReleaseNotifier` objeto.|

### <a name="macros"></a>Macros

|||
|-|-|
|[ActivatableClass](../windows/activatableclass-macros.md)|Popula um cache interno que contém uma fábrica que pode criar uma instância da classe especificada. Essa macro especifica os parâmetros de ID de fábrica e o grupo padrão.|
|[ActivatableClassWithFactory](../windows/activatableclass-macros.md)|Popula um cache interno que contém uma fábrica que pode criar uma instância da classe especificada. Essa macro permite que você especificar um parâmetro alocador determinado.|
|[ActivatableClassWithFactoryEx](../windows/activatableclass-macros.md)|Popula um cache interno que contém uma fábrica que pode criar uma instância da classe especificada. Essa macro permite que você especifique parâmetros de ID de grupo e fábrica específica.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ModuleBase`

`Module`

`Module`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)