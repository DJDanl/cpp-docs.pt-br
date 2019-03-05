---
title: Classe CAtlFileMapping
ms.date: 11/04/2016
f1_keywords:
- CAtlFileMapping
- atlfile/ATL::CAtlFileMapping
helpviewer_keywords:
- CAtlFileMapping class
ms.assetid: 899fc058-e05e-48b5-aca9-340403bb9e26
ms.openlocfilehash: d0a47a6cf0cc86409ceb9ef40d6fc6d738c86aa9
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57263475"
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

*T*<br/>
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

[Classe CAtlFileMappingBase](../../atl/reference/catlfilemappingbase-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
