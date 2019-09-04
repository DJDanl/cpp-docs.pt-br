---
title: _control87, _controlfp, __control87_2
ms.date: 08/29/2019
apiname:
- _control87
- _controlfp
- __control87_2
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _control87
- __control87_2
- control87
- _controlfp
- controlfp
- control87_2
- _control87_2
helpviewer_keywords:
- floating-point numbers, control word
- _control87 function
- control87 function
- controlfp function
- _controlfp function
- __control87_2 function
- floating-point functions, setting control word
- floating-point functions
- EM_AMBIGUOUS
- control87_2 function
ms.assetid: 0d09729d-d9a0-43d6-864c-43ff25e7e0c5
ms.openlocfilehash: 75b2870543ec3ddd20d445a492ad4270b91e80d7
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70218424"
---
# <a name="_control87-_controlfp-__control87_2"></a>_control87, _controlfp, __control87_2

Obtém e define a palavra de controle de ponto flutuante. Uma versão mais segura do **_controlfp** está disponível; consulte [_controlfp_s](controlfp-s.md).

## <a name="syntax"></a>Sintaxe

```C
unsigned int _control87(
   unsigned int new,
   unsigned int mask
);
unsigned int _controlfp(
   unsigned int new,
   unsigned int mask
);
int __control87_2(
   unsigned int new,
   unsigned int mask,
   unsigned int* x86_cw,
   unsigned int* sse2_cw
);
```

### <a name="parameters"></a>Parâmetros

*new*\
Novos valores de bit da palavra de controle.

*mascara*\
Máscara para novos bits da palavra de controle a ser definida.

*x86_cw*\
Preenchido com a palavra de controle da unidade de ponto flutuante x87. Passe 0 (**NULL**) para definir apenas a palavra de controle SSE2.

*sse2_cw*\
Palavra de controle da unidade de ponto flutuante SSE. Passe 0 (**NULL**) para definir apenas a palavra de controle x87.

## <a name="return-value"></a>Valor retornado

Para **_control87** e **_controlfp**, os bits no valor retornado indicam o estado de controle de ponto flutuante. Para obter uma definição completa dos bits retornados por **_control87**, consulte Float. T.

Para **__control87_2**, o valor de retorno é 1, que indica êxito.

## <a name="remarks"></a>Comentários

A função **_control87** Obtém e define a palavra de controle de ponto flutuante. A palavra de controle de ponto flutuante permite que o programa altere os modos de precisão, arredondamento e infinito, dependendo da plataforma. Você também pode usar **_control87** para mascarar ou desmascarar as exceções de ponto flutuante. Se o valor de *Mask* for igual a 0, **_control87** obterá a palavra de controle de ponto flutuante. Se *Mask* for diferente de zero, um novo valor para a palavra de controle será definido: Para qualquer bit que esteja em (ou seja, igual a 1) na *máscara*, o bit correspondente em *New* é usado para atualizar a palavra de controle. Em outras palavras, **fpcntrl** = ((**fpcntrl** & ~*Mask*) &#124; (*nova* & *máscara*)) em que **fpcntrl** é a palavra de controle de ponto flutuante.

> [!NOTE]
> Por padrão, as bibliotecas em tempo de execução mascaram todas as exceções de ponto flutuante.

**_controlfp** é uma versão portátil e independente de plataforma do **_control87** que é quase idêntica à função **_control87** . Se seu código tiver como alvo mais de uma plataforma, use **_controlfp** ou **_controlfp_s**. A diferença entre **_control87** e **_controlfp** está em como eles TRATAm valores desnormals. Para plataformas x86, x64, ARM e ARM64, **_control87** pode definir e limpar a máscara de exceção de operando desnormal. **_controlfp** não modifica a máscara de exceção de operando desnormal. Este exemplo demonstra a diferença:

```C
_control87( _EM_INVALID, _MCW_EM );
// DENORMAL is unmasked by this call
_controlfp( _EM_INVALID, _MCW_EM );
// DENORMAL exception mask remains unchanged
```

Os valores possíveis para a constante de máscara (*Mask*) e os novos valores de controle (*New*) são mostrados na tabela de máscaras e valores de palavras de controle. Use as constantes portáteis listadas abaixo ( **_MCW_EM**, **_EM_INVALID**e assim por diante) como argumentos para essas funções, em vez de fornecer os valores hexadecimais explicitamente.

As plataformas derivadas da Intel x86 dão suporte aos valores de entrada e saída desnormales no hardware. O comportamento do x86 é preservar valores DENORMAL. As plataformas ARM e ARM64 e as plataformas x64 que têm suporte SSE2 permitem que operandos e resultados desnormals sejam liberados ou forçados a zero. As funções **_controlfp** e **_control87** fornecem uma máscara para alterar esse comportamento. O exemplo a seguir demonstra o uso dessa máscara.

```C
_controlfp(_DN_SAVE, _MCW_DN);
// Denormal values preserved on ARM platforms and on x64 processors with
// SSE2 support. NOP on x86 platforms.
_controlfp(_DN_FLUSH, _MCW_DN);
// Denormal values flushed to zero by hardware on ARM platforms
// and x64 processors with SSE2 support. Ignored on other x86 platforms.
```

Nas plataformas ARM e ARM64, as funções **_control87** e **_controlfp** se aplicam ao registro FPSCR. Somente a palavra de controle SSE2 armazenada no registro MXCSR é afetada em plataformas x64. Em plataformas x86, **_control87** e **_controlfp** afetam as palavras de controle para o x87 e o SSE2, se presente.

A função **__control87_2** permite que as unidades de ponto flutuante x87 e SSE2 sejam controladas juntas ou separadas. Para afetar ambas as unidades, passe os endereços de dois inteiros para **x86_cw** e **sse2_cw**. Se você quiser apenas afetar uma unidade, passe um endereço para esse parâmetro, mas passe em 0 (**NULL**) para o outro. Se 0 for passado para um desses parâmetros, a função não terá efeito sobre essa unidade de ponto flutuante. É útil quando parte do seu código usa a unidade de ponto flutuante x87 e outra parte usa a unidade de ponto flutuante SSE2.

Se você usar **__control87_2** para definir valores diferentes para as palavras de controle de ponto flutuante, **_control87** ou **_controlfp** poderá não conseguir retornar uma única palavra de controle para representar o estado de ambas as unidades de ponto flutuante. Nesse caso, essas funções definem o sinalizador **EM_AMBIGUOUS** no valor inteiro retornado para indicar uma inconsistência entre as duas palavras de controle. O sinalizador **EM_AMBIGUOUS** é um aviso de que a palavra de controle retornada pode não representar o estado de palavras de controle de ponto flutuante com precisão.

Nas plataformas ARM, ARM64 e x64, não há suporte para alterar o modo infinito ou a precisão de ponto flutuante. Se a máscara de controle de precisão for usada na plataforma x64, a função gerará uma asserção e o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md).

> [!NOTE]
> Não há suporte para **__control87_2** nas plataformas ARM, ARM64 ou x64. Se você usar **__control87_2** e compilar seu programa para as plataformas ARM, ARM64 ou x64, o compilador gerará um erro.

Essas funções são ignoradas quando você usa a [compilação/CLR (Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md) para compilar. O Common Language Runtime (CLR) só dá suporte à precisão de ponto flutuante padrão.

### <a name="control-word-masks-and-values"></a>Controlar máscaras e valores de palavras

Para a máscara **_MCW_EM** , limpar a máscara define a exceção, que permite a exceção de hardware; a definição da máscara oculta a exceção. Se ocorrer um **_EM_UNDERFLOW** ou **_EM_OVERFLOW** , nenhuma exceção de hardware será lançada até que a próxima instrução de ponto flutuante seja executada. Para gerar uma exceção de hardware imediatamente após **_EM_UNDERFLOW** ou **_EM_OVERFLOW**, chame a instrução **fwait** MASM.

|Máscara|Valor hex.|Constante|Valor hex.|
|----------|---------------|--------------|---------------|
|**_MCW_DN** (Controle desnormal)|0x03000000|**_DN_SAVE**<br /><br /> **_DN_FLUSH**|0x00000000<br /><br /> 0x01000000|
|**_MCW_EM** (Máscara de exceção de interrupção)|0x0008001F|**_EM_INVALID**<br /><br /> **_EM_DENORMAL**<br /><br /> **_EM_ZERODIVIDE**<br /><br /> **_EM_OVERFLOW**<br /><br /> **_EM_UNDERFLOW**<br /><br /> **_EM_INEXACT**|0x00000010<br /><br /> 0x00080000<br /><br /> 0x00000008<br /><br /> 0x00000004<br /><br /> 0x00000002<br /><br /> 0x00000001|
|**_MCW_IC** (Controle de infinito)<br /><br /> (Sem suporte em plataformas ARM ou x64.)|0x00040000|**_IC_AFFINE**<br /><br /> **_IC_PROJECTIVE**|0x00040000<br /><br /> 0x00000000|
|**_MCW_RC** (Controle de arredondamento)|0x00000300|**_RC_CHOP**<br /><br /> **_RC_UP**<br /><br /> **_RC_DOWN**<br /><br /> **_RC_NEAR**|0x00000300<br /><br /> 0x00000200<br /><br /> 0x00000100<br /><br /> 0x00000000|
|**_MCW_PC** (Controle de precisão)<br /><br /> (Sem suporte em plataformas ARM ou x64.)|0x00030000|**_PC_24** (24 bits)<br /><br /> **_PC_53** (53 bits)<br /><br /> **_PC_64** (64 bits)|0x00020000<br /><br /> 0x00010000<br /><br /> 0x00000000|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_control87**, **_controlfp**, **_control87_2**|\<float.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_cntrl87.c
// processor: x86
// compile by using: cl /W4 /arch:IA32 crt_cntrl87.c
// This program uses __control87_2 to output the x87 control
// word, set the precision to 24 bits, and reset the status to
// the default.

#include <stdio.h>
#include <float.h>
#pragma fenv_access (on)

int main( void )
{
    double a = 0.1;
    unsigned int control_word_x87 = 0;
    int result;

    // Show original x87 control word and do calculation.
    result = __control87_2(0, 0, &control_word_x87, 0 );
    printf( "Original: 0x%.8x\n", control_word_x87 );
    printf( "%1.1f * %1.1f = %.15e\n", a, a, a * a );

    // Set precision to 24 bits and recalculate.
    result = __control87_2(_PC_24, MCW_PC, &control_word_x87, 0 );
    printf( "24-bit:   0x%.8x\n", control_word_x87 );
    printf( "%1.1f * %1.1f = %.15e\n", a, a, a * a );

    // Restore default precision-control bits and recalculate.
    result = __control87_2( _CW_DEFAULT, MCW_PC, &control_word_x87, 0 );
    printf( "Default:  0x%.8x\n", control_word_x87 );
    printf( "%1.1f * %1.1f = %.15e\n", a, a, a * a );
}
```

```Output
Original: 0x0009001f
0.1 * 0.1 = 1.000000000000000e-02
24-bit:   0x000a001f
0.1 * 0.1 = 9.999999776482582e-03
Default:  0x0009001f
0.1 * 0.1 = 1.000000000000000e-02
```

## <a name="see-also"></a>Consulte também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)\
[_clear87, _clearfp](clear87-clearfp.md)\
[_status87, _statusfp, _statusfp2](status87-statusfp-statusfp2.md)\
[_controlfp_s](controlfp-s.md)
