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
- troubleshooting Visual C++
- troubleshooting release builds
- memory [C++], overwrites
ms.assetid: 73cbc1f9-3e33-472d-9880-39a8e9977b95
ms.openlocfilehash: 7420fd5bbdeec30e9839206803952c02b8b56421
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62273917"
---
# <a name="common-problems-when-creating-a-release-build"></a>Problemas comuns durante a criação de uma compilação de versão

Durante o desenvolvimento, você geralmente compilar e testar com um build de depuração do seu projeto. Se você, em seguida, crie seu aplicativo para um build de versão, você poderá receber uma violação de acesso.

A lista a seguir mostra as principais diferenças entre uma depuração e um build de versão (nondebug). Existem outras diferenças, mas a seguir estão as principais diferenças que faria com que um aplicativo falhar em um build de versão quando ela funciona em uma compilação de depuração.

- [Layout de heap](#_core_heap_layout)

- [Compilação](#_core_compilation)

- [Suporte de ponteiro](#_core_pointer_support)

- [otimizações](#_core_optimizations)

Consulte a [/GZ (capturar erros de Build de versão no Build de depuração)](reference/gz-enable-stack-frame-run-time-error-checking.md) erros em compilações de depuração de compilação de opção de compilador para obter informações sobre como capturar a versão.

##  <a name="_core_heap_layout"></a> Layout de heap

Layout de heap será a causa de noventa por cento dos problemas aparentes quando um aplicativo funciona na depuração, mas não a versão.

Quando você compila seu projeto para depuração, você está usando o alocador de memória de depuração. Isso significa que todas as alocações de memória tem bytes guard colocados ao redor deles. Esses bytes guard detectam uma substituição de memória. Como o layout de heap é diferente entre a versão e depuração versões, uma substituição de memória não pode criar problemas em uma compilação de depuração, mas pode ter efeitos catastróficos em um build de versão.

Para obter mais informações, consulte [verificar se há substituição de memória](checking-for-memory-overwrites.md) e [usar a depurar Build para verificação de substituição de memória](using-the-debug-build-to-check-for-memory-overwrite.md).

##  <a name="_core_compilation"></a> Compilação

Muitas das macros MFC e grande parte das alterações de implementação MFC quando você compila para liberação. Em particular, a macro ASSERT avaliada como nada na compilação de versão, portanto, nenhum código encontrado no ASSERTs será executado. Para obter mais informações, consulte [Examine instruções ASSERT](using-verify-instead-of-assert.md).

Algumas funções são embutidas para maior velocidade no build de versão. Geralmente, as otimizações estiverem ativadas na compilação de versão. Um alocador de memória diferentes também está sendo usado.

##  <a name="_core_pointer_support"></a> Suporte de ponteiro

A falta de informações de depuração remove o preenchimento do seu aplicativo. Em uma compilação de versão, os ponteiros perdidos têm uma chance maior de que aponta para a memória não inicializada em vez de apontar para informações de depuração.

##  <a name="_core_optimizations"></a> otimizações

Dependendo da natureza de determinados segmentos de código, o compilador de otimização pode gerar código inesperado. Essa é a causa menos provável dos problemas de compilação de versão, mas ele surgir na ocasião. Para uma solução, consulte [otimizando seu código](optimizing-your-code.md).

## <a name="see-also"></a>Consulte também

[Builds de versão](release-builds.md)<br/>
[Corrigindo problemas do build de versão](fixing-release-build-problems.md)
