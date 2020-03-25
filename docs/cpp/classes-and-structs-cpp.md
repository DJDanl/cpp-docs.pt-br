---
title: Classes e structs (C++)
ms.date: 05/07/2019
helpviewer_keywords:
- C++, classes and structs
ms.assetid: 516dd496-13fb-4f17-845a-e9ca45437873
ms.openlocfilehash: 19d95c9519670db39f3ca467aff794233823d7ba
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80180882"
---
# <a name="classes-and-structs-c"></a>Classes e structs (C++)

Esta seção apresenta C++ classes e estruturas. As duas construções são idênticas em C++ , exceto que, em structs, a acessibilidade padrão é pública, enquanto em classes o padrão é privado.

Classes e structs são as construções pelas quais você define seus próprios tipos. Classes e structs podem conter membros de dados e funções de membro, que permitem descrever o estado e o comportamento do tipo.

Os tópicos a seguir estão incluídos:

- [class](../cpp/class-cpp.md)

- [struct](../cpp/struct-cpp.md)

- [Visão geral de membros de classe](../cpp/class-member-overview.md)

- [Controle de Acesso a membro](../cpp/member-access-control-cpp.md)

- [Herança](../cpp/inheritance-cpp.md)

- [Membros estáticos](../cpp/static-members-cpp.md)

- [Conversões de tipo definido pelo usuário](../cpp/user-defined-type-conversions-cpp.md)

- [Membros de dados mutáveis (especificador mutável)](../cpp/mutable-data-members-cpp.md)

- [Declarações de classe aninhada](../cpp/nested-class-declarations.md)

- [Tipos de classe anônima](../cpp/anonymous-class-types.md)

- [Ponteiros para membros](../cpp/pointers-to-members.md)

- [Ponteiro this](../cpp/this-pointer.md)

- [Campos de bits C++](../cpp/cpp-bit-fields.md)

Os três tipos de classe são estrutura, classe e união. Eles são declarados usando as palavras-chave [struct](../cpp/struct-cpp.md), [Class](../cpp/class-cpp.md)e [Union](../cpp/unions.md) . A tabela a seguir mostra as diferenças entre os três tipos de classe.

Para obter mais informações sobre uniões, consulte [uniões](../cpp/unions.md). Para obter informações sobre classes e structs C++em/CLI C++e/CX, consulte [classes e structs](../extensions/classes-and-structs-cpp-component-extensions.md).

### <a name="access-control-and-constraints-of-structures-classes-and-unions"></a>Controle de acesso e restrições de estruturas, classes e uniões

|Estruturas|Classes|Uniões|
|----------------|-------------|------------|
|a chave de classe é **struct**|a classe Key é **Class**|a chave de classe é **Union**|
|O acesso padrão é público|O acesso padrão é particular|O acesso padrão é público|
|Nenhuma restrição de uso|Nenhuma restrição de uso|Use apenas um membro de cada vez|

## <a name="see-also"></a>Confira também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)
