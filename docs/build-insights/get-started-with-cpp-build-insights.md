---
title: Introdução ao C++ Build Insights
description: Uma visão geral de alto nível das informações de Build do C++.
ms.date: 11/03/2019
helpviewer_keywords:
- C++ Build Insights
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 28d7e0758ea521af424129c546297fc97e3d6659
ms.sourcegitcommit: 8c8ed02a6f3bcb5ee008e3fe30ba7595d7c4c922
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/21/2020
ms.locfileid: "83759219"
---
# <a name="get-started-with-c-build-insights"></a>Introdução ao C++ Build Insights

::: moniker range="<=vs-2017"

As ferramentas de compilação do C++ estão disponíveis no Visual Studio 2019. Para ver a documentação dessa versão, defina o controle do seletor de **versão** do Visual Studio para este artigo como Visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range="vs-2019"

As informações de Build do C++ são uma coleção de ferramentas que fornece maior visibilidade na cadeia de ferramentas do Microsoft Visual C++ (MSVC). As ferramentas coletam dados sobre suas compilações do C++ e as apresentam em um formato que pode ajudá-lo a responder a perguntas comuns, como:

- Minhas compilações são suficientemente paralelizadas?
- O que devo incluir no meu cabeçalho pré-compilado (PCH)?
- Há um afunilamento específico no qual devo me concentrar para aumentar minhas velocidades de Build?

Os principais componentes dessa tecnologia são:

- *vcperf. exe*, um utilitário de linha de comando que você pode usar para coletar rastreamentos para suas compilações,
- uma extensão do Windows Performance Analyzer (WPA) que permite exibir rastreamentos de compilação no WPA e
- o SDK do Application insights do C++, um Software Development Kit para criar suas próprias ferramentas que consomem dados de informações de compilação do C++.

## <a name="documentation-sections"></a>Seções de documentação

[Tutorial: vcperf e analisador de desempenho do Windows](tutorials/vcperf-and-wpa.md)\
Saiba como coletar rastreamentos de Build para seus projetos C++ e como exibi-los no WPA.

[Tutorial: Noções básicas de desempenho do Windows](tutorials/wpa-basics.md)\
Descubra dicas de WPA úteis para analisar os rastreamentos de Build.

[SDK do insights de compilação do C++](reference/sdk/overview.md)\
Uma visão geral do SDK de informações de Build do C++.

## <a name="articles"></a>Artigos

Leia estes artigos no blog oficial da equipe do C++ para obter mais informações sobre as ideias de Build do C++:

[Apresentando as informações de Build do C++](https://devblogs.microsoft.com/cppblog/introducing-c-build-insights/)

[Analise suas compilações programaticamente com o SDK de compilação do C++](https://devblogs.microsoft.com/cppblog/analyze-your-builds-programmatically-with-the-c-build-insights-sdk/)

[Encontrando afunilamentos de compilação com os insights de compilação do C++](https://devblogs.microsoft.com/cppblog/finding-build-bottlenecks-with-cpp-build-insights/)

[Compilações mais rápidas com sugestões de PCH de análises de compilação do C++](https://devblogs.microsoft.com/cppblog/faster-builds-with-pch-suggestions-from-c-build-insights/)

::: moniker-end
