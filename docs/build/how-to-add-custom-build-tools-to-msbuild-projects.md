---
title: Como adicionar ferramentas de compilação personalizadas a projetos MSBuild
ms.date: 11/04/2016
helpviewer_keywords:
- 'msbuild (c++), howto: add custom build tools'
ms.assetid: de03899a-371d-4396-9bf9-34f45a65e909
ms.openlocfilehash: 812932d9e668ab5ee0eb75eadbf75be3d791cddb
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65220711"
---
# <a name="how-to-add-custom-build-tools-to-msbuild-projects"></a>Como adicionar ferramentas de compilação personalizadas a projetos MSBuild

Uma ferramenta de compilação personalizada é uma ferramenta de linha de comando definida pelo usuário que está associada a um arquivo específico.

Para um arquivo específico, especifique no arquivo de projeto (. vcxproj) a linha de comando a ser executada, quaisquer arquivos de entrada ou saída adicionais e uma mensagem a ser exibida. Se o **MSBuild** determinar que os arquivos de saída estão desatualizados em relação aos arquivos de entrada, ele exibirá a mensagem e executará a ferramenta de linha de comando.

Para especificar quando a ferramenta de compilação personalizada é executada, use um ou ambos os `CustomBuildBeforeTargets` elementos `CustomBuildAfterTargets` XML e no arquivo de projeto. Por exemplo, você pode especificar que a ferramenta de compilação personalizada seja executada após o compilador MIDL e antes do compilador C/C++. Especifique o `CustomBuildBeforeTargets` elemento para executar a ferramenta antes da execução de um destino específico; o `CustomBuildAfterTargets` elemento para executar a ferramenta após um destino específico; ou ambos os elementos para executar a ferramenta entre a execução de dois destinos. Se nenhum elemento for especificado, sua ferramenta de compilação personalizada será executada em seu local padrão, que é antes do destino **MIDL** .

As etapas de compilação personalizadas e as ferramentas de `CustomBuildBeforeTargets` Build personalizadas compartilham as informações `CustomBuildAfterTargets` especificadas nos elementos XML e. Especifique os destinos uma vez no arquivo de projeto.

### <a name="to-add-a-custom-build-tool"></a>Para adicionar uma ferramenta de compilação personalizada

1. Adicione um grupo de itens ao arquivo de projeto e adicione um item para cada arquivo de entrada. Especifique o comando, entradas adicionais, saídas e uma mensagem como metadados de item, conforme mostrado aqui. Este exemplo pressupõe que um arquivo "FAQ. txt" exista no mesmo diretório que o seu projeto.

    ```
    <ItemGroup>
      <CustomBuild Include="faq.txt">
        <Message>Copying readme...</Message>
        <Command>copy %(Identity) $(OutDir)%(Identity)</Command>
        <Outputs>$(OutDir)%(Identity)</Outputs>
      </CustomBuild>
    </ItemGroup>
    ```

### <a name="to-define-where-in-the-build-the-custom-build-tools-will-execute"></a>Para definir o local em que as ferramentas de Build personalizadas serão executadas

1. Adicione o seguinte grupo de propriedades ao arquivo de projeto. Você precisa especificar pelo menos um dos destinos, mas poderá omitir o outro se estiver interessado apenas em fazer com que a etapa de compilação seja executada antes (ou depois) de um destino específico. Este exemplo executa a etapa personalizada após a compilação, mas antes da vinculação.

    ```
    <PropertyGroup>
      <CustomBuildAfterTargets>ClCompile</CustomBuildAfterTargets>
      <CustomBuildBeforeTargets>Link</CustomBuildBeforeTargets>
    </PropertyGroup>
    ```

## <a name="see-also"></a>Confira também

[Walkthrough: usando o MSBuild para criar um projeto do C++](walkthrough-using-msbuild-to-create-a-visual-cpp-project.md)<br/>
[Como usar eventos de build em projetos de MSBuild](how-to-use-build-events-in-msbuild-projects.md)<br/>
[Como adicionar uma etapa de build personalizada a projetos MSBuild](how-to-add-a-custom-build-step-to-msbuild-projects.md)
