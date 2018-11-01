---
title: Melhorando o provedor somente leitura simples
ms.date: 10/26/2018
helpviewer_keywords:
- read-only poviders [C++]
- IRowsetLocate class
- IRowsetLocate class, adding to OLE DB template providers
- simple read-only poviders [C++]
ms.assetid: cba0e09f-44c1-41c1-9456-332aa13dc158
ms.openlocfilehash: 4b06eb77851df0bf0bd0d3ef91a3ea960835ccba
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50462914"
---
# <a name="enhancing-the-simple-read-only-provider"></a>Melhorando o provedor somente leitura simples

Esta seção mostra como aprimorar a [provedor somente leitura simples](../../data/oledb/implementing-the-simple-read-only-provider.md) criado na seção anterior. `IRowsetLocateImpl` cria uma implementação para o `IRowsetLocate` de interface e adiciona suporte a indicadores para você.

Quando você tiver um provedor de trabalho, você talvez queira aprimorá-lo para fazer a atualização do provedor, lidar com transações ou melhorar o desempenho do algoritmo de busca de linhas. A maioria dos aprimoramentos de provedor envolvem a adição de uma interface para um objeto COM existente.

O exemplo nos tópicos a seguir aumenta o mecanismo de busca de linhas, adicionando a `IRowsetLocate` interface `CAgentRowset`. Os tópicos mostram como para:

- [Tornar RCustomRowset herdam IRowsetLocate](../../data/oledb/modifying-the-inheritance-of-rmyproviderrowset.md).

- [Determinar dinamicamente as colunas retornadas ao consumidor](../../data/oledb/dynamically-determining-columns-returned-to-the-consumer.md).

## <a name="see-also"></a>Consulte também

[Criando um provedor somente leitura simples](../../data/oledb/creating-a-simple-read-only-provider.md)<br/>
