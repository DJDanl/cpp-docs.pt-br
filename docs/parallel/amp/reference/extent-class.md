---
title: Classe Extent (C++ AMP) | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- extent
- AMP/extent
- AMP/Concurrency::extent::extent
- AMP/Concurrency::extent::contains
- AMP/Concurrency::extent::size
- AMP/Concurrency::extent::tile
- AMP/Concurrency::extent::rank Constant
dev_langs:
- C++
helpviewer_keywords:
- extent structure
ms.assetid: edb5de3d-3935-4dbb-8365-4cc6c4fb0269
caps.latest.revision: 19
author: mikeblome
ms.author: mblome
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
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: 28c90118eeb83df75f19b49f47ac884bff111b8f
ms.contentlocale: pt-br
ms.lasthandoff: 03/17/2017

---
# <a name="extent-class-c-amp"></a>Classe extent (C++ AMP)
Representa um vetor de *N* valores inteiros que especificam os limites de um *N*-espaço tridimensional que tem uma origem de 0. Os valores do vetor são ordenados da mais significativo para o menos significativo.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
template <int _Rank>  
class extent;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Rank`  
 A classificação do `extent` objeto.  

 ## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp.h  
  
 **Namespace:** Simultaneidade  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor de extensão](#ctor)|Inicializa uma nova instância da classe `extent`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[contém](#contains)|Verifica se o especificado `extent` objeto tem a classificação especificada.|  
|[size](#size)|Retorna o tamanho total linear da extensão (em unidades de elementos).|  
|[lado a lado](#tile)|Produz um `tiled_extent` especificado de objeto com as extensões do lado a lado fornecida por dimensões.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operator-](#operator_min)|Retorna um novo `extent` objeto criado subtraindo o `index` elementos correspondentes `extent` elementos.|  
|[operator--](#operator_min_min)|Decrementa cada elemento de `extent` objeto.|  
|[operator%=](#operator_mod_eq)|Calcula o módulo (restante) de cada elemento de `extent` do objeto quando esse elemento é dividido por um número.|  
|[operator*=](#operator_star_eq)|Multiplica cada elemento de `extent` objeto por um número.|  
|[operator/=](#operator_min_eq)|Divide cada elemento de `extent` objeto por um número.|  
|[Extent:: Operator\[\]](#operator_at)|Retorna o elemento no índice especificado.|  
|[operator+](#operator_add)|Retorna um novo `extent` objeto é criado adicionando correspondente `index` e `extent` elementos.|  
|[operator++](#operator_add_add)|Incrementa a cada elemento do `extent` objeto.|  
|[operator+=](#operator_add_eq)|Adiciona o número especificado para cada elemento do `extent` objeto.|  
|[operator=](#operator_eq)|Copia o conteúdo de outro `extent` deste objeto.|  
|[operator-=](#operator_min_eq)|Subtrai o número especificado de cada elemento do `extent` objeto.|  

  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante Rank](#rank)|Obtém a classificação do `extent` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `extent`  


## <a name="contains"></a>contém 

Indica se o especificado [índice](index-class.md) valor está contido no objeto 'extensão'.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
bool contains(const index<rank>& _Index) const restrict(amp,cpu);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Index`  
 O `index` valor a ser testado.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se especificado `index` valor está contido no `extent` objeto; caso contrário, `false`.  
  
##  <a name="ctor"></a>extensão 

Inicializa uma nova instância da classe 'extensão'.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
extent() restrict(amp,cpu);    
extent(const extent<_Rank>& _Other) restrict(amp,cpu);    
explicit extent(int _I) restrict(amp,cpu);    
extent(int _I0,  int _I1) restrict(amp,cpu);    
extent(int _I0,  int _I1, int _I2) restrict(amp,cpu);    
explicit extent(const int _Array[_Rank])restrict(amp,cpu);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Array`  
 Uma matriz de `_Rank` inteiros que é usado para criar o novo `extent` objeto.  
  
 `_I`  
 O comprimento da extensão.  
  
 `_I0`  
 O comprimento da dimensão mais significativo.  
  
 `_I1`  
 O comprimento da dimensão Avançar-para-mais significativo.  
  
 `_I2`  
 O comprimento da dimensão menos significativo.  
  
 `_Other`  
 Um `extent` objeto no qual o novo `extent` com base em objeto.  
  
## <a name="remarks"></a>Comentários  
 O construtor sem parâmetro inicializa um `extent` objeto que tem uma classificação de três.  
  
 Se uma matriz é usada para construir um `extent` do objeto, o comprimento da matriz deve coincidir com a classificação do `extent` objeto.  
  
##  <a name="operator_mod_eq"></a>operador % = 

Calcula o módulo (restante) de cada elemento da extensão quando esse elemento é dividido por um número.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
extent<_Rank>& operator%=(int _Rhs) restrict(cpu, direct3d);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Rhs`  
 O número para localizar o resto de.  
  
### <a name="return-value"></a>Valor de retorno  
 O objeto `extent`.  
  
##  <a name="operator_star_eq"></a>operador * = 

Multiplica cada elemento no objeto 'extensão' pelo número especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
extent<_Rank>& operator*=(int _Rhs) restrict(amp,cpu);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Rhs`  
 O número a multiplicar.  
  
### <a name="return-value"></a>Valor de retorno  
 O objeto `extent`.  
  
## <a name="operator_add"></a>operador + 

Retorna um novo `extent` objeto criado adicionando correspondente `index` e `extent` elementos.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
extent<_Rank> operator+(const index<_Rank>& _Rhs) restrict(amp,cpu);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Rhs`  
 O `index` objeto que contém os elementos a serem adicionados.  
  
### <a name="return-value"></a>Valor de retorno  
 O novo objeto `extent`.  
  
##  <a name="operator_add_add"></a>operador + + 

Incrementa a cada elemento do objeto 'extensão'.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
extent<_Rank>& operator++() restrict(amp,cpu);    
extent<_Rank> operator++(int)restrict(amp,cpu);  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Para o operador de prefixo, o `extent` objeto (`*this`). Para o operador de sufixo, um novo `extent` objeto.  
  
##  <a name="operator_add_eq"></a>operador + = 

Adiciona o número especificado para cada elemento do objeto 'extensão'.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
extent<_Rank>& operator+=(const extent<_Rank>& _Rhs) restrict(amp,cpu);    
extent<_Rank>& operator+=(const index<_Rank>& _Rhs) restrict(amp,cpu);    
extent<_Rank>& operator+=(int _Rhs) restrict(amp,cpu);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Rhs`  
 O número, índice ou extensão para adicionar.  
  
### <a name="return-value"></a>Valor de retorno  
 O tipo do objeto `extent` resultante.  
  
##  <a name="operator_min"></a>operador- 

Cria um novo `extent` objeto subtraindo cada elemento especificado na `index` objeto do elemento correspondente no `extent` objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
extent<_Rank> operator-(const index<_Rank>& _Rhs) restrict(amp,cpu);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Rhs`  
 O `index` objeto que contém os elementos para subtrair.  
  
### <a name="return-value"></a>Valor de retorno  
 O novo objeto `extent`.  
  
##  <a name="operator_min_min"></a>operador- 

Decrementa cada elemento no objeto 'extensão'.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
extent<_Rank>& operator--() restrict(amp,cpu);    
extent<_Rank> operator--(int)restrict(amp,cpu);  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Para o operador de prefixo, o `extent` objeto (`*this`). Para o operador de sufixo, um novo `extent` objeto.  
  
##  <a name="operator_div_eq"></a>operador / = 

Divide cada elemento no objeto 'extensão' pelo número especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
extent<_Rank>& operator/=(int _Rhs) restrict(amp,cpu);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Rhs`  
 O número pelo qual dividir.  
  
### <a name="return-value"></a>Valor de retorno  
 O objeto `extent`.  
  
##  <a name="operator_min_eq"></a>operador = 

Subtrai o número especificado de cada elemento do objeto 'extensão'.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
extent<_Rank>& operator-=(const extent<_Rank>& _Rhs) restrict(amp,cpu);    
extent<_Rank>& operator-=(const index<_Rank>& _Rhs) restrict(amp,cpu);    
extent<_Rank>& operator-=(int _Rhs) restrict(amp,cpu);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Rhs`  
 O número para subtrair.  
  
### <a name="return-value"></a>Valor de retorno  
 O tipo do objeto `extent` resultante.  
  
##  <a name="operator_eq"></a>operador = 

Copia o conteúdo de outro objeto 'extensão' a este.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
extent<_Rank>& operator=(const extent<_Rank>& _Other) restrict(amp,cpu);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `extent` objeto copiar de.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a esta `extent` objeto.  
  
##  <a name="operator_at"></a>Extent:: Operator\[\] 
Retorna o elemento no índice especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
int operator[](unsigned int _Index) const restrict(amp,cpu);    
int& operator[](unsigned int _Index) restrict(amp,cpu);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Index`  
 Um inteiro entre 0 e a classificação menos 1.  
  
### <a name="return-value"></a>Valor de retorno  
 O elemento no índice especificado.  
  
##  <a name="rank_constant"></a>classificação 

Armazena a posição do objeto 'extensão'.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
static const int rank = _Rank;  
```  
  
##  <a name="size"></a>tamanho 

Retorna o tamanho total linear do `extent` objeto (em unidades de elementos).  
  
### <a name="syntax"></a>Sintaxe  

```  
unsigned int size() const restrict(amp,cpu);  
```  
  
## <a name="tile"></a>lado a lado 

Produz um objeto tiled_extent com as dimensões de bloco especificado.

```
template <int _Dim0>
tiled_extent<_Dim0> tile() const ;

template <int _Dim0, int _Dim1>
tiled_extent<_Dim0, _Dim1> tile() const ;

template <int _Dim0, int _Dim1, int _Dim2>
tiled_extent<_Dim0, _Dim1, _Dim2> tile() const ;
```  
### <a name="parameters"></a>Parâmetros
`_Dim0`O fator mais significativo da extensão lado a lado.
`_Dim1`O componente Avançar-para-mais significativo da extensão lado a lado.
`_Dim2`O componente menos significativo da extensão lado a lado.


  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)

