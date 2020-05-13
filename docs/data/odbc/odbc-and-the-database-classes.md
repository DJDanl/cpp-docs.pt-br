---
title: Classes ODBC e de banco de dados
ms.date: 11/04/2016
helpviewer_keywords:
- database classes [C++], ODBC
- ODBC API functions [C++]
- ODBC classes [C++], MFC database classes
- MFC [C++], ODBC and
ms.assetid: b166f82d-6f85-4556-aac8-fb851235d22c
ms.openlocfilehash: 6511aab9bb048882fe9c3398dd17f769eb16220c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81320060"
---
# <a name="odbc-and-the-database-classes"></a>Classes ODBC e de banco de dados

As classes de banco de dados MFC ODBC encapsulam as chamadas de função API do ODBC que você normalmente se tornaria nas funções de membro das classes [CDatabase](../../mfc/reference/cdatabase-class.md) e [CRecordset.](../../mfc/reference/crecordset-class.md) Por exemplo, as complexas seqüências de chamadas ODBC, a vinculação de registros retornados aos locais de armazenamento, o manuseio de condições de erro e outras operações são gerenciadas para você pelas classes de banco de dados. Como resultado, você usa uma interface de classe consideravelmente mais simples para manipular registros através de um objeto de conjunto de registros.

> [!NOTE]
> As fontes de dados ODBC são acessíveis através das classes MFC ODBC, conforme descrito neste tópico, ou através das classes DAO (Data Access Object, objeto de acesso de dados do MFC).

Embora as classes de banco de dados encapsulam a funcionalidade do ODBC, elas não fornecem um mapeamento um-para-um das funções da API ODBC. As classes de banco de dados fornecem um nível mais alto de abstração, modelado após objetos de acesso a dados encontrados no Microsoft Access e no Microsoft Visual Basic. Para obter mais informações, consulte [ODBC e MFC](../../data/odbc/odbc-and-mfc.md).

## <a name="see-also"></a>Confira também

[Noções básicas de ODBC](../../data/odbc/odbc-basics.md)
