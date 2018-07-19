---
title: Fonte de organização do código (modelos do C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: 50569c5d-0219-4966-9bcf-a8689074ad1d
author: mikeblome
ms.author: mblome
ms.openlocfilehash: ef23b1a12305be9ecf181beb085bb686e81b083b
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37939748"
---
# <a name="source-code-organization-c-templates"></a>Organização do código-fonte (modelos do C++)

Ao definir um modelo de classe, você deve organizar o código-fonte, de forma que as definições de membro sejam visíveis para o compilador quando precisa deles.   Você tem a opção de usar o *modelo de inclusão* ou o *instanciação explícita* modelo. No modelo de inclusão, você deve incluir as definições de membro em todos os arquivos que usa um modelo. Essa abordagem é mais simples e fornece máxima flexibilidade em termos de quais tipos concretos que podem ser usados com seu modelo. Sua desvantagem é que ele pode aumentar o tempo de compilação. O impacto pode ser significativo se um projeto e/ou os arquivos incluídos em si são grandes. Com a abordagem de instanciação explícita, o próprio modelo instancia classes concretas ou membros de classe para tipos específicos.  Essa abordagem pode acelerar os tempos de compilação, mas ela limita o uso somente às classes que o implementador de modelo habilitada antecipadamente. Em geral, é recomendável que você use o modelo de inclusão, a menos que os tempos de compilação se tornar um problema.

## <a name="background"></a>Informações preliminares

Modelos não são como classes comuns no sentido de que o compilador não gera o código de objeto para um modelo ou qualquer um dos seus membros. Não há nada para ser gerado até que o modelo é instanciado com tipos concretos. Quando o compilador encontra uma instanciação de modelo, como `MyClass<int> mc;` e ainda não existe nenhuma classe com essa assinatura, ele gera uma nova classe. Ele também tenta gerar código para todas as funções membro que são usados. Se essas definições estão em um arquivo que não seja #included, direta ou indiretamente, no arquivo. cpp que está sendo compilado, o compilador não pode vê-los.  Do ponto de vista do compilador, isso não é necessariamente um erro porque as funções podem ser definidas em outra unidade de tradução, nesse caso o vinculador poderão encontrá-los.  Se o vinculador não encontrar esse código, ele gera uma **externo não resolvido** erro.

## <a name="the-inclusion-model"></a>O modelo de inclusão

A maneira mais simples e mais comum para tornar as definições de modelo visível em uma unidade de tradução é colocar as definições no arquivo de cabeçalho em si.  Simplesmente tem qualquer arquivo. cpp que usa o modelo para #include do cabeçalho. Isso é a abordagem usada na biblioteca padrão.

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

Com essa abordagem, o compilador tem acesso à definição de modelo completo e pode criar uma instância de modelos e sob demanda para qualquer tipo. É simples e relativamente fácil de manter. No entanto, o modelo de inclusão tem um custo em termos de tempo de compilação.   Esse custo pode ser significativo em programas maiores, especialmente se o cabeçalho do modelo em si #includes outros cabeçalhos. Arquivo de cada. cpp #includes cabeçalho receberá sua própria cópia dos modelos de função e todas as definições. O vinculador poderá geralmente arrumar tudo para que você não acabará com várias definições para uma função, mas leva tempo para fazer esse trabalho. Em programas menores que o tempo de compilação a mais provavelmente não é significativo.

## <a name="the-explicit-instantiation-model"></a>O modelo de instanciação explícita

Se o modelo de inclusão não é viável para seu projeto e você sabe, definitivamente, o conjunto de tipos que serão usadas para criar uma instância de um modelo, você pode separar o código de modelo em um arquivo. h e. cpp e no arquivo. cpp explicitamente instanciar os modelos. Isso fará com que o código de objeto a ser gerado que o compilador verá quando ele encontra instanciações do usuário.

Você pode criar uma instanciação explícita usando o modelo de palavra-chave seguido pela assinatura da entidade que você deseja criar uma instância. Isso pode ser um tipo ou membro. Se você instanciar explicitamente um tipo, todos os membros são instanciados.

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
#include "stdafx.h"
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

No exemplo anterior, as instanciações explícitas estão na parte inferior do arquivo. cpp. Um `MyArray` pode ser usado apenas para **duplo** ou `String` tipos.

> [!NOTE]
> No C++ 11 a **exportar** palavra-chave foi preterida no contexto de definições de modelo. Em termos práticos, isso tem pouco impacto porque a maioria dos compiladores nunca suportado.
