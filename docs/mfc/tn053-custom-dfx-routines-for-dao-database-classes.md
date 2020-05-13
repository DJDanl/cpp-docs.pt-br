---
title: 'TN053: rotinas DFX personalizadas para classes de banco de dados DAO'
ms.date: 09/17/2019
helpviewer_keywords:
- MFC, DAO and
- database classes [MFC], DAO
- DAO [MFC], MFC
- DFX (DAO record field exchange) [MFC], custom routines
- TN053
- DAO [MFC], classes
- DFX (DAO record field exchange) [MFC]
- custom DFX routines [MFC]
ms.assetid: fdcf3c51-4fa8-4517-9222-58aaa4f25cac
ms.openlocfilehash: f7ad854f4dbb4e90c09e886c69260e4e2eea3be2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365256"
---
# <a name="tn053-custom-dfx-routines-for-dao-database-classes"></a>TN053: rotinas DFX personalizadas para classes de banco de dados DAO

> [!NOTE]
> O DAO é usado com bancos de dados access e é suportado através do Office 2013. DAO 3.6 é a versão final, e é considerada obsoleta. O ambiente Visual C++ e os assistentes não suportam DAO (embora as classes DAO estejam incluídas e você ainda possa usá-las). A Microsoft recomenda que você use [Modelos OLE DB](../data/oledb/ole-db-templates.md) ou [ODBC e MFC](../data/odbc/odbc-and-mfc.md) para novos projetos. Você só deve usar DAO na manutenção de aplicativos existentes.

Esta nota técnica descreve o mecanismo De troca de campo de registro DAO (DFX). Para ajudar a entender o que está `DFX_Text` acontecendo nas rotinas do DFX, a função será explicada detalhadamente como um exemplo. Como uma fonte adicional de informação para esta nota técnica, você pode examinar o código para o outro as funções individuais do DFX. Você provavelmente não precisará de uma rotina de DFX personalizada tantas vezes quanto você pode precisar de uma rotina de RFX personalizada (usada com classes de banco de dados ODBC).

Esta nota técnica contém:

- Visão geral do DFX

- [Exemplos](#_mfcnotes_tn053_examples) usando dao record field exchange e vinculação dinâmica

- [Como funciona o DFX](#_mfcnotes_tn053_how_dfx_works)

- [O que sua rotina de DFX personalizada faz](#_mfcnotes_tn053_what_your_custom_dfx_routine_does)

- [Detalhes da DFX_Text](#_mfcnotes_tn053_details_of_dfx_text)

**Visão geral do DFX**

O mecanismo de troca de campo de registro DAO (DFX) é `CDaoRecordset` usado para simplificar o procedimento de recuperação e atualização de dados ao usar a classe. O processo é simplificado usando `CDaoRecordset` membros de dados da classe. Ao derivar `CDaoRecordset`de , você pode adicionar membros de dados à classe derivada representando cada campo em uma tabela ou consulta. Este mecanismo de "vinculação estática" é simples, mas pode não ser o método de coleta/atualização de dados de escolha para todos os aplicativos. O DFX recupera todos os campos vinculados cada vez que o registro atual é alterado. Se você estiver desenvolvendo um aplicativo sensível ao desempenho que não requer buscar todos `CDaoRecordset::GetFieldValue` `CDaoRecordset::SetFieldValue` os campos quando a moeda é alterada, a "vinculação dinâmica" via e pode ser o método de acesso aos dados de escolha.

> [!NOTE]
> DFX e ligação dinâmica não são mutuamente exclusivos, de modo que um uso híbrido de ligação estática e dinâmica pode ser usado.

## <a name="example-1--use-of-dao-record-field-exchange-only"></a><a name="_mfcnotes_tn053_examples"></a>Exemplo 1 — Uso apenas do DAO Record Field Exchange

(assume `CDaoRecordset` — classe `CMySet` derivada já aberta)

```
// Add a new record to the customers table
myset.AddNew();

myset.m_strCustID = _T("MSFT");

myset.m_strCustName = _T("Microsoft");

myset.Update();
```

**Exemplo 2 — Uso apenas de vinculação dinâmica**

(assume usar `CDaoRecordset` a `rs`classe, e já está aberta)

```
// Add a new record to the customers table
COleVariant  varFieldValue1 (_T("MSFT"),
    VT_BSTRT);

//Note: VT_BSTRT flags string type as ANSI,
    instead of UNICODE default
COleVariant  varFieldValue2  (_T("Microsoft"),
    VT_BSTRT);

rs.AddNew();

rs.SetFieldValue(_T("Customer_ID"),
    varFieldValue1);

rs.SetFieldValue(_T("Customer_Name"),
    varFieldValue2);

rs.Update();
```

**Exemplo 3 — Uso de troca de campo de registro dadao e vinculação dinâmica**

(assume a navegação `CDaoRecordset`de dados `emp`de funcionários com classe derivada )

```
// Get the employee's data so that it can be displayed
emp.MoveNext();

// If user wants to see employee's photograph,
// fetch it
COleVariant varPhoto;
if (bSeePicture)
    emp.GetFieldValue(_T("photo"),
    varPhoto);

// Display the data
PopUpEmployeeData(emp.m_strFirstName,
    emp.m_strLastName,
    varPhoto);
```

## <a name="how-dfx-works"></a><a name="_mfcnotes_tn053_how_dfx_works"></a>Como funciona o DFX

O mecanismo DFX funciona de forma semelhante ao mecanismo de troca de campo de registro (RFX) usado pelas classes MFC ODBC. Os princípios do DFX e do RFX são os mesmos, mas existem inúmeras diferenças internas. O design das funções DFX foi tal que praticamente todo o código é compartilhado pelas rotinas individuais do DFX. No mais alto nível, o DFX só faz algumas coisas.

- O DFX constrói a cláusula SQL **SELECT** e a cláusula SQL **PARAMETERS,** se necessário.

- O DFX constrói a estrutura de `GetRows` ligação usada pela função do DAO (mais sobre isso mais tarde).

- O DFX gerencia o buffer de dados usado para detectar campos sujos (se o buffer duplo estiver sendo usado)

- O DFX gerencia as matrizes de status **NULL** e **DIRTY** e define valores, se necessário, em atualizações.

No coração do mecanismo DFX `CDaoRecordset` está a `DoFieldExchange` função da classe derivada. Esta função despacha chamadas para as funções DFX individuais de um tipo de operação apropriado. Antes `DoFieldExchange` de chamar as funções internas do MFC, defina o tipo de operação. A lista a seguir mostra os vários tipos de operação e uma breve descrição.

|Operação|Descrição|
|---------------|-----------------|
|`AddToParameterList`|Cláusula de parâmetros de compilação|
|`AddToSelectList`|Constrói cláusula SELECT|
|`BindField`|Configura estrutura de ligação|
|`BindParam`|Define valores de parâmetros|
|`Fixup`|Define o status NULL|
|`AllocCache`|Aloca cache para verificação suja|
|`StoreField`|Salva o registro atual para cache|
|`LoadField`|Restaura cache para valores de membro|
|`FreeCache`|Frees cache|
|`SetFieldNull`|Define o valor de status & de campo para NULL|
|`MarkForAddNew`|Marcas campos sujos se não PSEUDO NULL|
|`MarkForEdit`|Marcas campos sujos se não corresponder cache|
|`SetDirtyField`|Define valores de campo marcados como sujos|

Na próxima seção, cada operação será explicada com mais detalhes para `DFX_Text`.

O recurso mais importante a entender sobre o processo de `GetRows` troca `CDaoRecordset` de campo de registro DAO é que ele usa a função do objeto. A função `GetRows` DAO pode funcionar de várias maneiras. Esta nota técnica descreverá apenas `GetRows` brevemente, pois está fora do escopo desta nota técnica.
Dao `GetRows` pode funcionar de várias maneiras.

- Ele pode buscar vários registros e vários campos de dados ao mesmo tempo. Isso permite um acesso mais rápido aos dados com a complicação de lidar com uma grande estrutura de dados e as compensações adequadas para cada campo e para cada registro de dados na estrutura. O MFC não se aproveita desse mecanismo de busca de múltiplos registros.

- Outra `GetRows` maneira de funcionar é permitir que os programadores especifiquem endereços vinculativos para os dados recuperados de cada campo para um registro de dados.

- O DAO também "chamará de volta" o chamador para colunas de comprimento variável, a fim de permitir que o chamador aloque a memória. Este segundo recurso tem o benefício de minimizar o número de cópias de dados, `CDaoRecordset` bem como permitir o armazenamento direto de dados em membros de uma classe (a classe derivada). Este segundo mecanismo é o método que o `CDaoRecordset` MFC usa para vincular-se aos membros de dados em classes derivadas.

## <a name="what-your-custom-dfx-routine-does"></a><a name="_mfcnotes_tn053_what_your_custom_dfx_routine_does"></a>O que sua rotina de DFX personalizada faz

É evidente a partir desta discussão que a operação mais importante implementada em qualquer função DFX deve ser a capacidade de configurar as estruturas de dados necessárias para chamar `GetRows`com sucesso . Há uma série de outras operações que uma função DFX deve suportar também, `GetRows` mas nenhuma tão importante ou complexa quanto se preparar corretamente para a chamada.

O uso do DFX é descrito na documentação on-line. Essencialmente, há dois requisitos. Em primeiro lugar, os `CDaoRecordset` membros devem ser adicionados à classe derivada para cada campo e parâmetro vinculado. Depois `CDaoRecordset::DoFieldExchange` disso deve ser substituído. Observe que o tipo de dados do membro é importante. Ele deve corresponder aos dados do campo no banco de dados ou pelo menos ser conversível para esse tipo. Por exemplo, um campo numérico no banco de dados, como um inteiro `CString` longo, sempre pode ser convertido em texto e vinculado a um membro, mas um campo de texto em um banco de dados pode não ser necessariamente convertido em uma representação numérica, como inteiro longo e vinculado a um membro inteiro longo. O DAO e o mecanismo de banco de dados Microsoft Jet são responsáveis pela conversão (em vez de MFC).

## <a name="details-of-dfx_text"></a><a name="_mfcnotes_tn053_details_of_dfx_text"></a>Detalhes da DFX_Text

Como mencionado anteriormente, a melhor maneira de explicar como o DFX funciona é trabalhar através de um exemplo. Para isso, passar pelos `DFX_Text` internos deve funcionar muito bem para ajudar a fornecer pelo menos uma compreensão básica do DFX.

- `AddToParameterList`

   Esta operação constrói a cláusula SQL **PARAMETERS** ("`Parameters <param name>, <param type> ... ;`") exigida pela Jet. Cada parâmetro é nomeado e digitado (conforme especificado na chamada RFX). Consulte a `CDaoFieldExchange::AppendParamType` função para ver os nomes dos tipos individuais. No caso `DFX_Text`de , o tipo usado é **texto**.

- `AddToSelectList`

   Constrói a cláusula SQL **SELECT.** Isso é bastante direto, pois o nome da coluna especificado`SELECT <column name>, ...`pela chamada DFX é simplesmente anexado (" ").

- `BindField`

   O mais complexo das operações. Como mencionado anteriormente, é aqui que `GetRows` a estrutura de ligação DAO usada é configurada. Como você pode ver `DFX_Text` no código nos tipos de informações na estrutura incluem o tipo `DFX_Text`DAO usado (**DAO_CHAR** ou **DAO_WCHAR** no caso de ). Além disso, o tipo de ligação utilizada também é configurado. Em uma `GetRows` seção anterior foi descrito apenas brevemente, mas foi suficiente para explicar que o tipo de ligação usada pelo MFC é sempre a vinculação direta do endereço **(DAOBINDING_DIRECT).** Além da vinculação de chamada `DFX_Text`de comprimento variável (como ) é usada a vinculação de retorno de chamada para que o MFC possa controlar a alocação de memória e especificar um endereço do comprimento correto. O que isso significa é que o MFC pode sempre dizer ao DAO "onde" colocar os dados, permitindo assim vincular diretamente às variáveis membros. O resto da estrutura de vinculação é preenchido com coisas como o endereço da função de retorno de chamada de alocação de memória e o tipo de vinculação da coluna (vinculação por nome da coluna).

- `BindParam`

   Esta é uma operação `SetParamValue` simples que liga com o valor do parâmetro especificado no seu membro parâmetro.

- `Fixup`

   Preenche o status **NULL** para cada campo.

- `SetFieldNull`

   Esta operação marca apenas cada status de campo como **NULL** e define o valor da variável membro para **PSEUDO_NULL**.

- `SetDirtyField`

   Chamadas `SetFieldValue` para cada campo marcado sujo.

Todas as operações restantes lidam apenas com o uso do cache de dados. O cache de dados é um buffer extra dos dados no registro atual que é usado para tornar certas coisas mais simples. Por exemplo, campos "sujos" podem ser detectados automaticamente. Conforme descrito na documentação on-line, ele pode ser desligado completamente ou no nível de campo. A implementação do buffer utiliza um mapa. Este mapa é usado para corresponder cópias dinamicamente alocadas dos dados `CDaoRecordset` com o endereço do campo "bound" (ou membro de dados derivado).

- `AllocCache`

   Aloca dinamicamente o valor de campo armazenado em cache e adiciona-o ao mapa.

- `FreeCache`

   Exclui o valor de campo armazenado em cache e remove-o do mapa.

- `StoreField`

   Copia o valor de campo atual no cache de dados.

- `LoadField`

   Copia o valor armazenado em cache no membro de campo.

- `MarkForAddNew`

   Verifica se o valor atual do campo não é**NULA** e o marca sujo, se necessário.

- `MarkForEdit`

   Compara o valor de campo atual com o cache de dados e marcas sujas, se necessário.

> [!TIP]
> Modele suas rotinas de DFX personalizadas nas rotinas de DFX existentes para tipos de dados padrão.

## <a name="see-also"></a>Confira também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
