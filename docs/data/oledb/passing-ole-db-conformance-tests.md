---
title: Passando testes de conformidade de banco de dados OLE
ms.date: 11/04/2016
helpviewer_keywords:
- testing, OLE DB providers
- testing providers
- conformance testing
- conformance testing [OLE DB]
- OLE DB providers, testing
ms.assetid: d1a4f147-2edd-476c-b452-0e6a0ac09891
ms.openlocfilehash: eda4dccda147ddd4776bb56e649f539a7550abd1
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80209752"
---
# <a name="passing-ole-db-conformance-tests"></a>Passando testes de conformidade de banco de dados OLE

Para tornar os provedores mais consistentes, o SDK de acesso a dados fornece um conjunto de OLE DB testes de conformidade. Os testes verificam todos os aspectos do seu provedor e dão a você uma garantia razoável de que seu provedor funcione conforme o esperado. Você pode encontrar os testes de conformidade do OLE DB no SDK do Microsoft Data Access. Esta seção se concentra nas coisas que você deve fazer para passar os testes de conformidade. Para obter informações sobre como executar os testes de conformidade OLE DB, consulte o SDK.

## <a name="running-the-conformance-tests"></a>Executando os testes de conformidade

No Visual C++ 6,0, os modelos de provedor de OLE DB adicionaram várias funções de conexão para permitir que você verifique valores e propriedades. A maioria dessas funções foram adicionadas em resposta aos testes de conformidade.

> [!NOTE]
> Você precisa adicionar várias funções de validação para seu provedor para passar os testes de conformidade OLE DB.

Esse provedor requer duas rotinas de validação. A primeira rotina, `CRowsetImpl::ValidateCommandID`, faz parte da classe do conjunto de linhas. Ele é chamado durante a criação do conjunto de linhas pelos modelos de provedor. O exemplo usa essa rotina para informar aos consumidores que ele não oferece suporte a índices. A primeira chamada é para `CRowsetImpl::ValidateCommandID` (Observe que o provedor usa o typedef `_RowsetBaseClass` adicionado no mapa de interface para `CCustomRowset` no [suporte do provedor para indicadores](../../data/oledb/provider-support-for-bookmarks.md), de modo que você não precisa digitar essa linha longa de argumentos de modelo). Em seguida, retorne DB_E_NOINDEX se o parâmetro de índice não for nulo (isso indica que o consumidor deseja usar um índice em nós). Para obter mais informações sobre IDs de comando, consulte a especificação de OLE DB e procure `IOpenRowset::OpenRowset`.

O código a seguir é a rotina de validação de `ValidateCommandID`:

```cpp
/////////////////////////////////////////////////////////////////////
// CustomRS.H
// Class: CCustomRowset

HRESULT ValidateCommandID(DBID* pTableID, DBID* pIndexID)
{
   HRESULT hr = _RowsetBaseClass::ValidateCommandID(pTableID, pIndexID);
   if (hr != S_OK)
      return hr;

   if (pIndexID != NULL)
      return DB_E_NOINDEX;    // Doesn't support indexes

   return S_OK;
}
```

Os modelos de provedor chamam o método `OnPropertyChanged` sempre que alguém altera uma propriedade no grupo DBPROPSET_ROWSET. Se você quiser manipular propriedades para outros grupos, adicione-as ao objeto apropriado (ou seja, DBPROPSET_SESSION as verificações vão na classe `CCustomSession`).

O código verifica primeiro se a propriedade está vinculada a outra. Se a propriedade estiver sendo encadeada, ela definirá a propriedade DBPROP_BOOKMARKS como `True`. O Apêndice C da especificação de OLE DB contém informações sobre propriedades. Essas informações também indicam se a propriedade é encadeada a outra.

Talvez você também queira adicionar a rotina de `IsValidValue` ao seu código. Os modelos chamam `IsValidValue` ao tentar definir uma propriedade. Você substituirá esse método se precisar de processamento adicional ao definir um valor de propriedade. Você pode ter um desses métodos para cada conjunto de propriedades.

## <a name="see-also"></a>Confira também

[Técnicas de provedor avançadas](../../data/oledb/advanced-provider-techniques.md)
