---
title: Passando testes de conformidade do OLE DB | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- testing, OLE DB providers
- testing providers
- conformance testing
- conformance testing [OLE DB]
- OLE DB providers, testing
ms.assetid: d1a4f147-2edd-476c-b452-0e6a0ac09891
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 11677e6295956de768c7ebc0c113d775b066bb0c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="passing-ole-db-conformance-tests"></a>Passando testes de conformidade de banco de dados OLE
Para que os provedores de mais consistente, o SDK de acesso de dados fornece um conjunto de testes de conformidade do OLE DB. Os testes verificar todos os aspectos do seu provedor e fornecer garantia razoável que suas funções de provedor como esperadas. Você pode encontrar os testes de conformidade do OLE DB no SDK do Microsoft Data Access. Esta seção aborda as coisas que você deve fazer para os testes de conformidade. Para obter informações sobre como executar os testes de conformidade do OLE DB, consulte o SDK.  
  
## <a name="running-the-conformance-tests"></a>Execução de testes de conformidade  
 No Visual C++ 6.0, os modelos de provedor do OLE DB adicionado um número de funções de gancho para que você possa verificar valores e propriedades. A maioria dessas funções foram adicionada em resposta a testes de conformidade.  
  
> [!NOTE]
>  Você precisa adicionar várias funções de validação para o provedor para passar nos testes de conformidade do OLE DB.  
  
 Este provedor requer duas rotinas de validação. A rotina primeiro, `CRowsetImpl::ValidateCommandID`, faz parte de sua classe de conjunto de linhas. Ele é chamado durante a criação do conjunto de linhas pelos modelos de provedor. O exemplo usa esta rotina para informar os clientes que não dá suporte a índices. É a primeira chamada `CRowsetImpl::ValidateCommandID` (Observe que o provedor usa o **_RowsetBaseClass** typedef adicionado no mapa de interface para `CMyProviderRowset` na [suporte do provedor para indicadores](../../data/oledb/provider-support-for-bookmarks.md), portanto, você não precisa Digite essa linha de tempo de argumentos de modelo). Em seguida, retornar **DB_E_NOINDEX** se o parâmetro de índice não é **nulo** (Isso indica que o consumidor deseja usar um índice em nós). Para obter mais informações sobre as IDs de comando, consulte a especificação OLE DB e procure **IOpenRowset:: OPENROWSET**.  
  
 O código a seguir é o **ValidateCommandID** rotina de validação:  
  
```cpp
/////////////////////////////////////////////////////////////////////  
// MyProviderRS.H  
// Class: CMyProviderRowset   
  
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
  
 A chamada de modelos de provedor de `OnPropertyChanged` método sempre que alguém altera uma propriedade no **DBPROPSET_ROWSET** grupo. Se você deseja manipular propriedades de outros grupos, você adicioná-los para o objeto apropriado (ou seja, **DBPROPSET_SESSION** verificações entrar a `CMyProviderSession` classe).  
  
 O código primeiro verifica se a propriedade está vinculada a outro. Se a propriedade está sendo encadeada, ele define o **DBPROP_BOOKMARKS** propriedade como True. Apêndice C da especificação OLE DB contém informações sobre propriedades. Essas informações também indica se a propriedade é vinculada a outro.  
  
 Você também poderá adicionar o `IsValidValue` rotina ao seu código. A chamada de modelos `IsValidValue` durante a tentativa de definir uma propriedade. Você poderia substituir este método se você precisar de processamento adicional ao definir um valor de propriedade. Você pode ter um destes métodos para cada conjunto de propriedades.  
  
## <a name="threading-issues"></a>Problemas de Threading  
 Por padrão, o OLE DB Provider assistente no ATL OLE DB Provider assistente gera código para o provedor executar em um modelo de apartment. Se você tentar executar esse código com os testes de conformidade, você obterá inicialmente falhas. Isso é porque Ltm.exe, a ferramenta usada para executar os testes de conformidade do OLE DB, padrões para liberar um thread. Os padrões de código de OLE DB Provider Assistente para desempenho e a facilidade de uso do modelo de apartment.  
  
 Para corrigir esse problema, você pode alterar LTM ou alterar o provedor.  
  
#### <a name="to-change-ltm-to-run-in-apartment-threaded-mode"></a>Para alterar LTM para executar em apartment threaded modo  
  
1.  No menu principal LTM, clique em **ferramentas**e, em seguida, clique em **opções**.  
  
2.  Sobre o **geral** , altere o modelo de threading de **thread livre** para **Apartment Threaded**.  
  
 Para alterar o provedor para executar no modo de thread livre:  
  
-   No seu projeto de provedor, procurar todas as instâncias de `CComSingleThreadModel` e substituí-lo por `CComMultiThreadModel`, que deve ser em seus cabeçalhos de origem, a sessão e o conjunto de linhas de dados.  
  
-   No arquivo. rgs, alterar o modelo de threading de **Apartment** para **ambos**.  
  
-   Programação correta seguem regras programação thread livre (ou seja, o bloqueio em gravações).  
  
## <a name="see-also"></a>Consulte também  
 [Técnicas de provedor avançadas](../../data/oledb/advanced-provider-techniques.md)