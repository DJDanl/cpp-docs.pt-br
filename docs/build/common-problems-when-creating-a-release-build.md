---
title: Problemas comuns durante a criação de uma compilação de versão
ms.date: 11/04/2016
helpviewer_keywords:
- unexpected code generation
- debugging [MFC], release builds
- release builds, troubleshooting
- stray pointers
- debug builds, difference from release builds
- MFC [C++], release builds
- heap layout problems
- pointers, stray
- release builds, building applications
- debug memory allocator
- optimization [C++], compiler
- projects [C++], debug configuration
- troubleshooting release builds
- memory [C++], overwrites
ms.assetid: 73cbc1f9-3e33-472d-9880-39a8e9977b95
ms.openlocfilehash: 9bd1cafe40417872d42f2e9e1427e5f2eccad7a7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328861"
---
# <a name="common-problems-when-creating-a-release-build"></a>Problemas comuns durante a criação de uma compilação de versão

Durante o desenvolvimento, você geralmente construirá e testará com uma compilação de depuração do seu projeto. Se você construir seu aplicativo para uma compilação de liberação, você pode obter uma violação de acesso.

A lista abaixo mostra as principais diferenças entre uma compilação de depuração e uma versão (não depuração). Existem outras diferenças, mas a seguir estão as principais diferenças que fariam com que um aplicativo falhasse em uma compilação de versão quando funcionasse em uma compilação de depuração.

- [Layout de Pilha](#_core_heap_layout)

- [Compilação](#_core_compilation)

- [Suporte ao ponteiro](#_core_pointer_support)

- [Otimizações](#_core_optimizations)

Consulte a opção [compilador /GZ (Catch Release-Build Errors in Debug Build)](reference/gz-enable-stack-frame-run-time-error-checking.md) para obter informações sobre como capturar erros de compilação de release em compilações de depuração.

## <a name="heap-layout"></a><a name="_core_heap_layout"></a>Layout de Pilha

O layout do heap será a causa de cerca de noventa por cento dos problemas aparentes quando um aplicativo funciona em depuração, mas não em lançamento.

Quando você constrói seu projeto para depurar, você está usando o alocador de memória depuração. Isso significa que todas as alocações de memória têm bytes de guarda colocados ao seu redor. Estes bytes de guarda detectam uma sobregravação de memória. Como o layout heap é diferente entre versões de liberação e depuração, uma sobregravação de memória pode não criar problemas em uma compilação de depuração, mas pode ter efeitos catastróficos em uma compilação de versão.

Para obter mais informações, [consulte Verificar a sobregravação de memória](checking-for-memory-overwrites.md) e usar a [compilação de depuração para verificar a sobregravação de memória](using-the-debug-build-to-check-for-memory-overwrite.md).

## <a name="compilation"></a><a name="_core_compilation"></a>Compilação

Muitas das macros MFC e grande parte da implementação do MFC mudam quando você constrói para lançamento. Em particular, a macro ASSERT não avalia nada em uma compilação de versão, de modo que nenhum código encontrado em ASSERTs será executado. Para obter mais informações, consulte [Examine as declarações da ASSERT](using-verify-instead-of-assert.md).

Algumas funções são forradas para aumentar a velocidade na compilação de liberação. As otimizações são geralmente ligadas em uma compilação de versão. Um localizador de memória diferente também está sendo usado.

## <a name="pointer-support"></a><a name="_core_pointer_support"></a>Suporte ao ponteiro

A falta de informações de depuração remove o preenchimento do seu aplicativo. Em uma compilação de versão, ponteiros perdidos têm uma maior chance de apontar para memória não inicializada em vez de apontar para informações de depuração.

## <a name="optimizations"></a><a name="_core_optimizations"></a>Otimizações

Dependendo da natureza de certos segmentos de código, o compilador otimizador pode gerar código sumário. Esta é a causa menos provável de problemas de construção de liberação, mas surge de vez em quando. Para obter uma solução, consulte [Otimizando seu código](optimizing-your-code.md).

## <a name="see-also"></a>Confira também

[Builds de versão](release-builds.md)<br/>
[Corrigindo problemas de compilação da versão](fixing-release-build-problems.md)
