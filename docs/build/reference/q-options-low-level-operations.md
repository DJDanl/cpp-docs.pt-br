---
title: /Q Opções (operações de nível baixo)
ms.date: 01/23/2018
f1_keywords:
- /q
helpviewer_keywords:
- Q compiler option [C++]
- -Q compiler option [C++]
- /Q compiler option [C++]
ms.openlocfilehash: 6348226aa38d1f2eefdf9e19e27c4c87bd2f0812
ms.sourcegitcommit: effb516760c0f956c6308eeded48851accc96b92
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70927664"
---
# <a name="q-options-low-level-operations"></a>/Q Opções (operações de nível baixo)

Você pode usar as opções do compilador **/q** para executar as seguintes operações de compilador de nível baixo:

- [/Qfast_transcendentals (Force Fast Transcendentals)](qfast-transcendentals-force-fast-transcendentals.md): Gera transcendentais rápidos.

- [/QIfist (suprimir _ftol)](qifist-suppress-ftol.md): Suprime `_ftol` quando uma conversão de um tipo de ponto flutuante para um tipo inteiro é necessária (somente x86).

- [/Qimprecise_fwaits (remover fwaits dentro de blocos try)](qimprecise-fwaits-remove-fwaits-inside-try-blocks.md): Remove comandos `fwait` dentro de blocos `try`.

- [/Qpar (auto-paralelizador automático)](qpar-auto-parallelizer.md): Habilita a paralelização automática de loops que são marcados com a diretiva [loop de #pragma ()](../../preprocessor/loop.md) .

- [/Qpar-Report (nível de relatório do paralelizador automático automático)](qpar-report-auto-parallelizer-reporting-level.md): Habilita os níveis de relatório para paralelização automática.

- [/Qsafe_fp_loads](qsafe-fp-loads.md): Suprime otimizações para cargas de registro de ponto flutuante e para movimentações entre os registros de memória e de MMX.

- [/Qspectre](qspectre.md): Gera instruções para atenuar determinadas vulnerabilidades de segurança do Spectre.

- [/Qvec-Report (nível de relatório do Vetorizador automático automático)](qvec-report-auto-vectorizer-reporting-level.md): Habilita níveis de relatório para vetorização automática.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
