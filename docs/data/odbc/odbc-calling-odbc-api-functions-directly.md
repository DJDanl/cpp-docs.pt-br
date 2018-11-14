---
title: 'ODBC: chamando funções de API ODBC diretamente'
ms.date: 11/04/2016
helpviewer_keywords:
- ODBC API functions [C++], calling
- ODBC [C++], catalog functions
- ODBC API functions [C++]
- APIs [C++], calling
- ODBC classes [C++], vs. ODBC API
- direct ODBC API calls
- catalog functions (ODBC)
- catalog functions (ODBC), calling
- ODBC [C++], API functions
ms.assetid: 4295f1d9-4528-4d2e-bd6a-c7569953c7fa
ms.openlocfilehash: e76ff4da090a00409465333f8cbc9816ab4c4de6
ms.sourcegitcommit: afd6fac7c519dbc47a4befaece14a919d4e0a8a2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2018
ms.locfileid: "51518333"
---
# <a name="odbc-calling-odbc-api-functions-directly"></a>ODBC: chamando funções de API ODBC diretamente

As classes de banco de dados fornecem uma interface mais simples para um [fonte de dados](../../data/odbc/data-source-odbc.md) que o ODBC. Como resultado, as classes não encapsulam toda a API de ODBC. Para qualquer funcionalidade que está fora as capacidades das classes, você deve chamar funções API ODBC diretamente. Por exemplo, você deve chamar as funções de catálogo ODBC (`::SQLColumns`, `::SQLProcedures`, `::SQLTables`e outros) diretamente.

> [!NOTE]
>  Fontes de dados ODBC são acessíveis por meio de classes MFC ODBC, conforme descrito neste tópico, ou as classes de objeto de acesso a dados MFC (DAO).

Para chamar uma função de API ODBC diretamente, você deve levar as mesmas etapas que você levaria se você estava fazendo as chamadas sem a estrutura. Eles são etapas:

- Alocar armazenamento para todos os resultados que do retorno da chamada.

- Passar um ODBC `HDBC` ou `HSTMT` tratar, dependendo da assinatura do parâmetro da função. Use o [AFXGetHENV](../../mfc/reference/database-macros-and-globals.md#afxgethenv) macro para recuperar o identificador ODBC.

   Variáveis de membro `CDatabase::m_hdbc` e `CRecordset::m_hstmt` estão disponíveis para que você não precisa alocar e inicializar esses por conta própria.

- Talvez, chame funções adicionais do ODBC para se preparar para ou execute a chamada principal.

- Desalocar o armazenamento ao concluir.

Para obter mais informações sobre essas etapas, consulte a [conectividade aberta de banco de dados (ODBC)](/sql/odbc/microsoft-open-database-connectivity-odbc) SDK na documentação do MSDN.

Além dessas etapas, você precisa executar etapas adicionais para verificar os valores de retorno de função, certifique-se de que seu programa não está aguardando uma chamada assíncrona para concluir e assim por diante. Você pode simplificar essas últimas etapas, usando as macros AFX_SQL_ASYNC e AFX_SQL_SYNC. Para obter mais informações, consulte [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md) na *referência da MFC*.

## <a name="see-also"></a>Consulte também

[Noções básicas de ODBC](../../data/odbc/odbc-basics.md)
