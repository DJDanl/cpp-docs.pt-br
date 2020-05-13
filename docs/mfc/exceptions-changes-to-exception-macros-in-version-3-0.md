---
title: 'Exceções: alterações feitas em macros de exceção na versão 3.0'
ms.date: 11/04/2016
helpviewer_keywords:
- C++ exception handling [MFC], upgrade considerations
- CATCH macro [MFC]
- exceptions [MFC], what's changed
- THROW_LAST macro [MFC]
ms.assetid: 3aa20d8c-229e-449c-995c-ab879eac84bc
ms.openlocfilehash: 82320b0c7ccd6766e016f0437633339f8f8f61d6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365487"
---
# <a name="exceptions-changes-to-exception-macros-in-version-30"></a>Exceções: alterações feitas em macros de exceção na versão 3.0

Este é um tópico avançado.

Na versão 3.0 do MFC e posterior, as macros de manipulação de exceções foram alteradas para usar exceções C++. Este artigo diz como essas alterações podem afetar o comportamento do código existente que usa as macros.

Este artigo aborda os seguintes tópicos:

- [Tipos de exceção e a macro CATCH](#_core_exception_types_and_the_catch_macro)

- [Re-jogando exceções](#_core_re.2d.throwing_exceptions)

## <a name="exception-types-and-the-catch-macro"></a><a name="_core_exception_types_and_the_catch_macro"></a>Tipos de exceção e a macro CATCH

Nas versões anteriores do MFC, a macro **CATCH** usava informações do tipo de tempo de execução do MFC para determinar o tipo de exceção; o tipo de exceção é determinado, em outras palavras, no local de captura. Com exceções C++, no entanto, o tipo de exceção é sempre determinado no local de lançamento pelo tipo de objeto de exceção que é lançado. Isso causará incompatibilidades no caso raro em que o tipo de ponteiro para o objeto jogado difere do tipo do objeto jogado.

O exemplo a seguir ilustra a conseqüência dessa diferença entre a versão 3.0 do MFC e as versões anteriores:

[!code-cpp[NVC_MFCExceptions#1](../mfc/codesnippet/cpp/exceptions-changes-to-exception-macros-in-version-3-0_1.cpp)]

Este código se comporta de forma diferente na versão 3.0 porque o controle sempre passa para o primeiro bloco de **captura** com uma declaração de exceção correspondente. O resultado da expressão de arremesso

[!code-cpp[NVC_MFCExceptions#19](../mfc/codesnippet/cpp/exceptions-changes-to-exception-macros-in-version-3-0_2.cpp)]

é jogado `CException*`como um , mesmo que `CCustomException`seja construído como um . A **macro CATCH** nas versões 2.5 do MFC e anteriormente é usa `CObject::IsKindOf` para testar o tipo em tempo de execução. Porque a expressão

[!code-cpp[NVC_MFCExceptions#20](../mfc/codesnippet/cpp/exceptions-changes-to-exception-macros-in-version-3-0_3.cpp)]

é verdade, o primeiro bloco de captura pega a exceção. Na versão 3.0, que usa exceções C++ para implementar muitas das macros de `CException`manipulação de exceção, o segundo bloco de captura corresponde ao lançado .

Códigos como este são incomuns. Geralmente aparece quando um objeto de exceção é `CException*`passado para outra função que aceita um genérico, realiza o processamento de "pré-lançamento" e finalmente lança a exceção.

Para contornar esse problema, mova a expressão de lançamento da função para o código de chamada e lance uma exceção do tipo real conhecido pelo compilador no momento em que a exceção é gerada.

## <a name="re-throwing-exceptions"></a><a name="_core_re.2d.throwing_exceptions"></a>Exceções de relançamento

Um bloco de captura não pode lançar o mesmo ponteiro de exceção que ele pegou.

Por exemplo, este código era válido em versões anteriores, mas terá resultados inesperados com a versão 3.0:

[!code-cpp[NVC_MFCExceptions#2](../mfc/codesnippet/cpp/exceptions-changes-to-exception-macros-in-version-3-0_4.cpp)]

O uso **do THROW** no `e` bloco de captura faz com que o ponteiro seja excluído, de modo que o local de captura externo receba um ponteiro inválido. Use **THROW_LAST** para `e`relançar .

Para obter mais informações, consulte [Exceções: Captura e Exclusão de Exceções](../mfc/exceptions-catching-and-deleting-exceptions.md).

## <a name="see-also"></a>Confira também

[Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)
