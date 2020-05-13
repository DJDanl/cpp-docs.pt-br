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
ms.openlocfilehash: 737c9e669990f4de6ae18cdc7662c131ad61516f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375009"
---
# <a name="coleexception-class"></a>Classe COleException

Representa uma condição de exceção relacionada a uma operação oLE.

## <a name="syntax"></a>Sintaxe

```
class COleException : public CException
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleException::Process](#process)|Traduz uma exceção capturada em um código de retorno OLE.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleException::m_sc](#m_sc)|Contém o código de status que indica a razão da exceção.|

## <a name="remarks"></a>Comentários

A `COleException` classe inclui um membro de dados públicos que detém o código de status indicando o motivo da exceção.

Em geral, você não `COleException` deve criar um objeto diretamente; em vez disso, você deve chamar [AfxThrowOleException](exception-processing.md#afxthrowoleexception).

Para obter mais informações sobre exceções, consulte os artigos [Manipulação de Exceções (MFC)](../../mfc/exception-handling-in-mfc.md) e [Exceções: Exceções oLE](../../mfc/exceptions-ole-exceptions.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cexception](../../mfc/reference/cexception-class.md)

`COleException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="coleexceptionm_sc"></a><a name="m_sc"></a>COleException::m_sc

Este membro de dados contém o código de status OLE que indica a razão da exceção.

```
SCODE m_sc;
```

### <a name="remarks"></a>Comentários

O valor dessa variável é definido por [AfxThrowOleException](exception-processing.md#afxthrowoleexception).

Para obter mais informações sobre o SCODE, consulte [Estrutura de Códigos de erro COM](/windows/win32/com/structure-of-com-error-codes) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#22](../../mfc/codesnippet/cpp/coleexception-class_1.cpp)]

## <a name="coleexceptionprocess"></a><a name="process"></a>COleException::Process

Ligue para a função de membro **do Processo** para traduzir uma exceção capturada em um código de status OLE.

```
static SCODE PASCAL Process(const CException* pAnyException);
```

### <a name="parameters"></a>Parâmetros

*pAnyException*<br/>
Ponteiro para uma exceção capturada.

### <a name="return-value"></a>Valor retornado

Um código de status OLE.

### <a name="remarks"></a>Comentários

> [!NOTE]
> Esta função é **estática.**

Para obter mais informações sobre o SCODE, consulte [Estrutura de Códigos de erro COM](/windows/win32/com/structure-of-com-error-codes) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [COleDispatchDriver::CreateDispatch](../../mfc/reference/coledispatchdriver-class.md#createdispatch).

## <a name="see-also"></a>Confira também

[Amostra de MFC CALCDRIV](../../overview/visual-cpp-samples.md)<br/>
[Classe CException](../../mfc/reference/cexception-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
