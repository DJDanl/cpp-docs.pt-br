---
title: Registro de usuário
ms.date: 05/09/2019
helpviewer_keywords:
- records, user
- OLE DB providers, user record
- user records
- user records, described
- rowsets, user record
ms.assetid: 9c0d2864-2738-4f62-a750-1016d9c3523f
ms.openlocfilehash: d6920a73f107f226cc31cb27fd15178f6d2f1c26
ms.sourcegitcommit: 00e26915924869cd7eb3c971a7d0604388abd316
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/10/2019
ms.locfileid: "65525259"
---
# <a name="user-record"></a>Registro de usuário

> [!NOTE] 
> O assistente de Provedor OLE DB da ATL não está disponível no Visual Studio 2019 e posteriores.

O registro de usuário fornece a estrutura de dados e código que representa os dados da coluna para um conjunto de linhas. Um registro de usuário pode ser criado no tempo de compilação ou tempo de execução. Quando você cria um provedor usando o **Assistente de Provedor OLE DB da ATL**, o assistente cria um registro de usuário padrão que se parece com isto (supondo que você especificou um nome de provedor [nome curto] como *MyProvider*):

```cpp
class CWindowsFile:
   public WIN32_FIND_DATA
{
public:
  
BEGIN_PROVIDER_COLUMN_MAP(CMyProviderWindowsFile)
   PROVIDER_COLUMN_ENTRY("FileAttributes", 1, dwFileAttributes)
   PROVIDER_COLUMN_ENTRY("FileSizeHigh", 2, nFileSizeHigh)
   PROVIDER_COLUMN_ENTRY("FileSizeLow", 3, nFileSizeLow)
   PROVIDER_COLUMN_ENTRY_STR("FileName", 4, cFileName)
   PROVIDER_COLUMN_ENTRY_STR("AltFileName", 5, cAlternateFileName)
END_PROVIDER_COLUMN_MAP()
  
};
```

Os modelos de provedor OLE DB tratam de todas as especificações OLE DB em interações com o cliente. Para obter os dados de coluna necessários para uma resposta, o provedor chama a função `GetColumnInfo`, que você deve colocar no registro de usuário. Você pode substituir explicitamente `GetColumnInfo` no registro de usuário; por exemplo, declarando-o no arquivo .h, como mostrado aqui:

```cpp
template <class T>
static ATLCOLUMNINFO* GetColumnInfo(T* pThis, ULONG* pcCols) 
```

Isso equivale a:

```cpp
static ATLCOLUMNINFO* GetColumnInfo(CommandClass* pThis, ULONG* pcCols)
static ATLCOLUMNINFO* GetColumnInfo(RowsetClass* pThis, ULONG* pcCols)
```

Em seguida, implemente `GetColumnInfo` no arquivo .cpp do registro de usuário.

As macros PROVIDER_COLUMN_MAP auxiliam na criação de uma função `GetColumnInfo`:

- BEGIN_PROVIDER_COLUMN_MAP define o protótipo de função e uma matriz estática de estruturas `ATLCOLUMNINFO`.

- PROVIDER_COLUMN_ENTRY define e inicializa um único `ATLCOLUMNINFO`.

- END_PROVIDER_COLUMN_MAP fecha a matriz e a função. Ela também coloca a contagem de elementos de matriz no parâmetro *pcCols*.

Quando um registro de usuário é criado em tempo de execução, `GetColumnInfo` usa o parâmetro *pThis* para receber um ponteiro para uma instância do conjunto de linhas ou do comando. Os comandos e conjuntos de linhas devem ser compatíveis com a interface `IColumnsInfo` para que as informações de coluna possam ser extraídas desse ponteiro.

`CommandClass` e `RowsetClass` são os comandos e o conjunto de linhas que usam o registro de usuário.

Veja um exemplo mais detalhado de como substituir `GetColumnInfo` em um registro de usuário em [Determinando dinamicamente as colunas retornadas ao consumidor](../../data/oledb/dynamically-determining-columns-returned-to-the-consumer.md).

## <a name="see-also"></a>Consulte também

[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
