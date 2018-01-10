---
title: Classe CDefaultCharTraits | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDefaultCharTraits
- ATLCOLL/ATL::CDefaultCharTraits
- ATLCOLL/ATL::CDefaultCharTraits::CharToLower
- ATLCOLL/ATL::CDefaultCharTraits::CharToUpper
dev_langs: C++
helpviewer_keywords: CDefaultCharTraits class
ms.assetid: f94a3934-597f-401d-8513-ed6924ae069a
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 283f588af0e824801fbec13f32ae1276c13eb724
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cdefaultchartraits-class"></a>Classe CDefaultCharTraits
Essa classe fornece duas funções estáticas para conversão de caracteres entre maiusculas e minúsculas.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <typename T>  
class CDefaultCharTraits
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados a serem armazenados na coleção.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDefaultCharTraits::CharToLower](#chartolower)|(Estático) Chame essa função para converter um caractere em maiusculas.|  
|[CDefaultCharTraits::CharToUpper](#chartoupper)|(Estático) Chame essa função para converter um caractere em minúsculas.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece funções que são usadas pela classe [CStringElementTraitsI](../../atl/reference/cstringelementtraitsi-class.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
##  <a name="chartolower"></a>CDefaultCharTraits::CharToLower  
 Chame essa função para converter um caractere em minúsculas.  
  
```
static wchar_t CharToLower(wchar_t x);  
static char CharToLower(char x);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 O caractere a ser convertido em minúsculas.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities#132](../../atl/codesnippet/cpp/cdefaultchartraits-class_1.cpp)]  
  
##  <a name="chartoupper"></a>CDefaultCharTraits::CharToUpper  
 Chame essa função para converter um caractere em maiusculas.  
  
```
static wchar_t CharToUpper(wchar_t x);  
static char CharToUpper(char x);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 O caractere a ser convertido em maiúsculas.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
