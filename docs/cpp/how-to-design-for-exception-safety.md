---
title: Como criar para segurança de exceção
ms.custom: how-to
ms.date: 11/19/2019
ms.topic: conceptual
ms.assetid: 19ecc5d4-297d-4c4e-b4f3-4fccab890b3d
ms.openlocfilehash: 732a46166c99396c5d55a7d2acd834b58f3d2b2e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87187797"
---
# <a name="how-to-design-for-exception-safety"></a>Como criar para segurança de exceção

Uma das vantagens do mecanismo de exceção é que a execução, junto com os dados sobre a exceção, salta diretamente da instrução que gera a exceção para a primeira instrução catch que a manipula. O manipulador pode ser qualquer número de níveis na pilha de chamadas. Funções que são chamadas entre a instrução try e a instrução Throw não são necessárias para saber nada sobre a exceção que é lançada.  No entanto, eles precisam ser projetados para que possam sair do escopo "inesperadamente" em qualquer ponto em que uma exceção possa se propagar abaixo e fazer isso sem deixar por trás de objetos criados parcialmente, memória vazada ou estruturas de dados que estejam em Estados inutilizáveis.

## <a name="basic-techniques"></a>Técnicas básicas

Uma política de tratamento de exceção robusta requer uma consideração cuidadosa e deve fazer parte do processo de design. Em geral, a maioria das exceções são detectadas e geradas nas camadas inferiores de um módulo de software, mas normalmente essas camadas não têm contexto suficiente para lidar com o erro ou expor uma mensagem aos usuários finais. Nas camadas intermediárias, as funções podem capturar e relançar uma exceção quando precisam inspecionar o objeto de exceção ou têm informações úteis adicionais para fornecer a camada superior que, por fim, captura a exceção. Uma função deve capturar e "assimilar" uma exceção somente se for capaz de se recuperar por completo dela. Em muitos casos, o comportamento correto nas camadas intermediárias é permitir que uma exceção propague a pilha de chamadas. Mesmo na camada mais alta, pode ser apropriado permitir que uma exceção sem tratamento encerre um programa se a exceção deixar o programa em um estado no qual sua exatidão não possa ser garantida.

Não importa como uma função manipula uma exceção, para ajudar a garantir que ela seja "segura de exceção", ela deve ser projetada de acordo com as regras básicas a seguir.

### <a name="keep-resource-classes-simple"></a>Manter classes de recursos simples

Quando você encapsula o gerenciamento manual de recursos em classes, use uma classe que não faz nada, exceto gerenciar um único recurso. Ao manter a classe simples, você reduz o risco de introduzir vazamentos de recursos. Use [ponteiros inteligentes](smart-pointers-modern-cpp.md) quando possível, conforme mostrado no exemplo a seguir. Este exemplo é intencionalmente artificial e simplista para destacar as diferenças quando `shared_ptr` é usado.

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

Para ser seguro de exceção, uma função deve garantir que os objetos alocados usando `malloc` ou **`new`** sejam destruídos, e todos os recursos, como os identificadores de arquivo, sejam fechados ou liberados, mesmo que uma exceção seja lançada. O idioma de RAII ( *aquisição de recursos é inicialização* ) une o gerenciamento desses recursos ao ciclo de vida de variáveis automáticas. Quando uma função sai do escopo, retornando normalmente ou devido a uma exceção, os destruidores para todas as variáveis automáticas totalmente construídas são invocados. Um objeto wrapper RAII, como um ponteiro inteligente, chama a função Delete ou Close apropriada em seu destruidor. No código de exceção segura, é extremamente importante passar a propriedade de cada recurso imediatamente para algum tipo de objeto RAII. Observe que as `vector` `string` classes,, `make_shared` , `fstream` e semelhantes manipulam a aquisição do recurso para você.  No entanto, `unique_ptr` e as `shared_ptr` construções tradicionais são especiais porque a aquisição de recursos é executada pelo usuário em vez do objeto; portanto, elas contam como *liberação de recursos é a destruição* , mas é questionável como RAII.

## <a name="the-three-exception-guarantees"></a>As três garantias de exceção

Normalmente, a segurança de exceção é discutida em termos das três garantias que uma função pode fornecer: a *garantia sem falha*, a *garantia forte*e a *garantia básica*.

### <a name="no-fail-guarantee"></a>Garantia sem falha

A garantia sem falha (ou, "no-throw") é a garantia mais forte que uma função pode fornecer. Ele informa que a função não lançará uma exceção ou permitirá que uma seja propagada. No entanto, você não pode fornecer de forma confiável tal garantia, a menos que (a) você saiba que todas as funções que essa função chama também não têm falha, ou (b) você sabe que todas as exceções que são geradas são detectadas antes que elas cheguem a essa função, ou (c) você sabe como capturar e lidar corretamente com todas as exceções que possam alcançar essa

Tanto a garantia forte quanto a garantia básica dependem da suposição de que os destruidores não são-falham. Todos os contêineres e tipos na biblioteca padrão garantem que seus destruidores não lançam. Também há um requisito de inverso: a biblioteca padrão requer que os tipos definidos pelo usuário que são fornecidos a ele — por exemplo, como argumentos de modelo — devem ter destruidores sem lançamento.

### <a name="strong-guarantee"></a>Alta garantia

A alta garantia indica que, se uma função sair do escopo devido a uma exceção, ela não vazará memória e o estado do programa não será modificado. Uma função que fornece uma forte garantia é, essencialmente, uma transação com semântica de confirmação ou reversão: ela é completamente sucedido ou não tem efeito.

### <a name="basic-guarantee"></a>Garantia básica

A garantia básica é a mais fraca dos três. No entanto, pode ser a melhor opção quando uma alta garantia é muito cara no consumo de memória ou no desempenho. A garantia básica indica que, se ocorrer uma exceção, nenhuma memória será vazada e o objeto ainda estará em um estado utilizável, mesmo que os dados possam ter sido modificados.

## <a name="exception-safe-classes"></a>Classes de exceção segura

Uma classe pode ajudar a garantir sua própria segurança de exceção, mesmo quando ela é consumida por funções inseguras, impedindo que ela seja parcialmente construída ou parcialmente destruída. Se um construtor de classe sair antes da conclusão, o objeto nunca será criado e seu destruidor nunca será chamado. Embora as variáveis automáticas que são inicializadas antes da exceção tenham seus destruidores invocados, a memória alocada dinamicamente ou os recursos que não são gerenciados por um ponteiro inteligente ou variável automática semelhante serão vazados.

Os tipos internos são todos sem falha e os tipos de biblioteca padrão oferecem suporte à garantia básica no mínimo. Siga estas diretrizes para qualquer tipo definido pelo usuário que deve ser seguro para exceções:

- Use apontadores inteligentes ou outros wrappers de tipo RAII para gerenciar todos os recursos. Evite a funcionalidade de gerenciamento de recursos em seu destruidor de classe, pois o destruidor não será invocado se o Construtor lançar uma exceção. No entanto, se a classe for um Gerenciador de recursos dedicado que controla apenas um recurso, é aceitável usar o destruidor para gerenciar recursos.

- Entenda que uma exceção gerada em um construtor de classe base não pode ser assimilada em um construtor de classe derivada. Se você quiser converter e relançar a exceção de classe base em um Construtor derivado, use um bloco try de função.

- Considere a possibilidade de armazenar todo o estado da classe em um membro de dados que esteja encapsulado em um ponteiro inteligente, especialmente se uma classe tiver um conceito de "inicialização com permissão para falhar". Embora o C++ permita membros de dados não inicializados, ele não oferece suporte a instâncias de classe não inicializadas ou parcialmente iniciadas. Um construtor deve ser bem-sucedida ou falhar; nenhum objeto será criado se o construtor não for executado até a conclusão.

- Não permita que nenhuma exceção escape de um destruidor. Um axioma básico do C++ é que os destruidores nunca devem permitir que uma exceção propague a pilha de chamadas. Se um destruidor precisar executar uma operação de lançamento de exceção potencialmente, ele deverá fazer isso em um bloco try catch e assimilar a exceção. A biblioteca padrão fornece essa garantia em todos os destruidores que ele define.

## <a name="see-also"></a>Confira também

[Práticas recomendadas do C++ moderno para exceções e tratamento de erros](errors-and-exception-handling-modern-cpp.md)<br/>
[Como: interface entre códigos excepcionais e não excepcionais](how-to-interface-between-exceptional-and-non-exceptional-code.md)
