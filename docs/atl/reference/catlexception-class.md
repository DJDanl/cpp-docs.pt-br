---
title: Classe CAtlException | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: aaafdf42d218e2c3bca1e8ee28c27898f80bcf40
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32357864"
---
# <a name="catlexception-class"></a>Classe CAtlException
Essa classe define uma exceção de ATL.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CAtlException
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
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
|[CAtlException::m_hr](#m_hr)|A variável de tipo de HRESULT criados pelo objeto usado para armazenar a condição de erro.|  
  
## <a name="remarks"></a>Comentários  
 Um `CAtlException` objeto representa uma condição de exceção relacionada a uma operação de ATL. O `CAtlException` classe inclui um membro de dados pública que armazena o código de status indicando o motivo para a exceção e um operador de conversão que permite que você trate a exceção, como se fosse um HRESULT.  
  
 Em geral, você chamará `AtlThrow` em vez de criar um `CAtlException` diretamente do objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlexcept.h  
  
##  <a name="catlexception"></a>  CAtlException::CAtlException  
 O construtor.  
  
```
CAtlException(HRESULT hr) throw();
CAtlException() throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `hr`  
 O código de erro `HRESULT`.  
  
##  <a name="operator_hresult"></a>  CAtlException::operator HRESULT 
 Converte o objeto atual com um valor HRESULT.  
  
```  
operator HRESULT() const throw ();
```  
  
##  <a name="m_hr"></a>  CAtlException::m_hr  
 O `HRESULT` membro de dados.  
  
```
HRESULT m_hr;
```  
  
### <a name="remarks"></a>Comentários  
 O membro de dados que armazena a condição de erro. O valor HRESULT é definido pelo construtor, [CAtlException::CAtlException](#catlexception).  
  
## <a name="see-also"></a>Consulte também  
 [AtlThrow](debugging-and-error-reporting-global-functions.md#atlthrow)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
