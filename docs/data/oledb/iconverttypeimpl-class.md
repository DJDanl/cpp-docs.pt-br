---
title: Classe IConvertTypeImpl
ms.date: 11/04/2016
f1_keywords:
- ATL.IConvertTypeImpl<T>
- IConvertTypeImpl
- ATL.IConvertTypeImpl
- ATL::IConvertTypeImpl
- ATL::IConvertTypeImpl<T>
- IConvertTypeImpl.CanConvert
- CanConvert
- IConvertTypeImpl::CanConvert
helpviewer_keywords:
- IConvertTypeImpl class
- CanConvert method
ms.assetid: 7f81e79e-7d3f-4cbe-b93c-d632a94b15f6
ms.openlocfilehash: 0b3c0f239b3c80d0b4d3c8425b03a3612a0e6db2
ms.sourcegitcommit: c40469825b6101baac87d43e5f4aed6df6b078f5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2018
ms.locfileid: "51556225"
---
# <a name="iconverttypeimpl-class"></a>Classe IConvertTypeImpl

Fornece uma implementação de [IConvertType](https://docs.microsoft.com/previous-versions/windows/desktop/ms715926(v=vs.85)) interface.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
class ATL_NO_VTABLE IConvertTypeImpl
   : public IConvertType, public CConvertHelper
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IConvertTypeImpl`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldb.h

## <a name="members"></a>Membros

### <a name="interface-methods"></a>Métodos de interface

|||
|-|-|
|[CanConvert](#canconvert)|Fornece informações sobre a disponibilidade de conversões de tipo em um comando ou em um conjunto de linhas.|

## <a name="remarks"></a>Comentários

Essa interface é obrigatória em comandos, conjuntos de linhas e conjuntos de linhas do índice. `IConvertTypeImpl` implementa a interface delegando para o objeto de conversão fornecido pelo OLE DB.

## <a name="canconvert"></a> Iconverttypeimpl:: Canconvert

Fornece informações sobre a disponibilidade de conversões de tipo em um comando ou em um conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(CanConvert)(DBTYPE wFromType,
   DBTYPE wToType,
   DBCONVERTFLAGS dwConvertFlags);
```

#### <a name="parameters"></a>Parâmetros

Ver [IConvertType::CanConvert](https://docs.microsoft.com/previous-versions/windows/desktop/ms711224(v=vs.85)) na *referência do programador do OLE DB*.

### <a name="remarks"></a>Comentários

Usa a conversão de dados OLE DB em `MSADC.DLL`.

## <a name="see-also"></a>Consulte também

[Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)