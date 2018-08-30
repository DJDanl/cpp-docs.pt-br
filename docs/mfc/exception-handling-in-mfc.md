---
title: Tratamento de exceções em MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 14887f5d85fc6c1a3fcd83474240c68c90ca2991
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43200761"
---
# <a name="exception-handling-in-mfc"></a>Tratamento de exceções em MFC
Este artigo explica os mecanismos de tratamento de exceções disponíveis no MFC. Dois mecanismos estão disponíveis:  
  
-   Exceções de C++, disponíveis na versão MFC 3.0 e posteriores  
  
-   As macros de exceção MFC, disponíveis nas versões 1.0 do MFC e versões posteriores  
  
 Se você estiver escrevendo um novo aplicativo usando o MFC, você deve usar o mecanismo de C++. Se o seu aplicativo já usa esse mecanismo amplamente, você pode usar o mecanismo de macro.  
  
 Prontamente, é possível converter o código existente para usar as exceções do C++ em vez de macros de exceção MFC. Vantagens da conversão de seu código e diretrizes para fazer isso são descritas no artigo [exceções: Convertendo de Macros de exceção MFC](../mfc/exceptions-converting-from-mfc-exception-macros.md).  
  
 Se você já tiver desenvolvido um aplicativo usando as macros de exceção do MFC, você pode continuar a usar essas macros em seu código existente, usando exceções C++ em seu novo código. O artigo [exceções: alterações em Macros de exceção na versão 3.0](../mfc/exceptions-changes-to-exception-macros-in-version-3-0.md) oferece diretrizes para fazer isso.  
  
> [!NOTE]
>  Para habilitar no seu código de tratamento de exceções de C++, selecione Habilitar exceções do C++ na página de geração de código na pasta do projeto do C/C++ [páginas de propriedades](../ide/property-pages-visual-cpp.md) caixa de diálogo ou use o [/EHsc](../build/reference/eh-exception-handling-model.md) opção de compilador.  
  
 Este artigo aborda os seguintes tópicos:  
  
-   [Quando usar exceções](#_core_when_to_use_exceptions)  
  
-   [Suporte de exceção MFC](#_core_mfc_exception_support)  
  
-   [Leitura adicional sobre exceções](#_core_further_reading_about_exceptions)  
  
##  <a name="_core_when_to_use_exceptions"></a> Quando usar exceções  
 Três categorias de resultados podem ocorrer quando uma função é chamada durante a execução do programa: execução normal, execução incorreta ou execução anormal. Cada categoria é descrita abaixo.  
  
-   Execução normal  
  
     A função pode executar normalmente e retornar. Algumas funções retornam um código de resultado para o chamador, que indica o resultado da função. Os códigos de resultado possíveis são estritamente definidos para a função e representam o intervalo de possíveis resultados da função. O código de resultado pode indicar o êxito ou falha, ou até mesmo pode indicar um determinado tipo de falha que está dentro do intervalo normal de expectativas. Por exemplo, uma função de status do arquivo pode retornar um código que indica que o arquivo não existe. Observe que o termo "código de erro" não é usado como um código de resultado representa um dos muitos resultados esperados.  
  
-   Execução incorreta  
  
     O chamador cometeu passar argumentos para a função ou chama a função em um contexto inadequado. Essa situação causa um erro e ele deve ser detectado por uma asserção durante o desenvolvimento do programa. (Para obter mais informações sobre declarações, consulte [asserções C/C++](/visualstudio/debugger/c-cpp-assertions).)  
  
-   Execução anormal  
  
     Execução anormal inclui situações em que condições fora do controle do programa, como memória insuficiente ou erros de e/s, estão influenciando o resultado da função. Situações anormais devem ser manipuladas capturando e lançando exceções.  
  
 Usando exceções é especialmente adequado para execução anormal.  
  
##  <a name="_core_mfc_exception_support"></a> Suporte de exceção MFC  
 Se você usar as exceções de C++ diretamente ou usa as macros de exceção do MFC, você usará [classe CException](../mfc/reference/cexception-class.md) ou `CException`-derivado de objetos que podem ser gerados pelo framework ou pelo seu aplicativo.  
  
 A tabela a seguir mostra as exceções predefinidas fornecidas pelo MFC.  
  
|Classe de exceção|Significado|  
|---------------------|-------------|  
|[Classe CMemoryException](../mfc/reference/cmemoryexception-class.md)|Memória insuficiente|  
|[Classe CFileException](../mfc/reference/cfileexception-class.md)|Exceção de arquivo|  
|[Classe CArchiveException](../mfc/reference/carchiveexception-class.md)|Exceção de serialização/arquivamento|  
|[Classe CNotSupportedException](../mfc/reference/cnotsupportedexception-class.md)|Resposta à solicitação de serviço sem suporte|  
|[Classe CResourceException](../mfc/reference/cresourceexception-class.md)|Exceção de alocação de recurso do Windows|  
|[Classe CDaoException](../mfc/reference/cdaoexception-class.md)|Exceções de banco de dados (classes DAO)|  
|[Classe CDBException](../mfc/reference/cdbexception-class.md)|Exceções de banco de dados (classes ODBC)|  
|[Classe COleException](../mfc/reference/coleexception-class.md)|Exceções OLE|  
|[Classe COleDispatchException](../mfc/reference/coledispatchexception-class.md)|Exceções de expedição (automação)|  
|[Classe CUserException](../mfc/reference/cuserexception-class.md)|Exceção que alerta o usuário com uma caixa de mensagem, em seguida, gera um genérico [classe CException](../mfc/reference/cexception-class.md)|  
  
> [!NOTE]
>  MFC é compatível com as exceções do C++ e as macros de exceção do MFC. MFC não oferece suporte diretamente manipuladores de exceção do NT do Windows estruturada (SEH), conforme discutido em [Structured Exception Handling](https://msdn.microsoft.com/library/windows/desktop/ms680657).  
  
##  <a name="_core_further_reading_about_exceptions"></a> Leitura adicional sobre exceções  
 Os artigos a seguir explicam usando a biblioteca do MFC para tratamento de exceção:  
  
-   [Exceções: obtendo e excluindo exceções](../mfc/exceptions-catching-and-deleting-exceptions.md)  
  
-   [Exceções: examinando o conteúdo da exceção](../mfc/exceptions-examining-exception-contents.md)  
  
-   [Exceções: liberando objetos em exceções](../mfc/exceptions-freeing-objects-in-exceptions.md)  
  
-   [Exceções: lançando exceções das suas próprias funções](../mfc/exceptions-throwing-exceptions-from-your-own-functions.md)  
  
-   [Exceções: exceções de banco de dados](../mfc/exceptions-database-exceptions.md)  
  
-   [Exceções: exceções OLE](../mfc/exceptions-ole-exceptions.md)  
  
 Os artigos a seguir comparam as macros de exceção do MFC com as palavras-chave de exceção C++ e explicam como você pode adaptar seu código:  
  
-   [Exceções: alterações feitas em macros de exceção na versão 3.0](../mfc/exceptions-changes-to-exception-macros-in-version-3-0.md)  
  
-   [Exceções: convertendo de macros de exceção do MFC](../mfc/exceptions-converting-from-mfc-exception-macros.md)  
  
-   [Exceções: usando macros MFC e exceções C++](../mfc/exceptions-using-mfc-macros-and-cpp-exceptions.md)  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de exceções C++](../cpp/cpp-exception-handling.md)   
 [Como eu crio minhas próprias Classes de exceção personalizada](http://go.microsoft.com/fwlink/p/?linkid=128045)

