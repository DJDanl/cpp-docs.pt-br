---
title: "Como projetar tendo em vista a seguran&#231;a da exce&#231;&#227;o | Microsoft Docs"
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
ms.assetid: 19ecc5d4-297d-4c4e-b4f3-4fccab890b3d
caps.latest.revision: 20
caps.handback.revision: 20
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como projetar tendo em vista a seguran&#231;a da exce&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma das vantagens do mecanismo de exceção é que a execução, junto com dados sobre a exceção, ele diretamente da instrução que gerou a exceção da primeira instrução de captura que os identificadores ele.  O manipulador pode ser qualquer número de níveis acima da pilha de chamadas.  As funções que são chamadas entre a instrução try e a instrução do lançamento não são necessárias para saber nada sobre a exceção que é lançada.  No entanto, precisam ser criados de forma que eles possam sair do escopo “inesperado” em qualquer momento em que uma exceção pode propagar acima de baixo, e faz isso sem sair atrás de objetos parcialmente criados, de memória escape, ou as estruturas de dados que estão em estados inutilizáveis.  
  
## Técnicas básicas  
 Uma política robusta manipulação de exceções gerais requer o cuidado e deve fazer parte do processo de design.  Em geral, a maioria de exceções são detectadas e lançadas nas camadas inferior de um módulo de software, mas geralmente essas camadas não têm suficiente contexto para tratar o erro ou para expor uma mensagem aos usuários finais.  Nas camadas médias, as funções podem capturar e lançar novamente uma exceção quando precisam inspecionar o objeto de exceção, apresentam informações adicionais úteis a prever a camada superior que captura finalmente a exceção.  Uma função deve capturar e “” engulir uma exceção apenas se pode recuperar a ela.  Em muitos casos, o comportamento correto nas camadas médias deixar é uma extensão de exceção acima da pilha de chamadas.  Mesmo na camada a mais alta, pode ser apropriada deixar uma exceção sem\-tratamento encerrar um programa se a exceção permite que o programa em um estado no qual sua exatidão não pode ser garantida.  
  
 Não importa como uma função tratará uma exceção, para ajudar a garantir que é seguro exceções gerais “,” deve ser criado de acordo com as seguintes regras básicas.  
  
### Manter classes de recursos simples  
 Quando você encapsula o gerenciamento de recursos manual em classes, use uma classe que não faça nada mais gerenciar cada recurso; caso contrário, você poderá apresentar vazamentos.  Use [ponteiros inteligente](../cpp/smart-pointers-modern-cpp.md) quando possível, conforme mostrado no exemplo a seguir.  Este exemplo é intencionalmente artificial e simplista realce as diferenças quando `shared_ptr` é usado.  
  
```cpp  
// old-style new/delete version  
class NDResourceClass {  
private:  
    int*   m_p;  
    float* m_q;  
public:  
    NDResourceClass() : m_p(0), m_q(0) {  
        m_p = new int;  
        m_q = new float;  
    }  
  
    ~NDResourceClass() {  
        delete m_p;  
        delete m_q;  
    }  
    // Potential leak! When a constructor emits an exception,   
    // the destructor will not be invoked.     
};  
  
// shared_ptr version  
#include <memory>  
  
using namespace std;  
  
class SPResourceClass {  
private:  
    shared_ptr<int> m_p;  
    shared_ptr<float> m_q;  
public:  
    SPResourceClass() : m_p(new int), m_q(new float) { }  
    // Implicitly defined dtor is OK for these members,   
    // shared_ptr will clean up and avoid leaks regardless.  
};  
  
// A more powerful case for shared_ptr  
  
class Shape {  
    // ...  
};  
  
class Circle : public Shape {  
    // ...  
};  
  
class Triangle : public Shape {  
    // ...  
};  
  
class SPShapeResourceClass {  
private:  
    shared_ptr<Shape> m_p;  
    shared_ptr<Shape> m_q;  
public:  
    SPShapeResourceClass() : m_p(new Circle), m_q(new Triangle) { }  
};  
  
```  
  
### Use o idioma de RAII para gerenciar recursos  
 Para exceções gerais ser segura, uma função deve garantir que os objetos que alocou usando `malloc` ou `new` serem destruídos, e todos os recursos como os identificadores de arquivo são fechados ou liberados até mesmo se uma exceção é gerada.  O idioma *aquisição de recursos é inicialização* \(RAII\) amarra o gerenciamento desses recursos ao tempo de variáveis automático.  Quando uma função sair do escopo, retornando normalmente ou devido a uma exceção, os destruidores para todas as variáveis automático completa construídos serão invocados.  Um objeto de wrapper de RAII como um ponteiro inteligente chama a função apropriada de exclusão ou fim em seu destruidor.  Exceções gerais em código seguro, é importante criticamente passar imediatamente a propriedade de cada recurso a qualquer tipo de objeto de RAII.  Observe que `vector`, `string`, `make_shared`, `fstream`, e as classes semelhantes tratam a aquisição de recursos para você.  No entanto, `unique_ptr` e as construções tradicionais de `shared_ptr` são especiais como a aquisição de recursos é executada pelo usuário em vez do objeto; consequentemente, contam como *a versão do recurso é destruição* mas são duvidosos como RAII.  
  
## As três garantias de exceção  
 Normalmente, a segurança de exceção é discutida em termos das três garantias de exceção que uma função pode oferecer: *a garantia de não falhar*, *a garantia forte*, e *a garantia básica*.  
  
### Garantia de não falha  
 A garantia de não falha \(ou “, não geram”\) a garantia é a mais segura que uma função pode fornecer.  Indica que a função não gerará uma exceção ou não permitirá que se propague.  Porém, você não pode fornecer essa garantia da menos que \(a\) você souberem que todas as funções que esse as chamadas de função também são sem falha, ou \(b\) souber que todas as exceções que são geradas são capturadas antes que alcancem essa função, ou \(c\) souber capturar e manipular todas as exceções corretamente que podem acessar esta função.  
  
 A garantia forte e a garantia básica confiam na suposição que os destruidores são sem falha.  Todos os contêineres e na garantia de biblioteca padrão do que os destruidores não lançam.  Também há um requisito para trás: A biblioteca padrão exige que os tipos definidos pelo usuário que são dados \- para o exemplo, porque o modelo argumento\- deve ter destruidores de reprodução.  
  
### Garantia forte  
 A garantia forte que indica se uma função sai do escopo por causa de uma exceção, não escapará a memória e o estado de programa não será alterado.  Uma função que fornece uma garantia forte é essencialmente uma transação com a confirmação ou a semântica da reversão: ou tem êxito por ou não tem nenhum efeito.  
  
### Garantia básica  
 A garantia básica é a mais fraco dos três.  No entanto, pode ser a melhor opção quando uma garantia forte é muito dispendiosa o consumo de memória ou no desempenho.  A garantia básica que indica se uma exceção ocorrer, nenhuma memória é escape e o objeto ainda está em um estado utilizável mesmo que os dados possam ter sido alterado.  
  
## Classes seguras exceções gerais  
 Uma classe pode ajudar a garantir sua própria segurança de exceção, mesmo quando é consumida por funções não seguro, se impedindo que é criado parcialmente ou parcialmente destruir.  Se um construtor de classe é encerrado antes da conclusão, o objeto será criado e nunca seu destruidor nunca será chamado.  Embora as variáveis automático que são inicializados antes de exceção têm seus destruidores a memória ou os recursos de chamadas, dinamicamente atribuída que não são gerenciados por um ponteiro inteligente ou por uma variável automático semelhante serão ignorados.  
  
 Os tipos internos são sem qualquer falha, e os tipos de biblioteca padrão oferecem suporte a garantia básica no mínimo.  Siga estas diretrizes para qualquer tipo definido pelo usuário que deve ser: seguro exceções gerais  
  
-   Use ponteiros inteligente ou outros wrappers de RAII\- tipo para gerenciar todos os recursos.  Evite a funcionalidade de gerenciamento de recursos no destruidor da classe, como o destruidor não será invocado se o construtor gerencie uma exceção.  No entanto, se a classe for um gerenciador de recursos dedicado que controla apenas um recurso, é aceitável usar o destruidor para gerenciar recursos.  
  
-   Entenda que uma exceção lançada em um construtor de classe base não pode ser engulida em um construtor de classe derivada.  Se você deseja traduzir e a reabilitação geram a exceção da classe base em um construtor derivada, use um bloco try da função.  Para obter mais informações, consulte [\(NOTINBUILD\)How to: Handle Exceptions in Base Class Constructors \(C\+\+\)](http://msdn.microsoft.com/pt-br/53bb822e-785b-4581-9517-210dd05060a3).  
  
-   Considere armazenar especialmente se nenhum estado da classe em um membro de dados que é encapsulado em um ponteiro inteligente, se a classe tiver um conceito de “inicialização que é permitida a falhar.” Embora C\+\+ permite membros de dados não inicializada, o não oferece suporte a instâncias de classe não inicializado ou parcialmente inicializadas.  Um construtor deve ter êxito ou falhar; nenhum objeto é criado se o construtor não executa até a conclusão.  
  
-   Não permita que nenhuma exceções escapem de um destruidor.  Um axioma básico C\+\+ é que os destruidores nunca devem permitir que uma exceção propague acima da pilha de chamadas.  Se um destruidor deve executar uma operação potencial de reprodução, deverá fazê\-lo em um bloco try catch e engulir a exceção.  A biblioteca padrão fornece essa garantia em todos os destruidores que define o.  
  
## Consulte também  
 [Erros e tratamento de exceções](../cpp/errors-and-exception-handling-modern-cpp.md)   
 [Como realizar a interface entre códigos excepcional e não excepcional](../cpp/how-to-interface-between-exceptional-and-non-exceptional-code.md)