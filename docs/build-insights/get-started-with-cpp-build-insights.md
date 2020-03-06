---
title: Introdução ao C++ Build Insights
description: Uma visão geral de alto nível C++ das informações de compilação.
ms.date: 11/03/2019
helpviewer_keywords:
- C++ Build Insights
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 2a5799fecc885b96f4278e0f5077662ce5fd7c8f
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332001"
---
# <a name="get-started-with-c-build-insights"></a>Introdução ao C++ Build Insights

::: moniker range="<=vs-2017"

As C++ ferramentas de informações de compilação estão disponíveis no Visual Studio 2019. Para ver a documentação dessa versão, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2019.

::: moniker-end
::: moniker range="vs-2019"

C++As informações de compilação são uma coleção de ferramentas que fornece maior visibilidade na cadeia de ferramentas C++ do Microsoft Visual (MSVC). As ferramentas coletam dados sobre C++ suas compilações e as apresentam em um formato que pode ajudá-lo a responder a perguntas comuns, como:

- Minhas compilações são suficientemente paralelizadas?
- O que devo incluir no meu cabeçalho pré-compilado (PCH)?
- Há um afunilamento específico no qual devo me concentrar para aumentar minhas velocidades de Build?

Os principais componentes dessa tecnologia são:

- *vcperf. exe*, um utilitário de linha de comando que você pode usar para coletar rastreamentos para suas compilações,
- uma extensão do Windows Performance Analyzer (WPA) que permite exibir rastreamentos de compilação no WPA e
- o C++ SDK de informações de compilação, um Software Development Kit para criar suas próprias ferramentas que consomem C++ dados de informações de compilação.

Clique nos links abaixo para começar rapidamente com estes componentes:

[Tutorial: vcperf e analisador de desempenho do Windows](tutorials/vcperf-and-wpa.md)\
Saiba como coletar rastreamentos de compilação para C++ seus projetos e como exibi-los no WPA.

[Tutorial: Noções básicas de desempenho do Windows](tutorials/wpa-basics.md)\
Descubra dicas de WPA úteis para analisar os rastreamentos de Build.

\ do [SDK do insights de compilação C++ ](reference/sdk/overview.md)
Uma visão geral do C++ SDK do insights de compilação.

::: moniker-end
