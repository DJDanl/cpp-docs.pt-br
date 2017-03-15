---
title: "Manipula&#231;&#227;o de eventos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "atributos [C++], manipulação de eventos"
  - "manipulação de eventos, Visual C++"
  - "funções intrínsecas, manipulação de eventos"
ms.assetid: 82de3f9a-2d88-470c-9527-8a5b54c8ced4
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Manipula&#231;&#227;o de eventos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A manipulação de eventos é suportada principalmente para classes COM \(classes C\+\+ que implementam objetos COM, normalmente usando classes ATL ou o atributo de [CoClass](../windows/coclass.md)\).  Para obter mais informações, consulte [Manipulação de eventos em COM](../cpp/event-handling-in-com.md).  
  
 A manipulação de eventos também tem suporte para classes nativas de C\+\+ \(classes C\+\+ que não implementam objetos COM\). Entretanto, esse suporte é preterido e será removido em uma versão futura.  Para obter mais informações, consulte [Manipulação de eventos em C\+\+ nativo](../Topic/Event%20Handling%20in%20Native%20C++.md).  
  
 A manipulação de eventos tem suporte ao uso único e multithread e protege os dados contra acessos simultâneos multithread.  Ele também permite que você gere subclasses das classes de origem ou do receptor de eventos e tem suporte a fontes\/recebimentos de eventos na classe derivada.  
  
 O Visual C\+\+ inclui atributos e palavras\-chave para declarar eventos e manipuladores de eventos.  Os atributos de eventos e as palavras\-chave podem ser usados em programas CLR e em programas nativos C\+\+.  
  
|Tópico|Descrição|  
|------------|---------------|  
|[origem do evento](../windows/event-source.md)|Cria uma origem de evento.|  
|[event\_receiver](../windows/event-receiver.md)|Cria um receptor de eventos \(coletor\).|  
|[\_\_event](../cpp/event.md)|Declara um evento.|  
|[\_\_raise](../cpp/raise.md)|Enfatiza o site de chamada de um evento.|  
|[\_\_hook](../cpp/hook.md)|Associa um método de manipulador a um evento.|  
|[\_\_unhook](../cpp/unhook.md)|Dissocia um método de manipulador de um evento.|  
  
## Consulte também  
 [Referência de linguagem C\+\+](../cpp/cpp-language-reference.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Event Handling Samples](http://msdn.microsoft.com/pt-br/cc0287d4-f92b-4da5-85fc-a0f186e16424)