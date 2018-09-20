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
ms.openlocfilehash: 4ce963d312d145e26567a5902f32e45735eb1d89
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46438412"
---
# <a name="1-introduction"></a>1. Introdução

Este documento especifica uma coleção de variáveis de ambiente que podem ser usadas para especificar paralelismo de memória compartilhada em programas C e C++, funções de biblioteca e diretivas de compilador. A funcionalidade descrita neste documento é conhecida coletivamente como o *OpenMP Interface de programa de aplicativo C/C++ (API)*. O objetivo dessa especificação é fornecer um modelo de programação paralela, que permite que um programa como portáteis entre arquiteturas de memória compartilhada de diferentes fornecedores. A API de C/C++ do OpenMP terão suporte por compiladores de vários fornecedores. Para obter mais informações sobre o OpenMP, incluindo o *Interface de programa de aplicativo do OpenMP Fortran*, podem ser encontradas no seguinte site da web:

[http://www.openmp.org](http://www.openmp.org)

As diretivas, funções de biblioteca e variáveis de ambiente definidas neste documento permitirá que os usuários criar e gerenciar programas paralelos enquanto permite a portabilidade. As diretivas de estendem o C e modelo de programação sequencial em C++ com um único programa de várias construções de dados (SPMD), construções de compartilhamento de trabalho e construções de sincronização e eles fornecem suporte para o compartilhamento e a privatização de dados. Compiladores que dão suporte a OpenMP C e C++ API inclui uma opção de linha de comando para o compilador que ativa e permite que a interpretação de todas as diretivas de compilador OpenMP.