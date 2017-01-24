---
title: "TN053: rotinas DFX personalizadas para classes de banco de dados DAO | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.mfc.dfx"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "rotinas DFX personalizadas [C++]"
  - "DAO [C++], Classes "
  - "DAO [C++], MFC"
  - "classes de banco de dados [C++], DAO"
  - "DFX (troca de campos de registro DAO) [C++]"
  - "DFX (troca de campos de registro DAO) [C++], rotinas personalizadas"
  - "MFC [C++], DAO e"
  - "TN053"
ms.assetid: fdcf3c51-4fa8-4517-9222-58aaa4f25cac
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN053: rotinas DFX personalizadas para classes de banco de dados DAO
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  A partir do Visual C\+\+ .NET, o ambiente e os assistentes do Visual C\+\+ não dão suporte a DAO \(embora as classes de DAO são incluídas e você ainda pode usar o\).  A Microsoft recomenda que você use [Modelos OLE DB](../Topic/OLE%20DB%20Templates.md) ou [ODBC e MFC](../data/odbc/odbc-and-mfc.md) para novos projetos.  Você só deve usar DAO manter os aplicativos existentes.  
  
 Observe que essa técnica descreve o mecanismo de troca do campo de registro DAO \(DFX\).  Para ajudar a entender o que está ocorrendo nas rotinas de DFX, a função de `DFX_Text` será explicada em detalhes como um exemplo.  Como uma fonte de informações adicional a observação essa técnica, você pode examinar o código para outro as funções individuais DFX.  Você provavelmente não precisará de uma rotina personalizadas DFX frequência pode ser necessária uma rotina personalizadas RFX \(usada com base de dados de ODBC classificação\).  
  
 Observe que contém essa técnica:  
  
-   Visão geral de DFX  
  
-   [Exemplos](#_mfcnotes_tn053_examples) usando o campo de registro do Exchange DAO e a associação dinâmico  
  
-   [Como funciona DFX](#_mfcnotes_tn053_how_dfx_works)  
  
-   [O que sua rotina personalizadas DFX faz](#_mfcnotes_tn053_what_your_custom_dfx_routine_does)  
  
-   [Detalhes de DFX\_Text](#_mfcnotes_tn053_details_of_dfx_text)  
  
 **Visão geral de DFX**  
  
 O mecanismo de troca do campo de registro DAO \(DFX\) é usado para simplificar o procedimento de recuperar e atualizar dados ao usar a classe de `CDaoRecordset` .  O processo é simplificado usando membros de dados da classe de `CDaoRecordset` .  Derivando de `CDaoRecordset`, você pode adicionar membros de dados para a classe derivada que representa cada campo em uma tabela ou uma consulta.  Esse “mecanismo de associação estático” é simples, mas não pode ser o método de busca\/atualização de dados de opção para todos os aplicativos.  DFX recupera cada campo associado a cada vez que o registro atual é alterado.  Se você estiver desenvolvendo um aplicativo de caracteres que não requer a busca de cada campo quando a moeda é alterada, “a associação dinâmico” por meio de `CDaoRecordset::GetFieldValue` e `CDaoRecordset::SetFieldValue` podem ser o método de acesso a dados de sua escolha.  
  
> [!NOTE]
>  DFX e a associação dinâmico não são mutuamente exclusivos, assim que um híbrido uso de associação estático e dinâmico pode ser usado.  
  
 **Exemplo 1 \- uso do Exchange campo de registro de DAO apenas**  
  
 \(supõe que `CDaoRecordset` — classe derivada `CMySet` aberto\)  
  
```  
// Add a new record to the customers table  
myset.AddNew();  
myset.m_strCustID = _T("MSFT");  
myset.m_strCustName = _T("Microsoft");  
myset.Update();  
```  
  
 **Exemplo 2 \- uso de associação dinâmico somente**  
  
 \(supõe usando a classe de `CDaoRecordset` , `rs`, e já estiver aberta\)  
  
```  
// Add a new record to the customers table  
COleVariant  varFieldValue1 ( _T("MSFT"), VT_BSTRT );  
//Note: VT_BSTRT flags string type as ANSI, instead of UNICODE default  
COleVariant  varFieldValue2  (_T("Microsoft"), VT_BSTRT );  
rs.AddNew();  
rs.SetFieldValue(_T("Customer_ID"), varFieldValue1);  
rs.SetFieldValue(_T("Customer_Name"), varFieldValue2);  
rs.Update();  
```  
  
 **Exemplo 3 \- uso do Exchange campo de registro de DAO e associação dinâmico**  
  
 \(supõe procurar dados com `CDaoRecordset`\- classe derivada `emp`de funcionário\)  
  
```  
// Get the employee's data so that it can be displayed  
emp.MoveNext();  
  
// If user wants to see employee's photograph,  
// fetch it  
COleVariant varPhoto;  
if (bSeePicture)  
   emp.GetFieldValue(_T("photo"), varPhoto);  
  
// Display the data  
PopUpEmployeeData(emp.m_strFirstName,  
    emp.m_strLastName, varPhoto);  
```  
  
 **Como funciona DFX**  
  
 O trabalho do mecanismo de DFX de uma maneira semelhante ao mecanismo de troca do campo de registro \(RFX\) MFC usado por ODBC classe.  Os fundamentos de DFX e de RFX são iguais mas há várias diferenças internas.  O design das funções de DFX de modo que foi virtuais em qualquer código é compartilhado por rotinas individuais DFX.  No DFX o nível mais alto faz apenas algumas coisas.  
  
-   DFX a cláusula constrói do SQL **SELECIONAR** e a cláusula do SQL **PARÂMETROS** se necessário.  
  
-   DFX constrói a estrutura de associação usada pela função de `GetRows` de DAO \(mais neste posterior\).  
  
-   DFX gerencia o buffer de dados usado para detectar campos sujos \(se a proteção dois está sendo usada\)  
  
-   DFX gerencia as matrizes de **nulo** e do status de **DIRTY** e valores de conjuntos se necessário em atualizações.  
  
 No centro do mecanismo de DFX é a função de `DoFieldExchange` da classe derivada `CDaoRecordset` .  Essa função despacha chamadas de funções individuais DFX de um tipo apropriado da operação.  Antes de chamar `DoFieldExchange` as funções internas MFC definir o tipo da operação.  A lista a seguir mostra os vários tipos de operação e uma descrição curta.  
  
|Operação|Descrição|  
|--------------|---------------|  
|**AddToParameterList**|Cláusula PARAMETERS as compilações|  
|**AddToSelectList**|As construções a cláusula SELECT|  
|**BindField**|Configura a estrutura de associação|  
|**BindParam**|Define valores de parâmetro|  
|**Fixup**|Os conjuntos o status NULL|  
|**AllocCache**|Atribui o cache para a verificação suja|  
|**StoreField**|Salva o registro atual ao cache|  
|**LoadField**|As restaurações armazenam em cachê a valores de membros|  
|**FreeCache**|Libera o cache|  
|`SetFieldNull`|Valor de status do campo & de conjuntos PARA NULL|  
|**MarkForAddNew**|Marcas de NULL PSEUDO\- de campos não se sujo|  
|**MarkForEdit**|Marca os campos sujos se não corresponder ao cache|  
|**SetDirtyField**|Define os valores de campos marcados como sujos|  
  
 Na próxima seção, cada operação será explicada em mais detalhes para `DFX_Text`.  
  
 O recurso o mais importante para entender a seguir sobre o processo de troca do campo de registro DAO é que usa a função de `GetRows` do objeto de `CDaoRecordset` .  A função de `GetRows` DAO pode trabalhar em várias maneiras.  Observe que essa técnica somente descreverá brevemente `GetRows` como está fora do escopo dessa técnica. observação  
  
 DAO `GetRows` pode trabalhar em várias maneiras.  
  
-   Pode buscar vários registros e vários campos de dados ao mesmo tempo.  Isso permite um acesso a dados mais rápido com a complicação de tratar uma grande estrutura de dados e os deslocamentos apropriados para cada campo e cada registro dos dados na estrutura.  O MFC não se beneficia desse vários registro que busca o mecanismo.  
  
-   Outra maneira que `GetRows` pode trabalhar é permitir que os desenvolvedores especifiquem endereços de associação para os dados recuperados de cada campo para um registro dos dados.  
  
-   DAO “também chamará novamente” no chamador para colunas de comprimento variável para permitir que o chamador aloca memória.  Este segundo recurso tem o benefício de minimizar o número de cópias de dados bem como permitir o armazenamento direto de dados em membros de uma classe \(a classe derivada de `CDaoRecordset` \).  Este segundo mecanismo é o usa MFC do método associar a membros de dados em classes derivadas de `CDaoRecordset` .  
  
##  <a name="_mfcnotes_tn053_what_your_custom_dfx_routine_does"></a> O que sua rotina personalizadas DFX faz  
 É aparente desta discussão que a operação mais importante implementada em qualquer função de DFX deve ser a capacidade de configurar as estruturas de dados necessárias para chamar com êxito `GetRows`.  Existem várias outras operações de que uma função de DFX deve oferecer suporte além disso, mas nenhuma tão importante quanto corretamente ou complexas preparando\-se para a chamada de `GetRows` .  
  
 O uso de DFX é descrito na documentação online.  Essencialmente, há dois requisitos.  Primeiro, os membros devem ser adicionados à classe derivada de `CDaoRecordset` para cada campo associado e parâmetro.  Depois desse `CDaoRecordset::DoFieldExchange` deve ser substituído.  Observe que o tipo de dados de membro é importante.  Deve corresponder os dados do campo no base de dados ou pelo menos ser convertido no tipo.  Por exemplo um campo numérico no base de dados, como um inteiro longo, sempre pode ser convertido em texto e associado a um membro de `CString` , mas um campo de texto em um base de dados não necessariamente ser convertido em uma representação numérica, como o número inteiro e o limite longos a um membro inteiro longo.  DAO e o mecanismo de base de dados do Microsoft Jet são responsáveis pela conversão \(em vez do MFC\).  
  
##  <a name="_mfcnotes_tn053_details_of_dfx_text"></a> Detalhes de DFX\_Text  
 Conforme mencionado anteriormente, a melhor maneira de explicar como os trabalhos de DFX são trabalhar com um exemplo.  Essa finalidade desvie os internos de `DFX_Text` deve funcionar bem suficiente para ajudar a fornecer pelo menos uma compreensão básica de DFX.  
  
 **AddToParameterList**  
 Essa operação cria a cláusula do SQL **PARÂMETROS** \(“"\)`Parameters <param name>, <param type> ... ;`exigida pelo Jet.  Cada parâmetro é denominado e digitado \(conforme especificado na chamada de RFX\).  Consulte a função de **CDaoFieldExchange::AppendParamType** da função para ver os nomes dos tipos individuais.  No caso de `DFX_Text`, o tipo é usado `text`.  
  
 **AddToSelectList**  
 Compila a cláusula do SQL **SELECIONAR** .  Isso é consideravelmente simples porque o nome de coluna especificado pela chamada de DFX é anexado somente`SELECT <column name>, ...`\(“"\).  
  
 **BindField**  
 O mais complexo de operações.  Conforme mencionado anteriormente isso é onde a estrutura de associação de DAO usada por `GetRows` está configurada.  Como você pode ver o código em `DFX_Text` os tipos de informações na estrutura incluem o tipo de DAO \(usado**DAO\_CHAR** ou **DAO\_WCHAR** no caso de `DFX_Text`\).  Além disso, o tipo de associação usado também é configurado.  Em uma seção anterior `GetRows` foi descrito somente brevemente, mas não era suficiente explicar que o tipo de associação usado por MFC é sempre associação direta de endereço \(**DAOBINDING\_DIRECT**\).  Além da associação de comprimento variável de retorno de chamada de associação de coluna \(como `DFX_Text`\) é usado de forma que o MFC pode controlar a alocação de memória e especificar um endereço de tamanho correto.  O que isso significa que MFC sempre poderá indicar DAO “onde” colocar os dados, permitindo associar diretamente a variáveis de membro.  O restante da estrutura de associação é preenchido com coisas como o endereço da função de retorno de chamada de alocação de memória e do tipo de associação de coluna \(que o associa o nome de coluna\).  
  
 **BindParam**  
 Essa é uma operação simples que chama `SetParamValue` com o valor do parâmetro especificado em seu membro do parâmetro.  
  
 **Fixup**  
 Preenche o status de **nulo** para cada campo.  
  
 `SetFieldNull`  
 Essa operação marca somente status de cada campo como **nulo** e define o valor da variável de membro a **PSEUDO\_NULL**.  
  
 **SetDirtyField**  
 Chama `SetFieldValue` para cada campo marcado como sujo.  
  
 Todas as operações restantes controlam somente a utilização de cachê de dados.  O cachê de dados é um buffer adicional dos dados no registro atual usado para estabelecer algumas coisas mais simples.  Por exemplo, os campos “sujos” podem ser detectados.  Conforme descrito na documentação online pode ser desativado por meio do ou no nível do campo.  A implementação do buffer utiliza um mapa.  Esse mapa é usado para combinar as cópias atribuídas dinamicamente de dados com o endereço do campo de “limite” \(ou o membro de dados derivado de `CDaoRecordset` \).  
  
 **AllocCache**  
 Atribui dinamicamente o valor do campo armazenado em cachê e o adiciona ao mapa.  
  
 **FreeCache**  
 Exclui o valor do campo armazenado em cachê e remova\-o do mapa.  
  
 **StoreField**  
 Copia o valor do campo atual em cachê de dados.  
  
 **LoadField**  
 Copia o valor armazenado em cachê no membro do campo.  
  
 **MarkForAddNew**  
 Verifica se o valor do campo atual é**nulo** não e marcar\-l sujo se necessário.  
  
 **MarkForEdit**  
 Compara o valor do campo atual com o cachê de dados e sinalizador sujo se necessário.  
  
> [!TIP]
>  Modelagem suas rotinas personalizadas DFX existentes nas rotinas de DFX para tipos de dados padrão.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)