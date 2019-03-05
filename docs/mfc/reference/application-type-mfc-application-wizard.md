---
title: Tipo de aplicativo, Assistente de Aplicativo MFC
ms.date: 11/04/2016
f1_keywords:
- vc.appwiz.mfc.exe.apptype
helpviewer_keywords:
- static libraries, MFC
ms.assetid: c3f62b0e-3f13-42c5-9859-d3890d0c3e1d
ms.openlocfilehash: de23c59fdb59f6f40e256589c5450a8118bb8e5c
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57281246"
---
# <a name="application-type-mfc-application-wizard"></a>Tipo de aplicativo, Assistente de Aplicativo MFC

Use esta página do [Assistente de aplicativo MFC](../../mfc/reference/mfc-application-wizard.md) para criar e adicionar recursos básicos para um novo aplicativo do MFC.

- **Tipo de aplicativo**

  Especifica o tipo de suporte de documento que você deseja criar em seu aplicativo. O tipo de aplicativo que você selecionar determina as opções de interface do usuário que estão disponíveis para seu aplicativo. Ver [recursos de Interface do usuário, o Assistente de aplicativo MFC](../../mfc/reference/user-interface-features-mfc-application-wizard.md) para obter mais informações.

   Para obter mais informações sobre os tipos de documentos, consulte:

  - [SDI e MDI](../../mfc/sdi-and-mdi.md)

  - [Janelas com moldura](../../mfc/frame-windows.md)

  - [Classes de janela com moldura](../../mfc/frame-window-classes.md)

  - [Documentos, exibições e o Framework](../../mfc/documents-views-and-the-framework.md)

  - [Caixas de diálogo](../../mfc/dialog-boxes.md)

  |Opção|Descrição|
  |------------|-----------------|
  |**Documento único**|Cria uma arquitetura de interface (SDI) de documento único para seu aplicativo, onde uma classe de exibição é baseada em [classe CView](../../mfc/reference/cview-class.md). Você pode alterar a classe base para o modo de exibição de [Classes geradas, Assistente de aplicativo MFC](../../mfc/reference/generated-classes-mfc-application-wizard.md) página do assistente. Para criar um aplicativo baseado em formulário, por exemplo, use [classe CFormView](../../mfc/reference/cformview-class.md) para a classe de exibição.<br /><br /> Esse tipo de aplicativo, a janela do quadro do documento pode conter apenas um documento.|
  |**Vários documentos**|Cria uma arquitetura de MDI (interface MDI) vários documentos para seu aplicativo, onde uma classe de exibição é baseada em `CView`. Você pode alterar a classe base para o modo de exibição de **Classes geradas** página do assistente. Para criar um aplicativo baseado em formulário, por exemplo, use `CFormView` para a classe de exibição.<br /><br /> Esse tipo de aplicativo, a janela do quadro do documento pode conter vários filhos windows.|
  |**Documentos com guias**|Coloca cada documento em uma guia separada.|
  |**Caixa de diálogo com base em**|Cria uma arquitetura baseada em caixa de diálogo para seu aplicativo em que uma classe de caixa de diálogo é baseada em `CDialog`. (Para criar uma caixa de diálogo HTML, marque a caixa **caixa de diálogo HTML Use**.)|
  |**Use a caixa de diálogo HTML**|Caixa de diálogo caixa apenas para aplicativos. Derive a classe de caixa de diálogo do [classe CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md) em vez de [classe CDialog](../../mfc/reference/cdialog-class.md). Se você marcar essa caixa `CDHtmlDialog` está listado na **classe Base** caixa a [Classes geradas, Assistente de aplicativo MFC](../../mfc/reference/generated-classes-mfc-application-wizard.md) página do assistente.<br /><br /> Um `CDHtmlDialog`-caixa de diálogo derivada exibe as caixas de diálogo baseada em HTML, trocas de dados com HTML controlam e manipula os eventos HTML.|
  |**Vários documentos de nível superior**|Cria uma arquitetura de nível superior várias para seu aplicativo, onde uma classe de exibição é baseada em `CView`.<br /><br /> Nesse tipo de aplicativo, quando um usuário clica **New** (ou **novo quadro**) sobre o **arquivo** menu, o aplicativo cria uma janela cujo pai é implicitamente a área de trabalho. O novo quadro do documento aparece na barra de tarefas e não é restrito para área de cliente da janela do aplicativo.|

- **Suporte de arquitetura de documento/exibição**

  Especifica se a arquitetura de documento/exibição em seu aplicativo usando o [classe CDocument](../../mfc/reference/cdocument-class.md) e o [classe CView](../../mfc/reference/cview-class.md) (padrão). Desmarque essa caixa de seleção se você estiver portando um aplicativo não MFC ou se desejar reduzir o tamanho do seu executável compilado. Por padrão, um aplicativo sem a arquitetura de documento/exibição deriva [classe CWinApp](../../mfc/reference/cwinapp-class.md), e não tem suporte do MFC para abrir um documento de um arquivo de disco.

- **Idioma de recurso**

  Define o idioma de seus recursos. A lista exibe os idiomas disponíveis em seu sistema, como instalado pelo Visual Studio. Se você quiser selecionar um idioma diferente do idioma do seu sistema, a pasta de modelo apropriado para esse idioma já deve estar instalada.

  O idioma que você selecionar será refletido na **strings localizadas** opção do [cadeias de caracteres de modelo de documento, Assistente de aplicativo MFC](../../mfc/reference/document-template-strings-mfc-application-wizard.md) página do assistente.

- **Usar bibliotecas de Unicode**

  Especifica se a versão Unicode ou não-Unicode das bibliotecas MFC é usada.

- **Estilo de projeto**

  Indica se o seu aplicativo tem um padrão MFC, Explorador de arquivos, o Visual Studio, ou arquitetura do Office e exibição. Para obter mais informações, consulte [criando um aplicativo MFC no estilo do Explorer arquivo](../../mfc/reference/creating-a-file-explorer-style-mfc-application.md).

  |Opção|Descrição|
  |------------|-----------------|
  |**Padrão do MFC**|Fornece uma arquitetura de aplicativos padrão do MFC.|
  |**Explorador de arquivos**|Implementa um aplicativo semelhante ao Explorer do arquivo por meio de uma janela separadora onde o painel esquerdo é um [classe CTreeView](../../mfc/reference/ctreeview-class.md) e o painel direito é um [classe CListView](../../mfc/reference/clistview-class.md).|
  |**Visual Studio**|Implementa um aplicativo do Visual Studio semelhante que contém quatro painéis encaixável (**File View**, **Class View**, **propriedades**, e **saída**) que são derivados de [classe CDockablePane](../../mfc/reference/cdockablepane-class.md) e uma janela de quadro principal que é derivada de [classe CMDIFrameWndEx](../../mfc/reference/cmdiframewndex-class.md) (padrão).|
  |**Office**|Implementa um aplicativo semelhante do Office que contém uma faixa de opções que é derivada de [classe CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md), que é derivada de uma barra do Outlook [classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md), uma barra de legenda que é derivada de [Classe CMFCCaptionBar](../../mfc/reference/cmfccaptionbar-class.md)e um quadro principal que é derivado de [classe CMDIFrameWndEx](../../mfc/reference/cmdiframewndex-class.md).|

- **As cores e estilo visual**

  Determina o estilo visual do aplicativo. As seguintes opções estão disponíveis:

  - **Windows nativo/padrão**

  - **Office 2003**

  - **Visual Studio 2005**

  - **Office 2007 (tema azul)**

  - **Office 2007 (tema preto)**

  - **Office 2007 (tema prateado)**

  - **Office 2007 (tema Aqua)**

- **Habilitar a alternância de estilo visual**

  Especifica se o usuário pode alterar o estilo visual do aplicativo em tempo de execução, geralmente, selecionando o estilo visual de apropriada de um menu ou a faixa de opções.

- **Uso do MFC**

  Especifica como vincular à biblioteca do MFC. Por padrão, o MFC é vinculada como uma DLL compartilhada.

  |Opção|Descrição|
  |------------|-----------------|
  |**Usar MFC em uma DLL compartilhada**|Vincula a biblioteca do MFC para um aplicativo como uma DLL compartilhada. O aplicativo faz chamadas para a biblioteca do MFC em tempo de execução. Essa opção reduz os requisitos de disco e memória de aplicativos que consistem em vários arquivos executáveis que usam a biblioteca MFC. Aplicativos Win32 e o MFC podem chamar funções em sua DLL (padrão)|
  |**Usar MFC em uma biblioteca estática**|Links de um aplicativo para a biblioteca estática do MFC no momento da compilação.|

## <a name="see-also"></a>Consulte também

[Assistente de aplicativo do MFC](../../mfc/reference/mfc-application-wizard.md)<br/>
[Tipos de arquivo criados para projetos do Visual C++](../../ide/file-types-created-for-visual-cpp-projects.md)
