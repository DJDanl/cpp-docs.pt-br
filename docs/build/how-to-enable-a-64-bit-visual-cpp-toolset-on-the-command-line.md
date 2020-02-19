---
title: Como habilitar um conjunto de ferramentas MSVC de 64 bits na linha de comando
ms.date: 07/24/2019
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
ms.openlocfilehash: 9e8a671a7fe67150e1b867c62231173429f7b6ed
ms.sourcegitcommit: 7bea0420d0e476287641edeb33a9d5689a98cb98
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/17/2020
ms.locfileid: "77415937"
---
# <a name="how-to-enable-a-64-bit-x64-hosted-msvc-toolset-on-the-command-line"></a>Como habilitar um conjunto de ferramentas do MSVC hospedado em x64 de 64 bits na linha de comando

O Visual Studio inclui compiladores, vinculadores e outras ferramentas do C++ que você pode usar para criar versões específicas da plataforma dos aplicativos que podem ser executados em sistemas operacionais do Windows de 32 bits, 64 bits ou baseados no ARM. Outras cargas de trabalho opcionais do Visual Studio permitem que você use ferramentas C++ para direcionamento para outras plataformas, como iOS, Android e Linux. A arquitetura de build padrão usa ferramentas hospedadas no x86 de 32 bits para compilar o código nativo do Windows do x86 de 32 bits. No entanto, provavelmente, você terá um computador de 64 bits. Quando o Visual Studio é instalado em um sistema operacional Windows de 64 bits, atalhos adicionais do Prompt de Comando do Desenvolvedor para os compiladores nativos e cruzados hospedados no x64 de 64 bits ficam disponíveis. Aproveite o espaço de memória e o processador disponíveis para o código de 64 bits usando o conjunto de ferramentas hospedado no x64 de 64 bits quando você compilar o código para processadores x86, x64 ou ARM.

## <a name="use-a-64-bit-hosted-developer-command-prompt-shortcut"></a>Usar um atalho do Prompt de Comando do Desenvolvedor hospedado de 64 bits

Para acessar esses prompts de comando no Windows 10, no menu **Iniciar**, abra a pasta da versão do Visual Studio, por exemplo, **Visual Studio 2019** e, em seguida, escolha um dos prompts de comando do desenvolvedor de ferramenta nativa ou cruzada do x64. 

![Prompt de Comando de Ferramentas Nativas do x64](media/x64-native-tools-command-prompt.png "Ferramentas nativas do x64 no menu iniciar")

Para acessar esses prompts de comando no Windows 8, na tela **Iniciar**, abra **Todos os aplicativos**. Sob o título da versão instalada do Visual Studio, abra a pasta **Visual Studio** (em versões mais antigas do Visual Studio, ela pode ser chamada **Ferramentas do Visual Studio**). Em versões anteriores do Windows, escolha **Iniciar**, expanda **Todos os Programas**, a pasta da versão do **Visual Studio** (e em versões anteriores do Visual Studio, **Ferramentas do Visual Studio**). Para obter mais informações, consulte [Atalhos de prompt de comando do desenvolvedor](building-on-the-command-line.md#developer_command_prompt_shortcuts).

## <a name="use-vcvarsallbat-to-set-a-64-bit-hosted-build-architecture"></a>Usar vcvarsall.bat para definir uma arquitetura de build hospedada de 64 bits

Qualquer uma das configurações de build das ferramentas do compilador nativo ou cruzado pode ser usada na linha de comando com a execução do arquivo de comando vcvarsall.bat. Esse arquivo de comando configura o caminho e as variáveis de ambiente que habilitam determinada arquitetura de build em uma janela do prompt de comando existente. Para obter instruções específicas, confira [Localizações do arquivo de comando do desenvolvedor](building-on-the-command-line.md#developer_command_file_locations).

## <a name="remarks"></a>Comentários

> [!NOTE]
> Para obter informações sobre as ferramentas específicas incluídas em cada edição do Visual Studio, confira [Ferramentas e funcionalidades do Visual C++ nas edições do Visual Studio](../overview/visual-cpp-tools-and-features-in-visual-studio-editions.md).
>
> Para obter informações sobre como usar o IDE do Visual Studio para criar aplicativos de 64 bits, consulte [How to: configure C++ visual Projects to Target plataformas de 64 bits, x64](how-to-configure-visual-cpp-projects-to-target-64-bit-platforms.md).

Quando você instala uma carga de trabalho do C++ no Instalador do Visual Studio, ele sempre instala ferramentas do compilador nativo e cruzado hospedadas no x86 de 32 bits, para compilar o código do x86 e do x64. Se você incluir a carga de trabalho da Plataforma Universal do Windows, ela também instalará as ferramentas do compilador cruzado hospedadas no x86 para compilar o código do ARM. Se você instalar essas cargas de trabalho em um processador x64 de 64 bits, você também obterá as ferramentas do compilador nativo e cruzado de 64 bits para compilar o código do x86, do x64 e do ARM. As ferramentas de 32 e 64 bits geram um código idêntico, mas as ferramentas de 64 bits dão suporte a mais memória para símbolos de cabeçalho pré-compilado e as opções de Otimização do Programa Inteiro ([/GL](reference/gl-whole-program-optimization.md) e [/LTCG](reference/ltcg-link-time-code-generation.md)). Caso você atinja os limites de memória ao usar o compilador de 32 bits, tente usar o compilador de 64 bits.

## <a name="see-also"></a>Confira também

[Configurar projetos C++ para destinos x64 de 64 bits](configuring-programs-for-64-bit-visual-cpp.md)<br/>
