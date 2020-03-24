---
title: /fp (especificar comportamento de ponto flutuante)
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
ms.openlocfilehash: c90a35bbaf967ecf50977987865d6a768b019fe3
ms.sourcegitcommit: eff68e4e82be292a5664616b16a526df3e9d1cda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80150764"
---
# <a name="fp-specify-floating-point-behavior"></a>/fp (especificar comportamento de ponto flutuante)

Especifica como o compilador trata expressões de ponto flutuante, otimizações e exceções. As opções **/FP** especificam se o código gerado permite alterações no ambiente de ponto flutuante para o modo de arredondamento, máscaras de exceção e comportamento subnormal, e se as verificações de status de ponto flutuante retornam resultados atuais e precisos. Ele controla se o compilador gera código que mantém a operação de origem e a ordenação de expressão e está em conformidade com o padrão para a propagação de NaN ou, em vez disso, gera um código mais eficiente que pode reordenar ou combinar operações e usar a simplificação transformações de algébricas que não são permitidas pelo padrão.

## <a name="syntax"></a>Sintaxe

> **/fp:** [**preciso** | **estrito** | **fast** | rápida **, exceto**[ **-** ]]

### <a name="arguments"></a>Argumentos

#### <a name="precise"></a>Precisas

Por padrão, o compilador usa `/fp:precise` comportamento.

Em `/fp:precise` o compilador preserva a ordenação da expressão de origem e as propriedades de arredondamento do código de ponto flutuante quando ele gera e otimiza o código do objeto para o computador de destino. O compilador arredonda para a precisão do código-fonte em quatro pontos específicos durante a avaliação da expressão: em atribuições, em typecasts, quando um argumento de ponto flutuante é passado para uma chamada de função e quando um valor de ponto flutuante é retornado de uma chamada de função. As computações intermediárias podem ser executadas na precisão da máquina. Typecasts pode ser usado para arredondar explicitamente cálculos intermediários.

O compilador não executa transformações de algébricas em expressões de ponto flutuante, como reassociação ou distribuição, a menos que a transformação produza um resultado idêntico de bit a ponto.
As expressões que envolvem valores especiais (NaN, + Infinity,-Infinity,-0,0) são processadas de acordo com as especificações do IEEE-754. Por exemplo, `x != x` será avaliada como **true** se x for NaN. As *contratações*de ponto flutuante, ou seja, instruções de máquina que combinam operações de ponto flutuante, podem ser geradas em `/fp:precise`.

O compilador gera o código destinado à execução no [ambiente de ponto flutuante padrão](#the-default-floating-point-environment) e pressupõe que o ambiente de ponto flutuante não seja acessado ou modificado no tempo de execução. Ou seja, ele pressupõe que o código não mascara as exceções de ponto flutuante, leia ou grave registros de status de ponto flutuante ou altere os modos de arredondamento.

Se o seu código de ponto flutuante não depender da ordem das operações e das expressões em suas instruções de ponto flutuante (por exemplo, se você não se importa se `a * b + a * c` é computado como `(b + c) * a` ou `2 * a` como `a + a`), considere a opção [/fp: Fast](#fast) , que pode produzir um código mais rápido e mais eficiente. Se o seu código depende da ordem das operações e das expressões, e acessa ou altera o ambiente de ponto flutuante (por exemplo, para alterar os modos de arredondamento ou para interceptar exceções de ponto flutuante), use [/fp: strict](#strict).

#### <a name="strict"></a>strict

`/fp:strict` tem comportamento semelhante ao `/fp:precise`, ou seja, o compilador preserva a ordenação de origem e as propriedades de arredondamento do código de ponto flutuante quando gera e otimiza o código do objeto para o computador de destino e observa o padrão ao manipular valores especiais. Além disso, o programa pode acessar com segurança ou modificar o ambiente de ponto flutuante em tempo de execução.

Em `/fp:strict`, o compilador gera um código que permite ao programa desmascarar com segurança exceções de ponto flutuante, ler ou gravar registros de status de ponto flutuante ou alterar os modos de arredondamento. Ele arredonda para a precisão do código-fonte em quatro pontos específicos durante a avaliação da expressão: em atribuições, em typecasts, quando um argumento de ponto flutuante é passado para uma chamada de função e quando um valor de ponto flutuante é retornado de uma chamada de função. As computações intermediárias podem ser executadas na precisão da máquina. Typecasts pode ser usado para arredondar explicitamente cálculos intermediários. O compilador não executa transformações de algébricas em expressões de ponto flutuante, como reassociação ou distribuição, a menos que a transformação produza um resultado idêntico de bit a ponto. As expressões que envolvem valores especiais (NaN, + Infinity,-Infinity,-0,0) são processadas de acordo com as especificações do IEEE-754. Por exemplo, `x != x` será avaliada como **true** se x for NaN. As contratações de ponto flutuante não são geradas em `/fp:strict`.

`/fp:strict` é computacionalmente mais cara do que `/fp:precise` porque o compilador deve inserir instruções adicionais para interceptar exceções e permitir que os programas acessem ou modifiquem o ambiente de ponto flutuante em tempo de execução. Se o seu código não usar esse recurso, mas exigir ordenação e arredondamento de código-fonte, ou se depender de valores especiais, use `/fp:precise`. Caso contrário, considere o uso de `/fp:fast`, que pode produzir um código mais rápido e menor.

#### <a name="fast"></a>rápida

A opção `/fp:fast` permite que o compilador reordene, combine ou simplifique operações de ponto flutuante para otimizar o código de ponto flutuante para velocidade e espaço. O compilador pode omitir o arredondamento em instruções de atribuição, typecasts ou chamadas de função. Ele pode reordenar operações ou executar transformações de algébricas, por exemplo, usando leis associativas e distributivo, mesmo que essas transformações resultem em um comportamento de arredondamento muito diferente. Devido a essa otimização aprimorada, o resultado de alguns cálculos de ponto flutuante pode ser diferente daqueles produzidos por outras opções de `/fp`. Valores especiais (NaN, + Infinity,-Infinity,-0,0) não podem ser propagados ou se comportam estritamente de acordo com o padrão IEEE-754. As contratações de ponto flutuante podem ser geradas em `/fp:fast`. O compilador ainda é associado pela arquitetura subjacente em `/fp:fast`, e otimizações adicionais podem estar disponíveis por meio do uso da opção [/Arch](arch-minimum-cpu-architecture.md) .

Em `/fp:fast`, o compilador gera o código destinado à execução no ambiente de ponto flutuante padrão e pressupõe que o ambiente de ponto flutuante não seja acessado ou modificado em tempo de execução. Ou seja, ele pressupõe que o código não mascara as exceções de ponto flutuante, leia ou grave registros de status de ponto flutuante ou altere os modos de arredondamento.

`/fp:fast` destina-se a programas que não exigem ordenação de código-fonte estrito e arredondamento de expressões de ponto flutuante e não dependem das regras padrão para manipular valores especiais, como NaN. Se o seu código de ponto flutuante exigir preservação de ordem e arredondamento de código-fonte, ou se depender do comportamento padrão de valores especiais, use [/fp: preciso](#precise). Se o seu código acessa ou modifica o ambiente de ponto flutuante para alterar os modos de arredondamento, desmascarar exceções de ponto flutuante ou verificar o status de ponto flutuante, use [/fp: strict](#strict).

#### <a name="except"></a>excepção

A opção `/fp:except` gera código para garantir que quaisquer exceções de ponto flutuante sem máscara sejam geradas no ponto exato em que ocorrem e que nenhuma exceção de ponto flutuante adicional seja gerada. Por padrão, a opção `/fp:strict` habilita `/fp:except`e `/fp:precise` não. A opção `/fp:except` não é compatível com `/fp:fast`. A opção pode ser explicitamente desabilitada por nós da `/fp:except-`.

Observe que `/fp:except` não habilita nenhuma exceção de ponto flutuante por si só, mas é necessário para que os programas habilitem as exceções de ponto flutuante. Consulte [_controlfp](../../c-runtime-library/reference/control87-controlfp-control87-2.md) para obter informações sobre como habilitar exceções de ponto flutuante.

## <a name="remarks"></a>Comentários

Várias opções de `/fp` podem ser especificadas na mesma linha de comando do compilador. Somente uma das opções `/fp:strict`, `/fp:fast`e `/fp:precise` pode estar em vigor de cada vez. Se mais de uma dessas opções for especificada na linha de comando, a opção mais tarde terá precedência e o compilador gerará um aviso. As opções `/fp:strict` e `/fp:except` não são compatíveis com `/clr`.

A opção [/za](za-ze-disable-language-extensions.md) (compatibilidade com ANSI) não é compatível com `/fp`.

### <a name="using-compiler-directives-to-control-floating-point-behavior"></a>Usando diretivas de compilador para controlar o comportamento de ponto flutuante

O compilador fornece três diretivas pragma para substituir o comportamento de ponto flutuante especificado na linha de comando: [float_control](../../preprocessor/float-control.md), [fenv_access](../../preprocessor/fenv-access.md)e [fp_contract](../../preprocessor/fp-contract.md). Você pode usar essas diretivas para controlar o comportamento de ponto flutuante em nível de função, não dentro de uma função. Observe que essas diretivas não correspondem diretamente às opções de `/fp`. Esta tabela mostra como as instruções de `/fp` e as diretivas pragma são mapeadas entre si. Para obter mais informações, consulte a documentação para as instruções individuais e as diretivas de pragma.

||float_control (preciso)|float_control(except)|fenv_access|fp_contract|
|-|-|-|-|-|
|`/fp:fast`|Desligar|Desligar|Desligar|em|
|`/fp:precise`|em|Desligar|Desligar|em|
|`/fp:strict`|em|em|em|Desligar|

### <a name="the-default-floating-point-environment"></a>O ambiente de ponto flutuante padrão

Quando um processo é inicializado, o *ambiente de ponto flutuante padrão* é definido. Esse ambiente mascara todas as exceções de ponto flutuante, define o modo de arredondamento para arredondar para o mais próximo (`FE_TONEAREST`), preserva os valores de subnormal (desnormal), usa a precisão padrão de significante (mantissa) para valores **duplos** **flutuantes**, **duplos**e longos, e quando há suporte, define o controle de infinito como o modo de afinidade padrão.

### <a name="floating-point-environment-access-and-modification"></a>Acesso e modificação do ambiente de ponto flutuante

O Microsoft Visual C++ Runtime fornece várias funções para acessar e modificar o ambiente de ponto flutuante. Isso inclui [_controlfp](../../c-runtime-library/reference/control87-controlfp-control87-2.md), [_clearfp](../../c-runtime-library/reference/clear87-clearfp.md)e [_statusfp](../../c-runtime-library/reference/status87-statusfp-statusfp2.md) e suas variantes. Para garantir o comportamento correto do programa quando seu código acessa ou modifica o ambiente de ponto flutuante, `fenv_access` deve ser habilitado, seja pela opção `/fp:strict` ou pelo uso do `fenv_access` pragma, para que essas funções tenham qualquer efeito. Quando `fenv_access` não está habilitado, o acesso ou a modificação do ambiente de ponto flutuante pode resultar em um comportamento de programa inesperado: o código pode não honrar as alterações solicitadas no ambiente de ponto flutuante; os registros de status de ponto flutuante podem não relatar os resultados esperados ou atuais; e exceções inesperadas de ponto flutuante podem ocorrer ou exceções de ponto flutuante esperadas podem não ocorrer.

Quando seu código acessa ou modifica o ambiente de ponto flutuante, você deve ter cuidado ao combinar o código em que `fenv_access` está habilitado com código que não tem `fenv_access` habilitado. No código em que `fenv_access` não está habilitado, o compilador pressupõe que o ambiente de ponto flutuante padrão da plataforma esteja em vigor e que o status do ponto flutuante não seja acessado ou modificado. Recomendamos que você salve e restaure o ambiente de ponto flutuante local para seu estado padrão antes de o controle ser transferido para uma função que não tem `fenv_access` habilitado. Este exemplo demonstra como o `float_control` pragma pode ser definido e restaurado:

```cpp
#pragma float_control(strict, on, push)
// Code that uses /fp:strict mode
#pragma float_control(pop)
```

### <a name="floating-point-rounding-modes"></a>Modos de arredondamento de ponto flutuante

Em ambos `/fp:precise` e `/fp:fast` o compilador gera o código destinado à execução no ambiente de ponto flutuante padrão e pressupõe que o ambiente não seja acessado ou modificado no tempo de execução. Ou seja, ele pressupõe que o código não mascara as exceções de ponto flutuante, leia ou grave registros de status de ponto flutuante ou altere os modos de arredondamento.  No entanto, alguns programas precisam alterar o ambiente de ponto flutuante. Por exemplo, este exemplo computa limites de erro de uma multiplicação de ponto flutuante alterando os modos de arredondamento de ponto flutuante:

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

Como o compilador assume o ambiente de ponto flutuante padrão em `/fp:fast` e `/fp:precise` é livre para ignorar as chamadas para `_controlfp_s`. Por exemplo, quando compilado usando `/O2` e `/fp:precise` para a arquitetura x86, os limites não são computados e o programa de exemplo gera:

```Output
cLower = -inf
cUpper = -inf
```

Quando compilado com `/O2` e `/fp:strict` para a arquitetura x86, o programa de exemplo gera:

```Output
cLower = -inf
cUpper = -3.40282e+38
```

### <a name="floating-point-special-values"></a>Valores especiais de ponto flutuante

Em `/fp:precise` e `/fp:strict`, as expressões que envolvem valores especiais (NaN, + Infinity,-Infinity,-0,0) se comportam de acordo com as especificações de IEEE-754. Em `/fp:fast`, o comportamento desses valores especiais pode ser inconsistente com o IEEE-754.

Este exemplo demonstra o comportamento diferente de valores especiais em `/fp:precise`, `/fp:strict` e `/fp:fast`:

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

Quando compilado com `/O2` `/fp:precise` ou `/O2` `/fp:strict` para arquitetura x86, as saídas são consistentes com a especificação IEEE-754:

```Output
INFINITY == INFINITY : 1
NAN == NAN           : 0
INFINITY - INFINITY  : -nan(ind)
NAN - NAN            : -nan(ind)
std::signbit(-0.0/-INFINITY): 1
```

Quando compilado com `/O2` `/fp:fast` para arquitetura x86, as saídas não são consistentes com o IEEE-754:

```Output
INFINITY == INFINITY : 1
NAN == NAN           : 1
INFINITY - INFINITY  : 0.000000
NAN - NAN            : 0.000000
std::signbit(-0.0/-INFINITY): 0
```

### <a name="floating-point-algebraic-transformations"></a>Transformações de algébricas de ponto flutuante

Em `/fp:precise` e `/fp:strict`, o compilador não executa transformações matemáticas, a menos que haja garantia de que a transformação produza um resultado de bit idêntico. O compilador pode executar essas transformações em `/fp:fast`. Por exemplo, a expressão `a * b + a * c` na função de exemplo `algebraic_transformation` pode ser compilada em `a * (b + c)` em `/fp:fast`. Essas transformações não são executadas em `/fp:precise` ou `/fp:strict`e o compilador gera `a * b + a * c`.

```cpp
float algebraic_transformation (float a, float b, float c)
{
    return a * b + a * c;
}
```

### <a name="floating-point-explicit-casting-points"></a>Pontos de conversão explícitos de ponto flutuante

Em `/fp:precise` e `/fp:strict`, o compilador arredonda para a precisão do código-fonte em quatro pontos específicos durante a avaliação da expressão: em atribuições, em typecasts, quando um argumento de ponto flutuante é passado para uma chamada de função e quando um valor de ponto flutuante é retornado de uma chamada de função. Typecasts pode ser usado para arredondar explicitamente cálculos intermediários. Em `/fp:fast`, o compilador não gera conversões explícitas nesses pontos para garantir a precisão do código-fonte. Este exemplo demonstra o comportamento em diferentes opções de `/fp`:

```cpp
float casting(float a, float b)
{
    return 5.0*((double)(a+b));
}
```

Quando compilado usando `/O2` `/fp:precise` ou `/O2` `/fp:strict`, você pode ver que as conversões explícitas de tipo são inseridas no conversão e no ponto de retorno da função no código gerado para a arquitetura x64:

```asm
        addss    xmm0, xmm1
        cvtss2sd xmm0, xmm0
        mulsd    xmm0, QWORD PTR __real@4014000000000000
        cvtsd2ss xmm0, xmm0
        ret      0
```

Em `/O2` `/fp:fast` o código gerado é simplificado, pois todas as conversões de tipo são otimizadas para longe:

```asm
        addss    xmm0, xmm1
        mulss    xmm0, DWORD PTR __real@40a00000
        ret      0
```

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione as **Propriedades de configuração** > página de propriedades de **geração de código** **C/C++**  > .

1. Modifique a propriedade do **modelo de ponto flutuante** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.floatingPointModel%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
