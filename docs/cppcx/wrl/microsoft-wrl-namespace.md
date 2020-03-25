---
title: Namespace Microsoft::WRL
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL
- module/Microsoft::WRL
- async/Microsoft::WRL
- internal/Microsoft::WRL
- event/Microsoft::WRL
- ftm/Microsoft::WRL
- client/Microsoft::WRL
- corewrappers/Microsoft::WRL
helpviewer_keywords:
- WRL namespace
ms.assetid: 01118a8f-f564-4859-b87e-9444848585a1
ms.openlocfilehash: c92251dacbfa17e8f1ac0cbdc41aa9b06118ac91
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213766"
---
# <a name="microsoftwrl-namespace"></a>Namespace Microsoft::WRL

Define os tipos fundamentais que compõem a Windows Runtime C++ biblioteca de modelos.

## <a name="syntax"></a>Sintaxe

```cpp
namespace Microsoft::WRL;
```

## <a name="members"></a>Membros

### <a name="typedefs"></a>Typedefs

|Nome|DESCRIÇÃO|
|----------|-----------------|
|`InhibitWeakReferencePolicy`|`RuntimeClassFlags<WinRt | InhibitWeakReference>`|

### <a name="classes"></a>Classes

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Classe ActivationFactory](activationfactory-class.md)|Permite que uma ou mais classes sejam ativadas pelo Windows Runtime.|
|[Classe AsyncBase](asyncbase-class.md)|Implementa o Windows Runtime máquina de estado assíncrono.|
|[Classe ClassFactory](classfactory-class.md)|Implementa a funcionalidade básica da interface `IClassFactory`.|
|[Classe ComPtr](comptr-class.md)|Cria um tipo de *ponteiro inteligente* que representa a interface especificada pelo parâmetro de modelo. O ComPtr mantém automaticamente uma contagem de referência para o ponteiro de interface subjacente e libera a interface quando a contagem de referência chega a zero.|
|[Classe DeferrableEventArgs](deferrableeventargs-class.md)|Uma classe de modelo usada para os tipos de argumento de evento para adiamentos.|
|[EventSource Class](eventsource-class.md)|Representa um evento. `EventSource` funções membro adicionam, removem e chamam manipuladores de eventos.|
|[Classe FtmBase](ftmbase-class.md)|Representa um objeto de marshaling com thread livre.|
|[Classe Module](module-class.md)|Representa uma coleção de objetos relacionados.|
|[Classe RuntimeClass](runtimeclass-class.md)|Representa uma classe instanciada que herda o número especificado de interfaces e fornece o suporte especificado Windows Runtime, COM clássico e de referência fraca.|
|[Classe SimpleActivationFactory](simpleactivationfactory-class.md)|Fornece um mecanismo fundamental para criar uma classe base COM Windows Runtime ou clássica.|
|[Classe SimpleClassFactory](simpleclassfactory-class.md)|Fornece um mecanismo fundamental para criar uma classe base.|
|[Classe WeakRef](weakref-class.md)|Representa uma *referência fraca* que pode ser usada apenas pelo Windows Runtime, não pelo com clássico. Uma referência fraca representa um objeto que pode ou não estar acessível.|

### <a name="structures"></a>Estruturas

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Estrutura ChainInterfaces](chaininterfaces-structure.md)|Especifica as funções de verificação e inicialização que podem ser aplicadas a um conjunto de IDs de interface.|
|[Estrutura CloakedIid](cloakediid-structure.md)|Indica para os modelos de `RuntimeClass`, `Implements` e `ChainInterfaces` que a interface especificada não está acessível na lista de IID.|
|[Estrutura Implements](implements-structure.md)|Implementa `QueryInterface` e `GetIid` para as interfaces especificadas.|
|[Estrutura MixIn](mixin-structure.md)|Garante que uma classe de tempo de execução derive de interfaces Windows Runtime, se houver, e as interfaces COM clássicas.|
|[Estrutura RuntimeClassFlags](runtimeclassflags-structure.md)|Contém o tipo de uma instância de um [RuntimeClass](runtimeclass-class.md).|

### <a name="enumerations"></a>Enumerações

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Enumeração AsyncResultType](asyncresulttype-enumeration.md)|Especifica o tipo de resultado retornado pelo método `GetResults()`.|
|[Enumeração ModuleType](moduletype-enumeration.md)|Especifica se um módulo deve dar suporte a um servidor em processo ou a um servidor fora do processo.|
|[Enumeração RuntimeClassType](runtimeclasstype-enumeration.md)|Especifica o tipo de instância de [RuntimeClass](runtimeclass-class.md) com suporte.|

### <a name="functions"></a>Funções

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Função AsWeak](asweak-function.md)|Recupera uma referência fraca a uma instância especificada.|
|[Função de retorno de chamada (WRL)](callback-function-wrl.md)|Cria um objeto cuja função de membro é um método de retorno de chamada.|
|[Função CreateActivationFactory](createactivationfactory-function.md)|Cria uma fábrica que produz instâncias da classe especificada que pode ser ativada pelo Windows Runtime.|
|[Função CreateClassFactory](createclassfactory-function.md)|Cria uma fábrica que produz instâncias da classe especificada.|
|[Função Make](make-function.md)|Inicializa a classe de Windows Runtime especificada.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Async. h, Client. h, corewrappers. h, Event. h, FTM. h, Implements. h, Internal. h, Module. h

**Namespace:** Microsoft:: WRL

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL::Wrappers](microsoft-wrl-wrappers-namespace.md)
