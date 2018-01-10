---
title: "1. Introdução | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: c42e72bc-0e31-4b1c-b670-cd82673c0c5a
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f850e236ebfd056da93700df06ec830e5a573284
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="1-introduction"></a>1. Introdução
Este documento especifica uma coleção de variáveis de ambiente que podem ser usados para especificar paralelismo de memória compartilhada em programas C e C++, funções de biblioteca e diretivas de compilador. A funcionalidade descrita neste documento é coletivamente conhecida como o *OpenMP Interface de programa de aplicativo C/C++ (API)*. O objetivo dessa especificação é fornecer um modelo de programação paralela que permite que um programa ser portátil entre arquiteturas de memória compartilhada de fornecedores diferentes. A API do C/C++ OpenMP terão suporte por compiladores de vários fornecedores. Para obter mais informações sobre OpenMP, incluindo o *OpenMP Interface de programação de aplicativo de Fortran*, podem ser encontradas no seguinte site:  
  
 [http://www.OpenMP.org](http://www.openmp.org)  
  
 Diretivas, biblioteca de funções e variáveis de ambiente definidas neste documento permitirá que os usuários criem e gerenciem programas paralelos enquanto permite a portabilidade. As diretivas de estendem o C e modelo de programação sequencial do C++ com um único programa de várias construções de dados (SPMD), construções de compartilhamento de trabalho e construções de sincronização e eles fornecem suporte para o compartilhamento e a privatização de dados. Compiladores que dão suporte a OpenMP C e C++ API inclui uma opção de linha de comando para o compilador que ativa e permite a interpretação de todas as diretivas de compilador OpenMP.