---
title: "/ GENPROFILE, /FASTGENPROFILE (gerar perfis instrumentada compila&#231;&#227;o) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "GENPROFILE"
  - "FASTGENPROFILE"
  - "/GENPROFILE"
  - "/FASTGENPROFILE"
helpviewer_keywords: 
  - "GENPROFILE"
  - "FASTGENPROFILE"
ms.assetid: deff5ce7-46f5-448a-b9cd-a7a83a6864c6
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# / GENPROFILE, /FASTGENPROFILE (gerar perfis instrumentada compila&#231;&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica a geração de um arquivo. PGD pelo vinculador para dar suporte a Otimização Guiada por perfil \(PGO\).  \/ GENPROFILE e \/FASTGENPROFILE usam parâmetros padrão diferentes. Use \/GENPROFILE para favorecer precisão sobre o uso de memória e velocidade durante a criação de perfil. Use \/FASTGENPROFILE para favorecer menor uso de memória e velocidade sobre a precisão.  
  
## Sintaxe  
  
```  
/{GENPROFILE|FASTGENPROFILE}[:{COUNTER32|COUNTER64|EXACT|MEMMAX=#|MEMMIN=#|NOEXACT|NOPATH|NOTRACKEH|PATH|PGD=filename|TRACKEH}]   
```  
  
## Comentários  
 COUNTER32 &#124; COUNTER64  
 Use COUNTER32 para especificar o uso de contadores de teste de 32 bits e COUNTER64 para especificar os contadores de teste de 64 bits. Quando você especificar \/GENPROFILE, o padrão é COUNTER64. Quando você especificar \/FASTGENPROFILE, o padrão é COUNTER32.  
  
 EXATO &#124; NOEXACT  
 Use exato para especificar o thread\-safe interligados incrementos para testes. NOEXACT Especifica as operações de incremento desprotegido para testes. O padrão é NOEXACT.  
  
 MEMMAX \= value, MEMMIN \= valor  
 Use MEMMAX e MEMMIN para especificar os tamanhos mínimo e máximo de reserva para dados de treinamento na memória. O valor é a quantidade de memória para reservar em bytes.  Por padrão, esses valores são determinados por uma heurística interna.  
  
 CAMINHO &#124; NOPATH  
 Use o caminho para especificar um conjunto separado de contadores PGO para cada caminho exclusivo para uma função. Use NOPATH para especificar apenas um conjunto de contadores para cada função.   Quando você especificar \/GENPROFILE, o padrão é o caminho. Quando você especificar \/FASTGENPROFILE, o padrão é NOPATH.  
  
 TRACKEH &#124; NOTRACKEH  
 Especifica se deve usar os contadores extras para manter uma contagem precisa quando as exceções são geradas durante o treinamento. Use TRACKEH para especificar os contadores extras para uma contagem exata. Use NOTRACKEH para especificar contadores únicos para o código que não use o tratamento de exceção ou que não ocorram exceções em seus cenários de treinamento.  Quando você especificar \/GENPROFILE, o padrão é TRACKEH. Quando você especificar \/FASTGENPROFILE, o padrão é NOTRACKEH.  
  
 PGD \= arquivo  
 Especifica um nome de arquivo de base para o arquivo. PGD. Por padrão, o vinculador usa o nome do arquivo de imagem executável base com uma extensão. PGD.  
  
 As opções \/GENPROFILE e \/FASTGENPROFILE informam ao vinculador para gerar o arquivo de instrumentação de criação de perfil necessário para suportar a preparação do aplicativo para a Otimização Guiada por perfil \(PGO\). As informações de criação de perfil geradas pelo aplicativo treinamento são usadas como entrada para executar otimizações de todo o programa de destino durante compilações.   Você pode definir opções adicionais para controlar vários recursos de criação de perfil de desempenho durante o treinamento do aplicativo e se baseia. Opções padrão especificadas pelo \/GENPROFILE dar resultados mais precisos, especialmente para grandes e complexos aplicativos multi\-threaded. A opção \/FASTGENPROFILE usa padrões diferentes para uma base de memória menor e um desempenho mais rápido durante o treinamento às custas da precisão.  
  
 Informações de criação de perfil é capturada quando você executar o aplicativo instrumentado depois que você criar usando \/GENPROFILE de \/FASTGENPROFILE. Essas informações são usadas pelo vinculador quando você especificar a opção \/USEPROFILE. Para obter mais informações sobre como treinar seu aplicativo e os detalhes sobre os dados coletados, consulte Otimização Guiada por perfil.  
  
 Você também deve especificar \/LTCG quando você especificar \/GENPROFILE ou \/FASTGENPROFILE.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)   
 [\/LTCG \(geração de código do tempo de vinculação\)](../../build/reference/ltcg-link-time-code-generation.md)