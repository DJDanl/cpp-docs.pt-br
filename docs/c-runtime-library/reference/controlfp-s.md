---
title: "_controlfp_s | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_controlfp_s"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-runtime-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "controlfp_s"
  - "_controlfp_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _controlfp_s"
  - "Função controlfp_s"
  - "EM_AMBIGUOUS"
  - "funções de ponto flutuante, definindo a palavra de controle"
  - "números de ponto flutuante, palavra de controle"
ms.assetid: a51fc3f6-ab13-41f0-b227-6bf02d98e987
caps.latest.revision: 28
caps.handback.revision: 28
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _controlfp_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém e define a palavra de controle de ponto flutuante.  Essa versão de [\_control87, \_controlfp, \_\_control87\_2](../Topic/_control87,%20_controlfp,%20__control87_2.md) tem aprimoramentos de segurança, como descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
errno_t _controlfp_s(  
    unsigned int *currentControl,  
    unsigned int newControl,  
    unsigned int mask  
);  
```  
  
#### Parâmetros  
 `currentControl`  
 O valor do bit da palavra de controle atual.  
  
 `newControl`  
 Valores de bit da nova palavra de controle.  
  
 `mask`  
 Máscara para os bits da nova palavra de controle a ser definida.  
  
## Valor de retorno  
 Zero se tiver êxito, ou um código de erro de valor `errno`.  
  
## Comentários  
 A função `_controlfp_s` é uma versão mais segura independente de plataforma `_control87`, que obtém a palavra de controle de ponto flutuante no endereço armazenado em `currentControl` e a define usando `newControl`.  Os bits nos valores indicam o estado do controle de ponto flutuante.  O estado de controle de ponto flutuante permite que o programa altere a precisão, o arredondamento e os modos infinitos no pacote de matemática de ponto flutuante, dependendo da plataforma.  Também é possível usar `_controlfp_s` para mascarar ou desmascarar exceções de ponto flutuante.  
  
 Se o valor da `mask` for igual a 0, `_controlfp_s` obterá a palavra de controle de ponto flutuante e armazenará o valor recuperado em `currentControl`.  
  
 Se `mask` for diferente de zero, um novo valor para a palavra de controle é definido: Para qualquer bit que estiver definido \(ou seja, igual a 1\) em `mask`, o bit correspondente em `new` é usado para atualizar a palavra de controle.  Em outras palavras, `fpcntrl` `=` \(\(`fpcntrl` `& ~mask`\) &#124; \(`new & mask`\)\) onde `fpcntrl` é a palavra de controle de ponto flutuante.  Nesse cenário, `currentControl` é definida para o valor depois que a alteração é concluída; não é o valor de bits antigo da palavra de controle.  
  
> [!NOTE]
>  Por padrão, as bibliotecas em tempo de execução mascaram todas as exceções de ponto flutuante.  
  
 `_controlfp_s` é quase idêntico à função de `_control87` no Intel \(x86\), em plataformas de [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] e ARM.  Se você estiver definindo plataformas x86, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)], ou plataformas ARM como plataformas de destino, você pode usar `_control87` ou `_controlfp_s`.  
  
 A diferença entre `_control87` e `_controlfp_s` está na maneira como manipulam os valores `DENORMAL`.  Para Intel \(x86\), [!INCLUDE[vcprx64](../Token/vcprx64_md.md)], e as plataformas ARM, `_control87` podem definir e limpar a máscara de exceção DENORMAL OPERAND.  `_controlfp_s` não modifica a máscara de exceção DENORMAL OPERAND.  Esse exemplo demonstra a diferença:  
  
```  
_control87( _EM_INVALID, _MCW_EM );   
// DENORMAL is unmasked by this call.  
unsigned int current_word = 0;  
_controlfp_s( &current_word, _EM_INVALID, _MCW_EM );   
// DENORMAL exception mask remains unchanged.  
```  
  
 Os valores possíveis para a constante de máscara \(`mask`\) e os novos valores de controle \(`newControl`\) são mostrados na tabela de valores hexadecimais a seguir.  Use constantes portáteis listadas abaixo \(`_MCW_EM`, `_EM_INVALID`, e assim por diante\) como argumentos para essas funções, em vez de fornecer os valores hexadecimais explicitamente.  
  
 As plataformas derivadas de Intel \(x86\) suportam valores de entrada e saída de DENORMAL no hardware.  O comportamento do x86 é preservar valores DENORMAL.  A plataforma ARM e as plataformas [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] que têm suporte SSE2 ativam os operandos e os resultados DENORMAL a serem liberados ou forçados para zero.  As funções `_controlfp_s`, `_controlfp` e `_control87` fornecem uma máscara para alterar esse comportamento.  O exemplo a seguir demonstra o uso dessa máscara:  
  
```  
unsigned int current_word = 0;  
_controlfp_s(&current_word, _DN_SAVE, _MCW_DN);     
// Denormal values preserved on ARM platforms and on x64 processors with  
// SSE2 support. NOP on x86 platforms.  
_controlfp_s(&current_word, _DN_FLUSH, _MCW_DN);     
// Denormal values flushed to zero by hardware on ARM platforms   
// and x64 processors with SSE2 support. Ignored on other x86 platforms.  
```  
  
 Em plataformas ARM, a função `_controlfp_s` aplica\-se ao registro FPSCR.  Em arquiteturas [!INCLUDE[vcprx64](../Token/vcprx64_md.md)], somente a palavra de controle do SSE2 armazenada no registro MXCSR é afetado.  Em plataformas Intel \(x86\), `_controlfp_s` afeta as palavras de controle do x87 e SSE2, se presentes.  É possível para as duas palavras de controle serem inconsistentes entre si \(devido a uma chamada anterior a [\_\_control87\_2](../Topic/_control87,%20_controlfp,%20__control87_2.md), por exemplo\); se houver uma inconsistência entre as duas palavras de controle, `_controlfp_s` define o sinalizador de `EM_AMBIGUOUS` em `currentControl`.  Esse é um aviso de que a palavra de controle retornada pode não representar o estado das palavras de controle de ponto flutuante precisamente.  
  
 Nas arquiteturas ARM e [!INCLUDE[vcprx64](../Token/vcprx64_md.md)], não há suporte para a alteração do modo infinito ou do ponto flutuante de precisão.  Se a máscara de controle de precisão for usada na plataforma de [!INCLUDE[vcprx64](../Token/vcprx64_md.md)], a função gerará uma declaração e o manipulador de parâmetro inválido será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  
  
 Se a máscara não estiver definida corretamente, a função gerará uma exceção de parâmetro inválido, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essa função retornará `EINVAL` e definirá `errno` como `EINVAL`.  
  
 Essa função é ignorada quando você usa [\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md) ou **\/clr:pure** para compilar porque o CLR \(Common Language Runtime\) oferece suporte somente à precisão do ponto flutuante padrão.  
  
 **Valores hexadecimais**  
  
 Para a máscara de `_MCW_EM`, limpá\-la definirá a exceção, que permite a exceção de hardware; configurá\-la ocultará a exceção.  Se `_EM_UNDERFLOW` ou `_EM_OVERFLOW` ocorrer, nenhuma exceção de hardware será lançada até que a declaração de ponto flutuante seguinte seja executada.  Para gerar uma exceção de hardware imediatamente depois de `_EM_UNDERFLOW` ou `_EM_OVERFLOW`, chame a instrução MASM FWAIT.  
  
|Máscara|Valor hex.|Constante|Valor hex.|  
|-------------|----------------|---------------|----------------|  
|`_MCW_DN` \(controle de Anormal\)|0x03000000|`_DN_SAVE`<br /><br /> `_DN_FLUSH`|0x00000000<br /><br /> 0x01000000|  
|`_MCW_EM` \(máscara de exceção de interrupção\)|0x0008001F|`_EM_INVALID`<br /><br /> `_EM_DENORMAL`<br /><br /> `_EM_ZERODIVIDE`<br /><br /> `_EM_OVERFLOW`<br /><br /> `_EM_UNDERFLOW`<br /><br /> `_EM_INEXACT`|0x00000010<br /><br /> 0x00080000<br /><br /> 0x00000008<br /><br /> 0x00000004<br /><br /> 0x00000002<br /><br /> 0x00000001|  
|`_MCW_IC` \(controle de Infinito\)<br /><br /> \(Não suportado em plataformas do [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] ou ARM.\)|0x00040000|`_IC_AFFINE`<br /><br /> `_IC_PROJECTIVE`|0x00040000<br /><br /> 0x00000000|  
|`_MCW_RC` \(controle de Arredondamento\)|0x00000300|`_RC_CHOP`<br /><br /> `_RC_UP`<br /><br /> `_RC_DOWN`<br /><br /> `_RC_NEAR`|0x00000300<br /><br /> 0x00000200<br /><br /> 0x00000100<br /><br /> 0x00000000|  
|`_MCW_PC` \(controle de Precisão\)<br /><br /> \(Não suportado em plataformas do [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] ou ARM.\)|0x00030000|`_PC_24` \(24 bits\)<br /><br /> `_PC_53` \(53 bits\)<br /><br /> `_PC_64` \(64 bits\)|0x00020000<br /><br /> 0x00010000<br /><br /> 0x00000000|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_controlfp_s`|\<float.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_contrlfp_s.c  
// processor: x86  
// This program uses _controlfp_s to output the FP control   
// word, set the precision to 24 bits, and reset the status to   
// the default.  
//  
  
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
  
## Saída  
  
```  
Original: 0x9001f  
0.1 * 0.1 = 1.000000000000000e-002  
24-bit:   0xa001f  
0.1 * 0.1 = 9.999999776482582e-003  
Default:  0x9001f  
0.1 * 0.1 = 1.000000000000000e-002  
```  
  
## Equivalente ao .NET Framework  
 Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [\_clear87, \_clearfp](../../c-runtime-library/reference/clear87-clearfp.md)   
 [\_status87, \_statusfp, \_statusfp2](../../c-runtime-library/reference/status87-statusfp-statusfp2.md)   
 [\_control87, \_controlfp, \_\_control87\_2](../Topic/_control87,%20_controlfp,%20__control87_2.md)