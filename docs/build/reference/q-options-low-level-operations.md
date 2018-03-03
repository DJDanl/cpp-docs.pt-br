---
title: "-Q opções (operações de nível baixo) | Microsoft Docs"
ms.custom: 
ms.date: 1/23/2018
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /q
dev_langs:
- C++
helpviewer_keywords:
- Q compiler option [C++]
- -Q compiler option [C++]
- /Q compiler option [C++]
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7636b042669c7f7b04d2bc662bcaa2fbe4bdc82a
ms.sourcegitcommit: 9a0a287d6940591523af959ebdac5affa36220da
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/25/2018
---
# <a name="q-options-low-level-operations"></a>/Q Opções (operações de nível baixo)

Você pode usar o **/Q** opções do compilador para executar as seguintes operações de nível inferior do compilador:

- [/Qfast_transcendentals (forçar transcendentais rápidos)](../../build/reference/qfast-transcendentals-force-fast-transcendentals.md): gera transcendentais rápidos.

- [/Qifist (Suprimir ftol)](../../build/reference/qifist-suppress-ftol.md): suprime `_ftol` quando uma conversão de um tipo de ponto flutuante para um tipo inteiro é necessária (somente x86).

- [/Qimprecise_fwaits (remover fwaits dentro de blocos Try)](../../build/reference/qimprecise-fwaits-remove-fwaits-inside-try-blocks.md): remove `fwait` comandos dentro de `try` blocos.

- [/Qpar (Paralelizador automático)](../../build/reference/qpar-auto-parallelizer.md): habilita a paralelização de loops que são marcados com o [#pragma loop()](../../preprocessor/loop.md) diretiva.

- [/Qpar-Report (nível de emissão de relatórios do Paralelizador automático)](../../build/reference/qpar-report-auto-parallelizer-reporting-level.md): habilita níveis para paralelização de relatório.

- [/Qsafe_fp_loads](../../build/reference/qsafe-fp-loads.md): suprime otimizações para registro de ponto flutuante carrega e para movimentações entre memória e MMX registra.

- [/ Qspectre](../../build/reference/qspectre.md): gera instruções para atenuar determinadas vulnerabilidades de segurança Spectre.

- [/Qvec-Report (nível de emissão de relatórios do Vetorizador automático)](../../build/reference/qvec-report-auto-vectorizer-reporting-level.md): permite que os níveis de vetorização automática de relatório.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)  
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)  
