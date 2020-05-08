---
title: _controlfp_s
ms.date: 4/2/2020
api_name:
- _controlfp_s
- _o__controlfp_s
api_location:
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
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- controlfp_s
- _controlfp_s
helpviewer_keywords:
- floating-point numbers, control word
- controlfp_s function
- floating-point functions, setting control word
- EM_AMBIGUOUS
- _controlfp_s function
ms.assetid: a51fc3f6-ab13-41f0-b227-6bf02d98e987
ms.openlocfilehash: 0e734a0286ac21ed0883cc10b0cd4ee5857ba448
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82917258"
---
# <a name="_controlfp_s"></a>_controlfp_s

Obtém e define a palavra de controle de ponto flutuante. Esta versão de [_control87, _controlfp, \__control87_2](control87-controlfp-control87-2.md) traz melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t _controlfp_s(
    unsigned int *currentControl,
    unsigned int newControl,
    unsigned int mask
);
```

### <a name="parameters"></a>Parâmetros

*currentControl*<br/>
O valor de bit da palavra de controle atual.

*newControl*<br/>
Novos valores de bit da palavra de controle.

*mask*<br/>
Máscara para novos bits da palavra de controle a ser definida.

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido ou um código de erro de valor **errno** .

## <a name="remarks"></a>Comentários

A função **_controlfp_s** é uma versão independente de plataforma e mais segura do **_control87**, que obtém a palavra de controle de ponto flutuante no endereço armazenado em *CurrentControl* e a define usando *newControl*. Os bits nos valores indicam o estado do controle de ponto flutuante. O estado do controle de ponto flutuante permite que o programa altere os modos de precisão, arredondamento e infinito no pacote de matemática de ponto flutuante, dependendo da plataforma. Você também pode usar **_controlfp_s** para mascarar ou desmascarar as exceções de ponto flutuante.

Se o valor de *Mask* for igual a 0, **_controlfp_s** obterá a palavra de controle de ponto flutuante e armazenará o valor recuperado em *CurrentControl*.

Se *Mask* for diferente de zero, um novo valor para a palavra de controle será definido: para qualquer bit definido (ou seja, igual a 1) em *Mask*, o bit correspondente em *New* será usado para atualizar a palavra de controle. Em outras palavras, *fpcntrl* = ((*fpcntrl* & ~*Mask*) &#124; (*newControl* & *máscara*newControl)) em que *fpcntrl* é a palavra de controle de ponto flutuante. Nesse cenário, *CurrentControl* é definido como o valor após a alteração ser concluída; Não é o valor de bit de palavra de controle antigo.

> [!NOTE]
> Por padrão, as bibliotecas em tempo de execução mascaram todas as exceções de ponto flutuante.

**_controlfp_s** é quase idêntica à função **_Control87** nas plataformas Intel (x86), x64 e ARM. Se você estiver visando plataformas x86, x64 ou ARM, poderá usar **_control87** ou **_controlfp_s**.

A diferença entre **_control87** e **_controlfp_s** está em como eles tratam valores desnormals. Para plataformas Intel (x86), x64 e ARM, **_control87** pode definir e limpar a máscara de exceção de operando desnormal. **_controlfp_s** não modifica a máscara de exceção de operando desnormal. Este exemplo demonstra a diferença:

```C
_control87( _EM_INVALID, _MCW_EM );
// DENORMAL is unmasked by this call.
unsigned int current_word = 0;
_controlfp_s( &current_word, _EM_INVALID, _MCW_EM );
// DENORMAL exception mask remains unchanged.
```

Os valores possíveis para a constante de máscara (*Mask*) e os novos valores de controle (*newControl*) são mostrados na tabela de valores hexadecimais a seguir. Use as constantes portáteis listadas abaixo (**_MCW_EM**, **_EM_INVALID**e assim por diante) como argumentos para essas funções, em vez de fornecer os valores hexadecimais explicitamente.

Plataformas derivadas da Intel (x86) dão suporte a valores de entrada e saída DENORMAL em hardware. O comportamento do x86 é preservar valores DENORMAL. A plataforma ARM e as plataformas x64 que têm suporte SSE2 permitem que operandos e resultados desnormals sejam liberados ou forçados a zero. As funções **_controlfp_s**, **_controlfp**e **_control87** fornecem uma máscara para alterar esse comportamento. O seguinte exemplo demonstra o uso dessa máscara:

```C
unsigned int current_word = 0;
_controlfp_s(&current_word, _DN_SAVE, _MCW_DN);
// Denormal values preserved on ARM platforms and on x64 processors with
// SSE2 support. NOP on x86 platforms.
_controlfp_s(&current_word, _DN_FLUSH, _MCW_DN);
// Denormal values flushed to zero by hardware on ARM platforms
// and x64 processors with SSE2 support. Ignored on other x86 platforms.
```

Em plataformas ARM, a função **_controlfp_s** se aplica ao registro FPSCR. Em arquiteturas x64, somente a palavra de controle SSE2 armazenada no registro MXCSR é afetada. Em plataformas Intel (x86), **_controlfp_s** afeta as palavras de controle para x87 e SSE2, se presente. É possível que as duas palavras de controle sejam inconsistentes entre si (devido a uma chamada anterior para [__control87_2](control87-controlfp-control87-2.md), por exemplo); Se houver uma inconsistência entre as duas palavras de controle, **_controlfp_s** definirá o sinalizador de **EM_AMBIGUOUS** em *CurrentControl*. Esse é um aviso indicando que a palavra de controle retornada poderá não representar o estado de ambas as palavras de controle de ponto flutuante com precisão.

Nas arquiteturas ARM e x64, não há suporte para alterar o modo infinito ou a precisão de ponto flutuante. Se a máscara de controle de precisão for usada na plataforma x64, a função gerará uma asserção e o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md).

Se a máscara não estiver definida corretamente, essa função gerará uma exceção de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essa função retornará **EINVAL** e definirá **errno** como **EINVAL**.

Essa função é ignorada quando você usa a [compilação/CLR (Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md) para compilar porque o Common Language Runtime (CLR) só dá suporte à precisão de ponto flutuante padrão.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

### <a name="mask-constants-and-values"></a>Mascarar valores e constantes

Para a máscara de **_MCW_EM** , limpá-la define a exceção, que permite a exceção de hardware; configurá-lo oculta a exceção. Se ocorrer uma **_EM_UNDERFLOW** ou **_EM_OVERFLOW** , nenhuma exceção de hardware será lançada até que a próxima instrução de ponto flutuante seja executada. Para gerar uma exceção de hardware imediatamente após **_EM_UNDERFLOW** ou **_EM_OVERFLOW**, chame a instrução fwait MASM.

|Mask|Valor hex.|Constante|Valor hex.|
|----------|---------------|--------------|---------------|
|**_MCW_DN** (controle desnormal)|0x03000000|**_DN_SAVE**<br /><br /> **_DN_FLUSH**|0x00000000<br /><br /> 0x01000000|
|**_MCW_EM** (máscara de exceção de interrupção)|0x0008001F|**_EM_INVALID**<br /><br /> **_EM_DENORMAL**<br /><br /> **_EM_ZERODIVIDE**<br /><br /> **_EM_OVERFLOW**<br /><br /> **_EM_UNDERFLOW**<br /><br /> **_EM_INEXACT**|0x00000010<br /><br /> 0x00080000<br /><br /> 0x00000008<br /><br /> 0x00000004<br /><br /> 0x00000002<br /><br /> 0x00000001|
|**_MCW_IC** (controle de infinito)<br /><br /> (Sem suporte em plataformas ARM ou x64.)|0x00040000|**_IC_AFFINE**<br /><br /> **_IC_PROJECTIVE**|0x00040000<br /><br /> 0x00000000|
|**_MCW_RC** (controle de arredondamento)|0x00000300|**_RC_CHOP**<br /><br /> **_RC_UP**<br /><br /> **_RC_DOWN**<br /><br /> **_RC_NEAR**|0x00000300<br /><br /> 0x00000200<br /><br /> 0x00000100<br /><br /> 0x00000000|
|**_MCW_PC** (controle de precisão)<br /><br /> (Sem suporte em plataformas ARM ou x64.)|0x00030000|**_PC_24** (24 bits)<br /><br /> **_PC_53** (53 bits)<br /><br /> **_PC_64** (64 bits)|0x00020000<br /><br /> 0x00010000<br /><br /> 0x00000000|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_controlfp_s**|\<float.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_contrlfp_s.c
// processor: x86
// This program uses _controlfp_s to output the FP control
// word, set the precision to 24 bits, and reset the status to
// the default.

#include <stdio.h>
#include <float.h>
#pragma fenv_access (on)

int main( void )
{
    double a = 0.1;
    unsigned int control_word;
    int err;

    // Show original FP control word and do calculation.
    err = _controlfp_s(&control_word, 0, 0);
    if ( err ) /* handle error here */;

    printf( "Original: 0x%.4x\n", control_word );
    printf( "%1.1f * %1.1f = %.15e\n", a, a, a * a );

    // Set precision to 24 bits and recalculate.
    err = _controlfp_s(&control_word, _PC_24, MCW_PC);
    if ( err ) /* handle error here */;

    printf( "24-bit:   0x%.4x\n", control_word );
    printf( "%1.1f * %1.1f = %.15e\n", a, a, a * a );

    // Restore default precision-control bits and recalculate.
    err = _controlfp_s(&control_word, _CW_DEFAULT, MCW_PC);
    if ( err ) /* handle error here */;

    printf( "Default:  0x%.4x\n", control_word );
    printf( "%1.1f * %1.1f = %.15e\n", a, a, a * a );
}
```

```Output
Original: 0x9001f
0.1 * 0.1 = 1.000000000000000e-002
24-bit:   0xa001f
0.1 * 0.1 = 9.999999776482582e-003
Default:  0x9001f
0.1 * 0.1 = 1.000000000000000e-002
```

## <a name="see-also"></a>Confira também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[_clear87, _clearfp](clear87-clearfp.md)<br/>
[_status87, _statusfp, _statusfp2](status87-statusfp-statusfp2.md)<br/>
[_control87, _controlfp, \__control87_2](control87-controlfp-control87-2.md)<br/>
