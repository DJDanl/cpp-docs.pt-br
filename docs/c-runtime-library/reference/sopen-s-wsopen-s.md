---
title: _sopen_s, _wsopen_s
ms.date: 4/2/2020
api_name:
- _sopen_s
- _wsopen_s
- _o__sopen_s
- _o__wsopen_s
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
- api-ms-win-crt-stdio-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _sopen_s
- wsopen_s
- _wsopen_s
- sopen_s
helpviewer_keywords:
- sopen_s function
- _wsopen_s function
- wsopen_s function
- opening files, for sharing
- files [C++], opening
- _sopen_s function
- files [C++], sharing
ms.assetid: 059a0084-d08c-4973-9174-55e391b72aa2
ms.openlocfilehash: 81feacae0e4608512e7325c57e7f2b96bcf2cdde
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81356497"
---
# <a name="_sopen_s-_wsopen_s"></a>_sopen_s, _wsopen_s

Abre um arquivo para compartilhamento. Estas versões de [_sopen e _wsopen](sopen-wsopen.md) têm aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t _sopen_s(
   int* pfh,
   const char *filename,
   int oflag,
   int shflag,
   int pmode
);
errno_t _wsopen_s(
   int* pfh,
   const wchar_t *filename,
   int oflag,
   int shflag,
   int pmode,
);
```

### <a name="parameters"></a>Parâmetros

*Pfh*<br/>
O identificador de arquivo, ou -1 no caso de um erro.

*Filename*<br/>
Nome do arquivo.

*Oflag*<br/>
Os tipos de operações permitidas.

*Shflag*<br/>
O tipo de compartilhamento permitido.

*Pmode*<br/>
Configuração de permissão.

## <a name="return-value"></a>Valor retornado

Um valor de retorno não zero indica um erro; nesse **caso, errno** é definido como um dos seguintes valores.

|Valor errno|Condição|
|-|-|
| **Eacces** |  O caminho determinado é um diretório ou o arquivo é somente leitura, mas foi realizada uma tentativa de operação de abertura para gravação. |
| **EEXIST** |  **_O_CREAT** e **_O_EXCL** bandeiras foram especificadas, mas *o nome do arquivo* já existe. |
| **Einval** |  Sinalizador *inválido,* *shflag*ou argumento *pmode,* ou *pfh* ou *nome de arquivo* era um ponteiro nulo. |
| **EMFILE** | Nenhum outro descritor de arquivo disponível. |
| **Enoent** | Arquivo ou caminho não encontrado. |

Se um argumento inválido for passado para a função, o manipulador de parâmetro inválido será invocado, como descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **errno** será definido **como EINVAL** e **EINVAL** é devolvido.

Para obter mais informações sobre esses e outros códigos de devolução, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

No caso de um erro, -1 é devolvido através *de pfh* (a menos que *pfh* seja um ponteiro nulo).

## <a name="remarks"></a>Comentários

A função **_sopen_s** abre o arquivo especificado pelo *nome do arquivo* e prepara o arquivo para leitura ou escrita compartilhada, conforme definido por *oflag* e *shflag*. **_wsopen_s** é uma versão ampla do **_sopen_s;** o argumento *de nome de arquivo* para **_wsopen_s** é uma seqüência de caracteres amplo. **_wsopen_s** e **_sopen_s** se comportam de forma idêntica.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tsopen_s**|**_sopen_s**|**_sopen_s**|**_wsopen_s**|

A bandeira *de* expressão inteira é formada pela combinação de uma ou \<mais constantes manifestas, que são definidas em fcntl.h>. Quando duas ou mais constantes formam *a bandeira do*argumento, elas são combinadas com o operador bitwise-OR **(&#124;).**

|constante *bandeira*|Comportamento|
|-|-|
| **_O_APPEND** | Move o ponteiro para o final do arquivo antes de cada operação de gravação. |
| **_O_BINARY** | Abre o arquivo no modo binário (sem conversão). (Consulte [fopen](fopen-wfopen.md) para obter uma descrição do modo binário.) |
| **_O_CREAT** | Cria um arquivo e o abre para gravação. Não tem efeito se o arquivo especificado pelo *nome do arquivo* existir. O argumento *do pmode* é necessário quando **_O_CREAT** é especificado. |
| **_O_CREAT** **&#124; _O_SHORT_LIVED** | Cria um arquivo temporário e, se possível, não alinha com o disco. O argumento *do pmode* é necessário quando **_O_CREAT** é especificado. |
| **_O_CREAT** **&#124; _O_TEMPORARY** | Cria um arquivo temporário, que é excluído quando o último descritor de arquivo é fechado. O argumento *do pmode* é necessário quando **_O_CREAT** é especificado. |
| **_O_CREAT _O_CREAT** &#124;`_O_EXCL` | Retorna um valor de erro se um arquivo especificado pelo *nome do arquivo* existir. Aplica-se somente quando usado com **_O_CREAT**. |
| **_O_NOINHERIT** | Impede a criação de um descritor de arquivo compartilhado. |
| **_O_RANDOM** | Especifica que o cache é otimizado para acesso aleatório do disco, mas não se restringe a isso. |
| **_O_RDONLY** | Abre um arquivo somente leitura. Não pode ser especificado com **_O_RDWR** ou **_O_WRONLY**. |
| **_O_RDWR** | Abre um arquivo para leitura e gravação. Não pode ser especificado com **_O_RDONLY** ou **_O_WRONLY**. |
| **_O_SEQUENTIAL** | Especifica que o cache é otimizado para acesso sequencial do disco, mas não se restringe a isso. |
| **_O_TEXT** | Abre um arquivo no modo de texto (convertido). (Para obter mais informações, consulte [E/S de arquivo nos modos de texto e binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md) e [fopen](fopen-wfopen.md).) |
| **_O_TRUNC** | Abre um arquivo e o trunca para que ele fique com tamanho zero; o arquivo deve ter permissão de gravação. Não pode ser especificado com **_O_RDONLY**. **_O_TRUNC** usado com **_O_CREAT** abre um arquivo existente ou cria um arquivo. **Nota:** A **bandeira _O_TRUNC** destrói o conteúdo do arquivo especificado. |
| **_O_WRONLY** | Abre um arquivo somente gravação. Não pode ser especificado com **_O_RDONLY** ou **_O_RDWR**. |
| **_O_U16TEXT** | Abre um arquivo no modo Unicode UTF-16. |
| **_O_U8TEXT** | Abre um arquivo no modo Unicode UTF-8. |
| **_O_WTEXT** | Abre um arquivo no modo Unicode. |

Para especificar o modo de acesso ao arquivo, você deve especificar **_O_RDONLY,** **_O_RDWR**ou **_O_WRONLY**. Não há um valor padrão para o modo de acesso.

Quando um arquivo é aberto no modo Unicode usando **funções de**entrada _O_WTEXT, **_O_U8TEXT**ou **_O_U16TEXT,** traduza os dados lidos do arquivo em dados UTF-16 armazenados como **tipo wchar_t**. Funções que escrevem em um arquivo aberto no modo Unicode esperam buffers que contenham dados UTF-16 armazenados como **tipo wchar_t**. Se o arquivo estiver codificado como UTF-8, os dados em UTF-16 serão convertidos em UTF-8 no momento da gravação. O conteúdo do arquivo codificado como UTF-8 será convertido em UTF-16 no momento da leitura. Tentar ler ou gravar uma quantidade ímpar de bytes no modo Unicode gera um erro de validação de parâmetro. Para ler ou gravar dados armazenados em seu programa como UTF-8, use um modo de arquivo de texto ou binário em vez do modo Unicode. Você é responsável por toda a conversão de codificação necessária.

Se **_sopen_s** é chamado com **_O_WRONLY** | **_O_APPEND** (modo apêndice) e **_O_WTEXT,** **_O_U16TEXT**ou **_O_U8TEXT,** primeiro tenta abrir o arquivo para leitura e escrita, ler o BOM e reabri-lo apenas para escrever. Se uma falha impedir de abrir o arquivo para leitura e gravação, ele será aberto somente para gravação e usará o valor padrão na configuração do modo Unicode.

O argumento *shflag* é uma expressão constante que consiste em uma das \<seguintes constantes manifestas, que são definidas em share.h>.

|*shflag* constante|Comportamento|
|-|-|
| **_SH_DENYRW** | Nega acesso de leitura e gravação a um arquivo. |
| **_SH_DENYWR** | Nega acesso de gravação a um arquivo. |
| **_SH_DENYRD** | Nega acesso de leitura a um arquivo. |
| **_SH_DENYNO** | Permite acesso de leitura e gravação. |

O argumento *do pmode* é sempre necessário, ao contrário **de _sopen**. Quando você especifica **_O_CREAT**, se o arquivo não existe, o *pmode* especifica as configurações de permissão do arquivo, que são definidas quando o novo arquivo é fechado na primeira vez. Caso contrário, *o pmode* é ignorado. *pmode* é uma expressão inteira que contém uma ou ambas as constantes \<manifestas **_S_IWRITE** e **_S_IREAD,** que são definidas em sys\stat.h>. Quando as duas constantes são fornecidas, elas são combinadas com o operador OR bit a bit. O significado de *pmode* é o seguinte.

|*Pmode*|Significado|
|-|-|
| **_S_IREAD** | Somente a leitura é permitida. |
| **_S_IWRITE** | Gravação permitida. (Na verdade, permite leitura e gravação.) |
| **_S_IREAD** **_S_IWRITE &#124;** | Leitura e gravação permitidas. |

Se a permissão de gravação não for fornecida, o arquivo será somente leitura. No sistema operacional Windows, todos os arquivos podem ser lidos; não é possível conceder permissão de somente gravação. Portanto, os modos **_S_IWRITE** e **_S_IREAD** | **_S_IWRITE** são equivalentes.

**_sopen_s** aplica a máscara de permissão de arquivo atual ao *pmode* antes que as permissões sejam definidas. (Consulte [_umask](umask.md).)

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_sopen_s**|\<io.h>|\<fcntl.h>, \<sys\types.h>, \<sys\stat.h>, \<share.h>|
|**_wsopen_s**|\<io.h> ou \<wchar.h>|\<fcntl.h>, \<sys/types.h>, \<sys/stat.h>, \<share.h>|

**_sopen_s** e **_wsopen_s** são extensões da Microsoft. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [_locking](locking.md).

## <a name="see-also"></a>Confira também

[E/S de nível inferior](../../c-runtime-library/low-level-i-o.md)<br/>
[_close](close.md)<br/>
[_creat, _wcreat](creat-wcreat.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[_fsopen, _wfsopen](fsopen-wfsopen.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
