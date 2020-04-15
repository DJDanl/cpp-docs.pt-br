---
title: 'MFC: usando classes de banco de dados sem documentos e exibições'
ms.date: 11/04/2016
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
ms.openlocfilehash: c914a449b73e7da876d2e05b894c016b53881c3b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81360664"
---
# <a name="mfc-using-database-classes-without-documents-and-views"></a>MFC: usando classes de banco de dados sem documentos e exibições

Às vezes, você pode não querer usar a arquitetura de documentos/exibição do framework em seus aplicativos de banco de dados. Este tópico explica:

- [Quando você não precisa usar documentos](#_core_when_you_don.92.t_need_documents) como serialização de documentos.

- [Opções de assistente de aplicativo](#_core_appwizard_options_for_documents_and_views) para suportar aplicativos sem serialização e sem comandos de menu de **arquivos** relacionados a documentos, como **Novo,** **Abrir,** **Salvar**e **Salvar Como**.

- [Como trabalhar com um aplicativo que usa um documento mínimo.](#_core_applications_with_minimal_documents)

- [Como estruturar um aplicativo sem documento ou visualização.](#_core_applications_with_no_document)

## <a name="when-you-do-not-need-documents"></a><a name="_core_when_you_don.92.t_need_documents"></a>Quando você não precisa de documentos

Algumas aplicações têm um conceito distinto de um documento. Esses aplicativos normalmente carregam todos ou a maioria de um arquivo de armazenamento na memória com um comando **File Open.** Eles escrevem o arquivo atualizado de volta ao armazenamento de uma só vez com um comando **'Salvar ou** **salvar como'** O que o usuário vê é um arquivo de dados.

Algumas categorias de aplicações, no entanto, não exigem um documento. Os aplicativos de banco de dados operam em termos de transações. O aplicativo seleciona registros de um banco de dados e os apresenta ao usuário, muitas vezes um de cada vez. O que o usuário vê geralmente é um único registro atual, que pode ser o único na memória.

Se o seu aplicativo não exigir um documento para armazenar dados, você pode dispensar parte ou toda a arquitetura de documentação/exibição da estrutura. O quanto você dispensa depende da abordagem que você prefere. Você pode:

- Use um documento mínimo como um lugar para armazenar uma conexão com sua fonte de dados, mas dispense recursos normais de documentos, como serialização. Isso é útil quando você quer várias visualizações dos dados e deseja sincronizar todas as visualizações, atualizando-as todas de uma vez por todas.

- Use uma janela de quadro, na qual você desenha diretamente, em vez de usar uma vista. Neste caso, você omite o documento e armazena quaisquer conexões de dados ou dados no objeto da janela de quadro.

## <a name="application-wizard-options-for-documents-and-views"></a><a name="_core_appwizard_options_for_documents_and_views"></a>Opções de assistente de aplicativos para documentos e visualizações

O Assistente de Aplicativo Do MFC tem várias opções no **suporte ao banco de dados Select**, que estão listados na tabela a seguir. Se você usar o MFC Application Wizard para criar um aplicativo, todas essas opções produzirão aplicativos com documentos e visualizações. Algumas opções fornecem documentos e visualizações que omitem funcionalidades de documentos desnecessárias. Para obter mais informações, consulte [Database Support, MFC Application Wizard](../mfc/reference/database-support-mfc-application-wizard.md).

|Opção|Visualizar|Document|
|------------|----------|--------------|
|**Nenhum**|Derivada de `CView`.|Não fornece suporte ao banco de dados. Essa é a opção padrão.<br /><br /> Se você selecionar a opção **de suporte à arquitetura de documentos/exibição** na página Tipo de [aplicativo, MFC App Wizard,](../mfc/reference/application-type-mfc-application-wizard.md) você terá suporte completo ao documento, incluindo serialização e **novos,** **abrir,** **salvar**e **salvar como** comandos no menu **Arquivo.** Consulte [aplicativos sem documento](#_core_applications_with_no_document).|
|**Somente arquivos de cabeçalho**|Derivada de `CView`.|Fornece o nível básico de suporte ao banco de dados para sua aplicação.<br /><br /> Inclui Afxdb.h. Adiciona bibliotecas de links, mas não cria nenhuma classe específica de banco de dados. Você pode criar conjuntos de registros mais tarde e usá-los para examinar e atualizar registros.|
|**Exibição de banco de dados sem suporte a arquivos**|Derivado de`CRecordView`|Fornece suporte a documentos, mas sem suporte à serialização. O documento pode armazenar conjunto de registros e coordenar várias visualizações; não suporta serialização ou os comandos **Novo,** **Abrir,** **Salvar**e **Salvar Como.** Consulte [aplicativos com documentos mínimos](#_core_applications_with_minimal_documents). Se você incluir uma exibição de banco de dados, você deve especificar a fonte dos dados.<br /><br /> Inclui arquivos de cabeçalho de banco de dados, bibliotecas de link, uma exibição de registro e um conjunto de registros. (Disponível apenas para aplicativos com a opção **de suporte à arquitetura de documentos/exibição** selecionada na página Do assistente de aplicativo do [MFC.)](../mfc/reference/application-type-mfc-application-wizard.md)|
|**Exibição de banco de dados com suporte a arquivos**|Derivado de`CRecordView`|Fornece suporte completo a documentos, incluindo serialização e comandos de menu **de arquivos** relacionados a documentos. Os aplicativos de banco de dados normalmente operam por registro, em vez de por arquivo e, portanto, não precisam de serialização. No entanto, você pode ter um uso especial para serialização. Consulte [aplicativos com documentos mínimos](#_core_applications_with_minimal_documents). Se você incluir uma exibição de banco de dados, você deve especificar a fonte dos dados.<br /><br /> Inclui arquivos de cabeçalho de banco de dados, bibliotecas de link, uma exibição de registro e um conjunto de registros. (Disponível apenas para aplicativos com a opção **de suporte à arquitetura de documentos/exibição** selecionada na página Do assistente de aplicativo do [MFC.)](../mfc/reference/application-type-mfc-application-wizard.md)|

Para uma discussão sobre alternativas à serialização e usos alternativos para serialização, consulte [Serialização: Serialização vs. Entrada/Saída do banco de dados](../mfc/serialization-serialization-vs-database-input-output.md).

## <a name="applications-with-minimal-documents"></a><a name="_core_applications_with_minimal_documents"></a>Aplicações com Documentos Mínimos

O MFC Application Wizard tem duas opções que suportam aplicativos de acesso a dados baseados em formulários. Cada opção `CRecordView`cria uma classe de exibição derivada e um documento. Eles diferem no que deixam de fora do documento.

### <a name="document-without-file-support"></a><a name="_core_a_document_without_file_support"></a>Documento sem suporte a arquivos

Selecione a opção de banco de dados assistente de aplicativo **Exibição do banco de dados sem suporte a arquivos** se você não precisar de serialização de documentos. O documento serve aos seguintes propósitos úteis:

- É um lugar conveniente `CRecordset` para armazenar um objeto.

   Esse uso faz um paralelo com conceitos ordinários de documentos: o documento armazena os dados (ou, neste caso, um conjunto de registros) e a exibição é uma visão do documento.

- Se o aplicativo apresentar vários pontos de vista (como vários visualizações de registro), um documento suportará a coordenação das exibições.

   Se várias visualizações mostrarem os `CDocument::UpdateAllViews` mesmos dados, você poderá usar a função membro para coordenar atualizações para todas as exibições quando qualquer exibição mudar os dados.

Você geralmente usa essa opção para aplicativos simples baseados em formulários. O assistente de aplicativo suporta uma estrutura conveniente para esses aplicativos automaticamente.

### <a name="document-with-file-support"></a><a name="_core_a_document_with_file_support"></a>Documento com suporte a arquivos

Selecione a opção de banco de dados assistente de aplicativo **Exibição de banco de dados com suporte a arquivos** quando tiver um uso alternativo para os comandos do menu de **arquivos** relacionados a documentos e serialização de documentos. Para a parte de acesso a dados do seu programa, você pode usar o documento da mesma forma que descrito no [Documento Sem Suporte a Arquivos](#_core_a_document_without_file_support). Você pode usar o recurso de serialização do documento, por exemplo, para ler e escrever um documento de perfil de usuário serializado que armazena as preferências do usuário ou outras informações úteis. Para obter mais ideias, consulte [Serialização: Serialização vs. Entrada/Saída do banco de dados](../mfc/serialization-serialization-vs-database-input-output.md).

O assistente do aplicativo suporta essa opção, mas você deve escrever o código que serializa o documento. Armazene as informações serializadas em membros de dados de documentos.

## <a name="applications-with-no-document"></a><a name="_core_applications_with_no_document"></a>Aplicações sem documento

Às vezes, você pode querer escrever um aplicativo que não use documentos ou visualizações. Sem documentos, você armazena seus `CRecordset` dados (como um objeto) na sua classe de janela de quadros ou na classe de aplicativo. Quaisquer requisitos adicionais dependem se o aplicativo apresenta uma interface de usuário.

### <a name="database-support-with-a-user-interface"></a><a name="_core_database_support_with_a_user_interface"></a>Suporte de banco de dados com uma interface de usuário

Se você tiver uma interface de usuário (que não seja, por exemplo, uma interface de linha de comando do console), seu aplicativo se alinha diretamente para a área cliente da janela do quadro, em vez de para uma exibição. Tal aplicativo não `CRecordView`usa `CFormView`, `CDialog` ou para sua interface de `CDialog` usuário principal, mas normalmente usa para diálogos comuns.

### <a name="writing-applications-without-documents"></a><a name="_core_writing_applications_without_documents"></a>Redação de aplicativos sem documentos

Como o assistente de aplicativo não suporta a criação `CWinApp`de aplicativos sem documentos, você `CFrameWnd` deve `CMDIFrameWnd` escrever sua própria classe derivada e, se necessário, também criar uma ou classe. Anular `CWinApp::InitInstance` e declarar um objeto de aplicativo como:

```cpp
CYourNameApp theApp;
```

A estrutura ainda fornece o mecanismo de mapa de mensagens e muitos outros recursos.

### <a name="database-support-separate-from-the-user-interface"></a><a name="_core_database_support_separate_from_the_user_interface"></a>Suporte ao banco de dados separado da interface do usuário

Alguns aplicativos não precisam de interface de usuário ou apenas um mínimo. Por exemplo, suponha que você esteja escrevendo:

- Um objeto intermediário de acesso a dados que outros aplicativos (clientes) exigem para um processamento especial de dados entre o aplicativo e a fonte de dados.

- Um aplicativo que processa dados sem intervenção do usuário, como um aplicativo que move dados de um formato de banco de dados para outro ou um que faz cálculos e realiza atualizações em lote.

Como nenhum documento `CRecordset` possui o objeto, você provavelmente deseja armazená-lo como um membro de dados incorporado em sua `CWinApp`classe de aplicativo derivada. As alternativas incluem:

- Não manter `CRecordset` um objeto permanente. Você pode passar NULL para seus construtores de classe de conjunto de registros. Nesse caso, a estrutura `CDatabase` cria um objeto temporário usando `GetDefaultConnect` as informações na função de membro do conjunto de registros. Esta é a abordagem alternativa mais provável.

- Fazendo `CRecordset` do objeto uma variável global. Esta variável deve ser um ponteiro para um objeto `CWinApp::InitInstance` de conjunto de registros que você cria dinamicamente em sua substituição. Isso evita tentar construir o objeto antes que a estrutura seja inicializada.

- Usando objetos de conjunto de registros como você faria no contexto de um documento ou uma exibição. Crie conjuntos de registros nas funções de membro de objetos de aplicativo ou de janela de quadro.

## <a name="see-also"></a>Confira também

[Classes de banco de dados MFC](../data/mfc-database-classes-odbc-and-dao.md)
