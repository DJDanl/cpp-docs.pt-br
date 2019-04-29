---
title: _putenv, _wputenv
ms.date: 11/04/2016
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
ms.openlocfilehash: 952a4d62f6ceb6b689091ac09f6ca338d0b10864
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62357872"
---
# <a name="putenv-wputenv"></a>_putenv, _wputenv

Cria, modifica ou remove as variáveis de ambiente. Versões mais seguras dessas funções estão disponíveis; consulte [_putenv_s, _wputenv_s](putenv-s-wputenv-s.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

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

## <a name="return-value"></a>Valor de retorno

Retorna 0 se for bem-sucedido ou -1 caso de erro.

## <a name="remarks"></a>Comentários

O **putenv** função adiciona novas variáveis de ambiente ou modifica os valores das variáveis de ambiente existente. Variáveis de ambiente definem o ambiente no qual um processo é executado (por exemplo, o caminho de pesquisa padrão para bibliotecas a ser vinculado a um programa). **wputenv** é uma versão de caractere largo de **putenv**; o *cadeiacaracenv* argumento **wputenv** é uma cadeia de caracteres largos.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tputenv**|**_putenv**|**_putenv**|**_wputenv**|

O *cadeiacaracenv* argumento deve ser um ponteiro para uma cadeia de caracteres do formulário *varname*=*sequência_dovalor*, em que *varname* é o nome da variável de ambiente a ser adicionada ou modificada e *sequência_dovalor* é o valor da variável. Se *varname* já é parte do ambiente, seu valor é substituído pelo *sequência_dovalor*; caso contrário, o novo *varname* variável e seu *sequência_dovalor*  valor são adicionadas ao ambiente. Você pode remover uma variável do ambiente especificando uma vazia *sequência_dovalor*, ou em outras palavras, especificando somente *varname*=.

**putenv** e **wputenv** afetam apenas o ambiente local para o processo atual; você não pode usá-los para modificar o ambiente de nível de comando. Isso é, essas funções operam somente nas estruturas de dados que são acessíveis para a biblioteca em tempo de execução e não no segmento de ambiente criado para um processo pelo sistema operacional. Quando o processo atual termina, o ambiente é revertido para o nível do processo de chamada (que, na maioria dos casos, é o nível do sistema operacional). No entanto, o ambiente modificado pode ser passado para novos processos criados por **spawn**, **EXEC**, ou **sistema**, e esses novos processos obtém os novos itens adicionados pelo **putenv** e **wputenv**.

Não altere uma entrada de ambiente diretamente: em vez disso, use **putenv** ou **wputenv** alterá-la. Em particular, direta, liberar elementos dos **[ Environ]** matriz global pode levar a memória inválida seja resolvida.

**GETENV** e **putenv** usa a variável global **Environ** para acessar a tabela de ambiente; **wgetenv** e **wputenv** usar **wenviron**. **putenv** e **wputenv** pode alterar o valor de **Environ** e **wenviron**, invalidando, portanto, o **_envp** argumento para **principal** e o **_wenvp** argumento **wmain**. Portanto, é mais seguro usar **Environ** ou **wenviron** para acessar as informações de ambiente. Para obter mais informações sobre a relação de **putenv** e **wputenv** variáveis globais, consulte [Environ, wenviron](../../c-runtime-library/environ-wenviron.md).

> [!NOTE]
> O **putenv** e **_getenv** famílias de funções não são thread-safe. **_getenv** poderia retornar um ponteiro de cadeia de caracteres enquanto **putenv** está modificando a cadeia de caracteres, causando falhas aleatórias. As chamadas para essas funções devem estar sincronizadas.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_putenv**|\<stdlib.h>|
|**_wputenv**|\<stdlib.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Para obter um exemplo de como usar **putenv**, consulte [getenv, wgetenv](getenv-wgetenv.md).

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[getenv, _wgetenv](getenv-wgetenv.md)<br/>
[_searchenv, _wsearchenv](searchenv-wsearchenv.md)<br/>
