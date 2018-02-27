---
title: Classe CCommand | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CCommand
- CCommand
- ATL.CCommand
dev_langs:
- C++
helpviewer_keywords:
- CCommand class
ms.assetid: 0760bfc5-b9ee-4aee-8e54-31bd78714d3a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: f4c53d7b27c98e0509cd434bf6eac2412b9c1a1a
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="ccommand-class"></a>Classe CCommand
Fornece métodos para definir e executar um comando.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class TAccessor = CNoAccessor,  
          template <typename T> class TRowset = CRowset,  
          class TMultiple = CNoMultipleResults>  
class CCommand :   
           public CAccessorRowset <TAccessor, TRowset>,  
           public CCommandBase,  
           public TMultiple  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `TAccessor`  
 O tipo de classe de acessador (como `CDynamicParameterAccessor`, `CDynamicStringAccessor`, ou `CEnumeratorAccessor`) que você deseja que o comando a ser usado. O padrão é `CNoAccessor`, que especifica que a classe não oferecem suporte a parâmetros ou colunas de saída.  
  
 `TRowset`  
 O tipo de classe de conjunto de linhas (como `CArrayRowset` ou `CNoRowset`) que você deseja que o comando a ser usado. O padrão é `CRowset`.  
  
 `TMultiple`  
 Para usar um comando de OLE DB que pode retornar diversos resultados, especifique [CMultipleResults](../../data/oledb/cmultipleresults-class.md). Caso contrário, use [CNoMultipleResults](../../data/oledb/cnomultipleresults-class.md). Para obter detalhes, consulte [IMultipleResults](https://msdn.microsoft.com/en-us/library/ms721289.aspx).  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[Fechar](../../data/oledb/ccommand-close.md)|Fecha o comando atual.|  
|[GetNextResult](../../data/oledb/ccommand-getnextresult.md)|Busca o próximo resultado quando define usando vários resultados.|  
|[Abrir](../../data/oledb/ccommand-open.md)|Executa e, opcionalmente, associa o comando.|  
  
### <a name="inherited-methods"></a>Métodos herdados  
  
|||  
|-|-|  
|[Criar](../../data/oledb/ccommand-create.md)|Cria um novo comando para a sessão especificada e define o texto do comando.|  
|[CreateCommand](../../data/oledb/ccommand-createcommand.md)|Cria um novo comando.|  
|[GetParameterInfo](../../data/oledb/ccommand-getparameterinfo.md)|Obtém uma lista de parâmetros do comando, seus nomes e seus tipos.|  
|[Preparar](../../data/oledb/ccommand-prepare.md)|Valida e otimiza o comando atual.|  
|[ReleaseCommand](../../data/oledb/ccommand-releasecommand.md)|Libera o acessador de parâmetro, se necessário, em seguida, libera o comando.|  
|[SetParameterInfo](../../data/oledb/ccommand-setparameterinfo.md)|Especifica o tipo nativo de cada parâmetro de comando.|  
|[Unprepare](../../data/oledb/ccommand-unprepare.md)|Descarta o plano de execução do comando atual.|  
  
## <a name="remarks"></a>Comentários  
 Use esta classe quando você precisa executar uma operação baseada em parâmetro ou executar um comando. Se você precisa apenas abrir um conjunto de linhas simple, use [CTable](../../data/oledb/ctable-class.md) em vez disso.  
  
 A classe de acessador que você está usando determina o método de associação de parâmetros e dados.  
  
 Observe que você não pode usar procedimentos armazenados com o provedor OLE DB para Jet porque esse provedor não dá suporte armazenados procedimentos (somente constantes são permitidas em cadeias de caracteres de consulta).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)