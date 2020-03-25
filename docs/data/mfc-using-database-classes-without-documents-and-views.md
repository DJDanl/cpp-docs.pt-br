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
ms.openlocfilehash: 57a7abd89bc9bfb465912a35c21f9780668f4466
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213350"
---
# <a name="mfc-using-database-classes-without-documents-and-views"></a>MFC: usando classes de banco de dados sem documentos e exibições

Às vezes, talvez você não queira usar a arquitetura de documentos/exibições da estrutura em seus aplicativos de banco de dados. Este tópico explica:

- [Quando você não precisa usar documentos](#_core_when_you_don.92.t_need_documents) como serialização de documento.

- [Opções do assistente de aplicativo](#_core_appwizard_options_for_documents_and_views) para dar suporte a aplicativos sem serialização e sem comandos de menu de **arquivo** relacionados a documentos, como **novo**, **abrir**, **salvar**e **salvar como**.

- [Como trabalhar com um aplicativo que usa um documento mínimo](#_core_applications_with_minimal_documents).

- [Como estruturar um aplicativo sem nenhum documento ou exibição](#_core_applications_with_no_document).

##  <a name="when-you-do-not-need-documents"></a><a name="_core_when_you_don.92.t_need_documents"></a>Quando você não precisa de documentos

Alguns aplicativos têm um conceito distinto de um documento. Normalmente, esses aplicativos carregam todo ou a maior parte de um arquivo do armazenamento na memória com um comando **File Open** . Eles gravam o arquivo atualizado de volta ao armazenamento de uma só vez com um comando **File Save** ou **Save as** . O que o usuário vê é um arquivo de dados.

No entanto, algumas categorias de aplicativos não exigem um documento. Os aplicativos de banco de dados operam em termos de transações. O aplicativo seleciona registros de um banco de dados e os apresenta ao usuário, geralmente um de cada vez. O que o usuário vê geralmente é um único registro atual, que pode ser o único na memória.

Se seu aplicativo não exigir um documento para armazenar dados, você poderá dispensar com algumas ou todas as arquiteturas de documentos/exibições da estrutura. A quantidade de dispensas com o depende da abordagem que você preferir. Você pode:

- Use um documento mínimo como um local para armazenar uma conexão com sua fonte de dados, mas dispensar com recursos de documentos normais, como serialização. Isso é útil quando você deseja várias exibições dos dados e deseja sincronizar todas as exibições, atualizando-as todas de uma vez e assim por diante.

- Use uma janela de quadro, na qual você desenha diretamente, em vez de usar uma exibição. Nesse caso, você omite o documento e armazena quaisquer dados ou conexões de dados no objeto quadro-janela.

##  <a name="application-wizard-options-for-documents-and-views"></a><a name="_core_appwizard_options_for_documents_and_views"></a>Opções do assistente de aplicativo para documentos e exibições

O assistente de aplicativo do MFC tem várias opções em **selecionar suporte a banco de dados**, que são listadas na tabela a seguir. Se você usar o assistente de aplicativo do MFC para criar um aplicativo, todas essas opções produzirão aplicativos com documentos e exibições. Algumas opções fornecem documentos e exibições que omitem a funcionalidade de documento desnecessária. Para obter mais informações, consulte [suporte a banco de dados, assistente de aplicativo MFC](../mfc/reference/database-support-mfc-application-wizard.md).

|Opção|Visualizar|Document|
|------------|----------|--------------|
|**Nenhuma**|Derivada de `CView`.|Não fornece suporte a banco de dados. Essa é a opção padrão.<br /><br /> Se você selecionar a opção de **suporte de arquitetura de documento/exibição** na página [tipo de aplicativo, assistente de aplicativo MFC](../mfc/reference/application-type-mfc-application-wizard.md) , obterá suporte a documentos completos, incluindo serialização e **novos**, **abrir**, **salvar**e **salvar como** comandos no menu **arquivo** . Consulte [aplicativos sem nenhum documento](#_core_applications_with_no_document).|
|**Somente arquivos de cabeçalho**|Derivada de `CView`.|Fornece o nível básico de suporte de banco de dados para seu aplicativo.<br /><br /> Inclui AFXDB. h. Adiciona bibliotecas de links, mas não cria nenhuma classe específica de banco de dados. Você pode criar conjuntos de registros posteriormente e usá-los para examinar e atualizar registros.|
|**Exibição de banco de dados sem suporte a arquivo**|Derivado de `CRecordView`|Fornece suporte a documentos, mas sem suporte de serialização. O documento pode armazenar conjuntos de registros e coordenar várias exibições; o não oferece suporte à serialização ou aos comandos **novo**, **abrir**, **salvar**e **salvar como** . Consulte [aplicativos com documentos mínimos](#_core_applications_with_minimal_documents). Se você incluir um modo de exibição de banco de dados, deverá especificar a origem dos mesmos.<br /><br /> Inclui arquivos de cabeçalho de banco de dados, bibliotecas de link, uma exibição de registro e um conjunto de registros. (Disponível somente para aplicativos com a opção de **suporte de arquitetura de documento/exibição** selecionada na página [tipo de aplicativo, assistente de aplicativo MFC](../mfc/reference/application-type-mfc-application-wizard.md) .)|
|**Exibição de banco de dados com suporte a arquivos**|Derivado de `CRecordView`|Fornece suporte a documentos completos, incluindo a serialização e comandos de menu de **arquivo** relacionados a documentos. Os aplicativos de banco de dados normalmente operam em uma base por registro, em vez de por arquivo e, portanto, não precisam de serialização. No entanto, você pode ter um uso especial para a serialização. Consulte [aplicativos com documentos mínimos](#_core_applications_with_minimal_documents). Se você incluir um modo de exibição de banco de dados, deverá especificar a origem dos mesmos.<br /><br /> Inclui arquivos de cabeçalho de banco de dados, bibliotecas de link, uma exibição de registro e um conjunto de registros. (Disponível somente para aplicativos com a opção de **suporte de arquitetura de documento/exibição** selecionada na página [tipo de aplicativo, assistente de aplicativo MFC](../mfc/reference/application-type-mfc-application-wizard.md) .)|

Para obter uma discussão de alternativas para serialização e usos alternativos para serialização, consulte [serialização: serialização versus entrada/saída de banco de dados](../mfc/serialization-serialization-vs-database-input-output.md).

##  <a name="applications-with-minimal-documents"></a><a name="_core_applications_with_minimal_documents"></a>Aplicativos com documentos mínimos

O assistente de aplicativo do MFC tem duas opções que dão suporte a aplicativos de acesso a dados baseados em formulário. Cada opção cria uma classe de exibição derivada de `CRecordView`e um documento. Eles diferem no que saem do documento.

###  <a name="document-without-file-support"></a><a name="_core_a_document_without_file_support"></a>Documento sem suporte a arquivo

Selecione a opção de banco de dados do assistente de aplicativo exibição de banco de dados **sem suporte de arquivo** se você não precisar de serialização de documento. O documento oferece as seguintes finalidades úteis:

- É um local conveniente para armazenar um objeto de `CRecordset`.

   Esse uso paraleliza os conceitos de documento comum: o documento armazena os dados (ou, nesse caso, um conjunto de registros) e a exibição é uma exibição do documento.

- Se seu aplicativo apresentar várias exibições (como várias exibições de registro), um documento dará suporte à coordenação de exibições.

   Se várias exibições mostrarem os mesmos dados, você poderá usar a função de membro `CDocument::UpdateAllViews` para coordenar as atualizações para todas as exibições quando qualquer exibição alterar os dados.

Normalmente, você usa essa opção para aplicativos simples baseados em formulário. O assistente de aplicativo dá suporte a uma estrutura conveniente para esses aplicativos automaticamente.

###  <a name="document-with-file-support"></a><a name="_core_a_document_with_file_support"></a>Documento com suporte a arquivos

Selecione a opção de banco de dados do assistente de aplicativo **exibição de banco de dados com suporte a arquivos** quando você tiver um uso alternativo para os comandos de menu de **arquivo** relacionados ao documento e a serialização de documento. Para a parte de acesso a dados do seu programa, você pode usar o documento da mesma maneira descrita em [documento sem suporte a arquivos](#_core_a_document_without_file_support). Você pode usar o recurso de serialização do documento, por exemplo, para ler e gravar um documento de perfil de usuário serializado que armazena as preferências do usuário ou outras informações úteis. Para obter mais ideias, consulte [serialização: serialização versus entrada/saída do banco de dados](../mfc/serialization-serialization-vs-database-input-output.md).

O assistente de aplicativo dá suporte a essa opção, mas você deve escrever o código que serializa o documento. Armazene as informações serializadas em membros de dados de documento.

##  <a name="applications-with-no-document"></a><a name="_core_applications_with_no_document"></a>Aplicativos sem nenhum documento

Às vezes, talvez você queira escrever um aplicativo que não use documentos ou exibições. Sem documentos, você armazena seus dados (como um objeto `CRecordset`) em sua classe de janela de quadro ou sua classe de aplicativo. Quaisquer requisitos adicionais dependem se o aplicativo apresenta uma interface do usuário.

###  <a name="database-support-with-a-user-interface"></a><a name="_core_database_support_with_a_user_interface"></a>Suporte a banco de dados com uma interface do usuário

Se você tiver uma interface do usuário (diferente de, por exemplo, uma interface de linha de comando do console), seu aplicativo será desenhado diretamente na área do cliente da janela do quadro em vez de em uma exibição. Esse aplicativo não usa `CRecordView`, `CFormView`ou `CDialog` para sua interface do usuário principal, mas normalmente usa `CDialog` para caixas de diálogo comuns.

###  <a name="writing-applications-without-documents"></a><a name="_core_writing_applications_without_documents"></a>Gravando aplicativos sem documentos

Como o assistente de aplicativo não oferece suporte à criação de aplicativos sem documentos, você deve escrever sua própria classe derivada de `CWinApp`e, se necessário, também criar uma classe `CFrameWnd` ou `CMDIFrameWnd`. Substitua `CWinApp::InitInstance` e declare um objeto de aplicativo como:

```cpp
CYourNameApp theApp;
```

A estrutura ainda fornece o mecanismo de mapa de mensagens e muitos outros recursos.

###  <a name="database-support-separate-from-the-user-interface"></a><a name="_core_database_support_separate_from_the_user_interface"></a>Suporte a banco de dados separado da interface do usuário

Alguns aplicativos não precisam de nenhuma interface do usuário ou apenas um mínimo. Por exemplo, suponha que você esteja escrevendo:

- Um objeto intermediário de acesso a dados que outros aplicativos (clientes) chamam para processamento especial de dados entre o aplicativo e a fonte de dados.

- Um aplicativo que processa dados sem intervenção do usuário, como um aplicativo que move dados de um formato de banco de dado para outro ou um que faz cálculos e executa atualizações em lotes.

Como nenhum documento possui o objeto `CRecordset`, você provavelmente desejará armazená-lo como um membro de dados incorporado em sua classe de aplicativo derivada `CWinApp`. As alternativas incluem:

- Não manter um objeto `CRecordset` permanente. Você pode passar NULL para seus construtores de classe do conjunto de registros. Nesse caso, a estrutura cria um objeto de `CDatabase` temporário usando as informações na função de membro `GetDefaultConnect` do conjunto de registros. Essa é a abordagem alternativa mais provável.

- Tornando o objeto `CRecordset` uma variável global. Essa variável deve ser um ponteiro para um objeto Recordset criado dinamicamente em sua substituição de `CWinApp::InitInstance`. Isso evita a tentativa de construir o objeto antes que a estrutura seja inicializada.

- Usando objetos Recordset como você faria dentro do contexto de um documento ou de uma exibição. Crie conjuntos de registros nas funções de membro de seus objetos de aplicativo ou janela de quadro.

## <a name="see-also"></a>Confira também

[Classes de banco de dados MFC](../data/mfc-database-classes-odbc-and-dao.md)
