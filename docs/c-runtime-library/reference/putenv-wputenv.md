---
title: _putenv, _wputenv | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _putenv
- _wputenv
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
- api-ms-win-crt-environment-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _tputenv
- _wputenv
- _putenv
- wputenv
- tputenv
dev_langs:
- C++
helpviewer_keywords:
- _putenv function
- environment variables, deleting
- putenv function
- tputenv function
- environment variables, creating
- wputenv function
- _wputenv function
- _tputenv function
- environment variables, modifying
ms.assetid: 9ba9b7fd-276e-45df-8420-d70c4204b8bd
caps.latest.revision: 22
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: a82768750e6a7837bb81edd8a51847f83c294c20
ms.openlocfilehash: d91f7b780c8f17fbe1e12a195b6a7cf2eaad3d2f
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="putenv-wputenv"></a>_putenv, _wputenv
Cria, modifica ou remove as variáveis de ambiente. Versões mais seguras dessas funções estão disponíveis; consulte [_putenv_s, _wputenv_s](../../c-runtime-library/reference/putenv-s-wputenv-s.md).  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _putenv(  
   const char *envstring   
);  
int _wputenv(  
   const wchar_t *envstring   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `envstring`  
 Definição de cadeia de caracteres de ambiente.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna 0 se for bem-sucedido ou -1 em caso de erro.  
  
## <a name="remarks"></a>Comentários  
 A função `_putenv` adiciona novas variáveis de ambiente ou modifica os valores de variáveis de ambiente existentes. Variáveis de ambiente definem o ambiente no qual um processo é executado (por exemplo, o caminho de pesquisa padrão para bibliotecas a ser vinculado a um programa). A função `_wputenv` é uma versão de caractere largo da função `_putenv`; o argumento `envstring` para `_wputenv` é uma cadeia de caracteres larga.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_tputenv`|`_putenv`|`_putenv`|`_wputenv`|  
  
 O argumento `envstring` deve ser um ponteiro para uma cadeia de caracteres no formato `varname=string`, em que `varname` é o nome da variável de ambiente a ser adicionada ou modificada e `string` é o valor da variável. Se `varname` já fizer parte do ambiente, seu valor será substituído por `string`; caso contrário, a nova variável `varname` e seu valor `string` serão adicionados ao ambiente. Você pode remover uma variável do ambiente especificando uma cadeia de caracteres vazia `string`, em outras palavras, especificando apenas `varname=`.  
  
 `_putenv` e `_wputenv` afetam apenas o ambiente local para o processo atual; você não pode usá-las para modificar o ambiente no nível de comando. Isso é, essas funções operam somente nas estruturas de dados que são acessíveis para a biblioteca em tempo de execução e não no segmento de ambiente criado para um processo pelo sistema operacional. Quando o processo atual termina, o ambiente é revertido para o nível do processo de chamada (que, na maioria dos casos, é o nível do sistema operacional). No entanto, o ambiente modificado pode ser passado para novos processos criados por `_spawn`, `_exec` ou `system` e esses novos processos obtém os novos itens que são adicionados por `_putenv` e `_wputenv`.  
  
 Não altere uma entrada de ambiente diretamente. Em vez disso, use `_putenv` ou `_wputenv` para alterá-la. Em especial, liberar elementos da matriz global `_environ[]` diretamente pode fazer com que a memória inválida seja resolvida.  
  
 `getenv` e `_putenv` usam a variável global `_environ` para acessar a tabela de ambiente; `_wgetenv` e `_wputenv` usam `_wenviron`. `_putenv`e `_wputenv` pode alterar o valor de `_environ` e `_wenviron`, invalidação, portanto, o `_envp` argumento `main` e o `_wenvp` argumento `wmain`. Portanto, é mais seguro usar `_environ` ou `_wenviron` para acessar as informações de ambiente. Para obter mais informações sobre a relação de `_putenv` e `_wputenv` com as variáveis globais, consulte [_environ, _wenviron](../../c-runtime-library/environ-wenviron.md).  
  
> [!NOTE]
>  As famílias de funções `_putenv` e `_getenv` não são thread-safe. `_getenv` poderia retornar um ponteiro de cadeia de caracteres enquanto `_putenv` está modificando a cadeia de caracteres, causando falhas aleatórias. As chamadas para essas funções devem estar sincronizadas.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_putenv`|\<stdlib.h>|  
|`_wputenv`|\<stdlib.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
 Para ver uma amostra de como usar `_putenv`, consulte [getenv, _wgetenv](../../c-runtime-library/reference/getenv-wgetenv.md).  
  
## <a name="see-also"></a>Consulte também  
 [Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [getenv, _wgetenv](../../c-runtime-library/reference/getenv-wgetenv.md)   
 [_searchenv, _wsearchenv](../../c-runtime-library/reference/searchenv-wsearchenv.md)
