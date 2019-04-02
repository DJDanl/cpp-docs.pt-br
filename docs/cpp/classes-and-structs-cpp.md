---
title: Classes e structs (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- Visual C++, classes
- structures, C++ classes
- user-defined types
- classes [C++]
- user-defined types, C++ classes
ms.assetid: 516dd496-13fb-4f17-845a-e9ca45437873
ms.openlocfilehash: c28f83e7853ffb09bba7721ec71ab43c85aedb0c
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58779385"
---
# <a name="classes-and-structs-c"></a>Classes e structs (C++)

Esta seção apresenta as estruturas e classes do C++. As duas construções são idênticas em C++, exceto em structs a acessibilidade padrão é pública, enquanto em classes, o padrão é particular.

Classes e structs são as construções no qual definir seus próprios tipos. Classes e structs podem conter membros de dados e funções de membro, que permitem que você descrevem o estado e o comportamento do tipo.

Os seguintes tópicos estão incluídos:

- [class](../cpp/class-cpp.md)

- [struct](../cpp/struct-cpp.md)

- [Visão geral de membros de classe](../cpp/class-member-overview.md)

- [Controle de Acesso a membro](../cpp/member-access-control-cpp.md)

- [Herança](../cpp/inheritance-cpp.md)

- [Membros estáticos](../cpp/static-members-cpp.md)

- [Conversões de tipo definido pelo usuário](../cpp/user-defined-type-conversions-cpp.md)

- [Mutáveis (especificador mutável) os membros de dados](../cpp/mutable-data-members-cpp.md)

- [Declarações de classe aninhada](../cpp/nested-class-declarations.md)

- [Tipos de classe anônima](../cpp/anonymous-class-types.md)

- [Ponteiros para membros](../cpp/pointers-to-members.md)

- [Ponteiro this](../cpp/this-pointer.md)

- [Campos de bits C++](../cpp/cpp-bit-fields.md)

Os três tipos de classe são estrutura, classe e união. Elas são declaradas usando o [struct](../cpp/struct-cpp.md), [classe](../cpp/class-cpp.md), e [união](../cpp/unions.md) palavras-chave. A tabela a seguir mostra as diferenças entre os três tipos de classe.

Para obter mais informações sobre uniões, consulte [uniões](../cpp/unions.md). Para obter informações sobre classes e estruturas em C + + c++ /CLI e c++ /CLI CX, consulte [Classes e Structs](../extensions/classes-and-structs-cpp-component-extensions.md).

### <a name="access-control-and-constraints-of-structures-classes-and-unions"></a>Controle de acesso e restrições de estruturas, classes e uniões

|Estruturas|Classes|Uniões|
|----------------|-------------|------------|
|chave da classe é **struct**|chave da classe é **classe**|chave da classe é **union**|
|O acesso padrão é público|O acesso padrão é particular|O acesso padrão é público|
|Nenhuma restrição de uso|Nenhuma restrição de uso|Use apenas um membro de cada vez|

## <a name="see-also"></a>Consulte também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)