---
title: Operadores ATL
ms.date: 11/04/2016
helpviewer_keywords:
- operators [ATL]
ms.assetid: 58ccd252-2869-45ee-8a5c-3ca40ee7f8a2
ms.openlocfilehash: 6f1bd4f88b8d3a37f051a208a887c5264f61955a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62260903"
---
# <a name="atl-operators"></a>Operadores ATL

Esta seção contém os tópicos de referência para os operadores globais da ATL.

|Operador|Descrição|
|--------------|-----------------|
|[operator ==](#operator_eq_eq)|Compara duas `CSid` objetos ou `SID` estruturas quanto à igualdade.|
|[operator !=](#operator_neq)|Compara duas `CSid` objetos ou `SID` estruturas quanto à desigualdade.|
|[operador <](#operator_lt)|Testa se o `CSid` objeto ou `SID` estrutura no lado esquerdo do operador é menor do que o `CSid` objeto ou `SID` estrutura no lado direito (para compatibilidade de biblioteca padrão C++).|
|[operador >](#operator_gt)|Testa se o `CSid` objeto ou `SID` estrutura no lado esquerdo do operador é maior que o `CSid` objeto ou `SID` estrutura no lado direito (para compatibilidade de biblioteca padrão C++).|
|[operador < =](#operator_lt__eq)|Testa se o `CSid` objeto ou `SID` estrutura no lado esquerdo do operador é menor que ou igual a `CSid` objeto ou `SID` estrutura no lado direito (para compatibilidade de biblioteca padrão C++).|
|[operador > =](#operator_gt__eq)|Testa se o `CSid` objeto ou `SID` estrutura no lado esquerdo do operador é maior que ou igual a `CSid` objeto ou `SID` estrutura no lado direito (para compatibilidade de biblioteca padrão C++).|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity. h.

##  <a name="operator_eq_eq"></a>  operador = =

Compara `CSid` objetos ou `SID` estruturas (identificador de segurança) quanto à igualdade.

```
bool operator==(const CSid& lhs, const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*lhs*<br/>
A primeira `CSid` objeto ou `SID` estrutura a ser comparada.

*rhs*<br/>
A segunda `CSid` objeto ou `SID` estrutura a ser comparada.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se os objetos forem iguais, FALSO se não forem iguais.

##  <a name="operator_neq"></a>  operador! =

Compara `CSid` objetos ou `SID` estruturas (identificador de segurança) quanto à desigualdade.

```
bool operator==(const CSid& lhs, const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*lhs*<br/>
A primeira `CSid` objeto ou `SID` estrutura a ser comparada.

*rhs*<br/>
A segunda `CSid` objeto ou `SID` estrutura a ser comparada.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se os objetos não forem iguais, FALSE se eles forem iguais.

##  <a name="operator_lt"></a>  operador <

Testa se o `CSid` objeto ou `SID` estrutura no lado esquerdo do operador é menor do que o `CSid` objeto ou `SID` estrutura no lado direito (para compatibilidade de biblioteca padrão C++).

```
bool operator<(const CSid& lhs, const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*lhs*<br/>
A primeira `CSid` objeto ou `SID` estrutura a ser comparada.

*rhs*<br/>
A segunda `CSid` objeto ou `SID` estrutura a ser comparada.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o endereço do *lhs* objeto é menor que o endereço do *rhs* objeto, caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse operador atua no endereço do `CSid` objeto ou `SID` estrutura e é implementada para fornecer compatibilidade com classes de coleção da biblioteca padrão C++.

##  <a name="operator_gt"></a>  operator >

Testa se o `CSid` objeto ou `SID` estrutura no lado esquerdo do operador é maior que o `CSid` objeto ou `SID` estrutura no lado direito (para compatibilidade de biblioteca padrão C++).

```
bool operator<(const CSid& lhs, const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*lhs*<br/>
A primeira `CSid` objeto ou `SID` estrutura a ser comparada.

*rhs*<br/>
A segunda `CSid` objeto ou `SID` estrutura a ser comparada.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o endereço do *lhs* é maior que o endereço do *rhs*, FALSE caso contrário.

### <a name="remarks"></a>Comentários

Esse operador atua no endereço do `CSid` objeto ou `SID` estrutura e é implementada para fornecer compatibilidade com classes de coleção da biblioteca padrão C++.

##  <a name="operator_lt__eq"></a>  operador < =

Testa se o `CSid` objeto ou `SID` estrutura no lado esquerdo do operador é menor que ou igual a `CSid` objeto ou `SID` estrutura no lado direito (para compatibilidade de biblioteca padrão C++).

```
bool operator<(const CSid& lhs, const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*lhs*<br/>
A primeira `CSid` objeto ou `SID` estrutura a ser comparada.

*rhs*<br/>
A segunda `CSid` objeto ou `SID` estrutura a ser comparada.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o endereço do *lhs* é menor que ou igual ao endereço do *rhs*, FALSE caso contrário.

### <a name="remarks"></a>Comentários

Esse operador atua no endereço do `CSid` objeto ou `SID` estrutura e é implementada para fornecer compatibilidade com classes de coleção da biblioteca padrão C++.

##  <a name="operator_gt__eq"></a>  operador > =

Testa se o `CSid` objeto ou `SID` estrutura no lado esquerdo do operador é maior que ou igual a `CSid` objeto ou `SID` estrutura no lado direito (para compatibilidade de biblioteca padrão C++).

```
bool operator<(const CSid& lhs, const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*lhs*<br/>
A primeira `CSid` objeto ou `SID` estrutura a ser comparada.

*rhs*<br/>
A segunda `CSid` objeto ou `SID` estrutura a ser comparada.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o endereço do *lhs* é maior que ou igual ao endereço do *rhs*, FALSE caso contrário.

### <a name="remarks"></a>Comentários

Esse operador atua no endereço do `CSid` objeto ou `SID` estrutura e é implementada para fornecer compatibilidade com classes de coleção da biblioteca padrão C++.
