---
title: "_popen, _wpopen | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_popen"
  - "_wpopen"
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
  - "tpopen"
  - "popen"
  - "wpopen"
  - "_popen"
  - "_wpopen"
  - "_tpopen"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _popen"
  - "Função _tpopen"
  - "Função _wpopen"
  - "pipes, criando"
  - "Função popen"
  - "Função tpopen"
  - "Função wpopen"
ms.assetid: eb718ff2-c87d-4bd4-bd2e-ba317c3d6973
caps.latest.revision: 15
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _popen, _wpopen
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Cria um pipe e executa um comando.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos que executam no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
  
      FILE *_popen(  
const char *command,  
const char *mode   
);  
FILE *_wpopen(  
const wchar_t *command,  
const wchar_t *mode   
);  
```  
  
#### Parâmetros  
 *comando*  
 Comando a ser executado.  
  
 *mode*  
 Modo de fluxo retornado.  
  
## Valor de retorno  
 Retorna um fluxo associado a uma extremidade do pipe criado.  A outra extremidade do pipe será associada à saída padrão de entrada ou padrão de comando gerado.  As funções **nulo** de retorno em um erro.  Se o erro for um parâmetro inválido, como se *o comando* ou no *modo* for um ponteiro nulo, ou *o modo* não é um modo válido, `errno` está definido como `EINVAL`.  Consulte a seção comentários para modos válidos.  
  
 Para obter informações sobre esses e outros códigos de erro, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 A função de `_popen` cria um pipe e executar de forma assíncrona uma cópia desovada do processador de comando com *o comando*especificado de cadeia de caracteres.  *O modo* de cadeia de caracteres especifica o tipo de acesso solicitado, como a seguir.  
  
 **"r"**  
 O processo de chamada pode ler a saída padrão do comando gerado usando o fluxo retornado.  
  
 **"w"**  
 O processo de chamada pode gravar na entrada de comando padrão gerado que usa o fluxo retornado.  
  
 **"b"**  
 Abrir no modo binário.  
  
 **"t"**  
 Abrir no modo de texto.  
  
> [!NOTE]
>  Se usado em um programa do windows, a função de `_popen` retorna um ponteiro de arquivo inválido que faz com que o programa pare de responder indefinidamente.  `_popen` funciona corretamente em um aplicativo de console.  Para criar um aplicativo do Windows que redireciona a entrada e as saídas, consulte [Criando um processo filho com a entrada e a saída redirecionada](http://msdn.microsoft.com/library/windows/desktop/ms682499) em [!INCLUDE[winsdkshort](../../atl/reference/includes/winsdkshort_md.md)].  
  
 `_wpopen` é uma versão de ampla caractere de `_popen`; o argumento *de caminho* a `_wpopen` é uma cadeia de caracteres de ampla caractere.  Caso contrário, `_wpopen` e `_popen`, ao contrário, se comportam de forma idêntica.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tpopen`|`_popen`|`_popen`|`_wpopen`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_popen`|\<stdio.h\>|  
|`_wpopen`|\<stdio.h\> ou \<wchar.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Bibliotecas  
 Todas as versões das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
  
```  
// crt_popen.c  
/* This program uses _popen and _pclose to receive a   
 * stream of text from a system process.  
 */  
  
#include <stdio.h>  
#include <stdlib.h>  
  
int main( void )  
{  
  
   char   psBuffer[128];  
   FILE   *pPipe;  
  
        /* Run DIR so that it writes its output to a pipe. Open this  
         * pipe with read text attribute so that we can read it   
         * like a text file.   
         */  
  
   if( (pPipe = _popen( "dir *.c /on /p", "rt" )) == NULL )  
      exit( 1 );  
  
   /* Read pipe until end of file, or an error occurs. */  
  
   while(fgets(psBuffer, 128, pPipe))  
   {  
      printf(psBuffer);  
   }  
  
   /* Close pipe and print return value of pPipe. */  
   if (feof( pPipe))  
   {  
     printf( "\nProcess returned %d\n", _pclose( pPipe ) );  
   }  
   else  
   {  
     printf( "Error: Failed to read the pipe to the end.\n");  
   }  
}  
```  
  
## Saída de Exemplo  
 Essa saída assumem que há apenas um arquivo no diretório atual com a extensão de nome de arquivo de C.A.  
  
```  
 Volume in drive C is CDRIVE  
 Volume Serial Number is 0E17-1702  
  
 Directory of D:\proj\console\test1  
  
07/17/98  07:26p                   780 popen.c  
               1 File(s)            780 bytes  
                             86,597,632 bytes free  
  
Process returned 0  
```  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Processo e controle de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [\_pclose](../Topic/_pclose.md)   
 [\_pipe](../../c-runtime-library/reference/pipe.md)