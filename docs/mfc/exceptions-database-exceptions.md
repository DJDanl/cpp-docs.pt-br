---
title: 'Exceções: exceções de banco de dados'
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
ms.openlocfilehash: 894960338a7e8c293054ade00e0cdf3295648bb7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366624"
---
# <a name="exceptions-database-exceptions"></a>Exceções: exceções de banco de dados

Este artigo explica como lidar com exceções de banco de dados. A maior parte do material deste artigo se aplica se você está trabalhando com as classes MFC para Conectividade de Banco de Dados Aberto (ODBC) ou as classes MFC para Objetos de Acesso de Dados (DAO). O material específico de um ou outro modelo está explicitamente marcado. Os tópicos incluem:

- [Abordagens para o manuseio de exceções](#_core_approaches_to_exception_handling)

- [Um exemplo de manipulação de exceção de banco de dados](#_core_a_database_exception.2d.handling_example)

## <a name="approaches-to-exception-handling"></a><a name="_core_approaches_to_exception_handling"></a>Abordagens para o tratamento de exceções

A abordagem é a mesma se você estiver trabalhando com DAO (obsoleto) ou ODBC.

Você deve sempre escrever manipuladores de exceção para lidar com condições excepcionais.

A abordagem mais pragmática para capturar exceções de banco de dados é testar sua aplicação com cenários de exceção. Determine as exceções prováveis que podem ocorrer para uma operação em seu código e force a exceção a ocorrer. Em seguida, examine a saída de rastreamento para ver qual exceção é lançada ou examine as informações de erro retornadas no depurador. Isso permite que você saiba quais códigos de retorno você verá para os cenários de exceção que você está usando.

### <a name="error-codes-used-for-odbc-exceptions"></a>Códigos de erro usados para exceções ODBC

Além dos códigos de devolução definidos pelo framework, que têm nomes do formulário **AFX_SQL_ERROR_XXX,** [alguns CDBExceptions](../mfc/reference/cdbexception-class.md) são baseados em códigos de retorno [ODBC.](../data/odbc/odbc-basics.md) Os códigos de devolução para tais exceções têm nomes do formulário **SQL_ERROR_XXX**.

Os códigos de retorno, definidos pelo Framework e definidos pelo ODBC, que as classes de banco de dados podem retornar são documentados sob o membro de dados [m_nRetCode](../mfc/reference/cdbexception-class.md#m_nretcode) de classe `CDBException`. Informações adicionais sobre códigos de retorno definidos pela ODBC estão disponíveis na *Referência do Programador* ODBC SDK na Biblioteca MSDN.

### <a name="error-codes-used-for-dao-exceptions"></a>Códigos de erro usados para exceções de DAO

Para exceções de DAO, mais informações estão normalmente disponíveis. Você pode acessar informações de erro através de três membros de dados de um objeto [CDaoException](../mfc/reference/cdaoexception-class.md) capturado:

- [m_pErrorInfo](../mfc/reference/cdaoexception-class.md#m_perrorinfo) contém um ponteiro para um objeto [CDaoErrorInfo](../mfc/reference/cdaoerrorinfo-structure.md) que encapsula informações de erro na coleção de objetos de erro do DAO associados ao banco de dados.

- [m_nAfxDaoError](../mfc/reference/cdaoexception-class.md#m_nafxdaoerror) contém um código de erro estendido das classes DAO do MFC. Esses códigos de erro, que têm nomes do formulário `CDaoException` **AFX_DAO_ERROR_XXX,** são documentados sob o membro de dados em .

- [m_scode](../mfc/reference/cdaoexception-class.md#m_scode) contém um Código **OLE** do DAO, se aplicável. No entanto, você raramente precisará trabalhar com este código de erro. Normalmente, mais informações estão disponíveis nos outros dois membros de dados. Consulte o membro de dados para obter mais informações sobre os valores **do SCODE.**

Informações adicionais sobre erros de DAO, o tipo de objeto DAO Error e a coleção DE ERROS DAO estão disponíveis na classe [CDaoException](../mfc/reference/cdaoexception-class.md).

## <a name="a-database-exception-handling-example"></a><a name="_core_a_database_exception.2d.handling_example"></a>Um exemplo de manipulação de exceção de banco de dados

O exemplo a seguir tenta construir um objeto derivado de [CRecordset](../mfc/reference/crecordset-class.md)no heap com o **novo** operador e, em seguida, abrir o conjunto de registros (para uma fonte de dados ODBC). Para um exemplo semelhante para as classes DAO, consulte "Exemplo de Exceção DAO" abaixo.

### <a name="odbc-exception-example"></a>Exemplo de exceção ODBC

A função [Open](../mfc/reference/crecordset-class.md#open) member poderia lançar uma exceção (do tipo [CDBException](../mfc/reference/cdbexception-class.md) para `Open` as classes ODBC), de modo que este código suporte a chamada com um bloco **de tentativa.** O bloco **de** captura `CDBException`subseqüente pegará um . Você pode examinar o objeto `e`de exceção em si, chamado, mas neste caso é suficiente saber que a tentativa de criar um conjunto de registros falhou. O bloco **de captura** exibe uma caixa de mensagens e é limpa excluindo o objeto recordset.

[!code-cpp[NVC_MFCDatabase#36](../mfc/codesnippet/cpp/exceptions-database-exceptions_1.cpp)]

### <a name="dao-exception-example"></a>Exemplo de exceção da DAO

O exemplo da DAO é semelhante ao exemplo do ODBC, mas você normalmente pode recuperar mais tipos de informações. O código a seguir também tenta abrir um conjunto de registros. Se essa tentativa abrir uma exceção, você pode examinar um membro de dados do objeto de exceção para obter informações de erro. Como no exemplo anterior do ODBC, provavelmente é suficiente saber que a tentativa de criar um conjunto de registros falhou.

[!code-cpp[NVC_MFCDatabase#37](../mfc/codesnippet/cpp/exceptions-database-exceptions_2.cpp)]

Este código recebe uma seqüência de mensagem de erro do [membro m_pErrorInfo](../mfc/reference/cdaoexception-class.md#m_perrorinfo) do objeto de exceção. MFC preenche este membro quando ele lança a exceção.

Para uma discussão sobre as informações `CDaoException` de erro retornadas por um objeto, consulte as classes [CDaoException](../mfc/reference/cdaoexception-class.md) e [CDaoErrorInfo](../mfc/reference/cdaoerrorinfo-structure.md).

Quando você está trabalhando com bancos de dados Microsoft Jet (.mdb) e na maioria dos casos quando você está trabalhando com ODBC, haverá apenas um objeto de erro. No caso raro quando você está usando uma fonte de dados ODBC e há vários erros, você pode fazer loop através da coleta de erros do DAO com base no número de erros retornados pelo [CDaoException::GetErrorCount](../mfc/reference/cdaoexception-class.md#geterrorcount). Cada vez que através do loop, ligue para [CDaoException::GetErrorInfo](../mfc/reference/cdaoexception-class.md#geterrorinfo) para repreencher o membro de `m_pErrorInfo` dados.

## <a name="see-also"></a>Confira também

[Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)
