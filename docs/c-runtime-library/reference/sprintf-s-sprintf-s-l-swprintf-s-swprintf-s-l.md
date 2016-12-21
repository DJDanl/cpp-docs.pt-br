---
title: "sprintf_s, _sprintf_s_l, swprintf_s, _swprintf_s_l | Microsoft Docs"
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
  - "_swprintf_s_l"
  - "_sprintf_s_l"
  - "swprintf_s"
  - "sprintf_s"
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
  - "swprintf_s"
  - "sprintf_s"
  - "stdio/sprintf_s"
  - "stdio/swprintf_s"
  - "stdio/_sprintf_s_l"
  - "stdio/_swprintf_s_l"
  - "_sprintf_s_l"
  - "_swprintf_s_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função stprintf_s"
  - "Função stprintf_s_l"
  - "Função swprintf_s_l"
  - "Função sprintf_s"
  - "Função swprintf_s"
  - "Função _swprintf_s_l"
  - "Função sprintf_s_l"
  - "Função _stprintf_s_l"
  - "Função _stprintf_s"
  - "Função _sprintf_s_l"
  - "texto formatado [C++]"
ms.assetid: 424f0a29-22ef-40e8-b565-969f5f57782f
caps.latest.revision: 26
caps.handback.revision: 26
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# sprintf_s, _sprintf_s_l, swprintf_s, _swprintf_s_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Grava dados formatados em uma cadeia de caracteres. Essas são versões de [sprintf, \_sprintf\_l, swprintf, \_swprintf\_l, \_\_swprintf\_l](../../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md) com aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
int sprintf_s(  
   char *buffer,  
   size_t sizeOfBuffer,  
   const char *format,  
   ...   
);  
int _sprintf_s_l(  
   char *buffer,  
   size_t sizeOfBuffer,  
   const char *format,  
   locale_t locale,  
   ...   
);  
int swprintf_s(  
   wchar_t *buffer,  
   size_t sizeOfBuffer,  
   const wchar_t *format,  
   ...  
);  
int _swprintf_s_l(  
   wchar_t *buffer,  
   size_t sizeOfBuffer,  
   const wchar_t *format,  
   locale_t locale,  
   ...  
);  
template <size_t size>  
int sprintf_s(  
   char (&buffer)[size],  
   const char *format,  
   ...   
); // C++ only  
template <size_t size>  
int swprintf_s(  
   wchar_t (&buffer)[size],  
   const wchar_t *format,  
   ...  
); // C++ only  
```  
  
#### Parâmetros  
 `buffer`  
 Local de armazenamento para saída  
  
 `sizeOfBuffer`  
 Número máximo de caracteres a ser armazenado.  
  
 `format`  
 Cadeia de caracteres de controle de formato  
  
 `...`  
 Argumentos opcionais para ser formatado  
  
 `locale`  
 A localidade a ser usada.  
  
 Para obter mais informações, consulte [especificações de formato](../Topic/Format%20Specification%20Syntax:%20printf%20and%20wprintf%20Functions.md).  
  
## Valor de retorno  
 O número de caracteres gravados, ou \-1 se ocorreu um erro. Se `buffer` ou `format` é um ponteiro nulo, `sprintf_s` e `swprintf_s` retornar \-1 e definir `errno` para `EINVAL`.  
  
 `sprintf_s` Retorna o número de bytes armazenados em `buffer`, sem contar o caractere de terminação nula.`swprintf_s` Retorna o número de caracteres largos armazenados em `buffer`, sem contar o caractere largo nulo de terminação.  
  
## Comentários  
 O `sprintf_s` função formata e armazena uma série de caracteres e valores em `buffer`. Cada `argument` \(se houver\) é convertido e saída de acordo com a especificação de formato correspondente em `format`. O formato consiste em caracteres comuns e tem o mesmo formato e função que o `format` argumento [printf](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md). Um caractere nulo é acrescentado após o último caractere escrito. Se ocorrer cópia entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.  
  
 Uma das principal diferenças entre `sprintf_s` e `sprintf` é que `sprintf_s` verifica a cadeia de caracteres de formato para caracteres de formatação válidos, enquanto `sprintf` só verifica se o buffer ou cadeia de caracteres de formato são `NULL` ponteiros. Se a verificação falhar, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função retornará \-1 e conjuntos de `errno` para `EINVAL`.  
  
 A diferença principal entre `sprintf_s` e `sprintf` é que `sprintf_s` assume um parâmetro de comprimento que especifica o tamanho do buffer de saída em caracteres. Se o buffer é muito pequeno para o texto formatado, incluindo a terminação nula, e o buffer é definido como uma cadeia de caracteres vazia, colocando um caractere nulo no `buffer``[0]`, e o manipulador de parâmetro inválido é invocado. Ao contrário de `_snprintf`, `sprintf_s` garante que o buffer será ser terminada em nulo, a menos que o tamanho do buffer é zero.  
  
 `swprintf_s` é uma versão de caractere largo de `sprintf_s`; os argumentos de ponteiro para `swprintf_s` são cadeias de caracteres largos. Detecção de erros de codificação `swprintf_s` pode ser diferente no `sprintf_s`. As versões dessas funções com o `_l` sufixo são idênticas, exceto que eles usam o parâmetro de localidade passado em vez da localidade do thread atual.  
  
 No C\+\+, o uso dessas funções é simplificado pela sobrecargas de modelo; as sobrecargas podem inferir o comprimento de buffer automaticamente, que elimina a necessidade de especificar um argumento de tamanho, e eles automaticamente podem substituir funções mais antigas e não seguras com suas contrapartes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
 Há versões de `sprintf_s` que oferecem mais controle sobre o que acontece se o buffer é muito pequeno. Para obter mais informações, consulte [\_snprintf\_s, \_snprintf\_s\_l, \_snwprintf\_s, \_snwprintf\_s\_l](../../c-runtime-library/reference/snprintf-s-snprintf-s-l-snwprintf-s-snwprintf-s-l.md).  
  
### Mapeamentos de rotina de texto genérico  
  
|TCHAR. Rotina H|Unicode e MBCS não definidos|MBCS definido|Unicode definido|  
|---------------------|----------------------------------|-------------------|----------------------|  
|`_stprintf_s`|`sprintf_s`|`sprintf_s`|`swprintf_s`|  
|`_stprintf_s_l`|`_sprintf_s_l`|`_sprintf_s_l`|`_swprintf_s_l`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`sprintf_s`, `_sprintf_s_l`|C: \< stdio \><br /><br /> C\+\+: \< cstdio \> ou \< stdio \>|  
|`swprintf_s`, `_swprintf_s_l`|C: \< stdio \> ou \< WCHAR \><br /><br /> C\+\+: \< cstdio \>, \< cwchar \>, \< stdio \> ou \< WCHAR \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_sprintf_s.c  
// This program uses sprintf_s to format various  
// data and place them in the string named buffer.  
//  
  
#include <stdio.h>  
  
int main( void )  
{  
   char  buffer[200], s[] = "computer", c = 'l';  
   int   i = 35, j;  
   float fp = 1.7320534f;  
  
   // Format and print various data:   
   j  = sprintf_s( buffer, 200,     "   String:    %s\n", s );  
   j += sprintf_s( buffer + j, 200 - j, "   Character: %c\n", c );  
   j += sprintf_s( buffer + j, 200 - j, "   Integer:   %d\n", i );  
   j += sprintf_s( buffer + j, 200 - j, "   Real:      %f\n", fp );  
  
   printf_s( "Output:\n%s\ncharacter count = %d\n", buffer, j );  
}  
```  
  
```Output  
Saída: a cadeia de caracteres: computador caractere: l inteiro: 35 Real: contagem de caracteres 1.732053 = 79  
```  
  
## Exemplo  
  
```  
// crt_swprintf_s.c  
// wide character example  
// also demonstrates swprintf_s returning error code  
#include <stdio.h>  
  
int main( void )  
{  
   wchar_t buf[100];  
   int len = swprintf_s( buf, 100, L"%s", L"Hello world" );  
   printf( "wrote %d characters\n", len );  
   len = swprintf_s( buf, 100, L"%s", L"Hello\xffff world" );  
   // swprintf_s fails because string contains WEOF (\xffff)  
   printf( "wrote %d characters\n", len );  
}  
```  
  
```Output  
escrevi 11 caracteres escreveram caracteres-1  
```  
  
## Equivalência do .NET Framework  
 [System::String::Format](https://msdn.microsoft.com/en-us/library/system.string.format.aspx)  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fprintf, \_fprintf\_l, fwprintf, \_fwprintf\_l](../../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md)   
 [printf, \_printf\_l, wprintf, \_wprintf\_l](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [scanf, \_scanf\_l, wscanf, \_wscanf\_l](../../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md)   
 [sscanf, \_sscanf\_l, swscanf, \_swscanf\_l](../../c-runtime-library/reference/sscanf-sscanf-l-swscanf-swscanf-l.md)   
 [Funções vprintf](../../c-runtime-library/vprintf-functions.md)