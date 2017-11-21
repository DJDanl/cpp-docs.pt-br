---
title: 'Como: usar eventos de Build em projetos de MSBuild | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: msbuild.cpp.howto.usebuildevents
dev_langs: C++
helpviewer_keywords: 'msbuild (c++), howto: use build events in projects'
ms.assetid: 2a58dc9d-3d50-4e49-97c1-86c5a05ce218
caps.latest.revision: "23"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: ebbccf147cc45ce5e3dab512e13a8b059f104cdd
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="how-to-use-build-events-in-msbuild-projects"></a>Como usar eventos de build em projetos de MSBuild
Um evento de compilação é um comando que [!INCLUDE[vstecmsbuild](../build/includes/vstecmsbuild_md.md)] executa em uma fase específica no processo de compilação. O *pré-compilação* evento ocorre antes do início da compilação; o *pré-vínculo* evento ocorre antes do início da etapa link; e o *pós-compilação* evento ocorre após a compilação termina com êxito. Um evento de compilação ocorre somente se a etapa de compilação associado ocorre. Por exemplo, o evento de pré-vínculo não ocorre se a etapa de link não é executado.  
  
 Cada um dos eventos de três build é representada por um elemento de comando em um grupo de definição de item (`<Command>`) que é executado e um elemento de mensagem (`<Message>`) que é exibido quando **MSBuild** executa o evento de compilação. Cada elemento é opcional e, se você especificar o mesmo elemento várias vezes, a última ocorrência terá precedência.  
  
 Um recurso opcional *uso na compilação* elemento (`<`*evento de compilação***UseInBuild**`>`) pode ser especificado em um grupo de propriedades para indicar se a evento de compilação é executado. O valor do conteúdo de um *uso na compilação* elemento seja `true` ou `false`. Por padrão, um evento de compilação é executado, a menos que seu correspondente *uso na compilação* é definido como `false`.  
  
 A tabela a seguir lista cada elemento XML do evento de compilação:  
  
|Elemento XML|Descrição|  
|-----------------|-----------------|  
|`PreBuildEvent`|Esse evento é executado antes de inicia a compilação.|  
|`PreLinkEvent`|Esse evento é executado antes de começa a etapa de link.|  
|`PostBuildEvent`|Esse evento é executado após a conclusão da compilação.|  
  
 A tabela a seguir lista cada *uso na compilação* elemento:  
  
|Elemento XML|Descrição|  
|-----------------|-----------------|  
|`PreBuildEventUseInBuild`|Especifica se deve executar o *pré-compilação* eventos.|  
|`PreLinkEventUseInBuild`|Especifica se deve executar o *pré-vínculo* eventos.|  
|`PostBuildEventUseInBuild`|Especifica se deve executar o *pós-compilação* eventos.|  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir pode ser adicionado dentro do elemento de projeto do arquivo myproject.vcxproj criado em [passo a passo: usando MSBuild para criar um projeto Visual C++](../build/walkthrough-using-msbuild-to-create-a-visual-cpp-project.md). Um *pré-compilação* evento faz uma cópia de main.cpp; um *pré-vínculo* evento faz uma cópia do main.obj; e uma *pós-compilação* evento faz uma cópia do myproject.exe. Se o projeto é criado usando uma configuração de versão, os eventos de compilação são executados. Se o projeto é criado usando uma configuração de depuração, os eventos de compilação não são executados.  
  
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
  
## <a name="see-also"></a>Consulte também  
 [MSBuild (Visual C++)](../build/msbuild-visual-cpp.md)   
 [Instruções passo a passo: usando MSBuild para criar um projeto do Visual C++](../build/walkthrough-using-msbuild-to-create-a-visual-cpp-project.md)