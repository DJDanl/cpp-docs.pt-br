---
title: Classe CSyncObject
ms.date: 11/04/2016
f1_keywords:
- CSyncObject
- AFXMT/CSyncObject
- AFXMT/CSyncObject::CSyncObject
- AFXMT/CSyncObject::Lock
- AFXMT/CSyncObject::Unlock
- AFXMT/CSyncObject::m_hObject
helpviewer_keywords:
- CSyncObject [MFC], CSyncObject
- CSyncObject [MFC], Lock
- CSyncObject [MFC], Unlock
- CSyncObject [MFC], m_hObject
ms.assetid: c62ea6eb-a17b-4e01-aed4-321fc435a5f4
ms.openlocfilehash: 842ff5f98f05425fbbb511d112ae3e4fd65ff076
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57263703"
---
# <a name="csyncobject-class"></a>Classe CSyncObject

Uma classe virtual pura que fornece funcionalidade comum para os objetos de sincronização no Win32.

## <a name="syntax"></a>Sintaxe

```
class CSyncObject : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSyncObject::CSyncObject](#csyncobject)|Constrói um objeto `CSyncObject`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSyncObject::Lock](#lock)|Obtém o acesso ao objeto de sincronização.|
|[CSyncObject::Unlock](#unlock)|Obtém o acesso ao objeto de sincronização.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSyncObject::operator identificador](#operator_handle)|Fornece acesso ao objeto de sincronização.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSyncObject::m_hObject](#m_hobject)|O identificador para o objeto subjacente de sincronização.|

## <a name="remarks"></a>Comentários

A biblioteca Microsoft Foundation Class fornece várias classes derivadas de `CSyncObject`. Esses são [CEvent](../../mfc/reference/cevent-class.md), [CMutex](../../mfc/reference/cmutex-class.md), [CCriticalSection](../../mfc/reference/ccriticalsection-class.md), e [CSemaphore](../../mfc/reference/csemaphore-class.md).

Para obter informações sobre como usar os objetos de sincronização, consulte o artigo [Multithreading: Como usar as Classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CSyncObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmt.h

##  <a name="csyncobject"></a>  CSyncObject::CSyncObject

Constrói um objeto de sincronização com o nome fornecido.

```
explicit CSyncObject(LPCTSTR pstrName);
virtual ~CSyncObject();
```

### <a name="parameters"></a>Parâmetros

*pstrName*<br/>
O nome do objeto. Se for NULL, *pstrName* será nulo.

##  <a name="lock"></a>  CSyncObject::Lock

Chame essa função para acessar o recurso controlado pelo objeto de sincronização.

```
virtual BOOL Lock(DWORD dwTimeout = INFINITE);
```

### <a name="parameters"></a>Parâmetros

*dwTimeout*<br/>
Especifica a quantidade de tempo em milissegundos para aguardar o objeto de sincronização estejam disponíveis (sinalizado). Se for infinito, `Lock` aguardará até que o objeto é sinalizado antes de retornar.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Se o objeto de sincronização é sinalizado, `Lock` retornará com êxito e agora, o thread possui o objeto. Se o objeto de sincronização é não sinalizado (não disponível) `Lock` aguardará o objeto de sincronização ficar sinalizado até o número de milissegundos especificado na *dwTimeOut* parâmetro. Se o objeto de sincronização não sinalizado na quantidade especificada de tempo, `Lock` retorna falha.

##  <a name="m_hobject"></a>  CSyncObject::m_hObject

O identificador para o objeto subjacente de sincronização.

```
HANDLE m_hObject;
```

##  <a name="operator_handle"></a>  CSyncObject::operator identificador

Use este operador para obter o identificador do `CSyncObject` objeto.

```
operator HANDLE() const;
```

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, o identificador do objeto de sincronização; Caso contrário, nulo.

### <a name="remarks"></a>Comentários

Você pode usar o identificador para chamar diretamente as APIs do Windows.

##  <a name="unlock"></a>  CSyncObject::Unlock

A declaração de `Unlock` sem parâmetros é uma função virtual pura e deve ser substituído por todas as classes derivadas de `CSyncObject`.

```
virtual BOOL Unlock() = 0; virtual BOOL Unlock(
    LONG lCount,
    LPLONG lpPrevCount = NULL);
```

### <a name="parameters"></a>Parâmetros

*lCount*<br/>
Não é usada pela implementação do padrão.

*lpPrevCount*<br/>
Não é usada pela implementação do padrão.

### <a name="return-value"></a>Valor de retorno

Implementação padrão sempre retorna TRUE.

### <a name="remarks"></a>Comentários

A implementação padrão de declaração com dois parâmetros sempre retorna TRUE. Essa função é chamada para liberar o acesso ao objeto de sincronização pelo thread de chamada de propriedade. A segunda declaração é fornecida para objetos de sincronização, como semáforos que permitem que mais de um acesso de um recurso controlado.

## <a name="see-also"></a>Consulte também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
