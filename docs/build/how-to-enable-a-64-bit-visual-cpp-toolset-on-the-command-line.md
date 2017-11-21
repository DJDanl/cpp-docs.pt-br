---
title: 'Como: habilitar um 64-Bit Visual C++ conjunto de ferramentas na linha de comando | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
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
caps.latest.revision: "30"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: f776cbaec0b890959db180a373d4cb4152ac5826
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="how-to-enable-a-64-bit-x64-hosted-visual-c-toolset-on-the-command-line"></a>Como: habilitar 64 bits, x64 hospedado conjunto de ferramentas do Visual C++ na linha de comando

O Visual C++ inclui compiladores, vinculadores e outras ferramentas que você pode usar para criar versões específico da plataforma de aplicativos que podem ser executados em sistemas operacionais de Windows 32 bits, 64 bits ou baseados em ARM. Outras cargas de trabalho do Visual Studio opcionais permitem que você use ferramentas C++ para outras plataformas, como iOS, Android e Linux de destino. A arquitetura de compilação padrão usa ferramentas de 32 bits, baseado em x86 para compilar o código de 32 bits, x86 nativo do Windows. No entanto, você provavelmente terá um computador de 64 bits. Você pode tirar proveito do processador e espaço de memória disponível para o código de 64 bits usando o conjunto de ferramentas de 64 bits, x64 hospedado quando você compila o código para processadores ARM, x64 ou x86.
  
> [!NOTE]
>  Para obter informações sobre as ferramentas específicas que são incluídas com cada edição do Visual C++, consulte [recursos em edições do Visual Studio e ferramentas do Visual C++](../ide/visual-cpp-tools-and-features-in-visual-studio-editions.md).  
>   
>  Para obter informações sobre como usar o IDE do Visual Studio para criar aplicativos de 64 bits, consulte [como: configurar projetos do Visual C++ para o destino de 64 bits, x64 plataformas](../build/how-to-configure-visual-cpp-projects-to-target-64-bit-platforms.md).  
  
Quando você instala uma carga de trabalho do C++ no instalador do Visual Studio, ele sempre instala 32 bits, baseado em x86, nativo e entre as ferramentas de compilador para compilar código x86 e x64. Se você incluir a carga de trabalho de plataforma Universal do Windows, ele também instala as ferramentas de compilador cruzado hospedado x86 para compilar código ARM. Se você instalar essas cargas de trabalho em um x64 de 64 bits, processador, você também obtém nativo de 64 bits e entre as ferramentas de compilador criar x86, x64 e ARM de código. As ferramentas de 32 bits e 64 bits geram código idêntico, mas as ferramentas de 64 bits oferecem suporte a mais memória para a otimização de programa total e símbolos de cabeçalho pré-compilado ([/GL](../build/reference/gl-whole-program-optimization.md) e [/LTCG](../build/reference/ltcg-link-time-code-generation.md)) opções. Se você executar em limites de memória quando você usar as ferramentas de 32 bits, tente as ferramentas de 64 bits.  

## <a name="use-a-64-bit-hosted-developer-command-prompt-shortcut"></a>Use um atalho de prompt de comando do desenvolvedor hospedado de 64 bits
  
Quando o Visual Studio está instalado em um sistema de operacional do Windows de 64 bits, atalhos de prompt de comando do desenvolvedor adicionais para o nativo de 64 bits, x64 hospedado e entre compiladores estão disponíveis. Para acessar esses prompts de comando no Windows 10 no **iniciar** menu, abra a pasta para a sua versão do Visual Studio, por exemplo **2017 do Visual Studio**e, em seguida, escolha uma das x64 nativo ou a ferramenta de cruz prompts de comando do desenvolvedor. Para acessar esses prompts de comando no Windows 8 no **iniciar** tela, abra **todos os aplicativos**. Sob o título para a versão instalada do Visual Studio, abra o **Visual Studio** pasta (em versões mais antigas do Visual Studio, ele pode ser chamado **ferramentas do Visual Studio**). Em versões anteriores do Windows, escolha **iniciar**, expanda **todos os programas**, a pasta para a sua versão de **Visual Studio** (e em versões anteriores do Visual Studio,  **Ferramentas do Visual Studio**). Para obter mais informações, consulte [atalhos de prompt de comando do desenvolvedor](../build/building-on-the-command-line.md#developer_command_prompt_shortcuts).  
  
## <a name="use-vcvarsallbat-to-set-a-64-bit-hosted-build-architecture"></a>Use Vcvarsall.bat para definir uma arquitetura de compilação hospedado de 64 bits
  
Qualquer uma das nativo ou entre as ferramentas de compilador configurações de compilação podem ser usadas na linha de comando executando o vcvarsall.bat arquivo de comando. Esse arquivo de comando configura o caminho e as variáveis de ambiente que permitem que uma determinada compilação arquitetura em uma janela de prompt de comando existente. Para obter instruções específicas, consulte [locais e arquivos de comando do desenvolvedor](../build/building-on-the-command-line.md#developer_command_files) .  
  
## <a name="see-also"></a>Consulte também  

[Configurar o Visual C++ para x64 de 64 bits, destinos](../build/configuring-programs-for-64-bit-visual-cpp.md)