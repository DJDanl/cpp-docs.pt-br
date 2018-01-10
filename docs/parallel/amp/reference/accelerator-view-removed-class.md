---
title: Classe accelerator_view_removed | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- accelerator_view_removed
- AMPRT/accelerator_view_removed
- AMPRT/Concurrency::accelerator_view_removed:accelerator_view_removed
- AMPRT/Concurrency::accelerator_view_removed:get_view_removed_reason
dev_langs: C++
helpviewer_keywords: AMPRT/Concurrency::accelerator_view_removed:accelerator_view_removed Class
ms.assetid: 262446de-311c-454e-a5ed-e2aaced0d88a
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 68b770acd41956ec255718ee2e2db1c5ee556b9d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="acceleratorviewremoved-class"></a>Classe accelerator_view_removed
A exceção que é lançada quando uma chamada de DirectX subjacente falhar porque o mecanismo de detecção e recuperação de tempo limite do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class accelerator_view_removed : public runtime_exception;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor de accelerator_view_removed](#ctor)|Inicializa uma nova instância da classe `accelerator_view_removed`.|  

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

Inicializa uma nova instância do [accelerator_view_removed](accelerator-view-removed-class.md) classe.  
  
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
 Um código de erro HRESULT que indica a causa da remoção de `accelerator_view` objeto.  
  
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
