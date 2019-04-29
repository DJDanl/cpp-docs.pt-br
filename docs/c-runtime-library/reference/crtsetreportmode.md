---
title: _CrtSetReportMode
ms.date: 11/04/2016
apiname:
- _CrtSetReportMode
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
- _CrtSetReportMode
- CrtSetReportMode
helpviewer_keywords:
- _CrtSetReportMode function
- CrtSetReportMode function
ms.assetid: 3ecc6a12-afdd-4242-b046-8187ff6d4b36
ms.openlocfilehash: 2096d39a8ba316fc76c97517a16e34231940e7f4
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62335289"
---
# <a name="crtsetreportmode"></a>_CrtSetReportMode

Especifica o destino ou destinos de um tipo de relatório específico gerado por **crtdbgreport** e todas as macros que chamam [crtdbgreport, CrtDbgReportW](crtdbgreport-crtdbgreportw.md), como [macros Assert, asserte, Assert_expr](assert-asserte-assert-expr-macros.md), [macros Assert, asserte, assert_expr Macros](assert-asserte-assert-expr-macros.md), [macros rpt, rptf, rptw, Rptfw](rpt-rptf-rptw-rptfw-macros.md), e [macros rpt, rptf, rptw, Rptfw](rpt-rptf-rptw-rptfw-macros.md) (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
int _CrtSetReportMode(
   int reportType,
   int reportMode
);
```

### <a name="parameters"></a>Parâmetros

*reportType*<br/>
Tipo de relatório: **_CRT_WARN**, **crt_error**, e **_CRT_ASSERT**.

*reportMode*<br/>
Novo modo de relatório ou modos *reportType*.

## <a name="return-value"></a>Valor de retorno

Após a conclusão bem-sucedida, **CrtSetReportMode** retorna o modo de relatório anterior ou modos para o tipo de relatório especificado em *reportType*. Se um valor inválido for passado como *reportType* ou um modo inválido é especificado para *reportMode*, **CrtSetReportMode** invocará o manipulador de parâmetro inválido, como descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função definirá **errno** à **EINVAL** e retornará -1. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

**CrtSetReportMode** Especifica o destino de saída para **crtdbgreport**. Como as macros [macros Assert](assert-asserte-assert-expr-macros.md), [asserte](assert-asserte-assert-expr-macros.md), [macros RPT](rpt-rptf-rptw-rptfw-macros.md), e [rptf](rpt-rptf-rptw-rptfw-macros.md) chamar **crtdbgreport**, **CrtSetReportMode** Especifica o destino de saída de texto especificado com essas macros.

Quando [Debug](../../c-runtime-library/debug.md) não está definido, as chamadas a **CrtSetReportMode** são removidas durante o pré-processamento.

Se você não chamar **CrtSetReportMode** para definir o destino de saída das mensagens, em seguida, os seguintes padrões entrarão em vigor:

- Erros e falhas de declaração são direcionados para uma janela de mensagem de depuração.

- Os avisos de aplicativos do Windows são enviados para a janela de saída do depurador.

- Os avisos de aplicativos do console não são exibidos.

A tabela a seguir lista os tipos de relatório definidos em Crtdbg.h.

|Tipo de relatório|Descrição|
|-----------------|-----------------|
|**_CRT_WARN**|Avisos, mensagens e informações que não precisam de atenção imediata.|
|**_CRT_ERROR**|Erros, problemas irrecuperáveis e problemas que exigem atenção imediata.|
|**_CRT_ASSERT**|Falhas de declaração (expressões declaradas que são avaliadas como **falsos**).|

O **CrtSetReportMode** função atribui o novo modo de relatório especificado em *reportMode* para o tipo de relatório especificado na *reportType* e retorna o previamente definido modo de relatório para *reportType*. A tabela a seguir lista as opções disponíveis para o *reportMode* e o comportamento resultante de **crtdbgreport**. Essas opções são definidas como sinalizadores de bits em Crtdbg.h.

|Modo do relatório|Comportamento de _CrtDbgReport|
|-----------------|-----------------------------|
|**_CRTDBG_MODE_DEBUG**|Grava a mensagem na janela de saída do depurador.|
|**_CRTDBG_MODE_FILE**|Grava a mensagem em um identificador de arquivo fornecido pelo usuário. [_CrtSetReportFile](crtsetreportfile.md) deve ser chamado para definir o arquivo ou o fluxo específico a ser usado como o destino.|
|**_CRTDBG_MODE_WNDW**|Cria uma caixa de mensagem para exibir a mensagem junto com o [anular](abort.md), **Repita**, e **ignorar** botões.|
|**_CRTDBG_REPORT_MODE**|Retorna *reportMode* especificado *reportType*:<br /><br /> 1   **_CRTDBG_MODE_FILE**<br /><br /> 2   **_CRTDBG_MODE_DEBUG**<br /><br /> 4   **_CRTDBG_MODE_WNDW**|

Cada tipo de relatório pode ser relatado usando um, dois ou três modos ou nenhum modo. Portanto, é possível ter mais de um destino definido para um único tipo de relatório. Por exemplo, o fragmento de código a seguir causa falhas de declaração a ser enviado para ambos os uma janela de mensagem de depuração e, ao **stderr**:

```C
_CrtSetReportMode( _CRT_ASSERT, _CRTDBG_MODE_FILE | _CRTDBG_MODE_WNDW );
_CrtSetReportFile( _CRT_ASSERT, _CRTDBG_FILE_STDERR );
```

Além disso, os modos de relatório para cada tipo de relatório podem ser controlados separadamente. Por exemplo, é possível especificar que um *reportType* dos **_CRT_WARN** ser enviada para uma cadeia de caracteres de depuração de saída, enquanto **_CRT_ASSERT** ser exibido usando uma janela de mensagem de depuração e enviado para **stderr**, conforme ilustrado anteriormente.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_CrtSetReportMode**|\<crtdbg.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

**Bibliotecas:** Versões de depuração [recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md) apenas.

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
