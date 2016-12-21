---
title: "Sua fun&#231;&#227;o ao trabalhar com uma exibi&#231;&#227;o de registro (Acesso a dados MFC) | Microsoft Docs"
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
  - "MFC, exibições de registro"
  - "exibições de registro, personalizando código padrão"
ms.assetid: 691e89a5-ff21-4ca3-9278-69d4678288bb
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Sua fun&#231;&#227;o ao trabalhar com uma exibi&#231;&#227;o de registro (Acesso a dados MFC)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A tabela a seguir mostra o que você geralmente deve fazer para trabalhar com um modo de exibição do registro e a estrutura que funciona para você.  
  
### Trabalhando com uma exibição do registro: você e a estrutura  
  
|Você|A estrutura|  
|----------|-----------------|  
|Use o editor de diálogo do Visual C\+\+ para criar o formulário.|Cria um recurso de modelo de diálogo com controles.|  
|Use o [Assistente para Aplicativo do MFC](../mfc/reference/database-support-mfc-application-wizard.md) para criar classes derivadas de [CRecordView](../mfc/reference/crecordview-class.md) e [CRecordset](../Topic/CRecordset%20Class.md) ou de [CDaoRecordView](../mfc/reference/cdaorecordview-class.md) de [CDaoRecordset](../mfc/reference/cdaorecordset-class.md).|Grava as classes para você.|  
|Mapeie controles de exibição de registro para membros de dados de campo do conjunto de registros.|Fornece DDX entre os controles e os campos de registros.|  
||Fornece manipuladores de comando padrão para os comandos **Mover Primeiro**, **Mover por Último**, **Mover Próximo**, e **Mover Anterior** de menus ou botões da barra de menu.|  
||Atualiza as alterações feitas à fonte de dados.|  
|\[Opcional\] Escreva o código para preencher caixas de listagem ou caixas de combinação ou outros controles com dados de um segundo conjunto de registros.||  
|\[Opcional\] Escreva o código para qualquer validação especial.||  
|\[Opcional\] Escreva o código para adicionar ou excluir registros.||  
  
 Programação baseada em formulários é apenas uma abordagem de trabalhar com um banco de dados.  Para obter informações sobre os aplicativos usando algumas outra interface do usuário ou nenhuma interface de usuário, consulte [MFC: Usando classes de banco de dados com documentos e exibições](../data/mfc-using-database-classes-with-documents-and-views.md) e [MFC: Usando classes de banco de dados sem documentos e exibições](../data/mfc-using-database-classes-without-documents-and-views.md).  Para obter métodos alternativos para exibir os registros de banco de dados, consulte as classes [CListView](../mfc/reference/clistview-class.md) e [CTreeView](../mfc/reference/ctreeview-class.md).  
  
## Consulte também  
 [Exibição de registro \(Acesso a dados MFC\)](../data/record-views-mfc-data-access.md)   
 [Lista de drivers ODBC](../data/odbc/odbc-driver-list.md)