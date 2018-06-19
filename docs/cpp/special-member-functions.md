---
title: Funções de membro especiais | Microsoft Docs
ms.custom: ''
ms.date: 12/06/2016
ms.technology:
- cpp-language
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 76be131193508e4def79c6e178e27cd671c7ce11
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32422830"
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



 
