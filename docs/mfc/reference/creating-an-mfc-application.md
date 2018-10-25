---
title: Criando um aplicativo MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- applications [MFC]
- MFC, creating applications
- MFC applications
ms.assetid: b8b8aa08-9c49-404c-8078-b42079ac18f0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ec61db21b27ef49f660751605b4788599f7f3485
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50062490"
---
# <a name="creating-an-mfc-application"></a>Criando um aplicativo MFC

Um aplicativo MFC é um aplicativo executável do Windows que se baseia na biblioteca Microsoft Foundation Class (MFC). A maneira mais fácil de criar um aplicativo MFC é usar o Assistente de aplicativo do MFC.

> [!IMPORTANT]
>  Projetos MFC não têm suporte nas edições Express do Visual Studio.

Executáveis MFC geralmente se encaixam em cinco tipos: aplicativos do Windows padrão, caixas de diálogo, aplicativos baseados em formulários, aplicativos de estilo do Explorer e aplicativos de estilo de navegador da Web. Para obter mais informações, consulte:

- [Usando as Classes para escrever aplicativos do Windows](../../mfc/using-the-classes-to-write-applications-for-windows.md)

- [Criando e exibindo caixas de diálogo](../../mfc/creating-and-displaying-dialog-boxes.md)

- [Criando um aplicativo MFC com base em formulários](../../mfc/reference/creating-a-forms-based-mfc-application.md)

- [Criando um aplicativo MFC no estilo de Gerenciador de Arquivos](../../mfc/reference/creating-a-file-explorer-style-mfc-application.md)

- [Criando um aplicativo MFC no estilo de navegador da Web](../../mfc/reference/creating-a-web-browser-style-mfc-application.md)

O Assistente de aplicativo do MFC gera as classes apropriadas e os arquivos para qualquer um desses tipos de aplicativos, dependendo das opções selecionadas no assistente.

### <a name="to-create-an-mfc-application-using-the-mfc-application-wizard"></a>Para criar um aplicativo do MFC usando o Assistente de aplicativo do MFC

1. Siga as instruções do tópico da Ajuda [Criando um projeto com um assistente de aplicativo do Visual C++](../../ide/creating-desktop-projects-by-using-application-wizards.md).

1. No **novo projeto** caixa de diálogo, selecione **aplicativo MFC** no painel de modelos para abrir o assistente.

1. Definir as configurações do aplicativo usando o [Assistente de aplicativo MFC](../../mfc/reference/mfc-application-wizard.md).

    > [!NOTE]
    >  Ignore esta etapa para manter o Assistente de configurações padrão.

1. Clique em **concluir** para fechar o assistente e abrir o novo projeto no ambiente de desenvolvimento.

Depois que o projeto é criado, você pode exibir os arquivos criados na **Gerenciador de soluções**. Para obter mais informações sobre os arquivos que o assistente cria para seu projeto, consulte o arquivo gerado pelo projeto Readme. txt. Para obter mais informações sobre os tipos de arquivo, consulte [tipos de arquivo criados para projetos do Visual C++](../../ide/file-types-created-for-visual-cpp-projects.md).

## <a name="see-also"></a>Consulte também

[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Páginas de propriedade](../../ide/property-pages-visual-cpp.md)

