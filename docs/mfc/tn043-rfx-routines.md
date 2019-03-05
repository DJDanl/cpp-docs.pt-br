---
title: 'TN043: Rotinas RFX'
ms.date: 06/28/2018
f1_keywords:
- RFX
helpviewer_keywords:
- RFX (record field exchange), architecture
- TN043
- RFX (record field exchange)
ms.assetid: f552d0c1-2c83-4389-b472-42c9940aa713
ms.openlocfilehash: 18820c7d17ddea355490ee32679d5d690ec3533e
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57294480"
---
# <a name="tn043-rfx-routines"></a>TN043: Rotinas RFX

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação online.

Essa observação descreve a arquitetura do exchange (RFX) de campos de registro. Ele também descreve como escrever um **RFX_** procedimento.

## <a name="overview-of-record-field-exchange"></a>Visão geral da troca de campos do registro

Todas as funções de campo de conjunto de registros são feitas com o código C++. Não há recursos especiais ou macros mágicas. O coração do mecanismo é uma função virtual que deve ser substituída em todas as classes derivadas do conjunto de registros. Ele sempre é encontrado neste formulário:

```cpp
void CMySet::DoFieldExchange(CFieldExchange* pFX)
{
    //{{AFX_FIELD_MAP(CMySet)
        <recordset exchange field type call>
        <recordset exchange function call>
    //}}AFX_FIELD_MAP
}
```

Os comentários do formato especial AFX permitem ClassWizard localizar e editar o código nessa função. Código que não é compatível com ClassWizard deve ser colocado fora os comentários de formato especial.

No exemplo acima, \<recordset_exchange_field_type_call > está no formato:

```cpp
pFX->SetFieldType(CFieldExchange::outputColumn);
```

e \<recordset_exchange_function_call > está no formato:

```cpp
RFX_Custom(pFX, "Col2", m_Col2);
```

A maioria dos **RFX_** funções têm três argumentos, conforme mostrado acima, mas algumas (por exemplo, `RFX_Text` e `RFX_Binary`) têm argumentos opcionais adicionais.

Mais de um **RFX_** podem ser incluídos em cada `DoDataExchange` função.

Consulte 'afxdb. h' para obter uma lista de todos os as conjunto de registros campo exchange rotinas fornecido com o MFC.

Chamadas de campo do conjunto de registros são uma maneira de registrar os locais de memória (geralmente, membros de dados) para armazenar dados de campo para um `CMySet` classe.

## <a name="notes"></a>Observações

Funções de campo do conjunto de registros são projetadas para funcionar apenas com o `CRecordset` classes. Eles não são amplamente utilizáveis por quaisquer outras classes do MFC.

Os valores iniciais de dados são definidos no construtor padrão do C++, geralmente em um bloco com `//{{AFX_FIELD_INIT(CMylSet)` e `//}}AFX_FIELD_INIT` comentários.

Cada **RFX_** função deve oferecer suporte a várias operações, variando de retornar o status de falta de limpeza do campo para o campo em preparação para editar o campo de arquivamento.

Cada função que chama `DoFieldExchange` (por exemplo `SetFieldNull`, `IsFieldDirty`), faz sua própria inicialização em torno da chamada para `DoFieldExchange`.

## <a name="how-does-it-work"></a>Como ele funciona

Você não precisa compreender o seguinte para usar a troca de campos de registro. No entanto, compreensão de como isso funciona em segundo plano ajudará você a escrever seu próprio procedimento do exchange.

O `DoFieldExchange` função de membro é muito parecido com o `Serialize` função de membro — ele é responsável por obter ou definir os dados para/de um formulário externo (nesse colunas de caso do resultado de uma consulta ODBC) de/para dados de membro na classe. O *pFX* parâmetro é o contexto para fazer a troca de dados e é semelhante ao *CArchive* parâmetro `CObject::Serialize`. O *pFX* (um `CFieldExchange` objeto) tem um indicador de operação, que é semelhante ao, mas uma generalização do *CArchive* sinalizador de direção. Uma função RFX pode ter que dar suporte as seguintes operações:

- `BindParam` — Indicar onde ODBC deve recuperar dados de parâmetro

- `BindFieldToColumn` — Indicar onde ODBC deve recuperar/depósito outputColumn dados

- `Fixup` — Defina `CString/CByteArray` comprimentos, definir status NULL de bits

- `MarkForAddNew` — Suja marcar se o valor foi alterado desde que chamar AddNew

- `MarkForUpdate` — Suja marcar se o valor foi alterado desde a chamada de edição

- `Name` – Nomes de campo para os campos marcados como sujos de acréscimo

- `NameValue` — Acrescentar "\<nome da coluna > =" para os campos marcados como sujos

- `Value` — Acrescentar "" seguido por um separador, como ',' ou ' '

- `SetFieldDirty` — Defina o campo (ou seja, alterados) de status bits sujos

- `SetFieldNull` — Defina indicando um valor nulo para o campo de bits de status

- `IsFieldDirty` — Retornar o valor do bit sujo do status

- `IsFieldNull` — Retornar o valor do bit de status nulo

- `IsFieldNullable` — Retorna VERDADEIRO se o campo pode conter valores nulos

- `StoreField` — Valor do campo arquivo morto

- `LoadField` — Recarregar o valor do campo arquivados

- `GetFieldInfoValue` — Retornam informações gerais sobre um campo

- `GetFieldInfoOrdinal` — Retornam informações gerais sobre um campo

## <a name="user-extensions"></a>Extensões do usuário

Há várias maneiras de estender o mecanismo RFX padrão. É possível

- Adicione novos tipos de dados. Por exemplo:

    ```cpp
    CBookmark
    ```

- Adicione novos procedimentos do exchange (RFX_).

    ```cpp
    void AFXAPI RFX_Bigint(CFieldExchange* pFX,
        const char *szName,
        BIGINT& value);
    ```

- Ter o `DoFieldExchange` função de membro condicionalmente incluem chamadas RFX adicionais ou quaisquer outras instruções C++ válidas.

    ```cpp
    while (posExtraFields != NULL)
    {
        RFX_Text(pFX,
        m_listName.GetNext(posExtraFields),
        m_listValue.GetNext(posExtraValues));
    }
    ```

> [!NOTE]
> Esse código não pode ser editado por ClassWizard e deve ser usado apenas para os comentários de formato especial.

## <a name="writing-a-custom-rfx"></a>Escrever um personalizado RFX

Para escrever sua própria função personalizada RFX, é recomendável que você copie uma função RFX existente e modificá-lo para suas próprias finalidades. Selecionar o RFX à direita para copiar pode tornar seu trabalho muito mais fácil. Algumas funções RFX tem algumas propriedades exclusivas que devem levar em consideração ao decidir qual copiar.

`RFX_Long` e `RFX_Int`: Essas são as funções RFX mais simples. O valor de dados não precisa de nenhuma interpretação especial, e o tamanho dos dados é fixo.

`RFX_Single` e `RFX_Double`: Assim como RFX_Long e RFX_Int acima, essas funções são simples e pode fazer usar muito da implementação padrão. Eles são armazenados em dbflt.cpp em vez de dbrfx.cpp, no entanto, para habilitar o carregamento flutuante biblioteca ponto somente quando eles forem explicitamente referência o tempo de execução.

`RFX_Text` e `RFX_Binary`: Essas duas funções pré-alocar um buffer estático para armazenar informações de cadeia de caracteres/binário e devem registrar esses buffers SQLBindCol ODBC em vez de & valor do registro. Por isso, essas duas funções têm vários códigos de casos especiais.

`RFX_Date`: ODBC retorna informações de data e hora em sua própria estrutura de dados TIMESTAMP_STRUCT. Essa função aloca dinamicamente uma TIMESTAMP_STRUCT como um "proxy" para enviar e receber dados de tempo de data. Várias operações devem transferir as informações de data e hora entre o C++ `CTime` objeto e o proxy TIMESTAMP_STRUCT. Isso complica a essa função consideravelmente, mas é um bom exemplo de como usar um proxy para transferência de dados.

`RFX_LongBinary`: Essa é a biblioteca de classe única função RFX que não usa associação de coluna para receber e enviar dados. Essa função ignorará a operação BindFieldToColumn e em vez disso, durante a operação de correção, aloca armazenamento para manter os dados de entrada SQL_LONGVARCHAR ou SQL_LONGVARBINARY, em seguida, executa uma chamada de SQLGetData para recuperar o valor para o armazenamento alocado. Ao se preparar para enviar valores de dados de volta para a fonte de dados (como operações NameValue e valor), essa função usa a funcionalidade DATA_AT_EXEC do ODBC. Ver [45 de observação técnica](../mfc/tn045-mfc-database-support-for-long-varchar-varbinary.md) para obter mais informações sobre como trabalhar com SQL_LONGVARBINARY e SQL_LONGVARCHARs.

Ao escrever seus próprios **RFX_** função, você geralmente será capaz de usar `CFieldExchange::Default` para implementar uma determinada operação. Examinar a implementação do padrão para a operação em questão. Se ele realiza a operação você teria de escrever seu **RFX_** função, você pode delegar para o `CFieldExchange::Default`. Você pode ver exemplos para chamar `CFieldExchange::Default` em dbrfx.cpp

É importante chamar `IsFieldType` no início de sua função RFX e retornar imediatamente se ela retorna FALSE. Esse mecanismo mantém as operações de parâmetro em que está sendo executada no *outputColumns*e vice-versa (como chamar `BindParam` em um *outputColumn*). Além disso, `IsFieldType` automaticamente mantém o controle de contagem de *outputColumns* (*m_nFields*) e params (*m_nParams*).

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
