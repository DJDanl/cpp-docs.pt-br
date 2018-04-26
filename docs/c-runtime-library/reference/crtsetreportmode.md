---
title: _CrtSetReportMode | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- _CrtSetReportMode function
- CrtSetReportMode function
ms.assetid: 3ecc6a12-afdd-4242-b046-8187ff6d4b36
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: cc0ca207b903c773ff3afa1d0014b587240862bf
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="crtsetreportmode"></a>_CrtSetReportMode

Especifica o destino ou destinos de um tipo de relatório específico gerados pelo **crtdbgreport** e todas as macros que chamam [crtdbgreport, CrtDbgReportW](crtdbgreport-crtdbgreportw.md), como [Assert, asserte, Macros _ASSERT_EXPR](assert-asserte-assert-expr-macros.md), [Assert, asserte, Macros _ASSERT_EXPR](assert-asserte-assert-expr-macros.md), [rpt, rptf, rptw, rptfw Macros](rpt-rptf-rptw-rptfw-macros.md), e [rpt, rptf, rptw, rptfw Macros](rpt-rptf-rptw-rptfw-macros.md) (somente para a versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
int _CrtSetReportMode(
   int reportType,
   int reportMode
);
```

### <a name="parameters"></a>Parâmetros

*reportType*<br/>
Tipo de relatório: **_CRT_WARN**, **_CRT_ERROR**, e **_CRT_ASSERT**.

*reportMode*<br/>
Novo modo de relatório ou modos de *reportType*.

## <a name="return-value"></a>Valor de retorno

Após a conclusão bem-sucedida, **CrtSetReportMode** retorna o modo de relatório anterior ou modos para o tipo de relatório especificado no *reportType*. Se um valor inválido for passado como *reportType* ou um modo inválido especificado para *reportMode*, **CrtSetReportMode** invoca o manipulador de parâmetro inválido como descrito na [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, esta função define **errno** para **EINVAL** e retorna -1. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

**CrtSetReportMode** Especifica o destino de saída para **crtdbgreport**. Porque as macros [Assert](assert-asserte-assert-expr-macros.md), [asserte](assert-asserte-assert-expr-macros.md), [RPT](rpt-rptf-rptw-rptfw-macros.md), e [rptf](rpt-rptf-rptw-rptfw-macros.md) chamar **crtdbgreport**, **CrtSetReportMode** Especifica o destino da saída de texto especificado com as macros.

Quando [Debug](../../c-runtime-library/debug.md) não está definido, chamadas para **CrtSetReportMode** são removidos durante o pré-processamento.

Se você não chama **CrtSetReportMode** para definir o destino de saída de mensagens, em seguida, os seguintes padrões estão em vigor:

- Erros e falhas de declaração são direcionados para uma janela de mensagem de depuração.

- Os avisos de aplicativos do Windows são enviados para a janela de saída do depurador.

- Os avisos de aplicativos do console não são exibidos.

A tabela a seguir lista os tipos de relatório definidos em Crtdbg.h.

|Tipo de relatório|Descrição|
|-----------------|-----------------|
|**_CRT_WARN**|Avisos, mensagens e informações que não precisam de atenção imediata.|
|**_CRT_ERROR**|Erros, problemas irrecuperáveis e problemas que exigem atenção imediata.|
|**_CRT_ASSERT**|Falhas na asserção (declarada expressões que avaliam **FALSE**).|

O **CrtSetReportMode** função atribui o novo modo de relatório especificado na *reportMode* para o tipo de relatório especificado na *reportType* e retorna o previamente definido modo de relatório para *reportType*. A tabela a seguir lista as opções disponíveis para *reportMode* e o comportamento resultante de **crtdbgreport**. Essas opções são definidas como sinalizadores de bits em Crtdbg.h.

|Modo do relatório|Comportamento de _CrtDbgReport|
|-----------------|-----------------------------|
|**_CRTDBG_MODE_DEBUG**|Grava a mensagem na janela de saída do depurador.|
|**_CRTDBG_MODE_FILE**|Grava a mensagem em um identificador de arquivo fornecido pelo usuário. [_CrtSetReportFile](crtsetreportfile.md) deve ser chamado para definir o arquivo ou o fluxo específico a ser usado como o destino.|
|**_CRTDBG_MODE_WNDW**|Cria uma caixa de mensagem para exibir a mensagem junto com o [anular](abort.md), **novamente**, e **ignorar** botões.|
|**_CRTDBG_REPORT_MODE**|Retorna *reportMode* especificado *reportType*:<br /><br /> 1 **_CRTDBG_MODE_FILE**<br /><br /> 2 **_CRTDBG_MODE_DEBUG**<br /><br /> 4 **_CRTDBG_MODE_WNDW**|

Cada tipo de relatório pode ser relatado usando um, dois ou três modos ou nenhum modo. Portanto, é possível ter mais de um destino definido para um único tipo de relatório. Por exemplo, o fragmento de código a seguir causa falhas na asserção para serem enviadas para os dois uma janela de mensagem de depuração e **stderr**:

```C
_CrtSetReportMode( _CRT_ASSERT, _CRTDBG_MODE_FILE | _CRTDBG_MODE_WNDW );
_CrtSetReportFile( _CRT_ASSERT, _CRTDBG_FILE_STDERR );
```

Além disso, os modos de relatório para cada tipo de relatório podem ser controlados separadamente. Por exemplo, é possível especificar que uma *reportType* de **_CRT_WARN** ser enviado para uma cadeia de caracteres de depuração de saída, enquanto **_CRT_ASSERT** ser exibido usando uma janela de mensagem de depuração e enviado para **stderr**, ilustrado anteriormente.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_CrtSetReportMode**|\<crtdbg.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

**Bibliotecas:** somente versões de depuração dos [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
