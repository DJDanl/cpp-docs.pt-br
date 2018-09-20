---
title: 'TN053: Rotinas DFX personalizadas para DAO do banco de dados Classes | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.mfc.dfx
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 054ff12e47d2a6bd38d1a51a7745e5b3916c90dc
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46445107"
---
# <a name="tn053-custom-dfx-routines-for-dao-database-classes"></a>TN053: rotinas DFX personalizadas para classes de banco de dados DAO

> [!NOTE]
>  Os assistentes e o ambiente do Visual C++ não têm suporte DAO (embora as classes DAO estão incluídas e você ainda pode usá-los). A Microsoft recomenda que você use [modelos OLE DB](../data/oledb/ole-db-templates.md) ou [ODBC e MFC](../data/odbc/odbc-and-mfc.md) para novos projetos. Você só deve usar DAO em manutenção de aplicativos existentes.

Essa observação técnica descreve o mecanismo de troca (DFX) DAO campos de registro. Para ajudar a entender o que está acontecendo em rotinas DFX, o `DFX_Text` função será explicada em detalhes como um exemplo. Como uma fonte de informações para esta nota técnica adicional, você pode examinar o código para os outros as funções DFX individuais. Você provavelmente não será necessário uma rotina DFX personalizada sempre que você pode precisar de uma rotina RFX personalizada (usada com classes de banco de dados ODBC).

Essa observação técnica contém:

- Visão geral DFX

- [Exemplos](#_mfcnotes_tn053_examples) usando a troca de campos de registro DAO e a associação dinâmica

- [Como funciona o DFX](#_mfcnotes_tn053_how_dfx_works)

- [O que faz sua rotina DFX personalizadas](#_mfcnotes_tn053_what_your_custom_dfx_routine_does)

- [Detalhes de DFX_Text](#_mfcnotes_tn053_details_of_dfx_text)

**Visão geral DFX**

O mecanismo de troca de campos de registro (DFX) DAO é usado para simplificar o procedimento de recuperação e atualização de dados ao usar o `CDaoRecordset` classe. O processo é simplificado usando membros de dados a `CDaoRecordset` classe. Derivando de `CDaoRecordset`, você pode adicionar membros de dados para a classe derivada que representa cada campo em uma tabela ou consulta. Esse mecanismo de "vinculação estática" é simple, mas talvez não seja o método de busca/atualização de dados de preferência para todos os aplicativos. DFX recupera todos os campos associados a cada vez que o registro atual é alterado. Se você estiver desenvolvendo um aplicativo sensível ao desempenho que não exija buscar todos os campos quando moeda é alterada, "associação dinâmica" por meio `CDaoRecordset::GetFieldValue` e `CDaoRecordset::SetFieldValue` pode ser o método de acesso de dados de preferência.

> [!NOTE]
>  DFX e vinculação dinâmica não são mutuamente exclusivos, portanto, um uso de híbrido de associação estática e dinâmica pode ser usado.

## <a name="_mfcnotes_tn053_examples"></a> Exemplo 1 — De uso de troca de campos de registro DAO somente

(pressupõe `CDaoRecordset` — classe derivada `CMySet` estiver aberto)

```
// Add a new record to the customers table
myset.AddNew();

myset.m_strCustID = _T("MSFT");

myset.m_strCustName = _T("Microsoft");

myset.Update();
```

**Exemplo 2 — De uso de associação dinâmica**

(assume utilizando `CDaoRecordset` classe, `rs`, e ele ainda estiver aberto)

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

**Exemplo 3 — Uso de DAO registrar troca de campos e vinculação dinâmica**

(pressupõe que os dados de funcionário navegação com `CDaoRecordset`-classe derivada `emp`)

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

## <a name="_mfcnotes_tn053_how_dfx_works"></a> Como funciona o DFX

O mecanismo DFX funciona de maneira semelhante para o mecanismo do exchange (RFX) de campos de registro usada pelas classes do MFC ODBC. Os princípios de DFX e RFX são os mesmos, mas existem várias diferenças internas. O design das funções DFX era, de modo que praticamente todo o código é compartilhado por rotinas DFX individuais. No DFX mais alto nível só faz algumas coisas.

- DFX constrói o SQL **selecionar** SQL e cláusula **parâmetros** cláusula se necessário.

- DFX constrói a estrutura de associação usada do DAO `GetRows` função (mais sobre isso posteriormente).

- DFX gerencia o buffer de dados usado para detectar os campos de falta de limpeza (se o buffer duplo estiver sendo usado)

- DFX gerencia o **nulo** e **DIRTY** status matrizes e define valores se necessário, as atualizações.

No coração do DFX mecanismo é o `CDaoRecordset` derivado da classe `DoFieldExchange` função. Essa função expede chamadas para as funções DFX individuais de um tipo de operação apropriada. Antes de chamar `DoFieldExchange` das funções internas do MFC definem o tipo de operação. A lista a seguir mostra os vários tipos de operação e uma breve descrição.

|Operação|Descrição|
|---------------|-----------------|
|`AddToParameterList`|Cláusula de parâmetros de compilações|
|`AddToSelectList`|Cláusula SELECT de compilações|
|`BindField`|Define a estrutura de vinculação|
|`BindParam`|Define valores de parâmetro|
|`Fixup`|Define o status NULL|
|`AllocCache`|Aloca o cache para seleção suja|
|`StoreField`|Salva o registro atual em cache|
|`LoadField`|Restaurações de cache para valores de membro|
|`FreeCache`|Libera o cache|
|`SetFieldNull`|Conjuntos de campo de valor para NULL & status|
|`MarkForAddNew`|Campos de marcas sujo se não for nulo PSEUDO|
|`MarkForEdit`|Se sujo de campos de marcas não correspondem ao cache|
|`SetDirtyField`|Define os valores marcados como sujos de campo|

Na próxima seção, cada operação será explicada mais detalhadamente em `DFX_Text`.

O recurso mais importante para entender sobre o processo de troca de campos de registro DAO é que ele usa o `GetRows` função do `CDaoRecordset` objeto. O DAO `GetRows` função pode trabalhar de várias maneiras. Essa observação técnica descrevem resumidamente `GetRows` como ele está fora do escopo desta nota técnica.

DAO `GetRows` pode trabalhar de várias maneiras.

- Ele pode buscar vários campos de dados e de vários registros ao mesmo tempo. Assim, para acesso a dados mais rápido com a complicação de lidar com uma estrutura de dados grandes e os deslocamentos apropriados para cada campo em cada registro de dados na estrutura. MFC não se beneficia desse registro vários mecanismo de busca.

- Outra maneira de `GetRows` pode trabalho é permitir que os programadores a especificar endereços de associação para os dados recuperados de cada campo para um registro de dados.

- DAO será também "retornem" para o chamador para colunas de comprimento variável para permitir que o chamador alocar memória. Este segundo recurso tem a vantagem de minimizar o número de cópias de dados, bem como permitir que o armazenamento direto de dados em membros de uma classe (a `CDaoRecordset` classe derivada). Esse segundo mecanismo é o método MFC usa para associar a membros de dados em `CDaoRecordset` classes derivadas.

##  <a name="_mfcnotes_tn053_what_your_custom_dfx_routine_does"></a> O que faz sua rotina DFX personalizadas

É aparente depois dessa discussão que a operação mais importante, implementada em qualquer função DFX deve ser a capacidade de definir as estruturas de dados necessárias para chamar com êxito `GetRows`. Há uma série de outras operações que uma função DFX deve dar suporte, bem, mas nenhum como importantes ou complexos como preparar corretamente para o `GetRows` chamar.

O uso de DFX é descrito na documentação online. Basicamente, existem dois requisitos. Primeiro, os membros devem ser adicionados ao `CDaoRecordset` derivado da classe para cada campo associado e o parâmetro. Seguindo este `CDaoRecordset::DoFieldExchange` deve ser substituído. Observe que o tipo de dados do membro é importante. Ele deve corresponder aos dados do campo no banco de dados ou pelo menos ser conversível para esse tipo. Por exemplo, um campo numérico no banco de dados, como um inteiro longo, sempre pode ser convertido em texto e associado a um `CString` membro, mas um campo de texto em um banco de dados não necessariamente pode ser convertido em uma representação numérica, como inteiro longo e associado a um longo integ ER membro. DAO e o mecanismo de banco de dados Microsoft Jet são responsáveis por conversão (em vez de MFC).

##  <a name="_mfcnotes_tn053_details_of_dfx_text"></a> Detalhes de DFX_Text

Conforme mencionado anteriormente, a melhor maneira de explicar como funciona o DFX é trabalhar com um exemplo. Para essa finalidade percorrer as partes internas de `DFX_Text` deve funcionar muito bem para ajudar a fornecer pelo menos um entendimento básico de DFX.

- `AddToParameterList`

   Esta operação cria o SQL **parâmetros** cláusula ("`Parameters <param name>, <param type> ... ;`") exigido pelo Jet. Cada parâmetro é nomeado e digitado (conforme especificado na chamada RFX). Consulte a função `CDaoFieldExchange::AppendParamType` função para ver os nomes dos tipos individuais. No caso de `DFX_Text`, é o tipo usado **texto**.

- `AddToSelectList`

   Compilações de SQL **selecionar** cláusula. Isso é bastante simples e como o nome da coluna especificado pela chamada DFX é simplesmente acrescentado ("`SELECT <column name>, ...`").

- `BindField`

   O mais complexo das operações. Conforme mencionado anteriormente, isso é onde a estrutura de vinculação do DAO usado por `GetRows` está configurado. Como você pode ver no código `DFX_Text` os tipos de informações na estrutura incluem o tipo DAO usado (**DAO_CHAR** ou **DAO_WCHAR** no caso de `DFX_Text`). Além disso, o tipo de associação usada é também configurar. Em uma seção anterior `GetRows` foi descrito resumidamente, mas foi suficiente explicar que o tipo de associação usada pelo MFC sempre é associação direta de endereço (**DAOBINDING_DIRECT**). Além disso, para a associação de coluna de comprimento variável (como `DFX_Text`) vinculação do retorno de chamada é usada para que o MFC pode controlar a alocação de memória e especificar um endereço do tamanho correto. Isso significa que MFC sempre poderá indicar DAO "where" para colocar os dados, permitindo assim que a associação diretamente para as variáveis de membro. O restante da estrutura de vinculação é preenchido com coisas como o endereço da função de retorno de chamada de alocação de memória e o tipo de associação de coluna (associação de nome de coluna).

- `BindParam`

   Essa é uma operação simple que chama `SetParamValue` com o valor do parâmetro especificado no seu membro de parâmetro.

- `Fixup`

   Preenche o **nulo** status para cada campo.

- `SetFieldNull`

   Esta operação marca o status de cada campo como apenas **nulo** e define o membro de valor da variável como **PSEUDO_NULL**.

- `SetDirtyField`

   Chamadas `SetFieldValue` para cada campo marcado como sujo.

Todas as operações restantes lidam apenas com o uso de cache de dados. O cache de dados é um buffer adicional dos dados no registro atual que é usado para fazer certas coisas mais simples. Por exemplo, "sujos" campos podem ser detectados automaticamente. Conforme descrito na documentação online, que ele pode ter sido desligado completamente ou no nível do campo. A implementação do buffer utiliza um mapa. Esse mapa é utilizado para fazer sua correspondência alocadas dinamicamente cópias dos dados com o endereço do campo "ligado" (ou `CDaoRecordset` derivada do membro de dados).

- `AllocCache`

   Dinamicamente aloca o valor do campo em cache e o adiciona ao mapa.

- `FreeCache`

   Exclui o valor do campo em cache e a remove do mapa.

- `StoreField`

   Copia o valor do campo atual para o cache de dados.

- `LoadField`

   Copia o valor armazenado em cache para o membro de campo.

- `MarkForAddNew`

   Verifica se o valor do campo atual é não -**nulo** e marca sujo se necessário.

- `MarkForEdit`

   Compara o valor do campo atual com o cache de dados e marca sujo se necessário.

> [!TIP]
> Modelo suas rotinas DFX personalizadas nas rotinas DFX existentes para tipos de dados padrão.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

