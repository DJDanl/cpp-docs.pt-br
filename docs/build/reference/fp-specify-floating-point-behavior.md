---
title: /FP (Especificar comportamento de ponto flutuante)
ms.date: 11/09/2018
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
ms.openlocfilehash: c571bf104fd7e8f6a287c3dd35c444d904b4b7e8
ms.sourcegitcommit: c85c8a1226d8fbbaa29f4691ed719f8e6cc6575c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/24/2019
ms.locfileid: "54894088"
---
# <a name="fp-specify-floating-point-behavior"></a>/FP (Especificar comportamento de ponto flutuante)

Especifica como o compilador trata exceções, as otimizações e expressões de ponto flutuante. O **/fp** opções especificam se o código gerado permite o ambiente de ponto flutuante muda para o modo de arredondamento, máscaras de exceção e comportamento subnormal e se as verificações de status de ponto flutuante retornam atuais e precisas resultados. Ele controla se o compilador gera código que mantém a operação de fonte e a expressão de ordenação e está em conformidade com o padrão para a propagação de NaN, ou se, em vez disso, ele gera um código mais eficiente que pode reordenar ou combinam operações e usar simplificando transformações algébricas que não são permitidas por padrão.

## <a name="syntax"></a>Sintaxe

> **/fp:**[**precise** | **strict** | **fast** | **except**[**-**]]

### <a name="arguments"></a>Arguments

#### <a name="precise"></a>Preciso

Por padrão, o compilador utiliza **/fp: preciso** comportamento.

Sob **/fp: preciso** o compilador preserva a expressão de origem, ordenação e propriedades de código de ponto flutuante de arredondamento quando ele gera e otimiza o código de objeto para a máquina de destino. Arredonda para o compilador para precisão de código de origem em quatro pontos específicos durante a avaliação da expressão: em atribuições, em typecasts, quando um argumento de ponto flutuante é passado para uma chamada de função e quando um valor de ponto flutuante é retornado de uma chamada de função. Cálculos intermediários podem ser executados com precisão de máquina. Typecasts pode ser usada para arredondar explicitamente cálculos intermediários.

O compilador não executa transformações algébricas em expressões de ponto flutuantes, como reassociação ou distribuição, a menos que a transformação é garantida para produzir um resultado idêntico bit a bit.
Expressões que envolvem valores especiais (NaN, + infinity, - infinity, -0,0) são processadas de acordo com especificações IEEE-754. Por exemplo, `x != x` for avaliada como **verdadeiro** se x for NaN. Ponto flutuante *contrações*, ou seja, instruções de máquina que combinam operações de ponto flutuante podem ser gerados sob **/fp: preciso**.

O compilador gera código que deve ser executado nos [ambiente de ponto flutuante padrão](#the-default-floating-point-environment) e pressupõe que o ambiente de ponto flutuante não é acessado ou modificado em tempo de execução. Ou seja, ele pressupõe que o código não remover a máscara das exceções de ponto flutuante, ler ou gravar os registros de status de ponto flutuante ou alterar modos de arredondamento.

Se seu código de ponto flutuante não depende da ordem de operações e expressões em suas instruções de ponto flutuantes (por exemplo, se você não se importa se `a * b + a * c` é computado como `(b + c) * a` ou `2 * a` como `a + a`), considere o [Fast](#fast) opção, que pode produzir um código mais rápido e eficiente. Se seu código tanto depende da ordem das operações e expressões e acessa ou altera o ambiente de ponto flutuante (por exemplo, para alterar os modos de arredondamento ou interceptar exceções de ponto flutuante), use [/fp: strict](#strict).

#### <a name="strict"></a>strict

**/FP: strict** tem um comportamento semelhante ao **/fp: preciso**, ou seja, o compilador preserva a ordenação de código-fonte e propriedades de arredondamento de ponto flutuante código quando ele gera e otimiza o código para a máquina de destino do objeto e observa o padrão ao lidar com valores especiais. Além disso, o programa pode acessar ou modificar o ambiente de ponto flutuante em tempo de execução com segurança.

Sob **/fp: strict**, o compilador gera código que permite que o programa remover a máscara das exceções de ponto flutuante, ler ou gravar os registros de status de ponto flutuante ou alterar modos de arredondamento com segurança. Arredonda para precisão de código de origem em quatro pontos específicos durante a avaliação da expressão: em atribuições, em typecasts, quando um argumento de ponto flutuante é passado para uma chamada de função e quando um valor de ponto flutuante é retornado de uma chamada de função. Cálculos intermediários podem ser executados com precisão de máquina. Typecasts pode ser usada para arredondar explicitamente cálculos intermediários. O compilador não executa transformações algébricas em expressões de ponto flutuantes, como reassociação ou distribuição, a menos que a transformação é garantida para produzir um resultado idêntico bit a bit. Expressões que envolvem valores especiais (NaN, + infinity, - infinity, -0,0) são processadas de acordo com especificações IEEE-754. Por exemplo, `x != x` for avaliada como **verdadeiro** se x for NaN. Contrações de ponto flutuantes não são geradas sob **/fp: strict**.

**/FP: strict** é computacionalmente mais caro do que **/fp: preciso** porque o compilador deve inserir instruções adicionais para interceptar exceções e permitir que os programas acessar ou modificar o ambiente de ponto flutuante no tempo de execução. Se seu código não usa esse recurso, mas requer ordenação de código de origem e de arredondamento ou se baseia em valores especiais, use **/fp: preciso**. Caso contrário, considere o uso de **Fast**, que pode produzir um código mais rápido e menor.

#### <a name="fast"></a>Rápida

O **Fast** opção permite que o compilador reordenar, combinar ou simplificar as operações de ponto flutuantes para otimizar o código de ponto flutuante para velocidade e espaço. O compilador pode omitir o arredondamento em instruções de atribuição, typecasts ou chamadas de função. Ele pode reordenar operações ou executar transformações algébricas, por exemplo, pelo uso das leis associativas e distributivas, mesmo que essas transformações resultam em comportamento de arredondamento nitidamente diferente. Por causa dessa otimização aprimorada, o resultado de alguns cálculos de ponto flutuante pode ser diferentes das produzidas por outros **/fp** opções. Valores especiais (NaN, + infinity, - infinity, -0,0) não podem ser propagadas ou se comportam estritamente de acordo com o padrão IEEE-754. Contrações de ponto flutuantes podem ser geradas sob **Fast**. O compilador ainda está associado, a arquitetura subjacente sob **Fast**, e as otimizações adicionais podem estar disponíveis por meio do uso das [/arch](../../build/reference/arch-minimum-cpu-architecture.md) opção.

Sob **Fast**, o compilador gera código devem ser executados no ambiente de ponto flutuante padrão e pressupõe que o ambiente de ponto flutuante não é acessado ou modificado em tempo de execução. Ou seja, ele pressupõe que o código não remover a máscara das exceções de ponto flutuante, ler ou gravar os registros de status de ponto flutuante ou alterar modos de arredondamento.

**Fast** destina-se para programas que não exigem a ordenação de código fonte estrita e arredondamento de expressões de ponto flutuantes e não contam com as regras padrão para lidar com valores especiais, como NaN. Se seu código de ponto flutuante requer a preservação do código-fonte, ordenação e arredondamento ou depender do comportamento padrão dos valores especiais, use [/fp: preciso](#precise). Se seu código acessa ou modifica o ambiente de ponto flutuante para alterar os modos de arredondamento, remover a máscara das exceções de ponto flutuante, ou verificar o status de ponto flutuante, use [/fp: strict](#strict).

#### <a name="except"></a>except

O **/fp: except** opção gera código para garante que todas as exceções de ponto flutuantes sem máscara são acionadas no ponto exato em que eles ocorrem e que nenhuma exceção de ponto flutuante adicionais é acionadas. Por padrão, o **/fp: strict** opção habilita **/fp: exceto**, e **/fp: preciso** não. O **/fp: except** opção não é compatível com **Fast**. A opção pode ser desabilitada explicitamente por nós de **/fp: except-**.

Observe que **/fp: except** não habilita todas as exceções de ponto flutuantes por si só, mas é necessário para programas habilitar exceções de ponto flutuante. Ver [controlfp](../../c-runtime-library/reference/control87-controlfp-control87-2.md) para obter informações sobre como habilitar exceções de ponto flutuante.

## <a name="remarks"></a>Comentários

Vários **/fp** opções podem ser especificadas na mesma linha de comando do compilador. Somente um dos **/fp: strict**, **Fast**, e **/fp: preciso** opções podem estar em vigor por vez. Se mais de uma dessas opções for especificada na linha de comando, a opção posterior terá precedência e o compilador gera um aviso. O **/fp: strict** e **/fp: except** opções não são compatíveis com **/clr**.

O [/Za](../../build/reference/za-ze-disable-language-extensions.md) opção (compatibilidade com ANSI) não é compatível com **/fp**.

### <a name="using-pragmas-to-control-floating-point-behavior"></a>Usando Pragmas para controlar o comportamento de ponto flutuante

O compilador fornece três diretivas pragma para substituir o comportamento de ponto flutuante especificado na linha de comando: [float_control](../../preprocessor/float-control.md), [fenv_access](../../preprocessor/fenv-access.md), e [fp_contract](../../preprocessor/fp-contract.md). Você pode usar esses pragmas para controlar o comportamento de ponto flutuante no nível de função, não dentro de uma função. Observe que esses pragmas não correspondem diretamente para o **/fp** opções. Esta tabela mostra como o **/fp** pragmas e opções de mapear entre si. Para obter mais informações, consulte a documentação para os pragmas e opções individuais.

||float_control(precise)|float_control(except)|fenv_access|fp_contract|
|-|-|-|-|-|
|**/fp:fast**|Desativar|Desativar|Desativar|em|
|**/fp:precise**|em|Desativar|Desativar|em|
|**/fp:strict**|em|em|em|Desativar|

### <a name="the-default-floating-point-environment"></a>O ambiente de ponto flutuante padrão

Quando um processo é inicializado, o *padrão para o ambiente de ponto de flutuante* está definido. Nesse ambiente mascara exceções de ponto flutuante tudo, define o modo de arredondamento para arredondar mais próximo (`FE_TONEAREST`), preserva subnormal (desnormalizado) valores, usa a precisão padrão dos significando (mantissa) para **float**, **duplas**, e **longo duplo** valores e onde houver suporte, define o controle de infinito para o modo de afim de padrão.

### <a name="floating-point-environment-access-and-modification"></a>Modificação e acesso ao ambiente de ponto flutuante

O tempo de execução do Microsoft Visual C++ fornece várias funções para acessar e modificar o ambiente de ponto flutuante. Eles incluem [controlfp](../../c-runtime-library/reference/control87-controlfp-control87-2.md), [clearfp](../../c-runtime-library/reference/clear87-clearfp.md), e [statusfp](../../c-runtime-library/reference/status87-statusfp-statusfp2.md) e suas variantes. Para garantir o comportamento correto do programa ao seu código acessa ou modifica o ambiente de ponto flutuante, `fenv_access` deve ser habilitado, ou pelo **/fp: strict** opção ou pelo uso do `fenv_access` pragma para essas funções para ter nenhum efeito. Quando `fenv_access` não é habilitado, acesso ou modificação do ambiente de ponto flutuante pode resultar em comportamento inesperado do programa: código não pode aceitar alterações solicitadas para o ambiente de ponto flutuante; os registros de status de ponto flutuante podem não relatar resultados esperados ou atuais; e podem ocorrer exceções de ponto flutuantes inesperadas ou exceções esperadas de ponto flutuantes podem não ocorrer.

Quando seu código acessa ou modifica o ambiente de ponto flutuante, você deve ter cuidado ao combinar o código em que `fenv_access` é habilitado com o código que não tenha `fenv_access` habilitado. No código onde `fenv_access` não estiver habilitado, o compilador pressupõe que o ambiente de ponto flutuante de plataforma padrão está em vigor e que o status de ponto flutuante não é acessado ou modificado. Recomendamos que você salvar e restaurar o ambiente de ponto flutuante local para seu estado padrão antes do controle é transferido para uma função que não tem `fenv_access` habilitado. Este exemplo demonstra como o `float_control` pragma pode ser definida e restaurado:

```cpp
#pragma float_control(strict, on, push)
// Code that uses /fp:strict mode
#pragma float_control(pop)
```

### <a name="floating-point-rounding-modes"></a>Modos de arredondamento de ponto flutuantes

Em ambos **/fp: preciso** e **Fast** o compilador gera código devem ser executados no ambiente de ponto flutuante padrão e pressupõe que o ambiente não for acessado ou modificado em tempo de execução. Ou seja, ele pressupõe que o código não remover a máscara das exceções de ponto flutuante, ler ou gravar os registros de status de ponto flutuante ou alterar modos de arredondamento.  No entanto, alguns programas precisam alterar o ambiente de ponto flutuante. Por exemplo, este exemplo calcula os limites de erro de uma multiplicação de ponto flutuante alterando modos de arredondamento de ponto flutuantes:

```cpp
// fp_error_bounds.cpp
#include <iostream>
#include <limits>
using namespace std;

int main(void)
{
    float a = std::<float>::max();
    float b = -1.1;
    float cLower = 0.0;
    float cUpper = 0.0;
    unsigned int control_word = 0;
    int err = 0;

    // compute lower error bound.
    // set rounding mode to -infinity.
    err = _controlfp_s(&control_word, _RC_DOWN, _MCW_RC);
    if (err)
    {
        cout << "_controlfp_s(&control_word, _RC_DOWN, _MCW_RC) failed with error:" << err << endl;
    }  
    cLower = a * b;

    // compute upper error bound.
    // set rounding mode to +infinity.
    err = _controlfp_s(&control_word, _RC_UP, _MCW_RC);
    if (err)
    {
        cout << "_controlfp_s(&control_word, _RC_UP, _MCW_RC) failed with error:" << err << endl;
    }
    cUpper = a * b;

    // restore default rounding mode.
    err = _controlfp_s(&control_word, _CW_DEFAULT, _MCW_RC);
    if (err)
    {
        cout << "_controlfp_s(&control_word, _CW_DEFAULT, _MCW_RC) failed with error:" << err << endl;
    }
    // display error bounds.
    cout << "cLower = " << cLower << endl;
    cout << "cUpper = " << cUpper << endl;
    return 0;
}
```

Uma vez que o compilador assumirá o padrão flutuante ambiente ponto sob **Fast** e **/fp: preciso** é gratuito para ignorar as chamadas para `_controlfp_s`. Por exemplo, quando compilado usando ambos **/O2** e **/fp: preciso** para x86 arquitetura, os limites não são calculados e gera o programa de exemplo:

```Output
cLower = -inf
cUpper = -inf
```

Quando compilado com ambos **/O2** e **/fp: strict** para x86 saídas do arquitetura, o programa de exemplo:

```Output
cLower = -inf
cUpper = -3.40282e+38
```

### <a name="floating-point-special-values"></a>Valores especiais de ponto flutuante

Sob **/fp: preciso** e **/fp: strict**, expressões que envolvem valores especiais (NaN, + infinity, - infinity, -0,0) se comportam de acordo com as especificações IEEE-754. Sob **Fast**, o comportamento desses valores especiais pode ser inconsistente com IEEE-754.

Este exemplo demonstra o comportamento diferente dos valores especiais sob **/fp: preciso**, **/fp: strict** e **Fast**:

```cpp
// fp_special_values.cpp
#include <stdio.h>
#include <cmath>

float gf0 = -0.0;

int main()
{
    float f1 = INFINITY;
    float f2 = NAN;
    float f3 = -INFINITY;
    bool a, b;
    float c, d, e;
    a = (f1 == f1);
    b = (f2 == f2);
    c = (f1 - f1);
    d = (f2 - f2);
    printf("INFINITY == INFINITY : %d\n", a);
    printf("NAN == NAN           : %d\n", b);
    printf("INFINITY - INFINITY  : %f\n", c);
    printf("NAN - NAN            : %f\n", d);

    e = gf0 / abs(f3);
    printf("std::signbit(-0.0/-INFINITY): %d\n", std::signbit(c));
    return 0;
}
```

Quando compilado com **/O2** **/fp: preciso** ou **/O2** **/fp: strict** para x86 de arquitetura, as saídas são consistentes com o IEEE-754 especificação de:

```Output
INFINITY == INFINITY : 1
NAN == NAN           : 0
INFINITY - INFINITY  : -nan(ind)
NAN - NAN            : -nan(ind)
std::signbit(-0.0/-INFINITY): 1
```

Quando compilado com **/O2** **Fast** para x86 de arquitetura, as saídas não são consistentes com IEEE-754:

```Output
INFINITY == INFINITY : 1
NAN == NAN           : 1
INFINITY - INFINITY  : 0.000000
NAN - NAN            : 0.000000
std::signbit(-0.0/-INFINITY): 0
```

### <a name="floating-point-algebraic-transformations"></a>Transformações algébricas ponto flutuantes

Sob **/fp: preciso** e **/fp: strict**, o compilador não executa transformações de matemáticas, a menos que a transformação é garantida para produzir um resultado idêntico bit a bit. O compilador pode executar essas transformações sob **Fast**. Por exemplo, a expressão `a * b + a * c` na função de exemplo `algebraic_transformation` pode ser compilado em `a * (b + c)` sob **Fast**. Essas transformações não são realizadas sob **/fp: preciso** ou **/fp: strict**, e o compilador gera `a * b + a * c`.

```cpp
float algebraic_transformation (float a, float b, float c)
{
    return a * b + a * c;
}
```

### <a name="floating-point-explicit-casting-points"></a>Pontos de conversão explícita de ponto flutuante

Sob **/fp: preciso** e **/fp: strict**, o compilador é arredondado para a precisão de código de origem em quatro pontos específicos durante a avaliação da expressão: em atribuições, em typecasts quando um argumento de ponto flutuante é passado para uma chamada de função, e quando um valor de ponto flutuante é retornado de uma chamada de função. Typecasts pode ser usada para arredondar explicitamente cálculos intermediários. Sob **Fast**, o compilador não gera conversões explícitas nesses pontos para garantir a precisão de código de origem. Este exemplo demonstra o comportamento em diferentes **/fp** opções:

```cpp
float casting(float a, float b)
{
    return 5.0*((double)(a+b));
}
```

Quando compilado usando **/O2** **/fp: preciso** ou **/O2** **/fp: strict**, você pode ver que as conversões de tipo explícito são inseridos em ambos os conversão de tipo e a função retornar o ponto no código gerado para o x64 arquitetura:

```asm
        addss    xmm0, xmm1
        cvtss2sd xmm0, xmm0
        mulsd    xmm0, QWORD PTR __real@4014000000000000
        cvtsd2ss xmm0, xmm0
        ret      0
```

Sob **/O2** **Fast** o código gerado seja simplificado, porque todas as conversões de tipo são removidas:

```asm
        addss    xmm0, xmm1
        mulss    xmm0, DWORD PTR __real@40a00000
        ret      0
```

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **geração de código** página de propriedades.

1. Modificar a **modelo de ponto flutuante** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.floatingPointModel%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](compiler-options.md)<br/>
[Definindo opções do compilador](setting-compiler-options.md)<br/>
[Microsoft Visual C++ para otimização de ponto flutuante](floating-point-optimization.md)<br/>
