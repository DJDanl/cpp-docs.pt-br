---
title: Métodos gerados pelo Assistente do Consumidor
ms.date: 05/09/2019
helpviewer_keywords:
- OLE DB consumers, wizard-generated classes and methods
ms.assetid: d80ee51c-8bb3-4dca-8760-5808e0fb47b4
ms.openlocfilehash: f3bcc799f2a9591cfe7b2fc364b03161b5c0da33
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91500693"
---
# <a name="consumer-wizard-generated-methods"></a>Métodos gerados pelo Assistente do Consumidor

::: moniker range="vs-2019"

O Assistente de Consumidor OLE DB da ATL não está disponível no Visual Studio 2019 e posteriores. Ainda é possível adicionar a funcionalidade manualmente.

::: moniker-end

::: moniker range="<=vs-2017"

O **Assistente de Consumidor OLE DB da ATL** e o **Assistente para Aplicativo do MFC** geram determinadas funções sobre as quais você deve estar ciente. Alguns métodos são implementados de forma diferente em projetos atribuídos, portanto, há algumas advertências; cada caso é abordado abaixo. Saiba mais sobre como exibir o código injetado em [Depuração de código injetado](/visualstudio/debugger/how-to-debug-injected-code).

- `OpenAll` abre a fonte de dados, os conjuntos de linhas e ativa indicadores se estiverem disponíveis.

- `CloseAll` fecha todos os conjuntos de linhas abertos e libera todas as execuções de comando.

- `OpenRowset` é chamado por `OpenAll` para abrir o conjunto de linhas ou conjuntos de linhas do consumidor.

- `GetRowsetProperties` recupera um ponteiro para a propriedade do conjunto de linhas definido com o qual as propriedades podem ser definidas.

- `OpenDataSource` abre a fonte de dados usando a cadeia de caracteres de inicialização especificada na caixa de diálogo **Propriedades do Link de Dados**.

- `CloseDataSource` fecha a fonte de dados de forma apropriada.

## <a name="openall-and-closeall"></a>OpenAll e CloseAll

```cpp
HRESULT OpenAll();

void CloseAll();
```

O exemplo a seguir mostra como você pode chamar `OpenAll` e `CloseAll` quando executa o mesmo comando repetidamente. Compare o exemplo de código [ccommand::Close](./ccommand-class.md#close), que mostra uma variação que chama `Close` e `ReleaseCommand` em vez de `CloseAll`.

```cpp
int main(int argc, char* argv[])
{
   HRESULT hr;

   hr = CoInitialize(NULL);

   CCustOrdersDetail rs;      // Your CCommand-derived class
   rs.m_OrderID = 10248;      // Open order 10248
   hr = rs.OpenAll();         // (Open also executes the command)
   hr = rs.MoveFirst();         // Move to the first row and print it
   printf( "Name: %s, Unit Price: %d, Quantity: %d, Discount %d, Extended Price %d\n", rs.m_ProductName, rs.m_UnitPrice.int64, rs.m_Quantity, rs.m_Discount, rs.m_ExtendedPrice.int64 );

   // Close the first command execution
   rs.Close();

   rs.m_OrderID = 10249;      // Open order 10249 (a new order)
   hr = rs.Open();            // (Open also executes the command)
   hr = rs.MoveFirst();         // Move to the first row and print it
   printf( "Name: %s, Unit Price: %d, Quantity: %d, Discount %d, Extended Price %d\n", rs.m_ProductName, rs.m_UnitPrice.int64, rs.m_Quantity, rs.m_Discount, rs.m_ExtendedPrice.int64 );

   // Close the second command execution;
   // Instead of rs.CloseAll() you could call
   // rs.Close() and rs.ReleaseCommand():
   rs.CloseAll();

   CoUninitialize();
   return 0;
}
```

### <a name="remarks"></a>Comentários

Se você definir um método `HasBookmark`, o código `OpenAll` definirá a propriedade `DBPROP_IRowsetLocate`; certifique-se de fazer isso somente se seu provedor der o suporte adequado.

## <a name="openrowset"></a>OpenRowset

```cpp
// OLE DB Template version:
HRESULT OpenRowset(DBPROPSET* pPropSet = NULL)
// Attribute-injected version:
HRESULT OpenRowset(const CSession& session, LPCWSTR szCommand = NULL);
```

`OpenAll` chama esse método para abrir o conjunto de linhas ou conjuntos de linhas no consumidor. Normalmente, você não precisa chamar `OpenRowset`, a menos que queira trabalhar com vários conjuntos de linhas/fontes de dados/sessões. `OpenRowset` é declarado no arquivo de cabeçalho da classe de comando ou de tabela:

```cpp
// OLE DB Template version:
HRESULT OpenRowset(DBPROPSET *pPropSet = NULL)
{
   HRESULT hr = Open(m_session, NULL, pPropSet);
   #ifdef _DEBUG
   if(FAILED(hr))
      AtlTraceErrorRecords(hr);
   #endif
   return hr;
}
```

Os atributos implementam esse método de forma diferente. Essa versão usa um objeto de sessão e uma cadeia de caracteres de comando que é padronizada para a cadeia de caracteres de comando especificada em db_command, embora você possa passar uma diferente. Se você definir um método `HasBookmark`, o código `OpenRowset` definirá a propriedade `DBPROP_IRowsetLocate`; certifique-se de fazer isso somente se seu provedor der o suporte adequado.

```cpp
// Attribute-injected version:
HRESULT OpenRowset(const CSession& session, LPCWSTR szCommand=NULL)
{

   DBPROPSET *pPropSet = NULL;
   CDBPropSet propset(DBPROPSET_ROWSET);
   __if_exists(HasBookmark)

   {
      propset.AddProperty(DBPROP_IRowsetLocate, true);
      pPropSet= &propset;
      }
...
}
```

## <a name="getrowsetproperties"></a>GetRowsetProperties

```cpp
void GetRowsetProperties(CDBPropSet* pPropSet);
```

Esse método recupera um ponteiro para o conjunto de propriedades do conjunto de linhas. Você pode usar esse ponteiro para definir propriedades como `DBPROP_IRowsetChange`. `GetRowsetProperties` é usado na classe de registro de usuário como se segue. Você pode modificar esse código para definir as propriedades adicionais do conjunto de linhas:

```cpp
void GetRowsetProperties(CDBPropSet* pPropSet)
{
   pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
   pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
   pPropSet->AddProperty(DBPROP_IRowsetChange, true, DBPROPOPTIONS_OPTIONAL);
   pPropSet->AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE);
}
```

### <a name="remarks"></a>Comentários

Você não deve definir um método `GetRowsetProperties` global porque ele poderia entrar em conflito com o que foi definido pelo assistente. Esse é um método gerado pelo assistente que você obtém com projetos de modelo e atribuídos; os atributos não injetam esse código.

## <a name="opendatasource-and-closedatasource"></a>OpenDataSource e CloseDataSource

```cpp
HRESULT OpenDataSource();

void CloseDataSource();
```

### <a name="remarks"></a>Comentários

O assistente define os métodos `OpenDataSource` e `CloseDataSource`; `OpenDataSource` chama [CDataSource::OpenFromInitializationString](./cdatasource-class.md#openfrominitializationstring).

::: moniker-end

## <a name="see-also"></a>Consulte também

[Criando um consumidor OLE DB usando um assistente](../../data/oledb/creating-an-ole-db-consumer-using-a-wizard.md)
