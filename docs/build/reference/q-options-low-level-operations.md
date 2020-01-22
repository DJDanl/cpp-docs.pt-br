---
title: /Q Opções (operações de nível baixo)
ms.date: 01/08/2020
f1_keywords:
- /q
helpviewer_keywords:
- Q compiler option [C++]
- -Q compiler option [C++]
- /Q compiler option [C++]
ms.openlocfilehash: 9dd3675f200be4f0ec66620bcf3cf05706991b66
ms.sourcegitcommit: a930a9b47bd95599265d6ba83bb87e46ae748949
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/22/2020
ms.locfileid: "76518160"
---
# <a name="q-options-low-level-operations"></a>/Q Opções (operações de nível baixo)

Você pode usar as opções do compilador **/q** para executar as seguintes operações de compilador de nível baixo:

- [/Qfast_transcendentals (Force Fast Transcendentals)](qfast-transcendentals-force-fast-transcendentals.md): gera transcendentals rápido.

- [/QIfist (suprimir _ftol)](qifist-suppress-ftol.md): suprime `_ftol` quando uma conversão de um tipo de ponto flutuante para um tipo inteiro é necessária (somente x86).

- [/Qimprecise_fwaits (remover fwaits dentro de blocos try)](qimprecise-fwaits-remove-fwaits-inside-try-blocks.md): Remove `fwait` comandos dentro de blocos de `try`.

- [/QIntel-JCC-Erratum](qintel-jcc-erratum.md): reduz o impacto no desempenho causado pela atualização de microcódigo da Errata do código condicional do Intel (JCC).

- [/Qpar (auto-paralelizador automático)](qpar-auto-parallelizer.md): habilita a paralelização automática de loops que são marcados com a diretiva [loop de #pragma ()](../../preprocessor/loop.md) .

- [/Qpar-Report (nível de relatório do paralelizador automático automático)](qpar-report-auto-parallelizer-reporting-level.md): habilita os níveis de relatório para a paralelização automática.

- [/Qsafe_fp_loads](qsafe-fp-loads.md): suprime otimizações para cargas de registro de ponto flutuante e para movimentações entre registros de memória e de MMX.

- [/Qspectre](qspectre.md): gera instruções para atenuar determinadas vulnerabilidades de segurança do Spectre.

- [/Qvec-Report (nível de relatório do Vetorizador automático automático)](qvec-report-auto-vectorizer-reporting-level.md): habilita os níveis de relatório para a vetorização automática.

## <a name="see-also"></a>Veja também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
