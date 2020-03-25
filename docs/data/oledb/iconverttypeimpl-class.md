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
ms.openlocfilehash: e3b76be2a1f1edfcdc1139a3dd396835923c2b4a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80210685"
---
# <a name="iconverttypeimpl-class"></a>Classe IConvertTypeImpl

Fornece uma implementação da interface [IConvertType](/previous-versions/windows/desktop/ms715926(v=vs.85)) .

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
class ATL_NO_VTABLE IConvertTypeImpl
   : public IConvertType, public CConvertHelper
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Sua classe, derivada de `IConvertTypeImpl`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="interface-methods"></a>Métodos de interface

|||
|-|-|
|[Canconverter](#canconvert)|Fornece informações sobre a disponibilidade de conversões de tipo em um comando ou em um conjunto de linhas.|

## <a name="remarks"></a>Comentários

Essa interface é obrigatória em comandos, conjuntos de linhas e conjuntos de linhas de índice. `IConvertTypeImpl` implementa a interface delegando ao objeto de conversão fornecido pelo OLE DB.

## <a name="iconverttypeimplcanconvert"></a><a name="canconvert"></a>IConvertTypeImpl:: CanConvert

Fornece informações sobre a disponibilidade de conversões de tipo em um comando ou em um conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(CanConvert)(DBTYPE wFromType,
   DBTYPE wToType,
   DBCONVERTFLAGS dwConvertFlags);
```

#### <a name="parameters"></a>parâmetros

Consulte [IConvertType:: CanConvert](/previous-versions/windows/desktop/ms711224(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="remarks"></a>Comentários

Usa OLE DB conversão de dados em `MSADC.DLL`.

## <a name="see-also"></a>Confira também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)
