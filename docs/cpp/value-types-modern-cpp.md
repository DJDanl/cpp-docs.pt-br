---
title: Tipos de valor (C++ moderno)
ms.date: 05/07/2019
ms.topic: conceptual
ms.assetid: f63bb62c-60da-40d5-ac14-4366608fe260
ms.openlocfilehash: 204ea9f86377eb8a5796f01cb81a9161163d9649
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65221889"
---
# <a name="value-types-modern-c"></a>Tipos de valor (C++ moderno)

Classes C++ são tipos de valor padrão. Este tópico fornece uma visão geral introdutória dos tipos de valor e problemas relacionados ao seu uso.

## <a name="value-vs-reference-types"></a>Valor vs. tipos de referência

Conforme mencionado anteriormente, as classes C++ são tipos de valor padrão. Elas podem ser especificadas como tipos de referência, que permitem que o comportamento polimórfico dar suporte à programação orientada a objeto. Tipos de valor são exibidos, às vezes, da perspectiva do controle de layout e de memória, enquanto os tipos de referência são sobre classes base e funções virtuais para fins de polimórficos. Por padrão, os tipos de valor são podem ser copiados, que significa que sempre há um construtor de cópia e um operador de atribuição de cópia. Para tipos de referência, você faz a classe não podem ser copiados (desabilitar o construtor de cópia e o operador de atribuição de cópia) e usar um destruidor virtual, que dá suporte a seu polimorfismo pretendido. Tipos de valor também são sobre o conteúdo que, quando eles são copiados, sempre lhe dois valores independentes que podem ser modificados separadamente. Tipos de referência estão relacionados à identidade - que tipo de objeto é isso? Por esse motivo, "tipos de referência" também são chamados de "tipos polimórficos".

Se você realmente quiser um tipo de referência semelhante (classe base, funções virtuais), você precisa desabilitar explicitamente a cópia, conforme mostrado no `MyRefType` classe no código a seguir.

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

Compilar o código acima resultará no seguinte erro:

```Output
test.cpp(15) : error C2248: 'MyRefType::operator =' : cannot access private member declared in class 'MyRefType'
        meow.cpp(5) : see declaration of 'MyRefType::operator ='
        meow.cpp(3) : see declaration of 'MyRefType'
```

## <a name="value-types-and-move-efficiency"></a>Tipos de valor e mova a eficiência

Sobrecarga de alocação de cópia é evitada devido a novas otimizações de cópia. Por exemplo, quando você insere uma cadeia de caracteres no meio de um vetor de cadeias de caracteres, haverá sem sobrecarga de realocação de cópia, apenas uma mudança - mesmo que ele resulta em um aumento do vetor em si. Isso também se aplica a outras operações, por exemplo, executando uma operação de adição em dois objetos muito grandes. Como você pode habilitar essas otimizações de operação do valor? Alguns compiladores de C++, o compilador habilitará isso para você implicitamente, assim como os construtores de cópia podem ser automaticamente gerados pelo compilador. No entanto, em C++, sua classe precisará "opt-in" para mover a atribuição e construtores, declarando-o em sua definição de classe. Isso é feito por meio de duplo e comercial (& &) referência de rvalue no membro apropriado declarações de função e definição de construtor de movimentação e mover os métodos de atribuição.  Você também precisará inserir o código correto para "roubar as entranhas" fora do objeto de origem.

Como você decide se você precisa mover habilitado? Se você já sabe que você precisa copiar construção habilitada, você provavelmente desejará mover habilitado se ele pode ser mais barato do que uma cópia em profundidade. No entanto, se você souber que você precisa mover o suporte, ele não significa necessariamente que cópia habilitado. Neste último caso seria chamado "somente de movimentação typ". Um exemplo já está na biblioteca padrão é `unique_ptr`. Como uma observação, o antigo `auto_ptr` foi preterido e foi substituído pelo `unique_ptr` exatamente, devido à falta de suporte de semântica de movimentação na versão anterior do C++.

Usando a semântica de movimentação, você pode por-valor de retorno ou inserção no meio. Movimentação é uma otimização da cópia. Não há necessidade de alocação de heap como uma solução alternativa. Considere o seguinte pseudocódigo:

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

### <a name="enabling-move-for-appropriate-value-types"></a>Habilitando a mudança para os tipos de valor apropriado

Para uma classe de valor semelhante em que a movimentação pode ser mais barata do que uma cópia em profundidade, permitem a construção de movimentação e mover a atribuição para maior eficiência. Considere o seguinte pseudocódigo:

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

Se você habilitar a construção de cópia/atribuição, também habilite construção/atribuição de movimentação se ele pode ser mais barato do que uma cópia em profundidade.

Alguns *sem valor* tipos são somente de movimentação, como quando você não pode clonar um recurso, apenas transferir a propriedade. Exemplo: `unique_ptr`.

## <a name="section"></a>Seção

Conteúdo

## <a name="see-also"></a>Consulte também

[Sistema do tipo C++ (C++ moderno)](../cpp/cpp-type-system-modern-cpp.md)<br/>
[Bem-vindo ao C++ (C++ moderno)](../cpp/welcome-back-to-cpp-modern-cpp.md)<br/>
[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)
