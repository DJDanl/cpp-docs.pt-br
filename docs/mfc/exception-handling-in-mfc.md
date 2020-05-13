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
ms.openlocfilehash: d339ec98dabc6cb24fc7106c4c7238cd6a14a71b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365531"
---
# <a name="exception-handling-in-mfc"></a>Tratamento de exceções em MFC

Este artigo explica os mecanismos de tratamento de exceções disponíveis no MFC. Dois mecanismos estão disponíveis:

- Exceções C++, disponíveis na versão 3.0 do MFC e posteriores

- As macros de exceção do MFC, disponíveis nas versões 1.0 do MFC e posteriores

Se você estiver escrevendo um novo aplicativo usando MFC, você deve usar o mecanismo C++. Você pode usar o mecanismo baseado em macro se o aplicativo existente já usar esse mecanismo extensivamente.

Você pode converter facilmente o código existente para usar exceções C++ em vez das macros de exceção do MFC. As vantagens de converter seu código e diretrizes para fazê-lo são descritas no artigo [Exceções: Conversão de Macros de Exceção mfc](../mfc/exceptions-converting-from-mfc-exception-macros.md).

Se você já desenvolveu um aplicativo usando as macros de exceção do MFC, poderá continuar usando essas macros no seu código existente, enquanto usa exceções C++ em seu novo código. O artigo [Exceções: Alterações em Macros de Exceção na Versão 3.0](../mfc/exceptions-changes-to-exception-macros-in-version-3-0.md) dá diretrizes para fazê-lo.

> [!NOTE]
> Para habilitar o tratamento de exceção C++ em seu código, selecione Ativar exceções C++ na página Geração de Código na pasta C/C++ da caixa de diálogo Páginas de [Propriedade](../build/reference/property-pages-visual-cpp.md) do projeto ou usar a opção [compilador /EHsc.](../build/reference/eh-exception-handling-model.md)

Este artigo aborda os seguintes tópicos:

- [Quando usar exceções](#_core_when_to_use_exceptions)

- [Suporte a exceção do MFC](#_core_mfc_exception_support)

- [Leitura suplementar sobre exceções](#_core_further_reading_about_exceptions)

## <a name="when-to-use-exceptions"></a><a name="_core_when_to_use_exceptions"></a>Quando usar exceções

Três categorias de resultados podem ocorrer quando uma função é chamada durante a execução do programa: execução normal, execução errônea ou execução anormal. Cada categoria é descrita abaixo.

- Execução normal

   A função pode ser executada normalmente e retornar. Algumas funções retornam um código de resultado ao chamador, o que indica o resultado da função. Os possíveis códigos de resultado são estritamente definidos para a função e representam a gama de possíveis resultados da função. O código de resultado pode indicar sucesso ou falha ou até mesmo indicar um tipo específico de falha que está dentro da faixa normal de expectativas. Por exemplo, uma função de status de arquivo pode retornar um código que indica que o arquivo não existe. Observe que o termo "código de erro" não é usado porque um código de resultado representa um dos muitos resultados esperados.

- Execução errônea

   O chamador comete algum erro ao passar argumentos para a função ou chama a função em um contexto inadequado. Essa situação causa um erro, e deve ser detectada por uma afirmação durante o desenvolvimento do programa. (Para obter mais informações sobre afirmações, consulte [Afirmações C/C++.)](/visualstudio/debugger/c-cpp-assertions)

- Execução anormal

   A execução anormal inclui situações em que condições fora do controle do programa, como baixa memória ou erros de I/O, estão influenciando o resultado da função. Situações anormais devem ser tratadas capturando e jogando exceções.

Usar exceções é especialmente apropriado para execução anormal.

## <a name="mfc-exception-support"></a><a name="_core_mfc_exception_support"></a>Suporte a exceção do MFC

Se você usar as exceções C++ diretamente ou usar as macros `CException`de exceção do MFC, você usará [cexception class](../mfc/reference/cexception-class.md) ou objetos derivados que podem ser jogados pela estrutura ou pelo seu aplicativo.

A tabela a seguir mostra as exceções predefinidas fornecidas pelo MFC.

|Classe de exceção|Significado|
|---------------------|-------------|
|[Classe CMemoryException](../mfc/reference/cmemoryexception-class.md)|Fora da memória|
|[Classe CFileException](../mfc/reference/cfileexception-class.md)|Exceção de arquivo|
|[CArchiveClasse de exceção](../mfc/reference/carchiveexception-class.md)|Exceção de arquivamento/serialização|
|[Classe CNotSupportedException](../mfc/reference/cnotsupportedexception-class.md)|Resposta à solicitação de serviço sem suporte|
|[Classe CResourceException](../mfc/reference/cresourceexception-class.md)|Exceção de alocação de recursos do Windows|
|[Classe CDaoException](../mfc/reference/cdaoexception-class.md)|Exceções de banco de dados (classes DAO)|
|[Classe CDBException](../mfc/reference/cdbexception-class.md)|Exceções de banco de dados (classes ODBC)|
|[Classe COleException](../mfc/reference/coleexception-class.md)|Exceções OLE|
|[Classe COleDispatchException](../mfc/reference/coledispatchexception-class.md)|Despachar exceções (automação)|
|[Classe CUserException](../mfc/reference/cuserexception-class.md)|Exceção que alerta o usuário com uma caixa de mensagem e, em seguida, lança uma [classe CException](../mfc/reference/cexception-class.md) genérica|

A partir da versão 3.0, o MFC usa as exceções do C++, mas ainda dá suporte a macros de tratamento de exceções antigas, que têm formato semelhante ao das exceções do C++. Embora essas macros não sejam recomendadas para novos programas, ainda há suporte a elas para garantir a compatibilidade com versões anteriores. Em programas que já usam as macros, você também pode usar livremente as exceções do C++. Durante o pré-processamento, as macros avaliam até a exceção as palavras-chave definidas na implementação do MSVC da linguagem C++ como da versão 2.0 do Visual C++. Você pode manter as macros de exceção existentes em vigor quando você começar a usar exceções do C++. Para obter informações sobre a mistura de macros e o tratamento de exceções C++ e sobre a conversão de código antigo para usar o novo mecanismo, consulte os artigos [Exceções: Usando Macros MFC e Exceções e Exceções C++:](../mfc/exceptions-using-mfc-macros-and-cpp-exceptions.md) [Conversão de Macros de Exceção MFC](../mfc/exceptions-converting-from-mfc-exception-macros.md). As macros de exceção mais antigas do MFC, se você ainda as usa, são avaliadas para palavras-chave de exceção C++. Ver [Exceções: Alterações em Macros de Exceção na Versão 3.0](../mfc/exceptions-changes-to-exception-macros-in-version-3-0.md). O MFC não suporta diretamente os manipuladores de exceção estruturados do Windows NT (SEH), conforme discutido no [Structured Exception Handling](/windows/win32/debug/structured-exception-handling).

## <a name="further-reading-about-exceptions"></a><a name="_core_further_reading_about_exceptions"></a>Leitura adicional sobre exceções

Os seguintes artigos explicam o uso da biblioteca MFC para entrega de exceção:

- [Exceções: obtendo e excluindo exceções](../mfc/exceptions-catching-and-deleting-exceptions.md)

- [Exceções: examinando o conteúdo da exceção](../mfc/exceptions-examining-exception-contents.md)

- [Exceções: liberando objetos em exceções](../mfc/exceptions-freeing-objects-in-exceptions.md)

- [Exceções: lançando exceções a partir das funções próprias](../mfc/exceptions-throwing-exceptions-from-your-own-functions.md)

- [Exceções: exceções de banco de dados](../mfc/exceptions-database-exceptions.md)

- [Exceções: exceções OLE](../mfc/exceptions-ole-exceptions.md)

Os artigos a seguir comparam as macros de exceção do MFC com as palavras-chave de exceção C++ e explicam como você pode adaptar seu código:

- [Exceções: alterações feitas em macros de exceção na versão 3.0](../mfc/exceptions-changes-to-exception-macros-in-version-3-0.md)

- [Exceções: convertendo a partir de macros de exceção MFC](../mfc/exceptions-converting-from-mfc-exception-macros.md)

- [Exceções: usando macros MFC e exceções do C++](../mfc/exceptions-using-mfc-macros-and-cpp-exceptions.md)

## <a name="see-also"></a>Confira também

[Práticas recomendadas modernas do C++ para exceções e manipulação de erros](../cpp/errors-and-exception-handling-modern-cpp.md)<br/>
[Como faço: criar minhas próprias classes de exceção personalizadas](https://go.microsoft.com/fwlink/p/?linkid=128045)
