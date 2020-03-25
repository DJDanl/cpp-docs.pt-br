---
title: Código criado pelo assistente de aplicativo (Acesso a dados MFC)
ms.date: 11/04/2016
helpviewer_keywords:
- application wizards [C++], record view code
- record views, refreshing controls
- record views, application wizard code
ms.assetid: 18fd4703-5939-491d-b759-985f767b951f
ms.openlocfilehash: 69bebe978d03e5777f20765ac0bcf9a344f69320
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80209151"
---
# <a name="record-view-code-created-by-application-wizard--mfc-data-access"></a>Código criado pelo assistente de aplicativo (Acesso a dados MFC)

O [Assistente de aplicativo do MFC](../mfc/reference/database-support-mfc-application-wizard.md) substitui as `OnInitialUpdate` da exibição e as funções de membro de `OnGetRecordset`. Depois que a estrutura cria a janela do quadro, o documento e a exibição, ela chama `OnInitialUpdate` para inicializar a exibição. `OnInitialUpdate` obtém um ponteiro para o conjunto de registros do documento. Uma chamada para a classe base [cvisualização:: OnInitialUpdate](../mfc/reference/cview-class.md#oninitialupdate) abre o conjunto de registros. O código a seguir mostra esse processo para um `CRecordView`:

```cpp
void CSectionForm::OnInitialUpdate()
{
   m_pSet = &GetDocument()->m_sectionSet;
   CRecordView::OnInitialUpdate();
}
```

Quando o conjunto de registros é aberto, ele seleciona os registros. [CRecordset:: Open](../mfc/reference/crecordset-class.md#open) faz o primeiro registro do registro atual e o campo DDX move dados dos membros de dados de campo do conjunto de registros para os controles de formulário correspondentes na exibição. Para obter mais informações sobre suporte RFX, consulte [Record Field Exchange (suporte RFX)](../data/odbc/record-field-exchange-rfx.md). Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../mfc/dialog-data-exchange-and-validation.md). Para obter informações sobre o processo de criação de documento/exibição, consulte [usando as classes para escrever aplicativos para o Windows](../mfc/using-the-classes-to-write-applications-for-windows.md).

> [!NOTE]
>  Você deve dar aos usuários finais a capacidade de atualizar os controles de exibição de registro a partir do conjunto de registros. Sem esse recurso, se um usuário alterar o valor de um controle com um valor inválido, o usuário pode ficar permanentemente preso no registro atual. Para atualizar os controles, chame a função membro `CWnd` [UpdateData](../mfc/reference/cwnd-class.md#updatedata) com um parâmetro de false.

## <a name="see-also"></a>Confira também

[Usando uma exibição de registro](../data/using-a-record-view-mfc-data-access.md)
