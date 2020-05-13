---
title: Definir o caminho e as variáveis de ambiente para compilações de linha de comando
ms.custom: conceptual
ms.date: 07/24/2019
helpviewer_keywords:
- environment variables [C++]
- VCVARS32.bat file
- cl.exe compiler [C++], environment variables
- LINK tool [C++], environment variables
- PATH reserved word
- INCLUDE reserved word
- LINK tool [C++], path
- LIB environment variable
- compiling source code [C++], from command line
- environment variables [C++], CL compiler
ms.assetid: 99389528-deb5-43b9-b99a-03c8773ebaf4
ms.openlocfilehash: aeafe806e5d29b89c243586974814aa7cfc16d1d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81335580"
---
# <a name="set-the-path-and-environment-variables-for-command-line-builds"></a>Definir o caminho e as variáveis de ambiente para compilações de linha de comando

As ferramentas de compilação de linha de comando do Microsoft C++ (MSVC) exigem várias variáveis de ambiente personalizadas para a instalação e a configuração de compilação. Quando uma carga de trabalho do C++ é instalada pelo instalador do Visual Studio, ela cria arquivos de comando personalizados ou arquivos em lotes que definem as variáveis de ambiente necessárias. Em seguida, o instalador usa esses arquivos de comando para criar atalhos para o menu Iniciar do Windows para abrir uma janela de prompt de comando do desenvolvedor. Esses atalhos configuram as variáveis de ambiente para uma configuração de compilação específica. Quando você quiser usar as ferramentas de linha de comando, poderá executar um desses atalhos ou pode abrir uma janela de prompt de comando simples e executar um dos arquivos de comando personalizados para definir o ambiente de configuração de compilação por conta própria. Para obter mais informações, consulte [usar o conjunto de ferramentas MSVC na linha de comando](building-on-the-command-line.md). Para usar os arquivos de comando com um prompt de comando simples, consulte a seção denominada [locais de arquivo de comando do desenvolvedor](building-on-the-command-line.md#developer_command_file_locations).

As ferramentas de linha de comando MSVC usam as variáveis de ambiente PATH, TMP, INCLUDE, LIB e LIBPATH e também usam outras variáveis de ambiente específicas para suas ferramentas, plataformas e SDKs instalados. Mesmo uma instalação simples do Visual Studio pode definir vinte ou mais variáveis de ambiente. Como os valores dessas variáveis de ambiente são específicos para sua instalação e sua escolha de configuração de compilação, e podem ser alterados por atualizações de produto ou atualização, é altamente recomendável que você use um atalho de prompt de comando do desenvolvedor ou um dos arquivos de comando personalizados para defini-los, em vez de defini-los no ambiente do Windows por conta própria.

Para ver quais variáveis de ambiente são definidas por um atalho de prompt de comando do desenvolvedor, você pode usar o comando SET. Abra uma janela de prompt de comando simples e Capture a saída do comando SET para uma linha de base. Abra uma janela de prompt de comando do desenvolvedor e Capture a saída do comando SET para comparação. Uma ferramenta de comparação, como a incorporada no IDE do Visual Studio, pode ser útil para comparar as variáveis de ambiente e ver o que é definido pelo prompt de comando do desenvolvedor. Para obter informações sobre as variáveis de ambiente específicas usadas pelo compilador e pelo vinculador, consulte [variáveis de ambiente CL](reference/cl-environment-variables.md).

> [!NOTE]
> Várias ferramentas de linha de comando ou opções de ferramenta podem exigir permissão de administrador. Se você tiver problemas de permissão ao usá-los, recomendamos que abra a janela do prompt de comando do desenvolvedor usando a opção **Executar como administrador** . No Windows 10, clique com o botão direito do mouse para abrir o menu de atalho da janela do prompt de comando e escolha **mais**, **Executar como administrador**.

## <a name="see-also"></a>Confira também

[Uso do conjunto de ferramentas MSVC da linha de comando](building-on-the-command-line.md)<br/>
[Referência de vinculador MSVC](reference/linking.md)<br/>
[Opções de vinculador MSVC](reference/linker-options.md)<br/>
[Referência de compilador MSVC](reference/compiling-a-c-cpp-program.md)<br/>
[Opções do compilador MSVC](reference/compiler-options.md)
