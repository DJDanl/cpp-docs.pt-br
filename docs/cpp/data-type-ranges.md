---
title: "Intervalos de tipos de dados | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "unsigned"
  - "wchar_t"
  - "char"
  - "signed"
  - "short"
  - "long"
  - "double"
  - "float"
  - "int"
  - "long_double"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __wchar_t [C++]"
  - "palavra-chave char [C++]"
  - "tipos de dados [C++], intervalos"
  - "tipo de dados double, intervalos de tipos de dados"
  - "palavra-chave enum"
  - "palavra-chave float [C++]"
  - "números de ponto flutuante, intervalos de tipos de dados"
  - "tipo de dados int"
  - "tipo de dados inteiro, intervalos de tipos de dados"
  - "palavra-chave long double [C++]"
  - "palavra-chave long int [C++]"
  - "palavra-chave long [C++]"
  - "palavra-chave long long [C++]"
  - "intervalos [C++]"
  - "intervalos [C++], tipos de dados"
  - "tipo de dados curto"
  - "dados int curtos"
  - "palavra-chave char assinada [C++]"
  - "signed int"
  - "signed long int"
  - "signed short int"
  - "tipos assinados [C++], intervalos de tipos de dados"
  - "tipos de inteiros dimensionados"
  - "palavra-chave char não assinada [C++]"
  - "unsigned int"
  - "unsigned long"
  - "unsigned long int"
  - "unsigned short"
  - "unsigned short int"
  - "tipos não assinados [C++], intervalos de tipos de dados"
  - "Palavra-chave wchar_t [C++]"
ms.assetid: 3691ceca-05fb-4b82-b1ae-5c4618cda91a
caps.latest.revision: 25
caps.handback.revision: 25
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Intervalos de tipos de dados
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os compiladores de 32 bits e 64 bits do Visual C\+\+ reconhecem os tipos na tabela mais adiante neste artigo.  
  
-   `int` \(`unsigned` `int`\)  
  
-   `__int8` \(`unsigned` `__int8`\)  
  
-   `__int16` \(`unsigned` `__int16`\)  
  
-   `__int32` \(`unsigned` `__int32`\)  
  
-   `__int64` \(`unsigned` `__int64`\)  
  
-   `short` \(`unsigned` `short`\)  
  
-   `long` \(`unsigned` `long`\)  
  
-   `long` `long` \(`unsigned` `long` `long`\)  
  
 Se o nome começa com sublinhados duplos \(`__`\), um tipo de dados é diferente do padrão.  
  
 Os intervalos especificados na tabela a seguir são inclusivo\-inclusivo.  
  
|Nome de Tipo|Bytes|Outros nomes|Intervalo de valores|  
|------------------|-----------|------------------|--------------------------|  
|int|4|signed|–2.147.483.648 a 2.147.483.647|  
|unsigned int|4|sem sinal|0 a 4.294.967.295|  
|\_\_int8|1|char|–128 a 127|  
|unsigned \_\_int8|1|unsigned char|0 a 255|  
|\_\_int16|2|short, short int, signed short int|–32.768 a 32.767|  
|unsigned \_\_int16|2|unsigned short, unsigned short int|0 a 65.535|  
|\_\_int32|4|signed, signed int, int|–2.147.483.648 a 2.147.483.647|  
|unsigned \_\_int32|4|unsigned, unsigned int|0 a 4.294.967.295|  
|\_\_int64|8|long long, signed long long|–9.223.372.036.854.775.808 a 9.223.372.036.854.775.807|  
|unsigned \_\_int64|8|longo longo não atribuído|0 a 18.446.744.073.709.551.615|  
|bool|1|nenhum|false ou true|  
|char|1|nenhum|–128 a 127 por padrão<br /><br /> 0 a 255 quando compilado usando [\/J](../build/reference/j-default-char-type-is-unsigned.md)|  
|signed char|1|nenhum|–128 a 127|  
|unsigned char|1|nenhum|0 a 255|  
|short|2|short int, signed short int|–32.768 a 32.767|  
|unsigned short|2|unsigned short int|0 a 65.535|  
|long|4|long int, signed long int|–2.147.483.648 a 2.147.483.647|  
|unsigned long|4|unsigned long int|0 a 4.294.967.295|  
|long long|8|none \(mas equivalente a \_\_int64\)|–9.223.372.036.854.775.808 a 9.223.372.036.854.775.807|  
|longo longo não atribuído|8|none \(mas equivalente a unsigned \_\_int64\)|0 a 18.446.744.073.709.551.615|  
|enum|varia|nenhum|Consulte [Observações](#bkmkRemarks) posteriormente neste artigo|  
|float|4|nenhum|3.4E \+\/\- 38 \(7 dígitos\)|  
|duplo|8|nenhum|1.7E \+\/\- 308 \(15 dígitos\)|  
|longo duplo|igual a double|nenhum|Igual a double|  
|wchar\_t|2|\_\_wchar\_t|0 a 65.535|  
  
 Dependendo de como é usada, uma variável de `__wchar_t` designa um tipo de caractere largo ou um tipo de caractere multibyte.  Use o prefixo `L` antes de uma constante de caractere ou de cadeia de caracteres para designar a constante de tipo de caractere largo.  
  
 `signed` e `unsigned` são os modificadores que você pode usar com qualquer tipo integral, exceto `bool`.  Observe que `char`, `signed char` e `unsigned char` são três tipos distintos para fins de mecanismos como sobrecarga e modelos.  
  
 Os tipos `int` e `unsigned` `int` têm um tamanho de quatro bytes.  No entanto, o código portátil não deve depender do tamanho de `int` porque o padrão de linguagem permite que ele seja específico da implementação.  
  
 C\/C\+\+ no Visual Studio também tem suporte para tipos de inteiros dimensionados.  Para obter mais informações, consulte [\_\_int8, \_\_int16, \_\_int32, \_\_int64](../cpp/int8-int16-int32-int64.md) e [Limites de inteiro](../Topic/Integer%20Limits.md).  
  
 Para obter mais informações sobre as restrições de tamanhos de cada tipo, consulte [Tipos fundamentais](../cpp/fundamental-types-cpp.md).  
  
 O intervalo dos tipos enumerados varia dependendo do contexto de linguagem e dos sinalizadores de compilador especificados.  Para obter mais informações, consulte [Declarações de enumeração C](../c-language/c-enumeration-declarations.md) e [Enumerações](../cpp/enumerations-cpp.md).  
  
## Consulte também  
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Tipos fundamentais](../cpp/fundamental-types-cpp.md)