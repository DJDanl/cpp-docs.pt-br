---
title: 'Como: Adicionar uma etapa de compilação personalizada a projetos MSBuild'
ms.date: 11/04/2016
helpviewer_keywords:
- 'msbuild (c++), howto: add a custom build step'
ms.assetid: a20a0c47-4df4-4754-a1f0-a94a99958916
ms.openlocfilehash: d70f145a9d43463266a9c0bbff68e8e7f36ef2c6
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65220735"
---
# <a name="how-to-add-a-custom-build-step-to-msbuild-projects"></a>Como: Adicionar uma etapa de compilação personalizada a projetos MSBuild

Uma etapa de compilação personalizada é uma etapa definidos pelo usuário em uma compilação. Uma etapa de compilação personalizada se comporta como qualquer outro *ferramenta de comando* etapa, como a etapa de ferramenta de compilação ou de link padrão.

Especifique uma etapa de compilação personalizada no arquivo de projeto (. vcxproj). A etapa pode especificar uma linha de comando para execução, nenhuma entrada adicional ou arquivos de saída e uma mensagem a ser exibida. Se **MSBuild** determina que os arquivos de saída estão desatualizados em relação a seus arquivos de entrada, ele exibe a mensagem e executa o comando.

Para especificar o local da compilação personalizada etapa na sequência de destinos de compilação, use uma ou ambas as `CustomBuildAfterTargets` e `CustomBuildBeforeTargets` elementos XML no arquivo de projeto. Por exemplo, você poderia especificar que a etapa de compilação personalizado é executado após o destino da ferramenta de link e antes do destino da ferramenta de manifesto. O conjunto real de destinos disponíveis depende da sua compilação específica.

Especifique o `CustomBuildBeforeTargets` elemento para executar a etapa de compilação personalizado antes de executa um destino específico, o `CustomBuildAfterTargets` elemento para executar a etapa após a execução de um destino específico, ou ambos os elementos para executar a etapa entre dois destinos adjacentes. Se nenhum elemento for especificado, a ferramenta de compilação personalizada é executado no local padrão, que é posterior a **Link** destino.

Etapas de compilação personalizada e ferramentas de build personalizadas compartilham as informações especificadas na `CustomBuildBeforeTargets` e `CustomBuildAfterTargets` elementos XML. Portanto, especifica os destinos apenas uma vez no arquivo de projeto.

### <a name="to-define-what-is-executed-by-the-custom-build-step"></a>Para definir o que é executado pela etapa de compilação personalizada

1. Adicione um grupo de propriedades para o arquivo de projeto. Nesse grupo de propriedade, especifique o comando, suas entradas e saídas e uma mensagem, conforme mostrado no exemplo a seguir. Este exemplo cria um arquivo. cab do arquivo cpp criado no [passo a passo: Usando MSBuild para criar um C++ Project](walkthrough-using-msbuild-to-create-a-visual-cpp-project.md).

    ```
    <ItemDefinitionGroup>
      <CustomBuildStep>
        <Command>makecab.exe $(ProjectDir)main.cpp $(TargetName).cab</Command>
        <Outputs>$(TargetName).cab</Outputs>
        <Inputs>$(TargetFileName)</Inputs>
      </CustomBuildStep>
    </ItemDefinitionGroup>
    ```

### <a name="to-define-where-in-the-build-the-custom-build-step-will-execute"></a>Para definir onde na compilação de etapa de compilação personalizada será executada

1. Adicione o grupo de propriedades a seguir ao arquivo de projeto. Você pode especificar ambos os destinos, ou você pode omitir um se você quiser apenas a etapa personalizada a ser executada antes ou depois de um destino específico. Este exemplo informa **MSBuild** para executar a etapa personalizada após a etapa de compilação, mas antes da etapa de link.

    ```
    <PropertyGroup>
      <CustomBuildAfterTargets>ClCompile</CustomBuildAfterTargets>
      <CustomBuildBeforeTargets>Link</CustomBuildBeforeTargets>
    </PropertyGroup>
    ```

## <a name="see-also"></a>Consulte também

[Passo a passo: usar o MSBuild para a criação de um projeto C++](walkthrough-using-msbuild-to-create-a-visual-cpp-project.md)<br/>
[Como: Usar eventos de build em projetos do MSBuild](how-to-use-build-events-in-msbuild-projects.md)<br/>
[Como: Adicionar ferramentas personalizadas de build a projetos do MSBuild](how-to-add-custom-build-tools-to-msbuild-projects.md)
