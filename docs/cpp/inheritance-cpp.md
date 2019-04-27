---
title: Herança (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- derived classes [C++]
- derived classes [C++], about derived classes
- classes [C++], derived
ms.assetid: 3534ca19-d9ed-4a40-be1b-b921ad0e6956
ms.openlocfilehash: 0180a2f7b41e3169bc9e25d8b598dbe2b84be088
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62184574"
---
# <a name="inheritance--c"></a>Herança (C++)

Esta seção explica como usar classes derivadas para gerar programas extensíveis.

## <a name="overview"></a>Visão geral

Novas classes podem ser derivadas de classes existentes por meio de um mecanismo chamado "herança" (consulte as informações a partir [herança única](../cpp/single-inheritance.md)). As classes que são usadas para derivação são chamadas "classes base" de uma classe derivada específica. Uma classe derivada é declarada mediante a seguinte sintaxe:

```cpp
class Derived : [virtual] [access-specifier] Base
{
   // member list
};
class Derived : [virtual] [access-specifier] Base1,
   [virtual] [access-specifier] Base2, . . .
{
   // member list
};
```

Depois da marca (nome) da classe, aparecem dois-pontos seguidos por uma lista de especificações de base.  As classes base nomeadas dessa forma devem ter sido declaradas anteriormente.  As especificações de base podem conter um especificador de acesso, que é uma das palavras-chave **pública**, **protegido** ou **privada**.  Esses especificadores de acesso aparecem antes do nome da classe base e só se aplicam a essa classe base.  Esses especificadores controlam a permissão da classe derivada para usar os membros da classe base.  Ver [controle de acesso de membro](../cpp/member-access-control-cpp.md) para obter informações sobre o acesso a membros de classe base.  Se o especificador de acesso for omitido, o acesso a essa base é considerado **privada**.  As especificações de base podem conter a palavra-chave **virtual** para indicar a herança virtual.  Essa palavra-chave pode aparecer antes ou depois do especificador de acesso, se houver.  Se for usada a herança virtual, a classe base será conhecida como uma classe base virtual.

É possível especificar várias classes base, separadas por vírgulas.  Se uma única classe base for especificada, o modelo de herança será [herança única](../cpp/single-inheritance.md). Se mais de uma classe base for especificada, o modelo de herança é chamado [herança múltipla](../cpp/multiple-base-classes.md).

Os seguintes tópicos estão incluídos:

- [Herança única](../cpp/single-inheritance.md)

- [Várias classes base](../cpp/multiple-base-classes.md)

- [Funções virtuais](../cpp/virtual-functions.md)

- [Substituições explícitas](../cpp/explicit-overrides-cpp.md)

- [Classes abstratas](../cpp/abstract-classes-cpp.md)

- [Resumo das regras de escopo](../cpp/summary-of-scope-rules.md)

O [super](../cpp/super.md) e [interface](../cpp/interface.md) palavras-chave são documentadas nesta seção.

## <a name="see-also"></a>Consulte também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)