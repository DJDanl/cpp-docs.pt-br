---
title: Manipulação de eventos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- attributes [C++], event handling
- intrinsic functions [C++], event handling
- event handling [C++], Visual C++
ms.assetid: 82de3f9a-2d88-470c-9527-8a5b54c8ced4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 91fded4380875515da81b87c5ffd74665df01b21
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39408021"
---
# <a name="event-handling"></a>Tratamento de Evento
Manipulação de eventos é suportada principalmente para classes COM (classes C++ que implementam objetos COM, normalmente usando classes ATL ou o [coclass](../windows/coclass.md) atributo).  Para obter mais informações, consulte [manipulação de eventos em COM](../cpp/event-handling-in-com.md).  
  
 A manipulação de eventos também tem suporte para classes nativas de C++ (classes C++ que não implementam objetos COM). Entretanto, esse suporte é preterido e será removido em uma versão futura.  Para obter mais informações, consulte [manipulação de eventos em C++ nativo](../cpp/event-handling-in-native-cpp.md).  
  
 A manipulação de eventos tem suporte ao uso único e multithread e protege os dados contra acessos simultâneos multithread. Ele também permite que você gere subclasses das classes de origem ou do receptor de eventos e tem suporte a fontes/recebimentos de eventos na classe derivada.  
  
 O Visual C++ inclui atributos e palavras-chave para declarar eventos e manipuladores de eventos. Os atributos de eventos e as palavras-chave podem ser usados em programas CLR e em programas nativos C++.  
  
|Tópico|Descrição|  
|-----------|-----------------|  
|[event_source](../windows/event-source.md)|Cria uma origem de evento.|  
|[event_receiver](../windows/event-receiver.md)|Cria um receptor de eventos (coletor).|  
|[__event](../cpp/event.md)|Declara um evento.|  
|[__raise](../cpp/raise.md)|Enfatiza o site de chamada de um evento.|  
|[__hook](../cpp/hook.md)|Associa um método de manipulador a um evento.|  
|[__unhook](../cpp/unhook.md)|Dissocia um método de manipulador de um evento.|  
  
## <a name="see-also"></a>Consulte também  
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   