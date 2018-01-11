---
title: "Contêineres da biblioteca padrão C++ | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- C++ Standard Library, template class containers
- containers, C++ Standard Library
ms.assetid: 8e915ca1-19ba-4f0d-93c8-e2c3bfd638eb
caps.latest.revision: "29"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 23979709bcc43074d6db2f042fdde850f6894e73
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="c-standard-library-containers"></a>Contêineres da biblioteca padrão C++
A biblioteca padrão fornece vários contêineres fortemente tipados para armazenar coleções de objetos relacionados. Os contêineres são modelos de classe; Quando você declara uma variável de contêiner, você pode especificar o tipo dos elementos que esse contêiner armazenará. Contêineres podem ser criados com listas de inicializadores. Elas têm funções membro para adição e remoção de elementos e execução de outras operações.  
  
 Você itera pelos os elementos em um contêiner e acessa os elementos individuais usando [iteradores](../standard-library/iterators.md). Você pode usar iteradores explicitamente por meio de suas funções membro e operadores, bem como funções globais. Você também pode usá-los implicitamente, por exemplo, usando um loop range-for. Iteradores para todos os contêineres de biblioteca padrão C++ têm uma interface comum, mas cada contêiner define seus próprios iteradores especializados.  
  
 Contêineres podem ser divididos em três categorias: contêineres de sequência, contêineres associativos e adaptadores de contêiner.  
  
##  <a name="sequence_containers"></a> Contêineres de sequência  
 Contêineres de sequência mantêm a ordem dos elementos inseridos que você especifica.  
  
 Um `vector` contêiner se comporta como uma matriz, mas pode aumentar automaticamente conforme necessário. Ele tem acesso aleatório e comprimento altamente flexível, além de ser armazenado contiguamente. Por essas razões e outras, `vector` é o contêiner de sequência preferencial para a maioria dos aplicativos. Em caso de dúvida sobre qual tipo de contêiner de sequência usar, comece usando um vector! Para obter mais informações, consulte a [Classe vector](../standard-library/vector-class.md).  
  
 Um contêiner `array` tem algumas das vantagens do `vector`, mas o comprimento não é tão flexível. Para obter mais informações, consulte a [Classe array](../standard-library/array-class-stl.md).  
  
 Um contêiner `deque` (fila de duas extremidades) permite rápidas inserções e exclusões no início e no final do contêiner. Ele compartilha as vantagens de acesso aleatório e comprimento flexível de `vector`, mas não é contíguo. Para obter mais informações, consulte [Classe deque](../standard-library/deque-class.md).  
  
 Um contêiner `list` é uma lista duplamente vinculada que permite acesso bidirecional, rápidas inserções e exclusões rápidas em qualquer lugar no contêiner, mas você não pode acessar aleatoriamente um elemento no contêiner. Para obter mais informações, consulte a [Classe list](../standard-library/list-class.md).  
  
 Um contêiner `forward_list` é uma lista vinculada por vinculação simples – uma versão de acesso avançado de `list`. Para obter mais informações, consulte a [Classe forward_list](../standard-library/forward-list-class.md).  
  
## <a name="associative-containers"></a>Contêineres associativos  
 Em contêineres associativos, os elementos são inseridos em uma ordem predefinida – por exemplo, classificados em ordem crescente. Contêineres associativos desordenados também estão disponíveis. Os contêineres associativos podem ser agrupados em dois subconjuntos: maps e sets.  
  
 Um `map`, às vezes chamado de dicionário, consiste em um par chave/valor. A chave é usada para ordenar a sequência e o valor é associado essa chave. Por exemplo, um `map` pode conter chaves que representam cada palavra exclusiva em um texto e valores correspondentes que representam o número de vezes que cada palavra aparece no texto. A versão não ordenada de `map` é `unordered_map`. Para obter mais informações, consulte a [Classe map](../standard-library/map-class.md) e a [classe unordered_map](../standard-library/unordered-map-class.md).  
  
 Um `set` é apenas um contêiner em ordem crescente de elementos exclusivos – o valor também é a chave. A versão não ordenada de `set` é `unordered_set`. Para obter mais informações, consulte [Classe set](../standard-library/set-class.md) e [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Ambos `map` e `set` permitem apenas uma instância de uma chave ou um elemento a ser inserido no contêiner. Se várias instâncias de elementos são necessárias, use `multimap` ou `multiset`. As versões não ordenadas são `unordered_multimap` e `unordered_multiset`. Para obter mais informações, consulte a [Classe multimap](../standard-library/multimap-class.md), a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md), a [Classe multiset](../standard-library/multiset-class.md) e a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).  
  
 Sets e maps ordenados dão suporte a iteradores bidirecionais, enquanto suas contrapartes não ordenadas dão suporte a iteradores avançados. Para obter mais informações, consulte [Iteradores](../standard-library/iterators.md).  
  
### <a name="heterogeneous-lookup-in-associative-containers-c14"></a>Pesquisa heterogênea em contêineres associativos (C++14)  
 Os contêineres associativos ordenados (map, multimap, set e multiset) agora dão suporte a pesquisa heterogênea, que significa que não será mais necessário passar o exatamente o mesmo tipo de objeto como a chave ou elemento em funções membro como `find()` e `lower_bound()`. Em vez disso, você pode passar qualquer tipo para o qual é definido um `operator<` sobrecarregado que permite a comparação com o tipo de chave.  
  
 A pesquisa heterogênea é habilitada com base em aceitação quando você especifica o comparador "diamond functor" `std::less<>` ou `std::greater<>` ao declarar a variável de contêiner, conforme mostrado aqui:  
  
```  
std::set<BigObject, std::less<>> myNewSet;  
```  
  
 Se você usar o comparador padrão, o contêiner se comportará exatamente como fazia no C++11 e versões anteriores.  
  
 O exemplo a seguir mostra como sobrecarregar `operator<` para permitir que os usuários de um `std::set` façam pesquisas simplesmente passando uma pequena cadeia de caracteres que pode ser comparada ao membro `BigObject::id` de cada objeto.  
  
```cpp  
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
  
 As funções membro a seguir em map, multimap, set e multiset foram sobrecarregadas para dar suporte à pesquisa heterogênea:  
  
1.  find  
  
2.  count  
  
3.  lower_bound  
  
4.  upper_bound  
  
5.  equal_range  
  
## <a name="container-adapters"></a>Adaptadores de contêiner  
 Um adaptador de contêiner é uma variação de uma sequência ou um contêiner associativo que restringe a interface para simplicidade e maior clareza. Adaptadores de contêiner não dão suporte a iteradores.  
  
 Um contêiner `queue` segue a semântica de PEPS (primeiro a entrar, primeiro a sair). O primeiro elemento *enviado por push* – ou seja, inserido na fila – é o primeiro a ser *removido como o mais recente da pilha* – ou seja, removido da fila. Para obter mais informações, consulte a [Classe queue](../standard-library/queue-class.md).  
  
 Um contêiner `priority_queue` é organizado de modo que o elemento que tem o valor mais alto é sempre o primeiro na fila. Para obter mais informações, consulte a [Classe priority_queue](../standard-library/priority-queue-class.md).  
  
 Um contêiner `stack` segue a semântica de UEPS (último a entrar, primeiro a sair). O último elemento enviado por push para a pilha é o primeiro elemento a ser removido da pilha como o mais recente. Para obter mais informações, consulte a [Classe stack](../standard-library/stack-class.md).  
  
 Já que adaptadores de contêiner não dão suporte a iteradores, eles não podem ser usados com os algoritmos da biblioteca padrão C++. Para obter mais informações, consulte [Algoritmos](../standard-library/algorithms.md).  
  
## <a name="requirements-for-container-elements"></a>Requisitos dos elementos de contêiner  
 Em geral, os elementos inseridos em um contêiner de biblioteca padrão C++ podem ser de qualquer tipo de objeto se eles podem ser copiados. Elementos somente móveis – por exemplo, aqueles como `vector<unique_ptr<T>>` que são criados usando `unique_ptr<>` funcionarão, desde que você não chame funções membro que tentem copiá-los.  
  
 O destruidor não tem permissão para gerar uma exceção.  
  
 Contêineres associativos ordenados – descritos anteriormente neste artigo — devem ter um operador de comparação público definido. (Por padrão, o operador é `operator<`, mas mesmo tipos que não funcionam com `operator<` têm suporte.  
  
 Algumas operações em contêineres também podem exigir um construtor padrão público e um operador de equivalência público. Por exemplo, os contêineres associativos desordenados requerem suporte para igualdade e hash.  
  
## <a name="accessing-container-elements"></a>Acessando elementos de contêiner  
 Os elementos de contêineres são acessados por meio de iteradores. Para obter mais informações, consulte [Iteradores](../standard-library/iterators.md).  
  
> [!NOTE]
>  Você também pode usar [loops for baseados em intervalo](../cpp/range-based-for-statement-cpp.md) para iterar por coleções de biblioteca padrão C++.  
  
## <a name="comparing-containers"></a>Comparando contêineres  
 Todos os contêineres sobrecarregam o operator== para comparar dois contêineres do mesmo tipo que têm o mesmo tipo de elemento. Você pode usar == para comparar um vector\<string> a outro vector\<string>, mas você não pode usá-lo para comparar um vector\<string> a um list\<string> ou um vector\<string> a um vector\<char*>.  No C++98/03, você pode usar [std::equal](algorithm-functions.md#equal) ou [std::mismatch](algorithm-functions.md#mismatch) para comparar tipos de contêineres e/ou tipos de elemento diferentes. No C++11, você também pode usar [std::is_permutation](algorithm-functions.md#is_permutation). Mas em todos esses casos, as funções assumem que os contêineres têm o mesmo comprimento. Se o segundo intervalo é menor do que o primeiro, temos como resultado um comportamento indefinido. Se o segundo intervalo for maior, os resultados ainda poderão ser incorretos porque a comparação nunca continuará após o final do primeiro intervalo.  
  
### <a name="comparing-dissimilar-containers-c14"></a>Comparando tipos diferentes de contêineres (C++14)  
 No C++14 e posterior, você pode comparar tipos de contêineres e/ou de elementos diferentes, usando uma das sobrecargas de função **std::equal**, **std::mismatch** ou **std::is_permutation** que utilizam dois intervalos completos. Essas sobrecargas permitem que você compare contêineres com comprimentos diferentes. Essas sobrecargas são muito menos suscetíveis a erros de usuário e são otimizadas para retornar false em tempo constante quando contêineres de comprimentos diferentes são comparados. Portanto, recomendamos que você use essas sobrecargas, a menos que (1) você tenha um motivo muito claro para não fazê-lo ou (2) você esteja usando um contêiner [std::list](../standard-library/list-class.md), que não se beneficia de otimizações de intervalo duplo.  
  
## <a name="see-also"></a>Consulte também  
 [Contêineres](../cpp/containers-modern-cpp.md)   
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)   
 [\<sample container>](../standard-library/sample-container.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

