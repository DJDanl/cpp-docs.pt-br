---
title: "Como adicionar ferramentas de compila&#231;&#227;o personalizadas a projetos MSBuild | Microsoft Docs"
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
  - "msbuild.cpp.howto.addcustombuildtools"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "msbuild (c++), como adicionar ferramentas de compilação personalizada"
ms.assetid: de03899a-371d-4396-9bf9-34f45a65e909
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Como adicionar ferramentas de compila&#231;&#227;o personalizadas a projetos MSBuild
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma ferramenta de criação personalizado é uma definido pelo usuário, a ferramenta de linha de comando que é associada a um arquivo específico.  
  
 Para um arquivo específico, especifique no arquivo de projeto \(\) .vcxproj a linha de comando para executar, qualquer entrada ou arquivos de saída adicionais, e uma mensagem a ser exibida.  Se **MSBuild** determina que os arquivos de saída são expirado em relação aos arquivos de entrada, exibe a mensagem e executar a ferramenta de linha de comando.  
  
 Para especificar quando a ferramenta de criação personalizado é executado, use um ou ambos os elementos XML de `CustomBuildBeforeTargets` e de `CustomBuildAfterTargets` no arquivo de projeto.  Por exemplo, você pode especificar que a ferramenta de criação personalizado seja executado após o compilador de MIDL e antes do compilador C\/C\+\+.  Especifica o elemento de `CustomBuildBeforeTargets` para executar a ferramenta antes que um destino específico seja executado; o elemento de `CustomBuildAfterTargets` para executar a ferramenta depois de um determinado destino; ou ambos os elementos para executar a ferramenta entre uma execução de dois destinos.  Se nenhum elemento é especificado, a ferramenta de criação personalizado é executado no local padrão, que está antes que o destino de **MIDL** .  
  
 As etapas personalizadas da construção e as ferramentas personalizadas de compilação compartilham as informações especificadas em elementos XML de `CustomBuildBeforeTargets` e de `CustomBuildAfterTargets` .  Especifique os destinos uma vez no seu arquivo de projeto.  
  
### Para adicionar uma ferramenta de criação personalizado  
  
1.  Adicione um grupo do item para o arquivo de projeto e adicionar um item para cada arquivo de entrada.  Especifique o comando adicionais, as entradas, as saídas, e uma mensagem como metadados de item, conforme mostrado aqui.  Este exemplo supõe que um arquivo de faq.txt “” já existe no mesmo diretório do projeto.  
  
    ```  
    <ItemGroup>  
      <CustomBuild Include="faq.txt">  
        <Message>Copying readme...</Message>  
        <Command>copy %(Identity) $(OutDir)%(Identity)</Command>  
        <Outputs>$(OutDir)%(Identity)</Outputs>  
      </CustomBuild>  
    </ItemGroup>  
    ```  
  
### Para definir onde na construção as ferramentas personalizadas de compilação executarão  
  
1.  Adicione o seguinte grupo de propriedades para o arquivo de projeto.  Você deve especificar pelo menos um dos destinos, mas você pode omitir o outro se você estiver interessado apenas em que a etapa de compilação é executado antes ou após \(\) de destino específico.  Este exemplo executa a etapa personalizado após a compilação mas antes de vincular\-se.  
  
    ```  
    <PropertyGroup>  
      <CustomBuildAfterTargets>ClCompile</CustomBuildAfterTargets>  
      <CustomBuildBeforeTargets>Link</CustomBuildBeforeTargets>  
    </PropertyGroup>  
    ```  
  
## Consulte também  
 [Instruções passo a passo: usando MSBuild para criar um projeto do Visual C\+\+](../build/walkthrough-using-msbuild-to-create-a-visual-cpp-project.md)   
 [Como usar eventos de compilação em projetos de MSBuild](../build/how-to-use-build-events-in-msbuild-projects.md)   
 [Como adicionar uma etapa de build personalizada a projetos MSBuild](../Topic/How%20to:%20Add%20a%20Custom%20Build%20Step%20to%20MSBuild%20Projects.md)