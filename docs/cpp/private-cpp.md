---
title: private (C++)
ms.date: 11/04/2016
f1_keywords:
- private_cpp
helpviewer_keywords:
- private keyword [C++]
ms.assetid: 94e99983-46a5-4e21-800c-28f8a7c6a8ff
ms.openlocfilehash: 19ea551f625cac02e639753a976eddb7a5fa164b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50622268"
---
# <a name="private-c"></a>private (C++)

## <a name="syntax"></a>Sintaxe

```
private:
   [member-list]
private base-class
```

## <a name="remarks"></a>Comentários

Quando precede uma lista de membros de classe, o **privada** palavra-chave especifica que esses membros são acessíveis somente de funções de membro e friends da classe. Isso se aplica a todos os membros declarados até o especificador seguinte do acesso ou ao final da classe.

Preceder o nome de uma classe base, o **privada** palavra-chave especifica que os membros públicos e protegidos da classe base são membros particulares da classe derivada.

O acesso padrão dos membros em um classe é particular. O acesso padrão dos membros em uma estrutura ou união é público.

O acesso padrão de uma classe base é particular para classes e público para estruturas. Uniões não podem ter classes base.

Para obter informações relacionadas, consulte [amigo](../cpp/friend-cpp.md), [pública](../cpp/public-cpp.md), [protegido](../cpp/protected-cpp.md)e a tabela de acesso de membro em [controlando o acesso a membros de classe](member-access-control-cpp.md).

## <a name="clr-specific"></a>Específico do /clr

Nos tipos de CLR, o C++ palavras-chave do especificador de acesso (**pública**, **privada**, e **protegido**) podem afetar a visibilidade de tipos e métodos em relação aos assemblies. Para obter mais informações, consulte [controle de acesso de membro](member-access-control-cpp.md).

> [!NOTE]
>  Arquivos compilados com [/LN](../build/reference/ln-create-msil-module.md) não são afetados por esse comportamento. Nesse caso, todas as classes gerenciadas (públicas ou particulares) serão visíveis.

## <a name="end-clr-specific"></a>Específico de END /clr

## <a name="example"></a>Exemplo

```cpp
// keyword_private.cpp
class BaseClass {
public:
   // privMem accessible from member function
   int pubFunc() { return privMem; }
private:
   void privMem;
};

class DerivedClass : public BaseClass {
public:
   void usePrivate( int i )
      { privMem = i; }   // C2248: privMem not accessible
                         // from derived class
};

class DerivedClass2 : private BaseClass {
public:
   // pubFunc() accessible from derived class
   int usePublic() { return pubFunc(); }
};

int main() {
   BaseClass aBase;
   DerivedClass aDerived;
   DerivedClass2 aDerived2;
   aBase.privMem = 1;     // C2248: privMem not accessible
   aDerived.privMem = 1;  // C2248: privMem not accessible
                          //    in derived class
   aDerived2.pubFunc();   // C2247: pubFunc() is private in
                          //    derived class
}
```

## <a name="see-also"></a>Consulte também

[Controlando o acesso a membros de classe](member-access-control-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)