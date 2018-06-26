---
title: 'Exceções: Alterações em Macros de exceção na versão 3.0 | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- C++ exception handling [MFC], upgrade considerations
- CATCH macro [MFC]
- exceptions [MFC], what's changed
- THROW_LAST macro [MFC]
ms.assetid: 3aa20d8c-229e-449c-995c-ab879eac84bc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1c4e6c7744c3d5328985eee24e67ee1eb359fb3c
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36931012"
---
# <a name="exceptions-changes-to-exception-macros-in-version-30"></a>Exceções: alterações feitas em macros de exceção na versão 3.0
Este é um tópico avançado.  
  
 Em MFC versão 3.0 e posterior, as macros de tratamento de exceções foram alteradas para usar as exceções do C++. Este artigo mostra como essas alterações podem afetar o comportamento do código existente que usa as macros.  
  
 Este artigo aborda os seguintes tópicos:  
  
-   [Tipos de exceção e a macro CATCH](#_core_exception_types_and_the_catch_macro)  
  
-   [Lançar exceções](#_core_re.2d.throwing_exceptions)  
  
##  <a name="_core_exception_types_and_the_catch_macro"></a> Tipos de exceção e a Macro CATCH  
 Em versões anteriores do MFC, o **CATCH** macro usada informações de tipo de tempo de execução do MFC para determinar o tipo da exceção; tipo da exceção é determinado, em outras palavras, no local de catch. Com as exceções do C++, no entanto, tipo da exceção é sempre determinado no site throw pelo tipo de objeto de exceção que é lançado. Isso fará com que a incompatibilidades em casos raros em que o tipo de ponteiro para o objeto lançado difere do tipo do objeto descartado.  
  
 O exemplo a seguir ilustra a consequência desta diferença entre MFC versão 3.0 e versões anteriores:  
  
 [!code-cpp[NVC_MFCExceptions#1](../mfc/codesnippet/cpp/exceptions-changes-to-exception-macros-in-version-3-0_1.cpp)]  
  
 Esse código tem um comportamento diferente na versão 3.0 como sempre, o controle passará para o primeiro **catch** bloco com uma declaração de exceção correspondente. O resultado da expressão throw  
  
 [!code-cpp[NVC_MFCExceptions#19](../mfc/codesnippet/cpp/exceptions-changes-to-exception-macros-in-version-3-0_2.cpp)]  
  
 é gerada como um `CException*`, mesmo que ele é criado como um `CCustomException`. O **CATCH** macro na versão 2.5 do MFC e usa anteriores `CObject::IsKindOf` para testar o tipo em tempo de execução. Porque a expressão  
  
 [!code-cpp[NVC_MFCExceptions#20](../mfc/codesnippet/cpp/exceptions-changes-to-exception-macros-in-version-3-0_3.cpp)]  
  
 é verdadeiro, o primeiro bloco catch captura a exceção. Na versão 3.0, que usa as exceções do C++ para implementar muitas das macros a manipulação de exceção, o segundo bloco catch corresponde a lançado `CException`.  
  
 Como este é incomum. Ele geralmente é exibida quando um objeto de exceção é transmitido a outra função que aceita um genérico `CException*`, realiza o processamento de "pré-lançamento" e, finalmente, lança a exceção.  
  
 Para contornar esse problema, mova a expressão throw da função para o código de chamada e lançar uma exceção do tipo real conhecido para o compilador no momento em que a exceção é gerada.  
  
##  <a name="_core_re.2d.throwing_exceptions"></a> Lançar exceções  
 Um bloco catch não pode gerar o mesmo ponteiro de exceção capturado por ele.  
  
 Por exemplo, este código foi válido em versões anteriores, mas terá resultados inesperados com versão 3.0:  
  
 [!code-cpp[NVC_MFCExceptions#2](../mfc/codesnippet/cpp/exceptions-changes-to-exception-macros-in-version-3-0_4.cpp)]  
  
 Usando **gerar** em catch bloco faz com que o ponteiro `e` a ser excluído, para que o site externo catch receberá um ponteiro inválido. Use **THROW_LAST** para gerar novamente `e`.  
  
 Para obter mais informações, consulte [exceções: exceções de detectar e excluindo](../mfc/exceptions-catching-and-deleting-exceptions.md).  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)

