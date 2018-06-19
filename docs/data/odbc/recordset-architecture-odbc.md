---
title: 'Conjunto de registros: Arquitetura (ODBC) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- recordsets, data members
- field data members, recordset architecture
- field data members
- m_nParams data member, recordsets
- recordsets, architecture
- parameter data members in recordsets
- m_nFields data member
- ODBC recordsets, architecture
- m_nParams data member
- m_nFields data member, recordsets
ms.assetid: 47555ddb-11be-4b9e-9b9a-f2931764d298
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 5be3ec16ec01a6c6db2e24b1b6a6260f3a44bfec
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33092204"
---
# <a name="recordset-architecture-odbc"></a>Conjunto de registros: arquitetura (ODBC)
Este tópico se aplica às classes MFC ODBC.  
  
 Este tópico descreve os membros de dados que compõem a arquitetura de um objeto de conjunto de registros:  
  
-   [Membros de dados de campo](#_core_field_data_members)  
  
-   [Membros de dados de parâmetro](#_core_parameter_data_members)  
  
-   [Usando membros de dados m_nFields e m_nParams](#_core_using_m_nfields_and_m_nparams)  
  
> [!NOTE]
>  Este tópico se aplica a objetos derivados de `CRecordset` em qual linha em massa busca não foi implementada. Se a busca de linhas em massa é implementada, a arquitetura é semelhante. Para entender as diferenças, consulte [conjunto de registros: busca de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).  
  
##  <a name="_core_a_sample_class"></a> Exemplo de classe  
 Quando você usa o [Assistente de consumidor ODBC MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md) de **Adicionar classe** derivado do Assistente para declarar uma classe de conjunto de registros `CRecordset`, a classe resultante tem a estrutura geral mostrada a seguir simple classe:  
  
```  
class CCourse : public CRecordset  
{  
public:  
   CCourse(CDatabase* pDatabase = NULL);  
   ...  
   CString m_strCourseID;  
   CString m_strCourseTitle;  
   CString m_strIDParam;  
};  
```  
  
 No início da classe, o assistente grava um conjunto de [membros de dados de campo](#_core_field_data_members). Quando você cria a classe, você deve especificar um ou mais membros de dados de campo. Se a classe for parametrizada, como o exemplo de classe é (com o membro de dados `m_strIDParam`), você deve adicionar manualmente [membros de dados do parâmetro](#_core_parameter_data_members). O assistente não oferece suporte para adicionar parâmetros a uma classe.  
  
##  <a name="_core_field_data_members"></a> Membros de dados de campo  
 Os membros mais importantes da classe do conjunto de registros são os membros de dados do campo. Para cada coluna selecionada da fonte de dados, a classe contém um membro de dados do tipo de dados apropriado para essa coluna. Por exemplo, o [exemplo classe](#_core_a_sample_class) mostrado no início deste tópico tem dois membros de dados de campo, do tipo `CString`, chamado `m_strCourseID` e `m_strCourseTitle`.  
  
 Quando o conjunto de registros seleciona um conjunto de registros, a estrutura automaticamente associa as colunas do registro atual (após o **abrir** chamada, o primeiro registro é atual) para os membros de dados de campo do objeto. Ou seja, a estrutura usa o membro de dados de campo apropriado como um buffer para armazenar o conteúdo de uma coluna de registro.  
  
 Conforme o usuário rola para um novo registro, a estrutura usa os membros de dados de campo para representar o registro atual. A estrutura atualiza os membros de dados do campo, substituindo os valores do registro anterior. Os membros de dados do campo também são usados para atualizar o registro atual e para adicionar novos registros. Como parte do processo de atualização de um registro, você pode especificar os valores de atualização, atribuindo valores diretamente para os membros de dados de campo apropriado ou membros.  
  
##  <a name="_core_parameter_data_members"></a> Membros de dados de parâmetro  
 Se a classe for parametrizada, ele tem um ou mais membros de dados de parâmetro. Uma classe com parâmetros permite que uma consulta de conjunto de registros de base nas informações obtidas ou calculados em tempo de execução.  
  
 Normalmente, o parâmetro ajuda a restringir a seleção, como no exemplo a seguir. Com base no [exemplo classe](#_core_a_sample_class) no início deste tópico, o objeto de conjunto de registros pode executar a seguinte instrução SQL:  
  
```  
SELECT CourseID, CourseTitle FROM Course WHERE CourseID = ?  
```  
  
 O "?" é um espaço reservado para um valor de parâmetro que você fornecer em tempo de execução. Quando você cria o conjunto de registros e defina seu `m_strIDParam` torna-se membro de dados para MATH101, a instrução SQL efetivada para o conjunto de registros:  
  
```  
SELECT CourseID, CourseTitle FROM Course WHERE CourseID = MATH101  
```  
  
 Definindo membros de dados de parâmetro, você informar o framework sobre parâmetros na cadeia de caracteres SQL. A estrutura associa o parâmetro, que permite que o ODBC Saiba onde obter valores para substituir o espaço reservado. No exemplo, o conjunto de registros resultante contém somente o registro da tabela com uma coluna CourseID cujo valor é MATH101 curso. Todas as colunas especificadas desse registro são selecionadas. Você pode especificar quantos parâmetros (e espaços reservados) conforme necessário.  
  
> [!NOTE]
>  MFC não faz nada em si com os parâmetros – em particular, ele não executa uma substituição de texto. Em vez disso, o MFC informa ODBC onde obter o parâmetro; ODBC recupera os dados e executa a parametrização necessário.  
  
> [!NOTE]
>  A ordem dos parâmetros é importante. Para obter informações sobre isso e obter mais informações sobre parâmetros, consulte [conjunto de registros: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).  
  
##  <a name="_core_using_m_nfields_and_m_nparams"></a> Usando m_nFields e m_nParams  

 Quando um assistente grava um construtor para sua classe, também inicia o [m_nFields](../../mfc/reference/crecordset-class.md#m_nfields) membro de dados, que especifica o número de [membros de dados de campo](#_core_field_data_members) na classe. Se você adicionar qualquer [parâmetros](#_core_parameter_data_members) à sua classe, você também deverá adicionar a inicialização para o [m_nParams](../../mfc/reference/crecordset-class.md#m_nparams) membro de dados, que especifica o número de membros de dados do parâmetro. A estrutura usa esses valores para trabalhar com os membros de dados.  
  
 Para obter mais informações e exemplos, consulte [registrar troca de campos: usando RFX](../../data/odbc/record-field-exchange-using-rfx.md).  
  
## <a name="see-also"></a>Consulte também  
 [Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: Declarando uma classe para uma tabela (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-table-odbc.md)   
 [RFX (troca de campo de registro)](../../data/odbc/record-field-exchange-rfx.md)