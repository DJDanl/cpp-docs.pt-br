---
title: Criando um consumidor sem usar um assistente | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB consumers, creating
ms.assetid: e8241cfe-5faf-48f8-9de3-241203de020b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: c9f6bbc1ba45ec0b510dac015688fd29801c8449
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33097686"
---
# <a name="creating-a-consumer-without-using-a-wizard"></a>Criando um consumidor sem usar um assistente
O exemplo a seguir pressupõe que você está adicionando suporte de consumidor OLE DB a um projeto existente do ATL. Se você deseja adicionar suporte de consumidor OLE DB para um aplicativo MFC, você deve executar o Assistente de aplicativo MFC, que cria todo o suporte necessário e invoca as rotinas MFC necessárias para executar o aplicativo.  
  
 Para adicionar suporte de consumidor OLE DB sem usar o Assistente de ATL OLE DB consumidor:  
  
-   Em seu arquivo de Stdafx. h, acrescente o seguinte `#include` instruções:  
  
    ```  
    #include <atlbase.h>  
    #include <atldbcli.h>  
    #include <atldbsch.h> // if you are using schema templates  
    ```  
  
 Programaticamente, um consumidor normalmente executa a seguinte sequência de operações:  
  
-   Crie uma classe de registro de usuário que associa as colunas para variáveis locais. Neste exemplo, `CMyTableNameAccessor` é a classe de registro de usuário (consulte [registros de usuário](../../data/oledb/user-records.md)). Essa classe contém o mapa de coluna e o mapa de parâmetro. Declarar um membro de dados na classe de registro de usuário de cada campo que você especificar em seu mapa de coluna; para cada um desses membros de dados, também declare um membro de dados de status e um membro de dados de comprimento. Para obter mais informações, consulte [membros de dados de Status de campo em acessadores de Wizard-Generated](../../data/oledb/field-status-data-members-in-wizard-generated-accessors.md).  
  
    > [!NOTE]
    >  Se você escrever seu próprio cliente, as variáveis de dados devem vir antes das variáveis de status e comprimento.  
  
-   Criar uma instância de uma fonte de dados e uma sessão. Decidir o tipo de conjunto de linhas e o acessador de usar e, em seguida, criar um conjunto de linhas usando [CCommand](../../data/oledb/ccommand-class.md) ou [CTable](../../data/oledb/ctable-class.md):  
  
    ```  
    CDataSource ds;  
    CSession ss;  
    class CMyTableName : public CCommand<CAccessor<CMyTableNameAccessor>>  
    ```  
  
-   Chamar **CoInitialize** ao inicializar COM. Isso geralmente é chamado no código principal. Por exemplo:  
  
    ```  
    HRESULT hr = CoInitialize(NULL);  
    ```  
  
-   Chamar [cdatasource:: Open](../../data/oledb/cdatasource-open.md) ou uma de suas variações.  
  
-   Abrir uma conexão à fonte de dados, abra a sessão e abrir e inicializar o conjunto de linhas (e se um comando, também executá-lo):  
  
    ```  
    hr = ds.Open();  
    hr = ss.Open(ds);  
    hr = rs.Open();            // (Open also executes the command)  
    ```  
  
-   Opcionalmente, o conjunto de linhas propriedades usando `CDBPropSet::AddProperty` e passá-los como um parâmetro para `rs.Open`. Para obter um exemplo de como fazer isso, consulte GetRowsetProperties na [Consumer Wizard-Generated métodos](../../data/oledb/consumer-wizard-generated-methods.md).  
  
-   Agora você pode usar o conjunto de linhas para recuperar/manipular os dados.  
  
-   Quando seu aplicativo é concluído, feche a conexão, a sessão e o conjunto de linhas:  
  
    ```  
    rs.Close();  
    ss.Close();  
    ds.Close();  
    ```  
  
     Se você estiver usando um comando, você talvez queira chamar `ReleaseCommand` depois **fechar**. O exemplo de código em [ccommand:: Close](../../data/oledb/ccommand-close.md) mostra como chamar **fechar** e `ReleaseCommand`.  
  
-   Chamar **CoUnInitialize** para cancelar COM. Isso geralmente é chamado no código principal.  
  
    ```  
    CoUninitialize();  
    ```  
  
## <a name="see-also"></a>Consulte também  
 [Criando um consumidor do OLE DB](../../data/oledb/creating-an-ole-db-consumer.md)