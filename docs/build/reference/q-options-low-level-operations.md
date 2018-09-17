---
title: Opções -Q (operações de nível baixo) | Microsoft Docs
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
ms.openlocfilehash: 15854333a9f26f87d20f7819327e68050ab37bf6
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45717764"
---
# <a name="q-options-low-level-operations"></a>/Q Opções (operações de nível baixo)

Você pode usar o **/Q** opções do compilador para executar as seguintes operações de nível baixo de compilador:

- [/Qfast_transcendentals (forçar transcendentais rápidos)](../../build/reference/qfast-transcendentals-force-fast-transcendentals.md): gera transcendentais rápidos.

- [/Qifist (Suprimir ftol)](../../build/reference/qifist-suppress-ftol.md): suprime `_ftol` quando uma conversão de um tipo de ponto flutuante em um tipo inteiro é necessária (somente x86).

- [/Qimprecise_fwaits (remover fwaits dentro de blocos Try)](../../build/reference/qimprecise-fwaits-remove-fwaits-inside-try-blocks.md): remove `fwait` comandos dentro `try` blocos.

- [/Qpar (Paralelizador)](../../build/reference/qpar-auto-parallelizer.md): habilita a paralelização automática de loops que são marcados com o [#pragma loop()&lt;3](../../preprocessor/loop.md) diretiva.

- [/Qpar-Report (nível de relatórios do Paralelizador automático)](../../build/reference/qpar-report-auto-parallelizer-reporting-level.md): habilita níveis de relatório para paralelização automática.

- [/Qsafe_fp_loads](../../build/reference/qsafe-fp-loads.md): suprime otimizações de registro de ponto flutuante carrega e para movimentações entre a memória e MMX registra.

- [/Qspectre](../../build/reference/qspectre.md): gera instruções para atenuar as vulnerabilidades de segurança determinadas espectro.

- [/Qvec-Report (nível de relatórios do Vetorizador automático)](../../build/reference/qvec-report-auto-vectorizer-reporting-level.md): habilita níveis de relatório para vetorização automática.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)
