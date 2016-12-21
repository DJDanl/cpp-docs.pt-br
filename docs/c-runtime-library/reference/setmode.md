---
title: "_setmode | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_setmode"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-stdio-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_setmode"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _setmode"
  - "tradução de arquivo [C++], definindo modo"
  - "Arquivos  [C++], modos"
  - "Arquivos  [C++], tradução"
  - "Função setmode"
  - "Unicode [C++], saída de console"
ms.assetid: 996ff7cb-11d1-43f4-9810-f6097182642a
caps.latest.revision: 23
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _setmode
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define o modo de tradução do arquivo.  
  
## Sintaxe  
  
```  
int _setmode (    int fd,    int mode  );  
```  
  
#### Parâmetros  
 `fd`  
 Descritor de arquivo.  
  
 `mode`  
 Novo modo de conversão.  
  
## Valor de retorno  
 Se bem\-sucedido, retorna para o modo de conversão anterior.  
  
 Se parâmetros inválidos forem enviados a essa função, o manipulador de parâmetro inválido é chamado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essa função retorna –1 e define `errno` para `EBADF`, que indica um descritor de arquivo inválido ou `EINVAL`, que indica um argumento `mode` inválido.  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [\_doserrno, errno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 A função `_setmode` define para `mode` o modo de conversão do arquivo fornecido por `fd`.  Passar `_O_TEXT` como `mode` define o modo de texto \(ou seja, convertido\).  Combinações CR\-LF \(Retorno de carro–alimentação de linha\) são convertidas para um único caractere de alimentação de linha na entrada.  Os caracteres de alimentação de linha são convertidos para combinações CR\-LF na saída.  Passar `_O_BINARY` define o modo binário \(não traduzido\), em que essas conversões são suprimidas.  
  
 Você também pode passar `_O_U16TEXT`, `_O_U8TEXT` ou \_`O_WTEXT` para habilitar o modo Unicode, como demonstrado no segundo exemplo mais adiante neste documento.  `_setmode` normalmente é usado para modificar o modo de conversão padrão de `stdin` e `stdout`, mas você pode usá\-lo em qualquer arquivo.  Se você aplicar `_setmode` ao descritor de arquivo para um fluxo, chame `_setmode` antes de realizar alguma operação de entrada ou saída no fluxo.  
  
> [!CAUTION]
>  Se você gravar dados em um fluxo de arquivo, limpe explicitamente o código usando [fflush](../Topic/fflush.md) antes de usar `_setmode` para alterar o modo.  Se você não limpar o código, pode ocorrer comportamento inesperado.  Se você não tiver dados gravados no fluxo, não será preciso limpar o código.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalhos opcionais|  
|------------|--------------------------|--------------------------|  
|`_setmode`|\<io.h\>|\<fcntl.h\>|  
  
 Para obter mais informações de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_setmode.c  
// This program uses _setmode to change  
// stdin from text mode to binary mode.  
  
#include <stdio.h>  
#include <fcntl.h>  
#include <io.h>  
  
int main( void )  
{  
   int result;  
  
   // Set "stdin" to have binary mode:  
   result = _setmode( _fileno( stdin ), _O_BINARY );  
   if( result == -1 )  
      perror( "Cannot set mode" );  
   else  
      printf( "'stdin' successfully changed to binary mode\n" );  
}  
```  
  
  **'stdin' foi alterado com sucesso para o modo binário**   
## Exemplo  
  
```  
// crt_setmodeunicode.c  
// This program uses _setmode to change  
// stdout to Unicode. Cyrillic and Ideographic  
// characters will appear on the console (if  
// your console font supports those character sets).  
  
#include <fcntl.h>  
#include <io.h>  
#include <stdio.h>  
  
int main(void) {  
    _setmode(_fileno(stdout), _O_U16TEXT);  
    wprintf(L"\x043a\x043e\x0448\x043a\x0430 \x65e5\x672c\x56fd\n");  
    return 0;  
}  
  
```  
  
## Equivalente ao .NET Framework  
  
-   [\<caps:sentence id\="tgt28" sentenceid\="fe03c471a7a38d5378cea62467482dae" class\="tgtSentence"\>Classe System::IO::BinaryReader\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.io.binaryreader.aspx)  
  
-   [\<caps:sentence id\="tgt29" sentenceid\="105e62b7505c25e3e182779c87f145eb" class\="tgtSentence"\>Classe System::IO::TextReader\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.io.textreader.aspx)  
  
## Consulte também  
 [Manipulação de arquivos](../../c-runtime-library/file-handling.md)   
 [\_creat, \_wcreat](../../c-runtime-library/reference/creat-wcreat.md)   
 [fopen, \_wfopen](../../c-runtime-library/reference/fopen-wfopen.md)   
 [\_open, \_wopen](../../c-runtime-library/reference/open-wopen.md)   
 [\_set\_fmode](../../c-runtime-library/reference/set-fmode.md)