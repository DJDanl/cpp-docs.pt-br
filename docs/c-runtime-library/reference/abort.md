---
title: abort | Microsoft Docs
ms.custom: 
ms.date: 1/02/2018
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- aborting current process
- abort function
- processes, aborting
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 02e8c81ef539dc2f078a3b120ca673a0ef612779
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="abort"></a>abort

Anula o processo atual e retorna um código de erro.

> [!NOTE]
> Não use esse método para desligar um app Store Microsoft ou Windows UWP (plataforma Universal), exceto em teste ou cenários de depuração. Modos de interface do usuário ou por programação para fechar um aplicativo de repositório não são permitidos de acordo com o [políticas do Microsoft Store](/legal/windows/agreements/store-policies). Para obter mais informações, consulte [ciclo de vida do aplicativo UWP](/windows/uwp/launch-resume/app-lifecycle).

## <a name="syntax"></a>Sintaxe

```c
void abort( void );
```

## <a name="return-value"></a>Valor de retorno

`abort` não retorna o controle para o processo de chamada. Por padrão, ele verifica se há um manipulador de sinal de anulação e gera `SIGABRT` caso haja algum definido. Em seguida, `abort` termina o processo atual e retorna um código de saída ao processo pai.

## <a name="remarks"></a>Comentários

**Seção específica da Microsoft**

Por padrão, quando um aplicativo é compilado com a biblioteca em tempo de execução de depuração, a rotina `abort` exibe uma mensagem de erro antes que `SIGABRT` seja gerado. Para aplicativos de console em execução no modo de console, a mensagem é enviada para `STDERR`. Aplicativos da área de trabalho do Windows e aplicativos de console em execução no modo de janela exibem a mensagem em uma caixa de mensagem. Para suprimir a mensagem, use [set_abort_behavior](../../c-runtime-library/reference/set-abort-behavior.md) para limpar o sinalizador `_WRITE_ABORT_MSG`. A mensagem exibida depende da versão do ambiente de tempo de execução usada. Para aplicativos criados usando as versões mais recentes do Visual C++, a mensagem é semelhante a esta:

> R6010 - Abort () foi chamado

Nas versões anteriores da biblioteca em tempo de execução C, esta mensagem era exibida:

> Este aplicativo solicitou o tempo de execução terminasse de maneira incomum. Entre em contato com a equipe de suporte do aplicativo para obter mais informações.

Quando o programa é compilado no modo de depuração, a caixa de mensagem exibe opções para **Anular**, **Tentar novamente** ou **Ignorar**. Se o usuário escolher **Anular**, o programa será terminado imediatamente e retornará o código de saída 3. Se o usuário escolher **Tentar novamente**, um depurador será invocado para a depuração Just-In-Time, caso esteja disponível. Se o usuário escolher **Ignorar**, `abort` continuará o processamento normal.

Nas compilações de depuração e comerciais, `abort` verifica se um manipulador de sinal de anulação está definido. Se manipulador de sinal não padrão estiver definido, `abort` chamará `raise(SIGABRT)`. Use a função [signal](../../c-runtime-library/reference/signal.md) para associar uma função de manipulador de sinal de anulação ao sinal `SIGABRT`. Você pode executar ações personalizadas – por exemplo, limpar recursos ou informações de log – e terminar o aplicativo com seu próprio código de erro na função de manipulador. Quando nenhum manipulador personalizado de sinal está definido, `abort` não dispara o sinal `SIGABRT`.

Por padrão, em compilações de depuração não de aplicativos de área de trabalho ou console, `abort` , em seguida, invoca o mecanismo do serviço de relatório de erros do Windows (anteriormente conhecido como recuperação de desastres. Watson) para relatar falhas à Microsoft. Esse comportamento pode ser habilitado ou desabilitado chamando `_set_abort_behavior` e configurando ou mascarando o sinalizador `_CALL_REPORTFAULT`. Quando o sinalizador está definido, o Windows exibe uma caixa de mensagem contendo um texto semelhante a "Um problema impediu o programa de funcionar corretamente". O usuário pode escolher invocar um depurador com um botão **Depurar** ou escolher o botão **Fechar programa** para terminar o aplicativo com um código de erro definido pelo sistema operacional.

Se o manipulador de relatório de erros do Windows não for invocado, `abort` chamará [_exit](../../c-runtime-library/reference/exit-exit-exit.md) para terminar o processo com o código de saída 3 e retornará o controle ao processo pai ou ao sistema operacional. `_exit` não libera os buffers de fluxo ou executa o processamento `atexit` / `_onexit`.

Para obter mais informações sobre depuração de CRT, consulte [Técnicas de Depuração CRT](/visualstudio/debugger/crt-debugging-techniques).

**Fim da seção específica da Microsoft**

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`abort`|\<process.h> ou \<stdlib.h>|

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

[Usando abort](../../cpp/using-abort.md)  
[Função abort](../../c-language/abort-function-c.md)  
[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)  
[Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)  
[exit, _Exit, _exit](../../c-runtime-library/reference/exit-exit-exit.md)  
[raise](../../c-runtime-library/reference/raise.md)  
[signal](../../c-runtime-library/reference/signal.md)  
[Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)  
[_DEBUG](../../c-runtime-library/debug.md)  
[_set_abort_behavior](../../c-runtime-library/reference/set-abort-behavior.md)  

