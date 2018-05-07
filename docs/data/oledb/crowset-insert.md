---
title: CRowset::Insert | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL.CRowset<TAccessor>.Insert
- CRowset.Insert
- CRowset<TAccessor>.Insert
- CRowset<TAccessor>::Insert
- ATL::CRowset<TAccessor>::Insert
- ATL.CRowset.Insert
- CRowset::Insert
- ATL::CRowset::Insert
dev_langs:
- C++
helpviewer_keywords:
- Insert method
ms.assetid: 6a64a1c3-10ac-4296-8685-0fd6fe63a13b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 44dddd6f3da835744463a9a95c44aa224d29d626
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="crowsetinsert"></a>CRowset::Insert
Cria e inicializa uma nova linha usando dados de acessador.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT Insert(int nAccessor = 0,   
   bool bGetHRow = false) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nAccessor`  
 [in] O número de acessador a ser usado para inserir os dados.  
  
 *bGetHRow*  
 [in] Indica se o identificador para a linha inserida é recuperado.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 Esse método requer que a interface opcional `IRowsetChange`, que talvez não tenha suporte em todos os provedores; se esse for o caso, o método retornará **E_NOINTERFACE**. Você também deve definir **DBPROP_IRowsetChange** para `VARIANT_TRUE` antes de chamar **abrir** na tabela ou que contém o conjunto de linhas de comando.  
  
 Inserção pode falhar se uma ou mais colunas não é gravável. Modifique seu mapa de cursor para corrigir o problema.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como acessar uma fonte de dados por meio de um conjunto de linhas e, em seguida, insira uma cadeia de caracteres usando uma tabela em que conjunto de linhas.  
  
 Primeiro, crie uma classe de tabela, inserindo um novo objeto de ATL ao seu projeto. Por exemplo, com o botão direito no projeto no painel de espaço de trabalho e selecione **novo objeto ATL**. Do **acesso a dados** categoria, selecione **consumidor**. Criar um objeto do consumidor do tipo **tabela**. (Selecionar **tabela** cria um conjunto de linhas diretamente da tabela; selecionando **comando** cria um conjunto de linhas por meio de um comando SQL.) Selecione uma fonte de dados, especificando uma tabela por meio do qual acessar a fonte de dados. Se você chamar o objeto do consumidor **CCustomerTable**, em seguida, você poderia implementar seu código de inserção da seguinte maneira:  
  
 [!code-cpp[NVC_OLEDB_Consumer#10](../../data/oledb/codesnippet/cpp/crowset-insert_1.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CRowset](../../data/oledb/crowset-class.md)