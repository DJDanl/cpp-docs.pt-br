---
title: "PogoSafeMode | Microsoft Docs"
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
  - "PogoSafeMode"
ms.assetid: 2daeeff7-44cb-417f-90eb-6b9edf658533
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# PogoSafeMode
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especificar o uso do modo rápido ou o modo de segurança para criar o perfil do aplicativo.  
  
## Sintaxe  
  
```  
PogoSafeMode  
```  
  
## Comentários  
 A Otimização Guiada por Perfil \(PGO\) tem dois modos possíveis durante a fase de criação de perfil: modo rápido e modo de segurança.  Quando a analise está no modo rápido, ela usa a declaração de **INC** para aumentar contadores de dados.  A instrução **INC** é mais rápida, mas não é thread\-safe.  Quando a analise está no modo seguro, ela usa a declaração de **LOCK INC** para aumentar contadores de dados.  A instrução **LOCK INC** tem a mesma funcionalidade da instrução **INC** e é de thread seguro, mas é mais lenta do que a instrução **INC**.  
  
 Por padrão, a análise de PGO opera no modo rápido.  `PogoSafeMode` é necessário somente se você desejar usar o modo de segurança.  
  
 Para executar a criação de perfil de PGO no modo de segurança, você deve usar a variável de ambiente `PogoSafeMode` ou a opção de vinculador **\-PogoSafeMode**, dependendo do sistema.  Se você estiver executando a criação de perfis em um computador x64, deverá usar a opção de vinculador.  Se você estiver executando a criação de perfil em um computador x86, deverá definir a variável de ambiente para qualquer valor antes de iniciar o processo de otimização.  
  
## Exemplo  
  
```  
set PogoSafeMode=1  
```  
  
## Consulte também  
 [Variáveis de ambiente para otimizações orientadas a perfil](../../build/reference/environment-variables-for-profile-guided-optimizations.md)   
 [Otimizações orientadas a perfil](../../build/reference/profile-guided-optimizations.md)