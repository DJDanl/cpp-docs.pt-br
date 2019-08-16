---
title: Tratamento de exceções em MFC
ms.date: 11/04/2016
helpviewer_keywords:
- DAO [MFC], exceptions
- assertions [MFC], When to use exceptions
- exception handling [MFC], MFC
- resource allocation exception
- resources [MFC], allocating
- keywords [MFC], exception handling
- errors [MFC], detected by assertions
- ODBC exceptions [MFC]
- serialization [MFC], exceptions
- Automation [MFC], exceptions
- exception macros [MFC]
- predefined exceptions [MFC]
- C++ exception handling [MFC], enabling
- C++ exception handling [MFC], MFC applications
- requests for unsupported services [MFC]
- database exceptions [MFC]
- archive exceptions [MFC]
- MFC, exceptions
- C++ exception handling [MFC], types of
- macros [MFC], exception handling
- abnormal program execution [MFC]
- OLE exceptions [MFC], MFC exception handling
- error handling [MFC], exceptions and
- class libraries [MFC], exception support
- exceptions [MFC], MFC macros vs. C++ keywords
- memory [MFC], out-of-memory exceptions
- Windows [MFC], resource allocation exceptions
- macros [MFC], MFC exception macros
- function calls [MFC], results
- out-of-memory exceptions [MFC]
ms.assetid: 0926627d-2ba7-44a6-babe-d851a4a2517c
ms.openlocfilehash: e8c0f1feba566ef9b961edcfacb9124830f9851d
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69508615"
---
# <a name="exception-handling-in-mfc"></a>Tratamento de exceções em MFC

Este artigo explica os mecanismos de manipulação de exceção disponíveis no MFC. Dois mecanismos estão disponíveis:

- C++exceções, disponíveis na versão 3,0 do MFC e versões posteriores

- As macros de exceção do MFC, disponíveis nas versões 1,0 e posteriores do MFC

Se você estiver escrevendo um novo aplicativo usando o MFC, deverá usar o C++ mecanismo. Você pode usar o mecanismo baseado em macro se o aplicativo existente já usa esse mecanismo extensivamente.

Você pode converter o código existente prontamente C++ para usar exceções em vez das macros de exceção do MFC. As vantagens de converter seu código e suas diretrizes para fazer isso são descritas [no artigo exceções: Convertendo de macros](../mfc/exceptions-converting-from-mfc-exception-macros.md)de exceção do MFC.

Se você já tiver desenvolvido um aplicativo usando as macros de exceção do MFC, poderá continuar usando essas macros em seu código existente C++ , ao usar exceções no novo código. As exceções [do artigo: As alterações nas macros de exceção](../mfc/exceptions-changes-to-exception-macros-in-version-3-0.md) na versão 3,0 fornecem diretrizes para fazer isso.

> [!NOTE]
>  Para habilitar C++ o tratamento de exceções em seu código, C++ selecione Habilitar exceções na página geração de código, naC++ pasta C/da caixa de diálogo [páginas de propriedades](../build/reference/property-pages-visual-cpp.md) do projeto, ou use a opção de compilador [/EHsc](../build/reference/eh-exception-handling-model.md) .

Este artigo aborda os seguintes tópicos:

- [Quando usar exceções](#_core_when_to_use_exceptions)

- [Suporte de exceção do MFC](#_core_mfc_exception_support)

- [Leitura adicional sobre exceções](#_core_further_reading_about_exceptions)

##  <a name="_core_when_to_use_exceptions"></a>Quando usar exceções

Três categorias de resultados podem ocorrer quando uma função é chamada durante a execução do programa: execução normal, execução errada ou execução anormal. Cada categoria é descrita abaixo.

- Execução normal

   A função pode executar normalmente e retornar. Algumas funções retornam um código de resultado para o chamador, que indica o resultado da função. Os códigos de resultado possíveis são estritamente definidos para a função e representam o intervalo de possíveis resultados da função. O código de resultado pode indicar êxito ou falha ou pode até mesmo indicar um tipo específico de falha que está dentro do intervalo normal de expectativas. Por exemplo, uma função de status de arquivo pode retornar um código que indica que o arquivo não existe. Observe que o termo "código de erro" não é usado porque um código de resultado representa um dos muitos resultados esperados.

- Execução errada

   O chamador faz algum erro na passagem de argumentos para a função ou chama a função em um contexto inadequado. Essa situação causa um erro e deve ser detectada por uma asserção durante o desenvolvimento do programa. (Para obter mais informações sobre asserções, consulte [CC++ /Asserts](/visualstudio/debugger/c-cpp-assertions).)

- Execução anormal

   A execução anormal inclui situações em que as condições fora do controle do programa, como erros de memória insuficiente ou de e/s, estão influenciando o resultado da função. Situações anormais devem ser tratadas capturando e gerando exceções.

O uso de exceções é especialmente apropriado para a execução anormal.

##  <a name="_core_mfc_exception_support"></a>Suporte de exceção do MFC

Se você usar as C++ exceções diretamente ou usar as macros de exceção do MFC, usará a `CException` [classe CException](../mfc/reference/cexception-class.md) ou os objetos derivados que podem ser lançados pela estrutura ou pelo seu aplicativo.

A tabela a seguir mostra as exceções predefinidas fornecidas pelo MFC.

|Classe de exceção|Significado|
|---------------------|-------------|
|[Classe CMemoryException](../mfc/reference/cmemoryexception-class.md)|Memória insuficiente|
|[Classe CFileException](../mfc/reference/cfileexception-class.md)|Exceção de arquivo|
|[Classe CArchiveException](../mfc/reference/carchiveexception-class.md)|Exceção de arquivo morto/de serialização|
|[Classe CNotSupportedException](../mfc/reference/cnotsupportedexception-class.md)|Resposta à solicitação de serviço sem suporte|
|[Classe CResourceException](../mfc/reference/cresourceexception-class.md)|Exceção de alocação de recursos do Windows|
|[Classe CDaoException](../mfc/reference/cdaoexception-class.md)|Exceções de banco de dados (classes DAO)|
|[Classe CDBException](../mfc/reference/cdbexception-class.md)|Exceções de banco de dados (classes ODBC)|
|[Classe COleException](../mfc/reference/coleexception-class.md)|Exceções OLE|
|[Classe COleDispatchException](../mfc/reference/coledispatchexception-class.md)|Exceções de expedição (automação)|
|[Classe CUserException](../mfc/reference/cuserexception-class.md)|Exceção que alerta o usuário com uma caixa de mensagem e, em seguida, gera uma [classe CException](../mfc/reference/cexception-class.md) genérica|

> [!NOTE]
>  O MFC dá C++ suporte às exceções e às macros de exceção do MFC. O MFC não dá suporte diretamente a SEH (manipuladores de exceção estruturada) do Windows NT, conforme discutido em [manipulação de exceção estruturada](/windows/win32/debug/structured-exception-handling).

##  <a name="_core_further_reading_about_exceptions"></a>Leitura adicional sobre exceções

Os artigos a seguir explicam como usar a biblioteca do MFC para a entrega de exceção:

- [Exceções: obter e excluir exceções](../mfc/exceptions-catching-and-deleting-exceptions.md)

- [Exceções: examinar o conteúdo da exceção](../mfc/exceptions-examining-exception-contents.md)

- [Exceções: liberar objetos em exceções](../mfc/exceptions-freeing-objects-in-exceptions.md)

- [Exceções: lançar exceções a partir das funções próprias](../mfc/exceptions-throwing-exceptions-from-your-own-functions.md)

- [Exceções: exceções do banco de dados](../mfc/exceptions-database-exceptions.md)

- [Exceções: exceções OLE](../mfc/exceptions-ole-exceptions.md)

Os artigos a seguir comparam as macros C++ de exceção do MFC com as palavras-chave de exceção e explicam como você pode adaptar seu código:

- [Exceções: alterações feitas em macros de exceção na versão 3.0](../mfc/exceptions-changes-to-exception-macros-in-version-3-0.md)

- [Exceções: converter a partir de macros de exceção MFC](../mfc/exceptions-converting-from-mfc-exception-macros.md)

- [Exceções: usar macros MFC e exceções do C++](../mfc/exceptions-using-mfc-macros-and-cpp-exceptions.md)

## <a name="see-also"></a>Consulte também

[Tratamento de exceções em C++](../cpp/cpp-exception-handling.md)<br/>
[Como faço para: Criar minhas próprias classes de exceção personalizadas](https://go.microsoft.com/fwlink/p/?linkid=128045)
