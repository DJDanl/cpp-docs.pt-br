---
title: Classe CSimpleException
ms.date: 11/04/2016
f1_keywords:
- CSimpleException
- AFX/CSimpleException
- AFX/CSimpleException::CSimpleException
- AFX/CSimpleException::GetErrorMessage
helpviewer_keywords:
- CSimpleException [MFC], CSimpleException
- CSimpleException [MFC], GetErrorMessage
ms.assetid: be0eb8ef-e5b9-47d6-b0fb-efaff2d1e666
ms.openlocfilehash: eb94ba9e3d26b3cd910f23c3d4abb29d3b8b1cd1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318357"
---
# <a name="csimpleexception-class"></a>Classe CSimpleException

Esta classe é uma classe base para exceções mfc críticas de recursos.

## <a name="syntax"></a>Sintaxe

```
class AFX_NOVTABLE CSimpleException : public CException
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSimpleException::CSimpleException](#csimpleexception)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSimpleException::GetErrorMessage](#geterrormessage)|Fornece texto sobre um erro ocorrido.|

## <a name="remarks"></a>Comentários

`CSimpleException`é a classe base para exceções mfc críticas de recursos e lida com a propriedade e inicialização de uma mensagem de erro. As seguintes `CSimpleException` classes usam como sua classe base:

|||
|-|-|
|[Classe CMemoryException](../../mfc/reference/cmemoryexception-class.md)|Exceção fora da memória|
|[Classe CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md)|Solicitações para uma operação sem suporte|
|[Classe CResourceException](../../mfc/reference/cresourceexception-class.md)|Recurso do Windows não encontrado ou não creatable|
|[Classe CUserException](../../mfc/reference/cuserexception-class.md)|Exceção que indica que um recurso não foi encontrado|
|[Classe CInvalidArgException](../../mfc/reference/cinvalidargexception-class.md)|Exceção que indica um argumento inválido|

Por `CSimpleException` ser uma classe base abstrata, você não pode declarar um `CSimpleException` objeto diretamente. Em vez disso, você deve declarar objetos derivados como os da tabela anterior. Se você está declarando sua própria classe derivada, use as classes anteriores como um modelo.

Para obter mais informações, consulte o tópico [CException Class](../../mfc/reference/cexception-class.md) e [o Exception Handling (MFC).](../../mfc/exception-handling-in-mfc.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cexception](../../mfc/reference/cexception-class.md)

`CSimpleException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="csimpleexceptioncsimpleexception"></a><a name="csimpleexception"></a>CSimpleException::CSimpleException

O construtor.

```
CSimpleException();
explicit CSimpleException(BOOL bAutoDelete);
```

### <a name="parameters"></a>Parâmetros

*bAutoDelete*<br/>
Especifique TRUE `CSimpleException` se a memória do objeto tiver sido alocada no heap. Isso fará `CSimpleException` com que o objeto `Delete` seja excluído quando a função membro for chamada para excluir a exceção. Especifique `CSimpleException` FALSO se o objeto estiver na pilha ou se for um objeto global. Neste caso, `CSimpleException` o objeto não será `Delete` excluído quando a função membro for chamada.

### <a name="remarks"></a>Comentários

Você normalmente nunca precisaria chamar este construtor diretamente. Uma função que lança uma exceção `CException`deve criar uma instância de uma classe derivada e chamar seu construtor, ou deve usar uma das funções de lançamento do MFC, como [AfxThrowFileException,](exception-processing.md#afxthrowfileexception)para lançar um tipo predefinido.

## <a name="csimpleexceptiongeterrormessage"></a><a name="geterrormessage"></a>CSimpleException::GetErrorMessage

Ligue para esta função de membro para fornecer texto sobre um erro ocorrido.

```
virtual BOOL GetErrorMessage(
    LPTSTR lpszError,
    UINT  nMaxError,
    PUNIT  pnHelpContext = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszError*<br/>
Um ponteiro para um buffer que receberá uma mensagem de erro.

*nMaxError*<br/>
O número máximo de caracteres que o buffer pode conter, incluindo o exterminador NULL.

*pnHelpContext*<br/>
O endereço de um UINT que receberá o ID do contexto de ajuda. Se NULO, nenhuma id será devolvida.

### <a name="return-value"></a>Valor retornado

Não zero se a função for bem sucedida; caso contrário 0 se nenhum texto de mensagem de erro estiver disponível.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [CException::GetErrorMessage](../../mfc/reference/cfileexception-class.md#geterrormessage).

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CException](../../mfc/reference/cexception-class.md)<br/>
[Tratamento de Exceção](../../mfc/exception-handling-in-mfc.md)
