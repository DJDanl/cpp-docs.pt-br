---
title: Funções de membro especiais
ms.date: 12/06/2016
helpviewer_keywords:
- special member functions [C++]
- constructors [C++]
- destructors [C++]
- copy operators [C++]
- move operators [C++]
- assignment operators [C++]
ms.assetid: 017d6817-b012-44f0-b153-f3076c251ea7
ms.openlocfilehash: b15a0e50774bbc4e70912a31f9a57ea0439f2c12
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80178685"
---
# <a name="special-member-functions"></a>Funções de membro especiais

As *funções de membro especiais* são funções de membro de classe (ou struct) que, em determinados casos, o compilador gera automaticamente para você. Essas funções são o [construtor padrão](constructors-cpp.md#default_constructors), o [destruidor](destructors-cpp.md), o [Construtor de cópia e o operador de atribuição de cópia](copy-constructors-and-copy-assignment-operators-cpp.md)e o [Construtor de movimentação e o operador de atribuição de movimento](move-constructors-and-move-assignment-operators-cpp.md). Se sua classe não definir uma ou mais das funções de membro especiais, o compilador poderá declarar e definir implicitamente as funções que são usadas. As implementações geradas pelo compilador são chamadas de funções de membro especiais *padrão* . O compilador não gerará funções se elas não forem necessárias.

Você pode declarar explicitamente uma função de membro especial padrão usando a palavra-chave **= Default** . Isso faz com que o compilador defina a função somente se necessário, da mesma maneira como se a função não fosse declarada.

Em alguns casos, o compilador pode gerar funções de membro especiais *excluídas* , que não são definidas e, portanto, não podem ser chamadas. Isso pode acontecer em casos em que uma chamada para uma função de membro especial específica em uma classe não faz sentido, dadas outras propriedades da classe. Para impedir explicitamente a geração automática de uma função de membro especial, você pode declará-la como excluída usando a palavra-chave **= delete** .

O compilador gera um *construtor padrão*, um construtor que não usa argumentos, somente quando você não declarou nenhum outro construtor. Se você declarou apenas um construtor que usa parâmetros, o código que tenta chamar um construtor padrão faz com que o compilador produza uma mensagem de erro. O construtor padrão gerado pelo compilador executa uma [inicialização padrão](initializers.md#default_initialization) simples de membro do objeto. A inicialização padrão deixa todas as variáveis de membro em um estado indeterminado.

O destruidor padrão executa a destruição de membros do objeto. Ele será virtual somente se um destruidor de classe base for virtual.

As operações de construção e atribuição de cópia e movimentação padrão executam cópias de padrão de bits ou movimentações de membros de dados não estáticos. As operações de movimentação são geradas somente quando nenhuma operação de destruidor ou de movimentação ou cópia é declarada. Um construtor de cópia padrão só é gerado quando nenhum construtor de cópia é declarado. Ele será excluído implicitamente se uma operação de movimentação for declarada. Um operador de atribuição de cópia padrão é gerado somente quando nenhum operador de atribuição de cópia é declarado explicitamente. Ele será excluído implicitamente se uma operação de movimentação for declarada.

## <a name="see-also"></a>Confira também

[Referência da linguagem C++](cpp-language-reference.md)
