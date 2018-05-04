---
title: _CrtSetReportFile | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _CrtSetReportFile
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
- CrtSetReportFile
- _CrtSetReportFile
dev_langs:
- C++
helpviewer_keywords:
- CrtSetReportFile function
- _CrtSetReportFile function
ms.assetid: 3126537e-511b-44af-9c1c-0605265eabc4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a3df4f54ad8e191dac7110a914bdde1cec888ff9
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="crtsetreportfile"></a>_CrtSetReportFile

Depois que você usar [CrtSetReportMode](crtsetreportmode.md) para especificar **_CRTDBG_MODE_FILE**, você pode especificar o identificador de arquivo para receber o texto da mensagem. **Crtsetreportfile** também é usado por [crtdbgreport, CrtDbgReportW](crtdbgreport-crtdbgreportw.md) para especificar o destino de texto (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
_HFILE _CrtSetReportFile(
   int reportType,
   _HFILE reportFile
);
```

### <a name="parameters"></a>Parâmetros

*reportType*<br/>
Tipo de relatório: **_CRT_WARN**, **_CRT_ERROR**, e **_CRT_ASSERT**.

*reportFile*<br/>
Novo arquivo de relatório para *reportType*.

## <a name="return-value"></a>Valor de retorno

Após a conclusão bem-sucedida, **crtsetreportfile** retorna o arquivo de relatório anterior definido para o tipo de relatório especificado em *reportType*. Se um valor inválido for passado *reportType*, essa função invoca o manipulador de parâmetro inválido, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, **errno** é definido como **EINVAL** e a função retorna **_CRTDBG_HFILE_ERROR**. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

**Crtsetreportfile** é usado com o [CrtSetReportMode](crtsetreportmode.md) função para definir o destino ou os destinos de um tipo de relatório específico gerados pelo **crtdbgreport**. Quando **CrtSetReportMode** foi chamado para atribuir o **_CRTDBG_MODE_FILE** relatório de modo de um tipo de relatório específico, **crtsetreportfile** deve ser chamado para Defina o arquivo específico ou o fluxo a ser usado como o destino. Quando [Debug](../../c-runtime-library/debug.md) não está definido, chamadas para **crtsetreportfile** são removidos durante o pré-processamento.

A lista a seguir mostra as opções disponíveis para *reportFile* e o comportamento resultante de **crtdbgreport**. Essas opções são definidas como sinalizadores de bits em Crtdbg.h.

- **Identificador de arquivo**

   Um identificador para o arquivo que será o destino das mensagens. Nenhuma tentativa é feita para verificar a validade do identificador. É necessário abrir e fechar o identificador do arquivo. Por exemplo:

   ```C
   HANDLE hLogFile;
   hLogFile = CreateFile("c:\\log.txt", GENERIC_WRITE,
      FILE_SHARE_WRITE, NULL, CREATE_ALWAYS,
      FILE_ATTRIBUTE_NORMAL, NULL);
   _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
   _CrtSetReportFile(_CRT_WARN, hLogFile);

   _RPT0(_CRT_WARN,"file message\n");
   CloseHandle(hLogFile);
   ```

- **_CRTDBG_FILE_STDERR**

   Mensagem de gravações para **stderr**, que pode ser redirecionado da seguinte maneira:

   ```C
   freopen( "c:\\log2.txt", "w", stderr);
   _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
   _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);

   _RPT0(_CRT_ERROR,"1st message\n");
   ```

- **_CRTDBG_FILE_STDOUT**

   Mensagem de gravações para **stdout**, que você pode redirecionar.

- **_CRTDBG_REPORT_FILE**

   Retorna o modo de relatório atual.

O arquivo de relatório usado por cada tipo de relatório pode ser controlado separadamente. Por exemplo, é possível especificar que uma *reportType* de **_CRT_ERROR** relatado para **stderr**, enquanto um *reportType* de **_CRT_ASSERT** relatados para um identificador de arquivo definido pelo usuário ou o fluxo.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_CrtSetReportFile**|\<crtdbg.h>|\<errno.h>|

Não há suporte para o console em aplicativos do Windows UWP (plataforma Universal). Os identificadores de fluxo padrão que estão associados com o console, **stdin**, **stdout**, e **stderr**, deverá ser redirecionado para funções de tempo de execução C podem usá-los em aplicativos UWP . Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

**Bibliotecas:** somente versões de depuração dos [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
