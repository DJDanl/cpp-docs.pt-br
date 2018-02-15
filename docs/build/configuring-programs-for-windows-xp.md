---
title: Configurando programas para Windows XP | Microsoft Docs
ms.custom: 
ms.date: 02/02/2018
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 1e4487b3-d815-4123-878b-5718b22f0fd5
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 02ddf1d602fa88caa3ab069e6f2304ccb066621a
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="configuring-programs-for-windows-xp"></a>Configurando programas para Windows XP

Como o Visual Studio oferece suporte a vários conjuntos de ferramentas de plataforma, você pode direcionar os sistemas operacionais e as bibliotecas de tempo de execução que não são suportadas pelo conjunto de ferramentas padrão. Por exemplo, alternando o conjunto de ferramentas de plataforma, você pode usar C++ 11, C++ 14 e aprimoramentos de C++ 17 idiomas suportados pelo compilador do Visual C++ no Visual Studio para criar aplicativos que visam [!INCLUDE[winxp](../build/includes/winxp_md.md)] e [!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)]. Você pode também usar conjuntos de ferramentas de plataforma mais antigos para manter o código herdado binário compatível e ainda aproveitar os recursos mais recentes do IDE do Visual Studio.

## <a name="install-the-windows-xp-platform-toolset"></a>Instale o conjunto de ferramentas de plataforma do Windows XP

Para obter o conjunto de ferramentas de plataforma e componentes de destino [!INCLUDE[winxp](../build/includes/winxp_md.md)] e [!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)] no Visual Studio de 2017, execute o instalador do Visual Studio. Quando você instala inicialmente o Visual Studio ou quando você escolhe **modificar** para modificar uma instalação existente, verifique se o **desenvolvimento de área de trabalho com C++** cargas de trabalho está selecionada. Na lista de componentes opcionais para essa carga de trabalho, escolha **suporte do Windows XP para C++**e, em seguida, escolha **instalar** ou **modificar**.

## <a name="windows-xp-targeting-experience"></a>Direcionamento de experiência do Windows XP

O conjunto de ferramentas da plataforma Windows XP que está incluído no Visual Studio é uma versão do [!INCLUDE[win7](../build/includes/win7_md.md)] SDK, mas ele usa o compilador do C++ atual. Ele também configura as propriedades do projeto para valores padrão apropriados, por exemplo, a especificação de um vinculador compatível para o direcionamento de nível inferior. Somente Windows executar aplicativos de área de trabalho que são criados usando um conjunto de ferramentas de plataforma do Windows XP em [!INCLUDE[winxp](../build/includes/winxp_md.md)] e [!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)], mas esses aplicativos também podem executar em sistemas de operacionais mais recentes do Windows.

#### <a name="to-target-windows-xp"></a>Para direcionar o Windows XP

1. No **Gerenciador de Soluções**, abra o menu de atalho do projeto e escolha **Propriedades**.

1. No **páginas de propriedade** caixa de diálogo para o projeto em **propriedades de configuração** > **geral**, defina o **doconjuntodeferramentasdeplataforma** propriedade para o conjunto de ferramentas do Windows XP desejado. Por exemplo, escolha **2017 do Visual Studio - Windows XP (v141_xp)** para criar o código de [!INCLUDE[winxp](../build/includes/winxp_md.md)] e [!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)] , usando o compilador do Microsoft Visual C++ 2017.

### <a name="c-runtime-support"></a>Suporte de tempo de execução C++

Juntamente com o conjunto de ferramentas de plataforma do Windows XP, a biblioteca de tempo de execução do C (CRT), biblioteca padrão C++, ATL Active Template Library (), biblioteca de tempo de execução de simultaneidade (ConCRT), biblioteca de padrões paralelos (PPL), Microsoft Foundation Class Library (MFC) e C++ AMP (C++ Aceleradas programação grande) biblioteca incluem o suporte de tempo de execução para [!INCLUDE[winxp](../build/includes/winxp_md.md)] e [!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)]. Para esses sistemas operacionais, as versões mínimas com suporte são [!INCLUDE[winxp](../build/includes/winxp_md.md)] Service Pack 3 (SP3) para x86, [!INCLUDE[winxp](../build/includes/winxp_md.md)] Service Pack 2 (SP2) para x64, e [!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)] Service Pack 2 (SP2) para x86 e x64.

Essas bibliotecas são suportadas pelos conjuntos de ferramentas de plataforma instalados pelo Visual Studio, dependendo do destino:

|Biblioteca|Padrão do conjunto de ferramentas para Windows desktop aplicativos de plataforma|Padrão de plataforma conjunto de ferramentas para aplicativos da Windows Store|Direcionamento de conjunto de ferramentas de plataforma do Windows XP [!INCLUDE[winxp](../build/includes/winxp_md.md)], [!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)]|
|---|---|---|---|
|CRT|X|X|X|
|Biblioteca Padrão C++|X|X|X|
|ATL|X|X|X|
|ConCRT/PPL|X|X|X|
|MFC|X||X|
|C++ AMP|X|X||

> [!NOTE]
> Aplicativos que são escritos em C + + CLI e o destino do .NET Framework 4 são executados em [!INCLUDE[winxp](../build/includes/winxp_md.md)] e [!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)].

### <a name="differences-between-the-toolsets"></a>Diferenças entre os conjuntos de ferramentas

Devido a diferenças no suporte de plataforma e de biblioteca, a experiência de desenvolvimento para aplicativos que usam um conjunto de ferramentas de plataforma do Windows XP não é completa para aplicativos que usam o conjunto de ferramentas da plataforma Visual Studio padrão.

- **Recursos da linguagem C++**

   Apenas recursos da linguagem C++ implementados no Visual Studio 2012 têm suporte em aplicativos que usam o v110\_xp conjunto de ferramentas da plataforma. Apenas recursos da linguagem C++ implementados no Visual Studio 2013 têm suporte em aplicativos que usam o v120\_xp conjunto de ferramentas da plataforma. Apenas recursos da linguagem C++ implementados no Visual Studio 2012 têm suporte em aplicativos que usam o v140\_xp conjunto de ferramentas da plataforma. O Visual Studio usa o compilador correspondente quando ele cria usando os conjuntos de ferramentas de plataforma mais antigos. Use o conjunto de ferramentas plataforma mais recente do Windows XP para tirar proveito dos recursos de linguagem C++ adicionais implementado nessa versão do compilador.

- **Depuração remota**

   Ferramentas remotas para Visual Studio não oferece suporte para depuração remota em [!INCLUDE[winxp](../build/includes/winxp_md.md)] ou [!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)]. Para depurar um aplicativo quando ele é executado em [!INCLUDE[winxp](../build/includes/winxp_md.md)] ou [!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)], você pode usar um depurador de uma versão anterior do Visual Studio para depurá-lo localmente ou remotamente. Isso é semelhante a experiência de depuração de um aplicativo no Windows Vista, que é um destino de tempo de execução do conjunto de ferramentas de plataforma, mas não é um destino de depuração remoto.

- **Análise estática**

   Os conjuntos de ferramentas de plataforma do Windows XP não oferecer suporte a análise estática porque as anotações de SAL para o [!INCLUDE[win7](../build/includes/win7_md.md)] SDK e as bibliotecas de tempo de execução são incompatíveis. Quando você deseja executar uma análise estática em um aplicativo que oferece suporte a [!INCLUDE[winxp](../build/includes/winxp_md.md)] ou [!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)], você pode alternar temporariamente a solução para o conjunto de ferramentas de plataforma padrão para executar a análise de destino e, em seguida, alternar de volta para o conjunto de ferramentas da plataforma Windows XP para criar o aplicativo.

- **Depuração de gráficos do DirectX**

     Como o depurador de gráficos não oferecem suporte a API do Direct3D 9, ele não pode ser usado para depurar aplicativos que usam Direct3D em [!INCLUDE[winxp](../build/includes/winxp_md.md)] ou [!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)]. No entanto, se o aplicativo implementa um renderizador alternativo que usa as APIs do Direct3D 11 ou Direct3D 10, o depurador de gráficos pode ser usado para diagnosticar problemas com o uso dessas APIs.

- **Criando HLSL**

   Por padrão, o conjunto de ferramentas do Windows XP não compila arquivos de código fonte HLSL. Para compilar arquivos HLSL, baixe e instale o junho de 2010 SDK do DirectX e defina o projeto do VC diretórios para incluí-lo. Para obter mais informações, consulte o "SDK do DirectX não registra os caminhos de inclusão/biblioteca com o Visual Studio 2010" seção o [junho de 2010 página de download do SDK do DirectX](http://www.microsoft.com/download/details.aspx?displaylang=en&id=6812).
