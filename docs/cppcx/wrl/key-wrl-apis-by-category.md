---
title: APIs de chave WRL por categoria
ms.date: 11/04/2016
ms.topic: reference
ms.assetid: 7367bacf-6b7c-4ecd-a0ce-a662db46fc66
ms.openlocfilehash: 8ac89f3286866ac61bac5ae256bdb448fe88f07d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213818"
---
# <a name="key-wrl-apis-by-category"></a>APIs de chave WRL por categoria

As tabelas a seguir listam C++ as classes primárias da biblioteca de modelos Windows Runtime, structs, funções e macros. Construções em namespaces auxiliares e classes são omitidas. Essas listas aumentam a documentação da API, que é organizada por namespace.

## <a name="classes"></a>Classes

|Title|DESCRIÇÃO|
|-----------|-----------------|
|[Classe ActivationFactory](activationfactory-class.md)|Permite que uma ou mais classes sejam ativadas pelo Windows Runtime.|
|[Classe AsyncBase](asyncbase-class.md)|Implementa o Windows Runtime máquina de estado assíncrono.|
|[Classe ClassFactory](classfactory-class.md)|Implementa a funcionalidade básica da interface `IClassFactory`.|
|[Classe ComPtr](comptr-class.md)|Cria um tipo de *ponteiro inteligente* que representa a interface especificada pelo parâmetro de modelo. O ComPtr mantém automaticamente uma contagem de referência para o ponteiro de interface subjacente e libera a interface quando a contagem de referência chega a zero.|
|[Classe Event (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](event-class-wrl.md)|Representa um evento.|
|[EventSource Class](eventsource-class.md)|Representa um evento. `EventSource` funções membro adicionam, removem e chamam manipuladores de eventos.|
|[Classe FtmBase](ftmbase-class.md)|Representa um objeto de marshaling com thread livre.|
|[Classe HandleT](handlet-class.md)|Representa um identificador para um objeto.|
|[Classe HString](hstring-class.md)|Fornece suporte para manipular identificadores HSTRING.|
|[Classe HStringReference](hstringreference-class.md)|Representa um HSTRING que é criado a partir de uma cadeia de caracteres existente.|
|[Classe Module](module-class.md)|Representa uma coleção de objetos relacionados.|
|[Classe Module::GenericReleaseNotifier](module-genericreleasenotifier-class.md)|Invoca um manipulador de eventos quando o último objeto no módulo atual é liberado. O manipulador de eventos é especificado por em um lambda, functor ou ponteiro para função.|
|[Classe Module::MethodReleaseNotifier](module-methodreleasenotifier-class.md)|Invoca um manipulador de eventos quando o último objeto no módulo atual é liberado. O manipulador de eventos é especificado por um objeto e seu membro de ponteiro para um método.|
|[Classe Module::ReleaseNotifier](module-releasenotifier-class.md)|Invoca um manipulador de eventos quando o último objeto em um módulo é liberado.|
|[Classe RoInitializeWrapper](roinitializewrapper-class.md)|Inicializa o Windows Runtime.|
|[Classe RuntimeClass](runtimeclass-class.md)|Representa uma classe instanciada que herda o número especificado de interfaces e fornece o suporte especificado Windows Runtime, COM clássico e de referência fraca.|
|[Classe SimpleActivationFactory](simpleactivationfactory-class.md)|Fornece um mecanismo fundamental para criar uma classe base COM Windows Runtime ou clássica.|
|[Classe SimpleClassFactory](simpleclassfactory-class.md)|Fornece um mecanismo fundamental para criar uma classe base.|
|[Classe WeakRef](weakref-class.md)|Representa uma *referência fraca* que pode ser usada apenas pelo Windows Runtime, não pelo com clássico. Uma referência fraca representa um objeto que pode ou não estar acessível.|

## <a name="structures"></a>Estruturas

|Title|DESCRIÇÃO|
|-----------|-----------------|
|[Estrutura ChainInterfaces](chaininterfaces-structure.md)|Especifica as funções de verificação e inicialização que podem ser aplicadas a um conjunto de IDs de interface.|
|[Estrutura CloakedIid](cloakediid-structure.md)|Indica para os modelos de `RuntimeClass`, `Implements` e `ChainInterfaces` que a interface especificada não está acessível na lista de IID.|
|[Estrutura Implements](implements-structure.md)|Implementa `QueryInterface` e `GetIid` para as interfaces especificadas.|
|[Estrutura MixIn](mixin-structure.md)|Garante que uma classe de tempo de execução derive de interfaces Windows Runtime, se houver, e as interfaces COM clássicas.|

## <a name="functions"></a>Funções

|Title|DESCRIÇÃO|
|-----------|-----------------|
|[Função ActivateInstance](activateinstance-function.md)|Registra e recupera uma instância de um tipo especificado definido em uma ID de classe especificada.|
|[Função AsWeak](asweak-function.md)|Recupera uma referência fraca a uma instância especificada.|
|[Função de retorno de chamada](callback-function-wrl.md)|Cria um objeto cuja função de membro é um método de retorno de chamada.|
|[Função CreateActivationFactory](createactivationfactory-function.md)|Cria uma fábrica que produz instâncias da classe especificada que pode ser ativada pelo Windows Runtime.|
|[Função CreateClassFactory](createclassfactory-function.md)|Cria uma fábrica que produz instâncias da classe especificada.|
|[Função GetActivationFactory](getactivationfactory-function.md)|Recupera um alocador de ativação para o tipo especificado pelo parâmetro de modelo.|
|[Função Make](make-function.md)|Inicializa a classe de Windows Runtime especificada.|

## <a name="macros"></a>Macros

|Title|DESCRIÇÃO|
|-----------|-----------------|
|[ActivatableClass Macros](activatableclass-macros.md)|Popula um cache interno que contém uma fábrica que pode criar uma instância da classe especificada.|
|[Macro InspectableClass](inspectableclass-macro.md)|Define o nome da classe de tempo de execução e o nível de confiança.|

## <a name="see-also"></a>Confira também

[WRL (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](windows-runtime-cpp-template-library-wrl.md)
