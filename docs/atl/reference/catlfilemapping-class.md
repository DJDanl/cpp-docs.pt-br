---
title: Classe CAtlFileMapping | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CAtlFileMapping
- atlfile/ATL::CAtlFileMapping
dev_langs:
- C++
helpviewer_keywords:
- CAtlFileMapping class
ms.assetid: 899fc058-e05e-48b5-aca9-340403bb9e26
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 973501339d05f75414d076cbd22f5dabeb0bec7c
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43208717"
---
# <a name="catlfilemapping-class"></a>Classe CAtlFileMapping
Essa classe representa um arquivo mapeado em memória, adição de um operador cast para os métodos de [CAtlFileMappingBase](../../atl/reference/catlfilemappingbase-class.md).  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <typename T = char>  
class CAtlFileMapping : public CAtlFileMappingBase
```  
  
#### <a name="parameters"></a>Parâmetros  
 *T*  
 O tipo de dados usados para o operador cast.  
  
## <a name="members"></a>Membros  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlFileMapping::operator T *](#operator_t_star)|Permite a conversão implícita da `CAtlFileMapping` objetos à `T*`.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe adiciona um operador cast único para permitir que a conversão implícita de `CAtlFileMapping` objetos à `T*`. Outros membros são fornecidos pela classe base, [CAtlFileMappingBase](../../atl/reference/catlfilemappingbase-class.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CAtlFileMappingBase](../../atl/reference/catlfilemappingbase-class.md)  
  
 `CAtlFileMapping`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlfile.h  
  
##  <a name="operator_t_star"></a>  CAtlFileMapping::operator T *  
 Permite a conversão implícita da `CAtlFileMapping` objetos à `T*`.  
  
```  
operator T*() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um `T*` ponteiro para o início do arquivo mapeado em memória.  
  
### <a name="remarks"></a>Comentários  
 Chamadas [CAtlFileMappingBase::GetData](../../atl/reference/catlfilemappingbase-class.md#getdata) e reinterpreta o ponteiro retornado como um `T*` onde *T* é o tipo usado como o parâmetro de modelo dessa classe.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CAtlFileMappingBase](../../atl/reference/catlfilemappingbase-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
