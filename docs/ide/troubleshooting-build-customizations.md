---
title: "Solucionando problemas de personaliza&#231;&#245;es da compila&#231;&#227;o | Microsoft Docs"
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
helpviewer_keywords: 
  - "eventos de compilação [C++], solucionando problemas"
  - "etapas de compilação [C++], solucionando problemas"
  - "compilações [C++], compilar eventos"
  - "compilações [C++], solucionando problemas"
  - "etapas de compilação personalizada [C++], solucionando problemas"
  - "eventos [C++], compilar"
  - "solucionando problemas [C++], compilações"
ms.assetid: e4ceb177-fbee-4ed3-a7d7-80f0d78c1d07
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Solucionando problemas de personaliza&#231;&#245;es da compila&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se sua criação personalizado ou eliminar os eventos não está se comportando como você espera, há várias coisas que você pode fazer para tentar entender o que vai incorreto.  
  
-   Verifique se os arquivos das etapas personalizados de compilação para gerenciar a correspondência os arquivos que você declara como saída.  
  
-   Se suas etapas personalizados de compilação gerenciem qualquer arquivo que não seja entradas ou dependências de outros criam etapas \(personalizado ou não\), certifique\-se de que esses arquivos são adicionados ao seu projeto.  E verifique se as ferramentas que consomem esses arquivos são executados depois que a etapa de criação personalizado.  
  
-   Para exibir o que a etapa de criação personalizado está executando a verdade, adicione `@echo on` como o primeiro comando.  Os eventos de compilação e as etapas de compilação estão colocados em um arquivo .bat e em uma execução temporários quando o projeto é criado.  Em virtude disso, você pode adicionar erros que verifica a seus eventos de criação ou comandos da etapa de compilação.  
  
-   Examine o logon de compilação o diretório de arquivos intermediários para ver o que executou de fato.  O caminho e o nome do log de compilação são representados pela expressão macro de **MSBuild** , **$\(IntDir\)\\$\(MSBuildProjectName\).log**.  
  
-   Modificar suas configurações de projeto para coletar mais do que a quantidade de informações padrão no log de compilação.  No menu de **Ferramentas** , clique em **Opções**.  Na caixa de diálogo de **Opções** , clique no nó de **Projetos e Soluções** e clique no nó de **Compilar e executar** .  Em seguida, na caixa de **Detalhamento do arquivo de log de compilação do projeto no MSBuild** , clique em **Detalhado**.  
  
-   Verifique os valores de todas as macros de nome de arquivo ou diretório em uso.  Você pode ecoar macros individualmente, ou você pode adicionar `copy %0 command.bat` ao início da etapa de criação personalizado, que deve copiar os comandos personalizadas da etapa da criação command.bat com todos os macros expandidos.  
  
-   Etapas personalizados de compilação da execução e eventos de compilação individualmente para verificar seu comportamento.  
  
## Consulte também  
 [Noções básicas de etapas e eventos de compilação personalizados](../ide/understanding-custom-build-steps-and-build-events.md)