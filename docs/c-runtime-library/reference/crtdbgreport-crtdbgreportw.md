---
title: "_CrtDbgReport, _CrtDbgReportW | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_CrtDbgReport"
  - "_CrtDbgReportW"
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
  - "CrtDbgReport"
  - "CrtDbgReportW"
  - "_CrtDbgReportW"
  - "_CrtDbgReport"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "geração de relatórios de depuração"
  - "Função _CrtDbgReport"
  - "Função CrtDbgReport"
  - "Função CrtDbgReportW"
  - "Função _CrtDbgReportW"
ms.assetid: 6e581fb6-f7fb-4716-9432-f0145d639ecc
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _CrtDbgReport, _CrtDbgReportW
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

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
 Para todos os destinos do relatório, `_CrtDbgReport` e `_CrtDbgReportW` retornam -1 em caso de erro e 0 caso nenhum erro seja encontrado. No entanto, quando o destino do relatório é uma janela de mensagem de depuração e o usuário clica o **novamente** botão, essas funções retornam 1. Se o usuário clica o **anular** botão na janela de mensagem de depuração, essas funções é o imediatamente a anulação e não retornam um valor.  
  
 O [rpt, rptf](../Topic/_RPT,%20_RPTF,%20_RPTW,%20_RPTFW%20Macros.md) Depurar macros chamada `_CrtDbgReport` para gerar seu depuração relatórios. As versões de caracteres largos dessas macros, bem como [Assert &#91; E &#93;](../Topic/_ASSERT,%20_ASSERTE,%20_ASSERT_EXPR%20Macros.md), `_RPTW``n` e `_RPTFW``n`, use `_CrtDbgReportW` para gerar seu depuração relatórios. Quando `_CrtDbgReport` ou `_CrtDbgReportW` retorna o valor 1, essas macros iniciam o depurador se a depuração JIT (just-in-time) estiver habilitada.  
  
## <a name="remarks"></a>Comentários  
 `_CrtDbgReport` e `_CrtDbgReportW` podem enviar o relatório de depuração para três destinos diferentes: um arquivo de relatório de depuração, um monitor de depuração (o depurador [!INCLUDE[vsprvs](../../assembler/masm/includes/vsprvs_md.md)]) ou uma janela de mensagem de depuração. Duas funções de configuração [CrtSetReportMode](../../c-runtime-library/reference/crtsetreportmode.md) e [crtsetreportfile](../Topic/_CrtSetReportFile.md), são usados para especificar o destino ou destinos para cada tipo de relatório. Essas funções permitem o controle independente do destino de cada tipo de relatório. Por exemplo, é possível especificar que um `reportType` de `_CRT_WARN` seja enviado somente ao monitor de depuração, enquanto um `reportType` de `_CRT_ASSERT` é enviado a uma janela de mensagem de depuração e a um arquivo de relatório definido pelo usuário.  
  
 `_CrtDbgReportW` é a versão de caracteres largos do `_CrtDbgReport`. Todos os parâmetros de saída e cadeia de caracteres estão em cadeias de caracteres largos. Caso contrário, não há diferença da versão de caractere de byte único.  
  
 `_CrtDbgReport` e `_CrtDbgReportW` criam a mensagem do usuário para o relatório de depuração ao substituir os argumentos `argument`[`n`] na cadeia de caracteres `format` usando as mesmas regras definidas pelas funções `printf` ou `wprintf`. Essas funções geram o relatório de depuração e determinam o destino (ou destinos) com base nos modos do relatório atual e no arquivo definido para `reportType`. Quando o relatório é enviado para uma janela de mensagem de depuração, `filename`, `lineNumber` e `moduleName` são incluídos nas informações exibidas na janela.  
  
 O tabela a seguir lista as opções disponíveis para o modo (ou modos), o arquivo do relatório e o comportamento resultante de `_CrtDbgReport` e `_CrtDbgReportW`. Essas opções são definidas como sinalizadores de bits em \<crtdbg.h>.  
  
|Modo do relatório|Arquivo do relatório|Comportamento `_CrtDbgReport`, `_CrtDbgReportW`|  
|-----------------|-----------------|------------------------------------------------|  
|`_CRTDBG_MODE_DEBUG`|Não aplicável|Grava mensagens usando o Windows [OutputDebugString](http://msdn.microsoft.com/library/windows/desktop/aa363362.aspx) API.|  
|`_CRTDBG_MODE_WNDW`|Não aplicável|Chama o Windows [MessageBox](http://msdn.microsoft.com/library/windows/desktop/ms645505) API para criar a caixa de mensagem para exibir a mensagem junto com **anular**, **novamente**, e **Ignorar** botões. Se um usuário clicar **anular**, `_CrtDbgReport` ou `_CrtDbgReport` abortado imediatamente. Se um usuário clicar **novamente**, ele retorna 1. Se um usuário clicar **Ignorar**, a execução continua e `_CrtDbgReport` e `_CrtDbgReportW` retornam 0. Observe que clicar em **Ignorar** quando uma condição de erro existe sempre resulta em "comportamento inesperado".|  
|`_CRTDBG_MODE_FILE`|`__HFILE`|Grava a mensagem fornecida pelo usuário `HANDLE`, usando o Windows [WriteFile](http://msdn.microsoft.com/library/windows/desktop/aa365747.aspx) API e não verifica a validade do identificador de arquivo; o aplicativo é responsável por abrir o arquivo de relatório e passar um identificador de arquivo válido.|  
|`_CRTDBG_MODE_FILE`|`_CRTDBG_FILE_STDERR`|Grava a mensagem no `stderr`.|  
|`_CRTDBG_MODE_FILE`|`_CRTDBG_FILE_STDOUT`|Grava a mensagem no `stdout`.|  
  
 O relatório pode ser enviado para um, dois ou três destinos ou nenhum destino. Para obter mais informações sobre como especificar o modo de relatório ou modos e arquivo de relatório, consulte o [CrtSetReportMode](../../c-runtime-library/reference/crtsetreportmode.md) e [crtsetreportfile](../Topic/_CrtSetReportFile.md) funções. Para obter mais informações sobre como usar as macros de depuração e funções de relatórios, consulte [Macros para relatórios](../Topic/Macros%20for%20Reporting.md).  
  
 Se seu aplicativo precisar de mais flexibilidade do que o fornecido por `_CrtDbgReport` e `_CrtDbgReportW`, você pode escrever seu próprio relatório de função e vinculá-lo para a biblioteca de tempo de execução C mecanismo de relatórios usando o [crtsetreporthook](../../c-runtime-library/reference/crtsetreporthook.md) função.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_CrtDbgReport`|\<crtdbg.h>|  
|`_CrtDbgReportW`|\<crtdbg.h>|  
  
 `_CrtDbgReport` e `_CrtDbgReportW` são extensões da Microsoft. Para obter mais informações, consulte [compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="libraries"></a>Libraries  
 Versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md) somente.  
  
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
  
 Consulte [crt_dbg2](http://msdn.microsoft.com/pt-br/21e1346a-6a17-4f57-b275-c76813089167) para obter um exemplo de como alterar a função de relatório.  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
  
-   [System::Diagnostics::Debug::Write](https://msdn.microsoft.com/en-us/library/system.diagnostics.debug.write.aspx)  
  
-   [System::Diagnostics::Debug::WriteLine](https://msdn.microsoft.com/en-us/library/system.diagnostics.debug.writeline.aspx)  
  
-   [System::Diagnostics::Debug::WriteIf](https://msdn.microsoft.com/en-us/library/system.diagnostics.debug.writeif.aspx)  
  
-   [System::Diagnostics::Debug::WriteLineIf](https://msdn.microsoft.com/en-us/library/system.diagnostics.debug.writelineif.aspx)  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [CrtSetReportMode](../../c-runtime-library/reference/crtsetreportmode.md)   
 [Crtsetreportfile](../Topic/_CrtSetReportFile.md)   
 [printf, printf_l, and wprintf, wprintf_l](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [DEBUG](../Topic/_DEBUG.md)