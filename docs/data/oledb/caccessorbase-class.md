---
title: Classe CAccessorBase
ms.date: 11/04/2016
f1_keywords:
- CAccessorBase
- CAccessorBase.Close
- CAccessorBase::Close
- GetHAccessor
- CAccessorBase::GetHAccessor
- CAccessorBase.GetHAccessor
- CAccessorBase::GetNumAccessors
- GetNumAccessors
- CAccessorBase.GetNumAccessors
- IsAutoAccessor
- CAccessorBase.IsAutoAccessor
- CAccessorBase::IsAutoAccessor
- CAccessorBase::ReleaseAccessors
- CAccessorBase.ReleaseAccessors
- ReleaseAccessors
helpviewer_keywords:
- CAccessorBase class
- Close method
- GetHAccessor method
- GetNumAccessors method
- IsAutoAccessor method
- ReleaseAccessors method
ms.assetid: 389b65be-11ca-4ae0-9290-60c621c4982b
ms.openlocfilehash: 34c92f9057f2273d57b69bdb42c49a81923c3d2a
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59034946"
---
# <a name="caccessorbase-class"></a>Classe CAccessorBase

Todos os acessadores nos modelos OLE DB derivam dessa classe. `CAccessorBase` permite que um conjunto de linhas gerenciar vários acessadores. Ele também fornece uma associação de parâmetros e colunas de saída.

## <a name="syntax"></a>Sintaxe

```cpp
// Replace with syntax
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Fechar](#close)|Fecha os acessadores.|
|[GetHAccessor](#geth)|Recupera o identificador do acessador.|
|[GetNumAccessors](#getnum)|Recupera o número de acessadores criado pela classe.|
|[IsAutoAccessor](#isauto)|Testa se o acessador especificado é um autoaccessor.|
|[ReleaseAccessors](#release)|Libera os acessadores.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli.h

## <a name="close"></a> CAccessorBase::Close

Fecha os acessadores.

### <a name="syntax"></a>Sintaxe

```cpp
void Close();
```

### <a name="remarks"></a>Comentários

Você deve chamar [ReleaseAccessors](../../data/oledb/caccessorbase-releaseaccessors.md) primeiro.

## <a name="geth"></a> CAccessorBase::GetHAccessor

Recupera o identificador do acessador de um acessador especificado.

### <a name="syntax"></a>Sintaxe

```cpp
HACCESSOR GetHAccessor(ULONG nAccessor) const;
```

#### <a name="parameters"></a>Parâmetros

*nAccessor*<br/>
[in] O número de deslocamento zero do acessador.

### <a name="return-value"></a>Valor de retorno

Identificador do acessador.

## <a name="getnum"></a> CAccessorBase::GetNumAccessors

Recupera o número de acessadores criado pela classe.

### <a name="syntax"></a>Sintaxe

```cpp
ULONG GetNumAccessors() const;
```

### <a name="return-value"></a>Valor de retorno

O número de acessadores criado pela classe.

## <a name="isauto"></a> CAccessorBase::IsAutoAccessor

Retorna true se os dados são recuperados do acessador automaticamente durante uma operação de movimentação.

### <a name="syntax"></a>Sintaxe

```cpp
bool IsAutoAccessor(ULONG nAccessor) const;
```

#### <a name="parameters"></a>Parâmetros

*nAccessor*<br/>
[in] O número de deslocamento zero do acessador.

### <a name="return-value"></a>Valor de retorno

Retorna **verdadeira** se o acessador é uma autoaccessor. Caso contrário, retornará **falsos**.

## <a name="release"></a> CAccessorBase::ReleaseAccessors

Libera os acessadores criados pela classe.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT ReleaseAccessors(IUnknown* pUnk);
```

#### <a name="parameters"></a>Parâmetros

*pUnk*<br/>
[in] Um ponteiro para um `IUnknown` interface para o objeto COM para o qual foram criados os acessadores.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Chamado a partir [caccessorrowset:: Close](../../data/oledb/caccessorrowset-close.md).

## <a name="see-also"></a>Consulte também

[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)<br/>
[Classe CAccessorBase](../../data/oledb/caccessorbase-class.md)