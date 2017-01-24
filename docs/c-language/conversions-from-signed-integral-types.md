---
title: "Convers&#245;es de tipos integrais assinados | Microsoft Docs"
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
  - "conversões [C++], integral"
  - "conversão de tipo de dados [C++], inteiros assinados e não assinados"
  - "números inteiros, convertendo"
  - "conversões integrais, de assinado"
  - "conversão de tipo [C++], inteiros assinados e não assinados"
ms.assetid: 5eea32f8-8b14-413d-acac-c063b3d118d7
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Convers&#245;es de tipos integrais assinados
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando um inteiro com sinal é convertido em um inteiro sem sinal de tamanho igual ou maior e o valor do inteiro com sinal não é negativo, o valor não é alterado.  A conversão é feita estendendo o sinal do inteiro com sinal.  Um inteiro com sinal é convertido em um inteiro com sinal mais curto truncando os bits de ordem superior.  O resultado é interpretado como um valor sem sinal, conforme é mostrado neste exemplo.  
  
```  
int i = -3;  
unsigned short u;  
  
u = i;   
printf_s( "%hu\n", u );  // Prints 65533  
  
```  
  
 Nenhuma informação é perdida quando um inteiro com sinal é convertido em um valor flutuante; apenas alguma precisão pode ser perdida quando um valor **long int** ou **unsigned long int** é convertido em um valor **float**.  
  
 A tabela a seguir resume as conversões de tipos integrais com sinal.  Ela pressupõe que, por padrão, o tipo `char` tem sinal.  Se você usar uma opção de tempo de compilação para alterar o padrão do tipo `char` para sem sinal, as conversões fornecidas na tabela de [conversões de tipos integrais sem sinal](../c-language/conversions-from-unsigned-integral-types.md) para o tipo `unsigned char` serão aplicadas no lugar das conversões indicadas na tabela a seguir, de conversões de tipos integrais com sinal.  
  
### Conversões de tipos integrais com sinal  
  
|De|Em|Método|  
|--------|--------|------------|  
|`char`1|**short**|Extensão de sinal|  
|`char`|**long**|Extensão de sinal|  
|`char`|`unsigned char`|Preserva o padrão; o bit de ordem superior perde a função como bit de sinal|  
|`char`|**unsigned short**|Extensão de sinal para **short**; converte **short** em **unsigned short**|  
|`char`|`unsigned long`|Extensão de sinal para **long**; converte **long** em `unsigned long`|  
|`char`|**float**|Extensão de sinal para **long**; converte **long** em **float**|  
|`char`|**double**|Extensão de sinal para **long**; converte **long** em **double**|  
|`char`|`long double`|Extensão de sinal para **long**; converte **long** em **double**|  
|**short**|`char`|Preserva o byte de ordem inferior|  
|**short**|**long**|Extensão de sinal|  
|**short**|`unsigned char`|Preserva o byte de ordem inferior|  
|**short**|**unsigned short**|Preserva o padrão de bits; o bit de ordem superior perde a função como bit de sinal|  
|**short**|`unsigned long`|Extensão de sinal para **long**; converte **long** em `unsigned long`|  
|**short**|**float**|Extensão de sinal para **long**; converte **long** em **float**|  
|**short**|**double**|Extensão de sinal para **long**; converte **long** em **double**|  
|**short**|`long double`|Extensão de sinal para **long**; converte **long** em **double**|  
|**long**|`char`|Preserva o byte de ordem inferior|  
|**long**|**short**|Preserva a palavra de ordem inferior|  
|**long**|`unsigned char`|Preserva o byte de ordem inferior|  
|**long**|**unsigned short**|Preserva a palavra de ordem inferior|  
|**long**|`unsigned long`|Preserva o padrão de bits; o bit de ordem superior perde a função como bit de sinal|  
|**long**|**float**|É representado como **float**.  Se **long** não pode ser representado exatamente, alguma precisão é perdida.|  
|**long**|**double**|É representado como **double**.  Se **long** não pode ser representado exatamente como um **double**, alguma precisão é perdida.|  
|**long**|`long double`|É representado como **double**.  Se **long** não pode ser representado exatamente como um **double**, alguma precisão é perdida.|  
  
 1.  Todas as entradas de `char` pressupõem que, por padrão, o tipo `char` tem sinal.  
  
 **Específico da Microsoft**  
  
 Para o compilador de C de 32 bits da Microsoft, um inteiro é equivalente a um **long**.  A conversão de um valor `int` é realizada da mesma forma que para um **long**.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Conversões de atribuição](../c-language/assignment-conversions.md)