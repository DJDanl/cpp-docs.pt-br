---
title: 'Exceções: alterações feitas em macros de exceção na versão 3.0'
ms.date: 11/04/2016
helpviewer_keywords:
- C++ exception handling [MFC], upgrade considerations
- CATCH macro [MFC]
- exceptions [MFC], what's changed
- THROW_LAST macro [MFC]
ms.assetid: 3aa20d8c-229e-449c-995c-ab879eac84bc
ms.openlocfilehash: 72b343641b0b43d408c5820ca2a2af1de94ce327
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225053"
---
# <a name="exceptions-changes-to-exception-macros-in-version-30"></a>Exceções: alterações feitas em macros de exceção na versão 3.0

Este é um tópico avançado.

No MFC versão 3,0 e posterior, as macros de tratamento de exceções foram alteradas para usar exceções C++. Este artigo informa como essas alterações podem afetar o comportamento do código existente que usa as macros.

Este artigo aborda os seguintes tópicos:

- [Tipos de exceção e a macro CATCH](#_core_exception_types_and_the_catch_macro)

- [Relançando exceções](#_core_re.2d.throwing_exceptions)

## <a name="exception-types-and-the-catch-macro"></a><a name="_core_exception_types_and_the_catch_macro"></a>Tipos de exceção e a macro CATCH

Em versões anteriores do MFC, a macro **Catch** usava informações de tipo de tempo de execução do MFC para determinar o tipo de uma exceção; o tipo da exceção é determinado, em outras palavras, no site de captura. Com as exceções do C++, no entanto, o tipo da exceção é sempre determinado no site de lançamento pelo tipo do objeto de exceção que é gerado. Isso causará incompatibilidades no caso raro em que o tipo do ponteiro para o objeto gerado difere do tipo do objeto gerado.

O exemplo a seguir ilustra a consequência dessa diferença entre o MFC versão 3,0 e versões anteriores:

[!code-cpp[NVC_MFCExceptions#1](codesnippet/cpp/exceptions-changes-to-exception-macros-in-version-3-0_1.cpp)]

Esse código se comporta de forma diferente na versão 3,0 porque o controle sempre passa para o primeiro **`catch`** bloco com uma declaração de exceção correspondente. O resultado da expressão throw

[!code-cpp[NVC_MFCExceptions#19](codesnippet/cpp/exceptions-changes-to-exception-macros-in-version-3-0_2.cpp)]

é lançado como um `CException*` , mesmo que seja construído como um `CCustomException` . A macro **Catch** no MFC versões 2,5 e anteriores usa `CObject::IsKindOf` para testar o tipo em tempo de execução. Porque a expressão

[!code-cpp[NVC_MFCExceptions#20](codesnippet/cpp/exceptions-changes-to-exception-macros-in-version-3-0_3.cpp)]

é true, o primeiro bloco catch captura a exceção. Na versão 3,0, que usa exceções do C++ para implementar muitas das macros de tratamento de exceção, o segundo bloco catch corresponde ao gerado `CException` .

Um código como esse não é comum. Ele geralmente aparece quando um objeto de exceção é passado para outra função que aceita um genérico `CException*` , executa o processamento de "pré-lançamento" e, por fim, gera a exceção.

Para contornar esse problema, mova a expressão throw da função para o código de chamada e lance uma exceção do tipo real conhecido para o compilador no momento em que a exceção é gerada.

## <a name="re-throwing-exceptions"></a><a name="_core_re.2d.throwing_exceptions"></a>Relançando exceções

Um bloco catch não pode lançar o mesmo ponteiro de exceção que ele capturou.

Por exemplo, esse código era válido em versões anteriores, mas terá resultados inesperados com a versão 3,0:

[!code-cpp[NVC_MFCExceptions#2](codesnippet/cpp/exceptions-changes-to-exception-macros-in-version-3-0_4.cpp)]

O uso de **throw** no bloco catch faz com que o ponteiro `e` seja excluído, para que o site de captura externo receba um ponteiro inválido. Use **THROW_LAST** para lançar novamente `e` .

Para obter mais informações, consulte [exceções: capturando e excluindo exceções](exceptions-catching-and-deleting-exceptions.md).

## <a name="see-also"></a>Confira também

[Tratamento de exceção](exception-handling-in-mfc.md)
