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
ms.openlocfilehash: c612e8ea91882a6e744a8f47afe0decbeba85358
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367211"
---
# <a name="odbc-driver-requirements-for-dynasets"></a>Requisitos de driver ODBC para dynasets

Nas classes de banco de dados MFC ODBC, os dynasets são conjuntos de registros com propriedades dinâmicas; eles permanecem sincronizados com a fonte de dados de certas maneiras. Os dynasets MFC (mas não os conjuntos de registros somente para a frente) requerem um driver ODBC com conformidade API nível 2. Se o driver para sua fonte de [dados](../../data/odbc/data-source-odbc.md) estiver em conformidade com o conjunto de API nível 1, você ainda poderá usar instantâneos atualizáveis e somente leitura e conjuntos de registros somente para a frente, mas não dynasets. No entanto, um driver nível 1 pode suportar dinamismos se suportar cursores de busca estendida e chaveiros.

Na terminologia ODBC, dynasets e snapshots são chamados de cursores. Um cursor é um mecanismo usado para manter o controle de sua posição em um conjunto de registros. Para obter mais informações sobre os requisitos do driver para dynasets, consulte [Dynaset](../../data/odbc/dynaset.md). Para obter mais informações sobre cursores, consulte o SDK de conectividade de [banco de dados aberto (ODBC)](/sql/odbc/microsoft-open-database-connectivity-odbc) na documentação do MSDN.

> [!NOTE]
> Para conjuntos de registros atualizáveis, o driver ODBC `::SQLSetPos` deve suportar instruções de atualização posicionadas ou a função API ODBC. Se ambos forem suportados, o MFC usa `::SQLSetPos` para eficiência. Alternativamente, para instantâneos, você pode usar a biblioteca do cursor, que fornece o suporte necessário para instantâneos atualizáveis (cursores estáticos e instruções de atualização posicionadas).

## <a name="see-also"></a>Confira também

[Noções básicas de ODBC](../../data/odbc/odbc-basics.md)
