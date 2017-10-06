---
title: Usando setjmp longjmp | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- longjmp_cpp
- setjmp_cpp
dev_langs:
- C++
helpviewer_keywords:
- C++ exception handling, setjmp/longjmp functions
- SETJMPEX.H
- longjmp function in C++ programs
- SETJMP.H
- setjmp function
- setjmp function, C++ programs
ms.assetid: 96be8816-f6f4-4567-9a9c-0c3c720e37c5
caps.latest.revision: 9
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
ms.openlocfilehash: 356924c0a93f6d9d21bb417f84836385491b2144
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="using-setjmplongjmp"></a>Usando setjmp/longjmp
Quando [setjmp](../c-runtime-library/reference/setjmp.md) e [longjmp](../c-runtime-library/reference/longjmp.md) são usados juntos, eles fornecem uma maneira de executar um local não `goto`. Normalmente, eles são usados para transmitir o controle de execução para o código de recuperação ou de tratamento de erros em uma rotina anteriormente chamada anteriormente sem usar as convenções padrão de chamada ou de retorno.  
  
> [!CAUTION]
>  No entanto, como `setjmp` e `longjmp` não suportam semânticas de objeto de C++ e como podem prejudicar o desempenho evitando a otimização em variáveis locais, recomendamos que você não os utilize nos programas do C++. Recomendamos que você use `try` / `catch` construções em vez disso.  
  
 Se você decidir usar `setjmp` / `longjmp` em um programa C++, também incluem SETJMP. H ou SETJMPEX. H para garantir a correta interação entre as funções e tratamento de exceções C++. Se você usar [/EH](../build/reference/eh-exception-handling-model.md) para compilar, destruidores para objetos locais chamados durante o desenrolamento de pilha. Se você usar **/EHs** para compilação e uma de suas chamadas de funções, uma função que usa [nothrow](../cpp/nothrow-cpp.md) e a função que usa `nothrow` chamadas `longjmp`, em seguida, o desenrolamento destruidor poderá não ocorrer, Dependendo do otimizador.  
  
 No código portátil, quando um `goto` não local que chama `longjmp` é executado, a destruição correta dos objetos baseados em quadro pode não ser confiável.  
  
## <a name="see-also"></a>Consulte também  
 [Combinação de exceções C (estruturadas) e C++](../cpp/mixing-c-structured-and-cpp-exceptions.md)
