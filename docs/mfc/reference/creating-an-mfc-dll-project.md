---
title: Criando um projeto DLL MFC
ms.date: 08/19/2019
f1_keywords:
- vc.appwiz.mfcdll.project
helpviewer_keywords:
- MFC DLLs [MFC], creating projects
- DLLs [MFC], MFC
- projects [MFC], creating
- DLLs [MFC], creating
ms.assetid: 05540b93-4781-4a90-aadf-55158313f5b2
ms.openlocfilehash: 6367b2a4b85b2c586c5a4420a8be1f80d334b2e4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81363957"
---
# <a name="creating-an-mfc-dll-project"></a>Criando um projeto DLL MFC

Um MFC DLL é um arquivo binário que atua como uma biblioteca compartilhada de funções que podem ser usadas simultaneamente por vários aplicativos. A maneira mais fácil de criar um projeto MFC DLL é usar o MFC DLL Wizard.

> [!NOTE]
> O aparecimento de recursos no IDE pode depender de suas configurações ativas ou edição, e pode diferir daqueles descritos em Ajuda. Para alterar suas configurações, selecione **Importar e Exportar Configurações** no menu **Ferramentas** . Para obter mais informações, consulte [Personalizar o Visual Studio IDE](/visualstudio/ide/personalizing-the-visual-studio-ide).

### <a name="to-create-an-mfc-dll-project-using-the-mfc-dll-wizard"></a>Para criar um Projeto DLL MFC usando o Assistente DLL Do MFC

1. Siga as instruções no tópico ajuda [Criar um aplicativo MFC,](creating-an-mfc-application.md) mas escolha **a Biblioteca de Link Dinâmico MFC** ou o **DLL MFC** na lista de modelos disponíveis.

1. Defina as configurações do aplicativo usando a página [de configurações](../../mfc/reference/application-settings-mfc-dll-wizard.md) do [MFC DLL Wizard](../../mfc/reference/mfc-dll-wizard.md).

    > [!NOTE]
    >  Ignore esta etapa para manter as configurações padrão do assistente.

1. Clique **em Concluir** para fechar o assistente e abrir seu novo projeto no Solution **Explorer**.

Após a criação do seu projeto, será possível exibir os arquivos criados no **Gerenciador de Soluções**. Para saber mais sobre os arquivos que o assistente cria para seu projeto, veja o arquivo ReadMe.txt gerado pelo projeto. Para saber mais sobre os tipos de arquivo, confira [Tipos de arquivos criados para projetos do Visual Studio C++](../../build/reference/file-types-created-for-visual-cpp-projects.md).

## <a name="see-also"></a>Confira também

[Tipos de projeto do C++ no Visual Studio](/visualstudio/debugger/debugging-preparation-visual-cpp-project-types)<br/>
[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Páginas de propriedades](../../build/reference/property-pages-visual-cpp.md)
