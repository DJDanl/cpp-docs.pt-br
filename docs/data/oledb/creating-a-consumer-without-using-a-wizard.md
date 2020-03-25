---
title: Criando um consumidor sem usar um assistente
ms.date: 05/09/2019
helpviewer_keywords:
- OLE DB consumers, creating
ms.assetid: e8241cfe-5faf-48f8-9de3-241203de020b
ms.openlocfilehash: fff4146681e31f0f1fea9fbaa559de7c722740d2
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80211452"
---
# <a name="creating-a-consumer-without-using-a-wizard"></a>Criando um consumidor sem usar um assistente

O exemplo a seguir pressupõe que você está adicionando suporte do consumidor de OLE DB a um projeto existente da ATL. Se desejar adicionar o suporte do consumidor do OLE DB a um aplicativo do MFC, execute o **Assistente para Aplicativo do MFC**, que cria todo o suporte necessário e chama as rotinas necessárias do MFC para executar o aplicativo.

Adição de suporte do consumidor de OLE DB sem usar o **Assistente de Consumidor OLE DB do ATL**:

- No arquivo *PCH. h* , acrescente as seguintes instruções de `#include`:

    ```cpp
    #include <atlbase.h>
    #include <atldbcli.h>
    #include <atldbsch.h> // if you are using schema templates
    ```

Via programação, um consumidor normalmente executa a seguinte sequência de operações:

1. Criar uma classe de registro de usuário que associa colunas a variáveis locais. Neste exemplo, `CMyTableNameAccessor` é a classe de registro de usuário (confira [Registros de usuário](../../data/oledb/user-records.md)). Essa classe contém o mapa de coluna e o mapa de parâmetro. Declarar um membro de dados na classe de registro de usuário de cada campo que você especificar no seu mapa de coluna; para cada um desses membros de dados, também declarar um membro de dados de status e de comprimento. Saiba mais em [Membros de dados do status de campo em acessadores gerados por assistente](../../data/oledb/field-status-data-members-in-wizard-generated-accessors.md).

    > [!NOTE]
    > Se você criar seu próprio consumidor, as variáveis de dados deverão vir antes das variáveis de status e comprimento.

- Criar uma instância de uma fonte de dados e uma sessão. Decidir o tipo de conjunto de linhas e acessador a usar e, em seguida, criar uma instância de um conjunto de linhas usando [CCommand](../../data/oledb/ccommand-class.md) ou [CTable](../../data/oledb/ctable-class.md):

    ```cpp
    CDataSource ds;
    CSession ss;
    class CMyTableName : public CCommand<CAccessor<CMyTableNameAccessor>>
    ```

- Chamar `CoInitialize` ao iniciar o COM. Isso é chamado no código principal. Por exemplo:

    ```cpp
    HRESULT hr = CoInitialize(NULL);
    ```

- Chamar [CDataSource::Open](../../data/oledb/cdatasource-open.md) ou uma de suas variações.

- Abrir uma conexão com a fonte de dados, abrir a sessão e abrir e iniciar o conjunto de linhas (se for um comando, execute-o também):

    ```cpp
    hr = ds.Open();
    hr = ss.Open(ds);
    hr = rs.Open();            // (Open also executes the command)
    ```

- Opcionalmente, definir as propriedades do conjunto de linhas usando `CDBPropSet::AddProperty` e passá-las como um parâmetro para `rs.Open`. Confira um exemplo de como isso é feito em `GetRowsetProperties` em [Métodos gerados pelo Assistente do Consumidor](../../data/oledb/consumer-wizard-generated-methods.md).

- Agora, você pode usar o conjunto de linhas para recuperar/manipular os dados.

- Quando o aplicativo estiver concluído, feche a conexão, a sessão e o conjunto de linhas:

    ```cpp
    rs.Close();
    ss.Close();
    ds.Close();
    ```

   Se estiver usando um comando, talvez queira chamar `ReleaseCommand` após `Close`. O exemplo de código [CCommand::Close](../../data/oledb/ccommand-close.md) mostra como chamar `Close` e `ReleaseCommand`.

- Chamar `CoUnInitialize` para cancelar a inicialização do COM. Isso é chamado no código principal.

    ```cpp
    CoUninitialize();
    ```

## <a name="see-also"></a>Confira também

[Criando um consumidor do OLE DB](../../data/oledb/creating-an-ole-db-consumer.md)
