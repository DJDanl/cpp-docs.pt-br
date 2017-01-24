---
title: "abort | Microsoft Docs"
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
  - "abort"
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
  - "Abort"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "anulando o processo atual"
  - "Função abort"
  - "processos, anulando"
ms.assetid: a797783b-40ed-4bdb-a2cd-14ffede39e8a
caps.latest.revision: 24
caps.handback.revision: 24
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# abort
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Anula o processo atual e retorna um código de erro.  
  
> [!NOTE]
>  Não use esse método para desligar um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo, exceto em teste ou cenários de depuração. Formas de programação ou da interface do usuário para fechar um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo não são permitidos de acordo com o [requisitos de certificação de aplicativos do Windows 8](http://go.microsoft.com/fwlink/?LinkId=262889). Para obter mais informações, consulte [ciclo de vida do aplicativo \(aplicativos da Windows Store\)](http://go.microsoft.com/fwlink/?LinkId=262853).  
  
## Sintaxe  
  
```  
void abort( void );  
```  
  
## Valor de retorno  
 `abort` Retorna o controle para o processo de chamada. Por padrão, ele procura um manipulador de sinal de anulação e gera `SIGABRT` se um for definido. Em seguida, `abort` encerra o processo atual e retorna um código de saída para o processo pai.  
  
## Comentários  
 **Específico da Microsoft**  
  
 Por padrão, quando um aplicativo é compilado com a biblioteca de tempo de execução de depuração, o `abort` rotina exibe uma mensagem de erro antes de `SIGABRT` é gerado. Para aplicativos de console em execução no modo de console, a mensagem é enviada para `STDERR`. Aplicativos de área de trabalho do Windows e aplicativos de console em execução no modo de janela exibem a mensagem em uma caixa de mensagem. Para suprimir a mensagem, use [set\_abort\_behavior](../../c-runtime-library/reference/set-abort-behavior.md) para limpar o `_WRITE_ABORT_MSG` sinalizador. A mensagem exibida depende da versão do ambiente de tempo de execução usada. Para aplicativos criados usando a versão mais recente do Visual C\+\+, a mensagem é semelhante a isso:  
  
 `R6010`  
  
 `- abort() has been called`  
  
 Nas versões anteriores da biblioteca de tempo de execução C, esta mensagem foi exibida:  
  
 "`This application has requested the Runtime to terminate it in an unusual way. Please contact the application's support team for more information.`"  
  
 Quando o programa é compilado no modo de depuração, a caixa de mensagem exibe opções para **anular**, **novamente**, ou **Ignorar**. Se o usuário escolher **anular**, o programa é encerrado imediatamente e retorna um código de saída de 3. Se o usuário escolher **novamente**, um depurador é invocado para depuração just\-in\-time, se disponível. Se o usuário escolher **Ignorar**, `abort` continua o processamento normal.  
  
 Em compilações de depuração e comercial, `abort` em seguida, verifica se é definido como um manipulador de sinal de anulação. Se um manipulador de sinal não padrão for definido, `abort` chamadas `raise(SIGABRT)`. Use o [sinal](../../c-runtime-library/reference/signal.md) função para associar uma função de manipulador de sinal de anulação com o `SIGABRT` sinal. Você pode executar ações personalizadas — por exemplo, limpar recursos ou informações de log — e encerrar o aplicativo com seu próprio código de erro na função de manipulador. Se nenhum manipulador personalizado de sinal for definido, `abort` não dispara o `SIGABRT` sinal.  
  
 Por padrão, em compilações sem depuração de aplicativos de área de trabalho ou console, `abort` invoca o erro do Windows \(Dr mecanismo de relatórios. Watson\) para falhas de relatório à Microsoft. Esse comportamento pode ser habilitado ou desabilitado chamando `_set_abort_behavior` e configuração ou mascarando a `_CALL_REPORTFAULT` sinalizador. Quando o sinalizador estiver definido, o Windows exibe uma caixa de mensagem que contém texto algo como "Um problema fez com que o programa pare de funcionar corretamente." O usuário pode escolher invocar um depurador com um **Depurar** botão ou escolha o **Close program** botão para encerrar o aplicativo com um código de erro definido pelo sistema operacional.  
  
 Se o relatório de manipulador de erros do Windows não é chamado, em seguida, `abort` chamadas [exit](../../c-runtime-library/reference/exit-exit-exit.md) para finalizar o processo com exit código 3 e retorna o controle para o processo pai ou o sistema operacional.`_exit` não liberar buffers de fluxo ou `atexit`\/`_onexit` de processamento.  
  
 Para obter mais informações sobre depuração de CRT, consulte [Técnicas de depuração CRT](../Topic/CRT%20Debugging%20Techniques.md).  
  
 **Fim de específico da Microsoft**  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`abort`|\< process.h \> ou \< stdlib. h \>|  
  
## Exemplo  
 O seguinte programa tenta abrir um arquivo e será anulada se a tentativa falhará.  
  
```c  
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
Não foi possível abrir o arquivo: arquivo ou diretório inexistente  
```  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Usando abort](../../cpp/using-abort.md)   
 [Função abort](../../c-language/abort-function-c.md)   
 [Processo e controle de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [Funções \_exec, \_wexec](../../c-runtime-library/exec-wexec-functions.md)   
 [sair, Exit, Exit](../../c-runtime-library/reference/exit-exit-exit.md)   
 [raise](../../c-runtime-library/reference/raise.md)   
 [signal](../../c-runtime-library/reference/signal.md)   
 [Funções \_spawn, \_wspawn](../Topic/_spawn,%20_wspawn%20Functions.md)   
 [\_DEBUG](../Topic/_DEBUG.md)   
 [\_set\_abort\_behavior](../../c-runtime-library/reference/set-abort-behavior.md)