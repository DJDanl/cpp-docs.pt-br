---
title: signal | Microsoft Docs
ms.custom: ''
ms.date: 04/12/2018
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- signal
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
- signal
dev_langs:
- C++
helpviewer_keywords:
- signal function
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a87978ec3b0840be6ab1779af86765208c80832c
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32416814"
---
# <a name="signal"></a>signal

Define a manipulação de sinal de interrupção.

> [!IMPORTANT]
> Não use esse método para desligar um aplicativo da Microsoft Store, exceto em teste ou cenários de depuração. Modos de interface do usuário ou por programação para fechar um aplicativo de repositório não são permitidos de acordo com o [políticas do Microsoft Store](http://go.microsoft.com/fwlink/?LinkId=865936). Para obter mais informações, consulte [ciclo de vida do aplicativo UWP](http://go.microsoft.com/fwlink/p/?LinkId=865934).

## <a name="syntax"></a>Sintaxe

```C
void __cdecl *signal(int sig, int (*func)(int, int));
```

### <a name="parameters"></a>Parâmetros

*sig*<br/>
Valor de sinal.

*func*<br/>
O segundo parâmetro é um ponteiro para a função a ser executada. O primeiro parâmetro é um valor de sinal e o segundo parâmetro é um subcódigo que pode ser usado quando o primeiro parâmetro é SIGFPE.

## <a name="return-value"></a>Valor de retorno

**sinal** retorna o valor anterior da função associada com o sinal de determinado. Por exemplo, se o valor anterior da *func* foi **SIG_IGN**, o valor de retorno também será **SIG_IGN**. Um valor de retorno **SIG_ERR** indica um erro; nesse caso, **errno** é definido como **EINVAL**.

Para obter mais informações sobre esses códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **sinal** função permite que um processo de escolher uma das várias maneiras para lidar com um sinal de interrupção do sistema operacional. O *sig* argumento é a interrupção para o qual **sinal** responde; ele deve ser um dos seguintes manifestos constantes, que são definidas no sinal. H.

|*SIG* valor|Descrição|
|-----------------|-----------------|
|**SIGABRT**|Encerramento anormal|
|**SIGFPE**|Erro de ponto flutuante|
|**SIGILL**|Instrução ilegal|
|**SIGINT**|Sinal de CTRL+C|
|**SIGSEGV**|Acesso ao armazenamento inválido|
|**SIGTERM**|Solicitação de encerramento|

Se *sig* não é um dos valores acima, o manipulador de parâmetro inválido é invocado, conforme definido em [validação do parâmetro](../../c-runtime-library/parameter-validation.md) . Se a execução é permitida para continuar, esta função define **errno** para **EINVAL** e retorna **SIG_ERR**.

Por padrão, **sinal** encerra o programa de chamada com o código de saída 3, independentemente do valor *sig*.

> [!NOTE]
> **SIGINT** não há suporte para qualquer aplicativo do Win32. Quando ocorre uma interrupção CTRL+C, sistemas operacionais Win32 geram um novo thread para manipular especificamente essa interrupção. Isso pode fazer com que um aplicativo de thread único, tal como um no UNIX, torne-se multithread e cause um comportamento inesperado.

O *func* argumento é um endereço para um manipulador de sinal que você escrever ou uma das constantes predefinidas **SIG_DFL** ou **SIG_IGN**, que também é definido no sinal. H. Se *func* é uma função, ele é instalado como o manipulador de sinal para o sinal especificado. Protótipo do manipulador de sinal requer um argumento formal, *sig*, do tipo **int**. O sistema operacional fornece o argumento real por meio de *sig* quando ocorre uma interrupção; o argumento é o sinal que gerou a interrupção. Portanto, você pode usar as seis constantes de manifesto (listadas na tabela anterior) no seu manipulador de sinal para determinar qual interrupção ocorreu e tomar ações adequadas. Por exemplo, você pode chamar **sinal** duas vezes para atribuir o mesmo manipulador para dois sinais diferentes e, em seguida, teste o *sig* argumento no manipulador de ações diferentes com base no sinal recebido.

Se você estiver testando para exceções de ponto flutuante (**SIGFPE**), *func* aponta para uma função que utiliza um segundo argumento opcional que é uma das várias constantes de manifesto, definidos em FLOAT. H do formulário **FPE_xxx**. Quando um **SIGFPE** sinal ocorrer, você pode testar o valor do segundo argumento para determinar o tipo de exceção de ponto flutuante e, em seguida, execute a ação apropriada. Esse argumento e seus possíveis valores são extensões da Microsoft.

Exceções de ponto flutuante, o valor de *func* não é redefinido quando o sinal. Para recuperar-se de exceções de ponto flutuante, use cláusulas try/except ao redor de operações de ponto flutuante. Também é possível recuperar-se usando [setjmp](setjmp.md) com [longjmp](longjmp.md). Em ambos os casos, o processo de chamada continua a execução e deixa o estado de ponto flutuante do processo indefinido.

Se o manipulador de sinal retorna, a execução do processo de chamada é retomada imediatamente após o ponto em que ele recebeu o sinal de interrupção. Isso é verdadeiro independentemente do tipo de sinal ou modo de operação.

Antes da função especificada é executada, o valor de *func* é definido como **SIG_DFL**. O próximo sinal de interrupção é tratado como descrito para **SIG_DFL**, a menos que a interrupção de uma chamada para **sinal** especifique o contrário. Você pode usar esse recurso para redefinir os sinais na função chamada.

Já que rotinas de manipulador de sinal são geralmente chamadas de forma assíncrona quando ocorre uma interrupção, a função de manipulador de sinal pode obter controle quando uma operação em tempo de execução está incompleta e está em um estado desconhecido. A lista a seguir resume as restrições que determinam quais funções você pode usar em sua rotina de manipulador de sinal.

- Faça não problema de baixo nível ou STDIO. Rotinas de e/s de H (por exemplo, **printf** ou **fread**).

- Não chame rotinas de heap ou qualquer rotina que usa as rotinas de heap (por exemplo, **malloc**, **strdup**, ou **putenv**). Consulte [malloc](malloc.md) para obter mais informações.

- Não usar qualquer função que gera uma chamada do sistema (por exemplo, **getcwd** ou **tempo**).

- Não use **longjmp** , a menos que a interrupção é causada por uma exceção de ponto flutuante (ou seja, *sig* é **SIGFPE**). Nesse caso, reinicializar primeiro o pacote de ponto flutuante usando uma chamada para **fpreset**.

- Não use nenhuma rotina de sobreposição.

Um programa deve conter código de ponto flutuante se é para interceptar o **SIGFPE** exceção usando a função. Se o seu programa não tem código de ponto flutuante e requer o código de manipulação de sinal da biblioteca em tempo de execução, basta declarar um volatile double e inicializá-lo a zero:

```C
volatile double d = 0.0f;
```

O **SIGILL** e **SIGTERM** sinais não são gerados no Windows. Eles são incluídos para compatibilidade ANSI. Portanto, você pode definir manipuladores de sinal para esses sinais usando **sinal**, e você pode gerar explicitamente esses sinais chamando [gerar](raise.md).

Configurações de sinal não são preservadas em processos de reprodução que são criados por chamadas para [EXEC](../../c-runtime-library/exec-wexec-functions.md) ou [spawn](../../c-runtime-library/spawn-wspawn-functions.md) funções. As configurações de sinal são redefinidas para os valores padrão no novo processo.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**signal**|\<signal.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como usar **sinal** para adicionar um comportamento personalizado para o **SIGABRT** sinal. Para obter informações adicionais sobre o comportamento de anulação, consulte [_set_abort_behavior](set-abort-behavior.md).

```C
// crt_signal.c
// compile with: /EHsc /W4
// Use signal to attach a signal handler to the abort routine
#include <stdlib.h>
#include <signal.h>
#include <tchar.h>

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

```Output
This application has requested the Runtime to terminate it in an unusual way.
Please contact the application's support team for more information.
```

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[abort](abort.md)<br/>
[Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)<br/>
[exit, _Exit, _exit](exit-exit-exit.md)<br/>
[_fpreset](fpreset.md)<br/>
[Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)<br/>
