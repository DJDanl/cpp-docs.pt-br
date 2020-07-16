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
ms.openlocfilehash: e1cb5df4a93fc642ccf4d500a5eb93690b0b3d75
ms.sourcegitcommit: 6b3d793f0ef3bbb7eefaf9f372ba570fdfe61199
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/15/2020
ms.locfileid: "86403811"
---
# <a name="odbc-calling-odbc-api-functions-directly"></a>ODBC: chamando funções de API ODBC diretamente

As classes de banco de dados fornecem uma interface mais simples para uma [fonte de dado](../../data/odbc/data-source-odbc.md) do que o ODBC. Como resultado, as classes não encapsulam toda a API ODBC. Para qualquer funcionalidade que esteja fora das capacidades das classes, você deve chamar diretamente as funções da API do ODBC. Por exemplo, você deve chamar as funções de catálogo ODBC ( `::SQLColumns` , `::SQLProcedures` , `::SQLTables` , e outras) diretamente.

> [!NOTE]
> As fontes de dados ODBC podem ser acessadas por meio das classes ODBC do MFC, conforme descrito neste tópico ou por meio das classes DAO (objeto de acesso a dados) do MFC.

Para chamar uma função de API ODBC diretamente, você deve executar as mesmas etapas que tomaria se estivesse fazendo as chamadas sem a estrutura. As etapas são:

- Aloque o armazenamento para todos os resultados retornados pela chamada.

- Passe um ODBC `HDBC` ou um `HSTMT` identificador, dependendo da assinatura de parâmetro da função. Use a macro [AFXGetHENV](../../mfc/reference/database-macros-and-globals.md#afxgethenv) para recuperar o identificador ODBC.

   As variáveis `CDatabase::m_hdbc` de membro e `CRecordset::m_hstmt` estão disponíveis para que você não precise alocá-las e inicializá-las por conta própria.

- Talvez chame funções ODBC adicionais para preparar ou acompanhar a chamada principal.

- Desaloque o armazenamento quando terminar.

Para obter mais informações sobre essas etapas, consulte a [referência do programador de ODBC](/sql/odbc/reference/odbc-programmer-s-reference).

Além dessas etapas, você precisa executar etapas adicionais para verificar valores de retorno de função, garantir que seu programa não esteja aguardando uma chamada assíncrona para concluir e assim por diante. Você pode simplificar essas últimas etapas usando as macros AFX_SQL_ASYNC e AFX_SQL_SYNC. Para obter mais informações, consulte [macros e globais do MFC](../../mfc/reference/mfc-macros-and-globals.md).

## <a name="see-also"></a>Confira também

[Noções básicas de ODBC](../../data/odbc/odbc-basics.md)
