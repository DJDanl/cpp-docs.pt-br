---
title: "Tipos de valor (C++ moderno) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: f63bb62c-60da-40d5-ac14-4366608fe260
caps.latest.revision: 15
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tipos de valor (C++ moderno)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As classes C\+\+ por padrão são tipos de valor.  Este tópico fornece uma visão geral dos tipos de valores iniciais e problemas em relação ao seu uso.  
  
## Valor em tipos de referência  
 Como mencionado anteriormente, as classes C\+\+ por padrão são tipos de valor.  Podem ser especificados como os tipos de referência, que habilitam o comportamento polimórfica para dar suporte à programação orientada a objeto.  Os tipos de valor são exibidos às vezes a perspectiva de controle de memória e layout, enquanto os tipos de referência são sobre classes base e funções virtuais para fins polimorfos.  Por padrão, os tipos de valor são copyable, o que significa que há sempre um construtor de cópia e um operador de atribuição de cópia.  Para tipos de referência, você faz a classe non\-copyable \(desabilitar o construtor de cópia e o operador de atribuição de impressão\) e usa um destruidor virtual, que da suporte a seu polimorfismo pretendido.  Os tipos de valor são também sobre o conteúdo, que, quando são copiados, darão sempre dois valores independentes que podem ser modificados separadamente.  Os tipos de referência são sobre a identidade – o tipo de objeto é ele?  Por esse motivo, “os tipos referência” também conhecidas como “tipos polimorfos”.  
  
 Se você realmente quiser a referência\- como o tipo \(classe base, funções virtuais\), precisará desabilitar explicitamente a cópia, conforme mostrado na classe de `MyRefType` no código a seguir.  
  
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
  
 Compile o código acima resultará no seguinte erro:  
  
  **test.cpp \(15\): erro C2248: MyRefType::operator “\=”: não pode acessar o membro particular declarado no MyRefType das classes”**  
 **meow.cpp \(5\): consulte a declaração de MyRefType::operator “\=”**  
 **meow.cpp \(3\): consulte a declaração de “MyRefType”**   
## Tipos de valor e eficiência de movimentação  
 A sobrecarga de alocação de impressão é evitada devido às novas otimizações de cópia.  Por exemplo, quando você insere uma cadeia de caracteres no meio de um vetor de cadeias de caracteres, não haverá sobrecarga de redistribuição de cópia, somente uma movimentação mesmo se resultar em um crescimento de vetor próprio.  Isto também se aplica a outras operações, por exemplo executando uma operação de adição em dois objetos muito grandes.  Como habilitar essas otimizações da operação de valores?  Em alguns compiladores de C\+\+, o compilador habilitará esse implicitamente para você, bem como bloqueadores de cópia pode ser gerado automaticamente pelo compilador.  No entanto, no Visual C\+\+, sua classe precisará optar por “em” de mover a atribuição os construtores e declarando em sua definição da classe.  Isso é feito usando a referência de dois rvalue de E comercial \(&&\) em declarações de função de membro apropriadas e definindo métodos do construtor de movimentação e a alocação de movimentação.  Você também precisa inserir o código correto “rouba a entranhas” fora do objeto de origem.  
  
 Como você decidir se você precisar da movimentação habilitado?  Se você já souber você precisa da construção habilitada, você provavelmente de cópia deseja que o movimento habilitado se pode ser mais baixo de uma cópia em profundidade.  No entanto, se você souber você precisa de suporte a movimentação de dados, não necessariamente significa que a cópia habilitada.  Esses último casos serão chamados de “mover um tipo somente”.  Um exemplo na biblioteca padrão é `unique_ptr`.  Como uma nota lateral, `auto_ptr` antigo será substituído, e foi substituído por `unique_ptr` com precisão devido à falta de suporte da semântica de movimentação na versão anterior do C\+\+.  
  
 Usando a semântica de movimentação você pode retorno\-por\- valor ou INSERT\-em\- médio.  A mudança é uma otimização de cópia.  Houver necessidade da alocação de heap como uma solução alternativa.  Considere o seguinte pseudocódigo:  
  
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
  
### Habilitando a movimentação para tipos de valores apropriados  
 Da \- como a classe em que o movimento pode ser mais baixo de uma cópia em profundidade, para habilitar a construção de movimentação e a atribuição de movimentação para a eficiência.  Considere o seguinte pseudocódigo:  
  
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
  
 Se você habilitar a criação\/atribuição de impressão, habilitar a criação\/atribuição de movimentação se pode ser menor custo de uma cópia em profundidade.  
  
 Alguns tipos *de valor não* são movimentação somente leitura, como quando não é possível clonar um recurso, somente propriedade de transferência.  Exemplo: `unique_ptr`.  
  
## Seção  
 Conteúdo  
  
## Consulte também  
 [Sistema do tipo C\+\+](../Topic/C++%20Type%20System%20\(Modern%20C++\).md)   
 [Bem\-vindo ao C\+\+](../Topic/Welcome%20Back%20to%20C++%20\(Modern%20C++\).md)   
 [Referência de linguagem C\+\+](../cpp/cpp-language-reference.md)   
 [Biblioteca Padrão C\+\+](../standard-library/cpp-standard-library-reference.md)