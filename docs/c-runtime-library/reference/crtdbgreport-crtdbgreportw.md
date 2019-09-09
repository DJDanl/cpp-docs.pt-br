---
title: _CrtDbgReport, _CrtDbgReportW
ms.date: 11/04/2016
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
helpviewer_keywords:
- debug reporting
- _CrtDbgReport function
- CrtDbgReport function
- CrtDbgReportW function
- _CrtDbgReportW function
ms.assetid: 6e581fb6-f7fb-4716-9432-f0145d639ecc
ms.openlocfilehash: b5579a8996950c5f3e923f67ed2a5e667bb566fa
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69500008"
---
# <a name="_crtdbgreport-_crtdbgreportw"></a>_CrtDbgReport, _CrtDbgReportW

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
Tipo de relatório: **_CRT_WARN**, **_CRT_ERROR**e **_CRT_ASSERT**.

*filename*<br/>
Ponteiro para o nome do arquivo de origem em que a declaração/relatório ocorreu ou é **nulo**.

*linenumber*<br/>
Número de linha no arquivo de origem em que a declaração/relatório ocorreu ou **nulo**.

*moduleName*<br/>
Ponteiro para o nome do módulo (.exe ou .dll) em que a asserção/relatório ocorreu.

*format*<br/>
Ponteiro para a cadeia de caracteres formato-controle usada para criar a mensagem do usuário.

*argument*<br/>
Argumentos de substituição opcionais usados pelo *formato*.

## <a name="return-value"></a>Valor de retorno

Para todos os destinos de relatório, **_CrtDbgReport** e _ **CrtDbgReportW** retornam-1 se ocorrer um erro e 0 se não forem encontrados erros. No entanto, quando o destino do relatório é uma janela de mensagem de depuração e o usuário clica no botão **Tentar novamente**, essas funções retornam 1. Se o usuário clicar no botão **Anular** na janela Mensagem de Depuração, essas funções serão anuladas imediatamente e não retornarão um valor.

As macros de depuração [_RPT, _RPTF](rpt-rptf-rptw-rptfw-macros.md) chamam **_CrtDbgReport** para gerar seus relatórios de depuração. As versões de caractere largo dessas macros, bem como [_ASSERT, _ASSERTE](assert-asserte-assert-expr-macros.md), [_RPTW](rpt-rptf-rptw-rptfw-macros.md) e [_RPTFW](rpt-rptf-rptw-rptfw-macros.md), usam _ **CrtDbgReportW** para gerar seus relatórios de depuração. Quando **_CrtDbgReport** ou _ _ **CrtDbgReportW** retorna 1, essas macros iniciam o depurador, desde que a depuração JIT (just-in-time) esteja habilitada.

## <a name="remarks"></a>Comentários

**_CrtDbgReport** e _ _ **CrtDbgReportW** podem enviar o relatório de depuração para três destinos diferentes: um arquivo de relatório de depuração, um monitor de depuração (o depurador do Visual Studio) ou uma janela de mensagem de depuração. Duas funções de configuração, [_CrtSetReportMode](crtsetreportmode.md) e [_CrtSetReportFile](crtsetreportfile.md), são usadas para especificar os destinos de cada tipo de relatório. Essas funções permitem o controle independente do destino de cada tipo de relatório. Por exemplo, é possível especificar que um *reportType* de **_CRT_WARN** seja enviado somente para o monitor de depuração, enquanto um *reportType* de **_CRT_ASSERT** ser enviado a uma janela de mensagem de depuração e um arquivo de relatório definido pelo usuário.

_ **CrtDbgReportW** é a versão de caractere largo do **_CrtDbgReport**. Todos os parâmetros de saída e cadeia de caracteres estão em cadeias de caracteres largos. Caso contrário, não há diferença da versão de caractere de byte único.

**_CrtDbgReport** e _ _ **CrtDbgReportW** criam a mensagem de usuário para o relatório de depuração, substituindo os argumentos *Argument*[**n**] na cadeia de caracteres de *formato* , usando as mesmas regras definidas pela **printf** ou  **funções wprintf** . Essas funções geram o relatório de depuração e determinam o destino ou destinos, com base nos modos de relatório atuais e no arquivo definido para *reportType*. Quando o relatório é enviado a uma janela de mensagem de depuração, o *nome de arquivo*, **LineNumber**e *ModuleName* são incluídos nas informações exibidas na janela.

A tabela a seguir lista as opções disponíveis para o modo de relatório ou os modos e o arquivo e o comportamento resultante de **_CrtDbgReport** e _ **CrtDbgReportW**. Essas opções são definidas como sinalizadores de bit em \<crtdbg.h>.

|Modo do relatório|Arquivo do relatório|**_CrtDbgReport**, comportamento _ _ **CrtDbgReportW**|
|-----------------|-----------------|------------------------------------------------|
|**_CRTDBG_MODE_DEBUG**|Não aplicável|Grava mensagens usando a API [OutputDebugString](/windows/win32/api/debugapi/nf-debugapi-outputdebugstringw) do Windows.|
|**_CRTDBG_MODE_WNDW**|Não aplicável|Chama a API [MessageBox](/windows/win32/api/winuser/nf-winuser-messagebox) do Windows para criar uma caixa de mensagem e exibir a mensagem junto com os botões **Anular**, **Tentar novamente** e **Ignorar**. Se um usuário clicar em **abortar**, **_CrtDbgReport** ou **_CrtDbgReport** imediatamente abortará. Se um usuário clicar em **Tentar novamente**, ele retornará 1. Se um usuário clicar em **ignorar**, a execução continuará e **_CrtDbgReport** e _ **CrtDbgReportW** retornará 0. Observe que clicar em **Ignorar** quando há uma condição de erro geralmente resulta em “comportamento inesperado”.|
|**_CRTDBG_MODE_FILE**|**__HFILE**|Grava a mensagem no **identificador**fornecido pelo usuário, usando a API [WriteFile](/windows/win32/api/fileapi/nf-fileapi-writefile) do Windows e não verifica a validade do identificador de arquivo; o aplicativo é responsável por abrir o arquivo de relatório e passar um identificador de arquivo válido.|
|**_CRTDBG_MODE_FILE**|**_CRTDBG_FILE_STDERR**|Grava a mensagem em **stderr**.|
|**_CRTDBG_MODE_FILE**|**_CRTDBG_FILE_STDOUT**|Grava a mensagem em **stdout**.|

O relatório pode ser enviado para um, dois ou três destinos ou nenhum destino. Para obter mais informações sobre como especificar os modos de relatório e o arquivo de relatório, consulte as funções [_CrtSetReportMode](crtsetreportmode.md) e [_CrtSetReportFile](crtsetreportfile.md). Para obter mais informações sobre como usar as macros de depuração e as funções de relatório, consulte [Macros para relatórios](/visualstudio/debugger/macros-for-reporting).

Se seu aplicativo precisar de mais flexibilidade do que o fornecido pelo **_CrtDbgReport** e _ _ **CrtDbgReportW**, você poderá escrever sua própria função de relatório e conectá-la ao mecanismo de relatório da biblioteca de tempo de execução do C usando o [_CrtSetReportHook](crtsetreporthook.md) funcionamento.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_CrtDbgReport**|\<crtdbg.h>|
|**_CrtDbgReportW**|\<crtdbg.h>|

**_CrtDbgReport** e _ **CrtDbgReportW** são extensões da Microsoft. Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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
