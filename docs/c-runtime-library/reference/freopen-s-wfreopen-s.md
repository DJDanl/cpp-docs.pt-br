---
title: freopen_s, _wfreopen_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _wfreopen_s
- freopen_s
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
- freopen_s
- _tfreopen_s
- _wfreopen_s
dev_langs:
- C++
helpviewer_keywords:
- _tfreopen_s function
- _wfreopen_s function
- file pointers [C++], reassigning
- tfreopen_s function
- wfreopen_s function
- freopen_s function
ms.assetid: ad25a4da-6ad4-476b-a86d-660b221ca84d
caps.latest.revision: 27
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
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 28210b879c227b2200a4d6f9811c1cf53fce2330
ms.lasthandoff: 02/25/2017

---
# <a name="freopens-wfreopens"></a>freopen_s, _wfreopen_s
Reatribui um ponteiro de arquivo. Estas versões de [freopen, _wfreopen](../../c-runtime-library/reference/freopen-wfreopen.md) têm melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t freopen(   
   FILE** pFile,  
   const char *path,  
   const char *mode,  
   FILE *stream   
);  
errno_t _wfreopen(   
   FILE** pFile,  
   const wchar_t *path,  
   const wchar_t *mode,  
   FILE *stream   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [out] `pFile`  
 Um ponteiro para o ponteiro de arquivo a ser fornecido pela chamada.  
  
 [in] `path`  
 Caminho do novo arquivo.  
  
 [in] `mode`  
 Tipo de acesso permitido.  
  
 [in] `stream`  
 Ponteiro para a estrutura `FILE`.  
  
## <a name="return-value"></a>Valor de retorno  
 Cada uma dessas funções retorna um código de erro. Se ocorrer um erro, o arquivo original será fechado.  
  
## <a name="remarks"></a>Comentários  
 A função `freopen_s` fecha o arquivo atualmente associado a `stream` e reatribui `stream` ao arquivo especificado por `path.`, `_wfreopen_s` é uma versão de caractere largo de `_freopen_s` e os argumentos `path` e `mode` para `_wfreopen_s` são cadeias de caracteres largos. Caso contrário, `_wfreopen_s` e `_freopen_s` se comportam de forma idêntica.  
  
 Se `pFile`, `path`, `mode` ou `stream` forem `NULL` ou se `path` for uma cadeia de caracteres vazia, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções definirão `errno` como `EINVAL` e retornarão `EINVAL`.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tfreopen_s`|`freopen_s`|`freopen_s`|`_wfreopen_s`|  
  
 `freopen_s` normalmente é usado para redirecionar os arquivos abertos previamente `stdin`, `stdout` e `stderr` para arquivos especificados pelo usuário. O novo arquivo associado a `stream` é aberto com `mode` *, *, que é uma cadeia de caracteres que especifica o tipo de acesso solicitado para o arquivo, da seguinte maneira:  
  
 `"r"`  
 Abre para leitura. Se o arquivo não existir ou não puder ser encontrado, a chamada `freopen_s` falha.  
  
 `"w"`  
 Abre um arquivo vazio para gravação. Se o arquivo determinado existir, seus conteúdos são destruídos.  
  
 `"a"`  
 É aberto para gravação no fim do arquivo (acréscimo) sem remover o marcador de EOF antes de gravar novos no arquivo, criará o arquivo primeiro se ele não existir.  
  
 `"r+"`  
 Abre para leitura e gravação. (O arquivo deve existir.)  
  
 `"w+"`  
 Abre um arquivo vazio para leitura e gravação. Se o arquivo determinado existir, seus conteúdos são destruídos.  
  
 `"a+"`  
 Abre para leitura e acréscimo; a operação de acréscimo inclui a remoção do marcador de EOF antes que novos dados sejam gravados no arquivo e o marcador de EOF é restaurado após a gravação ser concluída; criará o arquivo primeiro se ele não existir.  
  
 Use os tipos `"w"` e `"w+"` com cuidado, pois eles podem destruir arquivos existentes.  
  
 Quando um arquivo é aberto com o tipo de acesso `"a"` ou `"a+"`, todas as operações de gravação ocorrem no fim do arquivo. Embora o ponteiro do arquivo possa ser reposicionado usando `fseek` ou `rewind`, ele sempre é movido de volta para o final do arquivo antes que qualquer operação de gravação seja realizada. Sendo assim, dados existentes não podem ser substituídos.  
  
 O modo `"a"` não remove o marcador de EOF antes de ser acrescentado ao arquivo. Depois de a conexão ter ocorrido, o comando MS-DOS TYPE só mostra dados até o marcador de EOF original, e não qualquer dado anexado ao arquivo. O modo `"a+"` remove o marcador de EOF antes de ser acrescentado ao arquivo. Depois de anexar, o comando MS-DOS TYPE mostra todos os dados no arquivo. O modo `"a+"` é exigido para conexão com um arquivo de fluxo terminado com o marcador de EOF CTRL+Z.  
  
 Quando o tipo de acesso `"r+",``"w+",` ou `"a+"` é especificado, são permitidas leitura e gravação (diz-se que o arquivo está aberto para "atualização"). No entanto, quando você muda entre leitura e gravação, deve haver uma operação [fsetpos](../../c-runtime-library/reference/fsetpos.md), [fseek](../../c-runtime-library/reference/fseek-fseeki64.md) ou [rewind](../../c-runtime-library/reference/rewind.md) intermediária. A posição atual pode ser especificada para a operação `fsetpos` ou `fseek`, se desejado. Além dos valores acima, um dos caracteres seguintes pode ser incluído na cadeia de caracteres `mode` para especificar o modo de conversão para novas linhas.  
  
 `t`  
 Abrir no modo de texto (convertido); combinações de CR-LF (retorno de carro – avanço de linha) são convertidas em caracteres de LF (avanço de linha) simples na entrada, caracteres de LF são convertidos em combinações de CR-LF na saída. Além disso, CTRL+Z é interpretado como um caractere de fim do arquivo na entrada. Em arquivos abertos para leitura ou para leitura e gravação com `"a+"`, a biblioteca em tempo de execução verifica se há um CTRL+Z no fim do arquivo e o remove, se possível. Isso é feito porque usar `fseek` e `ftell` para movimentação dentro de um arquivo pode fazer o `fseek` se comportar incorretamente perto do fim do arquivo. A opção `t` é uma extensão da Microsoft que não deve ser usada quando se desejar portabilidade ANSI.  
  
 `b`  
 Abrir no modo binário (não convertido); as conversões acima são suprimidas.  
  
 Se `t` ou `b` não for fornecido em `mode`, o modo de conversão padrão será definido pela variável global [_fmode](../../c-runtime-library/fmode.md). Se `t` ou `b` for prefixado para o argumento, a função falha e retorna `NULL`.  
  
 Para saber mais sobre os modos de texto e binário, consulte [E/S de texto e arquivo de modo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`freopen_s`|\<stdio.h>|  
|`_wfreopen_s`|\<stdio.h> ou \<wchar.h>|  
  
 Não há suporte para o console em aplicativos [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)]. Os identificadores de fluxo padrão associados ao console – `stdin`, `stdout` e `stderr` – devem ser redirecionados antes que as funções em tempo de execução C possam usá-los em aplicativos [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)]. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_freopen_s.c  
// This program reassigns stderr to the file  
// named FREOPEN.OUT and writes a line to that file.  
  
#include <stdio.h>  
#include <stdlib.h>  
  
FILE *stream;  
  
int main( void )  
{  
   errno_t err;  
   // Reassign "stderr" to "freopen.out":   
   err = freopen_s( &stream, "freopen.out", "w", stderr );  
  
   if( err != 0 )  
      fprintf( stdout, "error on freopen\n" );  
   else  
   {  
      fprintf( stdout, "successfully reassigned\n" ); fflush( stdout );  
      fprintf( stream, "This will go to the file 'freopen.out'\n" );  
      fclose( stream );  
   }  
   system( "type freopen.out" );  
}  
```  
  
```Output  
successfully reassigned  
This will go to the file 'freopen.out'  
```  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
  
-   [System::IO::File::Open](https://msdn.microsoft.com/en-us/library/system.io.file.open.aspx)  
  
-   <xref:System.IO.FileStream.%23ctor%2A>  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [freopen, _wfreopen](../../c-runtime-library/reference/freopen-wfreopen.md)   
 [fclose, _fcloseall](../../c-runtime-library/reference/fclose-fcloseall.md)   
 [_fdopen, _wfdopen](../../c-runtime-library/reference/fdopen-wfdopen.md)   
 [_fileno](../../c-runtime-library/reference/fileno.md)   
 [fopen, _wfopen](../../c-runtime-library/reference/fopen-wfopen.md)   
 [_open, _wopen](../../c-runtime-library/reference/open-wopen.md)   
 [_setmode](../../c-runtime-library/reference/setmode.md)
