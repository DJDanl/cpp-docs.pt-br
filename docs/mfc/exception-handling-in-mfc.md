---
title: Tratamento de exceções em MFC
ms.date: 11/19/2019
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
ms.openlocfilehash: ef827af413513d1a1753f84b1cb69a66f41f690c
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618861"
---
# <a name="exception-handling-in-mfc"></a>Tratamento de exceções em MFC

Este artigo explica os mecanismos de manipulação de exceção disponíveis no MFC. Dois mecanismos estão disponíveis:

- Exceções do C++, disponíveis na versão 3,0 do MFC e versões posteriores

- As macros de exceção do MFC, disponíveis nas versões 1,0 e posteriores do MFC

Se você estiver escrevendo um novo aplicativo usando o MFC, deverá usar o mecanismo C++. Você pode usar o mecanismo baseado em macro se o aplicativo existente já usa esse mecanismo extensivamente.

Você pode converter o código existente prontamente para usar exceções do C++ em vez das macros de exceção do MFC. As vantagens de converter seu código e suas diretrizes para fazer isso são descritas no artigo [exceções: convertendo de macros de exceção do MFC](exceptions-converting-from-mfc-exception-macros.md).

Se você já tiver desenvolvido um aplicativo usando as macros de exceção do MFC, poderá continuar usando essas macros em seu código existente, ao usar exceções do C++ no novo código. O artigo [exceções: alterações nas macros de exceção na versão 3,0](exceptions-changes-to-exception-macros-in-version-3-0.md) fornece diretrizes para fazer isso.

> [!NOTE]
> Para habilitar a manipulação de exceções do C++ em seu código, selecione Habilitar exceções do C++ na página geração de código na pasta C/C++ da caixa de diálogo [páginas de propriedades](../build/reference/property-pages-visual-cpp.md) do projeto ou use a opção de compilador [/EHsc](../build/reference/eh-exception-handling-model.md) .

Este artigo aborda os seguintes tópicos:

- [Quando usar exceções](#_core_when_to_use_exceptions)

- [Suporte de exceção do MFC](#_core_mfc_exception_support)

- [Leitura adicional sobre exceções](#_core_further_reading_about_exceptions)

## <a name="when-to-use-exceptions"></a><a name="_core_when_to_use_exceptions"></a>Quando usar exceções

Três categorias de resultados podem ocorrer quando uma função é chamada durante a execução do programa: execução normal, execução errada ou execução anormal. Cada categoria é descrita abaixo.

- Execução normal

   A função pode executar normalmente e retornar. Algumas funções retornam um código de resultado para o chamador, que indica o resultado da função. Os códigos de resultado possíveis são estritamente definidos para a função e representam o intervalo de possíveis resultados da função. O código de resultado pode indicar êxito ou falha ou pode até mesmo indicar um tipo específico de falha que está dentro do intervalo normal de expectativas. Por exemplo, uma função de status de arquivo pode retornar um código que indica que o arquivo não existe. Observe que o termo "código de erro" não é usado porque um código de resultado representa um dos muitos resultados esperados.

- Execução errada

   O chamador faz algum erro na passagem de argumentos para a função ou chama a função em um contexto inadequado. Essa situação causa um erro e deve ser detectada por uma asserção durante o desenvolvimento do programa. (Para obter mais informações sobre asserções, consulte [declarações de C/C++](/visualstudio/debugger/c-cpp-assertions).)

- Execução anormal

   A execução anormal inclui situações em que as condições fora do controle do programa, como erros de memória insuficiente ou de e/s, estão influenciando o resultado da função. Situações anormais devem ser tratadas capturando e gerando exceções.

O uso de exceções é especialmente apropriado para a execução anormal.

## <a name="mfc-exception-support"></a><a name="_core_mfc_exception_support"></a>Suporte de exceção do MFC

Se você usar as exceções C++ diretamente ou usar as macros de exceção do MFC, usará a [classe CException](reference/cexception-class.md) ou os `CException` objetos derivados que podem ser lançados pela estrutura ou pelo seu aplicativo.

A tabela a seguir mostra as exceções predefinidas fornecidas pelo MFC.

|Classe de exceção|Significado|
|---------------------|-------------|
|[Classe CMemoryException](reference/cmemoryexception-class.md)|Memória insuficiente|
|[Classe CFileException](reference/cfileexception-class.md)|Exceção de arquivo|
|[Classe CArchiveException](reference/carchiveexception-class.md)|Exceção de arquivo morto/de serialização|
|[Classe CNotSupportedException](reference/cnotsupportedexception-class.md)|Resposta à solicitação de serviço sem suporte|
|[Classe CResourceException](reference/cresourceexception-class.md)|Exceção de alocação de recursos do Windows|
|[Classe CDaoException](reference/cdaoexception-class.md)|Exceções de banco de dados (classes DAO)|
|[Classe CDBException](reference/cdbexception-class.md)|Exceções de banco de dados (classes ODBC)|
|[Classe COleException](reference/coleexception-class.md)|Exceções OLE|
|[Classe COleDispatchException](reference/coledispatchexception-class.md)|Exceções de expedição (automação)|
|[Classe CUserException](reference/cuserexception-class.md)|Exceção que alerta o usuário com uma caixa de mensagem e, em seguida, gera uma [classe CException](reference/cexception-class.md) genérica|

A partir da versão 3.0, o MFC usa as exceções do C++, mas ainda dá suporte a macros de tratamento de exceções antigas, que têm formato semelhante ao das exceções do C++. Embora essas macros não sejam recomendadas para novos programas, ainda há suporte a elas para garantir a compatibilidade com versões anteriores. Em programas que já usam as macros, você também pode usar livremente as exceções do C++. Durante o pré-processamento, as macros são avaliadas para as palavras-chave de manipulação de exceção definidas na implementação MSVC da linguagem C++ a partir da versão Visual C++ 2,0. Você pode manter as macros de exceção existentes em vigor quando você começar a usar exceções do C++. Para obter informações sobre como misturar macros e manipulação de exceções de C++ e converter código antigo para usar o novo mecanismo, consulte os artigos [exceções: usando macros do MFC e exceções](exceptions-using-mfc-macros-and-cpp-exceptions.md) e exceções [do C++: convertendo de macros de exceção do MFC](exceptions-converting-from-mfc-exception-macros.md). As macros de exceção mais antigas do MFC, se você ainda as usa, são avaliadas para palavras-chave de exceção C++. Consulte [exceções: alterações nas macros de exceção na versão 3,0](exceptions-changes-to-exception-macros-in-version-3-0.md). O MFC não dá suporte diretamente a SEH (manipuladores de exceção estruturada) do Windows NT, conforme discutido em [manipulação de exceção estruturada](/windows/win32/debug/structured-exception-handling).

## <a name="further-reading-about-exceptions"></a><a name="_core_further_reading_about_exceptions"></a>Leitura adicional sobre exceções

Os artigos a seguir explicam como usar a biblioteca do MFC para a entrega de exceção:

- [Exceções: obtendo e excluindo exceções](exceptions-catching-and-deleting-exceptions.md)

- [Exceções: examinando o conteúdo da exceção](exceptions-examining-exception-contents.md)

- [Exceções: liberando objetos em exceções](exceptions-freeing-objects-in-exceptions.md)

- [Exceções: lançando exceções a partir das funções próprias](exceptions-throwing-exceptions-from-your-own-functions.md)

- [Exceções: exceções de banco de dados](exceptions-database-exceptions.md)

- [Exceções: exceções OLE](exceptions-ole-exceptions.md)

Os artigos a seguir comparam as macros de exceção do MFC com as palavras-chave de exceção do C++ e explicam como você pode adaptar seu código:

- [Exceções: alterações feitas em macros de exceção na versão 3.0](exceptions-changes-to-exception-macros-in-version-3-0.md)

- [Exceções: convertendo a partir de macros de exceção MFC](exceptions-converting-from-mfc-exception-macros.md)

- [Exceções: usando macros MFC e exceções do C++](exceptions-using-mfc-macros-and-cpp-exceptions.md)

## <a name="see-also"></a>Consulte também

[Práticas recomendadas do C++ moderno para exceções e tratamento de erros](../cpp/errors-and-exception-handling-modern-cpp.md)<br/>
[Como faço para: criar minhas próprias classes de exceção personalizadas](https://go.microsoft.com/fwlink/p/?linkid=128045)
