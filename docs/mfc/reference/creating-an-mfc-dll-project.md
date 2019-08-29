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
ms.openlocfilehash: 649a47abea23aedb9aa97bb4923e7a800348e27e
ms.sourcegitcommit: bf1940a39029dbbd861f95480f55e5e8bd25cda0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/28/2019
ms.locfileid: "70108474"
---
# <a name="creating-an-mfc-dll-project"></a>Criando um projeto DLL MFC

Uma DLL do MFC é um arquivo binário que atua como uma biblioteca compartilhada de funções que podem ser usadas simultaneamente por vários aplicativos. A maneira mais fácil de criar um projeto de DLL do MFC é usar o assistente de DLL do MFC.

> [!NOTE]
>  A aparência dos recursos no IDE pode depender de suas configurações ativas ou edição e pode diferir das descritas na ajuda. Para alterar as configurações, escolha **Importar e Exportar Configurações** no menu **Ferramentas**. Para obter mais informações, confira [Personalizar o IDE do Visual Studio](/visualstudio/ide/personalizing-the-visual-studio-ide).

### <a name="to-create-an-mfc-dll-project-using-the-mfc-dll-wizard"></a>Para criar um projeto de DLL do MFC usando o assistente de DLL do MFC

1. Siga as instruções no tópico da ajuda [criando um aplicativo MFC](creating-an-mfc-application.md) , mas escolha **biblioteca de vínculo dinâmico MFC** ou **dll MFC** na lista de modelos disponíveis.

1. Defina as configurações do aplicativo usando a página [configurações do aplicativo](../../mfc/reference/application-settings-mfc-dll-wizard.md) do assistente de [dll do MFC](../../mfc/reference/mfc-dll-wizard.md).

    > [!NOTE]
    >  Ignore esta etapa para manter as configurações padrão do assistente.

1. Clique em **concluir** para fechar o assistente e abrir o novo projeto no **Gerenciador de soluções**.

Após a criação do seu projeto, será possível exibir os arquivos criados no **Gerenciador de Soluções**. Para saber mais sobre os arquivos que o assistente cria para seu projeto, veja o arquivo ReadMe.txt gerado pelo projeto. Para saber mais sobre os tipos de arquivo, confira [Tipos de arquivos criados para projetos do Visual Studio C++](../../build/reference/file-types-created-for-visual-cpp-projects.md).

## <a name="see-also"></a>Consulte também

[Tipos de projeto do C++ no Visual Studio](/visualstudio/debugger/debugging-preparation-visual-cpp-project-types)<br/>
[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Páginas de propriedade](../../build/reference/property-pages-visual-cpp.md)

