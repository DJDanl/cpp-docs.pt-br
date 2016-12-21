---
title: "Otimiza&#231;&#227;o guiada por perfil no hub de desempenho e diagn&#243;stico | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: dc3a1914-dbb6-4401-bc63-10665a8c8943
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Otimiza&#231;&#227;o guiada por perfil no hub de desempenho e diagn&#243;stico
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A Otimização Guiada por perfil para Visual C\+\+ de plug\-in no Hub de diagnóstico de desempenho e simplifica a experiência de Otimização Guiada por perfil para desenvolvedores.  Você pode [baixar o plug\-in](http://go.microsoft.com/fwlink/p/?LinkId=327915) de site do Visual Studio.  
  
 Guiada por perfil otimização \(PGO\) o ajuda a criar compilações de aplicativos nativos x86 e x64 que são otimizados para os maneira como os usuários interage com eles.  PGO é um processo de várias etapa: Crie a criação de um aplicativo que é instrumentada para criação de perfil e, em seguida, execute o "treinamento" — ou seja, você executa o aplicativo instrumentado cenários comuns de interação de usuário.  Salvar os dados capturados de criação de perfil e, em seguida, recriar seu aplicativo usando os resultados para orientar a otimização de todo o programa.  Embora você possa executar essas etapas individualmente no Visual Studio ou na linha de comando, o plug\-in PGO centraliza e simplifica o processo.  O plug\-in PGO define todas as opções necessárias, orienta você em cada etapa, mostra a análise e, em seguida, usa os resultados para configurar a compilação para otimizar a cada função de tamanho ou velocidade.  O plug\-in PGO também facilita executar novamente o treinamento do aplicativo e atualizar os dados de otimização de compilação que você altere seu código.  
  
## Pré\-requisitos  
 Você deve [baixar o plug\-in PGO](http://go.microsoft.com/fwlink/p/?LinkId=327915) e instalá\-lo no Visual Studio antes que você pode usá\-lo no Hub desempenho e diagnóstico.  
  
## Passo a passo: Usando o plug\-in PGO para otimizar um aplicativo  
 Primeiro, você criará um aplicativo de área de trabalho básico do Win32 no Visual Studio.  Se você já tiver um aplicativo nativo que você deseja otimizar, você pode usá\-lo e ignorar esta etapa.  
  
#### Para criar um aplicativo  
  
1.  Na barra de menus, escolha **Arquivo**, **Novo**, **Projeto**.  
  
2.  No painel esquerdo do **novo projeto** caixa de diálogo caixa, expanda **instalados**, **modelos**, **Visual C\+\+**, e, em seguida, selecione **MFC**.  
  
3.  No painel central, selecione **aplicativo MFC**.  
  
4.  Especifique um nome para o projeto — por exemplo, SamplePGOProject — no **nome** caixa.  Escolha o botão **OK**.  
  
5.  No **Visão geral** página do **MFC Application Wizard** caixa de diálogo caixa, escolha o **Concluir** botão.  
  
 Em seguida, defina a configuração de compilação do seu aplicativo para liberação para prepará\-lo para a compilação PGO e etapas de treinamento.  
  
#### Para definir a configuração de compilação  
  
1.  Na barra de menus, escolha **Compilação**, **Gerenciador de Configurações**.  
  
2.  No **Configuration Manager** caixa de diálogo caixa, escolha o **configuração da solução ativa** botão suspenso e selecione **versão**.  Escolha o **Fechar** botão.  
  
 Abra o Hub desempenho e diagnóstico — na barra de menus, escolha **Analisar**, **desempenho e diagnóstico**.  Isso abre uma página de sessão de diagnóstico que tenha as ferramentas de análise que estão disponíveis para o tipo de projeto.  
  
 ![PGO in the Performance and Diagnostics Hub](../../build/reference/media/pgofig0hub.png "PGOFig0Hub")  
  
 Em **ferramentas disponíveis**, selecione o **Otimização Guiada por perfil** caixa de seleção.  Escolha o **Iniciar** botão para iniciar o plug\-in PGO.  
  
 ![PGO introduction page](../../build/reference/media/pgofig1start.png "PGOFig1Start")  
  
 O **Otimização Guiada por perfil** página descreve as etapas que o plug\-in usa para melhorar o desempenho do seu aplicativo.  Escolha o **Iniciar** botão.  
  
 ![PGO instrumentation page](../Image/PGOFig2Instrument.png "PGOFig2Instrument")  
  
 No **instrumentação** seção, use o **treinamento é habilitado inicialmente** pode optar por incluir a fase de inicialização de seu aplicativo como parte do treinamento.  Se essa opção não estiver selecionada, os dados de treinamento não serão registrados em um aplicativo instrumentado em execução até você ativar explicitamente o treinamento.  
  
 Escolha o **instrumento** botão para criar seu aplicativo com um conjunto especial de opções do compilador.  O compilador insere instruções de investigação no código gerado.  Essas instruções registram dados de criação de perfil durante a fase de treinamento.  
  
 ![PGO instrumented build page](../../build/reference/media/pgofig3build.PNG "PGOFig3Build")  
  
 Quando a compilação instrumentada do seu aplicativo for concluída, o aplicativo é iniciado automaticamente.  
  
 Se todos os erros ou avisos ocorrem durante a compilação, corrija\-os e, em seguida, escolha **reinicie Build** reinicie a compilação instrumentada.  
  
 Quando seu aplicativo é iniciado, você pode usar o **Iniciar treinamento** e **Pausar treinamento** links na **treinamento** seção para controlar quando as informações de criação de perfil é registrada.  Você pode usar o **aplicativo parar** e **Iniciar aplicativo** links para interromper e reiniciar o aplicativo.  
  
 ![PGO training page](../Image/PGOFig4Training.PNG "PGOFig4Training")  
  
 Durante o treinamento passam por seus cenários de usuário para capturar as informações de criação de perfil que o plug\-in PGO precisa para otimizar o código.  Quando você tiver concluído o treinamento, feche o aplicativo ou escolha o **aplicativo parar** link.  Escolha o **Analisar** botão para iniciar a etapa de análise.  
  
 Quando a análise for concluída, o **análise** seção mostra um relatório das informações de criação de perfil que foram capturados durante a fase de treinamento do cenário do usuário.  Você pode usar esse relatório para examinar seu aplicativo chamado mais e gasto mais tempo em que as funções.  O plug\-in PGO usa as informações para determinar qual aplicativo funciona para otimizar a velocidade e para otimizar o tamanho.  O plug\-in PGO configura otimizações de compilação para criar o aplicativo menor, mais rápido para os cenários de usuário que você registrou durante o treinamento.  
  
 ![PGO analysis page](../../build/reference/media/pgofig5analyze.png "PGOFig5Analyze")  
  
 Se o treinamento capturadas as informações esperadas de criação de perfil, você poderá escolher **Salvar alterações** para salvar os dados de perfil analisado em seu projeto para otimizar nas versões futuras.  Para descartar os dados de perfil e começar o treinamento desde o início, escolha **Refazer treinamento**.  
  
 O arquivo de dados de perfil é salvo em seu projeto em um **dados de treinamento PGO** pasta.  Esses dados são usados para controlar as configurações de otimização do compilador compilação em seu aplicativo.  
  
 ![PGO data file in Solution Explorer](../../build/reference/media/pgofig6data.png "PGOFig6Data")  
  
 Após a análise, o plug\-in PGO define opções de compilação no seu projeto para usar os dados de perfil seletivamente otimizar seu aplicativo durante a compilação.  Você pode continuar a modificar e crie seu aplicativo com os mesmos dados de perfil.  Quando o aplicativo é compilado, a saída da compilação informa quantas funções e instruções foram otimizadas usando dados de perfil.  
  
 ![PGO output diagnostics](../../build/reference/media/pgofig7diagnostics.png "PGOFig7Diagnostics")  
  
 Se você fizer alterações significativas de código durante o desenvolvimento, você terá que treinar novamente seu aplicativo para obter as melhores otimizações.  É recomendável que você treinar novamente seu aplicativo quando a saída de compilação relata que menos de 80 por cento de funções ou instruções foram otimizados usando dados de perfil.