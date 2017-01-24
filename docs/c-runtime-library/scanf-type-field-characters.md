---
title: "Caracteres de campo de tipo scanf | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apilocation: 
  - "msvcr90.dll"
  - "msvcr80.dll"
  - "msvcr100.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr120.dll"
apitype: "DLLExport"
f1_keywords: 
  - "scanf"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "função scanf, caracteres de campo de tipo"
ms.assetid: 5d546a84-715b-44ca-b1c5-bbe997f9ff62
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Caracteres de campo de tipo scanf
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As informações a seguir se aplica a qualquer o `scanf` família de funções, incluindo as versões seguras, como `scanf_s`.  
  
 O `type` caractere é o único campo de formato necessário; ele aparece depois de quaisquer campos de formato opcional. O `type` caractere determina se o argumento associado é interpretado como um caractere, uma cadeia de caracteres ou um número.  
  
### Caracteres de tipo para funções scanf  
  
|Caractere|Tipo de entrada esperado|Tipo de argumento|Argumento de tamanho na versão segura?|  
|---------------|------------------------------|-----------------------|--------------------------------------------|  
|`c`|Caractere. Quando usado com `scanf` funciona, especifica o caractere de byte único, quando usado com `wscanf` funciona, especifica o caractere largo. Caracteres de espaço em branco que normalmente são ignorados são lidas quando `c` for especificado. Para ler o próximo caractere de byte único não – espaço em branco, use `%1s`; para ler a próxima não – brancos caracteres largos, use `%1ws`.|Ponteiro para `char` quando usado com `scanf` funções, ponteiro para `wchar_t` quando usado com `wscanf` funções.|Obrigatório. Tamanho não inclui espaço para um terminador nulo.|  
|`C`|Oposta caractere de tamanho. Quando usado com `scanf` funciona, especifica o caractere largo; quando usado com `wscanf` funciona, especifica o caractere de byte único. Caracteres de espaço em branco que normalmente são ignorados são lidas quando `C` for especificado. Para ler o próximo caractere de byte único não – espaço em branco, use `%1s`; para ler a próxima não – brancos caracteres largos, use `%1ws`.|Ponteiro para `wchar_t` quando usado com `scanf` funções, ponteiro para `char` quando usado com `wscanf` funções.|Obrigatório. Argumento de tamanho não inclui espaço para um terminador nulo.|  
|`d`|Inteiro decimal.|Ponteiro para `int`.|Não.|  
|`i`|Um inteiro. Hexadecimal, se a cadeia de caracteres de entrada começa com "0x" ou "0x", octal se a cadeia de caracteres começa com "0", caso contrário decimal.|Ponteiro para `int`.|Não.|  
|`o`|Inteiro octal.|Ponteiro para `int`.|Não.|  
|`p`|Um endereço de ponteiro em dígitos hexadecimais. O número máximo de dígitos de leitura depende do tamanho de um ponteiro \(32 ou 64 bits\), que depende da arquitetura de máquina. "0x" ou "0x" são aceitos como prefixos.|Ponteiro para `void*`.|Não.|  
|`u`|Inteiro decimal não assinado.|Ponteiro para `unsigned``int`.|Não.|  
|`x`|Inteiro hexadecimal.|Ponteiro para `int`.|Não.|  
|`e`, `E`, `f`, `g`, `G`|Valor de ponto flutuante consiste em sinal opcional \(\+ ou \-\), série de um ou mais dígitos decimais que contém o ponto decimal e o expoente opcional \("e" ou "E"\) seguido por um valor inteiro assinado opcionalmente.|Ponteiro para `float`.|Não.|  
|`n`|Nenhuma entrada de leitura de fluxo ou de buffer.|Ponteiro para `int`, em que é armazenado número de caracteres com êxito lidos do fluxo ou de buffer até esse ponto na chamada atual para `scanf` funções ou `wscanf` funções.|Não.|  
|`s`|Cadeia de caracteres, até o primeiro caractere de espaço em branco \(espaço, tabulação ou nova linha\). Para ler cadeias de caracteres não são delimitadas por caracteres de espaço, use o conjunto de colchetes \(`[ ]`\), conforme discutido em [Especificação de largura scanf Width](../c-runtime-library/scanf-width-specification.md).|Quando usado com `scanf` funciona, significa a matriz de caracteres de byte único; quando usado com `wscanf` funciona, significa a matriz de caractere largo. Em ambos os casos, a matriz de caracteres deve ser grande o suficiente para campo de entrada além do caractere de terminação nula, que é anexado automaticamente.|Obrigatório. Tamanho inclui espaço para um terminador nulo.|  
|`S`|O oposto\-tamanho da cadeia de caracteres até o primeiro caractere de espaço em branco \(espaço, tabulação ou nova linha\). Para ler cadeias de caracteres não são delimitadas por caracteres de espaço, use o conjunto de colchetes \(`[ ]`\), conforme discutido em [Especificação de largura scanf Width](../c-runtime-library/scanf-width-specification.md).|Quando usado com `scanf` funciona, significa a matriz de caractere largo; quando usado com `wscanf` funciona, significa a matriz de bytes – caractere único. Em ambos os casos, a matriz de caracteres deve ser grande o suficiente para campo de entrada além do caractere de terminação nula, que é anexado automaticamente.|Obrigatório. Tamanho inclui espaço para um terminador nulo.|  
  
 O `a` e `A` especificadores \(consulte [Caracteres de campo de tipo printf](../c-runtime-library/printf-type-field-characters.md)\) não estão disponíveis com `scanf`.  
  
 Os argumentos de tamanho, se necessário, devem ser transmitidos na lista de parâmetros imediatamente após o argumento que se aplicam. Por exemplo, o código a seguir:  
  
```  
char string1[11], string2[9];  
scanf_s("%10s %8s", string1, 11, string2, 9);  
```  
  
 lê uma cadeia de caracteres com um comprimento máximo de 10 em `string1`, e uma cadeia de caracteres com um comprimento máximo de 8 em `string2`. Os tamanhos de buffer devem ser pelo menos um mais do que as especificações de largura desde espaço devem ser reservado para o terminador nulo.  
  
 A cadeia de caracteres de formato pode lidar com a entrada de caracteres de byte único ou de longa independentemente do caractere de byte único ou a versão de caractere largo da função é usado. Portanto, para ler caracteres de byte único ou largos com `scanf` funções e `wscanf` funções, use os especificadores de formato da seguinte maneira.  
  
|Para ler caracteres como|Use esta função|Com esses especificadores de formato|  
|------------------------------|---------------------|------------------------------------------|  
|byte único|`scanf` funções|`c`, `hc`, or `hC`|  
|byte único|`wscanf` funções|`C`, `hc`, or `hC`|  
|largos|`wscanf` funções|`c`, `lc`, or `lC`|  
|largos|`scanf` funções|`C`, `lc`, or `lC`|  
  
 Para verificar se cadeias de caracteres com `scanf` funções, e `wscanf` funções, use a tabela acima com especificadores de tipo de formato `s` e `S` em vez de `c` e `C`.  
  
## Consulte também  
 [scanf, \_scanf\_l, wscanf, \_wscanf\_l](../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md)