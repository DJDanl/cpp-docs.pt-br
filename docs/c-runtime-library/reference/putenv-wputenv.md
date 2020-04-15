---
title: _putenv, _wputenv
ms.date: 4/2/2020
api_name:
- _putenv
- _wputenv
- _o__putenv
- _o__wputenv
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
- _tputenv
- _wputenv
- _putenv
- wputenv
- tputenv
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
ms.openlocfilehash: 3e74959e6c6cdb2e27ce0d68ba40d02d64949904
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81333038"
---
# <a name="_putenv-_wputenv"></a>_putenv, _wputenv

Cria, modifica ou remove as variáveis de ambiente. Versões mais seguras dessas funções estão disponíveis; consulte [_putenv_s, _wputenv_s](putenv-s-wputenv-s.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _putenv(
   const char *envstring
);
int _wputenv(
   const wchar_t *envstring
);
```

### <a name="parameters"></a>Parâmetros

*envstring*<br/>
Definição de cadeia de caracteres de ambiente.

## <a name="return-value"></a>Valor retornado

Retornar 0 se for bem sucedido ou -1 em caso de erro.

## <a name="remarks"></a>Comentários

A função **_putenv** adiciona novas variáveis de ambiente ou modifica os valores das variáveis de ambiente existentes. Variáveis de ambiente definem o ambiente no qual um processo é executado (por exemplo, o caminho de pesquisa padrão para bibliotecas a ser vinculado a um programa). **_wputenv** é uma versão ampla de **_putenv;** o argumento *de envstring* para **_wputenv** é uma seqüência de caracteres amplo.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tputenv**|**_putenv**|**_putenv**|**_wputenv**|

O argumento *envstring* deve ser um ponteiro para uma seqüência do formulário *varname*=*value_string*, onde *varname* é o nome da variável ambiente a ser adicionado ou modificado e *value_string* é o valor da variável. Se *o varname* já faz parte do ambiente, seu valor é substituído por *value_string;* caso contrário, a nova variável *varname* e seu *valor value_string* são adicionados ao ambiente. Você pode remover uma variável do ambiente especificando uma *value_string*vazia , ou em outras palavras, especificando apenas *varname*=.

**_putenv** e **_wputenv** afetam apenas o ambiente local ao processo atual; você não pode usá-los para modificar o ambiente de nível de comando. Isso é, essas funções operam somente nas estruturas de dados que são acessíveis para a biblioteca em tempo de execução e não no segmento de ambiente criado para um processo pelo sistema operacional. Quando o processo atual termina, o ambiente é revertido para o nível do processo de chamada (que, na maioria dos casos, é o nível do sistema operacional). No entanto, o ambiente modificado pode ser passado para quaisquer novos processos criados por **_spawn,** **_exec**ou **sistema,** e esses novos processos recebem novos itens adicionados por **_putenv** e **_wputenv.**

Não altere uma entrada de ambiente diretamente: em vez disso, use **_putenv** ou **_wputenv** para alterá-lo. Em particular, elementos de libertação direta da matriz global **_environ[]** podem levar a que a memória inválida seja endereçada.

**getenv** e **_putenv** usar a variável global **_environ** para acessar a tabela do ambiente; **_wgetenv** e **_wputenv** **_wenviron**de uso . **_putenv** e **_wputenv** podem alterar o valor de **_environ** e **_wenviron,** invalidando assim o argumento **_envp** para **o principal** e **o** _wenvp argumento para **wmain**. Portanto, é mais seguro usar **_environ** ou **_wenviron** para acessar as informações do ambiente. Para obter mais informações sobre a relação de **_putenv** e **_wputenv** com variáveis globais, consulte [_environ, _wenviron](../../c-runtime-library/environ-wenviron.md).

> [!NOTE]
> As **_putenv** e **_getenv** famílias de funções não são seguras para fios. **_getenv** pode retornar um ponteiro de seqüência enquanto **_putenv** está modificando a seqüência, causando falhas aleatórias. As chamadas para essas funções devem estar sincronizadas.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_putenv**|\<stdlib.h>|
|**_wputenv**|\<stdlib.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Para obter uma amostra de como usar **_putenv**, consulte [getenv, _wgetenv](getenv-wgetenv.md).

## <a name="see-also"></a>Confira também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[getenv, _wgetenv](getenv-wgetenv.md)<br/>
[_searchenv, _wsearchenv](searchenv-wsearchenv.md)<br/>
