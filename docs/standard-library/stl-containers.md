---
title: "Cont&#234;ineres da STL | Microsoft Docs"
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
helpviewer_keywords: 
  - "Biblioteca C++ padrão, contêineres de classe de modelo"
  - "contêineres STL"
ms.assetid: 8e915ca1-19ba-4f0d-93c8-e2c3bfd638eb
caps.latest.revision: 29
caps.handback.revision: 29
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Cont&#234;ineres da STL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A biblioteca padrão fornece vários contêineres de tipo seguro para armazenar coleções de objetos relacionados. Os contêineres são modelos de classe; Quando você declara uma variável de contêiner, você pode especificar o tipo dos elementos que conterá o contêiner. Contêineres podem ser construídos com listas de inicializadores. Eles têm funções de membro para adição e remoção de elementos e executar outras operações.  
  
 Iterar sobre os elementos em um contêiner e acessar os elementos individuais usando [iteradores](../Topic/Iterators.md). Você pode usar iteradores explicitamente por meio de suas funções de membro e operadores, bem como funções globais. Você também pode usá-los implicitamente, por exemplo, usando um intervalo de-loop for. Iteradores para todos os contêineres STL têm uma interface comum, mas cada contêiner define suas próprias iteradores especializados.  
  
 Contêineres podem ser divididos em três categorias: contêineres, contêineres associativos e adaptadores de contêiner de sequência.  
  
##  <a name="a-namesequencecontainersa-sequence-containers"></a><a name="sequence_containers"></a> Contêineres de sequência  
 Contêineres de sequência mantém a ordem dos elementos inseridos que você especificar.  
  
 Um `vector` contêiner se comporta como uma matriz, mas pode aumentar automaticamente conforme necessário. É o acesso aleatório e armazenados contiguamente e comprimento é altamente flexível. Por essas razões e mais, `vector` é o contêiner de sequência preferencial para a maioria dos aplicativos. Em caso de dúvida sobre qual tipo de contêiner de sequência para usar, comece usando um vetor! Para obter mais informações, consulte [classe vector](../standard-library/vector-class.md).  
  
 Um `array` contêiner tem algumas das vantagens do `vector`, mas o comprimento não é tão flexível. Para obter mais informações, consulte [classe array](../standard-library/array-class-stl.md).  
  
 Um `deque` contêiner (fila duas extremidades) permite rápidas inserções e exclusões no início e no final do contêiner. Ele compartilha as vantagens de acesso aleatório e comprimento flexível `vector`, mas não é contíguo. Para obter mais informações, consulte [classe deque](../standard-library/deque-class.md).  
  
 Um `list` contêiner é uma lista duplamente vinculada que permite acesso bidirecional, rápidas inserções e exclusões rápidas em qualquer lugar no contêiner, mas você não pode acessar aleatoriamente um elemento no contêiner. Para obter mais informações, consulte [classe list](../standard-library/list-class.md).  
  
 Um `forward_list` contêiner é uma lista encadeada — a versão do access avanço `list`. Para obter mais informações, consulte [classe forward_list](../standard-library/forward-list-class.md).  
  
## <a name="associative-containers"></a>Contêineres associativos  
 Em contêineres associativos, os elementos são inseridos em uma ordem predefinida — por exemplo, como classificada em ordem crescente. Os contêineres associativos desordenados também estão disponíveis. Os contêineres associativos podem ser agrupados em dois subconjuntos: mapas e conjuntos.  
  
 Um `map`, às vezes chamado como um dicionário, consiste em um par chave/valor. A chave é usada para ordenar a sequência e o valor é associado essa chave. Por exemplo, um `map` pode conter chaves que representam cada palavra exclusiva em um texto e valores correspondentes que representam o número de vezes que cada palavra aparece no texto. A versão não ordenada de `map` é `unordered_map`. Para obter mais informações, consulte [classe map](../Topic/map%20Class.md) e [classe unordered_map](../standard-library/unordered-map-class.md).  
  
 A `set` é apenas um contêiner em ordem crescente de elementos exclusivos — o valor também é a chave. A versão não ordenada de `set` é `unordered_set`. Para obter mais informações, consulte [classe set](../standard-library/set-class.md) e [classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Ambos `map` e `set` Permitir apenas uma instância de uma chave ou um elemento a ser inserido no contêiner. Se várias instâncias de elementos são necessárias, use `multimap` ou `multiset`. As versões não ordenadas são `unordered_multimap` e `unordered_multiset`. Para obter mais informações, consulte [classe multimap](../standard-library/multimap-class.md), [classe unordered_multimap](../standard-library/unordered-multimap-class.md), [classe multiset](../Topic/multiset%20Class.md), e [classe unordered_multiset](../standard-library/unordered-multiset-class.md).  
  
 Conjuntos e mapas ordenados suportam bidirecional iteradores, e suas contrapartes não ordenadas suportam iteradores forward. Para obter mais informações, consulte [iteradores](../Topic/Iterators.md).  
  
### <a name="heterogeneous-lookup-in-associative-containers-c14"></a>Pesquisa heterogênea em contêineres associativos (C + + 14)  
 O ordenados contêineres associativos (mapa, vários mapeamentos, conjunto e Multiconjunto) agora pesquisa heterogênea de suporte, que significa que não será mais necessário para passar o mesmo tipo de objeto exato como a chave ou elemento nas funções de membro como `find()` e `lower_bound()`. Em vez disso, você pode passar qualquer tipo para o qual um sobrecarregado `operator<` é definida que permite a comparação com o tipo de chave.  
  
 Pesquisa heterogênea é habilitada em uma base opt-in quando você especificar o `std::less<>` ou `std::greater<>` comparador "diamond functor" ao declarar a variável de contêiner, como mostrado aqui:  
  
```  
std::set<BigObject, std::less<>> myNewSet;  
```  
  
 Se você usar o comparador padrão, em seguida, o contêiner se comporta exatamente como fazia no C++ 11 e versões anteriores.  
  
 O exemplo a seguir mostra como a sobrecarga `operator<` para permitir que os usuários de um `std::set` para fazer pesquisas simplesmente passando uma pequena cadeia de caracteres que pode ser comparada a cada objeto `BigObject::id` membro.  
  
```  
#include <set>  
#include <string>  
#include <iostream>  
#include <functional>  
  
using namespace std;  
  
class BigObject  
{  
public:  
    string id;  
    explicit BigObject(const string& s) : id(s) {}  
    bool operator< (const BigObject& other) const  
    {  
        return this->id < other.id;  
    }  
  
    // Other members....  
};  
  
inline bool operator<(const string& otherId, const BigObject& obj)  
{  
    return otherId < obj.id;  
}  
  
inline bool operator<(const BigObject& obj, const string& otherId)  
{  
    return obj.id < otherId;  
}  
  
int main()  
{  
    // Use C++14 brace-init syntax to invoke BigObject(string).  
    // The s suffix invokes string ctor. It is a C++14 user-defined  
    // literal defined in <string>  
    BigObject b1{ "42F"s };   
    BigObject b2{ "52F"s };  
    BigObject b3{ "62F"s };  
    set<BigObject, less<>> myNewSet; // C++14  
    myNewSet.insert(b1);  
    myNewSet.insert(b2);  
    myNewSet.insert(b3);  
    auto it = myNewSet.find(string("62F"));  
    if (it != myNewSet.end())  
        cout << "myNewSet element = " << it->id << endl;   
    else  
        cout << "element not found " << endl;  
  
    // Keep console open in debug mode:  
    cout << endl << "Press Enter to exit.";  
    string s;  
    getline(cin, s);  
    return 0;  
}  
  
//Output: myNewSet element = 62F  
  
```  
  
 O membro a seguir funciona no mapa, multimap, set e multiset estar sobrecarregados para dar suporte à pesquisa heterogênea:  
  
1.  find  
  
2.  count  
  
3.  lower_bound  
  
4.  upper_bound  
  
5.  equal_range  
  
## <a name="container-adapters"></a>Adaptadores de contêiner  
 Um adaptador de contêiner é uma variação de uma sequência ou um contêiner associativo que restringe a interface para simplicidade e maior clareza. Adaptadores de contêiner não dão suporte a iteradores.  
  
 Um `queue` contêiner segue a semântica de PEPS (primeiro a entrar, primeiro a sair). O primeiro elemento *enviado*— ou seja, inserida na fila — é o primeiro a ser *aparecido*— ou seja, removido da fila. Para obter mais informações, consulte [classe queue](../standard-library/queue-class.md).  
  
 Um `priority_queue` contêiner é organizado de modo que o elemento que tem o valor mais alto é sempre o primeiro na fila. Para obter mais informações, consulte [classe priority_queue](../standard-library/priority-queue-class.md).  
  
 Um `stack` contêiner segue a semântica de LIFO (último a entrar, primeiro a sair). O último elemento empurrado na pilha é o primeiro elemento a ser exibido. Para obter mais informações, consulte [classe de pilha](../standard-library/stack-class.md).  
  
 Como adaptadores de contêiner não oferecem suporte a iteradores, não pode ser usados com os algoritmos da STL. Para obter mais informações, consulte [algoritmos](../standard-library/algorithms.md).  
  
## <a name="requirements-for-container-elements"></a>Requisitos para elementos de contêiner  
 Em geral, os elementos inseridos em um contêiner STL podem ser de qualquer tipo de objeto se eles podem ser copiados. Elementos somente móvel — por exemplo, aqueles como `vector<unique_ptr<T>>` que são criados usando `unique_ptr<>` funcionará desde que você não chamar membro funções que tentam copiá-los.  
  
 O destruidor não é permitido para lançar uma exceção.  
  
 Ordenado contêineres associativos — descrito anteriormente neste artigo — deve ter um operador de comparação público definido. (Por padrão, o operador é `operator<`, mas mesmo tipos que não funcionam com `operator<` têm suporte.  
  
 Algumas operações em contêineres também podem exigir um construtor padrão público e um operador de equivalência pública. Por exemplo, os contêineres associativos desordenados requerem suporte para hash e de igualdade.  
  
## <a name="accessing-container-elements"></a>Acessando elementos de contêiner  
 Os elementos de contêineres são acessados por meio de iteradores. Para obter mais informações, consulte [iteradores](../Topic/Iterators.md).  
  
> [!NOTE]
>  Você também pode usar [baseado em intervalo loops](../Topic/Range-based%20for%20Statement%20\(C++\).md) iterar em coleções STL.  
  
## <a name="comparing-containers"></a>Comparando contêineres  
 Todos os contêineres sobrecarregam o operador = = para comparar dois contêineres do mesmo tipo que tem o mesmo tipo de elemento. Você pode usar = = para comparar um vetor \< cadeia de caracteres> para outro vetor \< cadeia de caracteres>, mas você não pode usá-lo para comparar um vetor \< cadeia de caracteres> a uma lista \< cadeia de caracteres> ou um vetor \< cadeia de caracteres> a um vetor \< char * >.  No C++ 98/03, você pode usar [std::equal](../Topic/equal.md) ou [std::mismatch](../Topic/mismatch.md) para comparar tipos de contêineres diferentes e/ou tipos de elemento. No C++ 11 você também pode usar [std::is_permutation](../Topic/is_permutation.md). Mas em todos esses casos as funções assumem que os contêineres tiverem o mesmo comprimento. Se o segundo intervalo é menor do que os resultados de comportamento primeiro, depois indefinido. Se o segundo intervalo for maior, resultados ainda podem ser incorretos porque a comparação nunca continua após o final do primeiro intervalo.  
  
### <a name="comparing-dissimilar-containers-c14"></a>Comparando tipos diferentes contêineres (C + + 14)  
 No C++ 14 e posterior, você pode comparar diferentes contêineres e/ou tipos diferentes de elementos, usando uma da [std::equal](../Topic/equal.md), [std::mismatch](../Topic/mismatch.md), ou [std::is_permutation](../Topic/is_permutation.md) função sobrecargas que utilizam dois intervalos completos. Essas sobrecargas permitem que você compare contêineres com comprimentos diferentes. Essas sobrecargas são muito menos suscetíveis a erros de usuário e são otimizadas para retornar false em tempo constante quando contêineres de comprimentos diferentes são comparados. Portanto, recomendamos que você use essas sobrecargas, a menos que (1) que tenha um motivo muito claro não a ou (2) se estiver usando um [std:: List](../standard-library/list-class.md) contêiner, que não se beneficia das otimizações de intervalo duplo.  
  
## <a name="see-also"></a>Consulte também  
 [Contêineres](../Topic/Containers%20\(Modern%20C++\).md)   
 [Biblioteca de modelos padrão](../misc/standard-template-library.md)   
 [\< contêiner de exemplo>](../standard-library/sample-container.md)   
 [Segurança de threads na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

