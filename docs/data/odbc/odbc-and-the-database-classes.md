---
title: Classes ODBC e de banco de dados
ms.date: 11/04/2016
helpviewer_keywords:
- database classes [C++], ODBC
- ODBC API functions [C++]
- ODBC classes [C++], MFC database classes
- MFC [C++], ODBC and
ms.assetid: b166f82d-6f85-4556-aac8-fb851235d22c
ms.openlocfilehash: 7c69f49cbe233eb0782fdaa9767ea55f4d04203c
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213146"
---
# <a name="odbc-and-the-database-classes"></a>Classes ODBC e de banco de dados

As classes de banco de dados ODBC do MFC encapsulam as chamadas de função da API do ODBC que normalmente você faria nas funções membro das classes [CDatabase](../../mfc/reference/cdatabase-class.md) e [CRecordset](../../mfc/reference/crecordset-class.md) . Por exemplo, as sequências de chamadas ODBC complexas, associação de registros retornados a locais de armazenamento, tratamento de condições de erro e outras operações são gerenciadas para você pelas classes de banco de dados. Como resultado, você usa uma interface de classe consideravelmente mais simples para manipular registros por meio de um objeto Recordset.

> [!NOTE]
>  As fontes de dados ODBC podem ser acessadas por meio das classes ODBC do MFC, conforme descrito neste tópico ou por meio das classes DAO (objeto de acesso a dados) do MFC.

Embora as classes de banco de dados encapsulam a funcionalidade ODBC, elas não fornecem um mapeamento um-para-um de funções da API do ODBC. As classes de banco de dados fornecem um nível mais alto de abstração, modelada após os objetos de acesso a dados encontrados no Microsoft Access e no Microsoft Visual Basic. Para obter mais informações, consulte [ODBC e MFC](../../data/odbc/odbc-and-mfc.md).

## <a name="see-also"></a>Confira também

[Noções básicas de ODBC](../../data/odbc/odbc-basics.md)
