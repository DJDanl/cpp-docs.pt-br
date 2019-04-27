---
title: _open, _wopen
ms.date: 11/04/2016
apiname:
- _open
- _wopen
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
ms.openlocfilehash: 7ef28d6cafa0b74b50ee2c50ec380b8bd3aed79f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62156064"
---
# <a name="open-wopen"></a>_open, _wopen

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

Cada uma destas funções mostra um descritor de arquivo do arquivo aberto. Um valor retornado de -1 indica um erro; Nesse caso **errno** é definido como um dos valores a seguir.

|Valor errno|Condição|
|-|-|
| **EACCES** | Tentou abrir um arquivo somente leitura para modificá-lo, o modo de compartilhamento do arquivo não permite realizar as operações especificadas ou o caminho informado é um diretório. |
| **EEXIST** | **O_creat** e **o_excl** sinalizadores especificados, mas *filename* já existe. |
| **EINVAL** | Inválido *oflag* ou *pmode* argumento. |
| **EMFILE** | Não há outros descritores de arquivos disponíveis (há muitos arquivos abertos). |
| **ENOENT** | Arquivo ou caminho não encontrado. |

Para obter mais informações sobre esses e outros códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **Open** função abre o arquivo especificado por *filename* e o prepara para leitura ou gravação, conforme especificado por *oflag*. **wopen** é uma versão de caractere largo de **Open**; o *filename* argumento **wopen** é uma cadeia de caracteres largos. **wopen** e **Open** se comportam de forma idêntica caso contrário.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_topen**|**_open**|**_open**|**_wopen**|

*oflag* é uma expressão inteira formada por uma ou mais das seguintes constantes de manifesto ou combinações de constantes, que são definidas no \<fcntl. h >.

|*oflag* constant|Comportamento|
|-|-|
| **_O_APPEND** | Move o ponteiro para o final do arquivo antes de cada operação de gravação. |
| **_O_BINARY** | Abre o arquivo no modo binário (sem conversão). (Consulte [fopen](fopen-wfopen.md) para obter uma descrição do modo binário.) |
| **_O_CREAT** | Cria um arquivo e o abre para gravação. Não tem nenhum efeito se o arquivo especificado por *filename* existe. O *pmode* argumento é necessário quando **o_creat** for especificado. |
| **_O_CREAT** &#124; **_O_SHORT_LIVED** | Cria um arquivo temporário e, se possível, não alinha com o disco. O *pmode* argumento é necessário quando **o_creat** for especificado. |
| **_O_CREAT** &#124; **_O_TEMPORARY** | Cria um arquivo temporário, que é excluído quando o último descritor de arquivo é fechado. O *pmode* argumento é necessário quando **o_creat** for especificado. |
| **_O_CREAT** &#124; ` _O_EXCL` | Retorna um valor de erro se um arquivo especificado por *filename* existe. Aplica-se somente quando usado com **o_creat**. |
| **_O_NOINHERIT** | Impede a criação de um descritor de arquivo compartilhado. |
| **_O_RANDOM** | Especifica que o cache é otimizado para acesso aleatório do disco, mas não se restringe a isso. |
| **_O_RDONLY** | Abre um arquivo somente leitura. Não pode ser especificado com **o_rdwr** ou **o_wronly**. |
| **_O_RDWR** | Abre um arquivo para leitura e gravação. Não pode ser especificado com **o_rdonly** ou **o_wronly**. |
| **_O_SEQUENTIAL** | Especifica que o cache é otimizado para acesso sequencial do disco, mas não se restringe a isso. |
| **_O_TEXT** | Abre um arquivo no modo de texto (convertido). (Para obter mais informações, consulte [E/S de arquivo nos modos de texto e binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md) e [fopen](fopen-wfopen.md).) |
| **_O_TRUNC** | Abre um arquivo e o trunca para que ele fique com tamanho zero; o arquivo deve ter permissão de gravação. Não pode ser especificado com **o_rdonly**. **O_trunc** usado com **o_creat** abre um arquivo existente ou cria um arquivo. **Observação:** O **o_trunc** sinalizador destrói o conteúdo do arquivo especificado. |
| **_O_WRONLY** | Abre um arquivo somente gravação. Não pode ser especificado com **o_rdonly** ou **o_rdwr**. |
| **_O_U16TEXT** | Abre um arquivo no modo Unicode UTF-16. |
| **_O_U8TEXT** | Abre um arquivo no modo Unicode UTF-8. |
| **_O_WTEXT** | Abre um arquivo no modo Unicode. |

Para especificar o modo de acesso de arquivo, você deve especificar **o_rdonly**, **o_rdwr**, ou **o_wronly**. Não há um valor padrão para o modo de acesso.

Se **o_wtext** é usado para abrir um arquivo para leitura, **Open** lê o início do arquivo e verifica se há uma marca de ordem de byte (BOM). Quando há BOM, o arquivo é tratado como UTF-8 ou UTF-16LE, de acordo com a BOM identificada. Quando não há BOM, o arquivo é tratado como ANSI. Quando um arquivo é aberto para gravação por meio **o_wtext**, UTF-16 é usada. Independentemente de qualquer configuração anterior ou byte marca de ordem, se **_O_U8TEXT** é usado, o arquivo sempre será aberto como UTF-8; se **_O_U16TEXT** é usado, o arquivo sempre será aberto como UTF-16.

Quando um arquivo é aberto no modo Unicode, usando **o_wtext**, **_O_U8TEXT**, ou **_O_U16TEXT**, entrada funções convertem os dados lidos do arquivo em dados UTF-16 armazenados como tipo **wchar_t**. Funções que gravam em um arquivo aberto no modo Unicode esperam buffers que contenham dados UTF-16 armazenados como tipo **wchar_t**. Se o arquivo estiver codificado como UTF-8, os dados em UTF-16 serão convertidos em UTF-8 no momento da gravação. O conteúdo do arquivo codificado como UTF-8 será convertido em UTF-16 no momento da leitura. Tentar ler ou gravar uma quantidade ímpar de bytes no modo Unicode gera um erro de validação de parâmetro. Para ler ou gravar dados armazenados em seu programa como UTF-8, use um modo de arquivo de texto ou binário em vez do modo Unicode. Você é responsável por toda a conversão de codificação necessária.

Se **Open** for chamado com **o_wronly** | **o_append** (modo de acréscimo) e **o_wtext**, **_O_ U16TEXT**, ou **_O_U8TEXT**, ele primeiro tenta abrir o arquivo para leitura e gravação, lerá a BOM e reabrirá somente gravação. Se uma falha impedir de abrir o arquivo para leitura e gravação, ele será aberto somente para gravação e usará o valor padrão na configuração do modo Unicode.

Quando duas ou mais constantes manifestas são usadas para formar o *oflag* argumento, as constantes são combinadas com o operador OR bit a bit ( **&#124;** ). Para saber mais sobre os modos de texto e binário, consulte [E/S de arquivo nos modos de texto e binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md).

O *pmode* argumento é necessário somente quando **o_creat** for especificado. Se o arquivo já existir, *pmode* será ignorado. Caso contrário, *pmode* Especifica as configurações de permissão de arquivo, que são definidas quando o novo arquivo é fechado pela primeira vez. **Open** aplica-se a máscara de permissão de arquivo atual a *pmode* antes que as permissões estão definidas. (Para obter mais informações, consulte [umask](umask.md).) *pmode* é uma expressão de inteiro que contém uma ou ambas das seguintes constantes de manifesto, definidas em \<sys\stat.h. >.

|*pmode*|Significado|
|-|-|
| **_S_IREAD** | Somente a leitura é permitida. |
| **_S_IWRITE** | Gravação permitida. (Na verdade, permite leitura e gravação.) |
| **_S_IREAD** &#124; **_S_IWRITE** | Leitura e gravação permitidas. |

Quando as duas constantes são informadas, elas são unidas com o operador OR bit a bit ( **&#124;** ). Todos os arquivos podem ser lidos no Windows; não há permissão somente gravação. Portanto, os modos **s_iwrite** e **s_iread** | **s_iwrite** são equivalentes.

Se um valor diferente de uma combinação dos **s_iread** e **s_iwrite** é especificado para *pmode*— mesmo se especificaria válido *pmode*em outro sistema operacional — ou se qualquer valor diferente de permitidos *oflag* values for especificado, a função gera uma asserção no modo de depuração e invoca o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função retornará -1 e definirá **errno** à **EINVAL**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_open**|\<io.h>|\<fcntl.h>, \<sys\types.h>, \<sys\stat.h>|
|**_wopen**|\<io.h> ou \<wchar.h>|\<fcntl.h>, \<sys\types.h>, \<sys\stat.h>|

**Open** e **wopen** são extensões da Microsoft. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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
