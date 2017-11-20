---
title: Classe CComSafeArrayBound | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComSafeArrayBound
- ATLSAFE/ATL::CComSafeArrayBound
- ATLSAFE/ATL::GetCount
- ATLSAFE/ATL::GetLowerBound
- ATLSAFE/ATL::GetUpperBound
- ATLSAFE/ATL::SetCount
- ATLSAFE/ATL::SetLowerBound
dev_langs: C++
helpviewer_keywords: CComSafeArrayBound class
ms.assetid: dd6299db-5f84-4630-bbf0-f5add5318437
caps.latest.revision: "21"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: c52e429804fdc3eb84ca14005bbc65e00603a4c4
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ccomsafearraybound-class"></a>Classe CComSafeArrayBound
Essa classe é um wrapper para um [SAFEARRAYBOUND](http://msdn.microsoft.com/en-us/303a9bdb-71d6-4f14-8747-84cf84936c6d) estrutura.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CComSafeArrayBound : public SAFEARRAYBOUND
```  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[CComSafeArrayBound](#ccomsafearraybound)|O construtor.|  
|[GetCount](#getcount)|Chame este método para retornar o número de elementos.|  
|[GetLowerBound](#getlowerbound)|Chame este método para retornar o limite inferior.|  
|[GetUpperBound](#getupperbound)|Chame este método para retornar o limite superior.|  
|[SetCount](#setcount)|Chame este método para definir o número de elementos.|  
|[SetLowerBound](#setlowerbound)|Chame esse método para definir o limite inferior.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operador =](#operator_eq)|Conjuntos de `CComSafeArrayBound` para um novo valor.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe é um wrapper para o **SAFEARRAYBOUND** estrutura usada por [CComSafeArray](../../atl/reference/ccomsafearray-class.md). Ele fornece métodos para consultar e definir os limites superior e inferiores de uma única dimensão de uma `CComSafeArray` objeto e o número de elementos contidos nele. Um multidimensionais `CComSafeArray` objeto usa uma matriz de `CComSafeArrayBound` objetos, um para cada dimensão. Portanto, ao usar os métodos como [GetCount](#getcount), lembre-se de que esse método não retornará o número total de elementos em uma matriz multidimensional.  
  
 **Cabeçalho:** atlsafe.h  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsafe.h  
  
##  <a name="ccomsafearraybound"></a>CComSafeArrayBound::CComSafeArrayBound  
 O construtor.  
  
```
CComSafeArrayBound(ULONG ulCount = 0, LONG lLowerBound = 0) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `ulCount`  
 O número de elementos na matriz.  
  
 `lLowerBound`  
 O limite inferior do qual a matriz é numerada.  
  
### <a name="remarks"></a>Comentários  
 Se a matriz deve ser acessado a partir de um programa do Visual C++, é recomendável que o limite inferior seja definida como 0. Talvez seja preferível usar um valor de limite inferior diferente se a matriz é para ser usado com outras linguagens, como Visual Basic.  
  
##  <a name="getcount"></a>CComSafeArrayBound::GetCount  
 Chame este método para retornar o número de elementos.  
  
```
ULONG GetCount() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de elementos.  
  
### <a name="remarks"></a>Comentários  
 Se associado `CComSafeArray` objeto representa uma matriz multidimensional, esse método retornará somente o número total de elementos na dimensão mais à direita. Use [CComSafeArray::GetCount](../../atl/reference/ccomsafearray-class.md#getcount) para obter o número total de elementos.  
  
##  <a name="getlowerbound"></a>CComSafeArrayBound::GetLowerBound  
 Chame este método para retornar o limite inferior.  
  
```
LONG GetLowerBound() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o limite inferior do `CComSafeArrayBound` objeto.  
  
##  <a name="getupperbound"></a>CComSafeArrayBound::GetUpperBound  
 Chame este método para retornar o limite superior.  
  
```
LONG GetUpperBound() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o limite superior do `CComSafeArrayBound` objeto.  
  
### <a name="remarks"></a>Comentários  
 O limite superior depende do número de elementos e o valor de limite inferior. Por exemplo, se o limite inferior é 0 e o número de elementos é 10, o limite superior será automaticamente definido como 9.  
  
##  <a name="operator_eq"></a>CComSafeArrayBound::operator =  
 Conjuntos de `CComSafeArrayBound` para um novo valor.  
  
```
CComSafeArrayBound& operator= (const CComSafeArrayBound& bound) throw();
CComSafeArrayBound& operator= (ULONG ulCount) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `bound`  
 Um objeto `CComSafeArrayBound`.  
  
 `ulCount`  
 O número de elementos.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o `CComSafeArrayBound` objeto.  
  
### <a name="remarks"></a>Comentários  
 O `CComSafeArrayBound` objeto pode ser atribuído usando uma existente `CComSafeArrayBound`, ou fornecendo o número de elementos, nesse caso o limite inferior é definido como 0 por padrão.  
  
##  <a name="setcount"></a>CComSafeArrayBound::SetCount  
 Chame este método para definir o número de elementos.  
  
```
ULONG SetCount(ULONG ulCount) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `ulCount`  
 O número de elementos.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de elementos de `CComSafeArrayBound` objeto.  
  
##  <a name="setlowerbound"></a>CComSafeArrayBound::SetLowerBound  
 Chame esse método para definir o limite inferior.  
  
```
LONG SetLowerBound(LONG lLowerBound) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `lLowerBound`  
 O limite inferior.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o novo limite inferior do `CComSafeArrayBound` objeto.  
  
### <a name="remarks"></a>Comentários  
 Se a matriz deve ser acessado a partir de um programa do Visual C++, é recomendável que o limite inferior seja definida como 0. Talvez seja preferível usar um valor de limite inferior diferente se a matriz é para ser usado com outras linguagens, como Visual Basic.  
  
 O limite superior depende do número de elementos e o valor de limite inferior. Por exemplo, se o limite inferior é 0 e o número de elementos é 10, o limite superior será automaticamente definido como 9.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
