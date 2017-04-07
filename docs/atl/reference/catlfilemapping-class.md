---
title: Classe CAtlFileMapping | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAtlFileMapping
- atlfile/ATL::CAtlFileMapping
dev_langs:
- C++
helpviewer_keywords:
- CAtlFileMapping class
ms.assetid: 899fc058-e05e-48b5-aca9-340403bb9e26
caps.latest.revision: 20
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
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: 2693647af904eab1ed0f84bc406bc1207d4a9b8c
ms.lasthandoff: 02/25/2017

---
# <a name="catlfilemapping-class"></a>Classe CAtlFileMapping
Essa classe representa um arquivo de memória mapeada, adicionando um operador cast para os métodos de [CAtlFileMappingBase](../../atl/reference/catlfilemappingbase-class.md).  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <typename T = char>  
class CAtlFileMapping : public CAtlFileMappingBase
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados usados para o operador cast.  
  
## <a name="members"></a>Membros  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlFileMapping::operator T *](#operator_t_star)|Permite a conversão implícita de `CAtlFileMapping` objetos `T` ** \* **.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe adiciona um operador cast único para permitir a conversão implícita do `CAtlFileMapping` objetos `T` ** \* **. Outros membros são fornecidos pela classe base, [CAtlFileMappingBase](../../atl/reference/catlfilemappingbase-class.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CAtlFileMappingBase](../../atl/reference/catlfilemappingbase-class.md)  
  
 `CAtlFileMapping`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlfile.h  
  
##  <a name="operator_t_star"></a>CAtlFileMapping::operator T *  
 Permite a conversão implícita de `CAtlFileMapping` objetos `T` ** \* **.  
  
```  
operator T*() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um `T` ** \* ** ponteiro para o início do arquivo de memória mapeada.  
  
### <a name="remarks"></a>Comentários  
 Chamadas [CAtlFileMappingBase::GetData](../../atl/reference/catlfilemappingbase-class.md#getdata) e reinterprets o ponteiro retornado como um `T` ** \* ** onde *T* é o tipo usado como o parâmetro de modelo dessa classe.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CAtlFileMappingBase](../../atl/reference/catlfilemappingbase-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

