---
title: "SQL: Personalizando a instrução SQL de seu conjunto de registros (ODBC) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- recordsets, SQL statements
- ODBC recordsets, SQL statements
- SQL statements, customizing
- SQL statements, recordset
- customizing SQL statements
- overriding, SQL statements
- SQL, opening recordsets
ms.assetid: 72293a08-cef2-4be2-aa1c-30565fcfbaf9
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: cae8862dd8fc10dd117b07414ab00a34117f5e10
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="sql-customizing-your-recordsets-sql-statement-odbc"></a>SQL: personalizando a instrução SQL do conjunto de registros (ODBC)
Este tópico explica:  
  
-   Como o framework constrói uma instrução SQL  
  
-   Como substituir a instrução SQL  
  
> [!NOTE]
>  Essas informações se aplicam às classes MFC ODBC. Se você estiver trabalhando com as classes DAO MFC, consulte o tópico "Comparação do banco de dados do mecanismo de SQL e ANSI SQL do Microsoft Jet" na Ajuda do DAO.  
  
## <a name="sql-statement-construction"></a>Construção de instrução SQL  
 O conjunto de registros bases seleção de registros principalmente em um SQL **selecione** instrução. Quando você declara a classe com um assistente, ele grava uma versão substituindo o `GetDefaultSQL` função de membro que tem a seguinte aparência (para uma classe de conjunto de registros chamado `CAuthors`).  
  
```  
CString CAuthors::GetDefaultSQL()  
{  
    return "AUTHORS";  
}  
```  
  
 Por padrão, essa substituição retorna o nome da tabela especificada com o assistente. No exemplo, o nome da tabela é "Autores". Quando você chama o conjunto de registros posteriormente **abrir** função de membro, **abrir** constrói um final **selecione** instrução do formulário:  
  
```  
SELECT rfx-field-list FROM table-name [WHERE m_strFilter]   
       [ORDER BY m_strSort]  
```  
  
 onde `table-name` é obtido chamando `GetDefaultSQL` e `rfx-field-list` é obtido de chamadas de função RFX em `DoFieldExchange`. Este é o que você obterá um **selecione** instrução, a menos que você substituí-lo com uma versão de substituição em tempo de execução, embora você também pode modificar a instrução padrão com parâmetros ou um filtro.  
  
> [!NOTE]
>  Se você especificar um nome de coluna que contém espaços (ou pode conter uma), você deve colocar o nome entre colchetes. Por exemplo, o nome "Nome" deve ser "[nome]".  
  
 Para substituir o padrão **selecione** instrução, passe uma cadeia de caracteres que contém um conjunto completo **selecione** instrução ao chamar **abrir**. Em vez de criar sua própria cadeia de caracteres padrão, o conjunto de registros usa a cadeia de caracteres que você fornecer. Se a instrução de substituição contém um **onde** cláusula, não especifique um filtro em **m_strFilter** porque você teria duas instruções de filtro. Da mesma forma, se a instrução de substituição contém um **ORDER BY** cláusula, não especifique uma classificação em `m_strSort` para que você não terá duas instruções de classificação.  
  
> [!NOTE]
>  Se você usar cadeias de caracteres literais em seus filtros (ou outras partes da instrução SQL), talvez você precise "quote" (coloque entre delimitadores especificados) como cadeias de caracteres com um prefixo de literal de DBMS específico e literal sufixo caractere (ou caracteres).  
  
 Você também pode encontrar os requisitos especiais de sintáticos para operações como junções externas, dependendo do DBMS. Use funções ODBC para obter essas informações de seu driver para o DBMS. Por exemplo, chamar **:: SQLGetTypeInfo** para um tipo de dados específico, como **SQL_VARCHAR**, para solicitar o **LITERAL_PREFIX** e **LITERAL_SUFFIX** caracteres. Se você estiver escrevendo código independente do banco de dados, consulte o Apêndice C no *ODBC SDK**referência do programador de* no CD de biblioteca do MSDN para obter informações detalhadas de sintaxe.  
  
 Um objeto recordset constrói a instrução SQL que ele utiliza para selecionar registros, a menos que você passar uma instrução SQL personalizada. Como fazer isso depende principalmente o valor da `lpszSQL` parâmetro o **abrir** função de membro.  
  
 A forma geral de um SQL **selecione** instrução é:  
  
```  
SELECT [ALL | DISTINCT] column-list FROM table-list  
    [WHERE search-condition][ORDER BY column-list [ASC | DESC]]  
```  
  
 Uma maneira de adicionar o **DISTINCT** palavra-chave para a instrução de SQL do seu conjunto de registros é inserir a palavra-chave na primeira chamada de função RFX em `DoFieldExchange`. Por exemplo:  
  
```  
...  
    RFX_Text(pFX, "DISTINCT CourseID", m_strCourseID);  
...  
```  
  
> [!NOTE]
>  Use essa técnica somente com um conjunto de registros aberto como somente leitura.  
  
## <a name="overriding-the-sql-statement"></a>Substituindo a instrução SQL  
 A tabela a seguir mostra as possibilidades para o `lpszSQL` parâmetro **abrir**. Os casos na tabela são explicados a tabela a seguir.  
  
 **O parâmetro lpszSQL e a cadeia de caracteres resultante do SQL**  
  
|Caso|O que é passado no lpszSQL|A instrução SELECT resultante|  
|----------|------------------------------|------------------------------------|  
|1|**NULL**|**Selecione** *lista de campos de rfx* **FROM** *nome de tabela*<br /><br /> `CRecordset::Open`chamadas `GetDefaultSQL` para obter o nome da tabela. A cadeia de caracteres resultante é um dos casos de 2 a 5, dependendo do que `GetDefaultSQL` retorna.|  
|2|Um nome de tabela|**Selecione** *lista de campos de rfx* **FROM** *nome de tabela*<br /><br /> A lista de campos é obtida das instruções RFX em `DoFieldExchange`. Se **m_strFilter** e `m_strSort` não estão vazios, adiciona o **onde** e/ou **ORDER BY** cláusulas.|  
|3 *|Um conjunto completo **selecione** instrução mas sem uma **onde** ou **ORDER BY** cláusula|Como aprovada. Se **m_strFilter** e `m_strSort` não estão vazios, adiciona o **onde** e/ou **ORDER BY** cláusulas.|  
|4 *|Um conjunto completo **selecione** instrução com uma **onde** e/ou **ORDER BY** cláusula|Como aprovada. **m_strFilter** e/ou `m_strSort` devem permanecer vazio ou um filtro de duas e/ou instruções de classificação são produzidas.|  
|5 *|Uma chamada para um procedimento armazenado|Como aprovada.|  
  
 \*`m_nFields` deve ser menor ou igual ao número de colunas especificado no **selecione** instrução. O tipo de dados de cada coluna especificado no **selecione** instrução deve ser o mesmo que o tipo de dados da coluna de saída RFX correspondente.  
  
### <a name="case-1---lpszsql--null"></a>Caso 1 lpszSQL = NULL  
 A seleção de conjunto de registros depende de qual `GetDefaultSQL` retorna quando `CRecordset::Open` chamá-lo. Casos de 2 a 5 descrevem as cadeias de caracteres possíveis.  
  
### <a name="case-2---lpszsql--a-table-name"></a>Caso 2 lpszSQL = um nome de tabela  
 O conjunto de registros usa a troca de campos de registro (RFX) para criar a lista de colunas a partir dos nomes de coluna fornecido no RFX função chama na substituição da classe de conjunto de registros de `DoFieldExchange`. Se você usou um Assistente para declarar a classe de conjunto de registros, neste caso, tem o mesmo resultado de caso 1 (desde que você passar o mesmo nome da tabela especificada no Assistente). Se você não usar um Assistente para escrever sua classe, caso 2 é a maneira mais simples para construir a instrução SQL.  
  
 O exemplo a seguir constrói uma instrução SQL que seleciona os registros de um aplicativo de banco de dados MFC. Quando o framework chama o `GetDefaultSQL` função de membro, a função retorna o nome da tabela, `SECTION`.  
  
```  
CString CEnrollSet::GetDefaultSQL()  
{  
    return "SECTION";  
}  
```  
  
 Para obter os nomes das colunas para o SQL **selecione** instrução, o framework chama o `DoFieldExchange` função de membro.  
  
```  
void CEnrollSet::DoFieldExchange(CFieldExchange* pFX)  
{  
    pFX->SetFieldType(CFieldExchange::outputColumn);  
    RFX_Text(pFX, "CourseID", m_strCourseID);  
    RFX_Text(pFX, "InstructorID", m_strInstructorID);  
    RFX_Text(pFX, "RoomNo", m_strRoomNo);  
    RFX_Text(pFX, "Schedule", m_strSchedule);  
    RFX_Text(pFX, "SectionNo", m_strSectionNo);  
}  
```  
  
 Ao concluir, a instrução SQL tem esta aparência:  
  
```  
SELECT CourseID, InstructorID, RoomNo, Schedule, SectionNo   
    FROM SECTION  
```  
  
### <a name="case-3---lpszsql--a-selectfrom-statement"></a>Caso 3 lpszSQL = SELECT na instrução  
 Especifique a lista de colunas manualmente em vez de contar RFX para construí-lo automaticamente. Talvez você queira fazer isso quando:  
  
-   Para especificar o **DISTINCT** seguinte palavra-chave **selecione**.  
  
     Sua lista de colunas deve corresponder a nomes de coluna e tipos na mesma ordem como eles estão listados no `DoFieldExchange`.  
  
-   Você tem o motivo para recuperar manualmente os valores de coluna usando a função ODBC **:: SQLGetData** em vez de contar RFX para associar e recuperar colunas para você.  
  
     Por exemplo, convém acomodar novas colunas de que um cliente de seu aplicativo adicionado às tabelas de banco de dados depois que o aplicativo foi distribuído. Você precisa adicionar esses membros de dados de campo extra, que não eram conhecidos no momento em que você declarou a classe com um assistente.  
  
     Sua lista de colunas deve corresponder a nomes de coluna e tipos na mesma ordem como eles estão listados no `DoFieldExchange`, seguido pelos nomes das colunas associadas manualmente. Para obter mais informações, consulte [conjunto de registros: dinamicamente de associação de dados colunas (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).  
  
-   Você deseja associar tabelas com a especificação de várias tabelas no **FROM** cláusula.  
  
     Para obter informações e um exemplo, consulte [conjunto de registros: executar uma junção (ODBC)](../../data/odbc/recordset-performing-a-join-odbc.md).  
  
### <a name="case-4---lpszsql--selectfrom-plus-where-andor-order-by"></a>Caso 4 lpszSQL = SELECT / FROM e WHERE e/ou ORDER BY  
 Especificar tudo: a lista de colunas (com base em chamadas de RFX em `DoFieldExchange`), a lista de tabela e o conteúdo de um **onde** e/ou um **ORDER BY** cláusula. Se você especificar o **onde** e/ou **ORDER BY** cláusulas dessa forma, não use **m_strFilter** e/ou `m_strSort`.  
  
### <a name="case-5---lpszsql--a-stored-procedure-call"></a>Caso 5 lpszSQL = uma chamada de procedimento armazenado  
 Se você precisa chamar uma consulta predefinida (como um procedimento armazenado em um banco de dados do Microsoft SQL Server), você deve escrever uma **chamar** instrução na cadeia de caracteres que você passa para `lpszSQL`. Os assistentes não dão suporte para declarar uma classe de conjunto de registros para chamar uma consulta predefinida. Nem todas as consultas predefinidas retornam registros.  
  
 Se uma consulta predefinida não retornar registros, você pode usar o `CDatabase` função de membro `ExecuteSQL` diretamente. Para uma consulta predefinida que retornam registros, você deve gravar manualmente o RFX chamadas em `DoFieldExchange` para todas as colunas que o procedimento retorna. As chamadas RFX devem estar na mesma ordem e retornar os mesmos tipos, como a consulta predefinida. Para obter mais informações, consulte [conjunto de registros: declarando uma classe para um predefinidos consultas (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-predefined-query-odbc.md).  
  
## <a name="see-also"></a>Consulte também  
 [SQL: SQL e tipos de dados C++ (ODBC)](../../data/odbc/sql-sql-and-cpp-data-types-odbc.md)   
 [SQL: fazendo chamadas SQL diretas (ODBC)](../../data/odbc/sql-making-direct-sql-calls-odbc.md)
