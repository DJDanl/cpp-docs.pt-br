---
title: "gets, _getws | Microsoft Docs"
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
  - "_getws"
  - "gets"
apilocation: 
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr120.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcrt.dll"
  - "msvcr100.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_getts"
  - "gets"
  - "_getws"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função getws"
  - "Função getts"
  - "Função _getws"
  - "linhas, obtendo"
  - "fluxos, obtendo linhas"
  - "Função _getts"
  - "Função gets"
  - "entrada padrão, lendo de"
ms.assetid: 1ec2dd4b-f801-48ea-97c2-892590f16024
caps.latest.revision: 32
caps.handback.revision: 32
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# gets, _getws
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Obtém uma linha do `stdin` fluxo. Versões mais seguras dessas funções estão disponíveis; consulte [gets\_s, \_getws\_s](../c-runtime-library/reference/gets-s-getws-s.md).  
  
> [!IMPORTANT]
>  Essas funções são obsoletas. A partir do Visual Studio 2015, eles não estão disponíveis no CRT. As versões seguras dessas funções, gets\_s e getws\_s, ainda estão disponíveis. Para obter informações sobre essas funções alternativas, consulte [gets\_s, \_getws\_s](../c-runtime-library/reference/gets-s-getws-s.md).  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no tempo de execução do Windows. Para obter mais informações, consulte [funções de CRT não têm suportadas com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
char *gets(   
   char *buffer   
);  
wchar_t *_getws(   
   wchar_t *buffer   
);  
template <size_t size>  
char *gets(   
   char (&buffer)[size]  
); // C++ only  
template <size_t size>  
wchar_t *_getws(   
   wchar_t (&buffer)[size]  
); // C++ only  
```  
  
#### Parâmetros  
 `buffer`  
 Local de armazenamento para a cadeia de caracteres de entrada.  
  
## Valor de retorno  
 Retorna o argumento se for bem\-sucedido. Um `NULL` ponteiro indica uma condição de erro ou o final do arquivo. Use [ferror](../c-runtime-library/reference/ferror.md) ou [feof](../c-runtime-library/reference/feof.md) para determinar qual deles ocorreu. Se `buffer` for `NULL`, essas funções chamar um manipulador de parâmetro inválido, conforme descrito em [Validação do parâmetro](../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornam `NULL` e defina errno como `EINVAL`.  
  
## Comentários  
 O `gets` função lê uma linha do fluxo de entrada padrão `stdin` e armazena em `buffer`. A linha consiste em todos os caracteres até e incluindo o primeiro caractere de nova linha \('\\n'\).`gets` em seguida, substitui o caractere de nova linha com um caractere nulo \('\\0'\) antes de retornar a linha. Por outro lado, o `fgets` função retém o caractere de nova linha.`_getws` é uma versão de caractere largo de `gets`; seu argumento e o valor de retorno são cadeias de caracteres largos.  
  
> [!IMPORTANT]
>  Porque não há nenhuma maneira para limitar o número de caracteres lidos por obtém, entradas não confiáveis podem facilmente causar estouros de buffer. Use `fgets` em vez disso.  
  
 No C\+\+, essas funções têm sobrecargas de modelo que invocam as contrapartes seguros, mais recentes dessas funções. Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
### Mapeamentos de rotina de texto genérico  
  
|TCHAR. Rotina H|Unicode e MBCS não definidos|MBCS definido|Unicode definido|  
|---------------------|----------------------------------|-------------------|----------------------|  
|`_getts`|`gets`|`gets`|`_getws`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`gets`|\< stdio \>|  
|`_getws`|\< stdio \> ou \< WCHAR \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [compatibilidade](../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_gets.c  
// compile with: /WX /W3  
  
#include <stdio.h>  
  
int main( void )  
{  
   char line[21]; // room for 20 chars + '\0'  
   gets( line );  // C4996  
   // Danger: No way to limit input to 20 chars.  
   // Consider using gets_s instead.  
   printf( "The line entered was: %s\n", line );  
}  
```  
  
 Observe que a entrada mais do que 20 caracteres irá saturar o buffer de linha e certamente fazer com que o programa falhe.  
  
```Output  
  
Hello there!A linha inserida foi: bom dia!  
```  
  
## Equivalência do .NET Framework  
 [System::console::Read](https://msdn.microsoft.com/en-us/library/system.console.read.aspx)  
  
## Consulte também  
 [E\/S de fluxo](../c-runtime-library/stream-i-o.md)   
 [fgets, fgetws](../c-runtime-library/reference/fgets-fgetws.md)   
 [fputs, fputws](../Topic/fputs,%20fputws.md)   
 [puts, \_putws](../Topic/puts,%20_putws.md)