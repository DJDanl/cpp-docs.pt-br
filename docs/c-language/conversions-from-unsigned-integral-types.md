---
title: "Conversões de tipos integrais sem sinal | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- integers, converting
- type casts, involving integers
- data type conversion [C++], signed and unsigned integers
- type conversion [C++], signed and unsigned integers
- integral conversions, from unsigned
ms.assetid: 60fb7e10-bff9-4a13-8a48-e19f25a36a02
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 15e1bc61e9b15293290098b9414642d8edf46707
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="conversions-from-unsigned-integral-types"></a>Conversões de tipos integrais sem sinal
Um inteiro sem sinal é convertido em um inteiro com ou sem sinal mais curto por meio do truncamento dos bits de ordem superior; ou é convertido em um inteiro com ou sem sinal mais longo por meio da extensão de zero (consulte a tabela [Conversões de tipos integrais sem sinal](#_clang_table_4..3)).  
  
 Quando o valor com tipo integral é rebaixado para um inteiro com sinal de tamanho menor, ou um inteiro sem sinal é convertido no inteiro com sinal correspondente, o valor não será alterado se ele puder ser representado no novo tipo. No entanto, o valor que ele representa mudará se o bit de sinal for definido, como no exemplo a seguir.  
  
```  
int j;  
unsigned short k = 65533;  
  
j = k;  
printf_s( "%hd\n", j );   // Prints -3  
```  
  
 Se ele não puder ser representado, o resultado será definido na implementação. Consulte [Conversões de tipo](../c-language/type-cast-conversions.md) para obter informações sobre como o compilador de C da Microsoft manipula o rebaixamento de números inteiros. O mesmo comportamento resulta da conversão regular do inteiro ou da conversão de tipo ("cast") do inteiro.  
  
 Valores não assinados são convertidos de uma maneira que preserva o valor e não é representada diretamente em C. A única exceção é uma conversão de `unsigned long` para **float**, que perde, no máximo, os bits de ordem inferior. Caso contrário, o valor é preservado, com ou sem sinal. Quando um valor de tipo integral é convertido em flutuante e está fora do intervalo representável, o resultado é indefinido. (Consulte [Armazenamento de tipos básicos](../c-language/storage-of-basic-types.md) para obter informações sobre o alcance para os tipos integral e de ponto flutuante.)  
  
 A tabela a seguir resume as conversões de tipos integrais sem sinal.  
  
### <a name="conversions-from-unsigned-integral-types"></a>Conversões de tipos integrais sem sinal  
  
|De|Para|Método|  
|----------|--------|------------|  
|`unsigned char`|`char`|Preserva o padrão de bits; o bit de ordem superior torna-se o bit de sinal|  
|`unsigned char`|**short**|Extensão de zero|  
|`unsigned char`|**long**|Extensão de zero|  
|`unsigned char`|**unsigned short**|Extensão de zero|  
|`unsigned char`|`unsigned long`|Extensão de zero|  
|`unsigned char`|**float**|Converte em **long**; converte **long** em **float**|  
|`unsigned char`|**double**|Converte em **long**; converte **long** em **double**|  
|`unsigned char`|`long double`|Converte em **long**; converte **long** em **double**|  
|**unsigned short**|`char`|Preserva o byte de ordem inferior|  
|**unsigned short**|**short**|Preserva o padrão de bits; o bit de ordem superior torna-se o bit de sinal|  
|**unsigned short**|**long**|Extensão de zero|  
|**unsigned short**|`unsigned char`|Preserva o byte de ordem inferior|  
|**unsigned short**|`unsigned long`|Extensão de zero|  
|**unsigned short**|**float**|Converte em **long**; converte **long** em **float**|  
|**unsigned short**|**double**|Converte em **long**; converte **long** em **double**|  
|**unsigned short**|`long double`|Converte em **long**; converte **long** em **double**|  
|`unsigned long`|`char`|Preserva o byte de ordem inferior|  
|`unsigned long`|**short**|Preserva a palavra de ordem inferior|  
|`unsigned long`|**long**|Preserva o padrão de bits; o bit de ordem superior torna-se o bit de sinal|  
|`unsigned long`|`unsigned char`|Preserva o byte de ordem inferior|  
|`unsigned long`|**unsigned short**|Preserva a palavra de ordem inferior|  
|`unsigned long`|**float**|Converte em **long**; converte **long** em **float**|  
|`unsigned long`|**double**|Converter diretamente em **double**|  
|`unsigned long`|`long double`|Converte em **long**; converte **long** em **double**|  
  
 **Seção específica da Microsoft**  
  
 Para o compilador de C de 32 bits da Microsoft, o tipo `unsigned int` é equivalente ao tipo `unsigned long`. A conversão de um valor `unsigned int` é realizada da mesma maneira que a conversão de um `unsigned long`. As conversões de valores `unsigned long` em **float** não serão precisas se o valor convertido for maior do que o valor **long** positivo máximo com sinal.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Conversões de atribuição](../c-language/assignment-conversions.md)