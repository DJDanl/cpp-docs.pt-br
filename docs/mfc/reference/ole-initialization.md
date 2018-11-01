---
title: Inicialização OLE
ms.date: 11/04/2016
f1_keywords:
- afxdisp/AfxOleInit
- afxdisp/AfxEnableControlContainer
helpviewer_keywords:
- OLE initialization
ms.assetid: aa8a54a7-24c3-4344-b2c6-dbcf6084fa31
ms.openlocfilehash: c935dbf88b3c70cdd9ec585685bf6231ded01dde
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50623321"
---
# <a name="ole-initialization"></a>Inicialização OLE

Antes de um aplicativo pode usar os serviços do sistema OLE, ele deve inicializar as DLLs do sistema OLE e verifique se as DLLs são a versão correta. O `AfxOleInit` função inicializa as DLLs do sistema OLE.

### <a name="ole-initialization"></a>Inicialização OLE

|||
|-|-|
|[AfxOleInit](#afxoleinit)|Inicializa as bibliotecas OLE.|
|[AfxEnableControlContainer](#afxenablecontrolcontainer)|Chame essa função em seu objeto de aplicativo `InitInstance` função para habilitar o suporte de confinamento de controles OLE.|

## <a name="afxenablecontrolcontainer"></a> AfxEnableControlContainer

Chame essa função em seu objeto de aplicativo `InitInstance` função para habilitar o suporte de confinamento de controles OLE.

### <a name="syntax"></a>Sintaxe

```
void AfxEnableControlContainer( );
```

### <a name="remarks"></a>Comentários

Para obter mais informações sobre controles OLE (agora chamado de controles ActiveX), consulte [tópicos de controle ActiveX](../mfc-activex-controls.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

##  <a name="afxoleinit"></a>  AfxOleInit

Inicializa o suporte do OLE para o aplicativo.

```
BOOL AFXAPI AfxOleInit();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; 0 se a inicialização falhar, possivelmente porque versões incorretas das DLLs do sistema OLE estão instaladas.

### <a name="remarks"></a>Comentários

Chame essa função para inicializar o suporte OLE para um aplicativo do MFC. Quando essa função é chamada, ocorrem as seguintes ações:

- Inicializa a biblioteca COM no apartment atual do aplicativo de chamada. Para obter mais informações, consulte [OleInitialize](/windows/desktop/api/ole2/nf-ole2-oleinitialize).

- Cria um objeto de filtro de mensagem, Implementando a [IMessageFilter](/windows/desktop/api/objidl/nn-objidl-imessagefilter) interface. Esse filtro de mensagem pode ser acessado com uma chamada para [AfxOleGetMessageFilter](application-control.md#afxolegetmessagefilter).

> [!NOTE]
>  Se **AfxOleInit** é chamado de uma DLL do MFC, a chamada falhará. A falha ocorre porque a função pressupõe que, se ele é chamado de uma DLL, o sistema OLE foi inicializado anteriormente pelo aplicativo de chamada.

> [!NOTE]
>  Aplicativos MFC devem ser inicializados como um compartimento de único thread (STA). Se você chamar [CoInitializeEx](/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) em seu `InitInstance` substituir, especifique COINIT_APARTMENTTHREADED (em vez de COINIT_MULTITHREADED).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="see-also"></a>Consulte também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
