---
title: _fsopen, _wfsopen | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _wfsopen
- _fsopen
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
- wfsopen
- fsopen
- tfsopen
- _tfsopen
- _wfsopen
- _fsopen
dev_langs:
- C++
helpviewer_keywords:
- opening files, streams
- fsopen function
- tfsopen function
- wfsopen function
- _fsopen function
- files [C++], opening
- _tfsopen function
- _wfsopen function
- file sharing [C++]
ms.assetid: 5e4502ab-48a9-4bee-a263-ebac8d638dec
caps.latest.revision: 20
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
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: c53bdd4bdd5d6707e6da15def20b6375dcf6e0dd
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="fsopen-wfsopen"></a>_fsopen, _wfsopen
Abre um fluxo com compartilhamento de arquivos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
FILE *_fsopen(   
   const char *filename,  
   const char *mode,  
   int shflag   
);  
FILE *_wfsopen(   
   const wchar_t *filename,  
   const wchar_t *mode,  
   int shflag   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `filename`  
 Nome do arquivo a ser aberto.  
  
 `mode`  
 Tipo de acesso permitido.  
  
 `shflag`  
 Tipo de compartilhamento permitido.  
  
## <a name="return-value"></a>Valor de retorno  
 Cada uma dessas funções retorna um ponteiro para o fluxo. Um valor de ponteiro nulo indica um erro. Se `filename` ou `mode` for `NULL` ou uma cadeia de caracteres vazia, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão `NULL` e definirão `errno` para `EINVAL`.  
  
 Para obter mais informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 A função `_fsopen` abre o arquivo especificado por `filename` como um fluxo e prepara o arquivo para leitura ou gravação compartilhada posterior, conforme definido pelo modo e pelos argumentos de `shflag`. `_wfsopen` é uma versão de caractere largo de `_fsopen`; os argumentos `filename` e `mode` para `_wfsopen` são cadeias de caracteres largos. Caso contrário, `_wfsopen` e `_fsopen` se comportam de forma idêntica.  
  
 A cadeia de caracteres `mode` especifica o tipo de acesso solicitado para o arquivo, conforme mostrado na tabela a seguir.  
  
|Termo|Definição|  
|----------|----------------|  
|`"r"`|Abre para leitura. Se o arquivo não existir ou não puder ser encontrado, a chamada `_fsopen` falha.|  
|`"w"`|Abre um arquivo vazio para gravação. Se o arquivo determinado existir, seus conteúdos são destruídos.|  
|`"a"`|Abre para gravação no final do arquivo (acréscimo); cria o arquivo primeiro se ele não existir.|  
|`"r+"`|Abre para leitura e gravação. (O arquivo deve existir.)|  
|`"w+"`|Abre um arquivo vazio para leitura e gravação. Se o arquivo determinado existir, seus conteúdos são destruídos.|  
|`"a+"`|Abre para gravação e acréscimo; cria o arquivo primeiro se ele não existir.|  
  
 Use os tipos `"w"` e `"w+"` com cuidado, pois eles podem destruir arquivos existentes.  
  
 Quando um arquivo é aberto com o tipo de acesso `"a"` ou `"a+"`, todas as operações de gravação ocorrem no fim do arquivo. O ponteiro do arquivo pode ser reposicionado usando `fseek` ou `rewind`, mas é sempre movido de volta para o final do arquivo antes que qualquer operação de gravação seja realizada. Sendo assim, dados existentes não podem ser substituídos. Quando o tipo de acesso `"r+"`, `"w+"` ou `"a+"` é especificado, são permitidas leitura e gravação (diz-se que o arquivo está aberto para atualização). No entanto, ao alternar entre leitura e gravação, deve haver uma operação [fsetpos](../../c-runtime-library/reference/fsetpos.md), [fseek](../../c-runtime-library/reference/fseek-fseeki64.md) ou [rewind](../../c-runtime-library/reference/rewind.md) intermediária. A posição atual pode ser especificada para a operação `fsetpos` ou `fseek`, se desejado. Além dos valores acima, um dos caracteres seguintes pode ser incluído em `mode` para especificar o modo de conversão para novas linhas e para o gerenciamento de arquivo.  
  
|Termo|Definição|  
|----------|----------------|  
|`t`|Abre um arquivo no modo de texto (convertido). Nesse modo, combinações de carro linha de retorno de feed (CR LF) são transformadas em feeds de única linha (LF) na entrada e LF caracteres são convertidos para combinações de CR LF na saída. Além disso, CTRL+Z é interpretado como um caractere de fim do arquivo na entrada. Em arquivos abertos para leitura ou leitura/gravação, `_fsopen` verifica se há um CTRL+Z no fim do arquivo e o remove, se possível. Isso é feito porque usar `fseek` e `ftell` para movimentação dentro de um arquivo que termina com CTRL+Z pode fazer o `fseek` se comportar incorretamente perto do fim do arquivo.|  
|`b`|Abre um arquivo no modo binário (não convertido); as conversões acima são suprimidas.|  
|`S`|Especifica que o cache é otimizado para acesso sequencial do disco, mas não se restringe a isso.|  
|`R`|Especifica que o cache é otimizado para acesso aleatório do disco, mas não se restringe a isso.|  
|`T`|Especifica um arquivo como temporário. Se possível, ele não é liberado no disco.|  
|`D`|Especifica um arquivo como temporário. É excluído quando o último ponteiro de arquivo é fechado.|  
  
 Se `t` ou `b` não for informado em `mode`, o modo de conversão será definido pela variável de modo padrão `_fmode`. Se `t` ou `b` for prefixado para o argumento, a função falha e retorna `NULL`. Para saber mais sobre os modos de texto e binário, consulte [E/S de texto e arquivo de modo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md).  
  
 O argumento `shflag` é uma expressão constante formada por uma das seguintes constantes de manifesto, definidas em Share.h.  
  
|Termo|Definição|  
|----------|----------------|  
|`_SH_COMPAT`|Define o modo de Compatibilidade para aplicativos de 16 bits.|  
|`_SH_DENYNO`|Permite acesso de leitura e gravação.|  
|`_SH_DENYRD`|Nega acesso de leitura ao arquivo.|  
|`_SH_DENYRW`|Nega acesso de leitura e gravação ao arquivo.|  
|`_SH_DENYWR`|Nega acesso de gravação ao arquivo.|  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_tfsopen`|`_fsopen`|`_fsopen`|`_wfsopen`|  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|Cabeçalhos opcionais|  
|--------------|---------------------|----------------------|  
|`_fsopen`|\<stdio.h>|\<share.h><br /><br /> Para ver a constante de manifesto para o parâmetro `shflag`.|  
|`_wfsopen`|\<stdio.h> ou \<wchar.h>|\<share.h><br /><br /> Para ver a constante de manifesto para o parâmetro `shflag`.|  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_fsopen.c  
  
#include <stdio.h>  
#include <stdlib.h>  
#include <share.h>  
  
int main( void )  
{  
   FILE *stream;  
  
   // Open output file for writing. Using _fsopen allows us to  
   // ensure that no one else writes to the file while we are  
   // writing to it.  
    //  
   if( (stream = _fsopen( "outfile", "wt", _SH_DENYWR )) != NULL )  
   {  
      fprintf( stream, "No one else in the network can write "  
                       "to this file until we are done.\n" );  
      fclose( stream );  
   }  
   // Now others can write to the file while we read it.  
   system( "type outfile" );  
}  
```  
  
```Output  
No one else in the network can write to this file until we are done.  
```  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fclose, _fcloseall](../../c-runtime-library/reference/fclose-fcloseall.md)   
 [_fdopen, _wfdopen](../../c-runtime-library/reference/fdopen-wfdopen.md)   
 [ferror](../../c-runtime-library/reference/ferror.md)   
 [_fileno](../../c-runtime-library/reference/fileno.md)   
 [fopen, _wfopen](../../c-runtime-library/reference/fopen-wfopen.md)   
 [freopen, _wfreopen](../../c-runtime-library/reference/freopen-wfreopen.md)   
 [_open, _wopen](../../c-runtime-library/reference/open-wopen.md)   
 [_setmode](../../c-runtime-library/reference/setmode.md)   
 [_sopen, _wsopen](../../c-runtime-library/reference/sopen-wsopen.md)
