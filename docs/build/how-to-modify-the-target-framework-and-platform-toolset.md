---
title: 'Como: modificar a estrutura de destino e o conjunto de ferramentas da plataforma | Microsoft Docs'
ms.custom: conceptual
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
f1_keywords:
- msbuild.cpp.howto.modifytargetframeworkandplatformtoolset
dev_langs:
- C++
helpviewer_keywords:
- 'msbuild (c++), howto: modify target framework and platform toolset'
ms.assetid: 031b1d54-e6e1-4da7-9868-3e75a87d9ffe
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: eef4c0e7e32b85e26fbdc6adb7a2ebd26850b2ae
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43691729"
---
# <a name="how-to-modify-the-target-framework-and-platform-toolset"></a>Como modificar a estrutura de destino e o conjunto de ferramentas da plataforma
Você pode alterar as configurações de projeto do Visual C++ para ter diferentes versões do .NET Framework e usar conjuntos de ferramentas de plataforma diferente. Por padrão, o sistema do projeto usa a versão do .NET Framework e do conjunto de ferramentas que corresponde à versão do Visual Studio usada para criar o projeto. É possível alterar o conjunto de ferramentas da plataforma de destino modificando as propriedades do projeto. É possível alterar a Estrutura de destino modificando o arquivo do projeto (.vcxproj). Não é preciso manter uma base de código separada para cada destino de compilação.  
  
> [!IMPORTANT]
>  Algumas edições podem não ter suporte a Estruturas de destino ou conjuntos de ferramentas da plataforma modificados. Para obter informações de compatibilidade, consulte [portar, migrar e atualizar projetos do Visual Studio](/visualstudio/porting/port-migrate-and-upgrade-visual-studio-projects).  
  
 Ao alterar a Estrutura de destino, altere também o conjunto de ferramentas da plataforma para uma versão que suporte essa Estrutura. Por exemplo, para direcionar o .NET Framework 4.5, você deve usar um conjunto de ferramentas da plataforma compatível como o Visual Studio 2015 (v140), o Visual Studio 2013 (v120) ou o Visual Studio 2012 (v110). Você pode usar o **Windows7.1SDK** conjunto de ferramentas de plataforma para direcionar o .NET Framework 2.0, 3.0, 3.5 e 4 e x86, Itanium e x64 plataformas.  
  
> [!NOTE]
>  Para alterar o conjunto de ferramentas da plataforma de destino, é preciso ter a versão associada do Visual Studio ou do Windows Platform SDK instalada. Por exemplo, para a plataforma Itanium com o **Windows7.1SDK** conjunto de ferramentas de plataforma, você deve ter [Microsoft Windows SDK para Windows 7 e .NET Framework 4 SP1](http://www.microsoft.com/download/details.aspx?id=8279) instalados; no entanto, você pode usar outra versão compatível do Visual Studio para fazer o trabalho de desenvolvimento, desde que você o correto ferramentas de plataforma e versão do Framework de destino.  
  
 É possível estender a plataforma de destino ainda mais criando um conjunto de ferramentas personalizado da plataforma. Para obter mais informações, consulte [C++ multiplataforma nativa](https://blogs.msdn.microsoft.com/vcblog/2009/12/08/c-native-multi-targeting/) no blog do Visual C++.  
  
### <a name="to-change-the-target-framework"></a>Para alterar a Estrutura de destino  
  
1.  No Visual Studio, no **Gerenciador de soluções**, selecione seu projeto. Na barra de menus, abra o **Project** menu e escolha **descarregar projeto**. Isso descarrega o arquivo do projeto (.vcxproj) para seu projeto.  
  
    > [!NOTE]
    >  Um projeto C++ não pode ser carregado enquanto o arquivo do projeto estiver sendo modificado no Visual Studio. No entanto, é possível usar outro editor como o Bloco de Notas para modificar o arquivo do projeto enquanto o projeto é carregado no Visual Studio. O Visual Studio detectará que o arquivo do projeto foi modificado e solicitará que o projeto seja recarregado.  
  
2.  Na barra de menus, selecione **arquivo**, **abra**, **arquivo**. No **abrir arquivo** caixa de diálogo, navegue até a pasta do projeto e, em seguida, abra o arquivo de projeto (. vcxproj).  
  
3.  No arquivo do projeto, localize a entrada para a versão da Estrutura de destino. Por exemplo, se o projeto estiver designado para o .NET Framework 4.5, localize `<TargetFrameworkVersion>v4.5</TargetFrameworkVersion>` no elemento `<PropertyGroup Label="Globals">` do elemento `<Project>`. Se o elemento `<TargetFrameworkVersion>` não estiver presente, seu projeto não usa o .NET Framework e nenhuma modificação é necessária.  
  
4.  Altere o valor para a versão do Framework que você deseja, como v3.5 ou v 4.6.  
  
5.  Salve as alterações e feche o editor.  
  
6.  Na **Gerenciador de soluções**, abra o menu de atalho para o seu projeto e, em seguida, escolha **recarregar projeto**.  
  
7.  Para verificar a alteração, na **Gerenciador de soluções**, clique com botão direito para abrir o menu de atalho para o seu projeto (não para sua solução) e, em seguida, escolha **propriedades** para abrir seu projeto **propriedade Páginas** caixa de diálogo. No painel esquerdo da caixa de diálogo, expanda **propriedades de configuração** e, em seguida, selecione **geral**. Verifique **versão de destino do .NET Framework** mostra a nova versão do Framework.  
  
### <a name="to-change-the-project-toolset"></a>Para alterar o conjunto de ferramentas do projeto  
  
1.  No Visual Studio, no **Gerenciador de soluções**, abra o menu de atalho para o seu projeto (não para sua solução) e, em seguida, escolha **Properties** para abrir seu projeto **páginas de propriedades**caixa de diálogo.  
  
2.  No **páginas de propriedades** caixa de diálogo, abra o **Configuration** lista suspensa e selecione **todas as configurações de**.  
  
3.  No painel esquerdo da caixa de diálogo, expanda **propriedades de configuração** e, em seguida, selecione **geral**.  
  
4.  No painel direito, selecione **conjunto de ferramentas de plataforma** e, em seguida, selecione o conjunto de ferramentas que você deseja na lista suspensa. Por exemplo, se você tiver instalado o conjunto de ferramentas do Visual Studio 2010, selecione **Visual Studio 2010 (v100)** usá-lo para seu projeto.  
  
5.  Escolha o botão **OK**.  
  
## <a name="see-also"></a>Consulte também  
 [MSBuild (Visual C++)](../build/msbuild-visual-cpp.md)