---
title: Namespace Microsoft::WRL::Details | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs: C++
ms.assetid: d71fe149-d804-4c6f-961d-43fe21ef8630
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f005969908252602cb2fb4bdd73d3b55ae342a99
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="microsoftwrldetails-namespace"></a>Namespace Microsoft::WRL::Details
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
namespace Microsoft::WRL::Details;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="classes"></a>Classes  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Classe ComPtrRef](../windows/comptrref-class.md)|Representa uma referência a um objeto do tipo ComPtr\<T >.|  
|[Classe ComPtrRefBase](../windows/comptrrefbase-class.md)|Representa a classe base para o [ComPtrRef](../windows/comptrref-class.md) classe.|  
|[Classe DontUseNewUseMake](../windows/dontusenewusemake-class.md)|Impede o uso de operador `new` em `RuntimeClass`. Consequentemente, você deve usar o [função Make](../windows/make-function.md) em vez disso.|  
|[Classe EventTargetArray](../windows/eventtargetarray-class.md)|Representa uma matriz de manipuladores de eventos.|  
|[Classe MakeAllocator](../windows/makeallocator-class.md)|Aloca memória para uma classe ativável, com ou sem suporte de referência fraca.|  
|[Classe ModuleBase](../windows/modulebase-class.md)|Representa a classe base do [módulo](../windows/module-class.md) classes.|  
|[Classe RemoveIUnknown](../windows/removeiunknown-class.md)|Faz com que um tipo que é equivalente a uma `IUnknown`-baseado em tipo, mas possui não virtual `QueryInterface`, `AddRef`, e `Release` métodos.|  
|[Classe WeakReference](../windows/weakreference-class1.md)|Representa um *referência fraca* que pode ser usado com o tempo de execução do Windows ou o clássico com. Uma referência fraca representa um objeto que pode ou não pode ser acessado.|  
  
### <a name="structures"></a>Estruturas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Estrutura ArgTraits](../windows/argtraits-structure.md)|Declara um delegado especificado interface e uma função de membro anônimo que tem um número especificado de parâmetros.|  
|[Estrutura ArgTraitsHelper](../windows/argtraitshelper-structure.md)|Ajuda a define as características comuns dos argumentos do delegado.|  
|[Estrutura BoolStruct](../windows/boolstruct-structure.md)|Define se um ComPtr está gerenciando o tempo de vida do objeto de uma interface. BoolStruct é usado internamente pelo [BoolType()](../windows/comptr-operator-microsoft-wrl-details-booltype-operator.md) operador.|  
|[Estrutura CreatorMap](../windows/creatormap-structure.md)|Contém informações sobre como inicializar, registrar e cancelar o registro de objetos.|  
|[Estrutura DerefHelper](../windows/derefhelper-structure.md)|Representar um ponteiro desreferenciado para o `T*` parâmetro do modelo.|  
|[Estrutura EnableIf](../windows/enableif-structure.md)|Define um membro de dados do tipo especificado pelo parâmetro de modelo segundo se o primeiro parâmetro de modelo for avaliada como `true`.|  
|[Estrutura FactoryCache](../windows/factorycache-structure.md)|Contém o local de uma fábrica de classe e um valor que identifica um objeto de classe de tempo de execução do Windows ou COM registrado.|  
|[Estrutura ImplementsBase](../windows/implementsbase-structure.md)|Usado para validar os tipos de parâmetro de modelo no [implementa estrutura](../windows/implements-structure.md).|  
|[Estrutura ImplementsHelper](../windows/implementshelper-structure.md)|Ajuda a implementar o [implementa](../windows/implements-structure.md) estrutura.|  
|[Estrutura InterfaceList](../windows/interfacelist-structure.md)|Usado para criar uma lista recursiva de interfaces.|  
|[Estrutura InterfaceListHelper](../windows/interfacelisthelper-structure.md)|Cria um `InterfaceList` tipo por recursivamente aplicar os argumentos de parâmetro do modelo especificado.|  
|[Estrutura InterfaceTraits](../windows/interfacetraits-structure.md)|Características em comum implementa uma interface.|  
|[Estrutura InvokeHelper](../windows/invokehelper-structure.md)|Fornece uma implementação do método Invoke () com base no número especificado e tipo dos argumentos.|  
|[Estrutura IsBaseOfStrict](../windows/isbaseofstrict-structure.md)|Testa se um tipo é a base de outro.|  
|[Estrutura IsSame](../windows/issame-structure.md)|Testes se um tipo especificado é igual a outro tipo especificado.|  
|[Estrutura Nil](../windows/nil-structure.md)|Usado para indicar um parâmetro de modelo não especificado, opcional.|  
|[Estrutura RemoveReference](../windows/removereference-structure.md)|Retira a característica de referência ou referência de rvalue do parâmetro de modelo da classe especificada.|  
|[Estrutura RuntimeClassBase](../windows/runtimeclassbase-structure.md)|Usado para detectar `RuntimeClass` no [fazer](../windows/make-function.md) função.|  
|[Estrutura RuntimeClassBaseT](../windows/runtimeclassbaset-structure.md)|Fornece métodos auxiliares para `QueryInterface` operações e ao obter IDs de interface.|  
|[Estrutura VerifyInheritanceHelper](../windows/verifyinheritancehelper-structure.md)|Testa se uma interface é derivada de outra interface.|  
|[Estrutura VerifyInterfaceHelper](../windows/verifyinterfacehelper-structure.md)|Verifica se a interface especificada pelo parâmetro de modelo atende a certos requisitos.|  
  
### <a name="enumerations"></a>Enumerações  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Enumeração AsyncStatusInternal](../windows/asyncstatusinternal-enumeration.md)|Especifica um mapeamento entre enumerações internos para o estado das operações assíncronas e o **Windows::Foundation::AsyncStatus** enumeração.|  
  
### <a name="functions"></a>Funções  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Função ActivationFactoryCallback](../windows/activationfactorycallback-function.md)|Obtém o alocador de ativação para a ID de ativação especificado.|  
|[Função Move](../windows/move-function.md)|Move o argumento especificado de um local para outro.|  
|[Função RaiseException](../windows/raiseexception-function.md)|Gera uma exceção no thread de chamada.|  
|[Função Swap (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](../windows/swap-function-windows-runtime-cpp-template-library.md)|Substitui os valores dos dois argumentos especificados.|  
|[Função TerminateMap](../windows/terminatemap-function.md)|Desliga as fábricas de classe no módulo especificado.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h, client.h, corewrappers.h, event.h, ftm.h, implements.h, internal.h, module.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft:: wrl](../windows/microsoft-wrl-namespace.md)   
 [Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)