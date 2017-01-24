---
title: "C&#243;digo criado pelo assistente de aplicativo (Acesso a dados MFC) | Microsoft Docs"
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
  - "assistentes de aplicativo [C++], código de exibição de registro"
  - "exibições de registro, código de assistente de aplicativo"
  - "exibições de registro, atualizando controles"
ms.assetid: 18fd4703-5939-491d-b759-985f767b951f
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# C&#243;digo criado pelo assistente de aplicativo (Acesso a dados MFC)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O [Assistente para Aplicativo do MFC](../mfc/reference/database-support-mfc-application-wizard.md) substitui as funções de membro `OnInitialUpdate` and `OnGetRecordset` da exibição.  Depois que a estrutura cria a janela do quadro, o documento e a exibição, ela chama `OnInitialUpdate` para inicializar a exibição.  `OnInitialUpdate` obtém um ponteiro para o conjunto de registros do documento.  Uma chamada para a função de classe base [CView::OnInitialUpdate](../Topic/CView::OnInitialUpdate.md) abre o conjunto de registros.  O código a seguir mostra esse processo para uma `CRecordView` – o código para um `CDaoRecordView` é semelhante:  
  
```  
void CSectionForm::OnInitialUpdate()  
{  
   m_pSet = &GetDocument()->m_sectionSet;  
   CRecordView::OnInitialUpdate();  
}  
```  
  
 Quando o conjunto de registros é aberto, ele seleciona os registros.  [CRecordset::Open](../Topic/CRecordset::Open.md) or [CDaoRecordset::Open](../Topic/CDaoRecordset::Open.md) torna o primeiro registro o registro atual e o DDX move dados de membros de dados do campo do conjunto de registros para os respectivos controles de formulário na exibição.  Para obter mais informações sobre RFX, consulte [RFX \(Record Field Exchange\)](../data/odbc/record-field-exchange-rfx.md).  Para obter mais informações sobre DDX, consulte [Troca e validação de dados de diálogo](../mfc/dialog-data-exchange-and-validation.md).  Para obter informações sobre o processo de criação de exibição\/documento, consulte [Usando classes para gravar aplicativos no Windows](../Topic/Using%20the%20Classes%20to%20Write%20Applications%20for%20Windows.md).  
  
> [!NOTE]
>  Você deve dar aos usuários finais a capacidade de atualizar os controles de exibição de registro a partir do conjunto de registros.  Sem esse recurso, se um usuário alterar o valor de um controle com um valor inválido, o usuário pode ficar permanentemente preso no registro atual.  Para atualizar os controles, você chama a função de membro `CWnd` [Atualizar Dados](../Topic/CWnd::UpdateData.md) com um parâmetro **FALSE**.  
  
## Consulte também  
 [Usando uma exibição de registro](../data/using-a-record-view-mfc-data-access.md)