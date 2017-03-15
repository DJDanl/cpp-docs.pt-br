---
title: _putenv_s, _wputenv_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _wputenv_s
- _putenv_s
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
apitype: DLLExport
f1_keywords:
- putenv_s
- wputenv_s
- _wputenv_s
- _putenv_s
dev_langs:
- C++
helpviewer_keywords:
- wputenv_s function
- _putenv_s function
- environment variables, deleting
- putenv_s function
- _wputenv_s function
- environment variables, creating
- environment variables, modifying
ms.assetid: fbf51225-a8da-4b9b-9d7c-0b84ef72df18
caps.latest.revision: 20
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
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: b8db4c9aa0db780bf0cd0819be083c989ff29149
ms.lasthandoff: 02/25/2017

---
# <a name="putenvs-wputenvs"></a>_putenv_s, _wputenv_s
Cria, modifica ou remove as variáveis de ambiente. Essas são versões de [_putenv, _wputenv](../../c-runtime-library/reference/putenv-wputenv.md), mas têm melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
> [!IMPORTANT]
>  Essa API não pode ser usada em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)]. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/en-us/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `name`  
 O nome da variável de ambiente.  
  
 `value`  
 O valor a ser definido para a variável de ambiente.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna 0 se for bem-sucedido ou um código de erro.  
  
### <a name="error-conditions"></a>Condições de Erro  
  
|`name`|`value`|Valor retornado|  
|------------|-------------|------------------|  
|`NULL`|qualquer|`EINVAL`|  
|qualquer|`NULL`|`EINVAL`|  
  
 Se uma das condições de erro ocorrer, essas funções invocarão um manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão `EINVAL` e definirão `errno` para `EINVAL`.  
  
## <a name="remarks"></a>Comentários  
 A função `_putenv_s` adiciona novas variáveis de ambiente ou modifica os valores de variáveis de ambiente existentes. Variáveis de ambiente definem o ambiente no qual um processo é executado (por exemplo, o caminho de pesquisa padrão para bibliotecas a ser vinculado a um programa). A função `_wputenv_s` é uma versão de caractere largo da função `_putenv_s`; o argumento `envstring` para `_wputenv_s` é uma cadeia de caracteres larga.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tputenv_s`|`_putenv_s`|`_putenv_s`|`_wputenv_s`|  
  
 `name` é o nome da variável de ambiente a ser adicionada ou modificada e `value` é o valor da variável. Se `name` já fizer parte do ambiente, seu valor será substituído por `value`; caso contrário, a nova variável `name` e seu `value` são adicionadas ao ambiente. Você pode remover uma variável do ambiente especificando uma cadeia de caracteres vazia (isto é, "") para `value`.  
  
 `_putenv_s` e `_wputenv_s` afetam apenas o ambiente local para o processo atual; você não pode usá-las para modificar o ambiente no nível de comando. Essas funções operam somente nas estruturas de dados que são acessíveis para a biblioteca em tempo de execução e não no “segmento” de ambiente que o sistema operacional cria para um processo. Quando o processo atual termina, o ambiente será revertido para o nível do processo de chamada, que, na maioria dos casos, é o nível do sistema operacional. No entanto, o ambiente modificado pode ser passado para novos processos criados por `_spawn`, `_exec` ou `system` e esses novos processos obtém os novos itens que são adicionados por `_putenv_s` e `_wputenv_s`.  
  
 Não altere uma entrada de ambiente diretamente. Em vez disso, use `_putenv_s` ou `_wputenv_s` para alterá-la. Em especial, liberar elementos da matriz global `_environ[]` diretamente pode fazer com que a memória inválida seja resolvida.  
  
 `getenv` e `_putenv_s` usam a variável global `_environ` para acessar a tabela de ambiente; `_wgetenv` e `_wputenv_s` usam `_wenviron`. `_putenv_s` e `_wputenv_s` podem alterar o valor de `_environ` e `_wenviron`, invalidando, portanto, o argumento `envp` para `main` e o argumento `_wenvp` para `wmain`. Portanto, é mais seguro usar `_environ` ou `_wenviron` para acessar as informações de ambiente. Para obter mais informações sobre a relação de `_putenv_s` e `_wputenv_s` com as variáveis globais, consulte [_environ, _wenviron](../../c-runtime-library/environ-wenviron.md).  
  
> [!NOTE]
>  As famílias de funções `_putenv_s` e `_getenv_s` não são thread-safe. `_getenv_s` poderia retornar um ponteiro de cadeia de caracteres enquanto `_putenv_s` está modificando a cadeia de caracteres e, portanto, causar falhas aleatórias. As chamadas para essas funções devem estar sincronizadas.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_putenv_s`|\<stdlib.h>|  
|`_wputenv_s`|\<stdlib.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
 Para ver uma amostra que mostra como usar `_putenv_s`, consulte [getenv_s, _wgetenv_s](../../c-runtime-library/reference/getenv-s-wgetenv-s.md).  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [getenv, _wgetenv](../../c-runtime-library/reference/getenv-wgetenv.md)   
 [_searchenv, _wsearchenv](../../c-runtime-library/reference/searchenv-wsearchenv.md)
