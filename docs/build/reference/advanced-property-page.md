---
title: Página de propriedades avançada (projeto)
ms.date: 07/19/2019
f1_keywords:
- VC.Project.VCConfiguration.VCToolsVersion
ms.description: Use the Advanced property page in Visual Studio 2019 to set various properties for C++ projects.
ms.openlocfilehash: fae3c76d4a62e3b0409664b3630ad76ab601c52b
ms.sourcegitcommit: 610751254a01cba6ad15fb1e1764ecb2e71f66bf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/18/2019
ms.locfileid: "68315525"
---
# <a name="advanced-property-page"></a>Página de propriedades avançada

A página de propriedades avançada está disponível no Visual Studio 2019 e posterior.

::: moniker range="vs-2019"

## <a name="advanced-properties"></a>Propriedades avançadas

- **Extensão do arquivo de destino**

   Especifica a extensão de arquivo a ser usada para a saída da compilação. O padrão é **. exe** para Applications, **. lib** para bibliotecas estáticas e **. dll** para DLLs.

- **Extensões a Serem Excluídas na Limpeza**

   A opção **Limpar** (menu **Build**) exclui arquivos do diretório intermediário no qual uma configuração do projeto é compilada. Arquivos com extensões especificadas com essa propriedade serão excluídos quando a opção **Limpar** for executada ou quando você executar uma recompilação. Além dos arquivos dessas extensões no diretório intermediário, o sistema de build também excluirá todas as saídas de build conhecidas, independentemente de sua localização (incluindo saídas intermediárias, como arquivos .obj). Observe que você pode especificar caracteres curinga.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCConfiguration.DeleteExtensionsOnClean%2A>.

- **Arquivo de Log de Build**

   Permite que você especifique um local não padrão para o arquivo de log criado sempre que um projeto é compilado. A localização padrão é especificada pelas macros $(IntDir)$(MSBuildProjectName).log.

   Use as macros do projeto para alterar o local do diretório. Consulte [macros comuns para comandos e propriedades de compilação](common-macros-for-build-commands-and-properties.md).

- **Arquitetura de ferramenta de compilação preferida**

   Especifica se as ferramentas de compilação x86 ou x64 devem ser usadas.

- **Usar bibliotecas de depuração**

   Especifica se uma compilação de depuração ou de versão deve ser criada.

- **Habilitar compilação de Unity (JUMBO)**

   Habilita um processo de compilação em C++ que muitos arquivos de origem são combinados em um ou mais arquivos "Unity" antes da compilação para melhorar o desempenho da compilação. Não relacionado ao mecanismo de jogo do Unity.

- **Uso do MFC**

   Especifica se o projeto MFC será vinculado estática ou dinamicamente à DLL do MFC. Os projetos não MFC podem selecionar **Usar Bibliotecas Padrão do Windows** para serem vinculados a várias bibliotecas do Win32 incluídas quando você usa o MFC.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProject.VCProjectConfigurationProperties.useOfMfc%2A>.

- **Conjunto de Caracteres**

   Define se _UNICODE ou _MBCS deve ser definido. Também afeta o ponto de entrada do vinculador, quando apropriado.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProject.VCProjectConfigurationProperties.CharacterSet%2A>.

- **Otimização do Programa Inteiro**

   Especifica a opção do compilador [/GL](gl-whole-program-optimization.md) e a opção [/LTCG](ltcg-link-time-code-generation.md) do vinculador. Por padrão, isso está desabilitado para configurações de Depuração e habilitado para configurações de Varejo.

- **Versão do conjunto de ferramentas MSVC**

   Especifica a versão completa do conjunto de ferramentas MSVC que será usado para compilar o projeto. Se você tiver várias versões de atualização e visualização de um conjunto de ferramentas instalado, poderá especificar qual delas usar aqui.

## <a name="ccli-properties"></a>C++Propriedades de/CLI

- **Suporte a Common Language Runtime**

   Faz com que a opção do compilador [/clr](clr-common-language-runtime-compilation.md) seja usada.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProject.VCProjectConfigurationProperties.ManagedExtensions%2A>.

- **Versão da Estrutura de Destino .NET**

   Em projetos gerenciados, especifica a versão do .NET Framework de destino.

- **Habilitar Build Incremental Gerenciado**

   Para projetos gerenciados, isso habilita a detecção de visibilidade externa quando você gera assemblies. Se uma alteração em um projeto gerenciado não está visível para outros projetos, os projetos dependentes não são recompilados. Isso pode melhorar de maneira significativa os tempos de build em soluções que incluem projetos gerenciados.

::: moniker-end
