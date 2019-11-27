---
title: Classes C++ como tipos de valor
ms.date: 11/19/2019
ms.topic: conceptual
ms.assetid: f63bb62c-60da-40d5-ac14-4366608fe260
ms.openlocfilehash: 1aabcad46e848e1a499a142adaba5002a829bbf5
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74246017"
---
# <a name="c-classes-as-value-types"></a>Classes C++ como tipos de valor

C++as classes são por tipos de valor padrão. Eles podem ser especificados como tipos de referência, o que permite o comportamento polimórfico para dar suporte à programação orientada a objeto. Os tipos de valor às vezes são exibidos a partir da perspectiva da memória e do controle de layout, enquanto os tipos de referência são sobre classes base e funções virtuais para fins polimórficos. Por padrão, os tipos de valor são copiáveis, o que significa que há sempre um construtor de cópia e um operador de atribuição de cópia. Para tipos de referência, você torna a classe não-copiável (desabilita o construtor de cópia e o operador de atribuição de cópia) e usa um destruidor virtual que dá suporte ao polimorfismo pretendido. Os tipos de valor também são sobre o conteúdo, que, quando eles são copiados, sempre fornecem dois valores independentes que podem ser modificados separadamente. Tipos de referência são sobre identidade – que tipo de objeto é? Por esse motivo, "tipos de referência" também são chamados de "tipos polimórficos".

Se você realmente quiser um tipo de referência (classe base, funções virtuais), será necessário desabilitar explicitamente a cópia, conforme mostrado na classe `MyRefType` no código a seguir.

```cpp
// cl /EHsc /nologo /W4

class MyRefType {
private:
    MyRefType & operator=(const MyRefType &);
    MyRefType(const MyRefType &);
public:
    MyRefType () {}
};

int main()
{
    MyRefType Data1, Data2;
    // ...
    Data1 = Data2;
}
```

A compilação do código acima resultará no seguinte erro:

```Output
test.cpp(15) : error C2248: 'MyRefType::operator =' : cannot access private member declared in class 'MyRefType'
        meow.cpp(5) : see declaration of 'MyRefType::operator ='
        meow.cpp(3) : see declaration of 'MyRefType'
```

## <a name="value-types-and-move-efficiency"></a>Tipos de valor e eficiência de movimentação

A sobrecarga de alocação de cópia é evitada devido a novas otimizações de cópia. Por exemplo, quando você insere uma cadeia de caracteres no meio de um vetor de cadeias de caracteres, não haverá sobrecarga de realocação de cópia, apenas uma mudança, mesmo se resultar em um crescimento do próprio vetor. Isso também se aplica a outras operações, por exemplo, executando uma operação de adição em dois objetos muito grandes. Como você habilita essas otimizações de operação de valor? Em alguns C++ compiladores, o compilador permitirá isso para você implicitamente, assim como os construtores de cópia podem ser gerados automaticamente pelo compilador. No entanto C++, no, sua classe precisará "aceitar" para mover a atribuição e os construtores declarando-os em sua definição de classe. Isso é feito usando a referência a "e comercial dupla" (& &) rvalue nas declarações de função de membro apropriadas e definindo os métodos de atribuição de construtor e de movimentação de movimentação.  Você também precisa inserir o código correto para "roubar o entranhas" do objeto de origem.

Como você decide se precisa de uma movimentação habilitada? Se você já sabe que precisa de construção de cópia habilitada, provavelmente deseja mover habilitada se ela puder ser mais barata do que uma cópia em profundidade. No entanto, se você souber que precisa de suporte de movimentação, isso não significa necessariamente que você deseja que a cópia seja habilitada. Esse último caso seria chamado de "tipo somente de movimentação". Um exemplo já na biblioteca padrão é `unique_ptr`. Como uma observação adicional, o antigo `auto_ptr` é preterido e foi substituído por `unique_ptr` precisamente devido à falta de suporte à semântica de movimentação na versão anterior do C++.

Usando a semântica de movimentação, você pode retornar por valor ou inserir no meio. Move é uma otimização da cópia. Há necessidade de alocação de heap como uma solução alternativa. Considere o seguinte pseudocódigo:

```cpp
#include <set>
#include <vector>
#include <string>
using namespace std;

//...
set<widget> LoadHugeData() {
    set<widget> ret;
    // ... load data from disk and populate ret
    return ret;
}
//...
widgets = LoadHugeData();   // efficient, no deep copy

vector<string> v = IfIHadAMillionStrings();
v.insert( begin(v)+v.size()/2, "scott" );   // efficient, no deep copy-shuffle
v.insert( begin(v)+v.size()/2, "Andrei" );  // (just 1M ptr/len assignments)
//...
HugeMatrix operator+(const HugeMatrix& , const HugeMatrix& );
HugeMatrix operator+(const HugeMatrix& ,       HugeMatrix&&);
HugeMatrix operator+(      HugeMatrix&&, const HugeMatrix& );
HugeMatrix operator+(      HugeMatrix&&,       HugeMatrix&&);
//...
hm5 = hm1+hm2+hm3+hm4+hm5;   // efficient, no extra copies
```

### <a name="enabling-move-for-appropriate-value-types"></a>Habilitando a movimentação para tipos de valor apropriados

Para uma classe de valor em que a movimentação pode ser mais barata do que uma cópia em profundidade, habilite a construção de movimentação e a atribuição de movimento para obter eficiência. Considere o seguinte pseudocódigo:

```cpp
#include <memory>
#include <stdexcept>
using namespace std;
// ...
class my_class {
    unique_ptr<BigHugeData> data;
public:
    my_class( my_class&& other )   // move construction
        : data( move( other.data ) ) { }
    my_class& operator=( my_class&& other )   // move assignment
    { data = move( other.data ); return *this; }
    // ...
    void method() {   // check (if appropriate)
        if( !data )
            throw std::runtime_error("RUNTIME ERROR: Insufficient resources!");
    }
};
```

Se você habilitar a construção/atribuição de cópia, habilite também a construção/atribuição de movimentação se ela puder ser mais barata do que uma cópia profunda.

Alguns tipos *que não são de valor* são somente para movimentação, como quando você não pode clonar um recurso, somente transferir a propriedade. Exemplo: `unique_ptr`.

## <a name="see-also"></a>Consulte também

[C++sistema de tipos](../cpp/cpp-type-system-modern-cpp.md)<br/>
[Bem-vindo de volta paraC++](../cpp/welcome-back-to-cpp-modern-cpp.md)<br/>
[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
