---
title: "Fun&#231;&#245;es da troca de dados da caixa de di&#225;logo para CRecordView e CDaoRecordView | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.mfc.macros.data"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "DAO [C++], suporte à troca de dados da caixa de diálogo (DDX)"
  - "bancos de dados [C++], suporte à troca de dados da caixa de diálogo (DDX)"
  - "DDX (troca de dados da caixa de diálogo) [C++], suporte a banco de dados"
  - "DDX (troca de dados da caixa de diálogo) [C++], Funções "
  - "Funções DDX_Field"
  - "ODBC [C++], suporte à troca de dados da caixa de diálogo (DDX)"
ms.assetid: 0d8cde38-3a2c-4100-9589-ac80a7b1ce91
caps.latest.revision: 13
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#245;es da troca de dados da caixa de di&#225;logo para CRecordView e CDaoRecordView
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico lista as funções de DDX\_Field usadas para trocar dados entre [CRecordset](../Topic/CRecordset%20Class.md) e um formulário de [CRecordView](../../mfc/reference/crecordview-class.md) ou um [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) e um formulário de [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) .  
  
> [!NOTE]
>  As funções de DDX\_Field são as funções de DDX que elas troca de dados com controles em um formulário.  Mas ao contrário de DDX, elas troca de dados com os campos de objeto associada ao conjunto de registros de exibição em vez de com campos de exibição do registro próprios.  Classes `CRecordView` e de `CDaoRecordView`Para obter mais informações, consulte.  
  
### Funções de DDX\_Field  
  
|||  
|-|-|  
|[DDX\_FieldCBIndex](../Topic/DDX_FieldCBIndex.md)|Dados inteiro das transferências entre um membro de dados do campo do conjunto de registros e o índice da seleção atual em uma caixa de combinação em [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md).|  
|[DDX\_FieldCBString](../Topic/DDX_FieldCBString.md)|Dados de `CString` das transferências entre um membro de dados do campo do conjunto de registros e o controle de edição de uma caixa de combinação em `CRecordView` ou `CDaoRecordView`.  Ao mover dados do conjunto de registros ao controle, essa função selecione o item na caixa de combinação que iniciam com os caracteres na cadeia de caracteres especificada.|  
|[DDX\_FieldCBStringExact](../Topic/DDX_FieldCBStringExact.md)|Dados de `CString` das transferências entre um membro de dados do campo do conjunto de registros e o controle de edição de uma caixa de combinação em `CRecordView` ou `CDaoRecordView`.  Ao mover dados do conjunto de registros ao controle, essa função selecione o item na caixa de combinação que corresponde exatamente à cadeia de caracteres especificada.|  
|[DDX\_FieldCheck](../Topic/DDX_FieldCheck.md)|Transferências de dados boolianos entre um membro de dados do campo do conjunto de registros e uma caixa de seleção em `CRecordView` ou `CDaoRecordView`.|  
|[DDX\_FieldLBIndex](../Topic/DDX_FieldLBIndex.md)|Dados inteiro das transferências entre um membro de dados do campo do conjunto de registros e o índice da seleção atual em uma caixa de listagem em `CRecordView` ou `CDaoRecordView`.|  
|[DDX\_FieldLBString](../Topic/DDX_FieldLBString.md)|Gerencia a transferência de dados de [CString](../../atl-mfc-shared/reference/cstringt-class.md) entre um controle da caixa de listagem e os membros de dados do campo de um conjunto de registros.  Ao mover dados do conjunto de registros ao controle, essa função selecione o item na caixa de listagem que iniciam com os caracteres na cadeia de caracteres especificada.|  
|[DDX\_FieldLBStringExact](../Topic/DDX_FieldLBStringExact.md)|Gerencia a transferência de dados de `CString` entre um controle da caixa de listagem e os membros de dados do campo de um conjunto de registros.  Ao mover dados do conjunto de registros ao controle, essa função seleciona o primeiro item que corresponde exatamente à cadeia de caracteres especificada.|  
|[DDX\_FieldRadio](../Topic/DDX_FieldRadio.md)|Dados inteiro das transferências entre um membro de dados do campo do conjunto de registros e um grupo de botões de opção em `CRecordView` ou `CDaoRecordView`.|  
|[DDX\_FieldScroll](../Topic/DDX_FieldScroll.md)|Os conjuntos ou obtém a posição de rolagem de um controle da barra de rolagem em `CRecordView` ou em `CDaoRecordView`.  A chamada da função de [DoFieldExchange](../Topic/CDaoRecordset::DoFieldExchange.md) .|  
|[DDX\_FieldText](../Topic/DDX_FieldText.md)|As versões sobrecarregadas estão disponíveis para transferir `int`, **UINT**, **long**, `DWORD`, [CString](../../atl-mfc-shared/reference/cstringt-class.md), **float**, **double**, **short**, [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md), e dados de [COleCurrency](../Topic/COleCurrency%20Class.md) entre um membro de dados do campo do conjunto de registros e uma caixa de edição em `CRecordView` ou `CDaoRecordView`.|  
  
## Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)