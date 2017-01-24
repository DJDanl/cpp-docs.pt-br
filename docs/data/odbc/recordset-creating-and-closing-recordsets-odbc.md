---
title: "Conjunto de registros: criando e fechando conjuntos de registros (ODBC) | Microsoft Docs"
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
  - "conjunto de registros ODBC, fechamento"
  - "conjunto de registros ODBC, criando"
  - "conjunto de registros ODBC, abertura"
  - "conjuntos de registros, fechamento"
  - "conjuntos de registros, criando"
  - "conjuntos de registros, abertura"
ms.assetid: 8d2aac23-4396-4ce2-8c60-5ecf1b360d3d
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conjunto de registros: criando e fechando conjuntos de registros (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico se aplica às classes ODBC do MFC.  
  
 Para usar um conjunto de registros, construir um objeto do conjunto de registros e chame a função de membro de **Abrir** para executar a consulta do conjunto de registros e para selecionar registros.  Quando você terminar com o conjunto de registros, feche e destruir o objeto.  
  
 Este tópico explica:  
  
-   [Quando e como criar um objeto do conjunto de registros](#_core_creating_recordsets_at_run_time).  
  
-   [Quando e como você pode qualificar o comportamento do conjunto de registros parametrizando, filtrando, para classificar, ou bloqueando o](#_core_setting_recordset_options).  
  
-   [Quando e como fechar um objeto do conjunto de registros](#_core_closing_a_recordset).  
  
##  <a name="_core_creating_recordsets_at_run_time"></a> Criando conjuntos de registros em tempo de execução  
 Antes que você possa criar objetos do conjunto de registros em seu programa, você escreve normalmente classes específicos do aplicativo do conjunto de registros.  Para obter mais informações sobre essa etapa preliminar, consulte [Adicionando um consumidor de MFC ODBC](../../mfc/reference/adding-an-mfc-odbc-consumer.md).  
  
 Abra um objeto de dynaset ou de instantâneo quando você precisa selecionar registros de uma fonte de dados.  O tipo de objeto a ser criado depende do que você precisa fazer com os dados em seu aplicativo e do driver ODBC oferece suporte.  Para obter mais informações, consulte [Dynaset](../../data/odbc/dynaset.md) e [Instantâneo](../Topic/Snapshot.md).  
  
#### Para abrir um conjunto de registros  
  
1.  Construir um objeto do `CRecordset`\- classe derivada.  
  
     Você pode construir o objeto no heap ou no quadro de pilhas de uma função.  
  
2.  Também é possível modificar o comportamento padrão do conjunto de registros.  Para as opções disponíveis, consulte [Opções do conjunto de registros de configuração](#_core_setting_recordset_options).  
  
3.  Chame a função de membro de [Abrir](../Topic/CRecordset::Open.md) do objeto.  
  
 No construtor, transmitir um ponteiro para um objeto de `CDatabase` ou passe **nulo** para usar um objeto de base de dados temporário que a estrutura cria e abre com base na cadeia de conexão retornada pela função de membro de [GetDefaultConnect](../Topic/CRecordset::GetDefaultConnect.md) .  O objeto de `CDatabase` já poderá ser conectado a uma fonte de dados.  
  
 A chamada para **Abrir** usa SQL para selecionar registros na fonte de dados.  O primeiro registro selecionado \(se houver\) é o registro atual.  Os valores de campos do registro são armazenados nos membros de dados do campo do objeto do conjunto de registros.  Se qualquer registro foi selecionado, `IsBOF` e o retorno 0 das funções de membro de `IsEOF` .  
  
 Em sua chamada de [Abrir](../Topic/CRecordset::Open.md) , você pode:  
  
-   Especifique se o conjunto de registros é um dynaset ou um instantâneo.  Os conjuntos de registros são abertos como instantâneos por padrão.  Ou, você pode especificar um conjunto de registros somente avanço, que permite apenas a rolagem para frente, um registro de cada vez.  
  
     Por padrão, um conjunto de registros usa o tipo padrão armazenado no membro de dados **m\_nDefaultType**de `CRecordset` .  Os assistentes escrevem o código para inicializar **m\_nDefaultType** ao tipo de conjunto de registros você escolhe no assistente.  Em vez de aceitando essa opção, você pode substituir outro tipo de conjunto de registros.  
  
-   Especificar uma cadeia de caracteres para substituir a instrução padrão do SQL **SELECIONAR** que o conjunto de registros constrói.  
  
-   Especifique se o conjunto de registros é somente leitura ou somente de acréscimo.  Os conjuntos de registros permitem a atualização por padrão, mas você pode limitar ao adicionar novos registros apenas ou você pode desabilitar todas as atualizações.  
  
 O exemplo a seguir mostra como abrir um objeto somente leitura do instantâneo da classe `CStudentSet`, uma classe específica do aplicativo:  
  
```  
// Construct the snapshot object  
CStudentSet rsStudent( NULL );  
// Set options if desired, then open the recordset  
if(!rsStudent.Open(CRecordset::snapshot, NULL, CRecordset::readOnly))  
    return FALSE;  
// Use the snapshot to operate on its records...  
```  
  
 Depois de chamar **Abrir**, use as funções de membro e os membros de dados do objeto para trabalhar com os registros.  Em alguns casos, talvez você deseje que você consulte novamente ou atualizar o conjunto de registros para incluir as alterações que ocorreram na fonte de dados.  Para obter mais informações, consulte [Conjunto de registros: Consultar um conjunto de registros \(ODBC\)](../../data/odbc/recordset-requerying-a-recordset-odbc.md).  
  
> [!TIP]
>  A cadeia de caracteres que se conectam você usa durante o desenvolvimento pode não ser a mesma se conecta a cadeia de caracteres que sua necessidade de usuários eventual.  Para ideias sobre a generalização do aplicativo neste aspecto, consulte [Fonte de dados: Gerenciando conexões \(ODBC\)](../../data/odbc/data-source-managing-connections-odbc.md).  
  
##  <a name="_core_setting_recordset_options"></a> Opções do conjunto de registros de configuração  
 Depois que você constrói o objeto do conjunto de registros mas antes de chamar **Abrir** para selecionar registros, você pode querer definir algumas opções para controlar o comportamento do conjunto de registros.  Para todos os conjuntos de registros, você pode:  
  
-   Especifique [filtro](../../data/odbc/recordset-filtering-records-odbc.md) para restringir a seleção do registro.  
  
-   Especificar uma ordem de [tipo](../../data/odbc/recordset-sorting-records-odbc.md) para os registros.  
  
-   Especifique [parâmetros](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md) para que você possa selecionar registros usando as informações obtidas calculada ou em tempo de execução.  
  
 Você também pode definir a seguinte opção se as condições forem direita:  
  
-   Se o conjunto de registros é atualizável e da suporte a opções de bloqueio, especifique o método de [bloqueio](../../data/odbc/recordset-locking-records-odbc.md) usado para atualizações.  
  
> [!NOTE]
>  Para afetar a seleção do registro, você deve definir essas opções antes de chamar a função de membro de **Abrir** .  
  
##  <a name="_core_closing_a_recordset"></a> Fechando um conjunto de registros  
 Quando você terminar com seu conjunto de registros, você deve descartar d e desalocar sua memória.  
  
#### Para fechar um conjunto de registros  
  
1.  Chame a função de membro de [Término](../Topic/CRecordset::Close.md) .  
  
2.  Destruir o objeto do conjunto de registros.  
  
     Se você o declarados no quadro de pilhas de uma função, o objeto será destruído automaticamente quando o objeto sai do escopo.  Se não, use o operador de **delete** .  
  
 **Fechar** libera o identificador de **HSTMT** conjunto de registros.  Não destrói o objeto C\+\+.  
  
## Consulte também  
 [Conjunto de registros \(ODBC\)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: rolando \(ODBC\)](../Topic/Recordset:%20Scrolling%20\(ODBC\).md)   
 [Conjunto de registros: adicionando, atualizando e excluindo registros \(ODBC\)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md)