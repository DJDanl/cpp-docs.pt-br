---
title: APIs WRL por categoria de chave | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs: C++
ms.assetid: 7367bacf-6b7c-4ecd-a0ce-a662db46fc66
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 7ad38d1b24ca40b6209295f873bd44c54c3f6148
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="key-wrl-apis-by-category"></a>APIs de chave WRL por categoria
As tabelas a seguir listam os principais produtos de classes, estruturas, funções e macros biblioteca de modelos C++ do Windows Runtime. As construções em auxiliar namespaces e classes são omitidas. Essas listas aumentar a documentação da API, que é organizada por namespace.  
  
### <a name="classes"></a>Classes  
  
|Título|Descrição|  
|-----------|-----------------|  
|[Classe ActivationFactory](../windows/activationfactory-class.md)|Permite que uma ou mais classes sejam ativadas pelo tempo de execução do Windows.|  
|[Classe AsyncBase](../windows/asyncbase-class.md)|Implementa a máquina de estado assíncrona do tempo de execução do Windows.|  
|[Classe ClassFactory](../windows/classfactory-class.md)|Implementa a funcionalidade básica do `IClassFactory` interface.|  
|[Classe ComPtr](../windows/comptr-class.md)|Cria um *ponteiro inteligente* tipo que representa a interface especificada pelo parâmetro de modelo. ComPtr automaticamente mantém uma contagem de referência para o ponteiro de interface subjacente e libera a interface quando a contagem de referência chega a zero.|  
|[Classe Event (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](../windows/event-class-windows-runtime-cpp-template-library.md)|Representa um evento.|  
|[Classe EventSource](../windows/eventsource-class.md)|Representa um evento. `EventSource`funções de membro, adicionar, removem e invocar os manipuladores de eventos.|  
|[Classe FtmBase](../windows/ftmbase-class.md)|Representa um objeto de empacotamento de segmentação livre.|  
|[Classe HandleT](../windows/handlet-class.md)|Representa um identificador para um objeto.|  
|[Classe HString](../windows/hstring-class.md)|Fornece suporte para manipulação de identificadores HSTRING.|  
|[Classe HStringReference](../windows/hstringreference-class.md)|Representa um HSTRING que é criado a partir de uma cadeia de caracteres existente.|  
|[Classe Module](../windows/module-class.md)|Representa uma coleção de objetos relacionados.|  
|[Classe Module::GenericReleaseNotifier](../windows/module-genericreleasenotifier-class.md)|Invoca um manipulador de eventos quando o último objeto no módulo atual é liberado. O manipulador de eventos é especificado em um lambda, functor ou ponteiro para função.|  
|[Classe Module::MethodReleaseNotifier](../windows/module-methodreleasenotifier-class.md)|Invoca um manipulador de eventos quando o último objeto no módulo atual é liberado. O manipulador de eventos é especificado por um objeto e seus membros de ponteiro para um método.|  
|[Classe Module::ReleaseNotifier](../windows/module-releasenotifier-class.md)|Invoca um manipulador de eventos quando o último objeto em um módulo é liberado.|  
|[Classe RoInitializeWrapper](../windows/roinitializewrapper-class.md)|Inicializa o tempo de execução do Windows.|  
|[Classe RuntimeClass](../windows/runtimeclass-class.md)|Representa uma classe instanciada que herda o número especificado de interfaces e fornece o tempo de execução do Windows especificado, COM clássico e suporte de referência fraca.|  
|[Classe SimpleActivationFactory](../windows/simpleactivationfactory-class.md)|Fornece um mecanismo básico para criar um tempo de execução do Windows ou a classe de base COM clássico.|  
|[Classe SimpleClassFactory](../windows/simpleclassfactory-class.md)|Fornece um mecanismo fundamental para criar uma classe base.|  
|[Classe WeakRef](../windows/weakref-class.md)|Representa um *referência fraca* que pode ser usado por somente o Windows Runtime, COM. não clássico Uma referência fraca representa um objeto que pode ou não pode ser acessado.|  
  
### <a name="structures"></a>Estruturas  
  
|Título|Descrição|  
|-----------|-----------------|  
|[Estrutura ChainInterfaces](../windows/chaininterfaces-structure.md)|Especifica as funções de verificação e de inicialização que podem ser aplicadas a um conjunto de IDs de interface.|  
|[Estrutura CloakedIid](../windows/cloakediid-structure.md)|Indica para o `RuntimeClass`, `Implements` e `ChainInterfaces` que a interface especificada não está acessível na lista IID de modelos.|  
|[Estrutura Implements](../windows/implements-structure.md)|Implementa `QueryInterface` e `GetIid` para as interfaces especificadas.|  
|[Estrutura MixIn](../windows/mixin-structure.md)|Garante que uma classe de tempo de execução deriva de tempo de execução do Windows, se houver e a clássico, em seguida, COM interfaces.|  
  
### <a name="functions"></a>Funções  
  
|Título|Descrição|  
|-----------|-----------------|  
|[Função ActivateInstance](../windows/activateinstance-function.md)|Registra e recupera uma instância de um tipo especificado definido em uma ID de classe especificada.|  
|[Função AsWeak](../windows/asweak-function.md)|Recupera uma referência fraca a uma instância especificada.|  
|[Função de retorno de chamada](../windows/callback-function-windows-runtime-cpp-template-library.md)|Cria um objeto cuja função de membro é um método de retorno de chamada.|  
|[Função CreateActivationFactory](../windows/createactivationfactory-function.md)|Cria uma fábrica que produz instâncias da classe especificada que podem ser ativadas pelo tempo de execução do Windows.|  
|[Função CreateClassFactory](../windows/createclassfactory-function.md)|Cria uma fábrica que produz instâncias da classe especificada.|  
|[Função GetActivationFactory](../windows/getactivationfactory-function.md)|Recupera um alocador de ativação para o tipo especificado pelo parâmetro de modelo.|  
|[Função Make](../windows/make-function.md)|Inicializa a classe de tempo de execução do Windows especificada.|  
  
### <a name="macros"></a>Macros  
  
|Título|Descrição|  
|-----------|-----------------|  
|[ActivatableClass Macros](../windows/activatableclass-macros.md)|Popula um cache interno que contém uma fábrica que pode criar uma instância da classe especificada.|  
|[Macro InspectableClass](../windows/inspectableclass-macro.md)|Define o nível de confiança e de nome de classe em tempo de execução.|  
  
## <a name="see-also"></a>Consulte também  
 [WRL (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](../windows/windows-runtime-cpp-template-library-wrl.md)