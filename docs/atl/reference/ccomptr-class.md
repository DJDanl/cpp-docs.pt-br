---
title: Classe CComPtr
ms.date: 11/04/2016
f1_keywords:
- CComPtr
- ATLBASE/ATL::CComPtr
- ATLBASE/ATL::CComPtr::CComPtr
helpviewer_keywords:
- CComPtr class
ms.assetid: 22d9ea8d-ed66-4c34-940f-141db11e83bd
ms.openlocfilehash: 612deccdf4697f366c2d40b1f4a329c015ddded9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50432832"
---
# <a name="ccomptr-class"></a>Classe CComPtr

Uma classe de ponteiro inteligente para gerenciar os ponteiros de interface COM.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class CComPtr
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Uma interface COM especificando o tipo de ponteiro a ser armazenado.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComPtr::CComPtr](#ccomptr)|O construtor.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComPtr::operator =](#operator_eq)|Atribui um ponteiro para o ponteiro de membro.|

## <a name="remarks"></a>Comentários

Usa o ATL `CComPtr` e [CComQIPtr](../../atl/reference/ccomqiptr-class.md) para gerenciar os ponteiros de interface COM. Ambos derivam [CComPtrBase](../../atl/reference/ccomptrbase-class.md), e ambos executem a contagem de referência automática.

O `CComPtr` e [CComQIPtr](../../atl/reference/ccomqiptr-class.md) classes podem ajudar a eliminar vazamentos de memória ao executar a contagem de referência automática.  As funções a seguir os dois executam as mesmas operações lógicas; No entanto, observe como a segunda versão pode ser menos propenso a erro, usando o `CComPtr` classe:

[!code-cpp[NVC_ATL_Utilities#130](../../atl/codesnippet/cpp/ccomptr-class_1.cpp)]

[!code-cpp[NVC_ATL_Utilities#131](../../atl/codesnippet/cpp/ccomptr-class_2.cpp)]

Em compilações de depuração, vincule atlsd para rastreamento de código.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CComPtrBase](../../atl/reference/ccomptrbase-class.md)

`CComPtr`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="ccomptr"></a>  CComPtr::CComPtr

O construtor.

```
CComPtr() throw ();
CComPtr(T* lp) throw ();
CComPtr (const CComPtr<T>& lp) throw ();
```

### <a name="parameters"></a>Parâmetros

*LP*<br/>
Usado para inicializar o ponteiro de interface.

*T*<br/>
Uma interface COM.

##  <a name="operator_eq"></a>  CComPtr::operator =

Operador de atribuição.

```
T* operator= (T* lp) throw ();
T* operator= (const CComPtr<T>& lp) throw ();
```

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para a atualização `CComPtr` objeto

### <a name="remarks"></a>Comentários

Esta operação AddRefs o novo objeto e versões existe o objeto existente, se houver um.

## <a name="see-also"></a>Consulte também

[CComPtr::CComPtr](#ccomptr)<br/>
[CComQIPtr::CComQIPtr](../../atl/reference/ccomqiptr-class.md#ccomqiptr)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
