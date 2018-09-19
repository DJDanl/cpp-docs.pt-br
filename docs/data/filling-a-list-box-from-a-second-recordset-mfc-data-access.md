---
title: Preenchendo uma caixa de listagem de um segundo conjunto de registros (acesso a dados MFC) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- record views, filling list boxes
- list boxes, filling from second recordset
- recordsets [C++], filling list boxes or combo boxes
- CComboBox class, filling object from second rowset
- ODBC recordsets [C++], filling list boxes or combo boxes
- combo boxes [C++], filling from second recordset
- CListCtrl class, filling from second recordset
ms.assetid: 360c0834-da6b-4dc0-bcea-80e9acd611f0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: ee56369948cbfbaff57a0f848da1b8b27bf309fe
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46078043"
---
# <a name="filling-a-list-box-from-a-second-recordset--mfc-data-access"></a>Preenchendo uma caixa de listagem de um segundo conjunto de registros (Acesso a dados MFC)

Por padrão, uma exibição do registro está associada a objeto de um conjunto de registros único, cujos campos são mapeados para os controles de exibição do registro. Às vezes, convém colocar um controle de caixa de listagem ou caixa de combinação na exibição do registro e preenchê-lo com valores de um segundo objeto do conjunto de registros. O usuário pode usar a caixa de listagem para selecionar uma nova categoria de informações a serem exibidas na exibição do registro. Este tópico explica como e quando fazer isso.  
  
> [!TIP]
>  Lembre-se de que o preenchimento de uma caixa de combinação ou caixa de listagem de uma fonte de dados pode ser lenta. Tome precauções contra tentar preencher um controle de um conjunto de registros com um grande número de registros.  
  
O modelo referente a este tópico consiste em um conjunto de registros primário que preenche os controles do formulário, enquanto um conjunto de registros secundário preenche uma caixa de listagem ou combinação. A seleção de uma cadeia de caracteres na caixa de listagem faz com que o programa consulte novamente o conjunto de registros primário com base no que foi selecionado. O procedimento a seguir usa uma caixa de combinação, mas aplica-se igualmente a uma caixa de listagem.  
  
#### <a name="to-fill-a-combo-box-or-list-box-from-a-second-recordset"></a>Para preencher uma caixa de combinação ou caixa de listagem de um segundo conjunto de registros  
  
1. Criar o objeto recordset ([CRecordset](../mfc/reference/crecordset-class.md).  
  
1. Obter um ponteiro para o [CComboBox](../mfc/reference/ccombobox-class.md) objeto para o controle de caixa de combinação.  
  
1. Esvazie a caixa de combinação de qualquer conteúdo anterior.  
  
1. Percorra todos os registros no conjunto de registros, chamando [CComboBox:: AddString](../mfc/reference/ccombobox-class.md#addstring) para cada cadeia de caracteres do registro atual que você deseja adicionar à caixa de combinação.  
  
1. Inicialize a seleção na caixa de combinação.  
  
```cpp  
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
  
A função obtém `m_courseSet` do documento e o abre. Em seguida, esvazia `m_ctlCourseList` e rola pelo `m_courseSet`. Para cada registro, a função chama a função membro `AddString` da caixa de combinação para adicionar o valor da ID do curso do registro. Por fim, o código define a seleção da caixa de combinação.  
  
## <a name="see-also"></a>Consulte também  

[Exibição de registro (Acesso a dados MFC)](../data/record-views-mfc-data-access.md)<br/>
[Lista de drivers ODBC](../data/odbc/odbc-driver-list.md)