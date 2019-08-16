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
ms.openlocfilehash: c4f4c7a5b7594270aff9dfbc224e9a66ba09be3f
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69505915"
---
# <a name="cinternetexception-class"></a>Classe CInternetException

Representa uma condição de exceção relacionada a uma operação de Internet.

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

A `CInternetException` classe inclui dois membros de dados públicos: um contém o código de erro associado à exceção e o outro contém o identificador de contexto do aplicativo de Internet associado ao erro.

Para obter mais informações sobre identificadores de contexto para aplicativos da Internet, consulte o artigo [programação da Internet com WinInet](../../mfc/win32-internet-extensions-wininet.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CException](../../mfc/reference/cexception-class.md)

`CInternetException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXINET. h

##  <a name="cinternetexception"></a>  CInternetException::CInternetException

Essa função de membro é chamada quando `CInternetException` um objeto é criado.

```
CInternetException(DWORD dwError);
```

### <a name="parameters"></a>Parâmetros

*dwError*<br/>
O erro que causou a exceção.

### <a name="remarks"></a>Comentários

Para lançar um CInternetException, chame a função global do MFC [AfxThrowInternetException](internet-url-parsing-globals.md#afxthrowinternetexception).

##  <a name="m_dwcontext"></a>  CInternetException::m_dwContext

O valor de contexto associado à operação de Internet relacionada.

```
DWORD_PTR m_dwContext;
```

### <a name="remarks"></a>Comentários

O identificador de contexto é especificado originalmente em [CInternetSession](../../mfc/reference/cinternetsession-class.md) e passado por MFC para classes derivadas de [CInternetConnection](../../mfc/reference/cinternetconnection-class.md)e [CInternetFile](../../mfc/reference/cinternetfile-class.md). Você pode substituir esse padrão e atribuir a qualquer parâmetro *dwContext* um valor de sua escolha. *dwContext* está associado a qualquer operação do objeto fornecido. *dwContext* identifica as informações de status da operação retornadas por [CInternetSession:: OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback).

##  <a name="m_dwerror"></a>  CInternetException::m_dwError

O erro que causou a exceção.

```
DWORD m_dwError;
```

### <a name="remarks"></a>Comentários

Esse valor de erro pode ser um código de erro do sistema, encontrado no WINERROR. H ou um valor de erro do WININET. T.

Para obter uma lista de códigos de erro do Win32, consulte [códigos de erro](/windows/win32/Debug/system-error-codes). Para obter uma lista de mensagens de erro específicas da Internet, consulte. Os dois tópicos estão no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Classe CException](../../mfc/reference/cexception-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CException](../../mfc/reference/cexception-class.md)
