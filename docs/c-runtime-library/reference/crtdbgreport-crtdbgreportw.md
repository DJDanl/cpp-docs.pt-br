---
title: _CrtDbgReport, _CrtDbgReportW | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _CrtDbgReport
- _CrtDbgReportW
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
apitype: DLLExport
f1_keywords:
- CrtDbgReport
- CrtDbgReportW
- _CrtDbgReportW
- _CrtDbgReport
dev_langs:
- C++
helpviewer_keywords:
- debug reporting
- _CrtDbgReport function
- CrtDbgReport function
- CrtDbgReportW function
- _CrtDbgReportW function
ms.assetid: 6e581fb6-f7fb-4716-9432-f0145d639ecc
caps.latest.revision: 18
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: f197e4f6341508f05e566f45566f26a18be43bed
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="crtdbgreport-crtdbgreportw"></a>_CrtDbgReport, _CrtDbgReportW
Gera um relatório com uma mensagem de depuração e envia o relatório para três destinos possíveis (somente versões de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _CrtDbgReport(   
   int reportType,  
   const char *filename,  
   int linenumber,  
   const char *moduleName,  
   const char *format [,  
   argument] ...   
);  
int _CrtDbgReportW(   
   int reportType,  
   const wchar_t *filename,  
   int linenumber,  
   const wchar_t *moduleName,  
   const wchar_t *format [,  
   argument] ...   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `reportType`  
 Tipo de relatório: `_CRT_WARN`, `_CRT_ERROR` e `_CRT_ASSERT`.  
  
 `filename`  
 Ponteiro para o nome do arquivo de origem em que a asserção/relatório ocorreu ou que é `NULL`.  
  
 `linenumber`  
 Número da linha no arquivo de origem em que a asserção/relatório ocorreu ou que é `NULL`.  
  
 `moduleName`  
 Ponteiro para o nome do módulo (.exe ou .dll) em que a asserção/relatório ocorreu.  
  
 `format`  
 Ponteiro para a cadeia de caracteres formato-controle usada para criar a mensagem do usuário.  
  
 `argument`  
 Argumentos de substituição opcionais usados por `format`.  
  
## <a name="return-value"></a>Valor de retorno  
 Para todos os destinos de relatório, `_CrtDbgReport` e `_CrtDbgReportW` retornar -1 se ocorrer um erro e 0 se nenhum erro for encontrado. No entanto, quando o destino do relatório é uma janela de mensagem de depuração e o usuário clica no botão **Tentar novamente**, essas funções retornam 1. Se o usuário clicar no botão **Anular** na janela Mensagem de Depuração, essas funções serão anuladas imediatamente e não retornarão um valor.  
  
 As macros de depuração [_RPT, _RPTF](../../c-runtime-library/reference/rpt-rptf-rptw-rptfw-macros.md) chamam `_CrtDbgReport` para gerar seus relatórios de depuração. As versões de caractere largo dessas macros, bem como [_ASSERT&#91;E&#93;](../../c-runtime-library/reference/assert-asserte-assert-expr-macros.md), `_RPTW n` e `_RPTFW n`, usam `_CrtDbgReportW` para gerar seus relatórios de depuração. Quando `_CrtDbgReport` ou `_CrtDbgReportW` retorna o valor 1, essas macros iniciam o depurador se a depuração JIT (just-in-time) estiver habilitada.  
  
## <a name="remarks"></a>Comentários  
 `_CrtDbgReport` e `_CrtDbgReportW` podem enviar o relatório de depuração para três destinos diferentes: um arquivo de relatório de depuração, um monitor de depuração (o depurador [!INCLUDE[vsprvs](../../assembler/masm/includes/vsprvs_md.md)]) ou uma janela de mensagem de depuração. Duas funções de configuração, [_CrtSetReportMode](../../c-runtime-library/reference/crtsetreportmode.md) e [_CrtSetReportFile](../../c-runtime-library/reference/crtsetreportfile.md), são usadas para especificar os destinos de cada tipo de relatório. Essas funções permitem o controle independente do destino de cada tipo de relatório. Por exemplo, é possível especificar que um `reportType` de `_CRT_WARN` seja enviado somente ao monitor de depuração, enquanto um `reportType` de `_CRT_ASSERT` é enviado a uma janela de mensagem de depuração e a um arquivo de relatório definido pelo usuário.  
  
 `_CrtDbgReportW` é a versão de caracteres largos do `_CrtDbgReport`. Todos os parâmetros de saída e cadeia de caracteres estão em cadeias de caracteres largos. Caso contrário, não há diferença da versão de caractere de byte único.  
  
 `_CrtDbgReport` e `_CrtDbgReportW` criam a mensagem do usuário para o relatório de depuração ao substituir os argumentos `argument`[`n`] na cadeia de caracteres `format` usando as mesmas regras definidas pelas funções `printf` ou `wprintf`. Essas funções geram o relatório de depuração e determinam o destino (ou destinos) com base nos modos do relatório atual e no arquivo definido para `reportType`. Quando o relatório é enviado para uma janela de mensagem de depuração, `filename`, `lineNumber` e `moduleName` são incluídos nas informações exibidas na janela.  
  
 O tabela a seguir lista as opções disponíveis para o modo (ou modos), o arquivo do relatório e o comportamento resultante de `_CrtDbgReport` e `_CrtDbgReportW`. Essas opções são definidas como sinalizadores de bit em \<crtdbg.h>.  
  
|Modo do relatório|Arquivo do relatório|Comportamento `_CrtDbgReport`, `_CrtDbgReportW`|  
|-----------------|-----------------|------------------------------------------------|  
|`_CRTDBG_MODE_DEBUG`|Não aplicável|Grava mensagens usando a API [OutputDebugString](http://msdn.microsoft.com/library/windows/desktop/aa363362.aspx) do Windows.|  
|`_CRTDBG_MODE_WNDW`|Não aplicável|Chama a API [MessageBox](http://msdn.microsoft.com/library/windows/desktop/ms645505) do Windows para criar uma caixa de mensagem e exibir a mensagem junto com os botões **Anular**, **Tentar novamente** e **Ignorar**. Se um usuário clicar em **Anular**, `_CrtDbgReport` ou `_CrtDbgReport` será anulado imediatamente. Se um usuário clicar em **Tentar novamente**, ele retornará 1. Se um usuário clicar em **Ignorar**, a execução continuará e `_CrtDbgReport` e `_CrtDbgReportW` retornarão 0. Observe que clicar em **Ignorar** quando há uma condição de erro geralmente resulta em “comportamento inesperado”.|  
|`_CRTDBG_MODE_FILE`|`__HFILE`|Grava mensagens no `HANDLE` fornecido pelo usuário, usando a API [WriteFile](http://msdn.microsoft.com/library/windows/desktop/aa365747.aspx) do Windows e não verifica a validade do identificador de arquivo: o aplicativo é responsável por abrir o arquivo de relatório e passar um identificador de arquivo válido.|  
|`_CRTDBG_MODE_FILE`|`_CRTDBG_FILE_STDERR`|Grava a mensagem no `stderr`.|  
|`_CRTDBG_MODE_FILE`|`_CRTDBG_FILE_STDOUT`|Grava a mensagem no `stdout`.|  
  
 O relatório pode ser enviado para um, dois ou três destinos ou nenhum destino. Para obter mais informações sobre como especificar os modos de relatório e o arquivo de relatório, consulte as funções [_CrtSetReportMode](../../c-runtime-library/reference/crtsetreportmode.md) e [_CrtSetReportFile](../../c-runtime-library/reference/crtsetreportfile.md). Para obter mais informações sobre como usar as macros de depuração e as funções de relatório, consulte [Macros para relatórios](/visualstudio/debugger/macros-for-reporting).  
  
 Caso seu aplicativo precise de mais flexibilidade do que `_CrtDbgReport` e `_CrtDbgReportW` fornecem, é possível escrever sua própria função de relatório e vinculá-la ao mecanismo de relatório da biblioteca em tempo de execução C usando a função [_CrtSetReportHook](../../c-runtime-library/reference/crtsetreporthook.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_CrtDbgReport`|\<crtdbg.h>|  
|`_CrtDbgReportW`|\<crtdbg.h>|  
  
 `_CrtDbgReport` e `_CrtDbgReportW` são extensões da Microsoft. Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="libraries"></a>Libraries  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_crtdbgreport.c  
#include <crtdbg.h>  
  
int main(int argc, char *argv[]) {  
#ifdef _DEBUG  
   _CrtDbgReport(_CRT_ASSERT, __FILE__, __LINE__, argv[0], NULL);  
#endif  
}  
```  
  
 Consulte [crt_dbg2](http://msdn.microsoft.com/en-us/21e1346a-6a17-4f57-b275-c76813089167) para obter um exemplo de como alterar a função de relatório.  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [_CrtSetReportMode](../../c-runtime-library/reference/crtsetreportmode.md)   
 [_CrtSetReportFile](../../c-runtime-library/reference/crtsetreportfile.md)   
 [printf, _printf_l, wprintf, _wprintf_l](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [_DEBUG](../../c-runtime-library/debug.md)
