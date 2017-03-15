---
title: Operadores ATL | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: 'index-page '
dev_langs:
- C++
helpviewer_keywords:
- operators [ATL]
ms.assetid: 58ccd252-2869-45ee-8a5c-3ca40ee7f8a2
caps.latest.revision: 16
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
translationtype: Machine Translation
ms.sourcegitcommit: 3f69f0c3176d2fbe19e11ce08c071691a72d858d
ms.openlocfilehash: 87aadf7aacc31ded165a8e1380823cb20e614fb1
ms.lasthandoff: 02/25/2017

---
# <a name="atl-operators"></a>Operadores ATL
Esta seção contém os tópicos de referência para os operadores globais ATL.  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[operador = =](#operator_eq_eq)|Compara dois `CSid` objetos ou `SID` igualdade de estruturas.|  
|[operador! =](#operator_neq)|Compara dois `CSid` objetos ou `SID` estruturas para desigualdade.|  
|[operador](#operator_lt)|Testa se o `CSid` objeto ou `SID` estrutura no lado esquerdo do operador é menor do que o `CSid` objeto ou `SID` estrutura à direita (para compatibilidade de biblioteca padrão C++).|  
|[operador >](#operator_gt)|Testa se o `CSid` objeto ou `SID` estrutura no lado esquerdo do operador é maior do que o `CSid` objeto ou `SID` estrutura à direita (para compatibilidade de biblioteca padrão C++).|  
|[operador<>](#operator_lt__eq)|Testa se o `CSid` objeto ou `SID` estrutura no lado esquerdo do operador é menor ou igual a `CSid` objeto ou `SID` estrutura à direita (para compatibilidade de biblioteca padrão C++).|  
|[operador > =](#operator_gt__eq)|Testa se o `CSid` objeto ou `SID` estrutura no lado esquerdo do operador é maior que ou igual a `CSid` objeto ou `SID` estrutura à direita (para compatibilidade de biblioteca padrão C++).|  
  
 Esses operadores são definidos na atlsecurity. h do arquivo.  
  
##  <a name="a-nameoperatoreqeqa--operator-"></a><a name="operator_eq_eq"></a>operador = =  
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
 Retorna **true** se os objetos forem iguais, **false** se não forem iguais.  
  
##  <a name="a-nameoperatorneqa--operator-"></a><a name="operator_neq"></a>operador! =  
 Compara `CSid` objetos ou `SID` estruturas (identificador de segurança) para desigualdade.  
  
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
  
##  <a name="a-nameoperatorlta--operator-"></a><a name="operator_lt"></a>operador  
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
 Este operador atua no endereço do `CSid` objeto ou `SID` estrutura e é implementado para fornecer compatibilidade com classes de coleção da biblioteca padrão C++.  
  
##  <a name="a-nameoperatorgta--operator-"></a><a name="operator_gt"></a>operador >  
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
 Retorna **true** se o endereço do `lhs` é maior que o endereço do `rhs`, **false** caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Este operador atua no endereço do `CSid` objeto ou `SID` estrutura e é implementado para fornecer compatibilidade com classes de coleção da biblioteca padrão C++.  
  
##  <a name="a-nameoperatorlteqa--operator-"></a><a name="operator_lt__eq"></a>operador<=></=>  
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
 Este operador atua no endereço do `CSid` objeto ou `SID` estrutura e é implementado para fornecer compatibilidade com classes de coleção da biblioteca padrão C++.  
  
##  <a name="a-nameoperatorgteqa--operator-"></a><a name="operator_gt__eq"></a>operador > =  
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
 Este operador atua no endereço do `CSid` objeto ou `SID` estrutura e é implementado para fornecer compatibilidade com classes de coleção da biblioteca padrão C++.




