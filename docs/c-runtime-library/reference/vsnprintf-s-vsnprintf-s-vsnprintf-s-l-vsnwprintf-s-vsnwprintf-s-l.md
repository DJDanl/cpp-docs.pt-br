---
title: "vsnprintf_s, _vsnprintf_s, _vsnprintf_s_l, _vsnwprintf_s, _vsnwprintf_s_l | Microsoft Docs"
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
  - "_vsnwprintf_s"
  - "_vsnwprintf_s_l"
  - "_vsnprintf_s"
  - "vsnprintf_s"
  - "_vsnprintf_s_l"
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
  - "_vsnprintf_s"
  - "_vsntprintf_s"
  - "_vsnwprintf_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _vsnprintf_s"
  - "Função _vsnprintf_s_l"
  - "Função _vsntprintf_s"
  - "Função _vsntprintf_s_l"
  - "Função _vsnwprintf_s"
  - "Função _vsnwprintf_s_l"
  - "texto formatado [C++]"
  - "Função vsnprintf_s"
  - "Função vsnprintf_s_l"
  - "Função vsntprintf_s"
  - "Função vsntprintf_s_l"
  - "Função vsnwprintf_s"
  - "Função vsnwprintf_s_l"
ms.assetid: 147ccfce-58c7-4681-a726-ef54ac1c604e
caps.latest.revision: 30
caps.handback.revision: 28
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# vsnprintf_s, _vsnprintf_s, _vsnprintf_s_l, _vsnwprintf_s, _vsnwprintf_s_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A saída formatada de gravação usando um ponteiro para uma lista de argumentos.  Essas são as versões de [vsnprintf, \_vsnprintf, \_vsnprintf\_l, \_vsnwprintf, \_vsnwprintf\_l](../../c-runtime-library/reference/vsnprintf-vsnprintf-vsnprintf-l-vsnwprintf-vsnwprintf-l.md) com aprimoramentos de segurança, como descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
int vsnprintf_s(  
   char *buffer,  
   size_t sizeOfBuffer,  
   size_t count,  
   const char *format,  
   va_list argptr   
);  
int _vsnprintf_s(  
   char *buffer,  
   size_t sizeOfBuffer,  
   size_t count,  
   const char *format,  
   va_list argptr   
);  
int _vsnprintf_s_l(  
   char *buffer,  
   size_t sizeOfBuffer,  
   size_t count,  
   const char *format,  
   locale_t locale,  
   va_list argptr   
);  
int _vsnwprintf_s(  
   wchar_t *buffer,  
   size_t sizeOfBuffer,  
   size_t count,  
   const wchar_t *format,  
   va_list argptr   
);  
int _vsnwprintf_s_l(  
   wchar_t *buffer,  
   size_t sizeOfBuffer,  
   size_t count,  
   const wchar_t *format,  
   locale_t locale,  
   va_list argptr   
);  
template <size_t size>  
int _vsnprintf_s(  
   char (&buffer)[size],  
   size_t count,  
   const char *format,  
   va_list argptr   
); // C++ only  
template <size_t size>  
int _vsnwprintf_s(  
   wchar_t (&buffer)[size],  
   size_t count,  
   const wchar_t *format,  
   va_list argptr   
); // C++ only  
```  
  
#### Parâmetros  
 `buffer`  
 Local de armazenamento para saída.  
  
 `sizeOfBuffer`  
 O tamanho de `buffer` para saída, como a contagem de caracteres.  
  
 `count`  
 Número máximo de caracteres a serem gravados \(não incluindo o encerramento zero\), ou [\_TRUNCATE](../../c-runtime-library/truncate.md).  
  
 `format`  
 Especificação de formato.  
  
 `argptr`  
 Ponteiro para a lista de argumentos.  
  
 `locale`  
 A localidade a ser usada.  
  
 Para obter mais informações, consulte [Especificações de formato](../Topic/Format%20Specification%20Syntax:%20printf%20and%20wprintf%20Functions.md).  
  
## Valor de retorno  
 `vsnprintf_s`,`_vsnprintf_s` e `_vsnwprintf_s` retornam o número de caracteres gravados, não incluindo o terminador nulo, ou um valor negativo se um erro de saída ocorre.  `vsnprintf_s` é idêntico a `_vsnprintf_s`.  `vsnprintf_s` é incluído para conformidade com o padrão ANSI.  `_vnsprintf` é mantido para compatibilidade com versões anteriores.  
  
 Se o armazenamento necessário para armazenar os dados e um nulo encerrando exceder `sizeOfBuffer`, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md), a menos que `count` é [\_TRUNCATE](../../c-runtime-library/truncate.md), caso em que o máximo possível da cadeia de caracteres como caiba em `buffer` é gravado e \-1 retornado.  Se a execução continuará depois que o manipulador inválido do parâmetro, essas funções definem `buffer` a uma cadeia de caracteres vazia, definem `errno` a `ERANGE`, e o retorno \-1.  
  
 Se `buffer` ou `format` é um ponteiro de `NULL` , ou se `count` é menor ou igual a zero, o manipulador inválido do parâmetro é invocado.  Se a execução puder continuar, essas funções definirão `errno` para `EINVAL` e retornarão \-1.  
  
### Condições de erro  
  
|`Condition`|Return|`errno`|  
|-----------------|------------|-------------|  
|`buffer` é `NULL`|\-1|`EINVAL`|  
|`format` é `NULL`|\-1|`EINVAL`|  
|`count` \<\= 0|\-1|`EINVAL`|  
|`sizeOfBuffer` muito pequeno \(e `count` \! \= `_TRUNCATE`\)|\-1 \(e `buffer` definido como uma cadeia de caracteres vazia\)|`ERANGE`|  
  
## Comentários  
 Cada uma dessas funções usa um ponteiro para uma lista de argumentos, então em formatos e prepara a `count` caracteres dos dados para a memória apontada por `buffer` e anexará um zero sendo encerrado.  
  
 Se `count` é [\_TRUNCATE](../../c-runtime-library/truncate.md), então essas funções gravam o máximo possível da cadeia de caracteres como caiba em `buffer` ao sair de espaço para um zero sendo encerrado.  Se os que a cadeia de caracteres \(com o término do zero\) em `buffer`, essas funções retornam o número de caracteres gravados \(não incluindo o terminador nulo\); caso contrário, essas funções retornam \-1 para indicar que o truncamento.  
  
 As versões dessas funções com o sufixo `_l` são idênticas, exceto que usam o parâmetro de localidade passado em vez da localidade de thread atual.  
  
> [!IMPORTANT]
>  Verifique se `format` não é uma cadeia de caracteres definida pelo usuário.  Para obter mais informações, consulte [Evitando saturações de buffer](http://msdn.microsoft.com/library/windows/desktop/ms717795).  
  
> [!NOTE]
>  Para garantir que haja uma espaço para o terminador nulo, certifique\-se de que `count` é estritamente menor que o comprimento do buffer, ou use `_TRUNCATE`.  
  
 No C\+\+, o uso dessas funções é simplificado por sobrecargas de modelo; as sobrecargas podem interpretar o tamanho do buffer automaticamente \(eliminando a necessidade de especificar um argumento de tamanho\) e podem substituir automaticamente as funções menos seguras mais antigas por correspondentes mais seguras e mais recentes.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_vsntprintf_s`|`_vsnprintf_s`|`_vsnprintf_s`|`_vsnwprintf_s`|  
|`_vsntprintf_s_l`|`_vsnprintf_s_l`|`_vsnprintf_s_l`|`_vsnwprintf_s_l`|  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalhos opcionais|  
|------------|--------------------------|--------------------------|  
|`vsnprintf_s`|\<stdio.h\> e \<stdarg.h\>|\<varargs.h\>\*|  
|`_vsnprintf_s`, `_vsnprintf_s_l`|\<stdio.h\> e \<stdarg.h\>|\<varargs.h\>\*|  
|`_vsnwprintf_s`, `_vsnwprintf_s_l`|\<stdio.h\> ou \<wchar.h\> e \<stdarg.h\>|\<varargs.h\>\*|  
  
 \* Necessário para a compatibilidade de UNIX V.  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_vsnprintf_s.cpp  
#include <stdio.h>  
#include <wtypes.h>  
  
void FormatOutput(LPCSTR formatstring, ...)   
{  
   int nSize = 0;  
   char buff[10];  
   memset(buff, 0, sizeof(buff));  
   va_list args;  
   va_start(args, formatstring);  
   nSize = vsnprintf_s( buff, _countof(buff), _TRUNCATE, formatstring, args);  
   printf("nSize: %d, buff: %s\n", nSize, buff);  
}  
  
int main() {  
   FormatOutput("%s %s", "Hi", "there");  
   FormatOutput("%s %s", "Hi", "there!");  
   FormatOutput("%s %s", "Hi", "there!!");  
}  
```  
  
  **nSize: 8, lustre: Hello world lá**  
**nSize: 9, lustre: Lá hello world\!**  
**nSize: \-1, lustre: Lá hello world\!**   
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [Funções vprintf](../../c-runtime-library/vprintf-functions.md)   
 [fprintf, \_fprintf\_l, fwprintf, \_fwprintf\_l](../../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md)   
 [printf, \_printf\_l, wprintf, \_wprintf\_l](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [sprintf, \_sprintf\_l, swprintf, \_swprintf\_l, \_\_swprintf\_l](../../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)   
 [va\_arg, va\_copy, va\_end, va\_start](../../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md)