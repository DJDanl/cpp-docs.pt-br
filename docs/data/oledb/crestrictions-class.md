---
title: Classe CRestrictions
ms.date: 11/04/2016
f1_keywords:
- ATL::CRestrictions
- CRestrictions
- ATL.CRestrictions
- CRestrictions.Open
- ATL::CRestrictions::Open
- ATL.CRestrictions.Open
- CRestrictions::Open
helpviewer_keywords:
- CRestrictions class
- Open method
ms.assetid: 0aaa2364-641c-4318-b110-7446aada4b4f
ms.openlocfilehash: a380f1ba00dcc444099f186071b7d55c9db71291
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88844958"
---
# <a name="crestrictions-class"></a>Classe CRestrictions

Uma classe genérica que permite que você especifique restrições para conjuntos de linhas de esquema.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T, short nRestrictions, const GUID* pguid>
class CRestrictions :
   public CSchemaRowset <T, nRestrictions>
```

### <a name="parameters"></a>parâmetros

*T*<br/>
A classe usada para o acessador.

*nRestrictions*<br/>
O número de colunas de restrição para o conjunto de linhas de esquema.

*pguid*<br/>
Um ponteiro para o GUID do esquema.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atldbsch. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

| Nome | Descrição |
|-|-|
|[Abrir](#open)|Retorna um conjunto de resultados de acordo com as restrições fornecidas pelo usuário.|

## <a name="crestrictionsopen"></a><a name="open"></a> CRestrictions:: abrir

Retorna um conjunto de resultados de acordo com as restrições fornecidas pelo usuário.

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

#### <a name="parameters"></a>parâmetros

*sessão*<br/>
no Especifica um objeto de sessão existente usado para se conectar à fonte de dados.

*lpszParam*<br/>
no Especifica as restrições no conjunto de linhas de esquema.

*bBind*<br/>
no Especifica se o mapa de coluna deve ser associado automaticamente. O padrão é **`true`** , que faz com que o mapa de coluna seja vinculado automaticamente. Definir *bBind* para **`false`** impedir a associação automática do mapa de coluna para que você possa associar manualmente. (A vinculação manual é de interesse particular para os usuários OLAP.)

### <a name="return-value"></a>Valor Retornado

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

Você pode especificar um máximo de sete restrições em um conjunto de linhas de esquema.

Consulte [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686(v=vs.85)) para obter informações sobre as restrições definidas em cada conjunto de linhas de esquema.

## <a name="see-also"></a>Confira também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)<br/>
[Classes de conjunto de linhas de esquema e classes de typedef](../../data/oledb/schema-rowset-classes-and-typedef-classes.md)
