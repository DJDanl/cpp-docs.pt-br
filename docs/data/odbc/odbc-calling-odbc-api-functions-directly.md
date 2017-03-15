---
title: "ODBC: chamando fun&#231;&#245;es de API ODBC diretamente | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Chamada de funções de API de ODBC [C++]"
  - "ODBC [C++], funções de catálogo"
  - "Funções API de ODBC [C++]"
  - "APIs [C++], chamar"
  - "Classes ODBC [C++], vs. API DE ODBC"
  - "chamadas à API de ODBC diretas"
  - "funções de catálogo (ODBC)"
  - "funções de catálogo (ODBC), chamada"
  - "Funções de API, ODBC [C++]"
ms.assetid: 4295f1d9-4528-4d2e-bd6a-c7569953c7fa
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# ODBC: chamando fun&#231;&#245;es de API ODBC diretamente
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As classes de banco de dados fornecem uma interface mais simples para um [fonte de dados](../../data/odbc/data-source-odbc.md) que o ODBC. Como resultado, as classes não encapsulam a API de ODBC. Para qualquer funcionalidade que está fora das capacidades das classes, você deve chamar funções de API ODBC diretamente. Por exemplo, você deve chamar as funções de catálogo ODBC \(**:: SQLColumns**, **:: SQLProcedures**, **:: SQLTables**, e outros\) diretamente.  
  
> [!NOTE]
>  Fontes de dados ODBC são acessíveis por meio de classes MFC ODBC, conforme descrito neste tópico, ou as classes de objeto de acesso a dados MFC \(DAO\).  
  
 Para chamar uma função de API ODBC diretamente, você deve seguir as mesmas etapas que necessárias se você estava fazendo as chamadas sem a estrutura. Eles são etapas:  
  
-   Alocar armazenamento para qualquer resultado de que retorno de chamada.  
  
-   Passar um ODBC **HDBC** ou **HSTMT** tratar, dependendo da assinatura do parâmetro da função. Use o [AFXGetHENV](../Topic/AfxGetHENV.md) macro para recuperar o identificador do ODBC.  
  
     Variáveis de membro **CDatabase::m\_hdbc** e **CRecordset::m\_hstmt** estão disponíveis para que você não precisa alocar e inicializar esses por conta própria.  
  
-   Talvez, chame funções ODBC adicionais para preparar ou siga a chamada principal.  
  
-   Desalocar armazenamento quando você terminar.  
  
 Para obter mais informações sobre essas etapas, consulte o [conectividade aberta de banco de dados \(ODBC\)](https://msdn.microsoft.com/en-us/library/ms710252.aspx) SDK na documentação do MSDN.  
  
 Além dessas etapas, você precisa realizar etapas adicionais para verificar os valores de retorno de função, certifique\-se de que seu programa não está aguardando uma chamada assíncrona para concluir e assim por diante. Você pode simplificar essas últimas etapas usando o `AFX_SQL_ASYNC` e `AFX_SQL_SYNC` macros. Para obter mais informações, consulte [Macros e globais](../Topic/Macros,%20Global%20Functions,%20and%20Global%20Variables.md) no *referência da MFC*.  
  
## Consulte também  
 [Noções básicas de ODBC](../../data/odbc/odbc-basics.md)