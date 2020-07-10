---
title: /O opções (otimizar código)
description: As opções de compilador MSVC/O especificam as otimizações do compilador a serem usadas.
ms.date: 07/08/2020
f1_keywords:
- VC.Project.VCCLCompilerTool.Optimization
- /o
- VC.Project.VCCLWCECompilerTool.Optimization
helpviewer_keywords:
- performance, cle.exe compiler
- cl.exe compiler, performance
ms.assetid: 77997af9-5555-4b3d-aa57-6615b27d4d5d
ms.openlocfilehash: 36ef582787a3ec2d7aee1e589c70b48712d9d552
ms.sourcegitcommit: 80c8a512b361bd84e38958beb1a1bf6db7434021
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/09/2020
ms.locfileid: "86180871"
---
# <a name="o-options-optimize-code"></a>`/O`opções (otimizar código)

As **`/O`** opções controlam várias otimizações que ajudam a criar código para velocidade máxima ou tamanho mínimo.

- [`/O1`](o1-o2-minimize-size-maximize-speed.md)define uma combinação de otimizações que geram o código de tamanho mínimo.

- [`/O2`](o1-o2-minimize-size-maximize-speed.md)define uma combinação de otimizações que otimiza o código para a velocidade máxima.

- [`/Ob`](ob-inline-function-expansion.md)controla a expansão da função embutida.

- [`/Od`](od-disable-debug.md)desabilita a otimização para acelerar a compilação e simplificar a depuração.

- [`/Og`](og-global-optimizations.md)(preterido) habilita otimizações globais.

- [`/Oi`](oi-generate-intrinsic-functions.md)gera funções intrínsecas para chamadas de função apropriadas.

- [`/Os`](os-ot-favor-small-code-favor-fast-code.md)informa o compilador para favorecer otimizações de tamanho em otimizações para velocidade.

- [`/Ot`](os-ot-favor-small-code-favor-fast-code.md)(uma configuração padrão) informa ao compilador para favorecer otimizações para agilizar as otimizações de tamanho.

- [`/Ox`](ox-full-optimization.md)é uma opção de combinação que seleciona várias das otimizações com ênfase na velocidade. **`/Ox`** é um subconjunto estrito das **`/O2`** otimizações.

- [`/Oy`](oy-frame-pointer-omission.md)suprime a criação de ponteiros de quadro na pilha de chamadas para chamadas de função mais rápidas.

## <a name="remarks"></a>Comentários

Você pode combinar várias **`/O`** opções em uma única instrução de opção. Por exemplo, **`/Odi`** é o mesmo que **`/Od /Oi`** . Determinadas opções são mutuamente exclusivas e causam um erro de compilador se usadas em conjunto. Para obter mais informações, consulte as **`/O`** opções individuais.

## <a name="see-also"></a>Veja também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
