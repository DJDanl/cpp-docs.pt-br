---
title: Classe index | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- AMP/index
- AMP/Concurrency::index::index
- AMP/Concurrency::index::rank
dev_langs: C++
helpviewer_keywords: index structure
ms.assetid: cbe79b08-0ba7-474c-9828-f1a71da39eb3
caps.latest.revision: "20"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 04a10524a46fe7351b881e436d7aaf422b2a9acb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="index-class"></a>Classe index
Define uma *N*-dimensional índice pographics cpp amp.md.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <int _Rank>  
class index;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_Rank`  
 A classificação ou o número de dimensões.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor de índice](#ctor)|Inicializa uma nova instância da classe `index`.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operator--](#operator--)|Decrementa cada elemento do `index` objeto.|  
|[Operator(MOD) =](#operator_mod_eq)|Calcula o módulo (restante) de cada elemento no `index` do objeto quando esse elemento é dividido por um número.|  
|[operator*=](#operator_star_eq)|Multiplica cada elemento do `index` objeto por um número.|  
|[operator/=](#operator_div_eq)|Divide cada elemento do `index` objeto por um número.|  
|[index:: Operator\[\]](#operator_at)|Retorna o elemento no índice especificado.|  
|[operator++](#operator_add_add)|Incrementa a cada elemento do `index` objeto.|  
|[operator+=](#operator_add_eq)|Adiciona o número especificado para cada elemento do `index` objeto.|  
|[operator=](#operator_eq)|Copia o conteúdo de especificado `index` deste objeto.|  
|[operator-=](#operator_-_eq)|Subtrai o número especificado de cada elemento do `index` objeto.|  

  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante de classificação](#rank)|Armazena a classificação do `index` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `index`  
  
## <a name="remarks"></a>Comentários  
 O `index` estrutura representa um vetor de coordenada de *N* inteiros que especifica uma posição exclusiva em uma *N*-espaço bidimensional. Os valores do vetor são ordenados do mais significativos para menos significativo. Você pode recuperar os valores dos componentes usando [operador =](#operator_eq).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp.h  
  
 **Namespace:** Simultaneidade  


## <a name="index_ctor"></a>Construtor de índice
Inicializa uma nova instância da classe de índice.

```  
index() restrict(amp,cpu);

index(
   const index<_Rank>& _Other
) restrict(amp,cpu);

explicit index(
   int _I
) restrict(amp,cpu);

index(
   int _I0,
   int _I1
) restrict(amp,cpu);

index(
   int _I0,
   int _I1,
   int _I2
) restrict(amp,cpu);

explicit index(
   const int _Array[_Rank]
) restrict(amp,cpu);
``` 

### <a name="parameters"></a>Parâmetros

_Array  
Uma matriz unidimensional com os valores de classificação.  
EU _  
O local de índice em um índice unidimensional.  
_I0  
O comprimento da dimensão mais significativo.  
_I1  
O comprimento da dimensão Avançar-para-mais significativo.  
_I2  
O comprimento da dimensão menos significativo.  
_Other  
Um objeto de índice no qual o novo objeto de índice se baseia.  

## <a name="operator--"></a>operador-
Decrementa cada elemento do objeto index.  
```  
index<_Rank>& operator--() restrict(amp,cpu);  

index operator--(
   int
) restrict(amp,cpu);
```  
### <a name="return-values"></a>Valores de retorno
Para o operador de prefixo, o objeto de índice (* isso). Para o operador de sufixo, um novo objeto de índice.

## <a name="operator_mod_eq"></a>Operator(MOD) =   
Calcula o módulo (restante) de cada elemento no objeto de índice quando esse elemento é dividido pelo número especificado.

```  
index<_Rank>& operator%=(
   int _Rhs
) restrict(cpu, amp);
```  
### <a name="parameters"></a>Parâmetros
_Rhs o número de dividir por para localizar o módulo.
O objeto de índice do valor de retorno.

## <a name="operator_star_eq"></a>operador * =   
Multiplica cada elemento no objeto de índice pelo número especificado.
```
index<_Rank>& operator*=(
   int _Rhs
) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros
_Rhs o número para multiplicar.

## <a name="operator_div_eq"></a>operador / = 
Divide cada elemento no objeto de índice pelo número especificado.

```
index<_Rank>& operator/=(
   int _Rhs
) restrict(amp,cpu);
``` 
### <a name="parameters"></a>Parâmetros
_Rhs o número pelo qual dividir.

## <a name="operator_at"></a>  operator\[\]  
Retorna o componente do índice no local especificado.

```
int operator[] (
   unsigned _Index
) const restrict(amp,cpu);

int& operator[] (
   unsigned _Index
) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros
Index um número inteiro entre 0 e a classificação menos 1.

### <a name="return-value"></a>Valor de retorno
O elemento no índice especificado.

### <a name="remarks"></a>Comentários
Este exemplo a seguir exibe os valores de componente do índice.
```  
// Prints 1 2 3.
concurrency::index<3> idx(1, 2, 3);
std::cout << idx[0] << "\n";
std::cout << idx[1] << "\n";
std::cout << idx[2] << "\n";
```

## <a name="operator_add_add"></a>operador + +   
Incrementa a cada elemento do objeto index.
```  
index<_Rank>& operator++() restrict(amp,cpu);

index<_Rank> operator++(
   int
) restrict(amp,cpu);
```  
### <a name="return-value"></a>Valor de retorno
Para o operador de prefixo, o objeto de índice (* isso). Para o operador de sufixo, um novo objeto de índice.

## <a name="operator_add_eq"></a>+ operador =   
Adiciona o número especificado para cada elemento do objeto index.
```  
index<_Rank>& operator+=(
   const index<_Rank>& _Rhs
) restrict(amp,cpu);

index<_Rank>& operator+=(
   int _Rhs
) restrict(amp,cpu);
``` 
### <a name="parameters"></a>Parâmetros
_Rhs o número para adicionar.

### <a name="return-value"></a>Valor de retorno
O objeto de índice.

## <a name="operator_eq"></a>  operator=   
Copia o conteúdo do objeto de índice especificado para esta.
```  
index<_Rank>& operator=(
   const index<_Rank>& _Other
) restrict(amp,cpu);
``` 
### <a name="parameters"></a>Parâmetros
O objeto de índice para copiar a partir de _Other.

### <a name="return-value"></a>Valor de retorno
Uma referência a esse objeto de índice.

## <a name="operator_-_eq"></a>operador =
Subtrai o número especificado de cada elemento do objeto index.
```  
index<_Rank>& operator-=(
   const index<_Rank>& _Rhs
) restrict(amp,cpu);

index<_Rank>& operator-=(
   int _Rhs
) restrict(amp,cpu);
```  
### <a name="parameters"></a>Parâmetros
_Rhs o número para subtrair.

### <a name="return-value"></a>Valor de retorno
O objeto de índice.   

## <a name="rank"></a>Classificação  
  Obtém a posição do objeto index.
```
static const int rank = _Rank;
``` 
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
