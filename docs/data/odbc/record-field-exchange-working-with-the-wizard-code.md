---
title: "Registrar troca de campos: trabalhando com o c&#243;digo do assistente | Microsoft Docs"
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
  - "Método DoFieldExchange, substituindo"
  - "Unicode, com classes de banco de dados"
  - "membros de dados de campo, declarando"
  - "RFX (ODBC), código de Assistente"
  - "RFX (ODBC), Implementando"
  - "membros de dados de campos"
  - "ODBC, RFX"
  - "membro de dados m_nParams, inicializando"
  - "Membro de dados m_nFields"
  - "Membro de dados m_nParams"
  - "substituindo DoFieldExchange"
  - "membro de dados m_nFields, inicializando"
ms.assetid: f00d882a-ff1b-4a75-9717-98d8762bb237
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Registrar troca de campos: trabalhando com o c&#243;digo do assistente
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico explica o código que o Assistente para aplicativo do MFC e **Add Class** \(conforme descrito em [Adicionando um consumidor de ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)\) oferecer suporte a RFX e como você talvez queira alterar o código de gravação.  
  
> [!NOTE]
>  Este tópico se aplica a classes derivadas de `CRecordset` no qual linha em massa busca não foi implementada. Se você estiver usando a busca de linhas em massa, a troca de campos de registro em massa \(RFX em massa\) é implementada. Em massa RFX é semelhante ao RFX. Para compreender as diferenças, consulte [conjunto de registros: recuperando registros em massa \(ODBC\)](../Topic/Recordset:%20Fetching%20Records%20in%20Bulk%20\(ODBC\).md).  
  
 Quando você cria uma classe de conjunto de registros com o Assistente para aplicativo do MFC ou **Add Class**, o assistente grava os seguintes elementos de RFX para você, com base na fonte de dados, tabela e coluna escolhas feitas no Assistente:  
  
-   Declarações de membros de dados de campo do conjunto de registros na classe de conjunto de registros  
  
-   Substituição de `CRecordset::DoFieldExchange`  
  
-   Inicialização de membros de dados de campo do conjunto de registros no construtor da classe de conjunto de registros  
  
##  <a name="_core_the_field_data_member_declarations"></a> Declarações de membro de dados de campo  
 Os assistentes de escrever uma declaração de classe de conjunto de registros em um arquivo. h que se parece com o seguinte para a classe `CSections`:  
  
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
  
 Se você adicionar membros de dados de parâmetro ou novos membros de dados de campo que você associar\-se, você deve adicioná\-los depois aqueles gerados pelo assistente.  
  
 Além disso, observe que o assistente substitui o `DoFieldExchange` a função de membro da classe `CRecordset`.  
  
##  <a name="_core_the_dofieldexchange_override"></a> Substituição de DoFieldExchange  
 [DoFieldExchange](../Topic/CRecordset::DoFieldExchange.md) é o coração do RFX. O framework chama `DoFieldExchange` sempre precisa mover dados da fonte de dados ao conjunto de registros ou de conjunto de registros a fonte de dados.`DoFieldExchange` também oferece suporte à obtenção de informações sobre o campo membros de dados por meio de [IsFieldDirty](../Topic/CRecordset::IsFieldDirty.md) e [IsFieldNull](../Topic/CRecordset::IsFieldNull.md) funções de membro.  
  
 O seguinte `DoFieldExchange` substituição é para o `CSections` classe. O assistente grava a função no arquivo. cpp para sua classe de conjunto de registros.  
  
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
  
-   Uma chamada para `CFieldExchange::SetFieldType`, por meio de `pFX` ponteiro. Essa chamada especifica a função RFX all chama ao final da `DoFieldExchange` ou a próxima chamada para `SetFieldType` são colunas de saída. Para obter mais informações, consulte [CFieldExchange::SetFieldType](../Topic/CFieldExchange::SetFieldType.md).  
  
-   Várias chamadas para o `RFX_Text` função global — um por membro de dados do campo \(todos os quais são `CString` variáveis no exemplo\). Essas chamadas especificam a relação entre um nome de coluna na fonte de dados e um membro de dados do campo. As funções RFX fazem a transferência de dados reais. A biblioteca de classes fornece funções RFX para todos os tipos de dados comuns. Para obter mais informações sobre as funções RFX, consulte [troca de campos do registro: usando as funções RFX](../../data/odbc/record-field-exchange-using-the-rfx-functions.md).  
  
    > [!NOTE]
    >  A ordem das colunas no conjunto de resultados deve corresponder à ordem das chamadas de função RFX em `DoFieldExchange`.  
  
-   O `pFX` ponteiro para um [CFieldExchange](../../mfc/reference/cfieldexchange-class.md) objeto o framework passa quando ela chama `DoFieldExchange`. O `CFieldExchange` objeto Especifica a operação que `DoFieldExchange` é executar a direção da transferência e outras informações de contexto.  
  
##  <a name="_core_the_recordset_constructor"></a> Construtor de conjunto de registros  
 O construtor de conjunto de registros que os assistentes de gravação contém duas coisas relacionadas ao RFX:  
  
-   Uma inicialização de cada membro de dados de campo  
  
-   A inicialização para o [m\_nFields](../Topic/CRecordset::m_nFields.md) membro de dados, que contém o número de membros de dados de campo  
  
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
>  Se você adicionar membros de dados de qualquer campo manualmente, como você pode se associar dinamicamente novas colunas, você deve incrementar `m_nFields`. Fazer isso acrescentando outra linha de código, como:  
  
```  
m_nFields += 3;  
```  
  
 Este é o código para adicionar três novos campos. Se você adicionar qualquer membro de dados de parâmetro, você deve inicializar o [m\_nParams](../Topic/CRecordset::m_nParams.md) membro de dados, que contém o número de membros de dados do parâmetro. Coloque o `m_nParams` inicialização fora dos colchetes.  
  
## Consulte também  
 [Registrar troca de campos \(RFX\)](../../data/odbc/record-field-exchange-rfx.md)