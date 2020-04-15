---
title: Inicialização e término do mecanismo de banco de dados DAO
ms.date: 09/17/2019
helpviewer_keywords:
- DAO (Data Access Objects), termination
- DAO (Data Access Objects), initialization
ms.assetid: a7edf31c-e7c2-4f3e-aada-63c3e48781da
ms.openlocfilehash: 62460e8e55f70b8cb0743f1d044636d25121050d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365899"
---
# <a name="dao-database-engine-initialization-and-termination"></a>Inicialização e término do mecanismo de banco de dados DAO

O DAO é usado com bancos de dados access e é suportado através do Office 2013. DAO 3.6 é a versão final, e é considerada obsoleta. Ao usar objetos DaO do MFC, o mecanismo de banco de dados DAO deve primeiro ser inicializado e, em seguida, encerrado antes que seu aplicativo ou DLL desista. Duas `AfxDaoInit` funções, `AfxDaoTerm`e , executar essas tarefas.

### <a name="dao-database-engine-initialization-and-termination"></a>Inicialização e término do mecanismo de banco de dados DAO

|||
|-|-|
|[AfxDaoInit](#afxdaoinit)|Inicializa o mecanismo de banco de dados DAO.|
|[AfxDaoTerm](#afxdaoterm)|Termina o mecanismo de banco de dados DAO.|

## <a name="afxdaoinit"></a><a name="afxdaoinit"></a>Afxdaoinit

Esta função inicializa o mecanismo de banco de dados DAO.

```

void AfxDaoInit();

throw(CDaoException*);
```

### <a name="remarks"></a>Comentários

Na maioria dos casos, você `AfxDaoInit` não precisa ligar porque o aplicativo o chama automaticamente quando é necessário.

Para obter informações relacionadas e `AfxDaoInit`para um exemplo de chamada, consulte [Nota Técnica 54](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdao.h

## <a name="afxdaoterm"></a><a name="afxdaoterm"></a>Afxdaoterm

Esta função encerra o mecanismo de banco de dados DAO.

```

void AfxDaoTerm();
```

### <a name="remarks"></a>Comentários

Normalmente, você só precisa chamar essa função em uma DLL MFC regular; um aplicativo ligará `AfxDaoTerm` automaticamente quando for necessário.

Em DLLs MFC `AfxDaoTerm` regulares, ligue antes da `ExitInstance` função, mas depois de todos os objetos DaO MFC terem sido destruídos.

Para obter informações relacionadas, consulte [Nota Técnica 54](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdao.h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
