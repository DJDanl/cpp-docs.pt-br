---
title: Inicialização e término do mecanismo de banco de dados DAO
ms.date: 09/17/2019
helpviewer_keywords:
- DAO (Data Access Objects), termination
- DAO (Data Access Objects), initialization
ms.assetid: a7edf31c-e7c2-4f3e-aada-63c3e48781da
ms.openlocfilehash: 24a24d5a81da18d01472fc760c2adf96ee9868d5
ms.sourcegitcommit: 069e3833bd821e7d64f5c98d0ea41fc0c5d22e53
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/21/2019
ms.locfileid: "74303467"
---
# <a name="dao-database-engine-initialization-and-termination"></a>Inicialização e término do mecanismo de banco de dados DAO

O DAO é usado com bancos de dados do Access e tem suporte por meio do Office 2013. O DAO 3,6 é a versão final e é considerado obsoleto. Ao usar objetos DAO do MFC, o mecanismo de banco de dados DAO deve primeiro ser inicializado e, em seguida, encerrado antes do encerramento do aplicativo ou da DLL. Duas funções, `AfxDaoInit` e `AfxDaoTerm`, executam essas tarefas.

### <a name="dao-database-engine-initialization-and-termination"></a>Inicialização e término do mecanismo de banco de dados DAO

|||
|-|-|
|[AfxDaoInit](#afxdaoinit)|Inicializa o mecanismo de banco de dados DAO.|
|[AfxDaoTerm](#afxdaoterm)|Encerra o mecanismo de banco de dados DAO.|

##  <a name="afxdaoinit"></a>  AfxDaoInit

Essa função inicializa o mecanismo de banco de dados DAO.

```

void AfxDaoInit();

throw(CDaoException*);
```

### <a name="remarks"></a>Comentários

Na maioria dos casos, você não precisa chamar `AfxDaoInit` porque o aplicativo o chama automaticamente quando é necessário.

Para obter informações relacionadas, e para obter um exemplo de como chamar `AfxDaoInit`, consulte a [Nota técnica 54](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDAO. h

##  <a name="afxdaoterm"></a>  AfxDaoTerm

Essa função encerra o mecanismo de banco de dados DAO.

```

void AfxDaoTerm();
```

### <a name="remarks"></a>Comentários

Normalmente, você só precisa chamar essa função em uma DLL do MFC regular; um aplicativo chamará automaticamente `AfxDaoTerm` quando for necessário.

Em DLLs comuns do MFC, chame `AfxDaoTerm` antes da função `ExitInstance`, mas depois que todos os objetos DAO do MFC tiverem sido destruídos.

Para obter informações relacionadas, consulte a [Nota técnica 54](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDAO. h

## <a name="see-also"></a>Consulte também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
