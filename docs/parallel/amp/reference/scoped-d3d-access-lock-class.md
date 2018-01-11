---
title: Classe scoped_d3d_access_lock | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- scoped_d3d_access_lock
- AMPRT/scoped_d3d_access_lock
- AMPRT/concurrency::direct3d::scoped_d3d_access_lock::scoped_d3d_access_lock
dev_langs: C++
ms.assetid: 0ad333e6-9839-4736-a722-16d95d70c4b1
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 37dadc932701354de317d253a39bd2f2ee71a495
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="scopedd3daccesslock-class"></a>Classe scoped_d3d_access_lock
Wrapper RAII para um bloqueio de acesso do D3D em um objeto accelerator_view.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
class scoped_d3d_access_lock;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor scoped_d3d_access_lock](#ctor)|Sobrecarregado. Constrói um objeto `scoped_d3d_access_lock`. O bloqueio é liberado quando este objeto sai do escopo.|  
|[~ Destruidor scoped_d3d_access_lock](#dtor)|Libera o bloqueio de acesso do D3D em associado `accelerator_view` objeto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operator=](#operator_eq)|Apropriar-se de um bloqueio de outro `scoped_d3d_access_lock`.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `scoped_d3d_access_lock`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amprt.h  
  
 **Namespace:** Concurrency:: Direct3D  

##  <a name="ctor"></a>scoped_d3d_access_lock 

 Constrói um objeto `scoped_d3d_access_lock`. O bloqueio é liberado quando este objeto sai do escopo.  
 
```  
explicit scoped_d3d_access_lock(// [1] constructor  
    accelerator_view& _Av);

 
explicit scoped_d3d_access_lock(// [2] constructor  
    accelerator_view& _Av,  
    adopt_d3d_access_lock_t _T);

 
scoped_d3d_access_lock(// [3] move constructor  
    scoped_d3d_access_lock&& _Other);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Av`  
 O `accelerator_view` para adotar o bloqueio.  
  
 `_T`  
 O objeto `adopt_d3d_access_lock_t`.  
  
 `_Other`  
 O `scoped_d3d_access_lock` objeto do qual deseja mover um bloqueio existente.  
  
## <a name="construction"></a>Construção  
 [1] construtor  
 Adquire um bloqueio de acesso do D3D na determinado [accelerator_view](accelerator-view-class.md) objeto. Blocos de construção até que o bloqueio é adquirido.  
  
 [2] construtor  
 Adotar um bloqueio de acesso do D3D da determinado [accelerator_view](accelerator-view-class.md) objeto.  
  
 [3] construtor de movimentação para  
 Usa um bloqueio de acesso D3D existente de outro `scoped_d3d_access_lock` objeto. Não bloqueia a construção.  

  
##  <a name="dtor"></a>~ scoped_d3d_access_lock 

 Libera o bloqueio de acesso do D3D em associado `accelerator_view` objeto.  
  
```  
~scoped_d3d_access_lock();
```  
## <a name="operator_eq"></a>operador = 

Apropriar-se de um bloqueio de acesso do D3D de outro `scoped_d3d_access_lock` objeto, liberar o bloqueio anterior.  
 
```  
scoped_d3d_access_lock& operator= (scoped_d3d_access_lock&& _Other);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 Accelerator_view do qual deseja mover o bloqueio de acesso do D3D.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a este `scoped_accelerator_view_lock`.  

## <a name="see-also"></a>Consulte também  
 [Namespace Concurrency::direct3d](concurrency-direct3d-namespace.md)
