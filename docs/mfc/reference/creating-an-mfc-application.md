---
title: Criando um aplicativo MFC
ms.date: 08/28/2019
helpviewer_keywords:
- applications [MFC]
- MFC, creating applications
- MFC applications
ms.assetid: b8b8aa08-9c49-404c-8078-b42079ac18f0
ms.openlocfilehash: 16dbbc4a3b2e8927643d3612bec034f9f5da8d9c
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80077525"
---
# <a name="creating-an-mfc-application"></a>Criando um aplicativo MFC

Um aplicativo MFC é um aplicativo executável para Windows que se baseia na biblioteca do Microsoft Foundation Class (MFC). Os executáveis do MFC geralmente se enquadram em cinco tipos: aplicativos padrão do Windows, caixas de diálogo, aplicativos baseados em formulários, aplicativos de estilo de Gerenciador e aplicativos de estilo de navegador da Web. Para obter mais informações, consulte:

- [Usando as classes para escrever aplicativos do Windows](../../mfc/using-the-classes-to-write-applications-for-windows.md)

- [Criando e exibindo caixas de diálogo](../../mfc/creating-and-displaying-dialog-boxes.md)

- [Criando um aplicativo MFC com base em formulários](../../mfc/reference/creating-a-forms-based-mfc-application.md)

- [Criando um aplicativo MFC no estilo de Gerenciador de Arquivos](../../mfc/reference/creating-a-file-explorer-style-mfc-application.md)

- [Criando um aplicativo MFC no estilo de navegador da Web](../../mfc/reference/creating-a-web-browser-style-mfc-application.md)

O assistente de aplicativo do MFC gera as classes e os arquivos apropriados para qualquer um desses tipos de aplicativos, dependendo das opções que você selecionar no assistente.

A maneira mais fácil de criar um aplicativo MFC é usar o assistente de aplicativo do MFC (**projeto de aplicativo do MFC** no Visual Studio 2019). Para criar um aplicativo de console do MFC (um programa de linha de comando que usa bibliotecas MFC, mas é executado na janela do console), use o assistente de área de trabalho do Windows e escolha as opções **aplicativo de console** e **cabeçalhos MFC** .

::: moniker range=">=vs-2019"

## <a name="to-create-an-mfc-forms-or-dialog-based-application"></a>Para criar um aplicativo baseado em caixa de diálogo ou formulários do MFC

1. No menu principal, escolha **arquivo** > **novo** **projeto**de >.
1. Digite "MFC" na caixa de pesquisa e, em seguida, escolha **aplicativo MFC** na lista de resultados.
1. Modifique os padrões conforme necessário e, em seguida, pressione **criar** para abrir o **Assistente de aplicativo do MFC**.
1. Modifique os valores de configuração conforme necessário e pressione **concluir**.

Para obter mais informações, consulte [criando um aplicativo MFC baseado em formulários](creating-a-forms-based-mfc-application.md).

![Assistente de aplicativo MFC](media/mfc-app-wizard.png)

## <a name="to-create-an-mfc-console-application"></a>Para criar um aplicativo de console do MFC

Um aplicativo de console do MFC é um programa de linha de comando que usa bibliotecas MFC, mas é executado na janela do console.

1. No menu principal, escolha **arquivo** > **novo** **projeto**de >.
1. Insira "área de trabalho" na caixa de pesquisa e, em seguida, escolha **Assistente de área de trabalho do Windows** na lista de resultados.
1. Modifique o nome do projeto conforme necessário e, em seguida, pressione **Avançar** para abrir o **Assistente de área de trabalho do Windows**.
1. Marque a caixa **cabeçalhos do MFC** e defina outros valores conforme necessário e pressione **concluir**.

![Assistente de aplicativo MFC](media/windows-desktop-wizard.png)

::: moniker-end

::: moniker range="=vs-2017"

## <a name="to-create-an-mfc-forms-or-dialog-based-application"></a>Para criar um aplicativo baseado em caixa de diálogo ou formulários do MFC

1. No menu principal, escolha **arquivo** > **novo** **projeto**de >.
1. Nos modelos **instalados** , escolha **Visual C++**  > **MFC/ATL**. Se você não vê-los, use o Instalador do Visual Studio para adicioná-los.
1. Escolha **aplicativo MFC** no painel central.
1. Modifique os valores de configuração conforme necessário e pressione **concluir**.

Para obter mais informações, consulte [criando um aplicativo MFC baseado em formulários](creating-a-forms-based-mfc-application.md).

![Assistente de aplicativo MFC](media/mfc-app-wizard.png)

## <a name="to-create-an-mfc-console-application"></a>Para criar um aplicativo de console do MFC

Um aplicativo de console do MFC é um programa de linha de comando que usa bibliotecas MFC, mas é executado na janela do console.

1. No menu principal, escolha **arquivo** > **novo** **projeto**de >.
1. Nos modelos **instalados** , escolha **Visual C++**  > **área de trabalho do Windows**.
1. Escolha **Assistente de área de trabalho do Windows** no painel central.
1. Modifique o nome do projeto conforme necessário e pressione **OK** para abrir o **Assistente de área de trabalho do Windows**.
1. Marque a caixa **cabeçalhos do MFC** e defina outros valores conforme necessário e pressione **concluir**.

![Assistente de aplicativo MFC](media/windows-desktop-wizard-2017.png)

::: moniker-end

::: moniker range="=vs-2015"

## <a name="to-create-an-mfc-forms-or-dialog-based-application"></a>Para criar um aplicativo baseado em caixa de diálogo ou formulários do MFC

1. No menu principal, escolha **arquivo** > **novo** **projeto**de >.
1. Nos modelos **instalados** , escolha **Visual C++**  > **MFC**.
1. Escolha **aplicativo MFC** no painel central.
1. Clique em **Avançar** para iniciar o **Assistente de aplicativo MFC**.

Para obter mais informações, consulte [criando um aplicativo MFC baseado em formulários](creating-a-forms-based-mfc-application.md).

![Assistente de aplicativo MFC](media/mfc-app-wizard-2015.png)

## <a name="to-create-an-mfc-console-application"></a>Para criar um aplicativo de console do MFC

Um aplicativo de console do MFC é um programa de linha de comando que usa bibliotecas MFC, mas é executado na janela do console.

1. No menu principal, escolha **arquivo** > **novo** **projeto**de >.
1. Nos modelos **instalados** , escolha **Visual C++**  > **Win32**.
1. Escolha **aplicativo de console Win32** no painel central.
1. Modifique o nome do projeto conforme necessário e pressione **OK**.
1. Na segunda página do assistente, marque a caixa **Adicionar cabeçalhos comuns para MFC** e defina outros valores conforme necessário e pressione **concluir**.

::: moniker-end

Após a criação do seu projeto, será possível exibir os arquivos criados no **Gerenciador de Soluções**. Para saber mais sobre os arquivos que o assistente cria para seu projeto, veja o arquivo ReadMe.txt gerado pelo projeto. Para saber mais sobre os tipos de arquivo, confira [Tipos de arquivos criados para projetos do Visual Studio C++](../../build/reference/file-types-created-for-visual-cpp-projects.md).

## <a name="see-also"></a>Confira também

[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Páginas de propriedade](../../build/reference/property-pages-visual-cpp.md)