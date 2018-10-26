---
title: Classe COleException | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- COleException
- AFXDISP/COleException
- AFXDISP/COleException::Process
- AFXDISP/COleException::m_sc
dev_langs:
- C++
helpviewer_keywords:
- COleException [MFC], Process
- COleException [MFC], m_sc
ms.assetid: 2571e9fe-26cc-42f0-9ad9-8ad5b4311ec1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2705a1889e7b9c9c0960cce45b8dc7b411e16982
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50060996"
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
|[COleException::Process](#process)|Converte uma exceção capturada em um código de retorno OLE.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleException::m_sc](#m_sc)|Contém o código de status que indica o motivo da exceção.|

## <a name="remarks"></a>Comentários

O `COleException` classe inclui um membro de dados pública que contém o código de status que indica o motivo da exceção.

Em geral, você não deve criar uma `COleException` do objeto diretamente; em vez disso, você deve chamar [AfxThrowOleException](exception-processing.md#afxthrowoleexception).

Para obter mais informações sobre exceções, consulte os artigos [tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md) e [exceções: exceções OLE](../../mfc/exceptions-ole-exceptions.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CException](../../mfc/reference/cexception-class.md)

`COleException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

##  <a name="m_sc"></a>  COleException::m_sc

Este membro de dados contém o código de status OLE que indica o motivo da exceção.

```
SCODE m_sc;
```

### <a name="remarks"></a>Comentários

O valor da variável é definido por [AfxThrowOleException](exception-processing.md#afxthrowoleexception).

Para obter mais informações sobre SCODE, consulte [estrutura de códigos de erro COM](/windows/desktop/com/structure-of-com-error-codes) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#22](../../mfc/codesnippet/cpp/coleexception-class_1.cpp)]

##  <a name="process"></a>  COleException::Process

Chame o **processo** função de membro para converter uma exceção capturada em um código de status OLE.

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
>  Essa função é **estático**.

Para obter mais informações sobre SCODE, consulte [estrutura de códigos de erro COM](/windows/desktop/com/structure-of-com-error-codes) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [COleDispatchDriver::CreateDispatch](../../mfc/reference/coledispatchdriver-class.md#createdispatch).

## <a name="see-also"></a>Consulte também

[Exemplo MFC CALCDRIV](../../visual-cpp-samples.md)<br/>
[Classe CException](../../mfc/reference/cexception-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

