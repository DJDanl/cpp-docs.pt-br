---
title: Classe CUserException
ms.date: 11/04/2016
f1_keywords:
- CUserException
helpviewer_keywords:
- operations [MFC], stopping
- exceptions [MFC], throwing
- CUserException class [MFC]
- errors [MFC], trapping
- operations [MFC]
- throwing exceptions [MFC], stopping user operations
ms.assetid: 2156ba6d-2cce-415a-9000-6f02c26fcd7d
ms.openlocfilehash: 72d8537616792859a2b00a1a5cd880ce5eb452bf
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62323431"
---
# <a name="cuserexception-class"></a>Classe CUserException

Lançada para parar uma operação do usuário final.

## <a name="syntax"></a>Sintaxe

```
class CUserException : public CSimpleException
```

## <a name="remarks"></a>Comentários

Use `CUserException` quando você quiser usar o mecanismo de exceção throw/catch para exceções específicas do aplicativo. "Usuário" no nome da classe pode ser interpretado como "Meu usuário fez algo excepcionais que eu preciso lidar com".

Um `CUserException` geralmente é lançada após chamar a função global `AfxMessageBox` para notificar o usuário que uma operação falhou. Quando você escreve um manipulador de exceção, tratar a exceção, especialmente, pois o usuário geralmente já foi notificado da falha. A estrutura gera esta exceção em alguns casos. Para lançar uma `CUserException` por conta própria, alertar o usuário e, em seguida, chame a função global `AfxThrowUserException`.

No exemplo a seguir, uma função que contém operações poderão falhar alertará o usuário e gera um `CUserException`. A função de chamada captura a exceção e lida com isso especialmente:

[!code-cpp[NVC_MFCExceptions#24](../../mfc/codesnippet/cpp/cuserexception-class_1.cpp)]

Para obter mais informações sobre como usar `CUserException`, consulte o artigo [tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CException](../../mfc/reference/cexception-class.md)

[CSimpleException](../../mfc/reference/csimpleexception-class.md)

`CUserException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CException](../../mfc/reference/cexception-class.md)
