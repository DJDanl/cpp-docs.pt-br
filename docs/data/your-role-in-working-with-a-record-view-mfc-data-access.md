---
title: Sua função ao trabalhar com uma exibição de registro (Acesso a dados MFC)
ms.date: 11/04/2016
helpviewer_keywords:
- record views, customizing default code
- MFC, record views
ms.assetid: 691e89a5-ff21-4ca3-9278-69d4678288bb
ms.openlocfilehash: 351aa2d5ce950017aa8c1b3d99c8d297a423ad9f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80208995"
---
# <a name="your-role-in-working-with-a-record-view--mfc-data-access"></a>Sua função ao trabalhar com uma exibição de registro (Acesso a dados MFC)

A tabela a seguir mostra o que você geralmente deve fazer para trabalhar com um modo de exibição do registro e a estrutura que funciona para você.

### <a name="working-with-a-record-view-you-and-the-framework"></a>Trabalhando com uma exibição do registro: você e a estrutura

|Você|A estrutura|
|---------|-------------------|
|Use o editor de diálogo do Visual C++ para criar o formulário.|Cria um recurso de modelo de diálogo com controles.|
|Use o [Assistente de aplicativo MFC](../mfc/reference/database-support-mfc-application-wizard.md) para criar classes derivadas de [CRecordView](../mfc/reference/crecordview-class.md) e [CRecordset](../mfc/reference/crecordset-class.md).|Grava as classes para você.|
|Mapeie controles de exibição de registro para membros de dados de campo do conjunto de registros.|Fornece DDX entre os controles e os campos de registros.|
||Fornece manipuladores de comando padrão para **mover primeiro**, **mover por último**, mover **próximo**e **mover comandos anteriores** de menus ou botões da barra de ferramentas.|
||Atualiza as alterações feitas à fonte de dados.|
|[Opcional] Escreva o código para preencher caixas de listagem ou caixas de combinação ou outros controles com dados de um segundo conjunto de registros.||
|[Opcional] Escreva o código para qualquer validação especial.||
|[Opcional] Escreva o código para adicionar ou excluir registros.||

Programação baseada em formulários é apenas uma abordagem de trabalhar com um banco de dados. Para obter informações sobre aplicativos que usam alguma outra interface do usuário, ou nenhuma interface do usuário, consulte [MFC: usando classes de banco de dados com documentos e exibições](../data/mfc-using-database-classes-with-documents-and-views.md) e [MFC: usando classes de banco de dados sem documentos e exibições](../data/mfc-using-database-classes-without-documents-and-views.md). Para obter abordagens alternativas para exibir registros de banco de dados, consulte classes [CListView](../mfc/reference/clistview-class.md) e [CTreeView](../mfc/reference/ctreeview-class.md).

## <a name="see-also"></a>Confira também

[Exibição de registro (Acesso a dados MFC)](../data/record-views-mfc-data-access.md)<br/>
[Lista de drivers ODBC](../data/odbc/odbc-driver-list.md)
