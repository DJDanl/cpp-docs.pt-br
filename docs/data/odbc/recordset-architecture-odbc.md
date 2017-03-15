---
title: "Conjunto de registros: arquitetura (ODBC) | Microsoft Docs"
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
  - "membros de dados de campos"
  - "membros de dados de campos, arquitetura de conjunto de registros"
  - "Membro de dados m_nFields"
  - "Membro de dados m_nFields, conjuntos de registros"
  - "Membro de dados m_nParams"
  - "Membro de dados m_nParams, conjuntos de registros"
  - "conjunto de registros ODBC, arquitetura"
  - "membros de dados de parâmetros em conjuntos de registros"
  - "conjuntos de registros, arquitetura"
  - "conjuntos de registros, membros de dados"
ms.assetid: 47555ddb-11be-4b9e-9b9a-f2931764d298
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conjunto de registros: arquitetura (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico se aplica às classes ODBC do MFC.  
  
 Este tópico descreve os membros de dados que incluem a arquitetura de um objeto do conjunto de registros:  
  
-   [Membros de dados do campo](#_core_field_data_members)  
  
-   [Membros de dados do parâmetro](#_core_parameter_data_members)  
  
-   [Usando m\_nFields e membros de dados de m\_nParams](#_core_using_m_nfields_and_m_nparams)  
  
> [!NOTE]
>  Este tópico se aplica a objetos derivados de `CRecordset` no qual a busca de linhas do volume não foi implementado.  Se buscar em massa de linha é implementado, a arquitetura é semelhante.  Para entender as diferenças, consulte [Conjunto de registros: Buscando registros em massa \(ODBC\)](../Topic/Recordset:%20Fetching%20Records%20in%20Bulk%20\(ODBC\).md).  
  
##  <a name="_core_a_sample_class"></a> Exemplo de classe  
 Quando você usa [Assistente do consumidor MFC ODBC](../../mfc/reference/adding-an-mfc-odbc-consumer.md) do assistente de **Adicionar Classe** para declarar uma classe do conjunto de registros derivada de `CRecordset`, a classe resultante tem a estrutura geral mostrada na classe simples:  
  
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
  
 No início da classe, o assistente grava um conjunto de [membros de dados do campo](#_core_field_data_members).  Quando você cria a classe, você deve especificar um ou mais membros de dados do campo.  Se a classe for parametrizado, como a classe de exemplo é \(com o membro de dados `m_strIDParam`\), adicione manualmente [membros de dados do parâmetro](#_core_parameter_data_members).  O assistente não oferece suporte para adicionar parâmetros a uma classe.  
  
##  <a name="_core_field_data_members"></a> Membros de dados do campo  
 Os membros mais importantes da classe do conjunto de registros são os membros de dados do campo.  Para cada coluna selecionada da fonte de dados, a classe contém um membro de dados do tipo de dados apropriado para essa coluna.  Por exemplo, [classe de exemplo](#_core_a_sample_class) mostrado no início deste tópico tem dois membros de dados do campo, o tipo `CString`, `m_strCourseID` chamado e `m_strCourseTitle`.  
  
 Quando o conjunto de registros seleciona um conjunto de registros, a estrutura associa automaticamente as colunas do registro atual \(depois da chamada de **Abrir** , o primeiro registro é atual\) a membros de dados do campo do objeto.  Isto é, a estrutura usa o membro de dados apropriado de campo como um buffer para armazenar o conteúdo de uma coluna do registro.  
  
 Como rolagens do usuário para um novo registro, a estrutura usa os membros de dados do campo para representar o registro atual.  A estrutura atualiza membros de dados do campo, substituindo os valores anteriores do registro.  Os membros de dados do campo também são usados pela atualização do registro atual e adicionando novos registros.  Como parte do processo de atualização de um registro, você especifica os valores de atualização atribuindo valores diretamente ao membro de dados ou membros apropriados do campo.  
  
##  <a name="_core_parameter_data_members"></a> Membros de dados do parâmetro  
 Se a classe for parametrizado, tem um ou mais membros de dados do parâmetro.  Uma classe parametrizada permite de uma consulta do conjunto de registros nas informações obtidas calculada ou em tempo de execução.  
  
 Normalmente, a ajuda do parâmetro restringem a seleção, como no exemplo a seguir.  Baseado em [classe de exemplo](#_core_a_sample_class) no início desse tópico, o objeto do conjunto de registros pode executar a seguinte instrução SQL:  
  
```  
SELECT CourseID, CourseTitle FROM Course WHERE CourseID = ?  
```  
  
 “?” é um espaço reservado para um valor do parâmetro que você fornece em tempo de execução.  Quando você constrói o conjunto de registros e defina seu membro de dados de `m_strIDParam` a MATH101, a instrução SQL efetiva para o conjunto de registros é:  
  
```  
SELECT CourseID, CourseTitle FROM Course WHERE CourseID = MATH101  
```  
  
 Definindo membros de dados do parâmetro, informe a estrutura sobre parâmetros na cadeia de caracteres SQL.  A estrutura associa o parâmetro, que permite que o ODBC saiba onde obter valores para substituir o espaço reservado.  No exemplo, o conjunto de registros resultante conterá apenas o registro da tabela course com uma coluna CourseID cujo valor é MATH101.  Todas as colunas especificadas do registro são selecionadas.  Você pode especificar vários parâmetros e espaços reservados \(\) como você precisa.  
  
> [!NOTE]
>  O MFC não fará nada próprio com os parâmetros — em particular, não executa uma substituição em texto.  Em vez disso, o MFC informa ao ODBC onde obter o parâmetro; ODBC recupera os dados e executar a parametrização necessária.  
  
> [!NOTE]
>  A ordem de parâmetros é importante.  Para obter mais informações a respeito e mais informações sobre parâmetros, consulte [Conjunto de registros: A parametrização de um conjunto de registros \(ODBC\)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).  
  
##  <a name="_core_using_m_nfields_and_m_nparams"></a> Usando m\_nFields e m\_nParams  
 Quando um assistente grava um construtor para sua classe, também inicializa o membro de dados de [m\_nFields](../Topic/CRecordset::m_nFields.md) , que especifica o número de [membros de dados do campo](#_core_field_data_members) na classe.  Se você adicionar qualquer [parâmetros](#_core_parameter_data_members) a sua classe, você também deverá adicionar uma inicialização do membro de dados de [m\_nParams](../Topic/CRecordset::m_nParams.md) , que especifica o número de membros de dados do parâmetro.  A estrutura usa esses valores para trabalhar com os membros de dados.  
  
 Para obter mais informações e exemplos, consulte [Exchange campo do registro: Usando RFX](../../data/odbc/record-field-exchange-using-rfx.md).  
  
## Consulte também  
 [Conjunto de registros \(ODBC\)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: declarando uma classe para uma tabela \(ODBC\)](../../data/odbc/recordset-declaring-a-class-for-a-table-odbc.md)   
 [Registrar troca de campos \(RFX\)](../../data/odbc/record-field-exchange-rfx.md)