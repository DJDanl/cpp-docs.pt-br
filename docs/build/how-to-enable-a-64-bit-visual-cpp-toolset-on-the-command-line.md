---
title: 'Como: Habilitar um conjunto de ferramentas do MSVC de 64 bits na linha de comando'
ms.date: 03/29/2018
helpviewer_keywords:
- x64 [C++]
- 64-bit compiler [C++], command line usage
- 64-bit compiler [C++], toolset enabling at command line
- command line [C++], 64-bit compiler
- Itanium [C++], command-line compiler
- IPF
- Itanium [C++]
- IPF, command-line compiler
- x64 [C++], command-line compiler
ms.assetid: 4da93a19-e20d-4778-902a-5eee9a6a90b5
ms.openlocfilehash: 8436254a3d8c5c1dae018c2309ceaad7bd5b2408
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58769271"
---
# <a name="how-to-enable-a-64-bit-x64-hosted-msvc-toolset-on-the-command-line"></a>Como: Habilitar o de 64 bits, x64 hospedado MSVC conjunto de ferramentas na linha de comando

Visual Studio inclui compiladores, vinculadores e outras ferramentas que você pode usar para criar versões específicas da plataforma dos aplicativos que podem ser executados em sistemas de operacionais de 32 bits, 64 bits ou baseados em ARM Windows C++. Outras cargas de trabalho opcionais do Visual Studio permitem que você use ferramentas C++ para direcionar outras plataformas, como iOS, Android e Linux. A arquitetura de compilação padrão usa ferramentas hospedados em x86 de 32 bits para compilar o código do Windows de 32 bits, nativo x86. No entanto, você provavelmente terá um computador de 64 bits. Você pode tirar proveito do processador e espaço de memória disponível para o código de 64 bits usando o conjunto de ferramentas de 64 bits, hospedadas em x64, quando você compila o código para processadores ARM, x64 ou x86.

> [!NOTE]
> Para obter informações sobre as ferramentas específicas que são incluídas com cada edição do Visual Studio, consulte [ferramentas do Visual C++ e recursos em edições do Visual Studio](../overview/visual-cpp-tools-and-features-in-visual-studio-editions.md).
>
> Para obter informações sobre como usar o IDE do Visual Studio para criar aplicativos de 64 bits, consulte [como: Configurar projetos do Visual C++ para terem plataformas x64 de 64 bits como destino](how-to-configure-visual-cpp-projects-to-target-64-bit-platforms.md).

Quando você instala uma carga de trabalho do C++ no instalador do Visual Studio, ele sempre instala 32-bit hospedados em x86, nativos e cruzados as ferramentas do compilador para compilar código x86 e x64. Se você incluir a carga de trabalho da plataforma Universal do Windows, ele também instala as ferramentas do compilador cruzado hospedados em x86 para compilar o código ARM. Se você instalar essas cargas de trabalho em um x64 de 64 bits, processador, você também obtém nativo de 64 bits e as ferramentas do compilador para compilar x86, x64 e ARM cruzada de código. As ferramentas de 32 bits e 64 bits geram código idêntico, mas as ferramentas de 64 bits suportam mais memória para símbolos pré-compilados do cabeçalho e a otimização de programa inteiro ([/GL](reference/gl-whole-program-optimization.md) e [/LTCG](reference/ltcg-link-time-code-generation.md)) opções. Se você tiver limites de memória quando você usa as ferramentas de 32 bits, experimente as ferramentas de 64 bits.

## <a name="use-a-64-bit-hosted-developer-command-prompt-shortcut"></a>Usar um atalho de prompt de comando do desenvolvedor hospedado de 64 bits

Quando o Visual Studio é instalado em um sistema de operacional do Windows de 64 bits, atalhos de prompt de comando do desenvolvedor adicional para o nativo de 64 bits, hospedadas em x64 e os compiladores cruzados estão disponíveis. Para acessar esses prompts de comando no Windows 10, nos **inicie** menu, abra a pasta para a sua versão do Visual Studio, por exemplo **Visual Studio 2017**e, em seguida, escolha uma das x64 nativo ou de ferramenta cruzada prompts de comando do desenvolvedor. Para acessar esses prompts de comando no Windows 8, nos **inicie** tela, abra **todos os aplicativos**. Sob o título para a versão instalada do Visual Studio, abra o **Visual Studio** pasta (em versões mais antigas do Visual Studio, ele pode ser nomeado **ferramentas do Visual Studio**). Em versões anteriores do Windows, escolha **inicie**, expanda **todos os programas**, a pasta para sua versão do **Visual Studio** (e em versões anteriores do Visual Studio,  **Ferramentas do Visual Studio**). Para obter mais informações, consulte [Atalhos de prompt de comando do desenvolvedor](building-on-the-command-line.md#developer_command_prompt_shortcuts).

## <a name="use-vcvarsallbat-to-set-a-64-bit-hosted-build-architecture"></a>Use o vcvarsall. bat para definir uma arquitetura de compilação hospedado de 64 bits

Arquivo de comando de qualquer uma das nativo ou entre as ferramentas do compilador configurações de build podem ser usadas na linha de comando ao executar o vcvarsall. bat. Esse arquivo de comando configura o caminho e variáveis de ambiente que permitem que uma determinada compilação arquitetura em uma janela de prompt de comando existente. Para obter instruções específicas, consulte [locais de arquivo de comando do desenvolvedor](building-on-the-command-line.md#developer_command_file_locations).

## <a name="see-also"></a>Consulte também

[Configurar projetos do C++ para x64 de 64 bits, destinos](configuring-programs-for-64-bit-visual-cpp.md)<br/>
