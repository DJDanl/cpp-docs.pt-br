---
title: public (C++)
ms.date: 11/04/2016
f1_keywords:
- public_cpp
helpviewer_keywords:
- public keyword [C++]
ms.assetid: f3e10a59-39f6-4bcd-827e-3e99f8f89497
ms.openlocfilehash: 24cc4dd3cd7e0c893664339e7ad83383839b0b11
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50600354"
---
# <a name="public-c"></a>public (C++)

## <a name="syntax"></a>Sintaxe

```
public:
   [member-list]
public base-class
```

## <a name="remarks"></a>Comentários

Quando precede uma lista de membros de classe, o **pública** palavra-chave especifica que esses membros são acessíveis de qualquer função. Isso se aplica a todos os membros declarados até o especificador seguinte do acesso ou ao final da classe.

Preceder o nome de uma classe base, o **pública** palavra-chave especifica que os membros públicos e protegidos da classe base são públicos e protegidos membros, respectivamente, da classe derivada.

O acesso padrão dos membros em um classe é particular. O acesso padrão dos membros em uma estrutura ou união é público.

O acesso padrão de uma classe base é particular para classes e público para estruturas. Uniões não podem ter classes base.

Para obter mais informações, consulte [privados](../cpp/private-cpp.md), [protegido](../cpp/protected-cpp.md), [amigo](../cpp/friend-cpp.md)e a tabela de acesso de membro no [controlando o acesso a membros de classe](member-access-control-cpp.md) .

## <a name="clr-specific"></a>Específico do /clr

Nos tipos de CLR, o C++ palavras-chave do especificador de acesso (**pública**, **privada**, e **protegido**) podem afetar a visibilidade de tipos e métodos em relação aos assemblies. Para obter mais informações, consulte [controle de acesso de membro](member-access-control-cpp.md).

> [!NOTE]
>  Arquivos compilados com [/LN](../build/reference/ln-create-msil-module.md) não são afetados por esse comportamento. Nesse caso, todas as classes gerenciadas (públicas ou particulares) serão visíveis.

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

## <a name="see-also"></a>Consulte também

[Controlando o acesso a membros de classe](member-access-control-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)