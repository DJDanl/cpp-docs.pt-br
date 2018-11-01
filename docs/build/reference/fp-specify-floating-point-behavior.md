---
title: /fp (especificar comportamento de ponto flutuante)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCCLCompilerTool.floatingPointModel
- VC.Project.VCCLWCECompilerTool.FloatingPointExceptions
- /fp
- VC.Project.VCCLWCECompilerTool.floatingPointModel
- VC.Project.VCCLCompilerTool.FloatingPointExceptions
helpviewer_keywords:
- -fp compiler option [C++]
- /fp compiler option [C++]
ms.assetid: 10469d6b-e68b-4268-8075-d073f4f5d57e
ms.openlocfilehash: 8b948edba3244eb22089b2ef5b4c8131736e1fb3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50452566"
---
# <a name="fp-specify-floating-point-behavior"></a>/fp (especificar comportamento de ponto flutuante)

Especifica o comportamento de ponto flutuante em um arquivo de código-fonte.

## <a name="syntax"></a>Sintaxe

> **/FP:**[**preciso** | **exceto**[**-**] | **rápida** | **strict**]

### <a name="arguments"></a>Arguments

#### <a name="precise"></a>Preciso

O valor padrão de **/fp** é **/fp: preciso**.

O **/fp: preciso** sinalizador melhora a consistência dos testes de ponto flutuante para igualdade e desigualdade desabilitando as otimizações que poderiam alterar a precisão dos cálculos de ponto flutuantes. (É necessário manter a precisão específica para a total compatibilidade com ANSI.) Por padrão, no código para x86 arquiteturas que use x87 coprocessador instruções, o compilador usa o coprocessador de 80 bits registros a manter os resultados intermediários dos cálculos de ponto flutuantes. Isso aumenta a velocidade do programa e reduz o tamanho do programa. No entanto, como o cálculo envolve tipos de dados de ponto flutuante que são representados na memória por menos de 80 bits, transportar os bits extras de bits de precisão – 80 bits menos o número de bits em um tipo de ponto flutuante menor – por um cálculo longo pode gerar resultados inconsistentes.

Com o **/fp: preciso** em x86 processadores, o compilador executa o arredondamento em variáveis do tipo `float` na precisão correta para atribuições e conversões e quando os parâmetros são passados para uma função. Esse arredondado garante que os dados não retenham significância maior que a capacidade de seu tipo. Um programa compilado com **/fp: preciso** pode ser mais lento e maior que um compilado sem **/fp: preciso**. **/FP: preciso** desabilita intrínsecos; a biblioteca de tempo de execução padrão rotinas são usadas em vez disso. Para obter mais informações, consulte [/Oi (gerar funções intrínsecas)](../../build/reference/oi-generate-intrinsic-functions.md).

O seguinte comportamento de ponto flutuante está habilitado com **/fp: preciso**:

- Contrações – ou seja, usar uma operação composta que tenha apenas um arredondamento no final para substituir várias operações.

- As otimizações de expressão que são inválidas para valores especiais (NaN, +infinity, -infinity, +0, -0) não são permitidas. A otimizações x-x = > 0, x * 0 = > 0, x-0 = > x, x + 0 = > x e x-0 = > - x são inválidas por vários motivos. (Consulte IEEE 754 e o padrão C99.)

- O compilador trata corretamente as comparações que envolvem NaN. Por exemplo, x! = x é avaliada como **verdadeira** se `x` é NaN e as comparações ordenadas que envolvem NaN geram uma exceção.

- A avaliação da expressão segue o C99 FLT_EVAL_METHOD=2, com esta exceção: quando você programa para processadores x86, como o FPU é definido como uma precisão de 53 bits, isso é considerado uma precisão de double longo.

- Multiplicação por exatamente 1,0 transformada em um uso do outro fator. x * y\*1.0 é transformado em x\*y. Da mesma forma, os x\*1.0\*y é transformado em x\*y.

- A divisão por exatamente 1,0 é transformada em um uso do dividendo. x * y/1.0 é transformado em x\*y. Da mesma forma, o x / 1.0\*y é transformado em x\*y.

Usando o **/fp: preciso** quando [fenv_access](../../preprocessor/fenv-access.md) está ativado desabilita otimizações, como avaliações de tempo de compilação de expressões de ponto flutuantes. Por exemplo, se você usar [_control87, controlfp, \__control87_2](../../c-runtime-library/reference/control87-controlfp-control87-2.md) alterar o modo de arredondamento e o compilador executa um cálculo de ponto flutuante, o modo de arredondamento especificado não está em vigor, a menos que `fenv_access`está ON.

**/FP: preciso** substitui o **/Op** opção de compilador.

#### <a name="fast"></a>Rápida

O **Fast** opção cria o código mais rápido na maioria dos casos flexibilizando as regras para otimizar operações de ponto flutuante. Isso permite que o compilador otimize o código de ponto flutuante para velocidade às custas da precisão e da exatidão. Quando **Fast** for especificado, o compilador pode não arredondar corretamente em instruções de atribuição, typecasts ou chamadas de função e não pode executar arredondamento de expressões intermediárias. O compilador pode reordenar operações ou executar transformações algébricas – por exemplo, seguindo regras associativas e distributivas – sem considerar o efeito nos resultados finitos de precisão. O compilador pode alterar operações e operandos para precisão única em vez de seguir as regras da promoção de tipo C++. Otimizações de contração específicas de ponto flutuante estão sempre habilitadas ([fp_contract](../../preprocessor/fp-contract.md) está ON). Exceções de ponto flutuante e o acesso ao ambiente FPU são desabilitados (**/fp: except-** está implícita e [fenv_access](../../preprocessor/fenv-access.md) é OFF).

**Fast** não pode ser usado com **/fp: strict** ou **/fp: preciso**. A última opção especificada na linha de comando é usada. Especificar ambos **Fast** e **/fp: except** gera um erro do compilador.

Especificando [/Za, /Ze (desabilitar extensões de linguagem)](../../build/reference/za-ze-disable-language-extensions.md) (compatibilidade com ANSI) e **Fast** pode causar um comportamento inesperado. Por exemplo, operações de ponto flutuante de precisão única não podem ser arredondadas para precisão única.

#### <a name="except"></a>Exceto

O **/fp: except** opção permite que um modelo de exceção de ponto flutuante confiável. As exceções são geradas imediatamente depois que são disparadas. Por padrão, essa opção é desativada. Anexando um sinal de menos à opção (**/fp: except-**) desabilita explicitamente a ele.

#### <a name="strict"></a>strict

O **/fp: strict** opção permite que o modelo de ponto flutuante mais estrito. **/FP: strict** faz com que [fp_contract](../../preprocessor/fp-contract.md) seja desativado e [fenv_access](../../preprocessor/fenv-access.md) seja ativado. **/FP: except** está implícita e pode ser desabilitado explicitamente especificando **/fp: except-**. Quando usado com **/fp: exceto-**, **/fp: strict** impõe semântica estrita de ponto flutuante, mas sem relação a eventos excepcionais.

## <a name="remarks"></a>Comentários

Vários **/fp** opções podem ser especificadas na mesma compilação.

Para controlar o comportamento de ponto flutuante pela função, consulte a [float_control](../../preprocessor/float-control.md) pragma. Isso substitui o **/fp** configuração do compilador. Recomendamos salvar e restaurar o comportamento de ponto flutuante local como boa prática de engenharia:

```cpp
#pragma float_control(precise, on, push)
// Code that uses /fp:precise mode
#pragma float_control(pop)
```

A maioria das otimizações de ponto flutuantes relacionada à **/fp: strict**, **/fp: exceto** (e seus pragmas correspondentes) e o `fp_contract` pragma são dependentes do computador. **/FP: strict** e **/fp: except** não são compatíveis com **/clr**.

**/FP: preciso** deve tratar a maioria dos requisitos de ponto flutuante do aplicativo. Você pode usar **/fp: except** e **/fp: strict**, mas pode haver certa redução de desempenho. Se o desempenho for mais importante, considere a possibilidade de usar **Fast**.

**/FP: strict**, **Fast**, e **/fp: preciso** aos modos de precisão (exatidão). Somente um pode ser usado por vez. Se os dois **/fp: strict** e **/fp: preciso** forem especificados, o compilador usará aquele que é processado por último. Ambos **/fp: strict** e **Fast** não pode ser especificado.

Para obter mais informações, consulte [otimização de ponto flutuante do Microsoft Visual C++](floating-point-optimization.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Expanda o **propriedades de configuração** > **C/C++** > **geração de código** página de propriedades.

1. Modificar a **modelo de ponto flutuante** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.floatingPointModel%2A>.

## <a name="see-also"></a>Consulte também

- [Opções do Compilador](compiler-options.md)
- [Definindo opções do compilador](setting-compiler-options.md)
- [Microsoft Visual C++ para otimização de ponto flutuante](floating-point-optimization.md)