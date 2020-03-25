---
title: protected (C++)
ms.date: 11/04/2016
f1_keywords:
- protected_cpp
helpviewer_keywords:
- protected keyword [C++], member access
- protected keyword [C++]
ms.assetid: 863d299f-fc0d-45d5-a1a7-bd24b7778a93
ms.openlocfilehash: 29f57eac7201ac0647275c70c539f9b2f28eb81b
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80179244"
---
# <a name="protected-c"></a>protected (C++)

## <a name="syntax"></a>Sintaxe

```
protected:
   [member-list]
protected base-class
```

## <a name="remarks"></a>Comentários

A palavra-chave **Protected** especifica o acesso a membros de classe na *lista de membros* até o próximo especificador de acesso (**público** ou **privado**) ou o final da definição de classe. Os membros de classe declarados como **protegidos** podem ser usados somente pelo seguinte:

- Funções de membro da classe que declarou originalmente esses membros.

- Friends da classe que declarou originalmente esses membros.

- Classes derivadas com acesso público ou protegido da classe que declarou originalmente esses membros.

- Direcionar classes derivadas de modo particular que também têm acesso aos membros protegidos.

Ao anteceder o nome de uma classe base, a palavra-chave **Protected** especifica que os membros públicos e protegidos da classe base são membros protegidos de suas classes derivadas.

Membros protegidos não são tão privados como membros **privados** , que são acessíveis somente para membros da classe na qual eles são declarados, mas não são tão públicos como membros **públicos** , que são acessíveis em qualquer função.

Membros protegidos que também são declarados como **estáticos** são acessíveis a qualquer função Friend ou membro de uma classe derivada. Membros protegidos que não são declarados como **estáticos** são acessíveis a amigos e a funções de membro em uma classe derivada somente por meio de um ponteiro para, referência a ou objeto da classe derivada.

Para obter informações relacionadas, consulte [amigo](../cpp/friend-cpp.md), [público](../cpp/public-cpp.md), [privado](../cpp/private-cpp.md)e a tabela de acesso a membros no [controle de acesso a membros de classe](member-access-control-cpp.md).

## <a name="clr-specific"></a>Específico do /clr

Em tipos CLR, as C++ palavras-chave do especificador de acesso (**pública**, **privada**e **protegida**) podem afetar a visibilidade dos tipos e métodos em relação aos assemblies. Para obter mais informações, consulte [controle de acesso de membro](member-access-control-cpp.md).

> [!NOTE]
>  Arquivos compilados com [/ln](../build/reference/ln-create-msil-module.md) não são afetados por esse comportamento. Nesse caso, todas as classes gerenciadas (públicas ou particulares) serão visíveis.

## <a name="end-clr-specific"></a>Específico de END /clr

## <a name="example"></a>Exemplo

```cpp
// keyword_protected.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
class X {
public:
   void setProtMemb( int i ) { m_protMemb = i; }
   void Display() { cout << m_protMemb << endl; }
protected:
   int  m_protMemb;
   void Protfunc() { cout << "\nAccess allowed\n"; }
} x;

class Y : public X {
public:
   void useProtfunc() { Protfunc(); }
} y;

int main() {
   // x.m_protMemb;         error, m_protMemb is protected
   x.setProtMemb( 0 );   // OK, uses public access function
   x.Display();
   y.setProtMemb( 5 );   // OK, uses public access function
   y.Display();
   // x.Protfunc();         error, Protfunc() is protected
   y.useProtfunc();      // OK, uses public access function
                        // in derived class
}
```

## <a name="see-also"></a>Confira também

[Controlando o acesso a membros de classe](member-access-control-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
