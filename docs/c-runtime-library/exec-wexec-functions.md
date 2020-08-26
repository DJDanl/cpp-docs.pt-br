---
title: Funções _exec, _wexec
ms.date: 11/04/2016
api_location:
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr90.dll
- msvcrt.dll
- msvcr100.dll
- msvcr110.dll
- msvcr80.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _texecve
- texecl
- _texeclpe
- texecve
- texecv
- texeclp
- texecle
- exec
- texeclpe
- _texecvp
- _texecl
- _texecle
- wexec
- _exec
- _texeclp
- _texecvpe
- texecvpe
- _texecv
- _wexec
helpviewer_keywords:
- _texecle function
- _texecv function
- texeclpe function
- texecle function
- _texecl function
- texecv function
- _texeclp function
- _texecve function
- texecl function
- texecve function
- exec function
- texeclp function
- texecvp function
- texecvpe function
- processes, executing new
- _texecvp function
- _texeclpe function
- _wexec functions
- wexec functions
- _exec function
- _texecvpe function
ms.assetid: a261df93-206a-4fdc-b8ac-66aa7db83bc6
ms.openlocfilehash: ecfcf88b09a4383fc050e9737a0ffe7203f9a050
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88839719"
---
# <a name="_exec-_wexec-functions"></a>Funções _exec, _wexec

Cada função desta família carrega e executa um novo processo:

:::row:::
   :::column span="":::
      [_execl, _wexecl](../c-runtime-library/reference/execl-wexecl.md)\
      [_execv, _wexecv](../c-runtime-library/reference/execv-wexecv.md)\
      [_execle, _wexecle](../c-runtime-library/reference/execle-wexecle.md)
   :::column-end:::
   :::column span="":::
      [_execve, _wexecve](../c-runtime-library/reference/execve-wexecve.md)\
      [_execlp, _wexeclp](../c-runtime-library/reference/execlp-wexeclp.md)\
      [_execvp, _wexecvp](../c-runtime-library/reference/execvp-wexecvp.md)
   :::column-end:::
   :::column span="":::
      [_execlpe, _wexeclpe](../c-runtime-library/reference/execlpe-wexeclpe.md)\
      [_execvpe, _wexecvpe](../c-runtime-library/reference/execvpe-wexecvpe.md)
   :::column-end:::
:::row-end:::

A letra no final do nome da função determina a variação.

|_exec sufixo da função|Descrição|
|----------------------------|-----------------|
|`e`|`envp`, matriz de ponteiros para configurações de ambiente, que é passada para o novo processo.|
|`l`|Os argumentos da linha de comando são passados individualmente para a função `_exec`. Normalmente usado quando o número de parâmetros para o novo processo é conhecido de antemão.|
|`p`|A variável de ambiente `PATH` é usada para encontrar o arquivo a ser executado.|
|`v`|`argv`, matriz de ponteiros para argumentos da linha de comando, que é passada para `_exec`. Normalmente usado quando o número de parâmetros para o novo processo é variável.|

## <a name="remarks"></a>Comentários

Cada função `_exec` carrega e executa um novo processo. Todas as funções `_exec` usam a mesma função do sistema operacional ([CreateProcess](/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessw)). As funções `_exec` identificam automaticamente os argumentos da cadeia de caracteres multibyte como apropriados, reconhecendo as sequências de caracteres multibyte de acordo com a página de código multibyte em uso no momento. As funções `_wexec` são versões de caractere largo das funções `_exec`. As funções `_wexec` se comportam de maneira idêntica às equivalentes da família `_exec`, exceto por não identificarem cadeias de caracteres multibyte.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|`_texecl`|`_execl`|`_execl`|`_wexecl`|
|`_texecle`|`_execle`|`_execle`|`_wexecle`|
|`_texeclp`|`_execlp`|`_execlp`|`_wexeclp`|
|`_texeclpe`|`_execlpe`|`_execlpe`|`_wexeclpe`|
|`_texecv`|`_execv`|`_execv`|`_wexecv`|
|`_texecve`|`_execve`|`_execve`|`_wexecve`|
|`_texecvp`|`_execvp`|`_execvp`|`_wexecvp`|
|`_texecvpe`|`_execvpe`|`_execvpe`|`_wexecvpe`|

O parâmetro `cmdname` especifica o arquivo a ser executado como novo processo. Ele pode especificar um caminho completo (a partir da raiz), um caminho parcial (a partir do diretório de trabalho atual) ou um nome de arquivo. Se `cmdname` não tiver uma extensão de nome de arquivo ou não terminar com um ponto final (.), a função `_exec` procurará o arquivo nomeado. Se for malsucedida, a pesquisa tentará o mesmo nome base usando a extensão de nome de arquivo e as extensões de nome de arquivo .exe, .bat e .cmd. Se `cmdname` tiver uma extensão de nome de arquivo, apenas essa extensão será usada na pesquisa. Se `cmdname` terminar com um ponto final, a função `_exec` procurará `cmdname` sem extensão de nome de arquivo. `_execlp`, `_execlpe`, `_execvp` e `_execvpe` pesquisam `cmdname` (usando os mesmos procedimentos) nos diretórios especificados pela variável de ambiente `PATH`. Se `cmdname` contiver um especificador de unidade ou alguma barra (ou seja, se for um caminho relativo), a chamada `_exec` procura apenas o arquivo especificado. O caminho não é pesquisado.

Os parâmetros são passados para o novo processo atribuindo um ou mais ponteiros às cadeias de caracteres como parâmetros na chamada `_exec`. Essas cadeias de caracteres formam a lista de parâmetros do novo processo. O tamanho combinado das configurações de ambiente herdadas e as cadeias de caracteres que formam a lista de parâmetros do novo processo não devem exceder 32 quilobytes. O caractere nulo de terminação ('\0') para cada cadeia de caracteres não está incluído na contagem, mas os caracteres de espaço (inseridos automaticamente para separar os parâmetros) são contados.

> [!NOTE]
> Os espaços inseridos nas cadeias de caracteres podem causar um comportamento inesperado. Por exemplo, passando `_exec`, a cadeia de caracteres `"hi there"` resultará na obtenção de dois argumentos pelo processo, `"hi"` e `"there"`. Se a intenção for fazer o novo processo abrir um arquivo chamado "hi there", o processo falhará. É possível evitar isso colocando a cadeia de caracteres entre aspas: `"\"hi there\""`.

> [!IMPORTANT]
> Não passe a entrada do usuário para `_exec` sem verificar explicitamente seu conteúdo. `_exec` resultará em uma chamada para [CreateProcess](/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessw), então tenha em mente que nomes de caminho desqualificados podem levar a possíveis vulnerabilidades de segurança.

As funções `_exec` validam seus parâmetros. Se os parâmetros esperados forem ponteiros nulos, cadeias de caracteres vazias ou omitidos, as funções `_exec` invocarão o manipulador de parâmetro inválido, como descrito em [Validação de parâmetro](../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão `errno` como `EINVAL` e retornarão -1. Nenhum processo novo é executado.

Os ponteiros de argumento podem ser passados como parâmetros separados (em `_execl`, `_execle`, `_execlp` e `_execlpe`) ou como uma matriz de ponteiros (em `_execv`, `_execve`, `_execvp` e `_execvpe`). Pelo menos um parâmetro, `arg0`, deve ser passado para o novo processo. Esse parâmetro é `argv`[0] do novo processo. Normalmente, esse ponteiro é uma cópia de `cmdname`. (Um valor diferente não produz um erro.)

As chamadas `_execl`, `_execle`, `_execlp` e `_execlpe` costumam ser usadas quando o número de parâmetros é conhecido de antemão. O parâmetro `arg0` costuma ser um ponteiro para `cmdname`. Os parâmetros de `arg1` até `argn` apontam para as cadeias de caracteres que formam a nova lista de parâmetros. Um ponteiro nulo deve seguir `argn` para marcar o final da lista de parâmetros.

As chamadas `_execv`, `_execve`, `_execvp` e `_execvpe` são úteis quando o número de parâmetros para o novo processo é variável. Os ponteiros para os parâmetros são passados como uma matriz, `argv`. O parâmetro `argv`[0] costuma ser um ponteiro para `cmdname`. Os parâmetros de `argv`[1] até `argv`[`n`] apontam para as cadeias de caracteres que formam a nova lista de parâmetros. O parâmetro `argv`[`n`+1] deve ser um ponteiro **NULL** para marcar o final da lista de parâmetros.

Os arquivos abertos quando uma chamada `_exec` é feita continuam abertos no novo processo. Nas chamadas `_execl`, `_execlp`, `_execv` e `_execvp`, o novo processo herda o ambiente do processo de chamada. Chamadas `_execle`, `_execlpe`, `_execve` e `_execvpe` alteram o ambiente para o novo processo passando uma lista de configurações de ambiente por meio do parâmetro `envp`. `envp` é uma matriz de ponteiros de caractere e cada elemento (exceto o elemento final) aponta para uma cadeia de caracteres encerrada nula que define uma variável de ambiente. Normalmente, uma cadeia de caracteres assim tem a forma `NAME`=`value`, em que `NAME` é o nome de uma variável de ambiente e `value` é o valor da cadeia de caracteres cuja variável está definida. (Observe que `value` não está entre aspas duplas.) O elemento final da `envp` matriz deve ser **nulo**. Quando o próprio `envp` é **NULL**, o novo processo herda as configurações de ambiente do processo de chamada.

Um programa executado com uma das funções `_exec` é sempre carregado na memória como se o campo de alocação máximo no cabeçalho do arquivo .exe do programa estivesse definido com o valor padrão de 0xFFFFH.

As chamadas `_exec` não preservam os modos de conversão de arquivos abertos. Se o novo processo precisar usar arquivos herdados do processo de chamada, use a rotina [_setmode](../c-runtime-library/reference/setmode.md) para definir o modo de translação desses arquivos como o modo desejado. Você deve liberar explicitamente (usando `fflush` ou `_flushall`) ou fechar qualquer fluxo antes da chamada da função `_exec`. As configurações de sinal não são preservadas em novos processos criados por chamadas para rotinas `_exec`. As configurações de sinal padrão são restauradas no novo processo.

## <a name="example"></a>Exemplo

```c
// crt_args.c
// Illustrates the following variables used for accessing
// command-line arguments and environment variables:
// argc  argv  envp
// This program will be executed by crt_exec which follows.

#include <stdio.h>

int main( int argc,  // Number of strings in array argv
char *argv[],       // Array of command-line argument strings
char **envp )       // Array of environment variable strings
{
    int count;

    // Display each command-line argument.
    printf( "\nCommand-line arguments:\n" );
    for( count = 0; count < argc; count++ )
        printf( "  argv[%d]   %s\n", count, argv[count] );

    // Display each environment variable.
    printf( "\nEnvironment variables:\n" );
    while( *envp != NULL )
        printf( "  %s\n", *(envp++) );

    return;
}
```

Execute o seguinte programa para executar Crt_args.exe:

```c
// crt_exec.c
// Illustrates the different versions of exec, including
//      _execl          _execle          _execlp          _execlpe
//      _execv          _execve          _execvp          _execvpe
//
// Although CRT_EXEC.C can exec any program, you can verify how
// different versions handle arguments and environment by
// compiling and specifying the sample program CRT_ARGS.C. See
// "_spawn, _wspawn Functions" for examples of the similar spawn
// functions.

#include <stdio.h>
#include <conio.h>
#include <process.h>

char *my_env[] =     // Environment for exec?e
{
   "THIS=environment will be",
   "PASSED=to new process by",
   "the EXEC=functions",
   NULL
};

int main( int ac, char* av[] )
{
   char *args[4];
   int ch;
   if( ac != 3 ){
      fprintf( stderr, "Usage: %s <program> <number (1-8)>\n", av[0] );
      return;
   }

   // Arguments for _execv?
   args[0] = av[1];
   args[1] = "exec??";
   args[2] = "two";
   args[3] = NULL;

   switch( atoi( av[2] ) )
   {
   case 1:
      _execl( av[1], av[1], "_execl", "two", NULL );
      break;
   case 2:
      _execle( av[1], av[1], "_execle", "two", NULL, my_env );
      break;
   case 3:
      _execlp( av[1], av[1], "_execlp", "two", NULL );
      break;
   case 4:
      _execlpe( av[1], av[1], "_execlpe", "two", NULL, my_env );
      break;
   case 5:
      _execv( av[1], args );
      break;
   case 6:
      _execve( av[1], args, my_env );
      break;
   case 7:
      _execvp( av[1], args );
      break;
   case 8:
      _execvpe( av[1], args, my_env );
      break;
   default:
      break;
   }

   // This point is reached only if exec fails.
   printf( "\nProcess was not execed." );
   exit( 0 );
}
```

## <a name="requirements"></a>Requisitos

**Header:** process.h

## <a name="see-also"></a>Confira também

[Controle de processo e ambiente](../c-runtime-library/process-and-environment-control.md)<br/>
[anular](../c-runtime-library/reference/abort.md)<br/>
[atexit](../c-runtime-library/reference/atexit.md)<br/>
[exit, _Exit, _exit](../c-runtime-library/reference/exit-exit-exit.md)<br/>
[_onexit, _onexit_m](../c-runtime-library/reference/onexit-onexit-m.md)<br/>
[_spawn, _wspawn funções](../c-runtime-library/spawn-wspawn-functions.md)<br/>
[system, _wsystem](../c-runtime-library/reference/system-wsystem.md)
