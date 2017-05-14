---
title: Classe forward_list | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- forward_list
- forward_list/std::forward_list
- forward_list/std::forward_list::allocator_type
- forward_list/std::forward_list::const_iterator
- forward_list/std::forward_list::const_pointer
- forward_list/std::forward_list::const_reference
- forward_list/std::forward_list::difference_type
- forward_list/std::forward_list::iterator
- forward_list/std::forward_list::pointer
- forward_list/std::forward_list::reference
- forward_list/std::forward_list::size_type
- forward_list/std::forward_list::value_type
- forward_list/std::forward_list::assign
- forward_list/std::forward_list::before_begin
- forward_list/std::forward_list::begin
- forward_list/std::forward_list::cbefore_begin
- forward_list/std::forward_list::cbegin
- forward_list/std::forward_list::cend
- forward_list/std::forward_list::clear
- forward_list/std::forward_list::emplace_after
- forward_list/std::forward_list::emplace_front
- forward_list/std::forward_list::empty
- forward_list/std::forward_list::end
- forward_list/std::forward_list::erase_after
- forward_list/std::forward_list::front
- forward_list/std::forward_list::get_allocator
- forward_list/std::forward_list::insert_after
- forward_list/std::forward_list::max_size
- forward_list/std::forward_list::merge
- forward_list/std::forward_list::pop_front
- forward_list/std::forward_list::push_front
- forward_list/std::forward_list::remove
- forward_list/std::forward_list::remove_if
- forward_list/std::forward_list::resize
- forward_list/std::forward_list::reverse
- forward_list/std::forward_list::sort
- forward_list/std::forward_list::splice_after
- forward_list/std::forward_list::swap
- forward_list/std::forward_list::unique
dev_langs:
- C++
helpviewer_keywords:
- forward_list class
ms.assetid: 89a3b805-ab60-4858-b772-5855130c11b1
caps.latest.revision: 25
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 66798adc96121837b4ac2dd238b9887d3c5b7eef
ms.openlocfilehash: cde111871667e754f629fd69562a6aa4aeb07b94
ms.contentlocale: pt-br
ms.lasthandoff: 04/29/2017

---
# <a name="forwardlist-class"></a>Classe forward_list
Descreve um objeto que controla uma sequência de elementos de tamanho variado. A sequência é armazenada como uma lista de nós vinculada exclusivamente, com cada um contendo um membro do tipo `Type`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Type,   
    class Allocator = allocator<Type>>  
class forward_list   
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`Type`|O tipo de dados do elemento a ser armazenado na forward_list.|  
|`Allocator`|O objeto alocador armazenado que encapsula detalhes sobre a alocação e desalocação de memória na forward_list. Esse parâmetro é opcional. O valor padrão é allocator< `Type`>.|  
  
## <a name="remarks"></a>Comentários  
 O objeto `forward_list` aloca e libera armazenamento para a sequência que controla por meio de um objeto armazenado da classe `Allocator` que é baseado na [Classe allocator](../standard-library/allocator-class.md) (normalmente conhecido como `std::allocator)`. Para obter mais informações, consulte o [Alocadores](../standard-library/allocators.md). Um objeto alocador deve ter a mesma interface externa que um objeto da classe de modelo `allocator`.  
  
> [!NOTE]
>  O objeto alocador armazenado não é copiado quando o objeto de contêiner é atribuído.  
  
 Iteradores, ponteiros e referências podem se tornar inválidos quando elementos de sua sequência são apagados por meio de `forward_list`. Inserções e uniões executadas na sequência controlada por meio de `forward_list` não invalidam iteradores.  
  
 Adições à sequência controlada podem ocorrer por chamadas para [forward_list::insert_after](#insert_after), que é a única função membro que chama o construtor `Type(const  T&)`. `forward_list` também pode chamar construtores de movimento. Se a expressão gerar uma exceção, o objeto de contêiner não insere novos elementos e gera a exceção novamente. Portanto, um objeto da classe de modelo `forward_list` é deixado em um estado conhecido quando essas exceções ocorrem.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[forward_list](#forward_list)|Constrói um objeto do tipo `forward_list`.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[allocator_type](#allocator_type)|Um tipo que representa a classe de alocador para um objeto de lista de encaminhamento.|  
|[const_iterator](#const_iterator)|Um tipo que fornece um iterador constante para a lista de encaminhamento.|  
|[const_pointer](#const_pointer)|Um tipo que fornece um ponteiro para um elemento `const` em uma lista de encaminhamento.|  
|[const_reference](#const_reference)|Um tipo que fornece uma referência constante a um elemento na lista de encaminhamento.|  
|[difference_type](#difference_type)|Um tipo de inteiro com sinal que pode ser usado para representar o número de elementos de uma lista de encaminhamento em um intervalo entre os elementos apontados por iteradores.|  
|[iterator](#iterator)|Um tipo que fornece um iterador para a lista de encaminhamento.|  
|[pointer](#pointer)|Um tipo que fornece um ponteiro para um elemento na lista de encaminhamento.|  
|[reference](#reference)|Um tipo que fornece uma referência para um elemento na lista de encaminhamento.|  
|[size_type](#size_type)|Um tipo que representa a distância sem sinal entre dois elementos.|  
|[value_type](#value_type)|Um tipo que representa o tipo de elemento armazenado em uma lista de encaminhamento.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[assign](#assign)|Apaga elementos de uma lista de encaminhamento e copia um novo conjunto de elementos para uma lista de encaminhamento de destino.|  
|[before_begin](#before_begin)|Retorna um iterador que trata da posição antes do primeiro elemento em uma lista de encaminhamento.|  
|[begin](#begin)|Retorna um iterador que trata do primeiro elemento em uma lista de encaminhamento.|  
|[cbefore_begin](#cbefore_begin)|Retorna um iterador const que trata da posição antes do primeiro elemento em uma lista de encaminhamento.|  
|[cbegin](#cbegin)|Retorna um iterador const que trata do primeiro elemento em uma lista de encaminhamento.|  
|[cend](#cend)|Retorna um iterador const que trata do local após o último elemento em uma lista de encaminhamento.|  
|[clear](#clear)|Apaga todos os elementos de uma lista de encaminhamento.|  
|[emplace_after](#emplace_after)|Move constructos de um novo elemento após uma posição especificada.|  
|[emplace_front](#emplace_front)|Adiciona um elemento construído no local ao início da lista.|  
|[empty](#empty)|Testa se uma lista de encaminhamento está vazia.|  
|[end](#end)|Retorna um iterador que trata do local após o último elemento em uma lista de encaminhamento.|  
|[erase_after](#erase_after)|Remove elementos da lista de encaminhamento depois de uma posição especificada.|  
|[front](#front)|Retorna uma referência ao primeiro elemento em uma lista de encaminhamento.|  
|[get_allocator](#get_allocator)|Retorna uma cópia do objeto alocador usado para construir uma lista de encaminhamento.|  
|[insert_after](#insert_after)|Adiciona elementos à lista de encaminhamento depois de uma posição especificada.|  
|[max_size](#max_size)|Retorna o tamanho máximo de uma lista de encaminhamento.|  
|[merge](#merge)|Remove os elementos da lista de argumentos, insere-os na lista de encaminhamento de destino e ordena o conjunto novo conjunto combinado de elementos em ordem crescente ou em alguma outra ordem especificada.|  
|[pop_front](#pop_front)|Exclui o elemento no início de uma lista de encaminhamento.|  
|[push_front](#push_front)|Adiciona um elemento as início de uma lista de encaminhamento.|  
|[remove](#remove)|Apaga elementos em uma lista de encaminhamento que correspondem a um valor especificado.|  
|[remove_if](#remove_if)|Apaga os elementos da lista de encaminhamento para os quais um predicado especificado foi atendido.|  
|[resize](#resize)|Especifica um novo tamanho para uma lista de encaminhamento.|  
|[reverse](#reverse)|Reverte a ordem na qual os elementos ocorrem em uma lista de encaminhamento.|  
|[sort](#sort)|Organiza os elementos em ordem crescente ou em uma ordem especificada por um predicado.|  
|[splice_after](#splice_after)|Costura novamente links entre os nós.|  
|[swap](#swap)|Troca os elementos de duas listas de encaminhamento.|  
|[unique](#unique)|Remove elementos adjacentes que são passados a um teste especificado.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operator=](#op_eq)|Substitui os elementos da lista de encaminhamento por uma cópia de outra lista de encaminhamento.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<forward_list>  
  
 **Namespace:** std  
  
##  <a name="allocator_type"></a>  forward_list::allocator_type  
 Um tipo que representa a classe de alocador para um objeto de lista de encaminhamento.  
  
```  
typedef Allocator allocator_type;  
```  
  
### <a name="remarks"></a>Comentários  
 `allocator_type` é um sinônimo do parâmetro de modelo Allocator.  
  
##  <a name="assign"></a>  forward_list::assign  
 Apaga elementos de uma lista de encaminhamento e copia um novo conjunto de elementos para uma lista de encaminhamento de destino.  
  
```  
void assign(
    size_type Count,   
    const Type& Val);

void assign(
    initializer_list<Type> IList);

template <class InputIterator>  
void assign(InputIterator First, InputIterator Last);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`first`|O início do intervalo de substituição.|  
|`last`|O final do intervalo de substituição.|  
|`count`|O número de elementos a serem atribuídos.|  
|`val`|O valor a atribuir a cada elemento.|  
|`Type`|Tipo do valor.|  
|`IList`|A initializer_list a ser copiada.|  
  
### <a name="remarks"></a>Comentários  
 Se a forward_list for um tipo inteiro, a primeira função membro se comportará como `assign((size_type)First, (Type)Last)`. Caso contrário, a primeira função membro substitui a sequência controlada por `*this` pela sequência [`First, Last)`, que não deve se sobrepor à sequência controlada inicial.  
  
 A segunda função membro substitui a sequência controlada por `*this` por uma repetição de elementos `Count` de valor `Val`.  
  
 A terceira função membro copia os elementos de initializer_list para forward_list.  
  
##  <a name="before_begin"></a>  forward_list::before_begin  
 Retorna um iterador que trata da posição antes do primeiro elemento em uma lista de encaminhamento.  
  
```  
const_iterator before_begin() const;
iterator before_begin();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de encaminhamento que aponta para o primeiro elemento da sequência (ou imediatamente antes do fim de uma sequência vazia).  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="begin"></a>  forward_list::begin  
 Retorna um iterador que trata do primeiro elemento em uma lista de encaminhamento.  
  
```  
const_iterator begin() const;
iterator begin();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de encaminhamento que aponta para o primeiro elemento da sequência (ou imediatamente após o fim de uma sequência vazia).  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="cbefore_begin"></a>  forward_list::cbefore_begin  
 Retorna um iterador const que trata da posição antes do primeiro elemento em uma lista de encaminhamento.  
  
```  
const_iterator cbefore_begin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de encaminhamento que aponta para o primeiro elemento da sequência (ou imediatamente antes do fim de uma sequência vazia).  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="cbegin"></a>  forward_list::cbegin  
 Retorna um iterador `const` que trata o primeiro elemento no intervalo.  
  
```  
const_iterator cbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso por avanço `const` que aponta o primeiro elemento do intervalo ou o local logo após o fim de um intervalo vazio (para um intervalo vazio, `cbegin() == cend()`).  
  
### <a name="remarks"></a>Comentários  
 Com o valor de retorno `cbegin`, os elementos do intervalo não podem ser modificados.  
  
 Você pode usar essa função membro no lugar da função membro `begin()`, de modo a garantir que o valor de retorno seja `const_iterator`. Normalmente, é usada juntamente com a palavra-chave de dedução de tipo [auto](../cpp/auto-cpp.md), conforme mostrado no exemplo a seguir. No exemplo, considere `Container` como um contêiner modificável (não `const`) de qualquer tipo, que dá suporte para `begin()` e `cbegin()`.  
  
```cpp  
auto i1 = Container.begin();
// i1 is Container<T>::iterator   
auto i2 = Container.cbegin();
// i2 is Container<T>::const_iterator  
```  
  
##  <a name="cend"></a>  forward_list::cend  
 Retorna um iterador `const` que trata o local logo após o último elemento em um intervalo.  
  
```  
const_iterator cend() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso por avanço que aponta para além do fim do intervalo.  
  
### <a name="remarks"></a>Comentários  
 `cend` é usado para testar se um iterador passou do fim de seu intervalo.  
  
 Você pode usar essa função membro no lugar da função membro `end()`, de modo a garantir que o valor de retorno seja `const_iterator`. Normalmente, é usada juntamente com a palavra-chave de dedução de tipo [auto](../cpp/auto-cpp.md), conforme mostrado no exemplo a seguir. No exemplo, considere `Container` como um contêiner modificável (não `const`) de qualquer tipo, que dá suporte para `end()` e `cend()`.  
  
```cpp  
auto i1 = Container.end();
// i1 is Container<T>::iterator   
auto i2 = Container.cend();

// i2 is Container<T>::const_iterator  
```  
  
 O valor retornado por `cend` não deve ser desreferenciado.  
  
##  <a name="clear"></a>  forward_list::clear  
 Apaga todos os elementos de uma lista de encaminhamento.  
  
```  
void clear();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função membro chama `erase_after(before_begin(), end()).`  
  
##  <a name="const_iterator"></a>  forward_list::const_iterator  
 Um tipo que fornece um iterador constante para a lista de encaminhamento.  
  
```  
typedef implementation-defined const_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 `const_iterator` descreve um objeto que pode servir como um iterador de encaminhamento constante para a sequência controlada. Ele é descrito aqui como sinônimo de um tipo definido pela implementação.  
  
##  <a name="const_pointer"></a>  forward_list::const_pointer  
 Um tipo que fornece um ponteiro para um elemento `const` em uma lista de encaminhamento.  
  
```  
typedef typename Allocator::const_pointer  
    const_pointer; 
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="const_reference"></a>  forward_list::const_reference  
 Um tipo que fornece uma referência constante a um elemento na lista de encaminhamento.  
  
```  
typedef typename Allocator::const_reference const_reference;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="difference_type"></a>  forward_list::difference_type  
 Um tipo de inteiro com sinal que pode ser usado para representar o número de elementos de uma lista de encaminhamento em um intervalo entre os elementos apontados por iteradores.  
  
```  
typedef typename Allocator::difference_type difference_type;  
```  
  
### <a name="remarks"></a>Comentários  
 `difference_type` descreve um objeto que pode representar a diferença entre os endereços de dois elementos na sequência controlada.  
  
##  <a name="emplace_after"></a>  forward_list::emplace_after  
 Move constructos de um novo elemento após uma posição especificada.  
  
```  
template <class T>  
iterator emplace_after(const_iterator Where, Type&& val);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`Where`|A posição na lista de encaminhamento de destino em que o novo elemento é criado.|  
|`val`|O argumento do construtor.|  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador que designa o elemento recém-inserido.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro insere um elemento com os argumentos de construtor `val` logo após o elemento apontado por `Where` na sequência controlada. Seu comportamento é, nos outros aspectos, o mesmo que [forward_list::insert_after](#insert_after).  
  
##  <a name="emplace_front"></a>  forward_list::emplace_front  
 Adiciona um elemento construído no local ao início da lista.  
  
```  
template <class Type>  
void emplace_front(Type&& val);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`val`|O elemento adicionado ao início da lista de encaminhamento.|  
  
### <a name="remarks"></a>Comentários  
 Essa função membro insere um elemento com os argumentos de construtor `_ val` após o final da sequência controlada.  
  
 Se uma exceção for gerada, o contêiner permanecerá inalterado e a exceção será gerada novamente.  
  
##  <a name="empty"></a>  forward_list::empty  
 Testa se uma lista de encaminhamento está vazia.  
  
```  
bool empty() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se a lista de encaminhamento estiver vazia; caso contrário, `false`.  
  
##  <a name="end"></a>  forward_list::end  
 Retorna um iterador que trata do local após o último elemento em uma lista de encaminhamento.  
  
```  
const_iterator end() const;
iterator end();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de encaminhamento que aponta para logo após o fim da sequência.  
  
##  <a name="erase_after"></a>  forward_list::erase_after  
 Remove elementos da lista de encaminhamento depois de uma posição especificada.  
  
```  
iterator erase_after(const_iterator Where);
iterator erase_after(const_iterator first, const_iterator last);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`Where`|A posição na lista de encaminhamento de destino em que o novo elemento é apagado.|  
|`first`|O início do intervalo a ser apagado.|  
|`last`|O final do intervalo a ser apagado.|  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador que designa o primeiro elemento restante além de todos os elementos removidos ou [forward_list::end](#end) se esse elemento não existir.  
  
### <a name="remarks"></a>Comentários  
 A primeira função membro remove o elemento da sequência controlada logo após `Where`.  
  
 A segunda função membro remove os elementos da sequência controlada no intervalo `( first,  last)` (nenhum ponto de extremidade está incluído).  
  
 Apagar elementos `N` causas chamadas de destruidor de `N`. A [realocação](../standard-library/forward-list-class.md) ocorre, de modo que referências e iteradores tornam-se inválidos para os elementos apagados.  
  
 As funções membro nunca geram uma exceção.  
  
##  <a name="forward_list"></a>  forward_list::forward_list  
 Constrói um objeto do tipo `forward_list`.  
  
```  
forward_list();
explicit forward_list(const Allocator& Al);
explicit forward_list(size_type Count);
forward_list(size_type Count, const Type& Val);
forward_list(size_type Count, const Type& Val, const Allocator& Al);
forward_list(const forward_list& Right);
forward_list(const forward_list& Right, const Allocator& Al);
forward_list(forward_list&& Right);
forward_list(forward_list&& Right, const Allocator& Al);
forward_list(initializer_list<Type> IList, const Alloc& Al);
template <class InputIterator>  
forward_list(InputIterator First, InputIterator Last);
template <class InputIterator>  
forward_list(InputIterator First, InputIterator Last, const Allocator& Al);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`Al`|A classe de alocador a ser usada com esse objeto.|  
|`Count`|O número de elementos na lista construída.|  
|`Val`|O valor dos elementos na lista construída.|  
|`Right`|A lista da qual a lista construída é uma cópia.|  
|`First`|A posição do primeiro elemento no intervalo de elementos a serem copiados.|  
|`Last`|A posição do primeiro elemento além do intervalo de elementos a serem copiados.|  
|`IList`|A initializer_list a ser copiada.|  
  
### <a name="remarks"></a>Comentários  
 Todos os construtores armazenam um [alocador](../standard-library/allocator-class.md) e inicializam a sequência controlada. O objeto alocador será o argumento `Al`, se estiver presente. Para o construtor de cópia, ele será ` right.get_allocator()`. Caso contrário, será `Allocator()`.  
  
 Os primeiros dois construtores especificam uma sequência controlada inicial vazia.  
  
 O terceiro construtor especifica uma repetição de elementos `Count` de valor `Type()`.  
  
 O quarto e o quinto construtor especificam uma repetição de elementos `Count` de valor `Val`.  
  
 O sexto construtor especifica uma cópia da sequência controlada por `Right`. Se `InputIterator` for um tipo inteiro, os dois construtores seguintes especificam uma repetição de elementos `(size_type)First` de valor `(Type)Last`. Caso contrário, os dois construtores seguintes especificam a sequência `[First, Last)`.  
  
 O nono e o décimo construtor são os mesmos que o sexto, mas com uma referência de [rvalue](../cpp/rvalue-reference-declarator-amp-amp.md).  
  
 O último construtor especifica a sequência controlada inicial com um objeto da classe `initializer_list<Type>`.  
  
##  <a name="front"></a>  forward_list::front  
 Retorna uma referência ao primeiro elemento em uma lista de encaminhamento.  
  
```  
reference front();
const_reference front() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao primeiro elemento da sequência controlada, que não pode ser vazio.  
  
##  <a name="get_allocator"></a>  forward_list::get_allocator  
 Retorna uma cópia do objeto alocador usado para construir uma lista de encaminhamento.  
  
```  
allocator_type get_allocator() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O objeto [allocator](../standard-library/allocator-class.md) armazenado.  
  
##  <a name="insert_after"></a>  forward_list::insert_after  
 Adiciona elementos à lista de encaminhamento depois de uma posição especificada.  
  
```  
iterator insert_after(const_iterator Where, const Type& Val);
void insert_after(const_iterator Where, size_type Count, const Type& Val);
void insert_after(const iterator Where, initializer_list<Type> IList);
iterator insert_after(const_iterator Where, Type&& Val);
template <class InputIterator>  
void insert_after(const_iterator Where, InputIterator First, InputIterator Last);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`Where`|A posição na lista de encaminhamento de destino em que o primeiro elemento é inserido.|  
|`Count`|O número de elementos a serem inseridos.|  
|`First`|O início do intervalo de inserção.|  
|`Last`|O final do intervalo de inserção.|  
|`Val`|O elemento adicionado à lista de encaminhamento.|  
|`IList`|A initializer_list a ser inserida.|  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador que designa o elemento recém-inserido (apenas a primeira e a última função membro).  
  
### <a name="remarks"></a>Comentários  
 Cada uma das funções membro insere — logo após o elemento apontado por `Where` na sequência controlada — uma sequência especificada pelos operandos de restantes.  
  
 A primeira função membro insere um elemento que tem o valor `Val` e retorna um iterador que designa o elemento recém-inserido.  
  
 A segunda função membro insere uma repetição de elementos `Count` de valor `Val`.  
  
 Se `InputIterator` for um tipo inteiro, a terceira função membro se comportará da mesma forma que `insert(it, (size_type)First, (Type)Last)`. Caso contrário, inserirá a sequência `[First, Last)`, que não pode se sobrepor à sequência controlada inicial.  
  
 A quarta função membro insere a sequência especificada por um objeto da classe `initializer_list<Type>`.  
  
 A última operação membro é a mesma que a primeira, mas com uma referência de [rvalue](../cpp/rvalue-reference-declarator-amp-amp.md).  
  
 Inserir elementos `N` causa chamadas de construtor de `N`. A [realocação](../standard-library/forward-list-class.md) ocorre, mas nenhum iterador ou referência se torna inválida.  
  
 Se uma exceção for gerada durante a inserção de um ou mais elementos, o contêiner permanecerá inalterado e a exceção será gerada novamente.  
  
##  <a name="iterator"></a>  forward_list::iterator  
 Um tipo que fornece um iterador para a lista de encaminhamento.  
  
```  
typedef implementation-defined iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 `iterator` descreve um objeto que pode servir como um iterador de encaminhamento para a sequência controlada. Ele é descrito aqui como sinônimo de um tipo definido pela implementação.  
  
##  <a name="max_size"></a>  forward_list::max_size  
 Retorna o tamanho máximo de uma lista de encaminhamento.  
  
```  
size_type max_size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho da sequência mais longa que o objeto pode controlar.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="merge"></a>  forward_list::merge  
 Combina duas sequências classificadas em uma única sequência classificada em tempo linear. Remove os elementos da lista de argumentos e os insere neste `forward_list`. As duas listas devem ser classificadas pelo objeto de função de comparação antes da chamada para `merge`. A lista combinada será classificada pelo objeto de função de comparação.  
  
```  
void merge(forward_list& right);
template <class Predicate>  
void merge(forward_list& right, Predicate comp);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`right`|A lista de encaminhamento a ser mesclada.|  
|`comp`|O objeto de função compare que é usado para classificar elementos.|  
  
### <a name="remarks"></a>Comentários  
 `forward_list::merge` remove os elementos de `forward_list``right``,` e os insere neste `forward_list`. As duas sequências devem ser ordenadas pelo mesmo predicado, descrito abaixo. A sequência combinada também é ordenada por esse objeto de função de comparação.  
  
 Para os iteradores `Pi` e `Pj` que designam elementos nas posições `i` e `j`, a primeira função membro impõe a ordem `!(*Pj < *Pi)` sempre que `i < j`. (Os elementos são classificados na ordem `ascending`.) A segunda função membro impõe a ordem `! comp(*Pj, *Pi)` sempre que `i < j`.  
  
 Nenhum par de elementos na sequência controlada original é revertido na sequência controlada resultante. Se um par de elementos na sequência controlada resultante for igual a (`!(*Pi < *Pj) && !(*Pj < *Pi)`), um elemento da sequência controlada original aparecerá antes de um elemento da sequência controlada por `right`.  
  
 Uma exceção ocorre somente se `comp` gerar uma exceção. Nesse caso, a sequência controlada será deixada em uma ordem não especificada e a exceção será gerada novamente.  
  
##  <a name="op_eq"></a>  forward_list::operator=  
 Substitui os elementos da lista de encaminhamento por uma cópia de outra lista de encaminhamento.  
  
```  
forward_list& operator=(const forward_list& right);
forward_list& operator=(initializer_list<Type> IList);
forward_list& operator=(forward_list&& right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`right`|A lista de encaminhamento que está sendo copiada para a lista de encaminhamento.|  
|`IList`|Uma lista de inicializadores entre chaves, que se comporta exatamente como uma sequência de elementos do tipo `Type`.|  
  
### <a name="remarks"></a>Comentários  
 O primeiro operador de membro substitui a sequência controlada por uma cópia da sequência controlada por `right`.  
  
 O segundo operador membro substitui a sequência controlada de um objeto da classe `initializer_list<Type>`.  
  
 O terceiro operador membro é o mesmo que a primeiro, mas com uma referência de [rvalue](../cpp/rvalue-reference-declarator-amp-amp.md).  
  
##  <a name="pointer"></a>  forward_list::pointer  
 Um tipo que fornece um ponteiro para um elemento na lista de encaminhamento.  
  
```  
typedef typename Allocator::pointer pointer;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="pop_front"></a>  forward_list::pop_front  
 Exclui o elemento no início de uma lista de encaminhamento.  
  
```  
void pop_front();
```  
  
### <a name="remarks"></a>Comentários  
 O primeiro elemento da lista de encaminhamento não pode ser vazio.  
  
 A função membro nunca gera uma exceção.  
  
##  <a name="push_front"></a>  forward_list::push_front  
 Adiciona um elemento as início de uma lista de encaminhamento.  
  
```  
void push_front(const Type& val);
void push_front(Type&& val);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`val`|O elemento adicionado ao início da lista de encaminhamento.|  
  
### <a name="remarks"></a>Comentários  
 Se uma exceção for gerada, o contêiner permanecerá inalterado e a exceção será gerada novamente.  
  
##  <a name="reference"></a>  forward_list::reference  
 Um tipo que fornece uma referência para um elemento na lista de encaminhamento.  
  
```  
typedef typename Allocator::reference reference;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="remove"></a>  forward_list::remove  
 Apaga elementos em uma lista de encaminhamento que correspondem a um valor especificado.  
  
```  
void remove(const Type& val);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`val`|O valor que, se mantido por um elemento, resultará na remoção de tal elemento da lista.|  
  
### <a name="remarks"></a>Comentários  
 A função membro remove da sequência controlada todos os elementos, designados pelo iterador `P`, para os quais `*P ==  val`.  
  
 A função membro nunca gera uma exceção.  
  
##  <a name="remove_if"></a>  forward_list::remove_if  
 Apaga os elementos da lista de encaminhamento para os quais um predicado especificado foi atendido.  
  
```  
template <class Predicate>  
void remove_if(Predicate pred);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`pred`|O predicado unário que, se atendido por um elemento, resultará na exclusão de tal elemento da lista.|  
  
### <a name="remarks"></a>Comentários  
 A função membro remove da sequência controlada todos os elementos designados pelo iterador `P` para os quais ` pred(*P)` é verdadeiro.  
  
 Uma exceção ocorre somente se `pred` gerar uma exceção. Nesse caso, a sequência controlada é deixada em um estado não especificado e a exceção é gerada novamente.  
  
##  <a name="resize"></a>  forward_list::resize  
 Especifica um novo tamanho para uma lista de encaminhamento.  
  
```  
void resize(size_type _Newsize);
void resize(size_type _Newsize, const Type& val);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`_Newsize`|O número de elementos na lista de encaminhamento redimensionada.|  
|`val`|O valor a ser usado para preenchimento.|  
  
### <a name="remarks"></a>Comentários  
 As funções membro garantem que o número de elementos na lista daqui por diante seja `_Newsize`. Se for necessário tornar a sequência controlada mais longa, a primeira função membro acrescentará elementos com valor `Type()`, enquanto a segunda função membro acrescentará elementos com valor `val`. Para tornar a sequência controlada mais curta, as duas funções membro efetivamente chamam `erase_after(begin() + _Newsize - 1, end())`.  
  
##  <a name="reverse"></a>  forward_list::reverse  
 Reverte a ordem na qual os elementos ocorrem em uma lista de encaminhamento.  
  
```  
void reverse();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="size_type"></a>  forward_list::size_type  
 Um tipo que representa a distância sem sinal entre dois elementos.  
  
```  
typedef typename Allocator::size_type size_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo inteiro sem sinal descreve um objeto que pode representar o tamanho de qualquer sequência controlada.  
  
##  <a name="sort"></a>  forward_list::sort  
 Organiza os elementos em ordem crescente ou em uma ordem especificada por um predicado.  
  
```  
void sort();
template <class Predicate>  
void sort(Predicate pred);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`pred`|O predicado de ordenação.|  
  
### <a name="remarks"></a>Comentários  
 As duas funções membro ordenam os elementos na sequência controlada por um predicado, descrito abaixo.  
  
 Para os iteradores `Pi` e `Pj` que designam elementos nas posições `i` e `j`, a primeira função membro impõe a ordem `!(*Pj < *Pi)` sempre que `i < j`. (Os elementos são classificados na ordem `ascending`.) A função modelo membro impõe a ordem `! pred(*Pj, *Pi)` sempre que `i < j`. Nenhum par ordenado de elementos na sequência controlada original é revertido na sequência controlada resultante. (A classificação é estável).  
  
 Uma exceção ocorre somente se `pred` gerar uma exceção. Nesse caso, a sequência controlada será deixada em uma ordem não especificada e a exceção será gerada novamente.  
  
##  <a name="splice_after"></a>  forward_list::splice_after  
 Remove elementos de uma forward_list de origem e os insere em uma forward_list de destino.  
  
```  
// insert the entire source forward_list  
void splice_after(const_iterator Where, forward_list& Source);
void splice_after(const_iterator Where, forward_list&& Source);

// insert one element of the source forward_list  
void splice_after(const_iterator Where, forward_list& Source, const_iterator Iter);
void splice_after(const_iterator Where, forward_list&& Source, const_iterator Iter);

// insert a range of elements from the source forward_list  
void splice_after(
    const_iterator Where, 
    forward_list& Source,
    const_iterator First,
    const_iterator Last);

void splice_after(
    const_iterator Where,
    forward_list&& Source,
    const_iterator First,
    const_iterator Last);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Where`  
 A posição na forward_list de destino após a qual o elemento deve ser inserido.  
  
 `Source`  
 A forward_list de origem que deve ser inserida na forward_list de destino.  
  
 `Iter`  
 O elemento a ser inserido da forward_list de origem.  
  
 `First`  
 O primeiro elemento no intervalo a ser inserido da forward_list de origem.  
  
 `Last`  
 A primeira posição além do intervalo a ser inserida da forward_list de origem.  
  
### <a name="remarks"></a>Comentários  
 O primeiro par de funções de membro insere a sequência controlada por `Source` após o elemento na sequência controlada apontada por `Where`. Também remove elementos de `Source`. (`&Source` não deve ser igual a `this`.)  
  
 O segundo par de funções de membro remove o elemento imediatamente após `Iter` na sequência controlada por `Source` e o insere imediatamente após o elemento na sequência controlada apontada por `Where`. (Se `Where == Iter || Where == ++Iter`, nenhuma alteração ocorrerá.)  
  
 O terceiro par de funções de membro (união com intervalos) insere o subintervalo designado por `(First, Last)` da sequência controlada por `Source` imediatamente após o elemento na sequência controlada apontada por `Where`. Ele também remove o subintervalo original da sequência controlada por `Source`. (Se `&Source == this`, o intervalo `(First, Last)` não deve incluir o elemento apontado por `Where`.)  
  
 Se a união no intervalo inserir elementos `N` e `&Source != this`, um objeto da classe [iterator](#iterator) será incrementado `N` vezes.  
  
 Nenhum iterador, ponteiro ou referência que designa elementos unidos se torna inválido.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// forward_list_splice_after.cpp  
// compile with: /EHsc /W4  
#include <forward_list>  
#include <iostream>  
  
using namespace std;  
  
template <typename S> void print(const S& s) {  
    for (const auto& p : s) {  
        cout << "(" << p << ") ";  
    }  
  
    cout << endl;  
}  
  
int main()  
{  
    forward_list<int> c1{ 10, 11 };  
    forward_list<int> c2{ 20, 21, 22 };  
    forward_list<int> c3{ 30, 31 };  
    forward_list<int> c4{ 40, 41, 42, 43 };  
  
    forward_list<int>::iterator where_iter;  
    forward_list<int>::iterator first_iter;  
    forward_list<int>::iterator last_iter;  
  
    cout << "Beginning state of lists:" << endl;  
    cout << "c1 = ";  
    print(c1);  
    cout << "c2 = ";  
    print(c2);  
    cout << "c3 = ";  
    print(c3);  
    cout << "c4 = ";  
    print(c4);  
  
    where_iter = c2.begin();  
    ++where_iter; // start at second element  
    c2.splice_after(where_iter, c1);  
    cout << "After splicing c1 into c2:" << endl;  
    cout << "c1 = ";  
    print(c1);  
    cout << "c2 = ";  
    print(c2);  
  
    first_iter = c3.begin();  
    c2.splice_after(where_iter, c3, first_iter);  
    cout << "After splicing the first element of c3 into c2:" << endl;  
    cout << "c3 = ";  
    print(c3);  
    cout << "c2 = ";  
    print(c2);  
  
    first_iter = c4.begin();  
    last_iter = c4.end();  
    // set up to get the middle elements  
    ++first_iter;  
    c2.splice_after(where_iter, c4, first_iter, last_iter);  
    cout << "After splicing a range of c4 into c2:" << endl;  
    cout << "c4 = ";  
    print(c4);  
    cout << "c2 = ";  
    print(c2);  
}  
  
```  
  
```Output  
Beginning state of lists:c1 = (10) (11)c2 = (20) (21) (22)c3 = (30) (31)c4 = (40) (41) (42) (43)After splicing c1 into c2:c1 =c2 = (20) (21) (10) (11) (22)After splicing the first element of c3 into c2:c3 = (30)c2 = (20) (21) (31) (10) (11) (22)After splicing a range of c4 into c2:c4 = (40) (41)c2 = (20) (21) (42) (43) (31) (10) (11) (22)  
```  
  
##  <a name="swap"></a>  forward_list::swap  
 Troca os elementos de duas listas de encaminhamento.  
  
```  
void swap(forward_list& right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`right`|A lista de encaminhamento que fornece os elementos a serem trocados.|  
  
### <a name="remarks"></a>Comentários  
 A função membro troca as sequências controladas entre `*this` e `right`. Se `get_allocator() ==  right.get_allocator()`, ela faz isso em tempo constante, não gera exceções e não invalida referências, ponteiros ou iteradores que designam elementos nas duas sequências controlados. Caso contrário, executará uma série de atribuições de elemento e de chamadas do construtor proporcional ao número de elementos nas duas sequências controladas.  
  
##  <a name="unique"></a>  forward_list::unique  
 Elimina todos, exceto pelo primeiro elemento de cada grupo consecutivo de elementos iguais.  
  
```  
void unique();
template <class BinaryPredicate>  
void unique(BinaryPredicate comp);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`comp`|O predicado binário usado para comparar elementos sucessivos.|  
  
### <a name="remarks"></a>Comentários  
 Mantém o primeiro de cada elemento exclusivo e remove o restante. Os elementos devem ser classificados para que elementos do mesmo valor fiquem adjacentes na lista.  
  
 A primeira função membro remove da sequência controlada todos os elementos que, na comparação, são iguais ao elemento anterior. Para os iteradores `Pi` e `Pj` que designam elementos nas posições `i` e `j`, a segunda função membro remove todos os elementos para os quais `i + 1 == j &&  comp(*Pi, *Pj)`.  
  
 Para uma sequência controlada de tamanho `N` (> 0), o predicado ` comp(*Pi, *Pj)` é avaliado `N - 1` vezes.  
  
 Uma exceção ocorre somente se `comp` gerar uma exceção. Nesse caso, a sequência controlada é deixada em um estado não especificado e a exceção é gerada novamente.  
  
##  <a name="value_type"></a>  forward_list::value_type  
 Um tipo que representa o tipo de elemento armazenado em uma lista de encaminhamento.  
  
```  
typedef typename Allocator::value_type value_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para o parâmetro de modelo _ `Ty`.  
  
## <a name="see-also"></a>Consulte também  
 [<forward_list>](../standard-library/forward-list.md)


