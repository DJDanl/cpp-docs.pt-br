---
title: "Registrar troca de campos: Trabalhando com o código de Assistente | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- DoFieldExchange method, overriding
- Unicode, with database classes
- field data members, declaring
- RFX (ODBC), wizard code
- RFX (ODBC), implementing
- field data members
- ODBC, RFX
- m_nParams data member, initializing
- m_nFields data member
- m_nParams data member
- overriding, DoFieldExchange
- m_nFields data member, initializing
ms.assetid: f00d882a-ff1b-4a75-9717-98d8762bb237
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 8909a9e933e7b3f1c59fa9ab283706f7a6d1f0c0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="record-field-exchange-working-with-the-wizard-code"></a>Registrar troca de campos: trabalhando com o código do assistente
Este tópico explica o código que o Assistente de aplicativo MFC e **Adicionar classe de** (conforme descrito em [adicionando um consumidor de ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)) dar suporte a RFX e como você talvez queira alterar esse código de gravação.  
  
> [!NOTE]
>  Este tópico se aplica a classes derivadas de `CRecordset` em qual linha em massa busca não foi implementada. Se você estiver usando a busca de linhas em massa, a troca de campos de registro em massa (RFX em massa) é implementada. Em massa RFX é semelhante a RFX. Para entender as diferenças, consulte [conjunto de registros: busca de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).  
  
 Quando você cria uma classe de conjunto de registros com o Assistente de aplicativo do MFC ou **Adicionar classe**, o assistente grava os seguintes elementos de RFX para você, com base na fonte de dados, tabela e coluna escolhas feitas no Assistente:  
  
-   Declarações de membros de dados de campo do conjunto de registros na classe de conjunto de registros  
  
-   Uma substituição de`CRecordset::DoFieldExchange`  
  
-   Inicialização de membros de dados de campo do conjunto de registros no construtor da classe de conjunto de registros  
  
##  <a name="_core_the_field_data_member_declarations"></a>Declarações de membros de dados de campo  
 Os assistentes de gravar uma declaração de classe de conjunto de registros em um arquivo. h semelhante à seguinte para a classe `CSections`:  
  
```  
class CSections : public CRecordset  
{  
public:  
   CSections(CDatabase* pDatabase = NULL);  
   DECLARE_DYNAMIC(CSections)  
  
// Field/Param Data  
   CString   m_strCourseID;  
   CString   m_strInstructorID;  
   CString   m_strRoomNo;  
   CString   m_strSchedule;  
   CString   m_strSectionNo;  
  
// Overrides  
   // Wizard generated virtual function overrides  
   protected:  
   virtual CString GetDefaultConnect();  // Default connection string  
   virtual CString GetDefaultSQL();      // Default SQL for Recordset  
   virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support  
  
// Implementation  
#ifdef _DEBUG  
   virtual void AssertValid() const;  
   virtual void Dump(CDumpContext& dc) const;  
#endif  
  
};  
```  
  
 Se você adicionar membros de dados de parâmetro ou novos membros de dados de campo que você associar por conta própria, adicioná-los após os gerados pelo assistente.  
  
 Além disso, observe que o assistente substitui o `DoFieldExchange` função de membro de classe `CRecordset`.  
  
##  <a name="_core_the_dofieldexchange_override"></a>Substituição de DoFieldExchange  

 [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) é a essência do RFX. A estrutura chama `DoFieldExchange` sempre precisa mover dados de fonte de dados para o conjunto de registros ou de conjunto de registros a fonte de dados. `DoFieldExchange`também oferece suporte à obtenção de informações sobre o campo membros de dados por meio de [IsFieldDirty](../../mfc/reference/crecordset-class.md#isfielddirty) e [IsFieldNull](../../mfc/reference/crecordset-class.md#isfieldnull) funções de membro.  
  
 O seguinte `DoFieldExchange` substituição é para o `CSections` classe. O assistente grava a função no arquivo. cpp para a sua classe de conjunto de registros.  
  
```  
void CSections::DoFieldExchange(CFieldExchange* pFX)  
{  
   pFX->SetFieldType(CFieldExchange::outputColumn);  
   RFX_Text(pFX, "CourseID", m_strCourseID);  
   RFX_Text(pFX, "InstructorID", m_strInstructorID);  
   RFX_Text(pFX, "RoomNo", m_strRoomNo);  
   RFX_Text(pFX, "Schedule", m_strSchedule);  
   RFX_Text(pFX, "SectionNo", m_strSectionNo);  
}  
```  
  
 Observe os seguintes recursos principais da função:  
  
-   Esta seção da função é chamada de mapa de campo.  
  
-   Uma chamada para `CFieldExchange::SetFieldType`, por meio de `pFX` ponteiro. Essa chamada especifica que todos os RFX chamadas de função para cima até o final da `DoFieldExchange` ou a próxima chamada para `SetFieldType` são colunas de saída. Para obter mais informações, consulte [CFieldExchange::SetFieldType](../../mfc/reference/cfieldexchange-class.md#setfieldtype).  
  
-   Várias chamadas para o `RFX_Text` função global — um por membro de dados do campo (todos os que são `CString` variáveis no exemplo). Essas chamadas especificam a relação entre um nome de coluna na fonte de dados e um membro de dados do campo. As funções RFX fazer a transferência de dados reais. A biblioteca de classes fornece funções RFX para todos os tipos de dados comuns. Para obter mais informações sobre funções RFX, consulte [registrar troca de campos: usando as funções RFX](../../data/odbc/record-field-exchange-using-the-rfx-functions.md).  
  
    > [!NOTE]
    >  A ordem das colunas no conjunto de resultados deve corresponder à ordem das chamadas de função RFX em `DoFieldExchange`.  
  
-   O `pFX` ponteiro para um [CFieldExchange](../../mfc/reference/cfieldexchange-class.md) objeto framework passa quando chama `DoFieldExchange`. O `CFieldExchange` objeto Especifica a operação que `DoFieldExchange` é executar a direção da transferência e outras informações de contexto.  
  
##  <a name="_core_the_recordset_constructor"></a>Construtor de conjunto de registros  
 O construtor de conjunto de registros que os assistentes de gravação contém duas coisas relacionadas a RFX:  
  
-   Uma inicialização de cada membro de dados de campo  
  
-   A inicialização para o [m_nFields](../../mfc/reference/crecordset-class.md#m_nfields) membro de dados, que contém o número de membros de dados de campo  
  
 O construtor para o `CSections` exemplo de conjunto de registros tem esta aparência:  
  
```  
CSections::CSections(CDatabase* pdb)  
   : CRecordset(pdb)  
{  
   m_strCourseID = "";  
   m_strInstructorID = "";  
   m_strRoomNo = "";  
   m_strSchedule = "";  
   m_strSectionNo = "";  
   m_nFields = 5;  
}  
```  
  
> [!NOTE]
>  Se você adicionar quaisquer membros de dados do campo manualmente, como se você associar novas colunas dinamicamente, você deve incrementar `m_nFields`. Faça isso adicionando outra linha de código, como:  
  
```  
m_nFields += 3;  
```  

 Este é o código para adicionar três novos campos. Se você adicionar quaisquer membros de dados de parâmetro, você deverá inicializar o [m_nParams](../../mfc/reference/crecordset-class.md#m_nparams) membro de dados, que contém o número de membros de dados do parâmetro. Coloque o `m_nParams` inicialização fora os colchetes.  

  
## <a name="see-also"></a>Consulte também  
 [RFX (troca de campo de registro)](../../data/odbc/record-field-exchange-rfx.md)