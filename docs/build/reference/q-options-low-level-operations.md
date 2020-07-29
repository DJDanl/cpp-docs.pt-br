---
title: /Q Opções (operações de nível baixo)
ms.date: 01/08/2020
f1_keywords:
- /q
helpviewer_keywords:
- Q compiler option [C++]
- -Q compiler option [C++]
- /Q compiler option [C++]
ms.openlocfilehash: f5342071cef76bcc736f128c344279898a61c462
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231488"
---
# <a name="q-options-low-level-operations"></a>/Q Opções (operações de nível baixo)

Você pode usar as opções do compilador **/q** para executar as seguintes operações de compilador de nível baixo:

- [/Qfast_transcendentals (Force Fast Transcendentals)](qfast-transcendentals-force-fast-transcendentals.md): gera transcendentals rápido.

- [/QIfist (suprimir _ftol)](qifist-suppress-ftol.md): suprime `_ftol` quando uma conversão de um tipo de ponto flutuante para um tipo inteiro é necessária (somente x86).

- [/Qimprecise_fwaits (remover fwaits dentro de blocos try)](qimprecise-fwaits-remove-fwaits-inside-try-blocks.md): Remove `fwait` comandos dentro de **`try`** blocos.

- [/QIntel-JCC-Erratum](qintel-jcc-erratum.md): reduz o impacto no desempenho causado pela atualização de microcódigo da Errata do código condicional do Intel (JCC).

- [/Qpar (auto-paralelizador automático)](qpar-auto-parallelizer.md): habilita a paralelização automática de loops que são marcados com a diretiva [loop de #pragma ()](../../preprocessor/loop.md) .

- [/Qpar-Report (nível de relatório do paralelizador automático automático)](qpar-report-auto-parallelizer-reporting-level.md): habilita os níveis de relatório para a paralelização automática.

- [/Qsafe_fp_loads](qsafe-fp-loads.md): suprime otimizações para cargas de registro de ponto flutuante e para movimentações entre registros de memória e de MMX.

- [/Qspectre](qspectre.md): gera instruções para atenuar determinadas vulnerabilidades de segurança do Spectre.

- [/Qspectre-Load](qspectre-load.md): gera instruções para mitigar as vulnerabilidades de segurança do Spectre com base em cargas.

- [/Qspectre-Load-CF](qspectre-load-cf.md): gera instruções para mitigar as vulnerabilidades de segurança do Spectre com base nas instruções de fluxo de controle que carregam.

- [/Qvec-Report (nível de relatório do Vetorizador automático automático)](qvec-report-auto-vectorizer-reporting-level.md): habilita os níveis de relatório para a vetorização automática.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
