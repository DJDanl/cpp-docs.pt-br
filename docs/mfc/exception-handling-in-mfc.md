---
title: "Tratamento de exce&#231;&#245;es em MFC | Microsoft Docs"
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
  - "execução de programa anormal [C++]"
  - "exceções de arquivamento [C++]"
  - "declarações [C++], Quando usar exceções"
  - "Automação [C++], exceções"
  - "tratamento de exceção de C++, ativando"
  - "tratamento de exceção de C++, Aplicativos MFC"
  - "tratamento de exceção de C++, tipos de"
  - "bibliotecas de classes [C++], suporte a exceções"
  - "DAO [C++], exceções"
  - "exceções de banco de dados [C++]"
  - "tratamento de erros [C++], exceções e"
  - "erros [C++], detectado por declarações"
  - "tratamento de exceções [C++], MFC"
  - "macros de exceção [C++]"
  - "exceções [C++], Macros MFC vs. palavras-chave C++"
  - "chamadas de função, resultados"
  - "palavras-chave [C++], tratamento de exceção"
  - "macros [C++], tratamento de exceção"
  - "macros [C++], Macros de exceção MFC"
  - "memória [C++], exceções de memória insuficiente"
  - "MFC [C++], exceções"
  - "Exceções ODBC [C++]"
  - "Exceções OLE [C++], tratamento de exceção MFC"
  - "exceções de memória insuficiente [C++]"
  - "exceções predefinidas [C++]"
  - "solicitações de serviços sem suporte"
  - "exceção de alocação de recursos"
  - "recursos [C++], alocando"
  - "serialização [C++], exceções"
  - "Windows [C++], exceções de alocação de recursos"
ms.assetid: 0926627d-2ba7-44a6-babe-d851a4a2517c
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tratamento de exce&#231;&#245;es em MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica os mecanismos de manipulação de exceções gerais MFC disponíveis no.  Dois mecanismos estão disponíveis:  
  
-   Exceções C\+\+, disponíveis na versão 3,0 e posterior MFC  
  
-   Macros de exceção MFC, disponíveis nas versões 1,0 e posterior MFC  
  
 Se você estiver escrevendo um novo aplicativo usando o MFC, você deve usar o mecanismo C\+\+.  Você pode usar o mecanismo \- baseado se seu aplicativo existente já esse mecanismo extensivamente.  
  
 Você pode converter prontamente o código existente para usar exceções C\+\+ em vez de macros de exceção MFC.  As vantagens de converter seus código e diretrizes para fazer isso são descritas no artigo [Exceções: convertendo a partir de macros de exceção MFC](../mfc/exceptions-converting-from-mfc-exception-macros.md).  
  
 Se você tiver um aplicativo já desenvolvido usando macros de exceção MFC, você poderá continuar a usar esses macros em seu código existente, ao usar exceções C\+\+ em seu novo código.  O artigo [Exceções: alterações feitas em macros de exceção na versão 3.0](../mfc/exceptions-changes-to-exception-macros-in-version-3-0.md) contém diretrizes para fazer isso.  
  
> [!NOTE]
>  Para habilitar a manipulação de exceção C\+\+ em seu código, selecione habilita exceções C\+\+ na página de geração de código na pasta C\/C\+\+ da caixa de diálogo de [Páginas de propriedade](../ide/property-pages-visual-cpp.md) de projeto, ou usar a opção do compilador do \/GX.  O padrão é \/GX –, que desabilita a manipulação de exceção.  
  
 Este artigo abrange os seguintes tópicos:  
  
-   [Quando usar exceções](#_core_when_to_use_exceptions)  
  
-   [Suporte à exceção de MFC](#_core_mfc_exception_support)  
  
-   [Leitura adicionais sobre exceções](#_core_further_reading_about_exceptions)  
  
##  <a name="_core_when_to_use_exceptions"></a> Quando usar exceções  
 Três categorias de resultados podem ocorrer quando uma função é chamada durante a execução do programa: execução normal, execute errônea, ou execução anormal.  Cada categoria é descrita abaixo.  
  
-   Execução normal  
  
     A função pode executar normalmente e retornar.  Algumas funções retornam o código de resultado para o chamador, que indica o resultado da função.  Os códigos de resultados possíveis são definidos estritamente para a função e representam o intervalo de possíveis resultados da função.  O código de resultado pode indicar êxito ou falha ou mesmo pode indicar um tipo específico de falha que está dentro do intervalo normal das expectativas.  Por exemplo, uma função de arquivo status pode retornar um código que indica que o arquivo não existir.  Observe que o termo “código de erro” não é usado como um código de resultado representa um dos vários resultados esperados.  
  
-   Execução errônea  
  
     O chamador faz qualquer erro na argumentos à função ou chama a função em um contexto inadequada.  Essa situação causa um erro, e deve ser detectada por uma asserção durante desenvolvimento de programas. \(Para obter mais informações sobre as asserções, consulte [Asserções C\/C\+\+](../Topic/C-C++%20Assertions.md).\)  
  
-   Anormal execução  
  
     A execução anormal inclui as situações em que as condições fora do controle de programa, como a memória baixa ou erros de E\/S, está influenciando o resultado da função.  As situações anormais devem ser tratadas por exceções capturando e de reprodução.  
  
 Usar exceções é especialmente apropriada para a execução anormal.  
  
##  <a name="_core_mfc_exception_support"></a> Suporte à exceção de MFC  
 Se você usa as exceções C\+\+ diretamente ou usar macros de exceção MFC, você usará [Classe de CException](../mfc/reference/cexception-class.md) ou `CException`\- os objetos derivados que podem ser descartados pela estrutura ou por seu aplicativo.  
  
 A tabela a seguir mostra as exceções predefinidas fornecidas por MFC.  
  
|Classe de exceção|Significado|  
|-----------------------|-----------------|  
|[Classe de CMemoryException](../mfc/reference/cmemoryexception-class.md)|Falta de memória|  
|[Classe de CFileException](../mfc/reference/cfileexception-class.md)|Exceção de Arquivo|  
|[Classe de CArchiveException](../mfc/reference/carchiveexception-class.md)|Exceção de arquivo morto\/serialização|  
|[Classe de CNotSupportedException](../mfc/reference/cnotsupportedexception-class.md)|Resposta à solicitação para o serviço sem suporte|  
|[Classe de CResourceException](../mfc/reference/cresourceexception-class.md)|Exceção de atribuição de recursos do windows|  
|[Classe de CDaoException](../mfc/reference/cdaoexception-class.md)|Exceções da base de dados de classes DAO \(\)|  
|[Classe de CDBException](../mfc/reference/cdbexception-class.md)|Exceções da base de dados de classes \(ODBC\)|  
|[Classe de COleException](../mfc/reference/coleexception-class.md)|Exceções OLE|  
|[Classe de COleDispatchException](../Topic/COleDispatchException%20Class.md)|Exceções de distribuição \(automação\)|  
|[Classe de CUserException](../mfc/reference/cuserexception-class.md)|A exceção que o alerta usuário com uma caixa de mensagem em seguida, gerencie [Classe de CException](../mfc/reference/cexception-class.md)genérico|  
  
> [!NOTE]
>  MFC O oferece suporte às exceções de C\+\+ e macros de exceção MFC.  MFC O não da suporte diretamente manipuladores estruturados o Windows NT \(SEH\) de exceção, como discutido em [Manipulação de exceção estruturado](http://msdn.microsoft.com/library/windows/desktop/ms680657).  
  
##  <a name="_core_further_reading_about_exceptions"></a> Leitura adicionais sobre exceções  
 Os artigos a seguir explicam usando a biblioteca MFC para entregar de exceção:  
  
-   [Exceções: obtendo e excluindo exceções](../mfc/exceptions-catching-and-deleting-exceptions.md)  
  
-   [Exceções: examinando o conteúdo da exceção](../mfc/exceptions-examining-exception-contents.md)  
  
-   [Exceções: liberando objetos em exceções](../Topic/Exceptions:%20Freeing%20Objects%20in%20Exceptions.md)  
  
-   [Exceções: lançando exceções a partir das funções próprias](../mfc/exceptions-throwing-exceptions-from-your-own-functions.md)  
  
-   [Exceções: exceções de banco de dados](../mfc/exceptions-database-exceptions.md)  
  
-   [Exceções: exceções OLE](../Topic/Exceptions:%20OLE%20Exceptions.md)  
  
 Os artigos a seguir compara as macros de exceção MFC com as palavras\-chave de exceção C\+\+ e também explica como você pode adaptar o código:  
  
-   [Exceções: alterações feitas em macros de exceção na versão 3.0](../mfc/exceptions-changes-to-exception-macros-in-version-3-0.md)  
  
-   [Exceções: convertendo a partir de macros de exceção MFC](../mfc/exceptions-converting-from-mfc-exception-macros.md)  
  
-   [Exceções: usando macros MFC e exceções do C\+\+](../mfc/exceptions-using-mfc-macros-and-cpp-exceptions.md)  
  
## Consulte também  
 [Tratamento de exceções C\+\+](../cpp/cpp-exception-handling.md)   
 [Como fazer: Crie as próprias classes personalizadas de exceção?](http://go.microsoft.com/fwlink/?LinkId=128045)