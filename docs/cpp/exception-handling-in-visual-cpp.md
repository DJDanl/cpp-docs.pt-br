---
title: Tratamento de exceção em MSVC
description: Visão geral do tratamento de exceção de referência do idioma C++.
ms.date: 04/15/2020
helpviewer_keywords:
- try-catch keyword [C++], exception handling
ms.assetid: a6aa08de-669d-4ce8-9ec3-ec20d1354fcf
ms.openlocfilehash: 0d60f49c6f1412925c19aaf497352940411b5d92
ms.sourcegitcommit: 0e4feb35b47c507947262d00349d4a893863a6d3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/15/2020
ms.locfileid: "81396271"
---
# <a name="exception-handling-in-msvc"></a>Tratamento de exceção em MSVC

Uma exceção é uma condição de erro, possivelmente fora do controle do programa, que impede que o programa continue sua execução normal. Certas operações, incluindo criação de objetos, entrada/saída de arquivos e chamadas de função feitas a partir de outros módulos, são todas fontes potenciais de exceções, mesmo quando seu programa está sendo executado corretamente. O código robusto antecipar e trata exceções. Para detectar erros lógicos, use afirmações em vez de exceções (consulte [Usando afirmações](/visualstudio/debugger/c-cpp-assertions)).

## <a name="kinds-of-exceptions"></a>Tipos de exceções

O compilador Microsoft C++ (MSVC) suporta três tipos de tratamento de exceção:

- [C++ manipulação de exceções](errors-and-exception-handling-modern-cpp.md)

   Para a maioria dos programas C++, você deve usar o manuseio de exceção C++. É um tipo seguro, e garante que os destruidores de objetos sejam invocados durante o desenrolar da pilha.

- [Tratamento estruturado de exceções](structured-exception-handling-c-cpp.md)

   O Windows fornece seu próprio mecanismo de exceção, chamado de tratamento estruturado de exceções (SEH). Não é recomendado para programação C++ ou MFC. Use o SEH apenas em programas que não sejam em MFC ou C.

- [Exceções do MFC:](../mfc/exception-handling-in-mfc.md)

   Desde a versão 3.0, o MFC tem usado exceções C++. Ele ainda suporta suas macros de manuseio de exceção mais antigas, que são semelhantes às exceções C++na forma. Para obter conselhos sobre a mistura de macros MFC e exceções C++, consulte [Exceções: Usando Macros MFC e Exceções C++.](../mfc/exceptions-using-mfc-macros-and-cpp-exceptions.md)

Use uma opção de compilador [/EH](../build/reference/eh-exception-handling-model.md) para especificar o modelo de manipulação de exceção a ser usado em um projeto C++. Standard C++ exception handling (**/EHsc**) é o padrão em novos projetos C++ no Visual Studio.

Não recomendamos que você misture os mecanismos de manipulação de exceção. Por exemplo, não use exceções C++ com tratamento estruturado de exceções. O uso do manuseio de exceção C++ torna exclusivamente o seu código mais portátil, e permite lidar com exceções de qualquer tipo. Para obter mais informações sobre as desvantagens do tratamento estruturado de exceções, consulte [Tratamento estruturado de exceções](structured-exception-handling-c-cpp.md).

## <a name="in-this-section"></a>Nesta seção

- [Práticas recomendadas modernas do C++ para exceções e manipulação de erros](errors-and-exception-handling-modern-cpp.md)

- [Como projetar tendo em vista a segurança da exceção](how-to-design-for-exception-safety.md)

- [Como realizar a interface entre códigos excepcional e não excepcional](how-to-interface-between-exceptional-and-non-exceptional-code.md)

- [As instruções try, catch e throw](try-throw-and-catch-statements-cpp.md)

- [Como os blocos catch são avaliados](how-catch-blocks-are-evaluated-cpp.md)

- [Exceções e Desenrolar stack](exceptions-and-stack-unwinding-in-cpp.md)

- [Especificações de exceção](exception-specifications-throw-cpp.md)

- [noexcept](noexcept-cpp.md)

- [Exceções C++ não tratadas](unhandled-cpp-exceptions.md)

- [Combinação de exceções C (estruturadas) e C++](mixing-c-structured-and-cpp-exceptions.md)

- [SEH (tratamento de exceções estruturado) (C/C++)](structured-exception-handling-c-cpp.md)

## <a name="see-also"></a>Confira também

[Referência de linguagem C++](cpp-language-reference.md)</br>
[Tratamento de exceções x64](../build/exception-handling-x64.md)</br>
[Tratamento de exceções (C++/CLI e C++/CX)](../extensions/exception-handling-cpp-component-extensions.md)
