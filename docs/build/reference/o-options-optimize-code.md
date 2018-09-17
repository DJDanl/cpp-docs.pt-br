---
title: -O opções (otimizar código) | Microsoft Docs
ms.custom: ''
ms.date: 09/25/2017
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLCompilerTool.Optimization
- /o
- VC.Project.VCCLWCECompilerTool.Optimization
dev_langs:
- C++
helpviewer_keywords:
- performance, cle.exe compiler
- cl.exe compiler, performance
ms.assetid: 77997af9-5555-4b3d-aa57-6615b27d4d5d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5c77fd91d63ec79fca87e11a4a02eca157eddf84
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45717529"
---
# <a name="o-options-optimize-code"></a>/O opções (otimizar código)

O **/O** opções controlam várias otimizações que ajudam você a criar código para velocidade máxima ou tamanho mínimo.

- [/ O1](../../build/reference/o1-o2-minimize-size-maximize-speed.md) define uma combinação de otimizações que geram código de tamanho mínimo.

- [/ O2](../../build/reference/o1-o2-minimize-size-maximize-speed.md) define uma combinação de otimizações que otimiza o código para velocidade máxima.

- [/OB](../../build/reference/ob-inline-function-expansion.md) controla a expansão de função embutida.

- [/Od](../../build/reference/od-disable-debug.md) desabilita a otimização para acelerar a compilação e simplificar a depuração.

- [/Og](../../build/reference/og-global-optimizations.md) permite otimizações globais.

- [/Oi](../../build/reference/oi-generate-intrinsic-functions.md) gera funções intrínsecas para chamadas de função apropriada.

- [/Os](../../build/reference/os-ot-favor-small-code-favor-fast-code.md) informa ao compilador a favorecer otimizações para tamanho sobre otimizações de velocidade.

- [/OT](../../build/reference/os-ot-favor-small-code-favor-fast-code.md) (uma configuração padrão) instrui o compilador a favorecer as otimizações de velocidade sobre otimizações de tamanho.

- [/OX](../../build/reference/ox-full-optimization.md) é uma opção de combinação que seleciona várias das otimizações com ênfase na velocidade. É um subconjunto estrito dos **/O2** otimizações.

- [/Oy](../../build/reference/oy-frame-pointer-omission.md) suprime a criação de ponteiros de quadro na pilha de chamadas para chamadas de função mais rápidas.

## <a name="remarks"></a>Comentários

Você pode combinar vários **/O** opções em uma instrução única opção. Por exemplo, **/Odi** é o mesmo que **/Od /Oi**. Algumas opções são mutuamente exclusivas e causam um erro do compilador se usado em conjunto. Consulte o indivíduo **/O** opções para obter mais informações.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)