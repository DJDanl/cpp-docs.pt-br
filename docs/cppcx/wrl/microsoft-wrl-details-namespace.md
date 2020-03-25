---
title: Namespace Microsoft::WRL::Details
ms.date: 11/04/2016
ms.topic: reference
ms.assetid: d71fe149-d804-4c6f-961d-43fe21ef8630
ms.openlocfilehash: 4e8d2e5a2c7e6655674c4e965cd7222d930dff9a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213779"
---
# <a name="microsoftwrldetails-namespace"></a>Namespace Microsoft::WRL::Details

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
namespace Microsoft::WRL::Details;
```

## <a name="members"></a>Membros

### <a name="classes"></a>Classes

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Classe ComPtrRef](comptrref-class.md)|Representa uma referência a um objeto do tipo ComPtr\<T >.|
|[Classe ComPtrRefBase](comptrrefbase-class.md)|Representa a classe base para a classe [ComPtrRef](comptrref-class.md) .|
|[Classe DontUseNewUseMake](dontusenewusemake-class.md)|Impede o uso de `new` de operador em `RuntimeClass`. Consequentemente, você deve usar a [função Make](make-function.md) em vez disso.|
|[Classe EventTargetArray](eventtargetarray-class.md)|Representa uma matriz de manipuladores de eventos.|
|[Classe MakeAllocator](makeallocator-class.md)|Aloca memória para uma classe ativável, com ou sem suporte de referência fraca.|
|[Classe ModuleBase](modulebase-class.md)|Representa a classe base das classes do [módulo](module-class.md) .|
|[Classe RemoveIUnknown](removeiunknown-class.md)|Torna um tipo equivalente a um tipo baseado em `IUnknown`, mas tem métodos não virtuais `QueryInterface`, `AddRef`e `Release`.|
|[Classe WeakReference](weakreference-class.md)|Representa uma *referência fraca* que pode ser usada com o Windows Runtime ou o com clássico. Uma referência fraca representa um objeto que pode ou não estar acessível.|

### <a name="structures"></a>Estruturas

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Estrutura ArgTraits](argtraits-structure.md)|Declara uma interface de delegação especificada e uma função de membro anônimo que tem um número especificado de parâmetros.|
|[Estrutura ArgTraitsHelper](argtraitshelper-structure.md)|Ajuda a definir características comuns de argumentos delegados.|
|[Estrutura BoolStruct](boolstruct-structure.md)|Define se um `ComPtr` está gerenciando o tempo de vida do objeto de uma interface. `BoolStruct` é usado internamente pelo operador [booltype ()](comptr-class.md#operator-microsoft-wrl-details-booltype) .|
|[Estrutura CreatorMap](creatormap-structure.md)|Contém informações sobre como inicializar, registrar e cancelar o registro de objetos.|
|[Estrutura DerefHelper](derefhelper-structure.md)|Representa um ponteiro de referência para o parâmetro de modelo `T*`.|
|[Estrutura EnableIf](enableif-structure.md)|Define um membro de dados do tipo especificado pelo segundo parâmetro de modelo se o primeiro parâmetro de modelo for avaliado como `true`.|
|[Estrutura FactoryCache](factorycache-structure.md)|Contém o local de uma fábrica de classes e um valor que identifica um objeto registrado Windows Runtime ou classe COM.|
|[Estrutura ImplementsBase](implementsbase-structure.md)|Usado para validar os tipos de parâmetro de modelo na [estrutura implementações](implements-structure.md).|
|[Estrutura ImplementsHelper](implementshelper-structure.md)|Ajuda a implementar a estrutura de [implementações](implements-structure.md) .|
|[Estrutura InterfaceList](interfacelist-structure.md)|Usado para criar uma lista recursiva de interfaces.|
|[Estrutura InterfaceListHelper](interfacelisthelper-structure.md)|Cria um tipo de `InterfaceList` recursivamente aplicando os argumentos de parâmetro de modelo especificados.|
|[Estrutura InterfaceTraits](interfacetraits-structure.md)|Implementa características comuns de uma interface.|
|[Estrutura InvokeHelper](invokehelper-structure.md)|Fornece uma implementação do método `Invoke()` com base no número e tipo de argumentos especificados.|
|[Estrutura IsBaseOfStrict](isbaseofstrict-structure.md)|Testa se um tipo é a base de outro.|
|[Estrutura IsSame](issame-structure.md)|Testa se um tipo especificado é igual a outro tipo especificado.|
|[Estrutura Nil](nil-structure.md)|Usado para indicar um parâmetro de modelo opcional não especificado.|
|[Estrutura RemoveReference](removereference-structure.md)|Remove a característica de referência ou de referência rvalue do parâmetro de modelo de classe especificado.|
|[Estrutura RuntimeClassBase](runtimeclassbase-structure.md)|Usado para detectar `RuntimeClass` na função [Make](make-function.md) .|
|[Estrutura RuntimeClassBaseT](runtimeclassbaset-structure.md)|Fornece métodos auxiliares para operações de `QueryInterface` e obtenção de IDs de interface.|
|[Estrutura VerifyInheritanceHelper](verifyinheritancehelper-structure.md)|Testa se uma interface é derivada de outra interface.|
|[Estrutura VerifyInterfaceHelper](verifyinterfacehelper-structure.md)|Verifica se a interface especificada pelo parâmetro de modelo atende a determinados requisitos.|

### <a name="enumerations"></a>Enumerações

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Enumeração AsyncStatusInternal](asyncstatusinternal-enumeration.md)|Especifica um mapeamento entre enumerações internas para o estado de operações assíncronas e a enumeração de `Windows::Foundation::AsyncStatus`.|

### <a name="functions"></a>Funções

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Função ActivationFactoryCallback](activationfactorycallback-function.md)|Obtém o alocador de ativação para a ID de ativação especificada.|
|[Função Move](move-function.md)|Move o argumento especificado de um local para outro.|
|[Função RaiseException](raiseexception-function.md)|Gera uma exceção no thread de chamada.|
|[Função swap (WRL)](swap-function-wrl.md)|Troca os valores dos dois argumentos especificados.|
|[Função TerminateMap](terminatemap-function.md)|Desliga as fábricas de classes no módulo especificado.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Async. h, Client. h, corewrappers. h, Event. h, FTM. h, Implements. h, Internal. h, Module. h

**Namespace:** Microsoft:: WRL::D etalhes

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)<br/>
[Namespace Microsoft::WRL::Wrappers](microsoft-wrl-wrappers-namespace.md)
