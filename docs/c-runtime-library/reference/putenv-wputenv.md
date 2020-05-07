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
- api-ms-win-crt-private-l1-1-0.dll
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
ms.openlocfilehash: a86b58b868c96b6f77af8bfa32036d1a56b2a7cf
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82918863"
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

Retorne 0 se for bem-sucedido ou-1 no caso de um erro.

## <a name="remarks"></a>Comentários

A função **_putenv** adiciona novas variáveis de ambiente ou modifica os valores das variáveis de ambiente existentes. Variáveis de ambiente definem o ambiente no qual um processo é executado (por exemplo, o caminho de pesquisa padrão para bibliotecas a ser vinculado a um programa). **_wputenv** é uma versão de caractere largo do **_putenv**; o argumento *envstring* para **_wputenv** é uma cadeia de caracteres largos.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tputenv**|**_putenv**|**_putenv**|**_wputenv**|

O argumento *envstring* deve ser um ponteiro para uma cadeia de caracteres do formato *VarName*=*value_string*, em que *VarName* é o nome da variável de ambiente a ser adicionada ou modificada e *value_string* é o valor da variável. Se *VarName* já fizer parte do ambiente, seu valor será substituído por *value_string*; caso contrário, a nova variável *VarName* e seu valor *value_string* serão adicionados ao ambiente. Você pode remover uma variável do ambiente especificando um *value_string*vazio ou, em outras palavras, especificando somente *VarName*=.

**_putenv** e **_wputenv** afetam apenas o ambiente local para o processo atual; Você não pode usá-los para modificar o ambiente de nível de comando. Isso é, essas funções operam somente nas estruturas de dados que são acessíveis para a biblioteca em tempo de execução e não no segmento de ambiente criado para um processo pelo sistema operacional. Quando o processo atual termina, o ambiente é revertido para o nível do processo de chamada (que, na maioria dos casos, é o nível do sistema operacional). No entanto, o ambiente modificado pode ser passado para quaisquer novos processos criados por **_spawn**, **_exec**ou **sistema**, e esses novos processos recebem novos itens adicionados por **_putenv** e **_wputenv**.

Não altere uma entrada de ambiente diretamente: em vez disso, use **_putenv** ou **_wputenv** para alterá-la. Em particular, os elementos de liberação direta da matriz global **_environ []** podem levar à memória inválida que está sendo resolvida.

**getenv** e **_putenv** usar a variável global **_environ** para acessar a tabela de ambiente; **_wgetenv** e **_wputenv** usar **_wenviron**. **_putenv** e **_wputenv** podem alterar o valor de **_environ** e **_wenviron**, invalidando, portanto, o argumento **_envp** para **Main** e o argumento **_wenvp** para **wmain**. Portanto, é mais seguro usar **_environ** ou **_wenviron** para acessar as informações do ambiente. Para obter mais informações sobre a relação de **_putenv** e **_wputenv** a variáveis globais, consulte [_environ _wenviron](../../c-runtime-library/environ-wenviron.md).

> [!NOTE]
> As famílias de **_putenv** e **_getenv** de funções não são thread-safe. **_getenv** poderia retornar um ponteiro de cadeia de caracteres enquanto **_putenv** está modificando a cadeia de caracteres, causando falhas aleatórias. As chamadas para essas funções devem estar sincronizadas.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_putenv**|\<stdlib.h>|
|**_wputenv**|\<stdlib.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Para obter um exemplo de como usar **_putenv**, consulte [getenv, _wgetenv](getenv-wgetenv.md).

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[getenv, _wgetenv](getenv-wgetenv.md)<br/>
[_searchenv, _wsearchenv](searchenv-wsearchenv.md)<br/>
