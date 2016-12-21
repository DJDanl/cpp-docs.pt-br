---
title: "_vscprintf, _vscprintf_l, _vscwprintf, _vscwprintf_l | Microsoft Docs"
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
  - "_vscprintf"
  - "_vscprintf_l"
  - "_vscwprintf_l"
  - "_vscwprintf"
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
  - "vscprintf_l"
  - "vscwpeintf"
  - "_vscwprintf"
  - "_vsctprintf"
  - "_vscprintf"
  - "vscwprintf_l"
  - "vscprintf"
  - "_vscwprintf_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _vscprintf"
  - "Função _vscprintf_l"
  - "Função _vsctprintf"
  - "Função _vsctprintf_l"
  - "Função _vscwprintf"
  - "Função _vscwprintf_l"
  - "texto formatado [C++]"
  - "Função vscprintf"
  - "Função vscprintf_l"
  - "Função vsctprintf"
  - "Função vsctprintf_l"
  - "Função vscwprintf"
  - "Função vscwprintf_l"
ms.assetid: 1bc67d3d-21d5-49c9-ac8d-69e26b16a3c3
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _vscprintf, _vscprintf_l, _vscwprintf, _vscwprintf_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna o número de caracteres na cadeia de caracteres formatada usando um ponteiro para uma lista de argumentos.  
  
## Sintaxe  
  
```  
int _vscprintf(  
   const char *format,  
   va_list argptr   
);  
int _vscprintf_l(  
   const char *format,  
   locale_t locale,  
   va_list argptr   
);  
int _vscwprintf(  
   const wchar_t *format,  
   va_list argptr   
);  
int _vscwprintf_l(  
   const wchar_t *format,  
   locale_t locale,  
   va_list argptr   
);  
```  
  
#### Parâmetros  
 `format`  
 Cadeia de caracteres de controle de formato.  
  
 `argptr`  
 Ponteiro para a lista de argumentos.  
  
 `locale`  
 A localidade a ser usada.  
  
 Para obter mais informações, consulte [Especificações de formato](../Topic/Format%20Specification%20Syntax:%20printf%20and%20wprintf%20Functions.md).  
  
## Valor de retorno  
 `_vscprintf` retorna o número de caracteres que serão gerados se a cadeia de caracteres apontada pela lista de argumentos foi impressa ou enviada a um arquivo ou um buffer usando os códigos de formatação especificados.  O valor retornado não inclui o caractere nulo sendo encerrado.  `_vscwprintf` executa a mesma função para caracteres amplos.  
  
 As versões dessas funções com o sufixo `_l` são idênticas, exceto que usam o parâmetro de localidade passado em vez da localidade de thread atual.  
  
 Se `format` for um ponteiro nulo, o manipulador de parâmetro inválido será chamado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, as funções retornarão \-1 e definirão `errno` como `EINVAL`.  
  
## Comentários  
 Cada `argument` \(se houver\) é convertido de acordo com a especificação de formato correspondente em `format`.  O formato consiste em caracteres comuns e tem o mesmo formato e função do que o argumento `format` para [printf](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md).  
  
> [!IMPORTANT]
>  Certifique\-se de que se `format` é uma cadeia de caracteres definida pelo usuário, é encerrada e zero tenha\-se o número e o tipo de parâmetros corretos.  Para obter mais informações, consulte [Evitando saturações de buffer](http://msdn.microsoft.com/library/windows/desktop/ms717795).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_vsctprintf`|`_vscprintf`|`_vscprintf`|`_vscwprintf`|  
|`_vsctprintf_l`|`_vscprintf_l`|`_vscprintf_l`|`_vscwprintf_l`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_vscprintf`, `_vscprintf_l`|\<stdio.h\>|  
|`_vscwprintf`, `_vscwprintf_l`|\<stdio.h\> ou \<wchar.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
 Consulte o exemplo de [vsprintf](../../c-runtime-library/reference/vsprintf-vsprintf-l-vswprintf-vswprintf-l-vswprintf-l.md).  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fprintf, \_fprintf\_l, fwprintf, \_fwprintf\_l](../../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md)   
 [printf, \_printf\_l, wprintf, \_wprintf\_l](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [scanf, \_scanf\_l, wscanf, \_wscanf\_l](../../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md)   
 [sscanf, \_sscanf\_l, swscanf, \_swscanf\_l](../../c-runtime-library/reference/sscanf-sscanf-l-swscanf-swscanf-l.md)   
 [Funções vprintf](../../c-runtime-library/vprintf-functions.md)