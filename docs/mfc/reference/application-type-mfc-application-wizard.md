---
title: Tipo de aplicativo, Assistente de aplicativo MFC | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.appwiz.mfc.exe.apptype
dev_langs: C++
helpviewer_keywords: static libraries, MFC
ms.assetid: c3f62b0e-3f13-42c5-9859-d3890d0c3e1d
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 45253eed40e9a79dbcb372f63cc44aaeb99edbe0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="application-type-mfc-application-wizard"></a>Tipo de aplicativo, Assistente de Aplicativo MFC
Use esta página do [Assistente de aplicativo MFC](../../mfc/reference/mfc-application-wizard.md) para criar e adicionar recursos básicos para um novo aplicativo do MFC.  
  
 **Tipo de aplicativo**  
 Especifica o tipo de suporte de documento que você deseja criar em seu aplicativo. O tipo de aplicativo que você seleciona determina as opções de interface de usuário que estão disponíveis para seu aplicativo. Consulte [recursos de Interface do usuário, o Assistente de aplicativo MFC](../../mfc/reference/user-interface-features-mfc-application-wizard.md) para obter mais informações.  
  
 Para obter mais informações sobre os tipos de documentos, consulte:  
  
-   [SDI e MDI](../../mfc/sdi-and-mdi.md)  
  
-   [Janelas com moldura](../../mfc/frame-windows.md)  
  
-   [Classes de janela com moldura](../../mfc/frame-window-classes.md)  
  
-   [Documentos, exibições e o Framework](../../mfc/documents-views-and-the-framework.md)  
  
-   [Caixas de diálogo](../../mfc/dialog-boxes.md)  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Único documento**|Cria uma arquitetura de interface (SDI) único documento para seu aplicativo, onde uma classe de exibição é baseada em [classe CView](../../mfc/reference/cview-class.md). Você pode alterar a classe base para o modo de exibição de [Classes geradas, Assistente de aplicativo MFC](../../mfc/reference/generated-classes-mfc-application-wizard.md) página do assistente. Para criar um aplicativo baseado em formulário, por exemplo, use [CFormView classe](../../mfc/reference/cformview-class.md) para a classe de exibição.<br /><br /> Esse tipo de aplicativo, a janela do quadro do documento pode conter apenas um documento.|  
|**Vários documentos**|Cria uma arquitetura de interface MDI vários documentos para seu aplicativo, onde uma classe de exibição é baseada em `CView`. Você pode alterar a classe base para o modo de exibição de **Classes geradas pelo** página do assistente. Para criar um aplicativo baseado em formulário, por exemplo, use `CFormView` para a classe de exibição.<br /><br /> Nesse tipo de aplicativo, a janela do quadro do documento pode conter vários filhos windows.|  
|**Documentos com guias**|Coloca cada documento em uma guia separada.|  
|**Caixa de diálogo com base**|Cria uma arquitetura de caixa de diálogo para o seu aplicativo onde uma classe de caixa de diálogo é baseada em `CDialog`. (Para criar uma caixa de diálogo HTML, marque a caixa de **caixa de diálogo HTML Use**.)|  
|**Use a caixa de diálogo HTML**|Caixa de diálogo caixa apenas para aplicativos. Derive a classe de caixa de diálogo de [CDHtmlDialog classe](../../mfc/reference/cdhtmldialog-class.md) em vez de [classe CDialog](../../mfc/reference/cdialog-class.md). Se você marcar esta caixa, `CDHtmlDialog` está listado no **classe Base** caixa o [Classes geradas, Assistente de aplicativo MFC](../../mfc/reference/generated-classes-mfc-application-wizard.md) página do assistente.<br /><br /> Um `CDHtmlDialog`-caixa de diálogo derivada exibe caixas de diálogo baseado em HTML, controlam de dados de trocas com HTML e trata os eventos HTML.|  
|**Vários documentos de nível superior**|Cria uma arquitetura de nível superior vários para seu aplicativo, onde uma classe de exibição é baseada em `CView`.<br /><br /> Nesse tipo de aplicativo, quando um usuário clica **novo** (ou **novo quadro**) sobre o **arquivo** menu, o aplicativo cria uma janela cujo pai é implicitamente a área de trabalho. O novo quadro do documento aparece na barra de tarefas e não está restrita a área da janela do aplicativo cliente.|  
  
 **Suporte para a arquitetura de documento/exibição**  
 Especifica se a arquitetura de documento/exibição em seu aplicativo usando o [classe CDocument](../../mfc/reference/cdocument-class.md) e [classe CView](../../mfc/reference/cview-class.md) (padrão). Desmarque essa caixa de seleção se você estiver portando um aplicativo não MFC ou se desejar reduzir o tamanho de seu executável compilado. Por padrão, um aplicativo sem a arquitetura de documento/exibição é derivado de [classe CWinApp](../../mfc/reference/cwinapp-class.md), e não tem suporte do MFC para abrir um documento de um arquivo de disco.  
  
 **Idioma de recurso**  
 Define o idioma de seus recursos. A lista exibe os idiomas disponíveis no sistema, como instalado pelo Visual Studio. Se você quiser selecionar um idioma diferente do idioma do sistema, a pasta de modelo apropriado para o idioma já deve estar instalada. Para obter mais informações sobre como instalar recursos de idioma diferentes dos padrões disponíveis no **idioma de recurso** lista, consulte [suporte do Assistente para outros idiomas](../../ide/wizard-support-for-other-languages.md).  
  
 O idioma que você selecionar será refletido no **localizado cadeias de caracteres** opção do [cadeias de caracteres de modelo de documento, Assistente de aplicativo MFC](../../mfc/reference/document-template-strings-mfc-application-wizard.md) página do assistente.  
  
 **Usar bibliotecas de Unicode**  
 Especifica se a versão Unicode ou não-Unicode das bibliotecas MFC é usada.  
  
 **Estilo de projeto**  
 Indica se o aplicativo tem um padrão MFC, Explorador de arquivos, o Visual Studio, ou arquitetura do Office e exibição. Para obter mais informações, consulte [criando um aplicativo MFC no estilo do Explorer arquivo](../../mfc/reference/creating-a-file-explorer-style-mfc-application.md).  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Padrão MFC**|Fornece uma arquitetura de aplicativo do MFC padrão.|  
|**Explorador de arquivos**|Implementa um arquivo de aplicativo do Explorer como usando uma janela separadora onde o painel esquerdo é uma [classe CTreeView](../../mfc/reference/ctreeview-class.md) e o painel direito é um [classe CListView](../../mfc/reference/clistview-class.md).|  
|**Visual Studio**|Implementa um aplicativo do Visual Studio como que contém quatro painéis encaixável (**arquivo exibir**, **exibição de classe**, **propriedades**, e **saída**) que são derivados de [CDockablePane classe](../../mfc/reference/cdockablepane-class.md) e uma janela do quadro principal que é derivada de [CMDIFrameWndEx classe](../../mfc/reference/cmdiframewndex-class.md) (padrão).|  
|**Office**|Implementa um aplicativo semelhante que contém uma faixa de opções que é derivada de [classe CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md), uma barra do Outlook que é derivada de [CMFCOutlookBar classe](../../mfc/reference/cmfcoutlookbar-class.md), uma barra de legenda é derivada de [CMFCCaptionBar classe](../../mfc/reference/cmfccaptionbar-class.md)e um quadro principal que é derivado de [CMDIFrameWndEx classe](../../mfc/reference/cmdiframewndex-class.md).|  
  
 **Cores e o estilo visual**  
 Determina o estilo visual do aplicativo. As seguintes opções estão disponíveis:  
  
-   **Windows nativo/padrão**  
  
-   **Office 2003**  
  
-   **Visual Studio 2005**  
  
-   **Office 2007 (tema azul)**  
  
-   **Office 2007 (tema preto)**  
  
-   **Office 2007 (tema cinza)**  
  
-   **Office 2007 (tema azul-piscina)**  
  
 **Habilitar a alternância do estilo visual**  
 Especifica se o usuário pode alterar o estilo visual do aplicativo em tempo de execução, geralmente, selecionando o estilo visual apropriado de um menu ou uma faixa de opções.  
  
 **Uso de MFC**  
 Especifica como links para a biblioteca do MFC. Por padrão, o MFC é vinculado como uma DLL compartilhada.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Usar MFC em uma DLL compartilhada**|Vincula a biblioteca do MFC para um aplicativo como uma DLL compartilhada. O aplicativo faz chamadas para a biblioteca do MFC em tempo de execução. Essa opção reduz os requisitos de disco e memória de aplicativos que consistem em vários arquivos executáveis que usam a biblioteca do MFC. Aplicativos Win32 e MFC podem chamar funções em sua DLL (padrão)|  
|**Usar MFC em uma biblioteca estática**|Links de um aplicativo para a biblioteca estática do MFC em tempo de compilação.|  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de aplicativo MFC](../../mfc/reference/mfc-application-wizard.md)   
 [Tipos de arquivo criados para projetos do Visual C++](../../ide/file-types-created-for-visual-cpp-projects.md)

