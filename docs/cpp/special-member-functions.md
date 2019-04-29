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
ms.openlocfilehash: 3b26628fd18749bd19819fe787888fd3264a79d1
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62330974"
---
# <a name="special-member-functions"></a>Funções de membro especiais

O *funções de membro especial* é a classe (ou struct) funções de membro que, em alguns casos, o compilador gera automaticamente para você. Essas funções são as [construtor padrão](constructors-cpp.md#default_constructors), o [destruidor](destructors-cpp.md), o [construtor de cópia e o operador de atribuição de cópia](copy-constructors-and-copy-assignment-operators-cpp.md)e o [construtor de movimentação e Mover operador de atribuição](move-constructors-and-move-assignment-operators-cpp.md). Se sua classe não definir uma ou mais das funções de membro especial, em seguida, o compilador pode implicitamente declarar e definir as funções que são usadas. As implementações geradas pelo compilador são chamadas de *padrão* funções de membro especial. O compilador não gera funções se eles não são necessários.

Você pode declarar explicitamente uma função de membro especial padrão usando o **= default** palavra-chave. Isso faz com que o compilador definir a função somente se necessário, da mesma forma como se a função não foi declarada.

Em alguns casos, o compilador pode gerar *excluído* funções de membro especial, que não estão definidas e, portanto, não pode ser chamado. Isso pode ocorrer em casos em que uma chamada para uma função de membro especial específico em uma classe não faz sentido, devido a outras propriedades da classe. Para evitar a geração automática de uma função de membro especial explicitamente, você pode declará-la como excluído usando o **= excluir** palavra-chave.

O compilador gera uma *construtor padrão*, um construtor que não usa argumentos, somente quando você não declarar qualquer outro construtor. Se você declarar um construtor que usa parâmetros, o código tenta chamar um construtor padrão faz com que o compilador a produzir uma mensagem de erro. O construtor padrão gerado pelo compilador executa simples member-wise [inicialização padrão](initializers.md#default_initialization) do objeto. Inicialização padrão deixa todas as variáveis de membro em um estado indeterminado.

O destruidor padrão executa destruição por membros do objeto. Ele é virtual apenas se um destruidor de classe base é virtual.

Padrão de bit por membros de executar a cópia do padrão e operações de atribuição e construção de movimentação copia ou move membros de dados não estáticos. Mova as operações são geradas apenas quando não são declaradas nenhum destruidor ou operações de movimentação ou cópia. Um construtor de cópia padrão é gerado somente quando nenhum construtor de cópia é declarado. Ele é excluído implicitamente se uma operação de movimentação for declarada. Um operador de atribuição de cópia padrão é gerado somente quando nenhum operador de atribuição de cópia for declarado explicitamente. Ele é excluído implicitamente se uma operação de movimentação for declarada.

## <a name="see-also"></a>Consulte também

[Referência da linguagem C++](cpp-language-reference.md)