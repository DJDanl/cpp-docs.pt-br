---
title: "Caracteres de campo de tipo printf | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apilocation: 
  - "msvcr100.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
apitype: "DLLExport"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "printf - função, campos de especificação de formato"
  - "printf - função, caracteres de campo de tipo"
ms.assetid: 699cb438-cd14-402e-9f81-c7a32acc3317
caps.latest.revision: 15
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Caracteres de campo de tipo printf
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Em uma especificação de formato, o `type` caractere é um especificador de conversão que especifica se o argumento correspondente deve ser interpretado como um caractere, uma cadeia de caracteres, um ponteiro, um inteiro ou um número de ponto flutuante.  O `type` caractere é necessário o único campo de especificação de formato e aparece depois de quaisquer campos opcionais.  
  
 Os argumentos que seguem a cadeia de caracteres de formato são interpretados conforme correspondente `type` caractere e opcional [tamanho](../c-runtime-library/size-specification.md) prefixo.  Conversões de tipos de caracteres `char` e `wchar_t` são especificadas usando `c` ou `C`, e as cadeias de caracteres de byte único e vários bytes ou caracteres largos são especificadas usando `s` ou `S`, dependendo de qual função formatação está sendo usada.  Caracteres e cadeia de argumentos que são especificados usando `c` e `s` são interpretados como `char` e `char*` por `printf` funções da família, ou como `wchar_t` e `wchar_t*` por `wprintf` funções da família.  Caracteres e cadeia de argumentos que são especificados usando `C` e `S` são interpretados como `wchar_t` e `wchar_t*` por `printf` funções da família, ou como `char` e `char*` por `wprintf` funções da família.  
  
 Tipos de inteiro, como `short`, `int`, `long`, `long long`, e seus `unsigned` variantes, são especificadas usando `d`, `i`, `o`, `u`, `x`, e `X`.  Ponto flutuante tipos como `float`, `double`, e `long double`, são especificadas usando `a`, `A`, `e`, `E`, `f`, `g`, e `G`.  Por padrão, a menos que eles são modificados por um `size` prefixo de comprimento do campo argumentos inteiros são forçados para `int` tipo e argumentos de ponto flutuante são forçados para `double`.  Em sistemas de 64 bits, um `int` é um valor de 32 bits; portanto, inteiros de 64 bits serão truncados quando são formatados para saída, a menos que um `size` prefixo de `ll` ou `I64` é usado.  Tipos de ponteiro que são especificados pelo `p` usar o comprimento padrão para a plataforma.  
  
> [!NOTE]
>  O `C`, `S`, e `Z` digite caracteres e o comportamento da `c` e `s` digitar caracteres quando eles são usados com o `printf` e `wprintf` funções são extensões da Microsoft e não compatível com ANSI.  [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] não oferece suporte a `F` caractere de tipo.  
  
### Caracteres de campo de tipo printf  
  
|Caractere de tipo|Argumento|Formato de saída|  
|-----------------------|---------------|----------------------|  
|`c`|Caractere|Quando usado com `printf` funciona, especifica um caractere de byte único; quando usado com `wprintf` funciona, especifica um caractere largo.|  
|`C`|Caractere|Quando usado com `printf` funciona, especifica um caractere largo; quando usado com `wprintf` funciona, especifica um caractere de byte único.|  
|`d`|Inteiro|Inteiro decimal.|  
|`i`|Inteiro|Inteiro decimal.|  
|`o`|Inteiro|Inteiro octal não assinado.|  
|`u`|Inteiro|Inteiro decimal não assinado.|  
|`x`|Inteiro|Inteiro hexadecimal não assinado; usa "abcdef".|  
|`X`|Inteiro|Inteiro hexadecimal não assinado; usa "ABCDEF".|  
|`e`|Ponto flutuante|Assinado valor que tem o formato \[\-\]`d`**.**`dddd` e \[*sinal*\]`dd[d]` onde `d` é um dígito decimal, `dddd` é um ou mais dígitos decimais, `dd[d]` é dois ou três dígitos decimais dependendo do [formato de saída](../c-runtime-library/set-output-format.md) e o tamanho do expoente, e *sinal* é \+ ou.|  
|`E`|Ponto flutuante|Idêntico do `e` Formatar exceto que **E** em vez de **e** apresenta o expoente.|  
|`f`|Ponto flutuante|Assinado valor que tem o formato \[\-\]`dddd`**.**`dddd`, onde `dddd` é um ou mais dígitos decimais.  O número de dígitos antes do ponto decimal depende da magnitude do número e o número de dígitos após o ponto decimal depende da precisão solicitada.|  
|`g`|Ponto flutuante|Valores assinados são exibidos em `f` ou `e` de formato, o que for mais compacto para o valor especificado e a precisão.  O `e` formato é usado somente quando o expoente do valor é menor que – 4 ou maior ou igual a `precision` argumento.  Zeros à esquerda são truncados e o ponto decimal é exibida somente se um ou mais dígitos seguem.|  
|`G`|Ponto flutuante|Idêntico do `g` Formatar, exceto que **E**, em vez de **e**, apresenta o expoente \(quando apropriado\).|  
|`a`|Ponto flutuante|Assinado hexadecimal valor de ponto flutuante de precisão dupla que tem o formato \[−\] 0 x*h.hhhh* **p±**`dd`, onde *h.hhhh* são os dígitos hexadecimais \(usando letras minúsculas\) da mantissa, e `dd` são um ou mais dígitos para o expoente.  A precisão especifica o número de dígitos após o ponto.|  
|`A`|Ponto flutuante|Assinado hexadecimal valor de ponto flutuante de precisão dupla que tem o formato \[−\] 0x*h.hhhh* **P±**`dd`, onde *h.hhhh* são os dígitos hexadecimais \(usando letras maiúsculas\) da mantissa, e `dd` são um ou mais dígitos para o expoente.  A precisão especifica o número de dígitos após o ponto.|  
|`n`|Ponteiro para inteiro|Número de caracteres que são gravados até agora com êxito o fluxo ou o buffer.  Esse valor é armazenado no inteiro cujo endereço é fornecido como o argumento.  Consulte a observação de segurança neste artigo.|  
|`p`|Tipo de ponteiro|Exibe o argumento como um endereço de dígitos hexadecimais.|  
|`s`|Cadeia de Caracteres|Quando usado com `printf` funciona, especifica uma cadeia de caracteres de byte único ou vários bytes; quando usado com `wprintf` funciona, especifica uma cadeia de caracteres largos.  Os caracteres são exibidos até o primeiro caractere nulo ou até que o `precision` valor é atingido.|  
|`S`|Cadeia de Caracteres|Quando usado com `printf` funciona, especifica uma cadeia de caracteres largos; quando usado com `wprintf` funciona, especifica uma cadeia de caracteres de byte único ou vários bytes.  Os caracteres são exibidos até o primeiro caractere nulo ou até que o `precision` valor é atingido.|  
|`Z`|`ANSI_STRING` ou `UNICODE_STRING` estrutura|Quando o endereço de uma [ANSI\_STRING](http://msdn.microsoft.com/library/windows/hardware/ff540605.aspx) ou [UNICODE\_STRING](http://msdn.microsoft.com/library/windows/hardware/ff564879.aspx) estrutura é passado como o argumento, exibe a cadeia de caracteres que está contida no buffer é apontado pelo `Buffer` campo da estrutura.  Usar um prefixo de comprimento de modificador de `w` para especificar um `UNICODE_STRING` argumento — por exemplo, `%wZ`.  O `Length` campo da estrutura deve ser definido como o comprimento, em bytes, da cadeia de caracteres.  O `MaximumLength` campo da estrutura deve ser definido como o comprimento, em bytes, do buffer.<br /><br /> Normalmente, o `Z` caractere de tipo é usado apenas no driver de depuração de funções que usam uma especificação de formato, tais como `dbgPrint` e `kdPrint`.|  
  
 Se o argumento que corresponde a um especificador de conversão de ponto flutuante é indefinido, infinito ou NAN, a tabela a seguir lista a saída formatada.  
  
|Valor|Saída|  
|-----------|-----------|  
|\+ infinity|`1. #INF` *dígitos aleatórios*|  
|– infinito|`– 1. #INF` *dígitos aleatórios*|  
|Indefinido \(mesmo NaN silencioso\)|*dígitos* `. #IND` *dígitos aleatórios*|  
|NAN|*dígitos* `. #NAN` *dígitos aleatórios*|  
  
> [!NOTE]
>  Se o o `Buffer` o argumento que corresponde ao campo `%Z`, ou do argumento que corresponde a `%s` ou `%S`, é um ponteiro nulo, "\(nulo\)" será exibido.  
  
> [!NOTE]
>  Em todos os formatos exponenciais, o número de dígitos do expoente para exibir padrão é três.  Usando o [set\_output\_format](../c-runtime-library/set-output-format.md) função, você pode definir o número de dígitos exibidos como dois mas expandindo para três se exigido pelo tamanho do expoente.  
  
> [!IMPORTANT]
>  Porque o `%n` formato é inerentemente inseguro, ela é desabilitada por padrão.  Se `%n` for encontrado em uma cadeia de caracteres de formato, o manipulador de parâmetro inválido é chamado, conforme descrito em [Validação do parâmetro](../c-runtime-library/parameter-validation.md).  Para habilitar `%n` suporte, consulte [\_set\_printf\_count\_output](../c-runtime-library/reference/set-printf-count-output.md).  
  
## Consulte também  
 [printf, \_printf\_l, wprintf, \_wprintf\_l](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [Sintaxe de especificação de formato: funções printf e and wprintf](../Topic/Format%20Specification%20Syntax:%20printf%20and%20wprintf%20Functions.md)   
 [Diretivas de sinalizador](../Topic/Flag%20Directives.md)   
 [Especificação de largura printf](../c-runtime-library/printf-width-specification.md)   
 [Especificação da precisão](../c-runtime-library/precision-specification.md)   
 [Especificação de arquivo](../c-runtime-library/size-specification.md)   
 [\_set\_output\_format](../c-runtime-library/set-output-format.md)