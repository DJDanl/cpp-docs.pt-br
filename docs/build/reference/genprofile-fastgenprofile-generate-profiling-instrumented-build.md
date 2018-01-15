---
title: "-GENPROFILE, - FASTGENPROFILE (gerar a criação de perfil instrumentada compilação) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- GENPROFILE
- FASTGENPROFILE
- /GENPROFILE
- /FASTGENPROFILE
helpviewer_keywords:
- GENPROFILE
- FASTGENPROFILE
ms.assetid: deff5ce7-46f5-448a-b9cd-a7a83a6864c6
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 028b31044d035def628785969a04c27af4699f65
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="genprofile-fastgenprofile-generate-profiling-instrumented-build"></a>/GENPROFILE, /FASTGENPROFILE (gerar compilação instrumentada de criação de perfil)
Especifica a geração de um arquivo. PGD pelo vinculador para dar suporte a Otimização Guiada por perfil (PGO).  /GENPROFILE e /FASTGENPROFILE usam parâmetros padrão diferente. Use /GENPROFILE para favorecer precisão sobre velocidade e uso de memória durante a criação de perfil. Use /FASTGENPROFILE para favorecer velocidade e menor uso de memória em precisão.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/{GENPROFILE|FASTGENPROFILE}[:{COUNTER32|COUNTER64|EXACT|MEMMAX=#|MEMMIN=#|NOEXACT|NOPATH|NOTRACKEH|PATH|PGD=filename|TRACKEH}]   
```  
  
## <a name="remarks"></a>Comentários  
 COUNTER32 &#124; COUNTER64  
 Use COUNTER32 para especificar o uso de contadores de teste de 32 bits e COUNTER64 para especificar os contadores de teste de 64 bits. Quando você especificar /GENPROFILE, o padrão é COUNTER64. Quando você especificar /FASTGENPROFILE, o padrão é COUNTER32.  
  
 EXATO &#124; NOEXACT  
 Use EXACT para especificar incrementos interlocked para testes de thread-safe. NOEXACT Especifica as operações de incremento desprotegido para testes. O padrão é NOEXACT.  
  
 MEMMAX = value, MEMMIN = valor  
 Use MEMMAX e MEMMIN para especificar os tamanhos de reserva máximo e mínimo para dados de treinamento na memória. O valor é a quantidade de memória para reservar em bytes.  Por padrão, esses valores são determinados por uma heurística interna.  
  
 CAMINHO &#124; NOPATH  
 Use o caminho para especificar um conjunto separado de contadores PGO para cada caminho exclusivo para uma função. Use NOPATH para especificar apenas um conjunto de contadores para cada função.   Quando você especificar /GENPROFILE, o padrão é o caminho. Quando você especificar /FASTGENPROFILE, o padrão é NOPATH.  
  
 TRACKEH &#124; NOTRACKEH  
 Especifica se deve usar os contadores extras para manter uma contagem precisa quando as exceções são geradas durante o treinamento. Use TRACKEH para especificar contadores extras para uma contagem exata. Use NOTRACKEH para especificar contadores único para o código que não use o tratamento de exceção ou que não encontrar exceções em seus cenários de treinamento.  Quando você especificar /GENPROFILE, o padrão é TRACKEH. Quando você especificar /FASTGENPROFILE, o padrão é NOTRACKEH.  
  
 PGD = nome de arquivo  
 Especifica um nome de arquivo de base para o arquivo. PGD. Por padrão, o vinculador usa o nome do arquivo de imagem executável base com uma extensão. PGD.  
  
 As opções /GENPROFILE e /FASTGENPROFILE informam o vinculador para gerar o arquivo de instrumentação de criação de perfil necessário para dar suporte a treinamento de aplicativo para Otimização Guiada por perfil (PGO). As informações de perfil geradas pelo treinamento de aplicativo são usadas como entrada para executar destinados otimizações de programa inteiro durante compilações.   Você pode definir opções adicionais para controlar vários recursos de criação de perfil de desempenho durante o treinamento do aplicativo e cria. Opções padrão especificadas pelo /GENPROFILE dar resultados mais precisos, especialmente para aplicativos multithread grandes e complexos. A opção /FASTGENPROFILE usa padrões diferentes para uma base de memória menor e um desempenho mais rápido durante o treinamento, às custas de precisão.  
  
 Informações de criação de perfil é capturada quando você executa o aplicativo instrumentado depois que você cria usando /GENPROFILE de /FASTGENPROFILE. Essas informações são usadas pelo vinculador quando você especificar a opção /USEPROFILE. Para obter mais informações sobre como treinar seu aplicativo e os detalhes sobre os dados coletados, consulte Otimização Guiada por perfil.  
  
 Você também deve especificar /LTCG quando você especificar /GENPROFILE ou /FASTGENPROFILE.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)   
 [/LTCG (geração de código para Link-time)](../../build/reference/ltcg-link-time-code-generation.md)