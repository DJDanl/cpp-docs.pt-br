---
title: abort
ms.date: 1/02/2018
apiname:
- abort
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
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- Abort
helpviewer_keywords:
- aborting current process
- abort function
- processes, aborting
ms.openlocfilehash: d8cb190e36a64e8bd8cfcb75bc9a19c2a394fc48
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50532784"
---
# <a name="abort"></a>abort

Anula o processo atual e retorna um código de erro.

> [!NOTE]
> Não use esse método para desligar um aplicativo da Microsoft Store ou aplicativo de plataforma Universal do Windows (UWP), exceto em teste ou cenários de depuração. Maneiras programáticas ou interface do usuário de fechar um aplicativo da Store não são permitidas de acordo com o [políticas do Microsoft Store](/legal/windows/agreements/store-policies). Para obter mais informações, consulte [ciclo de vida do aplicativo UWP](/windows/uwp/launch-resume/app-lifecycle).

## <a name="syntax"></a>Sintaxe

```C
void abort( void );
```

## <a name="return-value"></a>Valor de retorno

**anular** retorna o controle para o processo de chamada. Por padrão, ele verifica se há um manipulador de sinal de anulação e gera `SIGABRT` caso haja algum definido. Em seguida **anular** encerra o processo atual e retorna um código de saída para o processo pai.

## <a name="remarks"></a>Comentários

**Seção específica da Microsoft**

Por padrão, quando um aplicativo é compilado com a biblioteca de tempo de execução de depuração, o **anular** rotina exibe uma mensagem de erro antes de `SIGABRT` é gerado. Para aplicativos de console em execução no modo de console, a mensagem é enviada para `STDERR`. Aplicativos da área de trabalho do Windows e aplicativos de console em execução no modo de janela exibem a mensagem em uma caixa de mensagem. Para suprimir a mensagem, use [set_abort_behavior](set-abort-behavior.md) para limpar o sinalizador `_WRITE_ABORT_MSG`. A mensagem exibida depende da versão do ambiente de tempo de execução usada. Para aplicativos compilados usando as versões mais recentes do Visual C++, a mensagem é semelhante a:

> R6010 - Abort () foi chamado

Nas versões anteriores da biblioteca em tempo de execução C, esta mensagem era exibida:

> Este aplicativo solicitou o tempo de execução terminasse de maneira incomum. Entre em contato com a equipe de suporte do aplicativo para obter mais informações.

Quando o programa é compilado no modo de depuração, a caixa de mensagem exibe opções para **Anular**, **Tentar novamente** ou **Ignorar**. Se o usuário escolher **Anular**, o programa será terminado imediatamente e retornará o código de saída 3. Se o usuário escolher **Tentar novamente**, um depurador será invocado para a depuração Just-In-Time, caso esteja disponível. Se o usuário escolhe **Ignore**, **anular** continuará o processamento normal.

Em compilações de depuração e comerciais **anular** , em seguida, verifica se um manipulador de sinal de anulação está definido. Se um manipulador de sinal não padrão for definido, **anular** chamadas `raise(SIGABRT)`. Use a função [signal](signal.md) para associar uma função de manipulador de sinal de anulação ao sinal `SIGABRT`. Você pode executar ações personalizadas – por exemplo, limpar recursos ou informações de log – e terminar o aplicativo com seu próprio código de erro na função de manipulador. Se nenhum manipulador personalizado de sinal for definido, **anular** não gera o `SIGABRT` sinal.

Por padrão, em compilações sem depuração de aplicativos de área de trabalho ou de console, **anular** , em seguida, invoca o mecanismo do serviço de relatório de erros do Windows (anteriormente conhecido como recuperação de desastres. Watson) para relatar falhas à Microsoft. Esse comportamento pode ser habilitado ou desabilitado chamando `_set_abort_behavior` e configurando ou mascarando o sinalizador `_CALL_REPORTFAULT`. Quando o sinalizador está definido, o Windows exibe uma caixa de mensagem contendo um texto semelhante a "Um problema impediu o programa de funcionar corretamente". O usuário pode escolher invocar um depurador com um botão **Depurar** ou escolher o botão **Fechar programa** para terminar o aplicativo com um código de erro definido pelo sistema operacional.

Se o relatório de manipulador de erros do Windows não é invocado, em seguida **anular** chamadas [exit](exit-exit-exit.md) para finalizar o processo com código de saída 3 e retornará controle para o processo pai ou o sistema operacional. `_exit` não libera os buffers de fluxo ou executa o processamento `atexit` / `_onexit`.

Para obter mais informações sobre depuração de CRT, consulte [Técnicas de Depuração CRT](/visualstudio/debugger/crt-debugging-techniques).

**Fim da seção específica da Microsoft**

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**abort**|\<process.h> ou \<stdlib.h>|

## <a name="example"></a>Exemplo

O seguinte programa tenta abrir um arquivo e é anulado quando a tentativa falha.

```C
// crt_abort.c
// compile with: /TC
// This program demonstrates the use of
// the abort function by attempting to open a file
// and aborts if the attempt fails.

#include  <stdio.h>
#include  <stdlib.h>

int main( void )
{
    FILE    *stream = NULL;
    errno_t err = 0;

    err = fopen_s(&stream, "NOSUCHF.ILE", "r" );
    if ((err != 0) || (stream == NULL))
    {
        perror( "File could not be opened" );
        abort();
    }
    else
    {
        fclose( stream );
    }
}
```

```Output
File could not be opened: No such file or directory
```

## <a name="see-also"></a>Consulte também

[Usando abort](../../cpp/using-abort.md)<br/>
[Função abort](../../c-language/abort-function-c.md)<br/>
[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)<br/>
[exit, _Exit, _exit](exit-exit-exit.md)<br/>
[raise](raise.md)<br/>
[signal](signal.md)<br/>
[Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)<br/>
[_DEBUG](../../c-runtime-library/debug.md)<br/>
[_set_abort_behavior](set-abort-behavior.md)