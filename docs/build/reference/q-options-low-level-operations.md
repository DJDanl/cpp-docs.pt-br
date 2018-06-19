---
title: -Q opções (operações de nível baixo) | Microsoft Docs
ms.custom: ''
ms.date: 1/23/2018
ms.technology:
- cpp-tools
ms.topic: reference
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
ms.workload:
- cplusplus
ms.openlocfilehash: c8a18c5d790cf21e8eb130a2b2baa152e20d79a1
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32375029"
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
