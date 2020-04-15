---
title: _putenv_s, _wputenv_s
ms.date: 4/2/2020
api_name:
- _wputenv_s
- _putenv_s
- _o__putenv_s
- _o__wputenv_s
api_location:
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
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- putenv_s
- wputenv_s
- _wputenv_s
- _putenv_s
helpviewer_keywords:
- wputenv_s function
- _putenv_s function
- environment variables, deleting
- putenv_s function
- _wputenv_s function
- environment variables, creating
- environment variables, modifying
ms.assetid: fbf51225-a8da-4b9b-9d7c-0b84ef72df18
ms.openlocfilehash: f0164feed05b409ba29ca713f11f4f3323dbaac3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81338397"
---
# <a name="_putenv_s-_wputenv_s"></a>_putenv_s, _wputenv_s

Cria, modifica ou remove as variáveis de ambiente. Essas são versões de [_putenv, _wputenv](putenv-wputenv.md), mas têm melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t _putenv_s(
   const char *varname,
   const char *value_string
);
errno_t _wputenv_s(
   const wchar_t *varname,
   const wchar_t *value_string
);
```

### <a name="parameters"></a>Parâmetros

*Varname*<br/>
O nome da variável de ambiente.

*value_string*<br/>
O valor a ser definido para a variável de ambiente.

## <a name="return-value"></a>Valor retornado

Retorna 0 se for bem-sucedido ou um código de erro.

### <a name="error-conditions"></a>Condições de erro

|*Varname*|*value_string*|Valor retornado|
|------------|-------------|------------------|
|**NULO**|any|**Einval**|
|any|**NULO**|**Einval**|

Se uma das condições de erro ocorrer, essas funções invocarão um manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, essas funções retornam **eINVAL** e definem **errno** para **EINVAL**.

## <a name="remarks"></a>Comentários

A função **_putenv_s** adiciona novas variáveis de ambiente ou modifica os valores das variáveis de ambiente existentes. Variáveis de ambiente definem o ambiente no qual um processo é executado (por exemplo, o caminho de pesquisa padrão para bibliotecas a ser vinculado a um programa). **_wputenv_s** é uma versão ampla de **_putenv_s;** o argumento *de envstring* para **_wputenv_s** é uma seqüência de caracteres amplo.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tputenv_s**|**_putenv_s**|**_putenv_s**|**_wputenv_s**|

*varname* é o nome da variável de ambiente a ser adicionada ou modificada e *value_string* é o valor da variável. Se *o varname* já faz parte do ambiente, seu valor é substituído por *value_string;* caso contrário, a nova variável *varname* e seus *value_string* são adicionados ao ambiente. Você pode remover uma variável do ambiente especificando uma seqüência de string vazia (ou seja, "") para *value_string*.

**_putenv_s** e **_wputenv_s** afetam apenas o ambiente local ao processo atual; você não pode usá-los para modificar o ambiente de nível de comando. Essas funções operam somente nas estruturas de dados que são acessíveis para a biblioteca em tempo de execução e não no “segmento” de ambiente que o sistema operacional cria para um processo. Quando o processo atual termina, o ambiente será revertido para o nível do processo de chamada, que, na maioria dos casos, é o nível do sistema operacional. No entanto, o ambiente modificado pode ser passado para quaisquer novos processos que sejam criados por **_spawn,** **_exec**ou **sistema,** e esses novos processos recebem novos itens que são adicionados por **_putenv_s** e **_wputenv_s**.

Não altere uma entrada de ambiente diretamente; em vez disso, use **_putenv_s** ou **_wputenv_s** para mudá-lo. Em particular, elementos de libertação direta da matriz global **_environ[]** pode fazer com que a memória inválida seja endereçada.

**getenv** e **_putenv_s** usar a variável global **_environ** para acessar a tabela do ambiente; **_wgetenv** e **_wputenv_s** **uso _wenviron**. **_putenv_s** e **_wputenv_s** podem alterar o valor de **_environ** e **_wenviron**e, assim, invalidar o argumento *envp* para **principal** e o **argumento _wenvp** para **wmain**. Portanto, é mais seguro usar **_environ** ou **_wenviron** para acessar as informações do ambiente. Para obter mais informações sobre a relação de **_putenv_s** e **_wputenv_s** com variáveis globais, consulte [_environ, _wenviron](../../c-runtime-library/environ-wenviron.md).

> [!NOTE]
> As **_putenv_s** e **_getenv_s** famílias de funções não são seguras para fios. **_getenv_s** pode retornar um ponteiro de seqüência enquanto **_putenv_s** está modificando a seqüência e, assim, causar falhas aleatórias. As chamadas para essas funções devem estar sincronizadas.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_putenv_s**|\<stdlib.h>|
|**_wputenv_s**|\<stdlib.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Para obter uma amostra que mostre como usar **_putenv_s,** consulte [getenv_s, _wgetenv_s](getenv-s-wgetenv-s.md).

## <a name="see-also"></a>Confira também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[getenv, _wgetenv](getenv-wgetenv.md)<br/>
[_searchenv, _wsearchenv](searchenv-wsearchenv.md)<br/>
