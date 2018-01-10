---
title: "Como: fornecer funções de trabalho para as Classes call e transformer | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- call class, example
- using the transformer class [Concurrency Runtime]
- using the call class [Concurrency Runtime]
ms.assetid: df715ce4-8507-41ca-b204-636d11707a73
caps.latest.revision: "15"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 52ab28a015fa0312a5d064401451640c2747e9db
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-provide-work-functions-to-the-call-and-transformer-classes"></a>Como fornecer funções de trabalho para as classes call e transformer
Este tópico ilustra várias maneiras de fornecer funções de trabalho para o [concurrency::call](../../parallel/concrt/reference/call-class.md) e [concurrency::transformer](../../parallel/concrt/reference/transformer-class.md) classes.  
  
 O primeiro exemplo mostra como passar uma expressão lambda para uma `call` objeto. O segundo exemplo mostra como passar um objeto de função para um `call` objeto. O terceiro exemplo mostra como associar um método de classe para um `call` objeto.  
  
 Para fins ilustrativos, todos os exemplos neste tópico usa o `call` classe. Para obter um exemplo que usa o `transformer` de classe, consulte [como: usar transformador em um Pipeline de dados](../../parallel/concrt/how-to-use-transformer-in-a-data-pipeline.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra uma maneira comum de usar o `call` classe. Este exemplo passa uma função lambda para o `call` construtor.  
  
 [!code-cpp[concrt-call-lambda#1](../../parallel/concrt/codesnippet/cpp/how-to-provide-work-functions-to-the-call-and-transformer-classes_1.cpp)]  
  
 Este exemplo gerencia a seguinte saída.  
  
```Output  
13 squared is 169.  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir assemelha-se à anterior, exceto que ele usa o `call` classe junto com um objeto de função (functor).  
  
 [!code-cpp[concrt-call-functor#1](../../parallel/concrt/codesnippet/cpp/how-to-provide-work-functions-to-the-call-and-transformer-classes_2.cpp)]  
  
## <a name="example"></a>Exemplo  

 O exemplo a seguir assemelha-se à anterior, exceto que ele usa o [std::bind1st](../../standard-library/functional-functions.md#bind1st) e [std::mem_fun](../../standard-library/functional-functions.md#mem_fun) funções para associar um `call` objeto para um método de classe.  

  
 Use essa técnica se você precisa associar um `call` ou `transformer` objeto para um método de classe específica em vez do operador de chamada de função, `operator()`.  
  
 [!code-cpp[concrt-call-method#1](../../parallel/concrt/codesnippet/cpp/how-to-provide-work-functions-to-the-call-and-transformer-classes_3.cpp)]  
  
 Você também pode atribuir o resultado da `bind1st` função para um [std:: Function](../../standard-library/function-class.md) de objeto ou usar o `auto` palavra-chave, conforme mostrado no exemplo a seguir.  
  
 [!code-cpp[concrt-call-method#2](../../parallel/concrt/codesnippet/cpp/how-to-provide-work-functions-to-the-call-and-transformer-classes_4.cpp)]  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `call.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc call.cpp**  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)   
 [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)   
 [Como: usar transformador em um Pipeline de dados](../../parallel/concrt/how-to-use-transformer-in-a-data-pipeline.md)   
 [Classe da chamada](../../parallel/concrt/reference/call-class.md)   
 [Classe transformer](../../parallel/concrt/reference/transformer-class.md)
