---
title: "Inicialização OLE | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.macros.ole
dev_langs:
- C++
helpviewer_keywords:
- OLE initialization
ms.assetid: aa8a54a7-24c3-4344-b2c6-dbcf6084fa31
caps.latest.revision: 13
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 17a158366f94d27b7a46917282425d652e6b9042
ms.openlocfilehash: 5c2d8a1552b8cd546b7e22683fe9f73bbc54df5c
ms.lasthandoff: 02/25/2017

---
# <a name="ole-initialization"></a>Inicialização OLE
Antes de um aplicativo pode usar os serviços do sistema OLE, ele deve inicializar as DLLs do sistema OLE e verifique se as DLLs são a versão correta. O **AfxOleInit** função inicializa as DLLs do sistema OLE.  
  
### <a name="ole-initialization"></a>Inicialização OLE  
  
|||  
|-|-|  
|[AfxOleInit](#afxoleinit)|Inicializa as bibliotecas OLE.|  
  
##  <a name="a-nameafxoleinita--afxoleinit"></a><a name="afxoleinit"></a>AfxOleInit  
 Inicializa o suporte OLE para o aplicativo.  
  
``` 
BOOL AFXAPI AfxOleInit(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; 0 se a inicialização falhar, possivelmente porque versões incorretas das DLLs do sistema OLE estão instaladas.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para inicializar o suporte OLE para um aplicativo MFC. Quando essa função é chamada, ocorrem as seguintes ações:  
  
-   Inicializa a biblioteca COM no apartment atual do aplicativo de chamada. Para obter mais informações, consulte [OleInitialize](http://msdn.microsoft.com/library/windows/desktop/ms690134).  
  
-   Cria um objeto de filtro de mensagem, Implementando o [IMessageFilter](http://msdn.microsoft.com/library/windows/desktop/ms693740) interface. Esse filtro de mensagem pode ser acessado com uma chamada para [AfxOleGetMessageFilter](http://msdn.microsoft.com/library/36cca011-4775-4086-b471-5557a87b266c).  
  
> [!NOTE]
>  Se **AfxOleInit** é chamado de uma DLL do MFC, a chamada falhará. A falha ocorre porque a função assumirá que, se ele é chamado de uma DLL, o sistema OLE anteriormente foi inicializado pelo aplicativo de chamada.  
  
> [!NOTE]
>  Aplicativos MFC devem ser inicializados como compartimento de único thread (STA). Se você chamar [CoInitializeEx](http://msdn.microsoft.com/library/windows/desktop/ms695279) em seu `InitInstance` substituir, especifique `COINIT_APARTMENTTHREADED` (em vez de `COINIT_MULTITHREADED`). Para obter mais informações, consulte PRB: aplicativo MFC para de responder quando você inicializar o aplicativo como um Multithreaded Apartment (828643) em [http://support.microsoft.com/default.aspxscid=kb;en-us;828643](http://support.microsoft.com/default.aspxscid=kb;en-us;828643).  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h

## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

