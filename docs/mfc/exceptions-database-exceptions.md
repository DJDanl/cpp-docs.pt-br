---
title: 'Exceções: Exceções do Banco de Dados'
ms.date: 11/04/2016
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
ms.openlocfilehash: 2f7f3bff9f28968361ecfa7374a235a727443004
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57285549"
---
# <a name="exceptions-database-exceptions"></a>Exceções: Exceções do Banco de Dados

Este artigo explica como tratar exceções de banco de dados. A maioria do material neste artigo se aplica se você estiver trabalhando com as classes MFC para conectividade aberta de banco de dados (ODBC) ou as classes MFC para objetos de acesso de dados (DAO). Material específica a um ou outro modelo é marcado explicitamente. Os tópicos incluem:

- [Abordagens para a manipulação de exceção](#_core_approaches_to_exception_handling)

- [Um exemplo de tratamento de exceções do banco de dados](#_core_a_database_exception.2d.handling_example)

##  <a name="_core_approaches_to_exception_handling"></a> Abordagens para a manipulação de exceção

A abordagem é o mesmo se você estiver trabalhando com DAO ou ODBC.

Você sempre deve escrever manipuladores de exceção para lidar com condições excepcionais.

É a abordagem mais pragmática para capturar exceções de banco de dados testar seu aplicativo com cenários de exceção. Determine as exceções de probabilidade que podem ocorrer por uma operação em seu código e forçar a exceção ocorrer. Em seguida, examine a saída de rastreamento para ver qual exceção é lançada ou examinar as informações de erro retornado no depurador. Isso permite saber qual retornar códigos que você verá para os cenários de exceção que você está usando.

### <a name="error-codes-used-for-odbc-exceptions"></a>Códigos de erro usados para exceções de ODBC

Além dos códigos de retornados definidos pela estrutura, que têm nomes no formato **AFX_SQL_ERROR_XXX**, algumas [CDBExceptions](../mfc/reference/cdbexception-class.md) baseiam [ODBC](../data/odbc/odbc-basics.md) códigos de retorno. Os códigos de retorno para essas exceções têm nomes no formato **SQL_ERROR_XXX**.

Os códigos de retorno — tanto definidos pela estrutura e definidas pelo ODBC — que as classes de banco de dados podem retornar estão documentados na [m_nRetCode](../mfc/reference/cdbexception-class.md#m_nretcode) membro de dados da classe `CDBException`. Informações adicionais sobre códigos de retorno definido pelo ODBC estão disponíveis no SDK do ODBC *referência do programador* na biblioteca MSDN.

### <a name="error-codes-used-for-dao-exceptions"></a>Códigos de erro usados para exceções de DAO

Para exceções do DAO, mais informações estão normalmente disponíveis. Você pode acessar informações de erro por meio de membros de dados de três de uma capturada [CDaoException](../mfc/reference/cdaoexception-class.md) objeto:

- [m_pErrorInfo](../mfc/reference/cdaoexception-class.md#m_perrorinfo) contém um ponteiro para uma [CDaoErrorInfo](../mfc/reference/cdaoerrorinfo-structure.md) objeto que encapsula informações de erro na coleção do DAO de objetos de erro associados com o banco de dados.

- [m_nAfxDaoError](../mfc/reference/cdaoexception-class.md#m_nafxdaoerror) contém um código de erro estendido de classes MFC DAO. Esses códigos de erro, que têm nomes no formato **AFX_DAO_ERROR_XXX**, estão documentados em que o membro de dados em `CDaoException`.

- [m_scode](../mfc/reference/cdaoexception-class.md#m_scode) contém uma OLE **SCODE** do DAO, se aplicável. Raramente, você precisará trabalhar com esse código de erro, no entanto. Geralmente, mais informações estão disponíveis nos membros de dados de dois. Consulte o membro de dados para obter mais informações **SCODE** valores.

Informações adicionais sobre erros, o tipo de objeto de erro do DAO e a coleção de erros do DAO DAO estão disponíveis na classe [CDaoException](../mfc/reference/cdaoexception-class.md).

##  <a name="_core_a_database_exception.2d.handling_example"></a> Um exemplo de tratamento de exceções do banco de dados

O exemplo a seguir tenta construir um [CRecordset](../mfc/reference/crecordset-class.md)-derivados do objeto no heap com as **novos** operador e, em seguida, abra o conjunto de registros (para uma fonte de dados ODBC). Para obter um exemplo semelhante para as classes DAO, consulte "DAO exceção exemplo" abaixo.

### <a name="odbc-exception-example"></a>Exemplo de exceção do ODBC

O [aberto](../mfc/reference/crecordset-class.md#open) função de membro pode lançar uma exceção (do tipo [CDBException](../mfc/reference/cdbexception-class.md) para as classes ODBC), portanto, esse código colchetes a `Open` chamar com um **tente** bloco. Os próximos **catch** bloco irá capturar uma `CDBException`. Você pode examinar o objeto de exceção em si, chamado `e`, mas nesse caso é suficiente saber que a tentativa de criar um conjunto de registros falhou. O **catch** bloco exibe uma caixa de mensagem e limpa excluindo o objeto recordset.

[!code-cpp[NVC_MFCDatabase#36](../mfc/codesnippet/cpp/exceptions-database-exceptions_1.cpp)]

### <a name="dao-exception-example"></a>Exemplo de exceção do DAO

O exemplo DAO é semelhante ao exemplo do ODBC, mas você normalmente pode recuperar a mais tipos de informações. O código a seguir também tenta abrir um conjunto de registros. Se essa tentativa de gerar uma exceção, você pode examinar um membro de dados do objeto de exceção para obter informações de erro. Como no exemplo anterior do ODBC, provavelmente é suficiente saber que houve falha na tentativa de criar um conjunto de registros.

[!code-cpp[NVC_MFCDatabase#37](../mfc/codesnippet/cpp/exceptions-database-exceptions_2.cpp)]

Esse código obtém uma cadeia de caracteres de mensagem de erro do [m_pErrorInfo](../mfc/reference/cdaoexception-class.md#m_perrorinfo) membro do objeto de exceção. MFC preenche esse membro quando ele gerará a exceção.

Para obter uma discussão sobre as informações de erro retornadas por uma `CDaoException` de objeto, consulte classes [CDaoException](../mfc/reference/cdaoexception-class.md) e [CDaoErrorInfo](../mfc/reference/cdaoerrorinfo-structure.md).

Quando você estiver trabalhando com bancos de dados Microsoft Jet (. mdb) e na maioria dos casos, quando você estiver trabalhando com o ODBC, haverá apenas um objeto de erro. Em casos raros quando você estiver usando uma fonte de dados ODBC e há vários erros, você pode executar um loop pela coleção de erros do DAO com base no número de erros retornados pelo [CDaoException::GetErrorCount](../mfc/reference/cdaoexception-class.md#geterrorcount). Cada vez pelo loop, chame [CDaoException::GetErrorInfo](../mfc/reference/cdaoexception-class.md#geterrorinfo) reabastecimento o `m_pErrorInfo` membro de dados.

## <a name="see-also"></a>Consulte também

[Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)
