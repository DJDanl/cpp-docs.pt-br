---
title: "_CrtSetDbgFlag | Microsoft Docs"
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
  - "_CrtSetDbgFlag"
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
apitype: "DLLExport"
f1_keywords: 
  - "_CRTDBG_REPORT_FLAG"
  - "_CRTDBG_CHECK_EVERY_16_DF"
  - "_CRTDBG_CHECK_DEFAULT_DF"
  - "CRTDBG_CHECK_DEFAULT_DF"
  - "CRTDBG_CHECK_EVERY_128_DF"
  - "CRTDBG_CHECK_EVERY_1024_DF"
  - "_CRTDBG_CHECK_EVERY_128_DF"
  - "CrtSetDbgFlag"
  - "CRTDBG_CHECK_EVERY_16_DF"
  - "_CRTDBG_CHECK_EVERY_1024_DF"
  - "_CrtSetDbgFlag"
  - "CRTDBG_REPORT_FLAG"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Macro _CRTDBG_ALLOC_MEM_DF"
  - "Macro _CRTDBG_CHECK_ALWAYS_DF"
  - "Macro _CRTDBG_CHECK_CRT_DF"
  - "Macro _CRTDBG_CHECK_DEFAULT_DF"
  - "Macro _CRTDBG_CHECK_EVERY_1024_DF"
  - "Macro _CRTDBG_CHECK_EVERY_128_DF"
  - "Macro _CRTDBG_CHECK_EVERY_16_DF"
  - "Macro _CRTDBG_DELAY_FREE_MEM_DF"
  - "Macro _CRTDBG_REPORT_FLAG"
  - "Função _CrtSetDbgFlag"
  - "Macro CRTDBG_ALLOC_MEM_DF"
  - "Macro CRTDBG_CHECK_ALWAYS_DF"
  - "Macro CRTDBG_CHECK_CRT_DF"
  - "Macro CRTDBG_CHECK_DEFAULT_DF"
  - "Macro CRTDBG_CHECK_EVERY_1024_DF"
  - "Macro CRTDBG_CHECK_EVERY_128_DF"
  - "Macro CRTDBG_CHECK_EVERY_16_DF"
  - "Macro CRTDBG_DELAY_FREE_MEM_DF"
  - "Macro CRTDBG_REPORT_FLAG"
  - "Função CrtSetDbgFlag"
ms.assetid: b5657ffb-6178-4cbf-9886-1af904ede94c
caps.latest.revision: 19
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _CrtSetDbgFlag
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Recupera ou modifica o estado do sinalizador **\_crtDbgFlag** para controlar o comportamento de alocação do gerenciador de heap da depuração \(somente versão de depuração\).  
  
## Sintaxe  
  
```  
  
int _CrtSetDbgFlag(     int newFlag  );  
```  
  
#### Parâmetros  
 `newFlag`  
 Novo estado de **\_crtDbgFlag**.  
  
## Valor de retorno  
 Retorna o estado anterior de **\_crtDbgFlag**.  
  
## Comentários  
 A função `_CrtSetDbgFlag` permite que o aplicativo controle como o gerenciador do heap de depuração acompanha alocações de memória modificando os campos de bit do sinalizador **\_crtDbgFlag**.  Definindo os bits \(ativando\), o aplicativo pode instruir o gerenciador do heap de depuração a realizar operações de depuração especiais, inclusive verificar perdas de memória quando o aplicativo for fechado e relatar se algo foi encontrado, simulando condições de pouca memória com a especificação de que blocos de memória liberados devam permanecer na lista vinculada do heap e a verificação da integridade do heap inspecionando todos os blocos de memória em todas as solicitações de alocação.  Quando [\_DEBUG](../Topic/_DEBUG.md) não está definido, as chamadas a `_CrtSetDbgFlag` são removidas durante o pré\-processamento.  
  
 A tabela a seguir lista os campos de bit de **\_crtDbgFlag** e descreve seus comportamentos.  Como a definição dos bits resulta em maior saída de diagnóstico e redução da velocidade na execução do programa, esses bits não ficam definidos \(desativados\) por padrão.  Para obter mais informações sobre esses campos de bit, consulte [Funções de relatório do estado heap](../Topic/CRT%20Debug%20Heap%20Details.md#BKMK_Heap_State_Reporting_Functions).  
  
|Campo de bits|Padrão|Descrição|  
|-------------------|------------|---------------|  
|**\_CRTDBG\_ALLOC\_MEM\_DF**|ON|ON: Habilite alocações do heap de depuração e uso de identificadores do tipo de bloco de memória como `_CLIENT_BLOCK`.  OFF: Adicione novas alocações à lista vinculada do heap, mas defina o tipo de bloco como **\_IGNORE\_BLOCK**.<br /><br /> Também pode ser combinado com qualquer uma das macros de verificação da frequência de heap.|  
|**\_CRTDBG\_CHECK\_ALWAYS\_DF**|OFF|ON: Chame [\_CrtCheckMemory](../../c-runtime-library/reference/crtcheckmemory.md) em qualquer solicitação de alocação e desalocação.  OFF: `_CrtCheckMemory` deve ser chamado explicitamente.<br /><br /> As macros de verificação da frequência de heap não entram em vigor quando esse sinalizador está definido.|  
|`_CRTDBG_CHECK_CRT_DF`|OFF|ON: Inclua tipos `_CRT_BLOCK` na detecção de vazamento e em operações de diferença de estado da memória.  OFF: A memória usada internamente pela biblioteca em tempo de execução é ignorada por essas operações.<br /><br /> Também pode ser combinado com qualquer uma das macros de verificação da frequência de heap.|  
|**\_CRTDBG\_DELAY\_FREE\_MEM\_DF**|OFF|ON: Mantenha os blocos de memória liberados na lista vinculada do heap, atribua\-os ao tipo **\_FREE\_BLOCK** e os preencha com o valor de byte 0xDD.  OFF: Não mantenha blocos liberados na lista vinculada do heap.<br /><br /> Também pode ser combinado com qualquer uma das macros de verificação da frequência de heap.|  
|`_CRTDBG_LEAK_CHECK_DF`|OFF|ON: Realize a verificação automática de perda na saída do programa por meio de uma chamada a [\_CrtDumpMemoryLeaks](../../c-runtime-library/reference/crtdumpmemoryleaks.md) e, caso o aplicativo não libere toda a memória alocada, gere um relatório de erros.  OFF: Não realize a verificação automática de perda na saída do programa.<br /><br /> Também pode ser combinado com qualquer uma das macros de verificação da frequência de heap.|  
  
 **Macros de frequência da verificação de heap**  
  
 É possível especificar com que frequência a biblioteca em tempo de execução do C realiza a validação do heap de depuração \(`_CrtCheckMemory`\) com base no número de chamadas a `malloc`, `realloc`, **free** e `_msize`.  
  
 `_CrtSetDbgFlag` e inspeciona os 16 bits superiores do parâmetro `newFlag` para um valor.  O valor especificado é o número de chamadas `malloc`, `realloc`, **free** e `_msize` entre as chamadas `_CrtCheckMemory`.  Quatro macros predefinidas são fornecidas com essa finalidade.  
  
|Macro|Número de chamadas malloc, realloc, free e \_msize entre as chamadas para \_CrtCheckMemory|  
|-----------|------------------------------------------------------------------------------------------------|  
|\_CRTDBG\_CHECK\_EVERY\_16\_DF|16|  
|\_CRTDBG\_CHECK\_EVERY\_128\_DF|128|  
|\_CRTDBG\_CHECK\_EVERY\_1024\_DF|1024|  
|\_CRTDBG\_CHECK\_DEFAULT\_DF|0 \(por padrão, sem verificações de heap\)|  
  
 Por padrão, `_CrtCheckMemory` é chamado uma vez a cada 1.024 vezes em que você chama `malloc`, `realloc` **free** e `_msize`.  
  
 Por exemplo, você poderia especificar uma verificação de heap a cada 16 operações `malloc`, `realloc`, **free** e `_msize` com o seguinte código:  
  
```  
#include <crtdbg.h>  
int main( )  
{  
int tmp;  
  
// Get the current bits  
tmp = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);  
  
// Clear the upper 16 bits and OR in the desired freqency  
tmp = (tmp & 0x0000FFFF) | _CRTDBG_CHECK_EVERY_16_DF;  
  
// Set the new bits  
_CrtSetDbgFlag(tmp);  
}  
```  
  
 Os 16 bits superiores do parâmetro `newFlag` são ignorados quando \_CRTDBG\_CHECK\_ALWAYS\_DF é especificado.  Nesse caso, `_CrtCheckMemory` é chamado sempre que você chama `malloc`, `realloc`, **free** e `_msize`.  
  
 `newFlag` é o novo estado a ser aplicado ao **\_crtDbgFlag** e é uma combinação dos valores de cada um dos campos de bit.  
  
### Para alterar um ou mais desses campos de bit e criar um novo estado para o sinalizador  
  
1.  Chame `_CrtSetDbgFlag` com `newFlag` igual a `_CRTDBG_REPORT_FLAG` para obter o estado **\_crtDbgFlag** atual e armazene o valor retornado em uma variável temporária.  
  
2.  Ative todos os bits com `OR` na variável temporária usando as bitmasks correspondentes \(representadas no código do aplicativo por constantes de manifesto\).  
  
3.  Desative os outros bits com **AND** na variável usando **NOT** bit a bit das bitmasks apropriadas.  
  
4.  Chame `_CrtSetDbgFlag` com `newFlag` igual ao valor armazenado na variável temporária para definir o novo estado para **\_crtDbgFlag**.  
  
 O código a seguir demonstra como simular condições de pouca memória mantendo os blocos de memória liberados na lista vinculada do heap e evitando que `_CrtCheckMemory` seja chamado em todas as solicitações de alocação:  
  
```  
// Get the current state of the flag  
// and store it in a temporary variable  
int tmpFlag = _CrtSetDbgFlag( _CRTDBG_REPORT_FLAG );  
  
// Turn On (OR) - Keep freed memory blocks in the  
// heap's linked list and mark them as freed  
tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;  
  
// Turn Off (AND) - prevent _CrtCheckMemory from  
// being called at every allocation request  
tmpFlag &= ~_CRTDBG_CHECK_ALWAYS_DF;  
  
// Set the new state for the flag  
_CrtSetDbgFlag( tmpFlag );  
```  
  
 Para obter uma visão geral do gerenciamento da memória e do heap de depuração, consulte [Detalhes da pilha de depuração CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  
  
 Para desabilitar um sinalizador com a função `_CrtSetDbgFlag`, você deve usar **AND** na variável com **NOT** bit a bit da bitmask.  
  
 Se `newFlag` não for um valor válido, essa função invocará o manipulador de parâmetros inválido, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essa função definirá `errno` como `EINVAL` e retornará o estado anterior de `_crtDbgFlag`.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_CrtSetDbgFlag`|\<crtdbg.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Libraries  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
  
```  
// crt_crtsetdflag.c  
// compile with: /c -D_DEBUG /MTd -Od -Zi -W3 /link -verbose:lib /debug  
/*  
 * This program concentrates on allocating and freeing memory  
 * blocks to test the functionality of the _crtDbgFlag flag..  
 */  
  
#include <string.h>  
#include <malloc.h>  
#include <crtdbg.h>  
  
int main( )  
{  
        char *p1, *p2;  
        int tmpDbgFlag;  
  
        _CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_FILE );  
        _CrtSetReportFile( _CRT_ERROR, _CRTDBG_FILE_STDERR );  
        /*  
         * Set the debug-heap flag to keep freed blocks in the  
         * heap's linked list - This will allow us to catch any  
         * inadvertent use of freed memory  
         */  
        tmpDbgFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);  
        tmpDbgFlag |= _CRTDBG_DELAY_FREE_MEM_DF;  
        tmpDbgFlag |= _CRTDBG_LEAK_CHECK_DF;  
        _CrtSetDbgFlag(tmpDbgFlag);  
  
        /*  
         * Allocate 2 memory blocks and store a string in each  
         */  
        p1 = malloc( 34 );  
        p2 = malloc( 38 );  
        strcpy_s( p1, 34, "p1 points to a Normal allocation block" );  
        strcpy_s( p2, 38, "p2 points to a Client allocation block" );  
  
        /*  
         * Free both memory blocks  
         */  
        free( p2 );  
        free( p1 );  
  
        /*  
         * Set the debug-heap flag to no longer keep freed blocks in the  
         * heap's linked list and turn on Debug type allocations (CLIENT)  
         */  
        tmpDbgFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);  
        tmpDbgFlag |= _CRTDBG_ALLOC_MEM_DF;  
        tmpDbgFlag &= ~_CRTDBG_DELAY_FREE_MEM_DF;  
        _CrtSetDbgFlag(tmpDbgFlag);  
  
        /*  
         * Explicitly call _malloc_dbg to obtain the filename and   
         * line number of our allocation request and also so we can   
         * allocate CLIENT type blocks specifically for tracking  
         */  
        p1 = _malloc_dbg( 40, _NORMAL_BLOCK, __FILE__, __LINE__ );  
        p2 = _malloc_dbg( 40, _CLIENT_BLOCK, __FILE__, __LINE__ );  
        strcpy_s( p1, 40, "p1 points to a Normal allocation block" );  
        strcpy_s( p2, 40, "p2 points to a Client allocation block" );  
  
        /*  
         * _free_dbg must be called to free the CLIENT block  
         */  
        _free_dbg( p2, _CLIENT_BLOCK );  
        free( p1 );  
  
        /*  
         * Allocate p1 again and then exit - this will leave unfreed  
         * memory on the heap  
         */  
        p1 = malloc( 10 );  
}  
```  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [\_crtDbgFlag](../Topic/_crtDbgFlag.md)   
 [\_CrtCheckMemory](../../c-runtime-library/reference/crtcheckmemory.md)