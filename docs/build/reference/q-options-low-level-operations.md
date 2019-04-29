---
title: /Q Opções (operações de nível baixo)
ms.date: 1/23/2018
f1_keywords:
- /q
helpviewer_keywords:
- Q compiler option [C++]
- -Q compiler option [C++]
- /Q compiler option [C++]
ms.openlocfilehash: 5bbb63b4f437f8aefd5c84c1c1c4bd20bdb965cb
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62319376"
---
# <a name="q-options-low-level-operations"></a>/Q Opções (operações de nível baixo)

Você pode usar o **/Q** opções do compilador para executar as seguintes operações de nível baixo de compilador:

- [/Qfast_transcendentals (forçar transcendentais rápidos)](qfast-transcendentals-force-fast-transcendentals.md): Gera transcendentais rápidos.

- [/Qifist (Suprimir ftol)](qifist-suppress-ftol.md): Suprime `_ftol` quando uma conversão de um tipo de ponto flutuante em um tipo inteiro é necessária (somente x86).

- [/Qimprecise_fwaits (remover fwaits dentro de blocos Try)](qimprecise-fwaits-remove-fwaits-inside-try-blocks.md): Remove comandos `fwait` dentro de blocos `try`.

- [/Qpar (Paralelizador)](qpar-auto-parallelizer.md): Habilita a paralelização automática de loops que são marcados com o [#pragma loop()&lt;3](../../preprocessor/loop.md) diretiva.

- [/Qpar-Report (nível de Paralelizador automático relatórios)](qpar-report-auto-parallelizer-reporting-level.md): Habilita os níveis de relatório para paralelização automática.

- [/Qsafe_fp_loads](qsafe-fp-loads.md): Suprime otimizações para cargas de registro de ponto flutuante e para movimentações entre a memória e os registros de MMX.

- [/Qspectre](qspectre.md): Gera instruções para atenuar as vulnerabilidades de segurança determinadas espectro.

- [/Qvec-Report (nível de Vetorizador automático relatórios)](qvec-report-auto-vectorizer-reporting-level.md): Habilita níveis de relatório para vetorização automática.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
