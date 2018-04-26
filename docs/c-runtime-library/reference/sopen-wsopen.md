---
title: _sopen, _wsopen | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _sopen
- _wsopen
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
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _wsopen
- wsopen
- _sopen
- _tsopen
dev_langs:
- C++
helpviewer_keywords:
- sopen function
- sharing files
- opening files, for sharing
- _sopen function
- wsopen function
- files [C++], opening
- files [C++], sharing
- _wsopen function
ms.assetid: a9d4cccf-06e9-414d-96fa-453fca88cc1f
caps.latest.revision: 21
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: fe8bc1480f2f0aa0234eb56242924543a6640dd5
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="sopen-wsopen"></a>_sopen, _wsopen

Abre um arquivo para compartilhamento. Versões mais seguras dessas funções estão disponíveis: consulte [sopen_s, wsopen_s](sopen-s-wsopen-s.md).

## <a name="syntax"></a>Sintaxe

```C
int _sopen(
   const char *filename,
   int oflag,
   int shflag [,
   int pmode ]
);
int _wsopen(
   const wchar_t *filename,
   int oflag,
   int shflag [,
   int pmode ]
);
```

### <a name="parameters"></a>Parâmetros

*filename*<br/>
Nome do arquivo.

*oflag*<br/>
Os tipos de operações permitidas.

*shflag*<br/>
O tipo de compartilhamento permitido.

*pmode*<br/>
Configuração de permissão.

## <a name="return-value"></a>Valor de retorno

Cada uma destas funções mostra um descritor de arquivo do arquivo aberto.

Se *filename* ou *oflag* é um **nulo** ponteiro, ou se *oflag* ou *shflag* não está dentro de uma opção válida intervalo de valores, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essas funções retornam -1 e defina **errno** para um dos valores a seguir.

|Valor errno|Condição|
|-|-|
**EACCES**|O caminho determinado é um diretório ou o arquivo é somente leitura, mas foi realizada uma tentativa de operação de abertura para gravação.
**EEXIST**|**O_creat** e **o_excl** sinalizadores forem especificados, mas *filename* já existe.
**EINVAL**|Inválido *oflag* ou *shflag* argumento.
**EMFILE**|Nenhum outro descritor de arquivo disponível.
**ENOENT**|Arquivo ou caminho não encontrado.

Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **sopen** função abre o arquivo especificado por *filename* e prepara o arquivo compartilhado de leitura ou gravação, conforme definido pelo *oflag* e *shflag* . **wsopen** é uma versão de caractere largo de **sopen**; o *filename* argumento **wsopen** é uma cadeia de caracteres largos. **wsopen** e **sopen** se comportam de forma idêntica caso contrário.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tsopen**|**_sopen**|**_sopen**|**_wsopen**|

A expressão de inteiro *oflag* é formado pela combinação de um ou mais dos seguintes manifestos constantes, que são definidas no \<fcntl.h >. Quando duas ou mais constantes formam o argumento *oflag*, eles são combinados com o operador OR bit a bit ( **&#124;** ).

|*oflag* constante|Comportamento|
|-|-|
**_O_APPEND**|Move o ponteiro para o final do arquivo antes de cada operação de gravação.
**O_BINARY**|Abre o arquivo no modo binário (sem conversão). (Consulte [fopen](fopen-wfopen.md) para obter uma descrição do modo binário.)
**O_CREAT**|Cria um arquivo e o abre para gravação. Não tem nenhum efeito se o arquivo especificado por *filename* existe. O *pmode* argumento é necessário quando **o_creat** for especificado.
**O_CREAT** &AMP;#124; **_O_SHORT_LIVED**|Cria um arquivo temporário e, se possível, não alinha com o disco. O *pmode* argumento é necessário quando **o_creat** for especificado.
**O_CREAT** &AMP;#124; **_O_TEMPORARY**|Cria um arquivo temporário, que é excluído quando o último descritor de arquivo é fechado. O *pmode* argumento é necessário quando **o_creat** for especificado.
**O_CREAT**&AMP;#124; ` _O_EXCL`|Retorna um valor de erro se um arquivo especificado por *filename* existe. Aplica-se somente quando usado com **o_creat**.
**_O_NOINHERIT**|Impede a criação de um descritor de arquivo compartilhado.
**_O_RANDOM**|Especifica que o cache é otimizado para acesso aleatório do disco, mas não se restringe a isso.
**_O_RDONLY**|Abre um arquivo somente leitura. Não pode ser especificado com **o_rdwr** ou **o_wronly**.
**O_RDWR**|Abre um arquivo para leitura e gravação. Não pode ser especificado com **o_rdonly** ou **o_wronly**.
**_O_SEQUENTIAL**|Especifica que o cache é otimizado para acesso sequencial do disco, mas não se restringe a isso.
**_O_TEXT**|Abre um arquivo no modo de texto (convertido). (Para obter mais informações, consulte [E/S de arquivo nos modos de texto e binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md) e [fopen](fopen-wfopen.md).)
**O_TRUNC**|Abre um arquivo e o trunca para que ele fique com tamanho zero; o arquivo deve ter permissão de gravação. Não pode ser especificado com **o_rdonly**. **O_trunc** usado com **o_creat** abre um arquivo existente ou cria um arquivo. **Observação:** o **o_trunc** sinalizador destrói o conteúdo do arquivo especificado.
**O_WRONLY**|Abre um arquivo somente gravação. Não pode ser especificado com **o_rdonly** ou **o_rdwr**.
**_O_U16TEXT**|Abre um arquivo no modo Unicode UTF-16.
**_O_U8TEXT**|Abre um arquivo no modo Unicode UTF-8.
**_O_WTEXT**|Abre um arquivo no modo Unicode.

Para especificar o modo de acesso de arquivo, você deve especificar **o_rdonly**, **o_rdwr**, ou **o_wronly**. Não há um valor padrão para o modo de acesso.

Quando um arquivo é aberto no modo Unicode usando **_O_WTEXT**, **_O_U8TEXT**, ou **_O_U16TEXT**, entrada funções convertem os dados lidos do arquivo de dados UTF-16 armazenados como tipo **wchar_t**. Funções que gravar em um arquivo aberto no modo Unicode esperam buffers que contêm dados UTF-16 armazenados como tipo **wchar_t**. Se o arquivo estiver codificado como UTF-8, os dados em UTF-16 serão convertidos em UTF-8 no momento da gravação. O conteúdo do arquivo codificado como UTF-8 será convertido em UTF-16 no momento da leitura. Tentar ler ou gravar uma quantidade ímpar de bytes no modo Unicode gera um erro de validação de parâmetro. Para ler ou gravar dados armazenados em seu programa como UTF-8, use um modo de arquivo de texto ou binário em vez do modo Unicode. Você é responsável por toda a conversão de codificação necessária.

Se **sopen** é chamado com **o_wronly** | **o_append** (modo de acréscimo) e **_O_WTEXT**, **_O_ U16TEXT**, ou **_O_U8TEXT**, ele primeiro tenta abrir o arquivo para leitura e gravação, ler o BOM e reabri-la somente para gravação. Se uma falha impedir de abrir o arquivo para leitura e gravação, ele será aberto somente para gravação e usará o valor padrão na configuração do modo Unicode.

O argumento *shflag* é uma expressão constante que consiste em um manifestos constantes, que são definidas no \<share.h >.

|*shflag* constante|Comportamento|
|-|-|
**SH_DENYRW**|Nega acesso de leitura e gravação a um arquivo.
**SH_DENYWR**|Nega acesso de gravação a um arquivo.
**SH_DENYRD**|Nega acesso de leitura a um arquivo.
**SH_DENYNO**|Permite acesso de leitura e gravação.

O *pmode* argumento é necessário somente quando **o_creat** for especificado. Se o arquivo não existir, *pmode* Especifica configurações de permissão do arquivo, que são definidas quando o novo arquivo será fechado na primeira vez. Caso contrário, *pmode* será ignorado. *pmode* é uma expressão de inteiro que contém uma ou ambas as constantes manifestos **s_iwrite** e **s_iread**, que é definido no \<sys\stat.h >. Quando as duas constantes são fornecidas, elas são combinadas com o operador OR bit a bit. O significado de *pmode* é o seguinte.

|*pmode*|Significado|
|-|-|
**S_IREAD**|Somente a leitura é permitida.
**S_IWRITE**|Gravação permitida. (Na verdade, permite leitura e gravação.)
**S_IREAD** &AMP;#124; **S_IWRITE**|Leitura e gravação permitidas.

Se a permissão de gravação não for fornecida, o arquivo será somente leitura. No sistema operacional Windows, todos os arquivos podem ser lidos; não é possível conceder permissão de somente gravação. Portanto, os modos de **s_iwrite** e **s_iread** | **s_iwrite** são equivalentes.

**sopen** aplica-se a máscara de permissão de arquivo atual para *pmode* antes que as permissões são definidas. (Consulte [_umask](umask.md).)

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_sopen**|\<io.h>|\<fcntl.h>, \<sys\types.h>, \<sys\stat.h>, \<share.h>|
|**_wsopen**|\<io.h> ou \<wchar.h>|\<fcntl.h>, \<sys\types.h>, \<sys\stat.h>, \<share.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [_locking](locking.md).

## <a name="see-also"></a>Consulte também

[E/S de nível inferior](../../c-runtime-library/low-level-i-o.md)<br/>
[_close](close.md)<br/>
[_creat, _wcreat](creat-wcreat.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[_fsopen, _wfsopen](fsopen-wfsopen.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
