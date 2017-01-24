---
title: "Vida &#250;til do objeto e gerenciamento de recursos (C++ moderno) | Microsoft Docs"
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
ms.assetid: 8aa0e1a1-e04d-46b1-acca-1d548490700f
caps.latest.revision: 18
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Vida &#250;til do objeto e gerenciamento de recursos (C++ moderno)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Ao contrário das linguagens gerenciadas, C\+\+ não tem a coleta de lixo \(GC\), que automaticamente libera recursos de memória nenhum\-longo\- usados como um programa é executado.  Em C\+\+, o gerenciamento de recursos está relacionado diretamente ao tempo de vida do objeto.  Este documento descreve os fatores que afetam o tempo de vida do objeto em C\+\+ e como gerenciar o.  
  
 C\+\+ não tiver o GC em primeiro lugar porque não lida com recursos de memória não.  Somente os destruidores determinísticas como aqueles em C\+\+ podem controlar recursos de memória e de memória não ambos.  GC O também tem outros problemas, como uma sobrecarga maior na memória e o consumo da CPU, e localidade.  Mas a universalidade é um problema fundamental que não pode ser mitigadas com otimizações inteligentes.  
  
## Conceitos  
 Uma é importante no gerenciamento de objetos de tempo de vida é a capsulagem\- os quais quer que que usa um objeto não precisa saber quais recursos que possui objeto, ou como descartar eles, ou mesmo se possuir recursos de todos eles.  Apenas tem que ser destruído o objeto.  O idioma do C\+\+ é criado para garantir que os objetos a serem destruídos no tempo corretos, ou seja, como os blocos são saídos, na ordem inversa de compilação.  Quando um objeto é destruído, suas bases e membros serão destruídos em uma ordem específica.  O idioma destrói automaticamente objetos, a menos que você faça coisas especiais como alocação ou o posicionamento do novo heap.  Por exemplo, [ponteiros inteligente](../cpp/smart-pointers-modern-cpp.md) como `unique_ptr` e de `shared_ptr`, e contêineres padrão de \(STL\) da biblioteca do modelo como `vector`, encapsula `new`\/`delete` e `new[]`\/`delete[]` nos objetos, que têm destruidores.  É por isso é tão importante usar ponteiros inteligente e contêineres STL.  
  
 Outro conceito importante no gerenciamento do tempo de vida: destruidores.  Os destruidores encapsulam a versão do recurso.  \(A mnemônico de uso geral é RRID, recurso que a versão é destruição.\)  Um recurso é algo que você obtiver de “sistema” e tem que fornecer posterior novamente.  A memória é o recurso o mais comum, mas também há arquivos, um soquetes, uma texturas, e outros recursos de memória não. “” Possuir um recurso significa que você pode usar a quando precisar mas você também tem que a liberar quando você estiver concluído com ela.  Quando um objeto é destruído, seu destruidor libera os recursos que possui.  
  
 O conceito final é o DAG \(gráfico acíclico direcionado\).  A estrutura da propriedade em um programa forma um DAG.  Nenhum objeto pode possuir próprio\- que não só impossível mas também inerentemente sem sentido.  Mas dois objetos podem compartilhar a propriedade de um terceiro objeto.  Vários tipos de links são possíveis em um DAG como este: A é um membro de B \(B possui A\), o armazena C `vector<D>` \(C possui cada elemento de D\), repositórios de E `shared_ptr<F>` \(E compartilha a propriedade de F\- 2.0, possivelmente com outros objetos\), e assim por diante.  Como não há nenhum ciclo e cada link no DAG é representado por um objeto que tem um destruidor \(em vez de um ponteiro bruto, de identificador, ou outro mecanismo\), os possíveis vazamentos de recursos são impossíveis como o idioma os evita.  Os recursos são liberados imediatamente depois que não são mais necessários, sem uma execução do coletor de lixo.  O controle de tempo de vida é sobrecarga\- livre para o escopo da pilha, as bases, os membros, e argumentos relacionados, e para baixo `shared_ptr`.  
  
### Tempo de vida Heap\-baseado  
 Durante o tempo de vida do objeto do heap, use [ponteiros inteligente](../cpp/smart-pointers-modern-cpp.md).  Use `shared_ptr` e `make_shared` como o ponteiro e o alocador padrão.  Use `weak_ptr` para interromper ciclos, faça o cachê, e observe objetos sem afetar ou presume que nada sobre seu tempo de vida.  
  
```cpp  
void func() {  
  
auto p = make_shared<widget>(); // no leak, and exception safe  
...  
p->draw();   
  
} // no delete required, out-of-scope triggers smart pointer destructor  
  
```  
  
 Use `unique_ptr` exclusivo para a propriedade, por exemplo, no idioma *de pimpl* . \(Consulte [Pimpl para encapsulamento do tempo de compilação](../cpp/pimpl-for-compile-time-encapsulation-modern-cpp.md).\) Faça a `unique_ptr` o destino primário de todas as expressões explícitas de `new` .  
  
```cpp  
unique_ptr<widget> p(new widget());  
```  
  
 Você pode usar ponteiros brutos para não propriedade e a inspeção.  Um ponteiro não proprietário pode oscilar, mas não é possível substituir.  
  
```cpp  
class node {  
  ...  
  vector<unique_ptr<node>> children; // node owns children  
  node* parent; // node observes parent, which is not a concern  
  ...  
};  
node::node() : parent(...) { children.emplace_back(new node(...) ); }  
  
```  
  
 Quando a otimização de desempenho são necessárias, você poderá ter que usar ponteiros proprietários *bem encapsulados* chamadas e explícitos para excluir.  Um exemplo é quando você implementa sua própria estrutura de dados de nível baixo.  
  
### Tempo de vida permissão com base em fila com base  
 Em C\+\+ moderno, *escopo com base em pilha* é um modo avançado de escrever código robusto pois combina *tempo de vida de pilhas* automático e *tempo de vida do membro de dados* com o controle de alto eficiência\- tempo de vida é essencialmente livre de sobrecarga.  O tempo de vida do objeto do heap exige o gerenciamento manual diligente e pode ser a origem de possíveis vazamentos e de incapacidades de recursos, especialmente quando você estiver trabalhando com ponteiros brutos.  Considere este código, que demonstra o escopo permissão com base em fila com base:  
  
```cpp  
class widget {  
private:  
  gadget g;   // lifetime automatically tied to enclosing object  
public:  
  void draw();  
};  
  
void functionUsingWidget () {  
  widget w;   // lifetime automatically tied to enclosing scope  
              // constructs w, including the w.g gadget member  
  …  
  w.draw();  
  …  
} // automatic destruction and deallocation for w and w.g  
  // automatic exception safety,   
  // as if "finally { w.dispose(); w.g.dispose(); }"  
  
```  
  
 Use o tempo de vida estático com moderação estático \(global, estático local da função\) porque podem ocorrer problemas.  O que acontece quando o construtor de um objeto global gerará uma exceção?  Normalmente, o aplicativo falhas de uma maneira que pode ser difícil de depuração.  A ordem de compilação é problemático para objetos estáticos de tempo de vida, e não é simultaneidade\- seguro.  É não apenas a construção do objeto um problema, ordem de destruição pode ser complexa, especialmente onde polimorfismo estiver envolvido.  Se seu objeto ou variável não é polimórfica e não têm a construir\/destruição complexas que regras, há ainda a introdução de simultaneidade seguro para threads.  Um aplicativo multi\-threaded não pode alterar os dados com segurança em objetos estáticos sem ter o armazenamento de thread local, os bloqueios de recursos, e outras precauções especiais.  
  
## Consulte também  
 [Bem\-vindo ao C\+\+](../Topic/Welcome%20Back%20to%20C++%20\(Modern%20C++\).md)   
 [Referência de linguagem C\+\+](../cpp/cpp-language-reference.md)   
 [Biblioteca Padrão C\+\+](../standard-library/cpp-standard-library-reference.md)