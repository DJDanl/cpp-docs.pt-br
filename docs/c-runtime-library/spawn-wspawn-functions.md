---
title: Funções _spawn, _wspawn
ms.date: 11/04/2016
apilocation:
- msvcr80.dll
- msvcr110_clr0400.dll
- msvcr110.dll
- msvcrt.dll
- msvcr120.dll
- msvcr100.dll
- msvcr90.dll
apitype: DLLExport
f1_keywords:
- _spawn
- _tspawnlp
- _tspawnlpe
- _tspawnve
- _tspawnvp
- _tspawnvpe
- _tspawnl
- spawn
- _tspawnv
- _tspawnle
- wspawn
helpviewer_keywords:
- _tspawnve function
- _spawn functions
- _tspawnlpe function
- tspawnvpe function
- processes, creating
- tspawnve function
- _tspawnvp function
- spawn functions
- tspawnl function
- tspawnlp function
- _tspawnvpe function
- _tspawnl function
- tspawnvp function
- tspawnv function
- processes, executing new
- _tspawnv function
- tspawnle function
- process creation
- _tspawnlp function
- tspawnlpe function
- _tspawnle function
ms.assetid: bb47c703-5216-4e09-8023-8cf25bbf2cf9
ms.openlocfilehash: 49a65680d330752679c86c47c4b142ee3153237c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50533790"
---
# <a name="spawn-wspawn-functions"></a>Funções _spawn, _wspawn

Cada uma das funções `_spawn` cria e executa um novo processo:

|||
|-|-|
|[_spawnl, _wspawnl](../c-runtime-library/reference/spawnl-wspawnl.md)|[_spawnv, _wspawnv](../c-runtime-library/reference/spawnv-wspawnv.md)|
|[_spawnle, _wspawnle](../c-runtime-library/reference/spawnle-wspawnle.md)|[_spawnve, _wspawnve](../c-runtime-library/reference/spawnve-wspawnve.md)|
|[_spawnlp, _wspawnlp](../c-runtime-library/reference/spawnlp-wspawnlp.md)|[_spawnvp, _wspawnvp](../c-runtime-library/reference/spawnvp-wspawnvp.md)|
|[_spawnlpe, _wspawnlpe](../c-runtime-library/reference/spawnlpe-wspawnlpe.md)|[_spawnvpe, _wspawnvpe](../c-runtime-library/reference/spawnvpe-wspawnvpe.md)|

As letras no final do nome da função determinam a variação.

|Letra|Variante|
|-|-|
| `e`  | `envp`, matriz de ponteiros para configurações de ambiente, é passada para o novo processo.  |
| `l`  | Os argumentos da linha de comando são passados individualmente para a função `_spawn`. Esse sufixo é normalmente usado quando um número de parâmetros para um novo processo é conhecido de antemão.  |
| `p`  | A variável de ambiente `PATH` é usada para encontrar o arquivo a ser executado.  |
| `v`  | `argv`, matriz de ponteiros para argumentos da linha de comando, é passada para a função `_spawn`. Esse sufixo é normalmente usado quando um número de parâmetros para um novo processo é variável.  |

## <a name="remarks"></a>Comentários

Cada uma das funções `_spawn` cria e executa um novo processo. Elas tratam automaticamente dos argumentos da cadeia de caracteres multibyte conforme apropriado, reconhecendo as cadeias de caracteres multibyte de acordo com a página de código multibyte em uso no momento. As funções `_wspawn` são versões de caractere largo das funções `_spawn`; elas não tratam de cadeias de caracteres multibyte. Caso contrário, as funções `_wspawn` comportam-se de maneira idêntica às suas correspondentes de tipo `_spawn`.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|`_tspawnl`|`_spawnl`|`_spawnl`|`_wspawnl`|
|`_tspawnle`|`_spawnle`|`_spawnle`|`_wspawnle`|
|`_tspawnlp`|`_spawnlp`|`_spawnlp`|`_wspawnlp`|
|`_tspawnlpe`|`_spawnlpe`|`_spawnlpe`|`_wspawnlpe`|
|`_tspawnv`|`_spawnv`|`_spawnv`|`_wspawnv`|
|`_tspawnve`|`_spawnve`|`_spawnve`|`_wspawnve`|
|`_tspawnvp`|`_spawnvp`|`_spawnvp`|`_wspawnvp`|
|`_tspawnvpe`|`_spawnvpe`|`_spawnvpe`|`_wspawnvpe`|

Deve haver memória suficiente disponível para carregar e executar o novo processo. O argumento `mode` determina a ação tomada pelo processo de chamada antes e durante `_spawn`. Os seguintes valores para `mode` são definidos em Process.h:

|||
|-|-|
| `_P_OVERLAY`  | Sobrepõe um novo processo a um processo de chamada, que é destruído (o mesmo efeito resultante de chamadas `_exec`).  |
| `_P_WAIT`  | Suspende um thread de chamada até que a execução do novo processo seja concluída (`_spawn` síncrono).  |
| `_P_NOWAIT` ou `_P_NOWAITO`  | Continua a executar um processo de chamada simultaneamente com o novo processo (`_spawn` assíncrono).  |
| `_P_DETACH`  | Continua a executar o processo de chamada; o novo processo é executado em segundo plano sem acesso ao console ou ao teclado. Chamadas para `_cwait` relacionadas ao novo processo falham (`_spawn` assíncrono).  |

O argumento `cmdname` especifica o arquivo que é executado como o novo processo e pode especificar um caminho completo (desde a raiz), um caminho parcial (desde o diretório de trabalho atual) ou apenas um nome de arquivo. Se `cmdname` não tem uma extensão de nome de arquivo ou não termina com um ponto (.), a função `_spawn` tenta primeiro a extensão de nome de arquivo .com e, em seguida, a extensão de nome de arquivo .exe, a extensão de nome de arquivo .bat e, finalmente, a extensão de nome de arquivo .cmd.

Se `cmdname` tiver uma extensão de nome de arquivo, apenas essa extensão será usada. Se `cmdname` terminar com um ponto final, a chamada `_spawn` procurará `cmdname` sem extensão de nome de arquivo. As funções `_spawnlp`, `_spawnlpe`, `_spawnvp` e `_spawnvpe` pesquisam por `cmdname` (usando os mesmos procedimentos) nos diretórios especificados pela variável de ambiente `PATH`.

Se `cmdname` contiver um especificador de unidade ou alguma barra (ou seja, se for um caminho relativo), a chamada `_spawn` pesquisará apenas em busca do arquivo especificado, sem pesquisar por nenhum caminho.

No passado, algumas dessas funções definiam `errno` para zero em caso de êxito; o comportamento atual é deixar `errno` inalterado em caso de êxito, conforme especificado pelo padrão C. Se você precisar emular o comportamento antigo, defina `errno` como zero logo antes de chamar essas funções.

> [!NOTE]
>  Para garantir a inicialização e término corretos da sobreposição, não use a função `setjmp` ou `longjmp` para entrar ou sair de uma rotina de sobreposição.

## <a name="arguments-for-the-spawned-process"></a>Argumentos para o processo gerado

Para passar argumentos para o novo processo, forneça um ou mais ponteiros para cadeias de caracteres como argumentos na chamada `_spawn`. Essas cadeias de caracteres formam a lista de argumentos do processo gerado. O comprimento combinado das cadeias de caracteres que formam a lista de argumentos para o novo processo não deve exceder 1.024 bytes. O caractere nulo de terminação ('\0') para cada cadeia de caracteres não está incluído na contagem, mas os caracteres de espaço (inseridos automaticamente para separar os argumentos) são incluídos.

> [!NOTE]
>  Os espaços inseridos nas cadeias de caracteres podem causar um comportamento inesperado. Por exemplo, passando `_spawn`, a cadeia de caracteres `"hi there"` resultará na obtenção de dois argumentos pelo processo, `"hi"` e `"there"`. Se a intenção for fazer o novo processo abrir um arquivo chamado "hi there", o processo falhará. É possível evitar isso colocando a cadeia de caracteres entre aspas: `"\"hi there\""`.

> [!IMPORTANT]
>  Não passe a entrada do usuário para `_spawn` sem verificar explicitamente seu conteúdo. `_spawn` resultará em uma chamada para [CreateProcess](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa), então tenha em mente que nomes de caminho desqualificados podem levar a possíveis vulnerabilidades de segurança.

Os ponteiros de argumento podem ser passados como argumentos separados (em `_spawnl`, `_spawnle`, `_spawnlp` e `_spawnlpe`) ou como uma matriz de ponteiros (em `_spawnv`, `_spawnve`, `_spawnvp` e `_spawnvpe`). Você deve passar pelo menos um argumento, `arg0` ou `argv`[0], para o processo gerado. Por convenção, este argumento é o nome do programa como você o digitaria na linha de comando. Um valor diferente não produz um erro.

As chamadas `_spawnl`, `_spawnle`, `_spawnlp` e `_spawnlpe` costumam ser usadas nos casos em que o número de argumentos é conhecido de antemão. O argumento `arg0` costuma ser um ponteiro para `cmdname`. Os argumentos de `arg1` a `argn` são ponteiros para as cadeias de caracteres que formam a nova lista de argumentos. Após `argn`, deve haver um ponteiro **NULL** para marcar o fim da lista de argumentos.

As chamadas `_spawnv`, `_spawnve`, `_spawnvp` e `_spawnvpe` são úteis quando há um número variável de argumentos para o novo processo. Os ponteiros para os parâmetros são passados como uma matriz, `argv`*.* O argumento `argv`[0] é geralmente um ponteiro para um caminho em modo real ou o nome do programa no modo protegido, enquanto `argv`[1] a `argv`[`n`] são ponteiros para as cadeias de caracteres que formam a nova lista de argumentos. O argumento `argv`[`n` +1] deve ser um ponteiro **NULL** para marcar o fim da lista de argumentos.

## <a name="environment-of-the-spawned-process"></a>Ambiente do processo gerado

Os arquivos abertos quando uma chamada `_spawn` é feita continuam abertos no novo processo. Nas chamadas `_spawnl`, `_spawnlp`, `_spawnv` e `_spawnvp`, o novo processo herda o ambiente do processo de chamada. Você pode usar as chamadas `_spawnle`, `_spawnlpe`, `_spawnve` e `_spawnvpe` para alterar o ambiente do novo processo passando uma lista de configurações de ambiente por meio do argumento `envp`. O argumento `envp` é uma matriz de ponteiros de caractere e cada elemento (exceto o elemento final) dessa matriz aponta para uma cadeia de caracteres terminada em nulo que define uma variável de ambiente. Normalmente, uma cadeia de caracteres assim tem a forma `NAME`=`value`, em que `NAME` é o nome de uma variável de ambiente e `value` é o valor da cadeia de caracteres cuja variável está definida. (Observe que o `value` não está entre aspas duplas.) O elemento final da matriz `envp` deve ser **NULL**. Quando o próprio `envp` é **NULL**, o novo processo gerado herda as configurações de ambiente do processo pai.

As funções `_spawn` podem passar todas as informações sobre arquivos abertos, incluindo o modo de tradução para o novo processo. Essas informações são passadas em modo real por meio da entrada `C_FILE_INFO` no ambiente. O código de inicialização normalmente processa essa entrada e, em seguida, a exclui do ambiente. No entanto, se uma função `_spawn` gerar um processo não C, essa entrada permanecerá no ambiente. O ambiente de impressão mostra os caracteres de gráfico na cadeia de caracteres definição para essa entrada, porque as informações de ambiente são passadas no formato binário em modo real. Isso não deve ter nenhum outro efeito em operações normais. No modo protegido, as informações de ambiente são transmitidas na forma de texto e, portanto, não contêm nenhum caractere de gráfico.

Você deve liberar explicitamente (usando `fflush` ou `_flushall`) ou fechar qualquer fluxo antes de chamar uma função `_spawn`.

As configurações de sinal não são preservadas em novos processos criados por chamadas para rotinas `_spawn`. Em vez disso, o processo gerado redefine as configurações de sinal para o padrão.

## <a name="redirecting-output"></a>Redirecionando a saída

Se você estiver chamando `_spawn` de uma DLL ou um aplicativo GUI e desejar redirecionar a saída para um pipe, você terá duas opções:

- Usar a API do Win32 para criar um pipe, depois chamar [AllocConsole](https://msdn.microsoft.com/library/windows/desktop/ms681944), definir os valores de identificador na estrutura de inicialização e chamar [CreateProcess](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa).

- Chamar [_popen, _wpopen](../c-runtime-library/reference/popen-wpopen.md), que criará um pipe e invocará o aplicativo usando **cmd.exe /c** (ou **command.exe /c**).

## <a name="example"></a>Exemplo

```
// crt_spawn.c
// This program accepts a number in the range
// 1-8 from the command line. Based on the number it receives,
// it executes one of the eight different procedures that
// spawn the process named child. For some of these procedures,
// the CHILD.EXE file must be in the same directory; for
// others, it only has to be in the same path.
//

#include <stdio.h>
#include <process.h>

char *my_env[] =
{
   "THIS=environment will be",
   "PASSED=to child.exe by the",
   "_SPAWNLE=and",
   "_SPAWNLPE=and",
   "_SPAWNVE=and",
   "_SPAWNVPE=functions",
   NULL
};

int main( int argc, char *argv[] )
{
   char *args[4];

   // Set up parameters to be sent:
   args[0] = "child";
   args[1] = "spawn??";
   args[2] = "two";
   args[3] = NULL;

   if (argc <= 2)
   {
      printf( "SYNTAX: SPAWN <1-8> <childprogram>\n" );
      exit( 1 );
   }

   switch (argv[1][0])   // Based on first letter of argument
   {
   case '1':
      _spawnl( _P_WAIT, argv[2], argv[2], "_spawnl", "two", NULL );
      break;
   case '2':
      _spawnle( _P_WAIT, argv[2], argv[2], "_spawnle", "two",
               NULL, my_env );
      break;
   case '3':
      _spawnlp( _P_WAIT, argv[2], argv[2], "_spawnlp", "two", NULL );
      break;
   case '4':
      _spawnlpe( _P_WAIT, argv[2], argv[2], "_spawnlpe", "two",
                NULL, my_env );
      break;
   case '5':
      _spawnv( _P_OVERLAY, argv[2], args );
      break;
   case '6':
      _spawnve( _P_OVERLAY, argv[2], args, my_env );
      break;
   case '7':
      _spawnvp( _P_OVERLAY, argv[2], args );
      break;
   case '8':
      _spawnvpe( _P_OVERLAY, argv[2], args, my_env );
      break;
   default:
      printf( "SYNTAX: SPAWN <1-8> <childprogram>\n" );
      exit( 1 );
   }
   printf( "from SPAWN!\n" );
}
```

```Output
child process output
from SPAWN!
```

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../c-runtime-library/process-and-environment-control.md)<br/>
[abort](../c-runtime-library/reference/abort.md)<br/>
[atexit](../c-runtime-library/reference/atexit.md)<br/>
[Funções _exec, _wexec](../c-runtime-library/exec-wexec-functions.md)<br/>
[exit, _Exit, _exit](../c-runtime-library/reference/exit-exit-exit.md)<br/>
[_flushall](../c-runtime-library/reference/flushall.md)<br/>
[_getmbcp](../c-runtime-library/reference/getmbcp.md)<br/>
[_onexit, _onexit_m](../c-runtime-library/reference/onexit-onexit-m.md)<br/>
[_setmbcp](../c-runtime-library/reference/setmbcp.md)<br/>
[system, _wsystem](../c-runtime-library/reference/system-wsystem.md)