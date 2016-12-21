---
title: "Especifica&#231;&#227;o de arquivo | Microsoft Docs"
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
  - "msvcr120.dll"
  - "msvcr80.dll"
  - "msvcr110.dll"
  - "msvcr90.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr100.dll"
apitype: "DLLExport"
f1_keywords: 
  - "size"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "printf - função, campos de especificação de formato"
ms.assetid: 525dc5d8-e70a-4797-a6a0-ec504a27355c
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Especifica&#231;&#227;o de arquivo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Em uma especificação de formato, o quarto campo é um modificador de comprimento do argumento para o especificador de conversão.  O `size` campo prefixos para o `type` campo —`h`, `l`, `w`, `I`, `I32`, `I64`, e `ll`— Especifique o "tamanho" do argumento correspondente — longo ou curto, 32 bits ou 64 bits, caracteres de byte único ou de caractere largo — dependendo do especificador de conversão que eles modificam.  Esses prefixos de tamanho são usados com `type` caracteres a `printf` e `wprintf` famílias de funções para especificar a interpretação de comprimentos de argumento, como mostrado na tabela a seguir.  O `size` campo é opcional para alguns tipos de argumentos.  Quando nenhum prefixo de tamanho é especificado, o formatador consome argumentos inteiros — por exemplo, assinados ou não assinados `char`, `short`, `int`, `long`, e tipos de enumeração — como 32 bits `int` tipos e argumentos de ponto flutuante são consumidos de 64 bits `double` tipos.  Isso corresponde às regras de promoção de argumento padrão para listas de argumentos variáveis.  Para obter mais informações sobre a promoção do argumento, consulte [Reticências e argumentos padrão](../misc/ellipses-and-default-arguments.md).  Em sistemas de 32 bits e 64 bits, a especificação de formato de um argumento de inteiro de 64 bits deve incluir um prefixo de tamanho de `ll` ou `I64`.  Caso contrário, o comportamento do formatador é indefinido.  
  
 Alguns tipos são tamanhos diferentes no código de 32 bits e 64 bits.  Por exemplo, `size_t` é de 32 bits em código compilado para x86 e 64 bits no código compilado para x64.  Para criar o código de formatação independente de plataforma para tipos de largura variável, você pode usar um modificador de comprimento do argumento de largura variável.  Como alternativa, use um modificador de comprimento do argumento de 64 bits e promover explicitamente o tipo de argumento de largura variável 64 bits.  Específicos do Microsoft `I` argumento modificador de comprimento lida com argumentos inteiros de largura variável.  
  
> [!NOTE]
>  O `I`, `I32`, e `I64` prefixos de modificador de comprimento são extensões da Microsoft e não são compatíveis com ANSI.  O `h` prefixo quando ele é usado com o tipo de dados `char`, o `w` prefixo quando ele é usado com o tipo de dados `wchar_t`, e o `l` prefixo quando ele é usado com o tipo de dados `double` são extensões da Microsoft.  O `hh`, `j`, `z`, e `t` não há suporte para prefixos de comprimento.  
  
### Prefixos de tamanho para printf e and wprintf especificadores de tipo de formato  
  
|Para especificar|Use o prefixo|Especificador de tipo|  
|----------------------|-------------------|---------------------------|  
|`long int`|`l` \(L minúsculo\)|`d`, `i`, `o`, `x`, or `X`|  
|`long unsigned int`|`l`|`o`, `u`, `x` ou `X`|  
|`long long`|`ll`|`d`, `i`, `o`, `x`, or `X`|  
|`short int`|`h`|`d`, `i`, `o`, `x`, or `X`|  
|`short unsigned int`|`h`|`o`, `u`, `x` ou `X`|  
|`__int32`|`I32`|`d`, `i`, `o`, `x`, or `X`|  
|`unsigned __int32`|`I32`|`o`, `u`, `x` ou `X`|  
|`__int64`|`I64`|`d`, `i`, `o`, `x`, or `X`|  
|`unsigned __int64`|`I64`|`o`, `u`, `x` ou `X`|  
|`ptrdiff_t` \(ou seja, `__int32` em plataformas de 32 bits, `__int64` em plataformas de 64 bits\)|`I`|`d`, `i`, `o`, `x`, or `X`|  
|`size_t` \(ou seja, `unsigned __int32` em plataformas de 32 bits, `unsigned __int64` em plataformas de 64 bits\)|`I`|`o`, `u`, `x` ou `X`|  
|`long double` \(No [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)], embora `long double` é um tipo diferente, ele tem a mesma representação interna como `double`.\)|`l` ou `L`|`a`, `A`, `e`, `E`, `f`, `g`, or `G`|  
|Caractere de byte único com `printf` e `wprintf` funções.  \(Um `hc` ou `hC` especificador de tipo é sinônimo de `c` em `printf` funções e com `C` em `wprintf` funções.\)|`h`|`c` ou `C`|  
|Caracteres largos com `printf` e `wprintf` funções.  \(Um `lc`, `lC`, `wc` ou `wC` especificador de tipo é sinônimo de `C` em `printf` funções e com `c` em `wprintf` funções.\)|`l` ou `w`|`c` ou `C`|  
|Cadeia de caracteres de byte único com `printf` e `wprintf` funções.  \(Um `hs` ou `hS` especificador de tipo é sinônimo de `s` em `printf` funções e com `S` em `wprintf` funções.\)|`h`|`s`, `S`, or `Z`|  
|Cadeia de caracteres largos com `printf` e `wprintf` funções.  \(Um `ls`, `lS`, `ws` ou `wS` especificador de tipo é sinônimo de `S` em `printf` funções e com `s` em `wprintf` funções.\)|`l` ou `w`|`s`, `S`, or `Z`|  
  
## Consulte também  
 [printf, \_printf\_l, wprintf, \_wprintf\_l](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [Sintaxe de especificação de formato: funções printf e and wprintf](../Topic/Format%20Specification%20Syntax:%20printf%20and%20wprintf%20Functions.md)   
 [Diretivas de sinalizador](../Topic/Flag%20Directives.md)   
 [Especificação de largura printf](../c-runtime-library/printf-width-specification.md)   
 [Especificação da precisão](../c-runtime-library/precision-specification.md)   
 [Caracteres de campo de tipo printf](../c-runtime-library/printf-type-field-characters.md)