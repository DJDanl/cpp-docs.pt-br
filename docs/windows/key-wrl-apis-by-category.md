---
title: "APIs de chave WRL por categoria | Microsoft Docs"
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
ms.assetid: 7367bacf-6b7c-4ecd-a0ce-a662db46fc66
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# APIs de chave WRL por categoria
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As tabelas seguintes listam primário [!INCLUDE[cppwrl](../windows/includes/cppwrl_md.md)] classes, estruturas, funções e macros. Construtores em classes e namespaces auxiliar são omitidos. Essas listas aumentar a documentação da API, que é organizada por namespace.  
  
### <a name="classes"></a>Classes  
  
|Título|Descrição|  
|-----------|-----------------|  
|[Classe ActivationFactory](../windows/activationfactory-class.md)|Permite que uma ou mais classes ser ativado pelo tempo de execução do Windows.|  
|[Classe AsyncBase](../windows/asyncbase-class.md)|Implementa a máquina de estado assíncrono de tempo de execução do Windows.|  
|[Classe ClassFactory](../windows/classfactory-class.md)|Implementa a funcionalidade básica do `IClassFactory` interface.|  
|[Classe ComPtr](../windows/comptr-class.md)|Cria um *ponteiro inteligente* tipo que representa a interface especificada pelo parâmetro de modelo. ComPtr automaticamente mantém uma contagem de referência para o ponteiro de interface subjacente e libera a interface quando a contagem de referência chega a zero.|  
|[Classe de evento (biblioteca de modelos C++ do tempo de execução do Windows)](../windows/event-class-windows-runtime-cpp-template-library.md)|Representa um evento.|  
|[Classe EventSource](../windows/eventsource-class.md)|Representa um evento. `EventSource` funções de membro, adicionar, removem e invocar manipuladores de eventos.|  
|[Classe FtmBase](../windows/ftmbase-class.md)|Representa um objeto de empacotamento de segmentação livre.|  
|[Classe HandleT](../Topic/HandleT%20Class.md)|Representa um identificador para um objeto.|  
|[Classe HString](../windows/hstring-class.md)|Fornece suporte para manipulação de identificadores do HSTRING.|  
|[Classe HStringReference](../windows/hstringreference-class.md)|Representa um HSTRING é criado a partir de uma cadeia de caracteres existente.|  
|[Classe de módulo](../windows/module-class.md)|Representa uma coleção de objetos relacionados.|  
|[Classe genericreleasenotifier](../windows/module-genericreleasenotifier-class.md)|Invoca um manipulador de eventos quando o último objeto no módulo atual for lançado. O manipulador de eventos é especificado por em um lambda, functor ou ponteiro de função.|  
|[Classe methodreleasenotifier](../Topic/Module::MethodReleaseNotifier%20Class.md)|Invoca um manipulador de eventos quando o último objeto no módulo atual for lançado. O manipulador de eventos é especificado por um objeto e seu membro de ponteiro para um método.|  
|[Classe releasenotifier](../Topic/Module::ReleaseNotifier%20Class.md)|Invoca um manipulador de eventos quando o último objeto em um módulo é liberado.|  
|[Classe RoInitializeWrapper](RoInitializeWrapper%20Class.md)|Inicializa o [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)].|  
|[Classe RuntimeClass](../windows/runtimeclass-class.md)|Representa uma classe instanciada que herda o número especificado de interfaces e fornece o tempo de execução do Windows especificado, COM clássico e suporte de referência fraca.|  
|[Classe SimpleActivationFactory](../windows/simpleactivationfactory-class.md)|Fornece um mecanismo fundamental para criar um tempo de execução do Windows ou a classe base do COM clássico.|  
|[Classe SimpleClassFactory](../windows/simpleclassfactory-class.md)|Fornece um mecanismo fundamental para criar uma classe base.|  
|[Classe WeakRef](../windows/weakref-class.md)|Representa um *referência fraca* que podem ser usadas por apenas o Windows Runtime, com não clássico. Uma referência fraca representa um objeto que pode ou não estar acessível.|  
  
### <a name="structures"></a>Estruturas  
  
|Título|Descrição|  
|-----------|-----------------|  
|[Estrutura ChainInterfaces](../windows/chaininterfaces-structure.md)|Especifica as funções de verificação e de inicialização que podem ser aplicadas a um conjunto de IDs de interface.|  
|[Estrutura CloakedIid](../windows/cloakediid-structure.md)|Indica para o `RuntimeClass`, `Implements` e `ChainInterfaces` que a interface especificada não está acessível na lista IID de modelos.|  
|[Implementa estrutura](../Topic/Implements%20Structure.md)|Implementa `QueryInterface` e `GetIid` para interfaces especificadas.|  
|[Estrutura MixIn](../windows/mixin-structure.md)|Garante que uma classe de tempo de execução deriva de interfaces de tempo de execução do Windows, se houver e, em seguida, clássicos interfaces COM.|  
  
### <a name="functions"></a>Funções  
  
|Título|Descrição|  
|-----------|-----------------|  
|[Função ActivateInstance](../windows/activateinstance-function.md)|Registra e recupera uma instância de um tipo especificado definido em uma ID de classe especificada.|  
|[Função AsWeak](../windows/asweak-function.md)|Recupera uma referência fraca em uma instância especificada.|  
|[Função de retorno de chamada](../windows/callback-function-windows-runtime-cpp-template-library.md)|Cria um objeto cuja função de membro é um método de retorno de chamada.|  
|[Função CreateActivationFactory](../windows/createactivationfactory-function.md)|Cria uma fábrica que produz instâncias da classe especificada que pode ser ativado pela execução do Windows.|  
|[Função CreateClassFactory](../windows/createclassfactory-function.md)|Cria uma fábrica que produz instâncias da classe especificada.|  
|[Função GetActivationFactory](../windows/getactivationfactory-function.md)|Recupera uma alocador de ativação para o tipo especificado pelo parâmetro de modelo.|  
|[Função make](../windows/make-function.md)|Inicializa especificado [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] classe.|  
  
### <a name="macros"></a>Macros  
  
|Título|Descrição|  
|-----------|-----------------|  
|[Macros de ActivatableClass](../Topic/ActivatableClass%20Macros.md)|Preenche um cache interno que contém uma fábrica que pode criar uma instância da classe especificada.|  
|[Macro InspectableClass](../windows/inspectableclass-macro.md)|Define o nível de confiança e de nome de classe em tempo de execução.|  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de modelos C++ do Windows Runtime (WRL)](../Topic/Windows%20Runtime%20C++%20Template%20Library%20\(WRL\).md)