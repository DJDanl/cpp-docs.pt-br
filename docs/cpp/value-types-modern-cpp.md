---
title: Valor de tipos (C++ moderno) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: f63bb62c-60da-40d5-ac14-4366608fe260
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e7e49c97bca86b8d2debde2f5b132f7dde16998e
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="value-types-modern-c"></a>Tipos de valor (C++ moderno)
Classes C++ são tipos de valor padrão. Este tópico fornece uma visão geral introdutória de tipos de valor e problemas relacionados ao seu uso.  
  
## <a name="value-vs-reference-types"></a>Valor vs. tipos de referência  
 Mencionado anteriormente, as classes C++ são tipos de valor padrão. Elas podem ser especificadas como tipos de referência, que permitem que o comportamento polimórfico dar suporte a programação orientada a objeto. Tipos de valor, às vezes, são exibidos sob a perspectiva do controle de layout e de memória, enquanto os tipos de referência são sobre classes base e funções virtuais para fins de polimórficas. Por padrão, os tipos de valor são copiados, que significa que sempre há um construtor de cópia e um operador de atribuição de cópia. Para tipos de referência, que a classe não pode ser copiado (desativar o construtor de cópia e o operador de atribuição de cópia) e usar um destruidor virtual, que dá suporte a seu polimorfismo pretendido. Tipos de valor também são sobre o conteúdo, que, quando eles são copiados, sempre lhe dois valores independentes que podem ser modificados separadamente. Tipos de referência são sobre identidade - que tipo de objeto é isso? Por esse motivo, "tipos de referência" também são conhecidas como "tipos polimórficos".  
  
 Se você realmente quiser um tipo de referência de tipo (classe base, funções virtuais), você precisa desabilitar explicitamente copiando, conforme o `MyRefType` classe no código a seguir.  
  
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
  
 Compilando o código acima resultará no seguinte erro:  
  
```Output  
test.cpp(15) : error C2248: 'MyRefType::operator =' : cannot access private member declared in class 'MyRefType'  
        meow.cpp(5) : see declaration of 'MyRefType::operator ='  
        meow.cpp(3) : see declaration of 'MyRefType'  
  
```  
  
## <a name="value-types-and-move-efficiency"></a>Os tipos de valor e mover a eficiência  
 Sobrecarga de alocação de cópia é evitada devido a otimizações de cópia nova. Por exemplo, quando você insere uma cadeia de caracteres no meio de um vetor de cadeias de caracteres, haverá sem sobrecarga de realocação de cópia, somente um move - mesmo que resulta em uma expansão do vetor em si. Isso também se aplica a outras operações, por exemplo, executar uma operação de adicionar em dois objetos muito grande. Como você habilitar essas otimizações de operação valor? Alguns compiladores C++, o compilador habilitará isso para você implicitamente, assim como construtores de cópia podem ser geradas automaticamente pelo compilador. No entanto, no Visual C++, sua classe será necessário para "aceitar" para mover a atribuição e construtores por declará-la em sua definição de classe. Isso é feito usando o e comercial duplo (& &) referência de rvalue no membro apropriado declarações e construtor de movimento de definição de função e mover os métodos de atribuição.  Você também precisa inserir o código correto para "roubar mostrarmos os detalhes" fora do objeto de origem.  
  
 Como decidir se você precisa mover habilitado? Se você já sabe que você precisa copiar construção habilitada, provavelmente desejará mover habilitado se ele pode ser mais barato do que uma cópia profunda. No entanto, se você souber que você precisa mover suporte, ele não significa necessariamente que cópia habilitado. Este último caso deve ser chamado um "somente mover tipo". Um exemplo já está na biblioteca padrão é `unique_ptr`. Como uma anotação, o antigo `auto_ptr` foi preterido e foi substituído pelo `unique_ptr` precisamente devido à falta de suporte de semântica de movimentação na versão anterior do C++.  
  
 Usando semântica de animação, você pode retornar por valor ou inserir no meio. Movimentação é uma otimização da cópia. Não há necessidade de alocação de heap como uma solução alternativa. Considere o seguinte pseudocódigo:  
  
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
  
### <a name="enabling-move-for-appropriate-value-types"></a>Habilitando o move para tipos de valor apropriado  
 Para uma classe de tipo de valor onde move pode ser mais barato do que uma cópia em profundidade, permitem a construção de mover e mova atribuição para maior eficiência. Considere o seguinte pseudocódigo:  
  
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
  
 Se você habilitar construção/atribuição de cópia, também permitem mover construção/atribuição se ele pode ser mais barato do que uma cópia profunda.  
  
 Alguns *sem valor* tipos são somente para mover, como quando você não pode clonar um recurso, apenas transferir a propriedade. Exemplo: `unique_ptr`.  
  
## <a name="section"></a>Seção  
 Conteúdo  
  
## <a name="see-also"></a>Consulte também  
 [Sistema de tipo C++](../cpp/cpp-type-system-modern-cpp.md)   
 [Bem-vindo novamente para C++](../cpp/welcome-back-to-cpp-modern-cpp.md)   
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)