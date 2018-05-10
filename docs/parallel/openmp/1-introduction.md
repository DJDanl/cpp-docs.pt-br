---
title: 1. Introdução | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: c42e72bc-0e31-4b1c-b670-cd82673c0c5a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 883af9cb48a0fb13dbb9a758d6f8174096d4c0c3
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="1-introduction"></a>1. Introdução
Este documento especifica uma coleção de variáveis de ambiente que podem ser usados para especificar paralelismo de memória compartilhada em programas C e C++, funções de biblioteca e diretivas de compilador. A funcionalidade descrita neste documento é coletivamente conhecida como o *OpenMP Interface de programa de aplicativo C/C++ (API)*. O objetivo dessa especificação é fornecer um modelo de programação paralela que permite que um programa ser portátil entre arquiteturas de memória compartilhada de fornecedores diferentes. A API do C/C++ OpenMP terão suporte por compiladores de vários fornecedores. Para obter mais informações sobre OpenMP, incluindo o *OpenMP Interface de programação de aplicativo de Fortran*, podem ser encontradas no seguinte site:  
  
 [http://www.openmp.org](http://www.openmp.org)  
  
 Diretivas, biblioteca de funções e variáveis de ambiente definidas neste documento permitirá que os usuários criem e gerenciem programas paralelos enquanto permite a portabilidade. As diretivas de estendem o C e modelo de programação sequencial do C++ com um único programa de várias construções de dados (SPMD), construções de compartilhamento de trabalho e construções de sincronização e eles fornecem suporte para o compartilhamento e a privatização de dados. Compiladores que dão suporte a OpenMP C e C++ API inclui uma opção de linha de comando para o compilador que ativa e permite a interpretação de todas as diretivas de compilador OpenMP.