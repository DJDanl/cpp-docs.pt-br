---
title: _CrtDbgReport, _CrtDbgReportW | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b2b0bcdc5ee6c4c2b71837f1cdd958f50d8d0b4a
ms.sourcegitcommit: b92ca0b74f0b00372709e81333885750ba91f90e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/16/2018
ms.locfileid: "42575442"
---
# <a name="crtdbgreport-crtdbgreportw"></a>_CrtDbgReport, _CrtDbgReportW

Gera um relatório com uma mensagem de depuração e envia o relatório para três destinos possíveis (somente versões de depuração).

## <a name="syntax"></a>Sintaxe

```C
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

### <a name="parameters"></a>Parâmetros

*reportType*<br/>
Tipo de relatório: **_CRT_WARN**, **crt_error**, e **_CRT_ASSERT**.

*filename*<br/>
Ponteiro para o nome do arquivo de origem em que a asserção/relatório ocorreu ou **nulo**.

*linenumber*<br/>
Número de linha no arquivo de origem em que a asserção/relatório ocorreu ou **nulo**.

*moduleName*<br/>
Ponteiro para o nome do módulo (.exe ou .dll) em que a asserção/relatório ocorreu.

*format*<br/>
Ponteiro para a cadeia de caracteres formato-controle usada para criar a mensagem do usuário.

*argument*<br/>
Argumentos de substituição opcionais usados pelo *formato*.

## <a name="return-value"></a>Valor de retorno

Para todos os destinos de relatório **crtdbgreport** e **CrtDbgReportW** retornar -1 se ocorrer um erro e 0 se nenhum erro for encontrado. No entanto, quando o destino do relatório é uma janela de mensagem de depuração e o usuário clica no botão **Tentar novamente**, essas funções retornam 1. Se o usuário clicar no botão **Anular** na janela Mensagem de Depuração, essas funções serão anuladas imediatamente e não retornarão um valor.

O [macros rpt, rptf](rpt-rptf-rptw-rptfw-macros.md) chamada de macros de depuração **crtdbgreport** para de depuração de gerar relatórios. As versões de caractere largo dessas macros, bem como [macros Assert, asserte](assert-asserte-assert-expr-macros.md), [rptw](rpt-rptf-rptw-rptfw-macros.md) e [rptfw](rpt-rptf-rptw-rptfw-macros.md), use **CrtDbgReportW** para Gere seus relatórios de depuração. Quando **crtdbgreport** ou **CrtDbgReportW** retornar 1, essas macros iniciam o depurador, desde que a depuração just-in-time (JIT) está habilitada.

## <a name="remarks"></a>Comentários

**Crtdbgreport** e **CrtDbgReportW** pode enviar o relatório de depuração para três destinos diferentes: um arquivo de relatório de depuração, um monitor de depuração (o depurador do Visual Studio) ou uma janela de mensagem de depuração. Duas funções de configuração, [_CrtSetReportMode](crtsetreportmode.md) e [_CrtSetReportFile](crtsetreportfile.md), são usadas para especificar os destinos de cada tipo de relatório. Essas funções permitem o controle independente do destino de cada tipo de relatório. Por exemplo, é possível especificar que um *reportType* dos **_CRT_WARN** só ser enviada para o monitor de depuração, enquanto um *reportType* de **_CRT_ASSERT** enviado para uma janela de mensagem de depuração e um arquivo de relatório definida pelo usuário.

**CrtDbgReportW** é a versão de caractere largo de **crtdbgreport**. Todos os parâmetros de saída e cadeia de caracteres estão em cadeias de caracteres largos. Caso contrário, não há diferença da versão de caractere de byte único.

**Crtdbgreport** e **CrtDbgReportW** criar a mensagem do usuário para o relatório de depuração, substituindo o *argumento*[**n**] argumentos para o *formato* de cadeia de caracteres, usando as mesmas regras definidas pela **printf** ou **wprintf** funções. Essas funções, em seguida, geram o relatório de depuração e determinam o destino ou destinos, com base nos modos de relatório atual e o arquivo definido para *reportType*. Quando o relatório é enviado para uma janela de mensagem de depuração, o *filename*, **lineNumber**, e *moduleName* estão incluídos nas informações exibidas na janela.

A tabela a seguir lista as opções disponíveis para o modo de relatório ou modos de arquivo e o comportamento resultante de **crtdbgreport** e **CrtDbgReportW**. Essas opções são definidas como sinalizadores de bit em \<crtdbg.h>.

|Modo do relatório|Arquivo do relatório|**Crtdbgreport**, **CrtDbgReportW** comportamento|
|-----------------|-----------------|------------------------------------------------|
|**_CRTDBG_MODE_DEBUG**|Não aplicável|Grava mensagens usando a API [OutputDebugString](http://msdn.microsoft.com/library/windows/desktop/aa363362.aspx) do Windows.|
|**_CRTDBG_MODE_WNDW**|Não aplicável|Chama a API [MessageBox](http://msdn.microsoft.com/library/windows/desktop/ms645505) do Windows para criar uma caixa de mensagem e exibir a mensagem junto com os botões **Anular**, **Tentar novamente** e **Ignorar**. Se um usuário clica **anular**, **crtdbgreport** ou **crtdbgreport** será anulado imediatamente. Se um usuário clicar em **Tentar novamente**, ele retornará 1. Se um usuário clica **Ignore**, a execução continua e **crtdbgreport** e **CrtDbgReportW** retornam 0. Observe que clicar em **Ignorar** quando há uma condição de erro geralmente resulta em “comportamento inesperado”.|
|**_CRTDBG_MODE_FILE**|**__HFILE**|Grava a mensagem fornecida pelo usuário **MANIPULAR**, usando o Windows [WriteFile](/windows/desktop/api/fileapi/nf-fileapi-writefile) API e não verifica a validade do identificador de arquivo; o aplicativo é responsável por abrir o arquivo de relatório e passar um arquivo válido identificador.|
|**_CRTDBG_MODE_FILE**|**_CRTDBG_FILE_STDERR**|Grava a mensagem **stderr**.|
|**_CRTDBG_MODE_FILE**|**_CRTDBG_FILE_STDOUT**|Grava a mensagem **stdout**.|

O relatório pode ser enviado para um, dois ou três destinos ou nenhum destino. Para obter mais informações sobre como especificar os modos de relatório e o arquivo de relatório, consulte as funções [_CrtSetReportMode](crtsetreportmode.md) e [_CrtSetReportFile](crtsetreportfile.md). Para obter mais informações sobre como usar as macros de depuração e as funções de relatório, consulte [Macros para relatórios](/visualstudio/debugger/macros-for-reporting).

Se seu aplicativo precisa de mais flexibilidade do que o fornecido pelo **crtdbgreport** e **CrtDbgReportW**, você pode escrever seu próprios relatórios função e conectá-la nos relatórios da biblioteca de tempo de execução de C o mecanismo usando o [crtsetreporthook](crtsetreporthook.md) função.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_CrtDbgReport**|\<crtdbg.h>|
|**_CrtDbgReportW**|\<crtdbg.h>|

**Crtdbgreport** e **CrtDbgReportW** são extensões da Microsoft. Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

```C
// crt_crtdbgreport.c
#include <crtdbg.h>

int main(int argc, char *argv[]) {
#ifdef _DEBUG
   _CrtDbgReport(_CRT_ASSERT, __FILE__, __LINE__, argv[0], NULL);
#endif
}
```

Consulte [crt_dbg2](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/crt/crt_dbg2) para obter um exemplo de como alterar a função de relatório.

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
[_CrtSetReportMode](crtsetreportmode.md)<br/>
[_CrtSetReportFile](crtsetreportfile.md)<br/>
[printf, _printf_l, wprintf, _wprintf_l](printf-printf-l-wprintf-wprintf-l.md)<br/>
[_DEBUG](../../c-runtime-library/debug.md)<br/>
