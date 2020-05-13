---
title: Classe CInternetException
ms.date: 11/04/2016
f1_keywords:
- CInternetException
- AFXINET/CInternetException
- AFXINET/CInternetException::CInternetException
- AFXINET/CInternetException::m_dwContext
- AFXINET/CInternetException::m_dwError
helpviewer_keywords:
- CInternetException [MFC], CInternetException
- CInternetException [MFC], m_dwContext
- CInternetException [MFC], m_dwError
ms.assetid: 44fb3cbe-523e-4754-8843-a77909990b14
ms.openlocfilehash: b0239afa2b984ccf93d661ec11f11013c89fd912
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372412"
---
# <a name="cinternetexception-class"></a>Classe CInternetException

Representa uma condição de exceção relacionada a uma operação na Internet.

## <a name="syntax"></a>Sintaxe

```
class CInternetException : public CException
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CInternetException::CInternetException](#cinternetexception)|Constrói um objeto `CInternetException`.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CInternetException::m_dwContext](#m_dwcontext)|O valor de contexto associado à operação que causou a exceção.|
|[CInternetException::m_dwError](#m_dwerror)|O erro que causou a exceção.|

## <a name="remarks"></a>Comentários

A `CInternetException` classe inclui dois membros de dados públicos: um detém o código de erro associado à exceção, e o outro detém o identificador de contexto do aplicativo da Internet associado ao erro.

Para obter mais informações sobre identificadores de contexto para aplicativos de Internet, consulte o artigo [Programação na Internet com WinInet](../../mfc/win32-internet-extensions-wininet.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cexception](../../mfc/reference/cexception-class.md)

`CInternetException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxinet.h

## <a name="cinternetexceptioncinternetexception"></a><a name="cinternetexception"></a>CInternetException::CInternetException

Essa função de membro `CInternetException` é chamada quando um objeto é criado.

```
CInternetException(DWORD dwError);
```

### <a name="parameters"></a>Parâmetros

*Dwerror*<br/>
O erro que causou a exceção.

### <a name="remarks"></a>Comentários

Para lançar uma CInternetException, chame a função global do MFC [AfxThrowInternetException](internet-url-parsing-globals.md#afxthrowinternetexception).

## <a name="cinternetexceptionm_dwcontext"></a><a name="m_dwcontext"></a>CInternetException::m_dwContext

O valor de contexto associado à operação da Internet relacionada.

```
DWORD_PTR m_dwContext;
```

### <a name="remarks"></a>Comentários

O identificador de contexto é originalmente especificado no [CInternetSession](../../mfc/reference/cinternetsession-class.md) e passado por MFC para [cInternetConnection](../../mfc/reference/cinternetconnection-class.md)- e [CInternetFile](../../mfc/reference/cinternetfile-class.md)-derived classes. Você pode substituir esse padrão e atribuir a qualquer parâmetro *dwContext* um valor de sua escolha. *dwContext* está associado a qualquer operação do objeto dado. *dwContext* identifica as informações de status da operação retornadas por [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback).

## <a name="cinternetexceptionm_dwerror"></a><a name="m_dwerror"></a>CInternetException::m_dwError

O erro que causou a exceção.

```
DWORD m_dwError;
```

### <a name="remarks"></a>Comentários

Este valor de erro pode ser um código de erro do sistema, encontrado no WINERROR. H, ou um valor de erro do WININET. H.

Para obter uma lista de códigos de erro Win32, consulte [Códigos de erro](/windows/win32/Debug/system-error-codes). Para obter uma lista de mensagens de erro específicas da Internet, consulte . Ambos os tópicos estão no Windows SDK.

## <a name="see-also"></a>Confira também

[Classe CException](../../mfc/reference/cexception-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CException](../../mfc/reference/cexception-class.md)
