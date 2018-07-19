---
title: Usando setjmp-longjmp | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- longjmp_cpp
- setjmp_cpp
dev_langs:
- C++
helpviewer_keywords:
- C++ exception handling, setjmp/longjmp functions
- setjmpex.h
- longjmp function in C++ programs
- setjmp.h
- setjmp function
- setjmp function, C++ programs
ms.assetid: 96be8816-f6f4-4567-9a9c-0c3c720e37c5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f68cd13304e73282735ad1227510b289b19caed8
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37939761"
---
# <a name="using-setjmplongjmp"></a>Usando setjmp/longjmp
Quando [setjmp](../c-runtime-library/reference/setjmp.md) e [longjmp](../c-runtime-library/reference/longjmp.md) são usados juntos, eles fornecem uma maneira de executar um não-local **goto**. Normalmente, eles são usados para transmitir o controle de execução para o código de recuperação ou de tratamento de erros em uma rotina anteriormente chamada anteriormente sem usar as convenções padrão de chamada ou de retorno.  
  
> [!CAUTION]
>  No entanto, como `setjmp` e `longjmp` não suportam semânticas de objeto de C++ e como podem prejudicar o desempenho evitando a otimização em variáveis locais, recomendamos que você não os utilize nos programas do C++. É recomendável que você use **tente**/**catch** constrói em vez disso.  
  
 Se você decidir usar `setjmp` / `longjmp` em um programa C++, também incluem \<setjmp > ou \<setjmpex > para garantir a interação correta entre as funções e o tratamento de exceções C++. Se você usar [/EH](../build/reference/eh-exception-handling-model.md) para compilar, os destruidores de objetos locais são chamados durante o desenrolamento de pilha. Se você usar **/EHs** para compilar e uma das funções chamar uma função que usa [nothrow](../cpp/nothrow-cpp.md) e a função que usa **nothrow** chamadas `longjmp`, em seguida, a desenrolamento do destruidor poderá não ocorrer, dependendo do otimizador.  
  
 No código portátil, quando não-local **goto** que chama `longjmp` é executado, destruição correta dos objetos baseados em quadro pode não ser confiável.  
  
## <a name="see-also"></a>Consulte também  
 [Combinação de exceções C (estruturadas) e C++](../cpp/mixing-c-structured-and-cpp-exceptions.md)