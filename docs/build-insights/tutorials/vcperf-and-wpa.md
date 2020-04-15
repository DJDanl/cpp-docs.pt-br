---
title: 'Tutorial: vcperf e Analisador de Desempenho do Windows'
description: Tutorial sobre como usar vcperf e WPA para analisar traços de compilação C++.
ms.date: 11/03/2019
helpviewer_keywords:
- C++ Build Insights
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: c22f3dfddfd346d4f0eee898cb5164fd8923336e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323417"
---
# <a name="tutorial-vcperf-and-windows-performance-analyzer"></a>Tutorial: vcperf e Analisador de Desempenho do Windows

::: moniker range="<=vs-2017"

As ferramentas C++ Build Insights estão disponíveis no Visual Studio 2019. Para ver a documentação desta versão, defina o controle do seletor Visual Studio **Version** para este artigo para o Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range="vs-2019"

Neste tutorial, você aprenderá a usar *vcperf.exe* para coletar um traço da sua compilação C++. Você também aprenderá como visualizar esse rastreamento no Analisador de Desempenho do Windows.

## <a name="step-1-install-and-configure-windows-performance-analyzer"></a>Passo 1: Instalar e configurar o Analisador de Desempenho do Windows

WPA é um visualizador de rastreamento disponível no Kit de Avaliação e Implantação do Windows (ADK). É um utilitário separado que não faz parte dos componentes que você pode instalar com o instalador do Visual Studio.

Uma versão do WPA que suporta C++ Build Insights está atualmente disponível apenas no Windows ADK Insider Preview. Para acessar esta pré-visualização, você deve se inscrever no [programa Windows Insider](https://insider.windows.com). Você não precisa instalar o sistema operacional Windows 10 Insider Preview para obter a visualização do Windows ADK. Você só precisa registrar sua conta microsoft no Programa Windows Insider.

### <a name="to-download-and-install-wpa"></a>Para baixar e instalar o WPA

NOTA: O Windows 8 ou superior é necessário para instalar o Analisador de Desempenho do Windows.

1. Navegue até a página [de download](https://www.microsoft.com/en-us/software-download/windowsinsiderpreviewADK)do Windows ADK Insider Preview .

1. Baixe o Windows ADK Insider Preview. É uma imagem de disco.

1. Abra a imagem do disco e execute o instalador *adksetup.exe.*

1. Quando solicitado para os recursos que deseja instalar, selecione o **Windows Performance Toolkit**. Você pode selecionar outros recursos se desejar, mas eles não são obrigados a instalar o WPA.

   ![A tela de seleção de recursos do instalador do Analisador de Desempenho do Windows](media/wpa-installation.png)

### <a name="to-configure-build-insights"></a><a name="configuration-steps"></a>Para configurar build insights

1. Lançar WPA.

1. Selecione **Tabelas** > **selecionadas de janela (experimental)**.

1. Desça até a seção **Diagnósticos.**

1. Selecione todas as visualizações do MSVC Build Insights.

   ![Painel de seleção de tabela do Analisador de Desempenho do Windows](media/wpa-configuration.png)

## <a name="step-2-trace-your-build-with-vcperfexe"></a>Passo 2: Trace sua compilação com vcperf.exe

Para visualizar os dados do C++ Build Insights, primeiro colete-os em um arquivo de rastreamento seguindo estas etapas:

1. Abra um prompt de comando nativo ou de desenvolvedor de ferramentas cruzadas para o Visual Studio 2019 no modo administrador. (Clique com o botão direito do mouse no item Iniciar menu e escolha **Mais** > **Executar como administrador**.)

1. Na janela de solicitação de comando, digite este comando:

   **vcperf.exe /start _SessionName_**

   Escolha um nome de sessão que você lembrará para *SessionName*.

1. Construa seu projeto como normalmente faria. Você não precisa usar a mesma janela de comando para construir.

1. Na janela de solicitação de comando, digite este comando:

   **vcperf.exe /stop _SessionName_ _traceFile.etl_**

   Use o mesmo nome de sessão escolhido para *SessionName* antes. Escolha um nome apropriado para o arquivo *traceFile.etl* trace.

Aqui está como uma seqüência de comando típico *vcperf.exe* se parece em uma janela de prompt de comando do desenvolvedor:

![Um cenário simples de uso vcperf.exe](media/vcperf-simple-usage.png)

### <a name="important-notes-about-vcperfexe"></a>Notas importantes sobre vcperf.exe

- Os privilégios do administrador são necessários para iniciar ou interromper um rastreamento *vcperf.exe.* Use uma janela de solicitação de comando do desenvolvedor que você abre usando **Executar como administrador**.

- Apenas uma sessão de rastreamento por vez pode ser executada em uma máquina.

- Certifique-se de lembrar o nome da sessão que você usou para iniciar seu rastreamento. Pode ser problemático parar uma sessão de corrida sem saber seu nome.

- Assim como *cl.exe* e *link.exe,* o utilitário de linha de comando *vcperf.exe* está incluído em uma instalação de MSVC. Não são necessárias etapas adicionais para obter este componente.

- *vcperf.exe* coleta informações sobre todas as ferramentas MSVC em execução em seu sistema. Como resultado, você não precisa iniciar sua compilação a partir do mesmo prompt de comando que você usou para coletar o rastreamento. Você pode construir seu projeto a partir de um prompt de comando diferente, ou mesmo no Visual Studio.

## <a name="step-3-view-your-trace-in-windows-performance-analyzer"></a>Passo 3: Veja seu rastreamento no Analisador de Desempenho do Windows

Inicie o WPA e abra o rastro que acabou de coletar. O WPA deve reconhecê-lo como um traço C++ Build Insights, e as seguintes visualizações devem aparecer no painel Do Graph Explorer à esquerda:

- Gerenciador de Compilação
- Arquivos
- Função

Se você não puder ver essas exibições, verifique duas vezes se o WPA está configurado corretamente, conforme descrito na [Etapa 1](#configuration-steps). Você pode visualizar seus dados de compilação arrastando as visualizações para a janela de análise vazia à direita, como mostrado aqui:

![Visualização de um rastreamento C++ Build Insights no Analisador de Desempenho do Windows](media/wpa-viewing-trace.gif)

Outras visualizações estão disponíveis no painel Graph Explorer. Arraste-os para a janela de análise quando estiver interessado nas informações que eles contêm. Uma útil é a visualização CPU (Sampled), que mostra a utilização da CPU durante toda a sua compilação.

## <a name="more-information"></a>Mais informações

[Tutorial: Noções básicas do Analisador de Desempenho do Windows](wpa-basics.md)\
Saiba mais sobre operações comuns de WPA que podem ajudá-lo a analisar seus traços de compilação.

[Referência: comandos vcperf](/cpp/build-insights/reference/vcperf-commands)\
A referência de comando *vcperf.exe* lista todas as opções de comando disponíveis.

[Referência: Visualizações do Analisador de Desempenho do Windows](/cpp/build-insights/reference/wpa-views)\
Consulte este artigo para obter detalhes sobre as visualizações do C++ Build Insights no WPA.

[Analisador de desempenho do Windows](/windows-hardware/test/wpt/windows-performance-analyzer)\
O site oficial de documentação da WPA.

::: moniker-end
