---
title: 'Registrar Troca de Campos: como trabalhar com o código do assistente'
ms.date: 05/09/2019
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
ms.openlocfilehash: 81b26e61f64623d1e3da5ed207d0e8e43350229d
ms.sourcegitcommit: fc1de63a39f7fcbfe2234e3f372b5e1c6a286087
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/15/2019
ms.locfileid: "65707998"
---
# <a name="record-field-exchange-working-with-the-wizard-code"></a>Registrar Troca de Campos: como trabalhar com o código do assistente

> [!NOTE] 
> O Assistente de consumidor ODBC do MFC não está disponível no Visual Studio 2019 e posterior. É possível criar um consumidor manualmente.

Este tópico explica o código que o Assistente de aplicativo MFC e **Adicionar Classe** (conforme descrito em [Como adicionar um consumidor ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)) escrevem para dar suporte à RFX e como você pode alterar esse código.

> [!NOTE]
>  Este tópico aplica-se a classes derivadas de `CRecordset` nas quais o fetch de linha em massa não foi implementado. Se você estiver usando o fetch de linha em massa, a RFX (troca de campos de registro) em massa será implementada. A RFX em massa é semelhante à RFX. Para entender as diferenças, confira [Conjunto de registros: como efetuar fetch de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Quando você cria uma classe de conjunto de registros com o Assistente de Aplicativo MFC ou **Adicionar Classe**, o assistente escreve os seguintes elementos relacionados a RFX para você, com base nas opções de fonte de dados, de tabela e de coluna que você faz no assistente:

- Declarações dos membros de dados do campo do conjunto de registros na classe de conjunto de registros

- Uma substituição de `CRecordset::DoFieldExchange`

- Inicialização de membros de dados do conjunto de registros no construtor de classe do conjunto de registros

##  <a name="_core_the_field_data_member_declarations"></a> Declarações de Membro de Dados de Campo

Os assistentes escrevem uma declaração de classe do conjunto de registros em um arquivo .h com a seguinte aparência para a classe `CSections`:

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

Se você adicionar membros de dados de parâmetro ou novos membros de dados de campo que você mesmo associou, adicione-os após aqueles gerados pelo assistente.

Além disso, observe que o assistente substitui a função de membro `DoFieldExchange` da classe `CRecordset`.

##  <a name="_core_the_dofieldexchange_override"></a> Substituição de DoFieldExchange

[DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) é o coração da RFX. A estrutura chamará `DoFieldExchange` sempre que ele precisar mover dados da fonte de dados para o conjunto de registros ou do conjunto de registros para a fonte de dados. `DoFieldExchange` também é compatível com a obtenção de informações sobre membros de dados de campo por meio das funções de membro [IsFieldDirty](../../mfc/reference/crecordset-class.md#isfielddirty) e [IsFieldNull](../../mfc/reference/crecordset-class.md#isfieldnull).

A seguinte substituição `DoFieldExchange` é para a classe `CSections`. O assistente escreve a função no arquivo .cpp para sua classe de conjunto de registros.

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

- Esta seção da função é chamada de mapa de campos.

- Uma chamada a `CFieldExchange::SetFieldType`, por meio do ponteiro `pFX`. Essa chamada especifica que todas as chamadas de função RFX até o final de `DoFieldExchange` ou da próxima chamada a `SetFieldType` são colunas de saída. Para saber mais, confira [CFieldExchange::SetFieldType](../../mfc/reference/cfieldexchange-class.md#setfieldtype).

- Várias chamadas de função global `RFX_Text` — uma por membro de dados de campo (das quais, todas são variáveis `CString` no exemplo). Essas chamadas especificam a relação entre um nome de coluna na fonte de dados e um membro de dados de campo. As funções RFX fazem a verdadeira transferência de dados. A biblioteca de classes fornece funções RFX para todos os tipos de dados comuns. Para saber mais sobre as funções RFX, confira [Troca de campo de registro: como usar as funções RFX](../../data/odbc/record-field-exchange-using-the-rfx-functions.md).

    > [!NOTE]
    >  A ordem das colunas em seu conjunto de resultados deve corresponder à ordem das chamadas de função RFX em `DoFieldExchange`.

- O ponteiro `pFX` para um objeto [CFieldExchange](../../mfc/reference/cfieldexchange-class.md) que a estrutura passa quando ela chama `DoFieldExchange`. O objeto `CFieldExchange` especifica a operação que `DoFieldExchange` deve executar, a direção da transferência e outras informações de contexto.

##  <a name="_core_the_recordset_constructor"></a> Construtor do conjunto de registros

O construtor do conjunto de registros que o assistente escreve contém duas coisas relacionadas a RFX:

- uma inicialização para cada membro de dados de campo

- uma inicialização para o membro de dados [m_nFields](../../mfc/reference/crecordset-class.md#m_nfields), que contém o número de membros de dados de campo

O construtor do exemplo do conjunto de registros `CSections` tem a seguinte aparência:

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
>  Se você adicionar membros de dados de campo manualmente, como você poderá fazer se associar novas colunas dinamicamente, será necessário incrementar `m_nFields`. Faça isso acrescentando outra linha de código, como:

```cpp
m_nFields += 3;
```

Este é o código para adicionar três novos campos. Se você adicionar membros de dados de parâmetro, deverá inicializar o membro de dados [m_nParams](../../mfc/reference/crecordset-class.md#m_nparams), que contém o número de membros de dados de parâmetro. Coloque a inicialização `m_nParams` fora dos colchetes.

## <a name="see-also"></a>Consulte também

[RFX (troca de campo de registro)](../../data/odbc/record-field-exchange-rfx.md)