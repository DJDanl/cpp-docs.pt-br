---
title: "Funções de membro especiais | Microsoft Docs"
ms.custom: 
ms.date: 12/06/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- special member functions [C++]
- constructors [C++]
- destructors [C++]
- copy operators [C++]
- move operators [C++]
- assignment operators [C++]
ms.assetid: 017d6817-b012-44f0-b153-f3076c251ea7
caps.latest.revision: 17
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 460e6e2ba25566cb4a2295ca4b35590405b51eb3
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="special-member-functions"></a>Funções de membro especiais  
  
O *funções de membro especiais* é classe (ou estrutura) de funções de membro que, em alguns casos, o compilador gera automaticamente para você. Essas funções são o [construtor padrão](constructors-cpp.md#default_constructors), o [destruidor](destructors-cpp.md), o [construtor de cópia e o operador de atribuição de cópia](copy-constructors-and-copy-assignment-operators-cpp.md)e o [construtor de movimentação e Mover o operador de atribuição](move-constructors-and-move-assignment-operators-cpp.md). Se sua classe não define uma ou mais das funções de membro especiais, em seguida, o compilador pode implicitamente declarar e definir as funções que são usadas. As implementações gerados pelo compilador são chamadas de *padrão* funções de membro especiais. O compilador não gera funções se eles não são necessários.  
  
Você pode declarar explicitamente uma função de membro especial padrão usando o `= default` palavra-chave. Isso faz com que o compilador definir a função somente se necessário, da mesma forma como se a função não foi declarada. 

Em alguns casos, o compilador pode gerar *excluído* funções de membro especial, que não são definidas e, portanto, não pode ser chamado. Isso pode ocorrer em casos em que uma chamada para uma função de membro especial específico em uma classe não faz sentido, considerando as outras propriedades da classe. Para evitar a geração automática de uma função de membro especial explicitamente, você pode declará-la como excluído usando a `= delete` palavra-chave.  
  
O compilador gera um *construtor padrão*, um construtor que não aceita argumentos, somente quando você não declarou nenhum outro construtor. Se você declarou apenas um construtor que aceita parâmetros, o código que tenta chamar um construtor padrão faz com que o compilador produzir uma mensagem de erro. O construtor padrão gerado pelo compilador executa simples member-wise [padrão inicialização](initializers.md#default_initialization) do objeto. Inicialização padrão deixa todas as variáveis de membro em um estado indeterminado.  
  
O destruidor padrão executa member-wise destruição do objeto. É virtual apenas se um destruidor de classe base é virtual.  
  
A cópia do padrão e operações de atribuição e mover construção executam padrão de bit member-wise copia ou move de membros de dados não estático. Mova operações são geradas somente quando nenhum destruidor ou operações de movimentação ou cópia são declaradas. Um construtor de cópia padrão é gerado somente quando nenhum construtor de cópia está declarado. Ele é excluído implicitamente se uma operação de movimentação é declarada. Um operador de atribuição de cópia padrão é gerado somente quando nenhum operador de atribuição de cópia é explicitamente declarado. Ele é excluído implicitamente se uma operação de movimentação é declarada.  
  
## <a name="see-also"></a>Consulte também  
[Referência da linguagem C++](cpp-language-reference.md)  



 

