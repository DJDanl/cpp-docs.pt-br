---
title: A função no trabalho com uma exibição de registro (acesso a dados MFC) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- record views, customizing default code
- MFC, record views
ms.assetid: 691e89a5-ff21-4ca3-9278-69d4678288bb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: e7a9d3fa7e828467e73c77736fb5643baf19660f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="your-role-in-working-with-a-record-view--mfc-data-access"></a>Sua função ao trabalhar com uma exibição de registro (Acesso a dados MFC)
A tabela a seguir mostra o que você geralmente deve fazer para trabalhar com um modo de exibição do registro e a estrutura que funciona para você.  
  
### <a name="working-with-a-record-view-you-and-the-framework"></a>Trabalhando com uma exibição do registro: você e a estrutura  
  
|Você|A estrutura|  
|---------|-------------------|  
|Use o editor de diálogo do Visual C++ para criar o formulário.|Cria um recurso de modelo de diálogo com controles.|  
|Use o [Assistente de aplicativo MFC](../mfc/reference/database-support-mfc-application-wizard.md) para criar classes derivadas de [CRecordView](../mfc/reference/crecordview-class.md) e [CRecordset](../mfc/reference/crecordset-class.md).|Grava as classes para você.|  
|Mapeie controles de exibição de registro para membros de dados de campo do conjunto de registros.|Fornece DDX entre os controles e os campos de registros.|  
||Fornece manipuladores de comandos de padrão **mover primeiro**, **Mover último**, **mover próximo**, e **mover anterior** comandos de menu ou barra de ferramentas botões.|  
||Atualiza as alterações feitas à fonte de dados.|  
|[Opcional] Escreva o código para preencher caixas de listagem ou caixas de combinação ou outros controles com dados de um segundo conjunto de registros.||  
|[Opcional] Escreva o código para qualquer validação especial.||  
|[Opcional] Escreva o código para adicionar ou excluir registros.||  
  
 Programação baseada em formulários é apenas uma abordagem de trabalhar com um banco de dados. Para obter informações sobre aplicativos usando alguma outra interface de usuário, ou nenhuma interface do usuário, consulte [MFC: usando Classes de banco de dados com documentos e exibições](../data/mfc-using-database-classes-with-documents-and-views.md) e [MFC: usando Classes de banco de dados sem documentos e exibições](../data/mfc-using-database-classes-without-documents-and-views.md). Para obter métodos alternativos para exibir os registros do banco de dados, consulte classes [CListView](../mfc/reference/clistview-class.md) e [CTreeView](../mfc/reference/ctreeview-class.md).  
  
## <a name="see-also"></a>Consulte também  
 [Exibições de registro (acesso a dados MFC)](../data/record-views-mfc-data-access.md)   
 [Lista de drivers ODBC](../data/odbc/odbc-driver-list.md)