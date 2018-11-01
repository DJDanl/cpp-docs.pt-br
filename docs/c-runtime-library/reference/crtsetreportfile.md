---
title: _CrtSetReportFile
ms.date: 11/04/2016
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
helpviewer_keywords:
- CrtSetReportFile function
- _CrtSetReportFile function
ms.assetid: 3126537e-511b-44af-9c1c-0605265eabc4
ms.openlocfilehash: 32a560e09c47468daf48c185e23d6e289c6d1d9b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50464240"
---
# <a name="crtsetreportfile"></a>_CrtSetReportFile

Depois de usar [CrtSetReportMode](crtsetreportmode.md) para especificar **_CRTDBG_MODE_FILE**, você pode especificar o identificador de arquivo para receber o texto da mensagem. **Crtsetreportfile** também é usado pelo [crtdbgreport, CrtDbgReportW](crtdbgreport-crtdbgreportw.md) para especificar o destino do texto (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
_HFILE _CrtSetReportFile(
   int reportType,
   _HFILE reportFile
);
```

### <a name="parameters"></a>Parâmetros

*reportType*<br/>
Tipo de relatório: **_CRT_WARN**, **crt_error**, e **_CRT_ASSERT**.

*reportFile*<br/>
Novo arquivo de relatório do *reportType*.

## <a name="return-value"></a>Valor de retorno

Após a conclusão bem-sucedida, **crtsetreportfile** retorna o arquivo de relatório anterior definido para o tipo de relatório especificado em *reportType*. Se um valor inválido for passado *reportType*, essa função invocará o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** é definido como **EINVAL** e a função retornará **_CRTDBG_HFILE_ERROR**. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

**Crtsetreportfile** é usado com o [CrtSetReportMode](crtsetreportmode.md) função para definir o destino ou destinos de um tipo de relatório específico gerado por **crtdbgreport**. Quando **CrtSetReportMode** tiver sido chamado para atribuir a **_CRTDBG_MODE_FILE** modo para um tipo de relatório do reporting **crtsetreportfile** , em seguida, deve ser chamado para Defina o arquivo específico ou o fluxo a ser usado como o destino. Quando [Debug](../../c-runtime-library/debug.md) não está definido, as chamadas a **crtsetreportfile** são removidas durante o pré-processamento.

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

   Grava a mensagem **stderr**, que pode ser redirecionada da seguinte maneira:

   ```C
   freopen( "c:\\log2.txt", "w", stderr);
   _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
   _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);

   _RPT0(_CRT_ERROR,"1st message\n");
   ```

- **_CRTDBG_FILE_STDOUT**

   Grava a mensagem **stdout**, que pode ser redirecionada.

- **_CRTDBG_REPORT_FILE**

   Retorna o modo de relatório atual.

O arquivo de relatório usado por cada tipo de relatório pode ser controlado separadamente. Por exemplo, é possível especificar que um *reportType* dos **crt_error** relatados ao **stderr**, enquanto um *reportType* do **_CRT_ASSERT** relatadas para um fluxo ou um identificador de arquivo definido pelo usuário.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_CrtSetReportFile**|\<crtdbg.h>|\<errno.h>|

Não há suporte para o console em aplicativos da plataforma Universal do Windows (UWP). Os identificadores de fluxo padrão que estão associados com o console **stdin**, **stdout**, e **stderr**, deverá ser redirecionado para funções de tempo de execução C possam ser usados em aplicativos UWP . Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

**Bibliotecas:** somente versões de depuração dos [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
