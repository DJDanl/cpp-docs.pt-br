---
title: 'MFC: Usando Classes de banco de dados sem documentos e exibições'
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
ms.openlocfilehash: ab9946609fa20c4644873a684a754cbc8a41742f
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59024628"
---
# <a name="mfc-using-database-classes-without-documents-and-views"></a>MFC: Usando Classes de banco de dados sem documentos e exibições

Às vezes, não convém usar a arquitetura de documento/exibição da estrutura em seus aplicativos de banco de dados. Este tópico explica:

- [Quando você não precisa usar documentos](#_core_when_you_don.92.t_need_documents) , como a serialização de documento.

- [Opções do Assistente de aplicativo](#_core_appwizard_options_for_documents_and_views) para dar suporte a aplicativos sem a serialização e sem relacionadas a documentos **arquivo** comandos de menu, como **New**, **abrir** , **Salve**, e **Salvar como**.

- [Como trabalhar com um aplicativo que usa um documento mínimo](#_core_applications_with_minimal_documents).

- [Como estruturar um aplicativo com nenhum documento ou o modo de exibição](#_core_applications_with_no_document).

##  <a name="_core_when_you_don.92.t_need_documents"></a> Quando você não precisa documentos

Alguns aplicativos têm um conceito distinto de um documento. Esses aplicativos normalmente carrega todos ou a maioria de um arquivo de armazenamento na memória com um **abrir arquivo** comando. Eles write-back o arquivo atualizado para o armazenamento de uma só vez com um **salvar arquivo** ou **Salvar como** comando. O que o usuário vê é um arquivo de dados.

Algumas categorias de aplicativos, no entanto, não exigem um documento. Aplicativos de banco de dados operam em termos de transações. O aplicativo seleciona os registros de um banco de dados e apresenta ao usuário, geralmente um por vez. O que o usuário vê é normalmente um único registro atual, que pode ser o único na memória.

Se seu aplicativo não exigir um documento para o armazenamento de dados, você pode dispensar com alguns ou todos da arquitetura de documento/exibição da estrutura. Quanto você dispensar depende a abordagem que você preferir. Você pode:

- Use um documento mínimo como um local para armazenar uma conexão à fonte de dados, mas dispensador com recursos de documento normal, como a serialização. Isso é útil quando você quiser vários modos de exibição dos dados e quiser sincronizar todas as exibições, atualizando-os ao mesmo tempo e assim por diante.

- Use uma janela de quadro no qual você desenhar diretamente, em vez de usar um modo de exibição. Nesse caso, você pode omite o documento e armazena dados ou conexões de dados no objeto de janela com moldura.

##  <a name="_core_appwizard_options_for_documents_and_views"></a> Opções do Assistente de aplicativo para documentos e exibições

O Assistente de aplicativo do MFC tem várias opções **selecione o suporte de banco de dados**, que são listadas na tabela a seguir. Se você usar o Assistente de aplicativo do MFC para criar um aplicativo, todas essas opções produzirem aplicativos com documentos e exibições. Algumas opções fornecem documentos e exibições que omitem funcionalidade desnecessários do documento. Para obter mais informações, consulte [suporte de banco de dados, o Assistente de aplicativo MFC](../mfc/reference/database-support-mfc-application-wizard.md).

|Opção|Exibir|Documento|
|------------|----------|--------------|
|**Nenhum**|Derivada de `CView`.|Não fornece suporte de nenhum banco de dados. Esta é a opção padrão.<br /><br /> Se você selecionar o **suporte de arquitetura de documento/exibição** opção a [tipo de aplicativo, Assistente de aplicativo MFC](../mfc/reference/application-type-mfc-application-wizard.md) página, você obtém suporte de documento completo, incluindo a serialização e **novo** , **Aberto**, **salvar**, e **Salvar como** os comandos no **arquivo** menu. Ver [aplicativos sem nenhum documento](#_core_applications_with_no_document).|
|**Somente os arquivos de cabeçalho**|Derivada de `CView`.|Fornece o nível básico de suporte do banco de dados para seu aplicativo.<br /><br /> Inclui afxdb. h. Adiciona bibliotecas de vínculo, mas não cria quaisquer classes específicas de banco de dados. Você pode criar conjuntos de registros mais tarde e usá-los para examinar e atualizar registros.|
|**Exibição de banco de dados sem suporte para arquivo**|Derivado de `CRecordView`|Fornece suporte a documentos, mas não há suporte de serialização. Documento pode armazenar o conjunto de registros e coordenar várias exibições; não oferece suporte a serialização ou o **New**, **abra**, **salvar**, e **Salvar como** comandos. Ver [aplicativos com o mínimo documentos](#_core_applications_with_minimal_documents). Se você incluir um modo de exibição de banco de dados, você deve especificar a fonte de dados.<br /><br /> Inclui um conjunto de registros, bibliotecas de vínculo, uma exibição de registro e arquivos de cabeçalho do banco de dados. (Disponível somente para aplicativos com o **suporte de arquitetura de documento/exibição** opção selecionada na [tipo de aplicativo, Assistente de aplicativo MFC](../mfc/reference/application-type-mfc-application-wizard.md) página.)|
|**Exibição de banco de dados com suporte para arquivo**|Derivado de `CRecordView`|Fornece suporte total a documentos, incluindo a serialização e relacionadas a documentos **arquivo** comandos de menu. Aplicativos de banco de dados geralmente operam em uma base por registro, em vez de por arquivo base e, portanto, não precisa de serialização. No entanto, você pode ter um uso especial para serialização. Ver [aplicativos com o mínimo documentos](#_core_applications_with_minimal_documents). Se você incluir um modo de exibição de banco de dados, você deve especificar a fonte de dados.<br /><br /> Inclui um conjunto de registros, bibliotecas de vínculo, uma exibição de registro e arquivos de cabeçalho do banco de dados. (Disponível somente para aplicativos com o **suporte de arquitetura de documento/exibição** opção selecionada na [tipo de aplicativo, Assistente de aplicativo MFC](../mfc/reference/application-type-mfc-application-wizard.md) página.)|

Para uma discussão sobre alternativas para serialização e usos alternativos para serialização, consulte [serialização: Serialização vs. Entrada/saída de banco de dados](../mfc/serialization-serialization-vs-database-input-output.md).

##  <a name="_core_applications_with_minimal_documents"></a> Aplicativos com documentos mínimos

O Assistente de aplicativo do MFC tem duas opções que dão suporte a aplicativos de acesso de dados com base em formulário. Cada opção cria um `CRecordView`-derivado da classe de exibição e um documento. Elas podem diferir no que eles deixam de fora do documento.

###  <a name="_core_a_document_without_file_support"></a> Documento sem suporte para arquivo

Selecione a opção de banco de dados do Assistente de aplicativo **modo de exibição sem suporte a arquivos de banco de dados** se você não precisa de serialização de documento. O documento tem as seguintes finalidades úteis:

- Ele é um local conveniente para armazenar um `CRecordset` objeto.

   Esse uso é comparável a conceitos de documento comum: o documento armazena os dados (ou, nesse caso, um conjunto de registros) e a exibição é um modo de exibição do documento.

- Se seu aplicativo apresenta vários modos de exibição (como várias exibições de registro), um documento dá suporte a coordenar os modos de exibição.

   Se várias exibições mostram os mesmos dados, você pode usar o `CDocument::UpdateAllViews` a função de membro para coordenar as atualizações para todos os modos de exibição quando qualquer modo de exibição altera os dados.

Você geralmente pode usar essa opção para aplicativos simples baseados em formulário. O Assistente de aplicativo dá suporte a uma estrutura conveniente para tais aplicativos automaticamente.

###  <a name="_core_a_document_with_file_support"></a> Documento com suporte para arquivo

Selecione a opção de banco de dados do Assistente de aplicativo **modo de exibição com suporte a arquivos de banco de dados** quando você tem a alternativa de usar para o documento relacionado **arquivo** comandos de menu e serialização do documento. Parte de acesso a dados do seu programa, você pode usar o documento da mesma maneira como descrito em [documento sem suporte a arquivos](#_core_a_document_without_file_support). Você pode usar o recurso de serialização do documento, por exemplo, para ler e gravar um documento de perfil de usuário serializada que armazena as preferências do usuário ou outras informações úteis. Para obter mais ideias, consulte [serialização: Serialização vs. Entrada/saída de banco de dados](../mfc/serialization-serialization-vs-database-input-output.md).

O Assistente de aplicativo dá suporte a essa opção, mas você deve escrever o código que serializa o documento. Store as informações serializadas em membros de dados do documento.

##  <a name="_core_applications_with_no_document"></a> Aplicativos sem nenhum documento

Às vezes, você talvez queira escrever um aplicativo que não usa documentos ou modos de exibição. Sem documentos, você armazena seus dados (como um `CRecordset` objeto) em sua classe de janela com moldura ou sua classe de aplicativo. Quaisquer requisitos adicionais dependem se o aplicativo apresenta uma interface do usuário.

###  <a name="_core_database_support_with_a_user_interface"></a> Suporte de banco de dados com uma Interface do usuário

Se você tiver uma interface do usuário (em vez de, por exemplo, uma interface de linha de comando do console), seu aplicativo desenha diretamente na área de cliente da janela do quadro, em vez de em uma exibição. Esse aplicativo não usa `CRecordView`, `CFormView`, ou `CDialog` para sua interface do usuário principal, mas normalmente usa `CDialog` para caixas de diálogo comuns.

###  <a name="_core_writing_applications_without_documents"></a> Escrevendo aplicativos sem documentos

Porque o Assistente de aplicativo não oferece suporte a criação de aplicativos sem documentos, você deve escrever seu próprio `CWinApp`-classe derivada e, se necessário, crie também uma `CFrameWnd` ou `CMDIFrameWnd` classe. Substituir `CWinApp::InitInstance` e declarar um objeto de aplicativo, como:

```cpp
CYourNameApp theApp;
```

A estrutura ainda fornece o mecanismo de mapa de mensagens e muitos outros recursos.

###  <a name="_core_database_support_separate_from_the_user_interface"></a> Banco de dados separado de suporte da Interface do usuário

Alguns aplicativos precisam de nenhuma interface do usuário ou apenas um mínimo. Por exemplo, suponha que você está escrevendo:

- Um objeto de acesso a dados intermediários que outros aplicativos (clientes) exigem um processamento especial de dados entre o aplicativo e a fonte de dados.

- Um aplicativo que processa os dados sem intervenção do usuário, como um aplicativo que move dados de um formato de banco de dados para outro ou que faz cálculos e executa as atualizações em lotes.

Como nenhum documento possui o `CRecordset` do objeto, você provavelmente deseja armazená-lo como um membro de dados inseridos em seu `CWinApp`-aplicativo classe derivada. As alternativas incluem:

- Não manter uma permanente `CRecordset` em todos os do objeto. É possível passar NULL para seus construtores de classe do conjunto de registros. Nesse caso, o framework cria um temporário `CDatabase` usando as informações no conjunto de registros do objeto `GetDefaultConnect` função de membro. Isso é a abordagem alternativa mais provável.

- Tornando o `CRecordset` uma variável global do objeto. Essa variável deve ser um ponteiro para um objeto de conjunto de registros que você criar dinamicamente no seu `CWinApp::InitInstance` substituir. Isso evita que a tentativa de construir o objeto antes que a estrutura seja inicializada.

- Usando objetos de conjunto de registros, como você faria no contexto de um documento ou uma exibição. Crie conjuntos de registros no membro de funções de seu aplicativo ou objetos de janela do quadro.

## <a name="see-also"></a>Consulte também

[Classes de banco de dados MFC](../data/mfc-database-classes-odbc-and-dao.md)