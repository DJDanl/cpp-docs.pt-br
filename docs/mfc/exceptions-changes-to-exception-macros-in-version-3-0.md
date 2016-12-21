---
title: "Exce&#231;&#245;es: altera&#231;&#245;es feitas em macros de exce&#231;&#227;o na vers&#227;o 3.0 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tratamento de exceção de C++, considerações sobre atualização"
  - "Macro CATCH"
  - "exceções, o que foi alterado"
  - "Macro THROW_LAST"
ms.assetid: 3aa20d8c-229e-449c-995c-ab879eac84bc
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Exce&#231;&#245;es: altera&#231;&#245;es feitas em macros de exce&#231;&#227;o na vers&#227;o 3.0
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este é um tópico avançada.  
  
 MFC na versão 3,0 e posterior, as macros manipulação de exceções gerais foram modificados para usar exceções C\+\+.  Este artigo informa como essas alterações podem afetar o comportamento de código existente que usa macros.  
  
 Este artigo abrange os seguintes tópicos:  
  
-   [Tipos de exceção e a macro CATCH](#_core_exception_types_and_the_catch_macro)  
  
-   [Lançando exceções](#_core_re.2d.throwing_exceptions)  
  
##  <a name="_core_exception_types_and_the_catch_macro"></a> Tipos de exceção e a macro CATCH  
 Em versões anteriores de MFC, a macro de **CATCH** usou as informações de tipo de tempo de execução MFC para determinar um tipo de exceção; o tipo de exceção é determinado, ou está no site de captura.  Com exceções C\+\+, porém, o tipo de exceção sempre é determinada no site de lançamento pelo tipo de objeto de exceção que é lançada.  Isso causará incompatibilidades em casos raros onde o tipo de ponteiro para um objeto é diferente do tipo de objeto lançado.  
  
 O exemplo a seguir ilustra ao resultado dessa diferença entre a versão 3,0 MFC o e versões anteriores:  
  
 [!code-cpp[NVC_MFCExceptions#1](../mfc/codesnippet/CPP/exceptions-changes-to-exception-macros-in-version-3-0_1.cpp)]  
  
 Esse código se comporta de maneira diferente na versão 3,0 porque o controle passa sempre o primeiro bloco de **catch** com exceções gerais uma declaração de correspondência.  O resultado da expressão do lançamento  
  
 [!code-cpp[NVC_MFCExceptions#19](../mfc/codesnippet/CPP/exceptions-changes-to-exception-macros-in-version-3-0_2.cpp)]  
  
 é gerado como **CException\***, mesmo que é criado como **CCustomException**.  A macro de **CATCH** nas versões 2,5 MFC e no anteriores `CObject::IsKindOf` testar em tempo de execução do tipo.  Como a expressão  
  
 [!code-cpp[NVC_MFCExceptions#20](../mfc/codesnippet/CPP/exceptions-changes-to-exception-macros-in-version-3-0_3.cpp)]  
  
 forem verdadeiras, as primeiras captura do bloco de captura a exceção.  Na versão 3,0, que usa exceções C\+\+ para implementar vários macros manipulação de exceções gerais, o segundo bloco de captura corresponde `CException`lançado.  
  
 O código como isso é raro.  Normalmente aparece quando um objeto de exceção é passado para outra função que aceita **CException\***genérico, executa o processamento de “previamente geram”, e finalmente gerou a exceção.  
  
 Para resolver esse problema, mova a expressão do lançamento da função ao código de chamada e gerar uma exceção do tipo real conhecido do compilador a exceção é gerada.  
  
##  <a name="_core_re.2d.throwing_exceptions"></a> Lançando exceções  
 Um bloco de captura não pode gerar o mesmo ponteiro de exceção que capturou.  
  
 Por exemplo, esse código não era válido nas versões anteriores, mas terá resultados inesperados com a versão 3,0:  
  
 [!code-cpp[NVC_MFCExceptions#2](../mfc/codesnippet/CPP/exceptions-changes-to-exception-macros-in-version-3-0_4.cpp)]  
  
 Usar **THROW** no bloco de captura faz com que o ponteiro `e` a ser excluído, de modo que o site externo de captura recebe um ponteiro inválido.  Use o novo `e`lançamento de `THROW_LAST` .  
  
 Para obter mais informações, consulte [Exceções: Capturando e excluindo exceções](../mfc/exceptions-catching-and-deleting-exceptions.md).  
  
## Consulte também  
 [Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)