---
title: Assistente de aplicativo MFC
ms.date: 11/04/2016
f1_keywords:
- vc.appwiz.mfc.exe.overview
helpviewer_keywords:
- MFC Application Wizard
- executable files, creating
ms.assetid: 227ac090-921d-4b2f-be0a-66a5f4cab0d4
ms.openlocfilehash: 6949f136890e8274f225a49496b2eb1b8f78b6fc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81351830"
---
# <a name="mfc-application-wizard"></a>Assistente de aplicativo MFC

O MFC Application Wizard gera um aplicativo que, quando compilado, implementa os recursos básicos de um aplicativo executável do Windows (.exe). O aplicativo inicial do MFC inclui arquivos de fonte C++ (.cpp), arquivos de recurso (.rc), arquivos de cabeçalho (.h) e um arquivo project (.vcxproj). O código gerado nestes arquivos iniciais é baseado em MFC.

> [!NOTE]
> Dependendo das opções selecionadas, o assistente cria arquivos adicionais em seu projeto. Por exemplo, se você selecionar **ajuda sensível** ao contexto na página [Recursos Avançados,](../../mfc/reference/advanced-features-mfc-application-wizard.md) o assistente criará os arquivos necessários para compilar os arquivos de Ajuda do projeto. Para obter mais informações sobre os arquivos que o assistente cria, consulte [Tipos de arquivos criados para projetos Do Visual Studio C++](../../build/reference/file-types-created-for-visual-cpp-projects.md)e consulte o arquivo Readme.txt no projeto.

## <a name="overview"></a>Visão geral

Esta página do assistente descreve as configurações atuais do aplicativo para o aplicativo MFC que você está criando. Por padrão, o assistente cria um projeto da seguinte forma:

- [Tipo de aplicativo, Assistente de Aplicativo MFC](../../mfc/reference/application-type-mfc-application-wizard.md)

  - O projeto é criado com suporte a interface de vários documentos (MDI) com guias. Para obter mais informações, consulte [SDI e MDI](../../mfc/sdi-and-mdi.md).

  - O projeto usa a [arquitetura document/view](../../mfc/document-view-architecture.md).

  - O projeto usa bibliotecas Unicode.

  - O projeto é criado usando o estilo de projeto do Visual Studio e permite a comutação de estilo visual.

  - O projeto usa MFC em um DLL compartilhado. Para obter mais informações, consulte [Criar DLLs C/C++ no Visual Studio](../../build/dlls-in-visual-cpp.md).

- [Suporte a documento composto, Assistente de aplicativo MFC](../../mfc/reference/compound-document-support-mfc-application-wizard.md)

  - O projeto não oferece suporte para documentos compostos.

- [Cadeias de caracteres de modelo do documento, Assistente de aplicativo MFC](../../mfc/reference/document-template-strings-mfc-application-wizard.md)

  - O projeto usa o nome do projeto para as seqüências de modelo de documento padrão.

- [Suporte ao banco de dados, Assistente de aplicativo MFC](../../mfc/reference/database-support-mfc-application-wizard.md)

  - O projeto não oferece suporte para bancos de dados.

- [Recursos da interface do usuário, Assistente de aplicativo MFC](../../mfc/reference/user-interface-features-mfc-application-wizard.md)

  - O projeto implementa recursos padrão de interface do usuário do Windows, como um menu do sistema, uma barra de status, maximizar e minimizar caixas, uma caixa **Sobre,** uma barra de menu padrão e barra de ferramentas de encaixe e quadros de crianças.

- [Recursos avançados, Assistente de Aplicativo MFC](../../mfc/reference/advanced-features-mfc-application-wizard.md)

  - O projeto suporta impressão e visualização de impressão.

  - O projeto suporta controles ActiveX. Para obter mais informações, consulte [Seqüência de Operações para Criação de Controles ActiveX](../../mfc/sequence-of-operations-for-creating-activex-controls.md).

  - O projeto não oferece suporte para [automação,](../../mfc/automation.md) [MAPI,](../../mfc/mapi-support-in-mfc.md) [soquetes de windows](../../mfc/windows-sockets-in-mfc.md)ou acessibilidade ativa.

  - O projeto suporta um painel de encaixe **explorer,** um painel de encaixe **de saída** e um painel de acoplamento **Propriedades.**

- [Classes geradas, Assistente de Aplicativo MFC](../../mfc/reference/generated-classes-mfc-application-wizard.md)

  - A classe de visualização do projeto é derivada da [Classe CView](../../mfc/reference/cview-class.md).

  - A classe de aplicação do projeto é derivada da [Classe CWinAppEx](../../mfc/reference/cwinappex-class.md).

  - A classe de documentos do projeto é derivada da [Classe CDocument](../../mfc/reference/cdocument-class.md).

  - A classe de quadro principal do projeto é derivada da [classe CMDIFrameWndEx](../../mfc/reference/cmdiframewndex-class.md).

  - A classe de quadroinfantil do projeto é derivada da [classe CMDIChildWndEx](../../mfc/reference/cmdichildwndex-class.md).

Para alterar essas configurações padrão, clique no título da guia apropriada na coluna esquerda do assistente e faça as alterações na página que aparece.

Depois de criar um projeto de aplicativo MFC, você pode adicionar objetos ou controles ao seu projeto usando assistentes de código Visual [C++.](../../ide/adding-functionality-with-code-wizards-cpp.md)

## <a name="see-also"></a>Confira também

[Criando um aplicativo MFC](../../mfc/reference/creating-an-mfc-application.md)<br/>
[Aplicativos da área de trabalho MFC](../../mfc/mfc-desktop-applications.md)<br/>
[Usando as classes para escrever aplicativos para Windows](../../mfc/using-the-classes-to-write-applications-for-windows.md)
