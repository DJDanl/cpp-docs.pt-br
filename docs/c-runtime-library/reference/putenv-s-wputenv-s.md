---
title: _putenv_s, _wputenv_s
ms.date: 11/04/2016
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
- api-ms-win-crt-environment-l1-1-0.dll
apitype: DLLExport
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
ms.openlocfilehash: f675c2c0a2b12db3cce841dd0db9fa722393f1b6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50558945"
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

Se uma das condições de erro ocorrer, essas funções invocarão um manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão **EINVAL** e defina **errno** para **EINVAL**.

## <a name="remarks"></a>Comentários

O **putenv_s** função adiciona novas variáveis de ambiente ou modifica os valores das variáveis de ambiente existente. Variáveis de ambiente definem o ambiente no qual um processo é executado (por exemplo, o caminho de pesquisa padrão para bibliotecas a ser vinculado a um programa). **wputenv_s** é uma versão de caractere largo de **putenv_s**; o *cadeiacaracenv* argumento **wputenv_s** é uma cadeia de caracteres largos.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tputenv_s**|**_putenv_s**|**_putenv_s**|**_wputenv_s**|

*varname* é o nome da variável de ambiente a ser adicionada ou modificada e *sequência_dovalor* é o valor da variável. Se *varname* já é parte do ambiente, seu valor é substituído pelo *sequência_dovalor*; caso contrário, o novo *varname* variável e seu *sequência_dovalor*  são adicionadas ao ambiente. Você pode remover uma variável do ambiente especificando uma cadeia de caracteres vazia (ou seja, "") para *sequência_dovalor*.

**putenv_s** e **wputenv_s** afetam apenas o ambiente local para o processo atual; você não pode usá-los para modificar o ambiente de nível de comando. Essas funções operam somente nas estruturas de dados que são acessíveis para a biblioteca em tempo de execução e não no “segmento” de ambiente que o sistema operacional cria para um processo. Quando o processo atual termina, o ambiente será revertido para o nível do processo de chamada, que, na maioria dos casos, é o nível do sistema operacional. No entanto, o ambiente modificado pode ser passado para novos processos criados por **spawn**, **EXEC**, ou **sistema**, e esses novos processos obtém os novos itens que são adicionado pelo **putenv_s** e **wputenv_s**.

Não altere uma entrada de ambiente diretamente. em vez disso, use **putenv_s** ou **wputenv_s** alterá-la. Em particular, diretamente, liberar elementos dos **[ Environ]** matriz global pode causar a memória inválida ser resolvido.

**GETENV** e **putenv_s** usa a variável global **Environ** para acessar a tabela de ambiente; **wgetenv** e **wputenv_s** usar **wenviron**. **putenv_s** e **wputenv_s** pode alterar o valor de **Environ** e **wenviron**, invalidando o *envp*argumento para **principal** e o **_wenvp** argumento **wmain**. Portanto, é mais seguro usar **Environ** ou **wenviron** para acessar as informações de ambiente. Para obter mais informações sobre a relação de **putenv_s** e **wputenv_s** variáveis globais, consulte [Environ, wenviron](../../c-runtime-library/environ-wenviron.md).

> [!NOTE]
> O **putenv_s** e **_getenv_s** famílias de funções não são thread-safe. **_getenv_s** poderia retornar um ponteiro de cadeia de caracteres enquanto **putenv_s** está modificando a cadeia de caracteres e, portanto, causar falhas aleatórias. As chamadas para essas funções devem estar sincronizadas.

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
