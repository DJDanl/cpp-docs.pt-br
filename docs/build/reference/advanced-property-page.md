---
title: Página de propriedades avançada (projeto)
ms.date: 08/10/2020
f1_keywords:
- VC.Project.VCConfiguration.VCToolsVersion
ms.description: Use the Advanced property page in Visual Studio 2019 to set various properties for C++ projects.
ms.openlocfilehash: 3b1e45f984cd40d6ea42ead25b045fc8688ad0a7
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92924039"
---
# <a name="advanced-property-page"></a>Página de propriedades avançada

::: moniker range="<=msvc-150"

A página de propriedades avançada está disponível no Visual Studio 2019 e posterior. Para ver a documentação dessa versão, defina o controle do seletor de **versão** do Visual Studio para este artigo como Visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end

::: moniker range="msvc-160"

A página de propriedades avançada está disponível no Visual Studio 2019 e posterior.

## <a name="advanced-properties"></a>Propriedades avançadas

- **Extensão do arquivo de destino**

   Especifica a extensão de arquivo a ser usada para a saída da compilação. O padrão é para *`.exe`* aplicativos, *`.lib`* para bibliotecas estáticas e *`.dll`* DLLs.

- **Extensões a serem excluídas na limpeza**

   A opção **Limpar** (menu **Build** ) exclui arquivos do diretório intermediário no qual uma configuração do projeto é compilada. Os arquivos com extensões especificadas nesta propriedade são excluídos quando a **limpeza** é executada ou quando você recria. O sistema de compilação exclui todos os arquivos que têm essas extensões no diretório intermediário. Ele também exclui qualquer saída conhecida da compilação, independentemente de onde está localizada. (Isso inclui as saídas intermediárias, como *`.obj`* arquivos.) Você pode especificar caracteres curinga nesta propriedade.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCConfiguration.DeleteExtensionsOnClean%2A>.

- **Arquivo de log de build**

   Permite especificar um local não padrão para o arquivo de log que é criado sempre que você cria um projeto. O local padrão é especificado pelas macros `$(IntDir)$(MSBuildProjectName).log` .

   Use as macros do projeto para alterar o local do diretório. Consulte [macros comuns para comandos e propriedades de compilação](common-macros-for-build-commands-and-properties.md).

- **Arquitetura de ferramenta de compilação preferida**

   Especifica se as ferramentas de compilação x86 ou x64 devem ser usadas.

- **Usar bibliotecas de depuração**

   Especifica se uma compilação de depuração ou de versão deve ser criada.

- **Habilitar compilação de Unity (JUMBO)**

   Habilita um processo de compilação mais rápido que combina muitos arquivos de origem do C++ em um ou mais arquivos antes da compilação. Esses arquivos combinados são conhecidos como arquivos do *Unity* . Eles não estão relacionados ao mecanismo de jogo do Unity.

- **Copiar conteúdo para OutDir**

   Copie os itens marcados como *conteúdo* no projeto para o diretório de saída do projeto ( `$(OutDir)` ). Essa configuração pode simplificar a implantação. Essa propriedade está disponível a partir do Visual Studio 2019 versão 16,7.

- **Copiar referências de projeto para OutDir**

   Copie os itens de referência de projeto do executável (arquivo DLL e EXE) para o diretório de saída do projeto ( `$(OutDir)` ). Em projetos C++/CLI ( [`/clr`](clr-common-language-runtime-compilation.md) ), essa propriedade é ignorada. Em vez disso, a propriedade **Copy local** em cada referência de projeto controla se ele é copiado para o diretório de saída. Essa configuração pode simplificar a implantação local. Ele está disponível a partir do Visual Studio 2019 versão 16,7.

- **Copiar símbolos de referências do projeto para OutDir**

   Copie os arquivos PDB para itens de referência do projeto junto com os itens do executável de referência do projeto para o diretório de saída do projeto ( `$(OutDir)` ). Essa propriedade sempre está habilitada para projetos C++/CLI. Essa configuração pode simplificar a implantação de depuração. Ele está disponível a partir do Visual Studio 2019 versão 16,7.

- **Copiar tempo de execução C++ para OutDir**

   Copie as DLLs de tempo de execução para o diretório de saída do projeto ( `$(OutDir)` ). Essa configuração pode simplificar a implantação local. Ele está disponível a partir do Visual Studio 2019 versão 16,7.

- **Uso do MFC**

   Especifica se o projeto do MFC é vinculado de forma estática ou dinâmica à DLL do MFC. Em projetos não MFC, selecione **usar bibliotecas padrão do Windows** para vincular as bibliotecas do Win32 incluídas pelo MFC.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProject.VCProjectConfigurationProperties.useOfMfc%2A>.

- **Conjunto de caracteres**

   Define se `_UNICODE` ou `_MBCS` deve ser definido. Também afeta o ponto de entrada do vinculador, quando apropriado.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProject.VCProjectConfigurationProperties.CharacterSet%2A>.

- **Otimização do Programa Inteiro**

   Especifica a opção de [`/GL`](gl-whole-program-optimization.md) compilador e a [`/LTCG`](ltcg-link-time-code-generation.md) opção de vinculador. Por padrão, a otimização completa do programa é desabilitada para configurações de depuração e habilitada para configurações de versão.

- **Versão do conjunto de ferramentas MSVC**

   Especifica a versão completa do conjunto de ferramentas MSVC usado para compilar o projeto. Você pode ter várias versões de atualização e visualização de um conjunto de ferramentas instalado. Você pode especificar qual deles usar aqui.

## <a name="ccli-properties"></a>Propriedades de C++/CLI

- **Suporte a Common Language Runtime**

   Faz com que a [`/clr`](clr-common-language-runtime-compilation.md) opção do compilador seja usada.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProject.VCProjectConfigurationProperties.ManagedExtensions%2A>.

- **Versão da Estrutura de Destino .NET**

   Em projetos gerenciados, especifica a versão do .NET Framework de destino.

- **Habilitar Build Incremental Gerenciado**

   Para projetos gerenciados, essa opção habilita a detecção de visibilidade externa quando você gera assemblies. Se uma alteração em um projeto gerenciado não estiver visível para outros projetos, os projetos dependentes não serão recriados. Compilações incrementais gerenciadas podem melhorar drasticamente os tempos de compilação em soluções que incluem projetos gerenciados.

::: moniker-end
