---
title: Otimização guiada por perfil no hub de desempenho e diagnóstico
ms.date: 11/19/2018
ms.assetid: dc3a1914-dbb6-4401-bc63-10665a8c8943
ms.openlocfilehash: e1aaf64c18ebde29e6ea0d6b4b6bdad66f21a435
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824258"
---
# <a name="profile-guided-optimization-in-the-visual-studio-2013-performance-and-diagnostics-hub"></a>Otimização no Hub de diagnóstico de desempenho do Visual Studio 2013 e guiada por perfil

Se você estiver usando o Visual Studio 2013, a Otimização Guiada por perfil para o Visual C++ de plug-in no Hub de diagnóstico de desempenho e simplifica a experiência de Otimização Guiada de perfil para desenvolvedores. Você pode [baixar o plug-in](https://marketplace.visualstudio.com/items?itemName=ProfileGuidedOptimizationTeam.ProfileGuidedOptimizationforVisualC) do site do Visual Studio. O plug-in não há suporte em versões posteriores do Visual Studio.

Guiadas por perfil (PGO) de otimização ajuda na criação de compilações do x86 e x64 aplicativos nativos que são otimizados para os maneira como os usuários interage com eles. A PGO é um processo de várias etapas: Você cria um build do aplicativo que é instrumentado para criação de perfil e, em seguida, você pode executar "treinamento". Ou seja, você deve executar o aplicativo instrumentado por meio de cenários comuns de interação do usuário. Salvar os dados capturados de criação de perfil e, em seguida, recriar seu aplicativo usando os resultados para orientar a otimização de programa inteiro. Embora seja possível executar essas etapas individualmente no Visual Studio ou na linha de comando, o plug-in de PGO centraliza e simplifica o processo. O plug-in de PGO define todas as opções necessárias, orienta você em cada etapa, mostra a análise e, em seguida, usa os resultados para configurar o build para otimizar a cada função para o tamanho ou velocidade. O plug-in de PGO também torna mais fácil executar novamente o treinamento do aplicativo e atualizar os dados de otimização do build que você altere seu código.

## <a name="prerequisites"></a>Pré-requisitos

Você deve [baixar o plug-in de PGO](https://marketplace.visualstudio.com/items?itemName=ProfileGuidedOptimizationTeam.ProfileGuidedOptimizationforVisualC) e instalá-lo no Visual Studio antes você pode usá-lo no Hub desempenho e diagnóstico.

## <a name="walkthrough-using-the-pgo-plug-in-to-optimize-an-app"></a>Passo a passo: Usando o plug-in de PGO para otimizar um aplicativo

Primeiro, você criará um aplicativo de área de trabalho básico do Win32 no Visual Studio. Se você já tiver um aplicativo nativo que você deseja otimizar, você pode usá-lo e ignorar esta etapa.

### <a name="to-create-an-app"></a>Para criar um aplicativo

1. Na barra de menus, escolha **Arquivo**, **Novo**, **Projeto**.

1. No painel esquerdo do **novo projeto** diálogo caixa, expanda **instalado**, **modelos**, **Visual C++** e, em seguida, selecione  **MFC**.

1. No painel central, selecione **aplicativo do MFC**.

1. Especifique um nome para o projeto — por exemplo, **SamplePGOProject**— na **nome** caixa. Escolha o botão **OK**.

1. No **visão geral** página do **Assistente de aplicativo MFC** caixa de diálogo, escolha o **concluir** botão.

Em seguida, defina a configuração de build do seu aplicativo para liberação para prepará-lo para a compilação de PGO e etapas de treinamento.

### <a name="to-set-the-build-configuration"></a>Para definir a configuração de compilação

1. Na barra de menus, escolha **Build**, **Configuration Manager**.

1. No **Configuration Manager** diálogo caixa, escolha o **configuração da solução ativa** botão suspenso e selecione **versão**. Escolha o botão **Fechar** .

Abra o Hub desempenho e diagnóstico — na barra de menus, escolha **Analyze**, **desempenho e diagnóstico**. Isso abre uma página de sessão de diagnóstico que tem as ferramentas de análise que estão disponíveis para o tipo de projeto.

![PGO no Hub desempenho e diagnóstico](media/pgofig0hub.png "PGO no Hub desempenho e diagnóstico")

Na **as ferramentas disponíveis**, selecione o **Otimização Guiada por perfil** caixa de seleção. Escolha o **iniciar** botão para iniciar o plug-in de PGO.

![Página de introdução de PGO](media/pgofig1start.png "página de introdução de PGO")

O **Otimização Guiada por perfil** página descreve as etapas que o plug-in usa para melhorar o desempenho do seu aplicativo. Escolha o **iniciar** botão.

![Página de instrumentação de PGO](media/pgofig2instrument.png "página de instrumentação de PGO")

No **instrumentação** seção, você usa o **treinamento é habilitado inicialmente** permite que você escolha se deseja incluir a fase de inicialização do aplicativo como parte do treinamento. Se essa opção não estiver selecionada, os dados de treinamento não são registrados em um aplicativo instrumentado em execução até que você habilitar explicitamente o treinamento.

Escolha o **instrumento** botão para criar seu aplicativo com um conjunto especial de opções do compilador. O compilador insere instruções de investigação no código gerado. Essas instruções registram dados de criação de perfil durante a fase de treinamento.

![Página de build instrumentado de PGO](media/pgofig3build.PNG "página de build instrumentado de PGO")

Quando o build instrumentado de seu aplicativo for concluído, o aplicativo é iniciado automaticamente.

Caso ocorram erros ou avisos durante a compilação, corrija-os e, em seguida, escolha **reiniciar Build** para reiniciar o build instrumentado.

Quando seu aplicativo é iniciado, você pode usar o **treinamento de Introdução** e **pausar treinamento** links na **treinamento** seção para controlar quando as informações de criação de perfil é registrada. Você pode usar o **aplicativo interrompa** e **Iniciar aplicativo** links para parar e reiniciar o aplicativo.

![Página de treinamento de PGO](media/pgofig4training.PNG "página de treinamento de PGO")

Durante o treinamento, percorra os cenários de usuário para capturar as informações de criação de perfil que o plug-in de PGO precisa para otimizar o código. Quando você tiver concluído o treinamento, feche o aplicativo ou escolha o **parar aplicativo** link. Escolha o **analisar** botão para iniciar a etapa de análise.

Quando a análise for concluída, o **análise** seção mostra um relatório das informações de criação de perfil que foi capturadas durante a fase de treinamento do cenário do usuário. Você pode usar esse relatório para examinar quais funções de seu aplicativo chamado a maioria das e gasto mais tempo no. O plug-in de PGO usa as informações para determinar qual aplicativo de funções para otimizar a velocidade e para otimizar o tamanho. O plug-in de PGO configura as otimizações de compilação para criar o aplicativo menor, mais rápido para os cenários de usuário que você registrou durante o treinamento.

![Página de análise PGO](media/pgofig5analyze.png "página de análise PGO")

Se o treinamento capturadas as informações esperadas de criação de perfil, você pode escolher **salvar alterações** para salvar os dados de perfil analisados em seu projeto para otimizar os builds futuros. Para descartar os dados de perfil e começar o treinamento desde o início, escolha **Refazer treinamento**.

O arquivo de dados de perfil é salvo em seu projeto em um **dados de treinamento de PGO** pasta. Esses dados são usados para controlar as configurações de otimização do compilador build em seu aplicativo.

![Arquivo de dados PGO no Gerenciador de soluções](media/pgofig6data.png "arquivo de dados PGO no Gerenciador de soluções")

Após a análise, o plug-in de PGO define opções de build em seu projeto para usar os dados de perfil para seletivamente otimizar seu aplicativo durante a compilação. Você pode continuar a modificar e criar seu aplicativo com os mesmos dados de perfil. Quando o aplicativo é compilado, a saída da compilação informa quantas funções e instruções foram otimizadas usando dados de perfil.

![Diagnósticos de saída de PGO](media/pgofig7diagnostics.png "diagnósticos de saída de PGO")

Se você fizer alterações significativas do código durante o desenvolvimento, talvez você precise treinar novamente seu aplicativo para obter as otimizações de melhores. É recomendável que você treinar novamente seu aplicativo quando a saída da compilação relata que menos de 80 por cento das funções ou instruções foram otimizadas usando dados de perfil.