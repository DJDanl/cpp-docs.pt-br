---
title: "-Q opções (operações de nível baixo) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /q
dev_langs: C++
helpviewer_keywords:
- Q compiler option [C++]
- -Q compiler option [C++]
- /Q compiler option [C++]
ms.assetid: 9fa738b9-630a-4bde-bc87-bdfa30552be4
caps.latest.revision: "24"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d970c2de5e34840ab2ed77f229c329db3c6f72fd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="q-options-low-level-operations"></a>/Q Opções (operações de nível baixo)
Você pode usar o **/Q** opções do compilador para executar as seguintes operações de nível inferior do compilador:  
  
-   [/Qfast_transcendentals (forçar transcendentais rápidos)](../../build/reference/qfast-transcendentals-force-fast-transcendentals.md): gera transcendentais rápidos.  
  
-   [/Qifist (Suprimir ftol)](../../build/reference/qifist-suppress-ftol.md): suprime `_ftol` quando uma conversão de um tipo de ponto flutuante para um tipo inteiro é necessária (somente x86).  
  
-   [/Qimprecise_fwaits (remover fwaits dentro de blocos Try)](../../build/reference/qimprecise-fwaits-remove-fwaits-inside-try-blocks.md): remove `fwait` comandos dentro de `try` blocos.  
  
-   [/Qpar (Paralelizador automático)](../../build/reference/qpar-auto-parallelizer.md): habilita a paralelização de loops que são marcados com o [#pragma loop()](../../preprocessor/loop.md) diretiva.  
  
-   [/Qpar-Report (nível de emissão de relatórios do Paralelizador automático)](../../build/reference/qpar-report-auto-parallelizer-reporting-level.md): habilita níveis para paralelização de relatório.  
  
-   [/Qsafe_fp_loads](../../build/reference/qsafe-fp-loads.md): suprime otimizações para registro de ponto flutuante carrega e para movimentações entre memória e MMX registra.  
  
-   [/Qvec-Report (nível de emissão de relatórios do Vetorizador automático)](../../build/reference/qvec-report-auto-vectorizer-reporting-level.md): permite que os níveis de vetorização automática de relatório.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)