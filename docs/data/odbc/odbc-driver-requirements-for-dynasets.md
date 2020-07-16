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
ms.openlocfilehash: 4c436764649a1aa418e12300809482b45224dd46
ms.sourcegitcommit: 6b3d793f0ef3bbb7eefaf9f372ba570fdfe61199
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/15/2020
ms.locfileid: "86403836"
---
# <a name="odbc-driver-requirements-for-dynasets"></a>Requisitos de driver ODBC para dynasets

Nas classes de banco de dados ODBC do MFC, os dynasets são conjuntos de registros com propriedades dinâmicas; Eles permanecem sincronizados com a fonte de dados de determinadas maneiras. Os dynasets do MFC (mas não os conjuntos de registros somente de encaminhamento) exigem um driver ODBC com conformidade de API de nível 2. Se o driver da [fonte de dados](../../data/odbc/data-source-odbc.md) estiver em conformidade com o conjunto de API de nível 1, você ainda poderá usar instantâneos atualizáveis e somente leitura e conjuntos de registros somente de encaminhamento, mas não os dynasets. No entanto, um driver de nível 1 pode dar suporte a dynasets se ele der suporte a busca estendida e cursores controlados por conjunto de chaves.

Na terminologia ODBC, os dynasets e os instantâneos são chamados de cursores. Um cursor é um mecanismo usado para manter o controle de sua posição em um conjunto de registros. Para obter mais informações sobre os requisitos de driver para dynasets, consulte [dynaset](../../data/odbc/dynaset.md). Para obter mais informações sobre cursores, consulte a documentação [ODBC (Open Database Connectivity)](/sql/odbc/microsoft-open-database-connectivity-odbc) .

> [!NOTE]
> Para conjuntos de registros atualizáveis, seu driver ODBC deve dar suporte a ambas as instruções UPDATE posicionadas ou a `::SQLSetPos` função ODBC API. Se ambos tiverem suporte, o MFC usará `::SQLSetPos` para eficiência. Como alternativa, para instantâneos, você pode usar a biblioteca de cursores, que fornece o suporte necessário para instantâneos atualizáveis (cursores estáticos e instruções de atualização posicionadas).

## <a name="see-also"></a>Confira também

[Noções básicas de ODBC](../../data/odbc/odbc-basics.md)
