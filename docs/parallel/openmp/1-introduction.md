---
title: "1. Introduction | Microsoft Docs"
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
ms.assetid: c42e72bc-0e31-4b1c-b670-cd82673c0c5a
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 1. Introduction
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este documento especifica um conjunto de diretivas de compilador, funções de biblioteca e variáveis de ambiente que podem ser usadas para especificar o paralelismo de memória compartilhada em programas c e C\+\+.  A funcionalidade descrita neste documento é conhecida coletivamente como o  *Aplicativo programa Interface \(API\) do OpenMP C\/C\+\+*.  O objetivo desta especificação é fornecer um modelo de programação paralela, que permite que um programa para ser portátil em arquiteturas de memória compartilhada de diferentes fornecedores.  A API do C\/C\+\+ OpenMP será suportada por compiladores de vários fornecedores.  Obter mais informações sobre o OpenMP, incluindo o  *OpenMP Fortran Application Program Interface*, podem ser encontradas no seguinte site da web:  
  
 [http:\/\/www.OpenMP.org](http://www.openmp.org)  
  
 Diretivas, funções de biblioteca e variáveis de ambiente definidas neste documento permitirá que os usuários criem e gerenciem programas paralelos, permitindo a portabilidade.  As diretivas de estendem o c e modelo de programação seqüencial do C\+\+ com o único programa várias construções de dados \(SPMD\), construções de compartilhamento de trabalho e construções de sincronização e eles fornecem suporte para o compartilhamento e a privatização dos dados.  Compiladores que suportam o OpenMP C e C\+\+ API incluirá uma opção de linha de comando do compilador que ativa e permite que a interpretação de todas as diretivas de compilador do OpenMP.