---
title: Caracteres de campo de tipo scanf | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
apilocation:
- msvcr90.dll
- msvcr80.dll
- msvcr100.dll
- msvcr110_clr0400.dll
- msvcr110.dll
- msvcr120.dll
apitype: DLLExport
f1_keywords:
- scanf
dev_langs:
- C++
helpviewer_keywords:
- scanf function, type field characters
ms.assetid: 5d546a84-715b-44ca-b1c5-bbe997f9ff62
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: eb4c1c25c5b45fc967954ea78a35a9420b712f81
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32417403"
---
# <a name="scanf-type-field-characters"></a>Caracteres de campo de tipo scanf
As informações a seguir se aplicam a qualquer função da família de funções `scanf`, incluindo as versões seguras como `scanf_s`.  
  
 O caractere `type` é o único campo de formato necessário; ele aparece depois de quaisquer campos de formato opcionais. O caractere `type` determina se o argumento associado é interpretado como um caractere, uma cadeia de caracteres ou um número.  
  
### <a name="type-characters-for-scanf-functions"></a>Caracteres de tipo para funções scanf  
  
|Caractere|Tipo de entrada esperado|Tipo de argumento|Argumento de tamanho na versão segura?|  
|---------------|----------------------------|----------------------|--------------------------------------|  
|`c`|Caractere. Quando usado com funções `scanf`, especifica o caractere de byte único; quando usado com funções `wscanf`, especifica o caractere largo. Caracteres de espaço em branco que normalmente são ignorados são lidos quando `c` é especificado. Para ler o próximo caractere de byte único que não é espaço em branco, use `%1s`; para ler o próximo caractere largo que não é espaço em branco, use `%1ws`.|Ponteiro para `char` quando usado com funções `scanf`, ponteiro para `wchar_t` quando usado com funções `wscanf`.|Necessário. O tamanho não inclui espaço para um terminador nulo.|  
|`C`|Caractere de tamanho oposto. Quando usado com funções `scanf`, especifica o caractere largo; quando usado com funções `wscanf`, especifica o caractere de byte único. Caracteres de espaço em branco que normalmente são ignorados são lidos quando `C` é especificado. Para ler o próximo caractere de byte único que não é espaço em branco, use `%1s`; para ler o próximo caractere largo que não é espaço em branco, use `%1ws`.|Ponteiro para `wchar_t` quando usado com funções `scanf`, ponteiro para `char` quando usado com funções `wscanf`.|Necessário. O argumento de tamanho não inclui espaço para um terminador nulo.|  
|`d`|Inteiro decimal.|Ponteiro para `int`.|Nº|  
|`i`|Um inteiro. Hexadecimal se a cadeia de caracteres de entrada começa com "0x" ou "0X", octal se a cadeia de caracteres começa com "0", caso contrário, decimal.|Ponteiro para `int`.|Nº|  
|`o`|Inteiro octal.|Ponteiro para `int`.|Nº|  
|`p`|Um endereço de ponteiro em dígitos hexadecimais. O número máximo de dígitos de leitura depende do tamanho de um ponteiro (32 ou 64 bits), que depende da arquitetura do computador. "0x" ou "0X" são aceitos como prefixos.|Ponteiro para `void*`.|Nº|  
|`u`|Inteiro decimal sem sinal.|Ponteiro para `unsigned int`.|Nº|  
|`x`|Inteiro hexadecimal.|Ponteiro para `int`.|Nº|  
|`e`, `E`, `f`, `F`, `g`, `G`|Valor de ponto flutuante consistindo de um sinal opcional (+ ou -), de uma série de um ou mais dígitos decimais que contém o ponto decimal e também de um expoente opcional ("e" ou "E"), seguido por um valor inteiro com sinal opcionalmente.|Ponteiro para `float`.|Nº|  
|`a`, `A`|Valor de ponto flutuante que consiste em uma série de um ou mais dígitos hexadecimais com um ponto decimal opcional e um expoente ("p" ou "P") seguido de um valor decimal.|Ponteiro para `float`.|Nº|  
|`n`|Nenhuma entrada lida do fluxo ou buffer.|Ponteiro para `int`, no qual é armazenado o número de caracteres lidos com êxito do fluxo ou buffer até esse ponto na chamada atual para funções `scanf` ou funções `wscanf`.|Nº|  
|`s`|Cadeia de caracteres, até o primeiro caractere de espaço em branco (espaço, tabulação ou nova linha). Para ler cadeias de caracteres não delimitadas por caracteres de espaço, use o conjunto de colchetes (`[ ]`), conforme discutido em [Especificação de largura scanf Width](../c-runtime-library/scanf-width-specification.md).|Quando usado com funções `scanf`, significa matriz de caracteres de byte único; quando usado com funções `wscanf`, significa matriz de caracteres largos. Em ambos os casos, a matriz de caracteres deve ser grande o suficiente para o campo de entrada mais o caractere nulo de terminação, que é anexado automaticamente.|Necessário. O tamanho inclui espaço para um terminador nulo.|  
|`S`|Cadeia de caracteres de tamanho oposto, até o primeiro caractere de espaço em branco (espaço, tabulação ou nova linha). Para ler cadeias de caracteres não delimitadas por caracteres de espaço, use o conjunto de colchetes (`[ ]`), conforme discutido em [Especificação de largura scanf Width](../c-runtime-library/scanf-width-specification.md).|Quando usado com funções `scanf`, significa matriz de caracteres largos; quando usado com funções `wscanf`, significa matriz de caracteres de byte único. Em ambos os casos, a matriz de caracteres deve ser grande o suficiente para o campo de entrada mais o caractere nulo de terminação, que é anexado automaticamente.|Necessário. O tamanho inclui espaço para um terminador nulo.|  
  
  
 Os argumentos de tamanho, se necessário, devem ser transmitidos na lista de parâmetros imediatamente após o argumento a que se aplicam. Por exemplo, o código a seguir:  
  
```  
char string1[11], string2[9];  
scanf_s("%10s %8s", string1, 11, string2, 9);  
```  
  
 lê uma cadeia de caracteres com um comprimento máximo de 10 em `string1` e uma cadeia de caracteres com um comprimento máximo de 8 em `string2`. Os tamanhos de buffer devem ser maiores do que as especificações de largura por pelo menos uma unidade, já que o espaço deve ser reservado para o terminador nulo.  
  
 A cadeia de caracteres de formato pode lidar com a entrada de caracteres de byte único ou largos independentemente de qual versão da função é usada, de caractere largo ou de caractere de byte único. Portanto, para ler caracteres de byte único ou largos com funções `scanf` e funções `wscanf`, use os especificadores de formato conforme descrito a seguir.  
  
|Para ler o caractere como|Use esta função|Com estes especificadores de formato|  
|--------------------------|-----------------------|----------------------------------|  
|byte único|Funções `scanf`|`c`, `hc` ou `hC`|  
|byte único|Funções `wscanf`|`C`, `hc` ou `hC`|  
|largos|Funções `wscanf`|`c`, `lc` ou `lC`|  
|largos|Funções `scanf`|`C`, `lc` ou `lC`|  
  
 Para examinar cadeias de caracteres com funções `scanf` e funções `wscanf`, use a tabela acima com os especificadores de tipo de formato `s` e `S` em vez de `c` e `C`.  
  
## <a name="see-also"></a>Consulte também  
 [scanf, _scanf_l, wscanf, _wscanf_l](../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md)