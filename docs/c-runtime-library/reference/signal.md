---
title: signal | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
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
ms.assetid: 094118de-d789-4063-b4f4-cffcc80bf29d
caps.latest.revision: 26
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: b124479c62a62ef7795498b6c4a96191e2ecb6e4
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="signal"></a>signal
Define a manipulação de sinal de interrupção.  
  
> [!IMPORTANT]
>  Não use esse método para desligar um aplicativo [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)], exceto em cenários de teste ou depuração. As formas programáticas ou de interface do usuário de fechar um aplicativo [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] não são permitidas de acordo com a Seção 3.6 dos [Requisitos de certificação de aplicativos do Windows 8](http://go.microsoft.com/fwlink/?LinkId=262889). Para obter mais informações, consulte [Ciclo de vida do aplicativo (aplicativos da Windows Store)](http://go.microsoft.com/fwlink/?LinkId=262853).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void (__cdecl *signal(  
   int sig,   
   void (__cdecl *func ) (int [, int ] )))   
   (int);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `sig`  
 Valor de sinal.  
  
 `func`  
 Função a ser executada. O primeiro parâmetro é um valor de sinal e o segundo parâmetro é um subcódigo que pode ser usado quando o primeiro parâmetro é SIGFPE.  
  
## <a name="return-value"></a>Valor de retorno  
 `signal` retorna o valor anterior de `func` que é associado ao sinal informado. Por exemplo, se o valor anterior de `func` era `SIG_IGN`, o valor retornado também é `SIG_IGN`. Um valor retornado de `SIG_ERR` indica um erro; nesse caso, `errno` é definido como `EINVAL`.  
  
 Para obter mais informações sobre esses códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 A função `signal` permite que um processo escolha uma das várias maneiras de lidar com um sinal de interrupção do sistema operacional. O argumento `sig` é a interrupção à qual `signal` responde; ele deve ser uma das constantes de manifesto a seguir, que são definidas em SIGNAL.H.  
  
|Valor `sig`|Descrição|  
|-----------------|-----------------|  
|`SIGABRT`|Encerramento anormal|  
|`SIGFPE`|Erro de ponto flutuante|  
|`SIGILL`|Instrução ilegal|  
|`SIGINT`|Sinal de CTRL+C|  
|`SIGSEGV`|Acesso ao armazenamento inválido|  
|`SIGTERM`|Solicitação de encerramento|  
  
 Se `sig` não é nenhum dos valores acima, o manipulador de parâmetro inválido é invocado conforme definido em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função definirá `errno` para `EINVAL` e retornará `SIG_ERR`.  
  
 Por padrão, `signal` encerra o programa de chamada com o código de saída 3, independentemente do valor de `sig`.  
  
> [!NOTE]
> Nenhum aplicativo Win32 dá suporte a  `SIGINT`. Quando ocorre uma interrupção CTRL+C, sistemas operacionais Win32 geram um novo thread para manipular especificamente essa interrupção. Isso pode fazer com que um aplicativo de thread único, tal como um no UNIX, torne-se multithread e cause um comportamento inesperado.  
  
 O argumento `func` é um endereço para um manipulador de sinal que você escreve ou uma das constantes predefinidas `SIG_DFL` ou `SIG_IGN`, que também são definidas em SIGNAL.H. Se `func` for uma função, ela será instalada como o manipulador de sinal para o sinal fornecido. O protótipo do manipulador de sinal requer um argumento formal, `sig`, do tipo `int`. O sistema operacional fornece o argumento real por meio de `sig` quando ocorre uma interrupção; o argumento é o sinal que gerou a interrupção. Portanto, você pode usar as seis constantes de manifesto (listadas na tabela anterior) no seu manipulador de sinal para determinar qual interrupção ocorreu e tomar ações adequadas. Por exemplo, você pode chamar `signal` duas vezes para atribuir o mesmo manipulador para dois sinais diferentes e, em seguida, testar o argumento `sig` no manipulador para executar ações diferentes com base no sinal recebido.  
  
 Se você estiver testando para exceções de ponto flutuante (`SIGFPE`), `func` apontará para uma função que leva um segundo argumento opcional que é uma das várias constantes de manifesto – definidas em FLOAT.H – do formulário `FPE_xxx`. Quando um sinal `SIGFPE` ocorre, você pode testar o valor do segundo argumento para determinar o tipo de exceção de ponto flutuante e, em seguida, realizar a ação apropriada. Esse argumento e seus possíveis valores são extensões da Microsoft.  
  
 Para exceções de ponto flutuante, o valor de `func` não é redefinido quando o sinal é recebido. Para recuperar-se de exceções de ponto flutuante, use cláusulas try/except ao redor de operações de ponto flutuante. Também é possível recuperar-se usando [setjmp](../../c-runtime-library/reference/setjmp.md) com [longjmp](../../c-runtime-library/reference/longjmp.md). Em ambos os casos, o processo de chamada continua a execução e deixa o estado de ponto flutuante do processo indefinido.  
  
 Se o manipulador de sinal retorna, a execução do processo de chamada é retomada imediatamente após o ponto em que ele recebeu o sinal de interrupção. Isso é verdadeiro independentemente do tipo de sinal ou modo de operação.  
  
 Antes da função especificada ser executada, o valor de `func` é definido como `SIG_DFL`. O próximo sinal de interrupção é tratado como descrito para `SIG_DFL`, a menos que uma chamada intermediária para `signal` especifique o contrário. Você pode usar esse recurso para redefinir os sinais na função chamada.  
  
 Já que rotinas de manipulador de sinal são geralmente chamadas de forma assíncrona quando ocorre uma interrupção, a função de manipulador de sinal pode obter controle quando uma operação em tempo de execução está incompleta e está em um estado desconhecido. A lista a seguir resume as restrições que determinam quais funções você pode usar em sua rotina de manipulador de sinal.  
  
-   Não emita rotinas de E/S de baixo nível ou STDIO.H (por exemplo, `printf` ou `fread`).  
  
-   Não chame rotinas de heap nem qualquer rotina que use as rotinas de heap (por exemplo, `malloc`, `_strdup` ou `_putenv`). Consulte [malloc](../../c-runtime-library/reference/malloc.md) para obter mais informações.  
  
-   Não use nenhuma função que gere uma chamada do sistema (por exemplo, `_getcwd` ou `time`).  
  
-   Não use `longjmp` a menos que a interrupção seja causada por uma exceção de ponto flutuante (ou seja, se `sig` for `SIGFPE`). Nesse caso, reinicialize primeiro o pacote de ponto flutuante usando uma chamada para `_fpreset`.  
  
-   Não use nenhuma rotina de sobreposição.  
  
 Um programa deverá conter código de ponto flutuante se for interceptar a exceção `SIGFPE` usando a função. Se o seu programa não tem código de ponto flutuante e requer o código de manipulação de sinal da biblioteca em tempo de execução, basta declarar um volatile double e inicializá-lo a zero:  
  
`volatile double d = 0.0f;`  
  
 Os sinais `SIGILL` e `SIGTERM` não são gerados no Windows. Eles são incluídos para compatibilidade ANSI. Portanto, você pode definir manipuladores de sinal para esses sinais usando `signal` e você também pode gerar esses sinais explicitamente, chamando [raise](../../c-runtime-library/reference/raise.md).  
  
 As configurações de sinal não são preservadas em processos gerados criados por chamadas para funções `_exec` ou `_spawn`. As configurações de sinal são redefinidas para os valores padrão no novo processo.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`signal`|\<signal.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como usar `signal` para adicionar um comportamento personalizado para o sinal `SIGABRT`. Para obter informações adicionais sobre o comportamento de anulação, consulte [_set_abort_behavior](../../c-runtime-library/reference/set-abort-behavior.md).  
  
```cpp  
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
 [Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [abort](../../c-runtime-library/reference/abort.md)   
 [Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)   
 [exit, _Exit, _exit](../../c-runtime-library/reference/exit-exit-exit.md)   
 [_fpreset](../../c-runtime-library/reference/fpreset.md)   
 [Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)
