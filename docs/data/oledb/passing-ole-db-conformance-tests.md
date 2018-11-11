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
ms.openlocfilehash: 7365176df314baf40ac1cc1ed53936598f05c79e
ms.sourcegitcommit: 943c792fdabf01c98c31465f23949a829eab9aad
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/07/2018
ms.locfileid: "51265068"
---
# <a name="passing-ole-db-conformance-tests"></a>Passando testes de conformidade de banco de dados OLE

Para provedores de tornar mais consistente, o SDK de acesso de dados fornece um conjunto de testes de conformidade do OLE DB. Os testes de verificar todos os aspectos do seu provedor e lhe dá garantia razoável de que suas funções de provedor como esperadas. Você pode encontrar os testes de conformidade com OLE DB sobre o Microsoft Data Access SDK. Esta seção se concentra em coisas que você deve fazer para passar nos testes de conformidade. Para obter informações sobre como executar os testes de conformidade com OLE DB, consulte o SDK.

## <a name="running-the-conformance-tests"></a>Executando os testes de conformidade

No Visual C++ 6.0, os modelos de provedor do OLE DB adicionado um número de funções de gancho para permitir que você verifique os valores e propriedades. A maioria dessas funções foram adicionada em resposta a testes de conformidade.

> [!NOTE]
> Você precisará adicionar várias funções de validação de seu provedor para passar nos testes de conformidade com OLE DB.

Este provedor requer duas rotinas de validação. A rotina primeiro, `CRowsetImpl::ValidateCommandID`, faz parte de sua classe de conjunto de linhas. Ele é chamado durante a criação do conjunto de linhas pelos modelos de provedor. O exemplo usa essa rotina para informar os consumidores que ele não dá suporte a índices. A primeira chamada é para `CRowsetImpl::ValidateCommandID` (Observe que o provedor usa o `_RowsetBaseClass` typedef adicionado no mapa de interface para `CCustomRowset` na [suporte do provedor para indicadores](../../data/oledb/provider-support-for-bookmarks.md), portanto, você não precise digitar essa linha longa de modelo argumentos). Em seguida, retorne DB_E_NOINDEX se o parâmetro de índice não é nulo (Isso indica que o consumidor deseja usar um índice em nós). Para obter mais informações sobre IDs de comando, consulte a especificação OLE DB e procure `IOpenRowset::OpenRowset`.

O código a seguir é o `ValidateCommandID` rotina de validação:

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

A chamada de modelos de provedor a `OnPropertyChanged` método sempre que alguém altera uma propriedade no grupo de DBPROPSET_ROWSET. Se você quiser manipular propriedades de outros grupos, adicioná-los ao objeto apropriado (ou seja, as verificações DBPROPSET_SESSION entrar a `CCustomSession` classe).

O código primeiro verifica para ver se a propriedade está vinculada a outro. Se a propriedade está sendo encadeada, ele define a propriedade DBPROP_BOOKMARKS como `True`. Apêndice b da especificação do OLE DB contém informações sobre as propriedades. Essas informações também indica se a propriedade encadeada a outra.

Você também poderá adicionar o `IsValidValue` rotina ao seu código. A chamada de modelos `IsValidValue` durante a tentativa de definir uma propriedade. Você pode substituir esse método se você precisar de processamento adicional ao definir um valor de propriedade. Você pode ter um dos seguintes métodos para cada conjunto de propriedades.

## <a name="see-also"></a>Consulte também

[Técnicas de provedor avançadas](../../data/oledb/advanced-provider-techniques.md)