---
title: abort
ms.date: 4/2/2020
api_name:
- abort
- _o_abort
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
- api-ms-win-crt-runtime-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- Abort
helpviewer_keywords:
- aborting current process
- abort function
- processes, aborting
ms.openlocfilehash: 1f70f54783ce6f6d28fdda028af4fd5a205aeb0b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81350926"
---
# <a name="abort"></a>abort

Anula o processo atual e retorna um código de erro.

> [!NOTE]
> Não use esse método para desligar um aplicativo da Microsoft Store ou aplicativo Universal Windows Platform (UWP), exceto em cenários de teste ou depuração. Formas programáticas ou de uI para fechar um aplicativo da Loja não são permitidas de acordo com as políticas da [Microsoft Store](/legal/windows/agreements/store-policies). Para obter mais informações, consulte [o ciclo de vida do aplicativo UWP](/windows/uwp/launch-resume/app-lifecycle).

## <a name="syntax"></a>Sintaxe

```C
void abort( void );
```

## <a name="return-value"></a>Valor retornado

**abortar** não retorna o controle ao processo de chamada. Por padrão, ele verifica se há um manipulador de sinal de anulação e gera `SIGABRT` caso haja algum definido. Em **seguida, o aborta** termina o processo atual e retorna um código de saída para o processo pai.

## <a name="remarks"></a>Comentários

**Específico da Microsoft**

Por padrão, quando um aplicativo é construído com a biblioteca de tempo `SIGABRT` de execução de depuração, a rotina **de abortar** exibe uma mensagem de erro antes de ser levantada. Para aplicativos de console em execução no modo de console, a mensagem é enviada para `STDERR`. Aplicativos da área de trabalho do Windows e aplicativos de console em execução no modo de janela exibem a mensagem em uma caixa de mensagem. Para suprimir a mensagem, use [set_abort_behavior](set-abort-behavior.md) para limpar o sinalizador `_WRITE_ABORT_MSG`. A mensagem exibida depende da versão do ambiente de runtime usada. Para aplicativos construídos usando as versões mais recentes do Visual C++, a mensagem se assemelha a isso:

> R6010 - abort() foi chamado

Nas versões anteriores da biblioteca de runtime C, esta mensagem era exibida:

> Este aplicativo solicitou ao Runtime para terminá-lo de uma maneira incomum. Entre em contato com a equipe de suporte do aplicativo para obter mais informações.

Quando o programa é compilado no modo de depuração, a caixa de mensagem exibe opções para **Anular**, **Tentar novamente** ou **Ignorar**. Se o usuário escolher **Anular**, o programa será terminado imediatamente e retornará o código de saída 3. Se o usuário escolher **Tentar novamente**, um depurador será invocado para a depuração Just-In-Time, caso esteja disponível. Se o usuário escolher **Ignorar,** **abortar** continuará o processamento normal.

Em construções de varejo e depuração, **aborte** e verifique se um manipulador de sinal abortado está definido. Se um manipulador de sinal não `raise(SIGABRT)`padrão estiver definido, **aborte** chamadas . Use a função [signal](signal.md) para associar uma função de manipulador de sinal de anulação ao sinal `SIGABRT`. Você pode executar ações personalizadas – por exemplo, limpar recursos ou informações de log – e terminar o aplicativo com seu próprio código de erro na função de manipulador. Se nenhum manipulador de sinal personalizado for `SIGABRT` definido, **abortar** não aumentará o sinal.

Por padrão, em compilações não depuradas de aplicativos de desktop ou console, **aborte** e, em seguida, invoca o mecanismo do Serviço de Relatório de Erros do Windows (anteriormente conhecido como Dr. Watson) para relatar falhas à Microsoft. Esse comportamento pode ser habilitado ou desabilitado chamando `_set_abort_behavior` e configurando ou mascarando o sinalizador `_CALL_REPORTFAULT`. Quando o sinalizador está definido, o Windows exibe uma caixa de mensagem contendo um texto semelhante a "Um problema impediu o programa de funcionar corretamente". O usuário pode escolher invocar um depurador com um botão **Depurar** ou escolher o botão **Fechar programa** para terminar o aplicativo com um código de erro definido pelo sistema operacional.

Se o manipulador de relatórios de erros do Windows não for invocado, **então aborte** chamadas [_exit](exit-exit-exit.md) para encerrar o processo com o código de saída 3 e retornar o controle para o processo pai ou o sistema operacional. `_exit` não libera os buffers de fluxo ou executa o processamento `atexit`/`_onexit`.

Para obter mais informações sobre depuração de CRT, consulte [Técnicas de Depuração CRT](/visualstudio/debugger/crt-debugging-techniques).

**Fim da seção específica da Microsoft**

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**Abortar**|\<process.h> ou \<stdlib.h>|

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

## <a name="see-also"></a>Confira também

[Usando abort](../../cpp/using-abort.md)<br/>
[função de abortar](../../c-language/abort-function-c.md)<br/>
[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)<br/>
[exit, _Exit, _exit](exit-exit-exit.md)<br/>
[raise](raise.md)<br/>
[Sinal](signal.md)<br/>
[Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)<br/>
[_DEBUG](../../c-runtime-library/debug.md)<br/>
[_set_abort_behavior](set-abort-behavior.md)
