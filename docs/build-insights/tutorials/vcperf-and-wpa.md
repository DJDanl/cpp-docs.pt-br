---
title: 'Tutorial: vcperf e analisador de desempenho do Windows'
description: Tutorial sobre como usar o vcperf e o WPA para analisar rastreamentos de Build do C++.
ms.date: 11/03/2019
helpviewer_keywords:
- C++ Build Insights
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: f3a0b4a9c57fd55c6788481adbf91c48e362444e
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88833394"
---
# <a name="tutorial-vcperf-and-windows-performance-analyzer"></a>Tutorial: vcperf e analisador de desempenho do Windows

::: moniker range="<=vs-2017"

As ferramentas de compilação do C++ estão disponíveis no Visual Studio 2019. Para ver a documentação desta versão, defina o controle do seletor de **versão** do Visual Studio para este artigo como Visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range="vs-2019"

Neste tutorial, você aprenderá a usar *vcperf.exe* para coletar um rastreamento de sua compilação em C++. Você também aprenderá a exibir esse rastreamento no analisador de desempenho do Windows.

## <a name="step-1-install-and-configure-windows-performance-analyzer"></a>Etapa 1: instalar e configurar o analisador de desempenho do Windows

O WPA é um visualizador de rastreamento disponível no ADK (Kit de avaliação e implantação do Windows). É um utilitário separado que não faz parte dos componentes que você pode instalar com o instalador do Visual Studio.

Uma versão do WPA que dá suporte a informações de compilação C++ está disponível no momento apenas no Windows ADK Insider Preview. Para acessar essa versão prévia, você deve se inscrever no [programa Windows Insider](https://insider.windows.com). Você não precisa instalar o sistema operacional Windows 10 Insider Preview para obter a versão prévia do Windows ADK. Você só precisa registrar seu conta Microsoft com o programa Windows Insider.

### <a name="to-download-and-install-wpa"></a>Para baixar e instalar o WPA

Observação: o Windows 8 ou superior é necessário para instalar o analisador de desempenho do Windows.

1. Navegue até a página de [Download](/windows-hardware/get-started/adk-install)do Windows ADK.

1. Baixe e instale a versão mais recente do Windows ADK.

1. Quando solicitado a fornecer os recursos que você deseja instalar, selecione o **Kit de ferramentas de desempenho do Windows**. Você pode selecionar outros recursos, se desejar, mas não é necessário instalar o WPA.

   ![A tela de seleção de recursos do instalador do analisador de desempenho do Windows](media/wpa-installation.png)

### <a name="to-configure-wpa"></a><a name="configuration-steps"></a> Para configurar o WPA

A exibição de rastreamentos de informações de Build do C++ no WPA requer um suplemento especial. Siga estas etapas para instalá-lo:

1. Obtenha o suplemento baixando um dos componentes abaixo. Você não precisa obter ambos. Escolha aquela que você acha mais conveniente.
    1. [Visual Studio 2019 versão 16,6 e superior](https://visualstudio.microsoft.com/downloads/), ou,
    1. [Pacote NuGet do insights do Build do C++](https://www.nuget.org/packages/Microsoft.Cpp.BuildInsights/).

1. Copie o `perf_msvcbuildinsights.dll` arquivo para o diretório de instalação do WPA.
    1. No Visual Studio 2019 versão 16,6 e posterior, esse arquivo está localizado aqui: `C:\Program Files (x86)\Microsoft Visual Studio\2019\{Edition}\VC\Tools\MSVC\{Version}\bin\Host{Architecture}\{Architecture}` .
    1. No pacote NuGet do insights do Build do C++, este arquivo está localizado aqui: `wpa\{Architecture}` .
    1. Nos caminhos acima, substitua as variáveis entre chaves da seguinte maneira:
        1. `{Edition}` é a edição do Visual Studio 2019, como Comunidade, Professional ou Enterprise.
        1. `{Version}` é sua versão do MSVC. Escolha a mais alta disponível.
        1. `{Architecture}`: escolha `x64` se você tem uma versão de 64 bits do Windows. Caso contrário, escolha `x86` .
    1. O diretório de instalação do WPA normalmente é: `C:\Program Files (x86)\Windows Kits\10\Windows Performance Toolkit` .

1. No diretório de instalação do WPA, abra o `perfcore.ini` arquivo e adicione uma entrada para `perf_msvcbuildinsights.dll` .

## <a name="step-2-trace-your-build-with-vcperfexe"></a>Etapa 2: rastrear sua compilação com o vcperf.exe

Para exibir dados de informações de compilação do C++, primeiro colete-os em um arquivo de rastreamento seguindo estas etapas:

1. Abra um **x64** ou **Prompt de Comando de Ferramentas Nativas do x86 para vs 2019** no modo de administrador. (Clique com o botão direito do mouse no item de menu iniciar e escolha **mais**  >  **Executar como administrador**.)
    1. Escolha **x64** se você tiver uma versão de 64 bits do Windows. Caso contrário, escolha **x86**.

1. Na janela do prompt de comando, digite este comando:

   **vcperf.exe/Start _SessionName_**

   Escolha um nome de sessão que você se lembrará de *SessionName*.

1. Compile seu projeto como faria normalmente. Você não precisa usar a mesma janela de prompt de comando para compilar.

1. Na janela do prompt de comando, digite este comando:

   **vcperf.exe/Stop _SessionName_ _TraceFile. etl_**

   Use o mesmo nome de sessão escolhido para *SessionName* antes de. Escolha um nome apropriado para o arquivo de rastreamento *TraceFile. etl* .

Esta é a aparência de uma seqüência de comandos típica *vcperf.exe* em uma janela de prompt de comando do desenvolvedor:

![Um cenário de uso simples de vcperf.exe](media/vcperf-simple-usage.png)

### <a name="important-notes-about-vcperfexe"></a>Observações importantes sobre vcperf.exe

- São necessários privilégios de administrador para iniciar ou parar um rastreamento de *vcperf.exe* . Use uma janela de prompt de comando do desenvolvedor que você abrir usando **Executar como administrador**.

- Somente uma sessão de rastreamento por vez pode ser executada em um computador.

- Lembre-se de lembrar o nome da sessão que você usou para iniciar o rastreamento. Pode ser difícil parar uma sessão em execução sem saber seu nome.

- Assim como *cl.exe* e *link.exe*, o utilitário de linha de comando *vcperf.exe* está incluído em uma instalação do MSVC. Nenhuma etapa adicional é necessária para obter esse componente.

- *vcperf.exe* coleta informações sobre todas as ferramentas do MSVC em execução no seu sistema. Como resultado, você não precisa iniciar sua compilação no mesmo prompt de comando usado para coletar o rastreamento. Você pode criar seu projeto por meio de um prompt de comando diferente ou até mesmo no Visual Studio.

### <a name="vcperfexe-is-open-source"></a>O vcperf.exe está em código-fonte aberto

Se você quiser criar e executar sua própria versão do *vcperf.exe*, sinta-se à vontade para cloná-la do [repositório GitHub do vcperf](https://github.com/microsoft/vcperf).

## <a name="step-3-view-your-trace-in-windows-performance-analyzer"></a>Etapa 3: exibir seu rastreamento no analisador de desempenho do Windows

Inicie o WPA e abra o rastreamento que você acabou de coletar. O WPA deve reconhecê-lo como um rastreamento de informações de Build do C++ e as seguintes exibições devem aparecer no painel do Graph Explorer à esquerda:

- Gerenciador de Compilação
- Arquivos
- Funções
- Instanciações de modelo

Se você não puder ver esses modos de exibição, verifique se o WPA está configurado corretamente, conforme descrito na [etapa 1](#configuration-steps). Você pode exibir seus dados de compilação arrastando as exibições para a janela de análise vazia à direita, conforme mostrado aqui:

![Exibindo um rastreamento de análise de informações do C++ no analisador de desempenho do Windows](media/wpa-viewing-trace.gif)

Outras exibições estão disponíveis no painel Gerenciador de gráficos. Arraste-os para a janela de análise quando estiver interessado nas informações que eles contêm. Um útil é a exibição da CPU (amostrada), que mostra a utilização da CPU em toda a compilação.

## <a name="more-information"></a>Mais informações

[Tutorial: Noções básicas do analisador de desempenho do Windows](wpa-basics.md)\
Saiba mais sobre as operações WPA comuns que podem ajudá-lo a analisar os rastreamentos de Build.

[Referência: comandos vcperf](/cpp/build-insights/reference/vcperf-commands)\
A referência de comando *vcperf.exe* lista todas as opções de comando disponíveis.

[Referência: exibições do analisador de desempenho do Windows](/cpp/build-insights/reference/wpa-views)\
Consulte este artigo para obter detalhes sobre os modos de exibição de informações de compilação do C++ no WPA.

[Analisador de desempenho do Windows](/windows-hardware/test/wpt/windows-performance-analyzer)\
O site de documentação do WPA oficial.

::: moniker-end
