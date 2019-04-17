---
title: Classe COleDispatchException
ms.date: 11/04/2016
f1_keywords:
- COleDispatchException
- AFXDISP/COleDispatchException
- AFXDISP/COleDispatchException::m_dwHelpContext
- AFXDISP/COleDispatchException::m_strDescription
- AFXDISP/COleDispatchException::m_strHelpFile
- AFXDISP/COleDispatchException::m_strSource
- AFXDISP/COleDispatchException::m_wCode
helpviewer_keywords:
- COleDispatchException [MFC], m_dwHelpContext
- COleDispatchException [MFC], m_strDescription
- COleDispatchException [MFC], m_strHelpFile
- COleDispatchException [MFC], m_strSource
- COleDispatchException [MFC], m_wCode
ms.assetid: 0e95c8be-e21a-490c-99ec-181c6a9a26d0
ms.openlocfilehash: 2d5b9d2a0dc1e716ea8cb20f0d0dcb4c5d765079
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58769050"
---
# <a name="coledispatchexception-class"></a>Classe COleDispatchException

Manipula exceções específicas para o OLE `IDispatch` interface, que é uma parte fundamental da automação OLE.

## <a name="syntax"></a>Sintaxe

```
class COleDispatchException : public CException
```

## <a name="members"></a>Membros

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDispatchException::m_dwHelpContext](#m_dwhelpcontext)|Contexto de ajuda para o erro.|
|[COleDispatchException::m_strDescription](#m_strdescription)|Descrição textual do erro.|
|[COleDispatchException::m_strHelpFile](#m_strhelpfile)|Ajuda do arquivo a ser usado com `m_dwHelpContext`.|
|[COleDispatchException::m_strSource](#m_strsource)|Aplicativo que gerou a exceção.|
|[COleDispatchException::m_wCode](#m_wcode)|`IDispatch`-código de erro específico.|

## <a name="remarks"></a>Comentários

Como as outras classes de exceção derivada do `CException` classe base `COleDispatchException` podem ser usados com as macros THROW, THROW_LAST, TRY, CATCH, AND_CATCH e END_CATCH.

Em geral, você deve chamar [AfxThrowOleDispatchException](exception-processing.md#afxthrowoledispatchexception) para criar e lançar um `COleDispatchException` objeto.

Para obter mais informações sobre exceções, consulte os artigos [tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md) e [exceções: Exceções OLE](../../mfc/exceptions-ole-exceptions.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CException](../../mfc/reference/cexception-class.md)

`COleDispatchException`

## <a name="requirements"></a>Requisitos

**Header:** afxdisp.h

##  <a name="m_dwhelpcontext"></a>  COleDispatchException::m_dwHelpContext

Identifica um contexto de ajuda na Ajuda do seu aplicativo (. Arquivo HLP).

```
DWORD m_dwHelpContext;
```

### <a name="remarks"></a>Comentários

Este membro é definido pela função [AfxThrowOleDispatchException](exception-processing.md#afxthrowoledispatchexception) quando uma exceção é lançada.

### <a name="example"></a>Exemplo

  Veja o exemplo de [COleDispatchDriver::CreateDispatch](../../mfc/reference/coledispatchdriver-class.md#createdispatch).

##  <a name="m_strdescription"></a>  COleDispatchException::m_strDescription

Contém uma descrição textual do erro, como "Disco cheio".

```
CString m_strDescription;
```

### <a name="remarks"></a>Comentários

Este membro é definido pela função [AfxThrowOleDispatchException](exception-processing.md#afxthrowoledispatchexception) quando uma exceção é lançada.

### <a name="example"></a>Exemplo

  Veja o exemplo de [COleDispatchDriver::CreateDispatch](../../mfc/reference/coledispatchdriver-class.md#createdispatch).

##  <a name="m_strhelpfile"></a>  COleDispatchException::m_strHelpFile

O framework preenche essa cadeia de caracteres com o nome do arquivo de Ajuda do aplicativo.

```
CString m_strHelpFile;
```

##  <a name="m_strsource"></a>  COleDispatchException::m_strSource

O framework preenche essa cadeia de caracteres com o nome do aplicativo que gerou a exceção.

```
CString m_strSource;
```

### <a name="example"></a>Exemplo

  Veja o exemplo de [COleDispatchDriver::CreateDispatch](../../mfc/reference/coledispatchdriver-class.md#createdispatch).

##  <a name="m_wcode"></a>  COleDispatchException::m_wCode

Contém um código de erro específico para seu aplicativo.

```
WORD m_wCode;
```

### <a name="remarks"></a>Comentários

Este membro é definido pela função [AfxThrowOleDispatchException](exception-processing.md#afxthrowoledispatchexception) quando uma exceção é lançada.

## <a name="see-also"></a>Consulte também

[Exemplo MFC CALCDRIV](../../overview/visual-cpp-samples.md)<br/>
[Classe CException](../../mfc/reference/cexception-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDispatchDriver](../../mfc/reference/coledispatchdriver-class.md)<br/>
[Classe COleException](../../mfc/reference/coleexception-class.md)
