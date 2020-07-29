---
title: Classe COleException
ms.date: 11/04/2016
f1_keywords:
- COleException
- AFXDISP/COleException
- AFXDISP/COleException::Process
- AFXDISP/COleException::m_sc
helpviewer_keywords:
- COleException [MFC], Process
- COleException [MFC], m_sc
ms.assetid: 2571e9fe-26cc-42f0-9ad9-8ad5b4311ec1
ms.openlocfilehash: c82099d816bc8ee8c179e9d4656f474156a629a9
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233191"
---
# <a name="coleexception-class"></a>Classe COleException

Representa uma condição de exceção relacionada a uma operação OLE.

## <a name="syntax"></a>Sintaxe

```
class COleException : public CException
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleException::P modelos](#process)|Traduz uma exceção capturada em um código de retorno OLE.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleException:: m_sc](#m_sc)|Contém o código de status que indica o motivo da exceção.|

## <a name="remarks"></a>Comentários

A `COleException` classe inclui um membro de dados públicos que contém o código de status que indica o motivo da exceção.

Em geral, você não deve criar um `COleException` objeto diretamente; em vez disso, você deve chamar [AfxThrowOleException](exception-processing.md#afxthrowoleexception).

Para obter mais informações sobre exceções, consulte os artigos [tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md) e [exceções: exceções OLE](../../mfc/exceptions-ole-exceptions.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CException](../../mfc/reference/cexception-class.md)

`COleException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDISP. h

## <a name="coleexceptionm_sc"></a><a name="m_sc"></a>COleException:: m_sc

Esse membro de dados contém o código de status OLE que indica o motivo da exceção.

```
SCODE m_sc;
```

### <a name="remarks"></a>Comentários

O valor dessa variável é definido por [AfxThrowOleException](exception-processing.md#afxthrowoleexception).

Para obter mais informações sobre SCODE, consulte [estrutura de códigos de erro com](/windows/win32/com/structure-of-com-error-codes) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#22](../../mfc/codesnippet/cpp/coleexception-class_1.cpp)]

## <a name="coleexceptionprocess"></a><a name="process"></a>COleException::P modelos

Chame a função de membro **process** para converter uma exceção capturada em um código de status OLE.

```
static SCODE PASCAL Process(const CException* pAnyException);
```

### <a name="parameters"></a>parâmetros

*pAnyException*<br/>
Ponteiro para uma exceção capturada.

### <a name="return-value"></a>Valor retornado

Um código de status OLE.

### <a name="remarks"></a>Comentários

> [!NOTE]
> Essa função é **`static`** .

Para obter mais informações sobre SCODE, consulte [estrutura de códigos de erro com](/windows/win32/com/structure-of-com-error-codes) no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [COleDispatchDriver:: createexpedição](../../mfc/reference/coledispatchdriver-class.md#createdispatch).

## <a name="see-also"></a>Confira também

[Exemplo de CALCDRIV do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CException](../../mfc/reference/cexception-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)
