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
ms.openlocfilehash: 37d4d5391da4dfb6e25754eb1350224acb97e972
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33881644"
---
# <a name="microsoftwrl-namespace"></a>Namespace Microsoft::WRL
Define os tipos fundamentais que compõem a biblioteca de modelos do Windows em tempo de execução C++.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
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
|[Classe ActivationFactory](../windows/activationfactory-class.md)|Permite que uma ou mais classes sejam ativadas pelo tempo de execução do Windows.|  
|[Classe AsyncBase](../windows/asyncbase-class.md)|Implementa a máquina de estado assíncrona do tempo de execução do Windows.|  
|[Classe ClassFactory](../windows/classfactory-class.md)|Implementa a funcionalidade básica do `IClassFactory` interface.|  
|[Classe ComPtr](../windows/comptr-class.md)|Cria um *ponteiro inteligente* tipo que representa a interface especificada pelo parâmetro de modelo. ComPtr automaticamente mantém uma contagem de referência para o ponteiro de interface subjacente e libera a interface quando a contagem de referência chega a zero.|  
|[Classe DeferrableEventArgs](../windows/deferrableeventargs-class.md)|Uma classe de modelo usada para os tipos de argumento do evento para adiamentos.|  
|[Classe EventSource](../windows/eventsource-class.md)|Representa um evento. `EventSource` funções de membro, adicionar, removem e invocar os manipuladores de eventos.|  
|[Classe FtmBase](../windows/ftmbase-class.md)|Representa um objeto de empacotamento de segmentação livre.|  
|[Classe Module](../windows/module-class.md)|Representa uma coleção de objetos relacionados.|  
|[Classe RuntimeClass](../windows/runtimeclass-class.md)|Representa uma classe instanciada que herda o número especificado de interfaces e fornece o tempo de execução do Windows especificado, COM clássico e suporte de referência fraca.|  
|[Classe SimpleActivationFactory](../windows/simpleactivationfactory-class.md)|Fornece um mecanismo básico para criar um tempo de execução do Windows ou a classe de base COM clássico.|  
|[Classe SimpleClassFactory](../windows/simpleclassfactory-class.md)|Fornece um mecanismo fundamental para criar uma classe base.|  
|[Classe WeakRef](../windows/weakref-class.md)|Representa um *referência fraca* que pode ser usado por somente o Windows Runtime, COM. não clássico Uma referência fraca representa um objeto que pode ou não pode ser acessado.|  
  
### <a name="structures"></a>Estruturas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Estrutura ChainInterfaces](../windows/chaininterfaces-structure.md)|Especifica as funções de verificação e de inicialização que podem ser aplicadas a um conjunto de IDs de interface.|  
|[Estrutura CloakedIid](../windows/cloakediid-structure.md)|Indica aos modelos RuntimeClass e ChainInterfaces e implementa a interface especificada não é acessível na lista IID.|  
|[Estrutura Implements](../windows/implements-structure.md)|Implementa QueryInterface e GetIid para interfaces especificadas.|  
|[Estrutura MixIn](../windows/mixin-structure.md)|Garante que uma classe de tempo de execução deriva de tempo de execução do Windows, se houver e a clássico, em seguida, COM interfaces.|  
|[Estrutura RuntimeClassFlags](../windows/runtimeclassflags-structure.md)|Contém o tipo de uma instância de um [RuntimeClass](../windows/runtimeclass-class.md).|  
  
### <a name="enumerations"></a>Enumerações  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Enumeração AsyncResultType](../windows/asyncresulttype-enumeration.md)|Especifica o tipo de resultado retornado pelo método GetResults().|  
|[Enumeração ModuleType](../windows/moduletype-enumeration.md)|Especifica se um módulo deve dar suporte a um servidor em processo ou fora de processo.|  
|[Enumeração RuntimeClassType](../windows/runtimeclasstype-enumeration.md)|Especifica o tipo de [RuntimeClass](../windows/runtimeclass-class.md) instância com suporte.|  
  
### <a name="functions"></a>Funções  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Função AsWeak](../windows/asweak-function.md)|Recupera uma referência fraca a uma instância especificada.|  
|[Função de retorno de chamada](../windows/callback-function-windows-runtime-cpp-template-library.md)|Cria um objeto cuja função de membro é um método de retorno de chamada.|  
|[Função CreateActivationFactory](../windows/createactivationfactory-function.md)|Cria uma fábrica que produz instâncias da classe especificada que podem ser ativadas pelo tempo de execução do Windows.|  
|[Função CreateClassFactory](../windows/createclassfactory-function.md)|Cria uma fábrica que produz instâncias da classe especificada.|  
|[Função Make](../windows/make-function.md)|Inicializa a classe de tempo de execução do Windows especificada.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h, client.h, corewrappers.h, event.h, ftm.h, implements.h, internal.h, module.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)