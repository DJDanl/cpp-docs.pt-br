---
title: Combinando C (estruturadas) e exceções do C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- exceptions [C++], mixed C and C++
- C++ exception handling, mixed-language
- structured exception handling [C++], mixed C and C++
- catch keyword [C++], mixed
- try-catch keyword [C++], mixed-language
ms.assetid: a149154e-36dd-4d1a-980b-efde2a563a56
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6e632faddb3b4f59733710a915ed121a12f4e0c6
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39404857"
---
# <a name="mixing-c-structured-and-c-exceptions"></a>Combinação de exceções C (Estruturada) e C++
Se você quiser escrever um código mais portátil, não recomendamos o uso de tratamento de exceções estruturadas em um programa C/C++. No entanto, às vezes, convém compilar com **/EHa** e combinar exceções estruturadas e código-fonte C++ e precisar de algum recurso para lidar com ambos os tipos de exceções. Como um manipulador de exceção estruturada não tem nenhum conceito de objetos ou exceções tipadas, ele não pode tratar exceções geradas por código C++. No entanto, C++ **catch** manipuladores podem tratar exceções estruturadas. Como tal, sintaxe de tratamento de exceções de C++ (**tente**, **throw**, **catch**) não é aceito pelo compilador C, mas a sintaxe de tratamento de exceções estruturado (**Try** , **EXCEPT**, **Finally**) é suportado pelo compilador do C++.  
  
 Ver [set_se_translator](../c-runtime-library/reference/set-se-translator.md) para obter informações sobre o tratamento de exceções estruturadas como exceções C++.  
  
 Se você combinar exceções estruturadas e exceções C++, observe o seguinte:  
  
1.  As exceções C++ e as exceções estruturadas não podem ser combinadas na mesma função.  
  
2.  Manipuladores de terminação (**Finally** blocos) são sempre executados, mesmo durante o desenrolamento depois que uma exceção será lançada.  
  
3.  Tratamento de exceções C++ pode capturar e preservar semânticas de desenrolamento em todos os módulos compilados com o [/EH](../build/reference/eh-exception-handling-model.md) opção do compilador (essa opção habilita a semântica de liberação).  
  
4.  Pode haver algumas situações nas quais as funções de destruidor não sejam chamadas de todos os objetos. Por exemplo, se uma exceção estruturada ocorre ao tentar fazer uma chamada de função por meio de um ponteiro de função não inicializado, e essa função usar como parâmetros objetos que foram criados antes da chamada, os destruidores desses objetos não serão chamados durante o desenrolamento de pilha.  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [Usando setjmp ou longjmp em programas C++](../cpp/using-setjmp-longjmp.md)  
  
-   [Diferenças entre SEH e C++ EH](../cpp/exception-handling-differences.md)  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de exceções em C++](../cpp/cpp-exception-handling.md)