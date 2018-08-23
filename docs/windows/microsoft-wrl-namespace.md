---
title: 'Namespace Microsoft:: wrl | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
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
dev_langs:
- C++
helpviewer_keywords:
- WRL namespace
ms.assetid: 01118a8f-f564-4859-b87e-9444848585a1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5ffea6dede3bc6bcc7c28b2326299362e78ed2b9
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42599295"
---
# <a name="microsoftwrl-namespace"></a>Namespace Microsoft::WRL

Define os tipos fundamentais que compõem a biblioteca de modelos C++ do Windows Runtime.

## <a name="syntax"></a>Sintaxe

```cpp
namespace Microsoft::WRL;
```

## <a name="members"></a>Membros

### <a name="typedefs"></a>Typedefs

|Nome|Descrição|
|----------|-----------------|
|`InhibitWeakReferencePolicy`|`RuntimeClassFlags<WinRt &#124; InhibitWeakReference>`|

### <a name="classes"></a>Classes

|Nome|Descrição|
|----------|-----------------|
|[Classe ActivationFactory](../windows/activationfactory-class.md)|Permite que um ou mais classes sejam ativadas pelo tempo de execução do Windows.|
|[Classe AsyncBase](../windows/asyncbase-class.md)|Implementa a máquina de estado assíncrona do tempo de execução do Windows.|
|[Classe ClassFactory](../windows/classfactory-class.md)|Implementa a funcionalidade básica do `IClassFactory` interface.|
|[Classe ComPtr](../windows/comptr-class.md)|Cria uma *ponteiro inteligente* tipo que representa a interface especificada pelo parâmetro de modelo. ComPtr automaticamente mantém uma contagem de referência para o ponteiro de interface subjacente e libera a interface quando a contagem de referência chega a zero.|
|[Classe DeferrableEventArgs](../windows/deferrableeventargs-class.md)|Uma classe de modelo usada para os tipos de argumento de evento para adiamentos.|
|[Classe EventSource](../windows/eventsource-class.md)|Representa um evento. `EventSource` funções de membro, adicionar, remover e invocar manipuladores de eventos.|
|[Classe FtmBase](../windows/ftmbase-class.md)|Representa um objeto livre de marshaler.|
|[Classe Module](../windows/module-class.md)|Representa uma coleção de objetos relacionados.|
|[Classe RuntimeClass](../windows/runtimeclass-class.md)|Representa uma classe instanciada que herda o número especificado de interfaces e fornece o tempo de execução do Windows especificado, COM clássico e suporte fraco de referência.|
|[Classe SimpleActivationFactory](../windows/simpleactivationfactory-class.md)|Fornece um mecanismo fundamental para criar um tempo de execução do Windows ou a classe base do COM clássico.|
|[Classe SimpleClassFactory](../windows/simpleclassfactory-class.md)|Fornece um mecanismo fundamental para criar uma classe base.|
|[Classe WeakRef](../windows/weakref-class.md)|Representa uma *referência fraca* que pode ser usado pelo apenas Windows Runtime, com clássico não. Uma referência fraca representa um objeto que pode ou não ser acessível.|

### <a name="structures"></a>Estruturas

|Nome|Descrição|
|----------|-----------------|
|[Estrutura ChainInterfaces](../windows/chaininterfaces-structure.md)|Especifica as funções de verificação e de inicialização que podem ser aplicadas a um conjunto de IDs de interface.|
|[Estrutura CloakedIid](../windows/cloakediid-structure.md)|Indica para o `RuntimeClass`, `Implements` e `ChainInterfaces` que a interface especificada não está acessível na lista de IID de modelos.|
|[Estrutura Implements](../windows/implements-structure.md)|Implementa `QueryInterface` e `GetIid` para interfaces especificadas.|
|[Estrutura MixIn](../windows/mixin-structure.md)|Garante que uma classe de tempo de execução deriva de interfaces do COM clássico, em seguida e as interfaces de tempo de execução do Windows, se houver.|
|[Estrutura RuntimeClassFlags](../windows/runtimeclassflags-structure.md)|Contém o tipo para uma instância de um [RuntimeClass](../windows/runtimeclass-class.md).|

### <a name="enumerations"></a>Enumerações

|Nome|Descrição|
|----------|-----------------|
|[Enumeração AsyncResultType](../windows/asyncresulttype-enumeration.md)|Especifica o tipo de resultado retornado pelo `GetResults()` método.|
|[Enumeração ModuleType](../windows/moduletype-enumeration.md)|Especifica se um módulo deve dar suporte a um servidor em processo ou um servidor fora do processo.|
|[Enumeração RuntimeClassType](../windows/runtimeclasstype-enumeration.md)|Especifica o tipo de [RuntimeClass](../windows/runtimeclass-class.md) instância com suporte.|

### <a name="functions"></a>Funções

|Nome|Descrição|
|----------|-----------------|
|[Função AsWeak](../windows/asweak-function.md)|Recupera uma referência fraca a uma instância especificada.|
|[Função de retorno de chamada](../windows/callback-function-windows-runtime-cpp-template-library.md)|Cria um objeto cuja função de membro é um método de retorno de chamada.|
|[Função CreateActivationFactory](../windows/createactivationfactory-function.md)|Cria uma fábrica que produz instâncias da classe especificada que pode ser ativado pelo tempo de execução do Windows.|
|[Função CreateClassFactory](../windows/createclassfactory-function.md)|Cria uma fábrica que produz instâncias da classe especificada.|
|[Função Make](../windows/make-function.md)|Inicializa a classe de tempo de execução do Windows especificada.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** async.h, client.h, corewrappers. h, Event. h, ftm.h, Implements. h, internal.h, module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)