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
ms.openlocfilehash: 0cf1b47cc03d1839ae5c547393c3c193dab439d4
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62230458"
---
# <a name="cnoaccessor-class"></a>Classe CNoAccessor

Pode ser usado como um argumento de modelo (`TAccessor`) para classes de modelo, como `CCommand` e `CTable`, que exigem um argumento de classe de acessador.

## <a name="syntax"></a>Sintaxe

```cpp
class CNoAccessor
```

## <a name="remarks"></a>Comentários

Use `CNoAccessor` como um argumento de modelo quando você não deseja que a classe para dar suporte a parâmetros ou colunas de saída.

`CNoAccessor` implementa os seguintes métodos de stub, cada um dos quais correspondem aos outros métodos de classe de acessador:

- `BindColumns` -Associa as colunas para acessadores.

- `BindParameters` -Associa os parâmetros criados para colunas.

- `Bind` -Cria associações.

- `Close` -Fecha o acessador.

- `ReleaseAccessors` -Libera os acessadores criados pela classe.

- `FreeRecordMemory` -Libera quaisquer colunas no registro atual que precise ser liberada.

- `GetColumnInfo` -Obtém informações de coluna do conjunto de linhas aberto.

- `GetNumAccessors` -Recupera o número de acessadores criado pela classe.

- `IsAutoAccessor` -Retorna true se os dados são recuperados do acessador automaticamente durante uma operação de movimentação.

- `GetHAccessor` -Recupera o identificador do acessador de um acessador especificado.

- `GetBuffer` -Recupera o ponteiro para o buffer de indicador.

- `NoBindOnNullRowset` -Impede que a associação de dados em conjuntos de linhas vazios.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli.h

## <a name="see-also"></a>Consulte também

[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)