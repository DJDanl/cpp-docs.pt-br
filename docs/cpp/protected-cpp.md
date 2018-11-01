---
title: protected (C++)
ms.date: 11/04/2016
f1_keywords:
- protected_cpp
helpviewer_keywords:
- protected keyword [C++], member access
- protected keyword [C++]
ms.assetid: 863d299f-fc0d-45d5-a1a7-bd24b7778a93
ms.openlocfilehash: 1cbe88a80b83caa78972d1e2799c1e0d87d1cb0a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50470974"
---
# <a name="protected-c"></a>protected (C++)

## <a name="syntax"></a>Sintaxe

```
protected:
   [member-list]
protected base-class
```

## <a name="remarks"></a>Comentários

O **protegidos** palavra-chave especifica o acesso a membros de classe na *lista de membros* até o próximo especificador de acesso (**público** ou **privada**) ou no final da definição de classe. Membros de classe declarados como **protegidos** pode ser usado somente pelo seguinte:

- Funções de membro da classe que declarou originalmente esses membros.

- Friends da classe que declarou originalmente esses membros.

- Classes derivadas com acesso público ou protegido da classe que declarou originalmente esses membros.

- Direcionar classes derivadas de modo particular que também têm acesso aos membros protegidos.

Preceder o nome de uma classe base, o **protegidos** palavra-chave especifica que os membros públicos e protegidos da classe base são membros protegidos de suas classes derivadas.

Membros protegidos não são tão particulares quanto **privados** membros, que são acessíveis somente aos membros da classe na qual eles são declarados, mas eles não são tão públicos quanto **público** membros, que são acessíveis no qualquer função.

Membros protegidos que também são declarados como **estático** podem ser acessados por qualquer friend ou função de membro de uma classe derivada. Membros que não são declarados como protegidos **estático** podem ser acessados por friends e funções de membro em uma classe derivada somente por meio de um ponteiro para fazer referência ao, ou o objeto da classe derivada.

Para obter informações relacionadas, consulte [amigo](../cpp/friend-cpp.md), [pública](../cpp/public-cpp.md), [privada](../cpp/private-cpp.md)e a tabela de acesso de membro no [controlando o acesso a membros de classe](member-access-control-cpp.md) .

## <a name="clr-specific"></a>Específico do /clr

Nos tipos de CLR, o C++ palavras-chave do especificador de acesso (**pública**, **privada**, e **protegido**) podem afetar a visibilidade de tipos e métodos em relação aos assemblies. Para obter mais informações, consulte [controle de acesso de membro](member-access-control-cpp.md).

> [!NOTE]
>  Arquivos compilados com [/LN](../build/reference/ln-create-msil-module.md) não são afetados por esse comportamento. Nesse caso, todas as classes gerenciadas (públicas ou particulares) serão visíveis.

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

## <a name="see-also"></a>Consulte também

[Controlando o acesso a membros de classe](member-access-control-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)