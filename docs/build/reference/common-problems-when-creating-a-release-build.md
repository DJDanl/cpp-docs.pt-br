---
title: "Problemas comuns durante a cria&#231;&#227;o de uma compila&#231;&#227;o de vers&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "depurar compilações, diferença de compilações de lançamento"
  - "depurar alocador de memória"
  - "depuração [MFC], compilações de lançamento"
  - "problemas de layout de heap"
  - "memória [C++], substitui"
  - "MFC [C++], compilações de lançamento"
  - "otimização [C++], Compilador "
  - "ponteiros, perdido"
  - "projetos [C++], depurar configuração"
  - "compilações de lançamento, criando aplicativos"
  - "compilações de lançamento, solucionando problemas"
  - "ponteiros perdidos"
  - "solucionando problemas de compilações de lançamento"
  - "solucionando problemas do Visual C++"
  - "geração de código inesperado"
ms.assetid: 73cbc1f9-3e33-472d-9880-39a8e9977b95
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Problemas comuns durante a cria&#231;&#227;o de uma compila&#231;&#227;o de vers&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Durante o desenvolvimento, geralmente você compilará e testará com uma compilação de depuração do projeto.  Se você criar em seu aplicativo para uma construção de versão, você poderá obter uma violação de acesso.  
  
 A lista a seguir mostra as principais diferenças entre uma depuração e uma construção de versão \(nondebug\).  Há outras diferenças, mas a seguir são as principais diferenças que causam um aplicativo falhar em uma compilação de versão ao trabalhar em uma compilação de depuração.  
  
-   [Layout de heap](#_core_heap_layout)  
  
-   [Compilação](#_core_compilation)  
  
-   [Suporte do ponteiro](#_core_pointer_support)  
  
-   [Otimizações](#_core_optimizations)  
  
 Consulte a opção do compilador de [\/GZ \(Erros de compilação versão de captura na construção de depuração\)](../../build/reference/gz-enable-stack-frame-run-time-error-checking.md) para obter informações sobre como os erros de compilação da liberação de trava em construções de depuração.  
  
##  <a name="_core_heap_layout"></a> Layout de heap  
 O layout do heap será a causa da porcentagem aproximadamente noventa dos problemas aparentes quando um aplicativo funciona na depuração, mas não a versão.  
  
 Quando você cria o projeto para a depuração, você estiver usando o alocador de memória de depuração.  Isso significa que todas as alocações de memória têm os bytes de protetor colocados em torno deless.  Esses bytes de protetor detectam a memória substitui.  Como o layout do heap é a diferença entre a versão e as versões de depuração, a memória substitui não pode criar todos os problemas em uma compilação de depuração, mas pode ter efeitos catastróficos em uma compilação da versão.  
  
 Para obter mais informações, consulte [A verificação da memória substitui](../../build/reference/checking-for-memory-overwrites.md) e [Use a construção de depuração para verificar a memória substituem](../Topic/Using%20the%20Debug%20Build%20to%20Check%20for%20Memory%20Overwrite.md).  
  
##  <a name="_core_compilation"></a> Compilação  
 Muitas de macros e de MFC muito da implementação de MFC quando você compila da versão.  Em particular, a macro AFIRMAR avalia a nada em uma compilação de versão, para que nenhuma de código encontrou ASSERTs serão executados.  Para obter mais informações, consulte [Examine AFIRMAM instruções](../../build/reference/using-verify-instead-of-assert.md).  
  
 Algumas funções será embutida para aumentar a velocidade na construção da versão.  As otimizações são ativadas normalmente em uma compilação de versão.  Um alocador diferente de memória está sendo usado também.  
  
##  <a name="_core_pointer_support"></a> Suporte do ponteiro  
 A falta de informações de depuração remove o preenchimento de seu aplicativo.  Em uma compilação de versão, os ponteiros dispersos têm uma possibilidade maior do que aponta para a memória não inicializado em vez de apontar para depurar informações.  
  
##  <a name="_core_optimizations"></a> Otimizações  
 Dependendo da natureza de certos segmentos de código, o compilador otimizando pode gerar código inesperado.  Essa é a causa menos provável de problemas de compilação da versão, mas ocorre ocasionalmente.  Para uma solução, consulte [Otimizando seu código](../../build/reference/optimizing-your-code.md).  
  
## Consulte também  
 [Compilações de versão](../../build/reference/release-builds.md)   
 [Corrigindo problemas de compilação da versão](../../build/reference/fixing-release-build-problems.md)