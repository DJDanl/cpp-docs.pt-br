---
title: "Sequ&#234;ncias de escape | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "aspas simples (')"
  - "símbolo ?"
  - "símbolo ?, caractere de sequência de escape"
  - "símbolo \ sem sequências de escape"
  - "sequência de escape \a"
  - "sequência de escape \f"
  - "sequência de escape \n"
  - "sequência de escape \r"
  - "sequência de escape \t"
  - "sequência de escape \v"
  - "sequência de escape backspace"
  - "sequência de escape \a de caractere de sino"
  - "retornos de carro"
  - "sequências de escape de caractere de controle"
  - "barra invertida dupla"
  - "caracteres de escape"
  - "sequências de escape"
  - "sequência de escape \f de avanço de página"
  - "sequência de escape hexadecimal"
  - "sequência de escape \t de tabulação horizontal"
  - "sequência de escape \n de caractere de nova linha"
  - "caracteres de controle não gráficos"
  - "sequência de escape octais"
  - "ponto de interrogação, literal"
  - "aspas, single"
  - "sequência de escape \t de tabulação"
  - "sequência de escape \v de tabulação vertical"
ms.assetid: 5aef377f-a76c-4d5c-aa04-8308758ad6a8
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Sequ&#234;ncias de escape
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As combinações de caracteres que consistem em uma barra invertida \(**\\**\) seguida por uma letra ou por uma combinação de dígitos são chamadas de "sequências de escape". Para representar um caractere de nova linha, aspas simples ou alguns outros caracteres em uma constante de caractere, você deve usar sequências de escape.  Uma sequência de escape é considerada um único caractere e, portanto, é válida como uma constante de caractere.  
  
 Geralmente, as sequências de escape são usadas para especificar ações como retornos de carro e movimentos de tabulação em terminais e impressoras.  Também são usadas para fornecer representações literais de caracteres não imprimíveis e de caracteres que normalmente têm significados especiais, como as aspas duplas \(**"**\).  A tabela a seguir lista as sequências de escape ANSI e o que elas representam.  
  
 Observe que o ponto de interrogação precedido por uma barra invertida \(**\\?**\) especifica um ponto de interrogação literal nos casos em que a sequência de caracteres seria interpretada incorretamente como um trígrafo.  Consulte [Trígrafos](../Topic/Trigraphs.md) para obter mais informações.  
  
### Sequências de Escape  
  
|Sequência de escape|Representa|  
|-------------------------|----------------|  
|**\\a**|Campainha \(alerta\)|  
|**\\b**|Backspace|  
|**\\f**|Avanço de página|  
|**\\n**|Nova linha|  
|**\\r**|Retorno de carro|  
|**\\t**|Tabulação horizontal|  
|**\\v**|Tabulação vertical|  
|**\\'**|Aspas simples|  
|**\\"**|Aspas duplas|  
|**\\\\**|Barra invertida|  
|**\\?**|Ponto de interrogação literal|  
|**\\** *ooo*|Caractere ASCII em notação octal|  
|**\\x** *hh*|Caractere ASCII em notação hexadecimal|  
|**\\x** *hhhh*|Caractere Unicode em notação hexadecimal, se esta sequência de escape é usada em uma constante de caractere largo ou uma literal de cadeia de caracteres Unicode.<br /><br /> Por exemplo, `WCHAR f = L'\x4e00'` ou `WCHAR b[] = L"The Chinese character for one is \x4e00"`.|  
  
 **Específico da Microsoft**  
  
 Se uma barra invertida precede um caractere que não consta da tabela, o compilador trata o caractere indefinido como o próprio caractere.  Por exemplo, `\c` é tratado como um `c`.  
  
 **FIM de Específico da Microsoft**  
  
 As sequências de escape permitem que você envie caracteres de controle não gráficos a um dispositivo de exibição.  Por exemplo, o caractere de ESC \(**\\033**\) costuma ser usado como o primeiro caractere de um comando de controle para um terminal ou uma impressora.  Algumas sequências de escape são específicas ao dispositivo.  Por exemplo, as sequências de escape de tabulação vertical e de avanço de página \(**\\v** e **\\f**\) não afetam a saída da tela, mas executam operações de impressora apropriadas.  
  
 Você também pode usar a barra invertida \(**\\**\) como um caractere de continuação.  Quando um caractere de nova linha \(equivalente a pressionar a tecla RETURN\) vem logo após a barra invertida, o compilador ignora a barra invertida e o caractere de nova linha e trata a próxima linha como parte da linha anterior.  Isso é útil principalmente para definições de pré\-processador que ocupam mais do que uma única linha.  Por exemplo:  
  
```  
#define assert(exp) \  
( (exp) ? (void) 0:_assert( #exp, __FILE__, __LINE__ ) )  
```  
  
## Consulte também  
 [Constantes de caractere C](../Topic/C%20Character%20Constants.md)