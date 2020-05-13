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
ms.openlocfilehash: ebfbc185cdca2effc96ce2e6d96d05f997c52bf7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365979"
---
# <a name="csyncobject-class"></a>Classe CSyncObject

Uma classe virtual pura que fornece funcionalidade comum aos objetos de sincronização no Win32.

## <a name="syntax"></a>Sintaxe

```
class CSyncObject : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSyncObject::CSyncObject](#csyncobject)|Constrói um objeto `CSyncObject`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSyncObject::Lock](#lock)|Obtém acesso ao objeto de sincronização.|
|[CSyncObject::Unlock](#unlock)|Obtém acesso ao objeto de sincronização.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSyncObject::handle do operador](#operator_handle)|Fornece acesso ao objeto de sincronização.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSyncObject::m_hObject](#m_hobject)|A alça do objeto de sincronização subjacente.|

## <a name="remarks"></a>Comentários

A Biblioteca de Classes da Microsoft `CSyncObject`Foundation oferece várias classes derivadas de . Estes são [CEvent,](../../mfc/reference/cevent-class.md) [CMutex,](../../mfc/reference/cmutex-class.md) [CCriticalSection](../../mfc/reference/ccriticalsection-class.md)e [CSemaphore](../../mfc/reference/csemaphore-class.md).

Para obter informações sobre como usar os objetos de sincronização, consulte o artigo [Multithreading: Como usar as classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CSyncObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmt.h

## <a name="csyncobjectcsyncobject"></a><a name="csyncobject"></a>CSyncObject::CSyncObject

Constrói um objeto de sincronização com o nome fornecido.

```
explicit CSyncObject(LPCTSTR pstrName);
virtual ~CSyncObject();
```

### <a name="parameters"></a>Parâmetros

*pstrName*<br/>
O nome do objeto. Se NULO, *pstrName* será nulo.

## <a name="csyncobjectlock"></a><a name="lock"></a>CSyncObject::Lock

Chame esta função para obter acesso ao recurso controlado pelo objeto de sincronização.

```
virtual BOOL Lock(DWORD dwTimeout = INFINITE);
```

### <a name="parameters"></a>Parâmetros

*Dwtimeout*<br/>
Especifica a quantidade de tempo em milissegundos para esperar que o objeto de sincronização esteja disponível (sinalizado). Se INFINITE, `Lock` esperará até que o objeto seja sinalizado antes de retornar.

### <a name="return-value"></a>Valor retornado

Não zero se a função foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se o objeto de sincronização for sinalizado, `Lock` retornará com sucesso e o segmento agora possui o objeto. Se o objeto de sincronização não `Lock` for sinalizado (indisponível), aguardará que o objeto de sincronização seja sinalizado até o número de milissegundos especificados no parâmetro *dwTimeOut.* Se o objeto de sincronização não tiver sido sinalizado na quantidade de tempo especificada, `Lock` a falha de retorno.

## <a name="csyncobjectm_hobject"></a><a name="m_hobject"></a>CSyncObject::m_hObject

A alça do objeto de sincronização subjacente.

```
HANDLE m_hObject;
```

## <a name="csyncobjectoperator-handle"></a><a name="operator_handle"></a>CSyncObject::handle do operador

Use este operador para obter `CSyncObject` a alça do objeto.

```
operator HANDLE() const;
```

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, a alça do objeto de sincronização; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Você pode usar a alça para chamar apis do Windows diretamente.

## <a name="csyncobjectunlock"></a><a name="unlock"></a>CSyncObject::Unlock

A declaração de `Unlock` sem parâmetros é uma função virtual pura, `CSyncObject`e deve ser substituída por todas as classes derivadas de .

```
virtual BOOL Unlock() = 0; virtual BOOL Unlock(
    LONG lCount,
    LPLONG lpPrevCount = NULL);
```

### <a name="parameters"></a>Parâmetros

*Lcount*<br/>
Não usado por implementação padrão.

*lpPrevCount*<br/>
Não usado por implementação padrão.

### <a name="return-value"></a>Valor retornado

A implementação padrão sempre retorna TRUE.

### <a name="remarks"></a>Comentários

A implementação padrão da declaração com dois parâmetros sempre retorna TRUE. Esta função é chamada para liberar o acesso ao objeto de sincronização de propriedade do segmento de chamada. A segunda declaração é fornecida para objetos de sincronização, como semáforos que permitem mais de um acesso a um recurso controlado.

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
