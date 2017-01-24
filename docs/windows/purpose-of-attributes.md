---
title: "Purpose of Attributes | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "attributes [C++], about attributes"
ms.assetid: 3aff8bfa-a2a3-4fcb-a2c6-1d96a2b4c68d
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Purpose of Attributes
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Atributos estendem C\+\+ em direções atualmente não é possíveis sem quebrar a estrutura clássica do idioma.  Atributos permitem que os provedores \(DLLs separadas\) para estender a funcionalidade de idioma dinamicamente.  O principal objetivo dos atributos é simplificar a autoria de componentes COM, para além de aumentar o nível de produtividade do desenvolvedor de componentes.  Atributos podem ser aplicados a praticamente qualquer construção de C\+\+, como, por exemplo, classes, funções de membro ou membros de dados.  Este é um realce dos benefícios oferecidos por essa nova tecnologia:  
  
-   Expõe uma convenção de chamada simple e familiar.  
  
-   Usos inserido o código, que, ao contrário das macros, é reconhecido pelo depurador.  
  
-   Permite fácil derivação de classes base sem detalhes de implementação extenuante.  
  
-   Substitui a grande quantidade de código IDL necessário por um componente COM alguns atributos concisos.  
  
 Por exemplo, para implementar um coletor de eventos simples para uma classe genérica do ATL, você pode aplicar o  [event\_receiver](../windows/event-receiver.md) de atributo para uma classe específica, como `CMyReceiver`.  O  **event\_receiver** atributo é então compilado pelo compilador Visual C\+\+, que insere o código apropriado no arquivo de objeto.  
  
```  
[event_receiver(com)]  
class CMyReceiver   
{  
   void handler1(int i) { ... }  
   void handler2(int i, float j) { ... }  
}  
```  
  
 Você pode então configurar o  **CMyReceiver** métodos `handler1` e `handler2` para manipular eventos \(usando a função intrínseca  [\_\_hook](../cpp/hook.md)\) de uma fonte de evento, que podem ser criadas usando  [event\_source](../windows/event-source.md).  
  
## Consulte também  
 [Concepts](../windows/attributed-programming-concepts.md)