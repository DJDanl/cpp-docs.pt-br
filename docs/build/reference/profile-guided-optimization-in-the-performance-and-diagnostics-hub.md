---
title: "Otimização no Hub desempenho e diagnóstico guiada por perfil | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: dc3a1914-dbb6-4401-bc63-10665a8c8943
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a51cab03c1361c178846e8b7f00ba7111dc8d731
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="profile-guided-optimization-in-the-performance-and-diagnostics-hub"></a>Otimização guiada por perfil no hub de desempenho e diagnóstico
A Otimização Guiada por perfil para o plug-in no Hub desempenho e diagnóstico do Visual C++, simplifica a experiência de otimização guiada do perfil para desenvolvedores. Você pode [baixar o plug-in](http://go.microsoft.com/fwlink/p/?LinkId=327915) do site do Visual Studio.  
  
 Guiadas por perfil otimização (PGO) ajuda na criação de compilações do x86 e x64 aplicativos nativos que são otimizados para os modo como os usuários interage com eles. PGO é um processo de várias etapa: Crie uma compilação do aplicativo que é instrumentada para criação de perfil e, em seguida, você pode executar "treinamento" — ou seja, executar o aplicativo instrumentado cenários comuns de interação de usuário. Salvar os dados capturados de criação de perfil e, em seguida, recriar seu aplicativo usando os resultados para orientar a otimização de programa inteiro. Embora você possa executar essas etapas individualmente no Visual Studio ou na linha de comando, o plug-in do PGO centraliza e simplifica o processo. O plug-in do PGO define todas as opções necessárias, orienta você em cada etapa, mostra a análise e, em seguida, usa os resultados para configurar a compilação para otimizar a cada função para tamanho ou velocidade. O plug-in do PGO também facilita a executar novamente o treinamento do aplicativo e atualizar os dados de otimização do build conforme você altere seu código.  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Você deve [baixar o plug-in do PGO](http://go.microsoft.com/fwlink/p/?LinkId=327915) e instalá-lo no Visual Studio antes de você pode usá-lo no Hub desempenho e diagnóstico.  
  
## <a name="walkthrough-using-the-pgo-plug-in-to-optimize-an-app"></a>Passo a passo: Usando o plug-in do PGO para otimizar um aplicativo  
 Primeiro, você criará um aplicativo de área de trabalho básico do Win32 no Visual Studio. Se você já tiver um aplicativo nativo que você deseja otimizar, você pode usá-lo e ignorar esta etapa.  
  
#### <a name="to-create-an-app"></a>Para criar um aplicativo  
  
1.  Na barra de menus, escolha **Arquivo**, **Novo**, **Projeto**.  
  
2.  No painel esquerdo do **novo projeto** caixa de diálogo caixa, expanda **instalado**, **modelos**, **Visual C++**e, em seguida, selecione  **MFC**.  
  
3.  No painel central, selecione **aplicativo MFC**.  
  
4.  Especifique um nome para o projeto — por exemplo, **SamplePGOProject**— no **nome** caixa. Escolha o botão **OK**.  
  
5.  No **visão geral** página do **Assistente de aplicativo MFC** caixa de diálogo caixa, escolha o **concluir** botão.  
  
 Em seguida, defina a configuração de build do seu aplicativo para a versão para prepará-lo para a compilação PGO e etapas de treinamento.  
  
#### <a name="to-set-the-build-configuration"></a>Para definir a configuração de compilação  
  
1.  Na barra de menus, escolha **Build**, **Configuration Manager**.  
  
2.  No **do Configuration Manager** caixa de diálogo caixa, escolha o **configuração de solução ativa** botão suspenso e selecione **versão**. Escolha o **fechar** botão.  
  
 Abrir o Hub desempenho e diagnóstico, na barra de menus, escolha **analisar**, **desempenho e diagnóstico**. Isso abre uma página de sessão de diagnóstico que tenha as ferramentas de análise que estão disponíveis para o tipo de projeto.  
  
 ![PGO no Hub desempenho e diagnóstico](../../build/reference/media/pgofig0hub.png "PGOFig0Hub")  
  
 Em **ferramentas disponíveis**, selecione o **Otimização Guiada por perfil** caixa de seleção. Escolha o **iniciar** botão para iniciar o PGO plug-in.  
  
 ![Página de Introdução do PGO](../../build/reference/media/pgofig1start.png "PGOFig1Start")  
  
 O **Otimização Guiada por perfil** página descreve as etapas que o plug-in usa para melhorar o desempenho do seu aplicativo. Escolha o **iniciar** botão.  
  
 ![Página de instrumentação PGO](../../build/reference/media/pgofig2instrument.png "PGOFig2Instrument")  
  
 No **instrumentação** seção, use o **treinamento é habilitado inicialmente** permite que você escolha se deseja incluir a fase de inicialização do aplicativo como parte do treinamento. Se essa opção não estiver selecionada, os dados de treinamento não serão registrados em um aplicativo instrumentado em execução até você ativar explicitamente o treinamento.  
  
 Escolha o **instrumento** botão para criar seu aplicativo com um conjunto especial de opções do compilador. O compilador insere instruções de teste no código gerado. Essas instruções registram dados de criação de perfil durante a fase de treinamento.  
  
 ![Página de compilação instrumentada PGO](../../build/reference/media/pgofig3build.PNG "PGOFig3Build")  
  
 Quando a compilação instrumentada do seu aplicativo for concluída, o aplicativo é iniciado automaticamente.  
  
 Se nenhum erro ou aviso ocorrer durante a compilação, corrija-os e, em seguida, escolha **reiniciar Build** para reiniciar a compilação instrumentada.  
  
 Quando seu aplicativo é iniciado, você pode usar o **iniciar treinamento** e **pausar treinamento** links no **treinamento** seção para controlar quando as informações de criação de perfil é registrada. Você pode usar o **parar aplicativo** e **Iniciar aplicativo** links para parar e reiniciar o aplicativo.  
  
 ![Página de treinamento PGO](../../build/reference/media/pgofig4training.PNG "PGOFig4Training")  
  
 Durante o treinamento, passar por seus cenários de usuário para capturar as informações de criação de perfil que o plug-in do PGO precisa para otimizar o código. Quando você tiver concluído o treinamento, feche o aplicativo ou escolha o **parar aplicativo** link. Escolha o **analisar** botão para iniciar a etapa de análise.  
  
 Quando a análise for concluída, o **Analysis** seção mostra um relatório das informações de criação de perfil que foi capturadas durante a fase de treinamento do cenário do usuário. Você pode usar este relatório para examinar seu aplicativo chamado a maioria das e gasto mais tempo em que as funções. O plug-in do PGO usa as informações para determinar qual aplicativo funções para otimizar a velocidade de e para otimizar o tamanho. O plug-in do PGO configura otimizações de compilação para criar o aplicativo menor, mais rápido para os cenários de usuário que você registrou durante o treinamento.  
  
 ![Página de análise do PGO](../../build/reference/media/pgofig5analyze.png "PGOFig5Analyze")  
  
 Se o treinamento capturadas as informações esperadas de criação de perfil, você pode escolher **salvar alterações** para salvar os dados de perfil analisados em seu projeto para otimizar os builds futuros. Para descartar os dados de perfil e recomeçar o treinamento desde o início, escolha **Refazer treinamento**.  
  
 O arquivo de dados de perfil é salvo em seu projeto em um **dados de treinamento PGO** pasta. Esses dados são usados para controlar as configurações de otimização do compilador compilação em seu aplicativo.  
  
 ![Arquivo de dados PGO no Gerenciador de soluções](../../build/reference/media/pgofig6data.png "PGOFig6Data")  
  
 Após a análise, o plug-in do PGO define opções de compilação em seu projeto para usar os dados de perfil para seletivamente otimizar seu aplicativo durante a compilação. Você pode continuar a modificar e criar seu aplicativo com os mesmos dados de perfil. Quando o aplicativo é compilado, a saída da compilação informa quantas funções e instruções foram otimizadas usando dados de perfil.  
  
 ![Diagnóstico de saída PGO](../../build/reference/media/pgofig7diagnostics.png "PGOFig7Diagnostics")  
  
 Se você fizer alterações significativas do código durante o desenvolvimento, você terá que treinar novamente seu aplicativo para obter as melhor otimizações. É recomendável que você treinar novamente seu aplicativo quando a saída da compilação relata que menos de 80 por cento de funções ou instruções foram otimizadas usando dados de perfil.