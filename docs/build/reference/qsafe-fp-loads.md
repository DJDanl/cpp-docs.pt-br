---
title: "/Qsafe_fp_loads | Microsoft Docs"
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
ms.assetid: 2b2ce52d-ba57-4bd3-a739-47a7f8bfaba9
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Qsafe_fp_loads
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Requer instruções de movimentação de inteiro para valores de ponto flutuante e desabilitar certas otimizações de ponto flutuante de carga.  
  
## Sintaxe  
  
```  
/Qsafe_fp_loads  
```  
  
## Comentários  
 **\/Qsafe\_fp\_loads** só está disponível nos compiladores que visam x86; não está disponível nos compiladores que visam x64 ou o BRAÇO.  
  
 **\/Qsafe\_fp\_loads** força o compilador para usar instruções o valor inteiro em vez de instruções de ponto flutuante de movimentação para mover dados entre a memória e MMX registros.  Essa opção também desabilita a otimização da carga do registro para os valores de ponto flutuante que podem ser carregados em vários caminhos quando o valor de pode causar uma exceção sobre NLB para o exemplo, um valor do controle de NaN.  
  
 Essa opção é substituída por [\/fp: exceto](../../build/reference/fp-specify-floating-point-behavior.md).  **\/Qsafe\_fp\_loads** especifica um subconjunto do comportamento do compilador que é especificado por **\/fp:except**.  
  
 **\/Qsafe\_fp\_loads** é incompatível com [\/clr](../../build/reference/clr-common-language-runtime-compilation.md) e [\/fp: rápido](../../build/reference/fp-specify-floating-point-behavior.md).  Para obter mais informações sobre as opções do compilador de ponto flutuante, consulte [\/fp \(especificar comportamento de ponto flutuante\)](../../build/reference/fp-specify-floating-point-behavior.md).  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Selecione a pasta **C\/C\+\+**.  
  
3.  Selecione a página de propriedades **Linha de Comando** .  
  
4.  Digite a opção de compilador na caixa **Opções Adicionais**.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [\/Q Opções \(operações de nível baixo\)](../../build/reference/q-options-low-level-operations.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)