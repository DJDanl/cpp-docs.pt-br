---
title: 'Como: adicionar ferramentas de compilação personalizadas a projetos MSBuild | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
f1_keywords:
- msbuild.cpp.howto.addcustombuildtools
dev_langs:
- C++
helpviewer_keywords:
- 'msbuild (c++), howto: add custom build tools'
ms.assetid: de03899a-371d-4396-9bf9-34f45a65e909
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3793e4223d00f219cc4f1d7b09e67453901bd6d1
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="how-to-add-custom-build-tools-to-msbuild-projects"></a>Como adicionar ferramentas de build personalizadas a projetos MSBuild
Uma ferramenta de compilação personalizada é uma ferramenta de linha de comando, definido pelo usuário que está associada um arquivo específico.  
  
 Para um arquivo específico, especifique o arquivo de projeto (. vcxproj) da linha de comando para executar, qualquer entrada adicional ou arquivos de saída, e uma mensagem para exibir. Se **MSBuild** determina que os arquivos de saída estão desatualizados em relação a seus arquivos de entrada, ele exibe a mensagem e executa a ferramenta de linha de comando.  
  
 Para especificar quando executa a ferramenta de compilação personalizada, use um ou ambos os `CustomBuildBeforeTargets` e `CustomBuildAfterTargets` elementos XML no arquivo de projeto. Por exemplo, você pode especificar que a ferramenta de compilação personalizada executar depois do compilador MIDL e antes do compilador do C/C++. Especifique o `CustomBuildBeforeTargets` elemento para executar a ferramenta antes de um destino específico é executado; o `CustomBuildAfterTargets` elemento para executar a ferramenta depois de um destino específico; ou os dois elementos para executar a ferramenta entre a execução de dois destinos. Se nenhum elemento for especificado, a ferramenta de compilação personalizada executa no local padrão, que é anterior a **MIDL** destino.  
  
 Etapas de compilação personalizada e as ferramentas de compilação personalizada compartilham as informações especificadas no `CustomBuildBeforeTargets` e `CustomBuildAfterTargets` elementos XML. Especifique os destinos de uma vez no arquivo de projeto.  
  
### <a name="to-add-a-custom-build-tool"></a>Para adicionar uma ferramenta de compilação personalizada  
  
1.  Adicionar um grupo de itens para o arquivo de projeto e adicionar um item para cada arquivo de entrada. Especifique o comando, adicionais entradas, saídas e uma mensagem como metadados de item, como mostrado aqui. Este exemplo presume que existe um arquivo de "faq.txt" no mesmo diretório do seu projeto.  
  
    ```  
    <ItemGroup>  
      <CustomBuild Include="faq.txt">  
        <Message>Copying readme...</Message>  
        <Command>copy %(Identity) $(OutDir)%(Identity)</Command>  
        <Outputs>$(OutDir)%(Identity)</Outputs>  
      </CustomBuild>  
    </ItemGroup>  
    ```  
  
### <a name="to-define-where-in-the-build-the-custom-build-tools-will-execute"></a>Para definir onde no build as ferramentas de compilação personalizada serão executado  
  
1.  Adicione o seguinte grupo de propriedade para o arquivo de projeto. Você deve especificar pelo menos um dos destinos, mas você pode omitir o outro se você só está interessado em ter a etapa de compilação executar antes (ou depois) um destino específico. Este exemplo executa a etapa personalizada após a compilação, mas antes de vincular.  
  
    ```  
    <PropertyGroup>  
      <CustomBuildAfterTargets>ClCompile</CustomBuildAfterTargets>  
      <CustomBuildBeforeTargets>Link</CustomBuildBeforeTargets>  
    </PropertyGroup>  
    ```  
  
## <a name="see-also"></a>Consulte também  
 [Passo a passo: Usando MSBuild para criar um projeto do Visual C++](../build/walkthrough-using-msbuild-to-create-a-visual-cpp-project.md)   
 [Como: usar eventos de Build em projetos de MSBuild](../build/how-to-use-build-events-in-msbuild-projects.md)   
 [Como adicionar uma etapa de build personalizada a projetos MSBuild](../build/how-to-add-a-custom-build-step-to-msbuild-projects.md)