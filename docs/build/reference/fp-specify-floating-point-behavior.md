---
title: "/fp (especificar comportamento de ponto flutuante) | Microsoft Docs"
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
  - "VC.Project.VCCLCompilerTool.floatingPointModel"
  - "VC.Project.VCCLWCECompilerTool.FloatingPointExceptions"
  - "/fp"
  - "VC.Project.VCCLWCECompilerTool.floatingPointModel"
  - "VC.Project.VCCLCompilerTool.FloatingPointExceptions"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /fp (C++)"
  - "Opção de compilador -fp [C++]"
ms.assetid: 10469d6b-e68b-4268-8075-d073f4f5d57e
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /fp (especificar comportamento de ponto flutuante)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica o comportamento de ponto flutuante em um arquivo de código\-fonte.  
  
## Sintaxe  
  
```  
/fp:[precise | except[-] | fast | strict ]  
```  
  
## Sinalizadores  
 **precise**  
 O padrão.  
  
 Melhora a consistência dos testes de ponto flutuante em termos de igualdade e desigualdade desabilitando as otimizações que poderiam alterar a precisão dos cálculos de ponto flutuante. \(É necessário manter a precisão específica para a total compatibilidade com ANSI.\) Por padrão, no código para arquiteturas x86, o compilador usa os registros de 80 bits do coprocessador para armazenar os resultados intermediários dos cálculos de ponto flutuante.  Isso aumenta a velocidade do programa e reduz o tamanho do programa.  No entanto, como o cálculo envolve tipos de dados de ponto flutuante que são representados na memória por menos de 80 bits, transportar os bits extras de bits de precisão – 80 bits menos o número de bits em um tipo de ponto flutuante menor – por um cálculo longo pode gerar resultados inconsistentes.  
  
 Com **\/fp:precise** em processadores x86, o compilador executa o arredondamento em variáveis do tipo `float` na precisão correta para atribuições e conversões e quando os parâmetros são passados para uma função.  Esse arredondado garante que os dados não retenham significância maior que a capacidade de seu tipo.  Um programa compilado com **\/fp:precise** pode ser mais lento e maior que um compilado sem **\/fp:precise**.  **\/fp:precise** desabilita intrínsecos; as rotinas da biblioteca em tempo de execução padrão são usadas.  Para obter mais informações, consulte [\/Oi \(gerar funções intrínsecas\)](../Topic/-Oi%20\(Generate%20Intrinsic%20Functions\).md).  
  
 O seguinte comportamento de ponto flutuante é habilitado com **\/fp:precise**:  
  
-   Contrações – ou seja, usar uma operação composta que tenha apenas um arredondamento no final para substituir várias operações.  
  
-   As otimizações de expressão que são inválidas para valores especiais \(NaN, \+infinity, \-infinity, \+0, \-0\) não são permitidas.  As otimizações x\-x \=\> 0, x\*0 \=\> 0, x\-0 \=\> x, x\+0 \=\> x e 0\-x \=\> \-x são inválidas por vários motivos. \(Consulte IEEE 754 e o padrão C99.\)  
  
-   O compilador trata corretamente as comparações que envolvem NaN.  Por exemplo, x \!\= x avalia como **true** se `x` for NaN e as comparações ordenadas que envolvem NaN geram uma exceção.  
  
-   A avaliação da expressão segue o C99 FLT\_EVAL\_METHOD\=2, com esta exceção: quando você programa para processadores x86, como o FPU é definido como uma precisão de 53 bits, isso é considerado uma precisão de double longo.  
  
-   Multiplicação por exatamente 1,0 transformada em um uso do outro fator.  x\*y\*1.0 é transformado em x\*y.  Da mesma forma, x\*1.0\*y é transformado em x\*y.  
  
-   A divisão por exatamente 1,0 é transformada em um uso do dividendo.  x\*y\/1.0 é transformado em x\*y.  Da mesma forma, x\/1.0\*y é transformado em x\*y.  
  
 Usar **\/fp:precise** quando [fenv\_access](../../preprocessor/fenv-access.md) está ativado desabilita otimizações, como avaliações de tempo de compilação de expressões de ponto flutuante.  Por exemplo, se você usar [\_control87, \_controlfp, \_\_control87\_2](../Topic/_control87,%20_controlfp,%20__control87_2.md) para alterar o modo de arredondamento, e o compilador executa um cálculo de ponto flutuante, o modo de arredondamento que você especificou não é aplicado a menos que `fenv_access` esteja ativado.  
  
 **\/fp:precise** substitui a opção do compilador **\/Op**.  
  
 **fast**  
 Cria o código mais rápido na maioria dos casos flexibilizando as regras para otimizar operações de ponto flutuante.  Isso permite que o compilador otimize o código de ponto flutuante para velocidade às custas da precisão e da exatidão.  Quando **\/fp:fast** é especificado, o compilador pode não arredondar corretamente em instruções de atribuição, typecasts ou chamadas de função, e pode não ser executado pelo arredondamento de expressões intermediárias.  O compilador pode reordenar operações ou executar transformações algébricas – por exemplo, seguindo regras associativas e distributivas – sem considerar o efeito nos resultados finitos de precisão.  O compilador pode alterar operações e operandos para precisão única em vez de seguir as regras da promoção de tipo C\+\+.  As otimizações de contração específicas de ponto flutuante são sempre habilitadas \([fp\_contract](../../preprocessor/fp-contract.md) é ativado\).  As exceções de ponto flutuante e o acesso ao ambiente FPU são desabilitados \(**\/fp:except\-** é implícito e [fenv\_access](../../preprocessor/fenv-access.md) é desativado\).  
  
 **\/fp:fast** não pode ser usado com **\/fp:strict** ou **\/fp:precise**.  A última opção especificada na linha de comando é usada.  Especificar **\/fp:fast** e **\/fp:except** gera um erro de compilador.  
  
 Especificar [\/Za, \/Ze \(desabilitar extensões de linguagem\)](../../build/reference/za-ze-disable-language-extensions.md) \(compatibilidade com ANSI\) e **\/fp:fast** pode causar um comportamento inesperado.  Por exemplo, operações de ponto flutuante de precisão única não podem ser arredondadas para precisão única.  
  
 **except\[\-\]**  
 Modelo de exceção de ponto flutuante confiável.  As exceções são geradas imediatamente depois que são disparadas.  Por padrão, essa opção é desativada.  Adicionar um sinal de menos à opção a desabilita explicitamente.  
  
 **strict**  
 O modelo de ponto flutuante mais estrito.  **\/fp:strict** faz com que [fp\_contract](../../preprocessor/fp-contract.md) seja desativado e [fenv\_access](../../preprocessor/fenv-access.md) seja ativado.  **\/fp:except** é implícito e pode ser desabilitado explicitamente especificando **\/fp:except\-**.  Quando usado com **\/fp:except\-**, **\/fp:strict** impõe semânticas estritas de ponto flutuante, mas sem relação a eventos excepcionais.  
  
## Comentários  
 Várias opções **\/fp** podem ser especificadas na mesma compilação.  
  
 Para controlar o comportamento do ponto flutuante pela função, consulte o pragma [float\_control](../Topic/float_control.md).  Isso substitui a configuração do compilador **\/fp**.  Recomendamos salvar e restaurar o comportamento de ponto flutuante local como boa prática de engenharia:  
  
```css  
#pragma float_control(precise, on, push)  
// Code that uses /fp:precise mode  
#pragma float_control(pop)  
```  
  
 A maioria das otimizações de ponto flutuante relacionadas a **\/fp:strict**, **\/fp:except** \(e seus pragmas correspondentes\) e ao pragma `fp_contract` depende do computador.  **\/fp:strict** e **\/fp:except** não são compatíveis com **\/clr**.  
  
 **\/fp:precise** deve tratar a maioria dos requisitos de ponto flutuante de um aplicativo.  Você pode usar **\/fp:except** e **\/fp:strict**, mas pode haver certa redução de desempenho.  Se o desempenho for mais importante, considere **\/fp:fast**.  
  
 **\/fp:strict**, **\/fp:fast** e **\/fp:precise** são modos de precisão \(exatidão\).  Somente um pode ser usado por vez.  Se **\/fp:strict** e **\/fp:precise** forem especificados, o compilador usará o que é processado por último.  **\/fp:strict** e **\/fp:fast** não podem ser especificados.  
  
 Para obter mais informações, consulte [Otimização de ponto flutuante do Microsoft Visual C\+\+](http://msdn.microsoft.com/library/aa289157.aspx).  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Expanda o nó **Propriedades de Configuração**.  
  
3.  Expanda o nó **C\/C\+\+**.  
  
4.  Selecione a página de propriedades **Geração de Código**.  
  
5.  Modifique a propriedade de **Modelo de Ponto Flutuante**.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.floatingPointModel%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [Otimização de ponto flutuante do Microsoft Visual C\+\+](http://msdn.microsoft.com/library/aa289157.aspx)