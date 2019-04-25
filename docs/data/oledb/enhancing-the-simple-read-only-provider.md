---
title: Melhorando o provedor somente leitura simples
ms.date: 10/26/2018
helpviewer_keywords:
- read-only poviders [C++]
- IRowsetLocate class
- IRowsetLocate class, adding to OLE DB template providers
- simple read-only poviders [C++]
ms.assetid: cba0e09f-44c1-41c1-9456-332aa13dc158
ms.openlocfilehash: d61f24a9a9abffe836a7f11bd5d1517fddf97fe7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62175349"
---
# <a name="enhancing-the-simple-read-only-provider"></a>Melhorando o provedor somente leitura simples

Esta seção mostra como aprimorar a [provedor somente leitura simples](../../data/oledb/implementing-the-simple-read-only-provider.md) criado na seção anterior. `IRowsetLocateImpl` cria uma implementação para o `IRowsetLocate` de interface e adiciona suporte a indicadores para você.

Quando você tiver um provedor de trabalho, você talvez queira aprimorá-lo para fazer a atualização do provedor, lidar com transações ou melhorar o desempenho do algoritmo de busca de linhas. A maioria dos aprimoramentos de provedor envolvem a adição de uma interface para um objeto COM existente.

O exemplo nos tópicos a seguir aumenta o mecanismo de busca de linhas, adicionando a `IRowsetLocate` interface `CAgentRowset`. Os tópicos mostram como para:

- [Tornar RCustomRowset herdam IRowsetLocate](../../data/oledb/modifying-the-inheritance-of-rmyproviderrowset.md).

- [Determinar dinamicamente as colunas retornadas ao consumidor](../../data/oledb/dynamically-determining-columns-returned-to-the-consumer.md).

## <a name="see-also"></a>Consulte também

[Criando um provedor somente leitura simples](../../data/oledb/creating-a-simple-read-only-provider.md)<br/>
