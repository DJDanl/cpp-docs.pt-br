---
title: "/Ob (expans&#227;o de fun&#231;&#227;o embutida) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "VC.Project.VCCLWCECompilerTool.InlineFunctionExpansion"
  - "VC.Project.VCCLCompilerTool.InlineFunctionExpansion"
  - "/ob"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /Ob (C++)"
  - "Opção de compilador /Ob0 (C++)"
  - "Opção de compilador /Ob1 (C++)"
  - "Opção de compilador /Ob2 (C++)"
  - "qualquer Opção de compilador adequada [C++]"
  - "Opção de compilador desabilitar [C++]"
  - "expressão embutida, Opção de compilador"
  - "funções embutidas, Opção de compilador expansão de função [C++]"
  - "Opção de compilador Ob [C++]"
  - "Opção de compilador -Ob [C++]"
  - "Opção de compilador Ob0 (C++)"
  - "Opção de compilador -Ob0 (C++)"
  - "Opção de compilador Ob1 (C++)"
  - "Opção de compilador -Ob1 (C++)"
  - "Opção de compilador Ob2 (C++)"
  - "Opção de compilador -Ob2 (C++)"
  - "Opção de compilador somente __inline [C++]"
ms.assetid: f134e6df-e939-4980-a01d-47425dbc562a
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Ob (expans&#227;o de fun&#231;&#227;o embutida)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Controla a expansão embutida de funções.  
  
## Sintaxe  
  
```  
/Ob{0|1|2}  
```  
  
## Argumentos  
 **0**  
 Desabilita expansões embutido.  Por padrão, expansão ocorre a critério do compilador em todas as funções, conhecida como *automática inlining*.  
  
 **1**  
 Permite expansão apenas das funções marcadas [embutido](../../misc/inline-inline-forceinline.md), [inline](../../misc/inline-inline-forceinline.md), ou [forceinline](../../misc/inline-inline-forceinline.md), ou em uma função de membro C\+\+ definido em uma declaração de classe.  
  
 **2**  
 O valor padrão.  Permite expansão das funções marcadas como `inline`, `__inline`, ou `__forceinline`, e qualquer outra função que o compilador escolhe.  
  
 **\/Ob2** está em vigor quando [\/O1, \/O2 \(minimizar tamanho, maximizar velocidade\)](../../build/reference/o1-o2-minimize-size-maximize-speed.md) ou [\/Ox \(otimização total\)](../../build/reference/ox-full-optimization.md) é usado.  
  
 Essa opção requer que você habilite otimizações usando **\/O1**, **\/O2**, **\/Ox**, ou **\/Og**.  
  
## Comentários  
 O compilador trata as opções de expansão embutida e as palavras\-chave como sugestões.  Não há nenhuma garantia de que todas as funções serão embutidas expandidas.  Você pode desabilitar expansões embutido, mas você não pode forçar o compilador a embutir uma função específica, mesmo ao usar o `__forceinline` palavra\-chave.  
  
 Você pode usar o `#pragma` [auto\_inline](../../preprocessor/auto-inline.md) diretiva para excluir funções da consideração como candidatos para expansão embutida.  Consulte também o `#pragma` [Intrínseco ](../../preprocessor/intrinsic.md) diretiva.  
  
> [!NOTE]
>  Informações coletadas de execuções de teste de criação de perfil substituem otimizações que seriam em vigor se você especificar **\/Ob**, **\/Os**, ou **\/Ot**.  Para obter mais informações, consulte [Otimizações orientadas a perfil](../../build/reference/profile-guided-optimizations.md).  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter detalhes, consulte [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda **Propriedades de configuração**, **C\/C\+\+**, e selecione **otimização**.  
  
3.  Modificar o **expansão de função embutida** propriedade.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.InlineFunctionExpansion%2A>.  
  
## Consulte também  
 [\/O opções \(otimizar código\)](../../build/reference/o-options-optimize-code.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)