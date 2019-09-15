---
title: _open, _wopen
ms.date: 11/04/2016
api_name:
- _open
- _wopen
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _wopen
- _topen
- _open
helpviewer_keywords:
- opening files, for file I/O
- topen function
- _open function
- _topen function
- _wopen function
- files [C++], opening
- wopen function
- open function
ms.assetid: 13f6a0c3-d1aa-450d-a7aa-74abc91b163e
ms.openlocfilehash: aad98844f4d9faf57c7bc5051eebabad09b860a4
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70951172"
---
# <a name="_open-_wopen"></a>_open, _wopen

Abre um arquivo. Essas funções foram preteridas porque há versões mais seguras disponíveis; consulte [_sopen_s, _wsopen_s](sopen-s-wsopen-s.md).

## <a name="syntax"></a>Sintaxe

```C
int _open(
   const char *filename,
   int oflag [,
   int pmode]
);
int _wopen(
   const wchar_t *filename,
   int oflag [,
   int pmode]
);
```

### <a name="parameters"></a>Parâmetros

*filename*<br/>
Nome do arquivo.

*oflag*<br/>
Os tipos de operações permitidas.

*pmode*<br/>
Modo de permissão.

## <a name="return-value"></a>Valor de retorno

Cada uma destas funções mostra um descritor de arquivo do arquivo aberto. Um valor de retorno de-1 indica um erro; Nesse caso, **errno** é definido como um dos valores a seguir.

|Valor errno|Condição|
|-|-|
| **EACCES** | Tentou abrir um arquivo somente leitura para modificá-lo, o modo de compartilhamento do arquivo não permite realizar as operações especificadas ou o caminho informado é um diretório. |
| **EEXIST** | Sinalizadores **_O_CREAT** e **_O_EXCL** especificados, mas o *nome de arquivo* já existe. |
| **EINVAL** | Argumento *oflag* ou *pmode* inválido. |
| **EMFILE** | Não há outros descritores de arquivos disponíveis (há muitos arquivos abertos). |
| **ENOENT** | Arquivo ou caminho não encontrado. |

Para obter mais informações sobre esses e outros códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **_open** abre o arquivo especificado por *filename* e o prepara para leitura ou gravação, conforme especificado por *oflag*. **_wopen** é uma versão de caractere largo do **_open**; o argumento *filename* para **_wopen** é uma cadeia de caracteres largos. **_wopen** e **_open** se comportam de outra forma.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_topen**|**_open**|**_open**|**_wopen**|

*oflag* é uma expressão de inteiro formada de uma ou mais das constantes de manifesto a seguir ou combinações constantes, que \<são definidas em Fcntl. h >.

|constante *oflag*|Comportamento|
|-|-|
| **_O_APPEND** | Move o ponteiro para o final do arquivo antes de cada operação de gravação. |
| **_O_BINARY** | Abre o arquivo no modo binário (sem conversão). (Consulte [fopen](fopen-wfopen.md) para obter uma descrição do modo binário.) |
| **_O_CREAT** | Cria um arquivo e o abre para gravação. Não terá efeito se o arquivo especificado por *filename* existir. O argumento *pmode* é necessário quando **_O_CREAT** é especificado. |
| **_O_CREAT** &#124; **_O_SHORT_LIVED** | Cria um arquivo temporário e, se possível, não alinha com o disco. O argumento *pmode* é necessário quando **_O_CREAT** é especificado. |
| **_O_CREAT** &#124; **_O_TEMPORARY** | Cria um arquivo temporário, que é excluído quando o último descritor de arquivo é fechado. O argumento *pmode* é necessário quando **_O_CREAT** é especificado. |
| **_O_CREAT** &#124; ` _O_EXCL` | Retorna um valor de erro se um arquivo especificado por *filename* existir. Aplica-se somente quando usado com **_O_CREAT**. |
| **_O_NOINHERIT** | Impede a criação de um descritor de arquivo compartilhado. |
| **_O_RANDOM** | Especifica que o cache é otimizado para acesso aleatório do disco, mas não se restringe a isso. |
| **_O_RDONLY** | Abre um arquivo somente leitura. Não pode ser especificado com **_O_RDWR** ou **_O_WRONLY**. |
| **_O_RDWR** | Abre um arquivo para leitura e gravação. Não pode ser especificado com **_O_RDONLY** ou **_O_WRONLY**. |
| **_O_SEQUENTIAL** | Especifica que o cache é otimizado para acesso sequencial do disco, mas não se restringe a isso. |
| **_O_TEXT** | Abre um arquivo no modo de texto (convertido). (Para obter mais informações, consulte [E/S de arquivo nos modos de texto e binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md) e [fopen](fopen-wfopen.md).) |
| **_O_TRUNC** | Abre um arquivo e o trunca para que ele fique com tamanho zero; o arquivo deve ter permissão de gravação. Não pode ser especificado com **_O_RDONLY**. **_O_TRUNC** usado com **_O_CREAT** abre um arquivo existente ou cria um arquivo. **Observação:** O sinalizador **_O_TRUNC** destrói o conteúdo do arquivo especificado. |
| **_O_WRONLY** | Abre um arquivo somente gravação. Não pode ser especificado com **_O_RDONLY** ou **_O_RDWR**. |
| **_O_U16TEXT** | Abre um arquivo no modo Unicode UTF-16. |
| **_O_U8TEXT** | Abre um arquivo no modo Unicode UTF-8. |
| **_O_WTEXT** | Abre um arquivo no modo Unicode. |

Para especificar o modo de acesso ao arquivo, você deve especificar **_O_RDONLY**, **_O_RDWR**ou **_O_WRONLY**. Não há um valor padrão para o modo de acesso.

Se **_O_WTEXT** for usado para abrir um arquivo para leitura, o **_open** lerá o início do arquivo e verificará se há uma bom (marca de ordem de byte). Quando há BOM, o arquivo é tratado como UTF-8 ou UTF-16LE, de acordo com a BOM identificada. Quando não há BOM, o arquivo é tratado como ANSI. Quando um arquivo é aberto para gravação usando **_O_WTEXT**, o UTF-16 é usado. Independentemente de qualquer configuração anterior ou marca de ordem de byte, se **_O_U8TEXT** for usado, o arquivo será sempre aberto como UTF-8; Se **_O_U16TEXT** for usado, o arquivo será sempre aberto como UTF-16.

Quando um arquivo é aberto no modo Unicode usando **_O_WTEXT**, **_O_U8TEXT**ou **_O_U16TEXT**, as funções de entrada convertem os dados lidos do arquivo em dados UTF-16 armazenados como tipo **wchar_t**. As funções que gravam em um arquivo aberto no modo Unicode esperam buffers que contêm dados UTF-16 armazenados como tipo **wchar_t**. Se o arquivo estiver codificado como UTF-8, os dados em UTF-16 serão convertidos em UTF-8 no momento da gravação. O conteúdo do arquivo codificado como UTF-8 será convertido em UTF-16 no momento da leitura. Tentar ler ou gravar uma quantidade ímpar de bytes no modo Unicode gera um erro de validação de parâmetro. Para ler ou gravar dados armazenados em seu programa como UTF-8, use um modo de arquivo de texto ou binário em vez do modo Unicode. Você é responsável por toda a conversão de codificação necessária.

Se **_open** for chamado com **_O_WRONLY** |  **_O_APPEND** (modo de acréscimo) e **_O_WTEXT**, **_O_U16TEXT**ou **_O_U8TEXT**, primeiro ele tentará abrir o arquivo para leitura e gravação, ler a bom e, em seguida, reabri-la para somente gravação. Se uma falha impedir de abrir o arquivo para leitura e gravação, ele será aberto somente para gravação e usará o valor padrão na configuração do modo Unicode.

Quando duas ou mais constantes de manifesto são usadas para formar o argumento *oflag* , as constantes são combinadas com o operador bit- **&#124;** a-or (). Para saber mais sobre os modos de texto e binário, consulte [E/S de arquivo nos modos de texto e binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md).

O argumento *pmode* é necessário somente quando **_O_CREAT** é especificado. Se o arquivo já existir, *pmode* será ignorado. Caso contrário, *pmode* especificará as configurações de permissão de arquivo, que são definidas quando o novo arquivo é fechado pela primeira vez. **_open** aplica a máscara de permissão de arquivo atual a *pmode* antes que as permissões sejam definidas. (Para obter mais informações, consulte [_umask](umask.md).) *pmode* é uma expressão de inteiro que contém uma ou ambas as seguintes constantes de manifesto, que são definidas \<em SYS\Stat.h >.

|*pmode*|Significado|
|-|-|
| **_S_IREAD** | Somente a leitura é permitida. |
| **_S_IWRITE** | Gravação permitida. (Na verdade, permite leitura e gravação.) |
| **_S_IREAD** &#124; **_S_IWRITE** | Leitura e gravação permitidas. |

Quando ambas as constantes são fornecidas, elas são unidas com o operador OR bit- **&#124;** a-or (). Todos os arquivos podem ser lidos no Windows; não há permissão somente gravação. Portanto, os modos **_S_IWRITE** e **_S_IREAD** |  **_S_IWRITE** são equivalentes.

Se um valor diferente de alguma combinação de **_S_IREAD** e **_S_IWRITE** for especificado para *pmode*— mesmo que ele especifique um *pmode* válido em outro sistema operacional — ou se qualquer valor diferente dos valores de *oflag* permitidos for especificado, a função gera uma asserção no modo de depuração e invoca o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, a função retornará-1 e definirá **errno** como **EINVAL**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_open**|\<io.h>|\<fcntl.h>, \<sys\types.h>, \<sys\stat.h>|
|**_wopen**|\<io.h> ou \<wchar.h>|\<fcntl.h>, \<sys\types.h>, \<sys\stat.h>|

**_open** e **_wopen** são extensões da Microsoft. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

```C
// crt_open.c
// compile with: /W3
/* This program uses _open to open a file
* named CRT_OPEN.C for input and a file named CRT_OPEN.OUT
* for output. The files are then closed.
*/
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <io.h>
#include <stdio.h>

int main( void )
{
   int fh1, fh2;

   fh1 = _open( "CRT_OPEN.C", _O_RDONLY ); // C4996
   // Note: _open is deprecated; consider using _sopen_s instead
   if( fh1 == -1 )
      perror( "Open failed on input file" );
   else
   {
      printf( "Open succeeded on input file\n" );
      _close( fh1 );
   }

   fh2 = _open( "CRT_OPEN.OUT", _O_WRONLY | _O_CREAT, _S_IREAD |
                            _S_IWRITE ); // C4996
   if( fh2 == -1 )
      perror( "Open failed on output file" );
   else
   {
      printf( "Open succeeded on output file\n" );
      _close( fh2 );
   }
}
```

### <a name="output"></a>Saída

```Output
Open succeeded on input file
Open succeeded on output file
```

## <a name="see-also"></a>Consulte também

[E/S de nível inferior](../../c-runtime-library/low-level-i-o.md)<br/>
[_chmod, _wchmod](chmod-wchmod.md)<br/>
[_close](close.md)<br/>
[_creat, _wcreat](creat-wcreat.md)<br/>
[_dup, _dup2](dup-dup2.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[_sopen, _wsopen](sopen-wsopen.md)<br/>
