---
title: Tratamento de Evento
ms.date: 05/07/2019
helpviewer_keywords:
- event handling [C++]
ms.assetid: 82de3f9a-2d88-470c-9527-8a5b54c8ced4
ms.openlocfilehash: cf16ea0e6e14981f1105456a5f17d68c05a9c3fa
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80189202"
---
# <a name="event-handling"></a>Tratamento de Evento

A manipulação de eventos é basicamente suportadaC++ para classes com (classes que implementam objetos com, normalmente usando classes ATL ou o atributo [coclass](../windows/coclass.md) ). Para obter mais informações, consulte [manipulação de eventos em com](../cpp/event-handling-in-com.md).

A manipulação de eventos também tem suporte para classes nativas de C++ (classes C++ que não implementam objetos COM). Entretanto, esse suporte é preterido e será removido em uma versão futura.  Para obter mais informações, consulte [manipulação de eventos C++em nativo ](../cpp/event-handling-in-native-cpp.md).

A manipulação de eventos tem suporte ao uso único e multithread e protege os dados contra acessos simultâneos multithread. Ele também permite que você gere subclasses das classes de origem ou do receptor de eventos e tem suporte a fontes/recebimentos de eventos na classe derivada.

O compilador C++ da Microsoft inclui atributos e palavras-chave para declarar eventos e manipuladores de eventos. Os atributos de eventos e as palavras-chave podem ser usados em programas CLR e em programas nativos C++.

|Tópico|DESCRIÇÃO|
|-----------|-----------------|
|[event_source](../windows/attributes/event-source.md)|Cria uma origem de evento.|
|[event_receiver](../windows/attributes/event-receiver.md)|Cria um receptor de eventos (coletor).|
|[__event](../cpp/event.md)|Declara um evento.|
|[__raise](../cpp/raise.md)|Enfatiza o site de chamada de um evento.|
|[__hook](../cpp/hook.md)|Associa um método de manipulador a um evento.|
|[__unhook](../cpp/unhook.md)|Dissocia um método de manipulador de um evento.|

## <a name="see-also"></a>Confira também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
