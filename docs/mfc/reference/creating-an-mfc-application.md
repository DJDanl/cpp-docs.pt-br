---
title: Criando um aplicativo MFC
ms.date: 07/28/2019
helpviewer_keywords:
- applications [MFC]
- MFC, creating applications
- MFC applications
ms.assetid: b8b8aa08-9c49-404c-8078-b42079ac18f0
ms.openlocfilehash: 454a994da6db2841317d41ea1cdacfd36b0705e4
ms.sourcegitcommit: 720b74dddb1cdf4e570d55103158304ee1df81f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/29/2019
ms.locfileid: "68606474"
---
# <a name="creating-an-mfc-application"></a>Criando um aplicativo MFC

Um aplicativo MFC é um aplicativo executável para Windows que se baseia na biblioteca do Microsoft Foundation Class (MFC). A maneira mais fácil de criar um aplicativo MFC é usar o assistente de aplicativo do MFC (**projeto de aplicativo do MFC** no Visual Studio 2019). Para criar um aplicativo de console do MFC, use o assistente de área de trabalho do Windows e escolha as opções **aplicativo de console** e **cabeçalhos MFC** .

> [!IMPORTANT]
>  Não há suporte para projetos MFC nas edições Visual Studio Express.

Os executáveis do MFC geralmente se enquadram em cinco tipos: aplicativos padrão do Windows, caixas de diálogo, aplicativos baseados em formulários, aplicativos de estilo de Gerenciador e aplicativos de estilo de navegador da Web. Para obter mais informações, consulte:

- [Usando as classes para escrever aplicativos do Windows](../../mfc/using-the-classes-to-write-applications-for-windows.md)

- [Criando e exibindo caixas de diálogo](../../mfc/creating-and-displaying-dialog-boxes.md)

- [Criando um aplicativo MFC com base em formulários](../../mfc/reference/creating-a-forms-based-mfc-application.md)

- [Criando um aplicativo MFC no estilo de Gerenciador de Arquivos](../../mfc/reference/creating-a-file-explorer-style-mfc-application.md)

- [Criando um aplicativo MFC no estilo de navegador da Web](../../mfc/reference/creating-a-web-browser-style-mfc-application.md)

O assistente de aplicativo do MFC gera as classes e os arquivos apropriados para qualquer um desses tipos de aplicativos, dependendo das opções que você selecionar no assistente.

### <a name="to-create-an-mfc-application-using-the-mfc-application-wizard"></a>Para criar um aplicativo MFC usando o assistente de aplicativo MFC

1. Siga as instruções no tópico da ajuda [criar um C++ projeto de aplicativo de console](../../get-started/tutorial-console-cpp.md).

1. Na caixa de diálogo **novo projeto** , selecione **aplicativo MFC** no painel modelos para abrir o assistente.

1. Defina as configurações do aplicativo usando o [Assistente de aplicativo do MFC](../../mfc/reference/mfc-application-wizard.md).

    > [!NOTE]
    >  Ignore esta etapa para manter as configurações padrão do assistente.

1. Clique em **Concluir** para fechar o assistente e abrir o novo projeto no ambiente de desenvolvimento.

Após a criação do seu projeto, será possível exibir os arquivos criados no **Gerenciador de Soluções**. Para saber mais sobre os arquivos que o assistente cria para seu projeto, veja o arquivo ReadMe.txt gerado pelo projeto. Para saber mais sobre os tipos de arquivo, confira [Tipos de arquivos criados para projetos do Visual Studio C++](../../build/reference/file-types-created-for-visual-cpp-projects.md).

## <a name="see-also"></a>Consulte também

[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Páginas de propriedade](../../build/reference/property-pages-visual-cpp.md)

