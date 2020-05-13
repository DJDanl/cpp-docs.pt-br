---
title: Classe CAtlFileMapping
ms.date: 11/04/2016
f1_keywords:
- CAtlFileMapping
- atlfile/ATL::CAtlFileMapping
helpviewer_keywords:
- CAtlFileMapping class
ms.assetid: 899fc058-e05e-48b5-aca9-340403bb9e26
ms.openlocfilehash: 7516349e4ec54d8cb90fa6ff23b0ded954aa043b
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168118"
---
# <a name="catlfilemapping-class"></a>Classe CAtlFileMapping

Essa classe representa um arquivo mapeado por memória, adicionando um operador cast aos métodos de [CAtlFileMappingBase](../../atl/reference/catlfilemappingbase-class.md).

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename T = char>
class CAtlFileMapping : public CAtlFileMappingBase
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados usado para o operador cast.

## <a name="members"></a>Membros

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlFileMapping:: Operator T *](#operator_t_star)|Permite a conversão implícita `CAtlFileMapping` de objetos `T*`no.|

## <a name="remarks"></a>Comentários

Essa classe adiciona um único operador cast para permitir a conversão implícita `CAtlFileMapping` de objetos `T*`no. Outros membros são fornecidos pela classe base, [CAtlFileMappingBase](../../atl/reference/catlfilemappingbase-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CAtlFileMappingBase](../../atl/reference/catlfilemappingbase-class.md)

`CAtlFileMapping`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlfile. h

## <a name="catlfilemappingoperator-t"></a><a name="operator_t_star"></a>CAtlFileMapping:: Operator T *

Permite a conversão implícita `CAtlFileMapping` de objetos `T*`no.

```cpp
operator T*() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna um `T*` ponteiro para o início do arquivo mapeado para a memória.

### <a name="remarks"></a>Comentários

Chama [CAtlFileMappingBase:: GetData](../../atl/reference/catlfilemappingbase-class.md#getdata) e reinterpreta o ponteiro retornado como um `T*` em que *T* é o tipo usado como o parâmetro de modelo dessa classe.

## <a name="see-also"></a>Confira também

[Classe CAtlFileMappingBase](../../atl/reference/catlfilemappingbase-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
