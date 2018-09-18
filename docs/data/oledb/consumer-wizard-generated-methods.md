---
title: Métodos gerados pelo Assistente do consumidor | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OpenAll method
- attribute-injected classes and methods
- wizard-generated classes and methods
- OLE DB consumers, wizard-generated classes and methods
- methods [C++], OLE DB Consumer Wizard-generated
- CloseDataSource method
- consumer wizard-generated classes and methods
- OpenDataSource method
- CloseAll method
- OpenRowset method
- GetRowsetProperties method
ms.assetid: d80ee51c-8bb3-4dca-8760-5808e0fb47b4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 4a3f80d3e421701ac0612ddb2552d10d1eff1f02
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46056021"
---
# <a name="consumer-wizard-generated-methods"></a>Métodos gerados pelo Assistente do Consumidor

A ATL OLE DB Assistente de consumidor e o Assistente de aplicativo do MFC geram determinadas funções das quais você deve estar ciente. Observe que alguns métodos são implementados de maneira diferente em atribuído projetos, portanto, há algumas advertências; cada caso é abordado abaixo. Para obter informações sobre como exibir o código injetado, consulte [depurando código injetado](/visualstudio/debugger/how-to-debug-injected-code).  
  
- `OpenAll` Abre a fonte de dados, conjuntos de linhas e ativa indicadores se elas estiverem disponíveis.  
  
- `CloseAll` Fecha todos os conjuntos de linhas e libera todas as execuções de comando.  
  
- `OpenRowset` é chamado pelo OpenAll para abrir o conjunto de linhas ou a conjuntos de linhas do consumidor.  
  
- `GetRowsetProperties` recupera um ponteiro para a propriedade do conjunto de linhas definido com as propriedades que podem ser definidas.  
  
- `OpenDataSource` Abre a fonte de dados usando a cadeia de caracteres de inicialização que você especificou na **propriedades de vínculo de dados** caixa de diálogo.  
  
- `CloseDataSource` Fecha a fonte de dados de forma apropriada.  
  
## <a name="openall-and-closeall"></a>OpenAll e CloseAll  
  
```cpp  
HRESULT OpenAll();   

void CloseAll();  
```  
  
O exemplo a seguir mostra como você pode chamar `OpenAll` e `CloseAll` quando você executa o mesmo comando repetidamente. Compare o exemplo de código [ccommand:: Close](../../data/oledb/ccommand-close.md), que mostra uma variação que chama `Close` e `ReleaseCommand` em vez de `CloseAll`.  
  
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
  
## <a name="remarks"></a>Comentários  

Observe que, se você definir um `HasBookmark` método, o `OpenAll` código define a propriedade DBPROP_IRowsetLocate; Certifique-se de fazer isso se seu provedor oferecer suporte a essa propriedade.  
  
## <a name="openrowset"></a>OpenRowset  
  
```cpp  
// OLE DB Template version:   
HRESULT OpenRowset(DBPROPSET* pPropSet = NULL)  
// Attribute-injected version:  
HRESULT OpenRowset(const CSession& session, LPCWSTR szCommand = NULL);  
```  
  
`OpenAll` chama esse método para abrir o conjunto de linhas ou conjuntos de linhas no consumidor. Normalmente, você não precisará chamar `OpenRowset` , a menos que você deseja trabalhar com vários dados fontes/sessões/conjuntos de linhas. `OpenRowset` é declarado no arquivo de cabeçalho de classe comando ou de tabela:  
  
```  
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
  
Os atributos implementam esse método de forma diferente. Essa versão usa um objeto de sessão e uma cadeia de caracteres de comando padrão é a cadeia de caracteres de comando especificada no db_command, embora você pode passar um diferente. Observe que, se você definir um `HasBookmark` método, o `OpenRowset` código define a propriedade DBPROP_IRowsetLocate; Certifique-se de fazer isso se seu provedor oferecer suporte a essa propriedade.  
  
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
  
Esse método recupera um ponteiro para o conjunto de propriedades do conjunto de linhas; Você pode usar esse ponteiro para definir propriedades como DBPROP_IRowsetChange. `GetRowsetProperties` é usado na classe de registro de usuário da seguinte maneira. Você pode modificar este código para definir as propriedades do conjunto de linhas adicionais:  
  
```cpp  
void GetRowsetProperties(CDBPropSet* pPropSet)  
{  
   pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);  
   pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);  
   pPropSet->AddProperty(DBPROP_IRowsetChange, true, DBPROPOPTIONS_OPTIONAL);  
   pPropSet->AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE);  
}  
```  
  
## <a name="remarks"></a>Comentários  

Você não deve definir um global `GetRowsetProperties` método porque poderia entrar em conflito com aquele definido pelo assistente. Observe que esse é um método gerado pelo assistente que você obtém com projetos de modelo e atribuídos; os atributos não inserir esse código.  
  
## <a name="opendatasource-and-closedatasource"></a>OpenDataSource e CloseDataSource  
  
```cpp  
HRESULT OpenDataSource();   

void CloseDataSource();  
```  
  
## <a name="remarks"></a>Comentários  

O assistente define os métodos `OpenDataSource` e `CloseDataSource`; `OpenDataSource` chamadas [cdatasource:: Openfrominitializationstring](../../data/oledb/cdatasource-openfrominitializationstring.md).  
  
## <a name="see-also"></a>Consulte também  

[Criando um consumidor do OLE DB usando um assistente](../../data/oledb/creating-an-ole-db-consumer-using-a-wizard.md)