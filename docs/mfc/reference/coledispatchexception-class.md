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
ms.openlocfilehash: 4572b639b757569d8e3cfa731f99c123762f3900
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375059"
---
# <a name="coledispatchexception-class"></a>Classe COleDispatchException

Lida com exceções específicas `IDispatch` da interface OLE, que é uma parte fundamental da automação OLE.

## <a name="syntax"></a>Sintaxe

```
class COleDispatchException : public CException
```

## <a name="members"></a>Membros

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDispatchException::m_dwHelpContext](#m_dwhelpcontext)|Ajude o contexto para o erro.|
|[COleDispatchException::m_strDescription](#m_strdescription)|Descrição de erro verbal.|
|[COleDispatchException::m_strHelpFile](#m_strhelpfile)|Arquivo de ajuda `m_dwHelpContext`para usar com .|
|[COleDispatchException::m_strSource](#m_strsource)|Aplicativo que gerou a exceção.|
|[COleDispatchException::m_wCode](#m_wcode)|`IDispatch`- código de erro específico.|

## <a name="remarks"></a>Comentários

Como as outras classes `CException` de exceção derivadas da classe base, `COleDispatchException` pode ser usado com as macros THROW, THROW_LAST, TRY, CATCH, AND_CATCH e END_CATCH.

Em geral, você deve chamar [AfxThrowOleDispatchException](exception-processing.md#afxthrowoledispatchexception) para criar e lançar um `COleDispatchException` objeto.

Para obter mais informações sobre exceções, consulte os artigos [Manipulação de Exceções (MFC)](../../mfc/exception-handling-in-mfc.md) e [Exceções: Exceções oLE](../../mfc/exceptions-ole-exceptions.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cexception](../../mfc/reference/cexception-class.md)

`COleDispatchException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="coledispatchexceptionm_dwhelpcontext"></a><a name="m_dwhelpcontext"></a>COleDispatchException::m_dwHelpContext

Identifica um contexto de ajuda na ajuda do seu aplicativo (. Arquivo HLP)

```
DWORD m_dwHelpContext;
```

### <a name="remarks"></a>Comentários

Este membro é definido pela função [AfxThrowOleDispatchException](exception-processing.md#afxthrowoledispatchexception) quando uma exceção é lançada.

### <a name="example"></a>Exemplo

  Veja o exemplo de [COleDispatchDriver::CreateDispatch](../../mfc/reference/coledispatchdriver-class.md#createdispatch).

## <a name="coledispatchexceptionm_strdescription"></a><a name="m_strdescription"></a>COleDispatchException::m_strDescription

Contém uma descrição de erro verbal, como "Disco cheio".

```
CString m_strDescription;
```

### <a name="remarks"></a>Comentários

Este membro é definido pela função [AfxThrowOleDispatchException](exception-processing.md#afxthrowoledispatchexception) quando uma exceção é lançada.

### <a name="example"></a>Exemplo

  Veja o exemplo de [COleDispatchDriver::CreateDispatch](../../mfc/reference/coledispatchdriver-class.md#createdispatch).

## <a name="coledispatchexceptionm_strhelpfile"></a><a name="m_strhelpfile"></a>COleDispatchException::m_strHelpFile

A estrutura preenche esta seqüência com o nome do arquivo de ajuda do aplicativo.

```
CString m_strHelpFile;
```

## <a name="coledispatchexceptionm_strsource"></a><a name="m_strsource"></a>COleDispatchException::m_strSource

O framework preenche essa seqüência com o nome do aplicativo que gerou a exceção.

```
CString m_strSource;
```

### <a name="example"></a>Exemplo

  Veja o exemplo de [COleDispatchDriver::CreateDispatch](../../mfc/reference/coledispatchdriver-class.md#createdispatch).

## <a name="coledispatchexceptionm_wcode"></a><a name="m_wcode"></a>COleDispatchException::m_wCode

Contém um código de erro específico para o seu aplicativo.

```
WORD m_wCode;
```

### <a name="remarks"></a>Comentários

Este membro é definido pela função [AfxThrowOleDispatchException](exception-processing.md#afxthrowoledispatchexception) quando uma exceção é lançada.

## <a name="see-also"></a>Confira também

[Amostra de MFC CALCDRIV](../../overview/visual-cpp-samples.md)<br/>
[Classe CException](../../mfc/reference/cexception-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDispatchDriver](../../mfc/reference/coledispatchdriver-class.md)<br/>
[Classe COleException](../../mfc/reference/coleexception-class.md)
