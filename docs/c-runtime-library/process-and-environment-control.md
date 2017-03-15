---
title: Processo e controle de ambiente | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- c.programs
dev_langs:
- C++
helpviewer_keywords:
- processes, stopping
- processes, administrative tasks
- parent process
- processes, starting
- environment control routines
- process control routines
ms.assetid: 7fde74c3-c2a6-4d15-84b8-092160d60c3e
caps.latest.revision: 9
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
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: d5198dcef7d24d2755c21b90802b19e809c5b8da
ms.lasthandoff: 02/25/2017

---
# <a name="process-and-environment-control"></a>Processo e controle de ambiente
Use as rotinas de controle de processo para iniciar, parar e gerenciar processos de dentro de um programa. Use as rotinas de controle de ambiente para obter e alterar informações sobre o ambiente do sistema operacional.  
  
### <a name="process-and-environment-control-functions"></a>Processo e funções de controle de ambiente  
  
|Rotina|Uso|Equivalente ao .NET Framework|  
|-------------|---------|-------------------------------|  
|[abort](../c-runtime-library/reference/abort.md)|Cancelar o processo sem liberar os buffers ou chamar funções registradas por `atexit` e `_onexit`|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).|  
|[assert](../c-runtime-library/reference/assert-macro-assert-wassert.md)|Testar se há erro de lógica|[System::Diagnostics::Debug::Assert](https://msdn.microsoft.com/en-us/library/system.diagnostics.debug.assert.aspx)|  
|Macros [_ASSERT, _ASSERTE](../c-runtime-library/reference/assert-asserte-assert-expr-macros.md)|Similar a `assert` mas disponível apenas em versões de depuração das bibliotecas de tempo de execução|[System::Diagnostics::Debug::Assert](https://msdn.microsoft.com/en-us/library/system.diagnostics.debug.assert.aspx)|  
|[atexit](../c-runtime-library/reference/atexit.md)|Agendar rotinas para execução no encerramento do programa|[System::Diagnostics::Process::Exited](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.exited.aspx)|  
|[_beginthread, _beginthreadex](../c-runtime-library/reference/beginthread-beginthreadex.md)|Criar um novo thread em um processo do sistema operacional Windows|[System::Threading::Thread::Start](https://msdn.microsoft.com/en-us/library/system.threading.thread.start.aspx)|  
|[_cexit](../c-runtime-library/reference/cexit-c-exit.md)|Executar procedimentos de encerramento `exit` (como liberar buffers) e depois devolver o controle ao programa de chamada sem encerrar processo|[System::Diagnostics::Process::CloseMainWindow](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.closemainwindow.aspx)|  
|[_c_exit](../c-runtime-library/reference/cexit-c-exit.md)|Executar procedimentos de encerramento `_exit` e depois devolver o controle ao programa de chamada sem encerrar processo|[System::Diagnostics::Process::CloseMainWindow](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.closemainwindow.aspx)|  
|[_cwait](../c-runtime-library/reference/cwait.md)|Aguarde até outro processo terminar|[System::Diagnostics::Process::WaitForExit](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.waitforexit.aspx)|  
|[_endthread, _endthreadex](../c-runtime-library/reference/endthread-endthreadex.md)|Encerrar um thread do sistema operacional Windows|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).|  
|[_execl, _wexecl](../c-runtime-library/reference/execl-wexecl.md)|Executar o novo processo com a lista de argumentos|[System::Diagnostics::Process Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [System::Diagnostics::ProcessStartInfo Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[_execle, _wexecle](../c-runtime-library/reference/execle-wexecle.md)|Executar o novo processo com a lista de argumentos e o ambiente fornecido|[System::Diagnostics::Process Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [System::Diagnostics::ProcessStartInfo Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[_execlp, _wexeclp](../c-runtime-library/reference/execlp-wexeclp.md)|Executar o novo processo usando a variável `PATH` e a lista de argumentos|[System::Diagnostics::Process Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [System::Diagnostics::ProcessStartInfo Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[_execlpe, _wexeclpe](../c-runtime-library/reference/execlpe-wexeclpe.md)|Executar o novo processo usando a variável `PATH` e a lista de argumentos e ambiente fornecidos|[System::Diagnostics::Process Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [System::Diagnostics::ProcessStartInfo Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[_execv, _wexecv](../c-runtime-library/reference/execv-wexecv.md)|Executar o novo processo com uma matriz de argumentos|[System::Diagnostics::Process Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [System::Diagnostics::ProcessStartInfo Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[_execve, _wexecve](../c-runtime-library/reference/execve-wexecve.md)|Executar o novo processo com a matriz de argumentos e o ambiente fornecido|[System::Diagnostics::Process Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [System::Diagnostics::ProcessStartInfo Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[_execvp, _wexecvp](../c-runtime-library/reference/execvp-wexecvp.md)|Executar o novo processo usando a variável `PATH` e a matriz de argumentos|[System::Diagnostics::Process Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [System::Diagnostics::ProcessStartInfo Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[_execvpe, _wexecvpe](../c-runtime-library/reference/execvpe-wexecvpe.md)|Executar o novo processo usando a variável `PATH`, a lista de argumentos e o ambiente fornecidos|[System::Diagnostics::Process Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [System::Diagnostics::ProcessStartInfo Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[exit](../c-runtime-library/reference/exit-exit-exit.md)|Chamar funções registradas por `atexit` e `_onexit`, liberar todos os buffers, fechar todos os arquivos abertos e encerrar processo|[System::Diagnostics::Process::Kill](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.kill.aspx)|  
|[_exit](../c-runtime-library/reference/exit-exit-exit.md)|Encerrar processo imediatamente sem chamar `atexit` ou `_onexit` ou liberar buffers|[System::Diagnostics::Process::Kill](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.kill.aspx)|  
|[getenv, _wgetenv](../c-runtime-library/reference/getenv-wgetenv.md), [getenv_s, _wgetenv_s](../c-runtime-library/reference/getenv-s-wgetenv-s.md)|Obter o valor da variável do ambiente|[System::Environment::GetEnvironmentVariable](https://msdn.microsoft.com/en-us/library/system.environment.getenvironmentvariable.aspx)|  
|[_getpid](../c-runtime-library/reference/getpid.md)|Obter o número de identificação do processo|[System::Diagnostics::Process::Id](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.id.aspx)|  
|[longjmp](../c-runtime-library/reference/longjmp.md)|Restaurar o ambiente de pilha salvo; usá-lo para executar um `goto` não local|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).|  
|[_onexit](../c-runtime-library/reference/onexit-onexit-m.md)|Agendar rotinas para execução no encerramento do programa; usar para compatibilidade com a versão 7.0 do Microsoft C/C++ e versões anteriores|[System::Diagnostics::Process::Exited](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.exited.aspx)|  
|[_pclose](../c-runtime-library/reference/pclose.md)|Aguardar um novo processador de comando e fechar o fluxo no pipe associado|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).|  
|[perror, _wperror](../c-runtime-library/reference/perror-wperror.md)|Imprimir mensagem de erro|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).|  
|[_pipe](../c-runtime-library/reference/pipe.md)|Criar um pipe para leitura e gravação|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).|  
|[_popen, _wpopen](../c-runtime-library/reference/popen-wpopen.md)|Criar pipe e executar o comando|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).|  
|[_putenv, _wputenv](../c-runtime-library/reference/putenv-wputenv.md), [_putenv_s, _wputenv_s](../c-runtime-library/reference/putenv-s-wputenv-s.md)|Adicionar ou alterar o valor da variável de ambiente|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).|  
|[raise](../c-runtime-library/reference/raise.md)|Enviar um sinal para o processo de chamada|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).|  
|[setjmp](../c-runtime-library/reference/setjmp.md)|Salvar o ambiente da pilha. usar para executar `goto` não local|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).|  
|[signal](../c-runtime-library/reference/signal.md)|Lidar com o sinal de interrupção|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).|  
|[_spawnl, _wspawnl](../c-runtime-library/reference/spawnl-wspawnl.md)|Criar e executar o novo processo com a lista de argumentos especificados|[System::Diagnostics::Process Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [System::Diagnostics::ProcessStartInfo Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[_spawnle, _wspawnle](../c-runtime-library/reference/spawnle-wspawnle.md)|Criar e executar o novo processo com a lista de argumentos e o ambiente especificados|[System::Diagnostics::Process Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [System::Diagnostics::ProcessStartInfo Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[_spawnlp, _wspawnlp](../c-runtime-library/reference/spawnlp-wspawnlp.md)|Criar e executar o novo processo usando a variável `PATH` e a lista de argumentos especificada|[System::Diagnostics::Process Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [System::Diagnostics::ProcessStartInfo Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[_spawnlpe, _wspawnlpe](../c-runtime-library/reference/spawnlpe-wspawnlpe.md)|Criar e executar o novo processo usando a variável `PATH`, o ambiente especificado e a lista de argumentos|[System::Diagnostics::Process Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [System::Diagnostics::ProcessStartInfo Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[_spawnv, _wspawnv](../c-runtime-library/reference/spawnv-wspawnv.md)|Criar e executar o novo processo com a matriz de argumentos especificada|[System::Diagnostics::Process Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [System::Diagnostics::ProcessStartInfo Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[_spawnve, _wspawnve](../c-runtime-library/reference/spawnve-wspawnve.md)|Criar e executar o novo processo com a matriz de argumentos e o ambiente especificados|[System::Diagnostics::Process Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [System::Diagnostics::ProcessStartInfo Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[_spawnvp, _wspawnvp](../c-runtime-library/reference/spawnvp-wspawnvp.md)|Criar e executar o novo processo usando a variável `PATH` e a matriz de argumentos especificada|[System::Diagnostics::Process Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [System::Diagnostics::ProcessStartInfo Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[_spawnvpe, _wspawnvpe](../c-runtime-library/reference/spawnvpe-wspawnvpe.md)|Criar e executar o novo processo usando a variável `PATH`, o ambiente especificado e a matriz de argumentos|[System::Diagnostics::Process Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [System::Diagnostics::ProcessStartInfo Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[system, _wsystem](../c-runtime-library/reference/system-wsystem.md)|Executar o comando do sistema operacional|[System::Diagnostics::ProcessStartInfo Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx), [System::Diagnostics::Process Class](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx)|  
  
 No sistema operacional Windows, o processo gerado é equivalente ao processo de geração. Qualquer processo pode usar `_cwait` para aguardar outro processo para o qual a ID do processo é conhecida.  
  
 A diferença entre as famílias `_exec` e `_spawn` é que uma função `_spawn` pode retornar o controle do novo processo para o processo de chamada. Em uma função `_spawn`, o processo de chamada e o novo processo estão presentes na memória, a menos que `_P_OVERLAY` seja especificado. Em uma função `_exec`, o novo processo se sobrepõe ao processo de chamada, para que o controle não retorne ao processo de chamada a menos que ocorra um erro ao tentar iniciar a execução do novo processo.  
  
 As diferenças entre as funções na família `_exec`, bem como entre aquelas da família `_spawn`, envolvem o método de localização do arquivo a ser executado como o novo processo, o formulário no qual os argumentos são passados para o novo processo e o método de configuração do ambiente, conforme mostra a tabela a seguir. Use uma função que passa uma lista de argumentos quando o número de argumentos for constante ou conhecido no momento da compilação. Use uma função que passa um ponteiro para uma matriz contendo os argumentos quando o número de argumentos for determinado no tempo de execução. As informações na tabela a seguir também se aplicam aos equivalentes de caractere largo das funções `_spawn` e `_exec`.  
  
### <a name="spawn-and-exec-function-families"></a>Famílias _spawn e _exec Function  
  
|Funções|Use a variável PATH para localizar o arquivo|Convenção de passagem de argumentos|Configurações do ambiente|  
|---------------|--------------------------------------|----------------------------------|--------------------------|  
|`_execl, _spawnl`|Não|Lista|Herdado do processo de chamada|  
|`_execle, _spawnle`|Não|Lista|Ponteiro para a tabela de ambientes para o novo processo passado como o último argumento|  
|`_execlp, _spawnlp`|Sim|Lista|Herdado do processo de chamada|  
|`_execlpe, _spawnlpe`|Sim|Lista|Ponteiro para a tabela de ambientes para o novo processo passado como o último argumento|  
|`_execv, _spawnv`|Não|Matriz|Herdado do processo de chamada|  
|`_execve, _spawnve`|Não|Matriz|Ponteiro para a tabela de ambientes para o novo processo passado como o último argumento|  
|`_execvp, _spawnvp`|Sim|Matriz|Herdado do processo de chamada|  
|`_execvpe, _spawnvpe`|Sim|Matriz|Ponteiro para a tabela de ambientes para o novo processo passado como o último argumento|  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)
