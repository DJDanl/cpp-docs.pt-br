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
ms.openlocfilehash: fed15dc2348fa540c1f33e7742c5cbcda96b5846
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37882527"
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
|[CAtlException::operator HRESULT](#operator_hresult)|Converte o objeto atual em um valor HRESULT.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlException::m_hr](#m_hr)|A variável do tipo HRESULT criado pelo objeto e usado para armazenar a condição de erro.|  
  
## <a name="remarks"></a>Comentários  
 Um `CAtlException` objeto representa uma condição de exceção relacionada a uma operação de ATL. O `CAtlException` classe inclui um membro de dados públicos que armazena o código de status que indica o motivo da exceção e um operador de conversão que permite que você trate a exceção como se fosse um HRESULT.  
  
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
 *hr*  
 O código de erro HRESULT.  
  
##  <a name="operator_hresult"></a>  CAtlException::operator HRESULT 
 Converte o objeto atual em um valor HRESULT.  
  
```  
operator HRESULT() const throw ();
```  
  
##  <a name="m_hr"></a>  CAtlException::m_hr  
 O membro de dados HRESULT.  
  
```
HRESULT m_hr;
```  
  
### <a name="remarks"></a>Comentários  
 O membro de dados que armazena a condição de erro. O valor HRESULT é definido pelo construtor, [CAtlException::CAtlException](#catlexception).  
  
## <a name="see-also"></a>Consulte também  
 [AtlThrow](debugging-and-error-reporting-global-functions.md#atlthrow)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
