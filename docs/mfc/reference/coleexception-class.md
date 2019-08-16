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
ms.openlocfilehash: 96061f704d9df6cd788e362652b6ed22a7ffa999
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69503944"
---
# <a name="coleexception-class"></a>Classe COleException

Representa uma condição de exceção relacionada a uma operação OLE.

## <a name="syntax"></a>Sintaxe

```
class COleException : public CException
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleException::Process](#process)|Traduz uma exceção capturada em um código de retorno OLE.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleException::m_sc](#m_sc)|Contém o código de status que indica o motivo da exceção.|

## <a name="remarks"></a>Comentários

A `COleException` classe inclui um membro de dados públicos que contém o código de status que indica o motivo da exceção.

Em geral, você não deve criar um `COleException` objeto diretamente; em vez disso, você deve chamar [AfxThrowOleException](exception-processing.md#afxthrowoleexception).

Para obter mais informações sobre exceções, consulte os artigos [tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md) e [exceções: Exceções](../../mfc/exceptions-ole-exceptions.md)OLE.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CException](../../mfc/reference/cexception-class.md)

`COleException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDISP. h

##  <a name="m_sc"></a>  COleException::m_sc

Esse membro de dados contém o código de status OLE que indica o motivo da exceção.

```
SCODE m_sc;
```

### <a name="remarks"></a>Comentários

O valor dessa variável é definido por [AfxThrowOleException](exception-processing.md#afxthrowoleexception).

Para obter mais informações sobre SCODE, consulte [estrutura de códigos de erro com](/windows/win32/com/structure-of-com-error-codes) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#22](../../mfc/codesnippet/cpp/coleexception-class_1.cpp)]

##  <a name="process"></a>  COleException::Process

Chame a função de membro **process** para converter uma exceção capturada em um código de status OLE.

```
static SCODE PASCAL Process(const CException* pAnyException);
```

### <a name="parameters"></a>Parâmetros

*pAnyException*<br/>
Ponteiro para uma exceção capturada.

### <a name="return-value"></a>Valor de retorno

Um código de status OLE.

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Essa função é **estática**.

Para obter mais informações sobre SCODE, consulte [estrutura de códigos de erro com](/windows/win32/com/structure-of-com-error-codes) no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [COleDispatchDriver:: createexpedição](../../mfc/reference/coledispatchdriver-class.md#createdispatch).

## <a name="see-also"></a>Consulte também

[Exemplo de CALCDRIV do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CException](../../mfc/reference/cexception-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
