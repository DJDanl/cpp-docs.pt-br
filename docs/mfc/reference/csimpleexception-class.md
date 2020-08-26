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
ms.openlocfilehash: afd83c1ddd6f68b10c5cc8c47c0e939bbd01b6c2
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88840707"
---
# <a name="csimpleexception-class"></a>Classe CSimpleException

Essa classe é uma classe base para exceções do MFC de recursos críticos.

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
|[CSimpleException:: GetErrorMessage](#geterrormessage)|Fornece um texto sobre um erro que ocorreu.|

## <a name="remarks"></a>Comentários

`CSimpleException` é a classe base para exceções do MFC de recursos críticos e manipula a propriedade e a inicialização de uma mensagem de erro. As classes a seguir usam `CSimpleException` como sua classe base:

|Nome|Descrição|
|-|-|
|[Classe CMemoryException](../../mfc/reference/cmemoryexception-class.md)|Exceção de memória insuficiente|
|[Classe CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md)|Solicitações para uma operação sem suporte|
|[Classe CResourceException](../../mfc/reference/cresourceexception-class.md)|Recurso do Windows não encontrado ou não creatable|
|[Classe CUserException](../../mfc/reference/cuserexception-class.md)|Exceção que indica que um recurso não pôde ser encontrado|
|[Classe CInvalidArgException](../../mfc/reference/cinvalidargexception-class.md)|Exceção que indica um argumento inválido|

Como `CSimpleException` é uma classe base abstrata, você não pode declarar um `CSimpleException` objeto diretamente. Em vez disso, você deve declarar objetos derivados como os da tabela anterior. Se você estiver declarando sua própria classe derivada, use as classes anteriores como um modelo.

Para obter mais informações, consulte o tópico de [classe CException](../../mfc/reference/cexception-class.md) e a [manipulação de exceção (MFC)](../../mfc/exception-handling-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CException](../../mfc/reference/cexception-class.md)

`CSimpleException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="csimpleexceptioncsimpleexception"></a><a name="csimpleexception"></a> CSimpleException::CSimpleException

O construtor.

```
CSimpleException();
explicit CSimpleException(BOOL bAutoDelete);
```

### <a name="parameters"></a>parâmetros

*bAutoDelete*<br/>
Especifique TRUE se a memória do `CSimpleException` objeto tiver sido alocada no heap. Isso fará com que o `CSimpleException` objeto seja excluído quando a `Delete` função de membro for chamada para excluir a exceção. Especifique FALSE se o `CSimpleException` objeto estiver na pilha ou for um objeto global. Nesse caso, o `CSimpleException` objeto não será excluído quando a função de `Delete` membro for chamada.

### <a name="remarks"></a>Comentários

Normalmente, você nunca precisaria chamar esse construtor diretamente. Uma função que gera uma exceção deve criar uma instância de uma `CException` classe derivada e chamar seu construtor, ou deve usar uma das funções de geração do MFC, como [AfxThrowFileException](exception-processing.md#afxthrowfileexception), para gerar um tipo predefinido.

## <a name="csimpleexceptiongeterrormessage"></a><a name="geterrormessage"></a> CSimpleException:: GetErrorMessage

Chame essa função de membro para fornecer texto sobre um erro que ocorreu.

```
virtual BOOL GetErrorMessage(
    LPTSTR lpszError,
    UINT  nMaxError,
    PUNIT  pnHelpContext = NULL);
```

### <a name="parameters"></a>parâmetros

*lpszError*<br/>
Um ponteiro para um buffer que receberá uma mensagem de erro.

*nMaxError*<br/>
O número máximo de caracteres que o buffer pode conter, incluindo o terminador nulo.

*pnHelpContext*<br/>
O endereço de um UINT que receberá a ID de contexto da ajuda. Se NULL, nenhuma ID será retornada.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0 se nenhum texto de mensagem de erro estiver disponível.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [CException:: GetErrorMessage](../../mfc/reference/cfileexception-class.md#geterrormessage).

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CException](../../mfc/reference/cexception-class.md)<br/>
[Tratamento de Exceção](../../mfc/exception-handling-in-mfc.md)
