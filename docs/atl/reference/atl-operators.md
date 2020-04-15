---
title: Operadores ATL
ms.date: 11/04/2016
helpviewer_keywords:
- operators [ATL]
ms.assetid: 58ccd252-2869-45ee-8a5c-3ca40ee7f8a2
ms.openlocfilehash: 8c15daa1d2b12c58323ef5ef75559a2ab911ad93
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319230"
---
# <a name="atl-operators"></a>Operadores ATL

Esta seção contém os tópicos de referência para os operadores globais atl.

|Operador|Descrição|
|--------------|-----------------|
|[operador ==](#operator_eq_eq)|Compara `CSid` dois `SID` objetos ou estruturas para a igualdade.|
|[operador !=](#operator_neq)|Compara `CSid` dois `SID` objetos ou estruturas para a desigualdade.|
|[operador <](#operator_lt)|Teste se `CSid` o `SID` objeto ou estrutura do lado esquerdo `CSid` do `SID` operador é menor que o objeto ou estrutura do lado direito (para compatibilidade com a Biblioteca Padrão C++).|
|[operador >](#operator_gt)|Teste se `CSid` o `SID` objeto ou estrutura do lado esquerdo `CSid` do `SID` operador é maior do que o objeto ou estrutura do lado direito (para compatibilidade com a Biblioteca Padrão C++).|
|[operador <=](#operator_lt__eq)|Teste se `CSid` o `SID` objeto ou estrutura do lado esquerdo do `CSid` operador `SID` é menor ou igual ao objeto ou estrutura do lado direito (para compatibilidade com a Biblioteca Padrão C++).|
|[operador >=](#operator_gt__eq)|Teste se `CSid` o `SID` objeto ou estrutura do lado esquerdo do `CSid` operador `SID` é maior ou igual ao objeto ou estrutura do lado direito (para compatibilidade com a Biblioteca Padrão C++).|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity.h.

## <a name="operator-"></a><a name="operator_eq_eq"></a>operador ==

Compara `CSid` objetos ou `SID` estruturas (identificadores de segurança) para igualdade.

```
bool operator==(const CSid& lhs, const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*Lhs*<br/>
O `CSid` primeiro `SID` objeto ou estrutura para comparar.

*rhs*<br/>
O `CSid` segundo `SID` objeto ou estrutura para comparar.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se os objetos forem iguais, FALSOs se não forem iguais.

## <a name="operator-"></a><a name="operator_neq"></a>operador !=

Compara `CSid` objetos ou `SID` estruturas (identificadores de segurança) para desigualdade.

```
bool operator==(const CSid& lhs, const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*Lhs*<br/>
O `CSid` primeiro `SID` objeto ou estrutura para comparar.

*rhs*<br/>
O `CSid` segundo `SID` objeto ou estrutura para comparar.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se os objetos não forem iguais, FALSOs se forem iguais.

## <a name="operator-"></a><a name="operator_lt"></a>operador <

Teste se `CSid` o `SID` objeto ou estrutura do lado esquerdo `CSid` do `SID` operador é menor que o objeto ou estrutura do lado direito (para compatibilidade com a Biblioteca Padrão C++).

```
bool operator<(const CSid& lhs, const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*Lhs*<br/>
O `CSid` primeiro `SID` objeto ou estrutura para comparar.

*rhs*<br/>
O `CSid` segundo `SID` objeto ou estrutura para comparar.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o endereço do objeto *lhs* for menor que o endereço do objeto *rhs,* FALSE de outra forma.

### <a name="remarks"></a>Comentários

Este operador atua no `CSid` endereço `SID` do objeto ou estrutura e é implementado para fornecer compatibilidade com as classes de coleção da Biblioteca Padrão C++.

## <a name="operator-"></a><a name="operator_gt"></a>operador >

Teste se `CSid` o `SID` objeto ou estrutura do lado esquerdo `CSid` do `SID` operador é maior do que o objeto ou estrutura do lado direito (para compatibilidade com a Biblioteca Padrão C++).

```
bool operator<(const CSid& lhs, const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*Lhs*<br/>
O `CSid` primeiro `SID` objeto ou estrutura para comparar.

*rhs*<br/>
O `CSid` segundo `SID` objeto ou estrutura para comparar.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o endereço dos *lhs* for maior que o endereço dos *rhs*, FALSE de outra forma.

### <a name="remarks"></a>Comentários

Este operador atua no `CSid` endereço `SID` do objeto ou estrutura e é implementado para fornecer compatibilidade com as classes de coleção da Biblioteca Padrão C++.

## <a name="operator-"></a><a name="operator_lt__eq"></a>operador <=

Teste se `CSid` o `SID` objeto ou estrutura do lado esquerdo do `CSid` operador `SID` é menor ou igual ao objeto ou estrutura do lado direito (para compatibilidade com a Biblioteca Padrão C++).

```
bool operator<(const CSid& lhs, const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*Lhs*<br/>
O `CSid` primeiro `SID` objeto ou estrutura para comparar.

*rhs*<br/>
O `CSid` segundo `SID` objeto ou estrutura para comparar.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o endereço dos *lhs* for menor ou igual ao endereço dos *rhs*, FALSE de outra forma.

### <a name="remarks"></a>Comentários

Este operador atua no `CSid` endereço `SID` do objeto ou estrutura e é implementado para fornecer compatibilidade com as classes de coleção da Biblioteca Padrão C++.

## <a name="operator-"></a><a name="operator_gt__eq"></a>operador >=

Teste se `CSid` o `SID` objeto ou estrutura do lado esquerdo do `CSid` operador `SID` é maior ou igual ao objeto ou estrutura do lado direito (para compatibilidade com a Biblioteca Padrão C++).

```
bool operator<(const CSid& lhs, const CSid& rhs) throw();
```

### <a name="parameters"></a>Parâmetros

*Lhs*<br/>
O `CSid` primeiro `SID` objeto ou estrutura para comparar.

*rhs*<br/>
O `CSid` segundo `SID` objeto ou estrutura para comparar.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o endereço dos *lhs* for maior ou igual ao endereço dos *rhs*, FALSE de outra forma.

### <a name="remarks"></a>Comentários

Este operador atua no `CSid` endereço `SID` do objeto ou estrutura e é implementado para fornecer compatibilidade com as classes de coleção da Biblioteca Padrão C++.
