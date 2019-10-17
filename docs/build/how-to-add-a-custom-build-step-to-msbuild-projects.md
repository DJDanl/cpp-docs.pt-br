---
title: Como adicionar uma etapa de build personalizada a projetos MSBuild
ms.date: 10/16/2019
helpviewer_keywords:
- 'msbuild (c++), howto: add a custom build step'
ms.assetid: a20a0c47-4df4-4754-a1f0-a94a99958916
ms.openlocfilehash: 78d40a5b4a02fe9b065bbbdde33afc6180d75381
ms.sourcegitcommit: 9aab425662a66825772f091112986952f341f7c8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/16/2019
ms.locfileid: "72444924"
---
# <a name="how-to-add-a-custom-build-step-to-msbuild-projects"></a>Como adicionar uma etapa de build personalizada a projetos MSBuild

Uma etapa de compilação personalizada é uma etapa definida pelo usuário em uma compilação. Uma etapa de compilação personalizada se comporta como qualquer outra etapa de *ferramenta de comando* , como a etapa padrão de compilação ou link Tool.

Especifique uma etapa de compilação personalizada no arquivo de projeto (. vcxproj). A etapa pode especificar uma linha de comando a ser executada, todos os arquivos de entrada ou saída adicionais e uma mensagem a ser exibida. Se o **MSBuild** determinar que os arquivos de saída estão desatualizados em relação aos arquivos de entrada, ele exibirá a mensagem e executará o comando.

Para especificar o local da etapa de compilação personalizada na sequência de destinos de compilação, use um ou ambos os elementos XML `CustomBuildAfterTargets` e `CustomBuildBeforeTargets` no arquivo de projeto. Por exemplo, você pode especificar que a etapa de compilação personalizada seja executada após o destino da ferramenta de link e antes do destino da ferramenta de manifesto. O conjunto real de destinos disponíveis depende de sua compilação em particular.

Especifique o elemento `CustomBuildBeforeTargets` para executar a etapa de compilação personalizada antes de um destino específico ser executado, o elemento `CustomBuildAfterTargets` para executar a etapa depois que um destino específico é executado, ou ambos os elementos para executar a etapa entre dois destinos adjacentes. Se nenhum elemento for especificado, a ferramenta de compilação personalizada será executada em seu local padrão, que é após o destino do **link** .

As etapas de compilação personalizadas e as ferramentas de Build personalizadas compartilham as informações especificadas nos elementos XML `CustomBuildBeforeTargets` e `CustomBuildAfterTargets`. Portanto, especifique os destinos apenas uma vez no arquivo de projeto.

### <a name="to-define-what-is-executed-by-the-custom-build-step"></a>Para definir o que é executado pela etapa de compilação personalizada

1. Adicione um grupo de propriedades ao arquivo de projeto. Nesse grupo de propriedades, especifique o comando, suas entradas e saídas e uma mensagem, conforme mostrado no exemplo a seguir. Este exemplo cria um arquivo. cab do arquivo Main. cpp que você criou em [Walkthrough: usando o MSBuild para criar C++ um projeto](walkthrough-using-msbuild-to-create-a-visual-cpp-project.md).

    ```
    <ItemDefinitionGroup>
      <CustomBuildStep>
        <Command>makecab.exe $(ProjectDir)main.cpp $(TargetName).cab</Command>
        <Outputs>$(TargetName).cab</Outputs>
        <Inputs>$(ProjectDir)main.cpp</Inputs>
      </CustomBuildStep>
    </ItemDefinitionGroup>
    ```

### <a name="to-define-where-in-the-build-the-custom-build-step-will-execute"></a>Para definir onde a etapa de compilação personalizada será executada

1. Adicione o seguinte grupo de propriedades ao arquivo de projeto. Você pode especificar ambos os destinos ou pode omitir um se quiser que a etapa personalizada seja executada antes ou depois de um destino específico. Este exemplo informa ao **MSBuild** para executar a etapa personalizada após a etapa de compilação, mas antes da etapa de link.

    ```
    <PropertyGroup>
      <CustomBuildAfterTargets>ClCompile</CustomBuildAfterTargets>
      <CustomBuildBeforeTargets>Link</CustomBuildBeforeTargets>
    </PropertyGroup>
    ```

## <a name="see-also"></a>Consulte também

[Walkthrough: usando o MSBuild para criar C++ um projeto](walkthrough-using-msbuild-to-create-a-visual-cpp-project.md)<br/>
[Como usar eventos de build em projetos do MSBuild](how-to-use-build-events-in-msbuild-projects.md)<br/>
[Como adicionar ferramentas de build personalizadas a projetos MSBuild](how-to-add-custom-build-tools-to-msbuild-projects.md)
