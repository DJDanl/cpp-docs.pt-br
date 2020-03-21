---
title: Tempo de vida do objeto e gerenciamento de recursos (RAII)
description: Siga o princípio de RAII em moderno C++ para evitar vazamentos de recursos.
ms.date: 11/19/2019
ms.topic: conceptual
ms.assetid: 8aa0e1a1-e04d-46b1-acca-1d548490700f
ms.openlocfilehash: d30b5296b35bec7f8949057becfaeeea61ef09a0
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80078027"
---
# <a name="object-lifetime-and-resource-management-raii"></a>Tempo de vida do objeto e gerenciamento de recursos (RAII)

Diferentemente das linguagens gerenciadas, C++ o não tem coleta de *lixo*automática. Esse é um processo interno que libera a memória de heap e outros recursos à medida que um programa é executado. Um C++ programa é responsável por retornar todos os recursos adquiridos para o sistema operacional. Falha ao liberar um recurso não utilizado é chamado de *vazamento*. Os recursos vazados ficam indisponíveis para outros programas até que o processo seja encerrado. Vazamentos de memória em particular são uma causa comum de bugs na programação em estilo C.

O C++ moderno evita o uso da memória heap o máximo possível declarando objetos na pilha. Quando um recurso é muito grande para a pilha, ele deve *pertencer* a um objeto. À medida que o objeto é inicializado, ele adquire o recurso que ele possui. O objeto é então responsável por liberar o recurso em seu destruidor. O próprio objeto proprietário é declarado na pilha. O princípio que os *próprios recursos de objetos* também é conhecido como "a aquisição de recursos é inicialização" ou RAII.

Quando um objeto de pilha de Propriedade do recurso sai do escopo, seu destruidor é invocado automaticamente. Dessa forma, a coleta de lixo C++ no está bem relacionada à vida útil do objeto e é determinística. Um recurso é sempre liberado em um ponto conhecido no programa, que você pode controlar. Somente destruidores determinísticos como aqueles C++ no podem manipular memória e recursos sem memória igualmente.

O exemplo a seguir mostra um objeto simples `w`. Ele é declarado na pilha no escopo da função e é destruído no final do bloco de função. O objeto `w` não possui *recursos* (como memória alocada para heap). Seu único membro `g` é declarado na pilha e simplesmente sai do escopo junto com `w`. Nenhum código especial é necessário no destruidor `widget`.

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
    // ...
    w.draw();
    // ...
} // automatic destruction and deallocation for w and w.g
  // automatic exception safety,
  // as if "finally { w.dispose(); w.g.dispose(); }"
```

No exemplo a seguir, `w` possui um recurso de memória e, portanto, deve ter código em seu destruidor para excluir a memória.

```cpp
class widget
{
private:
    int* data;
public:
    widget(const int size) { data = new int[size]; } // acquire
    ~widget() { delete[] data; } // release
    void do_something() {}
};

void functionUsingWidget() {
    widget w(1000000);   // lifetime automatically tied to enclosing scope
                        // constructs w, including the w.data member
    w.do_something();

} // automatic destruction and deallocation for w and w.data

```

Desde o C++ 11, há uma maneira melhor de escrever o exemplo anterior: usando um ponteiro inteligente da biblioteca padrão. O ponteiro inteligente manipula a alocação e a exclusão da memória que ela possui. O uso de um ponteiro inteligente elimina a necessidade de um destruidor explícito na classe `widget`.

```cpp
#include <memory>
class widget
{
private:
    std::unique_ptr<int> data;
public:
    widget(const int size) { data = std::make_unique<int>(size); }
    void do_something() {}
};

void functionUsingWidget() {
    widget w(1000000);   // lifetime automatically tied to enclosing scope
                // constructs w, including the w.data gadget member
    // ...
    w.do_something();
    // ...
} // automatic destruction and deallocation for w and w.data

```

Usando ponteiros inteligentes para alocação de memória, você pode eliminar o potencial de vazamentos de memória. Esse modelo funciona para outros recursos, como identificadores de arquivo ou soquetes. Você pode gerenciar seus próprios recursos de maneira semelhante em suas classes. Para obter mais informações, consulte [ponteiros inteligentes](smart-pointers-modern-cpp.md).

O design de C++ garante que os objetos sejam destruídos quando saem do escopo. Ou seja, eles são destruídos conforme os blocos são encerrados, na ordem inversa de construção. Quando um objeto é destruído, suas bases e membros são destruídos em uma ordem específica. Objetos declarados fora de qualquer bloco, no escopo global, podem causar problemas. Pode ser difícil depurar, se o construtor de um objeto global lançar uma exceção.

## <a name="see-also"></a>Confira também

[Bem-vindo de volta paraC++](../cpp/welcome-back-to-cpp-modern-cpp.md)<br/>
[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
