---
title: Criando um aplicativo MFC
ms.date: 08/28/2019
helpviewer_keywords:
- applications [MFC]
- MFC, creating applications
- MFC applications
ms.assetid: b8b8aa08-9c49-404c-8078-b42079ac18f0
ms.openlocfilehash: dd4a0b8a7a06debdc3556d48e000fe09deccf857
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92924433"
---
# <a name="creating-an-mfc-application"></a>Criando um aplicativo MFC

Um aplicativo MFC é um aplicativo executável para Windows que se baseia na biblioteca do Microsoft Foundation Class (MFC). Os executáveis do MFC geralmente se enquadram em cinco tipos: aplicativos padrão do Windows, caixas de diálogo, aplicativos baseados em formulários, aplicativos de estilo de Gerenciador e aplicativos de estilo de navegador da Web. Para obter mais informações, consulte:

- [Usando as classes para escrever aplicativos do Windows](../../mfc/using-the-classes-to-write-applications-for-windows.md)

- [Criando e exibindo caixas de diálogo](../../mfc/creating-and-displaying-dialog-boxes.md)

- [Criando um aplicativo Forms-Based MFC](../../mfc/reference/creating-a-forms-based-mfc-application.md)

- [Criando um arquivo Explorer-Style aplicativo MFC](../../mfc/reference/creating-a-file-explorer-style-mfc-application.md)

- [Criando um aplicativo Web Browser-Style MFC](../../mfc/reference/creating-a-web-browser-style-mfc-application.md)

O assistente de aplicativo do MFC gera as classes e os arquivos apropriados para qualquer um desses tipos de aplicativos, dependendo das opções que você selecionar no assistente.

A maneira mais fácil de criar um aplicativo MFC é usar o assistente de aplicativo do MFC ( **projeto de aplicativo do MFC** no Visual Studio 2019). Para criar um aplicativo de console do MFC (um programa de linha de comando que usa bibliotecas MFC, mas é executado na janela do console), use o assistente de área de trabalho do Windows e escolha as opções **aplicativo de console** e **cabeçalhos MFC** .

::: moniker range=">=msvc-160"

## <a name="to-create-an-mfc-forms-or-dialog-based-application"></a>Para criar um aplicativo baseado em caixa de diálogo ou formulários do MFC

1. No menu principal, escolha **arquivo** > **novo** > **projeto** .
1. Digite "MFC" na caixa de pesquisa e, em seguida, escolha **aplicativo MFC** na lista de resultados.
1. Modifique os padrões conforme necessário e, em seguida, pressione **criar** para abrir o **Assistente de aplicativo do MFC** .
1. Modifique os valores de configuração conforme necessário e pressione **concluir** .

Para obter mais informações, consulte [criando um aplicativo Forms-Based MFC](creating-a-forms-based-mfc-application.md).

![Captura de tela do assistente de aplicativo do MFC no Visual estúdios 2019.](media/mfc-app-wizard.png)

## <a name="to-create-an-mfc-console-application"></a>Para criar um aplicativo de console do MFC

Um aplicativo de console do MFC é um programa de linha de comando que usa bibliotecas MFC, mas é executado na janela do console.

1. No menu principal, escolha **arquivo** > **novo** > **projeto** .
1. Insira "área de trabalho" na caixa de pesquisa e, em seguida, escolha **Assistente de área de trabalho do Windows** na lista de resultados.
1. Modifique o nome do projeto conforme necessário e, em seguida, pressione **Avançar** para abrir o **Assistente de área de trabalho do Windows** .
1. Marque a caixa **cabeçalhos do MFC** e defina outros valores conforme necessário e pressione **concluir** .

![Captura de tela do assistente de área de trabalho do Windows no Visual estúdios 2019.](media/windows-desktop-wizard.png)

::: moniker-end

::: moniker range="=msvc-150"

## <a name="to-create-an-mfc-forms-or-dialog-based-application"></a>Para criar um aplicativo baseado em caixa de diálogo ou formulários do MFC

1. No menu principal, escolha **arquivo** > **novo** > **projeto** .
1. Nos modelos **instalados** , escolha **Visual C++**  >  **MFC/ATL** . Se você não vê-los, use o Instalador do Visual Studio para adicioná-los.
1. Escolha **aplicativo MFC** no painel central.
1. Modifique os valores de configuração conforme necessário e pressione **concluir** .

Para obter mais informações, consulte [criando um aplicativo Forms-Based MFC](creating-a-forms-based-mfc-application.md).

![Captura de tela do assistente de aplicativo do MFC no Visual estúdios 2017.](media/mfc-app-wizard.png)

## <a name="to-create-an-mfc-console-application"></a>Para criar um aplicativo de console do MFC

Um aplicativo de console do MFC é um programa de linha de comando que usa bibliotecas MFC, mas é executado na janela do console.

1. No menu principal, escolha **arquivo** > **novo** > **projeto** .
1. Nos modelos **instalados** , escolha **Visual C++** > **área de trabalho do Windows** .
1. Escolha **Assistente de área de trabalho do Windows** no painel central.
1. Modifique o nome do projeto conforme necessário e pressione **OK** para abrir o **Assistente de área de trabalho do Windows** .
1. Marque a caixa **cabeçalhos do MFC** e defina outros valores conforme necessário e pressione **concluir** .

![Captura de tela do assistente de área de trabalho do Windows no Visual estúdios 2017.](media/windows-desktop-wizard-2017.png)

::: moniker-end

::: moniker range="=msvc-140"

## <a name="to-create-an-mfc-forms-or-dialog-based-application"></a>Para criar um aplicativo baseado em caixa de diálogo ou formulários do MFC

1. No menu principal, escolha **arquivo** > **novo** > **projeto** .
1. Nos modelos **instalados** , escolha **Visual C++** > **MFC** .
1. Escolha **aplicativo MFC** no painel central.
1. Clique em **Avançar** para iniciar o **Assistente de aplicativo MFC** .

Para obter mais informações, consulte [criando um aplicativo Forms-Based MFC](creating-a-forms-based-mfc-application.md).

![Captura de tela do assistente de aplicativo do MFC no Visual estúdios 2015.](media/mfc-app-wizard-2015.png)

## <a name="to-create-an-mfc-console-application"></a>Para criar um aplicativo de console do MFC

Um aplicativo de console do MFC é um programa de linha de comando que usa bibliotecas MFC, mas é executado na janela do console.

1. No menu principal, escolha **arquivo** > **novo** > **projeto** .
1. Nos modelos **instalados** , escolha **Visual C++** > **Win32** .
1. Escolha **aplicativo de console Win32** no painel central.
1. Modifique o nome do projeto conforme necessário e pressione **OK** .
1. Na segunda página do assistente, marque a caixa **Adicionar cabeçalhos comuns para MFC** e defina outros valores conforme necessário e pressione **concluir** .

::: moniker-end

Após a criação do seu projeto, será possível exibir os arquivos criados no **Gerenciador de Soluções** . Para saber mais sobre os arquivos que o assistente cria para seu projeto, veja o arquivo ReadMe.txt gerado pelo projeto. Para saber mais sobre os tipos de arquivo, confira [Tipos de arquivos criados para projetos do Visual Studio C++](../../build/reference/file-types-created-for-visual-cpp-projects.md).

## <a name="see-also"></a>Veja também

[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Páginas de propriedade](../../build/reference/property-pages-visual-cpp.md)
