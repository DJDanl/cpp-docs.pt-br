---
title: Como habilitar um Conjunto de Ferramentas Visual C++ de 64 bits na linha de comando
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
ms.openlocfilehash: 5c5fe144fe81fcc0fb1194c57dec7fa7556101f2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50572361"
---
# <a name="how-to-enable-a-64-bit-x64-hosted-visual-c-toolset-on-the-command-line"></a>Como: habilitar de 64 bits, x64 hospedado ferramentas do Visual C++ na linha de comando

Visual C++ inclui compiladores, vinculadores e outras ferramentas que você pode usar para criar versões específicas da plataforma dos aplicativos que podem ser executados em sistemas operacionais de Windows 32 bits, 64 bits ou baseados em ARM. Outras cargas de trabalho opcionais do Visual Studio permitem que você use ferramentas C++ para direcionar outras plataformas, como iOS, Android e Linux. A arquitetura de compilação padrão usa ferramentas hospedados em x86 de 32 bits para compilar o código do Windows de 32 bits, nativo x86. No entanto, você provavelmente terá um computador de 64 bits. Você pode tirar proveito do processador e espaço de memória disponível para o código de 64 bits usando o conjunto de ferramentas de 64 bits, hospedadas em x64, quando você compila o código para processadores ARM, x64 ou x86.

> [!NOTE]
> Para obter informações sobre as ferramentas específicas que são incluídas com cada edição do Visual C++, consulte [ferramentas do Visual C++ e recursos em edições do Visual Studio](../ide/visual-cpp-tools-and-features-in-visual-studio-editions.md).
>
> Para obter informações sobre como usar o IDE do Visual Studio para criar aplicativos de 64 bits, consulte [como: configurar projetos do Visual C++ para o destino de 64 bits, x64 plataformas](../build/how-to-configure-visual-cpp-projects-to-target-64-bit-platforms.md).

Quando você instala uma carga de trabalho do C++ no instalador do Visual Studio, ele sempre instala 32-bit hospedados em x86, nativos e cruzados as ferramentas do compilador para compilar código x86 e x64. Se você incluir a carga de trabalho da plataforma Universal do Windows, ele também instala as ferramentas do compilador cruzado hospedados em x86 para compilar o código ARM. Se você instalar essas cargas de trabalho em um x64 de 64 bits, processador, você também obtém nativo de 64 bits e as ferramentas do compilador para compilar x86, x64 e ARM cruzada de código. As ferramentas de 32 bits e 64 bits geram código idêntico, mas as ferramentas de 64 bits suportam mais memória para símbolos pré-compilados do cabeçalho e a otimização de programa inteiro ([/GL](../build/reference/gl-whole-program-optimization.md) e [/LTCG](../build/reference/ltcg-link-time-code-generation.md)) opções. Se você tiver limites de memória quando você usa as ferramentas de 32 bits, experimente as ferramentas de 64 bits.

## <a name="use-a-64-bit-hosted-developer-command-prompt-shortcut"></a>Usar um atalho de prompt de comando do desenvolvedor hospedado de 64 bits

Quando o Visual Studio é instalado em um sistema de operacional do Windows de 64 bits, atalhos de prompt de comando do desenvolvedor adicional para o nativo de 64 bits, hospedadas em x64 e os compiladores cruzados estão disponíveis. Para acessar esses prompts de comando no Windows 10, nos **inicie** menu, abra a pasta para a sua versão do Visual Studio, por exemplo **Visual Studio 2017**e, em seguida, escolha uma das x64 nativo ou de ferramenta cruzada prompts de comando do desenvolvedor. Para acessar esses prompts de comando no Windows 8, nos **inicie** tela, abra **todos os aplicativos**. Sob o título para a versão instalada do Visual Studio, abra o **Visual Studio** pasta (em versões mais antigas do Visual Studio, ele pode ser nomeado **ferramentas do Visual Studio**). Em versões anteriores do Windows, escolha **inicie**, expanda **todos os programas**, a pasta para sua versão do **Visual Studio** (e em versões anteriores do Visual Studio,  **Ferramentas do Visual Studio**). Para obter mais informações, consulte [Atalhos de prompt de comando do desenvolvedor](../build/building-on-the-command-line.md#developer-command-prompt-shortcuts).

## <a name="use-vcvarsallbat-to-set-a-64-bit-hosted-build-architecture"></a>Use o vcvarsall. bat para definir uma arquitetura de compilação hospedado de 64 bits

Arquivo de comando de qualquer uma das nativo ou entre as ferramentas do compilador configurações de build podem ser usadas na linha de comando ao executar o vcvarsall. bat. Esse arquivo de comando configura o caminho e variáveis de ambiente que permitem que uma determinada compilação arquitetura em uma janela de prompt de comando existente. Para obter instruções específicas, consulte [arquivos de comando do desenvolvedor e locais](../build/building-on-the-command-line.md#developer-command-files-and-locations).

## <a name="see-also"></a>Consulte também

[Configurar o Visual C++ para destinos x64 de 64 bits](../build/configuring-programs-for-64-bit-visual-cpp.md)<br/>
