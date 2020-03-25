---
title: Classe CNoAccessor
ms.date: 11/04/2016
f1_keywords:
- ATL::CNoAccessor
- CNoAccessor
- ATL.CNoAccessor
helpviewer_keywords:
- CNoAccessor class
ms.assetid: eb669ae5-0a56-49a3-9646-c4ae6239da31
ms.openlocfilehash: c82d756690c6c2a719cb03f458c471aa44e3d5b5
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80211725"
---
# <a name="cnoaccessor-class"></a>Classe CNoAccessor

Pode ser usado como um argumento de modelo (`TAccessor`) para classes de modelo, como `CCommand` e `CTable`, que exigem um argumento de classe de acessador.

## <a name="syntax"></a>Sintaxe

```cpp
class CNoAccessor
```

## <a name="remarks"></a>Comentários

Use `CNoAccessor` como um argumento de modelo quando você não quiser que a classe dê suporte a parâmetros ou colunas de saída.

`CNoAccessor` implementa os seguintes métodos stub, cada um dos quais corresponde a outros métodos de classe de acessador:

- `BindColumns`-associa colunas a acessadores.

- `BindParameters`-associa os parâmetros criados a colunas.

- `Bind`-cria associações.

- `Close`-fecha o acessador.

- `ReleaseAccessors`-libera os acessadores criados pela classe.

- `FreeRecordMemory` – libera Todas as colunas no registro atual que precisam ser liberadas.

- `GetColumnInfo`-Obtém informações de coluna do conjunto de linhas aberto.

- `GetNumAccessors` – recupera o número de acessadores criados pela classe.

- `IsAutoAccessor`-retornará true se os dados forem recuperados automaticamente para o acessador durante uma operação de movimentação.

- `GetHAccessor` – recupera o identificador de acessador de um acessador especificado.

- `GetBuffer`-recupera o ponteiro para o buffer de indicadores.

- `NoBindOnNullRowset`-impede a vinculação de dados em conjuntos de linhas vazios.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli. h

## <a name="see-also"></a>Confira também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)
