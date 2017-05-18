---
title: Interface ICommandTarget | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ICommandTarget
- AFXWINFORMS/ICommandTarget
- AFXWINFORMS/ICommandTarget::Initialize
dev_langs:
- C++
helpviewer_keywords:
- ICommandTarget interface
ms.assetid: dd9927f6-3479-4e7c-8ef9-13206cf901f3
caps.latest.revision: 27
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 825fde18c56afb91bdb469212817109dc35abf68
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="icommandtarget-interface"></a>Interface ICommandTarget
Fornece um controle de usuário com uma interface para receber comandos de um objeto de origem do comando.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
interface class ICommandTarget  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[ICommandTarget::Initialize](#initialize)|Inicializa o objeto de destino de comando.|  
  
## <a name="remarks"></a>Comentários  
 Quando você hospeda um controle de usuário em uma exibição MFC, [CWinFormsView](../../mfc/reference/cwinformsview-class.md) comandos de rotas e atualização de comando mensagens de interface do usuário para o controle de usuário para permitir que ele manipule comandos MFC (por exemplo, itens de menu do quadro e botões de barra de ferramentas). Implementando `ICommandTarget`, você dá o controle de usuário uma referência para o [ICommandSource](../../mfc/reference/icommandsource-interface.md) objeto.  
  
 Consulte [como: Adicionar roteamento de comando para o controle Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) para obter um exemplo de como usar `ICommandTarget`.  
  
 Para obter mais informações sobre como usar o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwinforms.h (definido no assembly atlmfc\lib\mfcmifc80.dll)  
  
##  <a name="initialize"></a>ICommandTarget::Initialize  
 Inicializa o objeto de destino de comando.  
  
```  
void Initialize(ICommandSource^ cmdSource);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `cmdSource`  
 Um identificador para o objeto de origem do comando.  
  
### <a name="remarks"></a>Comentários  
 Quando você hospeda um controle de usuário em uma exibição MFC, CWinFormsView encaminha comandos e as mensagens UI de comando de atualização para o controle de usuário para permitir que lidar com comandos do MFC.  
  
 Esse método inicializa o objeto de destino de comando e associa o cmdSource de objeto de origem do comando especificado. Ele deve ser chamado na implementação de classe do controle de usuário. Na inicialização, você deve registrar manipuladores de comandos com o objeto de origem de comando por chamada ICommandSource::AddCommandHandler na implementação de inicialização. Consulte como: Adicionar roteamento de comando para o controle Windows Forms para obter um exemplo de como usar a inicialização para fazer isso.  
  
## <a name="see-also"></a>Consulte também  
 [Como: Adicionar comando de controle de formulários do roteamento do Windows](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md)   
 [Interface ICommandSource](../../mfc/reference/icommandsource-interface.md)




