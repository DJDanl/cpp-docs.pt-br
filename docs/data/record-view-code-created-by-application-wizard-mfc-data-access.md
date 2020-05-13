---
title: Código criado pelo assistente de aplicativo (Acesso a dados MFC)
ms.date: 11/04/2016
helpviewer_keywords:
- application wizards [C++], record view code
- record views, refreshing controls
- record views, application wizard code
ms.assetid: 18fd4703-5939-491d-b759-985f767b951f
ms.openlocfilehash: 69481299980329b98e378f02e090670fa3d7ece2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376027"
---
# <a name="record-view-code-created-by-application-wizard--mfc-data-access"></a>Código criado pelo assistente de aplicativo (Acesso a dados MFC)

O [Assistente de Aplicativo do MFC](../mfc/reference/database-support-mfc-application-wizard.md) substitui as funções da exibição e `OnInitialUpdate` `OnGetRecordset` do membro. Depois que a estrutura cria a janela do quadro, o documento e a exibição, ela chama `OnInitialUpdate` para inicializar a exibição. `OnInitialUpdate` obtém um ponteiro para o conjunto de registros do documento. Uma chamada para a classe base [CView::OnInitialUpdate](../mfc/reference/cview-class.md#oninitialupdate) é a função abre o conjunto de registros. O código a seguir `CRecordView`mostra este processo para:

```cpp
void CSectionForm::OnInitialUpdate()
{
   m_pSet = &GetDocument()->m_sectionSet;
   CRecordView::OnInitialUpdate();
}
```

Quando o conjunto de registros é aberto, ele seleciona os registros. [CRecordset::Open](../mfc/reference/crecordset-class.md#open) faz o primeiro registro do registro atual e o DDX move dados dos membros de dados de campo do conjunto de registros para os controles de formulário correspondentes na exibição. Para obter mais informações sobre o RFX, consulte [Record Field Exchange (RFX)](../data/odbc/record-field-exchange-rfx.md). Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../mfc/dialog-data-exchange-and-validation.md). Para obter informações sobre o processo de criação de documentos/exibição, consulte [Usando as classes para escrever aplicativos para Windows](../mfc/using-the-classes-to-write-applications-for-windows.md).

> [!NOTE]
> Você deve dar aos usuários finais a capacidade de atualizar os controles de exibição de registro a partir do conjunto de registros. Sem esse recurso, se um usuário alterar o valor de um controle com um valor inválido, o usuário pode ficar permanentemente preso no registro atual. Para atualizar os controles, `CWnd` você chama a função de membro [UpdateData](../mfc/reference/cwnd-class.md#updatedata) com um parâmetro de FALSE.

## <a name="see-also"></a>Confira também

[Usando uma exibição de registro](../data/using-a-record-view-mfc-data-access.md)
