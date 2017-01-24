---
title: "_putenv, _wputenv | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_putenv"
  - "_wputenv"
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
  - "api-ms-win-crt-environment-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_tputenv"
  - "_wputenv"
  - "_putenv"
  - "wputenv"
  - "tputenv"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _putenv"
  - "Função _tputenv"
  - "Função _wputenv"
  - "variáveis de ambiente, criando"
  - "variáveis de ambiente, excluindo"
  - "variáveis de ambiente, modificando"
  - "Função putenv"
  - "Função tputenv"
  - "Função wputenv"
ms.assetid: 9ba9b7fd-276e-45df-8420-d70c4204b8bd
caps.latest.revision: 22
caps.handback.revision: 22
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _putenv, _wputenv
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Cria, modifica ou remove variáveis de ambiente.  Versões mais seguras dessas funções estão disponíveis; consulte [\_putenv\_s, \_wputenv\_s](../../c-runtime-library/reference/putenv-s-wputenv-s.md).  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos que executam no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int _putenv(  
   const char *envstring   
);  
int _wputenv(  
   const wchar_t *envstring   
);  
```  
  
#### Parâmetros  
 `envstring`  
 Definição de cadeia de caracteres.  
  
## Valor de retorno  
 Retornar 0 se tiver êxito ou – 1 em caso de erro.  
  
## Comentários  
 A função `_putenv` adiciona novas variáveis de ambiente ou modifica os valores de variáveis de ambiente existentes.  As variáveis de ambiente definem o ambiente em que um processo é executado \(por exemplo, o caminho de pesquisa padrão para que as bibliotecas sejam vinculadas com um programa\).  `_wputenv` é uma versão de caractere longo de `_putenv`; o argumento `envstring` para `_wputenv` é uma cadeia de caractere longo.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tputenv`|`_putenv`|`_putenv`|`_wputenv`|  
  
 O argumento `envstring` deve ser um ponteiro para uma cadeia de caracteres do formulário `varname=string`, onde `varname` corresponde ao nome da variável de ambiente a ser adicionada ou modificada e `string` corresponde ao valor da variável.  Se `varname` já for parte do ambiente, seu valor é substituído por `string`; caso contrário, a nova variável de `varname` e seu valor de `string` são adicionados ao ambiente.  Você pode remover uma variável do ambiente especificando um `string` vazia — ou seja, especificando somente `varname=`.  
  
 `_putenv` e `_wputenv` afetam somente o ambiente do local para o processo atual; não é possível usá\-los para modificar o ambiente no nível de comando.  Isto é, essas funções operam somente em estruturas de dados acessíveis à biblioteca em tempo de execução e não no segmento de ambiente criado para um processo pelo sistema operacional.  Quando o processo atual é finalizado, o ambiente é revertido para o nível do processo de chamada \(na maioria dos casos, o nível do sistema operacional\).  No entanto, o ambiente alterado pode ser passado para todos os novos processos criados por `_spawn`, por `_exec`, ou por `system`, e esses novos processos obtêm quaisquer novos itens adicionados por `_putenv` e por `_wputenv`.  
  
 Não altere uma entrada de ambiente diretamente: em vez disso, use `_putenv` ou `_wputenv` para mudá\-la.  Em particular, liberar diretamente os elementos da matriz global `_environ[]` poderá fazer com que memória inválida seja endereçada.  
  
 `getenv` e `_putenv` usam a variável global `_environ` para acessar a tabela de ambiente; `_wgetenv` e `_wputenv` usam `_wenviron`.  `_putenv` e `_wputenv` podem alterar o valor de `_environ` e `_wenviron`, invalidando, assim, o argumento de `_envp` para `main` e o argumento de \_`wenvp` para `wmain`.  Portanto, é mais seguro usar `_environ` ou `_wenviron` para acessar informações de ambiente.  Para obter mais informações sobre a relação de `_putenv` e de `_wputenv` com as variáveis globais, consulte [\_environ, \_wenviron](../../c-runtime-library/environ-wenviron.md).  
  
> [!NOTE]
>  As famílias de funções `_putenv` e `_getenv` não são thread\-safe.  `_getenv` pode retornar um ponteiro de cadeia de caracteres quando `_putenv` está modificando a cadeia de caracteres, causando falhas aleatórios.  Certifique\-se de que as chamadas para essas funções sejam sincronizadas.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_putenv`|\<stdlib.h\>|  
|`_wputenv`|\<stdlib.h\> ou \<wchar.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
 Para um exemplo de como usar `_putenv`, consulte [getenv, \_wgetenv](../../c-runtime-library/reference/getenv-wgetenv.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Processo e controle de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [getenv, \_wgetenv](../../c-runtime-library/reference/getenv-wgetenv.md)   
 [\_searchenv, \_wsearchenv](../../c-runtime-library/reference/searchenv-wsearchenv.md)