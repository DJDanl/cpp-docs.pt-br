---
title: "/arch (x86) | Microsoft Docs"
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
ms.assetid: 9dd5a75d-06e4-4674-aade-33228486078d
caps.latest.revision: 33
caps.handback.revision: 33
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /arch (x86)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica a arquitetura para a geração de código no x86.  Consulte também [\/arch \(x64\)](../../build/reference/arch-x64.md) e [\/arch \(ARM\)](../../build/reference/arch-arm.md).  
  
## Sintaxe  
  
```  
/arch:[IA32|SSE|SSE2|AVX|AVX2]  
```  
  
## Argumentos  
 **\/arch:IA32**  
 Não especifica instruções aprimoradas e especifica x87 para cálculos de ponto flutuante.  
  
 **\/arch:SSE**  
 Habilita o uso de instruções SSE.  
  
 **\/arch:SSE2**  
 Habilita o uso de instruções SSE2.  Essa é a instrução padrão na plataforma x86 se nenhuma opção **\/arch** for especificada.  
  
 **\/arch:AVX**  
 Habilita o uso de instruções Intel Advanced Vector Extensions.  
  
 **\/arch:AVX2**  
 Habilita o uso de instruções Intel Advanced Vector Extensions 2.  
  
## Comentários  
 As instruções SSE e SSE2 existem em diversos processadores Intel e AMD.  As instruções AVX existem nos processadores Intel Sandy Bridge e AMD Bulldozer.  As instruções AVX2 são compatíveis com processadores Intel Haswell e Broadwell, e em processadores AMD baseados em Excavator.  
  
 As macros `_M_IX86_FP`, `__AVX__` e`__AVX2__` indicam que, se houve uma opção de compilador, a opção **\/arch** foi usada.  Para obter mais informações, consulte [Macros predefinidas](../../preprocessor/predefined-macros.md).  A opção **\/arch:AVX2** e a macro `__AVX2__` foram introduzidas na versão 12.0.34567.1 da atualização 2 do Visual Studio 2013.  
  
 O otimizador escolhe quando e como usar as instruções SSE e SSE2 quando a opção **\/arch** é especificada.  Ele usa as instruções SSE e SSE2 em alguns cálculos escalares de ponto flutuante quando determina que é mais rápido usar registros e instruções SSE\/SSE2 em vez da pilha de registro de ponto flutuante do x87.  Por isso, no momento, seu código pode combinar x87 e SSE\/SSE2 nos cálculos de ponto flutuante.  Além disso, com **\/arch:SSE2**, as instruções SSE2 podem ser usadas em algumas operações de inteiros de 64 bits.  
  
 Além de usar as instruções SSE e SSE2, o compilador também usa outras instruções presentes nas revisões do processador, que são compatíveis com SSE e SSE2.  Um exemplo disso é a instrução CMOV que apareceu pela primeira vez na revisão Pentium Pro dos processadores Intel.  
  
 Como o compilador do x86 gera códigos que usam as instruções SSE2 por padrão, você deve especificar a opção **\/arch:IA32** para desabilitar a geração de instruções SSE e SSE2 para processadores x86.  
  
 A opção **\/arch** afeta somente a geração de código de funções nativas.  Ao usar [\/clr](../../build/reference/clr-common-language-runtime-compilation.md) para compilar, **\/arch** não tem efeito sobre a geração de código para funções gerenciadas.  
  
 Não é possível usar as opções **\/arch** e [\/QIfist](../../build/reference/qifist-suppress-ftol.md) no mesmo compiland.  Isso é importante principalmente se você não estiver usando a opção `_controlfp` para modificar a palavra de controle de FP, e o código de inicialização do tempo de execução definir o campo de controle de precisão da palavra de controle de FPU do x87 como 53 bits.  Portanto, todas as operações duplicadas e de flutuação das expressões usam significandos de 53 bits e expoentes de 15 bits.  No entanto, todas as operações SSE de precisão simples usam significandos de 24 bits e expoentes de 8 bits. Já as operações SSE2 de precisão dupla usam significandos de 53 bits e expoentes de 11 bits.  Para obter mais informações, consulte [\_control87, \_controlfp, \_\_control87\_2](../Topic/_control87,%20_controlfp,%20__control87_2.md).  Essas diferenças podem ser usadas em árvores de expressões, mas não quando há uma atribuição de usuário após cada subexpressão.  Considere o seguinte:  
  
```c  
  
r = f1 * f2 + d;  // Different results are possible on SSE/SSE2.  
```  
  
 Em comparação a:  
  
```c  
  
t = f1 * f2;   // Do f1 * f2, round to the type of t.  
r = t + d;     // This should produce the same overall result   
               // whether x87 stack is used or SSE/SSE2 is used.  
```  
  
### Para definir essa opção de compilador para AVX, AVX2, IA32, SSE ou SSE2 no Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter mais informações, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Selecione a pasta **Propriedades de Configuração**, **C\/C\+\+**.  
  
3.  Selecione a página de propriedades **Geração de Código**.  
  
4.  Modifique a propriedade **Habilitar Conjunto de Instruções Avançadas**.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnableEnhancedInstructionSet%2A>.  
  
## Consulte também  
 [\/arch \(arquitetura mínima de CPU\)](../../build/reference/arch-minimum-cpu-architecture.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)