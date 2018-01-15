---
title: "-O opções (otimizar código) | Microsoft Docs"
ms.custom: 
ms.date: 09/25/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCCLCompilerTool.Optimization
- /o
- VC.Project.VCCLWCECompilerTool.Optimization
dev_langs: C++
helpviewer_keywords:
- performance, cle.exe compiler
- cl.exe compiler, performance
ms.assetid: 77997af9-5555-4b3d-aa57-6615b27d4d5d
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b7da04384d0c4ea00c2eaaedbcf0ec770e216289
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="o-options-optimize-code"></a>/O opções (otimizar código)

O **/O** opções controlam várias otimizações que ajudarão a criar o código para velocidade máxima ou tamanho mínimo.

- [/O1](../../build/reference/o1-o2-minimize-size-maximize-speed.md) define uma combinação de otimizações que geram um código de tamanho mínimo.

- [/ O2](../../build/reference/o1-o2-minimize-size-maximize-speed.md) define uma combinação de otimizações que otimiza o código para velocidade máxima.

- [/OB](../../build/reference/ob-inline-function-expansion.md) controla a expansão de função embutida.

- [/Od](../../build/reference/od-disable-debug.md) desabilita a otimização, a fim de acelerar a compilação e a simplificar a depuração.

- [/Og](../../build/reference/og-global-optimizations.md) habilita as otimizações globais.

- [/Oi](../../build/reference/oi-generate-intrinsic-functions.md) gera funções intrínsecas para chamadas de função apropriada.

- [/Os](../../build/reference/os-ot-favor-small-code-favor-fast-code.md) informa ao compilador a favorecer otimizações para tamanho sobre otimizações para maior velocidade.

- [/OT](../../build/reference/os-ot-favor-small-code-favor-fast-code.md) (uma configuração padrão) instrui o compilador a favorecer otimizações para velocidade sobre otimizações de tamanho.

- [/OX](../../build/reference/ox-full-optimization.md) é uma opção de combinação que seleciona várias otimizações com ênfase na velocidade. É um subconjunto restrito do **/O2** otimizações.

- [/Oy](../../build/reference/oy-frame-pointer-omission.md) suprime a criação de ponteiros de quadros na pilha de chamadas para chamadas de função mais rápidas.

## <a name="remarks"></a>Comentários

Você pode combinar vários **/O** opções em uma instrução única opção. Por exemplo, **/Odi** é o mesmo que **/Oi /Od**. Algumas opções são mutuamente exclusivas e causam um erro do compilador se usados em conjunto. Consulte o indivíduo **/O** opções para obter mais informações.

## <a name="see-also"></a>Consulte também

[Opções do compilador](../../build/reference/compiler-options.md)   
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)