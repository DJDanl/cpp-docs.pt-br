---
title: _controlfp_s | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _controlfp_s
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
- controlfp_s
- _controlfp_s
dev_langs:
- C++
helpviewer_keywords:
- floating-point numbers, control word
- controlfp_s function
- floating-point functions, setting control word
- EM_AMBIGUOUS
- _controlfp_s function
ms.assetid: a51fc3f6-ab13-41f0-b227-6bf02d98e987
caps.latest.revision: 28
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 559e3fcd0a4e5d7f71ff4644fa0fd58c9fb20137
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="controlfps"></a>_controlfp_s

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

*Máscara*<br/>
Máscara para novos bits da palavra de controle a ser definida.

## <a name="return-value"></a>Valor de retorno

Zero se tiver êxito, ou um **errno** valor de código de erro.

## <a name="remarks"></a>Comentários

O **controlfp_s** função é uma versão mais segura e independente de plataforma do **control87**, que obtém a palavra de controle de ponto flutuante para o endereço que é armazenado em  *currentControl* e define-a usando *newControl*. Os bits nos valores indicam o estado do controle de ponto flutuante. O estado do controle de ponto flutuante permite que o programa altere os modos de precisão, arredondamento e infinito no pacote de matemática de ponto flutuante, dependendo da plataforma. Você também pode usar **controlfp_s** para mascarar ou Retirar máscara exceções de ponto flutuante.

Se o valor de *máscara* é igual a 0, **controlfp_s** obtém a palavra de controle de ponto flutuante e armazena o valor recuperado no *currentControl*.

Se *máscara* é diferente de zero, um novo valor para a palavra de controle é definido: para qualquer bit que é definido (isto é, igual a 1) em *máscara*, o bit correspondente em *novo* é usado para atualizar o controle Word. Em outras palavras, *fpcntrl* = ((*fpcntrl* & ~*máscara*) &#124; (*newControl* & *máscara* )) onde *fpcntrl* é a palavra de controle de ponto flutuante. Nesse cenário, *currentControl* é definido como o valor após a conclusão da alteração; ele não é o valor de bit de palavra de controle antigo.

> [!NOTE]
> Por padrão, as bibliotecas em tempo de execução mascaram todas as exceções de ponto flutuante.

**controlfp_s** é praticamente idêntica do **control87** (x86), x64 e ARM plataformas de função na Intel. Se você estiver direcionando plataformas ARM, x64 ou x86, você pode usar **control87** ou **controlfp_s**.

A diferença entre **control87** e **controlfp_s** está em como elas tratam desnormalizado valores. Para Intel (x86), x64 e plataformas ARM, **control87** podem ser definidas e desmarque a máscara de exceção DESNORMALIZADO OPERANDO. **controlfp_s** não modifica a máscara de exceção DESNORMALIZADO OPERANDO. Este exemplo demonstra a diferença:

```C
_control87( _EM_INVALID, _MCW_EM );
// DENORMAL is unmasked by this call.
unsigned int current_word = 0;
_controlfp_s( &current_word, _EM_INVALID, _MCW_EM );
// DENORMAL exception mask remains unchanged.
```

Os valores possíveis para a constante máscara (*máscara*) e novos valores de controle (*newControl*) são mostrados na tabela a seguir de valores hexadecimais. Use as constantes portátil listadas abaixo (**_MCW_EM**, **_EM_INVALID**, e assim por diante) como argumentos para essas funções, em vez de fornecer o hexadecimal valores explicitamente.

Plataformas derivadas da Intel (x86) dão suporte a valores de entrada e saída DENORMAL em hardware. O comportamento do x86 é preservar valores DENORMAL. A plataforma ARM e suportam a plataformas SSE2 x64 habilitar ANORMAL operandos e os resultados a serem liberados ou forçados para zero. O **controlfp_s**, **controlfp**, e **control87** funções fornecem uma máscara para alterar esse comportamento. O seguinte exemplo demonstra o uso dessa máscara:

```C
unsigned int current_word = 0;
_controlfp_s(&current_word, _DN_SAVE, _MCW_DN);
// Denormal values preserved on ARM platforms and on x64 processors with
// SSE2 support. NOP on x86 platforms.
_controlfp_s(&current_word, _DN_FLUSH, _MCW_DN);
// Denormal values flushed to zero by hardware on ARM platforms
// and x64 processors with SSE2 support. Ignored on other x86 platforms.
```

Em plataformas ARM, o **controlfp_s** função aplica-se ao registro FPSCR. Em x64 arquiteturas, apenas a palavra de controle SSE2 é armazenado no MXCSR registro é afetado. Em plataformas de Intel (x86) **controlfp_s** afeta as palavras de controle para o x87 e SSE2, se presente. É possível que as palavras controle inconsistentes entre si (devido a uma chamada anterior a [__control87_2](control87-controlfp-control87-2.md), por exemplo); se não houver uma inconsistência entre as palavras de controle, **controlfp_s** define o **EM_AMBIGUOUS** sinalizador em *currentControl*. Esse é um aviso indicando que a palavra de controle retornada poderá não representar o estado de ambas as palavras de controle de ponto flutuante com precisão.

O ARM e x64 arquiteturas, alterando o modo de infinito ou a precisão de ponto flutuante não são suportadas. Se a máscara de controle de precisão é usada em x64 plataforma, a função gera uma asserção e o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md).

Se a máscara não estiver definida corretamente, essa função gerará uma exceção de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essa função retorna **EINVAL** e define **errno** para **EINVAL**.

Essa função é ignorada quando você usar [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) compilação porque o common language runtime (CLR) suporta apenas a precisão de ponto flutuante padrão.

### <a name="mask-constants-and-values"></a>Constantes de máscara e valores

Para o **_MCW_EM** máscara, desmarcá-la define a exceção, o que permite que a exceção de hardware; definição oculta a exceção. Se um **_EM_UNDERFLOW** ou **_EM_OVERFLOW** ocorre, nenhuma exceção de hardware é lançada até que a próxima instrução de ponto flutuante é executada. Para gerar uma exceção de hardware imediatamente após **_EM_UNDERFLOW** ou **_EM_OVERFLOW**, chame a instrução FWAIT MASM.

|Máscara|Valor hex.|Constante|Valor hex.|
|----------|---------------|--------------|---------------|
|**_MCW_DN** (desnormalizado controle)|0x03000000|**_DN_SAVE**<br /><br /> **_DN_FLUSH**|0x00000000<br /><br /> 0x01000000|
|**_MCW_EM** (máscara de exceção de interrupção)|0x0008001F|**_EM_INVALID**<br /><br /> **_EM_DENORMAL**<br /><br /> **_EM_ZERODIVIDE**<br /><br /> **_EM_OVERFLOW**<br /><br /> **_EM_UNDERFLOW**<br /><br /> **_EM_INEXACT**|0x00000010<br /><br /> 0x00080000<br /><br /> 0x00000008<br /><br /> 0x00000004<br /><br /> 0x00000002<br /><br /> 0x00000001|
|**_MCW_IC** (controle de infinito)<br /><br /> (Não plataformas com suporte no ARM ou x64.)|0x00040000|**_IC_AFFINE**<br /><br /> **_IC_PROJECTIVE**|0x00040000<br /><br /> 0x00000000|
|**_MCW_RC** (controle de arredondamento)|0x00000300|**_RC_CHOP**<br /><br /> **_RC_UP**<br /><br /> **_RC_DOWN**<br /><br /> **_RC_NEAR**|0x00000300<br /><br /> 0x00000200<br /><br /> 0x00000100<br /><br /> 0x00000000|
|**_MCW_PC** (controle de precisão)<br /><br /> (Não plataformas com suporte no ARM ou x64.)|0x00030000|**_PC_24** (24 bits)<br /><br /> **_PC_53** (53 bits)<br /><br /> **_PC_64** (64 bits)|0x00020000<br /><br /> 0x00010000<br /><br /> 0x00000000|

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

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[_clear87, _clearfp](clear87-clearfp.md)<br/>
[_status87, _statusfp, _statusfp2](status87-statusfp-statusfp2.md)<br/>
[_control87, _controlfp, \__control87_2](control87-controlfp-control87-2.md)<br/>
