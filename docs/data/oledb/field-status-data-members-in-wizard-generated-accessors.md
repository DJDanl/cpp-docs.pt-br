---
title: Membros de dados do status de campo em acessadores gerados por assistente
ms.date: 05/09/2019
helpviewer_keywords:
- OLE DB consumer templates, field status
- field status in OLE DB templates
ms.assetid: 66e4e223-c60c-471e-860d-d23abcdfe371
ms.openlocfilehash: 61ee867f664b6b0d885e35f6d58840b37ce322b9
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80210906"
---
# <a name="field-status-data-members-in-wizard-generated-accessors"></a>Membros de dados do status de campo em acessadores gerados por assistente

::: moniker range="vs-2019"

O Assistente de Consumidor OLE DB da ATL não está disponível no Visual Studio 2019 e posteriores. Ainda é possível adicionar a funcionalidade manualmente. Saiba mais em [Criação de um consumidor sem usar um assistente](creating-a-consumer-without-using-a-wizard.md).

::: moniker-end

::: moniker range="<=vs-2017"

Quando você usa o **Assistente de Consumidor OLE DB do ATL** para criar um consumidor, o assistente gera um membro de dados na classe de registro de usuário de cada campo que você especifica no seu mapa de coluna. Cada membro de dados é do tipo `DWORD` e contém um valor de status correspondente ao seu respectivo campo.

Por exemplo, para um membro de dados *m_OwnerID*, o assistente gera um membro de dados adicional para o status de campo (*dwOwnerIDStatus*) e outro para o tamanho do campo (*dwOwnerIDLength*). Ele também gera um mapa de coluna com entradas COLUMN_ENTRY_LENGTH_STATUS.

Isso é mostrado no código a seguir:

```cpp
class CAuthorsAccessor
{
public:
   LONG m_AuID;
   TCHAR m_Author[53];
   LONG m_YearBorn;

   DBSTATUS m_dwAuIDStatus;
   DBSTATUS m_dwAuthorStatus;
   DBSTATUS m_dwYearBornStatus;

   DBLENGTH m_dwAuIDLength;
   DBLENGTH m_dwAuthorLength;
   DBLENGTH m_dwYearBornLength;

   DEFINE_COMMAND_EX(CAuthorsAccessor, L" \
   SELECT \
      AuID, \
      Author, \
      YearBorn \
      FROM dbo.Authors")

   BEGIN_COLUMN_MAP(CAuthorsAccessor)
      COLUMN_ENTRY_LENGTH_STATUS(1, m_AuID, dwAuIDLength, dwAuIDStatus)
      COLUMN_ENTRY_LENGTH_STATUS(2, m_Author, dwAuthorLength, dwAuthorStatus)
      COLUMN_ENTRY_LENGTH_STATUS(3, m_YearBorn, dwYearBornLength, dwYearBornStatus)
   END_COLUMN_MAP()
...
```

> [!NOTE]
> Se você modificar a classe de registro de usuário ou escrever seu próprio consumidor, as variáveis de dados deverão vir antes das variáveis de status e comprimento.

É possível usar os valores de status para fins de depuração. Se o código gerado pelo **Assistente de Consumidor OLE DB do ATL** gerar erros de compilação, como DB_S_ERRORSOCCURRED ou DB_E_ERRORSOCCURRED, primeiro examine os valores atuais dos membros de dados do status de campo. Aqueles que têm valores diferentes de zero correspondem às colunas incorretas.

Você também pode usar os valores de status para definir um valor NULL para determinado campo. Isso ajuda nos casos em que você quer distinguir um valor de campo como NULL em vez de zero. Cabe a você decidir se NULL é um valor válido ou um valor especial e como seu aplicativo deve tratá-lo. O OLE DB define DBSTATUS_S_ISNULL como o meio correto de especificar um valor NULL genérico. Se o consumidor lê os dados e o valor é nulo, o campo de status é definido como DBSTATUS_S_ISNULL. Se o consumidor deseja definir um valor NULL, deve definir o valor de status como DBSTATUS_S_ISNULL antes de chamar o provedor.

Em seguida, abra o OLEDB e procure DBSTATUSENUM. Em seguida, você pode corresponder o valor numérico do status diferente de zero com valores de enumeração DBSTATUSENUM. Se o nome da enumeração não for suficiente para informar o que está errado, confira o tópico **Status** na seção **Associar valores de dados** do [Guia do Programador de OLE DB](/sql/connect/oledb/ole-db/oledb-driver-for-sql-server-programming). Este tópico contém tabelas de valores de status usados ao obter ou definir dados. Saiba mais sobre valores de comprimento no tópico **Comprimento** na mesma seção.

## <a name="retrieving-the-length-or-status-of-a-column"></a>Recuperar o comprimento ou status de uma coluna

É possível recuperar o comprimento de uma coluna de comprimento variável ou o status de uma coluna (para verificar se há DBSTATUS_S_ISNULL, por exemplo):

- Para obter o comprimento, use a macro COLUMN_ENTRY_LENGTH.

- Para obter o status, use a macro COLUMN_ENTRY_STATUS.

- Para obter ambos, use COLUMN_ENTRY_LENGTH_STATUS, conforme mostrado:

    ```cpp
    class CProducts
    {
    public:
       char      szName[40];
       long      nNameLength;
       DBSTATUS   nNameStatus;

    BEGIN_COLUMN_MAP(CProducts)
    // Bind the column to CProducts.m_ProductName.
    // nOrdinal is zero-based, so the column number of m_ProductName is 1.
       COLUMN_ENTRY_LENGTH_STATUS(1, szName, nNameLength, nNameStatus)
    END_COLUMN_MAP()
    };
    ```

- Em seguida, acesse o comprimento e/ou status conforme mostrado:

    ```cpp
    CTable<CAccessor<CProducts >> product;
    CSession session;

    product.Open(session, "Product");

    while (product.MoveNext() == S_OK)
    {
       // Check the product name isn't NULL before tracing it
       if (product.nNameStatus == DBSTATUS_S_OK)
          ATLTRACE("%s is %d characters\n", product.szName, product.nNameLength);
    }
    ```

Quando você usa `CDynamicAccessor`, o comprimento e o status são associados automaticamente. Para recuperar os valores de comprimento e status, use as funções de membro `GetLength` e `GetStatus`.

::: moniker-end

## <a name="see-also"></a>Confira também

[Trabalhando com modelos de consumidor do OLE DB](../../data/oledb/working-with-ole-db-consumer-templates.md)
