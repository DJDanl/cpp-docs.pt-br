---
title: Problemas comuns durante a criação de uma compilação de versão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8860783a2cf9fb88b28e24e0bc16eb16c0dd5d77
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="common-problems-when-creating-a-release-build"></a>Problemas comuns durante a criação de um build de versão
Durante o desenvolvimento, você geralmente compilar e testar com uma compilação de depuração do projeto. Se você, em seguida, criar seu aplicativo para uma compilação de versão, você pode receber uma violação de acesso.  
  
 A lista a seguir mostra as principais diferenças entre uma depuração e uma compilação de versão (nondebug). Há outras diferenças, mas a seguir estão as principais diferenças que possam causar um falha do aplicativo em uma versão de compilação quando ele funciona em uma compilação de depuração.  
  
-   [Layout de heap](#_core_heap_layout)  
  
-   [Compilação](#_core_compilation)  
  
-   [Suporte de ponteiro](#_core_pointer_support)  
  
-   [Otimizações](#_core_optimizations)  
  
 Consulte o [/GZ (Catch versão-erros de compilação de depuração de compilação)](../../build/reference/gz-enable-stack-frame-run-time-error-checking.md) erros em compilações de depuração de compilação de opção de compilador para obter informações sobre como capturar a versão.  
  
##  <a name="_core_heap_layout"></a> Layout de heap  
 Layout de heap será a causa de 90 por cento dos problemas aparentes quando um aplicativo funciona em depuração, mas não a versão.  
  
 Quando você compila seu projeto para a depuração, você está usando o alocador de memória de depuração. Isso significa que todas as alocações de memória têm bytes de proteção colocados ao redor deles. Esses bytes de protetor detectam uma substituição de memória. Como o layout de heap é diferente entre a versão e depuração versões, uma substituição de memória não podem criar problemas em uma compilação de depuração, mas pode ter efeitos catastróficos em uma compilação de versão.  
  
 Para obter mais informações, consulte [verificar se há memória substituir](../../build/reference/checking-for-memory-overwrites.md) e [usar a depuração de compilação para seleção para substituir memória](../../build/reference/using-the-debug-build-to-check-for-memory-overwrite.md).  
  
##  <a name="_core_compilation"></a> Compilação  
 Muitas das macros MFC e grande parte das alterações de implementação MFC quando você cria para versão. Em particular, a macro ASSERT avaliada como nada em uma compilação de versão, para que nenhum código de encontrado em declarações será executado. Para obter mais informações, consulte [examinar instruções ASSERT](../../build/reference/using-verify-instead-of-assert.md).  
  
 Algumas funções são embutidas para aumentar a velocidade na compilação de versão. Otimizações geralmente são ativadas em uma compilação de versão. Um alocador de memória diferentes também está sendo usado.  
  
##  <a name="_core_pointer_support"></a> Suporte de ponteiro  
 A falta de informações de depuração remove o preenchimento do seu aplicativo. Em uma versão de compilação, ponteiros perdidos tem uma possibilidade maior de apontar para a memória não inicializada em vez de apontar para informações de depuração.  
  
##  <a name="_core_optimizations"></a> Otimizações  
 Dependendo da natureza de determinados segmentos de código, o compilador de otimização pode gerar código inesperado. Essa é a causa menos provável dos problemas de compilação de versão, mas ele ocorrem na ocasião. Para uma solução, consulte [otimizando seu código](../../build/reference/optimizing-your-code.md).  
  
## <a name="see-also"></a>Consulte também  
 [Compilações de lançamento](../../build/reference/release-builds.md)   
 [Corrigindo problemas do build de versão](../../build/reference/fixing-release-build-problems.md)