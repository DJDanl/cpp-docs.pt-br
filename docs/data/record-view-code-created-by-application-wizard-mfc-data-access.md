---
title: Código criado pelo assistente de aplicativo (Acesso a dados MFC)
ms.date: 11/04/2016
helpviewer_keywords:
- application wizards [C++], record view code
- record views, refreshing controls
- record views, application wizard code
ms.assetid: 18fd4703-5939-491d-b759-985f767b951f
ms.openlocfilehash: e25ca9cad1390dd11ab7328ffefed31badf6fc0b
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59036069"
---
# <a name="record-view-code-created-by-application-wizard--mfc-data-access"></a>Código criado pelo assistente de aplicativo (Acesso a dados MFC)

O [Assistente de aplicativo MFC](../mfc/reference/database-support-mfc-application-wizard.md) substitui o modo de exibição `OnInitialUpdate` e `OnGetRecordset` funções de membro. Depois que a estrutura cria a janela do quadro, o documento e a exibição, ela chama `OnInitialUpdate` para inicializar a exibição. `OnInitialUpdate` Obtém um ponteiro para o conjunto de registros do documento. Uma chamada para a classe base [cview:: Oninitialupdate](../mfc/reference/cview-class.md#oninitialupdate) função abre o conjunto de registros. O código a seguir mostra esse processo para um `CRecordView`:

```cpp
void CSectionForm::OnInitialUpdate()
{
   m_pSet = &GetDocument()->m_sectionSet;
   CRecordView::OnInitialUpdate();
}
```

Quando o conjunto de registros é aberto, ele seleciona os registros. [{1&gt;crecordset::Open&lt;1](../mfc/reference/crecordset-class.md#open) torna o primeiro registro o registro atual e o DDX move dados de membros de dados de campo do conjunto de registros para os respectivos controles de formulário no modo de exibição. Para obter mais informações sobre RFX, consulte [Exchange RFX (Record Field)](../data/odbc/record-field-exchange-rfx.md). Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../mfc/dialog-data-exchange-and-validation.md). Para obter informações sobre o processo de criação de documento/exibição, consulte [usando as Classes para escrever aplicativos para Windows](../mfc/using-the-classes-to-write-applications-for-windows.md).

> [!NOTE]
>  Você deve dar aos usuários finais a capacidade de atualizar os controles de exibição de registro a partir do conjunto de registros. Sem esse recurso, se um usuário alterar o valor de um controle com um valor inválido, o usuário pode ficar permanentemente preso no registro atual. Para atualizar os controles, você chama o `CWnd` função de membro [UpdateData](../mfc/reference/cwnd-class.md#updatedata) com um parâmetro de FALSE.

## <a name="see-also"></a>Consulte também

[Usando uma exibição de registro](../data/using-a-record-view-mfc-data-access.md)