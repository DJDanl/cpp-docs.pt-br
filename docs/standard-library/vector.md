---
title: "&lt;vector&gt; | Microsoft Docs"
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
  - "<vector>"
  - "std.<vector>"
  - "std::<vector>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho vector"
ms.assetid: c1431ad8-c0b6-4dbb-89c4-5f651e432d7f
caps.latest.revision: 25
caps.handback.revision: 25
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;vector&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define o vetor de classe de modelo do contêiner e vários modelos de suporte.  
  
 O `vector` é um contêiner que organiza os elementos de um determinado tipo em uma sequência linear. Ele permite acesso aleatório rapidamente a qualquer elemento e dinâmicas adições e remoções para e da sequência. O `vector` é o contêiner preferencial para uma sequência de quando o desempenho de acesso aleatório é um fator determinante.  
  
 Para obter mais informações sobre a classe `vector`, consulte [classe vector](../standard-library/vector-class.md). Para obter informações sobre a especialização `vector<bool>`, consulte [vector \< bool> classe](../Topic/vector%3Cbool%3E%20Class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
namespace std {  
template <class Type, class Allocator>  
class vector;  
template <class Allocator>  
class vector<bool>;  
 
template <class Allocator>  
struct hash<vector<bool, Allocator>>;  
 // TEMPLATE FUNCTIONS  
template <class Type, class Allocator>  
bool operator== (
    const vector<Type, Allocator>& left,  
    const vector<Type, Allocator>& right);

template <class Type, class Allocator>  
bool operator!= (
    const vector<Type, Allocator>& left,  
    const vector<Type, Allocator>& right);

template <class Type, class Allocator>  
bool operator<(
    const vector<Type, Allocator>& left,  
    const vector<Type, Allocator>& right);

template <class Type, class Allocator>  
bool operator> (
    const vector<Type, Allocator>& left,  
    const vector<Type, Allocator>& right);

template <class Type, class Allocator>  
bool operator<= (
    const vector<Type, Allocator>& left,  
    const vector<Type, Allocator>& right);

template <class Type, class Allocator>  
bool operator>= (
    const vector<Type, Allocator>& left,  
    const vector<Type, Allocator>& right);

template <class Type, class Allocator>  
void swap (
    vector<Type, Allocator>& left,  
    vector<Type, Allocator>& right);

}  // namespace std  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Tipo  
 O parâmetro de modelo para o tipo de dados armazenados no vetor.  
  
 Alocador  
 O parâmetro de modelo para o objeto de alocador armazenado responsável por desalocação e alocação de memória.  
  
 ` left`  
 O primeiro vetor (à esquerda) em uma operação de comparação  
  
 ` right`  
 O segundo vetor (à direita) em uma operação de comparação.  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operador! =](../Topic/%3Cvector%3E%20operators.md#operator_neq)|Testa se o objeto de vetor no lado esquerdo do operador não é igual ao objeto vetorial no lado direito.|  
|[operador <](../Topic/%3Cvector%3E%20operators.md#operator_lt_)|Testa se o objeto de vetor no lado esquerdo do operador é menor que o objeto de vetor no lado direito.|  
|[operador \< =](../Topic/%3Cvector%3E%20operators.md#operator_lt__eq)|Testa se o vetor de objeto no lado esquerdo do operador é menor ou igual ao objeto vetorial no lado direito.|  
|[operador = =](../Topic/%3Cvector%3E%20operators.md#operator_eq_eq)|Testa se o objeto de vetor no lado esquerdo do operador é igual ao objeto vetorial no lado direito.|  
|[operador >](../Topic/%3Cvector%3E%20operators.md#operator_gt_)|Testa se o objeto de vetor no lado esquerdo do operador é maior que o objeto de vetor no lado direito.|  
|[operador > =](../Topic/%3Cvector%3E%20operators.md#operator_gt__eq)|Testa se o objeto de vetor no lado esquerdo do operador é maior que ou igual ao objeto vetorial no lado direito.|  
  
### <a name="classes"></a>Classes  
  
|||  
|-|-|  
|[Classe Vector](../standard-library/vector-class.md)|Uma classe de modelo de contêineres de sequência que organiza os elementos de um determinado tipo em uma organização linear e permite acesso aleatório rapidamente a qualquer elemento.|  
  
### <a name="specializations"></a>Especializações  
  
|||  
|-|-|  
|[vetor \< bool> classe](../Topic/vector%3Cbool%3E%20Class.md)|Uma especialização completa do vetor para elementos do tipo classe modelo `bool` com um alocador para o tipo subjacente usado pela especialização.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \< vector>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de modelos padrão](../misc/standard-template-library.md)

