---
title: -fp (Especificar comportamento de ponto flutuante) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCCLCompilerTool.floatingPointModel
- VC.Project.VCCLWCECompilerTool.FloatingPointExceptions
- /fp
- VC.Project.VCCLWCECompilerTool.floatingPointModel
- VC.Project.VCCLCompilerTool.FloatingPointExceptions
dev_langs: C++
helpviewer_keywords:
- -fp compiler option [C++]
- /fp compiler option [C++]
ms.assetid: 10469d6b-e68b-4268-8075-d073f4f5d57e
caps.latest.revision: "21"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 02ca51ef8c32e59a94f87419dd4a959022a30cde
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="fp-specify-floating-point-behavior"></a>/fp (especificar comportamento de ponto flutuante)
Especifica o comportamento de ponto flutuante em um arquivo de código-fonte.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/fp:[precise | except[-] | fast | strict ]  
```  
  
## <a name="flags"></a>Sinalizadores  
 **preciso**  
 O padrão.  
  
 Melhora a consistência dos testes de ponto flutuante em termos de igualdade e desigualdade desabilitando as otimizações que poderiam alterar a precisão dos cálculos de ponto flutuante. (É necessário manter a precisão específica para a total compatibilidade com ANSI.) Por padrão, no código para arquiteturas x86, o compilador usa os registros de 80 bits do coprocessador para armazenar os resultados intermediários dos cálculos de ponto flutuante. Isso aumenta a velocidade do programa e reduz o tamanho do programa. No entanto, como o cálculo envolve tipos de dados de ponto flutuante que são representados na memória por menos de 80 bits, transportar os bits extras de bits de precisão – 80 bits menos o número de bits em um tipo de ponto flutuante menor – por um cálculo longo pode gerar resultados inconsistentes.  
  
 Com **/fp: preciso** x86 processadores, o compilador executa de arredondamento em variáveis do tipo `float` à precisão correta de atribuições e conversões e quando os parâmetros são passados para uma função. Esse arredondado garante que os dados não retenham significância maior que a capacidade de seu tipo. Um programa compilado com **/fp: preciso** pode ser mais lento e maior que um compilado sem **/fp: preciso**. **/FP: preciso** desabilita intrínsecos; a biblioteca de tempo de execução padrão rotinas são usadas em vez disso. Para obter mais informações, consulte [/Oi (gerar funções intrínsecas)](../../build/reference/oi-generate-intrinsic-functions.md).  
  
 O seguinte comportamento de ponto flutuante está habilitado com **/fp: preciso**:  
  
-   Contrações – ou seja, usar uma operação composta que tenha apenas um arredondamento no final para substituir várias operações.  
  
-   As otimizações de expressão que são inválidas para valores especiais (NaN, +infinity, -infinity, +0, -0) não são permitidas. A otimizações x-x = > 0, x * 0 = > 0, x-0 = > x, x + 0 = > x e 0 x = > - x são inválidos por vários motivos. (Consulte IEEE 754 e o padrão C99.)  
  
-   O compilador trata corretamente as comparações que envolvem NaN. Por exemplo, x! = x é avaliada como **true** se `x` é NaN e comparações ordenadas que envolva NaN geram uma exceção.  
  
-   A avaliação da expressão segue o C99 FLT_EVAL_METHOD=2, com esta exceção: quando você programa para processadores x86, como o FPU é definido como uma precisão de 53 bits, isso é considerado uma precisão de double longo.  
  
-   Multiplicação por exatamente 1,0 transformada em um uso do outro fator. x * y\*1.0 é transformado em x\*y. Da mesma forma, x\*1.0\*y é transformado em x\*y.  
  
-   A divisão por exatamente 1,0 é transformada em um uso do dividendo. x * y/1.0 é transformado em x\*y. Da mesma forma, o x / 1.0\*y é transformado em x\*y.  
  
 Usando **/fp: preciso** quando [fenv_access](../../preprocessor/fenv-access.md) está em desabilita otimizações como avaliações de tempo de compilação de expressões de ponto flutuantes. Por exemplo, se você usar [control87, controlfp, \__control87_2](../../c-runtime-library/reference/control87-controlfp-control87-2.md) alterar o modo de arredondamento e o compilador executa um cálculo de ponto flutuante, o modo de arredondamento especificado não está em vigor, a menos que `fenv_access`é ON.  
  
 **/FP: preciso** substitui o **/Op** opção de compilador.  
  
 **rápida**  
 Cria o código mais rápido na maioria dos casos flexibilizando as regras para otimizar operações de ponto flutuante. Isso permite que o compilador otimize o código de ponto flutuante para velocidade às custas da precisão e da exatidão. Quando **Fast** for especificado, o compilador não arredondará corretamente em instruções de atribuição, typecasts, ou chamadas de função e não pode executar arredondamento de expressões intermediárias. O compilador pode reordenar operações ou executar transformações algébricas – por exemplo, seguindo regras associativas e distributivas – sem considerar o efeito nos resultados finitos de precisão. O compilador pode alterar operações e operandos para precisão única em vez de seguir as regras da promoção de tipo C++. Otimizações específicas de ponto flutuante contração estão sempre habilitadas ([fp_contract](../../preprocessor/fp-contract.md) está ativado). Exceções de ponto flutuante e o acesso ao ambiente FPU estão desativados (**/fp: exceto-** está implícita e [fenv_access](../../preprocessor/fenv-access.md) é OFF).  
  
 **Fast** não pode ser usado com **/fp: strict** ou **/fp: preciso**. A última opção especificada na linha de comando é usada. Especificar ambos **Fast** e **/fp: exceto** gera um erro do compilador.  
  
 Especificando [/Za, /Ze (desabilitar extensões de linguagem)](../../build/reference/za-ze-disable-language-extensions.md) (compatibilidade ANSI) e **Fast** pode causar um comportamento inesperado. Por exemplo, operações de ponto flutuante de precisão única não podem ser arredondadas para precisão única.  
  
 **exceto [-]**  
 Modelo de exceção de ponto flutuante confiável. As exceções são geradas imediatamente depois que são disparadas. Por padrão, essa opção é desativada. Adicionar um sinal de menos à opção a desabilita explicitamente.  
  
 **estrito**  
 O modelo de ponto flutuante mais estrito. **/FP: strict** faz com que [fp_contract](../../preprocessor/fp-contract.md) fique OFF e [fenv_access](../../preprocessor/fenv-access.md) esteja ativado. **/FP: exceto** está implícita e pode ser desabilitado especificando explicitamente **/fp: exceto-**. Quando usado com **/fp: exceto-**, **/fp: strict** impõe a semântica estrita de ponto flutuante, mas sem respeito a eventos excepcionais.  
  
## <a name="remarks"></a>Comentários  
 Vários **/fp** opções podem ser especificadas na mesma compilação.  
  
 Para controlar o comportamento de ponto flutuante por função, consulte o [float_control](../../preprocessor/float-control.md) pragma. Isso substitui o **/fp** configuração do compilador. Recomendamos salvar e restaurar o comportamento de ponto flutuante local como boa prática de engenharia:  
  
```cpp  
#pragma float_control(precise, on, push)  
// Code that uses /fp:precise mode  
#pragma float_control(pop)  
```  
  
 A maioria das otimizações de ponto flutuantes relacionada ao **/fp: strict**, **/fp: exceto** (e seus pragmas correspondente) e o `fp_contract` pragma dependem da máquina. **/FP: strict** e **/fp: exceto** não são compatíveis com **/clr**.  
  
 **/FP: preciso** deve resolver a maioria dos requisitos de ponto flutuante do aplicativo. Você pode usar **/fp: exceto** e **/fp: strict**, mas pode haver alguma diminuição no desempenho. Se o desempenho for mais importante, considere usar **Fast**.  
  
 **/FP: strict**, **Fast**, e **/fp: preciso** modos de precisão (precisão). Somente um pode ser usado por vez. Se ambos os **/fp: strict** e **/fp: preciso** forem especificados, o compilador usa a última processadas. Ambos **/fp: strict** e **Fast** não pode ser especificado.  
  
 Para obter mais informações, consulte [otimização de ponto flutuante do Microsoft Visual C++](http://msdn.microsoft.com/library/aa289157.aspx).  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda o **propriedades de configuração** nó.  
  
3.  Expanda o **C/C++** nó.  
  
4.  Selecione o **geração de código** página de propriedades.  
  
5.  Modificar o **modelo de ponto flutuante** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.floatingPointModel%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
 [Microsoft Visual C++ flutuante ponto otimização](http://msdn.microsoft.com/library/aa289157.aspx)