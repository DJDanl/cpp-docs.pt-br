---
title: "Erro fatal U1035 (NMAKE) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "U1035"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "U1035"
ms.assetid: 68f0cc59-007e-4109-ac30-7ac4ac447e6d
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal U1035 (NMAKE)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

erro de sintaxe: esperado “: ” ou “\=” separador  
  
 Dois\-pontos \(**:**\) ou um sinal de igualdade \(**\=**\) era esperado.  
  
### Para corrigir verificando as seguintes causas possíveis  
  
1.  Dois\-pontos não seguiu um destino.  
  
2.  Dois\-pontos e nenhum espaço \(como:\) e um destino de uma única letra.  NMAKE interpretou\-o como uma especificação da unidade.  
  
3.  Dois\-pontos não seguiu uma regra de inferência.  
  
4.  Uma definição macro não foi seguido por um sinal de igualdade.  
  
5.  Um caractere seguido uma barra invertida \(**\\**\) que esteve usado para retomar um comando em uma nova linha.  
  
6.  Uma cadeia de caracteres que apareceu não seguisse nenhuma regra a sintaxe de NMAKE.  
  
7.  O makefile foi formatado por um processador de textos.