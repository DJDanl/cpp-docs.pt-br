---
title: Processo e controle de ambiente
ms.date: 11/04/2016
f1_keywords:
- c.programs
helpviewer_keywords:
- processes, stopping
- processes, administrative tasks
- parent process
- processes, starting
- environment control routines
- process control routines
ms.assetid: 7fde74c3-c2a6-4d15-84b8-092160d60c3e
ms.openlocfilehash: 74194311eb33a23de5643b3cb956c2e3f752dea0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50525613"
---
# <a name="process-and-environment-control"></a>Processo e controle de ambiente

Use as rotinas de controle de processo para iniciar, parar e gerenciar processos de dentro de um programa. Use as rotinas de controle de ambiente para obter e alterar informações sobre o ambiente do sistema operacional.

## <a name="process-and-environment-control-functions"></a>Processo e funções de controle de ambiente

|Rotina|Use|
|-------------|---------|
|[abort](../c-runtime-library/reference/abort.md)|Anular o processo sem liberar os buffers ou chamar as funções registradas por **atexit** e **_onexit**|
|[assert](../c-runtime-library/reference/assert-macro-assert-wassert.md)|Testar se há erro de lógica|
|Macros [_ASSERT, _ASSERTE](../c-runtime-library/reference/assert-asserte-assert-expr-macros.md)|Similar a **assert**, mas disponível apenas nas versões de depuração das bibliotecas em tempo de execução|
|[atexit](../c-runtime-library/reference/atexit.md)|Agendar rotinas para execução no encerramento do programa|
|[_beginthread, _beginthreadex](../c-runtime-library/reference/beginthread-beginthreadex.md)|Criar um novo thread em um processo do sistema operacional Windows|
|[_cexit](../c-runtime-library/reference/cexit-c-exit.md)|Executar procedimentos de término **exit** (como liberar buffers) e depois retornar o controle ao programa de chamada sem terminar o processo|
|[_c_exit](../c-runtime-library/reference/cexit-c-exit.md)|Executar procedimentos de término **_exit** e depois retornar o controle ao programa de chamada sem terminar o processo|
|[_cwait](../c-runtime-library/reference/cwait.md)|Aguarde até outro processo terminar|
|[_endthread, _endthreadex](../c-runtime-library/reference/endthread-endthreadex.md)|Encerrar um thread do sistema operacional Windows|
|[_execl, _wexecl](../c-runtime-library/reference/execl-wexecl.md)|Executar o novo processo com a lista de argumentos|
|[_execle, _wexecle](../c-runtime-library/reference/execle-wexecle.md)|Executar o novo processo com a lista de argumentos e o ambiente fornecido|
|[_execlp, _wexeclp](../c-runtime-library/reference/execlp-wexeclp.md)|Executar o novo processo usando a variável **PATH** e a lista de argumentos|
|[_execlpe, _wexeclpe](../c-runtime-library/reference/execlpe-wexeclpe.md)|Executar o novo processo usando a variável **PATH**, ambiente fornecido e lista de argumentos|
|[_execv, _wexecv](../c-runtime-library/reference/execv-wexecv.md)|Executar o novo processo com uma matriz de argumentos|
|[_execve, _wexecve](../c-runtime-library/reference/execve-wexecve.md)|Executar o novo processo com a matriz de argumentos e o ambiente fornecido|
|[_execvp, _wexecvp](../c-runtime-library/reference/execvp-wexecvp.md)|Executar o novo processo usando a variável **PATH** e a matriz de argumentos|
|[_execvpe, _wexecvpe](../c-runtime-library/reference/execvpe-wexecvpe.md)|Executar o novo processo usando a variável **PATH**, ambiente fornecido e matriz de argumentos|
|[exit](../c-runtime-library/reference/exit-exit-exit.md)|Chamar funções registradas por **atexit** e **_onexit**, liberar todos os buffers, fechar todos os arquivos abertos e terminar o processo|
|[_exit](../c-runtime-library/reference/exit-exit-exit.md)|Terminar o processo imediatamente sem chamar **atexit** ou **_onexit** ou liberar buffers|
|[getenv, _wgetenv](../c-runtime-library/reference/getenv-wgetenv.md), [getenv_s, _wgetenv_s](../c-runtime-library/reference/getenv-s-wgetenv-s.md)|Obter o valor da variável do ambiente|
|[_getpid](../c-runtime-library/reference/getpid.md)|Obter o número de identificação do processo|[System::Diagnostics::Process::Id](https://msdn.microsoft.com/library/system.diagnostics.process.id.aspx)|
|[longjmp](../c-runtime-library/reference/longjmp.md)|Restaurar o ambiente de pilha salvo. Usá-lo para executar um **goto** não local|
|[_onexit](../c-runtime-library/reference/onexit-onexit-m.md)|Agendar rotinas para execução no encerramento do programa; usar para compatibilidade com a versão 7.0 do Microsoft C/C++ e versões anteriores|
|[_pclose](../c-runtime-library/reference/pclose.md)|Aguardar um novo processador de comando e fechar o fluxo no pipe associado|
|[perror, _wperror](../c-runtime-library/reference/perror-wperror.md)|Imprimir mensagem de erro|
|[_pipe](../c-runtime-library/reference/pipe.md)|Criar um pipe para leitura e gravação|
|[_popen, _wpopen](../c-runtime-library/reference/popen-wpopen.md)|Criar pipe e executar o comando|
|[_putenv, _wputenv](../c-runtime-library/reference/putenv-wputenv.md), [_putenv_s, _wputenv_s](../c-runtime-library/reference/putenv-s-wputenv-s.md)|Adicionar ou alterar o valor da variável de ambiente|
|[raise](../c-runtime-library/reference/raise.md)|Enviar um sinal para o processo de chamada|
|[setjmp](../c-runtime-library/reference/setjmp.md)|Salvar o ambiente da pilha. Usar para executar **goto** não local|
|[signal](../c-runtime-library/reference/signal.md)|Lidar com o sinal de interrupção|
|[_spawnl, _wspawnl](../c-runtime-library/reference/spawnl-wspawnl.md)|Criar e executar o novo processo com a lista de argumentos especificados|
|[_spawnle, _wspawnle](../c-runtime-library/reference/spawnle-wspawnle.md)|Criar e executar o novo processo com a lista de argumentos e o ambiente especificados|
|[_spawnlp, _wspawnlp](../c-runtime-library/reference/spawnlp-wspawnlp.md)|Criar e executar o novo processo usando a variável **PATH** e a lista de argumentos especificada|
|[_spawnlpe, _wspawnlpe](../c-runtime-library/reference/spawnlpe-wspawnlpe.md)|Criar e executar o novo processo usando a variável **PATH**, o ambiente especificado e a lista de argumentos|
|[_spawnv, _wspawnv](../c-runtime-library/reference/spawnv-wspawnv.md)|Criar e executar o novo processo com a matriz de argumentos especificada|
|[_spawnve, _wspawnve](../c-runtime-library/reference/spawnve-wspawnve.md)|Criar e executar o novo processo com a matriz de argumentos e o ambiente especificados|
|[_spawnvp, _wspawnvp](../c-runtime-library/reference/spawnvp-wspawnvp.md)|Criar e executar o novo processo usando a variável **PATH** e a matriz de argumentos especificada|
|[_spawnvpe, _wspawnvpe](../c-runtime-library/reference/spawnvpe-wspawnvpe.md)|Criar e executar o novo processo usando a variável **PATH**, o ambiente especificado e a matriz de argumentos|
|[system, _wsystem](../c-runtime-library/reference/system-wsystem.md)|Executar o comando do sistema operacional|

No sistema operacional Windows, o processo gerado é equivalente ao processo de geração. Qualquer processo pode usar **_cwait** para aguardar outro processo para o qual a ID do processo é conhecida.

A diferença entre as famílias **_exec** e **_spawn** é que uma função **_spawn** pode retornar o controle do novo processo para o processo de chamada. Em uma função **_spawn**, o processo de chamada e o novo processo estão presentes na memória, a menos que **_P_OVERLAY** seja especificado. Em uma função **_exec**, o novo processo se sobrepõe ao processo de chamada, para que o controle não retorne ao processo de chamada a menos que ocorra um erro ao tentar iniciar a execução do novo processo.

As diferenças entre as funções na família **_exec**, bem como entre aquelas da família **_spawn**, envolvem o método de localização do arquivo a ser executado como o novo processo, o formulário no qual os argumentos são passados para o novo processo e o método de configuração do ambiente, conforme mostra a tabela a seguir. Use uma função que passa uma lista de argumentos quando o número de argumentos for constante ou conhecido no momento da compilação. Use uma função que passa um ponteiro para uma matriz contendo os argumentos quando o número de argumentos for determinado no tempo de execução. As informações na tabela a seguir também se aplicam aos equivalentes de caractere largo das funções **_spawn** e **_exec**.

### <a name="spawn-and-exec-function-families"></a>Famílias _spawn e _exec Function

|Funções|Use a variável PATH para localizar o arquivo|Convenção de passagem de argumentos|Configurações do ambiente|
|---------------|--------------------------------------|----------------------------------|--------------------------|
|**_execl**, **_spawnl**|Não|Lista|Herdado do processo de chamada|
|**_execle**, **_spawnle**|Não|Lista|Ponteiro para a tabela de ambientes para o novo processo passado como o último argumento|
|**_execlp**, **_spawnlp**|Sim|Lista|Herdado do processo de chamada|
|**_execvpe**, **_spawnvpe**|Sim|Matriz|Ponteiro para a tabela de ambientes para o novo processo passado como o último argumento|
|**_execlpe**, **_spawnlpe**|Sim|Lista|Ponteiro para a tabela de ambientes para o novo processo passado como o último argumento|
|**_execv**, **_spawnv**|Não|Matriz|Herdado do processo de chamada|
|**_execve**, **_spawnve**|Não|Matriz|Ponteiro para a tabela de ambientes para o novo processo passado como o último argumento|
|**_execvp**, **_spawnvp**|Sim|Matriz|Herdado do processo de chamada|

## <a name="see-also"></a>Consulte também

[Rotinas de tempo de execução C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>
