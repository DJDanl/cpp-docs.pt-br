---
title: Inicialização OLE
ms.date: 11/04/2016
f1_keywords:
- afxdisp/AfxOleInit
- afxdisp/AfxEnableControlContainer
helpviewer_keywords:
- OLE initialization
ms.assetid: aa8a54a7-24c3-4344-b2c6-dbcf6084fa31
ms.openlocfilehash: 39a6f28bfe38f254f15f441ed6305daa2cb5793e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373028"
---
# <a name="ole-initialization"></a>Inicialização OLE

Antes que um aplicativo possa usar os serviços do sistema OLE, ele deve inicializar os DLLs do sistema OLE e verificar se os DLLs são a versão correta. A `AfxOleInit` função inicializa as DLLs do sistema OLE.

### <a name="ole-initialization"></a>Inicialização OLE

|||
|-|-|
|[AfxOleInit](#afxoleinit)|Inicializa as bibliotecas OLE.|
|[AfxEnableControlContainer](#afxenablecontrolcontainer)|Chame esta função na função `InitInstance` do objeto de aplicação para permitir o suporte para a contenção de controles OLE.|

## <a name="afxenablecontrolcontainer"></a><a name="afxenablecontrolcontainer"></a>AfxEnableControlContainer

Chame esta função na função `InitInstance` do objeto de aplicação para permitir o suporte para a contenção de controles OLE.

### <a name="syntax"></a>Sintaxe

```
void AfxEnableControlContainer( );
```

### <a name="remarks"></a>Comentários

Para obter mais informações sobre os controles OLE (agora chamados de controles ActiveX), consulte [ActiveX Control Topics](../mfc-activex-controls.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="afxoleinit"></a><a name="afxoleinit"></a>Afxoleinit

Inicializa o suporte ao OLE para a aplicação.

```
BOOL AFXAPI AfxOleInit();
```

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; 0 se a inicialização falhar, possivelmente porque versões incorretas dos DLLs do sistema OLE são instaladas.

### <a name="remarks"></a>Comentários

Chame esta função para inicializar o suporte ao OLE para um aplicativo MFC. Quando essa função é chamada, ocorrem as seguintes ações:

- Inicializa a biblioteca COM no apartamento atual do aplicativo de chamada. Para obter mais informações, consulte [OleInitialize](/windows/win32/api/ole2/nf-ole2-oleinitialize).

- Cria um objeto de filtro de mensagem, implementando a interface [IMessageFilter.](/windows/win32/api/objidl/nn-objidl-imessagefilter) Este filtro de mensagem pode ser acessado com uma chamada para [AfxOleGetMessageFilter](application-control.md#afxolegetmessagefilter).

> [!NOTE]
> Se **a AfxOleInit** for chamada de um DLL Do MFC, a chamada falhará. A falha ocorre porque a função assume que, se for chamada de dLL, o sistema OLE foi previamente inicializado pelo aplicativo de chamada.

> [!NOTE]
> As aplicações MFC devem ser inicializadas como apartamento com rosca única (STA). Se você chamar [CoInitializeEx](/windows/win32/api/combaseapi/nf-combaseapi-coinitializeex) em sua `InitInstance` substituição, especifique COINIT_APARTMENTTHREADED (em vez de COINIT_MULTITHREADED).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
