---
title: "Especifica&#231;&#227;o de largura scanf Width | Microsoft Docs"
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
  - "msvcr100.dll"
  - "msvcr120.dll"
  - "msvcr80.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr90.dll"
apitype: "DLLExport"
f1_keywords: 
  - "scanf"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função scanf, especificação de largura"
ms.assetid: 94b4e8fe-c4a2-4799-8b6c-a2cf28ffb09c
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Especifica&#231;&#227;o de largura scanf Width
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essas informações se aplicam à interpretação de cadeias de caracteres de formato no`scanf`família de funções, incluindo as versões seguras, como`scanf_s`.  Essas funções geralmente pressupõem que o fluxo de entrada é dividido em uma sequência de tokens.  Tokens são separados por espaços em branco \(espaço, tabulação ou nova linha\) ou, no caso de tipos numéricos, ao final de um tipo de dados numéricos, conforme indicado pelo primeiro caractere que não pode ser convertido em texto numérico natural.  No entanto, a especificação de largura pode ser usada para fazer com que a entrada para parar antes do fim natural de um token da análise.  
  
 O*largura*especificação consiste em caracteres entre o`%`e o especificador de campo de tipo, que pode incluir um número inteiro positivo chamado a*largura*campo e um ou mais caracteres que indica o tamanho do campo, que também pode ser considerado como modificadores do tipo de campo, como uma indicação se o tipo de inteiro é**curto**ou**longo**.  Esses caracteres são chamados para o prefixo de tamanho.  
  
## O campo de largura  
 *a largura*campo é um positivo inteiro decimal controlar o número máximo de caracteres a ser lido para esse campo.  Não mais do que*largura*caracteres são convertidas e armazenadas no correspondente`argument`.  Menos de*largura*caracteres podem ser lidos se um caractere de espaço em branco \(espaço, tabulação ou nova linha\) ou um caractere que não pode ser convertido de acordo com o formato de determinado ocorrerá antes*largura*for atingido.  
  
 A especificação de largura é independente do argumento de tamanho de buffer necessário para as versões seguras dessas funções \(ou seja,`scanf_s``wscanf_s`etc.\).  No exemplo a seguir, a especificação de largura é 20, que indica que até 20 caracteres devem ser lidos do fluxo de entrada.  O comprimento do buffer é 21, que inclui espaço para 20 caracteres possíveis mais o terminador nulo:  
  
```  
char str[21];  
scanf_s("%20s", str, 21);  
```  
  
 Se o*largura*campo não é usado,`scanf_s`tenta ler o token inteiro na cadeia de caracteres.  Se o tamanho especificado não é grande o suficiente para armazenar o token inteiro, nada será gravado para a cadeia de caracteres de destino.  Se o*largura*campo for especificado, então a primeira*largura*caracteres no token serão gravados para a cadeia de caracteres de destino juntamente com o terminador nulo.  
  
## O prefixo de tamanho  
 Os prefixos opcionais**hlllI64**e**L**indicam o tamanho do`argument`\(longo ou curto, caracteres de byte único ou de caractere largo, dependendo do caractere de tipo que eles modificam\).  Esses caracteres de especificação de formato são usados com caracteres de texto em`scanf`ou`wscanf`funções para especificar a interpretação dos argumentos, conforme mostrado na tabela a seguir.  O prefixo de tipo**I64**é uma extensão da Microsoft e não ANSI compatível.  Os caracteres de tipo e seus significados são descritos na tabela "Caracteres de tipo para funções scanf" em[Caracteres de campo de tipo scanf](../c-runtime-library/scanf-type-field-characters.md).  
  
> [!NOTE]
>  O**hl**e**L**prefixos são extensões da Microsoft quando usados com dados do tipo`char`.  
  
### Prefixos de tamanho para scanf e wscanf especificadores de tipo de formato  
  
|Para especificar|Use o prefixo|Especificador de tipo|  
|----------------------|-------------------|---------------------------|  
|**duplo**|**l**|**e E f g**or**G**|  
|**long double**\(mesmo que double\)|**L**|**e E f g**or**G**|  
|**Long int**|**l**|**d i o x**or**X**|  
|**unsigned long int**|**l**|**u**|  
|**long long**|**tudo**|**d i o x**or**X**|  
|`short int`|**h**|**d i o x**or**X**|  
|**Short int não assinado**|**h**|**u**|  
|\_\_**int64**|**I64**|**d i o u x**or**X**|  
|Caractere de byte único com`scanf`|**h**|**c**or**C**|  
|Caractere de byte único com`wscanf`|**h**|**c**or**C**|  
|Caractere largo com`scanf`|**l**|**c**or**C**|  
|Caractere largo com`wscanf`|**l**|**c**or**C**|  
|Byte único – cadeia de caracteres com`scanf`|**h**|**s**or**S**|  
|Byte único – cadeia de caracteres com`wscanf`|**h**|**s**or**S**|  
|Cadeia de caracteres largos com`scanf`|**l**|**s**or**S**|  
|Cadeia de caracteres largos com`wscanf`|**l**|**s**or**S**|  
  
 Os exemplos seguintes usam**h**e**l**com`scanf_s`funções e`wscanf_s`funções:  
  
```  
scanf_s("%ls", &x, 2);     // Read a wide-character string  
wscanf_s(L"%hC", &x, 2);    // Read a single-byte character  
```  
  
 Se usar uma função não segura no`scanf`família, omita o parâmetro de tamanho que indica o comprimento do buffer do argumento anterior.  
  
## Cadeias de caracteres de leitura Undelimited  
 Para ler cadeias de caracteres não delimitadas por espaço em branco caracteres, um conjunto de caracteres entre colchetes \(**\[\]**\) podem ser substituídos para o**s**caractere de tipo \(string\).  O conjunto de caracteres entre colchetes é chamado de uma cadeia de caracteres de controle.  O campo de entrada correspondente é ler até o primeiro caractere que não aparecem na cadeia de caracteres de controle.  Se o primeiro caractere no conjunto é um sinal de intercalação \(**^**\), o efeito é revertido: O campo de entrada lidos até o primeiro caractere que aparecem no restante do conjunto de caracteres.  
  
 Observe que**% \[a\-z\]**e**% \[z\-a\]**são interpretados como equivalente a**%\[abcde...z\]**.  Isso é um comum`scanf`extensão de função, mas observe que o padrão ANSI não exija isso.  
  
## Cadeias de caracteres não finalizada de leitura  
 Para armazenar uma cadeia de caracteres sem armazenar um caractere nulo de terminação \('\\0'\), use a especificação`%`*n***c**onde*n*é um inteiro decimal.  Nesse caso, o**c**caractere de tipo indica que o argumento é um ponteiro para uma matriz de caracteres.  O próximo*n*caracteres são lidas do fluxo de entrada no local especificado e nenhum caractere nulo \('\\0'\) é acrescentado.  Se*n*não for especificado, o valor padrão é 1.  
  
## Quando o scanf interrompe a leitura de um campo  
 O`scanf`função examina cada campo de entrada, caractere por caractere.  Ele pode parar de ler um determinado campo de entrada antes que ele atinja um caractere de espaço para uma variedade de motivos:  
  
-   A largura especificada foi atingida.  
  
-   O próximo caractere não pode ser convertido conforme especificado.  
  
-   O próximo caractere em conflito com um caractere na cadeia de controle deve para corresponder.  
  
-   O próximo caractere não será exibida em um determinado conjunto de caracteres.  
  
 Por algum motivo, quando o`scanf`função para de ler um campo de entrada, o próximo campo de entrada é considerado para começar no primeiro caractere não lido.  O caractere conflitante, se houver, é considerado não lidas e é o primeiro caractere do próximo campo de entrada ou o primeiro caractere em operações de leitura subsequentes no fluxo de entrada.  
  
## Consulte também  
 [scanf, \_scanf\_l, wscanf, \_wscanf\_l](../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md)   
 [scanf\_s, \_scanf\_s\_l, wscanf\_s, \_wscanf\_s\_l](../c-runtime-library/reference/scanf-s-scanf-s-l-wscanf-s-wscanf-s-l.md)   
 [Campos de especificação de formato: funções scanf e wscanf](../Topic/Format%20Specification%20Fields:%20scanf%20and%20wscanf%20Functions.md)   
 [Caracteres de campo de tipo scanf](../c-runtime-library/scanf-type-field-characters.md)