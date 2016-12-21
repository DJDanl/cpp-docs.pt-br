---
title: "Namespace Microsoft::WRL::Details | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
ms.assetid: d71fe149-d804-4c6f-961d-43fe21ef8630
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Namespace Microsoft::WRL::Details
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura do WRL e não se destina a ser usada diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
namespace Microsoft::WRL::Details;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="classes"></a>Classes  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Classe ComPtrRef](../Topic/ComPtrRef%20Class.md)|Representa uma referência a um objeto do tipo ComPtr \< T>.|  
|[Classe ComPtrRefBase](../windows/comptrrefbase-class.md)|Representa a classe base para o [ComPtrRef](../Topic/ComPtrRef%20Class.md) classe.|  
|[Classe DontUseNewUseMake](../windows/dontusenewusemake-class.md)|Impede que usando o operador `new` em `RuntimeClass`. Consequentemente, você deve usar o [que funcione](../windows/make-function.md) em vez disso.|  
|[Classe EventTargetArray](../windows/eventtargetarray-class.md)|Representa uma matriz de manipuladores de eventos.|  
|[Classe MakeAllocator](../windows/makeallocator-class.md)|Aloca memória para uma classe ativável, com ou sem suporte de referência fraca.|  
|[Classe ModuleBase](../windows/modulebase-class.md)|Representa a classe base do [módulo](../windows/module-class.md) classes.|  
|[Classe RemoveIUnknown](../windows/removeiunknown-class.md)|Cria um tipo que é equivalente a uma `IUnknown`-baseado em tipo, mas tem não virtual `QueryInterface`, `AddRef`, e `Release` métodos.|  
|[Classe WeakReference](../windows/weakreference-class1.md)|Representa um *referência fraca* que pode ser usado com o tempo de execução do Windows ou com clássico. Uma referência fraca representa um objeto que pode ou não estar acessível.|  
  
### <a name="structures"></a>Estruturas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Estrutura ArgTraits](../windows/argtraits-structure.md)|Declara um delegado especificado interface e uma função de membro anônimo que tem um número especificado de parâmetros.|  
|[Estrutura ArgTraitsHelper](../windows/argtraitshelper-structure.md)|Ajuda a definir as características comuns dos argumentos do delegado.|  
|[Estrutura BoolStruct](../windows/boolstruct-structure.md)|Define se um ComPtr é gerenciar a vida útil do objeto de uma interface. BoolStruct é usado internamente pelo [BoolType()](../windows/comptr-operator-microsoft-wrl-details-booltype-operator.md) operador.|  
|[Estrutura CreatorMap](../windows/creatormap-structure.md)|Contém informações sobre como inicializar, registrar e cancelar o registro de objetos.|  
|[Estrutura DerefHelper](../Topic/DerefHelper%20Structure.md)|Representar um ponteiro cancelado para o `T*` parâmetro do modelo.|  
|[Estrutura EnableIf](../windows/enableif-structure.md)|Define um membro de dados do tipo especificado pelo parâmetro de modelo segundo se o primeiro parâmetro de modelo é avaliada como `true`.|  
|[Estrutura FactoryCache](../Topic/FactoryCache%20Structure.md)|Contém o local de uma fábrica de classes e um valor que identifica um usuário [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] ou objeto de classe COM.|  
|[Estrutura ImplementsBase](../windows/implementsbase-structure.md)|Usado para validar os tipos de parâmetro de modelo no [implementa estrutura](../Topic/Implements%20Structure.md).|  
|[Estrutura ImplementsHelper](../windows/implementshelper-structure.md)|Ajuda a implementar o [implementa](../Topic/Implements%20Structure.md) estrutura.|  
|[Estrutura InterfaceList](../windows/interfacelist-structure.md)|Usado para criar uma lista recursiva de interfaces.|  
|[Estrutura InterfaceListHelper](../Topic/InterfaceListHelper%20Structure.md)|Cria um `InterfaceList` tipo por recursivamente aplicando os argumentos de parâmetro do modelo especificado.|  
|[Estrutura InterfaceTraits](../windows/interfacetraits-structure.md)|Características comuns de implementa uma interface.|  
|[Estrutura InvokeHelper](../windows/invokehelper-structure.md)|Fornece uma implementação do método Invoke () com base no tipo dos argumentos e o número especificado.|  
|[Estrutura IsBaseOfStrict](../windows/isbaseofstrict-structure.md)|Testa se um tipo é a base de outro.|  
|[Estrutura IsSame](../windows/issame-structure.md)|Testes se um tipo especificado é o mesmo que outro tipo especificado.|  
|[Estrutura nil](../Topic/Nil%20Structure.md)|Usado para indicar um parâmetro de modelo não especificado, opcional.|  
|[Estrutura RemoveReference](../windows/removereference-structure.md)|Retira a característica de referência ou referência de rvalue de parâmetro do modelo de classe especificada.|  
|[Estrutura RuntimeClassBase](../windows/runtimeclassbase-structure.md)|Usado para detectar `RuntimeClass` no [fazer](../windows/make-function.md) função.|  
|[Estrutura RuntimeClassBaseT](../windows/runtimeclassbaset-structure.md)|Fornece métodos auxiliares para `QueryInterface` operações e ao obter identificadores de interface.|  
|[Estrutura VerifyInheritanceHelper](../windows/verifyinheritancehelper-structure.md)|Testa se uma interface é derivada de outra interface.|  
|[Estrutura VerifyInterfaceHelper](../windows/verifyinterfacehelper-structure.md)|Verifica se a interface especificada pelo parâmetro de modelo atende a certos requisitos.|  
  
### <a name="enumerations"></a>Enumerações  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Enumeração AsyncStatusInternal](../windows/asyncstatusinternal-enumeration.md)|Especifica um mapeamento entre enumerações internos para o estado das operações assíncronas e **Windows::Foundation::AsyncStatus** enumeração.|  
  
### <a name="functions"></a>Funções  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Função ActivationFactoryCallback](../windows/activationfactorycallback-function.md)|Obtém a fábrica de ativação para a ID de ativação especificado.|  
|[Função move](../Topic/Move%20Function.md)|Move o argumento especificado de um local para outro.|  
|[Função RaiseException](../windows/raiseexception-function.md)|Gera uma exceção no thread de chamada.|  
|[Função swap (biblioteca de modelos C++ do tempo de execução do Windows)](../windows/swap-function-windows-runtime-cpp-template-library.md)|Troca os valores dos dois argumentos especificados.|  
|[Função TerminateMap](../windows/terminatemap-function.md)|Fecha as fábricas de classe no módulo especificado.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h, client.h, corewrappers.h, event.h, ftm.h, implements.h, internal.h, module.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft:: wrl](../windows/microsoft-wrl-namespace.md)   
 [Namespace Microsoft::WRL::wrappers](../Topic/Microsoft::WRL::Wrappers%20Namespace.md)