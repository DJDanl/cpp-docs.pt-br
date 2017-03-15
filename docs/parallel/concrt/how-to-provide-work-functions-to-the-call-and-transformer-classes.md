---
title: "Como fornecer fun&#231;&#245;es de trabalho para as classes call e transformer | Microsoft Docs"
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
  - "chamar a classe, exemplo"
  - "usando classe transformer [Tempo de Execução de Simultaneidade]"
  - "usando classe call [Tempo de Execução de Simultaneidade]"
ms.assetid: df715ce4-8507-41ca-b204-636d11707a73
caps.latest.revision: 15
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como fornecer fun&#231;&#245;es de trabalho para as classes call e transformer
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico ilustra vários modos de fornecer funções de trabalho às classes de [concurrency::call](../../parallel/concrt/reference/call-class.md) e de [concurrency::transformer](../../parallel/concrt/reference/transformer-class.md) .  
  
 O primeiro exemplo mostra como passar uma expressão de lambda a um objeto de `call` .  O segundo exemplo a seguir mostra como passar um objeto da função a um objeto de `call` .  O terceiro exemplo mostra como associar um método da classe para um objeto de `call` .  
  
 Para ilustrar, cada exemplo neste tópico usa a classe de `call` .  Para um exemplo que use a classe `transformer`. consulte [Como usar transformador em um pipeline de dados](../../parallel/concrt/how-to-use-transformer-in-a-data-pipeline.md).  
  
## Exemplo  
 O exemplo a seguir mostra uma forma comum de usar a classe de `call` .  Esse exemplo passa uma função de lambda para o construtor de `call` .  
  
 [!code-cpp[concrt-call-lambda#1](../../parallel/concrt/codesnippet/CPP/how-to-provide-work-functions-to-the-call-and-transformer-classes_1.cpp)]  
  
 O exemplo produz a seguinte saída.  
  
  **13 esquadrados é 169.**   
## Exemplo  
 O exemplo a seguir é semelhante ao anterior, exceto que usa a classe de `call` junto com um objeto de função \(funtor\).  
  
 [!code-cpp[concrt-call-functor#1](../../parallel/concrt/codesnippet/CPP/how-to-provide-work-functions-to-the-call-and-transformer-classes_2.cpp)]  
  
## Exemplo  
 O exemplo a seguir é semelhante ao anterior, exceto que usa as funções de [std::bind1st](../Topic/bind1st%20Function.md) e de [std::mem\_fun](../Topic/mem_fun%20Function.md) para associar um objeto de `call` a um método da classe.  
  
 Use essa técnica se você precisa associar um objeto de `call` ou de `transformer` a um método específico da classe em vez do operador na chamada de função, `operator()`.  
  
 [!code-cpp[concrt-call-method#1](../../parallel/concrt/codesnippet/CPP/how-to-provide-work-functions-to-the-call-and-transformer-classes_3.cpp)]  
  
 Você também pode atribuir o resultado da função de `bind1st` a um objeto de [std::function](../../standard-library/function-class.md) ou usar a palavra\-chave de `auto` , conforme mostrado no exemplo a seguir.  
  
 [!code-cpp[concrt-call-method#2](../../parallel/concrt/codesnippet/CPP/how-to-provide-work-functions-to-the-call-and-transformer-classes_4.cpp)]  
  
## Compilando o código  
 Copie o código de exemplo e cole\-o em um projeto do Visual Studio, ou cole\-o em um arquivo chamado `call.cpp` e execute o comando a seguir em uma janela de prompt de comando do Visual Studio.  
  
 **cl.exe \/EHsc call.cpp**  
  
## Consulte também  
 [Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md)   
 [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)   
 [Como usar transformador em um pipeline de dados](../../parallel/concrt/how-to-use-transformer-in-a-data-pipeline.md)   
 [classe da chamada](../../parallel/concrt/reference/call-class.md)   
 [Classe transformer](../../parallel/concrt/reference/transformer-class.md)