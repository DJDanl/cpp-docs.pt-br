---
title: Tratamento de exceção em MSVC
ms.date: 11/19/2019
helpviewer_keywords:
- try-catch keyword [C++], exception handling
ms.assetid: a6aa08de-669d-4ce8-9ec3-ec20d1354fcf
ms.openlocfilehash: 6cf71d6e6d0519951a084ebead65003bd363395f
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74246587"
---
# <a name="exception-handling-in-msvc"></a>Tratamento de exceção em MSVC

Uma exceção é uma condição de erro, possivelmente fora do controle do programa, que impede que o programa continue sua execução normal. Determinadas operações, incluindo a criação do objetos, a entrada/saída de arquivos e as chamadas de função feitas de outros módulos, são todas possíveis fontes de exceções até mesmo quando seu programa é executado corretamente. O código robusto antecipar e trata exceções. Para detectar erros lógicos, use asserções em vez de exceções (consulte [usando asserções](/visualstudio/debugger/c-cpp-assertions)).

## <a name="kinds-of-exceptions"></a>Tipos de exceções

O compilador C++ da Microsoft (MSVC) dá suporte a três tipos de manipulação de exceção:

- [C++tratamento de exceção](errors-and-exception-handling-modern-cpp.md)

   Para a maioria dos programas em C++, você deve usar o tratamento de exceções do C++, que é fortemente tipado e assegura que os destruidores de objeto sejam chamados durante o desenrolamento de pilha.

- [Manipulação de exceção estruturada](structured-exception-handling-c-cpp.md)

   O Windows fornece seu próprio mecanismo de exceção, chamado SEH. Ele não é recomendável para a programação em C++ ou MFC. Use SEH somente em programas não MFC C.

- [Exceções do MFC](../mfc/exception-handling-in-mfc.md)

Use a opção de compilador [/eh](../build/reference/eh-exception-handling-model.md) para especificar o tipo de tratamento de exceção a ser usado em um projeto; C++ o tratamento de exceção é o padrão. Não combine os mecanismos de tratamento de erro, por exemplo, não use exceções do C++ com manipulação de exceções estruturada. Usar manipulação de exceções C++ torna seu código mais portável e permite que você manipule exceções de qualquer tipo. Para obter mais informações sobre as desvantagens da manipulação de exceção estruturada, consulte [manipulação de exceção estruturada](structured-exception-handling-c-cpp.md). Para obter conselhos sobre como misturar macros e C++ exceções do MFC, consulte [exceções: C++ usando macros e exceções do MFC](../mfc/exceptions-using-mfc-macros-and-cpp-exceptions.md).

## <a name="in-this-section"></a>Nesta seção

- [Práticas C++ recomendadas modernas para exceções e tratamento de erros](errors-and-exception-handling-modern-cpp.md)

- [Como projetar para segurança de exceção](how-to-design-for-exception-safety.md)

- [Como interagir entre códigos excepcionais e não excepcionais](how-to-interface-between-exceptional-and-non-exceptional-code.md)

- [As instruções Try, catch e throw](try-throw-and-catch-statements-cpp.md)

- [Como os blocos catch são avaliados](how-catch-blocks-are-evaluated-cpp.md)

- [Exceções e desenrolamento de pilha](exceptions-and-stack-unwinding-in-cpp.md)

- [Especificações de exceção](exception-specifications-throw-cpp.md)

- [noexcept](noexcept-cpp.md)

- [Exceções C++ não tratadas](unhandled-cpp-exceptions.md)

- [Combinação de exceções C (estruturadas) e C++](mixing-c-structured-and-cpp-exceptions.md)

- [Manipulação de exceção estruturada (SEH) (C++C/)](structured-exception-handling-c-cpp.md)

## <a name="see-also"></a>Consulte também

[Referência da linguagem C++](cpp-language-reference.md)</br>
[Tratamento de exceções x64](../build/exception-handling-x64.md)</br>
[Tratamento de exceçãoC++(/CLI C++e/CX)](../extensions/exception-handling-cpp-component-extensions.md)
