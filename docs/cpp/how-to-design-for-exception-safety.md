---
title: "Como: Design de exceção de segurança | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 19ecc5d4-297d-4c4e-b4f3-4fccab890b3d
caps.latest.revision: "20"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 7d15df2f810848bb9349bc98c722ac02ff8cda17
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-design-for-exception-safety"></a>Como projetar tendo em vista a segurança da exceção
Uma das vantagens do mecanismo de exceção é que a execução, junto com dados sobre a exceção, catch de saltos diretamente da instrução que gera a exceção para a primeira instrução que o manipule. O manipulador pode ser qualquer número de níveis para cima na pilha de chamadas. Funções que são chamadas entre a instrução try e a instrução throw deve não sabe nada sobre a exceção que é lançada.  No entanto, eles precisam ser criados de forma que eles podem ir fora do escopo "inesperadamente" em qualquer ponto onde podem se propagar até abaixo de uma exceção e portanto sem deixando objetos criados parcialmente, vazamento memória ou estruturas de dados que esteja em estado inutilizável.  
  
## <a name="basic-techniques"></a>Técnicas básicas  
 Uma política de tratamento de exceções robusta requer cuidadosamente e deve ser parte do processo de design. Em geral, a maioria das exceções são detectadas e lançada em camadas inferiores de um módulo de software, mas essas camadas não possuem contexto suficiente para manipular o erro ou expor uma mensagem aos usuários finais. Nas camadas intermediários, funções podem capturar e relançar uma exceção quando eles têm que inspecionar o objeto de exceção ou tiverem informações úteis adicionais para fornecer para a camada superior que, por fim, captura a exceção. Uma função deve capturar e "assimilar" exceção somente se ele é capaz de recuperar completamente dele. Em muitos casos, o comportamento correto nas camadas intermediários é permitir que uma exceção se propagar até a pilha de chamadas. Ainda na camada mais alta, pode ser apropriado permitir que uma exceção sem tratamento encerrar um programa se a exceção deixar o programa em um estado no qual a sua correção não pode ser garantida.  
  
 Não importa como uma função trata uma exceção, para ajudar a garantir que ele for "exceção seguro" devem ser criado de acordo com as seguintes regras básicas.  
  
### <a name="keep-resource-classes-simple"></a>Simplificar a Classes de recursos  
 Ao encapsular o gerenciamento manual de recursos em classes, usar uma classe que não faz nada mais para gerenciar cada recurso. Caso contrário, você pode introduzir vazamentos. Use [ponteiros inteligentes](../cpp/smart-pointers-modern-cpp.md) quando possível, conforme mostrado no exemplo a seguir. Este exemplo é intencionalmente simplificado para destacar as diferenças e artificial quando `shared_ptr` é usado.  
  
```cpp  
// old-style new/delete version  
class NDResourceClass {  
private:  
    int*   m_p;  
    float* m_q;  
public:  
    NDResourceClass() : m_p(0), m_q(0) {  
        m_p = new int;  
        m_q = new float;  
    }  
  
    ~NDResourceClass() {  
        delete m_p;  
        delete m_q;  
    }  
    // Potential leak! When a constructor emits an exception,   
    // the destructor will not be invoked.     
};  
  
// shared_ptr version  
#include <memory>  
  
using namespace std;  
  
class SPResourceClass {  
private:  
    shared_ptr<int> m_p;  
    shared_ptr<float> m_q;  
public:  
    SPResourceClass() : m_p(new int), m_q(new float) { }  
    // Implicitly defined dtor is OK for these members,   
    // shared_ptr will clean up and avoid leaks regardless.  
};  
  
// A more powerful case for shared_ptr  
  
class Shape {  
    // ...  
};  
  
class Circle : public Shape {  
    // ...  
};  
  
class Triangle : public Shape {  
    // ...  
};  
  
class SPShapeResourceClass {  
private:  
    shared_ptr<Shape> m_p;  
    shared_ptr<Shape> m_q;  
public:  
    SPShapeResourceClass() : m_p(new Circle), m_q(new Triangle) { }  
};  
  
```  
  
### <a name="use-the-raii-idiom-to-manage-resources"></a>Usar o idioma RAII para gerenciar recursos  
 Para ser seguro de exceção, uma função deve garantir que os objetos que ela foi alocada usando `malloc` ou `new` são destruídas, e todos os recursos como identificadores de arquivos serão fechados ou liberados, mesmo se uma exceção será lançada. O *recurso aquisição é inicialização* idioma (RAII) vincula o gerenciamento de tais recursos para o tempo de vida de variáveis automáticas. Quando uma função sai do escopo, retornando normalmente ou devido a uma exceção, são chamados destruidores para todas as variáveis automáticas totalmente construído. Um objeto de wrapper RAII como um ponteiro inteligente chama apropriado excluir ou função em seu destruidor close. No código de exceção segura, é fundamental passar a propriedade de cada recurso imediatamente para algum tipo de objeto RAII. Observe que o `vector`, `string`, `make_shared`, `fstream`, e classes semelhantes lidar com a aquisição do recurso para você.  No entanto, `unique_ptr` tradicional e `shared_ptr` construções são especiais, pois a aquisição de recursos é executada pelo usuário em vez do objeto; portanto, eles são contados como *recurso versão é destruição* mas questionável como RAII.  
  
## <a name="the-three-exception-guarantees"></a>As três garantias de exceção  
 Normalmente, a segurança de exceção é discutida em termos de garantias de três exceção pode fornecer uma função: o *garantia de não falha*, o *forte garantia*e o *garantia básica* .  
  
### <a name="no-fail-guarantee"></a>Garantia de não falha  
 A garantia de não falha (ou "não-throw") é a garantia mais forte que pode fornecer uma função. Ele informa que a função não lançar uma exceção ou permitir que um a propagação. No entanto, não poderá fornecer uma garantia confiável, a menos que o (a) você sabe que todas as funções que chama essa função também não falhar, ou (b) você sabe que as exceções que são geradas são capturadas antes que elas atinjam esta função ou (c) você sabe como capturar e tratar corretamente todas as exceções que podem alcançar essa função.  
  
 A garantia de alta segurança e a garantia básica contam com a suposição de que os destrutores são não falha. Todos os contêineres e tipos na biblioteca padrão garantem que seus destruidores não emitem. Também há um requisito inverso: A biblioteca padrão requer que definidos pelo usuário tipos que recebem a ele — por exemplo, como argumentos de modelo — deve ter destruidores não lançamento.  
  
### <a name="strong-guarantee"></a>Garantia de alta segurança  
 A garantia de alta segurança estados que se uma função sai do escopo devido a uma exceção, ele será não apresentam vazamento de memória e o programa de estado não será modificado. Uma função que fornece uma garantia de alta segurança é essencialmente uma transação que tem semânticas de confirmação ou reversão: completamente obtenha êxito ou não tem nenhum efeito.  
  
### <a name="basic-guarantee"></a>Garantia básica  
 A garantia básica é a mais fraco dos três. No entanto, ele pode ser a melhor opção quando uma forte garantia é muito cara no consumo de memória ou de desempenho. Básica garantem estados que se ocorrer uma exceção, nenhuma memória é perda e o objeto ainda está em um estado utilizável, embora os dados podem ter sido modificados.  
  
## <a name="exception-safe-classes"></a>Classes de exceção-Safe  
 Uma classe pode ajudar a garantir a segurança de sua própria exceção, mesmo quando ele é consumido por funções não seguras, evitando próprio parcialmente construído ou parcialmente destruído. Se um construtor de classe for encerrado antes da conclusão, em seguida, o objeto nunca é criado e seu destruidor nunca será chamado. Embora as variáveis automáticas são inicializadas antes da exceção terá seus destruidores chamado, a memória alocada dinamicamente ou recursos que não são gerenciados por um ponteiro inteligente ou semelhante variável automática será perdida.  
  
 Os tipos internos são não todas as falhas e os tipos de biblioteca padrão oferecem suporte a garantia básica no mínimo. Siga estas diretrizes para qualquer tipo definido pelo usuário que deve ser segura de exceção:  
  
-   Use ponteiros inteligentes ou outros wrappers RAII-type para gerenciar todos os recursos. Evite a funcionalidade de gerenciamento de recursos no seu destruidor de classe, porque o destruidor não será chamado se o construtor lançará uma exceção. No entanto, se a classe for um Gerenciador de recursos dedicados que controla um recurso, é aceitável para usar o destruidor para gerenciar recursos.  
  
-   Entenda que uma exceção lançada em um construtor de classe base não pode ser ignorada em um construtor de classe derivada. Se você deseja converter e relançar a exceção de classe base em um construtor derivado, use um bloco try de função.   
  
-   Considere a possibilidade de armazenar todos os estados de classe em um membro de dados que é encapsulado em um ponteiro inteligente, especialmente se uma classe tem um conceito de "inicialização que pode falhar." Embora o C++ permite que os membros de dados não inicializados, ele não oferece suporte a instâncias de classe não inicializado ou parcialmente inicializada. Um construtor deve ser bem-sucedida ou falhar; Nenhum objeto será criado se o construtor não é executado até a conclusão.  
  
-   Não permita exceções para um destruidor de escape. Uma axioma básico do C++ é que destruidores nunca devem permitir que uma exceção propagar a pilha de chamadas. Se um destruidor deve executar uma operação potencialmente geradoras de exceções, ela deve então em um bloco try catch e assimilar a exceção. A biblioteca padrão fornece essa garantia em todos os destruidores define.  
  
## <a name="see-also"></a>Consulte também  
 [Erros e tratamento de exceção](../cpp/errors-and-exception-handling-modern-cpp.md)   
 [Como realizar a interface entre códigos excepcionais e não excepcionais](../cpp/how-to-interface-between-exceptional-and-non-exceptional-code.md)