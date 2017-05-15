---
title: _open, _wopen | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
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
dev_langs:
- C++
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
caps.latest.revision: 31
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 82b12ebfbff06c19a863bec7d8be2e6677c0148e
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="open-wopen"></a>_open, _wopen
Abre um arquivo. Essas funções foram preteridas porque há versões mais seguras disponíveis; consulte [_sopen_s, _wsopen_s](../../c-runtime-library/reference/sopen-s-wsopen-s.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
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
  
#### <a name="parameters"></a>Parâmetros  
 `filename`  
 Nome do arquivo.  
  
 `oflag`  
 Os tipos de operações permitidas.  
  
 `pmode`  
 Modo de permissão.  
  
## <a name="return-value"></a>Valor de retorno  
 Cada uma destas funções mostra um descritor de arquivo do arquivo aberto. Se o valor retornado for -1, é sinal de que há um erro. Nesse caso, a função `errno` é definida com um dos valores a seguir.  
  
 `EACCES`  
 Tentou abrir um arquivo somente leitura para modificá-lo, o modo de compartilhamento do arquivo não permite realizar as operações especificadas ou o caminho informado é um diretório.  
  
 `EEXIST`  
Os sinalizadores  `_O_CREAT` e `_O_EXCL` foram especificados, mas `filename` já existe.  
  
 `EINVAL`  
 Argumento `oflag` ou `pmode` inválido.  
  
 `EMFILE`  
 Não há outros descritores de arquivos disponíveis (há muitos arquivos abertos).  
  
 `ENOENT`  
 Arquivo ou caminho não encontrado.  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 A função `_open` abre o arquivo especificado por `filename` e o prepara para leitura ou gravação, como especificado pelo parâmetro `oflag`. A função `_wopen` é uma versão de caractere largo da função `_open`; o argumento `filename` para `_wopen` é uma cadeia de caracteres larga. Caso contrário, `_wopen` e `_open` se comportam de forma idêntica.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_topen`|`_open`|`_open`|`_wopen`|  
  
 `oflag` é uma expressão inteira formada por uma ou mais constantes manifestas ou combinações de constantes a seguir, definidas em \<fcntl.h>.  
  
 `_O_APPEND`  
 Move o ponteiro para o final do arquivo antes de cada operação de gravação.  
  
 `_O_BINARY`  
 Abre o arquivo no modo binário (sem conversão). (Consulte [fopen](../../c-runtime-library/reference/fopen-wfopen.md) para obter uma descrição do modo binário.)  
  
 `_O_CREAT`  
 Cria um arquivo e o abre para gravação. Não terá efeito algum se o arquivo especificado por `filename` já existir. O argumento `pmode` é necessário quando `_O_CREAT` é especificada.  
  
 `_O_CREAT` &#124; `_O_SHORT_LIVED`  
 Cria um arquivo temporário e, se possível, não alinha com o disco. O argumento `pmode` é necessário quando `_O_CREAT` é especificada.  
  
 `_O_CREAT` &#124; `_O_TEMPORARY`  
 Cria um arquivo temporário, que é excluído quando o último descritor de arquivo é fechado. O argumento `pmode` é necessário quando `_O_CREAT` é especificada.  
  
 `_O_CREAT` &#124; `_O_EXCL`  
 Retorna um valor de erro se o arquivo especificado por `filename` existir. Aplica-se somente quando usado com `_O_CREAT`.  
  
 `_O_NOINHERIT`  
 Impede a criação de um descritor de arquivo compartilhado.  
  
 `_O_RANDOM`  
 Especifica que o cache é otimizado para acesso aleatório do disco, mas não se restringe a isso.  
  
 `_O_RDONLY`  
 Abre um arquivo somente leitura. Não pode ser especificado com `_O_RDWR` ou `_O_WRONLY`.  
  
 `_O_RDWR`  
 Abre um arquivo para leitura e gravação. Não pode ser especificado com `_O_RDONLY` ou `_O_WRONLY`.  
  
 `_O_SEQUENTIAL`  
 Especifica que o cache é otimizado para acesso sequencial do disco, mas não se restringe a isso.  
  
 `_O_TEXT`  
 Abre um arquivo no modo de texto (convertido). (Para obter mais informações, consulte [E/S de arquivo nos modos de texto e binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md) e [fopen](../../c-runtime-library/reference/fopen-wfopen.md).)  
  
 `_O_TRUNC`  
 Abre um arquivo e o trunca para que ele fique com tamanho zero; o arquivo deve ter permissão de gravação. Não pode ser especificado com `_O_RDONLY`. A constante `_O_TRUNC`, usada com a constante `_O_CREAT`, abre um arquivo existente ou cria um.  
  
> [!NOTE]
>  O sinalizador `_O_TRUNC` destrói o conteúdo do arquivo especificado.  
  
 `_O_WRONLY`  
 Abre o arquivo somente gravação. Não pode ser especificado com `_O_RDONLY` ou `_O_RDWR`.  
  
 `_O_U16TEXT`  
 Abre o arquivo no modo Unicode UTF-16.  
  
 `_O_U8TEXT`  
 Abre o arquivo no modo Unicode UTF-8.  
  
 `_O_WTEXT`  
 Abre o arquivo no modo Unicode.  
  
 Para especificar o modo de acesso ao arquivo, você deve especificar `_O_RDONLY`, `_O_RDWR` ou `_O_WRONLY`. Não há um valor padrão para o modo de acesso.  
  
 Se a constante `_O_WTEXT` for usada para abrir um arquivo para leitura, a função `_open` lê o início do arquivo e verifica se há uma BOM (marca de ordem de byte). Quando há BOM, o arquivo é tratado como UTF-8 ou UTF-16LE, de acordo com a BOM identificada. Quando não há BOM, o arquivo é tratado como ANSI. Quando o arquivo é aberto com a constante `_O_WTEXT` para gravação, o formato UTF-16 é usado. Independente da configuração ou da marca de ordem de byte anterior, se a constante `_O_U8TEXT` for usada, o arquivo sempre será aberto como UTF-8; se a constante `_O_U16TEXT` for usada, o arquivo sempre será aberto como UTF-16.  
  
 Quando o arquivo é aberto no modo Unicode com a constante `_O_WTEXT`, `_O_U8TEXT` ou `_O_U16TEXT`, as funções de entrada convertem os dados do arquivo em dados UTF-16 armazenados como tipo `wchar_t`. Funções que gravam em arquivos abertos no modo Unicode esperam buffers que contenham dados UTF-16 armazenados como tipo `wchar_t`. Se o arquivo estiver codificado como UTF-8, os dados em UTF-16 serão convertidos em UTF-8 no momento da gravação. O conteúdo do arquivo codificado como UTF-8 será convertido em UTF-16 no momento da leitura. Tentar ler ou gravar uma quantidade ímpar de bytes no modo Unicode gera um erro de validação de parâmetro. Para ler ou gravar dados armazenados em seu programa como UTF-8, use um modo de arquivo de texto ou binário em vez do modo Unicode. Você é responsável por toda a conversão de codificação necessária.  
  
 Se `_open` for chamado com `_O_WRONLY|_O_APPEND` (modo de acréscimo) e `_O_WTEXT`, `_O_U16TEXT` ou `_O_U8TEXT`, ela tentará abrir o arquivo para leitura e gravação, lerá a BOM e reabrirá o arquivo somente gravação. Se uma falha impedir de abrir o arquivo para leitura e gravação, ele será aberto somente para gravação e usará o valor padrão na configuração do modo Unicode.  
  
 Quando duas ou mais constantes manifestas são usadas para formar o argumento `oflag`, as constantes são combinadas ao operador OR bit a bit ( `|` ). Para saber mais sobre os modos de texto e binário, consulte [E/S de arquivo nos modos de texto e binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md).  
  
 O argumento `pmode` só é necessário quando `_O_CREAT` é especificada. Se o arquivo já existir, o argumento `pmode` será ignorado. Caso contrário, o argumento `pmode` especificará as configurações de permissões do arquivo, que são definidas quando o novo arquivo é fechado pela primeira vez. A função `_open` aplica a máscara de permissão do arquivo ao argumento `pmode` antes da definição das permissões. (Para saber mais, consulte [_umask](../../c-runtime-library/reference/umask.md).) O argumento `pmode` é uma expressão inteira que contém uma ou mais constantes manifestas a seguir, definidas em \<sys\stat.h>.  
  
 `_S_IREAD`  
 Somente a leitura é permitida.  
  
 `_S_IWRITE`  
 Gravação permitida. (Na verdade, permite leitura e gravação.)  
  
 `_S_IREAD`  `|`  `_S_IWRITE`  
 Leitura e gravação permitidas.  
  
 Quando as duas constantes são informadas, elas são associadas com o operador OR bit a bit ( `|` ). Todos os arquivos podem ser lidos no Windows; não há permissão somente gravação. Portanto, os modos `_S_IWRITE` e `_S_IREAD` `|` `_S_IWRITE` são equivalentes.  
  
 Se algum outro valor diferente da combinação de `_S_IREAD` e `_S_IWRITE` for especificado para o argumento `pmode` — mesmo que esse valor especifique um `pmode` válido em outro sistema operacional — ou se algum outro valor que não os valores permitidos no parâmetro `oflag` for especificado, a função gera uma asserção no modo de depuração e invoca um manipulador de parâmetros inválido, como descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função retornará um valor -1 e definirá `errno` como `EINVAL`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|-------------|---------------------|---------------------|  
|`_open`|\<io.h>|\<fcntl.h>, \<sys\types.h>, \<sys\stat.h>|  
|`_wopen`|\<io.h> ou \<wchar.h>|\<fcntl.h>, \<sys\types.h>, \<sys\stat.h>|  
  
 `_open` e `_wopen` são extensões da Microsoft. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
  
```  
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
  
## <a name="output"></a>Saída  
  
```  
Open succeeded on input file  
Open succeeded on output file  
```  
  
## <a name="see-also"></a>Consulte também  
 [E/S de nível inferior](../../c-runtime-library/low-level-i-o.md)   
 [_chmod, _wchmod](../../c-runtime-library/reference/chmod-wchmod.md)   
 [_close](../../c-runtime-library/reference/close.md)   
 [_creat, _wcreat](../../c-runtime-library/reference/creat-wcreat.md)   
 [_dup, _dup2](../../c-runtime-library/reference/dup-dup2.md)   
 [fopen, _wfopen](../../c-runtime-library/reference/fopen-wfopen.md)   
 [_sopen, _wsopen](../../c-runtime-library/reference/sopen-wsopen.md)
