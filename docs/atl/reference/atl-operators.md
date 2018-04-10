---
title: Operadores ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- operators [ATL]
ms.assetid: 58ccd252-2869-45ee-8a5c-3ca40ee7f8a2
caps.latest.revision: 16
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: bcbe04fb057ffc8077f422cd784b5d31691df1e3
ms.sourcegitcommit: 0523c88b24d963c33af0529e6ba85ad2c6ee5afb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/10/2018
---
# <a name="atl-operators"></a>Operadores ATL
Esta seção contém os tópicos de referência para os operadores globais ATL.  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[operator ==](#operator_eq_eq)|Compara dois `CSid` objetos ou `SID` estruturas para igualdade.|  
|[operator !=](#operator_neq)|Compara dois `CSid` objetos ou `SID` estruturas de desigualdade.|  
|[operator <](#operator_lt)|Testa se o `CSid` objeto ou `SID` estrutura no lado esquerdo do operador é menor do que o `CSid` objeto ou `SID` estrutura à direita (para compatibilidade de biblioteca padrão C++).|  
|[operator >](#operator_gt)|Testa se o `CSid` objeto ou `SID` estrutura no lado esquerdo do operador é maior do que o `CSid` objeto ou `SID` estrutura à direita (para compatibilidade de biblioteca padrão C++).|  
|[operator <=](#operator_lt__eq)|Testa se o `CSid` objeto ou `SID` estrutura no lado esquerdo do operador é menor ou igual a `CSid` objeto ou `SID` estrutura à direita (para compatibilidade de biblioteca padrão C++).|  
|[operador > =](#operator_gt__eq)|Testa se o `CSid` objeto ou `SID` estrutura no lado esquerdo do operador é maior que ou igual a `CSid` objeto ou `SID` estrutura à direita (para compatibilidade de biblioteca padrão C++).|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsecurity.h.  
  
##  <a name="operator_eq_eq"></a>  operator ==  
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
  
##  <a name="operator_neq"></a>  operator !=  
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
  
##  <a name="operator_lt"></a>  operator <  
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
  
##  <a name="operator_gt"></a>  operator >  
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



