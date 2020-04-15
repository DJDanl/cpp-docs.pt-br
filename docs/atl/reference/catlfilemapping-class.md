---
title: Classe catlfilemapping
ms.date: 11/04/2016
f1_keywords:
- CAtlFileMapping
- atlfile/ATL::CAtlFileMapping
helpviewer_keywords:
- CAtlFileMapping class
ms.assetid: 899fc058-e05e-48b5-aca9-340403bb9e26
ms.openlocfilehash: ca46ccdacf5ea24f1de26cdc75bf808c4ecfaa40
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318952"
---
# <a name="catlfilemapping-class"></a>Classe catlfilemapping

Esta classe representa um arquivo mapeado pela memória, adicionando um operador de elenco aos métodos do [CAtlFileMappingBase](../../atl/reference/catlfilemappingbase-class.md).

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <typename T = char>
class CAtlFileMapping : public CAtlFileMappingBase
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados utilizados para o operador de elenco.

## <a name="members"></a>Membros

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlFileMapping::operador T*](#operator_t_star)|Permite a `CAtlFileMapping` conversão `T*`implícita de objetos para .|

## <a name="remarks"></a>Comentários

Esta classe adiciona um único operador `CAtlFileMapping` de `T*`elenco para permitir a conversão implícita de objetos para . Outros membros são fornecidos pela classe base, [CAtlFileMappingBase](../../atl/reference/catlfilemappingbase-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Catlfilemappingbase](../../atl/reference/catlfilemappingbase-class.md)

`CAtlFileMapping`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlfile.h

## <a name="catlfilemappingoperator-t"></a><a name="operator_t_star"></a>CAtlFileMapping::operador T*

Permite a `CAtlFileMapping` conversão `T*`implícita de objetos para .

```
operator T*() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna `T*` um ponteiro para o início do arquivo mapeado pela memória.

### <a name="remarks"></a>Comentários

Chama [CAtlFileMappingBase::GetData](../../atl/reference/catlfilemappingbase-class.md#getdata) e reinterpreta o ponteiro `T*` retornado como um em que *T* é o tipo usado como parâmetro de modelo desta classe.

## <a name="see-also"></a>Confira também

[CAtlFileMappingBase Class](../../atl/reference/catlfilemappingbase-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
