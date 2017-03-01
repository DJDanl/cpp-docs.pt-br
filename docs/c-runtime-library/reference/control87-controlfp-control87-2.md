---
title: _control87, _controlfp, __control87_2 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 34
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: cc82b83860786ffc3f0aee73ede18ecadef16a7a
ms.openlocfilehash: a6a25c035a55ca247f0d81f5c206207463672881
ms.lasthandoff: 02/25/2017

---
# <a name="control87-controlfp-control872"></a>_control87, _controlfp, __control87_2
Obtém e define a palavra de controle de ponto flutuante. Uma versão mais segura de `_controlfp` está disponível; consulte [_controlfp_s](../../c-runtime-library/reference/controlfp-s.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
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
  
#### <a name="parameters"></a>Parâmetros  
 `new`  
 Novos valores de bit da palavra de controle.  
  
 `mask`  
 Máscara para novos bits da palavra de controle a ser definida.  
  
 `x86_cw`  
 Preenchido com a palavra de controle da unidade de ponto flutuante x87. Passe 0 (`NULL`) para definir apenas a palavra de controle SSE2.  
  
 `sse2_cw`  
 Palavra de controle da unidade de ponto flutuante SSE. Passe 0 (`NULL`) para definir apenas a palavra de controle x87.  
  
## <a name="return-value"></a>Valor de retorno  
 Para `_control87` e `_controlfp`, os bits no valor retornado indicam o estado do controle de ponto flutuante. Para obter uma definição completa dos bits retornados por `_control87`, consulte FLOAT.H.  
  
 Para `__control87_2`, o valor retornado é 1, o que indica êxito.  
  
## <a name="remarks"></a>Comentários  
 A função `_control87` obtém e define a palavra de controle de ponto flutuante. A palavra de controle de ponto flutuante permite que o programa altere os modos de precisão, arredondamento e infinito no pacote de matemática de ponto flutuante, dependendo da plataforma. Também é possível usar `_control87` para mascarar ou remover a máscara das exceções de ponto flutuante. Se o valor de `mask` for igual a 0, `_control87` obterá a palavra de controle de ponto flutuante. Se `mask` for diferente de zero, um novo valor para a palavra de controle será definido: para qualquer bit que esteja ativado (ou seja, igual a 1) em `mask`, o bit correspondente em `new` será usado para atualizar a palavra de controle. Em outras palavras, `fpcntrl` `=` ((`fpcntrl` `& ~mask`) &#124; (`new & mask`)), em que `fpcntrl` é a palavra de controle de ponto flutuante.  
  
> [!NOTE]
>  Por padrão, as bibliotecas em tempo de execução mascaram todas as exceções de ponto flutuante.  
  
 `_controlfp` é uma versão portátil e independente de plataforma de `_control87`. É quase idêntico à função `_control87` nas plataformas Intel (x86), [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)] e ARM. Se você tiver plataformas x86, [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)] ou ARM como destino, use `_control87` ou `_controlfp`.  
  
 A diferença entre `_control87` e `_controlfp` está em como eles tratam valores DENORMAL. Para plataformas Intel (x86), [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)] e ARM, `_control87` pode definir e limpar a máscara de exceção DENORMAL OPERAND. `_controlfp` não modifica a máscara de exceção DENORMAL OPERAND. Este exemplo demonstra a diferença:  
  
```  
_control87( _EM_INVALID, _MCW_EM );   
// DENORMAL is unmasked by this call  
_controlfp( _EM_INVALID, _MCW_EM );   
// DENORMAL exception mask remains unchanged  
```  
  
 Os possíveis valores para a constante de máscara (`mask`) e os novos valores de controle (`new`) são mostrados na tabela Valores hexadecimais a seguir. Use as constantes portáteis listadas abaixo (`_MCW_EM`, `_EM_INVALID` e assim por diante) como argumentos para essas funções, em vez de fornecer os valores hexadecimais explicitamente.  
  
 Plataformas derivadas da Intel (x86) dão suporte a valores de entrada e saída DENORMAL em hardware. O comportamento do x86 é preservar valores DENORMAL. A plataforma ARM e as plataformas [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)] que têm o suporte a SSE2 permitem que operandos e resultados DENORMAL sejam liberados ou forçados para zero. As funções `_controlfp` e `_control87` fornecem uma máscara para alterar esse comportamento. O exemplo a seguir demonstra o uso dessa máscara.  
  
```  
_controlfp(_DN_SAVE, _MCW_DN);     
// Denormal values preserved on ARM platforms and on x64 processors with  
// SSE2 support. NOP on x86 platforms.  
_controlfp(_DN_FLUSH, _MCW_DN);     
// Denormal values flushed to zero by hardware on ARM platforms   
// and x64 processors with SSE2 support. Ignored on other x86 platforms.  
```  
  
 Em plataformas ARM, as funções `_control87` e `_controlfp` se aplicam ao registro FPSCR. Em arquiteturas [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)], apenas a palavra de controle SSE2 armazenada no registro MXCSR é afetada. Em plataformas Intel (x86), `_control87` e `_controlfp` afetarão as palavras de controle do x87 e do SSE2, caso estejam presentes. A função `__control87_2` permite que unidades de ponto flutuante x87 e SSE2 sejam controladas juntas ou separadamente. Se desejar afetar as duas unidades, passe os endereços dos dois inteiros para `x86_cw` e `sse2_cw`. Se desejar afetar apenas uma unidade, passe um endereço para esse parâmetro, mas passe 0 (NULL) para o outro. Se 0 for passado para um desses parâmetros, a função não terá efeito sobre essa unidade de ponto flutuante. Essa funcionalidade poderá ser útil em situações em que parte do código usa a unidade de ponto flutuante x87 e outra parte do código usa a unidade de ponto flutuante SSE2. Se você usar `__control87_2` em uma parte de um programa e definir valores diferentes para as palavras de controle de ponto flutuante e, em seguida, usar `_control87` ou `_controlfp` para manipular ainda mais a palavra de controle, talvez `_control87` e `_controlfp` não possam retornar uma única palavra de controle para representar o estado de ambas as unidades de ponto flutuante. Nesse caso, essas funções definem o sinalizador `EM_AMBIGUOUS` no valor inteiro retornado para indicar que há uma inconsistência entre as duas palavras de controle. Esse é um aviso indicando que a palavra de controle retornada poderá não representar o estado de ambas as palavras de controle de ponto flutuante com precisão.  
  
 Em arquiteturas ARM e [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)], não há suporte para a alteração do modo de infinito ou da precisão de ponto flutuante. Se a máscara de controle de precisão for usada na plataforma [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)], a função acionará uma declaração e o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md).  
  
> [!NOTE]
> Não há suporte para  `__control87_2` nas arquiteturas ARM ou [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)]. Se você usar `__control87_2` e compilar o programa para as arquiteturas ARM ou [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)], o compilador gerará um erro.  
  
 Essas funções são ignoradas quando você usa [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) para compilar porque o common language runtime (CLR) suporta apenas a precisão de ponto flutuante padrão.  
  
 **Valores hexadecimais**  
  
 Para a máscara `_MCW_EM`, limpar a máscara define a exceção, o que permite a exceção de hardware; configurar a máscara oculta a exceção. Se ocorrer um `_EM_UNDERFLOW` ou `_EM_OVERFLOW`, nenhuma exceção de hardware será gerada até que a próxima instrução de ponto flutuante seja executada. Para gerar uma exceção de hardware imediatamente após `_EM_UNDERFLOW` ou `_EM_OVERFLOW`, chame a instrução `FWAIT` do MASM.  
  
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
|`_control87`, `_controlfp`, `_control87_2`|\<float.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
  
      // crt_cntrl87.c  
// processor: x86  
// This program uses __control87_2 to output the x87 control   
// word, set the precision to 24 bits, and reset the status to   
// the default.  
//  
  
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
  
## <a name="output"></a>Saída  
  
```  
Original: 0x0001  
0.1 * 0.1 = 1.000000000000000e-002  
24-bit:   0x0001  
0.1 * 0.1 = 9.999999776482582e-003  
Default:  0x0001  
0.1 * 0.1 = 1.000000000000000e-002  
```  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [_clear87, _clearfp](../../c-runtime-library/reference/clear87-clearfp.md)   
 [_status87, _statusfp, _statusfp2](../../c-runtime-library/reference/status87-statusfp-statusfp2.md)   
 [_controlfp_s](../../c-runtime-library/reference/controlfp-s.md)
