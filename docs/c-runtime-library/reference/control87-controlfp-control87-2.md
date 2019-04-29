---
title: _control87, _controlfp, __control87_2
ms.date: 04/05/2018
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
ms.openlocfilehash: e2ebfdc80a451ebf02563f78a62dd08618f92bcd
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62340411"
---
# <a name="control87-controlfp-control872"></a>_control87, _controlfp, __control87_2

Obtém e define a palavra de controle de ponto flutuante. Uma versão mais segura **controlfp** está disponível; consulte [controlfp_s](controlfp-s.md).

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

*new*<br/>
Novos valores de bit da palavra de controle.

*mask*<br/>
Máscara para novos bits da palavra de controle a ser definida.

*x86_cw*<br/>
Preenchido com a palavra de controle da unidade de ponto flutuante x87. Passe 0 (**nulo**) para definir a palavra de controle SSE2.

*sse2_cw*<br/>
Palavra de controle da unidade de ponto flutuante SSE. Passe 0 (**nulo**) para definir apenas x87 palavra de controle.

## <a name="return-value"></a>Valor de retorno

Para **_control87** e **controlfp**, os bits no valor retornado indicam o estado de controle de ponto flutuante. Para obter uma definição completa dos bits retornados por **_control87**, consulte FLOAT. H.

Para **__control87_2**, o valor retornado é 1, que indica êxito.

## <a name="remarks"></a>Comentários

O **_control87** função obtém e define a palavra de controle de ponto flutuante. A palavra de controle de ponto flutuante permite que o programa altere os modos de precisão, arredondamento e infinito no pacote de matemática de ponto flutuante, dependendo da plataforma. Você também pode usar **_control87** para mascarar ou remover a máscara das exceções de ponto flutuante. Se o valor para *máscara* é igual a 0, **_control87** obtém a palavra de controle de ponto flutuante. Se *máscara* é diferente de zero, um novo valor para a palavra de controle é definido: Para qualquer bit que é em (ou seja, igual a 1) no *máscara*, o bit correspondente no *novos* é usado para atualizar a palavra de controle. Em outras palavras, **fpcntrl** = ((**fpcntrl** & ~*máscara*) &#124; (*novo* & *demáscara*)) em que **fpcntrl** é a palavra de controle de ponto flutuante.

> [!NOTE]
> Por padrão, as bibliotecas em tempo de execução mascaram todas as exceções de ponto flutuante.

**controlfp** é uma versão portátil, independente de plataforma do **_control87**. Ele é quase idêntico do **_control87** função em plataformas ARM, x64 e x86. Se você estiver visando plataformas ARM, x64 ou x86, use **_control87** ou **controlfp**.

A diferença entre **_control87** e **controlfp** está em como eles tratam valores DENORMAL. Para x86, x64 e plataformas ARM **_control87** pode definir e desmarcar a máscara de exceção DENORMAL OPERAND. **controlfp** não modifica a máscara de exceção DENORMAL OPERAND. Este exemplo demonstra a diferença:

```C
_control87( _EM_INVALID, _MCW_EM );
// DENORMAL is unmasked by this call
_controlfp( _EM_INVALID, _MCW_EM );
// DENORMAL exception mask remains unchanged
```

Os valores possíveis para a constante de máscara (*máscara*) e os novos valores de controle (*novos*) são mostrados na tabela de valores hexadecimais a seguir. Use as constantes portáteis listadas abaixo (**_MCW_EM**, **_EM_INVALID**e assim por diante) como argumentos para essas funções, em vez de fornecer o hexadecimal valores explicitamente.

Plataformas derivadas x86 da Intel dão suporte a entrada DENORMAL e valores no hardware de saída. O comportamento do x86 é preservar valores DENORMAL. A plataforma ARM e x64 dar suporte a plataformas que têm SSE2 permitem DENORMAL operandos e resultados sejam liberados ou forçados para zero. O **controlfp** e **_control87** funções fornecem uma máscara para alterar esse comportamento. O exemplo a seguir demonstra o uso dessa máscara.

```C
_controlfp(_DN_SAVE, _MCW_DN);
// Denormal values preserved on ARM platforms and on x64 processors with
// SSE2 support. NOP on x86 platforms.
_controlfp(_DN_FLUSH, _MCW_DN);
// Denormal values flushed to zero by hardware on ARM platforms
// and x64 processors with SSE2 support. Ignored on other x86 platforms.
```

Em plataformas ARM, o **_control87** e **controlfp** funções se aplicam ao registro fpscr. No x64 arquiteturas, apenas a palavra de controle SSE2 armazenada no registro MXCSR é afetada. Em x86 plataformas **_control87** e **controlfp** afetam as palavras de controle do x87 e SSE2, se estiver presente. A função **__control87_2** permite x87 e unidades de ponto flutuante de SSE2 sejam controladas juntas ou separadamente. Se você quiser afetar as duas unidades, passe os endereços dos dois inteiros serem **x86_cw** e **sse2_cw**. Se você quiser afetar uma unidade, passe um endereço para esse parâmetro, mas passe 0 (**nulo**) para os outros. Se 0 for passado para um desses parâmetros, a função não terá efeito sobre essa unidade de ponto flutuante. Essa funcionalidade poderá ser útil em situações em que parte do código usa a unidade de ponto flutuante x87 e outra parte do código usa a unidade de ponto flutuante SSE2. Se você usar **__control87_2** em uma parte de um programa e definir valores diferentes para as palavras de controle de ponto flutuante e, em seguida, usar **_control87** ou **controlfp** ainda mais manipular a palavra de controle, em seguida **_control87** e **controlfp** pode não ser capaz de retornar uma única palavra de controle para representar o estado de ambas as unidades de ponto flutuante. Nesse caso, essas funções definem os **EM_AMBIGUOUS** sinalizador no valor inteiro retornado para indicar que há uma inconsistência entre as duas palavras de controle. Esse é um aviso indicando que a palavra de controle retornada poderá não representar o estado de ambas as palavras de controle de ponto flutuante com precisão.

Sobre o ARM e x64 arquiteturas, alterando o modo de infinito ou a precisão de ponto flutuante não são suportadas. Se a máscara de controle de precisão for usada em x64 plataforma, a função gerará uma declaração e o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md).

> [!NOTE]
> **__control87_2** não é compatível com o ARM ou x64 arquiteturas. Se você usar **__control87_2** e compilar o programa para o ARM ou x64 arquiteturas, o compilador gera um erro.

Essas funções são ignoradas quando você usa [/clr (compilação de tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md) para compilar porque o common language runtime (CLR) dá suporte apenas a precisão de ponto flutuante padrão.

**Valores hexadecimais**

Para o **_MCW_EM** máscara, limpar a máscara define a exceção, que permite que a exceção de hardware; configurar a máscara oculta a exceção. Se um **_EM_UNDERFLOW** ou **_EM_OVERFLOW** ocorre, nenhuma exceção de hardware será gerada até que a próxima instrução de ponto flutuante é executada. Para gerar uma exceção de hardware imediatamente após **_EM_UNDERFLOW** ou **_EM_OVERFLOW**, chame o **FWAIT** instrução (MASM).

|Máscara|Valor hex.|Constante|Valor hex.|
|----------|---------------|--------------|---------------|
|**_MCW_DN** (controle desnormalizado)|0x03000000|**_DN_SAVE**<br /><br /> **_DN_FLUSH**|0x00000000<br /><br /> 0x01000000|
|**_MCW_EM** (máscara de exceção de interrupção)|0x0008001F|**_EM_INVALID**<br /><br /> **_EM_DENORMAL**<br /><br /> **_EM_ZERODIVIDE**<br /><br /> **_EM_OVERFLOW**<br /><br /> **_EM_UNDERFLOW**<br /><br /> **_EM_INEXACT**|0x00000010<br /><br /> 0x00080000<br /><br /> 0x00000008<br /><br /> 0x00000004<br /><br /> 0x00000002<br /><br /> 0x00000001|
|**_MCW_IC** (controle de infinito)<br /><br /> (Sem suporte no ARM ou x64] plataformas.)|0x00040000|**_IC_AFFINE**<br /><br /> **_IC_PROJECTIVE**|0x00040000<br /><br /> 0x00000000|
|**_MCW_RC** (controle de arredondamento)|0x00000300|**_RC_CHOP**<br /><br /> **_RC_UP**<br /><br /> **_RC_DOWN**<br /><br /> **_RC_NEAR**|0x00000300<br /><br /> 0x00000200<br /><br /> 0x00000100<br /><br /> 0x00000000|
|**_MCW_PC** (controle de precisão)<br /><br /> (Não plataformas com suporte no ARM ou x64.)|0x00030000|**_PC_24** (24 bits)<br /><br /> **_PC_53** (53 bits)<br /><br /> **_PC_64** (64 bits)|0x00020000<br /><br /> 0x00010000<br /><br /> 0x00000000|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_control87**, **_controlfp**, **_control87_2**|\<float.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_cntrl87.c
// processor: x86
// This program uses __control87_2 to output the x87 control
// word, set the precision to 24 bits, and reset the status to
// the default.

#include <stdio.h>
#include <float.h>
#pragma fenv_access (on)

int main( void )
{
    double a = 0.1;
    unsigned int control_word_x87;

    // Show original x87 control word and do calculation.
    control_word_x87 = __control87_2(0, 0,
                                     &control_word_x87, 0);
    printf( "Original: 0x%.4x\n", control_word_x87 );
    printf( "%1.1f * %1.1f = %.15e\n", a, a, a * a );

    // Set precision to 24 bits and recalculate.
    control_word_x87 = __control87_2(_PC_24, MCW_PC,
                                     &control_word_x87, 0);
    printf( "24-bit:   0x%.4x\n", control_word_x87 );
    printf( "%1.1f * %1.1f = %.15e\n", a, a, a * a );

    // Restore default precision-control bits and recalculate.
    control_word_x87 = __control87_2( _CW_DEFAULT, MCW_PC,
                                     &control_word_x87, 0 );
    printf( "Default:  0x%.4x\n", control_word_x87 );
    printf( "%1.1f * %1.1f = %.15e\n", a, a, a * a );
}
```

```Output
Original: 0x0001
0.1 * 0.1 = 1.000000000000000e-002
24-bit:   0x0001
0.1 * 0.1 = 9.999999776482582e-003
Default:  0x0001
0.1 * 0.1 = 1.000000000000000e-002
```

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[_clear87, _clearfp](clear87-clearfp.md)<br/>
[_status87, _statusfp, _statusfp2](status87-statusfp-statusfp2.md)<br/>
[_controlfp_s](controlfp-s.md)<br/>
