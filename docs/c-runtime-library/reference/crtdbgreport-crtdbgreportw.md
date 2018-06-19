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
ms.openlocfilehash: 57290d2985036ea3df2863e175d742c819a3fe03
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32405047"
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
Tipo de relatório: **_CRT_WARN**, **_CRT_ERROR**, e **_CRT_ASSERT**.

*filename*<br/>
Ponteiro para o nome do arquivo de origem em que ocorreu a assert/relatório ou **nulo**.

*linenumber*<br/>
Número no arquivo de origem em que ocorreu a assert/relatório de linha ou **nulo**.

*moduleName*<br/>
Ponteiro para o nome do módulo (.exe ou .dll) em que a asserção/relatório ocorreu.

*format*<br/>
Ponteiro para a cadeia de caracteres formato-controle usada para criar a mensagem do usuário.

*argument*<br/>
Argumentos de substituição opcional usados por *formato*.

## <a name="return-value"></a>Valor de retorno

Para todos os destinos de relatório, **crtdbgreport** e **CrtDbgReportW** retornar -1 se ocorrer um erro e 0 se nenhum erro for encontrado. No entanto, quando o destino do relatório é uma janela de mensagem de depuração e o usuário clica no botão **Tentar novamente**, essas funções retornam 1. Se o usuário clicar no botão **Anular** na janela Mensagem de Depuração, essas funções serão anuladas imediatamente e não retornarão um valor.

O [rpt, rptf](rpt-rptf-rptw-rptfw-macros.md) depurar macros chamada **crtdbgreport** para gerar seu depuração relatórios. As versões de caractere largo dessas macros, bem como [Assert, asserte](assert-asserte-assert-expr-macros.md), [rptw](rpt-rptf-rptw-rptfw-macros.md) e [rptfw](rpt-rptf-rptw-rptfw-macros.md), use **CrtDbgReportW** para Gere relatórios de depuração. Quando **crtdbgreport** ou **CrtDbgReportW** retornar 1, essas macros para iniciar o depurador, desde que a depuração just-in-time (JIT) está habilitada.

## <a name="remarks"></a>Comentários

**Crtdbgreport** e **CrtDbgReportW** pode enviar o relatório de depuração a três destinos diferentes: um arquivo de relatório de depuração, um monitor de depuração (o depurador do Visual Studio) ou uma janela de mensagem de depuração. Duas funções de configuração, [_CrtSetReportMode](crtsetreportmode.md) e [_CrtSetReportFile](crtsetreportfile.md), são usadas para especificar os destinos de cada tipo de relatório. Essas funções permitem o controle independente do destino de cada tipo de relatório. Por exemplo, é possível especificar que uma *reportType* de **_CRT_WARN** apenas ser enviada para o monitor de depuração, enquanto um *reportType* de **_CRT_ASSERT** ser enviados a uma janela de mensagem de depuração e um arquivo de relatório definidos pelo usuário.

**CrtDbgReportW** é a versão de caractere largo de **crtdbgreport**. Todos os parâmetros de saída e cadeia de caracteres estão em cadeias de caracteres largos. Caso contrário, não há diferença da versão de caractere de byte único.

**Crtdbgreport** e **CrtDbgReportW** crie a mensagem do usuário para o relatório de depuração, substituindo o *argumento*[**n**] argumentos para o *formato* de cadeia de caracteres, usando as mesmas regras definidas pelo **printf** ou **and wprintf** funções. Essas funções, em seguida, geram o relatório de depuração e determinam o destino ou os destinos, com base nos modos de relatório atual e o arquivo definido para *reportType*. Quando o relatório é enviado para uma janela de mensagem de depuração, o *filename*, **lineNumber**, e *moduleName* são incluídas nas informações exibidas na janela.

A tabela a seguir lista as opções disponíveis para o modo de relatório ou modos de arquivo e o comportamento resultante de **crtdbgreport** e **CrtDbgReportW**. Essas opções são definidas como sinalizadores de bit em \<crtdbg.h>.

|Modo do relatório|Arquivo do relatório|**Crtdbgreport**, **CrtDbgReportW** comportamento|
|-----------------|-----------------|------------------------------------------------|
|**_CRTDBG_MODE_DEBUG**|Não aplicável|Grava mensagens usando a API [OutputDebugString](http://msdn.microsoft.com/library/windows/desktop/aa363362.aspx) do Windows.|
|**_CRTDBG_MODE_WNDW**|Não aplicável|Chama a API [MessageBox](http://msdn.microsoft.com/library/windows/desktop/ms645505) do Windows para criar uma caixa de mensagem e exibir a mensagem junto com os botões **Anular**, **Tentar novamente** e **Ignorar**. Se um usuário clicar **anular**, **crtdbgreport** ou **crtdbgreport** anula imediatamente. Se um usuário clicar em **Tentar novamente**, ele retornará 1. Se um usuário clicar **ignorar**, a execução continua e **crtdbgreport** e **CrtDbgReportW** retornam 0. Observe que clicar em **Ignorar** quando há uma condição de erro geralmente resulta em “comportamento inesperado”.|
|**_CRTDBG_MODE_FILE**|**__HFILE**|Grava mensagem fornecida pelo usuário **tratar**, usando o Windows [WriteFile](http://msdn.microsoft.com/library/windows/desktop/aa365747.aspx) API e não não verificar a validade de identificador de arquivo; o aplicativo é responsável para abertura do arquivo de relatório e passando um arquivo válido identificador.|
|**_CRTDBG_MODE_FILE**|**_CRTDBG_FILE_STDERR**|Mensagem de gravações para **stderr**.|
|**_CRTDBG_MODE_FILE**|**_CRTDBG_FILE_STDOUT**|Mensagem de gravações para **stdout**.|

O relatório pode ser enviado para um, dois ou três destinos ou nenhum destino. Para obter mais informações sobre como especificar os modos de relatório e o arquivo de relatório, consulte as funções [_CrtSetReportMode](crtsetreportmode.md) e [_CrtSetReportFile](crtsetreportfile.md). Para obter mais informações sobre como usar as macros de depuração e as funções de relatório, consulte [Macros para relatórios](/visualstudio/debugger/macros-for-reporting).

Se seu aplicativo precisa de mais flexibilidade do que o fornecido por **crtdbgreport** e **CrtDbgReportW**, você pode escrever seu próprios relatórios função e vinculá-lo nos relatórios de biblioteca de tempo de execução C o mecanismo usando o [crtsetreporthook](crtsetreporthook.md) função.

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
