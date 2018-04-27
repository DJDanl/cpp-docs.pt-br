---
title: Macros _ASSERT, _ASSERTE, _ASSERT_EXPR Macros | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
ms.workload:
- cplusplus
ms.openlocfilehash: 2a089017b38d27130883bb091190e92d2b1e3469
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="assert-asserte-assertexpr-macros"></a>Macros _ASSERT, _ASSERTE, _ASSERT_EXPR

Avaliar uma expressão e gerar um relatório de depuração quando o resultado é **False** (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
// Typical usage:
_ASSERT_EXPR( booleanExpression, message );
_ASSERT( booleanExpression );
_ASSERTE( booleanExpression );
```

### <a name="parameters"></a>Parâmetros

*booleanExpression* uma expressão escalar (incluindo expressões de ponteiro) que é avaliada como zero (verdadeiro) ou 0 (false).

*mensagem* uma cadeia de caracteres longa para exibir como parte do relatório.

## <a name="remarks"></a>Comentários

O **_ASSERT_EXPR**, **Assert** e **asserte** macros fornecem um aplicativo com um mecanismo simple e transparente para fazer suposições durante o processo de depuração. Elas são muito flexíveis porque não precisam ser colocadas em instruções `#ifdef` para impedi-las de serem chamadas em um build comercial de um aplicativo. Essa flexibilidade é obtida usando a macro [_DEBUG](../../c-runtime-library/debug.md). **_ASSERT_EXPR**, **Assert** e **asserte** só estão disponíveis quando **Debug** é definido em tempo de compilação. Quando **Debug** é chamadas para essas macros não definida, são removidas durante o pré-processamento.

**_ASSERT_EXPR**, **Assert** e **asserte** avaliar seus *booleanExpression* argumento e quando o resultado é **false**(0), eles imprimem uma mensagem de diagnóstico e chame [CrtDbgReportW](crtdbgreport-crtdbgreportw.md) para gerar um relatório de depuração. O **Assert** macro imprime uma mensagem de diagnóstica simple, **asserte** inclui uma representação de cadeia de caracteres da expressão com falha na mensagem, e **_ASSERT_EXPR** inclui o *mensagem* cadeia de caracteres na mensagem de diagnóstico. Essas macros não fazem nada quando *booleanExpression* é avaliada como zero.

**_ASSERT_EXPR**, **Assert** e **asserte** invocar **CrtDbgReportW**, que faz com que todas as saídas em caracteres largos. **Asserte** imprime corretamente caracteres Unicode em *booleanExpression* e **_ASSERT_EXPR** imprime caracteres Unicode em *mensagem*.

Porque o **asserte** macro Especifica a expressão com falha, e **_ASSERT_EXPR** permite que você especificar uma mensagem no relatório gerado, elas permitem que os usuários a identificar o problema sem fazer referência à código de origem do aplicativo. No entanto, uma desvantagem existe em que cada *mensagem* impressos por **_ASSERT_EXPR** e cada expressão avaliada por **asserte** está incluído na saída (versão de depuração) arquivo do seu aplicativo como uma constante de cadeia de caracteres. Portanto, se um grande número de chamadas são feitas para **_ASSERT_EXPR** ou **asserte**, essas expressões podem aumentar significativamente o tamanho do seu arquivo de saída.

A menos que você especifique de outra forma com as funções [_CrtSetReportMode](crtsetreportmode.md) e [_CrtSetReportFile](crtsetreportfile.md), as mensagens aparecerão em uma caixa de diálogo pop-up equivalente à configuração:

```C
_CrtSetReportMode(CRT_ASSERT, _CRTDBG_MODE_WNDW);
````

**CrtDbgReportW** gera o relatório de depuração e determina o destino ou os destinos, com base no modo de relatório atual ou modos de arquivo definido para o **_CRT_ASSERT** tipo de relatório. Por padrão, erros e falhas de declaração são direcionados para uma janela de mensagem de depuração. As funções [_CrtSetReportMode](crtsetreportmode.md) e [_CrtSetReportFile](crtsetreportfile.md) são usadas para definir os destinos de cada tipo de relatório.

Quando o destino é uma janela de mensagem de depuração e o usuário clica o **novamente** botão, **CrtDbgReportW** retorna 1, fazendo com que o **_ASSERT_EXPR**, **_ ASSERT** e **asserte** macros para iniciar o depurador, desde que a depuração just-in-time (JIT) está habilitada.

Para obter mais informações sobre o processo de geração de relatórios, consulte a função [_CrtDbgReport, _CrtDbgReportW](crtdbgreport-crtdbgreportw.md). Para obter mais informações sobre como resolver falhas de declaração e usar essas macros como um mecanismo de tratamento de erro de depuração, consulte [Usando macros para verificação e relatórios](/visualstudio/debugger/macros-for-reporting).

Além de **Assert** macros, o [assert](assert-macro-assert-wassert.md) macro pode ser usada para verificar a lógica do programa. Essa macro está disponível nas versões de depuração e liberação das bibliotecas. As macros de depuração [_RPT, _RPTF](rpt-rptf-rptw-rptfw-macros.md) também estão disponíveis para gerar um relatório de depuração, mas não avaliam uma expressão. O **RPT** macros de geram um relatório simples. O **rptf** macros incluem o número de arquivos e linhas de origem onde a macro de relatório foi chamada no relatório gerado. Versões de caractere largo dessas macros estão disponíveis (**rptw**, **rptfw**). As versões de caractere largo são idênticas às versões de caractere estreito, exceto que cadeias de caracteres largos são usadas para todos os parâmetros de cadeia de caracteres e de saída.

Embora **_ASSERT_EXPR**, **Assert** e **asserte** são macros e estão disponíveis, incluindo \<crtdbg. h >, o aplicativo deve estabelecer um vínculo com um tipo de depuração versão da biblioteca de tempo de execução do C quando **Debug** é definida porque essas macros chamam outras funções de tempo de execução.

## <a name="requirements"></a>Requisitos

|Macro|Cabeçalho necessário|
|-----------|---------------------|
|**_ASSERT_EXPR**, **ASSERT**, **ASSERTE**|\<crtdbg.h>|

## <a name="example"></a>Exemplo

Neste programa, as chamadas são feitas para o **Assert** e **asserte** macros para testar a condição `string1 == string2`. Se a condição falhar, essas macros imprimirão uma mensagem de diagnóstico. O **RPT** e **rptf** grupo de macros também é utilizado neste programa, como uma alternativa para o **printf** função.

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
