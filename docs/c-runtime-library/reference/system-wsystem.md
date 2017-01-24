---
title: "system, _wsystem | Microsoft Docs"
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
  - "system"
  - "_wsystem"
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
  - "_tsystem"
  - "_wsystem"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _tsystem"
  - "Função _wsystem"
  - "intérprete de comando"
  - "comandos, executando"
  - "Função system"
  - "Função tsystem"
  - "Função wsystem"
ms.assetid: 7d3df2b6-f742-49ce-bf52-012b0aee3df5
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# system, _wsystem
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Executa um comando.  
  
> [!IMPORTANT]
>  Essa API não pode ser usada em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  Para obter mais informações, consulte [Funções de CRT sem suporte com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int system(  
   const char *command   
);  
int _wsystem(  
   const wchar_t *command   
);  
```  
  
#### Parâmetros  
 `command`  
 O comando a ser executado.  
  
## Valor de retorno  
 Se `command` for `NULL` e o interpretador de comandos for encontrado, retorna um valor diferente de zero.  Se o interpretador de comandos não for encontrado, retorna 0 e define `errno` para `ENOENT`.  Se `command` não `NULL`, `system` retorna o valor retornado por um interpretador de comandos.  Retorna o valor 0 somente se o interpretador de comando retorna o valor 0.  Um valor de retorno de – 1 indica um erro, e `errno` é definido como um dos seguintes valores:  
  
 `E2BIG`  
 A lista de argumentos \(que é dependente do sistema\) é muito grande.  
  
 `ENOENT`  
 Não é possível encontrar o interpretador de comandos.  
  
 `ENOEXEC`  
 O interpretador de comandos arquivo não pode ser executado porque o formato não é válido.  
  
 `ENOMEM`  
 Não há memória suficiente está disponível para executar o comando. ou memória disponível corrompida; ou existe um bloco inválido, que indica que o processo que está fazendo a chamada não foi alocado corretamente.  
  
 Consulte [doserrno, errno, sys\_errlist e sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md) para obter mais informações sobre esses códigos de retorno.  
  
## Comentários  
 O `system` função passa `command` ao interpretador de comandos, que executa a cadeia de caracteres como um comando de sistema operacional.  `system` usa a `COMSPEC` e `PATH` CMD.exe variáveis de ambiente para localizar o interpretador de comandos do arquivo.  Se `command` for `NULL`, a função simplesmente verifica se existe o interpretador de comandos.  
  
 Você deve liberar explicitamente — usando `fflush` ou `_flushall`— ou fechar qualquer fluxo antes de chamar `system`.  
  
 A função `_wsystem` é uma versão de caractere largo da função `system`; o argumento `command` para `_wsystem` é uma cadeia de caracteres larga.  Essas funções se comportam de forma idêntica caso contrário.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tsystem`|`system`|`system`|`_wsystem`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`system`|\< process.h \> ou \< stdlib. h \>|  
|`_wsystem`|\< process.h \> ou \< stdlib. h \> ou \< WCHAR. h \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
 Este exemplo usa `system` para o tipo de um arquivo de texto.  
  
```  
// crt_system.c  
  
#include <process.h>  
  
int main( void )  
{  
   system( "type crt_system.txt" );  
}  
```  
  
## Entrada: crt\_system.txt  
  
```  
Line one.  
Line two.  
```  
  
### Saída  
  
```  
Line one.  
Line two.  
```  
  
## Equivalência do .NET Framework  
  
-   [Classe System::Diagnostics::ProcessStartInfo](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)  
  
-   [Classe System::Diagnostics::Process](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx)  
  
## Consulte também  
 [Processo e controle de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [Funções \_exec, \_wexec](../../c-runtime-library/exec-wexec-functions.md)   
 [sair, Exit, Exit](../../c-runtime-library/reference/exit-exit-exit.md)   
 [\_flushall](../../c-runtime-library/reference/flushall.md)   
 [Funções \_spawn, \_wspawn](../Topic/_spawn,%20_wspawn%20Functions.md)