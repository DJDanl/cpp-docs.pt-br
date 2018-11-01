---
title: 'Exceções: alterações feitas em macros de exceção na versão 3.0'
ms.date: 11/04/2016
helpviewer_keywords:
- C++ exception handling [MFC], upgrade considerations
- CATCH macro [MFC]
- exceptions [MFC], what's changed
- THROW_LAST macro [MFC]
ms.assetid: 3aa20d8c-229e-449c-995c-ab879eac84bc
ms.openlocfilehash: 54826ee7a7ac129ae69715b45770a0a66596a2a3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50607981"
---
# <a name="exceptions-changes-to-exception-macros-in-version-30"></a>Exceções: alterações feitas em macros de exceção na versão 3.0

Este é um tópico avançado.

No MFC versão 3.0 e posterior, as macros de tratamento de exceção foram alteradas para usar as exceções do C++. Este artigo informa como essas alterações podem afetar o comportamento do código existente que usa as macros.

Este artigo aborda os seguintes tópicos:

- [Tipos de exceção e a macro CATCH](#_core_exception_types_and_the_catch_macro)

- [Lançar exceções](#_core_re.2d.throwing_exceptions)

##  <a name="_core_exception_types_and_the_catch_macro"></a> Tipos de exceção e a Macro CATCH

Em versões anteriores do MFC, o **CATCH** macro usada informações de tipo de tempo de execução do MFC para determinar o tipo de uma exceção; o tipo de exceção é determinado, em outras palavras, no local de catch. Com exceções de C++, no entanto, o tipo de exceção é sempre determinado no site de throw pelo tipo do objeto de exceção que é lançado. Isso fará com que as incompatibilidades em casos raros em que o tipo do ponteiro para o objeto gerado difere do tipo do objeto gerado.

O exemplo a seguir ilustra a consequência dessa diferença entre o MFC versão 3.0 e versões anteriores:

[!code-cpp[NVC_MFCExceptions#1](../mfc/codesnippet/cpp/exceptions-changes-to-exception-macros-in-version-3-0_1.cpp)]

Esse código tem um comportamento diferente na versão 3.0 como sempre, o controle passa para a primeira **catch** bloco com uma declaração de exceção correspondente. O resultado da expressão throw

[!code-cpp[NVC_MFCExceptions#19](../mfc/codesnippet/cpp/exceptions-changes-to-exception-macros-in-version-3-0_2.cpp)]

é lançada como uma `CException*`, mesmo que ele é criado como um `CCustomException`. O **CATCH** macro em versões MFC 2.5 e versões anteriores usam `CObject::IsKindOf` para testar o tipo de tempo de execução. Porque a expressão

[!code-cpp[NVC_MFCExceptions#20](../mfc/codesnippet/cpp/exceptions-changes-to-exception-macros-in-version-3-0_3.cpp)]

é verdadeiro, o primeiro bloco catch captura a exceção. Na versão 3.0, que usa as exceções do C++ para implementar muitas das macros de tratamento de exceção, o segundo bloco catch corresponde a lançada `CException`.

Código como este é incomum. Ele normalmente é exibida quando um objeto de exceção é passado para outra função que aceita um genérico `CException*`, executa o processamento de "pré-lançamento" e, finalmente, lança a exceção.

Para contornar esse problema, mova a expressão de lançamento da função para o código de chamada e lançar uma exceção do tipo real conhecido do compilador no momento em que a exceção é gerada.

##  <a name="_core_re.2d.throwing_exceptions"></a> Lançar exceções

Um bloco catch não pode gerar o mesmo ponteiro de exceção que ela capturada.

Por exemplo, esse código era válido nas versões anteriores, mas terá resultados inesperados com a versão 3.0:

[!code-cpp[NVC_MFCExceptions#2](../mfc/codesnippet/cpp/exceptions-changes-to-exception-macros-in-version-3-0_4.cpp)]

Usando o **lançar** em catch bloco faz com que o ponteiro `e` a ser excluído, para que o site externo catch receberá um ponteiro inválido. Use **THROW_LAST** para gerar novamente `e`.

Para obter mais informações, consulte [exceções: exceções de detectar e exclua](../mfc/exceptions-catching-and-deleting-exceptions.md).

## <a name="see-also"></a>Consulte também

[Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)

