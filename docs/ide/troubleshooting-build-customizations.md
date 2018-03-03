---
title: "Solução de problemas de compilação personalizações | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- build events [C++], troubleshooting
- builds [C++], build events
- troubleshooting [C++], builds
- build steps [C++], troubleshooting
- events [C++], build
- builds [C++], troubleshooting
- custom build steps [C++], troubleshooting
ms.assetid: e4ceb177-fbee-4ed3-a7d7-80f0d78c1d07
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5fa3b2d3910a71d189f5177e13fbd91930e15ee8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="troubleshooting-build-customizations"></a>Solucionando problemas de personalizações do build
Se as etapas de compilação personalizados ou eventos não estão funcionando conforme o esperado, há várias coisas que você pode fazer para tentar entender o que está errado.  
  
-   Certifique-se de que os arquivos que as etapas de compilação personalizada geram correspondem aos arquivos de que declarar saídas.  
  
-   Se as etapas de compilação personalizada geram todos os arquivos que são entradas ou dependências de outros criar etapas (personalizadas ou não), certifique-se de que esses arquivos são adicionados ao seu projeto. E certifique-se de que as ferramentas que consomem os arquivos executar após a etapa de compilação personalizada.  
  
-   Para exibir o que a etapa de compilação personalizada, na verdade, está fazendo, adicione `@echo on` como o primeiro comando. Os eventos de build e as etapas de compilação são colocadas em um arquivo temporário e executadas quando o projeto é compilado. Portanto, você pode adicionar o evento de compilação de verificação de erros ou comandos de etapa de compilação.  
  
-   Examine o log de compilação no diretório intermediário para ver o que realmente executado. O caminho e o nome do log de compilação é representado pelo **MSBuild** expressão de macro **$ (IntDir)\\. $(MSBuildProjectName) log**.  
  
-   Modificar as configurações do projeto para coletar mais do que a quantidade de informações no log de compilação padrão. No menu **Ferramentas**, clique em **Opções**. No **opções** caixa de diálogo, clique o **projetos e soluções** nó e, em seguida, clique o **compilar e executar** nó. Em seguida, no **detalhamento de arquivo de log de compilação do MSBuild projeto** , clique em **Detailed**.  
  
-   Verifique se que os valores de qualquer arquivo macros de nome ou diretório que você está usando. Você pode ecoar macros individualmente, ou você pode adicionar `copy %0 command.bat` ao início da sua etapa de compilação personalizada, que irá copiar comandos da etapa de compilação personalizada para command.bat com todas as macros expandidas.  
  
-   Executar etapas de compilação personalizada e eventos individualmente para verificar o comportamento de compilação.  
  
## <a name="see-also"></a>Consulte também  
 [Noções básicas sobre etapas e eventos compilação personalizada](../ide/understanding-custom-build-steps-and-build-events.md)