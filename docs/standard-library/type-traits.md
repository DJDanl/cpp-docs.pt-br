---
title: "&lt; type_traits &gt; | Microsoft Docs"
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
  - "<type_traits>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho typetrait [TR1]"
  - "type_traits"
ms.assetid: 2260b51f-8160-4c66-a82f-00b534cb60d4
caps.latest.revision: 35
caps.handback.revision: 25
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt; type_traits &gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define os modelos que fornecem constantes de tempo de compilação que dão informações sobre as propriedades dos argumentos de tipo ou produzirem transformado tipos.  
  
## Sintaxe  
  
```  
#include <type_traits>  
```  
  
## Comentários  
 As classes e os modelos no `<type_traits>` são usados para oferecer suporte a inferência de tipo, classificação e transformação em tempo de compilação, para detectar erros de tipo e para ajudá\-lo a otimizar o código genérico. Essas classes e modelos incluem unário características de tipo que descrevem uma propriedade de um tipo, características de tipo binário que descrevem uma relação entre tipos e características de transformação que modificar uma propriedade de um tipo.  
  
 Para dar suporte a características de tipo, uma classe auxiliar, `integral_constant`, está definido. Ele tem especializações de modelo `true_type` e `false_type` que formam as classes base para predicados de tipo. Um *predicado de tipo* é um modelo que pega um ou mais argumentos de tipo. Quando um predicado de tipo *for verdadeira*, ele é derivado publicamente, direta ou indiretamente, de [true\_type](../Topic/true_type%20Typedef.md). Quando um predicado de tipo *mantém false*, ele é derivado publicamente, direta ou indiretamente, de [false\_type](../Topic/false_type%20Typedef.md).  
  
 Um *modificador de tipo* ou *característica da transformação* é um modelo que pega um ou mais argumentos de modelo e tem um membro, `type`, que é um sinônimo para o tipo de modificação.  
  
### Modelos de alias  
 Para simplificar expressões de características de tipo [modelos de alias](../cpp/aliases-and-typedefs-cpp.md) para `typename some_trait<T>::type` são fornecidos, onde " `some_trait`" é o nome da classe de modelo. Por exemplo, [add\_const](../Topic/add_const%20Class.md) tem um modelo de alias para seu tipo, `add_const_t`, definida como:  
  
```cpp  
template<class T>  
    using add_const_t = typename add_const<T>::type;  
```  
  
|||||  
|-|-|-|-|  
|add\_const\_t|aligned\_storage\_t|make\_signed\_t|remove\_pointer\_t|  
|add\_cv\_t|aligned\_union\_t|make\_unsigned\_t|remove\_reference\_t|  
|add\_lvalue\_reference\_t|common\_type\_t|remove\_all\_extents\_t|remove\_volatile\_t|  
|add\_pointer\_t|conditional\_t|remove\_const\_t|result\_of\_t|  
|add\_rvalue\_reference\_t|decay\_t|remove\_cv\_t|underlying\_type\_t|  
|add\_volatile\_t|enable\_if\_t|remove\_extent\_t||  
  
### Classes  
 Definições de tipo e a classe auxiliar  
  
|||  
|-|-|  
|[integral\_constant](../standard-library/integral-constant-class-bool-constant-class.md)|Torna constante integral de um tipo e um valor.|  
|[true\_type](../Topic/true_type%20Typedef.md)|Mantém uma constante integral com valor true.|  
|[false\_type](../Topic/false_type%20Typedef.md)|Mantém uma constante integral com valor falso.|  
  
 Categorias de tipo principal  
  
|||  
|-|-|  
|[is\_void](../standard-library/is-void-class.md)|Testa se o tipo é `void`.|  
|[is\_null\_pointer](../standard-library/is-null-pointer-class.md)|Testa se o tipo é `std::nullptr_t`.|  
|[is\_integral](../standard-library/is-integral-class.md)|Testa se o tipo é integral.|  
|[is\_floating\_point](../standard-library/is-floating-point-class.md)|Testa se o tipo de ponto flutuante.|  
|[is\_array](../Topic/is_array%20Class.md)|Testa se o tipo é uma matriz.|  
|[is\_pointer](../standard-library/is-pointer-class.md)|Testa se o tipo é um ponteiro.|  
|[is\_lvalue\_reference](../standard-library/is-lvalue-reference-class.md)|Testa se o tipo é uma referência de lvalue.|  
|[is\_rvalue\_reference](../Topic/is_rvalue_reference%20Class.md)|Testa se o tipo é uma referência de rvalue.|  
|[is\_member\_object\_pointer](../standard-library/is-member-object-pointer-class.md)|Testa se o tipo é um ponteiro para um objeto de membro.|  
|[is\_member\_function\_pointer](../Topic/is_member_function_pointer%20Class.md)|Testa se o tipo é um ponteiro para uma função de membro.|  
|[is\_enum](../standard-library/is-enum-class.md)|Testa se o tipo é uma enumeração.|  
|[is\_union](../standard-library/is-union-class.md)|Testa se o tipo é uma união.|  
|[is\_class](../standard-library/is-class-class.md)|Testa se o tipo é uma classe.|  
|[is\_function](../standard-library/is-function-class.md)|Testa se o tipo é um tipo de função.|  
  
 Categorias de tipos compostos  
  
|||  
|-|-|  
|[is\_reference](../Topic/is_reference%20Class.md)|Testa se o tipo é uma referência.|  
|[is\_arithmetic](../Topic/is_arithmetic%20Class.md)|Testa se o tipo é aritmético.|  
|[is\_fundamental](../standard-library/is-fundamental-class.md)|Testa se o tipo é `void` aritmético.|  
|[is\_object](../standard-library/is-object-class.md)|Testa se o tipo é um tipo de objeto.|  
|[is\_scalar](../standard-library/is-scalar-class.md)|Testa se o tipo é escalar.|  
|[is\_compound](../standard-library/is-compound-class.md)|Testa se o tipo não é escalar.|  
|[is\_member\_pointer](../standard-library/is-member-pointer-class.md)|Testa se o tipo é um ponteiro para um membro.|  
  
 Propriedades de tipo  
  
|||  
|-|-|  
|[is\_const](../Topic/is_const%20Class.md)|Testa se o tipo é `const`.|  
|[is\_volatile](../standard-library/is-volatile-class.md)|Testa se o tipo é `volatile`.|  
|[is\_trivial](../Topic/is_trivial%20Class.md)|Testa se o tipo é trivial.|  
|[is\_trivially\_copyable](../standard-library/is-trivially-copyable-class.md)|Testa se o tipo é facilmente copiado.|  
|[is\_standard\_layout](../Topic/is_standard_layout%20Class.md)|Testa se o tipo for um tipo de layout padrão.|  
|[is\_pod](../standard-library/is-pod-class.md)|Testa se o tipo é um POD.|  
|[is\_literal\_type](../standard-library/is-literal-type-class.md)|Testa se o tipo pode ser um `constexpr` variável ou usado em um `constexpr` função.|  
|[is\_empty](../standard-library/is-empty-class.md)|Testa se o tipo é uma classe vazia.|  
|[is\_polymorphic](../Topic/is_polymorphic%20Class.md)|Testa se o tipo é uma classe polimórfica.|  
|[is\_abstract](../Topic/is_abstract%20Class.md)|Testa se o tipo é uma classe abstrata.|  
|[is\_final](../standard-library/is-final-class.md)|Testa se o tipo é marcado como um tipo de classe `final`.|  
|[is\_signed](../Topic/is_signed%20Class.md)|Testa se o tipo é um inteiro assinado.|  
|[is\_unsigned](../standard-library/is-unsigned-class.md)|Testa se o tipo é um inteiro não assinado.|  
|[is\_constructible](../standard-library/is-constructible-class.md)|Testa se o tipo é construível usando os tipos de argumento especificado.|  
|[is\_default\_constructible](../Topic/is_default_constructible%20Class.md)|Testa se o tipo tem um construtor padrão.|  
|[is\_copy\_constructible](../standard-library/is-copy-constructible-class.md)|Testa se o tipo tem um construtor de cópia.|  
|[is\_move\_constructible](../standard-library/is-move-constructible-class.md)|Testa se o tipo tem um construtor de movimentação.|  
|[is\_assignable](../standard-library/is-assignable-class.md)|Testa se o primeiro tipo pode ser atribuído um valor do segundo tipo.|  
|[is\_copy\_assignable](../standard-library/is-copy-assignable-class.md)|Testa se um tipo pode ser atribuído um valor de referência const do tipo.|  
|[is\_move\_assignable](../standard-library/is-move-assignable-class.md)|Testa se um tipo pode ser atribuído a uma referência de rvalue do tipo.|  
|[is\_destructible](../standard-library/is-destructible-class.md)|Testa se o tipo é destructible.|  
|[is\_trivially\_constructible](../standard-library/is-trivially-constructible-class.md)|Testa se o tipo não usa nenhuma operação incomum quando construída usando os tipos especificados.|  
|[is\_trivially\_default\_constructible](../standard-library/is-trivially-default-constructible-class.md)|Testa se o tipo não usa nenhuma operação incomum quando construída padrão.|  
|[is\_trivially\_copy\_constructible](../standard-library/is-trivially-copy-constructible-class.md)|Testa se o tipo não usa nenhuma operação incomum quando a cópia é construída.|  
|[is\_trivially\_move\_constructible](../standard-library/is-trivially-move-constructible-class.md)|Testa se o tipo não usa nenhuma operação incomum quando mover construído.|  
|[is\_trivially\_assignable](../Topic/is_trivially_assignable%20Class.md)|Testa se os tipos são atribuíveis e a atribuição não usa nenhuma operação não triviais.|  
|[is\_trivially\_copy\_assignable](../standard-library/is-trivially-copy-assignable-class.md)|Testa se o tipo não é atribuível de cópia e a atribuição usa nenhuma operação não triviais.|  
|[is\_trivially\_move\_assignable](../standard-library/is-trivially-move-assignable-class.md)|Testa se o tipo não é atribuível de movimentação e a atribuição usa nenhuma operação não triviais.|  
|[is\_trivially\_destructible](../standard-library/is-trivially-destructible-class.md)|Testa se o tipo é destructible e o destruidor não usa nenhuma operação não triviais.|  
|[is\_nothrow\_constructible](../standard-library/is-nothrow-constructible-class.md)|Testa se o tipo é construível e não puder emitir quando criada usando os tipos especificados.|  
|[is\_nothrow\_default\_constructible](../standard-library/is-nothrow-default-constructible-class.md)|Testes se o tipo é padrão construível e é conhecido por não lançar quando construída padrão.|  
|[is\_nothrow\_copy\_constructible](../standard-library/is-nothrow-copy-constructible-class.md)|Testa se o tipo é construível cópia e o construtor de cópia é conhecido por não lançar.|  
|[is\_nothrow\_move\_constructible](../standard-library/is-nothrow-move-constructible-class.md)|Testa se o tipo é mover construível e o construtor de movimentação é conhecido por não lançar.|  
|[is\_nothrow\_assignable](../standard-library/is-nothrow-assignable-class.md)|Testa se o tipo é atribuível usando o tipo especificado e a atribuição é conhecida por não lançar.|  
|[is\_nothrow\_copy\_assignable](../Topic/is_nothrow_copy_assignable%20Class.md)|Testa se o tipo é atribuível de cópia e a atribuição é conhecida por não lançar.|  
|[is\_nothrow\_move\_assignable](../standard-library/is-nothrow-move-assignable-class.md)|Testa se o tipo é atribuível de movimentação e a atribuição é conhecida por não lançar.|  
|[is\_nothrow\_destructible](../standard-library/is-nothrow-destructible-class.md)|Testa se o tipo é destructible e o destruidor é conhecido por não lançar.|  
|[has\_virtual\_destructor](http://msdn.microsoft.com/pt-br/c0f85f0b-c63c-410d-a046-72eeaf44f7eb)|Testa se o tipo tem um destruidor virtual.|  
  
 Consultas de propriedade de tipo  
  
|||  
|-|-|  
|[alignment\_of](../standard-library/alignment-of-class.md)|Obtém o alinhamento de um tipo.|  
|[rank](../Topic/rank%20Class.md)|Obtém o número de dimensões da matriz.|  
|[extent](../standard-library/extent-class.md)|Obtém o número de elementos na dimensão de matriz especificada.|  
  
 Relações de tipo  
  
|||  
|-|-|  
|[is\_same](../standard-library/is-same-class.md)|Testa se dois tipos são os mesmos.|  
|[is\_base\_of](../standard-library/is-base-of-class.md)|Testa se um tipo é uma base de outro.|  
|[is\_convertible](../standard-library/is-convertible-class.md)|Testa se um tipo é convertido em outro.|  
  
 Modificações de const volátil  
  
|||  
|-|-|  
|[add\_const](../Topic/add_const%20Class.md)|Produz um `const` tipo do tipo.|  
|[add\_volatile](../standard-library/add-volatile-class.md)|Produz um `volatile` tipo do tipo.|  
|[add\_cv](../standard-library/add-cv-class.md)|Produz um `const``volatile` tipo do tipo.|  
|[remove\_const](../standard-library/remove-const-class.md)|Produz um tipo não const do tipo.|  
|[remove\_volatile](../Topic/remove_volatile%20Class.md)|Produz um tipo não volátil do tipo.|  
|[remove\_cv](../standard-library/remove-cv-class.md)|Produz um tipo de não\-volátil não const do tipo.|  
  
 Modificações de referência  
  
|||  
|-|-|  
|[add\_lvalue\_reference](../standard-library/add-lvalue-reference-class.md)|Produz uma referência ao tipo do tipo.|  
|[add\_rvalue\_reference](../standard-library/add-rvalue-reference-class.md)|Produz uma referência rvalue para o tipo do tipo|  
|[remove\_reference](../standard-library/remove-reference-class.md)|Produz um tipo de não referência do tipo.|  
  
 Modificações de sinal  
  
|||  
|-|-|  
|[make\_signed](../standard-library/make-signed-class.md)|Gera o tipo se conectado, ou o menor tipo com sinal maior que ou igual em tamanho para o tipo.|  
|[make\_unsigned](../standard-library/make-unsigned-class.md)|Gera o tipo se não assinado ou o menor tipo sem sinal maior que ou igual em tamanho para o tipo.|  
  
 Modificações de matriz  
  
|||  
|-|-|  
|[remove\_all\_extents](../standard-library/remove-all-extents-class.md)|Produz um tipo não\-matriz de um tipo de matriz.|  
|[remove\_extent](../standard-library/remove-extent-class.md)|Gera o tipo de elemento de um tipo de matriz.|  
  
 Modificações de ponteiro  
  
|||  
|-|-|  
|[add\_pointer](../standard-library/add-pointer-class.md)|Produz um ponteiro para o tipo do tipo.|  
|[remove\_pointer](../Topic/remove_pointer%20Class.md)|Produz um tipo de um ponteiro para o tipo.|  
  
 Outras transformações  
  
|||  
|-|-|  
|[aligned\_storage](../standard-library/aligned-storage-class.md)|Aloca memória não inicializada para um tipo alinhado.|  
|[aligned\_union](../Topic/aligned_union%20Class.md)|Aloca memória não inicializada para uma união alinhada com um construtor não triviais ou um destruidor.|  
|[common\_type](../standard-library/common-type-class.md)|Produz o tipo comum de todos os tipos de pacote de parâmetros.|  
|[conditional](../standard-library/conditional-class.md)|Se a condição for verdadeira, produz o primeiro tipo especificado, caso contrário, o segundo tipo especificado.|  
|[decay](../standard-library/decay-class.md)|Produz o tipo como passado por valor. Cria o tipo de não referência, não const ou não\-volátil ou cria um ponteiro para o tipo.|  
|[enable\_if](../Topic/enable_if%20Class.md)|Não se a condição for verdadeira, produz o tipo especificado, caso contrário, nenhum tipo.|  
|[result\_of](../standard-library/result-of-class1.md)|Determina o tipo de retorno do tipo callable que usa os tipos de argumento especificado.|  
|[underlying\_type](../standard-library/underlying-type-class.md)|Produz o tipo integral subjacente para um tipo de enumeração.|  
  
## Consulte também  
 [\<functional\>](../standard-library/functional.md)