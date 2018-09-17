---
title: 'Como: adicionar ferramentas de Build personalizadas a projetos MSBuild | Microsoft Docs'
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
ms.openlocfilehash: 4e06a2a545862c0fa9cfdcf6311334ecc86de2bf
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45714396"
---
# <a name="how-to-add-custom-build-tools-to-msbuild-projects"></a>Como adicionar ferramentas de build personalizadas a projetos MSBuild

Uma ferramenta de compilação personalizada é uma ferramenta de linha de comando, definido pelo usuário que está associada um arquivo específico.

Para um arquivo específico, especifique no arquivo de projeto (. vcxproj) da linha de comando para executar, qualquer entrada adicional ou arquivos de saída e uma mensagem a ser exibida. Se **MSBuild** determina que os arquivos de saída estão desatualizados em relação a seus arquivos de entrada, ele exibe a mensagem e executa a ferramenta de linha de comando.

Para especificar quando executa a ferramenta de compilação personalizada, use um ou ambos os `CustomBuildBeforeTargets` e `CustomBuildAfterTargets` elementos XML no arquivo de projeto. Por exemplo, você pode especificar que a ferramenta de compilação personalizada executar depois do compilador MIDL e antes do compilador C/C++. Especifique o `CustomBuildBeforeTargets` elemento para executar a ferramenta antes de executa um destino específico; o `CustomBuildAfterTargets` elemento para executar a ferramenta depois de um destino específico; ou ambos os elementos para executar a ferramenta entre a execução de dois destinos. Se nenhum elemento for especificado, a ferramenta de compilação personalizada executa em seu local padrão, que é antes do **MIDL** destino.

Etapas de compilação personalizada e ferramentas de build personalizadas compartilham as informações especificadas na `CustomBuildBeforeTargets` e `CustomBuildAfterTargets` elementos XML. Especifique esses destinos de uma vez no arquivo de projeto.

### <a name="to-add-a-custom-build-tool"></a>Para adicionar uma ferramenta de compilação personalizada

1. Adicione um grupo de itens para o arquivo de projeto e adicione um item para cada arquivo de entrada. Especifique o comando, entradas adicionais, saídas e uma mensagem como metadados de item, conforme mostrado aqui. Este exemplo pressupõe que existe um arquivo de "faq.txt" no mesmo diretório que o seu projeto.

    ```
    <ItemGroup>
      <CustomBuild Include="faq.txt">
        <Message>Copying readme...</Message>
        <Command>copy %(Identity) $(OutDir)%(Identity)</Command>
        <Outputs>$(OutDir)%(Identity)</Outputs>
      </CustomBuild>
    </ItemGroup>
    ```

### <a name="to-define-where-in-the-build-the-custom-build-tools-will-execute"></a>Para definir onde na compilação de ferramentas de compilação personalizada serão executada

1. Adicione o grupo de propriedades a seguir ao arquivo de projeto. Você deve especificar pelo menos um dos destinos, mas você pode omitir a outra se você só estiver interessado em ter a etapa de compilação antes (ou depois) de executar um destino específico. Este exemplo executa a etapa personalizada após a compilação, mas antes de vincular.

    ```
    <PropertyGroup>
      <CustomBuildAfterTargets>ClCompile</CustomBuildAfterTargets>
      <CustomBuildBeforeTargets>Link</CustomBuildBeforeTargets>
    </PropertyGroup>
    ```

## <a name="see-also"></a>Consulte também

[Instruções passo a passo: usando MSBuild para criar um projeto do Visual C++](../build/walkthrough-using-msbuild-to-create-a-visual-cpp-project.md)<br/>
[Como usar eventos de build em projetos do MSBuild](../build/how-to-use-build-events-in-msbuild-projects.md)<br/>
[Como adicionar uma etapa de build personalizada a projetos MSBuild](../build/how-to-add-a-custom-build-step-to-msbuild-projects.md)