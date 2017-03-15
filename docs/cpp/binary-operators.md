---
title: "Operadores bin&#225;rios | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "operadores binários"
  - "operadores de seleção de membro"
  - "operadores [C++], binário"
ms.assetid: c0e7fbff-bc87-4708-8333-504ac09ee83e
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores bin&#225;rios
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A tabela a seguir mostra uma lista de operadores que podem ser sobrecarregados.  
  
### Operadores binários redefiníveis  
  
|Operador|Nome|  
|--------------|----------|  
|**,**|Vírgula|  
|`!=`|Desigualdade|  
|`%`|Módulo|  
|`%=`|Módulo\/atribuição|  
|**&**|AND bit a bit|  
|**&&**|AND lógico|  
|**&\=**|Atribuição AND bit a bit|  
|**\***|Multiplicação|  
|**\*\=**|Atribuição\/multiplicação|  
|**\+**|Adição|  
|`+=`|Atribuição\/adição|  
|**–**|Subtração|  
|**–\=**|Subtração\/atribuição|  
|**–\>**|Seleção de membro|  
|**–\>\***|Seleção de ponteiro para membro|  
|**\/**|Divisão|  
|`/=`|Divisão\/atribuição|  
|**\<**|Menor que|  
|**\<\<**|Deslocamento para a esquerda|  
|**\<\<\=**|Deslocamento para a esquerda\/atribuição|  
|**\<\=**|Menor ou igual a|  
|**\=**|Atribuição|  
|`==`|Igualdade|  
|**\>**|Maior que|  
|**\>\=**|Maior ou igual a|  
|**\>\>**|Deslocamento para a direita|  
|**\>\>\=**|Deslocamento para direita\/atribuição|  
|**^**|OR exclusivo|  
|`^=`|Atribuição OR exclusivo|  
|**&#124;**|OR inclusivo bit a bit|  
|`&#124;=`|OR inclusivo bit a bit\/atribuição|  
|`&#124;&#124;`|OR lógico|  
  
 Para declarar uma função de operador binário como um membro não estático, você deve declará\-la na forma:  
  
 *ret\-type* **operator**`op`**\(** `arg` **\)**  
  
 onde *ret\-type* é o tipo de retorno, `op` é um dos operadores listados na tabela anterior e `arg` é um argumento de qualquer tipo.  
  
 Para declarar uma função de operador binário como uma função global, você deve declará\-la na forma:  
  
 *ret\-type* **operator**`op`**\(** `arg1`**,** `arg2` **\)**  
  
 onde *ret\-type* e `op` são descritos para as funções do operador do membro e `arg1` e `arg2` são argumentos.  Ao menos um dos argumentos deve ser do tipo da classe.  
  
> [!NOTE]
>  Não há nenhuma restrição quanto aos tipos de retorno dos operadores binários; no entanto, a maioria dos operadores binários definidos pelo usuário retornam um tipo de classe ou uma referência a um tipo de classe.  
  
## Consulte também  
 [Sobrecarga de operador](../cpp/operator-overloading.md)