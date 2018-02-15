---
title: _controlfp_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6ed5896a723ec44d460b0d9588878b431ff7ef14
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="controlfps"></a>_controlfp_s
Obtém e define a palavra de controle de ponto flutuante. Esta versão de [_control87, _controlfp, \__control87_2](../../c-runtime-library/reference/control87-controlfp-control87-2.md) traz melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t _controlfp_s(  
    unsigned int *currentControl,  
    unsigned int newControl,  
    unsigned int mask  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `currentControl`  
 O valor de bit da palavra de controle atual.  
  
 `newControl`  
 Novos valores de bit da palavra de controle.  
  
 `mask`  
 Máscara para novos bits da palavra de controle a ser definida.  
  
## <a name="return-value"></a>Valor de retorno  
 Zero se tiver êxito ou um código de erro de valor `errno`.  
  
## <a name="remarks"></a>Comentários  
 A função `_controlfp_s` é uma versão mais segura e independente de plataforma de `_control87`, que insere a palavra de controle de ponto flutuante no endereço armazenado em `currentControl` e a define usando `newControl`. Os bits nos valores indicam o estado do controle de ponto flutuante. O estado do controle de ponto flutuante permite que o programa altere os modos de precisão, arredondamento e infinito no pacote de matemática de ponto flutuante, dependendo da plataforma. Também é possível usar `_controlfp_s` para mascarar ou remover a máscara das exceções de ponto flutuante.  
  
 Se o valor de `mask` for igual a 0, `_controlfp_s` obterá a palavra de controle de ponto flutuante e armazenará o valor recuperado em `currentControl`.  
  
 Se `mask` for diferente de zero, um novo valor para a palavra de controle será definido: para qualquer bit que esteja definido (ou seja, igual a 1) em `mask`, o bit correspondente em `new` será usado para atualizar a palavra de controle. Em outras palavras, `fpcntrl` `=` ((`fpcntrl` `& ~mask`) &#124; (`new & mask`)), em que `fpcntrl` é a palavra de controle de ponto flutuante. Nesse cenário, `currentControl` é definido com o valor após a conclusão da alteração; não é o valor antigo de bit da palavra de controle.  
  
> [!NOTE]
>  Por padrão, as bibliotecas em tempo de execução mascaram todas as exceções de ponto flutuante.  
  
 `_controlfp_s` é quase idêntico à função `_control87` nas plataformas Intel (x86), [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)] e ARM. Se você tiver plataformas x86, [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)] ou ARM como destino, será possível usar `_control87` ou `_controlfp_s`.  
  
 A diferença entre `_control87` e `_controlfp_s` está em como eles tratam valores `DENORMAL`. Para plataformas Intel (x86), [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)] e ARM, `_control87` pode definir e limpar a máscara de exceção DENORMAL OPERAND. `_controlfp_s` não modifica a máscara de exceção DENORMAL OPERAND. Este exemplo demonstra a diferença:  
  
```C  
_control87( _EM_INVALID, _MCW_EM );   
// DENORMAL is unmasked by this call.  
unsigned int current_word = 0;  
_controlfp_s( &current_word, _EM_INVALID, _MCW_EM );   
// DENORMAL exception mask remains unchanged.  
```  
  
 Os possíveis valores para a constante de máscara (`mask`) e os novos valores de controle (`newControl`) são mostrados na tabela Valores hexadecimais a seguir. Use as constantes portáteis listadas abaixo (`_MCW_EM`, `_EM_INVALID` e assim por diante) como argumentos para essas funções, em vez de fornecer os valores hexadecimais explicitamente.  
  
 Plataformas derivadas da Intel (x86) dão suporte a valores de entrada e saída DENORMAL em hardware. O comportamento do x86 é preservar valores DENORMAL. A plataforma ARM e as plataformas [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)] que têm o suporte a SSE2 permitem que operandos e resultados DENORMAL sejam liberados ou forçados para zero. As funções `_controlfp_s`, `_controlfp` e `_control87` fornecem uma máscara para alterar esse comportamento. O seguinte exemplo demonstra o uso dessa máscara:  
  
```C  
unsigned int current_word = 0;  
_controlfp_s(&current_word, _DN_SAVE, _MCW_DN);     
// Denormal values preserved on ARM platforms and on x64 processors with  
// SSE2 support. NOP on x86 platforms.  
_controlfp_s(&current_word, _DN_FLUSH, _MCW_DN);     
// Denormal values flushed to zero by hardware on ARM platforms   
// and x64 processors with SSE2 support. Ignored on other x86 platforms.  
```  
  
 Em plataformas ARM, a função `_controlfp_s` se aplica ao registro FPSCR. Em arquiteturas [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)], apenas a palavra de controle SSE2 armazenada no registro MXCSR é afetada. Em plataformas Intel (x86), `_controlfp_s` afetará as palavras de controle do x87 e do SSE2, caso esteja presente. É possível que as duas palavras de controle sejam mutuamente inconsistentes (devido a uma chamada anterior a [__control87_2](../../c-runtime-library/reference/control87-controlfp-control87-2.md), por exemplo); caso haja uma inconsistência entre as duas palavras de controle, `_controlfp_s` definirá o sinalizador `EM_AMBIGUOUS` em `currentControl`. Esse é um aviso indicando que a palavra de controle retornada poderá não representar o estado de ambas as palavras de controle de ponto flutuante com precisão.  
  
 Em arquiteturas ARM e [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)], não há suporte para a alteração do modo de infinito ou da precisão de ponto flutuante. Se a máscara de controle de precisão for usada na plataforma [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)], a função acionará uma declaração e o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md).  
  
 Se a máscara não estiver definida corretamente, essa função gerará uma exceção de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função retornará `EINVAL` e definirá `errno` como `EINVAL`.  
  
 Essa função é ignorada quando você usar [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) compilação porque o common language runtime (CLR) suporta apenas a precisão de ponto flutuante padrão.  
  
### <a name="mask-constants-and-values"></a>Constantes de máscara e valores  
  
 Para a máscara `_MCW_EM`, limpá-la define a exceção, o que permite a exceção de hardware; defini-la oculta a exceção. Se ocorrer um `_EM_UNDERFLOW` ou `_EM_OVERFLOW`, nenhuma exceção de hardware será gerada até que a próxima instrução de ponto flutuante seja executada. Para gerar uma exceção de hardware imediatamente após `_EM_UNDERFLOW` ou `_EM_OVERFLOW`, chame a instrução FWAIT do MASM.  
  
|Máscara|Valor hex.|Constante|Valor hex.|  
|----------|---------------|--------------|---------------|  
|`_MCW_DN` (Controle desnormalizado)|0x03000000|`_DN_SAVE`<br /><br /> `_DN_FLUSH`|0x00000000<br /><br /> 0x01000000|  
|`_MCW_EM` (Máscara de exceção de interrupção)|0x0008001F|`_EM_INVALID`<br /><br /> `_EM_DENORMAL`<br /><br /> `_EM_ZERODIVIDE`<br /><br /> `_EM_OVERFLOW`<br /><br /> `_EM_UNDERFLOW`<br /><br /> `_EM_INEXACT`|0x00000010<br /><br /> 0x00080000<br /><br /> 0x00000008<br /><br /> 0x00000004<br /><br /> 0x00000002<br /><br /> 0x00000001|  
|`_MCW_IC` (Controle de infinito)<br /><br /> (Sem suporte em plataformas ARM ou [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)].)|0x00040000|`_IC_AFFINE`<br /><br /> `_IC_PROJECTIVE`|0x00040000<br /><br /> 0x00000000|  
|`_MCW_RC` (Controle de arredondamento)|0x00000300|`_RC_CHOP`<br /><br /> `_RC_UP`<br /><br /> `_RC_DOWN`<br /><br /> `_RC_NEAR`|0x00000300<br /><br /> 0x00000200<br /><br /> 0x00000100<br /><br /> 0x00000000|  
|`_MCW_PC` (Controle de precisão)<br /><br /> (Sem suporte em plataformas ARM ou [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)].)|0x00030000|`_PC_24` (24 bits)<br /><br /> `_PC_53` (53 bits)<br /><br /> `_PC_64` (64 bits)|0x00020000<br /><br /> 0x00010000<br /><br /> 0x00000000|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_controlfp_s`|\<float.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
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
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [_clear87, _clearfp](../../c-runtime-library/reference/clear87-clearfp.md)   
 [_status87, _statusfp, _statusfp2](../../c-runtime-library/reference/status87-statusfp-statusfp2.md)   
 [_control87, _controlfp, \__control87_2](../../c-runtime-library/reference/control87-controlfp-control87-2.md)