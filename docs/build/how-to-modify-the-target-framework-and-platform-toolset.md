---
title: "Como modificar a estrutura de destino e o conjunto de ferramentas da plataforma | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "get-started-article"
f1_keywords: 
  - "msbuild.cpp.howto.modifytargetframeworkandplatformtoolset"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "msbuild (c++), como modificar a estrutura de destino e o conjunto de ferramentas da plataforma"
ms.assetid: 031b1d54-e6e1-4da7-9868-3e75a87d9ffe
caps.latest.revision: 32
caps.handback.revision: 32
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Como modificar a estrutura de destino e o conjunto de ferramentas da plataforma
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode alterar [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] configurações diferentes versões do .NET Framework de destino e usar conjuntos de ferramentas de plataforma diferente do projeto. Por padrão, o sistema de projeto usa a versão do .NET Framework e a versão do conjunto de ferramentas que correspondem à versão do Visual Studio que você pode usar para criar o projeto. Você pode alterar o conjunto de ferramentas de plataforma de destino modificando as propriedades do projeto. Você pode alterar a estrutura de destino modificando o arquivo de projeto \(. vcxproj\). Você não precisa manter um código separado para cada destino de compilação base.  
  
> [!IMPORTANT]
>  Algumas edições podem não suportar estruturas de destino ou conjuntos de ferramentas de plataforma. Para informações sobre compatibilidade, consulte [Portando, migrando e atualizando projetos do Visual Studio](../Topic/Porting,%20Migrating,%20and%20Upgrading%20Visual%20Studio%20Projects.md).  
  
 Quando você altera a estrutura de destino, também altere o conjunto de ferramentas de plataforma para uma versão que suporte essa estrutura. Por exemplo, para direcionar o .NET Framework 4.5, você deve usar um conjunto de ferramentas da plataforma compatível como o Visual Studio 2015 \(v140\), o Visual Studio 2013 \(v120\) ou o Visual Studio 2012 \(v110\). Você pode usar o **Windows 7.1 SDK** conjunto de ferramentas de plataforma como alvo o .NET Framework 2.0, 3.0, 3.5 e 4 e x86, Itanium e x64 plataformas.  
  
> [!NOTE]
>  Para alterar o conjunto de ferramentas de plataforma de destino, você deve ter a versão associada do Visual Studio ou o Windows Platform SDK instalada. Por exemplo, para direcionar a plataforma Itanium com o **Windows 7.1 SDK** conjunto de ferramentas de plataforma, você deve ter [Microsoft Windows SDK para Windows 7 e do .NET Framework 4 SP1](http://www.microsoft.com/download/details.aspx?id=8279) instalado; no entanto, você poderia usar outra versão compatível do Visual Studio para fazer o trabalho de desenvolvimento, desde que você toolset correto Framework versão e plataforma de destino.  
  
 Você pode estender a plataforma de destino, criando um conjunto de ferramentas personalizado da plataforma. Para obter mais informações, consulte [C\+\+ nativo multiplataforma](http://go.microsoft.com/fwlink/?LinkId=196619) no blog do Visual C\+\+.  
  
### Para alterar a estrutura de destino  
  
1.  No Visual Studio, em **Solution Explorer**, selecione seu projeto. Na barra de menus, abra o **projeto** menu e escolha **Descarregar projeto**. Isso descarrega o arquivo de projeto \(. vcxproj\) para o seu projeto.  
  
    > [!NOTE]
    >  Não é possível carregar um projeto C\+\+ enquanto o arquivo de projeto está sendo modificado no Visual Studio. No entanto, você pode usar outro editor, como o bloco de notas para modificar o arquivo de projeto enquanto o projeto é carregado no Visual Studio. O Visual Studio irá detectar que o arquivo de projeto foi alterado e solicitará que você recarregue o projeto.  
  
2.  Na barra de menus, selecione **arquivo**, **Abrir**, **arquivo**. No **Abrir arquivo** caixa de diálogo, navegue até a pasta do projeto e, em seguida, abra o arquivo de projeto \(. vcxproj\).  
  
3.  No arquivo de projeto, localize a entrada para a versão do Framework de destino. Por exemplo, se seu projeto foi projetado para usar o .NET Framework 4.5, localize `<TargetFrameworkVersion>v4.5</TargetFrameworkVersion>` no `<PropertyGroup Label="Globals">` elemento o `<Project>` elemento. Se o `<TargetFrameworkVersion>` elemento não estiver presente, seu projeto não usa o .NET Framework e nenhuma alteração é necessária.  
  
4.  Altere o valor para a versão do Framework desejado, como v 3.5 ou v 4.6.  
  
5.  Salve as alterações e feche o editor.  
  
6.  Em **Solution Explorer**, abra o menu de atalho para o seu projeto e escolha **Recarregar projeto**.  
  
7.  Para verificar a alteração, em **Solution Explorer**, com o botão direito para abrir o menu de atalho para o seu projeto \(não para a solução\) e, em seguida, escolha **propriedades** para abrir seu projeto **páginas de propriedade** caixa de diálogo. No painel esquerdo da caixa de diálogo, expanda **Propriedades de configuração** e, em seguida, selecione **geral**. Verifique **versão de destino do .NET Framework** mostra a nova versão do Framework.  
  
### Para alterar o conjunto de ferramentas do projeto  
  
1.  No Visual Studio, em **Solution Explorer**, abra o menu de atalho para o seu projeto \(não para a solução\) e, em seguida, escolha **propriedades** para abrir seu projeto **páginas de propriedade** caixa de diálogo.  
  
2.  No **páginas de propriedade** caixa de diálogo, abra o **configuração** lista suspensa e selecione **todas as configurações de**.  
  
3.  No painel esquerdo da caixa de diálogo, expanda **Propriedades de configuração** e, em seguida, selecione **geral**.  
  
4.  No painel direito, selecione **conjunto de ferramentas de plataforma** e, em seguida, selecione o conjunto de ferramentas que você deseja na lista suspensa. Por exemplo, se você tiver instalado o [!INCLUDE[vs_dev10_long](../build/includes/vs_dev10_long_md.md)] conjunto de ferramentas, selecione **Visual Studio 2010 \(v100\)** usá\-la para seu projeto.  
  
5.  Escolha o botão **OK**.  
  
## Consulte também  
 [MSBuild \(Visual C\+\+\)](../Topic/MSBuild%20\(Visual%20C++\).md)