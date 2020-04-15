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
ms.openlocfilehash: 208749438f40eef746a638dd12373397c426d454
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368665"
---
# <a name="odbc-calling-odbc-api-functions-directly"></a>ODBC: chamando funções de API ODBC diretamente

As classes de banco de dados fornecem uma interface mais simples para uma fonte de [dados](../../data/odbc/data-source-odbc.md) do que o ODBC. Como resultado, as classes não encapsulam toda a API ODBC. Para qualquer funcionalidade que esteja fora das capacidades das classes, você deve chamar diretamente as funções de API do ODBC. Por exemplo, você deve chamar diretamente as`::SQLColumns` `::SQLProcedures`funções do catálogo ODBC ( , , `::SQLTables`e outros) diretamente.

> [!NOTE]
> As fontes de dados ODBC são acessíveis através das classes MFC ODBC, conforme descrito neste tópico, ou através das classes DAO (Data Access Object, objeto de acesso de dados do MFC).

Para chamar diretamente uma função DePi ODBC, você deve tomar os mesmos passos que tomaria se estivesse fazendo as chamadas sem o framework. Os passos são:

- Aloque o armazenamento para quaisquer resultados que a chamada devolva.

- Passe um ODBC `HDBC` ou `HSTMT` alça, dependendo da assinatura do parâmetro da função. Use a macro [AFXGetHENV](../../mfc/reference/database-macros-and-globals.md#afxgethenv) para recuperar a alça ODBC.

   As variáveis `CDatabase::m_hdbc` `CRecordset::m_hstmt` dos membros estão disponíveis para que você não precise alocar e inicializar essas mesmas.

- Talvez chamar funções adicionais de ODBC para preparar ou acompanhar a chamada principal.

- Desaloque o armazenamento quando terminar.

Para obter mais informações sobre essas etapas, consulte o SDK de [conectividade de banco de dados aberto (ODBC)](/sql/odbc/microsoft-open-database-connectivity-odbc) na documentação do MSDN.

Além dessas etapas, você precisa tomar medidas extras para verificar os valores de retorno da função, garantir que seu programa não esteja esperando uma chamada assíncrona para terminar, e assim por diante. Você pode simplificar esses últimos passos usando as macros AFX_SQL_ASYNC e AFX_SQL_SYNC. Para obter mais informações, consulte [Macros e Globals](../../mfc/reference/mfc-macros-and-globals.md) na *referência mfc*.

## <a name="see-also"></a>Confira também

[Noções básicas de ODBC](../../data/odbc/odbc-basics.md)
