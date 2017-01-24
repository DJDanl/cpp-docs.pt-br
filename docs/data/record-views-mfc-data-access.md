---
title: "Exibi&#231;&#227;o de registro (Acesso a dados MFC) | Microsoft Docs"
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
  - "DAO [C++], exibições de registro"
  - "bancos de dados [C++], exibições de registro"
  - "formulários [C++], tarefas de acesso a dados"
  - "MFC [C++], exibições de registro"
  - "conjuntos de registros ODBC [C++], exibições de registro"
  - "exibições de registro [C++]"
ms.assetid: 562122d9-01d8-4284-acf6-ea109ab0408d
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Exibi&#231;&#227;o de registro (Acesso a dados MFC)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Esta seção aplica\-se apenas às classes MFC ODBC e DAO.  Para obter informações sobre modos de exibição de registros do banco de dados OLE, consulte [COleDBRecordView](../mfc/reference/coledbrecordview-class.md) e [usando as exibições de registro OLE DB](../data/oledb/using-ole-db-record-views.md).  
  
 Para dar suporte a aplicativos de acesso a dados baseada em formulários, a biblioteca de classes fornece as classes [CRecordView](../mfc/reference/crecordview-class.md) e [CDaoRecordView](../mfc/reference/cdaorecordview-class.md).  Uma exibição do registro é um objeto de exibição de formulário cujos controles são mapeados diretamente para os membros de dados de campo um objeto de [conjunto de registros](../data/odbc/recordset-odbc.md) \(e indiretamente para as colunas correspondentes em um resultado da consulta ou tabela na fonte de dados\).  Como sua classe base, [CFormView](../mfc/reference/cformview-class.md), `CRecordView` e `CDaoRecordView` baseia\-se em um recurso de modelo de diálogo.  
  
## Usos do formulário  
 Formulários são úteis para uma variedade de tarefas de acesso a dados:  
  
-   Inserir dados  
  
-   Executar um exame de somente leitura de dados  
  
-   Atualizando dados  
  
## Ler mais sobre as exibições de registro  
 O material nos tópicos aplicam\-se a classes baseadas em ODBC e baseadas em DAO.  Use `CRecordView` para ODBC e `CDaoRecordView` para DAO.  
  
 Os tópicos incluem:  
  
-   [Recursos de classes de exibição do registro](../data/features-of-record-view-classes-mfc-data-access.md)  
  
-   [Troca de dados para exibições de registro](../data/data-exchange-for-record-views-mfc-data-access.md)  
  
-   [A função no trabalho com uma exibição de registro](../data/your-role-in-working-with-a-record-view-mfc-data-access.md)  
  
-   [Projetando e criando uma exibição de registro](../data/designing-and-creating-a-record-view-mfc-data-access.md)  
  
-   [Usando uma exibição de registro](../data/using-a-record-view-mfc-data-access.md)  
  
## Consulte também  
 [Programação de acesso a dados \(MFC\/ATL\)](../data/data-access-programming-mfc-atl.md)   
 [Lista de drivers ODBC](../data/odbc/odbc-driver-list.md)