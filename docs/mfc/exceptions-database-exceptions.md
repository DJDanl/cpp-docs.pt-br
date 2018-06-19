---
title: 'Exceções: Exceções de banco de dados | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- DAO [MFC], exceptions
- exceptions [MFC], database
- exception handling [MFC], databases
- ODBC exceptions [MFC]
- ODBC [MFC], exceptions
- database exceptions [MFC]
- databases [MFC], exception handling
- error codes [MFC], database exception handling
ms.assetid: 28daf260-f824-4be6-aecc-1f859e6dec26
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2168bc530accfdde6fad4d41cd68e94d3088f153
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33354293"
---
# <a name="exceptions-database-exceptions"></a>Exceções: exceções de banco de dados
Este artigo explica como manipular exceções de banco de dados. A maioria do material neste artigo se aplica se você estiver trabalhando com as classes MFC para conectividade aberta de banco de dados (ODBC) ou as classes MFC para objetos de acesso de dados (DAO). Específica a um ou outro modelo de material é marcado explicitamente. Os tópicos incluem:  
  
-   [Abordagens para tratamento de exceção](#_core_approaches_to_exception_handling)  
  
-   [Um exemplo de manipulação de exceção de banco de dados](#_core_a_database_exception.2d.handling_example)  
  
##  <a name="_core_approaches_to_exception_handling"></a> Abordagens para tratamento de exceção  
 A abordagem é o mesmo se você estiver trabalhando com DAO ou ODBC.  
  
 Você sempre deve escrever manipuladores de exceção para lidar com condições excepcionais.  
  
 É a abordagem mais pragmática para capturar exceções de banco de dados testar seu aplicativo com cenários de exceção. Determine as exceções de probabilidade que podem ocorrer por uma operação em seu código e forçar a exceção ocorrer. Em seguida, examine a saída de rastreamento para ver quais exceção ou examinar as informações de erro retornado no depurador. Isso lhe permite saber qual retornar códigos que será exibida para os cenários de exceção que você está usando.  
  
### <a name="error-codes-used-for-odbc-exceptions"></a>Códigos de erro usados para exceções ODBC  
 Além dos códigos de retorno definidos pelo framework, que têm nomes no formato **AFX_SQL_ERROR_XXX**, algumas [CDBExceptions](../mfc/reference/cdbexception-class.md) se baseiam no [ODBC](../data/odbc/odbc-basics.md) códigos de retorno. Os códigos de retorno para tais exceções têm nomes no formato **SQL_ERROR_XXX**.  
  
 Os códigos de retorno — definida pelo framework tanto definidas pelo ODBC — que as classes de banco de dados podem retornar estão documentados no [m_nRetCode](../mfc/reference/cdbexception-class.md#m_nretcode) membro de dados da classe `CDBException`. Informações adicionais sobre códigos de retorno definido pelo ODBC estão disponíveis no SDK do ODBC *referência do programador de* na biblioteca MSDN.  
  
### <a name="error-codes-used-for-dao-exceptions"></a>Códigos de erro usados para exceções DAO  
 Para exceções DAO, mais informações estão geralmente disponíveis. Você pode acessar informações de erro por meio de membros de um capturada três dados [CDaoException](../mfc/reference/cdaoexception-class.md) objeto:  
  
-   [m_pErrorInfo](../mfc/reference/cdaoexception-class.md#m_perrorinfo) contém um ponteiro para um [CDaoErrorInfo](../mfc/reference/cdaoerrorinfo-structure.md) objeto que encapsula informações de erro na coleção do DAO de objetos de erro associados com o banco de dados.  
  
-   [m_nAfxDaoError](../mfc/reference/cdaoexception-class.md#m_nafxdaoerror) contém um código de erro estendidas das classes DAO MFC. Esses códigos de erro, que têm nomes no formato **AFX_DAO_ERROR_XXX**, estão documentados em membro de dados em `CDaoException`.  
  
-   [m_scode](../mfc/reference/cdaoexception-class.md#m_scode) contém uma OLE `SCODE` do DAO, se aplicável. Raramente, você precisará trabalhar com esse código de erro, no entanto. Geralmente, mais informações estão disponíveis nos membros de dados. Consulte o membro de dados para obter mais informações `SCODE` valores.  
  
 Informações adicionais sobre erros, o tipo de objeto de erro DAO e a coleção de erros DAO DAO estão disponíveis na classe [CDaoException](../mfc/reference/cdaoexception-class.md).  
  
##  <a name="_core_a_database_exception.2d.handling_example"></a> Um exemplo de manipulação de exceção de banco de dados  
 O exemplo a seguir tenta construir um [CRecordset](../mfc/reference/crecordset-class.md)-derivados do objeto no heap com o **novo** operador e, em seguida, abra o conjunto de registros (para uma fonte de dados ODBC). Para obter um exemplo semelhante para as classes DAO, consulte "DAO exceção exemplo" abaixo.  
  
### <a name="odbc-exception-example"></a>Exemplo de exceção de ODBC  
 O [abrir](../mfc/reference/crecordset-class.md#open) função de membro pode gerar uma exceção (do tipo [CDBException](../mfc/reference/cdbexception-class.md) para as classes ODBC), portanto esse código colchetes o **abrir** chamada com um **tente**  bloco. Próximos **catch** bloco irá capturar um `CDBException`. Você pode examinar o objeto de exceção em si, chamado `e`, mas nesse caso é suficiente para saber que a tentativa de criar um conjunto de registros falhou. O **catch** bloco exibe uma caixa de mensagem e limpa, excluindo o objeto de conjunto de registros.  
  
 [!code-cpp[NVC_MFCDatabase#36](../mfc/codesnippet/cpp/exceptions-database-exceptions_1.cpp)]  
  
### <a name="dao-exception-example"></a>Exemplo de exceção DAO  
 O exemplo DAO é semelhante ao exemplo para ODBC, mas normalmente você pode recuperar mais tipos de informações. O código a seguir também tenta abrir um conjunto de registros. Se essa tentativa lança uma exceção, você pode examinar um membro de dados do objeto de exceção para obter informações de erro. Como com o exemplo anterior do ODBC, provavelmente é suficiente para saber que houve falha na tentativa de criar um conjunto de registros.  
  
 [!code-cpp[NVC_MFCDatabase#37](../mfc/codesnippet/cpp/exceptions-database-exceptions_2.cpp)]  
  
 Esse código obtém uma cadeia de caracteres de mensagem de erro do [m_pErrorInfo](../mfc/reference/cdaoexception-class.md#m_perrorinfo) membro do objeto de exceção. MFC preenche esse membro quando ele lança a exceção.  
  
 Para obter uma discussão das informações de erro retornadas por um `CDaoException` de objeto, consulte classes [CDaoException](../mfc/reference/cdaoexception-class.md) e [CDaoErrorInfo](../mfc/reference/cdaoerrorinfo-structure.md).  
  
 Quando você estiver trabalhando com bancos de dados Microsoft Jet (. mdb) e na maioria dos casos, quando você estiver trabalhando com ODBC, haverá apenas um objeto de erro. No caso raro quando você estiver usando uma fonte de dados ODBC e houver vários erros, você pode executar um loop pela coleção de erros do DAO com base no número de erros retornados pelo [CDaoException::GetErrorCount](../mfc/reference/cdaoexception-class.md#geterrorcount). Cada vez pelo loop, chame [CDaoException::GetErrorInfo](../mfc/reference/cdaoexception-class.md#geterrorinfo) reabastecimento o `m_pErrorInfo` membro de dados.  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)

