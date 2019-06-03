---
title: 'Como: Modificar a estrutura de destino e o conjunto de ferramentas de plataforma'
ms.custom: conceptual
ms.date: 05/06/2019
helpviewer_keywords:
- 'msbuild (c++), howto: modify target framework and platform toolset'
ms.assetid: 031b1d54-e6e1-4da7-9868-3e75a87d9ffe
ms.openlocfilehash: b2cf5ac5c6a339917b87a25001be568a7caa2247
ms.sourcegitcommit: 28eae422049ac3381c6b1206664455dbb56cbfb6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/31/2019
ms.locfileid: "66450742"
---
# <a name="how-to-modify-the-target-framework-and-platform-toolset"></a>Como: Modificar a estrutura de destino e o conjunto de ferramentas de plataforma

Você pode alterar o Visual Studio C++ configurações para diferentes versões do .NET Framework de destino e usar conjuntos de ferramentas de plataforma diferente do projeto. Por padrão, o sistema do projeto usa a versão do .NET Framework e do conjunto de ferramentas que corresponde à versão do Visual Studio usada para criar o projeto. É possível alterar o conjunto de ferramentas da plataforma de destino modificando as propriedades do projeto. É possível alterar a Estrutura de destino modificando o arquivo do projeto (.vcxproj). Não é preciso manter uma base de código separada para cada destino de compilação.

> [!IMPORTANT]
>  Algumas edições podem não ter suporte a Estruturas de destino ou conjuntos de ferramentas da plataforma modificados. Para obter informações de compatibilidade, consulte [portar, migrar e atualizar projetos do Visual Studio](/visualstudio/porting/port-migrate-and-upgrade-visual-studio-projects).

Ao alterar a Estrutura de destino, altere também o conjunto de ferramentas da plataforma para uma versão que suporte essa Estrutura. Por exemplo, para direcionar o .NET Framework 4.5, você deve usar um conjunto de ferramentas da plataforma compatível como o Visual Studio 2015 (v140), o Visual Studio 2013 (v120) ou o Visual Studio 2012 (v110). Você pode usar o **Windows7.1SDK** conjunto de ferramentas de plataforma para direcionar o .NET Framework 2.0, 3.0, 3.5 e 4 e x86, Itanium e x64 plataformas.

> [!NOTE]
>  Para alterar o conjunto de ferramentas da plataforma de destino, é preciso ter a versão associada do Visual Studio ou do Windows Platform SDK instalada. Por exemplo, para a plataforma Itanium com o **Windows7.1SDK** conjunto de ferramentas de plataforma, você deve ter [Microsoft Windows SDK para Windows 7 e .NET Framework 4 SP1](https://www.microsoft.com/download/details.aspx?id=8279) instalados; no entanto, você pode usar outra versão compatível do Visual Studio para fazer o trabalho de desenvolvimento, desde que você o correto ferramentas de plataforma e versão do Framework de destino.

É possível estender a plataforma de destino ainda mais criando um conjunto de ferramentas personalizado da plataforma. Para obter mais informações, consulte [C++ multiplataforma nativa](https://blogs.msdn.microsoft.com/vcblog/2009/12/08/c-native-multi-targeting/) no blog do Visual C++.

### <a name="to-change-the-target-framework"></a>Para alterar a Estrutura de destino

1. No Visual Studio, no **Gerenciador de soluções**, selecione seu projeto. Na barra de menus, abra o **Project** menu e escolha **descarregar projeto**. Isso descarrega o arquivo do projeto (.vcxproj) para seu projeto.

    > [!NOTE]
    >  Um projeto C++ não pode ser carregado enquanto o arquivo do projeto estiver sendo modificado no Visual Studio. No entanto, é possível usar outro editor como o Bloco de Notas para modificar o arquivo do projeto enquanto o projeto é carregado no Visual Studio. O Visual Studio detectará que o arquivo do projeto foi modificado e solicitará que o projeto seja recarregado.

1. Na barra de menus, selecione **arquivo**, **abra**, **arquivo**. No **abrir arquivo** caixa de diálogo, navegue até a pasta do projeto e, em seguida, abra o arquivo de projeto (. vcxproj).

1. No arquivo do projeto, localize a entrada para a versão da Estrutura de destino. Por exemplo, se o projeto estiver designado para o .NET Framework 4.5, localize `<TargetFrameworkVersion>v4.5</TargetFrameworkVersion>` no elemento `<PropertyGroup Label="Globals">` do elemento `<Project>`. Se o elemento `<TargetFrameworkVersion>` não estiver presente, seu projeto não usa o .NET Framework e nenhuma modificação é necessária.

1. Altere o valor para a versão do Framework que você deseja, como v3.5 ou v 4.6.

1. Salve as alterações e feche o editor.

1. Na **Gerenciador de soluções**, abra o menu de atalho para o seu projeto e, em seguida, escolha **recarregar projeto**.

1. Para verificar a alteração, na **Gerenciador de soluções**, clique com botão direito para abrir o menu de atalho para o seu projeto (não para sua solução) e, em seguida, escolha **propriedades** para abrir seu projeto **propriedade Páginas** caixa de diálogo. No painel esquerdo da caixa de diálogo, expanda **propriedades de configuração** e, em seguida, selecione **geral**. Verifique **versão de destino do .NET Framework** mostra a nova versão do Framework.

### <a name="to-change-the-project-toolset"></a>Para alterar o conjunto de ferramentas do projeto

1. No Visual Studio, no **Gerenciador de soluções**, abra o menu de atalho para o seu projeto (não para sua solução) e, em seguida, escolha **Properties** para abrir seu projeto **páginas de propriedades**caixa de diálogo.

1. No **páginas de propriedades** caixa de diálogo, abra o **Configuration** lista suspensa e selecione **todas as configurações de**.

1. No painel esquerdo da caixa de diálogo, expanda **propriedades de configuração** e, em seguida, selecione **geral**.

1. No painel direito, selecione **conjunto de ferramentas de plataforma** e, em seguida, selecione o conjunto de ferramentas que você deseja na lista suspensa. Por exemplo, se você tiver instalado o conjunto de ferramentas do Visual Studio 2010, selecione **Visual Studio 2010 (v100)** usá-lo para seu projeto.

1. Escolha o botão **OK**.

## <a name="see-also"></a>Consulte também

[MSBuild na linha de comando – C++](msbuild-visual-cpp.md)
