---
title: 'Exceções: Exceções do Banco de Dados'
ms.date: 09/17/2019
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
ms.openlocfilehash: c279c5b788cc7bd8a68fe36128c116d8df91c2eb
ms.sourcegitcommit: 2f96e2fda591d7b1b28842b2ea24e6297bcc3622
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2019
ms.locfileid: "71095819"
---
# <a name="exceptions-database-exceptions"></a>Exceções: Exceções do Banco de Dados

Este artigo explica como lidar com exceções de banco de dados. A maior parte do material neste artigo se aplica se você estiver trabalhando com as classes do MFC para ODBC (Open Database Connectivity) ou as classes do MFC para DAO (objetos de acesso a dados). Material específico para um ou outro modelo está explicitamente marcado. Os tópicos incluem:

- [Abordagens para manipulação de exceção](#_core_approaches_to_exception_handling)

- [Um exemplo de manipulação de exceção de banco de dados](#_core_a_database_exception.2d.handling_example)

##  <a name="_core_approaches_to_exception_handling"></a>Abordagens para manipulação de exceção

A abordagem é a mesma se você estiver trabalhando com DAO (obsoleto) ou ODBC.

Você deve sempre escrever manipuladores de exceção para lidar com condições excepcionais.

A abordagem mais pragmática para capturar exceções de banco de dados é testar seu aplicativo com cenários de exceção. Determinar as exceções prováveis que podem ocorrer para uma operação em seu código e forçar a ocorrência da exceção. Em seguida, examine a saída de rastreamento para ver qual exceção é lançada ou examine as informações de erro retornadas no depurador. Isso permite que você saiba quais códigos de retorno serão exibidos para os cenários de exceção que você está usando.

### <a name="error-codes-used-for-odbc-exceptions"></a>Códigos de erro usados para exceções ODBC

Além dos códigos de retorno definidos pela estrutura, que têm nomes no formato **AFX_SQL_ERROR_XXX**, alguns [CDBExceptions](../mfc/reference/cdbexception-class.md) são baseados em códigos de retorno [ODBC](../data/odbc/odbc-basics.md) . Os códigos de retorno para essas exceções têm nomes no formato **SQL_ERROR_XXX**.

Os códigos de retorno, definidos pelo Framework e definidos pelo ODBC, que as classes de banco de dados podem retornar são documentados sob o membro de dados [m_nRetCode](../mfc/reference/cdbexception-class.md#m_nretcode) de classe `CDBException`. Informações adicionais sobre códigos de retorno definidos pelo ODBC estão disponíveis na *referência do programador do* ODBC SDK na biblioteca MSDN.

### <a name="error-codes-used-for-dao-exceptions"></a>Códigos de erro usados para exceções do DAO

Para exceções do DAO, mais informações estão normalmente disponíveis. Você pode acessar informações de erro por meio de três membros de dados de um objeto [CDaoException](../mfc/reference/cdaoexception-class.md) capturado:

- [m_pErrorInfo](../mfc/reference/cdaoexception-class.md#m_perrorinfo) contém um ponteiro para um objeto [CDaoErrorInfo](../mfc/reference/cdaoerrorinfo-structure.md) que encapsula informações de erro na coleção do DAO de objetos de erro associados ao banco de dados.

- [m_nAfxDaoError](../mfc/reference/cdaoexception-class.md#m_nafxdaoerror) contém um código de erro estendido das classes do MFC DAO. Esses códigos de erro, que têm nomes no formato **AFX_DAO_ERROR_XXX**, são documentados sob o membro de `CDaoException`dados em.

- [m_scode](../mfc/reference/cdaoexception-class.md#m_scode) contém um **SCODE** OLE do DAO, se aplicável. No entanto, você raramente precisará trabalhar com esse código de erro. Geralmente, mais informações estão disponíveis nos outros dois membros de dados. Consulte o membro de dados para obter mais informações sobre valores de **SCODE** .

Informações adicionais sobre erros do DAO, o tipo de objeto de erro do DAO e a coleção de erros do DAO estão disponíveis na classe [CDaoException](../mfc/reference/cdaoexception-class.md).

##  <a name="_core_a_database_exception.2d.handling_example"></a>Um exemplo de manipulação de exceção de banco de dados

O exemplo a seguir tenta construir um objeto derivado de [CRecordset](../mfc/reference/crecordset-class.md)no heap com o **novo** operador e, em seguida, abrir o conjunto de registros (para uma fonte de dados ODBC). Para obter um exemplo semelhante para as classes DAO, consulte "exemplo de exceção do DAO" abaixo.

### <a name="odbc-exception-example"></a>Exemplo de exceção ODBC

A função [Open](../mfc/reference/crecordset-class.md#open) member pode lançar uma exceção (do tipo [CDBException](../mfc/reference/cdbexception-class.md) para as classes ODBC), portanto, esse código tem o `Open` colchete na chamada com um bloco **try** . O bloco **Catch** subsequente irá capturar um `CDBException`. Você pode examinar o próprio objeto de exceção, `e`chamado, mas, nesse caso, é suficiente saber que a tentativa de criar um conjunto de registros falhou. O bloco **Catch** exibe uma caixa de mensagem e limpa excluindo o objeto Recordset.

[!code-cpp[NVC_MFCDatabase#36](../mfc/codesnippet/cpp/exceptions-database-exceptions_1.cpp)]

### <a name="dao-exception-example"></a>Exemplo de exceção do DAO

O exemplo de DAO é semelhante ao exemplo de ODBC, mas normalmente você pode recuperar mais tipos de informações. O código a seguir também tenta abrir um conjunto de registros. Se essa tentativa lançar uma exceção, você poderá examinar um membro de dados do objeto de exceção para obter informações sobre o erro. Assim como no exemplo de ODBC anterior, é provável que seja suficiente saber que houve falha na tentativa de criar um conjunto de registros.

[!code-cpp[NVC_MFCDatabase#37](../mfc/codesnippet/cpp/exceptions-database-exceptions_2.cpp)]

Esse código obtém uma cadeia de caracteres de mensagem de erro do membro [m_pErrorInfo](../mfc/reference/cdaoexception-class.md#m_perrorinfo) do objeto de exceção. O MFC preenche esse membro quando ele gera a exceção.

Para obter uma discussão sobre as informações de erro retornadas por um `CDaoException` objeto, consulte classes [CDaoException](../mfc/reference/cdaoexception-class.md) e [CDaoErrorInfo](../mfc/reference/cdaoerrorinfo-structure.md).

Quando você estiver trabalhando com bancos de dados do Microsoft Jet (. mdb) e, na maioria dos casos, quando estiver trabalhando com o ODBC, haverá apenas um objeto de erro. No caso raro, quando você estiver usando uma fonte de dados ODBC e houver vários erros, poderá executar um loop através da coleção de erros do DAO com base no número de erros retornados por [CDaoException:: GetErrorCount](../mfc/reference/cdaoexception-class.md#geterrorcount). Cada vez pelo loop, chame [CDaoException:: GetErrorInfo](../mfc/reference/cdaoexception-class.md#geterrorinfo) para reabastecer o `m_pErrorInfo` membro de dados.

## <a name="see-also"></a>Consulte também

[Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)
