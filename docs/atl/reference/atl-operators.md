---
title: Operadores ATL
ms.date: 11/04/2016
helpviewer_keywords:
- operators [ATL]
ms.assetid: 58ccd252-2869-45ee-8a5c-3ca40ee7f8a2
ms.openlocfilehash: fe5363d3d05123c17e45254898e2210797400022
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168846"
---
# <a name="atl-operators"></a>Operadores ATL

Esta seção contém os tópicos de referência para os operadores globais da ATL.

|Operador|Descrição|
|--------------|-----------------|
|[operador = =](#operator_eq_eq)|Compara dois `CSid` objetos ou `SID` estruturas para igualdade.|
|[operador! =](#operator_neq)|Compara dois `CSid` objetos ou `SID` estruturas para desigualdade.|
|[<do operador](#operator_lt)|Testa se o `CSid` objeto ou `SID` a estrutura no lado esquerdo do operador é menor do que o `CSid` objeto ou `SID` a estrutura no lado direito (para compatibilidade com biblioteca padrão do C++).|
|[>do operador](#operator_gt)|Testa se o `CSid` objeto ou `SID` a estrutura no lado esquerdo do operador é maior do que o `CSid` objeto ou `SID` a estrutura no lado direito (para compatibilidade com biblioteca padrão do C++).|
|[<do operador =](#operator_lt__eq)|Testa se o `CSid` objeto ou `SID` a estrutura no lado esquerdo do operador é menor ou igual ao `CSid` objeto ou `SID` à estrutura no lado direito (para compatibilidade com biblioteca padrão do C++).|
|[>do operador =](#operator_gt__eq)|Testa se o `CSid` objeto ou `SID` a estrutura no lado esquerdo do operador é maior ou igual ao `CSid` objeto ou `SID` à estrutura no lado direito (para compatibilidade com biblioteca padrão do C++).|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLSecurity. h.

## <a name="operator-"></a><a name="operator_eq_eq"></a>operador = =

Compara `CSid` objetos ou `SID` estruturas (identificador de segurança) para igualdade.

```cpp
bool operator==(const CSid& lhs, const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*lhs*<br/>
O primeiro `CSid` objeto ou `SID` estrutura a ser comparado.

*rhs*<br/>
O segundo `CSid` objeto ou `SID` estrutura a ser comparado.

### <a name="return-value"></a>Valor retornado

Retornará TRUE se os objetos forem iguais, FALSE se não forem iguais.

## <a name="operator-"></a><a name="operator_neq"></a>operador! =

Compara `CSid` objetos ou `SID` estruturas (identificador de segurança) para desigualdade.

```cpp
bool operator==(const CSid& lhs, const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*lhs*<br/>
O primeiro `CSid` objeto ou `SID` estrutura a ser comparado.

*rhs*<br/>
O segundo `CSid` objeto ou `SID` estrutura a ser comparado.

### <a name="return-value"></a>Valor retornado

Retornará TRUE se os objetos não forem iguais, FALSE se forem iguais.

## <a name="operator-"></a><a name="operator_lt"></a>< do operador

Testa se o `CSid` objeto ou `SID` a estrutura no lado esquerdo do operador é menor do que o `CSid` objeto ou `SID` a estrutura no lado direito (para compatibilidade com biblioteca padrão do C++).

```cpp
bool operator<(const CSid& lhs, const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*lhs*<br/>
O primeiro `CSid` objeto ou `SID` estrutura a ser comparado.

*rhs*<br/>
O segundo `CSid` objeto ou `SID` estrutura a ser comparado.

### <a name="return-value"></a>Valor retornado

Retornará TRUE se o endereço do objeto *LHS* for menor que o endereço do objeto *RHS* ; caso contrário, false.

### <a name="remarks"></a>Comentários

Esse operador atua no endereço do `CSid` objeto ou `SID` na estrutura e é implementado para fornecer compatibilidade com classes de coleção de bibliotecas padrão do C++.

## <a name="operator-"></a><a name="operator_gt"></a>> do operador

Testa se o `CSid` objeto ou `SID` a estrutura no lado esquerdo do operador é maior do que o `CSid` objeto ou `SID` a estrutura no lado direito (para compatibilidade com biblioteca padrão do C++).

```cpp
bool operator<(const CSid& lhs, const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*lhs*<br/>
O primeiro `CSid` objeto ou `SID` estrutura a ser comparado.

*rhs*<br/>
O segundo `CSid` objeto ou `SID` estrutura a ser comparado.

### <a name="return-value"></a>Valor retornado

Retornará TRUE se o endereço do *LHS* for maior que o endereço do *RHS*; caso contrário, false.

### <a name="remarks"></a>Comentários

Esse operador atua no endereço do `CSid` objeto ou `SID` na estrutura e é implementado para fornecer compatibilidade com classes de coleção de bibliotecas padrão do C++.

## <a name="operator-"></a><a name="operator_lt__eq"></a><do operador =

Testa se o `CSid` objeto ou `SID` a estrutura no lado esquerdo do operador é menor ou igual ao `CSid` objeto ou `SID` à estrutura no lado direito (para compatibilidade com biblioteca padrão do C++).

```cpp
bool operator<(const CSid& lhs, const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*lhs*<br/>
O primeiro `CSid` objeto ou `SID` estrutura a ser comparado.

*rhs*<br/>
O segundo `CSid` objeto ou `SID` estrutura a ser comparado.

### <a name="return-value"></a>Valor retornado

Retornará TRUE se o endereço do *LHS* for menor ou igual ao endereço do *RHS*; caso contrário, false.

### <a name="remarks"></a>Comentários

Esse operador atua no endereço do `CSid` objeto ou `SID` na estrutura e é implementado para fornecer compatibilidade com classes de coleção de bibliotecas padrão do C++.

## <a name="operator-"></a><a name="operator_gt__eq"></a>>do operador =

Testa se o `CSid` objeto ou `SID` a estrutura no lado esquerdo do operador é maior ou igual ao `CSid` objeto ou `SID` à estrutura no lado direito (para compatibilidade com biblioteca padrão do C++).

```cpp
bool operator<(const CSid& lhs, const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*lhs*<br/>
O primeiro `CSid` objeto ou `SID` estrutura a ser comparado.

*rhs*<br/>
O segundo `CSid` objeto ou `SID` estrutura a ser comparado.

### <a name="return-value"></a>Valor retornado

Retornará TRUE se o endereço do *LHS* for maior ou igual ao endereço do *RHS*; caso contrário, false.

### <a name="remarks"></a>Comentários

Esse operador atua no endereço do `CSid` objeto ou `SID` na estrutura e é implementado para fornecer compatibilidade com classes de coleção de bibliotecas padrão do C++.
