---
title: 'Cdatasource:: Open | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CDataSource::Open
- ATL.CDataSource.Open
- CDataSource::Open
- CDataSource.Open
dev_langs:
- C++
helpviewer_keywords:
- Open method
ms.assetid: a6d28bd1-799a-48ed-8993-5f82d1705b77
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 6b21add1180343070fb85da113309e0a31f86aeb
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="cdatasourceopen"></a>CDataSource::Open
Abre uma conexão a uma fonte de dados usando um **CLSID**, **ProgID**, ou `CEnumerator` moniker ou solicita ao usuário uma caixa de diálogo do localizador.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT Open(const CLSID& clsid,  
   DBPROPSET* pPropSet = NULL,  
   ULONG nPropertySets = 1) throw();  


HRESULT Open(const CLSID& clsid,  
   LPCTSTR pName,  
   LPCTSTR pUserName = NULL,  
   LPCTSTR pPassword = NULL,  
   long nInitMode = 0) throw();HRESULT Open(LPCTSTR szProgID,  
  DBPROPSET* pPropSet = NULL,  
   ULONG nPropertySets = 1) throw();HRESULT Open(LPCTSTR szProgID,  
   LPCTSTR pName,  LPCTSTR pUserName = NULL,  
   LPCTSTR pPassword = NULL,  
   long nInitMode = 0) throw();  

HRESULT Open(const CEnumerator& enumerator,  
   DBPROPSET* pPropSet = NULL,  
   ULONG nPropertySets = 1) throw();  

HRESULT Open(const CEnumerator& enumerator,  
   LPCTSTR pName,  
   LPCTSTR pUserName = NULL,  
   LPCTSTR pPassword = NULL,  
   long nInitMode = 0) throw();  

HRESULT Open(HWND hWnd = GetActiveWindow(),  
   DBPROMPTOPTIONS dwPromptOptions = DBPROMPTOPTIONS_WIZARDSHEET) throw();

HRESULT Open(LPCWSTR szProgID,   
  DBPROPSET* pPropSet = NULL,   
   ULONG nPropertySets = 1) throw();

HRESULT Open(LPCSTR szProgID,   
   LPCTSTR pName,LPCTSTR pUserName = NULL,   
   LPCTSTR pPassword = NULL,   
   long nInitMode = 0) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `clsid`  
 [in] O **CLSID** do provedor de dados.  
  
 *pPropSet*  
 [in] Um ponteiro para uma matriz de [DBPROPSET](https://msdn.microsoft.com/en-us/library/ms714367.aspx) estruturas contendo propriedades e valores a serem definidos. Consulte [conjuntos de propriedades e grupos de propriedade](https://msdn.microsoft.com/en-us/library/ms713696.aspx) no *referência do programador de OLE DB* no SDK do Windows.  
  
 *nPropertySets*  
 [in] O número de [DBPROPSET](https://msdn.microsoft.com/en-us/library/ms714367.aspx) estruturas passado a *pPropSet* argumento.  
  
 *pName*  
 [in] O nome do banco de dados ao qual se conectar.  
  
 *pUserName*  
 [in] O nome do usuário.  
  
 *pPassword*  
 [in] A senha do usuário.  
  
 `nInitMode`  
 [in] Modo de inicialização do banco de dados. Consulte [propriedades de inicialização](https://msdn.microsoft.com/en-us/library/ms723127.aspx)no *referência do programador de DB OLE* no SDK do Windows para obter uma lista dos modos de inicialização válido. Se `nInitMode` for zero, sem inicialização modo está incluído no conjunto de propriedades usado para abrir a conexão.  
  
 `szProgID`  
 [in] Um identificador de programa.  
  
 `enumerator`  
 [in] Um [CEnumerator](../../data/oledb/cenumerator-class.md) objeto usado para obter um identificador de origem para abrir a conexão quando o chamador não especificar um **CLSID**.  
  
 `hWnd`  
 [in] Identificador para a janela que está ser o pai da caixa de diálogo. Usando a sobrecarga de função que usa o `hWnd` parâmetro invocará automaticamente os componentes de serviço; Consulte comentários para obter detalhes.  
  
 `dwPromptOptions`  
 [in] Determina o estilo da caixa de diálogo de localizador para exibir. Consulte Msdasc.h para os valores possíveis.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 A sobrecarga do método que usa o `hWnd` parâmetro abre um objeto de fonte de dados com os componentes de serviço no Oledb32; essa DLL contém a implementação de recursos de componentes de serviço, como o pool de recursos, inscrição de transação automática, e assim por diante. Para obter mais informações, consulte "OLE DB Services" na referência do OLE DB do programador em [http://msdn.microsoft.com/library/default.asp?url=/library/oledb/htm/oledbole_db_services.asp?frame=true](http://msdn.microsoft.com/library/default.asp?url=/library/oledb/htm/oledbole_db_services.asp?frame=true).  
  
 As sobrecargas de método que não usam o `hWnd` parâmetro abrir um objeto de fonte de dados sem usar os componentes de serviço no Oledb32. Um [CDataSource](../../data/oledb/cdatasource-class.md) objeto aberto com essas sobrecargas de função, será possível usar qualquer funcionalidade de componentes de serviço.  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra como abrir uma fonte de dados do Jet 4.0 com modelos OLE DB. Você pode tratar a fonte de dados do Jet como uma fonte de dados OLE DB. No entanto, a chamada para **abrir** precisa de dois conjuntos de propriedades: uma para **DBPROPSET_DBINIT** e outro para **DBPROPSET_JETOLEDB_DBINIT**, de modo que você pode definir  **DBPROP_JETOLEDB_DATABASEPASSWORD**.  
  
 [!code-cpp[NVC_OLEDB_Consumer#7](../../data/oledb/codesnippet/cpp/cdatasource-open_1.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDataSource](../../data/oledb/cdatasource-class.md)
