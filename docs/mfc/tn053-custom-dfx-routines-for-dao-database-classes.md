---
title: 'TN053: Rotinas DFX personalizadas para DAO do banco de dados Classes | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c6935e4b3f2c8159677d1d322f6f875246160da2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tn053-custom-dfx-routines-for-dao-database-classes"></a>TN053: rotinas DFX personalizadas para classes de banco de dados DAO
> [!NOTE]
>  Os assistentes e o ambiente do Visual C++ não dão suporte DAO (embora as classes DAO estão incluídas e você ainda pode usá-los). A Microsoft recomenda que você use [modelos OLE DB](../data/oledb/ole-db-templates.md) ou [ODBC e MFC](../data/odbc/odbc-and-mfc.md) para novos projetos. Você só deve usar DAO na manutenção de aplicativos existentes.  
  
 Essa observação técnica descreve o mecanismo do DAO campos de registro (DFX) do exchange. Para ajudar a entender o que está acontecendo em rotinas DFX, o `DFX_Text` função será explicada em detalhes como um exemplo. Como uma fonte de informações para esta Observação técnica adicional, você pode examinar o código para os outros as funções DFX individuais. Você provavelmente não será necessário uma rotina DFX personalizada geralmente terá uma rotina RFX personalizada (usada com classes de banco de dados ODBC).  
  
 Esta nota técnica contém:  
  
-   Visão geral DFX  
  
- [Exemplos](#_mfcnotes_tn053_examples) usando a troca de campos de registro DAO e a associação dinâmica  
  
- [Como funciona o DFX](#_mfcnotes_tn053_how_dfx_works)  
  
- [O que faz a sua rotina DFX personalizadas](#_mfcnotes_tn053_what_your_custom_dfx_routine_does)  
  
- [Detalhes de DFX_Text](#_mfcnotes_tn053_details_of_dfx_text)  
  
 **Visão geral DFX**  
  
 O mecanismo de troca de campos de registro DAO (DFX) é usado para simplificar o procedimento de recuperação e atualização de dados ao usar o `CDaoRecordset` classe. O processo é simplificado usando membros de dados de `CDaoRecordset` classe. Derivando de `CDaoRecordset`, você pode adicionar membros de dados para a classe derivada que representa cada campo em uma tabela ou consulta. Esse mecanismo "vinculação estática" é simple, mas talvez não seja o método de busca/atualização de dados, de preferência para todos os aplicativos. DFX recupera cada campo associado a cada vez que o registro atual é alterado. Se você estiver desenvolvendo um aplicativo de desempenho confidenciais que não necessite de busca de cada campo quando moeda é alterada, "associação dinâmica" via `CDaoRecordset::GetFieldValue` e `CDaoRecordset::SetFieldValue` pode ser o método de acesso de dados de escolha.  
  
> [!NOTE]
>  DFX e associação dinâmica não são mutuamente exclusivos, para que um uso híbrida de associação estática e dinâmica pode ser usado.  
  
## <a name="_mfcnotes_tn053_examples"></a>Exemplo 1 — De uso de troca de campos de registro DAO somente  
  
 (supõe `CDaoRecordset` — classe derivada `CMySet` estiver aberto)  
  
```  
// Add a new record to the customers table  
myset.AddNew();

myset.m_strCustID = _T("MSFT");

myset.m_strCustName = _T("Microsoft");

myset.Update();
```  
  
 **Exemplo 2: Uso de associação dinâmica**  
  
 (assume usando `CDaoRecordset` classe, `rs`, e ainda estiver aberto)  
  
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
  
 **Exemplo 3: Uso de registro de troca de campos DAO e associação dinâmica**  
  
 (supõe procurar dados de funcionário com `CDaoRecordset`-classe derivada `emp`)  
  
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
  
## <a name="_mfcnotes_tn053_how_dfx_works"></a>Como funciona o DFX  
  
 O mecanismo DFX funciona de maneira semelhante para o mecanismo de troca (RFX) de campos de registro usado pelas classes MFC ODBC. Os princípios de DFX e RFX são os mesmos, mas existem várias diferenças internas. O design das funções DFX foi, de modo que, praticamente todo o código é compartilhado pelas rotinas DFX individuais. No apenas o DFX de nível mais alto faz algumas coisas.  
  
-   DFX constrói o SQL **selecione** cláusula e SQL **parâmetros** cláusula se necessário.  
  
-   DFX constrói a estrutura de associação usada do DAO `GetRows` função (mais adiante).  
  
-   DFX gerencia o buffer de dados usado para detectar problemas campos (se o buffer duplo está sendo usado)  
  
-   DFX gerencia o **nulo** e **DIRTY** status matrizes e define valores se necessário, as atualizações.  
  
 A essência do DFX mecanismo é o `CDaoRecordset` derivado da classe `DoFieldExchange` função. Essa função envia chamadas para as funções DFX individuais de um tipo de operação apropriada. Antes de chamar `DoFieldExchange` as funções internas do MFC definir o tipo de operação. A lista a seguir mostra os vários tipos de operação e uma breve descrição.  
  
|Operação|Descrição|  
|---------------|-----------------|  
|**AddToParameterList**|Cláusula de parâmetros de compilações|  
|**AddToSelectList**|Cláusula SELECT compilações|  
|**BindField**|Define a estrutura de vinculação|  
|**BindParam**|Define valores de parâmetro|  
|**Correção**|Define o status NULL|  
|**AllocCache**|Aloca o cache para seleção suja|  
|**StoreField**|Salva o registro atual em cache|  
|**LoadField**|Restaurações de cache para valores de membro|  
|**FreeCache**|Libera o cache|  
|`SetFieldNull`|Conjuntos de campo de status e o valor para NULL|  
|**MarkForAddNew**|Campos de marcas sujas se não PSEUDO nulo|  
|**MarkForEdit**|Se problemas de campos de marcas não correspondem ao cache|  
|**SetDirtyField**|Conjuntos de campo valores marcados como sujos|  
  
 Na próxima seção, cada operação será explicada mais detalhadamente em `DFX_Text`.  
  
 O recurso mais importante para entender sobre o processo de troca de campos de registro DAO é que ele usa o `GetRows` função do `CDaoRecordset` objeto. O DAO `GetRows` função pode trabalhar de várias maneiras. Essa observação técnica descrevem resumidamente `GetRows` porque ela está fora do escopo desta nota técnica.  
  
 DAO `GetRows` pode trabalhar de várias maneiras.  
  
-   Ele pode buscar vários registros e vários campos de dados ao mesmo tempo. Isso permite para acesso a dados mais rápido com o complicativo de lidar com uma estrutura de dados grandes e os deslocamentos apropriados para cada campo e para cada registro de dados na estrutura. MFC não tirar proveito desse registro vários busca de mecanismo.  
  
-   Outra maneira `GetRows` pode trabalho é permitir que os programadores que especificar endereços de associação para os dados recuperados de cada campo de um registro de dados.  
  
-   DAO será também "retorno de chamada" para o chamador para colunas de comprimento variável para permitir que o chamador alocar memória. Este segundo recurso tem a vantagem de minimizar o número de cópias de dados, bem como Permitir armazenamento direto de dados em membros de uma classe (o `CDaoRecordset` classe derivada). Esse mecanismo de segundo é o método MFC usa para associar a membros de dados em `CDaoRecordset` classes derivadas.  
  
##  <a name="_mfcnotes_tn053_what_your_custom_dfx_routine_does"></a>O que faz a sua rotina DFX personalizadas  
 É evidente a partir dessa discussão que a operação mais importante implementada em qualquer função DFX deve ser a capacidade de configurar as estruturas de dados necessária para chamar com êxito `GetRows`. Há um número de outras operações que uma função DFX deve oferecer suporte também, mas nenhum como importantes ou complexa como preparar corretamente para o `GetRows` chamar.  
  
 O uso de DFX é descrito na documentação online. Basicamente, há dois requisitos. Primeiro, os membros devem ser adicionados ao `CDaoRecordset` derivado da classe para cada campo associado e um parâmetro. Após isso `CDaoRecordset::DoFieldExchange` deve ser substituído. Observe que o tipo de dados do membro é importante. Ele deve corresponder aos dados do campo no banco de dados ou pelo menos ser conversível para esse tipo. Por exemplo, um campo numérico no banco de dados, como um inteiro longo, sempre pode ser convertido em texto e associado a um `CString` membro, mas um campo de texto em um banco de dados não necessariamente pode ser convertidos em uma representação numérica, como inteiros longos e associado a um integ longo ER membro. DAO e o mecanismo de banco de dados Microsoft Jet serão responsáveis pela conversão (em vez de MFC).  
  
##  <a name="_mfcnotes_tn053_details_of_dfx_text"></a>Detalhes de DFX_Text  
 Conforme mencionado anteriormente, a melhor maneira para explicar como funciona o DFX é trabalhar com um exemplo. Para essa finalidade for por meio dos recursos internos do `DFX_Text` devem funcionar muito bem para ajudar a fornecer pelo menos um entendimento básico de DFX.  
  
 **AddToParameterList**  
 Essa operação cria SQL **parâmetros** cláusula ("`Parameters <param name>, <param type> ... ;`") exigido pelo Jet. Cada parâmetro é chamado e digitado (conforme especificado na chamada RFX). Consulte a função **CDaoFieldExchange::AppendParamType** função para ver os nomes dos tipos individuais. No caso de `DFX_Text`, o tipo usado é `text`.  
  
 **AddToSelectList**  
 Compilações de SQL **selecione** cláusula. Isso é bastante direto como o nome de coluna especificado pela chamada DFX é simplesmente anexado ("`SELECT <column name>, ...`").  
  
 **BindField**  
 As mais complexas das operações. Conforme mencionado anteriormente, isso é onde a estrutura de vinculação DAO usado por `GetRows` é configurada. Como você pode ver no código `DFX_Text` os tipos de informações na estrutura de incluem o tipo DAO usado (**DAO_CHAR** ou **DAO_WCHAR** no caso de `DFX_Text`). Além disso, o tipo de associação usada é também configurado. Em uma seção anterior `GetRows` foi descrito resumidamente, mas é suficiente explicar que o tipo de associação usada pelo MFC é sempre ligação de endereço direto (**DAOBINDING_DIRECT**). Além disso, para a associação de coluna de comprimento variável (como `DFX_Text`) associação de retorno de chamada é usada para que MFC pode controlar a alocação de memória e especifique um endereço do tamanho correto. Isso significa que MFC sempre poderá indicar DAO "where" para colocar os dados, permitindo assim que a associação diretamente para variáveis de membro. O restante da estrutura de associação é preenchido com coisas como o endereço da função de retorno de chamada de alocação de memória e o tipo de associação de coluna (associação de nome de coluna).  
  
 **BindParam**  
 Essa é uma operação simple que chama `SetParamValue` com o valor do parâmetro especificado em seu membro de parâmetro.  
  
 **Correção**  
 Preenche o **nulo** status para cada campo.  
  
 `SetFieldNull`  
 Esta operação somente marca o status de cada campo como **nulo** e define o membro valor da variável como **PSEUDO_NULL**.  
  
 **SetDirtyField**  
 Chamadas `SetFieldValue` para cada campo marcado como sujo.  
  
 Todas as operações restantes somente lidam com o uso de cache de dados. O cache de dados é um buffer adicional dos dados no registro atual é usado para tornar certas coisas mais simples. Por exemplo, "sujos" campos podem ser detectados automaticamente. Conforme descrito na documentação online pode ter sido desligado completamente ou no nível de campo. A implementação do buffer utiliza um mapa. Este mapa é usado para corresponder alocada dinamicamente cópias dos dados com o endereço do campo "ligado" (ou `CDaoRecordset` derivada do membro de dados).  
  
 **AllocCache**  
 Dinamicamente aloca o valor do campo em cache e o adiciona ao mapa.  
  
 **FreeCache**  
 Exclui o valor do campo em cache e a remove do mapa.  
  
 **StoreField**  
 Copia o valor do campo atual no cache de dados.  
  
 **LoadField**  
 Copia o valor armazenado em cache para o membro do campo.  
  
 **MarkForAddNew**  
 Verifica se o valor do campo atual é não -**nulo** e marca sujas se necessário.  
  
 **MarkForEdit**  
 Compara o valor do campo atual com o cache de dados e marca sujo, se necessário.  
  
> [!TIP]
>  Modelo suas rotinas DFX personalizadas nas rotinas DFX existentes para tipos de dados padrão.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

