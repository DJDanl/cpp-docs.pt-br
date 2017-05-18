---
title: _sopen_s, _wsopen_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _sopen_s
- _wsopen_s
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
- _sopen_s
- wsopen_s
- _wsopen_s
- sopen_s
dev_langs:
- C++
helpviewer_keywords:
- sopen_s function
- _wsopen_s function
- wsopen_s function
- opening files, for sharing
- files [C++], opening
- _sopen_s function
- files [C++], sharing
ms.assetid: 059a0084-d08c-4973-9174-55e391b72aa2
caps.latest.revision: 29
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
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 19c59eafafa9be23a9c9bc2705e93db23ba7bc7d
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="sopens-wsopens"></a>_sopen_s, _wsopen_s
Abre um arquivo para compartilhamento. Estas versões de [_sopen e _wsopen](../../c-runtime-library/reference/sopen-wsopen.md) têm aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
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
  
#### <a name="parameters"></a>Parâmetros  
 [out] `pfh`  
 O identificador de arquivo, ou -1 no caso de um erro.  
  
 [in] `filename`  
 Nome do arquivo.  
  
 [in] `oflag`  
 Os tipos de operações permitidas.  
  
 [in] `shflag`  
 O tipo de compartilhamento permitido.  
  
 [in] `pmode`  
 Configuração de permissão.  
  
## <a name="return-value"></a>Valor de retorno  
 Um valor retornado diferente de zero indica um erro; nesse caso, `errno` é configurado com um dos seguintes valores.  
  
 `EACCES`  
 O caminho determinado é um diretório ou o arquivo é somente leitura, mas foi realizada uma tentativa de operação de abertura para gravação.  
  
 `EEXIST`  
Sinalizadores  `_O_CREAT` e `_O_EXCL` foram especificados, mas `filename` já existe.  
  
 `EINVAL`  
 Argumento `oflag`, `shflag` ou `pmode` inválido, ou `pfh` ou `filename` é um ponteiro nulo.  
  
 `EMFILE`  
 Nenhum outro descritor de arquivo disponível.  
  
 `ENOENT`  
 Arquivo ou caminho não encontrado.  
  
 Se um argumento inválido for passado para a função, o manipulador de parâmetro inválido será invocado, como descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se for permitido que a execução continue, `errno` é definido como `EINVAL` e `EINVAL` é retornado.  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
 Em caso de erro, -1 é retornado por `pfh` (a menos que `pfh` seja um ponteiro nulo).  
  
## <a name="remarks"></a>Comentários  
 A função `_sopen_s` abre o arquivo especificado por `filename` e prepara o arquivo para leitura ou gravação compartilhada, como definido por `oflag` e `shflag`. A função `_wsopen_s` é uma versão de caractere largo da função `_sopen_s`; o argumento `filename` para `_wsopen_s` é uma cadeia de caracteres larga. Caso contrário, `_wsopen_s` e `_sopen_s` se comportam de forma idêntica.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_tsopen_s`|`_sopen_s`|`_sopen_s`|`_wsopen_s`|  
  
 A expressão de número inteiro `oflag` é formada combinando uma ou mais constantes de manifesto, que são definidas em \<fcntl.h>. Quando duas ou mais constantes formam o argumento `oflag`, elas são combinadas com o operador OR bit a bit (`|`).  
  
 `_O_APPEND`  
 Reposiciona um ponteiro de arquivo no final do arquivo, antes de cada operação de gravação.  
  
 `_O_BINARY`  
 Abre um arquivo no modo binário (não convertido). (Consulte [fopen](../../c-runtime-library/reference/fopen-wfopen.md) para obter uma descrição do modo binário.)  
  
 `_O_CREAT`  
 Cria um arquivo e o abre para gravação. Não terá efeito algum se o arquivo especificado por `filename` já existir.  
  
 `_O_CREAT | _O_SHORT_LIVED`  
 Cria um arquivo temporário e, se possível, não alinha com o disco.  
  
 `_O_CREAT | _O_TEMPORARY`  
 Cria um arquivo temporário, que é excluído quando o último descritor de arquivo é fechado.  
  
 `_O_CREAT | _O_EXCL`  
 Retorna um valor de erro se o arquivo especificado por `filename` existir. Aplica-se somente quando usado com `_O_CREAT`.  
  
 `_O_NOINHERIT`  
 Impede a criação de um descritor de arquivo compartilhado.  
  
 `_O_RANDOM`  
 Especifica principalmente acesso aleatório do disco.  
  
 `_O_RDONLY`  
 Abre um arquivo somente leitura. Não pode ser especificado com `_O_RDWR` ou `_O_WRONLY`.  
  
 `_O_RDWR`  
 Abre um arquivo para leitura e gravação. Não pode ser especificado com `_O_RDONLY` ou `_O_WRONLY`.  
  
 `_O_SEQUENTIAL`  
 Especifica principalmente acesso sequencial do disco.  
  
 `_O_TEXT`  
 Abre um arquivo no modo de texto (convertido). (Para obter mais informações, consulte [E/S de arquivo nos modos de texto e binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md) e [fopen](../../c-runtime-library/reference/fopen-wfopen.md).)  
  
 `_O_TRUNC`  
 Abre um arquivo e o trunca para que ele fique com tamanho zero; o arquivo deve ter permissão de gravação. Não pode ser especificado com `_O_RDONLY`. A constante `_O_TRUNC`, usada com a constante `_O_CREAT`, abre um arquivo existente ou cria um.  
  
> [!NOTE]
>  ‏O sinalizador `_O_TRUNC` destrói o conteúdo do arquivo especificado.  
  
 `_O_WRONLY`  
 Abre um arquivo somente gravação. Não pode ser especificado com `_O_RDONLY` ou `_O_RDWR`.  
  
 `_O_U16TEXT`  
 Abre um arquivo no modo Unicode UTF-16.  
  
 `_O_U8TEXT`  
 Abre um arquivo no modo Unicode UTF-8.  
  
 `_O_WTEXT`  
 Abre um arquivo no modo Unicode.  
  
 Para especificar o modo de acesso ao arquivo, você deve especificar `_O_RDONLY`, `_O_RDWR` ou `_O_WRONLY`. Não há um valor padrão para o modo de acesso.  
  
 Quando o arquivo é aberto no modo Unicode com a constante `_O_WTEXT`, `_O_U8TEXT` ou `_O_U16TEXT`, as funções de entrada convertem os dados do arquivo em dados UTF-16 armazenados como tipo `wchar_t`. Funções que gravam em arquivos abertos no modo Unicode esperam buffers que contenham dados UTF-16 armazenados como tipo `wchar_t`. Se o arquivo estiver codificado como UTF-8, os dados em UTF-16 serão convertidos em UTF-8 no momento da gravação. O conteúdo do arquivo codificado como UTF-8 será convertido em UTF-16 no momento da leitura. Tentar ler ou gravar uma quantidade ímpar de bytes no modo Unicode gera um erro de validação de parâmetro. Para ler ou gravar dados armazenados em seu programa como UTF-8, use um modo de arquivo de texto ou binário em vez do modo Unicode. Você é responsável por toda a conversão de codificação necessária.  
  
 Se `_sopen_s` for chamado com `_O_WRONLY | _O_APPEND` (modo de acréscimo) e `_O_WTEXT`, `_O_U16TEXT` ou `_O_U8TEXT`, ela tentará abrir o arquivo para leitura e gravação, lerá a BOM e reabrirá o arquivo somente gravação. Se uma falha impedir de abrir o arquivo para leitura e gravação, ele será aberto somente para gravação e usará o valor padrão na configuração do modo Unicode.  
  
 O argumento `shflag` é uma expressão constante formada por uma das seguintes constantes de manifesto, definidas em \<share.h>.  
  
 `_SH_DENYRW`  
 Nega acesso de leitura e gravação a um arquivo.  
  
 `_SH_DENYWR`  
 Nega acesso de gravação a um arquivo.  
  
 `_SH_DENYRD`  
 Nega acesso de leitura a um arquivo.  
  
 `_SH_DENYNO`  
 Permite acesso de leitura e gravação.  
  
 O argumento `pmode` é sempre necessário, ao contrário de `_sopen`. Ao especificar `_O_CREAT`, se o arquivo não existir, `pmode` especifica as configurações de permissão do arquivo, que são definidas quando o novo arquivo é fechado pela primeira vez. Caso contrário, `pmode` é ignorado. `pmode` é uma expressão de inteiro que contém uma ou ambas as constantes de manifesto `_S_IWRITE` e `_S_IREAD`, definidas em \<sys\stat.h>. Quando as duas constantes são fornecidas, elas são combinadas com o operador OR bit a bit. O significado de `pmode` é o seguinte.  
  
 `_S_IWRITE`  
 Gravação permitida.  
  
 `_S_IREAD`  
 Leitura permitida.  
  
 `_S_IREAD | _S_IWRITE`  
 Leitura e gravação permitidas.  
  
 Se a permissão de gravação não for fornecida, o arquivo será somente leitura. No sistema operacional Windows, todos os arquivos podem ser lidos; não é possível conceder permissão de somente gravação. Portanto, os modos `_S_IWRITE` e `_S_IREAD | _S_IWRITE` são equivalentes.  
  
 A função `_sopen_s` aplica a máscara de permissão do arquivo ao argumento `pmode` antes da definição das permissões. (Consulte [_umask](../../c-runtime-library/reference/umask.md).)  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|-------------|---------------------|---------------------|  
|`_sopen_s`|\<io.h>|\<fcntl.h>, \<sys\types.h>, \<sys\stat.h>, \<share.h>|  
|`_wsopen_s`|\<io.h> ou \<wchar.h>|\<fcntl.h>, \<sys/types.h>, \<sys/stat.h>, \<share.h>|  
  
 `_sopen_s` e `_wsopen_s` são extensões da Microsoft. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [_locking](../../c-runtime-library/reference/locking.md).  
  
## <a name="see-also"></a>Consulte também  
 [E/S de nível inferior](../../c-runtime-library/low-level-i-o.md)   
 [_close](../../c-runtime-library/reference/close.md)   
 [_creat, _wcreat](../../c-runtime-library/reference/creat-wcreat.md)   
 [fopen, _wfopen](../../c-runtime-library/reference/fopen-wfopen.md)   
 [_fsopen, _wfsopen](../../c-runtime-library/reference/fsopen-wfsopen.md)   
 [_open, _wopen](../../c-runtime-library/reference/open-wopen.md)
