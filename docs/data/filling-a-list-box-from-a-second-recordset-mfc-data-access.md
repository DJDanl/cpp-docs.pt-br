---
title: "Preenchendo uma caixa de listagem de um segundo conjunto de registros (Acesso a dados MFC) | Microsoft Docs"
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
  - "Classe CComboBox, preenchendo objeto a partir do segundo conjunto de linhas"
  - "Classe CListCtrl, preenchendo a partir do segundo conjunto de registros"
  - "caixas de combinação [C++], preenchendo a partir do segundo conjunto de registros"
  - "Conjunto de registros DAO"
  - "Conjunto de registros DAO, preenchendo caixas de listagem ou caixas de combinação"
  - "preenchendo listas ou caixas de combinação"
  - "caixas de listagem, preenchendo a partir do segundo conjunto de registros"
  - "vários conjuntos de registros em exibições de registro"
  - "conjuntos de registros ODBC [C++], preenchendo caixas de listagem ou caixas de combinação"
  - "exibições de registro, preenchendo caixas de listagem"
  - "conjunto de registros [C++], preenchendo caixas de listagem ou caixas de combinação"
ms.assetid: 360c0834-da6b-4dc0-bcea-80e9acd611f0
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Preenchendo uma caixa de listagem de um segundo conjunto de registros (Acesso a dados MFC)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Por padrão, uma exibição do registro está associada a objeto de um conjunto de registros único, cujos campos são mapeados para os controles de exibição do registro.  Às vezes, convém colocar um controle de caixa de listagem ou caixa de combinação na exibição do registro e preenchê\-lo com valores de um segundo objeto do conjunto de registros.  O usuário pode usar a caixa de listagem para selecionar uma nova categoria de informações a serem exibidas na exibição do registro.  Este tópico explica como e quando fazer isso.  
  
> [!TIP]
>  Lembre\-se de que o preenchimento de uma caixa de combinação ou caixa de listagem de uma fonte de dados pode ser lenta.  Tome precauções contra tentar preencher um controle de um conjunto de registros com um grande número de registros.  
  
 O modelo referente a este tópico consiste em um conjunto de registros primário que preenche os controles do formulário, enquanto um conjunto de registros secundário preenche uma caixa de listagem ou combinação.  A seleção de uma cadeia de caracteres na caixa de listagem faz com que o programa consulte novamente o conjunto de registros primário com base no que foi selecionado.  O procedimento a seguir usa uma caixa de combinação, mas aplica\-se igualmente a uma caixa de listagem.  
  
#### Para preencher uma caixa de combinação ou caixa de listagem de um segundo conjunto de registros  
  
1.  Crie o objeto do conjunto de registros \([CRecordset](../Topic/CRecordset%20Class.md) para ODBC, [CDaoRecordset](../mfc/reference/cdaorecordset-class.md) para DAO\).  
  
2.  Obtenha um ponteiro para o objeto [CComboBox](../mfc/reference/ccombobox-class.md) para o controle de caixa de combinação.  
  
3.  Esvazie a caixa de combinação de qualquer conteúdo anterior.  
  
4.  Percorra todos os registros no conjunto de registros chamando [CComboBox::AddString](../Topic/CComboBox::AddString.md) para cada cadeia de caracteres do registro atual que você deseja adicionar à caixa de combinação.  
  
5.  Inicialize a seleção na caixa de combinação.  
  
```  
void CSectionForm::OnInitialUpdate()  
{  
    // ...  
  
    // Fill the combo box with all of the courses  
    CENROLLDoc* pDoc = GetDocument();  
    if (!pDoc->m_courseSet.Open())  
        return;  
  
    // ...  
  
    m_ctlCourseList.ResetContent();  
    if (pDoc->m_courseSet.IsOpen())  
    {   
        while (!pDoc->m_courseSet.IsEOF() )  
        {  
            m_ctlCourseList.AddString(  
                pDoc->m_courseSet.m_CourseID);  
            pDoc->m_courseSet.MoveNext();  
        }  
    }  
    m_ctlCourseList.SetCurSel(0);  
}  
```  
  
 Essa função usa um segundo conjunto de registros `m_courseSet`, que contém um registro para cada curso oferecido e um controle `CComboBox`, `m_ctlCourseList`, que é armazenado na classe de exibição do registro.  
  
 A função obtém `m_courseSet` do documento e o abre.  Em seguida, esvazia `m_ctlCourseList` e rola pelo `m_courseSet`.  Para cada registro, a função chama a função membro `AddString` da caixa de combinação para adicionar o valor da ID do curso do registro.  Por fim, o código define a seleção da caixa de combinação.  
  
## Consulte também  
 [Exibição de registro \(Acesso a dados MFC\)](../data/record-views-mfc-data-access.md)   
 [Lista de drivers ODBC](../data/odbc/odbc-driver-list.md)