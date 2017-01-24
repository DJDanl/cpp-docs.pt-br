---
title: "&lt; funcional &gt; | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "<functional>"
  - "functional/std::<functional>"
  - "std.<functional>"
  - "std::<functional>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "functores"
  - "Cabeçalho functional"
ms.assetid: 7dd463e8-a29f-49bc-aedd-8fa53b54bfbc
caps.latest.revision: 27
caps.handback.revision: 27
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt; funcional &gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define as funções de biblioteca padrão que ajudam a construir *objetos de função*— também conhecido como functors — e seus. Um objeto de função é um objeto de um tipo que define `operator()`. Um objeto de função pode ser um ponteiro de função, mas normalmente, o objeto é usado para armazenar informações adicionais que possam ser acessadas durante uma chamada de função.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#include <functional>  
```  
  
## <a name="remarks"></a>Comentários  
 Algoritmos requerem dois tipos de objetos de função: unário e binário. Objetos de função unário exigem um argumento, e objetos de função binário dois argumentos. Um objeto de função e ponteiros de função podem ser passados como um predicado para um algoritmo, mas objetos de função também são adaptáveis e aumentam o escopo, a flexibilidade e a eficiência da STL. Se, por exemplo, um valor é necessário para ser associado a uma função antes de ser passado para um algoritmo, um ponteiro de função não pode ser usado. Adaptadores de função convertem ponteiros de função em objetos de função adaptável que podem ser associados a um valor. O cabeçalho \< funcional> também contém adaptadores de função de membro que permitem que o membro funções sejam chamadas como objetos de função adaptáveis. Funções são adaptáveis se eles tiverem as declarações de tipo aninhado especificando seu argumento e tipos de retorno. O padrão C++ requer que essa capacidade de adaptação é implementada fazendo com que todas as classes de objeto padrão herdar das classes base unary_function ou binary_function. Objetos de função e seus adaptadores permitem a STL atualizar aplicativos existentes e ajudam a integrar a STL ao ambiente de programação do C++.  
  
 O [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] implementação dos objetos na função \< funcional> inclui *funções de operador transparentes*, que são especializações de padrão de objetos de função e tomar sem parâmetros de modelo e executar o encaminhamento perfeito dos argumentos da função e retornar perfeito do resultado. Esse recurso faz parte do C + + 14 rascunho especificação padrão. Nessas especializações de modelo não exigem que você especificar tipos de argumento ao chamar aritmética, comparação, lógicos e funções de operador bit a bit transparentes. Você pode sobrecarregar aritmética, comparação, lógicos ou operadores bit a bit para seus próprios tipos ou para combinações heterogêneas de tipos e, em seguida, usar as funções de operador transparentes como argumentos de função. Por exemplo, se seu tipo *MyType* implementa `operator<`, você pode chamar `sort(my_collection.begin(), my_collection.end(), less<>())` em vez de especificar explicitamente o tipo `sort(my_collection.begin(), my_collection.end(), less<MyType>())`.  
  
## <a name="c11c14-implementation"></a>O c + + 11 / C + + 14 implementação  
 Os seguintes recursos são adicionados na implementação do Visual C++ do C++ 11 / C + + 14:  
  
-   Um *chamada assinatura* é o nome de um tipo de retorno seguido por uma lista separada por vírgulas entre parênteses de zero ou mais tipos de argumento.  
  
-   Um *callable tipo* é um ponteiro para a função, um ponteiro para função de membro, um ponteiro para dados de membro ou um tipo de classe cujos objetos podem aparecer imediatamente à esquerda de um operador de chamada de função.  
  
-   Um *objeto acessível* é um objeto de um tipo que pode ser chamado.  
  
-   Um *tipo de wrapper de chamada* é um tipo que contém um objeto que pode ser chamado e oferece suporte a uma operação de chamada que encaminha a esse objeto.  
  
-   Um *wrapper de chamada* é um objeto de um tipo de wrapper de chamada.  
  
-   Um *objeto de destino* é o objeto que pode ser chamado mantido por um objeto wrapper de chamada.  
  
 A função pseudo `INVOKE(f, t1, t2, ..., tN)` significa um dos seguintes itens:  
  
- `(t1.*f)(t2, ..., tN)` Quando `f` é um ponteiro para função de membro da classe `T` e `t1` é um objeto do tipo `T` ou uma referência a um objeto do tipo `T` ou uma referência a um objeto de um tipo derivado de `T`.  
  
- `((*t1).*f)(t2, ..., tN)` Quando `f` é um ponteiro para função de membro da classe `T` e `t1` não é um dos tipos descritos no item anterior.  
  
- `t1.*f` Quando N = = 1 e `f` é um ponteiro para dados de membro de uma classe `T` e `t1` é um objeto do tipo `T` ou uma referência a um objeto do tipo `T` ou uma referência a um objeto de um tipo derivado de `T`.  
  
- `(*t1).*f` Quando N = = 1 e `f` é um ponteiro para dados de membro de uma classe `T` e `t1` não é um dos tipos descritos no item anterior.  
  
- `f(t1, t2, ..., tN)` em todos os outros casos.  
  
 A função pseudo `INVOKE(f, t1, t2, ..., tN, R)` significa `INVOKE(f, t1, t2, ..., tN)` implicitamente convertido para `R`.  
  
 Se tiver um wrapper de chamada um *tipo de resultado fraco*, do tipo de seu membro `result_type` é baseado no tipo `T` do objeto de destino do wrapper, da seguinte maneira:  
  
-   Se `T` é um ponteiro para função, `result_type` é um sinônimo para o tipo de retorno de `T`.  
  
-   Se `T` é um ponteiro para função de membro, `result_type` é um sinônimo para o tipo de retorno de `T`.  
  
-   Se `T` é um tipo de classe que tem um tipo de membro `result_type`, em seguida, `result_type` é um sinônimo para `T::result_type`.  
  
-   Caso contrário, não há nenhum membro `result_type`.  
  
 Cada wrapper de chamada tem um construtor de movimentação e um construtor de cópia. Um *wrapper simples chamada* é um wrapper de chamada que tem uma atribuição de operador e cujo construtor de cópia, o construtor de movimentação e o operador de atribuição não lançam exceções. Um *encaminhamento wrapper de chamada* é um wrapper de chamada que pode ser chamado usando uma lista de argumentos arbitrários e fornece os argumentos para o objeto que pode ser chamado encapsulado como referências. Todos os argumentos rvalue são entregues como referências de rvalue e argumentos lvalue são entregues como referências de l-value.  
  
### <a name="classes"></a>Classes  
  
|||  
|-|-|  
|[bad_function_call](../standard-library/bad-function-call-class.md)|Uma classe que descreve uma exceção gerada para indicar que uma chamada para `operator()` em uma [função](../standard-library/function-class.md) objeto falhou porque o objeto estava vazio.|  
|[binary_negate](../Topic/binary_negate%20Class.md)|Uma classe de modelo fornecendo uma função de membro que nega o valor de retorno de uma função binário especificado.|  
|[binder1st](../standard-library/binder1st-class.md)|Uma classe de modelo fornecendo um construtor que converte um objeto de função binário em um objeto de função unário associando o primeiro argumento da função binário com um valor especificado.|  
|[binder2nd](../standard-library/binder2nd-class.md)|Uma classe de modelo fornecendo um construtor que converte um objeto de função binário em um objeto de função unário associando o segundo argumento da função binário com um valor especificado.|  
|[const_mem_fun_ref_t](../standard-library/const-mem-fun-ref-t-class.md)|Uma classe de adaptador que permite que uma função de membro constante que não utiliza argumentos a ser chamado como um objeto de função unário quando é inicializado com um argumento de referência.|  
|[const_mem_fun_t](../standard-library/const-mem-fun-t-class.md)|Uma classe de adaptador que permite que uma função de membro constante que não utiliza argumentos a ser chamado como um objeto de função unário quando é inicializado com um argumento de ponteiro.|  
|[const_mem_fun1_ref_t](../standard-library/const-mem-fun1-ref-t-class.md)|Uma classe de adaptador que permite que uma função de membro const que aceita um único argumento a ser chamado como um objeto de função binário quando é inicializado com um argumento de referência.|  
|[const_mem_fun1_t](../standard-library/const-mem-fun1-t-class.md)|Uma classe de adaptador que permite que uma função de membro const que aceita um único argumento a ser chamado como um objeto de função binário quando é inicializado com um argumento de ponteiro.|  
|[função](../standard-library/function-class.md)|Uma classe que encapsula um objeto que pode ser chamado.|  
|[hash](../standard-library/hash-class.md)|Uma classe que computa um código hash para um valor.|  
|[is_bind_expression](../standard-library/is-bind-expression-class.md)|Uma classe que testa se um tipo específico é gerado por chamar `bind`.|  
|[is_placeholder](../Topic/is_placeholder%20Class.md)|Uma classe que testa se um tipo específico é um espaço reservado.|  
|[mem_fun_ref_t](../Topic/mem_fun_ref_t%20Class.md)|Uma classe de adaptador que permite uma **non_const** função de membro que não utiliza argumentos a ser chamado como um objeto de função unário quando é inicializado com um argumento de referência.|  
|[mem_fun_t](../standard-library/mem-fun-t-class.md)|Uma classe de adaptador que permite uma **non_const** função de membro que não utiliza argumentos a ser chamado como um objeto de função unário quando é inicializado com um argumento de ponteiro.|  
|[mem_fun1_ref_t](../standard-library/mem-fun1-ref-t-class.md)|Uma classe de adaptador que permite uma **non_const** função de membro que aceita um único argumento a ser chamado como um objeto de função binário quando é inicializado com um argumento de referência.|  
|[mem_fun1_t](../Topic/mem_fun1_t%20Class.md)|Uma classe de adaptador que permite uma **non_const** função de membro que aceita um único argumento a ser chamado como um objeto de função binário quando é inicializado com um argumento de ponteiro.|  
|[pointer_to_binary_function](../standard-library/pointer-to-binary-function-class.md)|Converte um ponteiro de função binário em uma função binária adaptável.|  
|[pointer_to_unary_function](../standard-library/pointer-to-unary-function-class.md)|Converte um ponteiro de função unário em uma função unário adaptáveis.|  
|[reference_wrapper](../Topic/reference_wrapper%20Class.md)|Uma classe que encapsula uma referência.|  
|[result_of](../standard-library/result-of-class2.md)|Uma estrutura que contém o tipo de retorno de um objeto que pode ser chamado encapsulado.|  
|[unary_negate](../standard-library/unary-negate-class.md)|Uma classe de modelo fornecendo uma função de membro que nega o valor de retorno de uma função unário especificado.|  
  
### <a name="functions"></a>Funções  
  
|||  
|-|-|  
|[ligação](../Topic/%3Cfunctional%3E%20functions.md#bind_function)|Associa os argumentos para um objeto que pode ser chamado.|  
|[bind1st](../Topic/%3Cfunctional%3E%20functions.md#bind1st_function)|Uma função de modelo auxiliar que cria um adaptador para converter um objeto de função binário em um objeto de função unário associando o primeiro argumento da função binário com um valor especificado.|  
|[bind2nd](../Topic/%3Cfunctional%3E%20functions.md#bind2nd_function)|Uma função de modelo auxiliar que cria um adaptador para converter um objeto de função binário em um objeto de função unário associando o segundo argumento da função binário com um valor especificado.|  
|[bit_and](../Topic/%3Cfunctional%3E%20functions.md#bit_and_function)|Retorna o e lógico bit a bit (operador binário &) dos dois parâmetros.|  
|[bit_not](../Topic/%3Cfunctional%3E%20functions.md#bit_not_function)|Retorna o complemento de lógico bit a bit (operador ~) do parâmetro.|  
|[bit_or](../Topic/%3Cfunctional%3E%20functions.md#bit_or_function)|Retorna o OR lógico bit a bit (operador &#124;) dos dois parâmetros.|  
|[bit_xor](../Topic/%3Cfunctional%3E%20functions.md#bit_xor_function)|Retorna o XOR lógico bit a bit (operador ^) dos dois parâmetros.|  
|[cref](../Topic/%3Cfunctional%3E%20functions.md#cref_function)|Constrói um const `reference_wrapper` de um argumento.|  
|[mem_fn](../Topic/%3Cfunctional%3E%20functions.md#mem_fn_function)|Gera um wrapper simples chamada.|  
|[mem_fun](../Topic/%3Cfunctional%3E%20functions.md#mem_fun_function)|Funções de modelo de auxiliares usadas para criar adaptadores de objeto de função para funções de membro quando inicializado com argumentos de ponteiro.|  
|[mem_fun_ref](../Topic/%3Cfunctional%3E%20functions.md#mem_fun_ref_function)|Uma função de modelo auxiliar usada para construir adaptadores de objeto de função para funções de membro quando inicializado com argumentos de referência.|  
|[not1](../Topic/%3Cfunctional%3E%20functions.md#not1_function)|Retorna o complemento de um predicado unário.|  
|[not2](../Topic/%3Cfunctional%3E%20functions.md#not2_function)|Retorna o complemento de um predicado binário.|  
|[ptr_fun](../Topic/%3Cfunctional%3E%20functions.md#ptr_fun_function)|Uma função auxiliar do modelo usado para converter unário e binária função ponteiros, respectivamente, em funções adaptáveis unário ou binário.|  
|[REF](../Topic/%3Cfunctional%3E%20functions.md#ref_function)|Constrói um `reference_wrapper` de um argumento.|  
|[troca](../Topic/%3Cfunctional%3E%20functions.md#swap_function)|Troca dois `function` objetos.|  
  
### <a name="structs"></a>Structs  
  
|||  
|-|-|  
|[binary_function](../Topic/binary_function%20Struct.md)|Uma classe base vazia que define os tipos que podem ser herdados por uma classe derivada que fornece um objeto de função binário.|  
|[divide](../standard-library/divides-struct.md)|A classe fornece um objeto de função predefinida que executa a operação de divisão aritmética em elementos de um tipo de valor especificado.|  
|[equal_to](../standard-library/equal-to-struct.md)|Um predicado binário que testa se um valor de um tipo especificado é igual a outro valor desse tipo.|  
|[maior](../standard-library/greater-struct.md)|Um predicado binário que testa se um valor de um tipo especificado é maior que outro valor desse tipo.|  
|[greater_equal](../standard-library/greater-equal-struct.md)|Um predicado binário que testa se um valor de um tipo especificado é maior que ou igual a outro valor desse tipo.|  
|[menor](../standard-library/less-struct.md)|Um predicado binário que testa se um valor de um tipo especificado é menor que outro valor desse tipo.|  
|[less_equal](../standard-library/less-equal-struct.md)|Um predicado binário que testa se um valor de um tipo especificado é menor que ou igual a outro valor desse tipo.|  
|[logical_and](../Topic/logical_and%20Struct.md)|A classe fornece um objeto de função predefinida que executa a operação lógica do conjunto em elementos de um tipo de valor especificado e testa a legitimidade ou falsity do resultado.|  
|[logical_not](../Topic/logical_not%20Struct.md)|A classe fornece um objeto de função predefinida que executa a operação de negação lógica em elementos de um tipo de valor especificado e testa a legitimidade ou falsity do resultado.|  
|[logical_or](../standard-library/logical-or-struct.md)|A classe fornece um objeto de função predefinida que executa a operação de disjunção lógica em elementos de um tipo de valor especificado e testa a legitimidade ou falsity do resultado.|  
|[subtração](../standard-library/minus-struct.md)|A classe fornece um objeto de função predefinida que realiza a operação aritmética de subtração em elementos de um tipo de valor especificado.|  
|[módulo](../standard-library/modulus-struct.md)|A classe fornece um objeto de função predefinida que executa a operação aritmética de módulo em elementos de um tipo de valor especificado.|  
|[Multiplica](../standard-library/multiplies-struct.md)|A classe fornece um objeto de função predefinida que realiza a operação de multiplicação aritmética em elementos de um tipo de valor especificado.|  
|[Negar](../standard-library/negate-struct.md)|A classe fornece um objeto de função predefinida que retorna o negativo de um valor de elemento.|  
|[not_equal_to](../standard-library/not-equal-to-struct.md)|Um predicado binário que testa se um valor de um tipo especificado não é igual a outro valor desse tipo.|  
|[sinal de adição](../standard-library/plus-struct.md)|A classe fornece um objeto de função predefinida que executa a operação de adição aritmética em elementos de um tipo de valor especificado.|  
|[unary_function](../Topic/unary_function%20Struct.md)|Uma classe base vazia que define os tipos que podem ser herdados por uma classe derivada que fornece um objeto de função unário.|  
  
### <a name="objects"></a>Objetos  
  
|||  
|-|-|  
|[_1.._M](../standard-library/1-object.md)|Espaços reservados para argumentos substituíveis.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operador = =](../Topic/%3Cfunctional%3E%20operators.md#operator_eq_eq)|Não permite a comparação de igualdade de objetos que pode ser chamados.|  
|[operador! =](../Topic/%3Cfunctional%3E%20operators.md#operator_neq)|Não permite a comparação de desigualdade de objetos que pode ser chamados.|  
  
## <a name="see-also"></a>Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de modelos padrão](../misc/standard-template-library.md)

