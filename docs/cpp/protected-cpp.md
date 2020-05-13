---
title: protected (C++)
ms.date: 11/04/2016
f1_keywords:
- protected_cpp
helpviewer_keywords:
- protected keyword [C++], member access
- protected keyword [C++]
ms.assetid: 863d299f-fc0d-45d5-a1a7-bd24b7778a93
ms.openlocfilehash: 79ca081726c1f26a251763e2533ade730f075e2f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317263"
---
# <a name="protected-c"></a>protected (C++)

## <a name="syntax"></a>Sintaxe

```
protected:
   [member-list]
protected base-class
```

## <a name="remarks"></a>Comentários

A palavra-chave **protegida** especifica o acesso aos membros da classe na *lista de membros* até o próximo especificador de acesso **(público** ou **privado)** ou o fim da definição de classe. Os membros da classe declarados **como protegidos** só podem ser usados pelo seguinte:

- Funções de membro da classe que declarou originalmente esses membros.

- Friends da classe que declarou originalmente esses membros.

- Classes derivadas com acesso público ou protegido da classe que declarou originalmente esses membros.

- Direcionar classes derivadas de modo particular que também têm acesso aos membros protegidos.

Ao preceder o nome de uma classe base, a palavra-chave **protegida** especifica que os membros públicos e protegidos da classe base são membros protegidos de suas classes derivadas.

Os membros protegidos não são tão privados quanto os **membros privados,** que são acessíveis apenas aos membros da classe em que são declarados, mas não são tão públicos quanto os membros **públicos,** que são acessíveis em qualquer função.

Membros protegidos que também são declarados **estáticos** são acessíveis a qualquer função de amigo ou membro de uma classe derivada. Membros protegidos que não são declarados **como estáticos** são acessíveis a amigos e funções de membros em uma classe derivada apenas através de um ponteiro para, referência ou objeto da classe derivada.

Para obter informações relacionadas, consulte [amigos,](../cpp/friend-cpp.md) [públicos,](../cpp/public-cpp.md) [privados](../cpp/private-cpp.md)e a tabela de acesso ao membro no [Controle de Acesso aos Membros de Classe](member-access-control-cpp.md).

## <a name="clr-specific"></a>Específico do /clr

Nos tipos CLR, as palavras-chave especificadoras de acesso C++**(públicas,** **privadas**e **protegidas)** podem afetar a visibilidade dos tipos e métodos em relação aos conjuntos. Para obter mais informações, consulte [O Controle de Acesso ao Membro](member-access-control-cpp.md).

> [!NOTE]
> Os arquivos compilados com [/LN](../build/reference/ln-create-msil-module.md) não são afetados por esse comportamento. Nesse caso, todas as classes gerenciadas (públicas ou particulares) serão visíveis.

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
