---
title: Namespace Microsoft::WRL::Details | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
ms.assetid: d71fe149-d804-4c6f-961d-43fe21ef8630
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 095d355ae26faf447b54a99437c843322efe5cb9
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42611742"
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
|[Classe ComPtrRef](../windows/comptrref-class.md)|Representa uma referência a um objeto do tipo ComPtr\<T >.|
|[Classe ComPtrRefBase](../windows/comptrrefbase-class.md)|Representa a classe base para o [ComPtrRef](../windows/comptrref-class.md) classe.|
|[Classe DontUseNewUseMake](../windows/dontusenewusemake-class.md)|Impeça o uso de operador **novos** em `RuntimeClass`. Consequentemente, você deve usar o [tornar função](../windows/make-function.md) em vez disso.|
|[Classe EventTargetArray](../windows/eventtargetarray-class.md)|Representa uma matriz de manipuladores de eventos.|
|[Classe MakeAllocator](../windows/makeallocator-class.md)|Aloca memória para uma classe ativável, com ou sem suporte fraco de referência.|
|[Classe ModuleBase](../windows/modulebase-class.md)|Representa a classe base do [módulo](../windows/module-class.md) classes.|
|[Classe RemoveIUnknown](../windows/removeiunknown-class.md)|Cria um tipo que é equivalente a um `IUnknown`-tipo com base, mas tem não virtual `QueryInterface`, `AddRef`, e `Release` métodos.|
|[Classe WeakReference](../windows/weakreference-class1.md)|Representa uma *referência fraca* que pode ser usado com o tempo de execução do Windows ou o com clássico. Uma referência fraca representa um objeto que pode ou não ser acessível.|

### <a name="structures"></a>Estruturas

|Nome|Descrição|
|----------|-----------------|
|[Estrutura ArgTraits](../windows/argtraits-structure.md)|Declara um delegado especificado de interface e uma função de membro anônimo que tem um número especificado de parâmetros.|
|[Estrutura ArgTraitsHelper](../windows/argtraitshelper-structure.md)|Ajuda a definir as características comuns de argumentos do delegado.|
|[Estrutura BoolStruct](../windows/boolstruct-structure.md)|Define se um `ComPtr` está gerenciando o tempo de vida do objeto de uma interface. `BoolStruct` é usado internamente pelo [BoolType()](../windows/comptr-operator-microsoft-wrl-details-booltype-operator.md) operador.|
|[Estrutura CreatorMap](../windows/creatormap-structure.md)|Contém informações sobre como inicializar, registrar e cancelar o registro de objetos.|
|[Estrutura DerefHelper](../windows/derefhelper-structure.md)|Representar um ponteiro cancelado para o `T*` parâmetro de modelo.|
|[Estrutura EnableIf](../windows/enableif-structure.md)|Define um membro de dados do tipo especificado pelo segundo parâmetro de modelo se o primeiro parâmetro de modelo é avaliado como **verdadeira**.|
|[Estrutura FactoryCache](../windows/factorycache-structure.md)|Contém o local de uma fábrica de classes e um valor que identifica um objeto de classe de tempo de execução do Windows ou COM registrados.|
|[Estrutura ImplementsBase](../windows/implementsbase-structure.md)|Usado para validar os tipos de parâmetro de modelo no [implementa estrutura](../windows/implements-structure.md).|
|[Estrutura ImplementsHelper](../windows/implementshelper-structure.md)|Ajuda a implementar o [implementa](../windows/implements-structure.md) estrutura.|
|[Estrutura InterfaceList](../windows/interfacelist-structure.md)|Usado para criar uma lista recursiva de interfaces.|
|[Estrutura InterfaceListHelper](../windows/interfacelisthelper-structure.md)|Cria um `InterfaceList` tipo por recursivamente aplicando os argumentos de parâmetro de modelo especificado.|
|[Estrutura InterfaceTraits](../windows/interfacetraits-structure.md)|Características comuns de implementa uma interface.|
|[Estrutura InvokeHelper](../windows/invokehelper-structure.md)|Fornece uma implementação do `Invoke()` método com base no tipo de argumentos e o número especificado.|
|[Estrutura IsBaseOfStrict](../windows/isbaseofstrict-structure.md)|Testa se um tipo é a base de outro.|
|[Estrutura IsSame](../windows/issame-structure.md)|Testes se um tipo especificado é igual a outro tipo especificado.|
|[Estrutura Nil](../windows/nil-structure.md)|Usado para indicar um parâmetro de modelo não especificado, opcional.|
|[Estrutura RemoveReference](../windows/removereference-structure.md)|Retira a característica de referência ou uma referência de rvalue do parâmetro de modelo de classe especificada.|
|[Estrutura RuntimeClassBase](../windows/runtimeclassbase-structure.md)|Usado para detectar `RuntimeClass` no [tornar](../windows/make-function.md) função.|
|[Estrutura RuntimeClassBaseT](../windows/runtimeclassbaset-structure.md)|Fornece métodos auxiliares para `QueryInterface` operações e ao obter IDs de interface.|
|[Estrutura VerifyInheritanceHelper](../windows/verifyinheritancehelper-structure.md)|Testa se uma interface é derivada de outra interface.|
|[Estrutura VerifyInterfaceHelper](../windows/verifyinterfacehelper-structure.md)|Verifica se a interface especificada pelo parâmetro de modelo atende a determinados requisitos.|

### <a name="enumerations"></a>Enumerações

|Nome|Descrição|
|----------|-----------------|
|[Enumeração AsyncStatusInternal](../windows/asyncstatusinternal-enumeration.md)|Especifica um mapeamento entre enumerações internos para o estado das operações assíncronas e o `Windows::Foundation::AsyncStatus` enumeração.|

### <a name="functions"></a>Funções

|Nome|Descrição|
|----------|-----------------|
|[Função ActivationFactoryCallback](../windows/activationfactorycallback-function.md)|Obtém o alocador de ativação para a ID de ativação especificado.|
|[Função Move](../windows/move-function.md)|Move o argumento especificado de um local para outro.|
|[Função RaiseException](../windows/raiseexception-function.md)|Gera uma exceção no thread de chamada.|
|[Função Swap (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](../windows/swap-function-windows-runtime-cpp-template-library.md)|Troca os valores dos dois argumentos especificados.|
|[Função TerminateMap](../windows/terminatemap-function.md)|Desliga as fábricas de classes no módulo especificado.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** async.h, client.h, corewrappers. h, Event. h, ftm.h, Implements. h, internal.h, module.h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)  
[Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)