---
title: Macros _ASSERT, _ASSERTE, _ASSERT_EXPR Macros | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
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
- _ASSERTE
- ASSERTE
- _ASSERT
- _ASSERT_EXPR
dev_langs:
- C++
helpviewer_keywords:
- debugging [CRT], using macros
- _ASSERTE macro
- macros, debugging with
- debug reporting macros
- _ASSERT macro
- _ASSERT_EXPR macro
ms.assetid: e98fd2a6-7f5e-4aa8-8fe8-e93490deba36
caps.latest.revision: 27
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: a0d8c456f20fc048bab91ec5bc9e1639b93adb6d
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="assert-asserte-assertexpr-macros"></a>Macros _ASSERT, _ASSERTE, _ASSERT_EXPR
Avalie uma expressão e gere um relatório de depuração quando o resultado for `False` (somente versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
_ASSERT_EXPR(  
   booleanExpression,  
   message  
);  
_ASSERT(   
   booleanExpression   
);  
_ASSERTE(   
   booleanExpression   
);  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `booleanExpression`  
 Uma expressão escalar (incluindo expressões de ponteiro) que é avaliada como não zero (verdadeiro) ou 0 (falso).  
  
 `message`  
 Uma cadeia de caracteres larga para exibir como parte do relatório.  
  
## <a name="remarks"></a>Comentários  
 As macros `_ASSERT_EXPR`, `_ASSERT` e `_ASSERTE` fornecem um aplicativo com um mecanismo simples e limpo para verificar suposições durante o processo de depuração. Elas são muito flexíveis porque não precisam ser colocadas em instruções `#ifdef` para impedi-las de serem chamadas em um build comercial de um aplicativo. Essa flexibilidade é obtida usando a macro [_DEBUG](../../c-runtime-library/debug.md). `_ASSERT_EXPR`, `_ASSERT` e `_ASSERTE` só estão disponíveis quando `_DEBUG` é definido no tempo de compilação. Quando `_DEBUG` não está definido, as chamadas para essas macros são removidas durante o pré-processamento.  
  
 `_ASSERT_EXPR`, `_ASSERT` e `_ASSERTE` avaliam seu argumento `booleanExpression` e, quando o resultado é `false` (0), imprimem uma mensagem de diagnóstico e chamam [_CrtDbgReportW](../../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md) para gerar um relatório de depuração. A macro `_ASSERT` imprime uma mensagem de diagnóstico simples, `_ASSERTE` inclui uma representação de cadeia de caracteres da expressão com falha na mensagem e `_ASSERT_EXPR` inclui a cadeia de caracteres `message` na mensagem de diagnóstico. Essas macros não fazem nada quando `booleanExpression` é avaliado como diferente de zero.  
  
 `_ASSERT_EXPR`, `_ASSERT` e `_ASSERTE` invocam `_CrtDbgReportW`, o que faz todas as saídas estarem em caracteres largos. `_ASSERTE` imprime corretamente caracteres Unicode em `booleanExpression` e `_ASSERT_EXPR` imprime caracteres Unicode em `message`.  
  
 Porque a macro `_ASSERTE` especifica a expressão com falha e `_ASSERT_EXPR` permite especificar uma mensagem no relatório gerado, elas permitem aos usuários identificar o problema sem consultar o código-fonte do aplicativo. No entanto, há uma desvantagem no sentido de que cada `message` impresso por `_ASSERT_EXPR` e cada expressão avaliada por `_ASSERTE` é incluído no arquivo (versão de depuração) de saída do seu aplicativo como uma constante de cadeia de caracteres. Portanto, se um grande número de chamadas for feito para `_ASSERT_EXPR` ou `_ASSERTE`, essas expressões poderão aumentar muito o tamanho do arquivo de saída.  
  
 A menos que você especifique de outra forma com as funções [_CrtSetReportMode](../../c-runtime-library/reference/crtsetreportmode.md) e [_CrtSetReportFile](../../c-runtime-library/reference/crtsetreportfile.md), as mensagens aparecerão em uma caixa de diálogo pop-up equivalente à configuração:  
  
`_CrtSetReportMode(CRT_ASSERT, _CRTDBG_MODE_WNDW);`  
  
 `_CrtDbgReportW` gera o relatório de depuração e determina seus destinos com base nos modos de relatório atuais e no arquivo definido para o tipo de relatório `_CRT_ASSERT`. Por padrão, erros e falhas de declaração são direcionados para uma janela de mensagem de depuração. As funções [_CrtSetReportMode](../../c-runtime-library/reference/crtsetreportmode.md) e [_CrtSetReportFile](../../c-runtime-library/reference/crtsetreportfile.md) são usadas para definir os destinos de cada tipo de relatório.  
  
 Quando o destino é uma janela de mensagem de depuração e o usuário clique no botão **Tentar Novamente**, `_CrtDbgReportW` retorna 1, fazendo as macros `_ASSERT_EXPR`, `_ASSERT` e `_ASSERTE` iniciarem o depurador, desde que a depuração JIT (Just-In-Time) esteja habilitada.  
  
 Para obter mais informações sobre o processo de geração de relatórios, consulte a função [_CrtDbgReport, _CrtDbgReportW](../../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md). Para obter mais informações sobre como resolver falhas de declaração e usar essas macros como um mecanismo de tratamento de erro de depuração, consulte [Usando macros para verificação e relatórios](/visualstudio/debugger/macros-for-reporting).  
  
 Além das macros `_ASSERT`, a macro [assert](../../c-runtime-library/reference/assert-macro-assert-wassert.md) pode ser usada para verificar a lógica do programa. Essa macro está disponível nas versões de depuração e liberação das bibliotecas. As macros de depuração [_RPT, _RPTF](../../c-runtime-library/reference/rpt-rptf-rptw-rptfw-macros.md) também estão disponíveis para gerar um relatório de depuração, mas não avaliam uma expressão. As macros `_RPT` geram um relatório simples. As macros `_RPTF` incluem o arquivo de origem e o número de linha no qual a macro do relatório foi chamada no relatório gerado. Estão disponíveis versões de caracteres largos dessas macros (`_RPTWn`, `_RPTFWn`). As versões de caractere largo são idênticas às versões de caractere estreito, exceto que cadeias de caracteres largos são usadas para todos os parâmetros de cadeia de caracteres e de saída.  
  
 Embora `_ASSERT_EXPR`, `_ASSERT` e `_ASSERTE` sejam macros e estejam disponíveis incluindo \<crtdbg.h>, o aplicativo deve ser vinculado a uma versão de depuração da biblioteca em tempo de execução C quando `_DEBUG` for definido, pois essas macros chamam outras funções de tempo de execução.  
  
## <a name="requirements"></a>Requisitos  
  
|Macro|Cabeçalho necessário|  
|-----------|---------------------|  
|`_ASSERT_EXPR`,                  `_ASSERT`, `_ASSERTE`|\<crtdbg.h>|  
  
## <a name="example"></a>Exemplo  
 Neste programa, as chamadas são feitas para as macros `_ASSERT` e `_ASSERTE` para testar a condição `string1 == string2`. Se a condição falhar, essas macros imprimirão uma mensagem de diagnóstico. O grupo de macros `_RPTn` e `_RPTFn` também é utilizado neste programa, como uma alternativa à função `printf`.  
  
```C  
// crt_ASSERT_macro.c  
// compile with: /D_DEBUG /MTd /Od /Zi /link /verbose:lib /debug  
//  
// This program uses the _ASSERT and _ASSERTE debugging macros.  
//  
  
#include <stdio.h>  
#include <string.h>  
#include <malloc.h>  
#include <crtdbg.h>  
  
int main()  
{  
   char *p1, *p2;  
  
   // The Reporting Mode and File must be specified  
   // before generating a debug report via an assert  
   // or report macro.  
   // This program sends all report types to STDOUT.  
   _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);  
   _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);  
   _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);  
   _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);  
   _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);  
   _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);  
  
   // Allocate and assign the pointer variables.  
   p1 = (char *)malloc(10);  
   strcpy_s(p1, 10, "I am p1");  
   p2 = (char *)malloc(10);  
   strcpy_s(p2, 10, "I am p2");  
  
   // Use the report macros as a debugging  
   // warning mechanism, similar to printf.  
   // Use the assert macros to check if the   
   // p1 and p2 variables are equivalent.  
   // If the expression fails, _ASSERTE will  
   // include a string representation of the  
   // failed expression in the report.  
   // _ASSERT does not include the  
   // expression in the generated report.  
   _RPT0(_CRT_WARN,  
       "Use the assert macros to evaluate the expression p1 == p2.\n");  
   _RPTF2(_CRT_WARN, "\n Will _ASSERT find '%s' == '%s' ?\n", p1, p2);  
   _ASSERT(p1 == p2);  
  
   _RPTF2(_CRT_WARN, "\n\n Will _ASSERTE find '%s' == '%s' ?\n",  
          p1, p2);  
   _ASSERTE(p1 == p2);  
  
   _RPT2(_CRT_ERROR, "'%s' != '%s'\n", p1, p2);  
  
   free(p2);  
   free(p1);  
  
   return 0;  
}  
```  
  
```Output  
Use the assert macros to evaluate the expression p1 == p2.  
crt_ASSERT_macro.c(54) :   
 Will _ASSERT find 'I am p1' == 'I am p2' ?  
crt_ASSERT_macro.c(55) : Assertion failed!  
crt_ASSERT_macro.c(58) :   
  
 Will _ASSERTE find 'I am p1' == 'I am p2' ?  
crt_ASSERT_macro.c(59) : Assertion failed: p1 == p2  
'I am p1' != 'I am p2'  
```  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [assert Macro, _assert, _wassert](../../c-runtime-library/reference/assert-macro-assert-wassert.md)   
 [Macros _RPT, _RPTF, _RPTW, _RPTFW](../../c-runtime-library/reference/rpt-rptf-rptw-rptfw-macros.md)
