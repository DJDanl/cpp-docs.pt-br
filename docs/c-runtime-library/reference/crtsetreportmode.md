---
title: _CrtSetReportMode
ms.date: 11/04/2016
api_name:
- _CrtSetReportMode
api_location:
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _CrtSetReportMode
- CrtSetReportMode
helpviewer_keywords:
- _CrtSetReportMode function
- CrtSetReportMode function
ms.assetid: 3ecc6a12-afdd-4242-b046-8187ff6d4b36
ms.openlocfilehash: ae7e83ac009d572f8a9f6484519b0cdfb7499ce3
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70938456"
---
# <a name="_crtsetreportmode"></a>_CrtSetReportMode

Especifica o destino ou destinos para um tipo de relatório específico gerado por **_CrtDbgReport** e todas as macros que chamam [_CrtDbgReport, _ CrtDbgReportW](crtdbgreport-crtdbgreportw.md), como [_ASSERT, _ASSERTE, _ASSERT_EXPR MACROs](assert-asserte-assert-expr-macros.md), [_ASSERT, _ASSERTE Macros ASSERT_EXPR](assert-asserte-assert-expr-macros.md), [_RPT, _RPTF, _RPTW, _RPTFW macros](rpt-rptf-rptw-rptfw-macros.md)e [_RPT, _RPTF, _RPTW, _RPTFW macros](rpt-rptf-rptw-rptfw-macros.md) (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
int _CrtSetReportMode(
   int reportType,
   int reportMode
);
```

### <a name="parameters"></a>Parâmetros

*reportType*<br/>
Tipo de relatório: **_CRT_WARN**, **_CRT_ERROR**e **_CRT_ASSERT**.

*reportMode*<br/>
Novo modo de relatório ou modos para *reportType*.

## <a name="return-value"></a>Valor de retorno

Após a conclusão bem-sucedida, **_CrtSetReportMode** retorna o modo de relatório ou os modos anteriores para o tipo de relatório especificado em *reportType*. Se um valor inválido for passado como *reportType* ou um modo inválido for especificado para *reportMode*, **_CrtSetReportMode** invocará o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função definirá **errno** como **EINVAL** e retornará-1. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

**_CrtSetReportMode** especifica o destino de saída para **_CrtDbgReport**. Como as macros [_ASSERT](assert-asserte-assert-expr-macros.md), [_ASSERTE](assert-asserte-assert-expr-macros.md), [_RPT](rpt-rptf-rptw-rptfw-macros.md)e [_RPTF](rpt-rptf-rptw-rptfw-macros.md) chamam **_CrtDbgReport**, **_CrtSetReportMode** especifica o destino de saída do texto especificado com essas macros.

Quando [_DEBUG](../../c-runtime-library/debug.md) não é definido, as chamadas para **_CrtSetReportMode** são removidas durante o pré-processamento.

Se você não chamar **_CrtSetReportMode** para definir o destino de saída de mensagens, os padrões a seguir estarão em vigor:

- Erros e falhas de declaração são direcionados para uma janela de mensagem de depuração.

- Os avisos de aplicativos do Windows são enviados para a janela de saída do depurador.

- Os avisos de aplicativos do console não são exibidos.

A tabela a seguir lista os tipos de relatório definidos em Crtdbg.h.

|Tipo de relatório|Descrição|
|-----------------|-----------------|
|**_CRT_WARN**|Avisos, mensagens e informações que não precisam de atenção imediata.|
|**_CRT_ERROR**|Erros, problemas irrecuperáveis e problemas que exigem atenção imediata.|
|**_CRT_ASSERT**|Falhas de asserção (expressões declaradas que são avaliadas como **false**).|

A função **_CrtSetReportMode** atribui o novo modo de relatório especificado em *reportMode* ao tipo de relatório especificado em *reportType* e retorna o modo de relatório definido anteriormente para *reportType*. A tabela a seguir lista as opções disponíveis para *reportMode* e o comportamento resultante de **_CrtDbgReport**. Essas opções são definidas como sinalizadores de bits em Crtdbg.h.

|Modo do relatório|Comportamento de _CrtDbgReport|
|-----------------|-----------------------------|
|**_CRTDBG_MODE_DEBUG**|Grava a mensagem na janela de saída do depurador.|
|**_CRTDBG_MODE_FILE**|Grava a mensagem em um identificador de arquivo fornecido pelo usuário. [_CrtSetReportFile](crtsetreportfile.md) deve ser chamado para definir o arquivo ou o fluxo específico a ser usado como o destino.|
|**_CRTDBG_MODE_WNDW**|Cria uma caixa de mensagem para exibir a mensagem junto com os botões [abortar](abort.md), **repetir**e **ignorar** .|
|**_CRTDBG_REPORT_MODE**|Retorna *reportMode* para o *reportType*especificado:<br /><br /> 1 **_CRTDBG_MODE_FILE**<br /><br /> 2   **_CRTDBG_MODE_DEBUG**<br /><br /> 4   **_CRTDBG_MODE_WNDW**|

Cada tipo de relatório pode ser relatado usando um, dois ou três modos ou nenhum modo. Portanto, é possível ter mais de um destino definido para um único tipo de relatório. Por exemplo, o fragmento de código a seguir faz com que as falhas de asserção sejam enviadas para uma janela de mensagem de depuração e para **stderr**:

```C
_CrtSetReportMode( _CRT_ASSERT, _CRTDBG_MODE_FILE | _CRTDBG_MODE_WNDW );
_CrtSetReportFile( _CRT_ASSERT, _CRTDBG_FILE_STDERR );
```

Além disso, os modos de relatório para cada tipo de relatório podem ser controlados separadamente. Por exemplo, é possível especificar que um *reportType* de **_CRT_WARN** seja enviado a uma cadeia de caracteres de depuração de saída, enquanto **_CRT_ASSERT** ser exibido usando uma janela de mensagem de depuração e enviado para **stderr**, conforme ilustrado anteriormente.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_CrtSetReportMode**|\<crtdbg.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

**DLLs** Depurar versões somente de [recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md) .

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
