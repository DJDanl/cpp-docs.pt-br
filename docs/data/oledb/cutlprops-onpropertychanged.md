---
title: 'Cutlprops:: OnPropertyChanged | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- OnPropertyChanged
- CUtlProps.OnPropertyChanged
- CUtlProps::OnPropertyChanged
dev_langs:
- C++
helpviewer_keywords:
- OnPropertyChanged method
ms.assetid: c5924210-b685-46c4-87f8-1b81e5bd3378
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: c9b52949db714206b6118000d004c6248b7d6235
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cutlpropsonpropertychanged"></a>CUtlProps::OnPropertyChanged
Chamado depois de definir uma propriedade para manipular propriedades encadeadas.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      virtual HRESULT OnPropertyChanged(ULONG /* iCurSet */,  
   DBPROP* pDBProp);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `iCurSet`  
 O índice na matriz de conjunto de propriedades; zero se houver apenas uma propriedade.  
  
 `pDBProp`  
 A ID de propriedade e o novo valor em uma [DBPROP](https://msdn.microsoft.com/en-us/library/ms717970.aspx) estrutura.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`. O padrão é valor de retorno `S_OK`.  
  
## <a name="remarks"></a>Comentários  
 Se você deseja manipular propriedades encadeadas, como indicadores ou atualizações cujos valores são dependentes de valor de propriedade do outro, você deve substituir essa função.  
  
## <a name="example"></a>Exemplo  
 Nessa função, o usuário obtém a ID de propriedade do `DBPROP*` parâmetro. Agora, é possível comparar a ID em relação a uma propriedade de cadeia. Quando a propriedade for localizada, `SetProperties` é chamado com a propriedade que agora será definida em conjunto com a outra propriedade. Nesse caso, se um obtém o `DBPROP_IRowsetLocate`, `DBPROP_LITERALBOOKMARKS`, ou `DBPROP_ORDEREDBOOKMARKS` propriedade, um conjunto de `DBPROP_BOOKMARKS` propriedade.  
  
 [!code-cpp[NVC_OLEDB_Provider#2](../../data/oledb/codesnippet/cpp/cutlprops-onpropertychanged_1.h)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CUtlProps](../../data/oledb/cutlprops-class.md)