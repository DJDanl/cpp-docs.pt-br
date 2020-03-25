---
title: Classe CColumnAccessor
ms.date: 11/04/2016
f1_keywords:
- CColumnAccessor
- ATL::CColumnAccessor
- ATL.CColumnAccessor
helpviewer_keywords:
- CColumnAccessor class
ms.assetid: 6ce1e67f-6a20-490d-9326-c168b43eee7e
ms.openlocfilehash: 2a3b1dac51a8300a915a7177c36f15512b583fa0
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212104"
---
# <a name="ccolumnaccessor-class"></a>Classe CColumnAccessor

Gera código de consumidor injetado.

## <a name="syntax"></a>Sintaxe

```cpp
class CColumnAccessor : public CAccessorBase
```

## <a name="remarks"></a>Comentários

No código injetado, cada coluna é associada como um acessador separado. Você deve estar ciente de que essa classe é usada no código injetado (por exemplo, você pode encontrá-la durante a depuração), mas normalmente nunca precisa usá-la ou seus métodos diretamente.

`CColumnAccessor` implementa os seguintes métodos stub, cada um dos quais corresponde à funcionalidade a outros métodos de classe de acessador:

- `CColumnAccessor` o Construtor; Cria uma instância e inicializa o objeto `CColumnAccessor`.

- `CreateAccessor` aloca memória para as estruturas de associação de coluna e inicializa os membros de dados de coluna.

- `BindColumns` associa colunas a acessadores.

- `SetParameterBuffer` aloca buffers para parâmetros.

- `AddParameter` adiciona uma entrada de parâmetro às estruturas de entrada de parâmetro.

- `HasOutputColumns` determina se o acessador tem colunas de saída

- `HasParameters` determina se o acessador tem parâmetros.

- `BindParameters` associa os parâmetros criados a colunas.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli. h

## <a name="see-also"></a>Confira também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)
