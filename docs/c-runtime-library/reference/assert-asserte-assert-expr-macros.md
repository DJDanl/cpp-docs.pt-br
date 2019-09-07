---
title: Macros _ASSERT, _ASSERTE, _ASSERT_EXPR
ms.date: 11/04/2016
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
helpviewer_keywords:
- debugging [CRT], using macros
- _ASSERTE macro
- macros, debugging with
- debug reporting macros
- _ASSERT macro
- _ASSERT_EXPR macro
ms.assetid: e98fd2a6-7f5e-4aa8-8fe8-e93490deba36
ms.openlocfilehash: d2d83c3afa8e22c1f75480fe2afefa8bf68be858
ms.sourcegitcommit: 180f63704f6ddd07a4172a93b179cf0733fd952d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2019
ms.locfileid: "70740019"
---
# <a name="_assert-_asserte-_assert_expr-macros"></a>Macros _ASSERT, _ASSERTE, _ASSERT_EXPR

Avaliar uma expressão e gerar um relatório de depuração quando o resultado for **false** (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
// Typical usage:
_ASSERT_EXPR( booleanExpression, message );
_ASSERT( booleanExpression );
_ASSERTE( booleanExpression );
```

### <a name="parameters"></a>Parâmetros

*booleanExpression*<br/>
Uma expressão escalar (incluindo expressões de ponteiro) que é avaliada como não zero (verdadeiro) ou 0 (falso).

*message*<br/>
Uma cadeia de caracteres larga para exibir como parte do relatório.

## <a name="remarks"></a>Comentários

As macros **_ASSERT_EXPR**, **_ASSERT** e **_ASSERTE** fornecem um aplicativo com um mecanismo limpo e simples para verificar suposições durante o processo de depuração. Elas são muito flexíveis porque não precisam ser colocadas em instruções `#ifdef` para impedi-las de serem chamadas em um build comercial de um aplicativo. Essa flexibilidade é obtida usando a macro [_DEBUG](../../c-runtime-library/debug.md). **_ASSERT_EXPR**, **_ASSERT** e **_ASSERTE** só estão disponíveis quando **_DEBUG** é definido no momento da compilação. Quando **_DEBUG** não é definido, as chamadas para essas macros são removidas durante o pré-processamento.

**_ASSERT_EXPR**, **_ASSERT** e **_ASSERTE** avaliam seu argumento *booliante* e quando o resultado é **false** (0), eles imprimem uma mensagem de diagnóstico e chamam _ _ [CrtDbgReportW](crtdbgreport-crtdbgreportw.md) para gerar um relatório de depuração. A macro **_ASSERT** imprime uma mensagem de diagnóstico simples, **_ASSERTE** inclui uma representação de cadeia de caracteres da expressão com falha na mensagem, e **_ASSERT_EXPR** inclui a cadeia de caracteres de *mensagem* na mensagem de diagnóstico. Essas macros não fazem nada quando *booliana* é avaliada como diferente de zero.

**_ASSERT_EXPR**, **_ASSERT** e **_ASSERTE** invoca _ _ **CrtDbgReportW**, que faz com que toda a saída esteja em caracteres largos. O **_ASSERTE** imprime corretamente os caracteres Unicode em *booliana* e **_ASSERT_EXPR** imprime caracteres Unicode na *mensagem*.

Como a macro **_ASSERTE** especifica a expressão com falha e o **_ASSERT_EXPR** permite especificar uma mensagem no relatório gerado, eles permitem que os usuários identifiquem o problema sem se referir ao código-fonte do aplicativo. No entanto, uma desvantagem existe em que todas as *mensagens* impressas por **_ASSERT_EXPR** e todas as expressões avaliadas por **_ASSERTE** são incluídas no arquivo de saída (versão de depuração) do seu aplicativo como uma constante de cadeia de caracteres. Portanto, se um grande número de chamadas for feito para **_ASSERT_EXPR** ou **_ASSERTE**, essas expressões poderão aumentar muito o tamanho do arquivo de saída.

A menos que você especifique de outra forma com as funções [_CrtSetReportMode](crtsetreportmode.md) e [_CrtSetReportFile](crtsetreportfile.md), as mensagens aparecerão em uma caixa de diálogo pop-up equivalente à configuração:

```C
_CrtSetReportMode(CRT_ASSERT, _CRTDBG_MODE_WNDW);
````

_ **CrtDbgReportW** gera o relatório de depuração e determina seu destino ou destinos, com base no modo de relatório atual ou nos modos e no arquivo definidos para o tipo de relatório **_CRT_ASSERT** . Por padrão, erros e falhas de declaração são direcionados para uma janela de mensagem de depuração. As funções [_CrtSetReportMode](crtsetreportmode.md) e [_CrtSetReportFile](crtsetreportfile.md) são usadas para definir os destinos de cada tipo de relatório.

Quando o destino é uma janela de mensagem de depuração e o usuário clica no botão de **repetição** , _ **CrtDbgReportW** retorna 1, fazendo com que as macros **_ASSERT_EXPR**, **_ASSERT** e **_ASSERTE** iniciem o depurador fornecido a depuração Just-in-time (JIT) está habilitada.

Para obter mais informações sobre o processo de geração de relatórios, consulte a função [_CrtDbgReport, _CrtDbgReportW](crtdbgreport-crtdbgreportw.md). Para obter mais informações sobre como resolver falhas de declaração e usar essas macros como um mecanismo de tratamento de erro de depuração, consulte [Usando macros para verificação e relatórios](/visualstudio/debugger/macros-for-reporting).

Além das macros **_ASSERT** , a macro [Assert](assert-macro-assert-wassert.md) pode ser usada para verificar a lógica do programa. Essa macro está disponível nas versões de depuração e liberação das bibliotecas. As macros de depuração [_RPT, _RPTF](rpt-rptf-rptw-rptfw-macros.md) também estão disponíveis para gerar um relatório de depuração, mas não avaliam uma expressão. As macros **_RPT** geram um relatório simples. As macros **_RPTF** incluem o arquivo de origem e o número de linha em que a macro de relatório foi chamada no relatório gerado. As versões de caracteres largos dessas macros estão disponíveis ( **_RPTW**, **_RPTFW**). As versões de caractere largo são idênticas às versões de caractere estreito, exceto que cadeias de caracteres largos são usadas para todos os parâmetros de cadeia de caracteres e de saída.

Embora **_ASSERT_EXPR**, **_ASSERT** e **_ASSERTE** sejam macros e estejam disponíveis incluindo \<CRTDBG. h >, o aplicativo deve vincular com uma versão de depuração da biblioteca de tempo de execução do C quando **_DEBUG** é definido porque Essas macros chamam outras funções de tempo de execução.

## <a name="requirements"></a>Requisitos

|Macro|Cabeçalho necessário|
|-----------|---------------------|
|**_ASSERT_EXPR**, **_ASSERT**, **_ASSERTE**|\<crtdbg.h>|

## <a name="example"></a>Exemplo

Neste programa, são feitas chamadas para as macros **_ASSERT** e **_ASSERTE** para testar a condição `string1 == string2`. Se a condição falhar, essas macros imprimirão uma mensagem de diagnóstico. O grupo de macros **_RPT** e **_RPTF** também é exercido neste programa, como uma alternativa à função **printf** .

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

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
[assert Macro, _assert, _wassert](assert-macro-assert-wassert.md)<br/>
[Macros _RPT, _RPTF, _RPTW, _RPTFW](rpt-rptf-rptw-rptfw-macros.md)<br/>
