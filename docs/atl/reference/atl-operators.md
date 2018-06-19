---
title: Operadores ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- operators [ATL]
ms.assetid: 58ccd252-2869-45ee-8a5c-3ca40ee7f8a2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 75c9ffb8c918cce70ad1e150dd80cb07ebdd7b34
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32360930"
---
# <a name="atl-operators"></a>Operadores ATL
Esta seção contém os tópicos de referência para os operadores globais ATL.  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[operador = =](#operator_eq_eq)|Compara dois `CSid` objetos ou `SID` estruturas para igualdade.|  
|[operador! =](#operator_neq)|Compara dois `CSid` objetos ou `SID` estruturas de desigualdade.|  
|[operador <](#operator_lt)|Testa se o `CSid` objeto ou `SID` estrutura no lado esquerdo do operador é menor do que o `CSid` objeto ou `SID` estrutura à direita (para compatibilidade de biblioteca padrão C++).|  
|[operador >](#operator_gt)|Testa se o `CSid` objeto ou `SID` estrutura no lado esquerdo do operador é maior do que o `CSid` objeto ou `SID` estrutura à direita (para compatibilidade de biblioteca padrão C++).|  
|[operador < =](#operator_lt__eq)|Testa se o `CSid` objeto ou `SID` estrutura no lado esquerdo do operador é menor ou igual a `CSid` objeto ou `SID` estrutura à direita (para compatibilidade de biblioteca padrão C++).|  
|[operador > =](#operator_gt__eq)|Testa se o `CSid` objeto ou `SID` estrutura no lado esquerdo do operador é maior que ou igual a `CSid` objeto ou `SID` estrutura à direita (para compatibilidade de biblioteca padrão C++).|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsecurity.h.  
  
##  <a name="operator_eq_eq"></a>  operador = =  
 Compara `CSid` objetos ou `SID` igualdade de estruturas (identificador de segurança).  
  
```   
bool operator==(const CSid& lhs, const CSid& rhs) throw(); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `lhs`  
 A primeira `CSid` objeto ou `SID` estrutura a ser comparado.  
  
 `rhs`  
 A segunda `CSid` objeto ou `SID` estrutura a ser comparado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se os objetos forem iguais, **false** se eles não forem iguais.  
  
##  <a name="operator_neq"></a>  operador! =  
 Compara `CSid` objetos ou `SID` estruturas (identificador de segurança) para fins de desigualdade.  
  
```   
bool operator==(const CSid& lhs, const CSid& rhs) throw(); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `lhs`  
 A primeira `CSid` objeto ou `SID` estrutura a ser comparado.  
  
 `rhs`  
 A segunda `CSid` objeto ou `SID` estrutura a ser comparado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se os objetos não forem iguais, **false** se eles forem iguais.  
  
##  <a name="operator_lt"></a>  operador <  
 Testa se o `CSid` objeto ou `SID` estrutura no lado esquerdo do operador é menor do que o `CSid` objeto ou `SID` estrutura à direita (para compatibilidade de biblioteca padrão C++).  
  
```   
bool operator<(const CSid& lhs, const CSid& rhs) throw(); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `lhs`  
 A primeira `CSid` objeto ou `SID` estrutura a ser comparado.  
  
 `rhs`  
 A segunda `CSid` objeto ou `SID` estrutura a ser comparado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se o endereço do `lhs` objeto é menor que o endereço do `rhs` objeto, **false** caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Este operador age no endereço do `CSid` objeto ou `SID` estrutura e é implementado para fornecer compatibilidade com classes de coleção da biblioteca padrão C++.  
  
##  <a name="operator_gt"></a>  operador >  
 Testa se o `CSid` objeto ou `SID` estrutura no lado esquerdo do operador é maior do que o `CSid` objeto ou `SID` estrutura à direita (para compatibilidade de biblioteca padrão C++).  
  
```   
bool operator<(const CSid& lhs, const CSid& rhs) throw(); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `lhs`  
 A primeira `CSid` objeto ou `SID` estrutura a ser comparado.  
  
 `rhs`  
 A segunda `CSid` objeto ou `SID` estrutura a ser comparado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se o endereço do `lhs` é maior do que o endereço do `rhs`, **false** caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Este operador age no endereço do `CSid` objeto ou `SID` estrutura e é implementado para fornecer compatibilidade com classes de coleção da biblioteca padrão C++.  
  
##  <a name="operator_lt__eq"></a>  operador < =  
 Testa se o `CSid` objeto ou `SID` estrutura no lado esquerdo do operador é menor ou igual a `CSid` objeto ou `SID` estrutura à direita (para compatibilidade de biblioteca padrão C++).  
  
```   
bool operator<(const CSid& lhs, const CSid& rhs) throw(); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `lhs`  
 A primeira `CSid` objeto ou `SID` estrutura a ser comparado.  
  
 `rhs`  
 A segunda `CSid` objeto ou `SID` estrutura a ser comparado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se o endereço do `lhs` é menor ou igual ao endereço do `rhs`, **false** caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Este operador age no endereço do `CSid` objeto ou `SID` estrutura e é implementado para fornecer compatibilidade com classes de coleção da biblioteca padrão C++.  
  
##  <a name="operator_gt__eq"></a>  operador > =  
 Testa se o `CSid` objeto ou `SID` estrutura no lado esquerdo do operador é maior que ou igual a `CSid` objeto ou `SID` estrutura à direita (para compatibilidade de biblioteca padrão C++).  
  
```   
bool operator<(const CSid& lhs, const CSid& rhs) throw(); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `lhs`  
 A primeira `CSid` objeto ou `SID` estrutura a ser comparado.  
  
 `rhs`  
 A segunda `CSid` objeto ou `SID` estrutura a ser comparado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se o endereço do `lhs` é maior que ou igual ao endereço do `rhs`, **false** caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Este operador age no endereço do `CSid` objeto ou `SID` estrutura e é implementado para fornecer compatibilidade com classes de coleção da biblioteca padrão C++.



