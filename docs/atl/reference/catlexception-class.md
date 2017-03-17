---
title: Classe CAtlException | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAtlException
- ATLEXCEPT/ATL::CAtlException
- ATLEXCEPT/ATL::CAtlException::CAtlException
- ATLEXCEPT/ATL::CAtlException::m_hr
dev_langs:
- C++
helpviewer_keywords:
- CAtlException class
ms.assetid: 3fd7b041-f70d-4292-b947-0d70781d95a8
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
translationtype: Machine Translation
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: 30c9235f16581c86ab5612522909dc366b1ce17e
ms.lasthandoff: 02/25/2017

---
# <a name="catlexception-class"></a>Classe CAtlException
Essa classe define uma exceção ATL.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CAtlException
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlException::CAtlException](#catlexception)|O construtor.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlException::operator HRESULT](#operator_hresult)|Converte o objeto atual com um valor HRESULT.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlException::m_hr](#m_hr)|A variável do tipo HRESULT criados pelo objeto e usado para armazenar a condição de erro.|  
  
## <a name="remarks"></a>Comentários  
 Um `CAtlException` objeto representa uma condição de exceção relacionada a uma operação de ATL. O `CAtlException` classe inclui um membro de dados pública que armazena o código de status indicando o motivo da exceção e um operador de conversão que permite que você trate a exceção como se fosse um HRESULT.  
  
 Em geral, você chamará `AtlThrow` em vez de criar um `CAtlException` diretamente do objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlexcept.h  
  
##  <a name="catlexception"></a>CAtlException::CAtlException  
 O construtor.  
  
```
CAtlException(HRESULT hr) throw();
CAtlException() throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `hr`  
 O `HRESULT` código de erro.  
  
##  <a name="operator_hresult"></a>CAtlException::operator HRESULT 
 Converte o objeto atual com um valor HRESULT.  
  
```  
operator HRESULT() const throw ();
```  
  
##  <a name="m_hr"></a>CAtlException::m_hr  
 O `HRESULT` membro de dados.  
  
```
HRESULT m_hr;
```  
  
### <a name="remarks"></a>Comentários  
 O membro de dados que armazena a condição de erro. O valor HRESULT é definido pelo construtor, [CAtlException::CAtlException](#catlexception).  
  
## <a name="see-also"></a>Consulte também  
 [AtlThrow](http://msdn.microsoft.com/library/2bd111da-8170-488d-914a-c9bf6b6765f7)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

