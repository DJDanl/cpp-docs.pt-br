---
title: 'Como: Criar e usar instâncias shared_ptr'
ms.custom: how-to
ms.date: 05/22/2019
ms.topic: conceptual
ms.assetid: 7d6ebb73-fa0d-4b0b-a528-bf05de96518e
ms.openlocfilehash: d0ee1a5e8c5d26e8e0bec060ffe3d5fea30ce0fa
ms.sourcegitcommit: bd7ddc044f9083246614b602ef6a758775313214
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2019
ms.locfileid: "68866144"
---
# <a name="how-to-create-and-use-shared_ptr-instances"></a>Como: Criar e usar instâncias shared_ptr

O tipo `shared_ptr` é um ponteiro inteligente na biblioteca padrão do C++ que foi projetado para cenários em que mais de um proprietário pode ter que gerenciar o tempo de vida do objeto na memória. Depois de inicializar um `shared_ptr`, você pode copiá-lo, passá-lo pelo valor em argumentos de função e atribuí-lo a outras instâncias `shared_ptr`. Todas as instâncias apontam para o mesmo objeto e compartilham o acesso a um "bloco de controle" que incrementa e decrementa a contagem de referência sempre que um novo `shared_ptr` é adicionado, sai do escopo ou é redefinido. Quando a contagem de referência alcança zero, o bloco de controle exclui o recurso de memória e ele mesmo.

A ilustração a seguir mostra várias instâncias `shared_ptr` que apontam para um local da memória.

![Diagrama de ponteiro compartilhado](../cpp/media/shared_ptr.png "Diagrama de ponteiro compartilhado")

## <a name="example-setup"></a>Configuração de exemplo

Os exemplos a seguir supõem que você incluiu os cabeçalhos necessários e declarou os tipos necessários, conforme mostrado aqui:

```cpp
// shared_ptr-examples.cpp
// The following examples assume these declarations:
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct MediaAsset
{
    virtual ~MediaAsset() = default; // make it polymorphic
};

struct Song : public MediaAsset
{
    std::wstring artist;
    std::wstring title;
    Song(const std::wstring& artist_, const std::wstring& title_) :
        artist{ artist_ }, title{ title_ } {}
};

struct Photo : public MediaAsset
{
    std::wstring date;
    std::wstring location;
    std::wstring subject;
    Photo(
        const std::wstring& date_,
        const std::wstring& location_,
        const std::wstring& subject_) :
        date{ date_ }, location{ location_ }, subject{ subject_ } {}
};

using namespace std;

int main()
{
    // The examples go here, in order:
    // Example 1
    // Example 2
    // Example 3
    // Example 4
    // Example 6
}
```

## <a name="example-1"></a>Exemplo 1

Sempre que possível, use a função [make_shared](../standard-library/memory-functions.md#make_shared) para criar um `shared_ptr` quando o recurso de memória for criado pela primeira vez. `make_shared` é à prova de exceção. Ele usa a mesma chamada para alocar a memória para o bloco de controle e o recurso, que reduz a sobrecarga de construção. Se você não usar `make_shared`, deverá usar uma expressão `new` explícita para criar o objeto antes de passá-lo para o construtor `shared_ptr`. O exemplo a seguir mostra várias maneiras de declarar e inicializar um `shared_ptr` junto com um novo objeto.

[!code-cpp[stl_smart_pointers#1](../cpp/codesnippet/CPP/how-to-create-and-use-shared-ptr-instances_1.cpp)]

## <a name="example-2"></a>Exemplo 2

O exemplo a seguir mostra como declarar e inicializar instâncias `shared_ptr` que assumem a posse compartilhada de um objeto que já foi alocado por outro `shared_ptr`. Suponha que `sp2` seja um `shared_ptr` inicializado.

[!code-cpp[stl_smart_pointers#2](../cpp/codesnippet/CPP/how-to-create-and-use-shared-ptr-instances_2.cpp)]

## <a name="example-3"></a>Exemplo 3:

`shared_ptr` também será útil em contêineres da Biblioteca Padrão do C++ quando você estiver usando algoritmos que copiam elementos. Você pode encapsular os elementos em um `shared_ptr` e, em seguida, copiá-lo em outros contêineres sabendo que a memória subjacente é válida somente pelo tempo em que for necessária. O exemplo a seguir mostra como usar o algoritmo `remove_copy_if` em instâncias `shared_ptr` em um vetor.

[!code-cpp[stl_smart_pointers#4](../cpp/codesnippet/CPP/how-to-create-and-use-shared-ptr-instances_3.cpp)]

## <a name="example-4"></a>Exemplo 4

Você pode usar `dynamic_pointer_cast`, `static_pointer_cast` e `const_pointer_cast` para converter um `shared_ptr`. Essas funções se parecem com os operadores `dynamic_cast`, `static_cast` e `const_cast`. O exemplo a seguir mostra como testar o tipo derivado de cada elemento em um vetor de `shared_ptr` de classes base e, em seguida, copiar os elementos e exibir informações sobre eles.

[!code-cpp[stl_smart_pointers#5](../cpp/codesnippet/CPP/how-to-create-and-use-shared-ptr-instances_4.cpp)]

## <a name="example-5"></a>Exemplo 5

Você pode passar um `shared_ptr` para outra função das seguintes maneiras:

- Passar o `shared_ptr` por valor. Isso invoca o construtor de cópia, incrementa a contagem de referência e torna o receptor um proprietário. Há uma pequena quantidade de sobrecarga nessa operação, que pode ser significativa dependendo de quantos objetos `shared_ptr` você está passando. Use essa opção quando o contrato de código implícito ou explícito entre o chamador e o receptor exigir que o receptor seja um proprietário.

- Passar o `shared_ptr` por referência ou referência const. Nesse caso, a contagem de referência não é incrementada e o receptor pode acessar o ponteiro desde que o chamador não saia do escopo. Ou o receptor pode optar por criar um `shared_ptr` com base na referência e se tornar um proprietário compartilhado. Use esta opção quando o chamador não tiver conhecimento do receptor ou quando você precisar passar um `shared_ptr` e quiser evitar a operação de cópia por motivos de desempenho.

- Passar o ponteiro subjacente ou uma referência ao objeto subjacente. Isso permite que o receptor use o objeto, mas não o habilita a compartilhar a propriedade ou estender o tempo de vida. Se o receptor criar um `shared_ptr` do ponteiro bruto, o novo `shared_ptr` será independente do original e não controlará o recurso subjacente. Use essa opção quando o contrato entre o chamador e o receptor claramente especificar que o chamador retém a propriedade do tempo de vida `shared_ptr`.

- Ao decidir como passar um `shared_ptr`, determine se o receptor deve compartilhar a propriedade do recurso subjacente. Um "proprietário" é um objeto ou uma função que pode manter o recurso subjacente ativo pelo tempo necessário. Se o chamador precisar garantir que o receptor pode estender o tempo do ponteiro para além do seu tempo de vida (da função), use a primeira opção. Se não se importar se o receptor estende o tempo de vida, passe por referência e permita ou não que o receptor o copie.

- Se tiver que fornecer um acesso de função auxiliar para o ponteiro subjacente e souber que a função auxiliar apenas usará o ponteiro e retornará antes de a função de chamada retornar, então essa função não precisará compartilhar a propriedade do ponteiro subjacente. Ela precisa apenas acessar o ponteiro dentro do tempo de vida do `shared_ptr` do chamador. Nesse caso, é seguro passar o `shared_ptr` por referência ou passar o ponteiro bruto ou uma referência ao objeto subjacente. Passar dessa maneira fornece um pequeno benefício de desempenho e também pode ajudar a expressar sua intenção de programação.

- Às vezes, por exemplo em um `std::vector<shared_ptr<T>>`, você poderá precisar passar cada `shared_ptr` a um corpo da expressão lambda ou a um objeto de função. Se o lambda ou a função não armazenar o ponteiro, passe `shared_ptr` por referência para evitar invocar o construtor de cópia para cada elemento.

## <a name="example-6"></a>Exemplo 6

O exemplo a seguir mostra como `shared_ptr` sobrecarrega vários operadores de comparação para habilitar comparações do ponteiro na memória que pertence às instâncias `shared_ptr`.

[!code-cpp[stl_smart_pointers#3](../cpp/codesnippet/CPP/how-to-create-and-use-shared-ptr-instances_6.cpp)]

## <a name="see-also"></a>Consulte também

[Ponteiros inteligentes (C++ moderno)](../cpp/smart-pointers-modern-cpp.md)
