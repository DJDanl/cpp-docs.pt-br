---
title: Sua função ao trabalhar com uma exibição de registro (Acesso a dados MFC)
ms.date: 11/04/2016
helpviewer_keywords:
- record views, customizing default code
- MFC, record views
ms.assetid: 691e89a5-ff21-4ca3-9278-69d4678288bb
ms.openlocfilehash: 1f1361baafa5bb3dc884adcc464a3571aee04dd3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50478631"
---
# <a name="your-role-in-working-with-a-record-view--mfc-data-access"></a>Sua função ao trabalhar com uma exibição de registro (Acesso a dados MFC)

A tabela a seguir mostra o que você geralmente deve fazer para trabalhar com um modo de exibição do registro e a estrutura que funciona para você.

### <a name="working-with-a-record-view-you-and-the-framework"></a>Trabalhando com uma exibição do registro: você e a estrutura

|Você|A estrutura|
|---------|-------------------|
|Use o editor de diálogo do Visual C++ para criar o formulário.|Cria um recurso de modelo de diálogo com controles.|
|Use o [Assistente de aplicativo MFC](../mfc/reference/database-support-mfc-application-wizard.md) para criar classes derivadas [CRecordView](../mfc/reference/crecordview-class.md) e [CRecordset](../mfc/reference/crecordset-class.md).|Grava as classes para você.|
|Mapeie controles de exibição de registro para membros de dados de campo do conjunto de registros.|Fornece DDX entre os controles e os campos de registros.|
||Fornece manipuladores de comandos para a padrão **mover primeiro**, **Mover último**, **mover próximo**, e **mover anterior** comandos dos menus ou barra de ferramentas botões.|
||Atualiza as alterações feitas à fonte de dados.|
|[Opcional] Escreva o código para preencher caixas de listagem ou caixas de combinação ou outros controles com dados de um segundo conjunto de registros.||
|[Opcional] Escreva o código para qualquer validação especial.||
|[Opcional] Escreva o código para adicionar ou excluir registros.||

Programação baseada em formulários é apenas uma abordagem de trabalhar com um banco de dados. Para obter informações sobre os aplicativos usando algumas outra interface do usuário, ou nenhuma interface do usuário, consulte [MFC: usando Classes de banco de dados com documentos e exibições](../data/mfc-using-database-classes-with-documents-and-views.md) e [MFC: usando Classes de banco de dados sem documentos e exibições](../data/mfc-using-database-classes-without-documents-and-views.md). Para obter métodos alternativos para exibir registros de banco de dados, consulte classes [CListView](../mfc/reference/clistview-class.md) e [CTreeView](../mfc/reference/ctreeview-class.md).

## <a name="see-also"></a>Consulte também

[Exibição de registro (Acesso a dados MFC)](../data/record-views-mfc-data-access.md)<br/>
[Lista de drivers ODBC](../data/odbc/odbc-driver-list.md)