---
title: "Fonte de organização de código (C++ modelos) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 50569c5d-0219-4966-9bcf-a8689074ad1d
caps.latest.revision: "5"
manager: ghogen
ms.openlocfilehash: 1b3b17c17bad3834774f747548dda6710e178cb4
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="source-code-organization-c-templates"></a>Organização de código fonte (modelos do C++)

Ao definir um modelo de classe, você deve organizar o código-fonte de forma que as definições de membro são visíveis para o compilador quando ele precisa deles.   Você tem a opção de usar o *modelo inclusão* ou *instanciação explícita* modelo. No modelo de inclusão, você deve incluir as definições de membro em cada arquivo que usa um modelo. Essa abordagem é mais simples e fornece máxima flexibilidade em termos de quais tipos concretos podem ser usados com o modelo. Sua desvantagem é que ele pode aumentar o tempo de compilação. O impacto pode ser significativo se um projeto de e/ou os próprios arquivos incluídos forem grandes. Com a abordagem de instanciação explícita, o próprio modelo cria classes concretas ou membros de classe para tipos específicos.  Essa abordagem pode acelerar o tempo de compilação, mas ela limita o uso de somente às classes que tiver habilitado o implementador de modelo antecipadamente. Em geral, é recomendável que você use o modelo de inclusão, a menos que o tempo de compilação se tornar um problema.  
  
## <a name="background"></a>Informações preliminares

 Modelos não são como as classes comuns no sentido de que o compilador gera o código de objeto para um modelo ou qualquer um de seus membros. Não há nada para ser gerado até que o modelo é instanciado com tipos concretos. Quando o compilador encontra uma instanciação de modelo, como `MyClass<int> mc;` e ainda não existe nenhuma classe com essa assinatura, ele gera uma nova classe. Ele também tenta gerar código para qualquer função de membro que são usados. Se essas definições estão em um arquivo que não seja #included, direta ou indiretamente, no arquivo. cpp que está sendo compilado, o compilador não pode vê-los.  Do ponto de vista do compilador, isso não é necessariamente um erro porque as funções podem ser definidas em outra unidade de tradução, nesse caso o vinculador será encontrá-los.  Se o vinculador não encontrar esse código, ele gerará uma **externo não resolvido** erro.  

## <a name="the-inclusion-model"></a>O modelo de inclusão

 A maneira mais simples e mais comum para tornar as definições de modelo visível em uma unidade de tradução é colocar as definições no próprio arquivo de cabeçalho.  Qualquer arquivo. cpp que usa o modelo simplesmente precisa #include o cabeçalho. Essa é a abordagem usada na biblioteca padrão.  
  
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
  
 Com essa abordagem, o compilador tem acesso à definição do modelo completo e pode instanciar modelos sob demanda para qualquer tipo. É relativamente fácil de manter e simples. No entanto, o modelo de inclusão tem um custo em termos de tempo de compilação.   Esse custo pode ser significativo em programas grandes, especialmente se o cabeçalho de modelo #includes outros cabeçalhos. Cada cpp arquivo #includes o cabeçalho terá sua própria cópia dos modelos de função e todas as definições. O vinculador geralmente será capaz de classificar itens para que você não terminar com várias definições para uma função, mas leva tempo para fazer esse trabalho. Em programas menores que o tempo de compilação extra provavelmente não é significativo.  
  
## <a name="the-explicit-instantiation-model"></a>O modelo de instanciação explícita

 Se o modelo de inclusão não é viável para o seu projeto e você souber definitivamente o conjunto de tipos que serão usados para criar uma instância de um modelo, você pode separar o código de modelo em um arquivo. h e. cpp e no arquivo. cpp instanciar explicitamente os modelos. Isso fará com que o código de objeto a ser gerado que o compilador verão quando encontra instanciações de usuário.  
  
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
  
 No exemplo anterior, as instanciações explícitas estão na parte inferior do arquivo. cpp. Um `MyArray` pode ser usada apenas para **duplo** ou **cadeia de caracteres** tipos.  
  
> [!NOTE]
>  No C++ 11 a **exportar** palavra-chave foi preterido no contexto de definições de modelo. Em termos práticos, isso tem pouco impacto porque a maioria dos compiladores nunca suportado.
