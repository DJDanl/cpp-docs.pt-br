---
title: Introdução ao C++ Build Insights
description: Uma visão geral de alto nível do C++ Build Insights.
ms.date: 11/03/2019
helpviewer_keywords:
- C++ Build Insights
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 3a75dfe3bf1263cce53d70b764607cad4eec86d5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325722"
---
# <a name="get-started-with-c-build-insights"></a>Introdução ao C++ Build Insights

::: moniker range="<=vs-2017"

As ferramentas C++ Build Insights estão disponíveis no Visual Studio 2019. Para ver a documentação dessa versão, defina o controle do seletor Visual Studio **Version** para este artigo para o Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range="vs-2019"

C++ Build Insights é uma coleção de ferramentas que fornece maior visibilidade na cadeia de ferramentas Microsoft Visual C++ (MSVC). As ferramentas coletam dados sobre suas compilações C++ e os apresentam em um formato que pode ajudá-lo a responder perguntas comuns, como:

- Minhas construções são suficientemente paralelas?
- O que devo incluir no meu cabeçalho pré-compilado (PCH)?
- Há algum gargalo específico em que eu deveria me concentrar para aumentar minhas velocidades de construção?

Os principais componentes desta tecnologia são:

- *vcperf.exe*, um utilitário de linha de comando que você pode usar para coletar vestígios para suas compilações,
- uma extensão WPA (Windows Performance Analyzer, analisador de desempenho do Windows) que permite visualizar traços de compilação no WPA e
- o C++ Build Insights SDK, um kit de desenvolvimento de software para criar suas próprias ferramentas que consomem dados C++ Build Insights.

Clique nos links abaixo para começar rapidamente com esses componentes:

[Tutorial: vcperf e Analisador de Desempenho do Windows](tutorials/vcperf-and-wpa.md)\
Aprenda a coletar traços de construção para seus projetos C++ e como visualizá-los no WPA.

[Tutorial: Noções básicas de desempenho do Windows](tutorials/wpa-basics.md)\
Descubra dicas de WPA úteis para analisar seus traços de compilação.

[C++ Build Insights SDK](reference/sdk/overview.md)\
Uma visão geral do C++ Build Insights SDK.

::: moniker-end
