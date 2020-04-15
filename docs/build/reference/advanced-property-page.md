---
title: Página de propriedade avançada (Projeto)
ms.date: 07/19/2019
f1_keywords:
- VC.Project.VCConfiguration.VCToolsVersion
ms.description: Use the Advanced property page in Visual Studio 2019 to set various properties for C++ projects.
ms.openlocfilehash: 8ce62b768f5cda30501e791bcd040a40b18bfb23
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328421"
---
# <a name="advanced-property-page"></a>Página de propriedade avançada

A página de propriedade Avançada está disponível no Visual Studio 2019 e posteriormente.

::: moniker range="vs-2019"

## <a name="advanced-properties"></a>Propriedades avançadas

- **Extensão de arquivo de destino**

   Especifica a extensão de arquivo a ser usada para a saída de compilação. Padrão para **.exe** para aplicativos, **.lib** para bibliotecas estáticas e **.dll** para DLLs.

- **Extensões a serem excluídas na limpeza**

   A opção **Limpar** (menu **Build**) exclui arquivos do diretório intermediário no qual uma configuração do projeto é compilada. Arquivos com extensões especificadas com essa propriedade serão excluídos quando a opção **Limpar** for executada ou quando você executar uma recompilação. Além dos arquivos dessas extensões no diretório intermediário, o sistema de build também excluirá todas as saídas de build conhecidas, independentemente de sua localização (incluindo saídas intermediárias, como arquivos .obj). Observe que você pode especificar caracteres curinga.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCConfiguration.DeleteExtensionsOnClean%2A>.

- **Arquivo de log de build**

   Permite que você especifique um local não padrão para o arquivo de log criado sempre que um projeto é compilado. A localização padrão é especificada pelas macros $(IntDir)$(MSBuildProjectName).log.

   Use as macros do projeto para alterar o local do diretório. Consulte [macros comuns para comandos de compilação e propriedades](common-macros-for-build-commands-and-properties.md).

- **Arquitetura de ferramenta de construção preferida**

   Especifica se deve usar as ferramentas de compilação x86 ou x64.

- **Use bibliotecas de depuração**

   Especifica se deve criar uma compilação DEBUG ou RELEASE.

- **Habilitar a construção de Unity (JUMBO)**

   Habilita um processo de compilação onde muitos arquivos de origem C++ são combinados em um ou mais arquivos de "unidade" antes da compilação para melhorar o desempenho da compilação. Não tem relação com o motor do jogo Unity.

- **Uso do MFC**

   Especifica se o projeto MFC será vinculado estática ou dinamicamente à DLL do MFC. Os projetos não MFC podem selecionar **Usar Bibliotecas Padrão do Windows** para serem vinculados a várias bibliotecas do Win32 incluídas quando você usa o MFC.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProject.VCProjectConfigurationProperties.useOfMfc%2A>.

- **Conjunto de caracteres**

   Define se _UNICODE ou _MBCS deve ser definido. Também afeta o ponto de entrada do vinculador, quando apropriado.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProject.VCProjectConfigurationProperties.CharacterSet%2A>.

- **Otimização do Programa Inteiro**

   Especifica a opção do compilador [/GL](gl-whole-program-optimization.md) e a opção [/LTCG](ltcg-link-time-code-generation.md) do vinculador. Por padrão, isso está desabilitado para configurações de Depuração e habilitado para configurações de Varejo.

- **Versão do conjunto de ferramentas MSVC**

   Especifica a versão completa do conjunto de ferramentas MSVC que será usado para construir o projeto. Se você tiver várias versões de atualização e visualização de um conjunto de ferramentas instalado, você pode especificar qual usar aqui.

## <a name="ccli-properties"></a>Propriedades C++/CLI

- **Suporte a Common Language Runtime**

   Faz com que a opção do compilador [/clr](clr-common-language-runtime-compilation.md) seja usada.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProject.VCProjectConfigurationProperties.ManagedExtensions%2A>.

- **Versão da Estrutura de Destino .NET**

   Em projetos gerenciados, especifica a versão do .NET Framework de destino.

- **Habilitar Build Incremental Gerenciado**

   Para projetos gerenciados, isso habilita a detecção de visibilidade externa quando você gera assemblies. Se uma alteração em um projeto gerenciado não está visível para outros projetos, os projetos dependentes não são recompilados. Isso pode melhorar de maneira significativa os tempos de build em soluções que incluem projetos gerenciados.

::: moniker-end
