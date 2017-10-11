---
title: "Operadores binários | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- member-selection operators [C++]
- operators [C++], binary
- binary operators [C++]
ms.assetid: c0e7fbff-bc87-4708-8333-504ac09ee83e
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 384ac135c7ecb63b864160723984ef5d271e1395
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="binary-operators"></a>Operadores binários
A tabela a seguir mostra uma lista de operadores que podem ser sobrecarregados.  
  
### <a name="redefinable-binary-operators"></a>Operadores binários redefiníveis  
  
|Operador|Nome|  
|--------------|----------|  
|**,**|Vírgula|  
|`!=`|Desigualdade|  
|`%`|Módulo|  
|`%=`|Módulo/atribuição|  
|**&**|AND bit a bit|  
|**&&**|AND lógico|  
|**&=**|Atribuição AND bit a bit|  
|**\***|Multiplicação|  
|**\*=**|Atribuição/multiplicação|  
|**+**|Adição|  
|`+=`|Atribuição/adição|  
|**-**|Subtração|  
|**-=**|Subtração/atribuição|  
|**->**|Seleção de membro|  
|**->\***|Seleção de ponteiro para membro|  
|**/**|Divisão|  
|`/=`|Divisão/atribuição|  
|**<**|Menor que|  
|**<<**|Shift esquerda|  
|**<<=**|Deslocamento para a esquerda/atribuição|  
|**<=**|Menor ou igual a|  
|**=**|Atribuição|  
|`==`|Igualdade|  
|**>**|Maior que|  
|**>=**|Maior ou igual a|  
|**>>**|Shift direita|  
|**>>=**|Deslocamento para direita/atribuição|  
|**^**|OR exclusivo|  
|`^=`|Atribuição OR exclusivo|  
|**&#124;**|OR inclusivo de bit a bit|  
|`&#124;=`|OR inclusivo bit a bit/atribuição|  
|`&#124;&#124;`|OR lógico|  
  
 Para declarar uma função de operador binário como um membro não estático, você deve declará-la na forma:  
  
 *tipo ret* **operador**`op`**(** `arg` **)**  
  
 onde *tipo ret* é o tipo de retorno, `op` é um dos operadores listados na tabela anterior, e `arg` é um argumento de qualquer tipo.  
  
 Para declarar uma função de operador binário como uma função global, você deve declará-la na forma:  
  
 *tipo ret* **operador**`op`**(** `arg1` **,** `arg2` **)**  
  
 onde *tipo ret* e `op` são conforme descrito para funções de operador de membro e `arg1` e `arg2` são argumentos. Ao menos um dos argumentos deve ser do tipo da classe.  
  
> [!NOTE]
>  Não há nenhuma restrição quanto aos tipos de retorno dos operadores binários; no entanto, a maioria dos operadores binários definidos pelo usuário retornam um tipo de classe ou uma referência a um tipo de classe.  
  
## <a name="see-also"></a>Consulte também  
 [Sobrecarga de Operador](../cpp/operator-overloading.md)
