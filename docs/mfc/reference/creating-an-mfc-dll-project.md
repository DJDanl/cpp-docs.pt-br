---
title: Criando um projeto DLL MFC
ms.date: 11/04/2016
f1_keywords:
- vc.appwiz.mfcdll.project
helpviewer_keywords:
- MFC DLLs [MFC], creating projects
- DLLs [MFC], MFC
- projects [MFC], creating
- DLLs [MFC], creating
ms.assetid: 05540b93-4781-4a90-aadf-55158313f5b2
ms.openlocfilehash: 44671985b2ab22e866a63b284a4b22d87b614667
ms.sourcegitcommit: 7d64c5f226f925642a25e07498567df8bebb00d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2019
ms.locfileid: "65446742"
---
# <a name="creating-an-mfc-dll-project"></a>Criando um projeto DLL MFC

Uma DLL MFC é um arquivo binário que atua como uma biblioteca compartilhada de funções que podem ser usados simultaneamente por vários aplicativos. A maneira mais fácil para criar um projeto de DLL do MFC é usar o Assistente de DLL do MFC.

> [!NOTE]
>  A aparência dos recursos no IDE pode depender de suas configurações ativas ou edição e pode diferir dos descritos na Ajuda. Para alterar as configurações, escolha **Importar e Exportar Configurações** no menu **Ferramentas**. Para obter mais informações, confira [Personalizar o IDE do Visual Studio](/visualstudio/ide/personalizing-the-visual-studio-ide).

### <a name="to-create-an-mfc-dll-project-using-the-mfc-dll-wizard"></a>Para criar um projeto de DLL do MFC usando o Assistente de DLL do MFC

1. Siga as instruções no tópico da Ajuda [criar um projeto de aplicativo de console C++](../../get-started/tutorial-console-cpp.md).

**Observação** no **novo projeto** caixa de diálogo, selecione o `MFC DLL` ícone no painel de modelos para abrir o Assistente de DLL do MFC.

1. Definir as configurações do aplicativo usando o [configurações do aplicativo](../../mfc/reference/application-settings-mfc-dll-wizard.md) página do [Assistente de DLL MFC](../../mfc/reference/mfc-dll-wizard.md).

    > [!NOTE]
    >  Ignore esta etapa para manter o Assistente de configurações padrão.

1. Clique em **terminar** para fechar o assistente e abrir seu novo projeto no **Gerenciador de soluções**.

Depois que o projeto é criado, você pode exibir os arquivos criados na **Gerenciador de soluções**. Para obter mais informações sobre os arquivos que o assistente cria para seu projeto, consulte o arquivo gerado pelo projeto Readme. txt. Para obter mais informações sobre os tipos de arquivo, consulte [tipos de arquivo criados para o Visual C++ projetos](../../build/reference/file-types-created-for-visual-cpp-projects.md).

## <a name="see-also"></a>Consulte também

[C++tipos de projeto no Visual Studio](/visualstudio/debugger/debugging-preparation-visual-cpp-project-types)<br/>
[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Páginas de propriedade](../../build/reference/property-pages-visual-cpp.md)

