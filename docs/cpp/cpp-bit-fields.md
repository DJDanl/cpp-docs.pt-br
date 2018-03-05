---
title: Campos de Bit C++ | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- bitfields [C++]
- fields [C++], bit
- bit fields
ms.assetid: 6f4b62e3-cc1d-4e5d-bf34-05904104f71a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ff6b2a37c511313bd129705da38e66380e89edae
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="c-bit-fields"></a>Campos de bit C++
As classes e as estruturas podem conter membros que ocupam menos armazenamento do que um tipo integral. Esses membros são especificados como campos de bits. A sintaxe para o campo de bits *Declarador de membro* especificação segue:  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
declarator  : constant-expression  
```  
  
## <a name="remarks"></a>Comentários  
 O elemento (opcional) `declarator` é o nome pelo qual o membro é acessado no programa. Deve ser um tipo integral (incluindo tipos enumerados). O *expressão constante* Especifica o número de bits que ocupa o membro da estrutura. Campos de bits anônimos - ou seja, membros de campos de bits sem identificador - podem ser usados para preenchimento.  
  
> [!NOTE]
>  Um campo de bits não nomeado de largura 0 força o alinhamento do próximo campo de bits com o próximo limite de `type`, onde `type` é o tipo do membro.  
  
 O exemplo a seguir declara uma estrutura que contém campos de bits:  
  
```  
// bit_fields1.cpp  
// compile with: /LD  
struct Date {  
   unsigned short nWeekDay  : 3;    // 0..7   (3 bits)  
   unsigned short nMonthDay : 6;    // 0..31  (6 bits)  
   unsigned short nMonth    : 5;    // 0..12  (5 bits)  
   unsigned short nYear     : 8;    // 0..100 (8 bits)  
};  
```  
  
 O layout de memória conceitual de um objeto do tipo `Date` é mostrado na figura a seguir.  
  
 ![Layout de memória de um objeto de data](../cpp/media/vc38uq1.png "vc38UQ1")  
Layout de memória de um objeto Date  
  
 Observe que `nYear` é de 8 bits de comprimento e excederia o limite de palavra do tipo declarado, **unsigned short**. Portanto, ele é iniciado no início de um novo **unsigned short**. Não é necessário que todos os campos de bits caibam em um mesmo objeto do tipo subjacente; novas unidades de armazenamento são alocadas de acordo com o número de bits solicitados na declaração.  
  
 **Seção específica da Microsoft**  
  
 A ordenação dos dados declarados como campos de bits vai do bit inferior até o superior, como mostra a figura acima.  
  
 **Fim da seção específica da Microsoft**  
  
 Se a declaração de uma estrutura inclui um campo não nomeado de comprimento 0, como mostrado no exemplo a seguir,  
  
```  
// bit_fields2.cpp  
// compile with: /LD  
struct Date {  
   unsigned nWeekDay  : 3;    // 0..7   (3 bits)  
   unsigned nMonthDay : 6;    // 0..31  (6 bits)  
   unsigned           : 0;    // Force alignment to next boundary.  
   unsigned nMonth    : 5;    // 0..12  (5 bits)  
   unsigned nYear     : 8;    // 0..100 (8 bits)  
};  
```  
  
 o layout de memória fica conforme ilustrado na figura a seguir.  
  
 ![Layout de objeto de data com zero &#45; o campo de bits de comprimento](../cpp/media/vc38uq2.png "vc38UQ2")  
Layout do objeto Date com campo de bits de comprimento zero  
  
 O tipo subjacente de um campo de bits deve ser um tipo integral, conforme descrito em [tipos fundamentais](../cpp/fundamental-types-cpp.md).  
  
## <a name="restrictions-on-bit-fields"></a>Restrições em campos de bits  
 A lista a seguir detalha as operações erradas em campos de bits:  
  
1.  Obtendo o endereço de um campo de bits.  
  
2.  Inicializando uma referência com um campo de bits.  
  
## <a name="see-also"></a>Consulte também  
 [Classes e Structs](../cpp/classes-and-structs-cpp.md)