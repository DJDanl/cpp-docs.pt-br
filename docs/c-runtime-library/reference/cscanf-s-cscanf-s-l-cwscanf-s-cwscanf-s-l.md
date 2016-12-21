---
title: "_cscanf_s, _cscanf_s_l, _cwscanf_s, _cwscanf_s_l | Microsoft Docs"
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
  - "_cwscanf_s_l"
  - "_cwscanf_s"
  - "_cscanf_s"
  - "_cscanf_s_l"
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
apitype: "DLLExport"
f1_keywords: 
  - "cscanf_s"
  - "cscanf_s_l"
  - "cwscanf_s"
  - "_cwscanf_s"
  - "_tcscanf_s"
  - "_cscanf_s"
  - "_cwscanf_s_l"
  - "_cscanf_s_l"
  - "cwscanf_s_l"
  - "_tcscanf_s_l"
  - "tcscanf_s"
  - "tcscanf_s_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _cscanf_s"
  - "Função _cscanf_s_l"
  - "Função _cwscanf_s"
  - "Função _cwscanf_s_l"
  - "Função _tcscanf_s"
  - "Função _tcscanf_s_l"
  - "console [C++], lendo de"
  - "Função cscanf_s"
  - "Função cscanf_s_l"
  - "Função cwscanf_s"
  - "Função cwscanf_s_l"
  - "dados [C++], lendo a partir do console"
  - "lendo dados [C++], a partir do console"
  - "Função tcscanf_s"
  - "Função tcscanf_s_l"
ms.assetid: 9ccab74d-916f-42a6-93d8-920525efdf4b
caps.latest.revision: 24
caps.handback.revision: 24
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _cscanf_s, _cscanf_s_l, _cwscanf_s, _cwscanf_s_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Lê dados formatados a partir do console.  Essas versões mais seguras de [\_cscanf, \_cscanf\_l, \_cwscanf, \_cwscanf\_l](../../c-runtime-library/reference/cscanf-cscanf-l-cwscanf-cwscanf-l.md) têm aprimoramentos de segurança, como descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos que executam no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int _cscanf_s(   
   const char *format [,  
   argument] ...   
);  
int _cscanf_s_l(   
   const char *format,  
   locale_t locale [,  
   argument] ...   
);  
int _cwscanf_s(   
   const wchar_t *format [,  
   argument] ...   
);  
int _cwscanf_s_l(   
   const wchar_t *format,  
   locale_t locale [,  
   argument] ...   
);  
```  
  
#### Parâmetros  
 `format`  
 Cadeia de caracteres de controle de formato.  
  
 `argument`  
 Parâmetros opcionais.  
  
 `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 O número de campos que foram convertidos e atribuídos com êxito.  O valor de retorno não inclui os campos que foram lidos, mas não atribuídos.  O valor de retorno é `EOF` para uma tentativa de leitura no fim do arquivo.  Isso pode ocorrer quando a entrada do teclado é redirecionada no nível de linha de comando do sistema operacional.  Um valor de retorno 0 significa que nenhum campo foi atribuído.  
  
 Essas funções validam seus parâmetros.  Se `format` for um ponteiro nulo, essas funções chamarão o manipulador de parâmetro inválido, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções retornarão `EOF` e `errno`será definido como `EINVAL`.  
  
## Comentários  
 A função de `_cscanf_s` lê os dados diretamente do console em locais fornecidos por `argument`.  A função [\_getche](../Topic/_getch,%20_getwch.md) é usada para ler caracteres.  Cada parâmetro opcional deve ser um ponteiro para uma variável com um tipo que corresponde a um especificador de tipo em `format`.  O formato controla a interpretação dos campos de entrada e tem o mesmo formulário e função do parâmetro `format` para a função de [scanf\_s](../../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md).  Embora o `_cscanf_s` ecoe normalmente o caractere de entrada, ele não faz isso se a última chamada foi para `_ungetch`.  
  
 Assim como outras versões seguras das funções na família de `scanf`, `_cscanf_s` e `_cswscanf_s` exigem argumentos de tamanho para os caracteres `c`, `C`, `s`, `S`, e `[` do campo de tipo.  Para obter mais informações, consulte [Especificação de largura scanf Width](../../c-runtime-library/scanf-width-specification.md).  
  
> [!NOTE]
>  O parâmetro de tamanho é do tipo `unsigned`, e não `size_t`.  
  
 As versões dessas funções com o sufixo `_l` são idênticas, exceto que usam o parâmetro de localidade passado em vez da localidade de thread atual.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tcscanf_s`|`_cscanf_s`|`_cscanf_s`|`_cwscanf_s`|  
|`_tcscanf_s_l`|`_cscanf_s_l`|`_cscanf_s_l`|`_cwscanf_s_l`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_cscanf_s`,`_cscanf_s_l`|\<conio.h\>|  
|`_cwscanf_s`, `_cwscanf_s_l`|\<conio.h\> ou \<wchar.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Bibliotecas  
 Todas as versões das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
  
```  
// crt_cscanf_s.c  
// compile with: /c  
/* This program prompts for a string  
 * and uses _cscanf_s to read in the response.  
 * Then _cscanf_s returns the number of items  
 * matched, and the program displays that number.  
 */  
  
#include <stdio.h>  
#include <conio.h>  
  
int main( void )  
{  
   int result, n[3];  
   int i;  
  
   result = _cscanf_s( "%i %i %i", &n[0], &n[1], &n[2] );  
   _cprintf_s( "\r\nYou entered " );  
   for( i=0; i<result; i++ )  
      _cprintf_s( "%i ", n[i] );  
   _cprintf_s( "\r\n" );  
}  
```  
  
## Entrada  
  
```  
1 2 3  
```  
  
## Saída  
  
```  
You entered 1 2 3  
```  
  
## Consulte também  
 [Console e E\/S de porta](../../c-runtime-library/console-and-port-i-o.md)   
 [\_cprintf, \_cprintf\_l, \_cwprintf, \_cwprintf\_l](../../c-runtime-library/reference/cprintf-cprintf-l-cwprintf-cwprintf-l.md)   
 [fscanf\_s, \_fscanf\_s\_l, fwscanf\_s, \_fwscanf\_s\_l](../../c-runtime-library/reference/fscanf-s-fscanf-s-l-fwscanf-s-fwscanf-s-l.md)   
 [scanf\_s, \_scanf\_s\_l, wscanf\_s, \_wscanf\_s\_l](../../c-runtime-library/reference/scanf-s-scanf-s-l-wscanf-s-wscanf-s-l.md)   
 [sscanf\_s, \_sscanf\_s\_l, swscanf\_s, \_swscanf\_s\_l](../Topic/sscanf_s,%20_sscanf_s_l,%20swscanf_s,%20_swscanf_s_l.md)