---
title: "Classe integer_sequence | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "type_traits/std::index_sequence"
  - "type_traits/std::make_index_sequence"
  - "type_traits/std::integer_sequence"
  - "type_traits/std::make_integer_sequence"
  - "type_traits/std::index_sequence_for"
  - "integer_sequence"
  - "std.integer_sequence"
  - "std::integer_sequence"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "integer_sequence"
ms.assetid: 2cfdddee-819d-478e-bb78-c8a9c2696803
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe integer_sequence
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa uma sequência de número inteiro. Pode ser usado para deduzir e expanda pacotes de parâmetros em tipos de variadic como std::tuple \< t... > que são passados como argumentos para uma função.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template <class T, T... Vals>  
struct integer_sequence  
```  
  
#### <a name="parameters"></a>Parâmetros  
 T  
 O tipo de valores; deve ser um tipo integral: bool, char, char16_t, char32_t, wchar_t, ou assinado ou tipos de inteiro sem sinal.  
  
 Valos  
 Um pacote de parâmetro de tipo não representa uma sequência de valores do tipo integral T.  
  
## <a name="members"></a>Membros  
  
|||  
|-|-|  
|`static size_t size() noexcept`|O número de elementos na sequência.|  
|TypeDef T value_type|O tipo de cada elemento na sequência. Deve ser um tipo integral.|  
  
## <a name="remarks"></a>Comentários  
 Um pacote de parâmetro que é passado diretamente para uma função pode ser descompactado sem qualquer auxiliares biblioteca especial. Quando um pacote de parâmetros é parte de um tipo que é passado para uma função, e você precisa de índices para acessar os elementos, descompactá-lo a maneira mais fácil é usar `integer_sequence` e seus aliases de tipo relacionado `make_integer_sequence`, `index_sequence`, `make_index_sequence`, e `index_sequence_for`.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir baseia-se na proposta de original [N3658](http://open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3658.html). Ele mostra como usar um `integer_sequence` para criar um `std::tuple` de um `std::array<T,N>`, e como usar um `integer_sequence` para obter os membros de tupla.  
  
 No `a2t` função, um `index_sequence` é um alias de `integer_sequence` com base no `size_t` tipo integral. `make_index_sequence` é um alias que cria uma base zero em tempo de compilação `index_sequence` com o mesmo número de elementos da matriz que é passado pelo chamador. `a2t` passa o `index_sequence` por valor para `a2t_` , onde a expressão `a[I]...` desempacota `I`, e, em seguida, os elementos estão sendo alimentados para `make_tuple` que consome individuais como argumentos. Por exemplo, se a sequência contém três elementos, em seguida, `make_tuple` é chamado de make_tuple ([0], [1], a[2]). Os próprios elementos de matriz do curso podem ser qualquer tipo.  
  
 A função aplicar aceita uma [std::tuple](../standard-library/tuple-class.md), e produz um integer_sequence usando o `tuple_size` classe auxiliar. Observe que [std::decay_t](../standard-library/decay-class.md)_is necessário porque [tuple_size](../standard-library/tuple-size-class-tuple.md) não funciona com tipos de referência. O `apply_` função descompacta os membros da tupla e encaminha separados como argumentos para uma chamada de função. Neste exemplo, a função é uma simples expressão lambda que imprime os valores.  
  
```  
  
#include <stddef.h>  
#include <iostream>  
#include <tuple>  
#include <utility>  
#include <array>  
#include <string>  
  
using namespace std;  
  
// Create a tuple from the array and the index_sequence  
template<typename Array, size_t... I>  
auto a2t_(const Array& a, index_sequence<I...>)  
{  
    return make_tuple(a[I]...);  
}  
  
// Create an index sequence for the array, and pass it to the  
// implementation function a2t_  
template<typename T, size_t N>  
auto a2t(const array<T, N>& a)  
{  
    return a2t_(a, make_index_sequence<N>());  
}  
  
// Call function F with the tuple members as separate arguments.   
template<typename F, typename Tuple = tuple<T...>, size_t... I>  
decltype(auto) apply_(F&& f, Tuple&& args, index_sequence<I...>)   
{  
    return forward<F>(f)(get<I>(forward<Tuple>(args))...);  
}  
  
// Create an index_sequence for the tuple, and pass it with the   
// function object and the tuple to the implementation function apply_  
template<typename F, typename Tuple = tuple<T...>>  
decltype(auto) apply(F&& f, Tuple&& args)  
{  
    using Indices = make_index_sequence<tuple_size<decay_t<Tuple>>::value >;  
    return apply_(forward<F>(f), forward<Tuple>(args), Indices());  
}  
  
int main()  
{   
    const array<string, 3> arr { "Hello", "from", "C++14" };  
  
    //Create a tuple given a array  
    auto tup = a2t(arr);   
  
    // Extract the tuple elements  
    apply([](const string& a, const string& b, const string& c) {cout << a << " " << b << " " << c << endl; }, tup);  
  
    char c;  
    cin >> c;  
}  
  
```  
  
  Para fazer um `index_sequence` para um pacote de parâmetro, use `index_sequence_for`\< t... > que é um alias para `make_index_sequence`\< sizeof... (T) >  
  
## <a name="requirements"></a>Requisitos  
 Cabeçalho: \< type_traits >  
  
 Namepace: std  
  
## <a name="see-also"></a>Consulte também  
 [Reticências e modelos Variadic](../cpp/ellipses-and-variadic-templates.md)

