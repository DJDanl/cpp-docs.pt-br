---
title: signal
ms.date: 04/12/2018
api_name:
- signal
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- signal
helpviewer_keywords:
- signal function
ms.openlocfilehash: 1dacf23b6c4f698b61c5bfe2dd2fb1ff7ee389f5
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87216746"
---
# <a name="signal"></a>signal

Define a manipulação de sinal de interrupção.

> [!IMPORTANT]
> Não use esse método para desligar um aplicativo Microsoft Store, exceto em cenários de teste ou depuração. As maneiras programática ou de interface do usuário de fechar um aplicativo da loja não são permitidas de acordo com as [políticas de Microsoft Store](/legal/windows/agreements/store-policies). Para obter mais informações, consulte [ciclo de vida do aplicativo UWP](/windows/uwp/launch-resume/app-lifecycle).

## <a name="syntax"></a>Sintaxe

```C
void __cdecl *signal(int sig, int (*func)(int, int));
```

### <a name="parameters"></a>parâmetros

*SIG*<br/>
Valor de sinal.

*func*<br/>
O segundo parâmetro é um ponteiro para a função a ser executada. O primeiro parâmetro é um valor de sinal e o segundo parâmetro é um subcódigo que pode ser usado quando o primeiro parâmetro é SIGFPE.

## <a name="return-value"></a>Valor retornado

**Signal** retorna o valor anterior de Func que está associado ao sinal fornecido. Por exemplo, se o valor anterior de *Func* fosse **SIG_IGN**, o valor de retorno também será **SIG_IGN**. Um valor de retorno de **SIG_ERR** indica um erro; Nesse caso, **errno** é definido como **EINVAL**.

Para obter mais informações sobre esses códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **Signal** permite que um processo escolha uma das várias maneiras de lidar com um sinal de interrupção do sistema operacional. O argumento *SIG* é a interrupção para a qual o **sinal** responde; Ele deve ser uma das constantes de manifesto a seguir, que são definidas no sinal. T.

|valor *SIG*|Descrição|
|-----------------|-----------------|
|**SIGABRT**|Encerramento anormal|
|**SIGFPE**|Erro de ponto flutuante|
|**SIGILL**|Instrução ilegal|
|**SIGINT**|Sinal de CTRL+C|
|**SIGSEGV**|Acesso ao armazenamento inválido|
|**SIGTERM**|Solicitação de encerramento|

Se *SIG* não for um dos valores acima, o manipulador de parâmetro inválido será invocado, conforme definido na [validação de parâmetro](../../c-runtime-library/parameter-validation.md) . Se a execução tiver permissão para continuar, essa função definirá **errno** como **EINVAL** e retornará **SIG_ERR**.

Por padrão, o **sinal** encerra o programa de chamada com o código de saída 3, independentemente do valor de *SIG*.

> [!NOTE]
> **SIGINT** não tem suporte para nenhum aplicativo Win32. Quando ocorre uma interrupção CTRL+C, sistemas operacionais Win32 geram um novo thread para manipular especificamente essa interrupção. Isso pode fazer com que um aplicativo de thread único, tal como um no UNIX, torne-se multithread e cause um comportamento inesperado.

O argumento *Func* é um endereço para um manipulador de sinais que você escreve, ou para uma das constantes predefinidas **SIG_DFL** ou **SIG_IGN**, que também são definidas no sinal. T. Se *Func* for uma função, ele será instalado como o manipulador de sinais para o sinal fornecido. O protótipo do manipulador de sinais requer um argumento formal, *SIG*, do tipo **`int`** . O sistema operacional fornece o argumento real por meio de *SIG* quando ocorre uma interrupção; o argumento é o sinal que gerou a interrupção. Portanto, você pode usar as seis constantes de manifesto (listadas na tabela anterior) no seu manipulador de sinal para determinar qual interrupção ocorreu e tomar ações adequadas. Por exemplo, você pode chamar **Signal** duas vezes para atribuir o mesmo manipulador a dois sinais diferentes e, em seguida, testar o argumento *SIG* no manipulador para executar ações diferentes com base no sinal recebido.

Se você estiver testando as exceções de ponto flutuante (**SIGFPE**), *Func* apontará para uma função que usa um segundo argumento opcional que é uma das várias constantes de manifesto, definidas em float. H, do formulário **FPE_xxx**. Quando ocorre um sinal **SIGFPE** , você pode testar o valor do segundo argumento para determinar o tipo de exceção de ponto flutuante e, em seguida, executar a ação apropriada. Esse argumento e seus possíveis valores são extensões da Microsoft.

Para exceções de ponto flutuante, o valor de *Func* não é redefinido quando o sinal é recebido. Para recuperar-se de exceções de ponto flutuante, use cláusulas try/except ao redor de operações de ponto flutuante. Também é possível recuperar-se usando [setjmp](setjmp.md) com [longjmp](longjmp.md). Em ambos os casos, o processo de chamada continua a execução e deixa o estado de ponto flutuante do processo indefinido.

Se o manipulador de sinal retorna, a execução do processo de chamada é retomada imediatamente após o ponto em que ele recebeu o sinal de interrupção. Isso é verdadeiro independentemente do tipo de sinal ou modo de operação.

Antes que a função especificada seja executada, o valor de *Func* é definido como **SIG_DFL**. O próximo sinal de interrupção é tratado como descrito para **SIG_DFL**, a menos que uma chamada intermediária para **Signal** especifique o contrário. Você pode usar esse recurso para redefinir os sinais na função chamada.

Já que rotinas de manipulador de sinal são geralmente chamadas de forma assíncrona quando ocorre uma interrupção, a função de manipulador de sinal pode obter controle quando uma operação em tempo de execução está incompleta e está em um estado desconhecido. A lista a seguir resume as restrições que determinam quais funções você pode usar em sua rotina de manipulador de sinal.

- Não emita o nível baixo ou STDIO. Rotinas de e/s do H (por exemplo, **printf** ou **fread**).

- Não chame rotinas de heap ou qualquer rotina que use as rotinas de heap (por exemplo, **malloc**, **_strdup**ou **_putenv**). Consulte [malloc](malloc.md) para obter mais informações.

- Não use nenhuma função que gere uma chamada do sistema (por exemplo, **_getcwd** ou **hora**).

- Não use **longjmp** a menos que a interrupção seja causada por uma exceção de ponto flutuante (ou seja, *SIG* é **SIGFPE**). Nesse caso, primeiro reinicialize o pacote de ponto flutuante usando uma chamada para **_fpreset**.

- Não use nenhuma rotina de sobreposição.

Um programa deve conter código de ponto flutuante se for interceptar a exceção **SIGFPE** usando a função. Se o seu programa não tem código de ponto flutuante e requer o código de manipulação de sinal da biblioteca em tempo de execução, basta declarar um volatile double e inicializá-lo a zero:

```C
volatile double d = 0.0f;
```

Os sinais **SIGILL** e **SIGTERM** não são gerados no Windows. Eles são incluídos para compatibilidade ANSI. Portanto, você pode definir manipuladores de sinais para esses sinais usando **Signal**e também pode gerar esses sinais explicitamente chamando [Raise](raise.md).

As configurações de sinal não são preservadas em processos gerados que são criados por chamadas para [_exec](../../c-runtime-library/exec-wexec-functions.md) ou [_spawn](../../c-runtime-library/spawn-wspawn-functions.md) funções. As configurações de sinal são redefinidas para os valores padrão no novo processo.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**signal**|\<signal.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como usar o **sinal** para adicionar um comportamento personalizado ao sinal **SIGABRT** . Para obter informações adicionais sobre o comportamento de anulação, consulte [_set_abort_behavior](set-abort-behavior.md).

```C
// crt_signal.c
// compile with: /EHsc /W4
// Use signal to attach a signal handler to the abort routine
#include <stdlib.h>
#include <signal.h>

void SignalHandler(int signal)
{
    if (signal == SIGABRT) {
        // abort signal handler code
    } else {
        // ...
    }
}

int main()
{
    typedef void (*SignalHandlerPointer)(int);

    SignalHandlerPointer previousHandler;
    previousHandler = signal(SIGABRT, SignalHandler);

    abort();
}
```

A saída depende da versão do tempo de execução usada, se o aplicativo é um console ou um aplicativo do Windows e as configurações do registro do Windows. Para um aplicativo de console, algo semelhante à mensagem a seguir pode ser enviado para stderr:

```Output
Debug Error!

Program: c:\Projects\crt_signal\Debug\crt_signal.exe

R6010

- abort() has been called
```

## <a name="see-also"></a>Confira também

[Controle de processo e ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[abort](abort.md)<br/>
[_exec, _wexec funções](../../c-runtime-library/exec-wexec-functions.md)<br/>
[exit, _Exit, _exit](exit-exit-exit.md)<br/>
[_fpreset](fpreset.md)<br/>
[_spawn, _wspawn funções](../../c-runtime-library/spawn-wspawn-functions.md)<br/>
