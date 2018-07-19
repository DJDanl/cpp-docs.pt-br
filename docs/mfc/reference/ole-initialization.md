---
title: Inicialização OLE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- afxdisp/AfxOleInit
- afxdisp/AfxEnableControlContainer
dev_langs:
- C++
helpviewer_keywords:
- OLE initialization
ms.assetid: aa8a54a7-24c3-4344-b2c6-dbcf6084fa31
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 330701c4fcc75d40e782d25baa55044b88852f50
ms.sourcegitcommit: 6408139d5f5ff8928f056bde93d20eecb3520361
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/02/2018
ms.locfileid: "37337785"
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
  
-   Inicializa a biblioteca COM no apartment atual do aplicativo de chamada. Para obter mais informações, consulte [OleInitialize](http://msdn.microsoft.com/library/windows/desktop/ms690134).  
  
-   Cria um objeto de filtro de mensagem, Implementando a [IMessageFilter](http://msdn.microsoft.com/library/windows/desktop/ms693740) interface. Esse filtro de mensagem pode ser acessado com uma chamada para [AfxOleGetMessageFilter](application-control.md#afxolegetmessagefilter).  
  
> [!NOTE]
>  Se **AfxOleInit** é chamado de uma DLL do MFC, a chamada falhará. A falha ocorre porque a função pressupõe que, se ele é chamado de uma DLL, o sistema OLE foi inicializado anteriormente pelo aplicativo de chamada.  
  
> [!NOTE]
>  Aplicativos MFC devem ser inicializados como um compartimento de único thread (STA). Se você chamar [CoInitializeEx](http://msdn.microsoft.com/library/windows/desktop/ms695279) em seu `InitInstance` substituir, especifique COINIT_APARTMENTTHREADED (em vez de COINIT_MULTITHREADED). Para obter mais informações, consulte PRB: aplicativo do MFC para de responder quando você inicializar o aplicativo como um Multi-Threaded Apartment (828643) em [ http://support.microsoft.com/default.aspxscid=kb; en-us; 828643](http://support.microsoft.com/default.aspxscid=kb;en-us;828643).  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h

## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
