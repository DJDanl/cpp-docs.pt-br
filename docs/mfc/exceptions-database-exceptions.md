---
title: "Exce&#231;&#245;es: exce&#231;&#245;es de banco de dados | Microsoft Docs"
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
  - "DAO [C++], exceções"
  - "exceções de banco de dados [C++]"
  - "bancos de dados [C++], tratamento de exceção"
  - "códigos de erro [C++], tratamento de exceções de banco de dados"
  - "tratamento de exceções [C++], bancos de dados"
  - "exceções [C++], Banco de dados"
  - "ODBC [C++], exceções"
  - "Exceções ODBC [C++]"
ms.assetid: 28daf260-f824-4be6-aecc-1f859e6dec26
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Exce&#231;&#245;es: exce&#231;&#245;es de banco de dados
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica como tratar exceções da base de dados.  A maioria do hardware neste artigo se aplicará se você estiver trabalhando com as classes de MFC do ODBC ou as classes de MFC para objetos \(DAO\) de acesso a dados.  O hardware específico a um ou outro modelo é marcado explicitamente.  Os tópicos incluem:  
  
-   [Abordagens para a manipulação de exceção](#_core_approaches_to_exception_handling)  
  
-   [Um exemplo de manipulação de exceções gerais da base de dados](#_core_a_database_exception.2d.handling_example)  
  
##  <a name="_core_approaches_to_exception_handling"></a> Abordagens para a manipulação de exceção  
 A abordagem é a mesma se você estiver trabalhando com DAO ou ODBC.  
  
 Você sempre deve escrever manipuladores de exceção às condições excepcionais do identificador.  
  
 A abordagem mais pragmática a capturar exceções da base de dados é testar seu aplicativo com cenários de exceção.  Determina as exceções provável que podem ocorrer para uma operação em seu código, e para forçar a exceção ocorrer.  Examine a saída de rastreamento para consultar exceção que é lançada, ou para revisar informações de erro retornado no depurador.  Isso permite saber que códigos de retorno você consultará os cenários de exceção que você está usando.  
  
### Códigos de erro ODBC usados para exceções  
 Além dos códigos de retorno definidos pela estrutura, que tenham nomes do formulário **AFX\_SQL\_ERROR\_XXX**, qualquer [CDBExceptions](../mfc/reference/cdbexception-class.md) é baseado em códigos de retorno [ODBC](../data/odbc/odbc-basics.md) .  Os códigos de retorno para tais exceções têm nomes do formulário **SQL\_ERROR\_XXX**.  
  
 Os códigos de retorno — vezes definido e — definida com que o base de dados de classificação podem retornar são documentados no membro de dados de [m\_nRetCode](../Topic/CDBException::m_nRetCode.md) da classe `CDBException`.  Informações adicionais sobre os códigos de retorno definidas pelo ODBC está disponível em *Referência do Programador* do ODBC SDK na Biblioteca MSDN.  
  
### Códigos de erro usados para exceções de DAO  
 Para exceções de DAO, mais informações geralmente está disponível.  Você pode informações de erro de acesso por meio de três membros de dados de um objeto capturado de [CDaoException](../mfc/reference/cdaoexception-class.md) :  
  
-   [m\_pErrorInfo](../Topic/CDaoException::m_pErrorInfo.md) contém um ponteiro para um objeto de [CDaoErrorInfo](../mfc/reference/cdaoerrorinfo-structure.md) que encapsula as informações de erro na coleção de DAO de objetos de erro associadas com o base de dados.  
  
-   [m\_nAfxDaoError](../Topic/CDaoException::m_nAfxDaoError.md) contém um código de erro estendidas de classes de MFC DAO.  Esses códigos de erro, que tenham nomes do formulário **AFX\_DAO\_ERROR\_XXX**, são documentados no membro de dados em `CDaoException`.  
  
-   [m\_scode](../Topic/CDaoException::m_scode.md) contém `SCODE` OLE de DAO, se aplicável.  Você precisará raramente de trabalhar com esse código de erro, porém.  Geralmente mais informações estão disponíveis em outros dois membros de dados.  Consulte o membro de dados para obter mais informações sobre valores de `SCODE` .  
  
 Informações adicionais sobre erros de DAO, o tipo de objeto do erro de DAO, e a coleção de erros de DAO está disponível sob a classe [CDaoException](../mfc/reference/cdaoexception-class.md).  
  
##  <a name="_core_a_database_exception.2d.handling_example"></a> Um exemplo de manipulação de exceções gerais da base de dados  
 O exemplo a seguir tenta criar [CRecordset](../Topic/CRecordset%20Class.md)\- objeto derivada no heap com o operador de **new** , e abra o conjunto de registros \(para uma fonte de dados ODBC\).  Para obter um exemplo semelhante para classes de DAO, consulte “o exemplo de exceção DAO” em.  
  
### Exemplo de exceção ODBC  
 A função de membro de [Abrir](../Topic/CRecordset::Open.md) pode gerar uma exceção \(do tipo [CDBException](../mfc/reference/cdbexception-class.md) para classes de ODBC\), de forma que os colchetes desse código a chamada de **Abrir** com um bloco de **try** .  O bloco subsequente de **catch** detectará `CDBException`.  Você pode examinar o próprio objeto de exceção, `e`chamado, mas nesse caso é suficiente para saber quais a tentativa de criar um conjunto de registros falhou.  O bloco de **catch** exibe uma caixa de mensagem e limpa\-a excluindo o objeto do conjunto de registros.  
  
 [!code-cpp[NVC_MFCDatabase#36](../mfc/codesnippet/CPP/exceptions-database-exceptions_1.cpp)]  
  
### Exemplo de exceção de DAO  
 O exemplo de DAO é semelhante ao exemplo para ODBC, mas você pode recuperar normalmente mais tipos de informações.  O código a seguir também tenta abrir um conjunto de registros.  Se essa tentativa gerou uma exceção, você pode examinar um membro de dados do objeto de exceção para as informações de erro.  Como no exemplo anterior ODBC, provavelmente o suficiente para saber quais a tentativa de criar um conjunto de registros falhou.  
  
 [!code-cpp[NVC_MFCDatabase#37](../mfc/codesnippet/CPP/exceptions-database-exceptions_2.cpp)]  
  
 Esse código obtém uma cadeia de caracteres da mensagem de erro do membro de [m\_pErrorInfo](../Topic/CDaoException::m_pErrorInfo.md) do objeto de exceção.  MFC O preenche esse membro quando gerou a exceção.  
  
 Para obter uma descrição das informações de erro retornado por um objeto de `CDaoException` , consulte a [CDaoException](../mfc/reference/cdaoexception-class.md) classes e [CDaoErrorInfo](../mfc/reference/cdaoerrorinfo-structure.md).  
  
 Quando você estiver trabalhando com bases de dados do Microsoft Jet \(.mdb\) e, na maioria dos casos quando você estiver trabalhando com ODBC, haverá apenas um objeto do erro.  Em casos raros quando você estiver usando uma fonte de dados ODBC e houver vários erros, você pode criar um loop através da coleção de erros de DAO com base no número de erros retornados por [CDaoException::GetErrorCount](../Topic/CDaoException::GetErrorCount.md).  Cada vez que pelo loop, chame [CDaoException::GetErrorInfo](../Topic/CDaoException::GetErrorInfo.md) para preencher novamente o membro de dados de `m_pErrorInfo` .  
  
## Consulte também  
 [Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)