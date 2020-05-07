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

Durante o desenvolvimento, normalmente você criará e testará com uma compilação de depuração do seu projeto. Se você criar seu aplicativo para uma compilação de versão, poderá obter uma violação de acesso.

A lista a seguir mostra as principais diferenças entre uma compilação de depuração e uma versão (não depurar). Há outras diferenças, mas a seguir estão as principais diferenças que poderiam fazer com que um aplicativo falhasse em uma compilação de versão quando ela funcionasse em uma compilação de depuração.

- [Layout do heap](#_core_heap_layout)

- [Compilação](#_core_compilation)

- [Suporte a ponteiro](#_core_pointer_support)

- [Otimizações](#_core_optimizations)

Consulte a opção de compilador [/gz (versão catch-Build Errors in Debug)](reference/gz-enable-stack-frame-run-time-error-checking.md) para obter informações sobre como detectar erros de compilação de versão em compilações de depuração.

## <a name="heap-layout"></a><a name="_core_heap_layout"></a>Layout do heap

O layout de heap será a causa de cerca de 90% dos problemas aparentes quando um aplicativo funciona em depuração, mas não em versão.

Ao compilar seu projeto para depuração, você está usando o alocador de memória de depuração. Isso significa que todas as alocações de memória têm bytes de proteção colocados em relação a elas. Esses bytes de proteção detectam uma substituição de memória. Como o layout de heap é diferente entre versões de versão e de depuração, uma substituição de memória pode não criar problemas em uma compilação de depuração, mas pode ter efeitos catastróficos em uma compilação de versão.

Para obter mais informações, consulte [verificar a substituição de memória](checking-for-memory-overwrites.md) e [usar a compilação de depuração para verificar a substituição de memória](using-the-debug-build-to-check-for-memory-overwrite.md).

## <a name="compilation"></a><a name="_core_compilation"></a>Ocorrida

Muitas das macros do MFC e grande parte da implementação do MFC são alteradas quando você cria para o lançamento. Em particular, a macro ASSERT é avaliada como Nothing em uma compilação de versão, portanto nenhum código encontrado em ASSERTs será executado. Para obter mais informações, consulte [examinar instruções Assert](using-verify-instead-of-assert.md).

Algumas funções são embutidas para aumentar a velocidade na compilação da versão. Otimizações geralmente são ativadas em uma compilação de versão. Um alocador de memória diferente também está sendo usado.

## <a name="pointer-support"></a><a name="_core_pointer_support"></a>Suporte a ponteiro

A falta de informações de depuração remove o preenchimento do seu aplicativo. Em uma compilação de versão, os ponteiros isolados têm uma chance maior de apontar para a memória não inicializada em vez de apontar para informações de depuração.

## <a name="optimizations"></a><a name="_core_optimizations"></a>Otimizações

Dependendo da natureza de determinados segmentos de código, o compilador de otimização pode gerar código inesperado. Essa é a causa menos provável de problemas de Build de liberação, mas isso ocorre ocasionalmente. Para obter uma solução, consulte [otimizando seu código](optimizing-your-code.md).

## <a name="see-also"></a>Confira também

[Builds de versão](release-builds.md)<br/>
[Corrigindo problemas de compilação da versão](fixing-release-build-problems.md)
