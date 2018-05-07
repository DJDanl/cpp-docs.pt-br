---
title: 'MFC: Usando Classes de banco de dados sem documentos e exibições | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- ODBC applications [C++], without views
- documents [C++], applications without
- ODBC applications [C++]
- document/view architecture [C++], in databases
- files [C++], MFC
- database classes [C++], MFC
- CRecordView class, using in database applications
- database applications [C++], without views
- database applications [C++], application wizard options
- application wizards [C++], creating database applications
- ODBC [C++], file support in database applications
- ODBC applications [C++], without documents
- database applications [C++], without documents
- user interface [C++], drawing information
ms.assetid: 15bf52d4-91cf-4b1d-8b37-87c3ae70123a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: ba2e59b53524975f87e4ad7ffe99b9a4a3cc870d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="mfc-using-database-classes-without-documents-and-views"></a>MFC: usando classes de banco de dados sem documentos e exibições
Às vezes, não convém usar a arquitetura de documento/exibição do framework em seus aplicativos de banco de dados. Este tópico explica:  
  
-   [Quando você não precisa usar documentos](#_core_when_you_don.92.t_need_documents) como a serialização de documento.  
  
-   [Opções do Assistente de aplicativo](#_core_appwizard_options_for_documents_and_views) para oferecer suporte a aplicativos sem serialização e relacionadas a documentos **arquivo** comandos de menu como **novo**, **abrir** , **Salvar**, e **Salvar como**.  
  
-   [Como trabalhar com um aplicativo que usa um documento mínimo](#_core_applications_with_minimal_documents).  
  
-   [Como um aplicativo sem documento ou modo de exibição de estrutura](#_core_applications_with_no_document).  
  
##  <a name="_core_when_you_don.92.t_need_documents"></a> Quando você não precisa documentos  
 Alguns aplicativos têm um conceito distinto de um documento. Esses aplicativos normalmente carrega todos ou a maioria de um arquivo de armazenamento na memória com um **abrir arquivo** comando. For gravar o arquivo atualizado de volta para o armazenamento de uma só vez com um **salvar arquivo** ou **Salvar como** comando. O que o usuário vê é um arquivo de dados.  
  
 No entanto, algumas categorias de aplicativos, não exigem um documento. Aplicativos de banco de dados operam em termos de transações. O aplicativo seleciona os registros de um banco de dados e apresenta ao usuário, geralmente um de cada vez. O que o usuário vê é normalmente um único registro atual, que pode ser o único na memória.  
  
 Se seu aplicativo não precisar de um documento para armazenar dados, você pode dispensar alguns ou todos da arquitetura de documento/exibição do framework. Quanto você dispensar depende a abordagem que você preferir. Você pode:  
  
-   Use um documento mínimo como um local para armazenar uma conexão à fonte de dados, mas dispensador com recursos de um documento normal, como a serialização. Isso é útil quando você deseja várias exibições dos dados e quiser sincronizar todas as exibições, atualizando-os de uma vez e assim por diante.  
  
-   Use uma janela do quadro, na qual desenhar diretamente, em vez de usar um modo de exibição. Nesse caso, você pode omite o documento e armazena os dados ou conexões de dados no objeto de janela com moldura.  
  
##  <a name="_core_appwizard_options_for_documents_and_views"></a> Opções do Assistente de aplicativo para documentos e exibições  
 O Assistente de aplicativo MFC tem várias opções **selecione suporte de banco de dados**, que são listados na tabela a seguir. Se você usar o Assistente de aplicativo MFC para criar um aplicativo, todas essas opções produzem aplicativos com documentos e exibições. Algumas opções fornecem documentos e exibições que omitir a funcionalidade de documento desnecessários. Para obter mais informações, consulte [suporte de banco de dados, o Assistente de aplicativo MFC](../mfc/reference/database-support-mfc-application-wizard.md).  
  
|Opção|Exibir|Documento|  
|------------|----------|--------------|  
|**Nenhum**|Derivado de `CView`.|Não fornece suporte nenhum banco de dados. Esta é a opção padrão.<br /><br /> Se você selecionar o **suporte para a arquitetura de documento/exibição** opção o [tipo de aplicativo, Assistente de aplicativo MFC](../mfc/reference/application-type-mfc-application-wizard.md) página, você obtém suporte de documento completo incluindo serialização e `New`,  **Abra**, **salvar**, e **Salvar como** comandos no **arquivo** menu. Consulte [aplicativos sem documentos](#_core_applications_with_no_document).|  
|**Somente os arquivos de cabeçalho**|Derivado de `CView`.|Fornece o nível básico de suporte de banco de dados para seu aplicativo.<br /><br /> Inclui Afxdb.h. Adiciona bibliotecas de vínculo, mas não cria todas as classes específicas de banco de dados. Você pode criar conjuntos de registros mais tarde e usá-los para examinar e atualizar registros.|  
|**Exibição de banco de dados sem suporte para arquivo**|Derivado de `CRecordView`|Fornece suporte de documento, mas não há suporte de serialização. Documento pode armazenar o conjunto de registros e coordenar os vários modos de exibição; não oferece suporte a serialização ou `New`, **abrir**, **salvar**, e **Salvar como** comandos. Consulte [aplicativos com documentos mínimo](#_core_applications_with_minimal_documents). Se você incluir um modo de exibição de banco de dados, você deve especificar a fonte de dados.<br /><br /> Inclui um conjunto de registros, bibliotecas de vínculo, uma exibição de registro e arquivos de cabeçalho do banco de dados. (Disponível somente para aplicativos com o **suporte para a arquitetura de documento/exibição** opção selecionada no [tipo de aplicativo, Assistente de aplicativo MFC](../mfc/reference/application-type-mfc-application-wizard.md) página.)|  
|**Exibição de banco de dados com suporte para arquivo**|Derivado de `CRecordView`|Fornece suporte total a documentos, incluindo serialização e relacionados ao documento **arquivo** comandos de menu. Aplicativos de banco de dados geralmente operam em uma base por registro em vez de por arquivo base e, portanto não precisa de serialização. No entanto, você pode ter um uso especial para serialização. Consulte [aplicativos com documentos mínimo](#_core_applications_with_minimal_documents). Se você incluir um modo de exibição de banco de dados, você deve especificar a fonte de dados.<br /><br /> Inclui um conjunto de registros, bibliotecas de vínculo, uma exibição de registro e arquivos de cabeçalho do banco de dados. (Disponível somente para aplicativos com o **suporte para a arquitetura de documento/exibição** opção selecionada no [tipo de aplicativo, Assistente de aplicativo MFC](../mfc/reference/application-type-mfc-application-wizard.md) página.)|  
  
 Para obter uma discussão de alternativas para serialização e usos alternativos para a serialização, consulte [serialização: vs de serialização. Banco de dados de entrada/saída](../mfc/serialization-serialization-vs-database-input-output.md).  
  
##  <a name="_core_applications_with_minimal_documents"></a> Aplicativos com documentos mínimos  
 O Assistente de aplicativo MFC tem duas opções com suporte a aplicativos de acesso de dados com base em formulário. Cada opção cria um `CRecordView`-derivado da classe de exibição e um documento. Elas diferem no que eles ficarem fora do documento.  
  
###  <a name="_core_a_document_without_file_support"></a> Documento sem suporte para arquivo  
 Selecione a opção de banco de dados do Assistente de aplicativo **exibição sem suporte para arquivo de banco de dados** se você não precisa de serialização do documento. O documento tem as seguintes finalidades úteis:  
  
-   Ele é um local conveniente para armazenar um `CRecordset` objeto.  
  
     Esse uso comparável ao conceitos de documento comum: o documento armazena os dados (ou, no caso, um conjunto de registros) e a exibição é um modo de exibição do documento.  
  
-   Se seu aplicativo apresenta várias exibições (como várias exibições de registro), um documento oferece suporte para coordenar os modos de exibição.  
  
     Se várias exibições mostram os mesmos dados, você pode usar o `CDocument::UpdateAllViews` a função de membro para coordenar as atualizações para todos os modos de exibição quando qualquer exibição altera os dados.  
  
 Normalmente, você usar essa opção para aplicativos baseados em formulário simples. O Assistente de aplicativo oferece suporte a uma estrutura conveniente para esses aplicativos automaticamente.  
  
###  <a name="_core_a_document_with_file_support"></a> Documento com suporte para arquivo  
 Selecione a opção de banco de dados do Assistente de aplicativo **exibição com suporte a arquivos de banco de dados** quando você tem a alternativa de usar para o documento relacionado **arquivo** comandos de menu e serialização do documento. Para a parte de acesso a dados de seu programa, você pode usar o documento da mesma maneira como descrito em [documento sem suporte do arquivo](#_core_a_document_without_file_support). Você pode usar o recurso de serialização do documento, por exemplo, para ler e gravar um documento de perfil de usuário serializada que armazena as preferências do usuário ou outras informações úteis. Para obter mais ideias, consulte [serialização: vs de serialização. Banco de dados de entrada/saída](../mfc/serialization-serialization-vs-database-input-output.md).  
  
 O Assistente de aplicativo oferece suporte a essa opção, mas você deve escrever o código que serializa o documento. Armazene as informações serializadas em membros de dados de documento.  
  
##  <a name="_core_applications_with_no_document"></a> Aplicativos sem documentos  
 Às vezes, convém escrever um aplicativo que não usa documentos ou exibições. Sem documentos, você armazena seus dados (como um `CRecordset` objeto) em sua classe de janela com moldura ou sua classe de aplicativo. Quaisquer requisitos adicionais dependem se o aplicativo apresenta uma interface do usuário.  
  
###  <a name="_core_database_support_with_a_user_interface"></a> Suporte de banco de dados com uma Interface do usuário  
 Se você tiver uma interface do usuário (diferente de, por exemplo, uma interface de linha de comando do console), seu aplicativo desenha diretamente na área cliente da janela do quadro, em vez de em uma exibição. Esse aplicativo não usa `CRecordView`, `CFormView`, ou `CDialog` para sua interface do usuário principal, mas normalmente usa `CDialog` para caixas de diálogo comuns.  
  
###  <a name="_core_writing_applications_without_documents"></a> Gravação de aplicativos sem documentos  
 Porque o Assistente de aplicativo não oferece suporte a criação de aplicativos sem documentos, você deve escrever suas próprias `CWinApp`-classe derivada e, se necessário, crie também um `CFrameWnd` ou `CMDIFrameWnd` classe. Substituir `CWinApp::InitInstance` e declarar um objeto de aplicativo, como:  
  
```  
CYourNameApp theApp;  
```  
  
 A estrutura ainda fornece o mecanismo de mapa de mensagem e muitos outros recursos.  
  
###  <a name="_core_database_support_separate_from_the_user_interface"></a> Banco de dados separado de suporte da Interface do usuário  
 Alguns aplicativos precisam de nenhuma interface do usuário ou apenas um mínimo. Por exemplo, suponha que você está escrevendo:  
  
-   Um objeto de acesso a dados intermediários que chamam outros aplicativos (clientes) para processamento especial de dados entre o aplicativo e a fonte de dados.  
  
-   Um aplicativo que processa dados sem intervenção do usuário, como um aplicativo que move os dados de um formato de banco de dados para outro ou que faz cálculos e executa as atualizações em lotes.  
  
 Porque nenhum documento possui o `CRecordset` do objeto, você provavelmente deseja armazená-lo como um membro de dados inseridos em seu `CWinApp`-aplicativo classe derivada. As alternativas incluem:  
  
-   Não manter uma permanente `CRecordset` objeto. Você pode passar **nulo** para os construtores de classe de conjunto de registros. Nesse caso, o framework cria um temporário `CDatabase` usando as informações do conjunto de registros do objeto `GetDefaultConnect` função de membro. Essa é a abordagem de alternativa mais provável.  
  
-   Tornando o `CRecordset` uma variável global do objeto. Essa variável deve ser um ponteiro para um objeto de conjunto de registros que você criar dinamicamente no seu `CWinApp::InitInstance` substituir. Isso evita a tentativa de construir o objeto antes da inicialização do framework.  
  
-   Usando objetos de conjunto de registros como você faria no contexto de um documento ou uma exibição. Crie conjuntos de registros no membro de funções de seu aplicativo ou objetos de janela do quadro.  
  
## <a name="see-also"></a>Consulte também  
 [Classes de banco de dados MFC](../data/mfc-database-classes-odbc-and-dao.md)