---
title: "Manipulação de eventos | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- attributes [C++], event handling
- intrinsic functions, event handling
- event handling, Visual C++
ms.assetid: 82de3f9a-2d88-470c-9527-8a5b54c8ced4
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: a05886ade7ff9369dfae29accf7c47d1890998b8
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="event-handling"></a>Tratamento de Evento
Manipulação de eventos principalmente tem suporte para classes COM (classes C++ que implementam os objetos COM, normalmente usando classes ATL ou [coclass](../windows/coclass.md) atributo).  Para obter mais informações, consulte [manipulação de eventos COM](../cpp/event-handling-in-com.md).  
  
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
 [Exemplos de manipulação de eventos](http://msdn.microsoft.com/en-us/cc0287d4-f92b-4da5-85fc-a0f186e16424)
