---
title: Organização do código-fonte (modelos do C++)
ms.date: 04/22/2019
ms.assetid: 50569c5d-0219-4966-9bcf-a8689074ad1d
ms.openlocfilehash: 76898d04e5f9f0576898eb40945b7718c650d71a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80178724"
---
# <a name="source-code-organization-c-templates"></a>Organização do código-fonte (modelos do C++)

Ao definir um modelo de classe, você deve organizar o código-fonte de tal forma que as definições de membro sejam visíveis para o compilador quando ele precisar delas.   Você tem a opção de usar o *modelo de inclusão* ou o modelo de *instanciação explícita*. No modelo de inclusão, as definições de membro são incluídas em todos os arquivos que usam um modelo. Essa abordagem é a mais simples e oferece a máxima flexibilidade em termos dos tipos concretos que podem ser usados com seu modelo. A desvantagem é que pode aumentar o tempo de compilação. O impacto pode ser significativo se um projeto e/ou os próprios arquivos incluídos forem grandes. Com a abordagem de instanciação explícita, o próprio modelo instancia as classes concretas ou membros de classe para tipos específicos.  Essa abordagem pode acelerar os tempos de compilação, mas limita o uso somente para as classes que o implementador de modelo habilitou antecipadamente. Em geral, é recomendável que você use o modelo de inclusão, a menos que os tempos de compilação se tornem um problema.

## <a name="background"></a>Segundo plano

Os modelos não são como classes comuns no sentido de que o compilador não gera o código de objeto para um modelo ou qualquer um dos seus membros. Não há nada a ser gerado até que o modelo seja instanciado com tipos concretos. Quando o compilador encontra uma instanciação de modelo, como `MyClass<int> mc;`, e ainda não existe nenhuma classe com essa assinatura, ele gera uma nova classe. Ele também tenta gerar código para todas as funções membro que são usadas. Se essas definições estiverem em um arquivo que não esteja #incluído, direta ou indiretamente, no arquivo .cpp que está sendo compilado, o compilador não poderá vê-los.  Do ponto de vista do compilador, isso não é necessariamente um erro porque as funções podem ser definidas em outra unidade de tradução, que serão encontradas pelo vinculador.  Caso o vinculador não encontre esse código, ele gerará um erro **externo não resolvido**.

## <a name="the-inclusion-model"></a>O modelo de inclusão

A maneira mais simples e mais comum de tornar visíveis as definições de modelo em uma unidade de tradução é colocando-as no próprio arquivo de cabeçalho.  Todo arquivo .cpp que usa o modelo simplesmente tem que #incluir o cabeçalho. Essa é a abordagem usada na Biblioteca Padrão.

```cpp
#ifndef MYARRAY
#define MYARRAY
#include <iostream>

template<typename T, size_t N>
class MyArray
{
    T arr[N];
public:
    // Full definitions:
    MyArray(){}
    void Print()
    {
        for (const auto v : arr)
        {
            std::cout << v << " , ";
        }
    }

    T& operator[](int i)
   {
       return arr[i];
   }
};
#endif
```

Com essa abordagem, o compilador tem acesso à definição completa de modelo e pode criar uma instância de modelos sob demanda para qualquer tipo. É simples e relativamente fácil de manter. No entanto, o modelo de inclusão tem um custo em termos de tempo de compilação.   Esse custo pode ser significativo em programas maiores, especialmente se o cabeçalho do modelo em si #incluir outros cabeçalhos. Todo arquivo .cpp que #inclui o cabeçalho receberá a própria cópia dos modelos de função e todas as definições. O vinculador geralmente conseguirá arrumar tudo para que você não acabe com várias definições para uma função, mas realizar esse trabalho leva tempo. Em programas menores, esse tempo de compilação a mais provavelmente não é significativo.

## <a name="the-explicit-instantiation-model"></a>O modelo de instanciação explícita

Se o modelo de inclusão não for viável para seu projeto e você conhecer bem o conjunto de tipos que serão usados para criar uma instância de um modelo, poderá separar o código de modelo em um arquivo. h e .cpp e, no arquivo .cpp, instanciar explicitamente os modelos. Isso fará com que o código de objeto que o compilador verá quando encontrar instanciações do usuário seja gerado.

Uma instanciação explícita é criada, usando o modelo de palavra-chave seguido da assinatura da entidade que você deseja instanciar. Pode ser um tipo ou membro. Caso você instancie explicitamente um tipo, todos os membros serão instanciados.

```cpp
template MyArray<double, 5>;
```

```cpp
//MyArray.h
#ifndef MYARRAY
#define MYARRAY

template<typename T, size_t N>
class MyArray
{
    T arr[N];
public:
    MyArray();
    void Print();
    T& operator[](int i);
};
#endif

//MyArray.cpp
#include <iostream>
#include "MyArray.h"

using namespace std;

template<typename T, size_t N>
MyArray<T,N>::MyArray(){}

template<typename T, size_t N>
void MyArray<T,N>::Print()
{
    for(const auto v : arr)
    {
        cout << v << "'";
    }
    cout << endl;
}

template MyArray<double, 5>;template MyArray<string, 5>;
```

No exemplo anterior, as instanciações explícitas estão na parte inferior do arquivo .cpp. Um `MyArray` pode ser usado apenas para os tipos **duplo** ou `String`.

> [!NOTE]
> No C++ 11, a palavra-chave **exportar** foi preterida no contexto de definições de modelo. Em termos práticos, isso tem pouco impacto porque a maioria dos compiladores nunca foi compatível com ela.
