---
title: 'TN053: Rotinas de DFX personalizadas para classes de banco de dados DAO'
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
ms.openlocfilehash: 949e1a07b2b45b01b08efb368046e0c65b1264e1
ms.sourcegitcommit: 2f96e2fda591d7b1b28842b2ea24e6297bcc3622
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2019
ms.locfileid: "71095981"
---
# <a name="tn053-custom-dfx-routines-for-dao-database-classes"></a>TN053: Rotinas de DFX personalizadas para classes de banco de dados DAO

> [!NOTE]
>  O DAO é usado com bancos de dados do Access e tem suporte por meio do Office 2013. 3,6 é a versão final e é considerada obsoleta. O ambiente C++ visual e os assistentes não dão suporte a DAO (embora as classes DAO estejam incluídas e você ainda possa usá-las). A Microsoft recomenda que você use [modelos de OLE DB](../data/oledb/ole-db-templates.md) ou [ODBC e MFC](../data/odbc/odbc-and-mfc.md) para novos projetos. Você só deve usar o DAO na manutenção de aplicativos existentes.

Esta nota técnica descreve o mecanismo de troca de campo de registro (DFX) do DAO. Para ajudar a entender o que está acontecendo nas rotinas DFX `DFX_Text` , a função será explicada em detalhes como um exemplo. Como uma fonte adicional de informações para essa nota técnica, você pode examinar o código para as outras funções DFX individuais. Provavelmente, você não precisará de uma rotina DFX personalizada sempre que precisar de uma rotina suporte RFX personalizada (usada com classes de banco de dados ODBC).

Esta nota técnica contém:

- Visão geral do DFX

- [Exemplos](#_mfcnotes_tn053_examples) usando a troca de campo de registro do DAO e a ligação dinâmica

- [Como o DFX funciona](#_mfcnotes_tn053_how_dfx_works)

- [O que sua rotina de DFX personalizada faz](#_mfcnotes_tn053_what_your_custom_dfx_routine_does)

- [Detalhes de DFX_Text](#_mfcnotes_tn053_details_of_dfx_text)

**Visão geral do DFX**

O mecanismo de troca do campo de registro do DAO (DFX) é usado para simplificar o procedimento de recuperação e atualização `CDaoRecordset` de dados ao usar a classe. O processo é simplificado usando membros de dados `CDaoRecordset` da classe. Derivando de `CDaoRecordset`, você pode adicionar membros de dados à classe derivada que representa cada campo em uma tabela ou consulta. Esse mecanismo de "associação estática" é simples, mas pode não ser o método de busca/atualização de dados de sua escolha para todos os aplicativos. DFX recupera cada campo associado a cada vez que o registro atual é alterado. Se você estiver desenvolvendo um aplicativo sensível ao desempenho que não exige a busca de todos os campos quando a moeda for alterada, a "Associação `CDaoRecordset::GetFieldValue` dinâmica `CDaoRecordset::SetFieldValue` " via e poderá ser o método de acesso a dados de sua preferência.

> [!NOTE]
>  DFX e a associação dinâmica não são mutuamente exclusivas, portanto, um uso híbrido de associação estática e dinâmica pode ser usado.

## <a name="_mfcnotes_tn053_examples"></a>Exemplo 1 – uso do campo de registro DAO somente Exchange

(pressupõe `CDaoRecordset` — classe `CMySet` derivada já aberta)

```
// Add a new record to the customers table
myset.AddNew();

myset.m_strCustID = _T("MSFT");

myset.m_strCustName = _T("Microsoft");

myset.Update();
```

**Exemplo 2 — uso somente de associação dinâmica**

(assume o `CDaoRecordset` uso de `rs`Class, e já está aberto)

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

**Exemplo 3 — uso de intercâmbio de campo de registro DAO e ligação dinâmica**

(pressupõe a procura de dados `CDaoRecordset`de funcionários com `emp`a classe derivada)

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

## <a name="_mfcnotes_tn053_how_dfx_works"></a>Como o DFX funciona

O mecanismo de DFX funciona de maneira semelhante ao mecanismo de troca de campo de registro (suporte RFX) usado pelas classes ODBC do MFC. Os princípios de DFX e suporte RFX são os mesmos, mas há inúmeras diferenças internas. O design das funções DFX era, de modo que praticamente todo o código é compartilhado pelas rotinas individuais do DFX. No nível mais alto, DFX faz apenas algumas coisas.

- DFX constrói a cláusula SQL **Select** e a cláusula de **parâmetros** SQL, se necessário.

- DFX constrói a estrutura de associação usada pela função do `GetRows` DAO (mais informações sobre isso posteriormente).

- DFX gerencia o buffer de dados usado para detectar campos sujos (se o buffer duplo estiver sendo usado)

- O DFX gerencia as matrizes de status **NULL** e **Dirty** e define valores, se necessário, em atualizações.

No coração do mecanismo DFX está a `CDaoRecordset` função da `DoFieldExchange` classe derivada. Essa função distribui chamadas para as funções DFX individuais de um tipo de operação apropriado. Antes de `DoFieldExchange` chamar as funções do MFC interno, defina o tipo de operação. A lista a seguir mostra os vários tipos de operação e uma breve descrição.

|Operação|Descrição|
|---------------|-----------------|
|`AddToParameterList`|Cláusula de parâmetros de builds|
|`AddToSelectList`|Compila a cláusula SELECT|
|`BindField`|Define a estrutura de associação|
|`BindParam`|Define valores de parâmetro|
|`Fixup`|Define o status nulo|
|`AllocCache`|Aloca o cache para verificação suja|
|`StoreField`|Salva o registro atual no cache|
|`LoadField`|Restaura o cache para valores de membro|
|`FreeCache`|Libera cache|
|`SetFieldNull`|Define o status do campo & valor como nulo|
|`MarkForAddNew`|Marca os campos com problemas se não for um PSEUDO nulo|
|`MarkForEdit`|Marca os campos com problemas se não corresponder ao cache|
|`SetDirtyField`|Define valores de campo marcados como sujos|

Na próxima seção, cada operação será explicada em mais detalhes para `DFX_Text`o.

O recurso mais importante a ser compreendido sobre o processo de troca de campo de registro DAO é `GetRows` que ele usa `CDaoRecordset` a função do objeto. A função `GetRows` DAO pode funcionar de várias maneiras. Esta nota técnica só descreverá `GetRows` brevemente como está fora do escopo desta nota técnica.
O DAO 3,6 é a versão final e é considerado obsoleto. `GetRows`pode trabalhar de várias maneiras.

- Ele pode buscar vários registros e vários campos de dados ao mesmo tempo. Isso permite acesso a dados mais rápido com a complicação de lidar com uma estrutura de dados grande e os deslocamentos apropriados para cada campo e para cada registro de dados na estrutura. O MFC não aproveita esse mecanismo de busca de vários registros.

- Outra maneira `GetRows` de funcionar é permitir que os programadores especifiquem endereços de associação para os dados recuperados de cada campo para um registro de dados.

- O DAO também fará "retorno de chamada" no chamador para colunas de comprimento variável para permitir que o chamador aloque memória. Esse segundo recurso tem o benefício de minimizar o número de cópias de dados, bem como permitir o armazenamento direto de dados em membros de uma classe (a `CDaoRecordset` classe derivada). Esse segundo mecanismo é o método que o MFC usa para associar membros de `CDaoRecordset` dados em classes derivadas.

##  <a name="_mfcnotes_tn053_what_your_custom_dfx_routine_does"></a>O que sua rotina de DFX personalizada faz

É aparente essa discussão que a operação mais importante implementada em qualquer função DFX deve ser a capacidade de configurar as estruturas de dados necessárias para chamar `GetRows`com êxito. Há uma série de outras operações que uma função DFX deve dar suporte também, mas nenhuma é tão importante ou complexa quanto a preparação correta para `GetRows` a chamada.

O uso de DFX é descrito na documentação online. Essencialmente, há dois requisitos. Primeiro, os membros devem ser adicionados à `CDaoRecordset` classe derivada para cada campo associado e parâmetro. Depois disso `CDaoRecordset::DoFieldExchange` , deve ser substituído. Observe que o tipo de dados do membro é importante. Ele deve corresponder aos dados do campo no banco de dados ou, pelo menos, ser conversíveis para esse tipo. Por exemplo, um campo numérico no banco de dados, como um inteiro longo, sempre pode ser convertido em texto e associado `CString` a um membro, mas um campo de texto em um banco de dados pode não ser necessariamente convertido em uma representação numérica, como um inteiro longo e associado a um integ longo membro er. O DAO e o mecanismo de banco de dados do Microsoft Jet são responsáveis pela conversão (em vez de MFC).

##  <a name="_mfcnotes_tn053_details_of_dfx_text"></a>Detalhes de DFX_Text

Como mencionado anteriormente, a melhor maneira de explicar como o DFX funciona é trabalhar com um exemplo. Para essa finalidade, percorrer os internos do `DFX_Text` deve funcionar bem para ajudar a fornecer pelo menos um entendimento básico do DFX.

- `AddToParameterList`

   Esta operação cria a cláusula de **parâmetros** SQL (`Parameters <param name>, <param type> ... ;`"") exigida pelo Jet. Cada parâmetro é nomeado e digitado (conforme especificado na chamada suporte RFX). Consulte a `CDaoFieldExchange::AppendParamType` função function para ver os nomes dos tipos individuais. No caso do `DFX_Text`, o tipo usado é **Text**.

- `AddToSelectList`

   Cria a cláusula SQL **Select** . Isso é muito simples, pois o nome da coluna especificado pela chamada DFX é simplesmente acrescentado ("`SELECT <column name>, ...`").

- `BindField`

   A mais complexa das operações. Como mencionado anteriormente, é aqui que a estrutura de vinculação do `GetRows` DAO usada pelo está configurada. Como você pode `DFX_Text` ver no código, os tipos de informações na estrutura incluem o tipo DAO usado (**DAO_CHAR** ou **DAO_WCHAR** no caso de `DFX_Text`). Além disso, o tipo de associação usado também é configurado. Em uma seção `GetRows` anterior, foi descrita apenas resumidamente, mas era suficiente explicar que o tipo de associação usado pelo MFC é sempre**DAOBINDING_DIRECT**(associação direta de endereço). Além disso, a associação de retorno de chamada de `DFX_Text`coluna de comprimento variável (como) é usada para que o MFC possa controlar a alocação de memória e especificar um endereço com o comprimento correto. Isso significa que o MFC sempre pode informar ao DAO "Where" para colocar os dados, permitindo, portanto, a associação diretamente às variáveis de membro. O restante da estrutura de associação é preenchido com coisas como o endereço da função de retorno de chamada de alocação de memória e o tipo de associação de coluna (Associação por nome de coluna).

- `BindParam`

   Essa é uma operação simples que chama `SetParamValue` com o valor de parâmetro especificado no seu membro de parâmetro.

- `Fixup`

   Preenche o status **nulo** de cada campo.

- `SetFieldNull`

   Essa operação marca apenas o status de cada campo como **nulo** e define o valor da variável de membro como **PSEUDO_NULL**.

- `SetDirtyField`

   Chamadas `SetFieldValue` para cada campo marcado como sujo.

Todas as operações restantes lidam apenas com o uso do cache de dados. O cache de dados é um buffer extra dos dados no registro atual que é usado para tornar determinadas coisas mais simples. Por exemplo, os campos "sujos" podem ser detectados automaticamente. Conforme descrito na documentação online, ele pode ser desativado completamente ou no nível do campo. A implementação do buffer utiliza um mapa. Esse mapa é usado para corresponder cópias de dados alocadas dinamicamente com o endereço do campo "associado" (ou `CDaoRecordset` membro de dados derivado).

- `AllocCache`

   Aloca dinamicamente o valor do campo em cache e o adiciona ao mapa.

- `FreeCache`

   Exclui o valor do campo armazenado em cache e o Remove do mapa.

- `StoreField`

   Copia o valor do campo atual no cache de dados.

- `LoadField`

   Copia o valor armazenado em cache no membro do campo.

- `MarkForAddNew`

   Verifica se o valor do campo atual é não**nulo** e marca-o como sujo, se necessário.

- `MarkForEdit`

   Compara o valor do campo atual com o cache de dados e marca o problema, se necessário.

> [!TIP]
> Modele suas rotinas de DFX personalizadas sobre as rotinas de DFX existentes para tipos de dados padrão.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
