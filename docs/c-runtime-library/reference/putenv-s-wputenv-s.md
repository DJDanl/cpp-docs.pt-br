---
title: _putenv_s, _wputenv_s | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e84d7a68530a748c9b1ad7c553fad80ed4e7c86b
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32405569"
---
# <a name="putenvs-wputenvs"></a>_putenv_s, _wputenv_s

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

*sequência_dovalor*<br/>
O valor a ser definido para a variável de ambiente.

## <a name="return-value"></a>Valor de retorno

Retorna 0 se for bem-sucedido ou um código de erro.

### <a name="error-conditions"></a>Condições de Erro

|*varname*|*sequência_dovalor*|Valor retornado|
|------------|-------------|------------------|
|**NULL**|qualquer|**EINVAL**|
|qualquer|**NULL**|**EINVAL**|

Se uma das condições de erro ocorrer, essas funções invocarão um manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essas funções retornam **EINVAL** e defina **errno** para **EINVAL**.

## <a name="remarks"></a>Comentários

O **putenv_s** função adiciona novas variáveis de ambiente ou modifica os valores das variáveis de ambiente existente. Variáveis de ambiente definem o ambiente no qual um processo é executado (por exemplo, o caminho de pesquisa padrão para bibliotecas a ser vinculado a um programa). **wputenv_s** é uma versão de caractere largo de **putenv_s**; o *cadeiacaracenv* argumento **wputenv_s** é uma cadeia de caracteres largos.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tputenv_s**|**_putenv_s**|**_putenv_s**|**_wputenv_s**|

*varname* é o nome da variável de ambiente a ser adicionado ou modificado e *sequência_dovalor* é o valor da variável. Se *varname* já faz parte do ambiente, seu valor é substituído por *sequência_dovalor*; caso contrário, o novo *varname* variável e seu *sequência_dovalor*  são adicionadas ao ambiente. Você pode remover uma variável de ambiente especificando uma cadeia de caracteres vazia (isto é, "") para *sequência_dovalor*.

**putenv_s** e **wputenv_s** afetam apenas o ambiente local para o processo atual; você não pode usá-los para modificar o ambiente de nível de comando. Essas funções operam somente nas estruturas de dados que são acessíveis para a biblioteca em tempo de execução e não no “segmento” de ambiente que o sistema operacional cria para um processo. Quando o processo atual termina, o ambiente será revertido para o nível do processo de chamada, que, na maioria dos casos, é o nível do sistema operacional. No entanto, o ambiente modificado pode ser passado para novos processos que são criados por **spawn**, **EXEC**, ou **sistema**, e esses novos processos de obtém os itens novos são adicionado por **putenv_s** e **wputenv_s**.

Não altere uma entrada de ambiente diretamente. em vez disso, use **putenv_s** ou **wputenv_s** alterá-lo. Em particular, liberando diretamente elementos do **[ Environ]** matriz global pode causar a memória inválido ser resolvido.

**GETENV** e **putenv_s** usar a variável global **Environ** para acessar a tabela do ambiente. **wgetenv** e **wputenv_s** usar **wenviron**. **putenv_s** e **wputenv_s** pode alterar o valor de **Environ** e **wenviron**e assim invalidar o *envp*argumento **principal** e **_wenvp** argumento **wmain**. Portanto, é mais seguro usar **Environ** ou **wenviron** para acessar as informações de ambiente. Para obter mais informações sobre a relação de **putenv_s** e **wputenv_s** variáveis globais, consulte [Environ, wenviron](../../c-runtime-library/environ-wenviron.md).

> [!NOTE]
> O **putenv_s** e **_getenv_s** famílias de funções não são thread-safe. **_getenv_s** poderia retornar um ponteiro de cadeia de caracteres ao **putenv_s** está modificando a cadeia de caracteres e, assim, causar falhas aleatórias. As chamadas para essas funções devem estar sincronizadas.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_putenv_s**|\<stdlib.h>|
|**_wputenv_s**|\<stdlib.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Para obter um exemplo que mostra como usar **putenv_s**, consulte [getenv_s, wgetenv_s](getenv-s-wgetenv-s.md).

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[getenv, _wgetenv](getenv-wgetenv.md)<br/>
[_searchenv, _wsearchenv](searchenv-wsearchenv.md)<br/>
