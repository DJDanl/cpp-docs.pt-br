---
title: "Processo e controle de ambiente | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "c.programs"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "rotinas de controle de ambiente"
  - "processo pai"
  - "rotinas de controle de processo"
  - "processos, tarefas administrativas"
  - "processos, iniciando"
  - "processos, parando"
ms.assetid: 7fde74c3-c2a6-4d15-84b8-092160d60c3e
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Processo e controle de ambiente
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use as rotinas controle de processo para iniciar, parar, e gerenciar processos do programa.  Use as rotinas de ambiente\- controle para obter e modificar informações sobre o ambiente de sistema operacional.  
  
### Funções do processo e controle de ambiente  
  
|Rotina|Uso|Equivalente a .NET Framework|  
|------------|---------|----------------------------------|  
|[anular](../c-runtime-library/reference/abort.md)|O processo de anulação sem enviar buffers ou funções de chamada registrados por `atexit` e por `_onexit`|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[assert](../c-runtime-library/reference/assert-macro-assert-wassert.md)|Teste para o erro lógico|[\<caps:sentence id\="tgt14" sentenceid\="14fd9bf776829d73028df00162f7533f" class\="tgtSentence"\>System::Diagnostics::Debug::Assert\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.diagnostics.debug.assert.aspx)|  
|macros de[\_ASSERT, \_ASSERTE](../Topic/_ASSERT,%20_ASSERTE,%20_ASSERT_EXPR%20Macros.md)|Semelhante a, mas `assert`disponível somente nas versões de depuração das bibliotecas de tempo de execução|[\<caps:sentence id\="tgt17" sentenceid\="14fd9bf776829d73028df00162f7533f" class\="tgtSentence"\>System::Diagnostics::Debug::Assert\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.diagnostics.debug.assert.aspx)|  
|[atexit](../c-runtime-library/reference/atexit.md)|Rotinas da agenda para a execução no encerramento de programa|[\<caps:sentence id\="tgt20" sentenceid\="db022fa9aa2a12937c3610e3eb32e80f" class\="tgtSentence"\>System::Diagnostics::Process::Exited\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.exited.aspx)|  
|[\_beginthread, \_beginthreadex](../Topic/_beginthread,%20_beginthreadex.md)|Crie um novo thread em um processo do sistema operacional Windows|[\<caps:sentence id\="tgt23" sentenceid\="221e38ecc6535bce91af4e1a19f464d1" class\="tgtSentence"\>System::Threading::Thread::Start\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.threading.thread.start.aspx)|  
|[\_cexit](../c-runtime-library/reference/cexit-c-exit.md)|Executar procedimentos de término de `exit` \(como liberar buffers\), então retornará o controle ao programa de chamada sem finalizar o processo|[\<caps:sentence id\="tgt26" sentenceid\="46302f19d05c09c5875a795cb64800f9" class\="tgtSentence"\>System::Diagnostics::Process::CloseMainWindow\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.closemainwindow.aspx)|  
|[\_c\_exit](../c-runtime-library/reference/cexit-c-exit.md)|Executar procedimentos de término de `_exit` , então retornará o controle ao programa de chamada sem finalizar o processo|[\<caps:sentence id\="tgt29" sentenceid\="46302f19d05c09c5875a795cb64800f9" class\="tgtSentence"\>System::Diagnostics::Process::CloseMainWindow\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.closemainwindow.aspx)|  
|[\_cwait](../c-runtime-library/reference/cwait.md)|Espere até que outro processo termina|[\<caps:sentence id\="tgt32" sentenceid\="d9c88c429eaacaa9f37d91d29bc6504e" class\="tgtSentence"\>System::Diagnostics::Process::WaitForExit\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.waitforexit.aspx)|  
|[\_endthread, \_endthreadex](../Topic/_endthread,%20_endthreadex.md)|Encerrar um thread do sistema operacional Windows|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_execl, \_wexecl](../Topic/_execl,%20_wexecl.md)|Executar o novo processo com a lista de argumentos|[Classe de System::Diagnostics::Process](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [Classe de System::Diagnostics::ProcessStartInfo](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[\_execle, \_wexecle](../c-runtime-library/reference/execle-wexecle.md)|Executar o novo processo com a lista de argumentos e ambiente específico|[Classe de System::Diagnostics::Process](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [Classe de System::Diagnostics::ProcessStartInfo](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[\_execlp, \_wexeclp](../c-runtime-library/reference/execlp-wexeclp.md)|Executar o novo processo usando uma variável de `PATH` e a lista de argumentos|[Classe de System::Diagnostics::Process](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [Classe de System::Diagnostics::ProcessStartInfo](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[\_execlpe, \_wexeclpe](../c-runtime-library/reference/execlpe-wexeclpe.md)|Executar o novo processo usando uma variável de `PATH` , dado o ambiente, e a lista de argumentos|[Classe de System::Diagnostics::Process](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [Classe de System::Diagnostics::ProcessStartInfo](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[\_execv, \_wexecv](../c-runtime-library/reference/execv-wexecv.md)|Executar o novo processo com matriz de argumentos|[Classe de System::Diagnostics::Process](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [Classe de System::Diagnostics::ProcessStartInfo](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[\_execve, \_wexecve](../c-runtime-library/reference/execve-wexecve.md)|Executar o novo processo com matriz de argumentos e ambiente específico|[Classe de System::Diagnostics::Process](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [Classe de System::Diagnostics::ProcessStartInfo](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[\_execvp, \_wexecvp](../c-runtime-library/reference/execvp-wexecvp.md)|Executar o novo processo usando uma variável de `PATH` e a matriz de argumentos|[Classe de System::Diagnostics::Process](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [Classe de System::Diagnostics::ProcessStartInfo](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[\_execvpe, \_wexecvpe](../Topic/_execvpe,%20_wexecvpe.md)|Executar o novo processo usando uma variável de `PATH` , dado o ambiente, e a matriz de argumentos|[Classe de System::Diagnostics::Process](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [Classe de System::Diagnostics::ProcessStartInfo](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[saída](../c-runtime-library/reference/exit-exit-exit.md)|As funções de chamada registradas por `atexit` e `_onexit`, liberar todos os buffers, fechará todos os arquivos abertos, e finalizam o processo|[\<caps:sentence id\="tgt64" sentenceid\="811a70e90f150f212690505b37a46c0f" class\="tgtSentence"\>System::Diagnostics::Process::Kill\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.kill.aspx)|  
|[\_exit](../c-runtime-library/reference/exit-exit-exit.md)|Término do processo imediatamente sem chamar `atexit` ou `_onexit` ou liberar buffers|[\<caps:sentence id\="tgt67" sentenceid\="811a70e90f150f212690505b37a46c0f" class\="tgtSentence"\>System::Diagnostics::Process::Kill\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.kill.aspx)|  
|[getenv, \_wgetenv](../c-runtime-library/reference/getenv-wgetenv.md), [getenv\_s, \_wgetenv\_s](../c-runtime-library/reference/getenv-s-wgetenv-s.md)|Obter o valor da variável de ambiente|[\<caps:sentence id\="tgt70" sentenceid\="795988b9277d74ea3b722ecd42dcb29d" class\="tgtSentence"\>System::Environment::GetEnvironmentVariable\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.environment.getenvironmentvariable.aspx)|  
|[\_getpid](../Topic/_getpid.md)|Obter o número de identificação do processo|[\<caps:sentence id\="tgt73" sentenceid\="745b82c461dc74b15540e9622f7cd7bd" class\="tgtSentence"\>System::Diagnostics::Process::Id\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.id.aspx)|  
|[longjmp](../c-runtime-library/reference/longjmp.md)|Ambiente salvo restauração de pilha; use o para executar `goto`nonlocal|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_onexit](../c-runtime-library/reference/onexit-onexit-m.md)|Rotinas da agenda para a execução no encerramento de programa; use para compatibilidade com a versão 7,0 do Microsoft C\/C\+\+ e anterior|[\<caps:sentence id\="tgt81" sentenceid\="db022fa9aa2a12937c3610e3eb32e80f" class\="tgtSentence"\>System::Diagnostics::Process::Exited\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.exited.aspx)|  
|[\_pclose](../Topic/_pclose.md)|Aguarde o novo processador de comando e feche o fluxo para o pipe associado|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[perror, \_wperror](../c-runtime-library/reference/perror-wperror.md)|Mensagem de erro de cópia|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_pipe](../c-runtime-library/reference/pipe.md)|Crie o pipe para ler e gravar|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_popen, \_wpopen](../c-runtime-library/reference/popen-wpopen.md)|Crie o pipe e execute o comando|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_putenv, \_wputenv](../c-runtime-library/reference/putenv-wputenv.md), [\_putenv\_s, \_wputenv\_s](../c-runtime-library/reference/putenv-s-wputenv-s.md)|Adicionar ou alterar o valor da variável de ambiente|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[gerar](../c-runtime-library/reference/raise.md)|Enviar o sinal para o processo de chamada|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[setjmp](../c-runtime-library/reference/setjmp.md)|Salve o ambiente de pilha; use o para executar `goto`não local|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[sinal](../c-runtime-library/reference/signal.md)|Sinal de interrupção de identificador|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_spawnl, \_wspawnl](../Topic/_spawnl,%20_wspawnl.md)|Criar e executar o novo processo com a lista de argumentos especificada|[Classe de System::Diagnostics::Process](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [Classe de System::Diagnostics::ProcessStartInfo](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[\_spawnle, \_wspawnle](../c-runtime-library/reference/spawnle-wspawnle.md)|Criar e executar o novo processo com a lista de argumentos especificados e ambiente|[Classe de System::Diagnostics::Process](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [Classe de System::Diagnostics::ProcessStartInfo](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[\_spawnlp, \_wspawnlp](../c-runtime-library/reference/spawnlp-wspawnlp.md)|Criar e executar o novo processo usando uma variável de `PATH` e a lista de argumentos especificada|[Classe de System::Diagnostics::Process](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [Classe de System::Diagnostics::ProcessStartInfo](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[\_spawnlpe, \_wspawnlpe](../Topic/_spawnlpe,%20_wspawnlpe.md)|Criar e executar o novo processo usando uma variável de `PATH` , o ambiente especificado, e a lista de argumentos|[Classe de System::Diagnostics::Process](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [Classe de System::Diagnostics::ProcessStartInfo](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[\_spawnv, \_wspawnv](../c-runtime-library/reference/spawnv-wspawnv.md)|Criar e executar o novo processo com matriz especificada do argumento|[Classe de System::Diagnostics::Process](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [Classe de System::Diagnostics::ProcessStartInfo](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[\_spawnve, \_wspawnve](../c-runtime-library/reference/spawnve-wspawnve.md)|Criar e executar o novo processo com matriz especificada de ambiente e o argumento|[Classe de System::Diagnostics::Process](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [Classe de System::Diagnostics::ProcessStartInfo](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[\_spawnvp, \_wspawnvp](../c-runtime-library/reference/spawnvp-wspawnvp.md)|Criar e executar o novo processo usando uma variável de `PATH` e a matriz especificada do argumento|[Classe de System::Diagnostics::Process](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [Classe de System::Diagnostics::ProcessStartInfo](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[\_spawnvpe, \_wspawnvpe](../Topic/_spawnvpe,%20_wspawnvpe.md)|Criar e executar o novo processo usando uma variável de `PATH` , o ambiente especificado, e a matriz de argumentos|[Classe de System::Diagnostics::Process](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx), [Classe de System::Diagnostics::ProcessStartInfo](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx)|  
|[o sistema, \_wsystem](../c-runtime-library/reference/system-wsystem.md)|Execute o comando de sistema operacional|[Classe de System::Diagnostics::ProcessStartInfo](https://msdn.microsoft.com/en-us/library/system.diagnostics.processstartinfo.aspx), [Classe de System::Diagnostics::Process](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.aspx)|  
  
 No sistema operacional Windows, o processo gerado é equivalente ao processo desovando.  Qualquer processo pode usar `_cwait` para aguardar qualquer outro processo para que o ID de processo é conhecido.  
  
 A diferença entre `_exec` e famílias de `_spawn` que é uma função de `_spawn` pode devolver o controle do novo processo para o processo de chamada.  Em uma função de `_spawn` , o processo de chamada e o novo processo estão presentes na memória `_P_OVERLAY` a menos que seja especificado.  Em uma função de `_exec` , o novo processo será interrompido o processo de chamada, para que o controle não pode retornar para o processo de chamada a menos que um erro ocorrer na tentativa de iniciar a execução do novo processo.  
  
 As diferenças entre as funções da família de `_exec` , bem como entre essas da família de `_spawn` , envolvem o método de localizar o arquivo a ser executado como o novo processo, o formulário nos argumentos que são passados para o novo processo, e o método de definição do ambiente, como mostra a tabela a seguir.  Use uma função que transmite uma lista de argumento quando o número de argumentos é constante ou é conhecido em tempo de compilação.  Use uma função que transmite um ponteiro para uma matriz que contém os argumentos quando o número de casos deve ser determinada em tempo de execução.  As informações na tabela a seguir também se aplica a contraparte de ampla caractere das funções de `_spawn` e de `_exec` .  
  
### famílias da função de \_spawn e de \_exec  
  
|Funções|Use a variável PATH para localizar o arquivo|Convenção de passagem de argumentos|Configurações de ambiente|  
|-------------|--------------------------------------------------|-----------------------------------------|-------------------------------|  
|`_execl, _spawnl`|Não|Lista|Herdado do processo de chamada|  
|`_execle, _spawnle`|Não|Lista|O ponteiro para a tabela de ambiente para o novo processo passado como o último argumento|  
|`_execlp, _spawnlp`|Sim|Lista|Herdado do processo de chamada|  
|`_execlpe, _spawnlpe`|Sim|Lista|O ponteiro para a tabela de ambiente para o novo processo passado como o último argumento|  
|`_execv, _spawnv`|Não|Matriz|Herdado do processo de chamada|  
|`_execve, _spawnve`|Não|Matriz|O ponteiro para a tabela de ambiente para o novo processo passado como o último argumento|  
|`_execvp, _spawnvp`|Sim|Matriz|Herdado do processo de chamada|  
|`_execvpe, _spawnvpe`|Sim|Matriz|O ponteiro para a tabela de ambiente para o novo processo passado como o último argumento|  
  
## Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)