---
title: Classe accelerator_view_removed | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- accelerator_view_removed
- AMPRT/accelerator_view_removed
- AMPRT/Concurrency::accelerator_view_removed:accelerator_view_removed
- AMPRT/Concurrency::accelerator_view_removed:get_view_removed_reason
dev_langs:
- C++
helpviewer_keywords:
- AMPRT/Concurrency::accelerator_view_removed:accelerator_view_removed Class
ms.assetid: 262446de-311c-454e-a5ed-e2aaced0d88a
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: c45eb8192266999c8771f6788de16859fe7a12c8
ms.lasthandoff: 03/17/2017

---
# <a name="acceleratorviewremoved-class"></a>Classe accelerator_view_removed
A exceção que é lançada quando uma chamada subjacente do DirectX falhar porque o mecanismo de detecção e recuperação de tempo limite do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class accelerator_view_removed : public runtime_exception;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor accelerator_view_removed](#ctor)|Inicializa uma nova instância da classe `accelerator_view_removed`.|  

### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[get_view_removed_reason](#get_view_removed_reason)|Retorna um código de erro HRESULT que indica a causa o `accelerator_view` remoção do objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `runtime_exception`  
  
 `out_of_memory`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amprt.h  
  
 **Namespace:** Simultaneidade  

## <a name="ctor"></a>accelerator_view_removed 

Inicializa uma nova instância de [accelerator_view_removed](accelerator-view-removed-class.md) classe.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
explicit accelerator_view_removed(  
    const char * _Message,  
    HRESULT _View_removed_reason ) throw();  
  
explicit accelerator_view_removed(  
    HRESULT _View_removed_reason ) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Message`  
 Uma descrição do erro.  
  
 `_View_removed_reason`  
 Um código de erro HRESULT indicando a causa da remoção de `accelerator_view` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma nova instância da classe accelerator_view_removed.  
  
## <a name="get_view_removed_reason_method"></a>get_view_removed_reason 

Retorna um código de erro HRESULT que indica a causa o `accelerator_view` remoção do objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
HRESULT get_view_removed_reason() const throw();  
```  
  
 
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)

