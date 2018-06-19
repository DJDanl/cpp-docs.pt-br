---
title: 'ODBC: Funções chamando a API ODBC diretamente | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 55b95c5dd48631f9c724aebd163ce948c3469850
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33089706"
---
# <a name="odbc-calling-odbc-api-functions-directly"></a>ODBC: chamando funções de API ODBC diretamente
As classes de banco de dados fornecem uma interface simples para um [fonte de dados](../../data/odbc/data-source-odbc.md) que o ODBC. Como resultado, as classes não encapsulam a API de ODBC. Para qualquer funcionalidade que fica fora a capacidade das classes, você deve chamar funções API ODBC diretamente. Por exemplo, você deve chamar as funções de catálogo ODBC (**:: SQLColumns**, **:: SQLProcedures**, **:: SQLTables**e outros) diretamente.  
  
> [!NOTE]
>  Fontes de dados ODBC são acessíveis por meio de classes MFC ODBC, conforme descrito neste tópico, ou as classes de objeto de acesso a dados MFC (DAO).  
  
 Para chamar uma função de API ODBC diretamente, você deve executar as mesmas etapas que necessárias se você estava fazendo as chamadas sem a estrutura. Eles são etapas:  
  
-   Alocar armazenamento para a chamada retorna resultados.  
  
-   Passar um ODBC **HDBC** ou **HSTMT** tratar, dependendo da assinatura de parâmetro da função. Use o [AFXGetHENV](../../mfc/reference/database-macros-and-globals.md#afxgethenv) macro para recuperar o identificador do ODBC.  
  
     Variáveis de membro **CDatabase::m_hdbc** e **CRecordset::m_hstmt** estão disponíveis para que você não precisa alocar e inicializar esses por conta própria.  
  
-   Talvez chame funções adicionais do ODBC para preparar-se ou acompanhar a chamada principal.  
  
-   Desalocar armazenamento quando terminar.  
  
 Para obter mais informações sobre essas etapas, consulte o [conectividade aberta de banco de dados (ODBC)](https://msdn.microsoft.com/en-us/library/ms710252.aspx) SDK na documentação do MSDN.  
  
 Além dessas etapas, você precisa realizar etapas adicionais para verificar os valores de retorno de função, certifique-se de que o programa não está aguardando uma chamada assíncrona para concluir e assim por diante. Você pode simplificar essas últimas etapas usando o `AFX_SQL_ASYNC` e `AFX_SQL_SYNC` macros. Para obter mais informações, consulte [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md) no *referência MFC*.  

  
## <a name="see-also"></a>Consulte também  
 [Noções básicas de ODBC](../../data/odbc/odbc-basics.md)
