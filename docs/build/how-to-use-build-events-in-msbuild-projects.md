---
title: "Como usar eventos de compila&#231;&#227;o em projetos de MSBuild | Microsoft Docs"
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
  - "msbuild.cpp.howto.usebuildevents"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "msbuild (c++), como usar eventos de compilação em projetos"
ms.assetid: 2a58dc9d-3d50-4e49-97c1-86c5a05ce218
caps.latest.revision: 23
caps.handback.revision: 23
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Como usar eventos de compila&#231;&#227;o em projetos de MSBuild
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um evento de compilação é um comando que [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] é executado em uma fase específica no processo de criação.  O evento *da construção* ocorre antes que a construção; o evento *de pré link* ocorre antes do início da etapa de link; e o evento *de pós\-compilação* ocorre após o término da compilação bem\-sucedida.  Um evento de construção só ocorrerá se a etapa associado de compilação ocorre.  Por exemplo, o evento do vínculo não ocorre se a etapa de vínculo não é executado.  
  
 Cada um dos três eventos de compilação é representado em um grupo de definição de item por um elemento command \(`<Command>`\) que é executada e um elemento message \(`<Message>`\) que é exibido quando **MSBuild** executará o evento de compilação.  Cada elemento é opcional, e se você especificar o mesmo elemento várias vezes, a última ocorrência terá precedência.  
  
 Um elemento opcional *de uso\-em\- construção* \(`<`*build\-event***UseInBuild**`>`\) pode ser especificado em um grupo de propriedades para indicar se o evento de compilação é executado.  O valor do conteúdo de um elemento *de uso\-em\- construção* é `true` ou `false`.  Por padrão, um evento de compilação é executado a menos que o elemento correspondente *uso\-em\- de construção* seja definido como `false`.  
  
 A tabela a seguir lista cada elemento XML do evento de construção:  
  
|Elemento XML|Descrição|  
|------------------|---------------|  
|`PreBuildEvent`|Esse evento é executado antes que a construção iniciar.|  
|`PreLinkEvent`|Esse evento é executado antes que a etapa de link iniciar.|  
|`PostBuildEvent`|Esse evento é executada após a compilação é concluída.|  
  
 A tabela a seguir lista cada elemento *de uso\-em\- construção* :  
  
|Elemento XML|Descrição|  
|------------------|---------------|  
|`PreBuildEventUseInBuild`|Especifica se executar o evento *da compilação* .|  
|`PreLinkEventUseInBuild`|Especifica se executar o evento *do link* .|  
|`PostBuildEventUseInBuild`|Especifica se executar o evento *pós\-compilação*.|  
  
## Exemplo  
 O exemplo a seguir pode ser adicionada dentro do elemento do projeto do arquivo de myproject.vcxproj criado em [Instruções passo a passo: usando MSBuild para criar um projeto do Visual C\+\+](../build/walkthrough-using-msbuild-to-create-a-visual-cpp-project.md).  Um evento *da construção* faz uma cópia de main.cpp; *um evento* do link faz uma cópia de main.obj; e *um evento* de pós\-compilação faz uma cópia de myproject.exe.  Se o projeto é criado usando uma configuração de versão, os eventos de compilação é executado.  Se o projeto é criado usando uma configuração de depuração, os eventos da construção não serão executados.  
  
```  
<ItemDefinitionGroup>  
  <PreBuildEvent>  
    <Command>copy $(ProjectDir)main.cpp $(ProjectDir)copyOfMain.cpp</Command>  
    <Message>Making a copy of main.cpp </Message>  
  </PreBuildEvent>  
  <PreLinkEvent>  
 <Command>copy $(ProjectDir)$(Configuration)\main.obj $(ProjectDir)$(Configuration)\copyOfMain.obj</Command>  
    <Message>Making a copy of main.obj</Message>  
  </PreLinkEvent>  
  <PostBuildEvent>  
 <Command>copy $(ProjectDir)$(Configuration)\$(TargetFileName) $(ProjectDir)$(Configuration)\copyOfMyproject.exe</Command>  
    <Message>Making a copy of myproject.exe</Message>  
  </PostBuildEvent>  
</ItemDefinitionGroup>  
  
<PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">  
  <PreBuildEventUseInBuild>true</PreBuildEventUseInBuild>  
  <PreLinkEventUseInBuild>true</PreLinkEventUseInBuild>  
  <PostBuildEventUseInBuild>true</PostBuildEventUseInBuild>  
</PropertyGroup>  
  
<PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">  
  <PreBuildEventUseInBuild>false</PreBuildEventUseInBuild>  
  <PreLinkEventUseInBuild>false</PreLinkEventUseInBuild>  
  <PostBuildEventUseInBuild>false</PostBuildEventUseInBuild>  
</PropertyGroup>  
```  
  
## Consulte também  
 [MSBuild \(Visual C\+\+\)](../Topic/MSBuild%20\(Visual%20C++\).md)   
 [Instruções passo a passo: usando MSBuild para criar um projeto do Visual C\+\+](../build/walkthrough-using-msbuild-to-create-a-visual-cpp-project.md)