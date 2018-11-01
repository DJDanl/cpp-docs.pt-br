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
ms.openlocfilehash: 8fb5f7e2133f1055cde05b2dc1358896c9ea0c20
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50508284"
---
# <a name="csimpleexception-class"></a>Classe CSimpleException

Essa classe é uma classe base para exceções críticas para os recursos do MFC.

## <a name="syntax"></a>Sintaxe

```
class AFX_NOVTABLE CSimpleException : public CException
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSimpleException::CSimpleException](#csimpleexception)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSimpleException::GetErrorMessage](#geterrormessage)|Fornece o texto sobre o erro que ocorreu.|

## <a name="remarks"></a>Comentários

`CSimpleException` é a classe base para exceções críticas para os recursos do MFC e lida com a propriedade e a inicialização de uma mensagem de erro. As seguintes classes usam `CSimpleException` como classe base:

|||
|-|-|
|[Classe CMemoryException](../../mfc/reference/cmemoryexception-class.md)|Exceção de falta de memória|
|[Classe CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md)|Solicitações para uma operação sem suporte|
|[Classe CResourceException](../../mfc/reference/cresourceexception-class.md)|Recursos do Windows não foi encontrado ou não pode ser criado|
|[Classe CUserException](../../mfc/reference/cuserexception-class.md)|Não foi possível encontrar uma exceção que indica um recurso|
|[Classe CInvalidArgException](../../mfc/reference/cinvalidargexception-class.md)|Exceção que indica um argumento inválido|

Porque `CSimpleException` é uma classe base abstrata, você não pode declarar um `CSimpleException` diretamente do objeto. Em vez disso, você deve declarar objetos derivados, como aqueles na tabela anterior. Se você está declarando a sua própria classe derivada, use as classes anteriores como um modelo.

Para obter mais informações, consulte o [classe CException](../../mfc/reference/cexception-class.md) tópico e [tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CException](../../mfc/reference/cexception-class.md)

`CSimpleException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="csimpleexception"></a>  CSimpleException::CSimpleException

O construtor.

```
CSimpleException();
explicit CSimpleException(BOOL bAutoDelete);
```

### <a name="parameters"></a>Parâmetros

*bAutoDelete*<br/>
Especifique verdadeiro se a memória para o `CSimpleException` objeto foi alocado no heap. Isso fará com que o `CSimpleException` objeto a ser excluído quando o `Delete` função membro é chamada para excluir a exceção. Especifique FALSE se o `CSimpleException` objeto na pilha ou é um objeto global. Nesse caso, o `CSimpleException` não serão excluídos quando o `Delete` função membro é chamada.

### <a name="remarks"></a>Comentários

Você normalmente não precisa chamar esse construtor diretamente. Uma função que gera uma exceção deve criar uma instância de um `CException`-classe derivada e chama seu construtor, ou ele deve usar um do MFC lançar funções, como [AfxThrowFileException](exception-processing.md#afxthrowfileexception), gerem um tipo predefinido.

##  <a name="geterrormessage"></a>  CSimpleException::GetErrorMessage

Chame essa função de membro para fornecer um texto sobre o erro que ocorreu.

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
O número máximo de caracteres que o buffer pode conter, incluindo o terminador NULL.

*pnHelpContext*<br/>
O endereço de UINT que receberá a ID do contexto de Ajuda. Se for NULL, nenhuma ID será retornado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; Caso contrário, 0 se nenhum erro de texto da mensagem está disponível.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [CException::GetErrorMessage](../../mfc/reference/cfileexception-class.md#geterrormessage).

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CException](../../mfc/reference/cexception-class.md)<br/>
[Tratamento de Exceção](../../mfc/exception-handling-in-mfc.md)

