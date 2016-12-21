---
title: "SQL: personalizando a instru&#231;&#227;o SQL do conjunto de registros (ODBC) | Microsoft Docs"
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
  - "personalizando instruções SQL"
  - "conjunto de registros ODBC, instruções SQL"
  - "substituição, instruções SQL"
  - "conjuntos de registros, instruções SQL"
  - "instruções SQL, personalizando"
  - "instruções SQL, conjunto de registros"
  - "SQL, abrindo conjuntos de registros"
ms.assetid: 72293a08-cef2-4be2-aa1c-30565fcfbaf9
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# SQL: personalizando a instru&#231;&#227;o SQL do conjunto de registros (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico explica:  
  
-   Como a estrutura constrói uma instrução SQL  
  
-   Como substituir a instrução SQL  
  
> [!NOTE]
>  Essas informações são aplicadas às classes de MFC ODBC.  Se você estiver trabalhando com as classes de MFC DAO, consulte o tópico “comparação do Microsoft Jet Mecanismo de Base de dados SQL e ANSI SQL” na ajuda de DAO.  
  
## Construção da instrução SQL  
 As bases do conjunto de registros registram a seleção primeiro em uma instrução SQL **SELECIONAR** .  Quando declara a sua classe com um assistente, escreva uma versão substituindo da função de membro de `GetDefaultSQL` quais aspectos aparência \(para uma classe `CAuthors`chamado de conjunto de registros\).  
  
```  
CString CAuthors::GetDefaultSQL()  
{  
    return "AUTHORS";  
}  
```  
  
 Por padrão, essa substituição retorna o nome da tabela especificado com o assistente.  No exemplo, o nome da tabela é “AUTORES”. Quando você posterior chame a função de membro de **Abrir** do conjunto de registros, **Abrir** construir uma instrução final de **SELECIONAR** do formulário:  
  
```  
SELECT rfx-field-list FROM table-name [WHERE m_strFilter]   
       [ORDER BY m_strSort]  
```  
  
 onde `table-name` é obtido chamando `GetDefaultSQL` e `rfx-field-list` é obtido das chamadas de função de RFX em `DoFieldExchange`.  Isso é o que você obtém a de uma instrução de **SELECIONAR** a menos que você a ser substituído por uma versão substituindo em tempo de execução, embora você também pode modificar a instrução padrão com parâmetros ou um filtro.  
  
> [!NOTE]
>  Se você especificar um nome de coluna que contenha \(ou\) pode conter espaços, você deve incluir o nome entre colchetes.  Por exemplo, o nome “name” deve ser “\[name\]”.  
  
 Para substituir a instrução padrão de **SELECIONAR** , passar uma cadeia de caracteres que contém uma instrução completa de **SELECIONAR** quando você chama **Abrir**.  Em vez de criar sua própria cadeia de caracteres padrão, o conjunto de registros usa a cadeia de caracteres que você fornece.  Se a instrução de substituição contém uma cláusula de **WHERE** , não especifique um filtro em **m\_strFilter** porque você teria em duas instruções de filtro.  De modo semelhante, se a instrução de substituição contém uma cláusula **ORDER BY** não especifique uma classificação em `m_strSort` de modo que você não tenha duas instruções de classificação.  
  
> [!NOTE]
>  Se você usar cadeias de caracteres literais nos filtros \(ou outras partes da instrução SQL\), você pode ter que “e” \(incluir em delimitadores especificados\) essas cadeias de caracteres com um prefixo literal DBMS específico e um caractere literal \(ou um sufixo de caracteres\).  
  
 Você também pode localizar sintáticos requisitos especiais para operações como junções externas, dependendo do DBMS.  Use funções ODBC para obter essas informações do driver para o DBMS.  Por exemplo, chame **::SQLGetTypeInfo** para um tipo de dados específico, como **SQL\_VARCHAR**, para solicitar os caracteres de **LITERAL\_PREFIX** e de **LITERAL\_SUFFIX** .  Se você estiver gravando o código base de dados \- independentemente, consulte o apêndice C em ODBC programmer's reference *SDK* no CD de Biblioteca MSDN para obter informações detalhadas de sintaxe.  
  
 Um objeto do conjunto de registros constrói a instrução SQL que o usa para selecionar registros a menos que você transmitir uma instrução SQL personalizado.  Como isso é feito depende principalmente do valor que você passa no parâmetro de `lpszSQL` da função de membro de **Abrir** .  
  
 O formato geral de uma instrução SQL **SELECIONAR** é:  
  
```  
SELECT [ALL | DISTINCT] column-list FROM table-list  
    [WHERE search-condition][ORDER BY column-list [ASC | DESC]]  
```  
  
 Uma maneira de adicionar a palavra\-chave de **DISTINCT** à instrução SQL do conjunto de registros é inserir a palavra\-chave na primeira chamada de função de RFX em `DoFieldExchange`.  Por exemplo:  
  
```  
...  
    RFX_Text(pFX, "DISTINCT CourseID", m_strCourseID);  
...  
```  
  
> [!NOTE]
>  Use essa técnica somente com um conjunto de registros aberto como somente leitura.  
  
## Substituindo a instrução SQL  
 A tabela a seguir mostra as possibilidades para o parâmetro de `lpszSQL` a **Abrir**.  Os casos na tabela são explicados depois da tabela.  
  
 **O parâmetro de lpszSQL e a cadeia de caracteres resultante do SQL**  
  
|Case|O que você passa em lpszSQL|A instrução SELECT resultante|  
|----------|---------------------------------|-----------------------------------|  
|1|**NULL**|*com nome*de **FROM***de rfx\-campo\- lista* de**SELECIONAR**<br /><br /> `CRecordset::Open` `GetDefaultSQL` chama para obter o nome da tabela.  A cadeia de caracteres resultante é uma do caso 2 a 5, dependendo de `GetDefaultSQL` retorna.|  
|2|Um nome de tabela|*com nome*de **FROM***de rfx\-campo\- lista* de**SELECIONAR**<br /><br /> A lista de campos é tomada de instruções de RFX em `DoFieldExchange`.  Se **m\_strFilter** e `m_strSort` não estão vazias, adiciona as cláusulas de **WHERE** e\/ou de **ORDER BY** .|  
|3 \*|Uma instrução completa de **SELECIONAR** mas sem uma cláusula de **WHERE** ou de **ORDER BY**|Como passado.  Se **m\_strFilter** e `m_strSort` não estão vazias, adiciona as cláusulas de **WHERE** e\/ou de **ORDER BY** .|  
|4 \*|Uma instrução completa de **SELECIONAR** com uma cláusula de **WHERE** e\/ou de **ORDER BY**|Como passado.  **m\_strFilter** e\/ou `m_strSort` devem permanecer em branco, ou dois filtragem e\/ou as instruções do tipo são geradas.|  
|5 \*|Uma chamada para um procedimento armazenado|Como passado.|  
  
 \* `m_nFields` deve ser menor ou igual ao número de colunas especificadas na instrução de **SELECIONAR** .  O tipo de dados de cada coluna especificada na instrução de **SELECIONAR** deve ser o mesmo que o tipo de dados da coluna de saída correspondente de RFX.  
  
### LpszSQL \= NULL dos casos 1  
 A seleção do conjunto de registros depende da `GetDefaultSQL` retorna quando `CRecordset::Open` o chama.  Os casos 2 a 5 descrevem as cadeias de caracteres possíveis.  
  
### LpszSQL dos casos 2 \= um nome de tabela  
 A troca de campo do registro do conjunto de registros \(RFX\) para criar a lista de colunas dos nomes das colunas fornecidas em chamadas de função de RFX na classe do conjunto de registros de `DoFieldExchange`.  Se você usar um assistente para declarar a sua classe do conjunto de registros, esses casos tenham o mesmo resultado que o caso 1 \(desde que você passa o mesmo nome da tabela especificado no assistente\).  Se você não usar um assistente para gravar sua classe, os casos 2 é a maneira mais simples de construir a instrução SQL.  
  
 O exemplo a seguir constrói uma instrução SQL que seleciona registros de um aplicativo de base de dados de MFC.  Quando a estrutura chama a função de membro de `GetDefaultSQL` , a função retorna o nome da tabela, `SECTION`.  
  
```  
CString CEnrollSet::GetDefaultSQL()  
{  
    return "SECTION";  
}  
```  
  
 Para obter os nomes de colunas para a instrução SQL **SELECIONAR** , a estrutura chama a função de membro de `DoFieldExchange` .  
  
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
  
 Quando terminar, a instrução SQL é semelhante a esta:  
  
```  
SELECT CourseID, InstructorID, RoomNo, Schedule, SectionNo   
    FROM SECTION  
```  
  
### LpszSQL dos casos 3 \= uma instrução de SELECT\/FROM  
 Você especifica a lista de colunas à mão em vez de confiar em RFX para construir\-lo automaticamente.  Talvez você queira fazer isso quando:  
  
-   Você deseja especificar a palavra\-chave de **DISTINCT** depois de **SELECIONAR**.  
  
     A lista de colunas devem corresponder aos nomes de coluna e o tipo na mesma ordem que são listados em `DoFieldExchange`.  
  
-   Você tem a razão manualmente recuperar valores de coluna usando a função **::SQLGetData** ODBC em vez de confiar em RFX para associar e recuperar colunas.  
  
     Você pode, por exemplo, você queira acomodar novas colunas um cliente de seu aplicativo adicionado a tabelas base de dados depois que o aplicativo foi distribuída.  Você precisa adicionar esses membros de dados adicionais do campo, que não foram conhecidos que o momento em que você declarou a classe com um assistente.  
  
     A lista de colunas devem corresponder aos nomes de coluna e o tipo na mesma ordem que são listados em `DoFieldExchange`, seguidos pelos nomes manualmente colunas associadas.  Para obter mais informações, consulte [Conjunto de registros: associando dinamicamente colunas de dados \(ODBC\)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).  
  
-   Você deseja adicionar tabelas especificando várias tabelas na cláusula de **FROM** .  
  
     Para obter informações e um exemplo, consulte [Conjunto de registros: realizando uma junção \(ODBC\)](../Topic/Recordset:%20Performing%20a%20Join%20\(ODBC\).md).  
  
### Caso o lpszSQL 4 \= o SELECT\/FROM mais WHERE e\/ou ORDER BY  
 Você especifica tudo: a lista de colunas \(com base em chamadas de RFX em `DoFieldExchange`\), a lista de tabelas, e o conteúdo de **WHERE** e\/ou de uma cláusula ORDER BY.  Se você especificar suas cláusulas de **WHERE** e\/ou de **ORDER BY** essa forma, não use **m\_strFilter** e\/ou `m_strSort`.  
  
### LpszSQL dos casos 5 \= uma chamada de procedimento armazenado  
 Se você precisar chamar uma consulta predefinido \(como um procedimento armazenado em uma base de dados do Microsoft SQL Server\), você deve escrever uma instrução de **CALL** na cadeia de caracteres que você passa a `lpszSQL`.  Os assistentes não oferecem suporte à declaração de uma classe do conjunto de registros para chamar uma consulta predefinida.  Nem todos os registros predefinidos de consultas retornam.  
  
 Se uma consulta predefinida não retorna registros, você pode usar a função de membro `ExecuteSQL` de `CDatabase` diretamente.  Para uma consulta predefinida que retorna registros, você também deve escrever manualmente às chamadas de RFX em `DoFieldExchange` para todas as colunas o procedimento retornará.  As chamadas de RFX devem estar na mesma ordem e retornar os mesmos tipos, como a consulta predefinida.  Para obter mais informações, consulte [Conjunto de registros: declarando uma classe para uma consulta predefinida \(ODBC\)](../../data/odbc/recordset-declaring-a-class-for-a-predefined-query-odbc.md).  
  
## Consulte também  
 [SQL: tipos de dados SQL e C\+\+ \(ODBC\)](../../data/odbc/sql-sql-and-cpp-data-types-odbc.md)   
 [SQL: fazendo chamadas SQL diretas \(ODBC\)](../../data/odbc/sql-making-direct-sql-calls-odbc.md)