---
title: 'Como: Design para segurança de exceção | Microsoft Docs'
ms.custom: how-to
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 19ecc5d4-297d-4c4e-b4f3-4fccab890b3d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1a9eaee55c806ea2efc82300cad47cc744c0a491
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39403687"
---
# <a name="how-to-design-for-exception-safety"></a>Como projetar tendo em vista a segurança da exceção
Uma das vantagens do mecanismo de exceção é que a execução, junto com dados sobre a exceção, catch de saltos diretamente da instrução que gerou a exceção para a primeira instrução que lida com isso. O manipulador pode ser qualquer número de níveis para cima na pilha de chamadas. Funções que são chamadas entre a instrução try e a instrução throw não precisarão saber nada sobre a exceção que é lançada.  No entanto, eles precisarão ser projetado para que eles podem ir fora do escopo "inesperadamente" em qualquer ponto em que uma exceção pode propagar-se de abaixo e então, sem deixar atrás de objetos criados parcialmente, vazados memória ou estruturas de dados que estão em estados inutilizável.  
  
## <a name="basic-techniques"></a>Técnicas básicas  
 Uma política de tratamento de exceções robusta requer uma consideração cuidadosa e deve ser parte do processo de design. Em geral, a maioria das exceções são detectadas e lançada em camadas inferiores de um módulo de software, mas normalmente essas camadas não tem contexto suficiente para tratar o erro ou expor uma mensagem aos usuários finais. Nas camadas intermediárias, funções podem capturar e relançar uma exceção quando eles têm que inspecionar o objeto de exceção ou ter informações adicionais úteis para fornecer para a camada superior que, por fim, captura a exceção. Uma função deve capturar e "assimilar" uma exceção apenas se ele é capaz de se recuperar completamente dela. Em muitos casos, o comportamento correto nas camadas intermediárias é permitir que uma exceção se propagar até a pilha de chamadas. Até mesmo na camada mais alta, pode ser apropriado permitir que uma exceção sem tratamento encerrar um programa se a exceção deixa o programa em um estado em que a sua correção não pode ser garantida.  
  
 Não importa como uma função lida com uma exceção, para ajudar a garantir que ele seja "à prova de exceções," deve ser projetado de acordo com as seguintes regras básicas.  
  
### <a name="keep-resource-classes-simple"></a>Simplificar a Classes de recursos  
 Ao encapsular o gerenciamento de recurso manual em classes, use uma classe que faz mais nada a gerenciar cada recurso; Caso contrário, você poderá introduzir vazamentos. Use [ponteiros inteligentes](../cpp/smart-pointers-modern-cpp.md) quando possível, conforme mostrado no exemplo a seguir. Este exemplo é intencionalmente simplificado para destacar as diferenças e artificial quando `shared_ptr` é usado.  
  
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
  
### <a name="use-the-raii-idiom-to-manage-resources"></a>Use a linguagem RAII para gerenciar recursos  
 Para ser à prova de exceções, uma função deve garantir que os objetos que ela foi alocada usando `malloc` ou **nova** são destruídos, e todos os recursos, como identificadores de arquivo são fechados ou liberados, mesmo se uma exceção é lançada. O *recurso de aquisição é inicialização* idiom (RAII) vincula o gerenciamento de tais recursos para o tempo de vida de variáveis automáticas. Quando uma função sai do escopo, retornando normalmente ou devido a uma exceção, os destruidores de todas as variáveis automáticas construído totalmente são invocados. Um objeto de wrapper RAII, como chamadas de um ponteiro inteligente excluir apropriado ou função em seu destruidor close. No código de exceção segura, é extremamente importante passar a propriedade de cada recurso imediatamente para algum tipo de objeto RAII. Observe que o `vector`, `string`, `make_shared`, `fstream`, e classes semelhantes lidar com a aquisição do recurso para você.  No entanto, `unique_ptr` tradicional `shared_ptr` construções são especiais porque a aquisição de recurso é executada pelo usuário em vez do objeto; portanto, eles contam como *recurso de versão é destruição* , mas são questionável como RAII.  
  
## <a name="the-three-exception-guarantees"></a>As três garantias de exceção  
 Normalmente, a segurança de exceção é discutida em termos de três garantias de exceção que pode fornecer a uma função: a *falhas não garantia*, o *garantia forte*e o *garantia básica* .  
  
### <a name="no-fail-guarantee"></a>Garantia de não falha  
 A garantia de não falha (ou "no-throw") é a garantia mais forte que uma função pode fornecer. Indica que a função não lançar uma exceção ou permitir que um propagar. No entanto, não poderá fornecer tal uma garantia de forma confiável, a menos que (a) você souber que todas as funções que chama essa função também são não falham, ou (b) você sabe que quaisquer exceções que são geradas são capturadas antes que elas atinjam a essa função, ou (c) você sabe como capturar e tratar corretamente a todas as exceções que podem alcançar essa função.  
  
 A garantia de alta segurança e a garantia básica se baseiam na suposição de que os destruidores são não falham. Todos os contêineres e os tipos na biblioteca padrão garantem que os destruidores não geram. Também há um requisito inverso: A biblioteca padrão exige que definidas pelo usuário tipos que recebem a ele — por exemplo, como argumentos de modelo — deve ter os destruidores de não lançamento.  
  
### <a name="strong-guarantee"></a>Garantia de alta segurança  
 A garantia de alta segurança declara que se uma função sai do escopo devido a uma exceção, ele será não causar perda de memória e o programa de estado não será modificado. Uma função que fornece uma forte garantia é essencialmente uma transação que tem a semântica de confirmação ou reversão: completamente obtenha êxito ou não tem nenhum efeito.  
  
### <a name="basic-guarantee"></a>Garantia básica  
 A garantia básica é a mais fraca de três. No entanto, ele pode ser a melhor escolha quando uma forte garantia é muito cara no consumo de memória ou de desempenho. Básica garantir estados que se ocorrer uma exceção, nenhuma memória é perdida e o objeto ainda está em um estado utilizável, mesmo que os dados podem ter sido modificados.  
  
## <a name="exception-safe-classes"></a>Classes de exceção segura  
 Uma classe pode ajudar a garantir sua própria segurança de exceção, mesmo quando ele é consumido por funções que não é seguras, evitando em si seja parcialmente construído ou parcialmente destruído. Se um construtor de classe é encerrada antes da conclusão, em seguida, o objeto nunca é criado e seu destruidor nunca será chamado. Embora as variáveis automáticas são inicializadas antes da exceção terá os destruidores invocado, a memória alocada dinamicamente ou recursos que não são gerenciados por um ponteiro inteligente ou semelhante variável automática será perdido.  
  
 Tipos internos são todos não falhas e os tipos de biblioteca padrão oferecem suporte a garantia básica no mínimo. Siga estas diretrizes para qualquer tipo definido pelo usuário que deve ser à prova de exceções:  
  
-   Use ponteiros inteligentes ou outros wrappers de tipo de RAII para gerenciar todos os recursos. Evite a funcionalidade de gerenciamento de recursos em seu destruidor de classe, porque o destruidor não será chamado se o construtor gerará uma exceção. No entanto, se a classe é um Gerenciador de recursos dedicados que controla a apenas um recurso, é aceitável para usar o destruidor para gerenciar recursos.  
  
-   Entenda que uma exceção gerada em um construtor de classe base não pode ser assimilada em um construtor de classe derivada. Se você deseja converter e relançar a exceção de classe base em um construtor derivado, use um bloco try de função.   
  
-   Considere a possibilidade de armazenar todos os estados de classe em um membro de dados que é encapsulado em um ponteiro inteligente, especialmente se uma classe tem um conceito de "inicialização que pode falhar." Embora o C++ permite que os membros de dados não inicializado, ele não oferece suporte a instâncias de classe parcialmente inicializado ou não inicializado. Um construtor deve ser bem-sucedida ou falhar; Nenhum objeto será criado se o construtor não é executado até a conclusão.  
  
-   Não permitir que qualquer exceção de escape de um destruidor. Uma axioma básica do C++ é que os destruidores nunca devem permitir que uma exceção propagar a pilha de chamadas. Se um destruidor deve executar uma operação potencialmente lançando a exceção, ele deve então em um bloco try catch e assimilar a exceção. A biblioteca padrão fornece essa garantia sobre todos os destruidores, que ela define.  
  
## <a name="see-also"></a>Consulte também  
 [Erros e tratamento de exceções](../cpp/errors-and-exception-handling-modern-cpp.md)   
 [Como realizar a interface entre códigos excepcionais e não excepcionais](../cpp/how-to-interface-between-exceptional-and-non-exceptional-code.md)