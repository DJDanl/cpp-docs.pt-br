---
title: "P&#225;gina de propriedade dos diret&#243;rios do VC++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "VC.Project.VCDirectories.IncludePath"
  - "VC.Project.VCDirectories.ReferencePath"
  - "VC.Project.VCDirectories.SourcePath"
  - "VC.Project.VCDirectories.LibraryWPath"
  - "VC.Project.VCDirectories.ExecutablePath"
  - "VC.Project.VCDirectories.LibraryPath"
  - "VS.ToolsOptionsPages.Projects.VCDirectories"
  - "VC.Project.VCDirectories.ExcludePath"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Página de propriedade dos diretórios do VC++"
ms.assetid: 428eeef6-f127-4271-b3ea-0ae6f2c3d624
caps.latest.revision: 25
caps.handback.revision: 25
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# P&#225;gina de propriedade dos diret&#243;rios do VC++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica os diretórios que você deseja que o Visual Studio use para compilar um projeto.  Para acessar essa página de propriedades, no **Gerenciador de Soluções**, abra o menu de atalho do projeto e escolha **Propriedades**e, no painel esquerdo da caixa de diálogo **Páginas de Propriedades**, expanda **Propriedades de Configuração** e selecione **Diretórios VC\+\+**.  
  
 Quando você usa o Visual Studio para criar um projeto, ele herda determinados diretórios.  Vários deles são fornecidos como macros.  Para examinar o valor atual de uma macro, no painel direito da página **Diretórios VC\+\+**, selecione uma linha – por exemplo, **Diretórios de Inclusão** – selecione o botão de seta para baixo à direita, escolha **Editar** e, na caixa de diálogo que aparecer, escolha o botão **Macros**.  Para obter mais informações, leia estes posts do blog: [VC\+\+ Directories](http://blogs.msdn.com/b/vsproject/archive/2009/07/07/vc-directories.aspx), [Inherited Properties and Property Sheets](http://blogs.msdn.com/b/vsproject/archive/2009/06/23/inherited-properties-and-property-sheets.aspx), e [Visual Studio 2010 C\+\+ Project Upgrade Guide](http://blogs.msdn.com/b/vcblog/archive/2010/03/02/visual-studio-2010-c-project-upgrade-guide.aspx).  
  
## Tipos de diretório  
 Você também pode especificar outros diretórios, como a seguir.  
  
 **Diretórios Executáveis**  
 Diretórios onde procurar por arquivos executáveis.  Corresponde à variável de ambiente **PATH**.  
  
 **Diretórios de Inclusão**  
 Diretórios nos quais procurar por arquivos de inclusão que são referenciados no código\-fonte.  Corresponde à variável de ambiente **INCLUDE**.  
  
 **Diretórios de Referência**  
 Diretórios onde procurar por arquivos de assembly e de módulo \(metadados\) que são referenciados no código\-fonte pela diretiva [\#using](../preprocessor/hash-using-directive-cpp.md).  Corresponde à variável de ambiente **LIBPATH**.  
  
 **Diretórios de Biblioteca**  
 Diretórios onde procurar por arquivos de bibliotecas \(.lib\); isso inclui as bibliotecas em tempo de execução.  Corresponde à variável de ambiente **LIB**.  Essa configuração não se aplica a arquivos .obj; para vincular a um arquivo .obj, na página de propriedades [Vinculador](../ide/linker-property-pages.md) **Geral**, selecione **Dependências de Bibliotecas Adicionais** e especifique o caminho relativo do arquivo.  
  
 **Diretórios de Origem**  
 Diretórios onde procurar por arquivos de origem para uso para o IntelliSense.  
  
 **Diretórios de Exclusão**  
 Diretórios onde não procurar ao verificar dependências de compilação.  
  
#### Para especificar ou modificar as configurações de diretório  
  
1.  No **Gerenciador de Soluções**, abra o menu de atalho do projeto que você deseja alterar e, em seguida, selecione **Propriedades**.  
  
2.  No painel esquerdo da caixa de diálogo **Páginas de Propriedades**, expanda **Propriedades de Configuração** e selecione **Diretórios VC\+\+**.  
  
3.  Para modificar uma das listas de diretórios, selecione\-a, escolha o botão de seta para baixo à direita e selecione **Editar**.  
  
     Na caixa de diálogo que aparece, você pode adicionar ou remover valores, e pode reorganizar a ordem em que os valores são exibidos.  Você também pode alterar se o projeto herda qualquer configuração selecionando ou desmarcando **Herdar do pai ou padrões de projeto**.  
  
## Compartilhando as configurações  
 Você pode compartilhar propriedades do projeto com outros usuários ou em vários computadores.  Para obter mais informações, consulte [Trabalhando com propriedades do projeto](../ide/working-with-project-properties.md).  
  
## Consulte também  
 [Trabalhando com propriedades do projeto](../ide/working-with-project-properties.md)