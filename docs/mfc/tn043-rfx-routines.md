---
title: 'TN043: Rotinas RFX | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- RFX
dev_langs:
- C++
helpviewer_keywords:
- RFX (record field exchange), architecture
- TN043
- RFX (record field exchange)
ms.assetid: f552d0c1-2c83-4389-b472-42c9940aa713
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 19bb44653c03505d954318a01a6e34c1a297dba7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tn043-rfx-routines"></a>TN043: rotinas RFX
> [!NOTE]
>  A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.  
  
 Esta anotação descreve a arquitetura do exchange (RFX) de campos de registro. Ele também descreve como escrever um **RFX_** procedimento.  
  
## <a name="overview-of-record-field-exchange"></a>Visão geral de troca de campos do registro  
 Todas as funções de campo do conjunto de registros são feitas com o código C++. Não existem recursos especiais ou magic macros. A essência do mecanismo é uma função virtual deve ser substituída em todas as classes derivadas de conjunto de registros. Ele sempre foi encontrado neste formulário:  
  
```  
void CMySet::DoFieldExchange(CFieldExchange* pFX)  
{ *//{{AFX_FIELD_MAP(CMySet)  
 <recordset exchange field type call>  
 <recordset exchange function call> *//}}AFX_FIELD_MAP  
}  
```  
  
 Os comentários do formato especial AFX permitem ClassWizard localizar e editar o código nessa função. Código que não é compatível com ClassWizard deve ser colocado fora os comentários de formato especial.  
  
 No exemplo acima, < recordset_exchange_field_type_call > está no formato:  
  
```  
pFX->SetFieldType(CFieldExchange::outputColumn);
```  
  
 e < recordset_exchange_function_call > está no formato:  
  
```  
RFX_Custom(pFX, "Col2",
    m_Col2);
```  
  
 A maioria dos **RFX_** funções têm três argumentos, como mostrado acima, mas alguns (por exemplo, `RFX_Text` e `RFX_Binary`) tem argumentos opcionais adicionais.  
  
 Mais de um **RFX_** podem ser incluídos em cada `DoDataExchange` função.  
  
 Consulte afxdb.h para obter uma lista de todos os as conjunto de registros campo exchange rotinas fornecido com MFC.  
  
 Chamadas de campo do conjunto de registros são uma maneira de registrar os locais de memória (geralmente membros de dados) para armazenar dados de campo para um **CMySet** classe.  
  
## <a name="notes"></a>Observações  
 Funções de campo do conjunto de registros são projetadas para funcionar apenas com o `CRecordset` classes. Eles não são geralmente usados por outras classes MFC.  
  
 Os valores iniciais de dados são definidos no construtor de C++ padrão, geralmente em um bloco com `//{{AFX_FIELD_INIT(CMylSet)` e `//}}AFX_FIELD_INIT` comentários.  
  
 Cada **RFX_** função deve oferecer suporte a várias operações, variando de retornar o status incorreto do campo para o campo na preparação para o campo de edição de arquivamento.  
  
 Cada função que chama `DoFieldExchange` (por exemplo `SetFieldNull`, `IsFieldDirty`), seu próprio inicialização em torno da chamada para `DoFieldExchange`.  
  
## <a name="how-does-it-work"></a>Como funciona  
 Você não precisa compreender o seguinte para usar a troca de campos de registro. No entanto, a compreensão de como isso funciona nos bastidores ajudará você a escrever seu próprio procedimento de exchange.  
  
 O `DoFieldExchange` função de membro é muito parecida com a `Serialize` função membro — é responsável por obter ou definir dados para/de um formulário externo (por este colunas de caso do resultado de uma consulta ODBC) de/para dados de membro na classe. O `pFX` parâmetro é o contexto para fazer a troca de dados e é semelhante de `CArchive` parâmetro `CObject::Serialize`. O `pFX` (uma `CFieldExchange` objeto) tem um indicador de operação, que é semelhante, mas uma generalização do `CArchive` sinalizador de direção. Uma função RFX pode ter que suportar as operações a seguir:  
  
- **BindParam** — indique onde ODBC deve recuperar dados de parâmetro  
  
- **BindFieldToColumn** — indique onde ODBC deve recuperar/depósito outputColumn dados  
  
- **Correção de** — defina **CString/CByteArray** comprimentos, definir status NULL bit  
  
- **MarkForAddNew** — marca sujas se o valor foi alterado desde que chamar AddNew  
  
- **MarkForUpdate** — marca sujas se o valor foi alterado desde que a chamada de edição  
  
- **Nome** — acrescentar os nomes de campo para campos marcados como sujos  
  
- **NameValue** — Append "\<nome da coluna > =" para os campos marcados como sujos  
  
- **Valor** — Append "" seguido pelo separador, como ',' ou ' '  
  
- `SetFieldDirty`— Defina o campo (ou seja, alterada) do status bit sujo  
  
- `SetFieldNull`– Configure os bits de status que indica o valor nulo para o campo  
  
- `IsFieldDirty`— Retornar o valor de bit sujo de status  
  
- `IsFieldNull`— Retornar o valor de bits de status nulo  
  
- `IsFieldNullable`— Retorna VERDADEIRO se o campo pode conter valores nulos  
  
- **StoreField** — arquivar o valor do campo  
  
- **LoadField** — recarregar arquivado o valor do campo  
  
- **GetFieldInfoValue** — retornar informações gerais sobre um campo  
  
- **GetFieldInfoOrdinal** — retornar informações gerais sobre um campo  
  
## <a name="user-extensions"></a>Extensões de usuário  
 Há várias maneiras de estender o mecanismo RFX padrão. É possível  
  
-   Adicione novos tipos de dados. Por exemplo:  
  
 ```  
    CBookmark 
 ```  
  
-   Adicione novos procedimentos do exchange (RFX_).  
  
 ```  
    void AFXAPI RFX_Bigint(CFieldExchange* pFX,
    const char *szName,  
    BIGINT& value);

 ```  
  
-   Ter o `DoFieldExchange` função membro condicionalmente incluem chamadas RFX adicionais ou qualquer outra instrução de C++ válida.  
  
 ```  
    while (posExtraFields != NULL)  
 {  
    RFX_Text(pFX,
    m_listName.GetNext(posExtraFields),   
    m_listValue.GetNext(posExtraValues));

 }  
 ```  
  
> [!NOTE]
>  Esse código não pode ser editado pelo ClassWizard e deve ser usado somente fora os comentários de formato especial.  
  
## <a name="writing-a-custom-rfx"></a>Escrevendo um RFX personalizado  
 Para escrever sua própria função RFX personalizado, é recomendável que você copie uma função RFX existente e modificá-lo para seus próprios fins. O direito RFX para copiar a seleção pode facilitar o trabalho. Algumas funções RFX tem algumas propriedades exclusivas que você deve levar em consideração ao decidir qual copiar.  
  
 **RFX_Long e RFX_Int**:  
 Essas são as funções RFX mais simples. O valor de dados não precisa de qualquer interpretação especial, e o tamanho dos dados é fixo.  
  
 **RFX_Single e RFX_Double**:  
 Como RFX_Long e RFX_Int acima, essas funções são simples e pode fazer usam amplamente da implementação do padrão. Eles são armazenados em dbflt.cpp em vez de dbrfx.cpp, no entanto, para habilitar o carregamento de tempo de execução flutuante biblioteca ponto somente quando eles forem explicitamente referência.  
  
 **RFX_Text e RFX_Binary**:  
 Essas duas funções alocar um buffer estático para armazenar informações de cadeia de caracteres/binário e devem registrar esses buffers com ODBC SQLBindCol em vez de registrar e valor. Por isso, essas duas funções com muitas código casos especiais.  
  
 `RFX_Date`:  
 ODBC retorna informações de data e hora em sua própria estrutura de dados TIMESTAMP_STRUCT. Essa função aloca dinamicamente uma TIMESTAMP_STRUCT como um "proxy" para enviar e receber dados de tempo de data. Várias operações devem transferir as informações de data e hora entre o C++ `CTime` objeto e o proxy TIMESTAMP_STRUCT. Isso complica consideravelmente a essa função, mas é um bom exemplo de como usar um proxy para transferência de dados.  
  
 `RFX_LongBinary`:  
 Esta é a biblioteca de classe única função RFX que não usa associação de coluna para receber e enviar dados. Essa função ignora a operação BindFieldToColumn em vez disso, durante a operação de correção, aloca armazenamento para manter os dados de entrada SQL_LONGVARCHAR ou SQL_LONGVARBINARY e executa uma chamada de SQLGetData para recuperar o valor para o armazenamento alocado. Ao se preparar para enviar valores de dados de volta para a fonte de dados (como operações NameValue e valor), essa função usa a funcionalidade DATA_AT_EXEC do ODBC. Consulte [45 de observação técnica](../mfc/tn045-mfc-database-support-for-long-varchar-varbinary.md) para obter mais informações sobre como trabalhar com SQL_LONGVARBINARY e SQL_LONGVARCHARs.  
  
 Ao escrever sua própria **RFX_** função, você geralmente será capaz de usar **CFieldExchange::Default** para implementar uma determinada operação. Examine a implementação do padrão para a operação em questão. Se ele realiza a operação seria gravar seu **RFX_** função você pode delegar para o **CFieldExchange::Default.** Você pode ver exemplos de chamada **CFieldExchange::Default** em dbrfx.cpp  
  
 É importante chamar `IsFieldType` no início de sua função RFX e retornar imediatamente se ela retorna FALSE. Esse mecanismo mantém sendo executadas em operações de parâmetro **outputColumns**e vice-versa (como chamar **BindParam** em uma **outputColumn**). Além disso, `IsFieldType` automaticamente mantém o controle de contagem de **outputColumns** (`m_nFields`) e parâmetros (`m_nParams`).  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

