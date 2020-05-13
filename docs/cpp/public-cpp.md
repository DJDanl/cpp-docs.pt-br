---
title: public (C++)
ms.date: 11/04/2016
f1_keywords:
- public_cpp
helpviewer_keywords:
- public keyword [C++]
ms.assetid: f3e10a59-39f6-4bcd-827e-3e99f8f89497
ms.openlocfilehash: bf8293c6a6cf12154b02979de08035807991052c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376047"
---
# <a name="public-c"></a>public (C++)

## <a name="syntax"></a>Sintaxe

```
public:
   [member-list]
public base-class
```

## <a name="remarks"></a>Comentários

Ao preceder uma lista de membros da classe, a palavra-chave **pública** especifica que esses membros estão acessíveis a partir de qualquer função. Isso se aplica a todos os membros declarados até o especificador seguinte do acesso ou ao final da classe.

Ao preceder o nome de uma classe base, a palavra-chave **pública** especifica que os membros públicos e protegidos da classe base são membros públicos e protegidos, respectivamente, da classe derivada.

O acesso padrão dos membros em um classe é particular. O acesso padrão dos membros em uma estrutura ou união é público.

O acesso padrão de uma classe base é particular para classes e público para estruturas. Uniões não podem ter classes base.

Para obter mais informações, consulte [privada](../cpp/private-cpp.md), [protegida,](../cpp/protected-cpp.md) [amiga](../cpp/friend-cpp.md)e a tabela de acesso ao membro no [Controle de Acesso aos Membros de Classe](member-access-control-cpp.md).

## <a name="clr-specific"></a>Específico do /clr

Nos tipos CLR, as palavras-chave especificadoras de acesso C++**(públicas,** **privadas**e **protegidas)** podem afetar a visibilidade dos tipos e métodos em relação aos conjuntos. Para obter mais informações, consulte [O Controle de Acesso ao Membro](member-access-control-cpp.md).

> [!NOTE]
> Os arquivos compilados com [/LN](../build/reference/ln-create-msil-module.md) não são afetados por esse comportamento. Nesse caso, todas as classes gerenciadas (públicas ou particulares) serão visíveis.

## <a name="end-clr-specific"></a>Específico de END /clr

## <a name="example"></a>Exemplo

```cpp
// keyword_public.cpp
class BaseClass {
public:
   int pubFunc() { return 0; }
};

class DerivedClass : public BaseClass {};

int main() {
   BaseClass aBase;
   DerivedClass aDerived;
   aBase.pubFunc();       // pubFunc() is accessible
                          //    from any function
   aDerived.pubFunc();    // pubFunc() is still public in
                          //    derived class
}
```

## <a name="see-also"></a>Confira também

[Controlando o acesso a membros de classe](member-access-control-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
