---
title: "MFC: usando classes de banco de dados sem documentos e exibi&#231;&#245;es | Microsoft Docs"
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
  - "Aplicativos ODBC [C++], sem exibições"
  - "documentos [C++], aplicativos sem"
  - "Aplicativos ODBC [C++]"
  - "DAO [C++], criação de aplicativos"
  - "arquitetura [C++], em bancos de dados de documento/exibição"
  - "arquivos [C++], MFC"
  - "DAO [C++], suporte a arquivos em aplicativos de banco de dados"
  - "classes de banco de dados [C++], MFC"
  - "Classe CRecordView usando em aplicativos de banco de dados"
  - "aplicativos de banco de dados [C++], sem exibições"
  - "Classe CDaoRecordView usando em aplicativos de banco de dados"
  - "aplicativos de banco de dados [C++], opções do Assistente de aplicativo"
  - "Assistentes de aplicativo [C++], criando aplicativos de banco de dados"
  - "ODBC [C++], suporte a arquivos em aplicativos de banco de dados"
  - "Aplicativos ODBC [C++], sem documentos"
  - "aplicativos de banco de dados [C++], sem documentos"
  - "informações de desenho de interface de usuário [C++]"
ms.assetid: 15bf52d4-91cf-4b1d-8b37-87c3ae70123a
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# MFC: usando classes de banco de dados sem documentos e exibi&#231;&#245;es
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Talvez você não deseje usar a arquitetura de documento\/exibição da estrutura em seus aplicativos de banco de dados. Este tópico explica:  
  
-   [Quando você não precisa usar documentos](#_core_when_you_don.92.t_need_documents) como a serialização de documentos.  
  
-   [Opções do Assistente de aplicativo](#_core_appwizard_options_for_documents_and_views) para oferecer suporte a aplicativos sem serialização e relacionadas a documentos **arquivo** comandos de menu, como **novo**, **Abrir**, **Salvar**, e **Salvar como**.  
  
-   [Como trabalhar com um aplicativo que usa um documento mínimo](#_core_applications_with_minimal_documents).  
  
-   [Como estruturar um aplicativo sem documento ou exibição](#_core_applications_with_no_document).  
  
##  <a name="_core_when_you_don.92.t_need_documents"></a> Quando você não precisa de documentos  
 Alguns aplicativos têm um conceito distinto de um documento. Esses aplicativos normalmente carrega todos ou a maior parte de um arquivo de armazenamento na memória com um **Abrir arquivo** comando. Eles gravam o arquivo atualizado novamente para o armazenamento de uma só vez com um **Salvar arquivo** ou **Salvar como** comando. O que o usuário vê é um arquivo de dados.  
  
 Algumas categorias de aplicativos, no entanto, não exigem um documento. Aplicativos de banco de dados operam em termos de transações. O aplicativo seleciona os registros do banco de dados e apresenta ao usuário, geralmente um de cada vez. O que o usuário vê é normalmente um único registro atual, que pode ser o único na memória.  
  
 Se seu aplicativo não precisar de um documento para armazenar dados, você pode dispensar alguns ou todos da arquitetura de documento\/exibição da estrutura. Quanto você dispensar depende a abordagem desejada. Você pode:  
  
-   Use um documento mínimo como um local para armazenar uma conexão à fonte de dados, mas dispensador com recursos de um documento normal, como a serialização. Isso é útil quando você deseja vários modos de exibição dos dados e quiser sincronizar todas as exibições, atualizando\-os todos de uma vez e assim por diante.  
  
-   Use uma janela de quadro, em que você desenhar diretamente, em vez de usar um modo de exibição. Nesse caso, você omite o documento e armazena todos os dados ou conexões de dados no objeto de janela do quadro.  
  
##  <a name="_core_appwizard_options_for_documents_and_views"></a> Opções do Assistente de aplicativo para documentos e exibições  
 O Assistente para aplicativo do MFC tem várias opções **Selecione suporte de banco de dados**, que são listados na tabela a seguir. Se você usar o Assistente para aplicativo do MFC para criar um aplicativo, todas essas opções produzem aplicativos com documentos e exibições. Algumas opções fornecem documentos e exibições que omitem funcionalidade documentos desnecessários. Para obter mais informações, consulte [Suporte ao banco de dados, Assistente de Aplicativo MFC](../mfc/reference/database-support-mfc-application-wizard.md).  
  
|Opção|Modo de Exibição|Documento|  
|-----------|----------------------|---------------|  
|**Nenhum**|Derivado de `CView`.|Não fornece suporte de nenhum banco de dados. Essa é a opção padrão.<br /><br /> Se você selecionar o **suporte para a arquitetura de documento\/exibição** opção o [Tipo de aplicativo, Assistente de Aplicativo MFC](../Topic/Application%20Type,%20MFC%20Application%20Wizard.md) página, você obtém suporte total a documentos incluindo serialização e `New`, **Abrir**, **Salvar**, e **Salvar como** comandos no **arquivo** menu. Consulte [aplicativos sem documentos](#_core_applications_with_no_document).|  
|**Somente os arquivos de cabeçalho**|Derivado de `CView`.|Fornece o nível básico de suporte de banco de dados para seu aplicativo.<br /><br /> Inclui afxdb. h. Adiciona as bibliotecas de vínculo, mas não cria as classes de banco de dados específico. Você pode criar conjuntos de registros posteriormente e usá\-los para examinar e atualizar registros.|  
|**Exibição de banco de dados sem suporte de arquivo**|Derivado de `CRecordView`|Oferece suporte a documentos, mas não há suporte para serialização. Documento pode armazenar um conjunto de registros e coordenar várias exibições; não oferece suporte à serialização ou o `New`, **Abrir**, **Salvar**, e **Salvar como** comandos. Consulte [aplicativos com documentos mínimo](#_core_applications_with_minimal_documents). Se você incluir um modo de exibição de banco de dados, você deve especificar a fonte de dados.<br /><br /> Inclui um conjunto de registros, bibliotecas de vínculo, uma exibição de registro e arquivos de cabeçalho do banco de dados. \(Disponível somente para aplicativos com o **suporte para a arquitetura de documento\/exibição** opção selecionada no [Tipo de aplicativo, Assistente de Aplicativo MFC](../Topic/Application%20Type,%20MFC%20Application%20Wizard.md) página.\)|  
|**Exibição de banco de dados com suporte a arquivos**|Derivado de `CRecordView`|Fornece suporte total a documentos, incluindo serialização e relacionadas a documentos **arquivo** comandos de menu. Aplicativos de banco de dados geralmente operam em uma base por registro, em vez de em cada arquivo base e, portanto não é necessário serialização. No entanto, você pode ter um uso especial para serialização. Consulte [aplicativos com documentos mínimo](#_core_applications_with_minimal_documents). Se você incluir um modo de exibição de banco de dados, você deve especificar a fonte de dados.<br /><br /> Inclui um conjunto de registros, bibliotecas de vínculo, uma exibição de registro e arquivos de cabeçalho do banco de dados. \(Disponível somente para aplicativos com o **suporte para a arquitetura de documento\/exibição** opção selecionada no [Tipo de aplicativo, Assistente de Aplicativo MFC](../Topic/Application%20Type,%20MFC%20Application%20Wizard.md) página.\)|  
  
 Para uma discussão sobre alternativas para serialização e usos alternativos para serialização, consulte [Serialização: serialização em comparação com entrada\/saída do banco de dados](../mfc/serialization-serialization-vs-database-input-output.md).  
  
##  <a name="_core_applications_with_minimal_documents"></a> Aplicativos com documentos mínimos  
 O Assistente para aplicativo do MFC tem duas opções que oferecem suporte a aplicativos de acesso de dados com base em formulário. Cada opção cria um `CRecordView`\-derivado da classe de exibição e um documento. Elas podem diferir em eles saem fora do documento.  
  
###  <a name="_core_a_document_without_file_support"></a> Documento sem suporte de arquivo  
 Selecione a opção de banco de dados do Assistente de aplicativo **exibição sem suporte a arquivos de banco de dados** se você não precisar de serialização do documento. O documento tem as seguintes finalidades úteis:  
  
-   É um local conveniente para armazenar um `CRecordset` objeto.  
  
     Esse uso comparável ao conceitos de documento comum: o documento armazena os dados \(ou, neste caso, um conjunto de registros\) e a exibição é um modo de exibição do documento.  
  
-   Se seu aplicativo apresenta vários modos de exibição \(como várias exibições de registro\), um documento oferece suporte para coordenar os modos de exibição.  
  
     Se várias exibições mostram os mesmos dados, você pode usar o `CDocument::UpdateAllViews` a função de membro para coordenar as atualizações para todos os modos de exibição quando qualquer exibição altera os dados.  
  
 Você geralmente pode usar essa opção para aplicativos baseados em formulário simples. O Assistente de aplicativo oferece suporte a uma estrutura conveniente para tais aplicativos automaticamente.  
  
###  <a name="_core_a_document_with_file_support"></a> Documento com suporte a arquivos  
 Selecione a opção de banco de dados do Assistente de aplicativo **exibição com suporte a arquivos de banco de dados** quando você tem a alternativa de usar para o documento relacionado **arquivo** comandos de menu e serialização do documento. Parte de acesso a dados do programa, você pode usar o documento da mesma maneira como descrito em [documento sem suporte a arquivo](#_core_a_document_without_file_support). Você pode usar o recurso de serialização do documento, por exemplo, para ler e gravar um documento de perfil de usuário serializado que armazena as preferências do usuário ou outras informações úteis. Para obter mais idéias, consulte [Serialização: serialização em comparação com entrada\/saída do banco de dados](../mfc/serialization-serialization-vs-database-input-output.md).  
  
 O Assistente de aplicativo oferece suporte a essa opção, mas você deve escrever o código que serializa o documento. Armazene as informações serializadas em membros de dados de documentos.  
  
##  <a name="_core_applications_with_no_document"></a> Aplicativos sem documentos  
 Às vezes, convém escrever um aplicativo que não usa documentos ou exibições. Sem documentos, você pode armazenar os dados \(como uma `CRecordset` objeto\) em sua classe de janela de quadro ou sua classe de aplicativo. Quaisquer requisitos adicionais dependem se o aplicativo apresenta uma interface do usuário.  
  
###  <a name="_core_database_support_with_a_user_interface"></a> Suporte de banco de dados com uma Interface do usuário  
 Se você tiver uma interface do usuário \(diferente de, por exemplo, uma interface de linha de comando do console\), seu aplicativo desenha diretamente na área cliente da janela de quadro em vez de em uma exibição. Esse aplicativo não usa `CRecordView`, `CFormView`, ou `CDialog` para sua interface do usuário principal, mas normalmente usa `CDialog` para caixas de diálogo comuns.  
  
###  <a name="_core_writing_applications_without_documents"></a> Escrevendo aplicativos sem documentos  
 Porque o Assistente de aplicativo não oferece suporte a criação de aplicativos sem documentos, você deve escrever seu próprio `CWinApp`\-classe derivada e, se necessário, crie também um `CFrameWnd` ou `CMDIFrameWnd` classe. Substituir `CWinApp::InitInstance` e declarar um objeto de aplicativo como:  
  
```  
CYourNameApp theApp;  
```  
  
 O framework ainda fornece o mecanismo de mapa de mensagem e muitos outros recursos.  
  
###  <a name="_core_database_support_separate_from_the_user_interface"></a> Banco de dados separado de suporte da Interface do usuário  
 Alguns aplicativos precisam de nenhuma interface do usuário ou somente um mínimo. Por exemplo, suponha que você está escrevendo:  
  
-   Um objeto de acesso a dados intermediários que outros aplicativos \(clientes\) exigem processamento especial de dados entre o aplicativo e a fonte de dados.  
  
-   Um aplicativo que processa dados sem intervenção do usuário, como um aplicativo que move dados de um formato de banco de dados para outro ou que faz os cálculos e executa as atualizações em lotes.  
  
 Como nenhum documento possui o `CRecordset` ou `CDaoRecordset` do objeto, você provavelmente desejará armazená\-la como um membro de dados inseridos em seu `CWinApp`\-aplicativo classe derivada. As alternativas incluem:  
  
-   Não manter uma permanente `CRecordset` ou `CDaoRecordset` objeto. Você pode passar **nulo** para seus construtores de classe de conjunto de registros. Nesse caso, o framework cria um temporário `CDatabase` ou `CDaoDatabase` objeto usando as informações no conjunto de registros `GetDefaultConnect` função de membro. Essa é a abordagem alternativa mais provável.  
  
-   Tornando o `CRecordset` ou `CDaoRecordset` uma variável global do objeto. Essa variável deve ser um ponteiro para um objeto de conjunto de registros que você criar dinamicamente no seu `CWinApp::InitInstance` Substituir. Isso evita a tentativa de construir o objeto antes que a estrutura seja inicializada.  
  
-   Usando objetos de conjunto de registros como faria no contexto de um documento ou uma exibição. Crie conjuntos de registros no membro de funções de seu aplicativo ou objetos de janela do quadro.  
  
## Consulte também  
 [Classes de banco de dados MFC \(ODBC e DAO\)](../Topic/MFC%20Database%20Classes%20\(ODBC%20and%20DAO\).md)