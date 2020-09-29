---
title: Como fornecer funções de trabalho para as classes call e transformer
ms.date: 11/04/2016
helpviewer_keywords:
- call class, example
- using the transformer class [Concurrency Runtime]
- using the call class [Concurrency Runtime]
ms.assetid: df715ce4-8507-41ca-b204-636d11707a73
ms.openlocfilehash: b629d0e0e11388e212c56b8e1f6bea290368c884
ms.sourcegitcommit: 94893973211d0b254c8bcdcf0779997dcc136b0c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/28/2020
ms.locfileid: "91414341"
---
# <a name="how-to-provide-work-functions-to-the-call-and-transformer-classes"></a>Como fornecer funções de trabalho para as classes call e transformer

Este tópico ilustra várias maneiras de fornecer funções de trabalho para as classes [Concurrency:: Call](../../parallel/concrt/reference/call-class.md) e [Concurrency:: Transformer](../../parallel/concrt/reference/transformer-class.md) .

O primeiro exemplo mostra como passar uma expressão lambda para um `call` objeto. O segundo exemplo mostra como passar um objeto de função para um `call` objeto. O terceiro exemplo mostra como associar um método de classe a um `call` objeto.

Para ilustração, cada exemplo neste tópico usa a `call` classe. Para obter um exemplo que usa a `transformer` classe, consulte [como: usar o transformador em um pipeline de dados](../../parallel/concrt/how-to-use-transformer-in-a-data-pipeline.md).

## <a name="example-call-class"></a>Exemplo: chamar classe

O exemplo a seguir mostra uma maneira comum de usar a `call` classe. Este exemplo passa uma função lambda para o `call` Construtor.

[!code-cpp[concrt-call-lambda#1](../../parallel/concrt/codesnippet/cpp/how-to-provide-work-functions-to-the-call-and-transformer-classes_1.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
13 squared is 169.
```

## <a name="example-call-class-with-function-object"></a>Exemplo: chamar classe com o objeto de função

O exemplo a seguir é semelhante ao anterior, exceto pelo fato de que ele usa a `call` classe junto com um objeto de função (functor).

[!code-cpp[concrt-call-functor#1](../../parallel/concrt/codesnippet/cpp/how-to-provide-work-functions-to-the-call-and-transformer-classes_2.cpp)]

## <a name="example-functions-to-bind-call-object"></a>Exemplo: funções para associar o objeto de chamada

O exemplo a seguir é semelhante ao anterior, exceto pelo fato de que ele usa as funções [std:: bind1st](../../standard-library/functional-functions.md#bind1st) e [std:: mem_fun](../../standard-library/functional-functions.md#mem_fun) para associar um `call` objeto a um método de classe.

Use essa técnica se você tiver que associar um `call` `transformer` objeto ou a um método de classe específico em vez do operador de chamada de função, `operator()` .

[!code-cpp[concrt-call-method#1](../../parallel/concrt/codesnippet/cpp/how-to-provide-work-functions-to-the-call-and-transformer-classes_3.cpp)]

Você também pode atribuir o resultado da `bind1st` função a um objeto [std:: function](../../standard-library/function-class.md) ou usar a **`auto`** palavra-chave, conforme mostrado no exemplo a seguir.

[!code-cpp[concrt-call-method#2](../../parallel/concrt/codesnippet/cpp/how-to-provide-work-functions-to-the-call-and-transformer-classes_4.cpp)]

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `call.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **cl.exe/EHsc Call. cpp**

## <a name="see-also"></a>Confira também

[Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Como: usar o transformador em um pipeline de dados](../../parallel/concrt/how-to-use-transformer-in-a-data-pipeline.md)<br/>
[Classe Call](../../parallel/concrt/reference/call-class.md)<br/>
[Classe de transformador](../../parallel/concrt/reference/transformer-class.md)
