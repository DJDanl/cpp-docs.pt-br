---
title: "_putenv_s, _wputenv_s | Microsoft Docs"
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
  - "_wputenv_s"
  - "_putenv_s"
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
apitype: "DLLExport"
f1_keywords: 
  - "putenv_s"
  - "wputenv_s"
  - "_wputenv_s"
  - "_putenv_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _putenv_s"
  - "Função _wputenv_s"
  - "variáveis de ambiente, criando"
  - "variáveis de ambiente, excluindo"
  - "variáveis de ambiente, modificando"
  - "Função putenv_s"
  - "Função wputenv_s"
ms.assetid: fbf51225-a8da-4b9b-9d7c-0b84ef72df18
caps.latest.revision: 20
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _putenv_s, _wputenv_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Cria, modifica ou remove as variáveis de ambiente.  Essas são versões de [\_putenv, \_wputenv](../../c-runtime-library/reference/putenv-wputenv.md) mas tem aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
> [!IMPORTANT]
>  Essa API não pode ser usada em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  Para obter mais informações, consulte [Funções de CRT sem suporte com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
errno_t _putenv_s(  
   const char *name,  
   const char *value   
);  
errno_t _wputenv_s(  
   const wchar_t *name,  
   const wchar_t *value  
);  
```  
  
#### Parâmetros  
 `name`  
 O nome da variável de ambiente.  
  
 `value`  
 O valor para definir a variável de ambiente.  
  
## Valor de retorno  
 Retorna 0 se for bem\-sucedido, ou um código de erro.  
  
### Condições de erro  
  
|`name`|`value`|Valor de retorno|  
|------------|-------------|----------------------|  
|`NULL`|qualquer|`EINVAL`|  
|qualquer|`NULL`|`EINVAL`|  
  
 Se uma das condições de erro ocorrer, essas funções chamar um manipulador de parâmetro inválido, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções retornarão `EINVAL` e definirão `errno` para `EINVAL`.  
  
## Comentários  
 O `_putenv_s` função adiciona novas variáveis de ambiente ou modifica os valores das variáveis de ambiente existente.  Variáveis de ambiente definem o ambiente no qual um processo executado \(por exemplo, o caminho de pesquisa padrão para bibliotecas a serem vinculadas com um programa\).  A função `_wputenv_s` é uma versão de caractere largo da função `_putenv_s`; o argumento `envstring` para `_wputenv_s` é uma cadeia de caracteres larga.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tputenv_s`|`_putenv_s`|`_putenv_s`|`_wputenv_s`|  
  
 `name` é o nome da variável de ambiente a ser adicionado ou modificado e `value` é o valor da variável.  Se `name` já faz parte do ambiente, seu valor é substituído pelo `value`; caso contrário, o novo `name` variável e seu `value` são adicionadas ao ambiente.  Você pode remover uma variável de ambiente especificando uma cadeia de caracteres vazia \(isto é, ""\) para `value`.  
  
 `_putenv_s` e `_wputenv_s` afetam somente o ambiente local para o processo atual; você não pode usá\-las para alterar o ambiente de nível de comando.  Essas funções operam apenas em estruturas de dados que são acessíveis para a biblioteca de tempo de execução e não no ambiente de "segmento", o sistema operacional cria um processo.  Quando termina o processo atual, o ambiente será revertido para o nível do processo de chamada, que, na maioria dos casos, é o nível de sistema operacional.  No entanto, o ambiente modificado pode ser passado para novos processos criados por `_spawn`, `_exec`, ou `system`, e esses novos processos obtém quaisquer novos itens são adicionados por `_putenv_s` e `_wputenv_s`.  
  
 Não altere uma entrada de ambiente diretamente. em vez disso, use `_putenv_s` ou `_wputenv_s` para alterá\-lo.  Em particular, liberando diretamente elementos da `_environ[]` matriz global pode causar a memória inválida a serem resolvidos.  
  
 `getenv` e `_putenv_s` usar a variável global `_environ` para acessar a tabela de ambiente; `_wgetenv` e `_wputenv_s` usar `_wenviron`.  `_putenv_s` e `_wputenv_s` pode alterar o valor de `_environ` e `_wenviron`, e, portanto, invalidar o `envp` argumento para `main` e o `_wenvp` argumento `wmain`.  Portanto, é mais seguro usar `_environ` ou `_wenviron` para acessar as informações de ambiente.  Para obter mais informações sobre a relação entre `_putenv_s` e `_wputenv_s` variáveis globais, consulte [\_environ, \_wenviron](../../c-runtime-library/environ-wenviron.md).  
  
> [!NOTE]
>  O `_putenv_s` e `_getenv_s` famílias de funções não são thread\-safe.  `_getenv_s` pode retornar um ponteiro de cadeia de caracteres ao `_putenv_s` é modificar a cadeia de caracteres e, portanto, causar falhas aleatórias.  Certifique\-se de que as chamadas para essas funções estão sincronizadas.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_putenv_s`|\<stdlib.h\>|  
|`_wputenv_s`|\<stdlib.h\> ou \<wchar.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
 Para obter um exemplo que mostra como usar `_putenv_s`, consulte [getenv\_s, \_wgetenv\_s](../../c-runtime-library/reference/getenv-s-wgetenv-s.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Processo e controle de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [getenv, \_wgetenv](../../c-runtime-library/reference/getenv-wgetenv.md)   
 [\_searchenv, \_wsearchenv](../../c-runtime-library/reference/searchenv-wsearchenv.md)