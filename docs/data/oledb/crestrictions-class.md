---
title: Classe CRestrictions | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL::CRestrictions
- CRestrictions
- ATL.CRestrictions
- CRestrictions.Open
- ATL::CRestrictions::Open
- ATL.CRestrictions.Open
- CRestrictions::Open
dev_langs:
- C++
helpviewer_keywords:
- CRestrictions class
- Open method
ms.assetid: 0aaa2364-641c-4318-b110-7446aada4b4f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: a4ea0536a8af87927521f88d888e19aa145f2c04
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50072064"
---
# <a name="crestrictions-class"></a>Classe CRestrictions

Uma classe genérica que permite que você especificar restrições para conjuntos de linhas de esquema.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T, short nRestrictions, const GUID* pguid>
class CRestrictions :
   public CSchemaRowset <T, nRestrictions>
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
A classe usada para o acessador.

*nRestrictions*<br/>
O número de colunas de restrição para o conjunto de linhas de esquema.

*pguid*<br/>
Um ponteiro para o GUID para o esquema.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbsch.h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Abrir](#open)|Retorna um resultado definido de acordo com as restrições fornecidas pelo usuário.|

## <a name="open"></a> Crestrictions:: Open

Retorna um resultado definido de acordo com as restrições fornecidas pelo usuário.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Open(const CSession& session,
   LPCTSTR lpszParam 1 = NULL,
   LPCTSTR lpszParam 2 = NULL,
   LPCTSTR lpszParam 3 = NULL,
   LPCTSTR lpszParam 4 = NULL,
   LPCTSTR lpszParam 5 = NULL,
   LPCTSTR lpszParam 6 = NULL,
   LPCTSTR lpszParam 7 = NULL,
   bool bBind = true);
```

#### <a name="parameters"></a>Parâmetros

*Sessão*<br/>
[in] Especifica um objeto de sessão existente usado para se conectar à fonte de dados.

*lpszParam*<br/>
[in] Especifica as restrições no conjunto de linhas de esquema.

*bBind*<br/>
[in] Especifica se deve associar o mapa de coluna automaticamente. O padrão é **verdadeira**, que faz com que o mapa de coluna a ser associado automaticamente. Definindo *bBind* à **falso** impede que a associação automática do mapa de coluna para que você pode vincular manualmente. (A vinculação manual é de interesse específico para os usuários OLAP.)

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

Você pode especificar um máximo de sete restrições em um conjunto de linhas de esquema.

Ver [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686) para obter informações sobre as restrições definidas em cada conjunto de linhas de esquema.

## <a name="see-also"></a>Consulte também

[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)<br/>
[Classes typedef e classes de conjunto de linhas de esquema](../../data/oledb/schema-rowset-classes-and-typedef-classes.md)