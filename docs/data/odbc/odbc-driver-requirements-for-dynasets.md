---
title: Requisitos de driver ODBC para dynasets
ms.date: 11/04/2016
helpviewer_keywords:
- ODBC recordsets, dynasets
- drivers, for dynasets
- drivers, ODBC
- recordsets, dynasets
- dynasets
- ODBC drivers, dynasets
ms.assetid: 585cc67b-4d92-404b-9903-d769cd17badc
ms.openlocfilehash: c44e34023ecdeb994ea3a60ea3b699cd5b1488a3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62395749"
---
# <a name="odbc-driver-requirements-for-dynasets"></a>Requisitos de driver ODBC para dynasets

As classes de banco de dados ODBC do MFC, dynasets são conjuntos de registros com propriedades dinâmicas; eles permanecem sincronizados com a fonte de dados de determinadas maneiras. MFC dynasets (mas não apenas de encaminhamento de conjuntos de registros) exigem um driver ODBC com conformidade com a API do nível 2. Se o driver para o seu [fonte de dados](../../data/odbc/data-source-odbc.md) está de acordo com a API de nível 1 definido, você ainda pode usar instantâneos atualizáveis tanto como somente leitura e somente de encaminhamento de conjuntos de registros, mas não dynasets. No entanto, um driver de nível 1 pode dar suporte a dynasets se ele dá suporte a busca estendida e cursores controlados por conjunto de chaves.

Na terminologia do ODBC, dynasets e os instantâneos são denominados cursores. Um cursor é um mecanismo usado para controlar sua posição em um conjunto de registros. Para obter mais informações sobre os requisitos de driver para dynasets, consulte [Dynaset](../../data/odbc/dynaset.md). Para obter mais informações sobre cursores, consulte o [conectividade aberta de banco de dados (ODBC)](/sql/odbc/microsoft-open-database-connectivity-odbc) SDK na documentação do MSDN.

> [!NOTE]
>  Para conjuntos de registros pode ser atualizados, o driver ODBC deve oferecer suporte das instruções de atualização posicionada ou o `::SQLSetPos` função ODBC API. Se ambos forem compatíveis, o MFC usa `::SQLSetPos` para maior eficiência. Como alternativa, para instantâneos, você pode usar a biblioteca de cursores, que fornece o suporte necessário para instantâneos atualizáveis (Cursores estáticos e instruções update posicionadas).

## <a name="see-also"></a>Consulte também

[Noções básicas de ODBC](../../data/odbc/odbc-basics.md)