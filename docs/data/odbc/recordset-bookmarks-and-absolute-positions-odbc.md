---
title: "Conjunto de registros: indicadores e posi&#231;&#245;es absolutas (ODBC) | Microsoft Docs"
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
  - "SetAbsolutePosition"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "posições absolutas, conjunto de registros ODBC"
  - "indicadores"
  - "indicadores, CDBVariant"
  - "indicadores, conjunto de registros ODBC"
  - "Classe CDBVariant, indicadores"
  - "cursores [ODBC], posição absoluta em conjuntos de registros"
  - "Método GetBookmark"
  - "conjunto de registros ODBC, posições absolutas"
  - "conjunto de registros ODBC, indicadores"
  - "posicionando registros"
  - "posicionamento de registros"
  - "conjuntos de registros, posições absolutas"
  - "conjuntos de registros, indicadores"
  - "Método SetAbsolutePosition"
  - "Método SetAbsolutePosition, indicadores"
  - "Método SetBookmark"
ms.assetid: 189788d6-33c1-41c5-9265-97db2a5d43cc
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conjunto de registros: indicadores e posi&#231;&#245;es absolutas (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico se aplica às classes ODBC do MFC.  
  
 Ao navegar com um conjunto de registros, você precisa frequentemente um modo de retornar a um registro específico.  O indicador e a posição absoluta de um registro fornecem esses dois métodos.  
  
 Este tópico explica:  
  
-   [Como usar indicadores](#_core_bookmarks_in_mfc_odbc).  
  
-   [Como definir o registro atual usando posições absolutas](#_core_absolute_positions_in_mfc_odbc).  
  
##  <a name="_core_bookmarks_in_mfc_odbc"></a> Indicadores em ODBC MFC  
 Um indicador identifica exclusivamente um registro.  Quando você navega com um conjunto de registros, nem sempre é possível confiar na posição absoluta de um registro como os registros podem ser excluídos do conjunto de registros.  O modo confiável de acompanhar a posição de um registro é usar seu medidor.  Funções de membro de fontes de `CRecordset` da classe para:  
  
-   Obtém o indicador do registro atual, o que pode salvá\-lo em uma variável \([GetBookmark](../Topic/CRecordset::GetBookmark.md)\).  
  
-   Movendo rapidamente a um determinado registro especificando seu medidor, que você salvou a anterior em uma variável \([SetBookmark](../Topic/CRecordset::SetBookmark.md)\).  
  
 O exemplo a seguir ilustra como usar essas funções de membro para marcar o registro atual e o retorno posterior a ela:  
  
```  
// rs is a CRecordset or  
// CRecordset-derived object  
  
CDBVariant varRecordToReturnTo;  
rs.GetBookmark( varRecordToReturnTo );  
  
// More code in which you  
// move to other records  
  
rs.SetBookmark( varRecordToReturnTo );  
```  
  
 Você não precisa extrair o tipo de dados subjacente do objeto de [Classe de CDBVariant](../Topic/CDBVariant%20Class.md) .  Atribuir o valor com `GetBookmark` e retornar ao medidor com `SetBookmark`.  
  
> [!NOTE]
>  Dependendo do tipo de driver ODBC e do conjunto de registros, os medidores talvez não haja suporte.  Você pode facilmente determinar se os indicadores são suportados chamando [CRecordset::CanBookmark](../Topic/CRecordset::CanBookmark.md).  Além disso, se os indicadores são suportadas, você deve escolher explicitamente para os implementar especificando a opção de **CRecordset::useBookmarks** na função de membro de [CRecordset::Open](../Topic/CRecordset::Open.md) .  Você também deve verificar a persistência de indicadores depois de determinadas operações de conjunto de registros.  Por exemplo, se você **Requery** um conjunto de registros, medidores talvez não seja mais válida.  Chame [CDatabase::GetBookmarkPersistence](../Topic/CDatabase::GetBookmarkPersistence.md) para verificar se você pode chamar com segurança `SetBookmark`.  
  
##  <a name="_core_absolute_positions_in_mfc_odbc"></a> Posições absolutas em ODBC MFC  
 Além dos indicadores, a classe `CRecordset` permite que você defina o registro atual especificando uma posição ordinal.  Isso é chamado de posicionamento absoluto.  
  
> [!NOTE]
>  O posicionamento absoluto não está disponível em conjuntos de registros de somente avanço.  Para obter mais informações sobre conjuntos de registros de somente avanço, consulte [Conjunto de registros \(ODBC\)](../../data/odbc/recordset-odbc.md).  
  
 Para mover o ponteiro de registro atual que usa a posição absoluta, chame [CRecordset::SetAbsolutePosition](../Topic/CRecordset::SetAbsolutePosition.md).  Quando você passar um valor a `SetAbsolutePosition`, o registro que corresponda à posição ordinal se torna o registro atual.  
  
> [!NOTE]
>  A posição absoluta de um registro é potencialmente não confiável.  Se o usuário excluir registros do conjunto de registros, a posição ordinal do registro subsequente será alterado.  Os indicadores são o método recomendado para mover o registro atual.  Para obter mais informações, consulte [Indicadores em ODBC MFC](#_core_bookmarks_in_mfc_odbc).  
  
 Para obter mais informações sobre a navegação do conjunto de registros, consulte [Conjunto de registros: rolando \(ODBC\)](../Topic/Recordset:%20Scrolling%20\(ODBC\).md).  
  
## Consulte também  
 [Conjunto de registros \(ODBC\)](../../data/odbc/recordset-odbc.md)