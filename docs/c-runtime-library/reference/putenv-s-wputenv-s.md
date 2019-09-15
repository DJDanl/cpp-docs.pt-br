---
title: _putenv_s, _wputenv_s
ms.date: 11/04/2016
api_name:
- _wputenv_s
- _putenv_s
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
ms.openlocfilehash: b2de609314a12f626a21680b470bc8831eada2cb
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70949897"
---
# <a name="_putenv_s-_wputenv_s"></a>_putenv_s, _wputenv_s

Cria, modifica ou remove as variáveis de ambiente. Essas são versões de [_putenv, _wputenv](putenv-wputenv.md), mas têm melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

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

*varname*<br/>
O nome da variável de ambiente.

*value_string*<br/>
O valor a ser definido para a variável de ambiente.

## <a name="return-value"></a>Valor de retorno

Retorna 0 se for bem-sucedido ou um código de erro.

### <a name="error-conditions"></a>Condições de Erro

|*varname*|*value_string*|Valor retornado|
|------------|-------------|------------------|
|**NULL**|qualquer|**EINVAL**|
|qualquer|**NULL**|**EINVAL**|

Se uma das condições de erro ocorrer, essas funções invocarão um manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão **EINVAL** e definirá **errno** como **EINVAL**.

## <a name="remarks"></a>Comentários

A função **_putenv_s** adiciona novas variáveis de ambiente ou modifica os valores das variáveis de ambiente existentes. Variáveis de ambiente definem o ambiente no qual um processo é executado (por exemplo, o caminho de pesquisa padrão para bibliotecas a ser vinculado a um programa). **_wputenv_s** é uma versão de caractere largo do **_putenv_s**; o argumento *envstring* para **_wputenv_s** é uma cadeia de caracteres largos.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tputenv_s**|**_putenv_s**|**_putenv_s**|**_wputenv_s**|

*VarName* é o nome da variável de ambiente a ser adicionada ou modificada e *value_string* é o valor da variável. Se *VarName* já fizer parte do ambiente, seu valor será substituído por *value_string*; caso contrário, a nova variável *VarName* e suas *value_string* serão adicionadas ao ambiente. Você pode remover uma variável do ambiente especificando uma cadeia de caracteres vazia (ou seja, "") para *value_string*.

**_putenv_s** e **_wputenv_s** afetam apenas o ambiente local para o processo atual; Você não pode usá-los para modificar o ambiente de nível de comando. Essas funções operam somente nas estruturas de dados que são acessíveis para a biblioteca em tempo de execução e não no “segmento” de ambiente que o sistema operacional cria para um processo. Quando o processo atual termina, o ambiente será revertido para o nível do processo de chamada, que, na maioria dos casos, é o nível do sistema operacional. No entanto, o ambiente modificado pode ser passado para quaisquer novos processos criados por **_spawn**, **_exec**ou **System**, e esses novos processos recebem novos itens que são adicionados por **_putenv_s** e **_wputenv_s**.

Não altere uma entrada de ambiente diretamente; em vez disso, use **_putenv_s** ou **_wputenv_s** para alterá-lo. Em particular, a liberação direta de elementos da matriz global **_environ []** pode fazer com que a memória inválida seja resolvida.

**getenv** e **_putenv_s** usam a variável global **_environ** para acessar a tabela de ambiente; **_wgetenv** e **_wputenv_s** usam **_wenviron**. **_putenv_s** e **_wputenv_s** podem alterar o valor de **_environ** e **_wenviron**e, portanto, invalidar o argumento *envp* para **Main** e o argumento **_wenvp** para **wmain**. Portanto, é mais seguro usar **_environ** ou **_wenviron** para acessar as informações do ambiente. Para obter mais informações sobre a relação de **_putenv_s** e **_wputenv_s** para variáveis globais, consulte [_environ, _wenviron](../../c-runtime-library/environ-wenviron.md).

> [!NOTE]
> As famílias de funções **_putenv_s** e **_getenv_s** não são thread-safe. **_getenv_s** poderia retornar um ponteiro de cadeia de caracteres enquanto **_putenv_s** está modificando a cadeia de caracteres e, portanto, causa falhas aleatórias. As chamadas para essas funções devem estar sincronizadas.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_putenv_s**|\<stdlib.h>|
|**_wputenv_s**|\<stdlib.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Para obter um exemplo que mostra como usar **_putenv_s**, consulte [getenv_s, _wgetenv_s](getenv-s-wgetenv-s.md).

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[getenv, _wgetenv](getenv-wgetenv.md)<br/>
[_searchenv, _wsearchenv](searchenv-wsearchenv.md)<br/>
