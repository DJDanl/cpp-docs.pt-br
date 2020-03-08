---
title: Inicialização OLE
ms.date: 11/04/2016
f1_keywords:
- afxdisp/AfxOleInit
- afxdisp/AfxEnableControlContainer
helpviewer_keywords:
- OLE initialization
ms.assetid: aa8a54a7-24c3-4344-b2c6-dbcf6084fa31
ms.openlocfilehash: 6860697dd3adbe26197dd9075e84f402029e00a5
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78855678"
---
# <a name="ole-initialization"></a>Inicialização OLE

Antes que um aplicativo possa usar os serviços do sistema OLE, ele deve inicializar as DLLs do sistema OLE e verificar se as DLLs são a versão correta. A função `AfxOleInit` inicializa as DLLs do sistema OLE.

### <a name="ole-initialization"></a>Inicialização OLE

|||
|-|-|
|[AfxOleInit](#afxoleinit)|Inicializa as bibliotecas OLE.|
|[AfxEnableControlContainer](#afxenablecontrolcontainer)|Chame essa função na função `InitInstance` do seu objeto de aplicativo para habilitar o suporte para a contenção de controles OLE.|

## <a name="afxenablecontrolcontainer"></a>AfxEnableControlContainer

Chame essa função na função `InitInstance` do seu objeto de aplicativo para habilitar o suporte para a contenção de controles OLE.

### <a name="syntax"></a>Sintaxe

```
void AfxEnableControlContainer( );
```

### <a name="remarks"></a>Comentários

Para obter mais informações sobre controles OLE (agora chamados de controles ActiveX), consulte [Tópicos do controle ActiveX](../mfc-activex-controls.md).

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** AFXDISP. h

##  <a name="afxoleinit"></a>AfxOleInit

Inicializa o suporte a OLE para o aplicativo.

```
BOOL AFXAPI AfxOleInit();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; 0 se a inicialização falhar, possivelmente porque versões incorretas das DLLs do sistema OLE estão instaladas.

### <a name="remarks"></a>Comentários

Chame essa função para inicializar o suporte a OLE para um aplicativo MFC. Quando essa função é chamada, ocorrem as seguintes ações:

- Inicializa a biblioteca COM no apartamento atual do aplicativo de chamada. Para obter mais informações, consulte [OleInitialize](/windows/win32/api/ole2/nf-ole2-oleinitialize).

- Cria um objeto de filtro de mensagem, implementando a interface [IMessageFilter](/windows/win32/api/objidl/nn-objidl-imessagefilter) . Esse filtro de mensagem pode ser acessado com uma chamada para [AfxOleGetMessageFilter](application-control.md#afxolegetmessagefilter).

> [!NOTE]
>  Se **AfxOleInit** for chamado de uma DLL do MFC, a chamada falhará. A falha ocorre porque a função pressupõe que, se for chamada de uma DLL, o sistema OLE foi inicializado anteriormente pelo aplicativo de chamada.

> [!NOTE]
>  Os aplicativos MFC devem ser inicializados como STA (single-threaded apartment). Se você chamar [CoInitializeEx](/windows/win32/api/combaseapi/nf-combaseapi-coinitializeex) em sua substituição de `InitInstance`, especifique COINIT_APARTMENTTHREADED (em vez de COINIT_MULTITHREADED).

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** AFXDISP. h

## <a name="see-also"></a>Consulte também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
