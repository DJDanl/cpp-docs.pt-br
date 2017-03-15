---
title: "VCPROFILE_ALLOC_SCALE | Microsoft Docs"
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
  - "VCPROFILE_ALLOC_SCALE"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Variável de ambiente VCPROFILE_ALLOC_SCALE"
ms.assetid: 5cb5ce27-f9b8-489b-b46c-d6e9bcab2d34
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# VCPROFILE_ALLOC_SCALE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Modifique a quantidade de memória alocada para manter os dados do perfil.  
  
## Sintaxe  
  
```  
VCPROFILE_ALLOC_SCALE=scale_value  
```  
  
#### Parâmetros  
 `scale_value`  
 O valor da escala para a quantidade de memória que você deseja cenários de teste em execução.  O padrão é 1.  
  
## Comentários  
 Em casos raros, não há memória suficiente para oferecer suporte a perfis de dados do ao executar cenários de teste.  Em casos, você pode aumentar a quantidade de memória com `VCPROFILE_ALLOC_SCALE`.  
  
 Se você receber uma mensagem de erro durante a execução do teste que indica que você não tem memória suficiente, atribua um valor maior que a `VCPROFILE_ALLOC_SCALE`, até que as execuções de teste foi concluído sem erros de falta de memória.  
  
## Exemplo  
  
```  
set VCPROFILE_ALLOC_SCALE=2  
```  
  
## Consulte também  
 [Variáveis de ambiente para otimizações orientadas a perfil](../../build/reference/environment-variables-for-profile-guided-optimizations.md)