---
title: Membros de dados do status de campo em acessadores gerados por assistente
ms.date: 10/24/2018
helpviewer_keywords:
- OLE DB consumer templates, field status
- field status in OLE DB templates
ms.assetid: 66e4e223-c60c-471e-860d-d23abcdfe371
ms.openlocfilehash: dd650b7cafef78e23c23ddfef791c88b6b93727f
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59025066"
---
# <a name="field-status-data-members-in-wizard-generated-accessors"></a>Membros de dados do status de campo em acessadores gerados por assistente

Quando você usa o **ATL OLE DB Assistente de consumidor** para criar um consumidor, o assistente gera um membro de dados na classe de registro de usuário de cada campo que você especificar no seu mapa de coluna. Cada membro de dados é do tipo `DWORD` e contém um valor de status correspondente ao seu respectivo campo.

Por exemplo, para um membro de dados *m_OwnerID*, o assistente gera um membro de dados adicionais para o status de campo (*dwOwnerIDStatus*) e outra para o tamanho do campo (*dwOwnerIDLength*). Ele também gera um mapa de coluna com entradas COLUMN_ENTRY_LENGTH_STATUS.

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
> Se você modificar a classe de registro de usuário ou escrever seu próprios consumidor, as variáveis de dados devem vir antes das variáveis de status e o comprimento.

Você pode usar os valores de status para fins de depuração. Se o código gerado pelo **ATL OLE DB Assistente de consumidor** gera erros de compilação como DB_S_ERRORSOCCURRED ou DB_E_ERRORSOCCURRED, você deve primeiro examinar os valores atuais dos membros de dados de status de campo. Aqueles que têm valores diferentes de zero correspondem às colunas incorretas.

Você também pode usar os valores de status para definir um valor NULL para um determinado campo. Isso ajuda você em casos em que você deseja distinguir um valor de campo como NULL em vez de zero. Cabe a você decidir se NULL é um valor válido ou um valor especial e decidir como seu aplicativo deve tratá-la. OLE DB define DBSTATUS_S_ISNULL como o meio correto de especificar um valor nulo genérico. Se o consumidor lê os dados e o valor for nulo, o campo de status é definido como DBSTATUS_S_ISNULL. Se o consumidor deseja definir um valor NULL, o consumidor define o valor de status como DBSTATUS_S_ISNULL antes de chamar o provedor.

Em seguida, abra o OLEDB e procure DBSTATUSENUM. Em seguida, você pode combinar o valor numérico do status diferente de zero em relação a valores de enumeração DBSTATUSENUM. Se o nome da enumeração não é suficiente para dizer o que está errado, consulte o **Status** tópico na **valores de dados de associação** seção o [guia do programador do DB OLE](/sql/connect/oledb/ole-db/oledb-driver-for-sql-server-programming). Este tópico contém tabelas de valores de status usados ao obter ou definir os dados. Para obter informações sobre valores de comprimento, consulte a **comprimento** tópico na mesma seção.

## <a name="retrieving-the-length-or-status-of-a-column"></a>Recuperando o Status de uma coluna ou de comprimento

Você pode recuperar o status de uma coluna (para verificar se há DBSTATUS_S_ISNULL, por exemplo) ou o comprimento de uma coluna de comprimento variável:

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

- Em seguida, acesse o tamanho e/ou o status conforme mostrado:

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

Quando você usa `CDynamicAccessor`, o comprimento e o status associados para você automaticamente. Para recuperar os valores de comprimento e o status, use o `GetLength` e `GetStatus` funções de membro.

## <a name="see-also"></a>Consulte também

[Trabalhando com modelos de consumidor do OLE DB](../../data/oledb/working-with-ole-db-consumer-templates.md)