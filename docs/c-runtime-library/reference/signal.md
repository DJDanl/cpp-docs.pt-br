---
title: "signal | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "signal"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-runtime-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "signal"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função signal"
ms.assetid: 094118de-d789-4063-b4f4-cffcc80bf29d
caps.latest.revision: 26
caps.handback.revision: 24
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# signal
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define a manipulação de sinais de interrupção.  
  
> [!IMPORTANT]
>  Não use este método para fechar um aplicativo de [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)], exceto em cenários de teste e depuração.  As maneiras programáticas ou de interface de usuário de fechar um aplicativo do [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] não são permitidas de acordo com a seção 3.6 dos [Requisitos de certificação de aplicativo do Windows 8](http://go.microsoft.com/fwlink/?LinkId=262889).  Para obter mais informações, consulte [Ciclo de vida do aplicativo \(aplicativos da Windows Store\)](http://go.microsoft.com/fwlink/?LinkId=262853).  
  
## Sintaxe  
  
```  
void (__cdecl *signal(  
   int sig,   
   void (__cdecl *func ) (int [, int ] )))   
   (int);  
```  
  
#### Parâmetros  
 `sig`  
 Valor do sinal.  
  
 `func`  
 Função a ser executada.  O primeiro parâmetro é um valor de sinal e o segundo parâmetro é um subcódigo que pode ser usado quando o primeiro parâmetro é SIGFPE.  
  
## Valor de retorno  
 `signal` retorna o valor anterior `func` que está associado ao sinal especificado.  Por exemplo, se o valor anterior de `func` era `SIG_IGN`, o valor de retorno também é `SIG_IGN`.  Um valor de retorno de `SIG_ERR` indica um erro; nesse caso, `errno` é definido como `EINVAL`.  
  
 Para obter mais informações sobre códigos de retorno, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 A função `signal` permite que um processo escolha uma das várias maneiras de manipular um sinal de interrupção do sistema operacional.  O argumento `sig` é a interrupção à qual `signal` responde; ele deve ser uma das constantes de manifesto a seguir, que são definidas em SIGNAL.H.  
  
|Valor `sig`|Descrição|  
|-----------------|---------------|  
|`SIGABRT`|Encerramento anormal|  
|`SIGFPE`|Erro de ponto flutuante|  
|`SIGILL`|Instrução ilegal|  
|`SIGINT`|Sinal de CTRL\+C|  
|`SIGSEGV`|Acesso ilegal ao armazenamento|  
|`SIGTERM`|Solicitação de finalização|  
  
 Se `sig` não for um dos valores acima, o manipulador de parâmetro inválido é chamado, conforme definido em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essa função definirá `errno` como `EINVAL` e retornará `SIG_ERR`.  
  
 Por padrão, `signal` finaliza o programa de chamada com código de saída 3, independentemente do valor de `sig`.  
  
> [!NOTE]
>  `SIGINT` não tem suporte em aplicativos do Win32.  Quando uma interrupção de CTRL\+C ocorre, os sistemas operacionais Win32 geram um novo thread para manipular especificamente essa interrupção.  Isso pode gerar um aplicativo single\-thread, como um em UNIX, para se tornar multi\-threaded e gerar comportamento inesperado.  
  
 O argumento `func` é um endereço para um manipulador de sinal que você escreve ou para uma das constantes predefinidas `SIG_DFL` ou `SIG_IGN`, que também são definidas em SIGNAL.H.  Se `func` for uma função, será instalado como manipulador de sinal para o sinal determinado.  O protótipo do manipulador de sinais requer um argumento formal, `sig`, do tipo `int`.  O sistema operacional fornece o argumento real por meio de `sig` quando ocorre uma interrupção; o argumento é o sinal que gerou a interrupção.  Portanto, você pode usar as seis constantes de manifesto \(listadas na tabela acima\) em seu manipulador de sinal para determinar qual interrupção ocorreu e executar a ação adequada.  Por exemplo, você pode chamar `signal` duas vezes para atribuir o mesmo manipulador a dois sinais diferentes, e testa o argumento de `sig` no manipulador para executar diferentes ações com base no sinal recebido.  
  
 Se você estiver testando exceções de ponto flutuante \(`SIGFPE`\), `func` apontará para uma função que recebe um segundo argumento opcional que é uma das várias restrições do manifesto, definidas em FLOAT.H, do formulário `FPE_xxx`.  Quando um sinal `SIGFPE` ocorre, você pode testar o valor do segundo argumento para determinar o tipo de exceção de ponto flutuante e, então, executar a ação apropriada.  Esse argumento e seus valores possíveis são extensões da Microsoft.  
  
 Para exceções de ponto flutuante, o valor de `func` não é redefinido quando o sinal é recebido.  Para recuperar as exceções de ponto flutuante, use as cláusulas try\/except para cercar as operações de ponto flutuante.  Também é possível recuperar usando [setjmp](../../c-runtime-library/reference/setjmp.md) com [longjmp](../../c-runtime-library/reference/longjmp.md).  Em ambos os casos, o processo de chamada continua a execução e deixa o estado de ponto flutuante de processo indefinido.  
  
 Se o manipulador de sinal retornar, o processo de chamada continua a execução imediatamente após o ponto em que recebeu o sinal de interrupção.  Isso é verdadeiro, independentemente do tipo de sinal ou modo operacional.  
  
 Antes da execução da função especificada, o valor de `func` será definido como `SIG_DFL`.  O próximo sinal de interrupção é tratado conforme descrito para `SIG_DFL`, a menos que uma chamada interveniente a `signal` especifique o contrário.  Você pode usar esse recurso para redefinir sinais na função chamada.  
  
 Como as rotinas de manipulador por sinal são geralmente chamadas de forma assíncrona quando ocorre uma interrupção, sua função de manipulador por sinal pode obter o controle quando uma operação de tempo de execução está incompleta e em estado desconhecido.  A lista a seguir resume as restrições que determinam as funções que você pode usar na sua rotina de manipulador por sinal.  
  
-   Não emita rotinas de baixo nível ou de E\/S de STDIO.H \(por exemplo, `printf` ou `fread`\).  
  
-   Não chame rotinas da heap ou nenhuma rotina que usa rotinas da heap \(por exemplo, `malloc`, `_strdup`, ou `_putenv`\).  Consulte [malloc](../../c-runtime-library/reference/malloc.md) para maiores informações.  
  
-   Não use nenhuma função que produz uma chamada do sistema \(por exemplo, `_getcwd` ou `time`\).  
  
-   Não use `longjmp` a menos que a interrupção seja causada por uma exceção de ponto flutuante \(ou seja, `sig` é `SIGFPE`\).  Nesse caso, reinicializar primeiro o pacote de ponto flutuante usando uma chamada a `_fpreset`.  
  
-   Não use nenhuma rotina de sobreposição.  
  
 Um programa deve conter o código de ponto flutuante se for interceptar a exceção de `SIGFPE` usando a função.  Se seu programa não possuir código de ponto flutuante e não exigir o código de tratamento de sinal da biblioteca em tempo de execução, apenas declare um double temporário e inicialize\-o com o valor de zero:  
  
```  
volatile double d = 0.0f;   
```  
  
 Os sinais `SIGILL` e `SIGTERM` não são gerados no Windows.  Eles foram incluídos para compatibilidade ANSI.  Portanto, você pode definir manipuladores de sinal para esses sinais usando `signal` e também pode gerar explicitamente esses sinais chamando [raise](../../c-runtime-library/reference/raise.md).  
  
 As configurações de sinal não são mantidas em processos gerados criados por chamadas para `_exec` ou funções `_spawn` .  As configurações de sinal são redefinidas para valores padrão no novo processo.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`signal`|\<signal.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
 O exemplo a seguir mostra como usar `signal` para adicionar um comportamento personalizado ao sinal `SIGABRT`.  Para obter mais informações sobre o comportamento do cancelamento, consulte [\_set\_abort\_behavior](../../c-runtime-library/reference/set-abort-behavior.md).  
  
```cpp  
// crt_signal.c  
// compile with: /EHsc /W4  
// Use signal to attach a signal handler to the abort routine  
#include <stdlib.h>  
#include <signal.h>  
#include <tchar.h>  
  
void SignalHandler(int signal)  
{  
    if (signal == SIGABRT) {  
        // abort signal handler code  
    } else {  
        // ...  
    }  
}  
  
int main()  
{  
    typedef void (*SignalHandlerPointer)(int);  
  
    SignalHandlerPointer previousHandler;  
    previousHandler = signal(SIGABRT, SignalHandler);  
  
    abort();  
}  
  
```  
  
  **Esse aplicativo solicitou que o Tempo de Execução o encerre de maneira incomum.**  
**Entre em contato com a equipe de suporte do aplicativo para obter mais informações.**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Processo e controle de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [abort](../../c-runtime-library/reference/abort.md)   
 [Funções \_exec, \_wexec](../../c-runtime-library/exec-wexec-functions.md)   
 [sair, Exit, Exit](../../c-runtime-library/reference/exit-exit-exit.md)   
 [\_fpreset](../../c-runtime-library/reference/fpreset.md)   
 [Funções \_spawn, \_wspawn](../Topic/_spawn,%20_wspawn%20Functions.md)