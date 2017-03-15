---
title: Classe scoped_d3d_access_lock | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 0ad333e6-9839-4736-a722-16d95d70c4b1
caps.latest.revision: 8
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
ms.sourcegitcommit: fc190feb08d9b221cd1cc21a9c91ad567c86c848
ms.openlocfilehash: c5bc6183b3abc7a5598159717b0dbfa1dae2a05d
ms.lasthandoff: 02/25/2017

---
# <a name="scopedd3daccesslock-class"></a>Classe scoped_d3d_access_lock
Wrapper RAII para um bloqueio de acesso D3D em um objeto accelerator_view.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
class scoped_d3d_access_lock;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor scoped_d3d_access_lock](#ctor)|Sobrecarregado. Constrói um objeto `scoped_d3d_access_lock`. O bloqueio é liberado quando esse objeto sai do escopo.|  
|[~ Destruidor scoped_d3d_access_lock](#dtor)|Libera o bloqueio de acesso D3D em associado `accelerator_view` objeto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operador Operator =](#operator_eq)|Apropriar-se de um bloqueio de outro `scoped_d3d_access_lock`.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `scoped_d3d_access_lock`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amprt.h  
  
 **Namespace:** Concurrency:: Direct3D  

##  <a name="a-namectora-scopedd3daccesslock"></a><a name="ctor"></a>scoped_d3d_access_lock 

 Constrói um objeto `scoped_d3d_access_lock`. O bloqueio é liberado quando esse objeto sai do escopo.  
 
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
 Adquire um bloqueio de acesso D3D na determinado [accelerator_view](accelerator-view-class.md) objeto. Blocos de construção até que o bloqueio é adquirido.  
  
 [2] construtor  
 Adotar um bloqueio de acesso D3D da determinado [accelerator_view](accelerator-view-class.md) objeto.  
  
 [3] construtor de movimentação  
 Usa um bloqueio de acesso D3D existente de outro `scoped_d3d_access_lock` objeto. Não bloqueia a construção.  

  
##  <a name="a-namedtora-scopedd3daccesslock"></a><a name="dtor"></a>~ scoped_d3d_access_lock 

 Libera o bloqueio de acesso D3D em associado `accelerator_view` objeto.  
  
```  
~scoped_d3d_access_lock();
```  
## <a name="a-nameoperatoreqa-operator"></a><a name="operator_eq"></a>operador = 

Apropriar-se de um bloqueio de acesso D3D de outro `scoped_d3d_access_lock` objeto, liberar o bloqueio anterior.  
 
```  
scoped_d3d_access_lock& operator= (scoped_d3d_access_lock&& _Other);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 Accelerator_view do qual deseja mover o bloqueio de acesso D3D.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a esta `scoped_accelerator_view_lock`.  

## <a name="see-also"></a>Consulte também  
 [Namespace Concurrency:: Direct3D](concurrency-direct3d-namespace.md)

