---
title: 'Tutorial: vcperf e analisador de desempenho do Windows'
description: Tutorial sobre como usar o vcperf e o WPA para C++ analisar rastreamentos de Build.
ms.date: 11/03/2019
helpviewer_keywords:
- C++ Build Insights
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 091e366da9342f2561620d975ead2f01b5439bad
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332407"
---
# <a name="tutorial-vcperf-and-windows-performance-analyzer"></a>Tutorial: vcperf e analisador de desempenho do Windows

::: moniker range="<=vs-2017"

As C++ ferramentas de informações de compilação estão disponíveis no Visual Studio 2019. Para ver a documentação dessa versão, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2019.

::: moniker-end
::: moniker range="vs-2019"

Neste tutorial, você aprenderá a usar o *vcperf. exe* para coletar um rastreamento de sua C++ compilação. Você também aprenderá a exibir esse rastreamento no analisador de desempenho do Windows.

## <a name="step-1-install-and-configure-windows-performance-analyzer"></a>Etapa 1: instalar e configurar o analisador de desempenho do Windows

O WPA é um visualizador de rastreamento disponível no ADK (Kit de avaliação e implantação do Windows). É um utilitário separado que não faz parte dos componentes que você pode instalar com o instalador do Visual Studio.

Uma versão do WPA que dá C++ suporte à compilação de informações está disponível no momento apenas no Windows ADK Insider Preview. Para acessar essa versão prévia, você deve se inscrever no [programa Windows Insider](https://insider.windows.com). Você não precisa instalar o sistema operacional Windows 10 Insider Preview para obter a versão prévia do Windows ADK. Você só precisa registrar seu conta Microsoft com o programa Windows Insider.

### <a name="to-download-and-install-wpa"></a>Para baixar e instalar o WPA

Observação: o Windows 8 ou superior é necessário para instalar o analisador de desempenho do Windows.

1. Navegue até a [página de download](https://www.microsoft.com/en-us/software-download/windowsinsiderpreviewADK)do Windows ADK Insider Preview.

1. Baixe o Windows ADK Insider Preview. É uma imagem de disco.

1. Abra a imagem de disco e execute o instalador *adksetup. exe* .

1. Quando solicitado a fornecer os recursos que você deseja instalar, selecione o **Kit de ferramentas de desempenho do Windows**. Você pode selecionar outros recursos, se desejar, mas não é necessário instalar o WPA.

   ![A tela de seleção de recursos do instalador do analisador de desempenho do Windows](media/wpa-installation.png)

### <a name="configuration-steps"></a>Para configurar as informações de compilação

1. Inicie o WPA.

1. Selecione **janela** > **selecionar tabelas (experimental)** .

1. Role para baixo até a seção **diagnóstico** .

1. Selecione todas as exibições do MSVC Build insights.

   ![Painel de seleção de tabela do analisador de desempenho do Windows](media/wpa-configuration.png)

## <a name="step-2-trace-your-build-with-vcperfexe"></a>Etapa 2: rastrear sua compilação com o vcperf. exe

Para exibir C++ dados de informações de compilação, primeiro colete-os em um arquivo de rastreamento seguindo estas etapas:

1. Abra um prompt de comando das ferramentas nativas ou do desenvolvedor de ferramentas cruzadas para o Visual Studio 2019 no modo de administrador. (Clique com o botão direito do mouse no item de menu iniciar e escolha **mais** > **Executar como administrador**.)

1. Na janela do prompt de comando, digite este comando:

   **vcperf. exe/start _SessionName_**

   Escolha um nome de sessão que você se lembrará de *SessionName*.

1. Compile seu projeto como faria normalmente. Você não precisa usar a mesma janela de prompt de comando para compilar.

1. Na janela do prompt de comando, digite este comando:

   **vcperf. exe/Stop _SessionName_ _TraceFile. etl_**

   Use o mesmo nome de sessão escolhido para *SessionName* antes de. Escolha um nome apropriado para o arquivo de rastreamento *TraceFile. etl* .

Veja a aparência de uma seqüência de comandos *vcperf. exe* típica em uma janela de prompt de comando do desenvolvedor:

![Um cenário de uso simples do vcperf. exe](media/vcperf-simple-usage.png)

### <a name="important-notes-about-vcperfexe"></a>Observações importantes sobre o vcperf. exe

- São necessários privilégios de administrador para iniciar ou parar um rastreamento *vcperf. exe* . Use uma janela de prompt de comando do desenvolvedor que você abrir usando **Executar como administrador**.

- Somente uma sessão de rastreamento por vez pode ser executada em um computador.

- Lembre-se de lembrar o nome da sessão que você usou para iniciar o rastreamento. Pode ser difícil parar uma sessão em execução sem saber seu nome.

- Assim como o *CL. exe* e o *link. exe*, o utilitário de linha de comando *vcperf. exe* é incluído em uma instalação do MSVC. Nenhuma etapa adicional é necessária para obter esse componente.

- o *vcperf. exe* coleta informações sobre todas as ferramentas do MSVC em execução no seu sistema. Como resultado, você não precisa iniciar sua compilação no mesmo prompt de comando usado para coletar o rastreamento. Você pode criar seu projeto por meio de um prompt de comando diferente ou até mesmo no Visual Studio.

## <a name="step-3-view-your-trace-in-windows-performance-analyzer"></a>Etapa 3: exibir seu rastreamento no analisador de desempenho do Windows

Inicie o WPA e abra o rastreamento que você acabou de coletar. O WPA deve reconhecê- C++ lo como um rastreamento de informações de compilação e as seguintes exibições devem aparecer no painel do Graph Explorer à esquerda:

- Build Explorer
- Files
- Função

Se você não puder ver esses modos de exibição, verifique se o WPA está configurado corretamente, conforme descrito na [etapa 1](#configuration-steps). Você pode exibir seus dados de compilação arrastando as exibições para a janela de análise vazia à direita, conforme mostrado aqui:

![Exibindo C++ um rastreamento do Build insights no analisador de desempenho do Windows](media/wpa-viewing-trace.gif)

Outras exibições estão disponíveis no painel Gerenciador de gráficos. Arraste-os para a janela de análise quando estiver interessado nas informações que eles contêm. Um útil é a exibição da CPU (amostrada), que mostra a utilização da CPU em toda a compilação.

## <a name="more-information"></a>Mais informações

[Tutorial: Noções básicas do analisador de desempenho do Windows](wpa-basics.md)\
Saiba mais sobre as operações WPA comuns que podem ajudá-lo a analisar os rastreamentos de Build.

[Referência: comandos vcperf](/cpp/build-insights/reference/vcperf-commands)\
A referência de comando *vcperf. exe* lista todas as opções de comando disponíveis.

[Referência: exibições do analisador de desempenho do Windows](/cpp/build-insights/reference/wpa-views)\
Consulte este artigo para obter detalhes sobre os C++ modos de exibição de informações de compilação no WPA.

\ do [analisador de desempenho do Windows](/windows-hardware/test/wpt/windows-performance-analyzer)
O site de documentação do WPA oficial.

::: moniker-end