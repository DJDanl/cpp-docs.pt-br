---
title: _control87, _controlfp, __control87_2 | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 48d0c3107bf2edc09017ea138e4c8024ce328dd8
ms.sourcegitcommit: 6e3cf8df676d59119ce88bf5321d063cf479108c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/22/2018
ms.locfileid: "34451476"
---
# <a name="control87-controlfp-control872"></a>_control87, _controlfp, __control87_2

Obtém e define a palavra de controle de ponto flutuante. Uma versão mais segura do **controlfp** disponível; consulte [controlfp_s](controlfp-s.md).

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

*Máscara*<br/>
Máscara para novos bits da palavra de controle a ser definida.

*x86_cw*<br/>
Preenchido com a palavra de controle da unidade de ponto flutuante x87. Passar 0 (**nulo**) para definir a palavra de controle SSE2.

*sse2_cw*<br/>
Palavra de controle da unidade de ponto flutuante SSE. Passar 0 (**nulo**) para definir apenas o x87 controlar o word.

## <a name="return-value"></a>Valor de retorno

Para **control87** e **controlfp**, os bits no valor retornado indicam o estado de controle de ponto flutuante. Para obter uma definição completa do bits retornados pela **control87**, consulte FLOAT. H.

Para **__control87_2**, o valor de retorno é 1, que indica êxito.

## <a name="remarks"></a>Comentários

O **control87** função obtém e define a palavra de controle de ponto flutuante. A palavra de controle de ponto flutuante permite que o programa altere os modos de precisão, arredondamento e infinito no pacote de matemática de ponto flutuante, dependendo da plataforma. Você também pode usar **control87** para mascarar ou Retirar máscara exceções de ponto flutuante. Se o valor de *máscara* é igual a 0, **control87** obtém a palavra de controle de ponto flutuante. Se *máscara* é diferente de zero, um novo valor para a palavra de controle é definido: para qualquer bit no (isto é, igual a 1) em *máscara*, o bit correspondente em *novo* é usado para atualizar o controle Word. Em outras palavras, **fpcntrl** = ((**fpcntrl** & ~*máscara*) &#124; (*novo* & *máscara*)) onde **fpcntrl** é a palavra de controle de ponto flutuante.

> [!NOTE]
> Por padrão, as bibliotecas em tempo de execução mascaram todas as exceções de ponto flutuante.

**controlfp** é uma versão independente de plataforma e portátil do **control87**. Ele é quase idêntico de **control87** função em plataformas ARM, x64 e x86. Se você estiver direcionando plataformas ARM, x64 ou x86, use **control87** ou **controlfp**.

A diferença entre **control87** e **controlfp** está em como elas tratam valores ANORMAL. Para x86, x64 e ARM plataformas, **control87** podem ser definidas e desmarque a máscara de exceção DESNORMALIZADO OPERANDO. **controlfp** não modifica a máscara de exceção DESNORMALIZADO OPERANDO. Este exemplo demonstra a diferença:

```C
_control87( _EM_INVALID, _MCW_EM );
// DENORMAL is unmasked by this call
_controlfp( _EM_INVALID, _MCW_EM );
// DENORMAL exception mask remains unchanged
```

Os valores possíveis para a constante máscara (*máscara*) e novos valores de controle (*nova*) são mostrados na tabela a seguir de valores hexadecimais. Use as constantes portátil listadas abaixo (**_MCW_EM**, **_EM_INVALID**, e assim por diante) como argumentos para essas funções, em vez de fornecer o hexadecimal valores explicitamente.

Plataformas x86 derivado do Intel oferecem suporte a entrada ANORMAL e valores no hardware de saída. O comportamento do x86 é preservar valores DENORMAL. A plataforma ARM e suportam a plataformas SSE2 x64 habilitar ANORMAL operandos e os resultados a serem liberados ou forçados para zero. O **controlfp** e **control87** funções fornecem uma máscara para alterar esse comportamento. O exemplo a seguir demonstra o uso dessa máscara.

```C
_controlfp(_DN_SAVE, _MCW_DN);
// Denormal values preserved on ARM platforms and on x64 processors with
// SSE2 support. NOP on x86 platforms.
_controlfp(_DN_FLUSH, _MCW_DN);
// Denormal values flushed to zero by hardware on ARM platforms
// and x64 processors with SSE2 support. Ignored on other x86 platforms.
```

Em plataformas ARM, o **control87** e **controlfp** funções se aplicam ao registro FPSCR. Em x64 arquiteturas, apenas a palavra de controle SSE2 é armazenado no MXCSR registro é afetado. X86 plataformas, **control87** e **controlfp** afetam as palavras de controle para o x87 e SSE2, se presente. A função **__control87_2** habilita o x87 e unidades de ponto flutuantes SSE2 seja controlado juntos ou separadamente. Se você quiser afetar as unidades, passar os endereços dos dois inteiros para **x86_cw** e **sse2_cw**. Se você quiser afetar uma unidade, passar um endereço para esse parâmetro, mas foi aprovado em 0 (**nulo**) para os outros. Se 0 for passado para um desses parâmetros, a função não terá efeito sobre essa unidade de ponto flutuante. Essa funcionalidade poderá ser útil em situações em que parte do código usa a unidade de ponto flutuante x87 e outra parte do código usa a unidade de ponto flutuante SSE2. Se você usar **__control87_2** em uma parte de um programa e definir valores diferentes para as palavras controle de ponto flutuante e, em seguida, usar **control87** ou **controlfp** para obter mais manipular a palavra de controle, em seguida, **control87** e **controlfp** pode ser não é possível retornar uma palavra de controle único para representar o estado de ambas as unidades de ponto flutuantes. Nesse caso, defina essas funções a **EM_AMBIGUOUS** sinalizador no valor de número inteiro retornado para indicar que há uma inconsistência entre as palavras de controle. Esse é um aviso indicando que a palavra de controle retornada poderá não representar o estado de ambas as palavras de controle de ponto flutuante com precisão.

O ARM e x64 arquiteturas, alterando o modo de infinito ou a precisão de ponto flutuante não são suportadas. Se a máscara de controle de precisão é usada em x64 plataforma, a função gera uma asserção e o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md).

> [!NOTE]
> **__control87_2** não há suporte para o ARM ou x64 arquiteturas. Se você usar **__control87_2** e compilar seu programa para o ARM ou x64 arquiteturas, o compilador gerará um erro.

Essas funções são ignoradas quando você usa [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) compilação porque o common language runtime (CLR) suporta apenas a precisão de ponto flutuante padrão.

**Valores hexadecimais**

Para o **_MCW_EM** máscara, limpando a máscara define a exceção, o que permite que a exceção de hardware; definindo a máscara oculta a exceção. Se um **_EM_UNDERFLOW** ou **_EM_OVERFLOW** ocorre, nenhuma exceção de hardware é lançada até que a próxima instrução de ponto flutuante é executada. Para gerar uma exceção de hardware imediatamente após **_EM_UNDERFLOW** ou **_EM_OVERFLOW**, chame o **FWAIT** instrução MASM.

|Máscara|Valor hex.|Constante|Valor hex.|
|----------|---------------|--------------|---------------|
|**_MCW_DN** (desnormalizado controle)|0x03000000|**_DN_SAVE**<br /><br /> **_DN_FLUSH**|0x00000000<br /><br /> 0x01000000|
|**_MCW_EM** (máscara de exceção de interrupção)|0x0008001F|**_EM_INVALID**<br /><br /> **_EM_DENORMAL**<br /><br /> **_EM_ZERODIVIDE**<br /><br /> **_EM_OVERFLOW**<br /><br /> **_EM_UNDERFLOW**<br /><br /> **_EM_INEXACT**|0x00000010<br /><br /> 0x00080000<br /><br /> 0x00000008<br /><br /> 0x00000004<br /><br /> 0x00000002<br /><br /> 0x00000001|
|**_MCW_IC** (controle de infinito)<br /><br /> (Sem suporte no ARM ou x64] plataformas.)|0x00040000|**_IC_AFFINE**<br /><br /> **_IC_PROJECTIVE**|0x00040000<br /><br /> 0x00000000|
|**_MCW_RC** (controle de arredondamento)|0x00000300|**_RC_CHOP**<br /><br /> **_RC_UP**<br /><br /> **_RC_DOWN**<br /><br /> **_RC_NEAR**|0x00000300<br /><br /> 0x00000200<br /><br /> 0x00000100<br /><br /> 0x00000000|
|**_MCW_PC** (controle de precisão)<br /><br /> (Não plataformas com suporte no ARM ou x64.)|0x00030000|**_PC_24** (24 bits)<br /><br /> **_PC_53** (53 bits)<br /><br /> **_PC_64** (64 bits)|0x00020000<br /><br /> 0x00010000<br /><br /> 0x00000000|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**control87**, **controlfp**, **_control87_2**|\<float.h>|

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
