---
title: "srand | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "srand"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-utility-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "srand"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "números, pseudoaleatórios"
  - "números, aleatório"
  - "números pseudoaleatórios"
  - "números aleatórios, gerando"
  - "ponto inicial aleatório"
  - "ponto inicial aleatório, configuração"
  - "Função srand"
  - "pontos iniciais"
  - "pontos iniciais, definindo aleatório"
ms.assetid: 7bf56dc5-5692-4182-a3c1-18af98d2dd1a
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# srand
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define o valor inicial de semente para o gerador de número pseudoaleatório.  
  
## Sintaxe  
  
```  
void srand(  
   unsigned int seed   
);  
```  
  
#### Parâmetros  
 `seed`  
 Semente para a geração de número pseudoaleatório  
  
## Comentários  
 A função de `srand` define o ponto de partida para gerar uma série de inteiros pseudoaleatório no thread atual.  Para reinicializar o gerador para criar a mesma sequência de resultados, chame a função de `srand` e use o mesmo argumento de `seed` novamente.  Qualquer outro valor para `seed` define o gerador a um ponto de partida diferente na sequência pseudoaleatório.  `rand` recupera os números pseudoaleatório que são gerados.  Chamada `rand` antes de qualquer chamada para gerar `srand` a mesma sequência de chamar `srand` com `seed` passada como 1.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`srand`|\<stdlib.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
 Consulte o exemplo de [margem](../Topic/rand.md).  
  
## Equivalência do .NET Framework  
 [Classe de System::Random](https://msdn.microsoft.com/en-us/library/system.random.aspx)  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [rand](../Topic/rand.md)