---
title: Inicialização e término do mecanismo de banco de dados DAO
ms.date: 11/04/2016
f1_keywords:
- vc.mfc.macros.data
helpviewer_keywords:
- DAO (Data Access Objects), termination
- DAO (Data Access Objects), initialization
ms.assetid: a7edf31c-e7c2-4f3e-aada-63c3e48781da
ms.openlocfilehash: ff924f0e0d599d447ef7dea0039de788d388d759
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50589625"
---
# <a name="dao-database-engine-initialization-and-termination"></a>Inicialização e término do mecanismo de banco de dados DAO

Ao usar objetos MFC DAO, o mecanismo de banco de dados DAO deve primeiro ser inicializado e, em seguida, encerrado antes de seu aplicativo ou DLL é fechado. Duas funções, `AfxDaoInit` e `AfxDaoTerm`, executar essas tarefas.

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

Na maioria dos casos, você não precisa chamar `AfxDaoInit` porque o aplicativo automaticamente chama quando for necessário.

Para obter informações relacionadas e para obter um exemplo de chamada `AfxDaoInit`, consulte [54 de observação técnica](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdao.h

##  <a name="afxdaoterm"></a>  AfxDaoTerm

Essa função encerra o mecanismo de banco de dados DAO.

```

void AfxDaoTerm();
```

### <a name="remarks"></a>Comentários

Normalmente, você só precisa chamar essa função em uma DLL do MFC; regular um aplicativo chamará automaticamente `AfxDaoTerm` quando ela for necessária.

Em DLLs MFC regulares, chame `AfxDaoTerm` antes do `ExitInstance` função, mas depois que todos os objetos de MFC DAO tenham sido destruídos.

Para obter informações relacionadas, consulte [54 de observação técnica](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdao.h

## <a name="see-also"></a>Consulte também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
