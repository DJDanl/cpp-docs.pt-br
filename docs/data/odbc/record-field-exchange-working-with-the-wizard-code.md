---
title: 'Registrar troca de campos: Trabalhando com o código de Assistente | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: cffd5b262b40fca4814acbd5d0d89d6a6693c814
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50070543"
---
# <a name="record-field-exchange-working-with-the-wizard-code"></a>Registrar troca de campos: trabalhando com o código do assistente

Este tópico explica o código que o Assistente de aplicativo do MFC e **Add Class** (conforme descrito em [adicionando um consumidor de ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)) dar suporte a RFX e como você pode alterar esse código de gravação.

> [!NOTE]
>  Este tópico se aplica a classes derivadas de `CRecordset` em qual linha em massa buscando não foi implementado. Se você estiver usando a busca de linhas em massa, é implementada em massa registrar troca de campos (RFX em massa). Em massa RFX é semelhante a RFX. Para entender as diferenças, consulte [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Quando você cria uma classe de conjunto de registros com o Assistente de aplicativo do MFC ou **Adicionar classe**, o assistente grava os seguintes elementos de RFX para você, com base na fonte de dados, tabela e coluna escolhas feitas no Assistente:

- Declarações de membros de dados de campo do conjunto de registros na classe de conjunto de registros

- Uma substituição do `CRecordset::DoFieldExchange`

- Inicialização de membros de dados do campo de conjunto de registros no construtor da classe de conjunto de registros

##  <a name="_core_the_field_data_member_declarations"></a> Declarações de membro de dados de campo

Os assistentes de escrever uma declaração de classe do conjunto de registros em um arquivo. h que se parece com o seguinte para a classe `CSections`:

```cpp
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

Se você adicionar membros de dados de parâmetro ou novos membros de dados de campo que você associar por conta própria, você deve adicioná-los após aquelas geradas pelo assistente.

Além disso, observe que o assistente substitui o `DoFieldExchange` função de membro da classe `CRecordset`.

##  <a name="_core_the_dofieldexchange_override"></a> Substituição de DoFieldExchange

[DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) é o coração do RFX. A estrutura chama `DoFieldExchange` sempre que precisa para mover dados da fonte de dados para o conjunto de registros ou de conjunto de registros a fonte de dados. `DoFieldExchange` também dá suporte à obtenção de informações sobre o campo membros de dados por meio de [IsFieldDirty](../../mfc/reference/crecordset-class.md#isfielddirty) e [IsFieldNull](../../mfc/reference/crecordset-class.md#isfieldnull) funções de membro.

O seguinte `DoFieldExchange` substituição é para o `CSections` classe. O assistente grava a função no arquivo. cpp para a sua classe de conjunto de registros.

```cpp
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

- Esta seção da função é chamada de mapa de campo.

- Uma chamada para `CFieldExchange::SetFieldType`, por meio de `pFX` ponteiro. Essa chamada especifica que todas as função RFX chama-se ao final da `DoFieldExchange` ou a próxima chamada para `SetFieldType` são colunas de saída. Para obter mais informações, consulte [CFieldExchange::SetFieldType](../../mfc/reference/cfieldexchange-class.md#setfieldtype).

- Várias chamadas para o `RFX_Text` função global — um por membro de dados do campo (que são todos `CString` variáveis no exemplo). Essas chamadas de especificam a relação entre um nome de coluna na fonte de dados e um membro de dados do campo. As funções RFX fazem a transferência de dados real. A biblioteca de classes fornece funções RFX para todos os tipos de dados comuns. Para obter mais informações sobre as funções RFX, consulte [troca de campos do registro: usando as funções RFX](../../data/odbc/record-field-exchange-using-the-rfx-functions.md).

    > [!NOTE]
    >  A ordem das colunas no conjunto de resultados deve corresponder à ordem das chamadas de função RFX em `DoFieldExchange`.

- O `pFX` ponteiro para um [CFieldExchange](../../mfc/reference/cfieldexchange-class.md) objeto que o framework passa quando ele chama `DoFieldExchange`. O `CFieldExchange` objeto Especifica a operação que `DoFieldExchange` é executar a direção da transferência e outras informações de contexto.

##  <a name="_core_the_recordset_constructor"></a> Construtor de conjunto de registros

O construtor de conjunto de registros que os assistentes de gravação contém duas coisas relacionadas ao RFX:

- Uma inicialização para cada membro de dados de campo

- A inicialização para o [m_nFields](../../mfc/reference/crecordset-class.md#m_nfields) membro de dados, que contém o número de membros de dados de campo

O construtor para o `CSections` exemplo de conjunto de registros tem esta aparência:

```cpp
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
>  Se você adicionar quaisquer membros de dados do campo manualmente, como você pode se associar dinamicamente novas colunas, você deve incrementar `m_nFields`. Para fazer isso, acrescentando outra linha de código, tais como:

```cpp
m_nFields += 3;
```

Este é o código para adicionar três novos campos. Se você adicionar quaisquer membros de dados de parâmetro, você deve inicializar o [m_nParams](../../mfc/reference/crecordset-class.md#m_nparams) membro de dados, que contém o número de membros de dados do parâmetro. Coloque o `m_nParams` inicialização fora os colchetes.

## <a name="see-also"></a>Consulte também

[RFX (troca de campo de registro)](../../data/odbc/record-field-exchange-rfx.md)