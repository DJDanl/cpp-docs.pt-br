---
title: Como fornecer funções de trabalho para as classes call e transformer
ms.date: 11/04/2016
helpviewer_keywords:
- call class, example
- using the transformer class [Concurrency Runtime]
- using the call class [Concurrency Runtime]
ms.assetid: df715ce4-8507-41ca-b204-636d11707a73
ms.openlocfilehash: 4d2b7b3c88b51003a96526ef14d9940a8c26c3b3
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142482"
---
# <a name="how-to-provide-work-functions-to-the-call-and-transformer-classes"></a>Como fornecer funções de trabalho para as classes call e transformer

Este tópico ilustra várias maneiras de fornecer funções de trabalho para as classes [Concurrency:: Call](../../parallel/concrt/reference/call-class.md) e [Concurrency:: Transformer](../../parallel/concrt/reference/transformer-class.md) .

O primeiro exemplo mostra como passar uma expressão lambda para um objeto `call`. O segundo exemplo mostra como passar um objeto de função para um objeto `call`. O terceiro exemplo mostra como associar um método de classe a um objeto `call`.

Para ilustração, cada exemplo neste tópico usa a classe `call`. Para obter um exemplo que usa a classe `transformer`, consulte [como: usar o transformador em um pipeline de dados](../../parallel/concrt/how-to-use-transformer-in-a-data-pipeline.md).

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir mostra uma maneira comum de usar a classe `call`. Este exemplo passa uma função lambda para o Construtor `call`.

[!code-cpp[concrt-call-lambda#1](../../parallel/concrt/codesnippet/cpp/how-to-provide-work-functions-to-the-call-and-transformer-classes_1.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
13 squared is 169.
```

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir é semelhante ao anterior, exceto pelo fato de que ele usa a classe `call` junto com um objeto de função (functor).

[!code-cpp[concrt-call-functor#1](../../parallel/concrt/codesnippet/cpp/how-to-provide-work-functions-to-the-call-and-transformer-classes_2.cpp)]

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir é semelhante ao anterior, exceto pelo fato de que ele usa as funções [std:: bind1st](../../standard-library/functional-functions.md#bind1st) e [std:: mem_fun](../../standard-library/functional-functions.md#mem_fun) para associar um objeto de `call` a um método de classe.

Use essa técnica se você precisar associar um objeto `call` ou `transformer` a um método de classe específico em vez do operador de chamada de função, `operator()`.

[!code-cpp[concrt-call-method#1](../../parallel/concrt/codesnippet/cpp/how-to-provide-work-functions-to-the-call-and-transformer-classes_3.cpp)]

Você também pode atribuir o resultado da função `bind1st` a um objeto [std:: function](../../standard-library/function-class.md) ou usar a palavra-chave `auto`, conforme mostrado no exemplo a seguir.

[!code-cpp[concrt-call-method#2](../../parallel/concrt/codesnippet/cpp/how-to-provide-work-functions-to-the-call-and-transformer-classes_4.cpp)]

## <a name="compiling-the-code"></a>Compilando o Código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `call.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **CI. exe/EHsc Call. cpp**

## <a name="see-also"></a>Consulte também

[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Como usar transformador em um pipeline de dados](../../parallel/concrt/how-to-use-transformer-in-a-data-pipeline.md)<br/>
[Classe call](../../parallel/concrt/reference/call-class.md)<br/>
[Classe transformer](../../parallel/concrt/reference/transformer-class.md)
