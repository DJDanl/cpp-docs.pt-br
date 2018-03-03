---
title: "Como: adicionar uma etapa de compilação personalizada a projetos MSBuild | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- msbuild.cpp.howto.addcustombuildstep
dev_langs:
- C++
helpviewer_keywords:
- 'msbuild (c++), howto: add a custom build step'
ms.assetid: a20a0c47-4df4-4754-a1f0-a94a99958916
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d664b9fad6a9ec67dc009a90171119036dc13cde
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-add-a-custom-build-step-to-msbuild-projects"></a>Como adicionar uma etapa de build personalizada a projetos MSBuild
Uma etapa de compilação personalizada é uma etapa definido pelo usuário em uma compilação. Uma etapa de compilação personalizada se comporta como qualquer outro *ferramenta de comando* etapa, como a etapa de ferramenta de compilação ou link padrão.  
  
 Especifique uma etapa de compilação personalizada no arquivo de projeto (. vcxproj). A etapa pode especificar uma linha de comando a ser executado, nenhuma entrada adicional ou arquivos de saída e uma mensagem a ser exibida. Se **MSBuild** determina que os arquivos de saída estão desatualizados em relação a seus arquivos de entrada, ele exibe a mensagem e executa o comando.  
  
 Para especificar o local de compilação personalizada etapa na sequência de destinos de compilação, use um ou ambos os `CustomBuildAfterTargets` e `CustomBuildBeforeTargets` elementos XML no arquivo de projeto. Por exemplo, você pode especificar que a etapa de compilação personalizada é executado após o destino de link de ferramenta e antes do destino da ferramenta de manifesto. O conjunto real de destinos disponíveis depende de sua compilação específica.  
  
 Especifique o `CustomBuildBeforeTargets` elemento para executar a etapa de compilação personalizada para um destino específico é executado, o `CustomBuildAfterTargets` elemento para executar a etapa após a execução de um destino específico, ou ambos os elementos para executar a etapa entre dois destinos adjacentes. Se nenhum elemento for especificado, a ferramenta de compilação personalizada executa no local padrão, após o **Link** destino.  
  
 Etapas de compilação personalizada e as ferramentas de compilação personalizada compartilham as informações especificadas no `CustomBuildBeforeTargets` e `CustomBuildAfterTargets` elementos XML. Portanto, especifica os destinos apenas uma vez no arquivo de projeto.  
  
### <a name="to-define-what-is-executed-by-the-custom-build-step"></a>Para definir o que é executado pela etapa de compilação personalizada  
  
1.  Adicione um grupo de propriedades para o arquivo de projeto. Nesse grupo de propriedade, especifique o comando, suas entradas e saídas e uma mensagem, conforme mostrado no exemplo a seguir. Este exemplo cria um arquivo. cab do arquivo main.cpp criado na [passo a passo: usando MSBuild para criar um projeto Visual C++](../build/walkthrough-using-msbuild-to-create-a-visual-cpp-project.md).  
  
    ```  
    <ItemDefinitionGroup>  
      <CustomBuildStep>  
        <Command>makecab.exe $(ProjectDir)main.cpp $(TargetName).cab</Command>  
        <Outputs>$(TargetName).cab</Outputs>  
        <Inputs>$(TargetFileName)</Inputs>  
      </CustomBuildStep>  
    </ItemDefinitionGroup>  
    ```  
  
### <a name="to-define-where-in-the-build-the-custom-build-step-will-execute"></a>Para definir onde na compilação de etapa de compilação personalizada será executado  
  
1.  Adicione o seguinte grupo de propriedade para o arquivo de projeto. Você pode especificar ambos os destinos, ou você pode omitir um se você quiser apenas a etapa personalizada a ser executada antes ou depois de um destino específico. Este exemplo informa **MSBuild** para executar a etapa personalizada após a etapa de compilação, mas antes da etapa de link.  
  
    ```  
    <PropertyGroup>  
      <CustomBuildAfterTargets>ClCompile</CustomBuildAfterTargets>  
      <CustomBuildBeforeTargets>Link</CustomBuildBeforeTargets>  
    </PropertyGroup>  
    ```  
  
## <a name="see-also"></a>Consulte também  
 [Passo a passo: Usando MSBuild para criar um projeto do Visual C++](../build/walkthrough-using-msbuild-to-create-a-visual-cpp-project.md)   
 [Como: usar eventos de Build em projetos de MSBuild](../build/how-to-use-build-events-in-msbuild-projects.md)   
 [Como adicionar ferramentas de build personalizadas a projetos MSBuild](../build/how-to-add-custom-build-tools-to-msbuild-projects.md)