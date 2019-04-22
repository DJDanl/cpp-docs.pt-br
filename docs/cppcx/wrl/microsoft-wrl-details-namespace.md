---
title: Namespace Microsoft::WRL::Details
ms.date: 11/04/2016
ms.topic: reference
ms.assetid: d71fe149-d804-4c6f-961d-43fe21ef8630
ms.openlocfilehash: fce6e620600164e73d3708d98d8a7fa979e8ab42
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59027462"
---
# <a name="microsoftwrldetails-namespace"></a>Namespace Microsoft::WRL::Details

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
namespace Microsoft::WRL::Details;
```

## <a name="members"></a>Membros

### <a name="classes"></a>Classes

|Nome|Descrição|
|----------|-----------------|
|[Classe ComPtrRef](comptrref-class.md)|Representa uma referência a um objeto do tipo ComPtr\<T >.|
|[Classe ComPtrRefBase](comptrrefbase-class.md)|Representa a classe base para o [ComPtrRef](comptrref-class.md) classe.|
|[Classe DontUseNewUseMake](dontusenewusemake-class.md)|Impeça o uso de operador `new` em `RuntimeClass`. Consequentemente, você deve usar o [tornar função](make-function.md) em vez disso.|
|[Classe EventTargetArray](eventtargetarray-class.md)|Representa uma matriz de manipuladores de eventos.|
|[Classe MakeAllocator](makeallocator-class.md)|Aloca memória para uma classe ativável, com ou sem suporte fraco de referência.|
|[Classe ModuleBase](modulebase-class.md)|Representa a classe base do [módulo](module-class.md) classes.|
|[Classe RemoveIUnknown](removeiunknown-class.md)|Cria um tipo que é equivalente a um `IUnknown`-tipo com base, mas tem não virtual `QueryInterface`, `AddRef`, e `Release` métodos.|
|[Classe WeakReference](weakreference-class.md)|Representa uma *referência fraca* que pode ser usado com o tempo de execução do Windows ou o com clássico. Uma referência fraca representa um objeto que pode ou não ser acessível.|

### <a name="structures"></a>Estruturas

|Nome|Descrição|
|----------|-----------------|
|[Estrutura ArgTraits](argtraits-structure.md)|Declara um delegado especificado de interface e uma função de membro anônimo que tem um número especificado de parâmetros.|
|[Estrutura ArgTraitsHelper](argtraitshelper-structure.md)|Ajuda a definir as características comuns de argumentos do delegado.|
|[Estrutura BoolStruct](boolstruct-structure.md)|Define se um `ComPtr` está gerenciando o tempo de vida do objeto de uma interface. `BoolStruct` é usado internamente pelo [BoolType()](comptr-class.md#operator-microsoft-wrl-details-booltype) operador.|
|[Estrutura CreatorMap](creatormap-structure.md)|Contém informações sobre como inicializar, registrar e cancelar o registro de objetos.|
|[Estrutura DerefHelper](derefhelper-structure.md)|Representar um ponteiro cancelado para o `T*` parâmetro de modelo.|
|[Estrutura EnableIf](enableif-structure.md)|Define um membro de dados do tipo especificado pelo segundo parâmetro de modelo se o primeiro parâmetro de modelo é avaliado como `true`.|
|[Estrutura FactoryCache](factorycache-structure.md)|Contém o local de uma fábrica de classes e um valor que identifica um objeto de classe de tempo de execução do Windows ou COM registrados.|
|[Estrutura ImplementsBase](implementsbase-structure.md)|Usado para validar os tipos de parâmetro de modelo no [implementa estrutura](implements-structure.md).|
|[Estrutura ImplementsHelper](implementshelper-structure.md)|Ajuda a implementar o [implementa](implements-structure.md) estrutura.|
|[Estrutura InterfaceList](interfacelist-structure.md)|Usado para criar uma lista recursiva de interfaces.|
|[Estrutura InterfaceListHelper](interfacelisthelper-structure.md)|Cria um `InterfaceList` tipo por recursivamente aplicando os argumentos de parâmetro de modelo especificado.|
|[Estrutura InterfaceTraits](interfacetraits-structure.md)|Características comuns de implementa uma interface.|
|[Estrutura InvokeHelper](invokehelper-structure.md)|Fornece uma implementação do `Invoke()` método com base no tipo de argumentos e o número especificado.|
|[Estrutura IsBaseOfStrict](isbaseofstrict-structure.md)|Testa se um tipo é a base de outro.|
|[Estrutura IsSame](issame-structure.md)|Testes se um tipo especificado é igual a outro tipo especificado.|
|[Estrutura Nil](nil-structure.md)|Usado para indicar um parâmetro de modelo não especificado, opcional.|
|[Estrutura RemoveReference](removereference-structure.md)|Retira a característica de referência ou uma referência de rvalue do parâmetro de modelo de classe especificada.|
|[Estrutura RuntimeClassBase](runtimeclassbase-structure.md)|Usado para detectar `RuntimeClass` no [tornar](make-function.md) função.|
|[Estrutura RuntimeClassBaseT](runtimeclassbaset-structure.md)|Fornece métodos auxiliares para `QueryInterface` operações e ao obter IDs de interface.|
|[Estrutura VerifyInheritanceHelper](verifyinheritancehelper-structure.md)|Testa se uma interface é derivada de outra interface.|
|[Estrutura VerifyInterfaceHelper](verifyinterfacehelper-structure.md)|Verifica se a interface especificada pelo parâmetro de modelo atende a determinados requisitos.|

### <a name="enumerations"></a>Enumerações

|Nome|Descrição|
|----------|-----------------|
|[Enumeração AsyncStatusInternal](asyncstatusinternal-enumeration.md)|Especifica um mapeamento entre enumerações internos para o estado das operações assíncronas e o `Windows::Foundation::AsyncStatus` enumeração.|

### <a name="functions"></a>Funções

|Nome|Descrição|
|----------|-----------------|
|[Função ActivationFactoryCallback](activationfactorycallback-function.md)|Obtém o alocador de ativação para a ID de ativação especificado.|
|[Função Move](move-function.md)|Move o argumento especificado de um local para outro.|
|[Função RaiseException](raiseexception-function.md)|Gera uma exceção no thread de chamada.|
|[Função swap (WRL)](swap-function-wrl.md)|Troca os valores dos dois argumentos especificados.|
|[Função TerminateMap](terminatemap-function.md)|Desliga as fábricas de classes no módulo especificado.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** async.h, client.h, corewrappers. h, Event. h, ftm.h, Implements. h, internal.h, module.h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)<br/>
[Namespace Microsoft::WRL::Wrappers](microsoft-wrl-wrappers-namespace.md)