---
title: /O opções (otimizar código)
ms.date: 09/25/2017
f1_keywords:
- VC.Project.VCCLCompilerTool.Optimization
- /o
- VC.Project.VCCLWCECompilerTool.Optimization
helpviewer_keywords:
- performance, cle.exe compiler
- cl.exe compiler, performance
ms.assetid: 77997af9-5555-4b3d-aa57-6615b27d4d5d
ms.openlocfilehash: ffd3023120f1d930a24ccef6fa297594062322df
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57816120"
---
# <a name="o-options-optimize-code"></a>/O opções (otimizar código)

O **/O** opções controlam várias otimizações que ajudam você a criar código para velocidade máxima ou tamanho mínimo.

- [/ O1](o1-o2-minimize-size-maximize-speed.md) define uma combinação de otimizações que geram código de tamanho mínimo.

- [/ O2](o1-o2-minimize-size-maximize-speed.md) define uma combinação de otimizações que otimiza o código para velocidade máxima.

- [/OB](ob-inline-function-expansion.md) controla a expansão de função embutida.

- [/Od](od-disable-debug.md) desabilita a otimização para acelerar a compilação e simplificar a depuração.

- [/Og](og-global-optimizations.md) permite otimizações globais.

- [/Oi](oi-generate-intrinsic-functions.md) gera funções intrínsecas para chamadas de função apropriada.

- [/Os](os-ot-favor-small-code-favor-fast-code.md) informa ao compilador a favorecer otimizações para tamanho sobre otimizações de velocidade.

- [/OT](os-ot-favor-small-code-favor-fast-code.md) (uma configuração padrão) instrui o compilador a favorecer as otimizações de velocidade sobre otimizações de tamanho.

- [/OX](ox-full-optimization.md) é uma opção de combinação que seleciona várias das otimizações com ênfase na velocidade. É um subconjunto estrito dos **/O2** otimizações.

- [/Oy](oy-frame-pointer-omission.md) suprime a criação de ponteiros de quadro na pilha de chamadas para chamadas de função mais rápidas.

## <a name="remarks"></a>Comentários

Você pode combinar vários **/O** opções em uma instrução única opção. Por exemplo, **/Odi** é o mesmo que **/Od /Oi**. Algumas opções são mutuamente exclusivas e causam um erro do compilador se usado em conjunto. Consulte o indivíduo **/O** opções para obter mais informações.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
