---
title: Assistente de aplicativo MFC | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.appwiz.mfc.exe.overview
dev_langs:
- C++
helpviewer_keywords:
- MFC Application Wizard
- executable files, creating
ms.assetid: 227ac090-921d-4b2f-be0a-66a5f4cab0d4
caps.latest.revision: 14
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 2d1d950ac5adb5d17b172fa058a40593e4e61c34
ms.lasthandoff: 02/25/2017

---
# <a name="mfc-application-wizard"></a>Assistente de aplicativo MFC
O Assistente para aplicativo do MFC gera um aplicativo que, quando compilado, implementa os recursos básicos de um aplicativo executável (.exe) do Windows. O aplicativo do MFC starter inclui arquivos de origem (. cpp) de C++, arquivos de recurso (. rc), arquivos de cabeçalho (. h) e um arquivo de projeto (. vcxproj). O código gerado nesses arquivos inicial baseia-se no MFC.  
  
> [!NOTE]
>  Dependendo das opções que você selecionar, o assistente cria arquivos adicionais no seu projeto. Por exemplo, se você selecionar **ajuda contextual** sobre o [recursos avançados](../../mfc/reference/advanced-features-mfc-application-wizard.md) página, o assistente cria os arquivos necessários compilar os arquivos de Ajuda do projeto. Para obter mais informações sobre os arquivos que o assistente cria, consulte [tipos de arquivo criados para projetos do Visual C++](../../ide/file-types-created-for-visual-cpp-projects.md)e consulte o arquivo readme txt no projeto.  
  
## <a name="overview"></a>Visão Geral  
 Esta página do assistente descreve as configurações do aplicativo atual para o aplicativo do MFC que você está criando. Por padrão, o assistente cria um projeto da seguinte maneira:  
  
-   [Tipo de aplicativo, Assistente de aplicativo MFC](../../mfc/reference/application-type-mfc-application-wizard.md)  
  
    -   O projeto é criado com o suporte de interface com guias de documentos múltiplos (MDI). Para obter mais informações, consulte [SDI e MDI](../../mfc/sdi-and-mdi.md).  
  
    -   O projeto usa o [arquitetura de documento/exibição](../../mfc/document-view-architecture.md).  
  
    -   O projeto usa bibliotecas de Unicode.  
  
    -   O projeto é criado usando o estilo de projeto do Visual Studio e permite a alternância de estilo visual.  
  
    -   O projeto usa MFC em uma DLL compartilhada. Para obter mais informações, consulte [DLLs no Visual C++](../../build/dlls-in-visual-cpp.md).  
  
-   [Documento suporte composto, Assistente de aplicativo MFC](../../mfc/reference/compound-document-support-mfc-application-wizard.md)  
  
    -   O projeto não oferece suporte para documentos compostos.  
  
-   [Cadeias de caracteres de modelo de documento, Assistente de aplicativo MFC](../../mfc/reference/document-template-strings-mfc-application-wizard.md)  
  
    -   O projeto usa o nome do projeto para as cadeias de caracteres de modelo de documento padrão.  
  
-   [Suporte de banco de dados, o Assistente de aplicativo MFC](../../mfc/reference/database-support-mfc-application-wizard.md)  
  
    -   O projeto não oferece suporte para bancos de dados.  
  
-   [Recursos de Interface do usuário, Assistente de aplicativo MFC](../../mfc/reference/user-interface-features-mfc-application-wizard.md)  
  
    -   O projeto implementa recursos de interface do usuário como um menu de sistema, uma barra de status, maximizar e minimizar caixas, padrão do Windows uma **sobre** caixa, uma barra de menus padrão e ferramentas de encaixe e quadros filho.  
  
-   [Recursos avançados, Assistente de aplicativo MFC](../../mfc/reference/advanced-features-mfc-application-wizard.md)  
  
    -   O projeto oferece suporte a impressão e visualização de impressão.  
  
    -   O projeto oferece suporte a controles ActiveX. Para obter mais informações, consulte [sequência de operações para criar controles ActiveX](../../mfc/sequence-of-operations-for-creating-activex-controls.md).  
  
    -   O projeto não oferece suporte para [automação](../../mfc/automation.md), [MAPI](../../mfc/mapi-support-in-mfc.md), [Windows Sockets](../../mfc/windows-sockets-in-mfc.md), ou acessibilidade ativa.  
  
    -   O projeto oferece suporte a um **Explorer** painel de encaixe, uma **saída** painel de encaixe e um **propriedades** painel de encaixe.  
  
-   [Classes geradas, Assistente de aplicativo MFC](../../mfc/reference/generated-classes-mfc-application-wizard.md)  
  
    -   Classe de exibição do projeto é derivado de [classe CView](../../mfc/reference/cview-class.md).  
  
    -   Classe de aplicativo do projeto é derivado de [CWinAppEx classe](../../mfc/reference/cwinappex-class.md).  
  
    -   Classe de documento do projeto é derivado de [classe CDocument](../../mfc/reference/cdocument-class.md).  
  
    -   Classe de quadro principal do projeto é derivado de [CMDIFrameWndEx classe](../../mfc/reference/cmdiframewndex-class.md).  
  
    -   Classe de quadro filho do projeto é derivado de [CMDIChildWndEx classe](../../mfc/reference/cmdichildwndex-class.md).  
  
 Para alterar essas configurações padrão, clique no título da guia apropriada na coluna à esquerda do assistente e faça as alterações na página que é exibida.  
  
 Depois de criar um projeto de aplicativo do MFC, você pode adicionar objetos ou controles ao seu projeto usando o Visual C++ [assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md).  
  
## <a name="see-also"></a>Consulte também  
 [Criando um aplicativo MFC](../../mfc/reference/creating-an-mfc-application.md)   
 [Aplicativos de Desktop do MFC](../../mfc/mfc-desktop-applications.md)   
 [Usando as Classes para escrever aplicativos para Windows](../../mfc/using-the-classes-to-write-applications-for-windows.md)

